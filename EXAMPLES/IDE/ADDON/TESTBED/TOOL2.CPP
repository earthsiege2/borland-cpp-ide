/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  tool2.cpp
  Created: 12/21/95
  Copyright (c) 1987, 1995 Borland International Inc.  All Rights Reserved.
  $Revision:   1.15  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "tool2.h"

const char * toolName = "myTool";

//.............................................................................
ToolTestC::ToolTestC() {
  _projectClient = new ProjectClient;
  _toolInvoker = new ToolInvoker;

  _projectClient->RegisterToolTest( this );
  _toolServer = GET_INTERFACE( IToolServer );
  _projectServer = GET_INTERFACE( IProjectServer );


  if ( _projectServer ) {
    _projectClient->AddRef();
    _projectServer->RegisterProjectClient( _projectClient );
    IProjectServer2 * ps2 = GET_INTERFACE( IProjectServer2 );
    if ( ps2 ) {  // this interface not available on BCW versions < 5.01
      _projectClient->AddRef();
      ps2->RegisterProjectSaveClient( _projectClient );
      ps2->Release();
    }
  }
  _toolName = MakePolyString( toolName );
  OutStr( "Registers MyTool, invoke it from the Tool menu to test." );
}
//.............................................................................
ToolTestC::~ToolTestC() {
  IProjectServer2 * ps2 = GET_INTERFACE( IProjectServer2 );
  if ( ps2 ) {  // this interface not available on BCW versions < 5.01
    _projectClient->AddRef();
    ps2->UnregisterProjectSaveClient( _projectClient );
    ps2->Release();
  }
  _projectClient->AddRef();
  _projectServer->UnregisterProjectClient( _projectClient );
  _projectClient->Release();
  _projectClient = 0;

  _toolInvoker->Release();

  if ( _projectServer ) {
    _projectServer->Release();
  }
  _toolName->Release();
}
//.............................................................................
void ToolTestC::RegisterTool() {
  IToolInfo * toolInfo;
  ToolObj tool;
  if ( !_toolServer ) {
    return;
  }
  _toolName->AddRef();
  tool = _toolServer->ToolFind( _toolName );
  if ( tool ) {
    _toolServer->ToolRemove( tool );
  }
  toolInfo = _toolServer->CreateToolInfoInstance();
  if ( !toolInfo ) {
    return;
  }
  toolInfo->SetTypes( TT_Viewer );
  _toolName->AddRef();
  toolInfo->SetName( _toolName );
  toolInfo->SetFlags( TIFlag_OnToolsMenu );
  toolInfo->SetMenuName( MakePolyString( "&My Tool" ) );
  _toolInvoker->AddRef();
  toolInfo->SetImplementor( _toolInvoker );
  _toolServer->ToolAdd( toolInfo );
}
//.............................................................................
  void ToolTestC::UnregisterTool() {
  if ( !_toolServer ) {
    return;
  }
  _toolName->AddRef();
  ToolObj tool = _toolServer->ToolFind( _toolName );
  if ( tool ) {
    _toolServer->ToolRemove( tool );
  }
}
//.............................................................................
void ProjectClient::OpenNotify( IPolyString * projectName ) {
  if ( _toolTest ) {
    _toolTest->RegisterTool();
  }
  projectName->Release();
}  
//.............................................................................
void ProjectClient::CloseNotify() {}
//.............................................................................
void ProjectClient::BeforeSaveNotify() {
  //
  // Yank the add-on tool before the project is saved, so it will not
  // appear in the project if it is loaded when this add-on isn't installed.
  //
  if ( _toolTest ) {
    _toolTest->UnregisterTool();
  }
} 
//.............................................................................
void ProjectClient::AfterSaveNotify() {
  //
  // Now that the project has been saved, we must re-install the add-on tool.
  //
  if ( _toolTest ) {
    _toolTest->RegisterTool();
  }
}
//.............................................................................
ToolReturn ToolInvoker::Execute( 
                IPolyString * /* cmdLine */, 
                ProjectNode * /* nodeArray */, 
                int /* numNodes */ ) {

  MessageBox( 0, "Hey!", "ToolInvoked", MB_OK );
  return TR_Success;
  
}                 
