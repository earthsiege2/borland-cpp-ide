//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// Tool to load, register, unregister, and debug OLE2 inproc servers and EXEs.
// Reads its command line to determine action, suggestion: use progman icons.
// Does no registration itself, simply invokes functions in the OC component.
// Brings up help dialog on empty command line; refer to that for usage info.
//----------------------------------------------------------------------------
#include <ocf/ocreg.h>
#include <classlib/cmdline.h>
#include <string.h>
#include "register.rh"
#include <shellapi.h>

#define DLLENTRY   "DllRegisterCommand"
#define MSDLLREGSERVERENTRY "DllRegisterServer"
#define MSDLLUNREGSERVERENTRY "DllUnregisterServer"
#define REGISTER32 "REGIST32.EXE"

//
// Error handling facility using local exception object
//
struct TLocalError {   // local exception object for this program
  TLocalError(const char* title, const char* message)
                  : Title(title),    Message(message) {}
  const char* Title;
  const char* Message;
};

static void Error(const char* title, const char* message)
{
  throw TLocalError(title, message);
}

static inline void ErrorIf(int error, const char* title, int resId)
{
  if (error)
    Error(title, (char*)resId);
}
static inline void ErrorIf(int error, int resId, const char* message)
{
  if (error)
    Error((char*)resId, message);
}

static inline void ErrorIf(int error, const char* title, const char* message)
{
  if (error)
    Error(title,message);
}


//
// File type determination
//

const int ftExists  = 1;
const int ftModule  = 2;
const int ftLibrary = 4;
const int ft32Bit   = 8;

int GetFileType(const char far* fileName)
{
  HFILE hdl = _lopen(fileName, OF_READ);
  if (hdl == HFILE_ERROR)
    return 0;
  int type = ftExists;
  char buf[64];
  if (_lread(hdl, buf, sizeof(buf)) == sizeof(buf) &&
      *(short*)(buf+0x00) == 0x5A4D &&  // check if executable image
      *(short*)(buf+0x18) == 0x0040) {  // check if NEWEXE type, not just DOS
    long offset = *(long*)(buf+0x3C);
    if (_llseek(hdl, offset, 0) != HFILE_ERROR &&
        _lread(hdl, buf, sizeof(buf)) == sizeof(buf)) {
      if (*(short*)(buf+0x00) == 0x454E) {        // check if 16-bit module
        type |= ftModule;
        if (*(short*)(buf+0x0C) & 0x8000)
          type |= ftLibrary;
      }
      else if (*(short*)(buf+0x00) == 0x4550) { // check if 32-bit module
        type |= (ftModule | ft32Bit);
        if (*(short*)(buf+0x16) & 0x2000)
          type |= ftLibrary;
      }
    }
  }
  _lclose(hdl);
  return type;
}

//
// DLL loading and entry point management class
//
struct TDllData {
  TDllData() : Lib(0)   {::OleInitialize(0);}
 ~TDllData() {FreeLib(); ::OleUninitialize();}

  bool LoadLib(const char* name);
  void FreeLib() {if (Lib) ::FreeLibrary(Lib); Lib = 0;}
  bool GetEntry();
  HRESULT CallEntry(const char far* cmdLine);

  HINSTANCE Lib;
  union {
    TDllRegisterCommand  DllRegisterCommand;
    HRESULT STDAPICALLTYPE (*MsDllRegServer)();
    HRESULT STDAPICALLTYPE (*MsDllUnRegServer)();
    FARPROC  DllRegProc;
  };
  bool DllRegisterCommandEntry;
};

bool TDllData::LoadLib(const char* name)
{
  DllRegProc = 0;
  FreeLib();
  if ((Lib=::LoadLibrary(name)) >= (HINSTANCE)HINSTANCE_ERROR)
    return true;
  Lib = 0;
  return false;
}

bool TDllData::GetEntry()
{
  if ((DllRegProc = ::GetProcAddress(Lib, DLLENTRY)) != 0) {
    DllRegisterCommandEntry = true;
    return true;
  }
  DllRegisterCommandEntry = false;  // Will have to call Dll[R|Unr]egisterServer
  // note:  we're getting the entry for DllRegisterServer but it may change
  // (in CallEntry) to the entry for DllUnregisterServer.
  return (DllRegProc = ::GetProcAddress(Lib, MSDLLREGSERVERENTRY)) != 0;
}

HRESULT TDllData::CallEntry(const char far* cmdLine)
{
  // It's one of ours
  if (DllRegisterCommandEntry)
    return (*DllRegisterCommand)(cmdLine);

  // We need to work with a lowercase command line
  TAPointer<char> lwcLine = new char[strlen(cmdLine)+1];
  strcpy(lwcLine, cmdLine);
  strlwr(lwcLine);

  // DllUnregisterServer
  if (strstr(lwcLine, "unregserver")) {
    if ((DllRegProc = ::GetProcAddress(Lib, MSDLLUNREGSERVERENTRY)) == 0)
      return ResultFromScode(E_UNEXPECTED);
    else
      return (*MsDllUnRegServer)();
  }

  // DllRegisterServer
  if (strstr(lwcLine, "regserver"))
    return (*MsDllRegServer)();

  // Neither RegServer nor UnRegServer Selected, just return
  return ResultFromScode(S_OK);
}

//
// Command option state flags
//
const int rfDone     = 1; // force break from loop
const int rfNoValue  = 2; // no value allowed for option
const int rfReqValue = 4; // value required for option
const int rfOptValue = 8; // optional value for option
const int rfDebug   = 16; // special test for debug option
const int rfTypeLib = 32; // check for typelib generation errors
const int rfRegServer=64; // check for registration errors
const int rfQuietReg=128; // suppress registry error reporting

//
// Command option table
//
struct {
  char*   String;
  int     Flags;
} table[] = {
  {"Language",   rfOptValue },
  {"RegServer",  rfOptValue | rfRegServer },
  {"UnregServer",rfNoValue },
  {"TypeLib",    rfOptValue | rfTypeLib },
  {"Debug",      rfNoValue | rfDebug },
  {"QuietReg",   rfQuietReg | rfNoValue },
};
const int tableCount = sizeof(table)/sizeof(table[0]);

#define MAX_CMD_LINE 256

bool CALLBACK __export
HelpProc(HWND hDlg, UINT msg, WPARAM /*wParam*/, LPARAM /*lParam*/)
{
  if (msg != WM_COMMAND)
    return msg == WM_INITDIALOG;
  ::EndDialog(hDlg, TRUE);
  return true;
}

int PASCAL
WinMain(HINSTANCE hInst, HINSTANCE/*hPrev*/, char far* cmdLine, int/*show*/)
{
  TCmdLine cmd(cmdLine);
  TDllData dll;
  int optFlags;
  int curFlags;
  char cmdbuf[MAX_CMD_LINE + sizeof(REGISTER32)];  // complete command line
  char modName[MAX_CMD_LINE]; // copy of module name only, including file path
  char* execmd;               // command line for EXE, include module path
  char* regcmd;               // command line for DLL, no file path
  char* cmdptr;
  int tblIndex;
  char regBuf[80];            // holds error string from registry

  try {
    if (cmd.NextToken() != TCmdLine::Name)
      return ::DialogBox(hInst, MAKEINTRESOURCE(IDD_HELP), 0,(DLGPROC)HelpProc);
    do {   // module loop
      optFlags = 0;
      curFlags = rfNoValue;
      strcpy(cmdbuf, REGISTER32);  // set up to spawn 32-bit tool from 16-bit
      execmd = cmdbuf + strlen(cmdbuf);
      *execmd++ = ' ';             // start of command line for EXE
      memcpy(execmd, cmd.Token, cmd.TokenLen);
      cmdptr = execmd + cmd.TokenLen;
      *cmdptr = 0;   // temp. terminate for strchr and strcpy
      if ((regcmd = strchr(execmd, '+')) != 0)  // test for "tdw+module.exe"
        *regcmd++ = ' ';
      else
        regcmd = execmd;
      strcpy(modName, regcmd);
      *cmdptr++ = ' ';
      regcmd = cmdptr;             // reg options only, for DLL, no pathname
      strcpy(cmdptr, "/QuietReg ");
      cmdptr += strlen(cmdptr);
      do {
        switch (cmd.NextToken()) {
          case TCmdLine::Name:
          case TCmdLine::Done:
            ErrorIf(!optFlags, modName, IDS_NOOPTIONS);
            curFlags |= rfDone;  // break out of loop
            continue;
          case TCmdLine::Option:
            tblIndex = 0;
            while (strnicmp(cmd.Token, table[tblIndex].String, cmd.TokenLen))
              ErrorIf(++tblIndex == tableCount, IDS_UNKNOWNOPT, cmd.Token);
            curFlags = table[tblIndex].Flags;
            optFlags |= curFlags;
            if (curFlags & rfQuietReg)
              break;
            *cmdptr++ = '/'; // use slash for option, dash needs leading space
            strcpy(cmdptr, table[tblIndex].String);
            cmdptr += strlen(table[tblIndex].String);
            break;
          case TCmdLine::Value:
            ErrorIf((curFlags & rfNoValue), cmd.Token, IDS_MISSINGOPT);
            curFlags = rfNoValue;   // prevent another value without option
            *cmdptr++ = '=';
            memcpy(cmdptr, cmd.Token, cmd.TokenLen);
            cmdptr += cmd.TokenLen;
            break;
        }
      } while (!(curFlags & rfDone));
      *cmdptr = 0;

      int fileType = GetFileType(modName);
      ErrorIf(!(fileType & ftExists), IDS_NOFINDMOD,  modName);
      ErrorIf(!(fileType & ftModule), IDS_INVALIDMOD, modName);
      if (fileType & ftLibrary) {
#ifdef __WIN32__
        ErrorIf(!(fileType&ft32Bit),IDS_CANTLOAD16,modName);
        {
#else
        if (fileType & ft32Bit) {
          uint execStat = ::WinExec(cmdbuf, SW_SHOW);
          ErrorIf(execStat < (uint)HINSTANCE_ERROR, IDS_CANTLOAD32, modName);
        }
        else {
#endif
          ErrorIf(!dll.LoadLib(modName), IDS_NOLOADMOD, modName);
          ErrorIf(!dll.GetEntry(), IDS_NOENTRYPNT, DLLENTRY);
          ErrorIf(dll.CallEntry(regcmd) != NOERROR, IDS_REGFAILURE, execmd);
          if (optFlags & rfDebug)
            ::MessageBox(0, "Press OK to unload when debugging is finished",
                         "DLL loaded for debugging", MB_OK);
        }
      }
      else {
        uint execStat = ::WinExec(execmd, SW_HIDE);
        ErrorIf(execStat < (uint)HINSTANCE_ERROR, IDS_NOLOADMOD, modName);
      }
      if (optFlags & rfQuietReg) // ignore errors if spawned from another app
        continue;
      long buflen = sizeof(regBuf);
      if ((optFlags & rfRegServer) && S_OK ==
          ::RegQueryValue(TRegKey::ClassesRoot,"OcErr_RegServer", regBuf,&buflen)){
        ::RegDeleteKey(TRegKey::ClassesRoot, "OcErr_RegServer");
        Error((char*)IDS_REGFAILURE, regBuf);
      }
      if ((optFlags & rfTypeLib) && S_OK ==
          ::RegQueryValue(TRegKey::ClassesRoot, "OcErr_Typelib", regBuf,&buflen)){
        ::RegDeleteKey(TRegKey::ClassesRoot, "OcErr_Typelib");
        Error((char*)IDS_TYPELIBERR, regBuf);
      }
    } while (cmd.Kind != TCmdLine::Done);
    return 0;
  }

  catch (TLocalError& xcpt) {
    char msgbuf[80];
    const char ** pmsg;
    if (*(pmsg = &xcpt.Message) <= (const char*)IDS_MAX ||
        *(pmsg = &xcpt.Title)   <= (const char*)IDS_MAX)
    {
      ::LoadString(hInst, *(unsigned*)pmsg, msgbuf, sizeof(msgbuf));
      *pmsg = msgbuf;
    }
    ::MessageBox(0, xcpt.Message, xcpt.Title, MB_OK);
  }
  catch (xmsg& xcpt) {    // should not occur, but check anyway while catching
    ::MessageBox(0, xcpt.why().c_str(), "Exception", MB_OK);
  }
  return 1;
}
