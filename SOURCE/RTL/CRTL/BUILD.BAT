@echo off

rem     BUILD.BAT
rem
rem     builds RTL for windows or DOS
rem
rem     parameters:
rem
rem     %1 name of library to be built
rem     all  clib  winlib  windll  startup  math  emu

rem Ensure these exist
if not %TASM%x == x goto tc
set TASM=tasm /zi
if %DEBUG%x == x set TASM=tasm
:tc
if not %TC%x == x goto tlib
set TC=bcc /v
if %DEBUG%x == x set TC=bcc
:tlib
if not %TLIB%x == x goto checkparm
set TLIB=tlib /E /P128
if %DEBUG%x == x set TLIB=tlib /0 /E

:checkparm

if %1.==. goto error
if %1 == winlib goto ok
if %1 == windll goto ok
if %1 == clib goto ok
if %1 == math goto ok
if %1 == emu goto ok
if %1 == startup goto ok
if %1 == all goto ok
goto error

:ok

if %1 == windll goto largemodel
echo MODEL environment variable not set.  Setting it to all models.
if %1 == winlib goto winmodel
set MODEL=s c m l h
goto checklog
:largemodel
set MODEL=l
goto checklog
:winmodel
set MODEL=s c m l

:checklog

rem if not "%LOGFILE%"=="" goto build
rem echo LOGFILE environment variable not set.  Setting it to ..\log\crtl.log
set LOGFILE=..\log\crtl.log

:build

if %1 == startup goto nomodel

for %%x in (%MODEL%) do make -DMODEL=%%x %1
goto exit

:nomodel

make -DMODEL=x %1
goto exit

:error

echo BUILD.BAT
echo Usage: build libtype
echo   where libtype is one of
echo   all  clib  winlib  windll startup  math 
echo 
echo Example: build clib
echo 
echo This batch file rebuilds one or more libraries.  It compiles or assembles
echo all source files, and rebuilds the library (or libraries).
echo 
echo The MODEL environment variable specifies the memory model (or models)
echo to rebuild. If MODEL isn't set, all appropriate models are rebuilt.
echo 
echo The LOGFILE environment variable specifies the name of the error log file.
echo If LOGFILE isn't set, it is set to ..\log\crtl.log.  Set LOGFILE to CON
echo to send the error log to the screen.

goto exit

:exit
