/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  script.h
  Created: 10/28/95
  Copyright (c) 1995, Borland International
  $Revision:   1.18  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __SCRIPT_H
#define __SCRIPT_H

#include <ideaddon\iscript.h>
#include "tests.h"

//.............................................................................
class ScriptTestA : public TestObject {
 public:
  ScriptTestA();
  virtual ~ScriptTestA();

  //........ TestObject Interface Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );
 protected:
  IScriptServer * _scriptServer;
}; 

#endif    //  __SCRIPT_H
