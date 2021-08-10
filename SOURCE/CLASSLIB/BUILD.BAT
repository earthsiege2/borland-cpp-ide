:// -------------------------------------------------------------------------
:// Borland International Data Structures Library
:// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
://
:// Simple MAKEFILE illustrating the command line options to rebuild
:// the Libraries
:// 
:// NOTE : The 'BIDSOPTS' macro defined below can be used to set additional
://        options. For example, if you want to rebuild the libraries
://        with DIAGNOSTICS and DEBUG information enabled, you can 
://                set BIDSOPTS=-DDIAGS -DDEBUG
:// -------------------------------------------------------------------------
@echo off

set BIDSNAME=BIDS
set BIDSDLLNAME=BDS
set BIDSVER=501
set BIDSOPTS=

:// -------------------------------------------------------------------------
://  Build 16-bit libraries
:// -------------------------------------------------------------------------
  echo.
  echo Building 16-bit static link libraries
  echo.
  make -DDOS MODEL=s %BIDSOPTS%
  if errorlevel 1 goto Failure

  make -DDOS MODEL=c %BIDSOPTS%
  if errorlevel 1 goto Failure

  make -DDOS MODEL=m %BIDSOPTS%
  if errorlevel 1 goto Failure

  make -DDOS MODEL=l %BIDSOPTS%
  if errorlevel 1 goto Failure

  make -DDOS MODEL=h %BIDSOPTS%
  if errorlevel 1 goto Failure

  make -DDOS -DDLL %BIDSOPTS%
  if errorlevel 1 goto Failure



:// -------------------------------------------------------------------------
://  Build 32-bit libraries
:// -------------------------------------------------------------------------
  echo.
  echo Building 32-bit static link libraries
  echo.
  make -DWIN32 %BIDSOPTS%
  if errorlevel 1 goto Failure

  echo.
  echo Building 32-bit DLLs
  echo.
  make -DWIN32 -DDLL %BIDSOPTS%
  if errorlevel 1 goto Failure

  echo.
  echo Building 32-bit multithreaded static link libraries
  echo.
  make WIN32=1 MT=1 %BIDSOPTS%
  if errorlevel 1 goto Failure

  echo.
  echo  Building 32-bit multithreaded DLL
  echo.
  make -DWIN32 -DDLL -DMT %BIDSOPTS%
  if errorlevel 1 goto Failure

