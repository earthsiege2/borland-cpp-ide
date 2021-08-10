//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//
// ExitWin will exit Windows.  If "prompt" is given on the command-line then
// the user will be prompted to confirm the exit.
//
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <services/memory.h>
#include <string.h>

//
//
//
int PASCAL WinMain(HINSTANCE, HINSTANCE, LPSTR clpLine, int)
{
  if (strstr((char*)clpLine, "prompt") != 0)
    if (::MessageBox(0, "Confirm!", "Exit Windows", MB_OKCANCEL) == IDCANCEL)
      return 0;

#if defined(BI_PLAT_WIN16)
  return ExitWindows(0,0);

#elif defined(BI_PLAT_WIN32)

  // Check for Win32s and use the old Win16 API version if so
  //
  if ((::GetVersion()&0x80000000) && (::GetVersion()&0xFF) < 4)
    return ExitWindows(0,0);

  // Must be WinNT or Win 4.X. If NT, adjust privaleges first
  //
  if ((::GetVersion()&0xFF) < 4) {
    HANDLE            hToken;
    LUID              takeOwnershipValue;
    TOKEN_PRIVILEGES  tkp;

    if (!OpenProcessToken(GetCurrentProcess(),
                          TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
      return !::MessageBox(0, "Exit Error", "OpenProcessToken() failed", MB_OK);
    if (!LookupPrivilegeValue(0, SE_SHUTDOWN_NAME, &takeOwnershipValue))
      return !::MessageBox(0, "Exit Error", "LookupPrivilegeValue() failed", MB_OK);

    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Luid = takeOwnershipValue;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    AdjustTokenPrivileges(hToken, false, &tkp, sizeof(TOKEN_PRIVILEGES), 0, 0);
    if (GetLastError())
      return !::MessageBox(0, "Exit Error", "AdjustTokenPrivileges() failed", MB_OK);
  }

  // Now call the Win32 API to force windows to shutdown.
  //
  return ExitWindowsEx(EWX_FORCE | EWX_SHUTDOWN,0);
#endif
}
