/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  project.h
  Created: 10/24/95
  Copyright (c) 1995, 1996 Borland International
  $Revision:   1.15  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __PROJECT_H
#define __PROJECT_H

//.... interface directory headers ....
#include <ideaddon\iproj.h>
#include <ideaddon\comhelp.h>

//.... local headers ....
#include "tests.h"

class ProjectTestA;  // forward declaration

//.............................................................................
class ProjectClientImpl : public IUnknownImp< IProjectClient > 
{
 public:
  ProjectClientImpl( ProjectTestA * pt, IProjectServer * ps ) 
      : IUNKNOWNIMPL_INIT( IProjectClient ) {
    _curProjectName = NULL;
    _projectServer = ps;
    _testObj = pt;
    _showEvents = FALSE;
  }

  void ShowEvents( BOOL b ) { _showEvents = b; }

  void ShowPolyStr( const char * label, IPolyString * ps, BOOL release );
  
  //.... IProjectClient methods ....
  virtual void OpenNotify( IPolyString * projectName );
  virtual void CloseNotify();
  virtual void NodeDeleteNotify( ProjectNode node );
  virtual void NodeAddNotify( ProjectNode node );
  virtual void NodeCopyNotify( ProjectNode node, ProjectNode newParent, BOOL reference );
  virtual void NodeMoveNotify( ProjectNode node, ProjectNode oldParent );
  virtual void NodeChangeNotify( ProjectNode node );
  virtual void DependencyQueryResponder( ProjectNode node, 
                            IPolyString * outputName );
  virtual BOOL HandleAddNodeUI() { return FALSE; }
                            
 protected:
  IPolyString * nodeName( ProjectNode node );

  BOOL _showEvents;
  IPolyString * _curProjectName;
  IProjectServer * _projectServer;
  ProjectTestA * _testObj;
};

//.............................................................................
class ProjectTestA : public TestObject {
 public:
  ProjectTestA();
  virtual ~ProjectTestA();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  BOOL registerForEvents();
  void showNodeInfo( ProjectNode node );

  IProjectServer * _projectServer;
  ProjectClientImpl * _projectClient;
  IPolyString * _curProjectName;
}; 

#endif    //  __PROJECT_H
