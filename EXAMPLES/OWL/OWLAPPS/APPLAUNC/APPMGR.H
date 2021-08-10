//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#if !defined(__APPMGR_H)
#define __APPMGR_H

#include <classlib\vectimp.h>
#include <cstring.h>

struct TAppRec;

//
// Represents an application in AppLauncher.
//
class TAppRec {
  public:
    TAppRec()
      : PromptForInput(0), StartupStyle(1), Error(0) {}

    TAppRec(string& pp, string& pa, string& ip, unsigned pfi, unsigned ss)
      : ProgramPath(pp), ProgramArgs(pa), IconPath(ip), PromptForInput(pfi),
        StartupStyle(ss), Error(0) {}

    TAppRec(const TAppRec& ap)
      : ProgramPath(ap.ProgramPath), ProgramArgs(ap.ProgramArgs),
        IconPath(ap.IconPath), PromptForInput(ap.PromptForInput),
        StartupStyle(ap.StartupStyle), Error(0) {}

    TAppRec(const string& rec);

    int operator ==(const TAppRec& ar) const {
      return ProgramPath == ar.ProgramPath;
    }

    int     IsBad() {return Error;}
    string  AsString();
    string  GetIconPath();

    string          ProgramPath;
    string          ProgramArgs;
    string          IconPath;
    unsigned        PromptForInput;
    unsigned        StartupStyle;

  private:
    int             Error;
};

//
// Manages the collection of TAppRecs.
// Operations:
//  . Inherits publicly from TICVectorImp.
//  . Add a string version of a TAppRec.
//
class TAppMgr : public TICVectorImp<TAppRec> {
  public:
    TAppMgr() : TICVectorImp<TAppRec>(30, 1) {}

    TAppMgr& operator =(const TAppMgr& am);

    int  AddFromString(const string& rec, unsigned loc);
};

#endif // __APPMGR_H
