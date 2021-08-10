/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  msgcli.cpp
  Created: 06/27/96
  Copyright (c) 1996, Borland International
  $Revision:   1.0  $

  MessageClientTest
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#include "msgcli.h"


MessageClientTest::MessageClientTest() : IUNKNOWNIMPL_INIT( IMessageClient ) {
  _tooLateToStartHandling = false;
  _showHandlingEnabled = _viewHandlingEnabled = _editHandlingEnabled = false;
  IMessageSystem2 * ms = GET_INTERFACE( IMessageSystem2 );
  ms->RegisterMessageClient( this );
  OutStr( "Registered dormant message client." );
  ms->Release();
}

void MessageClientTest::warnIfTooLate() {
  if ( _tooLateToStartHandling ) {
    OutStr( "It is too late to begin message handling." );
  }
} 

BOOL MessageClientTest::Init() {
  warnIfTooLate();
  return TRUE;
}

void MessageClientTest::UnInit() {
}


const char * MessageClientTest::GetName() {
  return "Message Client Test";
}


BOOL MessageClientTest::CanHandleMessage( IPolyString * handlerType, IPolyString * action ) {
  BOOL ret = FALSE;
  if ( lstrcmp( handlerType->GetCstr(), "SourceEditor" ) == 0 ) {
    _tooLateToStartHandling = true;   
    if ( lstrcmp( action->GetCstr(), "Edit" ) == 0 ) {
      ret = _editHandlingEnabled;
    }
    else if ( lstrcmp( action->GetCstr(), "View" ) == 0 ) {
      ret = _viewHandlingEnabled;
    }
    else if ( lstrcmp( action->GetCstr(), "Show" ) == 0 ) {
      ret = _showHandlingEnabled;
    }
  }
  OutStr( 
    FormatStr( "MessageClientTest::CanHandleMessage( %s, %s ) returning %s",
    handlerType->GetCstr(), action->GetCstr(), ret? "TRUE" : "FALSE" ) );
    
  
  handlerType->Release();
  action->Release();
  return ret;
}

void MessageClientTest::HandleMessage( IPolyString * action, int column, int line, IPolyString * filePath ) {
  OutStr( FormatStr( "MessageClientTest::HandleMessage( %s, %d, %d, %s )",
    action->GetCstr(), column, line, filePath->GetCstr() ) );
  action->Release();
  filePath->Release();    
}

const char * MessageClientTest::GetTestDescription( int testNum ) {
  switch ( testNum ) {
    case 1:
      return "Handle 'Show' messages for handler type 'SourceEdit'";
    case 2:
      return "Handle 'View' messages for handler type 'SourceEdit'";
    case 3:
      return "Handle 'Edit' messages for handler type 'SourceEdit'";
    case 4:
      break;
  }
  return "This test not implemented.";
}

void MessageClientTest::DoTest( int testNum ) {
  warnIfTooLate();
  switch ( testNum ) {
    case 1:
      _showHandlingEnabled = true;
      break;
    case 2:
      _viewHandlingEnabled = true;
      break;
    case 3:
      _editHandlingEnabled = true;
      break;
    case 4:
    default:
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      break;
    
  }
  OutStr( FormatStr( "MessageClient state: Show=%s View=%s Edit=%s",
          _showHandlingEnabled? "Enabled" : "Off",
          _viewHandlingEnabled? "Enabled" : "Off",
          _editHandlingEnabled? "Enabled" : "Off" ) );
          

}
