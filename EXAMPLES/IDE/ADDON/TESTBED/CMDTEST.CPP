/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  cmdtest.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.17  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "cmdtest.h"
#include "tests.hrc"

extern HINSTANCE ghInst;

BOOL PASCAL Enabler();
static BOOL okToEnable = TRUE;

//.............................................................................
CmdTestA::CmdTestA()
  {
  _startInitFailed = TRUE;
  _cmdServer  = GET_INTERFACE(ICommandServer);
  if ( _cmdServer )
    {
    ICommand *cmd = _cmdServer->CreateCommand();
    if ( cmd )
      {
      HBITMAP smallBmp = LoadBitmap( ghInst, MAKEINTRESOURCE(BITMAP_1) );
      HBITMAP largeBmp = LoadBitmap( ghInst, MAKEINTRESOURCE(BITMAP_2) );

      // Fill in the cmd
      cmd->SetName( ::MakePolyString ("AnotherFileOpen") );
      cmd->SetDescription( ::MakePolyString ("Another File Open") );
      cmd->SetScriptCommand( ::MakePolyString ("IDE.FileOpen();") );
      cmd->SetToolTip( ::MakePolyString ("A test of the command interface") );
      cmd->SetHelpHint( ::MakePolyString ("A test of the command interface")  );
      cmd->SetHelpId( 0 );
      cmd->SetHelpFile( NULL );
      cmd->SetIcons( smallBmp, largeBmp );
      cmd->SetEnableFunction( Enabler );
      cmd->SetUserData( 0 );

      cmd->AddRef();
      _cmdServer->AddCommand( cmd, TRUE );  // ask for continuos query of the enabler
      _startInitFailed = FALSE;
      }
    }
  }
//.............................................................................
CmdTestA::~CmdTestA()
  {
  UnInit();
  if ( _cmdServer )
    {
    _cmdServer->Release();
    _cmdServer = NULL;
    }
  }
//.............................................................................
BOOL CmdTestA::Init()
  {
  if ( _startInitFailed )
    {
    OutStr( "CmdTestA was inited at startup but failed :-(" );
    }
  else
    {
    OutStr( "CmdTestA was inited at startup." );
    OutStr( "...You should find our test bitmap in the available buttons list." );
    }
  return FALSE;
}
//.............................................................................
void CmdTestA::UnInit()
  {
  OutStr( "CmdTestA::UnInit() is a no-op" );
  }
//.............................................................................
const char * CmdTestA::GetName()
  {
  return "Command test";
  }
//.............................................................................
const char * CmdTestA::GetTestDescription( int testNum )
  {
  switch ( testNum )
    {
    case 1:
      return "Toggle command enable/disable";
    }
  return "This test not implemented.";
  }
//.............................................................................
void CmdTestA::DoTest( int testNum )
  {
  if ( !_cmdServer )
    {
    OutStr( "Command Server not initialized!" );
    return;
    }
  switch ( testNum )
    {
    case 1:
      okToEnable = !okToEnable;
      OutStr( FormatStr(
            "our command is now %s.", okToEnable?
            "enabled" : "disabled" ) );
      break;
    default:
      {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      }
    }
  }


BOOL PASCAL Enabler() {
  return okToEnable;
}
