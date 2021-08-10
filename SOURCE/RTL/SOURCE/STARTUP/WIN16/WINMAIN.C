/*------------------------------------------------------------------------
 * filename - winmain.c
 *
 * function(s)
 *        WinMain - main entry point for EasyWindows programs
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.3  $        */

#include <windows.h>
#include <dos.h>

#ifndef __DLL__

int main(int argc, char *argv[], char *env[]);

#pragma inline
asm extrn __InitEasyWin

#pragma argsused
int PASCAL WinMain(HANDLE hInstance, HANDLE hPrevInstance,
                   LPSTR lpszCmdLine, int cmdShow)
{
    return main(_argc, _argv, _environ);
}

#endif  // !__DLL__
