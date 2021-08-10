/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  project.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\iproj.h>
#include <ideaddon\ioption.h>
#include "project.h"

//.............................................................................
ProjectTestA::ProjectTestA() {
  _projectClient = NULL;
  _curProjectName = NULL;
  _projectServer = GET_INTERFACE( IProjectServer );
  if ( _projectServer ) {
    registerForEvents();
  }
}
//.............................................................................
ProjectTestA::~ProjectTestA() {
  if ( _projectClient ) {
    if ( _projectServer ) {
    _projectClient->AddRef();
      _projectServer->UnregisterProjectClient( _projectClient );
    }
    _projectClient->Release();
   _projectClient = 0;
  }
  if ( _projectServer ) {
    _projectServer->Release();
  }
  if ( _curProjectName ) {
    _curProjectName->Release();
  }
}
//.............................................................................
BOOL ProjectTestA::registerForEvents() {
  if ( !_projectClient ) {
    _projectClient = new ProjectClientImpl( this, _projectServer );
  }
  if ( _projectServer ) {
   _projectClient->AddRef();
    _projectServer->RegisterProjectClient( _projectClient );
    return TRUE;
  }
  return FALSE;
}
//.............................................................................
BOOL ProjectTestA::Init() {
  OutStr( "ProjectTestA::Init()" );

  if ( _projectServer && _projectClient ) {
    OutStr( "ProjectServer and ProjectClient objects are alive." );
    _projectClient->ShowEvents( TRUE );
  }   
  return TRUE;
}
//.............................................................................
void ProjectTestA::UnInit() {
  OutStr( "ProjectTestA::UnInit()" );
  if ( _projectClient ) {
    _projectClient->ShowEvents( FALSE );
  }

}
//.............................................................................
const char * ProjectTestA::GetName() {
  return "Project Test A";
}
//.............................................................................
const char * ProjectTestA::GetTestDescription( int testNum ) {
  switch ( testNum ) {
    case 1: 
      return "Shows the number of selected project nodes.";
    case 2: 
      return "Returns info about the top node.";
    case 3:
      return "Show info about the current node.";
    case 4:
      return "Show info about the parent node.";
  }
  return "This test not implemented.";
}  
//.............................................................................
void ProjectTestA::showNodeInfo( ProjectNode node ) {
  IProjectNodeInfo * info = _projectServer->QueryNodeInfo( node );
  if ( info ) {
    OutStr( FormatStr( "Node info for node %u follows...", node ) );
    ShowPolyStr( "Name = ", info->GetName(), TRUE );
    ShowPolyStr( "Type = ", info->GetNodeType(), TRUE );
    ShowPolyStr( "Description = ", info->GetDescription(), TRUE );
    ShowPolyStr( "InputLocation = ", info->GetInputLocation(), TRUE );
    ShowPolyStr( "OutputLocation = ", info->GetOutputLocation(), TRUE );
    info->Release();
  }
}
//.............................................................................
void ProjectTestA::DoTest( int testNum ) {
  if ( !_projectServer ) {
    OutStr( "Project Server not initialized!" );
    return;
  }
  switch ( testNum ) {
    case 1: {
      int numNodes;  // num selected nodes
      _projectServer->QuerySelectedNodes( &numNodes );
      OutStr( FormatStr( "%d Nodes selected.", numNodes ) );
      break;
    }
    case 2: { // top node info
      ProjectNode node = _projectServer->QueryTopNode();
      showNodeInfo( node );
      break;
    }
    case 3: { // current node info
      int numNodes;
      ProjectNode * nodes = _projectServer->QuerySelectedNodes( &numNodes );
      if ( numNodes ) {
        OutStr( "Current node found..." );
        showNodeInfo( nodes[0] );
      }
      else {
        OutStr( "No node selected." );
      }
      break;
    }
    case 4: { // node parent info
      int numNodes;
      ProjectNode * nodes = _projectServer->QuerySelectedNodes( &numNodes );
      if ( numNodes ) {
        IProjectNodeInfo * info = _projectServer->QueryNodeInfo( nodes[0] );
        if ( info ) {
          ProjectNode parent = info->GetParent();
          if ( parent ) {
            OutStr( "Parent node found..." );
            showNodeInfo( parent );
          }
          else {
            OutStr( "No parent node found." );
          }
          info->Release();
        }
      }
      else {
        OutStr( "No node selected." );
      }
      break;
    }
    default: {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
    }
  }
}
/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  ProjectClientImpl 
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
void ProjectClientImpl::ShowPolyStr( const char * label, IPolyString * ps, BOOL release ) {
  if ( _showEvents ) {
    _testObj->ShowPolyStr( label, ps, release );
  }
}
//.............................................................................
IPolyString * ProjectClientImpl::nodeName( ProjectNode node ) {
  //
  // The caller of this method must Release() the returned polystring
  //
  if ( _projectServer ) {
    IProjectNodeInfo * info = _projectServer->QueryNodeInfo( node );
    if ( info ) {
      return info->GetName();
    }
  }
  return NULL;
}
//.............................................................................
void ProjectClientImpl::OpenNotify( IPolyString * projectName ) {
  if ( _curProjectName ) {
    _curProjectName->Release();
    _curProjectName = NULL;
  }
  if ( projectName ) {
    _curProjectName = projectName;
  }
  ShowPolyStr( "Project Opening", _curProjectName, FALSE );
}
//.............................................................................
void ProjectClientImpl::CloseNotify() {
  ShowPolyStr( "Project Closing", _curProjectName, FALSE );
}
//.............................................................................
void ProjectClientImpl::NodeDeleteNotify( ProjectNode node ) {
  ShowPolyStr( "Node Delete", nodeName( node ), TRUE );
}
//.............................................................................
void ProjectClientImpl::NodeAddNotify( ProjectNode node ) {
  ShowPolyStr( "Node Add", nodeName( node ), TRUE );
}
//.............................................................................
void ProjectClientImpl::NodeCopyNotify( ProjectNode node, ProjectNode newParent, BOOL reference ) {
  ShowPolyStr( "Node Copied", nodeName( node ), TRUE );
  ShowPolyStr( "-- new parent", nodeName( newParent ), TRUE );
  if ( reference ) {
    _testObj->OutStr( "-- this was a reference copy." );
  }
}
//.............................................................................
void ProjectClientImpl::NodeMoveNotify( ProjectNode node, ProjectNode oldParent ) {
  ShowPolyStr( "Node Moved", nodeName( node ), TRUE );
  ShowPolyStr( "-- old parent", nodeName( oldParent ), TRUE );
} 
//.............................................................................
void ProjectClientImpl::NodeChangeNotify( ProjectNode node ) {
  ShowPolyStr( "Node Changed", nodeName( node ), TRUE );
}
//.............................................................................
void ProjectClientImpl::DependencyQueryResponder( ProjectNode /*node*/, 
                          IPolyString * /*outputName*/ ) {}

  
