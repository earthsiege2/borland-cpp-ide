/*------------------------------------------------------------------------*/
/*                                                                        */
/*  FILEDATA.H                                                            */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved.                                                  */
/*                                                                        */
/*  Sorted container example header file                                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

#ifndef __FILEDATA_H
#define __FILEDATA_H

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif  // __CSTRING_H

#if !defined( __CLASSLIB__TIME_H )
#include "classlib\time.h"
#endif  // __LTIME_H

#ifndef __DIR_H
#include <dir.h>
#endif

class FileData
{

public:

    FileData( ffblk& );

    friend ostream& operator << ( ostream&, const FileData& );

protected:

    string FileName;
    TTime FileTime;
    long FileSize;

};

class FilesByName : public FileData
{

public:

    FilesByName( ffblk& blk ) : FileData( blk ) {}

    int operator == ( const FilesByName& ) const;
    int operator <  ( const FilesByName& ) const ;

};

class FilesByDate : public FileData
{

public:

    FilesByDate( ffblk& blk ) : FileData( blk ) {}

    int operator == ( const FilesByDate& ) const;
    int operator <  ( const FilesByDate& ) const;

};

class FilesBySize : public FileData
{

public:

    FilesBySize( ffblk& blk ) : FileData( blk ) {}

    int operator == ( const FilesBySize& ) const;
    int operator <  ( const FilesBySize& ) const;

};

#endif    
