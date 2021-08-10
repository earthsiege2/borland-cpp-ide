//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Global data required for every module using OWL
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

class _OWLCLASS TDocTemplate;

//
// Global module pointer representing this executable instance
// provides the default instance for resources contructed within this module
//
TModule* Module = 0;  // must be set to a TApplication* or a TModule*

//
// Document templates contructed before doc manager get linked in here
//
TDocTemplate* DocTemplateStaticHead = 0;  // initialize to no templates

//
// Exported access to global variables for DLLs that use OWL
//
#if defined(BI_APP_DLL)
extern "C" {

TDocTemplate** PASCAL __export GetDocTemplateHead(int version)
{
  return (version&0xFFF0) == (OWLVersion&0xFFF0) ? &DocTemplateStaticHead : 0;
}

TModule** PASCAL __export GetModulePtr(int version)
{
  return (version&0xFFF0) == (OWLVersion&0xFFF0) ? &Module : 0;
}

}

#endif
