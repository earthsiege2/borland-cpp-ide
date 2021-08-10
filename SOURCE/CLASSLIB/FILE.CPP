/*--------------------------------------------------------------------*/
/*                                                                    */
/*  FILE.CPP                                                          */
/*                                                                    */
/*  Copyright (c) Borland International 1993                          */
/*  All Rights Reserved                                               */
/*                                                                    */
/*--------------------------------------------------------------------*/

#if !defined( __LIMITS_H )
#include <limits.h>
#endif	// __LIMITS_H

#if !defined( __DIR_H )
#include <dir.h>
#endif  // __DIR_H

#if !defined( __DOS_H )
#include <dos.h>
#endif  // __DOS_H

#if !defined( __IOSTREAM_H )
#include <iostream.h>
#endif  // __IOSTREAM_H

#if !defined( __CLASSLIB_FILE_H )
#include "classlib\file.h"
#endif

int TFile::Open( const char _BIDSFAR *name, uint16 access, uint16 permission )
{
    const unsigned shareFlags =
        Compat | DenyNone | DenyRead | DenyWrite | DenyRdWr | NoInherit;
    if( IsOpen() )
        return 0;
    Handle = ::sopen( name,
                      access & ~shareFlags,
                      access & shareFlags,
                      permission );
    return IsOpen();
}

int TFile::Close()
{
    if( IsOpen() && ::close(Handle) == 0) 
        {
        Handle = FileNull;
        return 1;
        }
    else
        return 0;
}

long TFile::Length() const
{
    return ::filelength( Handle );
}

int TFile::GetStatus( TFileStatus _BIDSFAR & status ) const
{
    struct ftime ftime;
    if( ::getftime(Handle, &ftime) != 0 )
        return 0;
    TDate fileDate( ftime.ft_day, ftime.ft_month, ftime.ft_year+80 );
    status.createTime = TTime( fileDate,
                                 ftime.ft_hour,
                                 ftime.ft_min,
                                 ftime.ft_tsec*2 );
    status.modifyTime = status.createTime;
    status.accessTime = status.createTime;
    status.size = Length();
    status.attribute = 0;
    status.fullName[0] = '\0';
    return 1;
}

struct dos_ftime
{
    unsigned tsec : 5;
    unsigned min  : 6;
    unsigned hour : 5;
};

struct dos_fdate
{
    unsigned day  : 5;
    unsigned mon  : 4;
    unsigned year : 7;
};

int TFile::GetStatus( const char _BIDSFAR *name, TFileStatus _BIDSFAR & status )
{
    if( ::_fullpath( status.fullName, name, sizeof(status.fullName) ) == 0 )
        {
        status.fullName[0] = '\0';
        return 0;
        }
    ffblk blk;
    const uint16 FA_ALL = FA_RDONLY | FA_HIDDEN | FA_SYSTEM |
                          FA_LABEL | FA_DIREC | FA_ARCH;
    if( findfirst( status.fullName, &blk, FA_ALL ) != 0 )
        return 0;

    union
    {
        dos_ftime time;
        dos_fdate date;
        unsigned value;
    };

    value = blk.ff_fdate;
    TDate fileDate( date.day, date.mon, date.year+80 );
    value = blk.ff_ftime;
    status.createTime = TTime( fileDate,
                                 time.hour,
                                 time.min,
                                 time.tsec*2 );
    
    status.modifyTime = status.createTime;
    status.accessTime = status.createTime;
    status.size = blk.ff_fsize;
    status.attribute = blk.ff_attrib;
    return 1;
}

int TFile::SetStatus( const char _BIDSFAR *name, const TFileStatus _BIDSFAR & status )
{
    int attr = ::_rtl_chmod( name, 0 );
    if( attr & FA_RDONLY )
        return 0;

    ftime fileTime;
    fileTime.ft_tsec = status.createTime.Second()/2;
    fileTime.ft_min = status.createTime.Minute();
    fileTime.ft_hour = status.createTime.Hour();
    TDate date( status.createTime );
    fileTime.ft_day = date.DayOfMonth();
    fileTime.ft_month = date.Month();
    fileTime.ft_year = date.Year()-80;

    TFile file( name, ReadWrite | DenyWrite );
    if( ::setftime( file.GetHandle(), &fileTime ) != 0 )
        return 0;
    if( ::chsize( file.GetHandle(), status.size ) != 0 )
        return 0;
    if( ::_rtl_chmod( name, 1, status.attribute ) == -1 )
        return 0;
    return 1;
}

