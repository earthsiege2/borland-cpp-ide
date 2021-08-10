/*------------------------------------------------------------------------
 * filename - winmain.c
 *
 * function(s)
 *        WinMain - main entry point for EasyWindows programs
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

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
