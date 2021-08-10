//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of TPrintDC
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif

OWL_DIAGINFO;

//
// Supply missing function definition and macros for newer Win32 function
//
#if defined(BI_PLAT_WIN32)
  extern "C" {
    int  WINAPI DeviceCapabilitiesExA(LPCSTR, LPCSTR, LPCSTR, WORD,
                                      LPSTR, CONST DEVMODEA*);
    int  WINAPI DeviceCapabilitiesExW(LPCWSTR, LPCWSTR, LPCWSTR, WORD,
                                      LPWSTR, CONST DEVMODEW*);
    #if defined(UNICODE)
      #define DeviceCapabilitiesEx  DeviceCapabilitiesExW
    #else
      #define DeviceCapabilitiesEx  DeviceCapabilitiesExA
    #endif // !UNICODE
  }
  #define PROC_DEVICECAPABILITIES MAKEINTRESOURCE(91)
#endif

//
//
//
class TPrinterDriverLibrary : public TModule {
  public:
    TPrinterDriverLibrary(const char far* drvName);

#if defined(BI_PLAT_WIN32)
    TModuleProc5<int,LPCSTR,LPCSTR,WORD,LPSTR,const DEVMODEA*> DeviceCapabilities;
#else
    TModuleProc5<uint32,LPCSTR,LPCSTR,WORD,LPSTR,const DEVMODE far*> DeviceCapabilities;
#endif
};

//
//
//
TPrinterDriverLibrary::TPrinterDriverLibrary(const char far* drvName)
:
  TModule(drvName, true, true),
  DeviceCapabilities(*this,PROC_DEVICECAPABILITIES)
{
}

//
//
//
TPrintDC::TPrintDC(HDC handle, TAutoDelete autoDelete)
:
  TCreatedDC(handle, autoDelete)
{
  memset(&DocInfo, 0, sizeof(DocInfo));
  DocInfo.cbSize = sizeof(DocInfo);
  DocInfo.lpszOutput = "";
#if defined(BI_PLAT_WIN32)
  DocInfo.lpszDatatype = "";
#endif
}

//
//
//
TPrintDC::TPrintDC(const char far* driver, const char far* device,
                   const char far* output, const DEVMODE far* initData)
:
  TCreatedDC(driver, device, output, initData)
{
  memset(&DocInfo, 0, sizeof(DocInfo));
  DocInfo.cbSize = sizeof(DocInfo);
  DocInfo.lpszOutput = "";
#if defined(BI_PLAT_WIN32)
  DocInfo.lpszDatatype = "";
#endif
}

//
//
//
uint32
TPrintDC::DeviceCapabilities(const char far* driver,
                             const char far* device,
                             const char far* port,
                             int capability,
                             char far* output,
                             LPDEVMODE devmode)
{
  // Hand call DeviceCapabilities due to Win32s missing function!
  //
  uint32 caps = 0;

#if defined(BI_PLAT_WIN32)
  // Try the Win32 DeviceCapabilitiesEx function
  //
  caps = ::DeviceCapabilitiesEx(driver, device, port, (uint16)capability, output, devmode);
  if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED)
    return caps;
#endif

  // Locate & call the DeviceCapabilities function within the printer driver
  // itself.
  //
  try {
    TPrinterDriverLibrary driverLib(driver);
    caps = driverLib.DeviceCapabilities(device, port, (uint16)capability, output, devmode);
  }
  catch (...) {
  }
  return caps;
}
