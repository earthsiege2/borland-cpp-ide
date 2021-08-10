/*------------------------------------------------------------------------*/
/*                                                                        */
/*  FILEDATA.CPP                                                          */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved.                                                  */
/*                                                                        */
/*  Sorted container example source file                                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

#ifndef __IOSTREAM_H
#include <iostream.h>
#endif

#ifndef __IOMANIP_H
#include <iomanip.h>
#endif

#ifndef __DIR_H
#include <dir.h>
#define __DIR_H
#endif

#ifndef __FILEDATA_H
#include "filedata.h"
#endif

FileData::FileData( ffblk& blk ) :
    FileName( blk.ff_name ),
    FileSize( blk.ff_fsize ),
    FileTime( 
              TDate( 
                     blk.ff_fdate & 0x0001F,
                     (blk.ff_fdate >> 5) & 0x000F,
                     (blk.ff_fdate >> 9) + 80 ),
              blk.ff_ftime >> 11,
              (blk.ff_ftime >> 5) & 0x3F,
              blk.ff_ftime & 0x1F )
{
}

ostream& operator << ( ostream&os, const FileData& f )
{
    os << setw( 14 ) << setiosflags( ios::left )   << f.FileName
       << setw( 27 ) << f.FileTime << resetiosflags( ios::left )
       << setw( 10 ) << f.FileSize << " bytes";
    return os;
}

int FilesByName::operator == ( const FilesByName& testFile ) const
{
    return FileName == testFile.FileName;
}

int FilesByName::operator <  ( const FilesByName& testFile ) const
{
    return FileName < testFile.FileName;
}

int FilesByDate::operator == ( const FilesByDate& testFile ) const
{
    return FileTime == testFile.FileTime;
}

int FilesByDate::operator <  ( const FilesByDate& testFile ) const
{
    return FileTime < testFile.FileTime;
}

int FilesBySize::operator == ( const FilesBySize& testFile ) const
{
    return FileSize == testFile.FileSize;
}

int FilesBySize::operator <  ( const FilesBySize& testFile ) const
{
    return FileSize < testFile.FileSize;
}
