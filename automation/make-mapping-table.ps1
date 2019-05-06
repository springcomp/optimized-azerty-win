[CmdletBinding()]
param([string] $path)

BEGIN {
    Function Get-CodePoint {
        param([Char] $char)
        Write-Output ([Int32] $char)
    }
}

PROCESS {

    Get-Content -Path $path |% {
        $char = $_[0]
        $currency = $_[1]
        $codePoint = Get-CodePoint -Char $char
        $curr = Get-CodePoint -Char $currency

        Write-Output "$($codePoint.ToString("x4"))`t$($curr.ToString("x4"))`t// $($char) -> $($currency)"
    }

}