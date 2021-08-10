@echo off

set errorlevel=0
if not [%LOGFILE%] == [] goto gotlog
echo Setting LOGFILE to log\rtl.log!
if not exist log\nul md log
set LOGFILE=.\log\rtl.log

:gotlog
echo Building... > %LOGFILE%
echo Building...

REM ######################################################################
REM # Build the Win32 RTLs.
REM ######################################################################
echo C++Builder RTL library (cw32mt.lib)
echo make -DMT all >> %LOGFILE%
make -DMT all >> %LOGFILE%
if errorlevel 1 goto builderr

echo C++Builder VCL enabled RTL static library
echo make -DMT -DMAGIC all >> %LOGFILE%
make -DMT -DMAGIC all >> %LOGFILE%
if errorlevel 1 goto builderr

echo C++Builder combined (Standard/VCL) MT RTL dynamic library
echo make -DMT -DDLL -DMAGIC all >> %LOGFILE%
make -DMT -DDLL -DMAGIC all >> %LOGFILE%
if errorlevel 1 goto builderr

REM Note: The following three forms of the RTL are *NOT* needed for VCL
REM       C++Builder (GUI) applications.  They can be skipped by uncommenting
REM       The following line.

REM goto skip_extra_rtl

echo C++Builder RTL static library (Single Thread)
echo make all >> %LOGFILE%
make all >> %LOGFILE%
if errorlevel 1 goto builderr

echo C++Builder RTL dynamic library (Single Thread)
echo make -DDLL all >> %LOGFILE%
make -DDLL all >> %LOGFILE%
if errorlevel 1 goto builderr

:skip_extra_rtl

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
