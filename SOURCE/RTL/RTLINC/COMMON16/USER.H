/*------------------------------------------------------------------------
 * filename - user.h
 *
 *      user-defined part of C++ I/O stream
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

union ios_user_union {
    long lword;
    void *pword;
};
