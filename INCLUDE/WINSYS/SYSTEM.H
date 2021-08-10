//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.10  $
//
// Definition of TSystem, a system information provider class
//----------------------------------------------------------------------------
#if !defined(WINSYS_SYSTEM_H)
#define WINSYS_SYSTEM_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if !defined(WINSYS_WSYSINC_H)
# include <winsys/wsysinc.h>
#endif

//
// Define Win95 platform constant if not defined in system headers
//
#if !defined(VER_PLATFORM_WIN32_WINDOWS)
# define VER_PLATFORM_WIN32_WINDOWS 1
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// class TSystem
// ~~~~~ ~~~~~~~
class _WSYSCLASS TSystem {
  public:

    // High level capability support queries
    //
    static bool SupportsExceptions();
    static bool SupportsThreads();
    static bool SupportsInstanceData();

    static bool Has3dUI();
    static bool HasSmallCaption();
    static bool HasSmallIcon();

    // More specific platform type queries
    //
#if defined(BI_PLAT_WIN16)
    static bool IsWoW();
    static bool IsWin95();
#endif
#if defined(BI_PLAT_WIN32)
    static bool IsNT();
    static bool IsWin95();
    static bool IsWin32s();
#endif

    enum TPlatformId {
#if defined(BI_PLAT_WIN32)
      Win32s       = VER_PLATFORM_WIN32s,
      Win32Windows = VER_PLATFORM_WIN32_WINDOWS,
      Win32NT      = VER_PLATFORM_WIN32_NT,
      Win16        = -1,
#else
      Win32s       = -1,
      Win32Windows = -1,
      Win32NT      = -1,
      Win16        = 0,
#endif
    };
    static uint GetPlatformId();

    // Version information
    //
    static uint GetVersion();
    static uint GetVersionFlags();

    static uint GetMajorVersion();
    static uint GetMinorVersion();
    static uint GetBuildNumber();

    static const _TCHAR* GetVersionStr();

    // Hardware information
    //
    enum TProcessor {
#if defined(BI_PLAT_WIN32)
      Intel386     = PROCESSOR_INTEL_386,
      Intel486     = PROCESSOR_INTEL_486,
      IntelPentium = PROCESSOR_INTEL_PENTIUM,
      MipsR4000    = PROCESSOR_MIPS_R4000,
      Alpha21064   = PROCESSOR_ALPHA_21064,
#else
      Intel386,
      Intel486,
      IntelPentium,
      MipsR4000    = -1,
      Alpha21064   = -1,
#endif
      Ppc601       = -1,
      Ppc603       = -1,
      Ppc604       = -1,
      Ppc620       = -1,
    };
    static TProcessor GetProcessorType();

  protected:

#if defined(BI_PLAT_WIN32)
    // Class that encapsulates the OSVERSIONINFO struct and the GetVersionEx()
    // Win32 call.
    //
    class TVersionInfo : private _OSVERSIONINFOA {
      public:
        TVersionInfo();
        uint GetMajorVersion() const;
        uint GetMinorVersion() const;
        uint GetBuildNumber() const;
        uint GetPlatformId() const;
        const _TCHAR* GetVersionStr() const;
    };

    // Return an initialized version info object
    //
    static TVersionInfo& GetVerInfo();

    // Class that encapsulates the _SYSTEM_INFO struct and the GetSystemInfo()
    // Win32 call.
    //
    class TSystemInfo : private _SYSTEM_INFO {
      public:
        TSystemInfo();
        TProcessor GetProcessorType() const;
    };

    // Return an initialized system info object
    //
    static TSystemInfo& GetSystemInfo();
#endif
};

#if defined(BI_NAMESPACE)
}     // namespace ClassLib
#endif

//----------------------------------------------------------------------------
// Inlines
//

//
// Does this OS support tiny caption (via the WS_EX_TOOLWINDOW style)
//
inline bool TSystem::HasSmallCaption()
{
  return Has3dUI();
}

//
// Does this OS support small window icons
//
inline bool TSystem::HasSmallIcon()
{
  return Has3dUI();
}


#if defined(BI_PLAT_WIN16)

//
// Return true if the system has exception suport built in and the runtime
// library uses it for stack unwinding support.
//
inline bool TSystem::SupportsExceptions() {
  return false;
}

//
// Return true if the system has thread suport built in and the runtime
// library uses it.
//
inline bool TSystem::SupportsThreads() {
  return false;
}

//
// Return true if the system has suport for per-instance data built in and the
// runtime library uses it.
//
inline bool TSystem::SupportsInstanceData() {
  return false;
}

//
inline uint TSystem::GetPlatformId() {
  return Win16;
}

//
inline uint TSystem::GetMajorVersion() {
  return LOBYTE(LOWORD(GetVersion()));
}

//
inline uint TSystem::GetMinorVersion() {
  return HIBYTE(LOWORD(GetVersion()));
}

//
inline const _TCHAR* TSystem::GetVersionStr() {
  return "";
}

#elif defined(BI_PLAT_WIN32)

//
inline bool TSystem::IsNT() {
  return GetPlatformId() == Win32NT;
}

//
inline bool TSystem::IsWin95() {
  return GetPlatformId() == Win32Windows;
}

//
inline bool TSystem::IsWin32s() {
  return GetPlatformId() == Win32s;
}

//
inline uint TSystem::GetPlatformId() {
  return GetVerInfo().GetPlatformId();
}

//
inline TSystem::TProcessor TSystem::GetProcessorType() {
  return GetSystemInfo().GetProcessorType();
}

//
inline uint TSystem::GetMajorVersion() {
  return GetVerInfo().GetMajorVersion();
}

//
inline uint TSystem::GetMinorVersion() {
  return GetVerInfo().GetMinorVersion();
}

//
inline uint TSystem::GetBuildNumber() {
  return GetVerInfo().GetBuildNumber();
}

//
inline const _TCHAR* TSystem::GetVersionStr() {
  return GetVerInfo().GetVersionStr();
}

//
inline TSystem::TSystemInfo::TSystemInfo() {
  // no struct size to fill in...
  ::GetSystemInfo(this);
}

//
inline TSystem::TProcessor TSystem::TSystemInfo::GetProcessorType() const {
  return (TProcessor)dwProcessorType;
}

//
inline TSystem::TVersionInfo::TVersionInfo() {
  dwOSVersionInfoSize = sizeof *this;
  ::GetVersionEx(this);
}

//
inline uint TSystem::TVersionInfo::GetMajorVersion() const {
  return dwMajorVersion;
}

//
inline uint TSystem::TVersionInfo::GetMinorVersion() const {
  return dwMinorVersion;
}

//
inline uint TSystem::TVersionInfo::GetBuildNumber() const {
  return dwBuildNumber;
}

//
inline uint TSystem::TVersionInfo::GetPlatformId() const {
  return dwPlatformId;
}

//
inline const _TCHAR* TSystem::TVersionInfo::GetVersionStr() const {
  return szCSDVersion;
}

#endif  // else/defined(BI_PLAT_WIN16)

#endif  // WINSYS_SYSTEM_H
