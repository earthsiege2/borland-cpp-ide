/*------------------------------------------------------------------------
 * filename - setenvrn.c
 *
 * function(s)
 *     _setenviron (init proc)
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include <mem.h>

#pragma warn -use

extern int _envLng;             /* environment length           */
extern int _envseg;             /* environment segment          */
extern int _envSize;    /* # of strings in environment * sizeof(char *) */

extern unsigned _WinAllocFlag;

#define EXTRA   4               /* # of extra envp slots to include*/

#if defined(__DPMI16__)
extern char _FAR **_C0environ;
int _setenvp__  = 0;  // This is the symbol which pulls in _setenvp
#endif

char **		_environ = NULL;
static char *	evBlockSave;

/*----------------------------------------------------------------------*

Name    _setenviron - initializes the global variable _environ

Usage   Is executed when any reference to _environ causes this module
        to be linked in.

Desc.   Allocates and initializes the global variable _environ.

Notes   Must be executed after _setenv init proc so that _envLng, _envseg,
        and _envSize are already setup.

*-----------------------------------------------------------------------*/
static void _setenviron(void)
{
    int  i;
    char *evBlock;
    unsigned Old_WinAllocFlag = _WinAllocFlag;

/*
    Get block to hold strings, copy the strings to the local block.
    Get a block to hold the envp array pointers.  We'll get a
    block large enough to hold 4 more pointers than there currently
    are.  This way minor additions can be made to the environment
    without having to realloc the pointer array each time.
    Fill in array of pointers with the addresses of the strings.
    Make _envSize reflect how many slots there are now.
*/

    _WinAllocFlag |= 0x2000;
    if ((evBlockSave = evBlock = malloc(_envLng)) == NULL)
        abort();
    movedata(_envseg, 0, FP_SEG((char far *)evBlock),
             FP_OFF((char far *)evBlock), _envLng);

    i = ((_envSize/sizeof(char *))+EXTRA) * sizeof(char *);
    if ((_environ = (char **)malloc(i)) == NULL)
        abort();
    memset(_environ, 0, i);
    
    for (i=0; i<(_envSize/sizeof(char*)); i++, evBlock+=(strlen(evBlock)+1))
        _environ[i] = evBlock;
    _envSize += EXTRA*sizeof(char*);
    _WinAllocFlag = Old_WinAllocFlag;

#if defined(__DPMI16__)
    _C0environ = _environ;
#endif
}

#pragma startup _setenviron 9  	/* Must be executed after _setenv (8) */

static void _rlsenviron(void)
{
    free(evBlockSave);
    free(_environ);
}
#pragma exit _rlsenviron 9  	

