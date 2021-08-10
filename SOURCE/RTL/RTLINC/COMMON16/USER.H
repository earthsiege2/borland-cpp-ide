/*------------------------------------------------------------------------
 * filename - user.h
 *
 *      user-defined part of C++ I/O stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1990, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $ */

union ios_user_union {
    long lword;
    void *pword;
};
