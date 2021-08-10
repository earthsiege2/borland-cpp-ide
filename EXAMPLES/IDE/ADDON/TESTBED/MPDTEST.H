/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  mpdtest.h
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.18  $
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __MPDTEST_H
#define __MPDTEST_H

#include <ideaddon\impd.h>
#include "tests.h"

//.............................................................................
class MpdTest : public TestObject {

public:
  MpdTest();
  ~MpdTest();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

  void ConcatPolyStr ( const char *startStr, IPolyString *pPoly, char *buf, int max, bool OutIt );

protected:
  void DoTest1();
  void DoTest2();
  void DoTest3();
  void DoTest4();

  IMpdServer* d_impdServer;
  IMpdChapter* d_chapEnv;
  IMpdChapter* d_chapPrj;

}; 


#endif    //  __MPDTEST_H
