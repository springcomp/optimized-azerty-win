[CmdletBinding()]
param([string] $version = "1.0.3.40")

BEGIN {
    Function Make-Version {
        [CmdletBinding()]
        param(
            [string]$number,
            [switch]$spaces
        )

        $result = $number.Replace(".", ",")
        if ($spaces.IsPresent) {
            $result = $result.Replace(",", ", ")
        }
        Write-Output $result
    }

    Function Build-Layout {
        param(
            [string] $name
        )

        BEGIN { 

            Function Compile-Layout {
                param(
                    [string] $name,
                    [string] $option,
                    [string] $target,
                    [switch] $quiet = $false
                )

                $expression = "C:\MSKLC\bin\i386\kbdutool.exe -v -w -u $option `"$name.klc`""
                Invoke-Expression -Command $expression | ? {
                    -not $_.Contains("can't open for write.")
                } | % {
                    if (-not $quiet.IsPresent) {
                        Write-Host $_
                    }
                } 

                New-Item -Path $target -ItemType Directory -EA SilentlyContinue | Out-Null
                Move-Item -Path "$name.DLL" -Destination $target -Force
            }

            Function Make-Readonly {
                param(
                    [string] $name,
                    [switch] $readwrite = $false
                )
                if ($readwrite.IsPresent) {
                    attrib -R "$name.C"
                    attrib -R "$name.H"
                    attrib -R "$name.RC"
                    attrib -R "$name.DEF"
                }
                else {
                    attrib +R "$name.C"
                    attrib +R "$name.H"
                    attrib +R "$name.RC"
                    attrib +R "$name.DEF"
                }
            }

            $x86 = ".\Package_x86\bin\"
            $x64 = ".\Package_x64\bin\"
        }

        PROCESS {

            ## Protect the files to prevent kbdutool from overwriting them

            Make-ReadOnly -Name $name

            ## Only the last group of commands report
            ## warnings an errors feedback in the output

            Compile-Layout -Name $name -Option "-x" -Target $x86 -Quiet
            Compile-Layout -Name $name -Option "-m" -Target $x64
    
            Make-Readonly -Name $name -ReadWrite
        }
    }

    Function Fix-Encoding {
        param(
            [string] $name
        )

        PROCESS {

            Set-Content -Path "$name.C" -Encoding UTF8 -Value `
            (Get-Content `
                    -Path "$name.C" `
                    -Encoding UTF8 `
                    -Raw).Replace(
                "�", "é"
            ).Replace(
                "échap", "Échap"
            )

        }
    }

    Function Patch-Version {
        param(
            [string] $name,
            [string] $version
        )

        BEGIN {

            $defaultVersion = "1.0.3.40"
            $defCommas = Make-Version -Number $defaultVersion
            $defSpaces = Make-Version -Number $defaultVersion -Spaces

            $requestedVersion = $version
            $reqCommas = Make-Version -Number $requestedVersion
            $reqSpaces = Make-Version -Number $requestedVersion -Spaces

        }

        PROCESS {

            Set-Content -Path "$name.RC" -Encoding Unicode -Value `
            (Get-Content `
                    -Path "$name.RC" `
                    -Encoding Unicode `
                    -Raw).Replace(
                " (3.40)", ""
            ).Replace(
                $defCommas, $reqCommas
            ).Replace(
                $defSpaces, $reqSpaces
            )
        }
    }

    ## This scripts accepts an argument
    ## for testing purposes
    ## When launched from a Docker container
    ## via AppVeyor, we use an environment
    ## variable to specify our requested version number.

    if ($version -eq "1.0.3.40") {
        $version = $Env:KBFRZ71_VERSION
        if (-not $version) {
            $version = "1.0.3.40"
        }
    }
}

PROCESS {

    Push-Location -Path "C:\sources"

    ## Remove target CPU folders
    ## These folder should not exist previously but this
    ## is useful for testing

    Remove-Item -Path Package_x86\bin -Recurse -Force -EA SilentlyContinue | Out-Null
    Remove-Item -Path Package_x64\bin -Recurse -Force -EA SilentlyContinue | Out-Null

    ## kbdutool.exe converts the KLC layout to a .C source file
    ## and then builds a resulting DLL for each supported target CPU.
    ## Unfortunately, the C source file does not use an encoding that
    ## preserves the accented characters

    ## First create C source file

    C:\MSKLC\bin\i386\kbdutool.exe -u -s KBFRZ71.klc | Out-Null
    C:\MSKLC\bin\i386\kbdutool.exe -u -s KBFRZ71N.klc | Out-Null

    ## Restore corrupted accented characters

    Fix-Encoding -Name KBFRZ71
    Fix-Encoding -Name KBFRZ71N

    ## Update version in RC source file
    ## MSKLC creates a DLL with version fixed to 1.0.3.40.
    ## We need to patch the file to update our version

    Patch-Version -Name KBFRZ71 -Version $version
    Patch-Version -Name KBFRZ71N -Version $version

    Build-Layout -Name KBFRZ71
    Build-Layout -Name KBFRZ71N

    ##Remove-Item -Path KBFRZ71.C
    ##Remove-Item -Path KBFRZ71.H
    ##Remove-Item -Path KBFRZ71.RC
    ##Remove-Item -Path KBFRZ71.DEF

    ## Copy MSKLC KbdMsi.dll used as Windows Installer custom actions
    ## in the resulting .MSI packages

    Copy-Item -Path C:\MSKLC\bin\i386\KbdMsi.dll -Destination Package_x86\bin | Out-Null

    Pop-Location
}