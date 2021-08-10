//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TProfile class
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/profile.h>
#include <osl/inlines.h>

//
// Use system profile for filename==0
//
TProfile::TProfile(const char* section, const char* filename)
{
  Section = section ? strnewdup(section) : 0;
  if (filename) {
    OFSTRUCT ofs;
    ofs.cBytes = sizeof ofs;
    OpenFile(filename, &ofs, OF_EXIST);
    FileName = strnewdup(ofs.szPathName);
  }
  else
    FileName = 0;
}

TProfile::~TProfile()
{
  delete [] FileName;
  delete [] Section;
}

int
TProfile::GetInt(const char* key, int defaultInt)
{
  return FileName
    ? ::GetPrivateProfileInt(Section, key, defaultInt, FileName)
    : ::GetProfileInt(Section, key, defaultInt);
}

//
// returns all section values if key==0
//
bool
TProfile::GetString(const char* key, char buff[], unsigned buffSize,
                    const char* defaultString)
{
  return FileName
    ? ::GetPrivateProfileString(Section, key, defaultString, buff, buffSize, FileName)
    : ::GetProfileString(Section, key, defaultString, buff, buffSize);
}

bool
TProfile::WriteInt(const char* key, int value)
{
  char buf[16];
  itoa(value, buf, 10);
  return WriteString(key, buf);
}

bool
TProfile::WriteString(const char* key, const char* str)
{
  return FileName
    ? ::WritePrivateProfileString(Section, key, str, FileName)
    : ::WriteProfileString(Section, key, str);
}
