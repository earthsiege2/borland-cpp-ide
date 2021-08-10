/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  toolsrvr.h
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.19  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __TOOLSRVR_H
#define __TOOLSRVR_H

#include <ideaddon\itool.h>
#include <ideaddon\iproj.h>
#include "tests.h"

//.............................................................................
class ToolTestA : public TestObject {
 public:
  ToolTestA();
  virtual ~ToolTestA();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

  void ConcatPolyStr ( const char *startStr, IPolyString *pPoly, char *buf, int max, bool OutIt );

 protected:
  IToolServer * _toolServer;
}; 

class ToolTestB : public TestObject, public IUnknownImp< IProjectSaveClient > {
 public:
  ToolTestB();
  virtual ~ToolTestB();

  void AddTool();
  void RemoveTool();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );
  
  //....... IProjectSaveClient ..........
  virtual void BeforeSaveNotify();
  virtual void AfterSaveNotify();

 protected:
  IToolServer  * _toolServer;
  IProjectServer * _projectServer;
  IProjectClient * _projectClient;
}; 

//.............................................................................
class ProjectToolClient : public IUnknownImp< IProjectClient > 
{
 public:
  ProjectToolClient( ToolTestB * tB ) : IUNKNOWNIMPL_INIT( IProjectClient ) 
    {
    _toolTestB = tB;
    _currentProject = NULL;
    }

  //.... IProjectClient methods ....
  virtual void OpenNotify( IPolyString * projectName );
  virtual void CloseNotify();
  virtual void NodeDeleteNotify( ProjectNode node ) {}
  virtual void NodeAddNotify( ProjectNode node ) {}
  virtual void NodeCopyNotify( ProjectNode, ProjectNode, BOOL ) {}
  virtual void NodeMoveNotify( ProjectNode, ProjectNode ) {}
  virtual void NodeChangeNotify( ProjectNode ) {}
  virtual void DependencyQueryResponder( ProjectNode node, 
                            IPolyString * outputName ) {}
  virtual BOOL HandleAddNodeUI() { return FALSE; }
 protected:
  ToolTestB * _toolTestB;
  IPolyString * _currentProject; 
};

#endif    //  __TOOLSRVR_H
