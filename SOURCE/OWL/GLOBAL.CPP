//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\global.cpp
//   Global data required for every module using OWL
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>

class _OWLCLASS TDocTemplate;

// Global module pointer representing this executable instance
//   provides the default instance for resources contructed within this module

TModule* Module = 0;  // must be set to a TApplication* or a TModule*

// Document templates contructed before doc manager get linked in here

TDocTemplate* DocTemplateStaticHead = 0;  // initialize to no templates

#if defined(__DLL__)

// Exported access to global variables

extern "C" {

TDocTemplate** _export PASCAL GetDocTemplateHead(int version)
{
  return version == 0x200 ? &DocTemplateStaticHead : 0;
}

TModule** _export PASCAL GetModulePtr(int version)
{
  return version == 0x200 ? &Module : 0;
}

}

#endif
