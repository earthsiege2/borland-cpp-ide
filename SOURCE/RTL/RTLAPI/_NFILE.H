/*  _nfile.h

    Maximum number of open files

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1991, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#ifndef ___NFILE_H
#define ___NFILE_H

#if !defined(__FLAT__)

#define _NFILE_ 20

#else

#define _NFILE_ 40

#endif

#endif
