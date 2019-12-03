[CmdletBinding()]
param(
    [Parameter(Mandatory = $true, Position = 0, ParameterSetName = "Paths")]
    [string] $path,
    [Parameter(Position = 1, ParameterSetName = "Paths")]
    [string] $output,

    [Parameter(Mandatory = $true, ParameterSetName = "Name")]
    [string] $name,

    [string] $encoding = "UTF8",
    [switch] $force = $false
)

BEGIN {

    if ($name -ne $null){
        $path = ".\$($name).klc.tpl"
        $output = ".\$($name).klc"
    }

    $path = (Resolve-Path -Path $path).ProviderPath
    $folder = Split-Path -Path $path -Parent
    $klc = [IO.Path]::GetFileNameWithoutExtension($path)

    if (-not $output) {
        $output = Join-Path -Path $folder -ChildPath $klc
    } else {
        $output = (Resolve-Path -Path $output).ProviderPath
    }

    if (Test-Path -Path $output) {
        if (-not $force.IsPresent) {
            throw "The layout file `"$klc`" already exists. Please, use the -force flag to overwrite."
        }

        Remove-Item -Path "$output~" -EA SilentlyContinue | Out-Null
        Rename-Item -Path $output -NewName "$output~"
    }

    $code = "\<\? (?<cmd>.*) \?\>"

    Function Run-Command {
        [CmdletBinding()]
        param(
            [string] $script
        )

        BEGIN {
            $path = (Resolve-Path -Path $script).ProviderPath
            $folder = Split-Path -Path $path -Parent
            $ps = Split-Path -Path $path -Leaf

            Push-Location $folder
        }
        PROCESS {
            Write-Output (Invoke-Expression ".\$ps")
        }
        END {
            Pop-Location
        }
    }
}
PROCESS {

    Get-Content -Path $path -Encoding UTF8 | % {

        $line = $_
        $match = $line -match $code

        if ($match) {
            $command = $matches["cmd"]
            $result = Run-Command -Script $command
            $result | % {
                Add-Content -Path $output -Encoding $encoding -Value $_
            }
        }
        else {
            Add-Content -Path $output -Encoding $encoding -Value $_
        }
    }
}