/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  script.cpp
  Created: 10/28/95
  Copyright (c) 1995, Borland International
  $Revision:   1.18  $
  
  To try this out, make sure and put ssinit.spp and sstest.spp in your
  bc5\script directory. Then, pay attention to the "script" page in the 
  message window. You should see a print of "ssinit.spp" at startup time
  in the message window.
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\iscript.h>
#include "script.h"

//.............................................................................
ScriptTestA::ScriptTestA() { 
  _scriptServer = GET_INTERFACE( IScriptServer ); 
  if ( _scriptServer ) {
    OutStr( "Scheduling script: ssinit.spp" );
    _scriptServer->ScheduleScriptFile( MakePolyString( "ssinit" ) );
    _scriptServer->Release();
  }
  _scriptServer = NULL;
}
//.............................................................................
ScriptTestA::~ScriptTestA() {
  UnInit();
}
//.............................................................................
BOOL ScriptTestA::Init() {
  OutStr( "ScriptTestA::Init()" );
  if ( !_scriptServer ) {
    _scriptServer = GET_INTERFACE( IScriptServer );
  }
  return TRUE;
}
//.............................................................................
void ScriptTestA::UnInit() {
  OutStr( "OptionSetTestA::UnInit()" );
  if ( _scriptServer ) {
    _scriptServer->Release();
    _scriptServer = NULL;
  }
}  
//.............................................................................
const char * ScriptTestA::GetName() {
  return "ScriptServer Test A";
}
//.............................................................................
const char * ScriptTestA::GetTestDescription( int testNum ) {
  switch ( testNum ) {
    case 1: 
      return "Runs script: sstest.spp.";
    case 2:
      return "Runs script command: SSAddOnTest(); (function in sstest.spp)";
  }
  return "This test not implemented.";
}  
//.............................................................................
void ScriptTestA::DoTest( int testNum ) {
  if ( !_scriptServer ) {
    OutStr( "Script Server not initialized!" );
    return;
  }
  switch ( testNum ) {
    case 1: {
      _scriptServer->RunScriptFile( MakePolyString( "sstest" ) );
      break;
    }
    case 2: {
      IPolyString * retstr = CreatePolyString();
      int res = _scriptServer->RunScriptCommand( 
                    MakePolyString( "return SSAddOnTest();" ), retstr );
      OutStr( FormatStr( "Command result: %d \"%s\"", res, retstr->GetCstr() ) );
      retstr->Release();
      break;
    }
    default: {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
    }
  }
}
