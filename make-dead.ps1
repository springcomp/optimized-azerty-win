<#
 # Creates the dead-key table in the MSKLC format
 # using every base character in the specified layout
 # and the code point of a unicode combining character.
 #
 # For instance, "e" + 0x0301 (COMBINING ACUTE ACCENT)
 # to produce the line: 0065    00e9    e -> é
 #>
[CmdletBinding()]
param(
    [string] $layout = "aAzZeErRtTyYuUiIoOpPqQsSdDfFgGhHjJkKlLmMwWxXcCvVbBnN",
    [Alias("Combining")]
    [Int32] $combine = 0x0301
)

BEGIN{


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

    Function Combine {
        param([Char] $char, [Int32] $combining)

        $codePoint = (Get-CodePoint $char[0])

        [byte[]] $array = @(
            (Low $codePoint), `
            (High $codePoint), `
            (Low $combining), `
            (High $combining)
        )

        $text = [Text.Encoding]::Unicode.GetString($array)
        $norm = $text.Normalize()

        Write-Output $norm
    }
}

PROCESS{

    $text = $layout
    $len = $text.Length

    Write-Output "DEADKEY $($combine.ToString("x4"))"
    Write-Output ""

    for ($index = 0; $index -lt $len; $index = $index + 1)
    {
        $char = $text.Substring($index, 1)
        $codePoint = Get-CodePoint -Char $char[0]
        $combined = Combine -Char $char[0] -Combining $combine
        $mapped = Get-CodePoint -Char $combined[0]

        if ($codePoint -ne $mapped)
            { Write-Output "$($codePoint.ToString("x4"))`t// $($mapped.ToString("x4"))`t$($char) -> $($combined)" }
    }

    Write-Output ""
}