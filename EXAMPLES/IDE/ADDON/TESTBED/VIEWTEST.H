/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  viewtest.h
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.18  $
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __VIEWTEST_H
#define __VIEWTEST_H

#include <ideaddon\iview.h>
#include "tests.h"

//.............................................................................
class ViewTest : public TestObject {
 public:
  ViewTest();
  virtual ~ViewTest();

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
}; 


#endif    //  __VIEWTEST_H
