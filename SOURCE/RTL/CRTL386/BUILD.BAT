@ECHO OFF

rem     BUILD.BAT
rem
rem     builds RTL for NT
rem
rem     parameters:
rem
rem     %1 name of library to be built
rem     all  clib  mt  dll  dllmt

cd win32

:checkparm

if %1.==. goto error
if %1 == clib goto ok
if %1 == mt goto ok
if %1 == dll goto ok
if %1 == dllmt goto ok
if %1 == all goto ok
goto error

:ok
rem if not "%LOGFILE%"=="" goto build
rem echo LOGFILE environment variable not set.  Setting it to log\crtl.log
set LOGFILE=log\crtl.log

:build

goto %1

:all
:clib

echo Building CW32.LIB
echo          COMMON
make -DCLIB     >>%LOGFILE%
if errorlevel 1 goto exit
echo          CLIB
make -DCLIBNT   >>%LOGFILE%
if errorlevel 1 goto exit
echo          IOSTREAM
make -DIOSTREAM >>%LOGFILE%
if errorlevel 1 goto exit
echo Finished CW32.LIB
if not %1 == all goto exit


:mt

echo Building CW32MT.LIB
echo          COMMON
make -DCLIB -DMT     >>%LOGFILE%
if errorlevel 1 goto exit
echo          CLIB
make -DCLIBNT -DMT   >>%LOGFILE%
if errorlevel 1 goto exit
echo          IOSTREAM
make -DIOSTREAM -DMT >>%LOGFILE%
if errorlevel 1 goto exit
echo Finished CW32MT.LIB
if not %1 == all goto exit


:dll

echo Building CW32.DLL
echo          COMMON
make -DDLL -DCLIB     >>%LOGFILE%
if errorlevel 1 goto exit
echo          CLIB
make -DDLL -DCLIBNT  >>%LOGFILE%
if errorlevel 1 goto exit
echo          IOSTREAM
make -DDLL -DIOSTREAM >>%LOGFILE%
if errorlevel 1 goto exit
echo Linking  CW32.DLL
make -DDLL -DCLIB dll >>%LOGFILE%
if errorlevel 1 goto exit
echo Finished CW32.DLL
if not %1 == all goto exit

:dllmt

echo Building CW32MT.DLL
echo          COMMON
make -DDLL -DMT -DCLIB     >>%LOGFILE%
if errorlevel 1 goto exit
echo          CLIB
make -DDLL -DMT -DCLIBNT  >>%LOGFILE%
if errorlevel 1 goto exit
echo          IOSTREAM
make -DDLL -DMT -DIOSTREAM >>%LOGFILE%
if errorlevel 1 goto exit
echo Linking  CW32MT.DLL
make -DDLL -DMT -DCLIB dll >>%LOGFILE%
if errorlevel 1 goto exit
echo Finished CW32MT.DLL
if not %1 == all goto exit

goto exit

:error

echo BUILD.BAT
echo Usage: build libtype
echo   where libtype is one of
echo   all  clib  mt
echo 
echo Example: build clib
echo 
echo This batch file rebuilds one or more libraries.  It compiles or assembles
echo all source files, and rebuilds the library (or libraries).
echo 
echo The LOGFILE environment variable specifies the name of the error log file.
echo If LOGFILE isn't set, it is set to log\crtl.log.  Set LOGFILE to CON
echo to send the error log to the screen.

goto exit

:exit
cd ..