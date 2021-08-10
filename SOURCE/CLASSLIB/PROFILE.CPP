//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.2  $
//
// Implementation of TProfile class
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/profile.h>
#include <services/memory.h>

//
// Use system profile for filename==0. Use system to search in normal places
// if no path is included in filename.
//
TProfile::TProfile(const char far* section, const char far* filename)
{
  Section  = section ? strnewdup(section) : 0;

  // Use OpenFile to track down the given filename
  //   if can't find it, use copy of original name,
  //   if found, use copy of full path
  //
  if (filename) {
    OFSTRUCT ofs;
    ofs.cBytes = sizeof ofs;
    FileName = strnewdup(
      (OpenFile(filename, &ofs, OF_EXIST) == HFILE_ERROR) ? filename : ofs.szPathName
    );
  }
  else {
    FileName = 0;
  }
}

//
// Clean up buffers
//
TProfile::~TProfile()
{
  delete[] FileName;
  delete[] Section;
}

//
// Retrieve an integer value from the profile
//
int
TProfile::GetInt(const char far* key, int defaultInt)
{
  return FileName
    ? ::GetPrivateProfileInt(Section, key, defaultInt, FileName)
    : ::GetProfileInt(Section, key, defaultInt);
}

//
// Return all section values if key==0
//
bool
TProfile::GetString(const char far* key, char far* buff, unsigned buffSize,
                    const char far* defaultString)
{
  return FileName
    ? ::GetPrivateProfileString(Section, key, defaultString, buff, buffSize, FileName)
    : ::GetProfileString(Section, key, defaultString, buff, buffSize);
}

//
// Write an integer value to the profile
//
bool
TProfile::WriteInt(const char far* key, int value)
{
  char buf[16];
  itoa(value, buf, 10);
  return WriteString(key, buf);
}

//
// Write an string value to the profile
//
bool
TProfile::WriteString(const char far* key, const char far* str)
{
  return FileName
    ? ::WritePrivateProfileString(Section, key, str, FileName)
    : ::WriteProfileString(Section, key, str);
}

//
// Make sure that all written profile values are flushed to the actual file
//
void
TProfile::Flush()
{
  if (FileName)
    ::WritePrivateProfileString(0, 0, 0, FileName);
}
