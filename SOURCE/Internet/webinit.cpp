// Borland C++ Builder
// Copyright (c) 1995, 2001 by Borland International
// All rights reserved

#include <WebInit.h>
#include <WebReq.hpp>

__fastcall TWebAppPageInit::TWebAppPageInit(
    TMetaClass* AComponentClass,
    TWebModuleCacheMode ACacheMode,
    TWebPageAccess AAccess,
    const AnsiString APageFile,
    const AnsiString APageName,
    const AnsiString ACaption,
    const AnsiString ADescription,
    const AnsiString AViewAccess)
{
  if (WebRequestHandler() != NULL)
  {
    TWebPageInfo *WebPageInfo = new TWebPageInfo(AAccess, APageFile, APageName,
      ACaption, ADescription, AViewAccess);
    TAbstractWebModuleFactory *WebModuleFactory;
    WebModuleFactory = new TWebAppPageModuleFactory(AComponentClass,
      WebPageInfo, ACacheMode);
    WebRequestHandler()->AddWebModuleFactory(WebModuleFactory);
  }
}

__fastcall TWebPageInit::TWebPageInit(
    TMetaClass* AComponentClass,
    TWebModuleCreateMode ACreateMode,
    TWebModuleCacheMode ACacheMode,
    TWebPageAccess AAccess,
    const AnsiString APageFile,
    const AnsiString APageName,
    const AnsiString ACaption,
    const AnsiString ADescription,
    const AnsiString AViewAccess)
{
  if (WebRequestHandler() != NULL)
  {
    TWebPageInfo *WebPageInfo = new TWebPageInfo(AAccess, APageFile, APageName,
      ACaption, ADescription, AViewAccess);
    TAbstractWebModuleFactory *WebModuleFactory;
    WebModuleFactory = new TWebPageModuleFactory(AComponentClass,
      WebPageInfo, ACreateMode, ACacheMode);
    WebRequestHandler()->AddWebModuleFactory(WebModuleFactory);
  }
}

__fastcall TWebDataModuleInit::TWebDataModuleInit(
    TMetaClass* AComponentClass,
    TWebModuleCreateMode ACreateMode,
    TWebModuleCacheMode ACacheMode)
{
  if (WebRequestHandler() != NULL)
  {
    TAbstractWebModuleFactory *WebModuleFactory;
    WebModuleFactory = new TWebDataModuleFactory(AComponentClass, ACreateMode, ACacheMode);
    WebRequestHandler()->AddWebModuleFactory(WebModuleFactory);
  }
}

__fastcall TWebAppDataModuleInit::TWebAppDataModuleInit(
    TMetaClass* AComponentClass,
    TWebModuleCacheMode ACacheMode)
{
  if (WebRequestHandler() != NULL)
  {
    TAbstractWebModuleFactory *WebModuleFactory;  
    WebModuleFactory = new TWebAppDataModuleFactory(AComponentClass, ACacheMode);
    WebRequestHandler()->AddWebModuleFactory(WebModuleFactory);
  }
}

