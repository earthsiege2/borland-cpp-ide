/*-----------------------------------------------------------------------*
 * filename - strrev.c
 *
 * function(s)
 *        strrev - reverses a string
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#include <string.h>

/*---------------------------------------------------------------------*

Name            strrev - reverses a string

Usage           char *strrev(char * str);

Prototype in    string.h

Description     strrev reverses all characters in a string (except the
                terminating null character).

Return value    strrev returns a pointer to the reversed string. There is no
                error return.

*---------------------------------------------------------------------*/

char * _RTLENTRY _EXPFUNC strrev(char *str)
{
     char *p, *q, r;

     if (!*str)
        return str;
     p = str + strlen(str) - 1;
     q = str;
     while( p > q )
     {
         if (*p == *q)
         {
             --p;
             ++q;
         }
         else
         {
             r = *p;
             *p-- = *q;
             *q++ = r;
         }
     }
     return(str);
}

