/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  target.cpp
  Created: 10/26/95
  Copyright (c) 1995, Borland International
  $Revision:   1.18  $
   
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
      return "Adds various targets to the current project.";
    case 2: 
      return "Adding custom target Win32 OWL application.";
    case 3:
      return "Is current node a target?";
  }
  return "This test not implemented.";
}  

struct Target {
  const char * nodeName;
  TargetType type;
  TargetPlatform platform;
  int libs;
  TargetModel model;
};
static Target targets[] = {
  { "Exe-Win32-StdLibsDyn-Gui", TT_Application, TP_Win32, TL_StdLibs|TL_Dynamic, TM_Gui },
  { "Exe-Win32-StdLibsDyn-Console", TT_Application, TP_Win32, TL_Bids|TL_Rtl|TL_Dynamic, TM_FsConsole },
  { "Dll-Win32-StdLibsDyn-Gui", TT_Dll, TP_Win32, TL_StdLibs|TL_Dynamic, TM_Gui },
  { "Dll-Win16-StdLibsDyn-Gui", TT_Dll, TP_Win16, TL_StdLibs|TL_Dynamic, TM_Gui },
  { "Exe-DosOverlay-Large", TT_Application, TP_DosOverlay, TL_StdLibs|TL_Dynamic, TM_Large },
  { "Exe-Dos16-StdLibsStatic-Small", TT_Application, TP_Dos16, TL_StdLibs|TL_Static, TM_Small },
  { "Lib-Dos16-STdLibs-Medium", TT_StaticLib, TP_Dos16, TL_StdLibs, TM_Medium },
  { NULL }
};  
//.............................................................................
void TargetTestA::DoTest( int testNum ) {
  if ( !_targetServer ) {
    OutStr( "TargetServer not initialized!" );
    return;
  }
  switch ( testNum ) {
    case 1: {
      Target * t = targets;
      while ( t->nodeName ) {
        ProjectNode node = _targetServer->TargetAdd(
              MakePolyString( t->nodeName ),
              0,
              t->type,
              t->platform,
              t->libs,
              t->model );
        if ( _targetServer->NodeIsTarget( node ) ) {
          OutStr( FormatStr( "New target %s added.", t->nodeName ) );
        }
        else {
          OutStr( FormatStr( "Problem creating target: %s.", t->nodeName ) );
        }
              
        ++t;
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
