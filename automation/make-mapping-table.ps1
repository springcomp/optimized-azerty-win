[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)]
    [string] $path,
    [switch] $noHeader = $false
)

BEGIN {

    $spaces = @(
        0x00a0,
        0x2003,
        0x202f
    )

    $layers = @(
        0x00a4, # ¤
        0x00b5, # µ
        0x017f # Eu
    )

    ## Get dead key and corresponding combining code points
    ## from the file name
    ## e.g: 002f_short_solidus_overlay_0337
    ## e.g: 002f_0337_short_solidus_overlay

    $dead = $null
    $combining = $null

    $regex = "^.*?(?<cp>[a-f0-9]{4})(?:_(?<cm>[a-f0-9]{4}))?.*$"
    $match = $path -match $regex

    if ($match) {
        $dead = [Convert]::ToUint32($matches["cp"], 16)
        if ($null -ne $matches["cm"]) {
            $combining = [Convert]::ToUint32($matches["cm"], 16)
        }
    }
    else {
        $noHeader = $true
    }

    Function Make-Object {
        param(
            [Parameter(Position = 1)]
            [string] $codePoint,
            [Parameter(Position = 2)]
            [string] $mapCodePoint,
            [Parameter(Position = 3)]
            [string] $character,
            [Parameter(Position = 4)]
            [string] $mapCharacter
        )

        $obj = New-Object -Type PSObject
        $obj | Add-Member -MemberType NoteProperty -Name "CodePoint" -Value $codePoint
        $obj | Add-Member -MemberType NoteProperty -Name "Mapped CodePoint" -Value $mapCodePoint
        $obj | Add-Member -MemberType NoteProperty -Name "Character" -Value $character
        $obj | Add-Member -MemberType NoteProperty -Name "Mapped Character" -Value $mapCharacter

        Write-Output $obj
    }

    Function Get-CodePoint {
        param([Char] $char)
        Write-Output ([Int32] $char)
    }
    Function Get-Char {
        param([int] $codePoint)
        Write-Output ([Char] $codePoint)
    }

    Function Write-Combining {
        param(
            [int] $codePoint,
            [int] $combiningCodePoint
        )

        $char = Get-Char -CodePoint $codePoint

        $combiningHigh = ($combining -band 0xff00) -shr 8
        $combiningLow = ($combining -band 0x00ff)
        $array = @(0xcc, 0x25, $combiningLow, $combiningHigh)
        $mapped = [Text.Encoding]::Unicode.GetString($array)

        $output = Make-Object `
            -codePoint ($codePoint.ToString("x4")) `
            -mapCodePoint ($combiningCodePoint.ToString("x4")) `
            -character "$char" `
            -mapCharacter "$mapped"

        Write-Output $output
    }

    Function Write-Mapped {
        param(
            [Char] $char,
            [Char] $mapped
        )

        $codePoint = Get-CodePoint -Char $char
        $mappedCodePoint = Get-CodePoint -Char $mapped
        if ($mappedCodePoint -eq 0x2400) {
            $mappedCodePoint = 0x0000
        }

        $character = $char
        $contains = $spaces | ? { $_ -eq $codePoint }
        if ($null -ne $contains) {
            $character = " "
        }

        $output = Make-Object `
            -codePoint ($codePoint.ToString("x4")) `
            -mapCodePoint ($mappedCodePoint.ToString("x4")) `
            -character "$character" `
            -mapCharacter "$mapped"

        Write-Output $output
    }

}
PROCESS {

    if (-not $noHeader.IsPresent) {
        Write-Output "DEADKEY $($dead.ToString("x4"))"
        Write-Output ""
    }

    $table = @()

    Get-Content -Path $path | % {
        $char = $_[0]
        $mapped = $_[1]

        if ($char -eq " ") {

            $table = $table | Sort-Object -Property "CodePoint"

            if ($null -ne $combining) {
                $table += Write-Combining -CodePoint $dead -Combining $combining
            }

            $mappedCodePoint = Get-CodePoint -Char $mapped
            $layers | % {
                $cp = $_
                $has = $table | ? { $_."CodePoint" -eq $cp.ToString("x4") }
                if ($has -eq $null) {
                    $table += Write-Mapped -Char (Get-Char -CodePoint $cp) -Mapped (Get-Char -CodePoint $mappedCodePoint) 
                }
            }
            $spaces | % {
                $cp = $_
                $table += Write-Mapped -Char (Get-Char -CodePoint $cp) -Mapped (Get-Char -CodePoint $mappedCodePoint) 
            }

        }

        $table += Write-Mapped -Char $char -Mapped $mapped
    }

    $table | % {
        $cp = $_."CodePoint"
        $mp = $_."Mapped CodePoint"
        $ch = $_."Character"
        $mh = $_."Mapped Character"
        Write-Output "$cp`t$mp`t// $ch -> $mh"
    }

    if (-not $noHeader.IsPresent) {
        Write-Output ""
    }
}