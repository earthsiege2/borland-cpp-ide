//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// Implementation of diagnostic initialization functions. Settings are stored
// in a profile (name is provided) in a section named "Diagnostics". Profile
// format in an ascii .ini file looks like:
//
//  [Diagnostics]
//  Enabled = <enabled>
//  <groupname1> = <enabled> <level>
//  <groupname2> = <enabled> <level>
//    ...
//  <groupnameN> = <enabled> <level>
//
// where:
//  <enabled> = 0|1
//  <level>   = 0..255
//
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if !defined(WINSYS_PROFILE_H)
# include <winsys/profile.h>
#endif
#include <string.h>
#include <stdlib.h>
#include <tchar.h>

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

static const _TCHAR Section[] = "Diagnostics";
static int DiagsAreEnabled = 0;

//
// Retrieve a diag's enabled flag from a private .ini file. Master enable
// switch 'Enabled' overrides individual group settings. .ini file is searched
// for in standard profile places
//
uint8 _WSYSFUNC
GetDiagEnabled(_TCHAR* filename, _TCHAR* name, uint8 defEnabled)
{
  TProfile diagProfile(Section, filename);

  _TCHAR buf[32];
  static bool initialCheck = false;
  if (!initialCheck) {
    initialCheck = true;
    diagProfile.GetString("Enabled", buf, sizeof buf, "0");
    DiagsAreEnabled = _ttoi(buf);
  }
  if (!DiagsAreEnabled)
    return 0;

  diagProfile.GetString(name, buf, sizeof buf, "");
  _TCHAR* enabled = _tcstok(buf, " ");
  return enabled ? uint16(_ttoi(enabled)) : defEnabled;
}

//
// Retrieve a diag's level setting from a private .ini file.
//
uint8 _WSYSFUNC
GetDiagLevel(_TCHAR* filename, _TCHAR* name, uint8 defLevel)
{
  _TCHAR buf[32];
  TProfile(Section, filename).GetString(name, buf, sizeof buf, "");

  _tcstok(buf, " ");
  _TCHAR* level = _tcstok(0, " ");
  return level ? uint16(_ttoi(level)) : defLevel;
}

#if defined(BI_NAMESPACE)
} // namespace ClassLib
#endif
