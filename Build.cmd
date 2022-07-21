@echo off
set include=include;fasmgP;fasmg\packages\x86\include;
if not exist Release md Release
set app=TinyWinDL

set variant=386
call :Build

set variant=386_micro
call :Build

set variant=amd64
call :Build

set variant=amd64_micro
call :Build

pause
exit /b

:Build
call fasmg\core\fasmg.exe -e65535 %app%_%variant%.asm Release\%app%_%variant%.exe
exit /b