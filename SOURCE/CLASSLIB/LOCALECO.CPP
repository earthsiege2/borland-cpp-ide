//----------------------------------------------------------------------------
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
// TLocaleString default NLS compare function - used only if non-OLE
//----------------------------------------------------------------------------
#if !defined(_Windows)
# define _Windows      // pretend we are in windows to get the headers we need
#endif
#include <osl/locale.h>

#if defined(BI_PLAT_WIN32)

TLangId
TLocaleString::GetSystemLangId()
{
  return ::GetSystemDefaultLangID();
}

TLangId
TLocaleString::GetUserLangId()
{
  return ::GetUserDefaultLangID();
}

int
TLocaleString::CompareLang(const char far* s1, const char far* s2, TLangId lang)
{
  typedef int WINAPI (*TCompareStringA)(LCID, DWORD, LPCSTR, int, LPCSTR, int);
  
  static int WINAPI (*compareStringA)(LCID, DWORD, LPCSTR, int, LPCSTR, int) =
    (TCompareStringA)::GetProcAddress(::GetModuleHandle("kernel32"), "CompareStringA");

  // Use CompareStringA if it is available
  //
  if (compareStringA)
    return compareStringA(lang, NORM_IGNORECASE | NORM_IGNORENONSPACE,
                          s1,-1, s2,-1) - 2;

  // Otherwise just use RTL function
  //
  return _fstricmp(s1, s2);  // only permissible if not an OLE application
}

#else

#include <string.h>

TLangId
TLocaleString::GetSystemLangId()
{
  return 0x409;  // US English if no OLE or Win32 support
}

TLangId
TLocaleString::GetUserLangId()
{
  return 0x409;  // US English if no OLE or Win32 support
}

int
TLocaleString::CompareLang(const char far* s1, const char far* s2, TLangId)
{
  return _fstricmp(s1, s2);  // only permissible if not an OLE application
}

#endif
