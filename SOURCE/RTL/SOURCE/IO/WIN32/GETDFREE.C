/*---------------------------------------------------------------------------
 * filename - getdfree.c
 *
 * function(s)
 *        getdfree - gets disk free space
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1991, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ntbc.h>

#include <dos.h>

/*--------------------------------------------------------------------------*

Name            getdfree - gets disk free space

Usage           #include <dos.h>
                void getdfree(int drive, struct dfree *dfreep);

Prototype in    dos.h

Description     accepts a drive specifier in drive (0 = default, 1 = A, etc.)
                and fills in the dfree structure pointed to by dfreep with
                disk characteristics.

                The dfree structure is defined as follows:

                struct dfree {
                        unsigned df_avail;      (* Available clusters *)
                        unsigned df_total;      (* Total clusters *)
                        unsigned df_bsec;       (* Bytes per sector *)
                        unsigned df_sclus;      (* Sectors per cluster *)
                };

Return value    Nothing. In the event of an error, df_sclus in the
                dfree structure is set to -1.

*---------------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC getdfree(unsigned char drive, struct dfree *dtable)
{
    char root[4];
    char *rootname;
    DWORD spc;      /* sectors per cluster */
    DWORD bps;      /* bytes per sector */
    DWORD nfc;      /* no. of free clusters */
    DWORD tnc;      /* total no. of clusters */

    if (drive == 0)     /* default drive */
        rootname = NULL;
    else
    {
        root[0] = drive - 1 + 'A';
        root[1] = ':';
        root[2] = '\\';
        root[3] = '\0';
        rootname = root;
    }

    if (GetDiskFreeSpace(rootname, &spc, &bps, &nfc, &tnc) != TRUE)
        dtable->df_sclus = (unsigned)-1;        /* failure */
    else
    {
        dtable->df_total = (unsigned)tnc;
        dtable->df_avail = (unsigned)nfc;
        dtable->df_sclus = (unsigned)spc;
        dtable->df_bsec  = (unsigned)bps;
    }
}
