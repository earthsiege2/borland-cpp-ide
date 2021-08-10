//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   owl\source\except.cpp
//   Defines type TXOwl.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\except.h>
#include <owl\module.h>


//
// mbModalFlag() determines the best MB modal flag to use in the current
// situation. Uses MB_TASKMODAL if under NT, or the task/thread has at least
// one toplevel window. Uses MB_SYSTEMMODAL for win32s/win16 when there are
// no windows.
//
#if defined(__WIN32__)

BOOL CALLBACK threadHasWnd(HWND, BOOL* has) { *has = TRUE; return FALSE; }

static unsigned mbModalFlag()
{
  if (!(HIWORD(::GetVersion()) & 0x8000))   // NT can always open task modal
    return MB_TASKMODAL;
  BOOL has = FALSE;
  ::EnumThreadWindows(GetCurrentThreadId(), (WNDENUMPROC)threadHasWnd,
                      LPARAM(&has));
  return has ? MB_TASKMODAL : MB_SYSTEMMODAL;
}

#else

BOOL CALLBACK taskHasWnd(HWND, BOOL far* has) { *has = TRUE; return FALSE; }

static unsigned mbModalFlag()
{
  BOOL has = FALSE;
  ::EnumTaskWindows(GetCurrentTask(), (WNDENUMPROC)taskHasWnd,
                    LPARAM((BOOL far*)&has));
  return has ? MB_TASKMODAL : MB_SYSTEMMODAL;
}

#endif

//
// Global exception handler used when an application object is not available.
// May be overriden by user code by redefining this function.  If a valid
// application object is found by GetApplicationObject, then the virtual
// TModule::Error(TXOwl& x, char* caption, BOOL canResume) is usually used
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

//
// Static member function used to convert a resource id to a 'string'.  This
// is necessary since we must pass a string to the xmsg base class
// constructor.  Sets found to TRUE if the resource was located, otherwise
// FALSE.  In either case, the string is initialized to something
// printable.
//
string
TXOwl::ResourceIdToString(BOOL* found, unsigned resId, TModule* module)
{
  char buf[128];

  BOOL status = (module && module->LoadString(resId, buf, sizeof(buf)) != 0);
  if (found)
    *found = status;

  if (!status)
    wsprintf(buf, "Exception #%u (no message available).", resId);

  string rscStr(buf);
  return rscStr;
}

TXOwl::TXOwl(unsigned resId, TModule* module)
  : xmsg(ResourceIdToString(0, resId, module))
{
}

int
TXOwl::Unhandled(TModule* app, unsigned promptResId)
{
  return app->Error(*this, IDS_OWLEXCEPTION, promptResId);
}

TXOwl*
TXOwl::Clone()
{
  return new TXOwl(*this);
}

void
TXOwl::Throw()
{
  THROW( *this );
}

TXOutOfMemory::TXOutOfMemory() : TXOwl(IDS_OUTOFMEMORY)
{
}

TXOwl*
TXOutOfMemory::Clone()
{
  return new TXOutOfMemory(*this);
}
void
TXOutOfMemory::Throw()
{
  THROW( *this );
}
