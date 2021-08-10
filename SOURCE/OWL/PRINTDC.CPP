//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TPrintDC
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/dc.h>

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
  typedef int (WINAPI* DeviceCapabilitiesFcn)(LPCSTR, LPCSTR, WORD, LPSTR, CONST DEVMODEA*);
  #define PROC_DEVICECAPABILITIES MAKEINTRESOURCE(91)
#else
  typedef uint32 (CALLBACK* DeviceCapabilitiesFcn)(LPCSTR, LPCSTR, WORD, LPSTR, const DEVMODE far*);
#endif

TPrintDC::TPrintDC(HDC handle, TAutoDelete autoDelete) 
:
  TCreatedDC(handle, autoDelete)
{
  DocInfo.cbSize = sizeof(DocInfo);
}

TPrintDC::TPrintDC(const char far* driver, const char far* device,
                   const char far* output, const DEVMODE far* initData)
:
  TCreatedDC(driver, device, output, initData)
{
  DocInfo.cbSize = sizeof(DocInfo);
}

uint32
TPrintDC::DeviceCapabilities(const char far* driver, 
                             const char far* device, 
                             const char far* port,
                             int capability, 
                             char far* output,
                             LPDEVMODE devmode)
{
  //
  // DeviceCapabilitiesEx not functional in this Win32 (NT) release
  //
  #if 0 && defined(BI_PLAT_WIN32)
    return ::DeviceCapabilitiesEx(driver, device, port, capability, output, devmode);

  //
  // DeviceCapabilities missing in Win32s
  //
  #elif 0 && defined(BI_PLAT_WIN32)
    return ::DeviceCapabilities(device, port, (uint16)capability, output, devmode);

  //
  // Hand call DeviceCapabilities due to Win32s missing function!
  //
  #else
    uint32 caps = 0;
    #if defined(BI_PLAT_WIN32)
      //
      // Try the Win32 DeviceCapabilitiesEx function
      //
      caps = ::DeviceCapabilitiesEx(driver, device, port, (uint16)capability, output, devmode);
      if (GetLastError() != ERROR_CALL_NOT_IMPLEMENTED)
        return caps;
    #endif

    //
    // Locate & call the DeviceCapabilities function within the printer driver
    // itself.
    //
    HINSTANCE driverInst = ::LoadLibrary(driver);

    if (driverInst) {
      DeviceCapabilitiesFcn deviceCapabilities = 
         (DeviceCapabilitiesFcn)::GetProcAddress(driverInst, PROC_DEVICECAPABILITIES);
      if (deviceCapabilities)
        caps = deviceCapabilities(device, port, (uint16)capability, output, devmode);
      ::FreeLibrary(driverInst);
    }
    return caps;
  #endif
}
