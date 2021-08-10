/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  filetest.h
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:  
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __FILETEST_H
#define __FILETEST_H

#include <ideaddon\ivfile.h>
#include "tests.h"

//.............................................................................
class FileTestA : public TestObject {
 public:
  FileTestA();
  virtual ~FileTestA();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  IVirtualFile * _vFile;
}; 

#endif    //  __FILETEST_H
