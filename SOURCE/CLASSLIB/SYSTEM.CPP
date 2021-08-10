//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.6  $
//
// Implementation of TSystem class.
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/system.h>

#if defined(BI_PLAT_WIN32)

//
// Return an initialized version info object
//
TSystem::TVersionInfo& TSystem::GetVerInfo()
{
  static TVersionInfo versionInfo;
  return versionInfo;
}

//
// Return an initialized system info object
//
TSystem::TSystemInfo& TSystem::GetSystemInfo()
{
  static TSystemInfo systemInfo;
  return systemInfo;
}

//
// Return true if the system has exception suport built in and the runtime
// library uses it for stack unwinding support.
//
bool TSystem::SupportsExceptions()
{
  static bool exceptionOK = GetPlatformId() != Win32s;
  return exceptionOK;
}

//
// Return true if the system has thread suport built in and the runtime
// library uses it.
//
bool TSystem::SupportsThreads()
{
  static bool threadOK = GetPlatformId() != Win32s;
  return threadOK;
}

//
// Return true if the system has suport for per-instance data built in and the
// runtime library uses it.
//
bool TSystem::SupportsInstanceData()
{
  static bool instanceDataOK = GetPlatformId() != Win32s;
  return instanceDataOK;
}

#endif  // defined(BI_PLAT_WIN32)

//
// Does this OS support a full 3d UI? (Basically, is it Win95?)
//
bool TSystem::Has3dUI()
{
#if defined(BI_PLAT_WIN16)
  return IsWin95();
#else
  return GetVerInfo().GetMajorVersion() >= 4;  // Win95 or NT w/ New Shell
#endif
}

#if defined(BI_PLAT_WIN16)

//
// Return true if the system is win16 WoW under NT.
//
bool TSystem::IsWoW()
{
  static bool isWoW = ToBool(::GetWinFlags()&0x4000);      // WoW box
  return isWoW;
}

//
// Return true if the system is any version of windows 95
//
bool TSystem::IsWin95()
{
  static bool isWin95 = (GetVersion() >= 0x35F);
  return isWin95;
}

TSystem::TProcessor TSystem::GetProcessorType()
{
  // 386 CPUs do not have the alignment check (AC) bit (18), but 486s and above
  // do
  //
  __asm {
    db    0x66          // push extended flags (pushfd)
    pushf
    pop   ax            // read low word of flags
//    and   ax, 0x0FFF    // clear IOPL bits
    pop   dx            // read high word
    or    dx, 0x0004    // set alignment check bit
    push  dx
    push  ax

    db    0x66          // pop extended flags
    popf
    db    0x66          // now re-push them
    pushf

    pop   ax            // Get the flags,
    pop   dx
    test  dx, 0x0004    // and see if the AC bit stuck
    jnz   Not386        // if so, then is newer that a 386
  }
  return Intel386;

Not386:
  //  Check for the ability to set/clear the ID flag (bit 21) in EFLAGS
  //  which diferentiates between Pentium (or greater) and the Intel486.
  //
  __asm {
    db    0x66          // push extended flags (pushfd)
    pushf
    pop   ax            // read low word of flags
//    and   ax, 0x0FFF    // clear IOPL bits
    pop   dx            // read high word
    or    dx, 0x0020    // set ID bit
    push  dx
    push  ax

    db    0x66          // pop extended flags
    popf
    db    0x66          // now re-push them
    pushf

    pop   ax            // Get the flags,
    pop   dx
    test  dx, 0x0020    // and see if the ID flag bit stuck
    jnz   Not486        // if so, then is newer that a 486
  }
  return Intel486;

Not486:
  return IntelPentium;
}

#endif

//
// Get the windows version number in a 16bit unsigned int, with the bytes in
// the correct order: major in high byte, minor in low byte. Uses older
// GetVersion() API call.
//
uint TSystem::GetVersion() {
  static uint version = uint( ((::GetVersion()&0xFF) << 8) |
                              ((::GetVersion()&0xFF00) >> 8) );
  return version;
}

//
// Get the windows version flags number in a 16bit unsigned int. This is the
// high 16bits of the older GetVersion() API call.
//
uint TSystem::GetVersionFlags() {
  static uint versionFlags = uint(::GetVersion() >> 16);
  return versionFlags;
}

