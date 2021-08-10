:// -------------------------------------------------------------------------
:// ObjectComponents
:// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
:// 
:// $Revision:   2.28  $
:// $Author:   BMYERS  $
:// $Date:   05 Jul 1996 16:03:26  $
:// 
:// Simple batch file illustrating command line options to rebuild
:// the OCF libraries
:// 
:// NOTE : The 'OCFOPTS' macro defined below can be used to set additional
://        options. For example, if you want to rebuild the libraries
://        with DIAGNOSTICS and DEBUG information enabled, you can 
://                set OCFOPTS=-DDIAGS -DDEBUG
:// -------------------------------------------------------------------------
@echo off

set OCFNAME=OCF
set OCFVER=501
set OCFOPTS=

:// -------------------------------------------------------------------------
://  16-bit versions of Library
:// -------------------------------------------------------------------------
  make WIN16=1 MODEL=l NAME=%OCFNAME% %OCFOPTS%
  if errorlevel 1 goto Failure
  del ..\lib\ocfwl.csm

  make WIN16=1 MODEL=l NAME=%OCFNAME% USERDLL=1 %OCFOPTS%
  if errorlevel 1 goto Failure
  del ..\lib\ocfwlu.csm

  make WIN16=1 DLL=1 NAME=%OCFNAME% %OCFOPTS%
  if errorlevel 1 goto Failure
  del ..\lib\ocfwi.csm

  make WIN16=1 DLL=1 NAME=%OCFNAME% USERDLL=1 %OCFOPTS%
  if errorlevel 1 goto Failure
  del ..\lib\ocfwiu.csm


:// -------------------------------------------------------------------------
://  32-bit versions of Library
:// -------------------------------------------------------------------------
  make WIN32=1 MODEL=f NAME=%OCFNAME% %OCFOPTS%
  if errorlevel 1 goto Failure
  del ..\lib\ocfwf.csm

  make WIN32=1 DLL=1 NAME=%OCFNAME% %OCFOPTS%
  if errorlevel 1 goto Failure
  del ..\lib\ocfwfi.csm

  make WIN32=1 MODEL=f MT=1 NAME=%OCFNAME% %OCFOPTS%
  if errorlevel 1 goto Failure
  del ..\lib\ocfw*.csm

  make WIN32=1 DLL=1 MT=1 NAME=%OCFNAME% %OCFOPTS%
  if errorlevel 1 goto Failure
  del ..\lib\ocfw*.csm

