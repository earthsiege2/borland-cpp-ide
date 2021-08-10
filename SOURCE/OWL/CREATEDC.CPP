//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of classes TCreatedDC, and TIC
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGDI);

//
//
//
TCreatedDC::TCreatedDC()
:
  TDC()
{
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCreatedDC constructed @" << (void*)this);
}

//
//
//
TCreatedDC::TCreatedDC(const char far* driver, const char far* device,
                       const char far* output, const DEVMODE far* initData)
:
  TDC()
{
  Handle = ::CreateDC(driver, device, output, initData);
  CheckValid();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCreatedDC constructed @" << (void*)this <<
    " with driver " << string(driver));
}

//
// Use an existing HDC. Delete it on destruction as requested
//
TCreatedDC::TCreatedDC(HDC handle, TAutoDelete autoDelete)
:
  TDC(handle, autoDelete)
{
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCreatedDC constructed @" << (void*)this <<
    " with handle " << uint(handle));
}

//
// Destruct the TDC by deleting the HDC if ShouldDelete is true
//
TCreatedDC::~TCreatedDC()
{
  RestoreObjects();
  if (ShouldDelete && Handle)
    ::DeleteDC(HDC(Handle));
  TRACEX(OwlGDI, OWL_CDLEVEL, "TCreatedDC destructed @" << (void*)this);
}

//
//
//
TIC::TIC(const char far* driver, const char far* device,
         const char far* output, const DEVMODE far* initData)
:
  TCreatedDC()
{
  Handle = ::CreateIC(driver, device, output, initData);
  CheckValid();
  TRACEX(OwlGDI, OWL_CDLEVEL, "TIC constructed @" << (void*)this <<
    " with driver " << string(driver));
}

//
//
//
TIC::~TIC()
{
  TRACEX(OwlGDI, OWL_CDLEVEL, "TIC destructed @" << (void*)this);
}
