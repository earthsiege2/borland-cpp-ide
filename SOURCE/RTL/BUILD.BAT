@echo off

rem     BUILD.BAT
rem
rem     builds RTL for windows or DOS
rem
rem     parameters:
rem
rem     %1 name of library to be built
rem     all  dos16  win16  win32


:checkparm

if %1.==. goto error
if %1 == dos16 goto ok
if %1 == win16 goto ok
if %1 == win32 goto ok
if %1 == all goto ok

goto error

:ok

goto %1

rem  ALL as the parameter will build all projects

:all
:dos16
cd crtl
call build startup
call build clib
call build math
cd ..
if errorlevel 1 goto build_err
if %1==dos16 goto exit

:win16
cd crtl
call build startup
call build math
call build winlib
call build windll
cd ..
if errorlevel 1 goto build_err
if %1==win16 goto exit

:win32
cd crtl386
call build all
cd ..
if errorlevel 1 goto build_err

goto exit

:build_err
echo   !!!  E R R O R  I N  B U I L D  !!!
goto exit

:error
echo syntax: build {project}
echo.
echo   Options for the "project" argument:
echo.
echo   all - will build each project, or:
echo   dos16, win16, win32
echo.
:exit
