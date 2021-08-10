/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  cmdtest.h
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.13  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __CMDTEST_H
#define __CMDTEST_H

#include <ideaddon\icmd.h>
#include "tests.h"

//.............................................................................
class CmdTestA : public TestObject {
 public:
  CmdTestA();
  ~CmdTestA();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  ICommandServer *  _cmdServer;
  bool          _startInitFailed;
// CommandClientA *  _client;

}; 


#endif    //  __CMDTEST_H
