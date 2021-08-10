//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\owldiag.cpp
//   Implementation of OWL diagnostics
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\point.h>
#include <string.h>
#include <stdlib.h>

static const char Section[] = "Diagnostics";
static int InitialCheck = 0;
static int DiagsAreEnabled = 0;

//
// Retrieve a diag's enabled flag from a private .ini file. Master enable
// switch overrides. .ini file is searched for along cwd, windowsdir, 
// windowsystemdir, path, mapped network dirs.
//
uint8 _OWLFUNC
GetDiagEnabled(char* file, char* name, uint8 e)
{
  char buf[32];

  OFSTRUCT ofs;
  ofs.cBytes = sizeof ofs;
  OpenFile(file, &ofs, OF_EXIST);
  
  if (!InitialCheck) {
    InitialCheck = 1;
    GetPrivateProfileString(Section, "Enabled", "0", buf, sizeof(buf), ofs.szPathName);
    DiagsAreEnabled = atoi(buf);
  }
  if (!DiagsAreEnabled)
    return 0;
  
  GetPrivateProfileString(Section, name, "", buf, sizeof(buf), ofs.szPathName);
  char *pe = strtok(buf, " ");
  return pe ? uint8(atoi(pe)) : e;
}

//
// Retrieve a diag's level setting from a private .ini file.
//
uint8 _OWLFUNC
GetDiagLevel(char* file, char* name, uint8 l)
{
  char buf[32];

  OFSTRUCT ofs;
  ofs.cBytes = sizeof ofs;
  OpenFile(file, &ofs, OF_EXIST);

  GetPrivateProfileString(Section, name, "", buf, sizeof(buf), ofs.szPathName);
  strtok(buf, " ");
  char *pl = strtok(0, " ");
  return pl ? uint8(atoi(pl)) : l;
}
