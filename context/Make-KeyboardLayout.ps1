[CmdletBinding()]
param()

PROCESS{

    Push-Location -Path "C:\sources"

    ## Only the last group of commands report
    ## warnings an errors feedback in the output

    C:\MSKLC\bin\i386\kbdutool.exe -v -w -u -x KBFRZ71.klc | Out-Null
    New-Item -Path i386 -ItemType Directory | Out-Null
    Move-Item -Path KBFRZ71.DLL -Destination i386 -Force

    C:\MSKLC\bin\i386\kbdutool.exe -v -w -u -i KBFRZ71.klc | Out-Null
    New-Item -Path ia64 -ItemType Directory | Out-Null
    Move-Item -Path KBFRZ71.DLL -Destination ia64 -Force

    C:\MSKLC\bin\i386\kbdutool.exe -v -w -u -m KBFRZ71.klc | Out-Null
    New-Item -Path amd64 -ItemType Directory | Out-Null
    Move-Item -Path KBFRZ71.DLL -Destination amd64 -Force
    
    C:\MSKLC\bin\i386\kbdutool.exe -v -w -u -o KBFRZ71.klc
    New-Item -Path wow64 -ItemType Directory | Out-Null
    Move-Item -Path KBFRZ71.DLL -Destination wow64 -Force

    Pop-Location
}