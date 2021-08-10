/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  prset.h
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __PRSET_H
#define __PRSET_H

#include <ideaddon\iprset.h>
#include "tests.h"

//.............................................................................
class PrinterSettingsTest : public TestObject {
 public:
  PrinterSettingsTest();
  virtual ~PrinterSettingsTest();

  //........ TestObject Interface Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );
}; 

#endif    //  __PRSET_H
