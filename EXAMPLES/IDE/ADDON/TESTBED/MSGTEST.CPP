/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   msgtest.cpp
   Created: 1/3/96
   Copyright (c) 1987, 1996 Borland International Inc.  All Rights Reserved.
   $Revision:   1.13  $
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <stdio.h> 
#include <ideaddon\iide.h>
#include "msgtest.h"

GenericMessageFolder::GenericMessageFolder(LPCSTR name) {
  IMessageSystem* pMsgSys;

  pMsgSys = GET_INTERFACE(IMessageSystem);

  d_folder = pMsgSys->NewFolder(MakePolyString(name));

  pMsgSys->Release();
  d_msgItem = 0;
};

void GenericMessageFolder::OpenFile(LPCSTR fileName, LPCSTR msg) {
  d_msgItem = d_folder->NewFileMessage( fileName ? MakePolyString(fileName) : 0
                                      , MakePolyString(msg));
}

void GenericMessageFolder::Log(LPCSTR msg) {
  d_folder->NewMessage(d_msgItem, MakePolyString(msg));
}

#define BUFSIZE 4096 
 
VOID GenericMessageFolder::ReadFromPipe(HANDLE hFile) { 
  /* Read output from child, and write it to parent's STDOUT. */ 

  DWORD dwRead, dwWritten; 
  CHAR chBuf[BUFSIZE+1]; 
  //
  // append a null terminator. this is needed by strtok
  //
  chBuf[BUFSIZE] = 0;
  for (;;) { 
      if (! ReadFile(hFile, chBuf, BUFSIZE, &dwRead, NULL) || 
          dwRead == 0) break; 

      chBuf[dwRead] = 0;
      if (! WriteMessage(chBuf, dwRead, &dwWritten)) 
          break; 
  }
} 

BOOL GenericMessageFolder::WriteMessage(LPSTR chBuf, DWORD /*dwRead*/, DWORD* /*dwWritten*/) {
  LPSTR pH = chBuf;
  LPSTR p = strtok(pH, "\n\r");
  while (p != NULL) {
    Log(p);
    p = strtok(NULL, "\n\r");
  };
  return 1;
}

DWORD ThreadFunc(LPDWORD lpdwParam) {
  GenericMessageFolder* folder = (GenericMessageFolder*)lpdwParam;
  folder->Run();
  return 0;
}

unsigned GenericMessageFolder::DoThread(LPCSTR cmd) {
  d_currentCmd = cmd;

  DWORD dwThreadId;
  HANDLE hThread;
  hThread = CreateThread(
      NULL,                       /* no security attributes       */
      0,                           /* use default stack size        */
      (LPTHREAD_START_ROUTINE) ThreadFunc, /* thread function      */
      (LPVOID)this,               /* argument to thread function   */
      0,                           /* use default creation flags    */
      &dwThreadId);               /* returns the thread identifier */

  /* Check the return value for success. */

  if (hThread == NULL)
    return 0;

  return 1;
};

void GenericMessageFolder::Run() {
  CreatePipedProcess((LPSTR)d_currentCmd);
};

DWORD GenericMessageFolder::CreatePipedProcess(LPSTR commandLine) { 

  HRESULT                hr     = NOERROR;
  SECURITY_ATTRIBUTES    sAttr   =
  {
    sizeof(SECURITY_ATTRIBUTES),
    0,
    TRUE
  };

  STARTUPINFO    siStartInfo;
  BOOL            bSuccess;

  memset(&siStartInfo, 0, sizeof(STARTUPINFO));
  siStartInfo.cb = sizeof(STARTUPINFO);

  // Create a pipe for the child's stdout.
  HANDLE          hPipeRead;      // The child's stdin.
  HANDLE          hPipeWrite;    // The child's stdout.

  if (!CreatePipe(  &hPipeRead,
                    &hPipeWrite,
                    &sAttr,
                    0)) {
    return  ResultFromScode(E_FAIL);
  }

  // Don't allow the child program to inherit the read end of the pipe.
  DuplicateHandle(GetCurrentProcess(),
                  hPipeRead,
                  GetCurrentProcess(),
                  0,
                  0,
                  FALSE,
                  DUPLICATE_SAME_ACCESS);

  siStartInfo.dwFlags    = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
  siStartInfo.hStdOutput  = hPipeWrite;
  siStartInfo.wShowWindow = SW_HIDE;

  // Start the child process.
  PROCESS_INFORMATION piProcInfo; 
  bSuccess = CreateProcess(NULL,
                           commandLine,
                           &sAttr,
                           &sAttr,
                           TRUE,
                           CREATE_NEW_PROCESS_GROUP,
                           0,
                           0,
                           &siStartInfo,
                           &piProcInfo);

  CloseHandle(hPipeWrite);
  
  if (bSuccess)
  {
    // Close the handles to the child process and thread.
    CloseHandle(piProcInfo.hThread);
    CloseHandle(piProcInfo.hProcess);
    ReadFromPipe(hPipeRead); 
  }

  CloseHandle(hPipeRead);
  
  return  hr;
}

/* ****************************************************************************
 *
 *
 */
MsgSystemTest::MsgSystemTest() {
   d_msgFolder1 = NULL;
   d_msgFolder2 = NULL;
}

MsgSystemTest::~MsgSystemTest() {
  UnInit();
}
//.............................................................................
BOOL MsgSystemTest::Init() 
{
  d_msgFolder1 = new GenericMessageFolder("Addon");
  d_msgFolder2 = new GenericMessageFolder("Addon");

  OutStr( "MsgSystemTest::Init()" );
  return FALSE;
}

void MsgSystemTest::UnInit() 
{
  OutStr( "MsgSystemTest::UnInit()" );
  if ( d_msgFolder1 ) {
     delete d_msgFolder1;
  }
  if ( d_msgFolder2 ) {
     delete d_msgFolder2;
  }    
}

const char * MsgSystemTest::GetName() 
{
  return "Message System Test";
}

const char * MsgSystemTest::GetTestDescription( int testNum) 
{
  switch ( testNum )
  {
    case 1:
      return "Create a message folder associated with a file";

    case 2:
      return "Display a meesage in folder created by test1";

    case 3:
      return "Create a message folder";

    case 4:
      return "Display a meesage in folder created by test3";
  }
  return "This test not implemented.";
}

void MsgSystemTest::DoTest( int testNum ) 
{
  switch ( testNum ) 
  {
    case 1:
      d_msgFolder1->OpenFile("msgtest.cpp", "Click this line to open file msgtest.cpp");
      break;
    case 2:
      // my test here 
      d_msgFolder1->DoThread("where find.*");
      d_msgFolder1->Log("Test output");
      break;
    case 3:
      d_msgFolder2->OpenFile(NULL, "Click this line to expand/collapse node");
      break;
    case 4:
      d_msgFolder2->Log("Test output");
      break;
    default: 
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      break;
  }
}
