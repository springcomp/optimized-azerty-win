$layout = "$PSScriptRoot\KBFRZ71.klc"

# build the keyboard, waiting for exit
Write-Output "Building keyboard setup..."
&"C:\Program Files (x86)\Microsoft Keyboard Layout Creator 1.4\MSKLC.exe" $layout /build | Out-Null

# delete existing .\bin dir
Remove-Item .\bin -Force -Recurse -ErrorAction Ignore

# copy the build result on local .\bin
$mydoc = [environment]::getfolderpath("mydocuments")
Move-Item $mydoc\kbfrz71 .\
Move-Item .\kbfrz71 bin

Write-Output "Build complete, setup files are on the .\bin folder"