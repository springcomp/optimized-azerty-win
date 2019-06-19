Get-ChildItem -Filter "*.txt" |? { $_.Name -match "^[0-9a-f]{4}.*"} | Sort-Object -Property Name |% {
    .\make-mapping-table $_
}