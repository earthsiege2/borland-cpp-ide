//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/buttonga.h>
#include <stdlib.h>
#include "appmgr.h"

//
// Constructor. Create an app rec from a string.  The string consists of
// fields separated by ';'.  Here is the format:
//  <program path>;<program args>;<icon path>;<prompt for input>;<startup opts>
// If the format is not correct an error state is set.
//
TAppRec::TAppRec(const string& rec)
{
  // Holds each field of the record.
  //
  char*       pp;
  char*       pa;
  char*       ip;
  char*       pfi;
  char*       ss;
  char*       temp = new char[rec.length()+1];
  string      nullStr;

  Error = 0;
  strcpy(temp, rec.c_str());
  if ((pp = strtok(temp, ";")) != 0 &&
      (pa = strtok(0, ";")) != 0 &&
      (ip = strtok(0, ";")) != 0 &&
      (pfi= strtok(0, ";")) != 0 &&
      (ss = strtok(0, ";")) != 0 ) {
    ProgramPath = pp;
    ProgramArgs = pa;
    IconPath = ip;
    PromptForInput = atoi(pfi);
    StartupStyle = atoi(ss);
    Error = (StartupStyle != 1 && StartupStyle != 2 && StartupStyle != 3);
  }
  else
    Error = 1;

  delete temp;
}

//
// ReturnAsString().  Contatenate a TAppRec's values into a string and return
// it.  Any empty (or null) fields are converted to 1 space strings for
// easier manipulation later.
//
string
TAppRec::AsString()
{
  char        num[5];
  string      empty(" ");
  string      str;

  str = ProgramPath + ";";
  str += ProgramArgs.is_null() ? empty : ProgramArgs;
  str += ";";
  str += IconPath.is_null() ? empty : IconPath;
  str += ";";
  itoa(PromptForInput, num, 10);
  str += num;
  str += ";";
  itoa(StartupStyle, num, 10);
  str += num;

  return str;
}

//
// GetIconPath().  Return the path to the icon for current app through
// 'iconPath'.  If the 'IconPath' member is not empty use it, else use
// program path.
//
string
TAppRec::GetIconPath()
{
  string iconPath = ProgramPath;
  if (!IconPath.is_null() && IconPath[0] != ' ')
    iconPath = IconPath;
  return iconPath;
}

//----------------------------------------------------------------------------

//
// Assignment operator.  Copy recs to recieving object.
//
TAppMgr&
TAppMgr::operator =(const TAppMgr& am)
{
  unsigned  end = am.Limit();

  for (unsigned i = 0; i < end; i++) {
    if (am[i] != 0)
      Add(new TAppRec(*am[i]));
  }
  return *this;
}

//
// AddFromString(). Parses given string into a TAppRec and stores it.
// Assumes the string contains the correct info. Does check for correct
// number of items.
//
int
TAppMgr::AddFromString(const string& rec, unsigned loc)
{
  TAppRec* appRec = new TAppRec(rec);

  if (!appRec->IsBad())
    return AddAt(appRec, loc);
  return 0;
}
