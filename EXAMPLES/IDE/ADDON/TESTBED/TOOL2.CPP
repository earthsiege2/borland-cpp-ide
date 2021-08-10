/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  tool2.cpp
  Created: 12/21/95
  Copyright (c) 1987, 1995 Borland International Inc.  All Rights Reserved.
  $Revision:   1.11  $
   
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
  }
  _toolName = MakePolyString( toolName );
  OutStr( "Registers MyTool, invoke it from the Tool menu to test." );
}
//.............................................................................
ToolTestC::~ToolTestC() {
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
void ProjectClient::CloseNotify() {
  if ( _toolTest ) {
    _toolTest->UnregisterTool();
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

