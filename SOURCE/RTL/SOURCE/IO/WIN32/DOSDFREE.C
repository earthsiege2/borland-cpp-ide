/*---------------------------------------------------------------------------
 * filename - dosdfree.c
 *
 * function(s)
 *        _dos_getdiskfree - gets disk free space
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1991, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#include <ntbc.h>
#include <dos.h>
#include <errno.h>

/*--------------------------------------------------------------------------*

Name            _dos_getdiskfree - gets disk free space

Usage           #include <dos.h>
                unsigned _dos_getdiskfree(unsigned drive,
                                        struct diskfree_t *dfreep);

Prototype in    dos.h

Description     accepts a drive specifier in drive (0 = default, 1 = A, etc.)
                and fills in the diskfree_t structure pointed to by dfreep with
                disk characteristics.

                The diskfree_t structure is defined as follows:

                struct diskfree_t {
                        unsigned total_clusters;
                        unsigned avail_clusters;
                        unsigned sectors_per_cluster;
                        unsigned bytes_per_sector;
                };

Return value    Returns 0 on success.  Otherwise, returns non-zero
                and sets errno to:

                        EINVAL  Invalid drive specified

*---------------------------------------------------------------------------*/

unsigned _RTLENTRY _EXPFUNC
_dos_getdiskfree(unsigned drive, struct diskfree_t *dtable)
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
        return (errno = EINVAL);

    dtable->total_clusters = (unsigned)tnc;
    dtable->avail_clusters = (unsigned)nfc;
    dtable->sectors_per_cluster = (unsigned)spc;
    dtable->bytes_per_sector = (unsigned)bps;
    return (0);
}
