[CmdletBinding()]
param()

PROCESS {

    $currency = New-Object -TypeName System.Text.StringBuilder

    for ($codePoint = 0; $codePoint -lt 0x110000; $codePoint = $codePoint + 1) {
        if (($codePoint -ge 0xd800) -and ($codePoint -le 0xdfff)) { 
        }
        else {

            $char = [Char]::ConvertFromUtf32($codePoint)
            $category = [Char]::GetUnicodeCategory($char, 0)

            if ($category -eq [System.Globalization.UnicodeCategory]::CurrencySymbol) {
                $currency.Append($char) | Out-Null
                $currency.Append([Char] 0x0d) | Out-Null
                $currency.Append([Char] 0x0a) | Out-Null
            }
        }
    }

    $text = $currency.ToString()
    Write-Output $text
}