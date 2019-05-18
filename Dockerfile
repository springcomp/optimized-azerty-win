FROM springcompdocker/msklc:1.4
WORKDIR /scripts
COPY ./Make-KeyboardLayout.ps1 .

## $command = ". C:\scripts\Make-KeyboardLayout.ps1"
## $bytes = [System.Text.Encoding]::Unicode.GetBytes($command)
## $encodedCommand = [Convert]::ToBase64String($bytes)

ENTRYPOINT ["powershell.exe", "-nologo", "-encodedCommand", "LgAgAC8AcwBjAHIAaQBwAHQAcwAvAE0AYQBrAGUALQBLAGUAeQBiAG8AYQByAGQATABhAHkAbwB1AHQALgBwAHMAMQA="]