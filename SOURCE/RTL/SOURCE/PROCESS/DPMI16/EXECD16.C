/*-----------------------------------------------------------------------*
 * filename - execd16.c  (DPMI16 version)
 *
 * function(s)
 *        exec - creates and runs child processes
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1994 by Borland International
 *      All Rights Reserved.
 *
 */


#include <_process.h>

/*--------------------------------------------------------------------------*
 * _exec: Low level helper function for the exec... functions.
 *        In DPMI16 land we cannot preform a true exec (meaning
 *        unloading ourselves and then spawning to the target process)
 *        so we put the current process on hold and run the target
 *        process by calling spawn.
 *
 *--------------------------------------------------------------------------*/

int cdecl near _exec (char *pathP, char *cmdP, char *envP)
{
        return _spawn (pathP, cmdP, envP);
}
