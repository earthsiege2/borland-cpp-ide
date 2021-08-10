/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   Created: 1/3/96
   Copyright (c) 1987, 1996 Borland International Inc.  All Rights Reserved.
   $Revision:   1.12  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 

#ifndef __MSGTEST_H
#define __MSGTEST_H

#include <ideaddon\imsgsys.h>
#include "tests.h"

struct GenericMessageFolder {
  GenericMessageFolder(LPCSTR name);
  void OpenFile(LPCSTR fileName, LPCSTR msg);
  void Log(LPCSTR msg);

  DWORD CreatePipedProcess(LPSTR commandLine);
  VOID  ReadFromPipe(HANDLE hFile);
  BOOL  WriteMessage(LPSTR chBuf, DWORD dwRead, DWORD* dwWritten);
  void  Run();
  unsigned DoThread(LPCSTR cmd);


protected:
  IMessageFolder* d_folder;
  HMSGITEM        d_msgItem;
  LPCSTR          d_currentCmd;
};


class MsgSystemTest : public TestObject {
 public:
  MsgSystemTest();
  ~MsgSystemTest();

  //........ TestObject Methods .......
  virtual BOOL Init();
  virtual void UnInit();  
  virtual const char * GetName();
  virtual const char * GetTestDescription( int testNum );
  virtual void DoTest( int testNum );

 protected:
  GenericMessageFolder* d_msgFolder1;
  GenericMessageFolder* d_msgFolder2;

}; 



#endif // __MSGTEST_H
