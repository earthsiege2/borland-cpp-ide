//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\dc.cpp
//   Implementation of TPrintDC
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\dc.h>

#if defined(__WIN32__)
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
  typedef DWORD (CALLBACK* DeviceCapabilitiesFcn)(LPCSTR, LPCSTR, WORD, LPSTR, const DEVMODE far*);
#endif

TPrintDC::TPrintDC(HDC handle, TAutoDelete autoDelete) 
  : TCreatedDC(handle, autoDelete)
{
  DocInfo.cbSize = sizeof(DocInfo);
}

TPrintDC::TPrintDC(const char far* driver, const char far* device,
                   const char far* output, const DEVMODE far* initData)
  : TCreatedDC(driver, device, output, initData)
{
  DocInfo.cbSize = sizeof(DocInfo);
}

DWORD
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
  #if 0 && defined(__WIN32__)
    return ::DeviceCapabilitiesEx(driver, device, port, capability, output, devmode);

  //
  // DeviceCapabilities missing in Win32s
  //
  #elif 0 && defined(__WIN32__)
    return ::DeviceCapabilities(device, port, (uint16)capability, output, devmode);


  //
  // Hand call DeviceCapabilities due to Win32s missing function!
  //
  #else
    DWORD caps = 0;
    #if defined(__WIN32__)
      //
      // Try the Win32 DeviceCapabilitiesEx function
      //
      caps = ::DeviceCapabilitiesEx(driver, device, port, (WORD)capability, output, devmode);
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
        caps = deviceCapabilities(device, port, (WORD)capability, output, devmode);
      ::FreeLibrary(driverInst);
    }
    return caps;
  #endif
}
