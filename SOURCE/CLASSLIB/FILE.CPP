/*------------------------------------------------------------------------*/
/*                                                                        */
/*  FILE.CPP                                                              */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __LIMITS_H )
#include <limits.h>
#endif

#if !defined( __DIR_H )
#include <dir.h>
#endif

#if !defined( __DOS_H )
#include <dos.h>
#endif

#if !defined( __IOSTREAM_H )
#include <iostream.h>
#endif

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if defined( BI_PLAT_OS2 ) && !defined( __OS2_H )
#define INCL_BASE
#include <os2.h>
#endif

#if defined( BI_PLAT_WIN32 ) && !defined( __WINDOWS_H )
#include <windows.h>
#endif

#if !defined( CLASSLIB_FILE_H )
#include <classlib/file.h>
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

#if !defined( __OS2__ )
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
#else

TTime MakeTTime( FDATE fdate, FTIME ftime )
{
    TDate fileDate( fdate.day, fdate.month, fdate.year );
    return TTime( fileDate, ftime.hours, ftime.minutes, ftime.twosecs*2 );
}

int TFile::GetStatus( TFileStatus _BIDSFAR& status ) const
{
    FILESTATUS stat;
    if( ::DosQueryFileInfo( Handle, FIL_STANDARD, &stat, sizeof(stat) ) != 0 )
        return 0;
    status.createTime = MakeTTime( stat.fdateCreation, stat.ftimeCreation );
    status.modifyTime = MakeTTime( stat.fdateLastWrite, stat.ftimeLastWrite );
    status.accessTime = MakeTTime( stat.fdateLastAccess, stat.ftimeLastAccess );
    status.size = stat.cbFile;
    status.attribute = stat.attrFile;
    status.fullName[0] = '\0';
    return 1;
}
#endif

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

#if !defined( __OS2__ )
int TFile::GetStatus( const char _BIDSFAR *name,
                      TFileStatus _BIDSFAR & status )
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
#else
int TFile::GetStatus( const char _BIDSFAR *name,
                      TFileStatus _BIDSFAR & status )
{
    if( ::_fullpath( status.fullName, name, sizeof(status.fullName) ) == 0 )
        {
        status.fullName[0] = '\0';
        return 0;
        }
    const uint16 FA_ALL = FA_RDONLY | FA_HIDDEN | FA_SYSTEM |
                          FA_LABEL | FA_DIREC | FA_ARCH;
    HDIR Handle;
    FILEFINDBUF stat;
    ULONG count;
    if( ::DosFindFirst( status.fullName,
                        &Handle,
                        FA_ALL,
                        &stat,
                        sizeof(stat),
                        &count,
                        0 ) != 0 )
        {
        status.fullName[0] = '\0';
        return 0;
        }
        
    status.createTime = MakeTTime( stat.fdateCreation, stat.ftimeCreation );
    status.modifyTime = MakeTTime( stat.fdateLastWrite, stat.ftimeLastWrite );
    status.accessTime = MakeTTime( stat.fdateLastAccess, stat.ftimeLastAccess );
    status.size = stat.cbFile;
    status.attribute = stat.attrFile;
    return 1;
}
#endif

#if !defined( __OS2__ )
int TFile::SetStatus( const char _BIDSFAR *name,
                      const TFileStatus _BIDSFAR & status )
{
    int attr = ::_rtl_chmod( name, 0 );
    if( attr & TFile::RdOnly )
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
#else

FDATE MakeFDATE( TTime time )
{
    FDATE fdate;
    fdate.day = TDate(time).Day();
    fdate.month = TDate(time).Month();
    fdate.year = TDate(time).Year();
    return fdate;
}

FTIME MakeFTIME( TTime time )
{
    FTIME ftime;
    ftime.hours = time.Hour();
    ftime.minutes = time.Minute();
    ftime.twosecs = time.Second()/2;
    return ftime;
}

int TFile::SetStatus( const char _BIDSFAR *name,
                      const TFileStatus _BIDSFAR & status )
{
    FILESTATUS stat;
    stat.fdateCreation = MakeFDATE( status.createTime );
    stat.ftimeCreation = MakeFTIME( status.createTime );
    stat.fdateLastAccess = MakeFDATE( status.accessTime );
    stat.ftimeLastAccess = MakeFTIME( status.accessTime );
    stat.fdateLastWrite = MakeFDATE( status.modifyTime );
    stat.ftimeLastWrite = MakeFTIME( status.modifyTime );
    stat.cbFile = status.size;
    stat.cbFileAlloc = status.size;
    stat.attrFile = status.attribute;
    TFile file( name, ReadWrite | DenyWrite );
    return ::DosSetFileInfo( file.GetHandle(),
                             FIL_STANDARD,
                             &stat,
                             sizeof(stat) );
}
#endif


