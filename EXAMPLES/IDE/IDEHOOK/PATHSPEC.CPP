//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#pragma hdrstop
#include <string.h>
#include <dos.h>
#include <commdlg.h>
#include "pathspec.h"


//                                      //
//    class PathSpec implementation     //
//                                      //

int
PathSpec::split()
{
    return( _flags = ::fnsplit( _path, _drive, _dir, _file, _ext ) );
}

void
PathSpec::merge()
{
    ::fnmerge( _path, _drive, _dir, _file, _ext );
}

void
PathSpec::path(const char *path)
{
    strcpy( _path, path );
    split();
}

void
PathSpec::drive(const char *drive)
{
    strcpy( _drive, drive );
    merge();
}

void
PathSpec::dir(const char *dir)
{
    strcpy( _dir, dir );
    merge();
}

void
PathSpec::file(const char *file)
{
    strcpy( _file, file );
    merge();
}

void
PathSpec::ext(const char *ext)
{
    strcpy( _ext, ext );
    merge();
}

void
PathSpec::fileext( const char *fileExt )
{
    char * p = (char *)(strchr(fileExt,'.'));

    if( !p )
        p = "";

    ext( p );
    *p = 0;

    file( fileExt );
}

int
PathSpec::first()
{
    if( ::findfirst( _path, &_dta, 0 ) == -1 )
        return(0);

    fileext( _dta.ff_name );
    return( 1 );
}

int
PathSpec::next()
{
    if( ::findnext( &_dta ) == -1 )
        return( 0 );

    fileext( _dta.ff_name );
    return( 1 );
}

int
PathSpec::sameDrive( PathSpec & other )
{
    if( *_drive == *other._drive )
        return(1);

    if( !*_drive )
    {
        _drive[0] = ::getdisk() + 'A' - 1;
        _drive[1] = ':';
        _drive[2] = 0;
    }
    else
    {
        if( !*other._drive )
        {
            other._drive[0] = ::getdisk() + 'A' - 1;
            other._drive[1] = ':';
            other._drive[2] = 0;
        }
    }

    char    s[3];

    s[0] = *_drive;
    s[1] = *other._drive;
    s[2] = 0;
    
    strlwr( s );

    return( s[0] == s[1] );
}

int
PathSpec::isDirectory()
{
    int lastCharPos = strlen( _path ) - 1;

    char lastChar;
    
    if(((lastChar = _path[lastCharPos]) == '\\') || (lastChar == '/'))
        _path[lastCharPos] = 0;

    int ret =  (::findfirst( _path, &_dta, FA_DIREC ) != -1 ) &&
                  ( _dta.ff_attrib & FA_DIREC );
             
    _path[ lastCharPos ] = lastChar;
        
    return( ret );
}

char *
PathSpec::stripTrailingSlash()
{
    int lastCharPos = strlen( _path ) - 1;

    if( (_path[lastCharPos] == '\\') || (_path[lastCharPos] == '/') )
        _path[lastCharPos] = 0;

    return( _path );
}

void
PathSpec::addTrailingSlash()
{
    int lastCharPos = strlen( _path ) - 1;

    if( (_path[lastCharPos] != '\\') && (_path[lastCharPos] != '/') )
    {
        strcat( _path, "\\" );
        split();
    }
}

int
PathSpec::newFileDialog
(
   const char *    filter,
   const char *    initialDir,
   unsigned long   hwndParent
)
{
   return(
       fileDialog
           (
               filter,
               initialDir,
               hwndParent,
               OFN_HIDEREADONLY |
               OFN_PATHMUSTEXIST
           )
        );
}

int
PathSpec::openFileDialog
(
   const char *    filter,
   const char *    initialDir,
   unsigned long   hwndParent
)
{
   return(
       fileDialog
           (
               filter,
               initialDir,
               hwndParent,
               OFN_HIDEREADONLY |
               OFN_PATHMUSTEXIST |
               OFN_FILEMUSTEXIST
           )
        );
}

int
PathSpec::fileDialog
(
   const char *    filter,
   const char *    initialDir,
   unsigned long   hwndParent,
   unsigned long   flags
)
{
    char           szFile[256];
    char          *szFilter;

    strcpy( szFile, file() );
    if( *szFile )
       strcat( szFile, ext() );

    if( !filter )
       filter = "All files (*.*)|(*.*)|";
    szFilter = new char[ strlen(filter) + 1 ];
    strcpy( szFilter, filter );
    
    for ( unsigned short i = 0; szFilter[i] != 0; i++)
    {
        if (szFilter[i] == '|' )
           szFilter[i] = 0;
    }

    /* Set all structure members to zero. */

    OPENFILENAME   ofn;

    memset( &ofn, 0, sizeof(ofn) );

    ofn.lStructSize        = sizeof(OPENFILENAME);
    ofn.hwndOwner          = (HWND)(hwndParent);
    ofn.lpstrFilter        = szFilter;
    ofn.nFilterIndex       = 1;
    ofn.lpstrFile          = szFile;
    ofn.nMaxFile           = sizeof(szFile);
    ofn.lpstrInitialDir    = initialDir;
    ofn.Flags              = flags;


    int ret;

    if ( (ret = GetOpenFileName(&ofn)) == 0 )
    {
      DWORD Errval = ::CommDlgExtendedError();

      if (Errval != 0)    // 0 value means user selected Cancel
      {
         char szErr[80];

         wsprintf( szErr, "GetOpenFile error: %ld", Errval );
         ::MessageBox( ::GetActiveWindow(),szErr,"OpenFile", 
                       MB_ICONEXCLAMATION | MB_OK );
      }
    }
    else
    {
       path( ofn.lpstrFile );
    }

    delete szFilter;

    return( ret );
}

// End of file

