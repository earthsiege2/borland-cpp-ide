///////////////////////////////////////////////////////////////
// IDE Demo Program                                          //
// Delivery.cpp                                              //
// Copyright (c) 1993 by Borland International               //
///////////////////////////////////////////////////////////////
#include <stdio.h>
#include <dir.h>
#include <classlib\arrays.h>
#include <cstring.h>
#include <fstream.h>


//                                                  //
//  To take advantage of the tracing, attach the    //
//  'Diagnostics' StyleSheet to this node by        //
//  selecting 'Edit node attributes' from the       //
//  node's SpeedMenu and selecting it from the      //
//  StyleSheets dropdown                            //
//                                                  //

DIAG_DEFINE_GROUP( IdeDeliver, 1, 1 );
    

//                                                          //
//  class Delivery                                          //
//                                                          //
//  class Delivery for reading command line and executing   //
//  appropriate actions. If you wish to extend the          //
//  functionality of this program, add a method to the      //
//  to the Delivery class with the same prototype as        //
//  Delivery::Copy and a corresponding entry to the static  //
//  data member Delivery::_commands[]                       //
//                                                          //

class Arguments;

class Delivery
{
public:

    //        Parser/Dispatcher        //
    
    void Execute( Arguments & );

protected:

    //        Commands        //
    
    void Copy   ( Arguments & );
    void Move   ( Arguments & );
    void MkDir  ( Arguments & );
    void Clean  ( Arguments & );
    void Rename ( Arguments & );


private:

    //  Array of command methods and there text equivalents  //
    
    typedef void (Delivery::*commandMethod)( Arguments & );
    
    struct Commands
    {
        commandMethod    parser;
        const char *cmdName;
    };

    static Commands _commands[];

    // low-level helpers..    //

    enum FileCmd 
    {
        fcCopy,
        fcMove
    };
    
    void FilesCopyMove( Arguments &, FileCmd );
    void FilesCopyMove( const char *, const char *, FileCmd );

    void FileCopy  ( const char *, const char *);
    void FileMove  ( const char *, const char *, int );
    void FileRename( const char *, const char *);
    void FileDelete( const char *, int okToFail = 1 );
    
};


//                                              //
//    class Arguments                           //
//    Array for holding command line arguments  //
//                                              //

class _BIDSCLASS Arguments : public TArray<string>
{
public:
    Arguments( int argc, char * * argv );

    //        Return the Deliver command text found on command line  //
    
    const char * command();

    //        Return the last filename on the command line. (This has  //
    //        the side-effect of limiting the number of valid source   //
    //        filenames by one.)                                       //
    
    const char * destination();

    //        Return the filename at 'index'. Valid values for index     //
    //        start at 1 (one) and this method will return 0 when there  //
    //        are no more source filenames.                              //
    
    const char * source( int index );
    
private:
    
    void expandFile( char * );
    const char * arg(int i);

    int _destinationAt;
    
};

inline const char * 
Arguments::arg( int i )
{
    return( ((*this)[i]).c_str() );
}

//    PrintProgramSignature will output the program signature //

void PrintProgramSignature()
{
    static int headerHasBeenPut = 0;

    if( !headerHasBeenPut )
    {
        cout  << "Deliver:"
                << endl;
                
        headerHasBeenPut = 1;
    }
}

//                 //
//        main()   //
//                 //

int main (int argc, char * argv[])
{
    int    returnCode;
    
    try
    {
        Arguments    args( argc, argv );

        Delivery        parser;

        parser.Execute( args );

        returnCode = 0;
        
    }
    catch ( xmsg & x )
    {  
        PrintProgramSignature();
        
        cout    << "Fatal Error: " 
                << x.why() 
                << endl;
                
        returnCode = 2;
    }

    return returnCode;
    
}

//                                                  //
//    class FileSpec for manipulation file paths    //
//                                                  //

class FileSpec
{
public:
    //        ctor        //
    
    FileSpec( const char * = "" );

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

    //        flags() returns FILENAME, WILDCARDS etc. flags found in dir.h  //
    
    int             flags();

    //        explicit splitter/merger    //
    
    int             split();
    void            merge();

    //        disk manipulation and polling        //
    
    int             exists();
    int             first();
    int             next();

    //        Are this and another FileSpec referring to the same drive? //
    
    int             sameDrive( FileSpec & );

    //        Is this FileSpec really representing a directory?           //
    
    int             isDirectory();

    void            addTrailingSlash();
    
    //        Strip the trailing slash from the path() element and return  //
    //        the path(). (Calling this invalidates the use dir(), file()  //
    //        and ext()).                                                  //
    
    char *          stripTrailingSlash();
        
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
FileSpec::FileSpec( const char * apath )
{
    path( apath );
}

inline const char *  
FileSpec::path()
{
    return( _path );
}

inline const char *    
FileSpec::drive()
{
    return( _drive );
}

inline const char *    
FileSpec::dir()
{
    return( _dir );
}

inline const char *    
FileSpec::file()
{
    return( _file );
}

inline const char *    
FileSpec::ext()
{
    return( _ext );
}

inline int 
FileSpec::flags()
{
    return( _flags );
}

inline int
FileSpec::exists()
{
    return( first() );
}

inline long
FileSpec::age()
{
    if( exists() )
    {
        unsigned long date = _dta.ff_fdate;
        unsigned long time = _dta.ff_ftime;
        
        return( (long)( (date << 16) | time ) );
    }
    return( -1L );
}

//                                  //
//        class Delivery implemenation    //
//                                  //

Delivery::Commands Delivery::_commands[] =
{
    { &Delivery::Copy,  "COPY"   },
    { &Delivery::Move,  "MOVE"   },
    { &Delivery::MkDir, "MKDIR"  },
    { &Delivery::Clean, "CLEAN"  },
    { &Delivery::Rename,"RENAME" },
    { 0 }
};

void 
Delivery::Execute( Arguments & args )
{
    const char * cmdName = args.command();

    int cmdNo = -1;
    
    for( int i = 0; _commands[i].cmdName; i++ )
    {
        if( !stricmp( cmdName, _commands[i].cmdName ) )
        {
            cmdNo = i;
            break;
        }
    }

    if( cmdNo == -1 )
        throw xmsg( "Unknown command!" );

    (this->*_commands[cmdNo].parser)( args );
}

void
Delivery::FileCopy( const char * source, const char * destination )
{
    TRACEX( IdeDeliver, 0,
                  "Copy source: \"" 
                << source 
                << "\" => \""
                << destination
                << "\"" );

    FILE    * in;
    FILE  * out;

    if( (in = fopen(source, "rb")) == 0 )
        throw xmsg( "Error opening source" );

    if( (out = fopen(destination, "wb")) == 0 )
        throw xmsg( "Error opening destination" );

    register int c;

    while( (c = fgetc(in)) != EOF )
        fputc(c,out);

    fclose(in);
    fclose(out);
}

void
Delivery::FileMove
    ( const char * source, const char * destination, int sameDrive )
{
    if( sameDrive )
    {
        //    '1' here means it's ok for Delete to fail...  //
        
        FileDelete( destination, 1 );
        FileRename( source, destination );
    }
    else
    {
        FileCopy( source, destination );
        FileDelete( source );
    }
}

void
Delivery::FileDelete( const char * fileName, int okToFail )
{
    if( ::unlink( fileName ) && !okToFail )
        throw xmsg( "Error deleting file" );
}

void
Delivery::FileRename( const char * oldName, const char * newName )
{
  if( ::rename( oldName, newName ) )
        throw xmsg( "Error renaming file" );
}

void
Delivery::FilesCopyMove
  ( const char * sourceFile, const char * destinationFile, FileCmd cmd )
{
    FileSpec    source     ( sourceFile );
    FileSpec    destination( destinationFile );

    if( !source.first() )
        throw    xmsg( "Can\'t find source" );

    int useSourceFileName;

    if( destination.isDirectory() )
    {
        destination.addTrailingSlash();    
        useSourceFileName = 1;
    }
    else
    {
        useSourceFileName = 0;
    }
        
    do
    {
        if( useSourceFileName )
        {
            destination.file( source.file() );
            destination.ext ( source.ext()  );
        }
            
        if( cmd == fcCopy )
        {
            //        Future: there could be a check here for the ages  //
            //        of the FileSpecs if the user had requested        //
            //        'update' copy                                     //
            
            FileCopy( source.path(), destination.path() );
        }
        else
        {
            FileMove(     source.path(), 
                            destination.path(), 
                            destination.sameDrive( source ) );
        }

    } while( source.next() );
    
}
    

void
Delivery::FilesCopyMove( Arguments & args, FileCmd cmd )
{
    const char * destination = args.destination();

    const char * source;
    
    int i = 1;
    
    while( (source = args.source(i++)) != 0 )
    {
        FilesCopyMove( source, destination, cmd );
    }
}
    
void 
Delivery::Copy ( Arguments & args )
{
    FilesCopyMove( args, fcCopy );
}

void 
Delivery::Move ( Arguments & args )
{
    FilesCopyMove( args, fcMove );
}

void 
Delivery::MkDir( Arguments & args )
{
    const char * source;
    
    int i = 1;

    while( (source = args.source(i++)) != 0 )
    {
        FileSpec    dirName( source );

        //    Future: it would be nice if this did a recursive   //
        //    makedir like XCOPY                                 //
        
        if( ::mkdir( dirName.stripTrailingSlash() ) )
            throw xmsg( "Error making directory" );
    }
}

void 
Delivery::Clean( Arguments & args )
{
    const char * sourceFile;
    FileSpec         source;
    
    int i = 1;
    
    while( (sourceFile = args.source(i++)) != 0 )
    {
        source.path( sourceFile );

        if( !source.exists() )
        {
            PrintProgramSignature();
            cout    << "Warning DELIVER : Can\'t find "
                    << source.path()
                    << endl;
            continue;
        }
        
        do FileDelete( source.path() );
          while( source.next() );
    }
}

void 
Delivery::Rename( Arguments & args )
{
    if( args.GetItemsInContainer() != 3 )
        throw    xmsg( "Wrong number of arguments for renaming" );

    FileRename( args.source(1), args.destination() );
}

 
//                                      //
//      class Arguments implementation  //
//                                      //

Arguments::Arguments( int argc, char * * argv )
    : TArray<string>( 10 )
{
    for( int i = 1; i < argc; i++ )
    {
        char * arg = argv[i];

        if( *arg == '+' )
            expandFile( arg+1 ); 
        else
            Add( arg );
     }

    //        Initialize to one past the last item on the command line, if   //
    //        the caller calls the destination() method, we'll crank this    //
    //        back by one.                                                   //
    
    _destinationAt = GetItemsInContainer();
     
}
    

void 
Arguments::expandFile( char * fileName )
{
    //        This method will open a response file and treat every text  //
    //        word found in the file as an entry on the command line      //
    
    ifstream    in( fileName );

    if( !in.good() )
        throw    xmsg( "Can't open response file" );
        
    string    nextString;
    
    while( in.good() )
    {
        in >> nextString;
        nextString.strip( string::Both, ' ' );
        if( nextString.length() )
            Add( nextString );
    }
}

const char *
Arguments::source( int index )
{
    if( index < 1 )
        throw xmsg( "Missing source operand" );
        
    return( index >= _destinationAt ? 0 : arg(index) );
}

const char *
Arguments::command()
{
    if( !GetItemsInContainer() )
        throw xmsg( "Missing command" );
        
    return( arg(0) );
}

const char * 
Arguments::destination()
{
    if( GetItemsInContainer() < 3 )
        throw xmsg( "Missing destination operand" );

    //    This controls the effictiveness of the method source()  //
    
    --_destinationAt;
    
    return( arg(_destinationAt) );
}

//                                 //
//    class FileSpec implementation   //
//                                 //

int 
FileSpec::split()
{
    return( _flags = ::fnsplit( _path, _drive, _dir, _file, _ext ) );
}

void 
FileSpec::merge()
{
    ::fnmerge( _path, _drive, _dir, _file, _ext );
}

void 
FileSpec::path(const char *path)
{
    strcpy( _path, path );
    split();
}

void 
FileSpec::drive(const char *drive)
{
    strcpy( _drive, drive );
    merge();
}

void 
FileSpec::dir(const char *dir)
{
    strcpy( _dir, dir );
    merge();
}

void 
FileSpec::file(const char *file)
{
    strcpy( _file, file );
    merge();
}

void 
FileSpec::ext(const char *ext)
{
    strcpy( _ext, ext );
    merge();
}

void
FileSpec::fileext( const char *fileExt )
{
    char * p = (char *)(strchr(fileExt,'.'));

    if( !p )
        p = "";

    ext( p );
    *p = 0;

    file( fileExt );
}

int 
FileSpec::first()
{
    if( ::findfirst( _path, &_dta, 0 ) == -1 )    
        return(0);

    fileext( _dta.ff_name );
    return( 1 );
}

int
FileSpec::next()
{
    if( ::findnext( &_dta ) == -1 )
        return( 0 );

    fileext( _dta.ff_name );
    return( 1 );
}

int
FileSpec::sameDrive( FileSpec & other )
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
FileSpec::isDirectory()
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
FileSpec::stripTrailingSlash()
{
    int lastCharPos = strlen( _path ) - 1;

    if( (_path[lastCharPos] == '\\') || (_path[lastCharPos] == '/') )
        _path[lastCharPos] = 0;

    return( _path );
}

void
FileSpec::addTrailingSlash()
{
    int lastCharPos = strlen( _path ) - 1;

    if( (_path[lastCharPos] != '\\') && (_path[lastCharPos] != '/') )
    {
        strcat( _path, "\\" );
        split();
    }
}
    

//  End of file     //
