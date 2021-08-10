/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  target.h
  Created: 10/26/95
  Copyright (c) 1995, 1996 Borland International
  $Revision:   1.15  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __TARGET_H
#define __TARGET_H

//.... interface headers .....
#include <ideaddon\itarg.h>

//.... example headers .....
#include "tests.h"

//.............................................................................
class TargetTestA : public TestObject {
 public:
  TargetTestA();
  virtual ~TargetTestA();

  //........ TestObject Interface Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  ITargetServer * _targetServer;
  LPUNKNOWN    d_owlTarget;

}; 

#endif    //  __TARGET_H
