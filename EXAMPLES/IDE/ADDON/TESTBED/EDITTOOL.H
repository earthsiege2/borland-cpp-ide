/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  edittool.h
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.10  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __EDITTOOL_H
#define __EDITTOOL_H

#include <ideaddon\itool.h>
#include "tests.h"

//.............................................................................
class EditToolTest : public TestObject {
 public:
  EditToolTest();
  virtual ~EditToolTest();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  IToolServer * _toolServer;
}; 


#endif    //  __EDITTOOL_H
