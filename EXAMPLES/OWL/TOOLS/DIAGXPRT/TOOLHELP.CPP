//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1995, 1995 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <stdlib.h>
#include <stdio.h>
#include "diagxprt.h"
#include <toolhelp.h>

char  TToolHelp::buffer[1024];
struct  TToolHelp::ERRMAP TToolHelp::errmap[] = {
#if defined(BI_PLAT_WIN16)
  { ERR_GALLOC,     "GlobalAlloc failed" },
  { ERR_GREALLOC,   "GlobalReAlloc failed" },
  { ERR_GLOCK,      "GlobalLock failed" },
  { ERR_LALLOC,     "LocalAlloc failed" },
  { ERR_LREALLOC,   "LocalReAlloc failed" },
  { ERR_LLOCK,      "LocalLock failed" },
#endif
  { ERR_ALLOCRES,   "AllocResource failed" },
  { ERR_LOCKRES,    "LockResource failed" },
  { ERR_LOADMODULE, "LoadModule failed" },

  { ERR_CREATEDLG,  "CreateDialog() failed: Couldn't load menu or create window" },
  { ERR_CREATEDLG2, "CreateDialog() failed: Couldn't create window" },
  { ERR_REGISTERCLASS, "RegisterClass failed: Class already exists" },
  { ERR_DCBUSY,     "DC Cache full: Too many GetDC() calls" },
  { ERR_CREATEWND,  "CreateWindow failed: Window class not found" },
  { ERR_STRUCEXTRA, "Unallocated extra window/class word index used" },
  { ERR_LOADSTR,    "LoadString() failed" },
  { ERR_LOADMENU,   "LoadMenu() failed" },
  { ERR_NESTEDBEGINPAINT, "Nested BeginPaint() calls" },
  { ERR_BADINDEX,   "Invalid window word index value" },
  { ERR_CREATEMENU, "CreateMenu failed" },

  { ERR_CREATEDC,   "CreateDC failed" },
  { ERR_CREATEMETA, "CreateMetafile: Can't create metafile" },
  { ERR_SELBITMAP,  "Bitmap already selected" },
  { ERR_DELOBJSELECTED, "Selected object deleted" },
  { 0, 0 }
};

char*
TToolHelp::GetTaskName()
{
  HTASK hTask = GetCurrentTask();
  TASKENTRY te;
  te.dwSize = sizeof(te);
  TaskName[0]=0;
  if (TaskFindHandle(&te, hTask))
    strcpy(TaskName,(LPSTR)te.szModule);
  return TaskName;
}

char*
TToolHelp::GetProcName(FARPROC lpfn)
{
  GLOBALENTRY ge;
  MODULEENTRY me;
  ge.dwSize = sizeof(ge);
  me.dwSize = sizeof(me);
  ProcName[0]=0;
  if (GlobalEntryHandle(&ge, (HGLOBAL)HIWORD(lpfn)) &&
                        ge.wType == GT_CODE &&
                        ModuleFindHandle(&me, (HMODULE)ge.hOwner)) {
    strcpy(ProcName,(LPSTR)me.szModule);
  }
  return ProcName;
}


// Table of LogParamErrors
//
struct LogParamError
{
  unsigned err;   // Error code
  char*    type;
  unsigned fmt;  // Format hints for specific error
};

struct LogParamError logParamErrors[] =
{
  {ERR_BAD_VALUE,        "value",        1},
  {ERR_BAD_INDEX,        "index",        1},
  {ERR_BAD_FLAGS,        "flags",        2},
  {ERR_BAD_SELECTOR,     "selector",     2},
  {ERR_BAD_DFLAGS,       "flags",        3},
  {ERR_BAD_DVALUE,       "value",        3},
  {ERR_BAD_DINDEX,       "index",        3},
  {ERR_BAD_PTR,          "pointer",      4},
  {ERR_BAD_FUNC_PTR,     "function pointer", 4},
  {ERR_BAD_STRING_PTR,   "string pointer", 4},
  {ERR_BAD_HINSTANCE,    "HINSTANCE",    2},
  {ERR_BAD_HMODULE,      "HMODULE",      2},
  {ERR_BAD_GLOBAL_HANDLE,"global handle", 2},
  {ERR_BAD_LOCAL_HANDLE, "local handle", 2},
  {ERR_BAD_ATOM,         "atom",         2},
  {ERR_BAD_HWND,         "HWND",         2},
  {ERR_BAD_HMENU,        "HMENU",        2},
  {ERR_BAD_HCURSOR,      "HCURSOR",      2},
  {ERR_BAD_HICON,        "HICON",        2},
  {ERR_BAD_GDI_OBJECT,   "HGDIOBJ",      2},
  {ERR_BAD_HDC,          "HDC",          2},
  {ERR_BAD_HPEN,         "HPEN",         2},
  {ERR_BAD_HFONT,        "HFONT",        2},
  {ERR_BAD_HBRUSH,       "HBRUSH",       2},
  {ERR_BAD_HBITMAP,      "HBITMAP",      2},
  {ERR_BAD_HRGN,         "HRGN",         2},
  {ERR_BAD_HPALETTE,     "HPALETTE",     2},
  {ERR_BAD_HANDLE,       "HANDLE",       2},
  {ERR_BAD_HFILE,        "HFILE",        2},
  {ERR_BAD_HMETAFILE,    "HMETAFILE",    2},
  {ERR_BAD_CID,          "CID",          2},
  {ERR_BAD_HDRVR,        "HDRVR",        2},
  {ERR_BAD_HDWP,         "HDWP",         2}
};


void
TToolHelp::FormatLogParamError(char *result, int size, TDispData *d)
{
  char *type = "parameter";
  unsigned fmt = 0;
  char *warning;
  unsigned err = d->ErrorCode & ~ERR_WARNING;

  // Look through table of errors until we find one that matches
  //
  for (int i = 0; i < (sizeof(logParamErrors) / sizeof(struct LogParamError)); i++) {
    if (logParamErrors[i].err == err) {
      fmt = logParamErrors[i].fmt;
      type = logParamErrors[i].type;
      break;
    }
  }
  if (d->ErrorCode & ERR_WARNING)
    warning = "Warning:";
  else
    warning = "Error:";

  if (fmt == 4)
    sprintf(buffer,"%s %s %s: Invalid %s: %#04x:%#04x \r\n",warning,
      d->ModuleName,d->ProcName,type,SELECTOROF(d->Param),OFFSETOF(d->Param));

  else if (fmt == 3)
    sprintf(buffer,"%s %s %s: Invalid %s: %#04x%#04x \r\n",warning,
      d->ModuleName,d->ProcName,type,(DWORD)d->Param);

  else
    sprintf(buffer,"%s %s %s: Invalid %s: %#04x\r\n",warning,
      d->ModuleName,d->ProcName,type,(WORD)(DWORD)d->Param);

  strncpy(result, buffer, size - 1);
  buffer[size - 1] = 0;
}


#define ERR_SIZEMASK   (ERR_BYTE | ERR_WORD | ERR_DWORD)

void
TToolHelp::FormatLogError(char* result, int size, TDispData* d)
{
  char* p = buffer;
  char* errStr = "";

  uint err = (d->ErrorCode & ~(ERR_WARNING | ERR_SIZEMASK));

  for (int i = 0; errmap[i].szErr; i++) {
    if (errmap[i].err == err) {
      errStr = errmap[i].szErr;
      break;
    }
  }

  if (d->ErrorCode & ERR_WARNING) {
    sprintf(p, "%s: Warning %x: %s",
      (LPSTR)d->ModuleName, d->ErrorCode, (LPSTR)errStr);
  } else {
    sprintf(p, "%s: Error %x: %s",
      (LPSTR)d->ModuleName, d->ErrorCode, (LPSTR)errStr);
  }

  p += strlen(p);
  switch (d->ErrorCode & ERR_SIZEMASK) {
    case ERR_BYTE:
      sprintf(p, "%x\r\n", LOBYTE(LOWORD(d->Data)));
      break;
    case ERR_WORD:
      sprintf(p, "%x\r\n", LOWORD(d->Data));
      break;
    case ERR_DWORD:
      sprintf(p, "%x%x\r\n", HIWORD(d->Data), LOWORD(d->Data));
      break;
    default:
      sprintf(p, "\r\n");
  }
  strncpy(result, buffer, size - 1);
  buffer[size - 1] = 0;
}
