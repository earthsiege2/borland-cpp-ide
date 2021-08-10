//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.1  $
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

static const char Section[] = "Diagnostics";
static int DiagsAreEnabled = 0;

//
// Retrieve a diag's enabled flag from a private .ini file. Master enable
// switch 'Enabled' overrides individual group settings. .ini file is searched
// for in standard profile places
//
uint8 _WSYSFUNC
GetDiagEnabled(char* filename, char* name, uint8 defEnabled)
{
  TProfile diagProfile(Section, filename);

  char buf[32];
  static bool initialCheck = false;
  if (!initialCheck) {
    initialCheck = true;
    diagProfile.GetString("Enabled", buf, sizeof buf, "0");
    DiagsAreEnabled = atoi(buf);
  }
  if (!DiagsAreEnabled)
    return 0;

  diagProfile.GetString(name, buf, sizeof buf, "");
  char* enabled = strtok(buf, " ");
  return enabled ? uint16(atoi(enabled)) : defEnabled;
}

//
// Retrieve a diag's level setting from a private .ini file.
//
uint8 _WSYSFUNC
GetDiagLevel(char* filename, char* name, uint8 defLevel)
{
  char buf[32];
  TProfile(Section, filename).GetString(name, buf, sizeof buf, "");

  strtok(buf, " ");
  char* level = strtok(0, " ");
  return level ? uint16(atoi(level)) : defLevel;
}
