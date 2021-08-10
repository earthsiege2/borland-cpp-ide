/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  maketest.h
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __MAKETEST_H
#define __MAKETEST_H

#include <ideaddon\imake.h>
#include "tests.h"

//.............................................................................
class MakeTestA : public TestObject {
 public:
  MakeTestA();
  virtual ~MakeTestA();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

  void ConcatPolyStr ( const char *startStr, IPolyString *pPoly, char *buf, int max, bool OutIt );

 protected:
  IMakeServer * _makeServer;
  IMakeClient * _makeClient;
}; 


#endif    //  __MAKETEST_H
