//----------------------------------------------------------------------------
// IdeHook - (C) Copyright 1994 by Borland International
//----------------------------------------------------------------------------
#ifndef __PATHSPEC_H
#define __PATHSPEC_H

#ifndef __DIR_H
#  include <dir.h>
#endif

//                                                  //
//    class PathSpec for manipulation file paths    //
//                                                  //

class PathSpec
{
public:
    //        ctor        //
    
    PathSpec( const char * = "" );

    //        accessors            //
    
    const char *    path();
    const char *    drive();
    const char *    dir();
    const char *    file();
    const char *    ext();

    void            path(const char *);
    void            drive(const char *);
    void            dir(const char *);
    void            file(const char *);
    void            ext(const char *);
    void            fileext( const char * );

    long            age();

    //  flags() returns FILENAME, WILDCARDS etc. flags found in dir.h  //
    
    int             flags();

    //        explicit splitter/merger    //
    
    int             split();
    void            merge();

    //        disk manipulation and polling        //
    
    int             exists();
    int             first();
    int             next();

    //        Are this and another PathSpec referring to the same drive? //
    
    int             sameDrive( PathSpec & );

    //        Is this PathSpec really representing a directory?           //
    
    int             isDirectory();

    void            addTrailingSlash();
    
    //  Strip the trailing slash from the path() element and return  //
    //  the path(). (Calling this invalidates the use dir(), file()  //
    //  and ext()).                                                  //
    
    char *          stripTrailingSlash();

    //                                                 //
    //     Do a FileOpen dialog on this pathSpec...    //
    //     'filter' should use the pipe character ('|')//
    //         as a separator                          //
    //         (e.g. "All files (*.*)|*.*|")           //
    //     NOTE: In this implementation 'hwndParent'   //
    //     is a Windows' HWND.                         //
    //                                                 //
    
    int             openFileDialog
                        (
                           const char *    filter = 0,
                           const char *    initialDir = 0,
                           unsigned long   hwndParent = 0
                        );
        
    int             newFileDialog
                        (
                           const char *    filter = 0,
                           const char *    initialDir = 0,
                           unsigned long   hwndParent = 0
                        );

    int             fileDialog
                        (
                           const char *    filter = 0,
                           const char *    initialDir = 0,
                           unsigned long   hwndParent = 0,
                           unsigned long   flags = 0
                        );
private:

    char _path [ MAXPATH  ];
    char _drive[ MAXDRIVE ];
    char _dir  [ MAXDIR   ];
    char _file [ MAXFILE  ];
    char _ext  [ MAXEXT   ];
    int  _flags;

    struct ffblk    _dta;
};

inline
PathSpec::PathSpec( const char * apath )
{
    path( apath );
}

inline const char *
PathSpec::path()
{
    return( _path );
}

inline const char *
PathSpec::drive()
{
    return( _drive );
}

inline const char *
PathSpec::dir()
{
    return( _dir );
}

inline const char *
PathSpec::file()
{
    return( _file );
}

inline const char *
PathSpec::ext()
{
    return( _ext );
}

inline int
PathSpec::flags()
{
    return( _flags );
}

inline int
PathSpec::exists()
{
    return( first() );
}

inline long
PathSpec::age()
{
    if( exists() )
    {
        unsigned long date = _dta.ff_fdate;
        unsigned long time = _dta.ff_ftime;

        return( (long)( (date << 16) | time ) );
    }
    return( -1L );
}

#endif __PATHSPEC_H

// End of file

