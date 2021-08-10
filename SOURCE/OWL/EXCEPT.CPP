//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Implementation of class TXOwl, the base exception class for OWL exceptions
// that can forward handling to the app module by default.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_EXCEPT_H)
# include <owl/except.h>
#endif
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
#include <stdio.h>

//
// mbModalFlag() determines the best MB modal flag to use in the current
// situation. Uses MB_TASKMODAL if under NT, or the task/thread has at least
// one toplevel window. Uses MB_SYSTEMMODAL for Win32S/Win16 when there are
// no toplevel windows.
//
bool CALLBACK hasWndProc(TWindow::THandle, bool far* hasWnd)
{
  *hasWnd = true;
  return false;
}

static unsigned mbModalFlag()
{
#if defined(BI_PLAT_WIN32)
  // NT can always open task modal, even before windows are up
  //
  if (TSystem::IsNT())
    return MB_TASKMODAL;
#endif

  // Windows95, Win32s & Win16 need first window created before task modal msg
  // box can be created
  //
  bool hasWnds = false;
#if defined(BI_PLAT_WIN32)
  ::EnumThreadWindows(GetCurrentThreadId(), (WNDENUMPROC)hasWndProc,
                      TParam2(&hasWnds));
#else
  ::EnumTaskWindows(GetCurrentTask(), (WNDENUMPROC)hasWndProc,
                    TParam2((bool far*)&hasWnds));
#endif

  return hasWnds ? MB_TASKMODAL : MB_SYSTEMMODAL;
}

//
// Global exception handler used when an application object is not available.
// May be overriden by user code by redefining this function.  If a valid
// application object is found by GetApplicationObject, then the virtual
// TModule::Error(TXOwl& x, char* caption, bool canResume) is usually used
// instead.
//
int _OWLFUNC
HandleGlobalException(xmsg& x, char* caption, char* canResume)
{
  char errorStr[255];
  int  buttons = MB_OK;
  int  len = x.why().length();

  if (!caption)
    caption = "Unhandled Exception";
  if (len)
    strcpy(errorStr, x.why().c_str());
  else {
    strcpy(errorStr, "Unknown Exception");
    len = strlen(errorStr);
  }
  if (canResume) {
    buttons = MB_YESNO;
    errorStr[len] = '\n';
    strcpy(errorStr+len+1, canResume);
  }
  return ::MessageBox(0, errorStr, caption,
                      mbModalFlag() | MB_ICONSTOP | buttons) == IDYES ? 0 : -1;
}

//----------------------------------------------------------------------------

//
// An OWL exception with a given message for displaying and an unsigned Id
// that can be used for identification or loading a string
//
TXOwl::TXOwl(const string& msg, uint resId)
:
  TXBase(msg),
  ResId(resId)
{
}

//
// An OWL exception with a given unsigned Id that can is used for loading a
// message string & identification
//
TXOwl::TXOwl(unsigned resId, TModule* module)
:
  TXBase(ResourceIdToString(0, resId, module)),
  ResId(resId)
{
}

//
//
//
TXOwl::~TXOwl()
{
}

//
//
//
int
TXOwl::Unhandled(TModule* app, uint promptResId)
{
  return app->Error(*this, IDS_OWLEXCEPTION, promptResId);
}

#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXOwl*
#endif
TXOwl::Clone()
{
  return new TXOwl(*this);
}

//
//
//
void
TXOwl::Throw()
{
  THROW( *this );
}

//
// Construct a TXOwl exception from scratch, and throw it. Two versions
// corresponding to the two constructor signatures
//
void
TXOwl::Raise(const string& msg, uint resId)
{
  TXOwl(msg, resId).Throw();
}

//
//
//
void
TXOwl::Raise(uint resId, TModule* module)
{
  TXOwl(resId, module).Throw();
}

//
// Static member function used to convert a resource id to a 'string'. This
// is necessary since we must pass a string to the xmsg base class
// constructor.  Sets found to true if the resource was located, otherwise
// false.  In either case, the string is initialized to something
// printable.
//
string
TXOwl::ResourceIdToString(bool* found, uint resId, TModule* module)
{
  char buf[128];

  bool status = module && module->LoadString(resId, buf, sizeof buf);
  if (found)
    *found = status;

  if (!status)
    sprintf(buf, "Exception #%u (no message available).", resId);

  string rscStr(buf);
  return rscStr;
}

//
// Extension to string loader adds the feature of sprintf'ing an
// additional information string into the resource message string.
//
string
TXOwl::MakeMessage(uint resId, const char far* infoStr, TModule* module)
{
  string rscMsg = ResourceIdToString(0, resId, module);
  char buf[255];
  sprintf(buf, rscMsg.c_str(), infoStr);
  return string(buf);
}

//
// Extension to string loader adds the feature of sprintf'ing an additional
// information number into the resource message string.
//
string
TXOwl::MakeMessage(uint resId, uint infoNum, TModule* module)
{
  string rscMsg = ResourceIdToString(0, resId, module);
  char buf[255];
  sprintf(buf, rscMsg.c_str(), infoNum);
  return string(buf);
}

//----------------------------------------------------------------------------

//
//
//
TXOutOfMemory::TXOutOfMemory()
:
  TXOwl(IDS_OUTOFMEMORY)
{
}

#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXOutOfMemory*
#endif
TXOutOfMemory::Clone()
{
  return new TXOutOfMemory(*this);
}

//
//
//
void
TXOutOfMemory::Throw()
{
  THROW( *this );
}

//
// Construct a TXOutOfMemory exception from scratch, and throw it
//
void
TXOutOfMemory::Raise()
{
  TXOutOfMemory().Throw();
}
