//
// ProjectTestB: Test the functions introduced in the IProjectServer3 and 
// IProjectNodeInfo2 interfaces.
//


#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\itool.h>
#include <ideaddon\iproj.h>

#include "project2.h"



////////////////////////////////
// ProjectTestB Implementation
////////////////////////////////


ProjectTestB::ProjectTestB()
       : prjServer(NULL)
{
   
}


ProjectTestB::~ProjectTestB()
{
   if( prjServer )
       prjServer->Release();
}


BOOL ProjectTestB::Init()
{
   OutStr( "ProjectTestB::Init()" );
   IProjectServer* _prjServer = GET_INTERFACE( IProjectServer );
   prjServer = QUERY_INTERFACE( _prjServer, IProjectServer3 );
   if( prjServer == NULL )  {
     OutStr( "Unable to retrieve IProjectServer3 interface" );
     _prjServer->Release();
     return FALSE;
   }
   _prjServer->Release();
   return TRUE;            
}


void ProjectTestB::UnInit()
{
  OutStr( "ProjectTestB::UnInit()" );
}


const char* ProjectTestB::GetName()
{
   return "Project Test B";
}


const char* ProjectTestB::GetTestDescription(int testNum)
{
    switch(testNum)  {
      case 1:
        return "Move Selected Node Down One.";
      case 2:
        return "Copy Selected Node."; 
      case 3:
        return "Change Translator for Selected Nodes"; 
      case 4:
        return "Mark Selected Nodes as Dirty";
      default: 
        return "Test Not Implemented";
    }
}


void ProjectTestB::DoTest(int testNum)
{
    switch(testNum)  {
      case 1:
        MoveNode();
        break;
      case 2:
        CopyNode();
        break;  
      case 3:
        SwapTranslator();
        break; 
      case 4:
        MarkDirty();
        break; 
      default:
        OutStr( "Test Not Implemented" );
    }
}


//
// Moves the first of the selected nodes down one slot in the project 
// if possible. If not possible (checks with NodeIsValidMove) prints 
// out "Invalid Move".
//
void ProjectTestB::MoveNode()
{
  int i = 0;
  ProjectNode* node1 = prjServer->QuerySelectedNodes( &i );
  if( i == 0 ) {
      OutStr( "No nodes selected." );
      return;
  }
  IProjectNodeInfo* info = prjServer->QueryNodeInfo( *node1 );
  ProjectNode node2 = info->GetNextSibling();
  info->Release();
  if( node2 && 
      prjServer->NodeIsValidMove(*node1,node2,PNP_AfterSibling) )  
    prjServer->NodeMove( *node1, node2, PNP_AfterSibling );
  else
    OutStr( "Invalid Move." ); 
}


//
// Copies first of selected nodes to the last child of the node's parent. 
// First tests with NodeIsValidCopy to make sure copy operation is valid.
// If not, prints "Invalid Copy". 
//
void ProjectTestB::CopyNode()
{
  int i = 0;
  ProjectNode* node1 = prjServer->QuerySelectedNodes( &i );
  if( i == 0 ) {
      OutStr( "No nodes selected." );
      return;
  }
  IProjectNodeInfo* info = prjServer->QueryNodeInfo( *node1 );
  ProjectNode node2 = info->GetParent();
  info->Release();
  if( node2 && 
      prjServer->NodeIsValidCopy(*node1,node2,PNP_LastChild) )
    prjServer->NodeCopy( *node1, node2, PNP_LastChild );
  else
    OutStr( "Invalid Copy." ); 
}


//
// Change the translator of the selected nodes to CppToAssembler. Will also
// display old tool name. 
//
void ProjectTestB::SwapTranslator()
{
  int num = 0;
  ProjectNode* nodes = prjServer->QuerySelectedNodes( &num );
  if( num == 0 )  {
    OutStr( "No Nodes Selected" );
    return;
  }   

  IToolServer* toolServer = GET_INTERFACE( IToolServer );
  ToolObj cppToAsm = toolServer->ToolFind( MakePolyString("CppToAssembler") );
  if( cppToAsm )  {
    for(int i = 0; i < num; i++ )  {
       IProjectNodeInfo* _nodeInfo = prjServer->QueryNodeInfo( nodes[i] );
       IProjectNodeInfo2* nodeInfo = QUERY_INTERFACE( _nodeInfo, IProjectNodeInfo2 );
       _nodeInfo->Release();
       if( nodeInfo )  {
         char buf[64];
         ToolObj oldTool = nodeInfo->GetTranslator();
         IToolInfo* toolInfo = toolServer->QueryToolInfo( oldTool );
         IPolyString* toolName = toolInfo->GetName();
         IPolyString* nodeName = nodeInfo->GetName();
         toolInfo->Release();
         nodeInfo->Release();
         wsprintf( buf, "Node: %s  OldTool: %s", 
                   nodeName->GetCstr(), toolName->GetCstr() );
         OutStr( buf );
         nodeName->Release();
         toolName->Release();
       }
       prjServer->NodeSetTranslator( nodes[i], cppToAsm );
    }
  }
  toolServer->Release();
}       


//
// Marks selected nodes as dirty, meaning they will be recompiled during a 
// a make, even if not out of date. 
//
void ProjectTestB::MarkDirty()
{
  int num = 0;
  ProjectNode* nodes = prjServer->QuerySelectedNodes( &num );
  if( num == 0 )  {
    OutStr( "No Nodes Selected" );
    return;
  }

  for(int i = 0; i < num; i++)  {
    prjServer->NodeSetDirty( nodes[i] );
  }
}




