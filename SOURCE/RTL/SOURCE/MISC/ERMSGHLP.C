/*-----------------------------------------------------------------------*
 * filename - ermsghlp.c
 *
 * function(s)
 *        _ErrorMessageHelper - write an error message to file if
                                specified.

 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1995, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.5.2.1 $        */

#define INCL_USER
#include <ntbc.h>
#include <stdlib.h>
#include <string.h>

/* --------------------------------------------------------------------------*/
static char * DateTime (void)
{

  static char buf[25];
  SYSTEMTIME st;

  GetLocalTime (&st);

  wsprintf (buf, "%02d/%02d/%04d %02d:%02d:%02d.%03d ",
            st.wMonth,
            st.wDay,
            st.wYear,
            st.wHour,
            st.wMinute,
            st.wSecond,
            st.wMilliseconds
         );
  return buf;
}
/* --------------------------------------------------------------------------*/
void _ErrorMessageHelper (const char *msgfile, const char *msg)
{
    HANDLE fh;
    char *date;
    DWORD outcnt;

    if ((fh = CreateFile(msgfile,
                         GENERIC_READ | GENERIC_WRITE,
                         0,
                         NULL,
                         CREATE_ALWAYS,
                         FILE_ATTRIBUTE_NORMAL,
                         0
                        )) == NULL)
    {
        return;
    }

    date = DateTime ();

    WriteFile(fh, (void *)date, strlen(date), &outcnt, NULL);
    WriteFile(fh, (void *)msg, strlen(msg), &outcnt, NULL);
    CloseHandle (fh);
}
/* --------------------------------------------------------------------------*/
