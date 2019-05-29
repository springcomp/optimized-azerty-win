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

    ## This scripts accepts an argument
    ## for testing purposes
    ## When launched from a Docker container
    ## via AppVeyor, we use an environment
    ## variable to specify our requestion version number.

    if ($version = "1.0.3.40"){
        $version = $Env:KBFRZ71_VERSION
        if (-not $version){
            $version = "1.0.3.40"
        }
    }

}

PROCESS {

    Push-Location -Path "C:\sources"

    ## Remove target CPU folders
    ## These folder should not exist previously but this
    ## is useful for testing

    Remove-Item -Path i386 -Recurse -Force -EA SilentlyContinue | Out-Null
    Remove-Item -Path ia64 -Recurse -Force -EA SilentlyContinue | Out-Null
    Remove-Item -Path amd64 -Recurse -Force -EA SilentlyContinue | Out-Null
    Remove-Item -Path wow64 -Recurse -Force -EA SilentlyContinue | Out-Null

    ## kbdutool.exe converts the KLC layout to a .C source file
    ## and then builds a resulting DLL for each supported target CPU.
    ## Unfortunately, the C source file does not use an encoding that
    ## preserves the accented characters

    ## First create C source file

    C:\MSKLC\bin\i386\kbdutool.exe -u -s KBFRZ71.klc | Out-Null

    ## Restore corrupted accented characters

    Set-Content -Path KBFRZ71.C -Encoding UTF8 -Value `
    (Get-Content `
            -Path KBFRZ71.C `
            -Encoding UTF8 `
            -Raw).Replace(
                "�", "é"
            ).Replace(
                "échap", "Échap"
            )

    ## Update version in RC source file
    ## MSKLC creates a DLL with version fixed to 1.0.3.40.
    ## We need to patch the file to update our version

    $defaultVersion = "1.0.3.40"
    $defCommas = Make-Version -Number $defaultVersion
    $defSpaces = Make-Version -Number $defaultVersion -Spaces

    $requestedVersion = $version
    $reqCommas = Make-Version -Number $requestedVersion
    $reqSpaces = Make-Version -Number $requestedVersion -Spaces

    Set-Content -Path KBFRZ71.RC -Encoding Unicode -Value `
    (Get-Content `
            -Path .\KBFRZ71.RC `
            -Encoding Unicode `
            -Raw).Replace(
                "kbfrz71 (3.40)", "kbfrz71"
            ).Replace(
                $defCommas, $reqCommas
            ).Replace(
                $defSpaces, $reqSpaces
            )

    ## Protect the files to prevent kbdutool from overwriting them

    attrib +R KBFRZ71.C
    attrib +R KBFRZ71.H
    attrib +R KBFRZ71.RC
    attrib +R KBFRZ71.DEF

    ## Only the last group of commands report
    ## warnings an errors feedback in the output

    C:\MSKLC\bin\i386\kbdutool.exe -v -w -u -x KBFRZ71.klc | ? { -not $_.Contains("can't open for write.") } | Out-Null
    New-Item -Path i386 -ItemType Directory | Out-Null
    Move-Item -Path KBFRZ71.DLL -Destination i386 -Force

    C:\MSKLC\bin\i386\kbdutool.exe -v -w -u -i KBFRZ71.klc | ? { -not $_.Contains("can't open for write.") } | Out-Null
    New-Item -Path ia64 -ItemType Directory | Out-Null
    Move-Item -Path KBFRZ71.DLL -Destination ia64 -Force

    C:\MSKLC\bin\i386\kbdutool.exe -v -w -u -m KBFRZ71.klc | ? { -not $_.Contains("can't open for write.") } | Out-Null
    New-Item -Path amd64 -ItemType Directory | Out-Null
    Move-Item -Path KBFRZ71.DLL -Destination amd64 -Force
    
    C:\MSKLC\bin\i386\kbdutool.exe -v -w -u -o KBFRZ71.klc | ? { -not $_.Contains("can't open for write.") }
    New-Item -Path wow64 -ItemType Directory | Out-Null
    Move-Item -Path KBFRZ71.DLL -Destination wow64 -Force

    attrib -R KBFRZ71.C
    attrib -R KBFRZ71.H
    attrib -R KBFRZ71.RC
    attrib -R KBFRZ71.DEF

    Remove-Item -Path KBFRZ71.C
    Remove-Item -Path KBFRZ71.H
    Remove-Item -Path KBFRZ71.RC
    Remove-Item -Path KBFRZ71.DEF

    Pop-Location
}