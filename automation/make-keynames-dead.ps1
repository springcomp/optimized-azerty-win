Write-Output "KEYNAME_DEAD"
Write-Output ""

Get-ChildItem -Filter "*.txt" |? { $_.Name -match "^[0-9a-f]{4}.*"} | Sort-Object -Property Name |% {
    $match = $_.Name -match "^(?<cp>[0-9a-f]{4})(?:_[0-9a-f]{4})?_(?<name>.*)\.txt$"
    if ($match){
        $codePoint = [Convert]::ToInt32($matches["cp"], 16)
        $name = $matches["name"].Replace("_", " ").ToUpper()
        Write-Output "$($codePoint.ToString("x4"))`t`"$($name)`""
    }
}

Write-Output ""