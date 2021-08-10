/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  tool2.h
  Created: 12/21/95
  Copyright (c) 1987, 1995 Borland International Inc.  All Rights Reserved.
  $Revision:   1.11  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __TOOL2_H
#define __TOOL2_H

#include <ideaddon\itool.h>
#include <ideaddon\iproj.h>
#include <ideaddon\comhelp.h>
#include "tests.h"

class ToolTestC;    

//.............................................................................
class ToolInvoker : public IUnknownImp< IToolImplementor > {
 public:
  ToolInvoker() : IUNKNOWNIMPL_INIT( IToolImplementor ) {}
  virtual ToolReturn Execute( 
                IPolyString * cmdLine, 
                ProjectNode * nodeArray, 
                int numNodes );
};
//.............................................................................
class ProjectClient : public IUnknownImp< IProjectClient > {
 public:
  ProjectClient() : IUNKNOWNIMPL_INIT( IProjectClient ) { _toolTest = NULL; }
  virtual void OpenNotify( IPolyString * projectName );
  virtual void CloseNotify();
  virtual void NodeDeleteNotify( ProjectNode node ) {}
  virtual void NodeAddNotify( ProjectNode node ) {}
  virtual void NodeCopyNotify( ProjectNode, ProjectNode, BOOL ) {}
  virtual void NodeMoveNotify( ProjectNode, ProjectNode ) {}
  virtual void NodeChangeNotify( ProjectNode ) {}
  virtual BOOL HandleAddNodeUI() { return FALSE; }
  virtual void DependencyQueryResponder( ProjectNode /*node*/, 
                            IPolyString * outputName ) {
    outputName->Release();
  }
  void RegisterToolTest( ToolTestC * tt ) { _toolTest = tt; }
 protected:
  ToolTestC * _toolTest;
  
};
//.............................................................................
class ToolTestC : public TestObject {
 public:
  ToolTestC();
  virtual ~ToolTestC();
  //........ TestObject Interface Methods .......
  virtual BOOL Init() { return TRUE; }
  virtual void UnInit() {}  
  virtual const char * GetName() { return "ToolTestC"; }
  virtual const char * GetTestDescription( int /*testNum*/ ) { return "Does Nothing"; }
  virtual void DoTest( int /*testNum*/ ) {}
  
  void RegisterTool();
  void UnregisterTool();
  void SetToolName( IPolyString * name ) { _toolName = name; }
  
 protected:
  IToolServer * _toolServer;
  IProjectServer * _projectServer;
  ProjectClient *_projectClient;
  ToolInvoker  *_toolInvoker;
  IPolyString * _toolName;
}; 

#endif    //  __TOOL2_H
