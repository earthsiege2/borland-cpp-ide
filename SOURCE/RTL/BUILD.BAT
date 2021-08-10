@echo off

REM ######################################################################
REM # Check for valid options.
REM ######################################################################

if [%1] == [all]    goto ok
if [%1] == [all16]  goto ok
if [%1] == [all32]  goto ok
if [%1] == [dos]    goto ok
if [%1] == [win16]  goto ok
if [%1] == [dpmi16] goto ok
if [%1] == [win32]  goto ok
if [%1] == [dpmi32] goto ok

goto syntax

:ok

REM ######################################################################
REM # Ensure directory creation.
REM ######################################################################
if not exist obj\dpmi16\nul md obj\dpmi16
if not exist obj\dpmi32\nul md obj\dpmi32

REM ######################################################################
REM # Set enironment flag to denote a build of the RTL SOURCE
REM ######################################################################
set RTLSOURCE=1

REM ######################################################################
REM # Ensure log file creation.
REM ######################################################################

set errorlevel=0
if not [%LOGFILE%] == [] goto gotlog
echo Setting LOGFILE to log\%1.log!
if not exist log\nul md log
set LOGFILE=.\log\%1.log

:gotlog
echo Building... > %LOGFILE%
goto dos


REM ######################################################################
REM # Build the DOS RTL
REM ######################################################################
:dos
if [%1] == [all] goto bdos
if [%1] == [all16] goto bdos
if [%1] == [dos] goto bdos
goto win16

:bdos
echo Building DOS RTLs
if not exist obj\dos\t\nul md obj\dos\t
make OS=DOS MODEL=t all >> %LOGFILE%
if errorlevel 1 goto builderr
make OS=DOS MODEL=s all >> %LOGFILE% 
if errorlevel 1 goto builderr
make OS=DOS MODEL=m all >> %LOGFILE% 
if errorlevel 1 goto builderr
make OS=DOS MODEL=c all >> %LOGFILE% 
if errorlevel 1 goto builderr
make OS=DOS MODEL=l all >> %LOGFILE% 
if errorlevel 1 goto builderr
make OS=DOS MODEL=h all >> %LOGFILE% 
if errorlevel 1 goto builderr


REM ######################################################################
REM # Build the Windows RTLs.
REM ######################################################################
:win16
if [%1] == [all] goto bwin16
if [%1] == [all16] goto bwin16
if [%1] == [win16] goto bwin16
goto dpmi16

:bwin16
echo Building Windows libraries 
make OS=WIN16 MODEL=s all >> %LOGFILE% 
if errorlevel 1 goto builderr
make OS=WIN16 MODEL=m all >> %LOGFILE% 
if errorlevel 1 goto builderr
make OS=WIN16 MODEL=c all >> %LOGFILE% 
if errorlevel 1 goto builderr
make OS=WIN16 MODEL=l all >> %LOGFILE%
if errorlevel 1 goto builderr

echo Building Windows DLL 
make OS=WIN16 MODEL=l -DDLL all >> %LOGFILE%
if errorlevel 1 goto builderr

REM ######################################################################
REM # Build the DPMI16 RTL.
REM ######################################################################
:dpmi16
if [%1] == [all] goto bdpmi16
if [%1] == [all16] goto bdpmi16
if [%1] == [dpmi16] goto bdpmi16
goto win32

:bdpmi16
echo Building DPMI16 libraries 
make OS=DPMI16 MODEL=l all >> %LOGFILE%
if errorlevel 1 goto builderr

REM ######################################################################
REM # Build the Win32 RTLs.
REM ######################################################################
:win32
if [%1] == [all] goto bwin32
if [%1] == [all32] goto bwin32
if [%1] == [win32] goto bwin32
goto dpmi32

:bwin32
echo Building Win32 libraries 
make OS=WIN32 all >> %LOGFILE%
if errorlevel 1 goto builderr
echo Building Multi-thread Win32 libraries
make OS=WIN32 -DMT all >> %LOGFILE%
if errorlevel 1 goto builderr
echo Building Win32 DLL
make OS=WIN32 -DDLL all >> %LOGFILE%
if errorlevel 1 goto builderr
echo Building Multi-thread Win32 DLL
make OS=WIN32 -DMT -DDLL all >> %LOGFILE%
if errorlevel 1 goto builderr

REM ######################################################################
REM # Build the DPMI32 RTL
REM ######################################################################
:dpmi32
if [%1] == [all] goto bdpmi32
if [%1] == [all32] goto bdpmi32
if [%1] == [dpmi32] goto bdpmi32
goto exit

:bdpmi32
echo Building DPMI32 libraries
make OS=DPMI32 all >> %LOGFILE%
if errorlevel 1 goto builderr
goto exit

REM ######################################################################
REM # Usage
REM ######################################################################

:syntax
echo  Syntax: build {WHAT}
echo.
echo    WHAT is one of:
echo        all    - Builds everything specific to the correct OS
echo        all16  - Builds 16 bit libraries
echo        all32  - Builds 32 bit libraries
echo        dos    - Builds the DOS RTLs
echo        dpmi16 - Builds the DPMI16 RTL
echo        dpmi32 - Builds the DPMI32 RTL
echo        win16  - Builds the Windows RTLs
echo        win32  - Builds the Win32 RTLs
echo.
goto exit

REM ######################################################################
REM # Cleanup and exit.
REM ######################################################################
:builderr
echo !! Error in %1 build !!

REM ######################################################################
REM # Cleanup and exit.
REM ######################################################################
:exit
set LOGFILE=
set RTLSOURCE=
