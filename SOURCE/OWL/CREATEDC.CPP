//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\dc.cpp
//   Implementation of TCreatedDC, TIC & TDibDC
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\dc.h>

TCreatedDC::TCreatedDC() : TDC()
{
}

TCreatedDC::TCreatedDC(const char far* driver, const char far* device, 
                       const char far* output, const DEVMODE far* initData)
  : TDC()
{
  Handle = ::CreateDC(driver, device, output, initData);
  CheckValid();
}

//
// Use an existing HDC. Delete it on destruction as requested
//
TCreatedDC::TCreatedDC(HDC handle, TAutoDelete autoDelete)
  : TDC(handle, autoDelete)
{
}

//
// Destruct the TDC by deleting it
//
TCreatedDC::~TCreatedDC()
{
  RestoreObjects();
  if (ShouldDelete)
    ::DeleteDC(HDC(Handle));
}

//
//
//
TIC::TIC(const char far* driver, const char far* device, 
         const char far* output, const DEVMODE far* initData)
  : TCreatedDC()
{
  Handle = ::CreateIC(driver, device, output, initData);
  CheckValid();
}

//
//
//
TDibDC::TDibDC(const TDib& dib)
  : TCreatedDC("DIB", 0, 0, (const DEVMODE far*)dib.GetInfoHeader())
{
}
