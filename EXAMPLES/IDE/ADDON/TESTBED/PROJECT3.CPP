#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\iscript.h>

#include "project3.h"


//
// Used to call OutStr to display dependencies in 
// MyProjClient::DependencyQueryResponder;
//
ProjectTestC* thisTest;

////////////////////////////////
// ProjectTestC Implementation
////////////////////////////////


ProjectTestC::ProjectTestC()
             : prjServer( 0 ), prjClient( 0 )
{
   
}


ProjectTestC::~ProjectTestC()
{
  if( prjClient )  {
      prjClient->AddRef();
      prjServer->UnregisterProjectClient( prjClient );
      prjClient->Release();
  }
  
  if( prjServer )
      prjServer->Release();
      
}


BOOL ProjectTestC::Init()
{
  OutStr( "ProjectTestC::Init()" );
  thisTest = this;
  IProjectServer* _prjServer = GET_INTERFACE( IProjectServer );
  prjServer = QUERY_INTERFACE( _prjServer, IProjectServer3 );
  _prjServer->Release();
  if( !prjServer )  {
    OutStr( "Couldn't get IProjectServer3 interface" );
    return FALSE;
  }

  prjClient = new MyProjClient();
  prjClient->AddRef();
  prjServer->RegisterProjectClient( prjClient );
  
  return TRUE;
}


void ProjectTestC::UnInit()
{
  OutStr( "ProjectTestC::UnInit()" );
}


const char* ProjectTestC::GetName()
{
   return "Project Test C";
}


const char* ProjectTestC::GetTestDescription(int testNum)
{
    switch(testNum)  {
      case 1:
        return "Display dependencies for selected node";
      default: 
        return "Test Not Implemented";
    }
}


void ProjectTestC::DoTest(int testNum)
{
    switch(testNum)  {
      case 1:  
        ShowDeps();
        break;
      default:
        OutStr( "Test Not Implemented" );
    }
}


void ProjectTestC::ShowDeps()
{
  int num = 0;
  ProjectNode* node = prjServer->QuerySelectedNodes( &num );
  if( num == 0 )  {
    OutStr( "No nodes selected" );
    return;
  }

  IProjectNodeInfo* info = prjServer->QueryNodeInfo( *node );
  IPolyString* name = info->GetName();
  OutStr( FormatStr("Dependencies for: %s", name->GetCstr()) );
  info->Release();
  name->Release();

  prjServer->QueryAutoDependencies( *node, prjClient );
}


/*-----------------------------------------------------------------------*/


void MyProjClient::DependencyQueryResponder( ProjectNode node,
                                             IPolyString* name )
{
   thisTest->OutStr( name->GetCstr() );
   name->Release();
}


/*-----------------------------------------------------------------------*/
