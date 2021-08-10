// Borland C++ Builder
// Copyright (c) 1995, 2001 by Borland International
// All rights reserved

#ifndef __WEBINIT_H
#define __WEBINIT_H

#include <vcl.h>
#include <WebFact.hpp>
#include <HTTPApp.hpp>

class TWebAppPageInit {
public:
  __fastcall TWebAppPageInit(
    TMetaClass* AComponentClass,
    TWebModuleCacheMode ACacheMode,
    TWebPageAccess AAccess,
    const AnsiString APageFile = ".html",
    const AnsiString APageName = "",
    const AnsiString ACaption = "",
    const AnsiString ADescription = "",
    const AnsiString AViewAccess = "");
};

class TWebPageInit {
public:
  __fastcall TWebPageInit(
    TMetaClass* AComponentClass,
    TWebModuleCreateMode ACreateMode,
    TWebModuleCacheMode ACacheMode,
    TWebPageAccess AAccess,
    const AnsiString APageFile = ".html",
    const AnsiString APageName = "",
    const AnsiString ACaption = "",
    const AnsiString ADescription = "",
    const AnsiString AViewAccess = "");
};

class TWebDataModuleInit {
public:
  __fastcall TWebDataModuleInit(
    TMetaClass* AComponentClass,
    TWebModuleCreateMode ACreateMode,
    TWebModuleCacheMode ACacheMode);
};

class TWebAppDataModuleInit {
public:
  __fastcall TWebAppDataModuleInit(
    TMetaClass* AComponentClass,
    TWebModuleCacheMode ACacheMode);
};

#endif // __WEBINIT_H



