//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//
// ExitWin will exit Windows.  If "prompt" is given on the command-line then
// the user will be prompted to confirm the exit.
//
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <string.h>
#include <windows.h>

#if defined(__SMALL__) || defined(__MEDIUM__)
  #define strstr _fstrstr
#endif

int PASCAL WinMain(HINSTANCE, HINSTANCE, LPSTR clpLine, int)
{
  if (strstr(clpLine, "prompt") != 0)
    if (MessageBox(0, "Confirm!", "Exit Windows", MB_OKCANCEL) == IDCANCEL)
      return 0;
  return ExitWindows(0,0);
}
