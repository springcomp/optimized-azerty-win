<# Create the ¤ currency sign dead-key table
 # First, run the dump-currencies.ps1 script
 # This creates a list of all known Unicode currency symbols
 # Create a .\currencies.txt file that contains the desired mappings
 # The format of the file must be one mapping per line,
 # each line consisting of two unicode characters, the key and corresponding currency symbol.
 # For instance:
 # 
 # A₳
 # e₠
 # r₽
 # R₹
 # etc.
 #
 #>
[CmdletBinding()]
param()

BEGIN {
    Function Format-Hex {
        param([Char] $char)
        Write-Output (Get-CodePoint($char)).ToString("x4") 
    }

    Function Low {
        param([Int32] $codePoint)
        Write-Output ([byte]($codePoint -band 0x00FF))
    }
    Function High {
        param([Int32] $codePoint)
        Write-Output ([byte](($codePoint -band 0xFF00) -shr 8))
    }


    Function Get-CodePoint {
        param([Char] $char)
        Write-Output ([Int32] $char)
    }
 
}

PROCESS {

    Write-Output "DEADKEY 00a4"
    Write-Output ""

    Get-Content -Path ".\currencies.txt" |% {
        $char = $_[0]
        $currency = $_[1]
        $codePoint = Get-CodePoint -Char $char
        $curr = Get-CodePoint -Char $currency

        Write-Output "$($codePoint.ToString("x4"))`t$($curr.ToString("x4"))`t// $($char) -> $($currency)"
    }

    Write-Output ""
}