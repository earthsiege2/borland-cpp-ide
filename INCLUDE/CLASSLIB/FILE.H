/*------------------------------------------------------------------------*/
/*                                                                        */
/*  FILE.H                                                                */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_FILE_H )
#define CLASSLIB_FILE_H

#ifndef __STDLIB_H
#include <stdlib.h>
#endif

#ifndef __STDIO_H
#include <stdio.h>
#endif

#ifndef __FCNTL_H
#include <fcntl.h>
#endif

#ifndef __STAT_H
#include <sys/stat.h>
#endif

#ifndef __SHARE_H
#include <share.h>
#endif

#ifndef __IO_H
#include <io.h>
#endif

#ifndef __DOS_H
#include <dos.h>
#endif

#if !defined( __SYSTYPES_H )
#include <systypes.h>
#endif

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if !defined( CLASSLIB__TIME_H )
#include <classlib/time.h>
#endif

#if !defined( CLASSLIB__DATE_H )
#include <classlib/date.h>
#endif

#if defined( BI_HAS_HREADWRITE ) && !defined( __WINDOWS_H )
#include <windows.h>
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

struct TFileStatus
{
    TTime createTime;
    TTime modifyTime;
    TTime accessTime;
    long size;
    uint8 attribute;
    char fullName[_MAX_PATH];
};

class _EXPCLASS ostream;

ostream _BIDSFAR & _BIDSFUNC operator << ( ostream _BIDSFAR &, const TFileStatus _BIDSFAR & );

class _BIDSCLASS TFile
{

public:

    enum { FileNull = -1 };

    enum{
    //  Open mode
        ReadOnly    = O_RDONLY,
        ReadWrite   = O_RDWR,
        WriteOnly   = O_WRONLY,
        Create      = O_CREAT | O_TRUNC,
        CreateExcl  = O_CREAT | O_EXCL,
        Append      = O_APPEND,

    //  Share mode
#if defined( __WIN32__ )
        Compat      = 0,        // SH_COMPAT
        DenyNone    = SH_DENYNO,
#else
        Compat      = SH_COMPAT,
        DenyNone    = SH_DENYNONE,
#endif
        DenyRead    = SH_DENYRD,
        DenyWrite   = SH_DENYWR,
        DenyRdWr    = SH_DENYRW,
        NoInherit   = O_NOINHERIT
        };

    enum{
    //  Permission flags for Create
        PermRead    = S_IREAD,
        PermWrite   = S_IWRITE,
        PermRdWr    = S_IREAD | S_IWRITE
        };

    enum{
    //  DOS file type flags
        Normal      = FA_NORMAL,
        RdOnly      = FA_RDONLY,
        Hidden      = FA_HIDDEN,
        System      = FA_SYSTEM,
        Volume      = FA_LABEL,
        Directory   = FA_DIREC,
        Archive     = FA_ARCH
        };

    enum seek_dir
        { 
        beg = 0, 
        cur = 1, 
        end = 2 
        };

    TFile();
    TFile( int handle );
    TFile( const TFile _BIDSFAR & file );
    TFile( const char _BIDSFAR * name,
           uint16 access=ReadOnly,
           uint16 permission=PermRdWr );
   ~TFile();

    int Open( const char _BIDSFAR * name, uint16 access, uint16 permission );
    int Close();

    int GetHandle() const;

    long Position() const;
    long Length() const;
    void Length( long newLen );
    long Seek( long offset, int origin = beg );
    long SeekToBegin();
    long SeekToEnd();
    int GetStatus( TFileStatus _BIDSFAR & status ) const;
    int IsOpen() const;

    int Read( void _BIDSFAR *buffer, int numBytes );
#if defined( BI_HAS_HREADWRITE )
    long Read( void __huge *buffer, long numBytes );
#endif
    int Write( const void _BIDSFAR *buffer, int numBytes );
#if defined( BI_HAS_HREADWRITE )
    long Write( const void __huge *buffer, long numBytes );
#endif
    void Flush();

    void LockRange( long position, uint32 count );
    void UnlockRange(long Position, uint32 count );

    static int GetStatus( const char _BIDSFAR *name, TFileStatus _BIDSFAR & status );
    static int SetStatus( const char _BIDSFAR *name, const TFileStatus _BIDSFAR & status );
    static void Remove( const char _BIDSFAR *name );
    static void Rename( const char _BIDSFAR *oldName, const char _BIDSFAR *newName );

private:

    int Handle;         // Low-level C file handle
    int ShouldClose;    // Should C++ object close file on dtor

};

//---------------------------------------------------------------------------
// Inlines
//---------------------------------------------------------------------------

inline TFile::TFile() : Handle( FileNull ), ShouldClose(0)
{
}

inline TFile::TFile( int h ) : Handle(h), ShouldClose(0)
{
}

inline TFile::TFile( const TFile& file) : ShouldClose(1)
{
    Handle = ::dup( file.Handle );
}

inline TFile::TFile(const char *name, uint16 access, uint16 permission) :
    Handle(FileNull),
    ShouldClose(1)
{
    Open( name, access, permission );
}

inline TFile::~TFile()
{
    if( IsOpen() && ShouldClose )
        ::close(Handle);
}

inline int TFile::GetHandle() const
{ 
    return Handle; 
}

inline long TFile::Position() const
{
    return ::tell(Handle);
}

inline int TFile::IsOpen() const
{ 
    return Handle > FileNull; 
}

inline void TFile::Length( long newLen )
{
    ::chsize( Handle, newLen);
}

inline long TFile::Seek( long offset, int origin )
{
    return ::lseek( Handle, offset, origin);
}

inline long TFile::SeekToBegin()
{
    return ::lseek( Handle, 0, beg );
}

inline long TFile::SeekToEnd()
{
    return ::lseek( Handle, 0, end );
}

inline int TFile::Read( void *buffer, int numBytes )
{
    return ::_rtl_read( Handle, buffer, numBytes );
}

inline int TFile::Write( const void *buffer, int numBytes)
{
    return ::_rtl_write( Handle, buffer, numBytes );
}

inline void TFile::Flush()
{
    ::close(::dup(Handle));
}

inline void TFile::LockRange( long position, uint32 count )
{
    ::lock( Handle, position, count );
}

inline void TFile::UnlockRange( long position, uint32 count )
{
    ::unlock( Handle, position, count );
}

inline void TFile::Remove( const char *name )
{
    ::remove(name);
}

inline void TFile::Rename( const char *oldName, const char *newName )
{
    ::rename( oldName, newName );
}

#if defined( BI_HAS_HREADWRITE )
inline long TFile::Read(void __huge* Buffer, long NumBytes)
{
    return _hread( Handle, Buffer, NumBytes );
}

inline long TFile::Write(const void __huge* Buffer, long NumBytes)
{
    return _hwrite(Handle, Buffer, NumBytes);
}
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#endif  // CLASSLIB_FILE_H
