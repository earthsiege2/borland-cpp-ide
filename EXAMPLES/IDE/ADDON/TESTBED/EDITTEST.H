/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  edittest.h
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.18  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __EDITTEST_H
#define __EDITTEST_H

#include <ideaddon\ieditor.h>
#include "tests.h"

//.............................................................................
class EditTestA : public TestObject {
 public:
  EditTestA();
  virtual ~EditTestA();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  IEditorServer * _editServer;
}; 

//.............................................................................
class EditTestB : public TestObject {
 public:
  EditTestB();
  virtual ~EditTestB();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  IEditorServer * _editServer;
}; 

#endif    //  __EDITTEST_H
