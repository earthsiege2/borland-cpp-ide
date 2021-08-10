/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  option.h
  Created: 10/24/95
  Copyright (c) 1995, 1996 Borland International
  $Revision:   1.18  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __OPTION_H
#define __OPTION_H

#include <ideaddon\ioption.h>
#include <ideaddon\iproj.h>
#include "tests.h"

//.............................................................................
//
// This class is used to do a simple test of the OptionSet server, see
// option.cpp for further details.
//
class OptionSetTestA : public TestObject {
 public:
  OptionSetTestA();
  virtual ~OptionSetTestA();

  //........ TestObject Interface Methods (see tests.h) .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );
 protected:
  IOptionSetServer * _optionSetServer;
  IProjectServer * _projectServer;
}; 

#endif    //  __OPTION_H
