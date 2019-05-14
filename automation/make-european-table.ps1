[CmdletBinding()]
param([string] $path = ".\europeans.txt")

BEGIN {
    Function Get-ScriptDirectory {
        Split-Path -Parent $PSCommandPath
    }

    $thisPath = Get-ScriptDirectory
    $script = Join-Path -Path $thisPath -ChildPath "make-mapping-table.ps1"
 
}

PROCESS {

    Write-Output "DEADKEY 0259"
    Write-Output ""

    Invoke-Expression -Command ". `"$($script)`" -Path `"$($path)`" "

    Write-Output ""
}