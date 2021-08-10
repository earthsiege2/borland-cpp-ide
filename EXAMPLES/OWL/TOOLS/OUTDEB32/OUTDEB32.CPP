//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/serialze.h>
#include <iostream.h>
#include <cstring.h>
#include <ctype.h>

#define DIAGXPRT "DiagXprt"

//
// class TDebugProcess
// ~~~~~ ~~~~~~~~~~~~~
class TDebugProcess {
  public:
    TDebugProcess(string progName, string cmdLine);
    bool Execute();

    virtual uint32 Exception(EXCEPTION_DEBUG_INFO)              { return ContinueEvent(); }
    virtual uint32 CreateThread(CREATE_THREAD_DEBUG_INFO)       { return ContinueEvent(); }
    virtual uint32 CreateProcess(CREATE_PROCESS_DEBUG_INFO)     { return ContinueEvent(); }
    virtual uint32 ExitThread(EXIT_THREAD_DEBUG_INFO)           { return ContinueEvent(); }
    virtual uint32 ExitProcess(EXIT_PROCESS_DEBUG_INFO)         { return ContinueEvent(); }
    virtual uint32 LoadDll(LOAD_DLL_DEBUG_INFO)                 { return ContinueEvent(); }
    virtual uint32 UnloadDll(UNLOAD_DLL_DEBUG_INFO)             { return ContinueEvent(); }
    virtual uint32 OutputDebugString(OUTPUT_DEBUG_STRING_INFO)  { return ContinueEvent(); }
    virtual uint32 RIP(RIP_INFO)                                { return ContinueEvent(); }

    HANDLE GetProcessHandle()    { return pi.hProcess; }
    HANDLE GetThreadHandle()     { return pi.hThread; }
    uint32 GetProcessId()        { return pi.dwProcessId; }
    uint32 GetThreadId()         { return pi.dwThreadId; }

  private:
    uint32 ContinueEvent()        { return DBG_CONTINUE; }
    uint32 ExceptionNotHandled()  { return DBG_EXCEPTION_NOT_HANDLED; }

    string ProgName;
    string CmdLine;
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    DEBUG_EVENT de;
};

//
//
//
TDebugProcess::TDebugProcess(string progName, string cmdLine) :
  ProgName(progName), CmdLine(cmdLine)
{
  memset(&pi, 0, sizeof pi);
  memset(&de, 0, sizeof de);
  memset(&si, 0, sizeof si);
  si.cb = sizeof si;
}

//
//
//
bool
TDebugProcess::Execute()
{
  char* commandLine = new char[CmdLine.length()+1];
  lstrcpy(commandLine, CmdLine.c_str());

  HWND diagXprt = ::FindWindow(DIAGXPRT, 0);
  if (IsWindow(diagXprt))  {
    TSerializer(diagXprt, ProgName.length()+1, (void far*)ProgName.c_str());
    TSerializer(diagXprt, 2, " ");
    TSerializer(diagXprt, CmdLine.length()+1, (void far*)CmdLine.c_str());
    TSerializer(diagXprt, 3, "\r\n");
  }
  else {
    cerr << "ProgName = " << ProgName << endl;
    cerr << "CommandLine = " << "'" << commandLine << "'" << endl;
  }

  if (::CreateProcess(ProgName.c_str(), commandLine, 0, 0, 0, DEBUG_PROCESS, 0, 0, &si, &pi)) {
    bool done = false;
    while (!done) {
      ::WaitForDebugEvent(&de, INFINITE);
      uint32 continueCode = 0;
      switch (de.dwDebugEventCode) {
        case EXCEPTION_DEBUG_EVENT:
          continueCode = Exception(de.u.Exception);
          break;
        case CREATE_THREAD_DEBUG_EVENT:
          continueCode = CreateThread(de.u.CreateThread);
          break;
        case CREATE_PROCESS_DEBUG_EVENT:
          continueCode = CreateProcess(de.u.CreateProcessInfo);
          break;
        case EXIT_THREAD_DEBUG_EVENT:
          continueCode = ExitThread(de.u.ExitThread);
          break;
        case EXIT_PROCESS_DEBUG_EVENT:
          continueCode = ExitProcess(de.u.ExitProcess);
          break;
        case LOAD_DLL_DEBUG_EVENT:
          continueCode = LoadDll(de.u.LoadDll);
          break;
        case UNLOAD_DLL_DEBUG_EVENT:
          continueCode = UnloadDll(de.u.UnloadDll);
          break;
        case OUTPUT_DEBUG_STRING_EVENT:
          continueCode = OutputDebugString(de.u.DebugString);
          break;
        case RIP_EVENT:
          continueCode = RIP(de.u.RipInfo);
          break;
      }
      if (de.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT)
        done = true;
      ::ContinueDebugEvent(GetProcessId(), GetThreadId(), continueCode);
    }
  }
  else {
    cerr << "Last Error = " << GetLastError() << endl;
    return false;
  }
  delete []commandLine;
  return true;
}


//
// class TOutputDebugProcess
// ~~~~~ ~~~~~~~~~~~~~~~~~~~
class TOutputDebugProcess : public TDebugProcess {
  public:
    TOutputDebugProcess(string progName, string cmdLine);
    uint32 OutputDebugString(OUTPUT_DEBUG_STRING_INFO);
};


//
//
//
TOutputDebugProcess::TOutputDebugProcess(string progName, string cmdLine)
:
  TDebugProcess(progName, cmdLine)
{
}


//
//
//
uint32
TOutputDebugProcess::OutputDebugString(OUTPUT_DEBUG_STRING_INFO odsi)
{
  if (odsi.fUnicode == 0) {
    // ascii
    //
    char* msg = new char[odsi.nDebugStringLength+1];
    uint32 bytesRead = 0;
    if (::ReadProcessMemory(GetProcessHandle(), odsi.lpDebugStringData, msg,
      odsi.nDebugStringLength, &bytesRead)) {
      msg[bytesRead] = 0;

      // remove trailing whitespace
      //
      if (strlen(msg) > 0) {
        HWND diagXprt = ::FindWindow(DIAGXPRT, 0);
        if (IsWindow(diagXprt))
          TSerializer(diagXprt, bytesRead, msg);
        else
          cerr << msg;
      }
    }
    delete[] msg;
  }
  return TDebugProcess::OutputDebugString(odsi);
}


//
//
//
void
DebugProgram(char* progName, string& cmdLine)
{
  TOutputDebugProcess odp(progName, cmdLine);
  odp.Execute();
}


//
//
//
int
main(int argc, char *argv[])
{
  if (argc < 2) {
    cerr << "Wrong number of arguments." << endl;
    cerr << "Usage: " << endl;
    cerr << argv[0] << " debuggee.exe [args to debuggee]" << endl;
    return -1;
  }

  // rebuild cmdline arguments to debuggee
  //
  string cmdLine;
  if (argc > 2) {
    for (int i = 2; i < argc; i++) {
      cmdLine += argv[i];
      if (i != argc-1)
        cmdLine += " ";
    }
  }

  try {
    DebugProgram(argv[1], cmdLine);
  }
  catch (TXBase& xBase) {
    cerr << "Exception caught!" << endl;
    cerr << xBase.why().c_str() << endl;
  }

  return 0;
}

