/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  target.cpp
  Created: 10/26/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\iproj.h>
#include <ideaddon\iide.h>
#include "target.h"
#include "txowl.h"
//.............................................................................
TargetTestA::TargetTestA() { 
  d_owlTarget = 0;
  _targetServer = NULL; 
}
//.............................................................................
TargetTestA::~TargetTestA() {
  UnInit();
}

//.............................................................................
BOOL TargetTestA::Init() {
  OutStr( "TargetTestA::Init()" );
  if ( !_targetServer ) {
    _targetServer = GET_INTERFACE( ITargetServer );
  }
  return _targetServer? TRUE : FALSE;
}
//.............................................................................
void TargetTestA::UnInit() {
  OutStr( "TargetTestA::UnInit()" );
  if ( _targetServer ) {
    _targetServer->Release();
    _targetServer = NULL;
  }
  if ( d_owlTarget ) {
   d_owlTarget->Release();
  }
}  
//.............................................................................
const char * TargetTestA::GetName() {
  return "TargetServer Test A";
}
//.............................................................................
const char * TargetTestA::GetTestDescription( int testNum ) {
  switch ( testNum ) {
    case 1: 
      return "Adds a Win32 GUI Application target.";
    case 2: 
      return "Adding custom target Win32 OWL application.";
    case 3:
      return "Is current node a target?";
  }
  return "This test not implemented.";
}  
//.............................................................................
void TargetTestA::DoTest( int testNum ) {
  if ( !_targetServer ) {
    OutStr( "TargetServer not initialized!" );
    return;
  }
  switch ( testNum ) {
    case 1: {
      OutStr( "Adding target." );
      ProjectNode node = 
          _targetServer->TargetAdd( 
              MakePolyString( "Test1.exe" ),  // node name
              0,                     // parent node
              TT_Application,           // target type
              TP_Win32,               // target platform
              (TargetStdLibs)(TL_StdLibs|TL_Dynamic), // libs
              TM_Gui );               // target model
              
      if ( _targetServer->NodeIsTarget( node ) ) {
        OutStr( "Target node added." );
      }
      else {
        OutStr( "Apparent problem adding target node!" );
      }
      break;
    }
    case 2: {
      OutStr( "Adding custom target Win32 OWL application." );
      d_owlTarget = (ITargetType*)new OwlTargetImpl(GetIdeServer());
      break;
    }
    case 3: {
      IProjectServer * projectServer = GET_INTERFACE( IProjectServer );
      if ( projectServer ) {
        int numNodes;
        ProjectNode * nodes = projectServer->QuerySelectedNodes( &numNodes );
        if ( numNodes ) {
          OutStr( FormatStr( "Selected node is %s target.", 
              _targetServer->NodeIsTarget( nodes[0] )? "a" : "not a" ) );
        }
        else {
          OutStr( "No node selected." );
        }
        projectServer->Release();
      }
      break;
    }
    default: {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
    }
  }
}




