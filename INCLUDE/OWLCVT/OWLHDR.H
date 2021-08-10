// OWLCVT
// ObjectWindows - (C) Copyright 1992 by Borland International

#if !defined(__OWLHDR_H)
#define __OWLHDR_H

#if defined(_CLASSDLL) || defined(__DLL__)
#  define _RTLDLL
#endif

#if !defined(BI_OLDNAMES)
#define BI_OLDNAMES
#endif

#include <_defs.h>
#include <typeinfo.h>
#include <fstream.h>
#include <iostream.h>
#include <stdiostr.h>
#include <strstrea.h>
#include <cstring.h>

//
// RTTI and DDVTs don't get along, so we need to disable RTTI
// for OWL 1 code. This also means that we must disable exceptions.
//
#pragma option -RT-
#pragma option -x-

#include <owlrc.h>
#include <stddef.h>
#include <object.h>
#include <windows.h>
#include <dir.h>
#include <array.h>
#include <strng.h>
#include <stdlib.h>
#include <dos.h>

#if         defined(BUILD_OWL)

#if         !defined(WIN31) || !defined(STRICT)
#error   OWL must be built with WIN31 and STRICT defined.
#endif

#if         defined(__COMPACT__)
#error   OWL cannot be built in Compact model.
#endif

#if         defined(__TINY__)
#error   OWL cannot be built in Tiny model.
#endif

#else   //  !defined(BUILD_OWL)

#if         !defined(WIN31) || !defined(STRICT)
#error   OWL applications must be built with WIN31 and STRICT defined.
#endif

#if         defined(__COMPACT__)
#error   OWL applications cannot be built in Compact model.
#endif

#if         defined(__TINY__)
#error   OWL applications cannot be built in Tiny model.
#endif

#endif  //  !defined(BUILD_OWL)

#if defined(__cplusplus)
typedef int	   _FAR &		Rint;
typedef int	   _FAR *		Pint;
typedef void	   _FAR *		Pvoid;
typedef void	   _FAR * _FAR &	RPvoid;
typedef char	   _FAR *		Pchar;
typedef const char _FAR *		PCchar;
typedef const void _FAR *		PCvoid;

// windows 3.0-compatibility types

#if  defined(WIN30)

#define            _WIN30_API           1

typedef long                            LONG_30;
typedef unsigned int                    WORD_30;
typedef unsigned int                    WORD_30;
typedef unsigned int                    HDC_30;
typedef unsigned int                    HWND_30;
typedef unsigned int                    HINSTANCE_30;

#endif
#endif

/* Since some resource editors strip comments from header files, some
   brief comments on the contents of owlrc.h are included here:

   The SD_ constants are used for the File Open, File Save, Input,
   Search and Replace dialogs.

   ID_FNAME, ID_FPATH, ID_FLIST and ID_DLIST are used for TFileDialog.

   ID_PROMPT, ID_INPUT, ID_SEARCHTEXT, ID_CASESENSITIVE, ID_REPLACETEXT,
   ID_REPLACEALL and ID_PROMPTONREPLACE are used by TSearchDialog.

   ID_EDITOR is used by TEditWindow.

   ID_MDICLIENT is the default id for TMDIClient and ID_FIRSTMDICHILD
   is the id of the first MDI child created by a TMDIClient.

   Note that the ID_ constants defined in OWL are all greater than or
   equal to ID_RESERVED. Any ID_ constants you use should be less than
   ID_RESERVED.

   Note that the CM_ constants defined in OWL are all greater than or
   equal to CM_RESERVED. Any CM_ constants you use should be less than
   CM_RESERVED.

*/

/* Constants for application messages */
#define WM_FIRST        0x0000  /* 0x0000- 0x7FFF window messages */
#define WM_INTERNAL     0x7F00  /* 0x7F00- 0x7FFF reserved for internal use */
#define ID_FIRST        0x8000  /* 0x8000- 0x8FFF child id messages */
#define ID_INTERNAL     0x8F00  /* 0x8F00- 0x8FFF reserved for internal use */
#define NF_FIRST        0x9000  /* 0x9000- 0x9FFF notification messages */
#define NF_INTERNAL     0x9F00  /* 0x9F00- 0x9FFF reserved for internal use */
#define CM_FIRST        0xA000  /* 0xA000- 0xFFFF command messages */
#define CM_INTERNAL     0xFF00  /* 0xFF00- 0xFFFF reserved for internal use */
#define WM_COUNT 	0x8000	/* num of window msgs */
#define ID_COUNT 	0x1000	/* num of child id msgs */
#define NF_COUNT 	0x1000	/* num of notification msgs */
#define CM_COUNT 	0x6000	/* num of command msgs */

#define WM_RESERVED             WM_INTERNAL - WM_FIRST

#define ID_RESERVED             ID_INTERNAL - ID_FIRST
#define ID_FIRSTMDICHILD        ID_RESERVED + 1
#define ID_MDICLIENT 	        ID_RESERVED + 2

#define CM_RESERVED             CM_INTERNAL - CM_FIRST


  /* Bit masks for TWindowsObject Flags */
#define WB_ALIAS              0x01
#define WB_AUTOCREATE         0x02
#define WB_FROMRESOURCE       0x04
#define WB_KBHANDLER          0x08
#define WB_MDICHILD           0x10
#define WB_MDIFRAME           0x20
#define WB_PREDEFINEDCLASS    0x40
#define WB_TRANSFER           0x80

  /* Error conditions */
#define EM_INVALIDCHILD         -1
#define EM_INVALIDCLIENT        -2
#define EM_INVALIDMAINWINDOW    -3
#define EM_INVALIDMODULE        -4
#define EM_INVALIDWINDOW        -5
#define EM_OUTOFMEMORY          -6

  /* Transfer function flags */
#define TF_GETDATA               0
#define TF_SETDATA               1
#define TF_SIZEDATA              2

/* Checkbox flags indicating check state */
#define BF_CHECKED      0x1
#define BF_GRAYED       0x2
#define BF_UNCHECKED    0x0

// define classes types for isA()

#define  moduleClass          (__firstOWLClass)
#define  applicationClass     (moduleClass + 1)
#define  scrollerClass        (applicationClass + 1)
#define  windowClass          (scrollerClass + 1)
#define  dialogClass          (windowClass + 1)

#if  defined(__DLL__)
#  define _EXPORT _export
#else
#  define _EXPORT _CLASSTYPE
#endif

const int DEFAULT_SAFETY_POOL_SIZE = 8192;

_CLASSDEF(SafetyPool)

class _EXPORT SafetyPool
{
public:
    static  int		    Allocate(size_t size
				    = DEFAULT_SAFETY_POOL_SIZE);
    static  int		    IsExhausted()
			      // returns true if safetyPool is exhausted
			      { return safetyPool == NULL; };
    static  int		    Size;
    static  Pvoid 	    safetyPool;
};

enum Boolean { False, True };

typedef unsigned short ushort;
typedef unsigned char uchar;

const char EOS = '\0';

typedef int ccIndex;
typedef Boolean (_FAR *ccTestFunc)( Pvoid, Pvoid );
typedef void (_FAR *ccAppFunc)( Pvoid, Pvoid );

const ccNotFound = -1;
const maxCollectionSize = (int)((65536uL - 16)/sizeof( Pvoid ));

const TCOLLECTION_CLASS_HASH_VALUE = 0;

_CLASSDEF(TNSCollection)
_CLASSDEF(TNSSortedCollection)

class _CLASSTYPE TNSCollection
{
public:

    TNSCollection( ccIndex aLimit, ccIndex aDelta );
    ~TNSCollection();

    Pvoid at( ccIndex index );
    virtual ccIndex indexOf( Pvoid item );

    void atFree( ccIndex index );
    void atRemove( ccIndex index );
    void remove( Pvoid item );
    void removeAll();
    void free( Pvoid item );
    void freeAll();

    void atInsert( ccIndex index, Pvoid item );
    void atPut( ccIndex index, Pvoid item );
    virtual ccIndex insert( Pvoid item );

    static void error( ccIndex code, ccIndex info );

    Pvoid firstThat( ccTestFunc Test, Pvoid arg );
    Pvoid lastThat( ccTestFunc Test, Pvoid arg );
    void forEach( ccAppFunc action, Pvoid arg );

    void pack();
    virtual void setLimit( ccIndex aLimit );

    ccIndex getCount()
        { return count; }

protected:

    TNSCollection();

    Pvoid _FAR *items;
    ccIndex count;
    ccIndex limit;
    ccIndex delta;
    Boolean shouldDelete;

private:

    virtual void freeItem( Pvoid item );
};

class _CLASSTYPE TNSSortedCollection: public virtual TNSCollection
{
public:

    TNSSortedCollection( ccIndex aLimit, ccIndex aDelta) :
	    TNSCollection( aLimit, aDelta )
	    { delta = aDelta; setLimit( aLimit ); }

    virtual Boolean search( Pvoid key, ccIndex _FAR & index );

    virtual ccIndex indexOf( Pvoid item );
    virtual ccIndex insert( Pvoid item );

    Boolean duplicates;

protected:

    TNSSortedCollection() {};
    virtual Pvoid keyOf( Pvoid item ) { return item; }

private:

    virtual int compare( Pvoid key1, Pvoid key2 ) = 0;
};

#if !defined( __fLink_def )
#define __fLink_def
struct fLink
{
    fLink near *f;
    class _CLASSTYPE TStreamableClass near *t;
};
#endif

#define __link( s )             \
  extern TStreamableClass s;    \
  static fLink force ## s =     \
    { (fLink near *)&force ## s, (TStreamableClass near *)&s };

typedef unsigned P_id_type;

enum StreamableInit { streamableInit };

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class TStreamable                                                     */
/*                                                                         */
/*   This is the base class for all storable objects.  It provides         */
/*   three member functions, streamableName(), read(), and write(), which  */
/*   must be overridden in every derived class.                            */
/*                                                                         */
/* ------------------------------------------------------------------------*/

_CLASSDEF(TStreamable)
_CLASSDEF(TStreamableClass)
_CLASSDEF(TStreamableTypes)
_CLASSDEF(TPWrittenObjects)
_CLASSDEF(TPWObj)
_CLASSDEF(TPReadObjects)
_CLASSDEF(pstream)
_CLASSDEF(ipstream)
_CLASSDEF(opstream)
_CLASSDEF(iopstream)
_CLASSDEF(fpbase)
_CLASSDEF(ifpstream)
_CLASSDEF(ofpstream)
_CLASSDEF(fpstream)

class _CLASSTYPE TStreamable
{

    friend class _CLASSTYPE opstream;
    friend class _CLASSTYPE ipstream;

private:

    virtual const Pchar streamableName() const = 0;

protected:

    virtual Pvoid read(Ripstream) = 0;
    virtual void write(Ropstream) = 0;
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class TStreamableClass                                                */
/*                                                                         */
/*   Used internally by TStreamableTypes and pstream.                      */
/*                                                                         */
/* ------------------------------------------------------------------------*/

typedef PTStreamable (_FAR *BUILDER)();
#define __DELTA( d ) (FP_OFF((TStreamable *)(d *)1)-1)

class _CLASSTYPE TStreamableClass
{
    friend class _CLASSTYPE TStreamableTypes;
    friend class _CLASSTYPE opstream;
    friend class _CLASSTYPE ipstream;
    friend class _CLASSTYPE TObjStrmRegRecord;

public:

    TStreamableClass( PCchar n, BUILDER b, int d );

protected:
    PCchar name;
    BUILDER build;
    int delta;
};

class _CLASSTYPE TObjStrmRegRecord
{
    friend class TStreamableClass;
public:
    TObjStrmRegRecord(PTStreamableClass pTStreamableClass);
    int Validate();

    PTStreamableClass pTStreamableClass;
private:
    unsigned short SegmentLimit;
    unsigned short Checksum;
	Pvoid operator new (size_t s);
	void operator delete(Pvoid ptr);
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class TStreamableTypes                                                */
/*                                                                         */
/*   Maintains a database of all registered types in the application.      */
/*   Used by opstream and ipstream to find the functions to read and       */
/*   write objects.                                                        */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE TStreamableTypes : private TNSSortedCollection
{

public:

    TStreamableTypes() : TNSSortedCollection( 5, 5 )
        {duplicates = True;}
    ~TStreamableTypes() { shouldDelete = False; }

#if !defined(__DLL__)
    void registerType( PCTStreamableClass d)
        { insert( (void *)d ); }
#else
    void registerType(TObjStrmRegRecord *pTObjStrmRegRecord);
#endif

    PCTStreamableClass lookup( PCchar );

    Pvoid operator new( size_t sz ) { return ::operator new( sz ); }
    Pvoid operator new( size_t, Pvoid arena ) { return arena; }

protected:
    virtual Boolean search( Pvoid key, ccIndex _FAR & index );

private:
    virtual Pvoid keyOf(Pvoid d);
    int compare( Pvoid, Pvoid );
};


/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class TPWObj                                                          */
/*                                                                         */
/*   Used internally by TPWrittenObjects.                                  */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE TPWObj
{
	
    friend class _CLASSTYPE TPWrittenObjects;
    friend class _CLASSTYPE TPReadObjects;
    friend class _CLASSTYPE ipstream;
    friend class _CLASSTYPE opstream;

private:

    TPWObj(PCvoid adr, P_id_type id ) : address( Pvoid(adr) ), ident( id ) {}

    Pvoid address;
    P_id_type ident;

};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class TPWrittenObjects                                                */
/*                                                                         */
/*   Maintains a database of all objects that have been written to the     */
/*   current object stream.                                                */
/*                                                                         */
/*   Used by opstream when it writes a pointer onto a stream to determine  */
/*   whether the object pointed to has already been written to the stream. */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE TPWrittenObjects : public TNSSortedCollection
{

    friend class _CLASSTYPE opstream;

public:

    void removeAll() { curId = 1; TNSSortedCollection::removeAll(); }

private:

    TPWrittenObjects() : TNSSortedCollection( 5, 5 ), curId( 1 ) {}
    ~TPWrittenObjects() { shouldDelete = False; }

    void registerObject( PCvoid adr );
    P_id_type find( PCvoid adr );

    Pvoid keyOf(Pvoid d) { return ((TPWObj *)d)->address; }
    int compare( Pvoid, Pvoid );

    P_id_type curId;

};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class TPReadObjects                                                   */
/*                                                                         */
/*   Maintains a database of all objects that have been read from the      */
/*   current persistent stream.                                            */
/*                                                                         */
/*   Used by ipstream when it reads a pointer from a stream to determine   */
/*   the address of the object being referred to.                          */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE TPReadObjects : public TNSCollection
{

    friend class _CLASSTYPE ipstream;

public:

    void removeAll() { curId = 1; TNSCollection::removeAll(); }

private:

    TPReadObjects() : TNSCollection( 5, 5 ), curId( 1 )
        { insert( 0 ); }    // prime it, so we won't use index 0
    ~TPReadObjects() { shouldDelete = False; }

    void registerObject( PCvoid adr );
    PCvoid find( P_id_type id ) { return at( id ); }
    P_id_type curId;

};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class pstream                                                         */
/*                                                                         */
/*   Base class for handling streamable objects.                           */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE pstream
{

    friend class _CLASSTYPE TStreamableTypes;

public:

    enum StreamableError { peNotRegistered = 0x1000, peInvalidType = 0x2000 };
    enum PointerTypes { ptNull, ptIndexed, ptObject };

    _Cdecl pstream( Pstreambuf sb ) { init( sb ); }
    virtual _Cdecl ~pstream() {}

    int _Cdecl rdstate() const { return state; }
    int _Cdecl eof() const { return state & ios::eofbit; }
    int _Cdecl fail() const
        { return state & (ios::failbit | ios::badbit | ios::hardfail); }
    int _Cdecl bad() const { return state & (ios::badbit | ios::hardfail); }
    int _Cdecl good() const { return state == 0; }

    void _Cdecl clear( int i = 0 )
        { state = (i & 0xFF) | (state & ios::hardfail); }

    _Cdecl operator Pvoid() const { return fail() ? 0 : (void *)this; }
    int _Cdecl operator ! () const { return fail(); }

	Pstreambuf _Cdecl rdbuf() const { return bp; }

	static void initTypes();
	static PTStreamableTypes types;

protected:

	_Cdecl pstream() {}

	void _Cdecl error( StreamableError );
	void _Cdecl error( StreamableError, RCTStreamable );

	Pstreambuf bp;
	int state;
	
	void _Cdecl init( Pstreambuf sbp) { state = 0; bp = sbp; }
	void _Cdecl setstate( int b) { state |= (b&0x00FF); }
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class ipstream                                                        */
/*                                                                         */
/*   Base class for reading streamable objects                             */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE ipstream : virtual public pstream
{

public:

    _Cdecl  ipstream( Pstreambuf sb) { pstream::init( sb ); }
    _Cdecl ~ipstream() {}

    streampos _Cdecl tellg()
        { return bp->seekoff( 0, ios::cur, ios::in ); }

    Ripstream _Cdecl seekg( streampos );
    Ripstream _Cdecl seekg( streamoff, ios::seek_dir );

    uchar _Cdecl readByte() { return bp->sbumpc(); }
    void _Cdecl readBytes( Pvoid data, size_t sz)
        { bp->sgetn( (char *)data, sz ); }
    void _Cdecl freadBytes( void far *data, size_t sz );

    ushort _Cdecl readWord();
    Pchar _Cdecl readString();
    Pchar _Cdecl readString( Pchar, unsigned );
    char far *freadString();
    char far *freadString( char far *buf, unsigned maxLen );

    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        signed char _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        unsigned char _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        signed short _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        unsigned short _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        signed int _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        unsigned int _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        signed long _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        unsigned long _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        float _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        double _FAR & );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream,
        long double _FAR & );

    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream, RTStreamable );
    friend Ripstream _Cdecl _EXPFUNC operator >> ( Ripstream, RPvoid);

protected:

    _Cdecl ipstream() {}

    PCTStreamableClass _Cdecl readPrefix();
    Pvoid _Cdecl readData( PCTStreamableClass, PTStreamable );
    void _Cdecl readSuffix();

    PCvoid _Cdecl find( P_id_type id) { return objs.find( id ); }
    void _Cdecl registerObject( PCvoid adr ) { objs.registerObject( adr ); }

private:

    TPReadObjects objs;

};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class opstream                                                        */
/*                                                                         */
/*   Base class for writing streamable objects                             */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE opstream : virtual public pstream
{

public:

    _Cdecl opstream( Pstreambuf sb) { pstream::init( sb ); }
    _Cdecl ~opstream() {}

	streampos _Cdecl tellp() { return bp->seekoff( 0, ios::cur, ios::out ); }
	Ropstream _Cdecl seekp( streampos pos);
	Ropstream _Cdecl seekp( streamoff off, ios::seek_dir dir);
	Ropstream _Cdecl flush();

	void _Cdecl writeByte( uchar ch) { bp->sputc( ch ); }
	void _Cdecl writeBytes( PCvoid data, size_t sz)
		{ bp->sputn( (char *)data, sz ); }
	void _Cdecl fwriteBytes( const void far *data, size_t sz );

    void _Cdecl writeWord( ushort sh)
        { bp->sputn( (char *)&sh, sizeof( ushort ) ); }

    void _Cdecl writeString( PCchar );
    void _Cdecl fwriteString( const char far * str );

    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, signed char );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, unsigned char );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, signed short );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, unsigned short );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, signed int );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, unsigned int );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, signed long );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, unsigned long );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, float );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, double );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, long double );

    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, RTStreamable );
    friend Ropstream _Cdecl _EXPFUNC operator << ( Ropstream, PTStreamable );

protected:

    _Cdecl opstream() {}

    void _Cdecl writePrefix( RCTStreamable );
    void _Cdecl writeData( RTStreamable );
    void _Cdecl writeSuffix( RCTStreamable )
        { writeByte( ']' ); }

    P_id_type _Cdecl find( PCvoid adr ) { return objs.find( adr ); }
    void _Cdecl registerObject( PCvoid adr ) { objs.registerObject( adr ); }

private:
	TPWrittenObjects objs;

};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class iopstream                                                       */
/*                                                                         */
/*   Base class for reading and writing streamable objects                 */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE iopstream : public ipstream, public opstream
{

public:

	_Cdecl iopstream( Pstreambuf sb) { pstream::init( sb ); }
	_Cdecl ~iopstream() {}

protected:

	_Cdecl iopstream() {}
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class fpbase                                                          */
/*                                                                         */
/*   Base class for handling streamable objects on file streams            */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE fpbase : virtual public pstream
{
	
public:

	_Cdecl fpbase() { pstream::init( &buf ); }
	_Cdecl fpbase( PCchar, int, int = filebuf::openprot );
	_Cdecl fpbase( int f ) : buf (f) { pstream::init( &buf ); }
	_Cdecl fpbase( int f, Pchar b, int len) : buf( f, b, len )
		{ pstream::init( &buf ); }
	_Cdecl ~fpbase() {}

	void _Cdecl open( PCchar, int, int = filebuf::openprot );
	void _Cdecl attach( int );
	void _Cdecl close();
	void _Cdecl setbuf( Pchar, int );
	Pfilebuf _Cdecl rdbuf() { return &buf; }
	
private:

	filebuf buf;

};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class ifpstream                                                       */
/*                                                                         */
/*   Base class for reading streamable objects from file streams           */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE ifpstream : public fpbase, public ipstream
{

public:

	_Cdecl ifpstream() {}
	_Cdecl ifpstream( PCchar name,
                      int mode = ios::in,
                      int prot = filebuf::openprot
                    );
	_Cdecl ifpstream(int f) : fpbase( f ) {}
	_Cdecl ifpstream( int f, Pchar b, int len) : fpbase(f, b, len) {}
	_Cdecl ~ifpstream() {}

    Pfilebuf _Cdecl rdbuf() { return fpbase::rdbuf(); }
    void _Cdecl open( PCchar,
                      int = ios::in,
                      int = filebuf::openprot
					);
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class ofpstream                                                       */
/*                                                                         */
/*   Base class for writing streamable objects to file streams             */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE ofpstream : public fpbase, public opstream
{

public:

	_Cdecl ofpstream() {}
	_Cdecl ofpstream( PCchar,
					  int = ios::out,
                      int = filebuf::openprot
                    );
	_Cdecl ofpstream( int f) : fpbase( f ) {}
	_Cdecl ofpstream( int f, Pchar b, int len ) : fpbase(f, b, len) {}
	_Cdecl ~ofpstream() {}

    Pfilebuf _Cdecl rdbuf() { return fpbase::rdbuf(); }
    void _Cdecl open( PCchar,
                      int = ios::out,
                      int = filebuf::openprot
                    );

};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class fpstream                                                        */
/*                                                                         */
/*   Base class for reading and writing streamable objects to              */
/*   bidirectional file streams                                            */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _CLASSTYPE fpstream : public fpbase, public iopstream
{

public:

	_Cdecl fpstream() {}
	_Cdecl fpstream( PCchar, int, int = filebuf::openprot );
	_Cdecl fpstream( int f) : fpbase( f ) {}
	_Cdecl fpstream( int f, Pchar b, int len ) : fpbase(f, b, len) {}
	_Cdecl ~fpstream() {}

	Pfilebuf _Cdecl rdbuf() { return fpbase::rdbuf(); }
	void _Cdecl open( PCchar, int, int = filebuf::openprot );

};

_CLASSDEF(TWindow)
_CLASSDEF(TScroller)

#define MaxInt 32767
long LongMulDiv(long Mult1, long Mult2, long Div1);

  /* TScroller object */

class _EXPORT TScroller : public Object, public TStreamable
{
public:
    PTWindow Window;
    long XPos, YPos;      // current pos in horz/vert scroll units
    long XRange, YRange;  // # of scrollable horz/vert scroll units
    int XUnit, YUnit;     //logical device units per horz/vert scroll unit
    int XLine, YLine;        // # of horz/vert scroll units per line
    int XPage, YPage;        // # of horz/vert scroll units per page
    BOOL AutoMode;           // auto scrolling mode
    BOOL TrackMode;          // track scroll mode
    BOOL AutoOrg;            // indicates Scroller offsets origin
    BOOL HasHScrollBar;
    BOOL HasVScrollBar;

    TScroller(PTWindow TheWindow, int TheXUnit, int TheYUnit,
              long TheXRange, long TheYRange);
    ~TScroller();
    void SetUnits(int TheXUnit, int TheYUnit);
    virtual void SetPageSize();
    virtual void SetSBarRange();
    void SetRange(long TheXRange, long TheYRange);
#if defined(WIN31)
    // windows 3.1 interface
    virtual void BeginView(HDC PaintDC, PAINTSTRUCT _FAR & PaintInfo);
#endif
#if defined(WIN30)
    // windows 3.0 interface
    virtual void BeginView(HDC_30 PaintDC, PAINTSTRUCT _FAR & PaintInfo);
#endif
#if (defined(WIN30) || defined(WIN31)) && !(defined(WIN30) && defined(WIN31))
    // this function is never called. it is used to pad the vtable so that
    // exactly two BeginView(...) definitions are always present.
    virtual void BeginView(void *, void *) { };
#endif
    virtual void EndView();
    virtual void VScroll(WORD ScrollEvent, int ThumbPos);
    virtual void HScroll(WORD ScrollEvent, int ThumbPos);
    virtual void ScrollTo(long X, long Y);

    /* Scrolls to a position calculated using the passed
       "Delta" values. */
    void ScrollBy(long Dx, long Dy)
        { ScrollTo(XPos + Dx, YPos + Dy); }

    virtual void AutoScroll();

    /* Returns a BOOL value indicating whether or not the passed
       area (in units) is currently visible. */
    BOOL IsVisibleRect(long X, long Y, int XExt, int YExt)
        { return (X + XExt >= XPos) && (Y + YExt >= YPos) &&
             (X < XPos + XPage) && (Y < YPos + YPage); }

    /* Converts a horizontal range value from the scrollbar to a
       horizontal scroll value. */
    int XScrollValue(long ARangeUnit)
        { return (int)LongMulDiv(ARangeUnit, MaxInt, XRange); }

    /* Converts a vertical range value from the scrollbar to a
       vertical scroll value. */
    int YScrollValue(long ARangeUnit)
        { return (int)LongMulDiv(ARangeUnit, MaxInt, YRange); }

    /* Converts a horizontal scroll value from the scrollbar to
       a horizontal range value. */
    long XRangeValue(int AScrollUnit)
        { return LongMulDiv(AScrollUnit, XRange, MaxInt); }

    /* Converts a vertical scroll value from the scrollbar to
       a vertical range value. */
    long YRangeValue(int AScrollUnit)
        { return LongMulDiv(AScrollUnit, YRange, MaxInt); }

    // define pure virtual functions derived from Object class
    virtual classType  	isA() const
	    { return scrollerClass; }
    virtual Pchar nameOf() const
	    { return "TScroller"; }
    virtual hashValueType hashValue() const
	    { return InstanceHashValue; }
    virtual int   	isEqual(RCObject testobj)  const
        { return (this ==  &(RTScroller)testobj); }
    virtual void     	printOn(Rostream outputStream) const
        { outputStream << nameOf() << "{ Window = " << Window <<" }\n";}

    static PTStreamable build();

protected:
    TScroller(StreamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);
    hashValueType InstanceHashValue;
    static hashValueType ClassHashValue;

private:
    virtual const Pchar streamableName() const
	    { return "TScroller"; }
	
    void __BeginView(HDC PaintDC, PAINTSTRUCT _FAR & PaintInfo);	
};

inline Ripstream operator >> ( Ripstream is, RTScroller cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTScroller cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTScroller cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTScroller cl )
    { return os << (PTStreamable )cl; }

//  windows 3.1 name confict with TWindowsObject::GetFirstChild()
#if defined(GetFirstChild)
#undef GetFirstChild(hwnd)
#endif

struct TMessage {
  HWND Receiver;
  WORD Message;
  union {
    WORD WParam;
        struct tagWP {
          BYTE Lo;
          BYTE Hi;
        } WP;
  };
  union {
        DWORD LParam;
        struct tagLP {
          WORD Lo;
          WORD Hi;
        } LP;
  };
  long Result;
};

_CLASSDEF(TMDIClient)
_CLASSDEF(TApplication)
_CLASSDEF(TModule)
_CLASSDEF(TWindowsObject)


typedef TMessage _FAR &RTMessage;

typedef void ( _FAR *TActionFunc )(Pvoid Child, Pvoid ParamList);
typedef BOOL ( _FAR *TCondFunc )(Pvoid Child, Pvoid ParamList);

/* TWindowsObject */
class _EXPORT TWindowsObject : public Object, public TStreamable
{
public:
    int Status;
    HWND HWindow;	// handle to associated MS-Windows window
    LPSTR Title;
    PTWindowsObject Parent;

    TWindowsObject(PTWindowsObject AParent, PTModule AModule = NULL);
    virtual ~TWindowsObject();
    void SetFlags(WORD Mask, BOOL OnOff);

    /* Determines whether the flag whose mask is passed has been set,
       returning a BOOL indicator --  True = On, False = Off. */
    BOOL IsFlagSet(WORD Mask)
        { return( (Flags & Mask) == Mask); }

    PTWindowsObject FirstThat(TCondFunc Test, Pvoid PParamList);
    void ForEach(TActionFunc Action, Pvoid PParamList);
    PTWindowsObject FirstThat(
	    BOOL (TWindowsObject::* _FAR Test)(Pvoid, Pvoid), Pvoid PParamList);
    void ForEach(
	    void (TWindowsObject::* _FAR Action)(Pvoid, Pvoid), Pvoid PParamList);

    PTWindowsObject Next();
    PTWindowsObject GetFirstChild()
	    { return ChildList->SiblingList; }
    PTWindowsObject GetLastChild()
	    { return ChildList; }
    PTWindowsObject Previous();
    void EnableKBHandler();
    void EnableAutoCreate();
    void DisableAutoCreate();
    void EnableTransfer();
    void DisableTransfer();

    PTModule GetModule()
        { return Module; }
    PTApplication GetApplication()
        { return Application; }
    WNDPROC GetInstance()
        { return Instance; }
    virtual BOOL Register();

/* Pure virtual function, placeholder for derived classes to redefine to
   create an MS_Windows element to be associated with an OWL window
   object */
    virtual BOOL Create() = 0;

    virtual void Destroy();

    virtual int GetId();
    PTWindowsObject ChildWithId(int Id);
    virtual PTMDIClient GetClient();
    virtual void SetParent(PTWindowsObject NewParent);
    void Show(int ShowCmd);
    void SetCaption(LPSTR ATitle);
    virtual BOOL CanClose();
    void SetTransferBuffer(Pvoid ATransferBuffer)
        { TransferBuffer = ATransferBuffer; }
    virtual WORD Transfer(Pvoid DataPtr, WORD TransferFlag);
    virtual void TransferData(WORD Direction);
    virtual void DefWndProc(RTMessage Msg);
    virtual void BeforeDispatchHandler() {}
    virtual void AfterDispatchHandler() {}
    virtual void DispatchAMessage(WORD AMsg, RTMessage AMessage,
	    void (TWindowsObject::* _FAR)(RTMessage ));
    void CloseWindow();
    void GetChildren(Ripstream is);
    void PutChildren(Ropstream os);
    BOOL CreateChildren();
    virtual void ShutDownWindow();
    virtual void DrawItem(DRAWITEMSTRUCT far & DrawInfo);
    virtual void ActivationResponse(WORD Activated, BOOL IsIconified);

    // define pure virtual functions derived from Object class
    virtual classType      isA() const = 0;
    virtual Pchar nameOf() const = 0;
    virtual hashValueType  hashValue() const
        { return hashValueType(HWindow); }
    virtual int       	   isEqual(RCObject testwin)  const
        { return this ==  &(RTWindowsObject)testwin; }
    virtual void      	   printOn(Rostream outputStream) const
	{ outputStream << nameOf() << "{ HWindow = "
		 << (void _FAR *)HWindow << " }\n"; }

    static PTStreamable build();

protected:

    WNDPROC DefaultProc;
    Pvoid TransferBuffer;
    virtual void GetWindowClass(WNDCLASS _FAR & AWndClass);
    virtual LPSTR GetClassName() = 0;
    void RemoveClient()
		{ RemoveChild((PTWindowsObject)GetClient()); }
	void GetChildPtr(Ripstream is, RPTWindowsObject P);
	void PutChildPtr(Ropstream os, PTWindowsObject P);
	void GetSiblingPtr(Ripstream is, RPTWindowsObject P);
	void PutSiblingPtr(Ropstream os, PTWindowsObject P);
    virtual void DefCommandProc(RTMessage Msg);
    virtual void DefChildProc(RTMessage Msg);
    virtual void DefNotificationProc(RTMessage Msg);
    virtual void SetupWindow();
    virtual void WMVScroll(RTMessage Msg) =
                 [WM_FIRST + WM_VSCROLL];
    virtual void WMHScroll(RTMessage Msg) =
                 [WM_FIRST + WM_HSCROLL];
    void DispatchScroll(RTMessage Msg);
    virtual void WMCommand(RTMessage Msg) =
                 [WM_FIRST + WM_COMMAND];
    virtual void WMDrawItem(RTMessage Msg) =
                 [WM_FIRST + WM_DRAWITEM];
    virtual void WMClose(RTMessage Msg) =
                 [WM_FIRST + WM_CLOSE];
    virtual void WMDestroy(RTMessage Msg) =
                 [WM_FIRST + WM_DESTROY];
    virtual void WMNCDestroy(RTMessage Msg) =
                 [WM_FIRST + WM_NCDESTROY];
    virtual void WMActivate(RTMessage Msg) =
                 [WM_FIRST + WM_ACTIVATE];
    virtual void WMQueryEndSession(RTMessage Msg) =
                 [WM_FIRST + WM_QUERYENDSESSION];
    virtual void CMExit(RTMessage Msg) =
                 [CM_FIRST + CM_EXIT];

    TWindowsObject(StreamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:

    WNDPROC Instance;
    PTApplication Application;
    PTModule Module;
    WORD Flags;
    WORD CreateOrder;
    BOOL OrderIsI(Pvoid P, Pvoid I);
    BOOL CreateZeroChild(Pvoid P, Pvoid I);
    void AssignCreateOrder();
    PTWindowsObject ChildList, SiblingList;
    void AddChild(PTWindowsObject AChild);
    void RemoveChild(PTWindowsObject AChild);
    int IndexOf(PTWindowsObject P);
    PTWindowsObject At(int APosition);

    virtual const Pchar streamableName() const
        { return "TWindowsObject"; }

};	// end of WindowsObject class

/* Returns the Id of the TWindowsObject, used to identify the window
   in a specified parent's ChildList.  Redefined by TControl
   descendants to return their identifier from their attributes
   structure.  0 is returned here as the default identifier. This
   precludes any window with a 0 Id from being easily found. If you
   need to address individual windows, redefine GetId to return
   something other than 0.*/
inline int TWindowsObject::GetId()
        { return 0; }

/* Returns a pointer to the TWindowsObject's next sibling (the next
   window in its parent's child window list.  If this was the last child
   added to the list, returns a pointer to the first child added.*/
inline PTWindowsObject TWindowsObject::Next()
        { return SiblingList; }

typedef void ( TWindowsObject::* _FAR TActionMemFunc )(Pvoid Child, Pvoid ParamList);
typedef BOOL ( TWindowsObject::* _FAR TCondMemFunc )(Pvoid Child, Pvoid ParamList);

inline Ripstream operator >> ( Ripstream is, RTWindowsObject cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTWindowsObject cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTWindowsObject cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTWindowsObject cl )
    { return os << (PTStreamable )cl; }

const int BAD_DIALOG_STATUS = -2;

/* TDialog creation atributes */
struct _CLASSTYPE TDialogAttr { // _CLASSTYPE needed by BC++ 2.0
    LPSTR Name;
    DWORD Param;
};

  /* TDialog */

_CLASSDEF(TDialog)

class _EXPORT TDialog : public TWindowsObject
{
public:
    TDialogAttr Attr;
    BOOL IsModal;

    TDialog(PTWindowsObject AParent, LPSTR AName, PTModule AModule = NULL);
    TDialog(PTWindowsObject AParent, int ResourceId, PTModule AModule = NULL);
    virtual ~TDialog();

    virtual BOOL Create();
    virtual int Execute();

    virtual void CloseWindow(int ARetValue);
    virtual void CloseWindow();
    virtual void ShutDownWindow(int ARetValue);
    virtual void ShutDownWindow();
    virtual void Destroy(int ARetValue);
    virtual void Destroy();

    void SetCaption(LPSTR ATitle);

/* Returns the handle of the dialog's control with the passed Id.*/
    HWND GetItemHandle(int DlgItemID)
      { return GetDlgItem(HWindow, DlgItemID); }

/* Sends the passed message to the dialog's control which has
   the Id DlgItemID. */
    DWORD SendDlgItemMsg(int DlgItemID, WORD AMsg, WORD WParam, DWORD LParam)
      { return SendDlgItemMessage(HWindow, DlgItemID, AMsg, WParam, LParam); }


    virtual classType  	  isA() const
	{ return dialogClass; }
    virtual Pchar nameOf() const
        { return "TDialog"; }

    static PTStreamable build();

protected:
    virtual void GetWindowClass(WNDCLASS _FAR & AWndClass);
    virtual LPSTR GetClassName();
    virtual void SetupWindow();
    virtual void Ok(RTMessage Msg) = [ID_FIRST + IDOK];
    virtual void Cancel(RTMessage Msg) = [ID_FIRST + IDCANCEL];
    virtual void WMInitDialog(RTMessage Msg) = [WM_FIRST + WM_INITDIALOG];
    virtual void WMQueryEndSession(RTMessage Msg) =
                 [WM_FIRST + WM_QUERYENDSESSION];
    virtual void WMClose(RTMessage Msg) = [WM_FIRST + WM_CLOSE];

    TDialog(StreamableInit) : TWindowsObject(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TDialog"; }
};

inline Ripstream operator >> ( Ripstream is, RTDialog cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTDialog cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTDialog cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTDialog cl )
    { return os << (PTStreamable)cl; }

  /* TWindow creation attributes */
struct _CLASSTYPE TWindowAttr { // _CLASSTYPE needed by BC++ 2.0
    DWORD Style;
    DWORD ExStyle;
    int X, Y, W, H;
    LPSTR Menu;  // Menu name
    int Id ;     // Child identifier
    LPSTR Param;
 };


/* Window Class */

_CLASSDEF(TWindow)

class _EXPORT TWindow : public TWindowsObject
{
public:
    TWindowAttr  Attr;
    PTScroller Scroller;
    HWND FocusChildHandle;

    TWindow(PTWindowsObject AParent, LPSTR ATitle, PTModule AModule = NULL);
    TWindow(HWND AnHWindow, PTModule AModule = NULL);
    virtual ~TWindow();

    virtual BOOL AssignMenu(LPSTR MenuName);
    virtual BOOL AssignMenu(int MenuId);
    virtual BOOL Create();
    virtual void ActivationResponse(WORD Activated, BOOL IsIconified);

    virtual classType  	  isA() const
	{ return windowClass; }
    virtual Pchar nameOf() const
	{ return "TWindow"; }

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
        { return "OWLWindow31"; }
    virtual void GetWindowClass(WNDCLASS _FAR & AWndClass);
    virtual void SetupWindow();

    virtual void WMCreate(RTMessage Msg) = [WM_FIRST + WM_CREATE];
    virtual void WMMDIActivate(RTMessage Msg) =
                 [WM_FIRST + WM_MDIACTIVATE];
    virtual void WMHScroll(RTMessage Msg) = [WM_FIRST + WM_HSCROLL];
    virtual void WMVScroll(RTMessage Msg) = [WM_FIRST + WM_VSCROLL];
    virtual void WMPaint(RTMessage Msg) = [WM_FIRST + WM_PAINT];
#if defined(WIN31)
    // windows 3.1 interface
    virtual void Paint(HDC PaintDC, PAINTSTRUCT _FAR & PaintInfo);
#endif
#if defined(WIN30)
    // windows 3.0 interface
    virtual void Paint(HDC_30 PaintDC, PAINTSTRUCT _FAR & PaintInfo);
#endif
#if (defined(WIN30) || defined(WIN31)) && !(defined(WIN30) && defined(WIN31))
    // this function is never called. it is used to pad the vtable so that
    // exactly two Paint(...) definitions are always present.
    virtual void Paint(void *, void *) { };
#endif
    virtual void WMSize(RTMessage Msg) = [WM_FIRST + WM_SIZE];
    virtual void WMMove(RTMessage Msg) = [WM_FIRST + WM_MOVE];
    virtual void WMLButtonDown(RTMessage Msg) = [WM_FIRST + WM_LBUTTONDOWN];

    TWindow(StreamableInit) : TWindowsObject(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TWindow"; }

}; 	// end of Window class

inline Ripstream operator >> ( Ripstream is, RTWindow cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTWindow cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTWindow cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTWindow cl )
    { return os << (PTStreamable)cl; }

#define FILESPEC	MAXPATH + MAXEXT

_CLASSDEF(TFileDialog)

  /* TFileDialog */
class _EXPORT TFileDialog : public TDialog
{
public:
    LPSTR FilePath;
    char PathName[MAXPATH];
    char Extension[MAXEXT];
    char FileSpec[FILESPEC];

    TFileDialog(PTWindowsObject AParent, int ResourceId, LPSTR AFilePath,
                PTModule AModule = NULL);
    virtual BOOL CanClose();
    void SelectFileName();
    void UpdateFileName();
    BOOL UpdateListBoxes();

    static PTStreamable build();

protected:
    virtual void SetupWindow();
    virtual void HandleFName(RTMessage Msg)
          = [ID_FIRST + ID_FNAME];
    virtual void HandleFList(RTMessage Msg)
          = [ID_FIRST + ID_FLIST];
    virtual void HandleDList(RTMessage Msg)
          = [ID_FIRST + ID_DLIST];

    TFileDialog(StreamableInit) : TDialog(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TFileDialog"; }
};

inline Ripstream operator >> ( Ripstream is, RTFileDialog cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTFileDialog cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTFileDialog cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTFileDialog cl )
    { return os << (PTStreamable )cl; }

_CLASSDEF(TInputDialog)

  /* TInputDialog */
class _EXPORT TInputDialog : public TDialog
{
public:
    LPSTR Prompt;
    LPSTR Buffer;
    WORD BufferSize;

    TInputDialog(PTWindowsObject AParent, LPSTR ATitle,
              LPSTR APrompt, LPSTR ABuffer, WORD ABufferSize,
              PTModule AModule = NULL);
    void TransferData(WORD Direction);

    static PTStreamable build();

protected:
    virtual void SetupWindow();
    TInputDialog(StreamableInit) : TDialog(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TInputDialog"; }
};

inline Ripstream operator >> ( Ripstream is, RTInputDialog cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTInputDialog cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTInputDialog cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTInputDialog cl )
    { return os << (PTStreamable )cl; }

_CLASSDEF(TBWindow)

/* TBWindow */

class _EXPORT TBWindow : public TWindow
{
public:
    TBWindow(PTWindowsObject AParent, LPSTR AName,
	     PTModule AModule = NULL);

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
	    {return "TBWindow";}
    virtual void GetWindowClass(WNDCLASS _FAR & AWndClass);

    TBWindow(StreamableInit) : TWindow(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TBWindow"; }
};

inline Ripstream operator >> ( Ripstream is, RTBWindow cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTBWindow cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTBWindow cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTBWindow cl )
    { return os << (PTStreamable)cl; }

  /* TControl */

_CLASSDEF(TControl)

class _EXPORT TControl : public TWindow {
public:
    TControl(PTWindowsObject AParent, int AnId, LPSTR ATitle, int X,
             int Y, int W, int H, PTModule AModule = NULL);
    TControl(PTWindowsObject AParent, int ResourceId,
	     PTModule AModule = NULL);
    virtual int GetId()
        { return Attr.Id; }

protected:
    TControl(StreamableInit) : TWindow(streamableInit) {};

    virtual void WMPaint(RTMessage Msg) = [WM_FIRST + WM_PAINT];
    virtual void WMDrawItem(RTMessage Msg) = [WM_FIRST + WM_DRAWITEM];
    virtual void ODADrawEntire(DRAWITEMSTRUCT far & DrawInfo);
    virtual void ODAFocus(DRAWITEMSTRUCT far & DrawInfo);
    virtual void ODASelect(DRAWITEMSTRUCT far & DrawInfo);
};

_CLASSDEF(TMDIFrame)
_CLASSDEF(TMDIClient)

/* --------------------------------------------------------
  TMDIClient object
  -------------------------------------------------------- */

class _EXPORT TMDIClient : public TWindow
{
public:
    LPCLIENTCREATESTRUCT ClientAttr;

    TMDIClient(PTMDIFrame AParent, PTModule AModule = NULL);
    TMDIClient(PTMDIFrame AParent, HWND AnHWindow, PTModule AModule = NULL);
    virtual ~TMDIClient();

    /* Arranges iconized MDI child windows. */
    virtual void ArrangeIcons()
    { SendMessage(HWindow, WM_MDIICONARRANGE, 0, 0); }

    /* Cascades the MDI child windows. */
    virtual void CascadeChildren()
    { SendMessage(HWindow, WM_MDICASCADE, 0, 0); }

    /* Tiles the MDI child windows. */
    virtual void TileChildren()
    { SendMessage(HWindow, WM_MDITILE, 0, 0); }

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
        { return "MDICLIENT"; }

    /* Override TWindow::WMPaint and instead call DefWndProc */
    virtual void WMPaint(RTMessage Msg) = [WM_FIRST + WM_PAINT]
        { DefWndProc(Msg); }

    /* Override TWindow::WMMDIActivate, instead just call DefWndProc. */
    virtual void WMMDIActivate(RTMessage Msg) =
                 [WM_FIRST + WM_MDIACTIVATE]
        { DefWndProc(Msg); }

    TMDIClient(StreamableInit) : TWindow(streamableInit) {}
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TMDIClient"; }
};

inline Ripstream operator >> ( Ripstream is, RTMDIClient cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTMDIClient cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTMDIClient cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTMDIClient cl )
    { return os << (PTStreamable)cl; }

/* --------------------------------------------------------
  TMDIFrame object
  -------------------------------------------------------- */

class _EXPORT TMDIFrame : public TWindow
{
public:
    PTMDIClient ClientWnd;     // MDI client window
    int ChildMenuPos;          // menu position for child menu
    PTWindow ActiveChild;

    TMDIFrame(LPSTR ATitle, LPSTR MenuName, PTModule AModule = NULL);
    TMDIFrame(LPSTR ATitle, int MenuId, PTModule AModule = NULL);
    TMDIFrame(HWND AnHWindow, HWND ClientHWnd, PTModule AModule = NULL);
    virtual ~TMDIFrame();

    /* Constructs the TMDIFrame's MDI client window. */
    virtual void InitClientWindow()
        { ClientWnd = new TMDIClient(this); }

    /* Returns a pointer to the TMDIFrame's MDI client window. */
    virtual PTMDIClient GetClient()
        { return ClientWnd; }

    /* Constructs a new MDI child window object.  By default,
      constructs an instance of TWindow as an MDI child window object.
      Will almost always be redefined by descendants to construct an
      instance of a user-defined TWindow descendant as an MDI child
      window object. */
    virtual PTWindowsObject InitChild()
        { return new TWindow(this, ""); }

    virtual PTWindowsObject CreateChild();

    /* Tiles the MDI child windows by calling the TileChildren method
      of the MDI client window object. */
    virtual void TileChildren()
        { ClientWnd->TileChildren(); }

    /* Cascades the MDI child windows by calling the CascadeChildren
      method of the MDI client window object. */
    virtual void CascadeChildren()
        { ClientWnd->CascadeChildren(); }

    /* Arranges iconized MDI child windows by calling the
      ArrangeIcons method of the MDI client window object. */
    virtual void ArrangeIcons()
        { ClientWnd->ArrangeIcons(); }

    virtual BOOL CloseChildren();
    static PTStreamable build();

protected:
    virtual void GetWindowClass(WNDCLASS _FAR & AWndClass);
    virtual LPSTR GetClassName()
        { return "OWLMDIFrame31"; }
    virtual void SetupWindow();

    /* Since an MDI child doesn't get MDIACTIVATE messages when the
       frame gets (de)activated, call its ActivationResponse here. */
    virtual void WMActivate(RTMessage Msg)
        { TWindow::WMActivate(Msg);
          if ( ActiveChild )
            ActiveChild->ActivationResponse(
                   Msg.WParam, IsIconic(ActiveChild->HWindow)); }

    /* Responds to an incoming "CreateChild" command (with a
      CM_CREATECHILD command identifier) by calling CreateChild to
      construct and create a new MDI child. */
    virtual void CMCreateChild(RTMessage) =
                 [CM_FIRST + CM_CREATECHILD]
        { CreateChild(); }

    /* Responds to an incoming "Tile" command (with a CM_TILECHILDREN
      command identifier) by calling TileChildren to tile the MDI
      child windows. */
    virtual void CMTileChildren(RTMessage) =
                 [CM_FIRST + CM_TILECHILDREN]
        { TileChildren(); }

    /* Responds to an incoming "Cascade" command (with a
      CM_CASCADECHILDREN command identifier) by calling
      CascadeChildren to cascade the MDI  child windows. */
    virtual void CMCascadeChildren(RTMessage) =
                 [CM_FIRST + CM_CASCADECHILDREN]
        { CascadeChildren(); }

    /* Responds to an incoming "Arrange" command (with a
      CM_ARRANGEICONS command identifier) by calling ArrangeIcons
      to arrange the icons of the MDI child windows. */
    virtual void CMArrangeIcons(RTMessage) =
                 [CM_FIRST + CM_ARRANGEICONS]
        { ArrangeIcons(); }

    /* Responds to an incoming "CloseAll" command (with a
      CM_CLOSECHILDREN command identifier) by calling CloseChildren
      to close the MDI child windows. */
    virtual void CMCloseChildren(RTMessage) =
                 [CM_FIRST + CM_CLOSECHILDREN]
        { CloseChildren(); }

    TMDIFrame(StreamableInit) : TWindow(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TMDIFrame"; }
};

inline Ripstream operator >> ( Ripstream is, RTMDIFrame cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTMDIFrame cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTMDIFrame cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTMDIFrame cl )
    { return os << (PTStreamable)cl; }

_CLASSDEF(TModule)

// Module Class

class _EXPORT TModule : public Object {
public:

    // Lib and WinMain args
    HINSTANCE		hInstance;
    LPSTR		lpCmdLine;

    int Status;
    LPSTR Name;

#if defined(WIN31)
    TModule(LPSTR AName, HINSTANCE AnInstance, LPSTR ACmdLine);
#endif
#if defined(WIN30)
    TModule(LPSTR AName, HINSTANCE_30 AnInstance, LPSTR ACmdLine);
#endif
    virtual ~TModule();

    BOOL LowMemory();
    void RestoreMemory();
    virtual PTWindowsObject ValidWindow(PTWindowsObject AWindowsObject);
    virtual PTWindowsObject MakeWindow(PTWindowsObject AWindowsObject);
    virtual int ExecDialog(PTWindowsObject ADialog);
    HWND GetClientHandle(HWND AnHWindow);

#if defined(WIN31)
    // windows 3.1 interface
    virtual PTWindowsObject GetParentObject(HWND ParentHandle);
#endif
#if defined(WIN30)
    // windows 3.0 interface
    virtual PTWindowsObject GetParentObject(HWND_30 ParentHandle);
#endif
#if (defined(WIN30) || defined(WIN31)) && !(defined(WIN30) && defined(WIN31))
    // this function is never called. it is used to pad the vtable so that
    // exactly two GetParentObject(...) definitions are always present.
    virtual PTWindowsObject GetParentObject(void *)
            { return NULL; }
#endif
    virtual void Error(int ErrorCode);

    // define pure virtual functions derived from Object class
    virtual classType  	  isA() const
	    { return moduleClass; }
    virtual Pchar nameOf() const
	    { return "TModule"; }
    virtual hashValueType hashValue() const
	    {  return hashValueType(hInstance); }
    virtual int 	  isEqual(RCObject module)  const
            { return (hInstance == ((RTModule)module).hInstance); }
    virtual void	  printOn(Rostream outputStream) const
            { outputStream << nameOf() << "{ hInstance = "
              << (void _FAR *)hInstance << " }\n"; }
private:

    PTWindowsObject __GetParentObject(HWND ParentHandle);
    void __TModule(LPSTR AName, HINSTANCE AnInstance, LPSTR ACmdLine);

};	// end of Module class

extern PTModule Module;

_CLASSDEF(TBDivider)

/* --------------------------------------------------------
  TBDivider object
  -------------------------------------------------------- */
class _EXPORT TBDivider : public TControl
{
public:
	TBDivider(PTWindowsObject AParent, int AnId, LPSTR AText,
            int X, int Y, int W, int H, BOOL IsVertical,
	    BOOL IsBump, PTModule AModule = NULL);
	TBDivider(PTWindowsObject AParent, int ResourceId,
	    PTModule AModule = NULL);
    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
	    {return "BORSHADE";}
    TBDivider(StreamableInit) : TControl(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TBDivider"; }
};

inline Ripstream operator >> ( Ripstream is, RTBDivider cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTBDivider cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTBDivider cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTBDivider cl )
    { return os << (PTStreamable)cl; }

_CLASSDEF(TBStaticBmp)

/* --------------------------------------------------------
  TBStaticBmp object
  -------------------------------------------------------- */
class _EXPORT TBStaticBmp : public TControl
{
public:
    TBStaticBmp(PTWindowsObject AParent, int AnId, LPSTR AText,
            int X, int Y, int W, int H, PTModule AModule = NULL);
    TBStaticBmp(PTWindowsObject AParent, int ResourceId,
		 PTModule AModule = NULL);

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
	    {return "BORBTN";}
    TBStaticBmp(StreamableInit) : TControl(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TBStaticBmp"; }
};

inline Ripstream operator >> ( Ripstream is, RTBStaticBmp cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTBStaticBmp cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTBStaticBmp cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTBStaticBmp cl )
    { return os << (PTStreamable)cl; }

/* --------------------------------------------------------
  TButton object
  -------------------------------------------------------- */

_CLASSDEF(TButton)

class _EXPORT TButton : public TControl
{
public:
    BOOL IsDefPB;

	TButton(PTWindowsObject AParent, int AnId, LPSTR AText,
            int X, int Y, int W, int H, BOOL IsDefault,
	    PTModule AModule = NULL);
	TButton(PTWindowsObject AParent, int ResourceId,
	    PTModule AModule = NULL);

    static PTStreamable build();
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

protected:
    BOOL IsCurrentDefPB;

    virtual LPSTR GetClassName()
        { return "BUTTON"; }
    virtual void SetupWindow();

    virtual void WMGetDlgCode(RTMessage Msg) =
                         [WM_FIRST + WM_GETDLGCODE];
    virtual void BMSetStyle(RTMessage Msg) = [WM_FIRST + BM_SETSTYLE];

    TButton(StreamableInit) : TControl(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TButton"; }
};

inline Ripstream operator >> ( Ripstream is, RTButton cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTButton cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTButton cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTButton cl )
    { return os << (PTStreamable)cl; }

/* --------------------------------------------------------
  TBButton object
  -------------------------------------------------------- */

_CLASSDEF(TBButton)

class _EXPORT TBButton : public TButton
{
public:
    TBButton(PTWindowsObject AParent, int AnId, LPSTR AText,
            int X, int Y, int W, int H, BOOL IsDefault,
	    PTModule AModule = NULL);
    TBButton(PTWindowsObject AParent, int ResourceId,
	    PTModule AModule = NULL);
    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
	    {return "BORBTN";}
    TBButton(StreamableInit) : TButton(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TBButton"; }
};

inline Ripstream operator >> ( Ripstream is, RTBButton cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTBButton cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTBButton cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTBButton cl )
    { return os << (PTStreamable)cl; }

_CLASSDEF(TGroupBox)

/* --------------------------------------------------------
  TGroupBox object
  -------------------------------------------------------- */
class _EXPORT TGroupBox : public TControl
{
public:
    BOOL NotifyParent;

    TGroupBox(PTWindowsObject AParent, int AnId, LPSTR AText, int X,
              int Y, int W, int H, PTModule AModule = NULL);
    TGroupBox(PTWindowsObject AParent, int ResourceId,
              PTModule AModule = NULL);
    virtual void SelectionChanged(int ControlId);

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
        { return "BUTTON"; }

    TGroupBox(StreamableInit) : TControl(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TGroupBox"; }
};

inline Ripstream operator >> ( Ripstream is, RTGroupBox cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTGroupBox cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTGroupBox cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTGroupBox cl )
    { return os << (PTStreamable )cl; }

_CLASSDEF(TBGroupBox)

/* --------------------------------------------------------
  TBGroupBox object
  -------------------------------------------------------- */
class _EXPORT TBGroupBox : public TGroupBox
{
public:
    TBGroupBox(PTWindowsObject AParent, int AnId, LPSTR AText, int X,
              int Y, int W, int H, PTModule AModule = NULL);
    TBGroupBox(PTWindowsObject AParent, int ResourceId,
	        PTModule AModule = NULL);

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
	    {return "BORSHADE";}
    TBGroupBox(StreamableInit) : TGroupBox(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TBGroupBox"; }
};

inline Ripstream operator >> ( Ripstream is, RTBGroupBox cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTBGroupBox cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTBGroupBox cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTBGroupBox cl )
    { return os << (PTStreamable )cl; }

_CLASSDEF(TListBox)
_CLASSDEF(TListBoxData)

/* --------------------------------------------------------
  TListBox object
  -------------------------------------------------------- */

class _EXPORT TListBox : public TControl
{
public:
    TListBox(PTWindowsObject AParent, int AnId, int X, int Y,
             int W, int H, PTModule AModule = NULL);
    TListBox(PTWindowsObject AParent, int ResourceId, PTModule AModule = NULL)
             : TControl(AParent, ResourceId, AModule){};

    int AddString(LPSTR AString);
    int InsertString(LPSTR AString, int Index);
    int DeleteString(int Index);
    void ClearList();
    virtual WORD Transfer(Pvoid DataPtr, WORD TransferFlag);
    int GetCount();
    int FindString(LPSTR AString, int SearchIndex);
    int FindExactString(LPSTR AString, int SearchIndex);
    int GetString(LPSTR AString, int Index);
    int GetStringLen(int Index);

    // next four functions only for single-selection
    // list boxes (and combo boxes).
    int GetSelString(LPSTR AString, int MaxChars);
    int SetSelString(LPSTR AString, int SearchIndex);
    int GetSelIndex();
    int SetSelIndex(int Index);

    int GetSelCount();

    // next four functions only for multiple-selection list boxes.
    int GetSelStrings(LPSTR *Strings, int MaxCount, int MaxChars);
    int SetSelStrings(LPSTR *Prefixes, int NumSelections,
                      BOOL ShouldSet);
    int GetSelIndexes(Pint Indexes, int MaxCount);
    int SetSelIndexes(Pint Indexes, int NumSelections,
                      BOOL ShouldSet);

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
        { return "LISTBOX"; }
    virtual WORD GetMsgID(WORD AMsg);

    TListBox(StreamableInit) : TControl(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TListBox"; }
};

inline Ripstream operator >> ( Ripstream is, RTListBox cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTListBox cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTListBox cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTListBox cl )
    { return os << (PTStreamable )cl; }

enum msgname {MN_ADDSTRING,    MN_INSERTSTRING, MN_DELETESTRING,
              MN_RESETCONTENT, MN_GETCOUNT,     MN_GETTEXT,
              MN_GETTEXTLEN,   MN_SELECTSTRING, MN_SETCURSEL,
              MN_GETCURSEL,    MN_FINDSTRING };

class _EXPORT TListBoxData
{
public:
    PArray Strings;
    PArray SelStrings;
    int SelCount;

    TListBoxData();
    ~TListBoxData();
    void AddString(Pchar AString, BOOL IsSelected = FALSE);
    void SelectString(LPSTR AString);
    void ResetSelections();
    int GetSelStringLength(int Index = 0);
    void GetSelString(LPSTR Buffer, int BufferSize, int Index = 0);
};

// TScrollBar transfer structure
struct TScrollBarData {
  int LowValue;
  int HighValue;
  int Position;
};

_CLASSDEF(TScrollBar)

/* --------------------------------------------------------
  TScrollBar object
  -------------------------------------------------------- */

class _EXPORT TScrollBar : public TControl
{
public:
    int LineMagnitude, PageMagnitude;

    TScrollBar(PTWindowsObject AParent, int AnId, int X, int Y, int W,
               int H, BOOL IsHScrollBar, PTModule AModule = NULL);
    TScrollBar(PTWindowsObject AParent, int ResourceId,
               PTModule AModule = NULL);

    void GetRange(Rint LoVal, Rint HiVal);
    int GetPosition();
    void SetRange(int LoVal, int HiVal);
    void SetPosition(int ThumbPos);
    int DeltaPos(int Delta);
    virtual WORD Transfer(Pvoid DataPtr, WORD TransferFlag);

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
        { return "SCROLLBAR"; }
    virtual void SetupWindow();

    virtual void SBLineUp(RTMessage Msg) = [NF_FIRST + SB_LINEUP];
    virtual void SBLineDown(RTMessage Msg) = [NF_FIRST + SB_LINEDOWN];
    virtual void SBPageUp(RTMessage Msg) = [NF_FIRST + SB_PAGEUP];
    virtual void SBPageDown(RTMessage Msg) = [NF_FIRST + SB_PAGEDOWN];
    virtual void SBThumbPosition(RTMessage Msg) =
                                      [NF_FIRST + SB_THUMBPOSITION];
    virtual void SBThumbTrack(RTMessage Msg) = [NF_FIRST + SB_THUMBTRACK];
    virtual void SBTop(RTMessage Msg) = [NF_FIRST + SB_TOP];
    virtual void SBBottom(RTMessage Msg) = [NF_FIRST + SB_BOTTOM];

    TScrollBar(StreamableInit) : TControl(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TScrollBar"; }
};

inline Ripstream operator >> ( Ripstream is, RTScrollBar cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTScrollBar cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTScrollBar cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTScrollBar cl )
    { return os << (PTStreamable )cl; }

  /* TStatic */

_CLASSDEF(TStatic)

class _EXPORT TStatic : public TControl
{
public:
    WORD TextLen;

    TStatic(PTWindowsObject AParent, int AnId, LPSTR ATitle, int X,
            int Y, int W, int H, WORD ATextLen, PTModule AModule = NULL);
    TStatic(PTWindowsObject AParent, int ResourceId, WORD ATextLen,
            PTModule AModule = NULL);

    /* Returns the length of the control's text. */
    int GetTextLen()
        { return GetWindowTextLength(HWindow); }

    /* Fills the passed string with the text of the associated text
       control.  Returns the number of characters copied. */
    int GetText(LPSTR ATextString, int MaxChars)
        { return GetWindowText(HWindow, ATextString, MaxChars); }

    /* Sets the contents of the associated static text control to
       the passed string. */
    void SetText(LPSTR ATextString)
        { SetWindowText(HWindow, ATextString); }

    /* Clears the text of the associated static text control. */
    void Clear()
        { SetText(""); }

    virtual WORD Transfer(Pvoid DataPtr, WORD TransferFlag);

    virtual Pchar nameOf() const
	    { return "TStatic"; }

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
        { return "STATIC"; }

    TStatic(StreamableInit) : TControl(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);
private:
    virtual const Pchar streamableName() const
        { return "TStatic"; }
};

inline Ripstream operator >> ( Ripstream is, RTStatic cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTStatic cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTStatic cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTStatic cl )
    { return os << (PTStreamable)cl; }

_CLASSDEF(TComboBox)
_CLASSDEF(TComboBoxData)

/* --------------------------------------------------------
  TComboBox object
  -------------------------------------------------------- */

class _EXPORT TComboBox : public TListBox
{
public:
    WORD TextLen;

    TComboBox(PTWindowsObject AParent, int AnId, int X, int Y, int W,
              int H, DWORD AStyle, WORD ATextLen, PTModule AModule = NULL);
    TComboBox(PTWindowsObject AParent, int ResourceId, WORD ATextLen,
              PTModule AModule = NULL);

    /* Returns the length of the associated edit control's text. */
    int GetTextLen()
        { return GetWindowTextLength(HWindow); }

    /* Fills the supplied string with the text of the associated
       edit control. Returns the number of characters copied. */
    int GetText(LPSTR AString, int MaxChars)
        { return GetWindowText(HWindow, AString, MaxChars); }

    void SetText(LPSTR AString);

    /* Selects characters in the edit control of the combo box
       which are between StartPos and EndPos. Returns CB_ERR if
       the combo box does not have an edit control. */
    int SetEditSel(int StartPos, int EndPos)
        { return (int)SendMessage(HWindow, CB_SETEDITSEL,
                      0, MAKELONG(StartPos, EndPos)); }

    int GetEditSel(Rint StartPos, Rint EndPos);

    /* Clears the text of the associated edit control. */
    void Clear()
        { SetText(""); }

    void ShowList();
    void HideList();
    virtual WORD Transfer(Pvoid DataPtr, WORD TransferFlag);
    virtual Pchar nameOf() const
	    { return "TComboBox"; }

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
	    {return "COMBOBOX";}
    virtual WORD GetMsgID(WORD AnId);
    virtual void SetupWindow();

    TComboBox(StreamableInit) : TListBox(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TComboBox"; }
};

inline Ripstream operator >> ( Ripstream is, RTComboBox cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTComboBox cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTComboBox cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTComboBox cl )
    { return os << (PTStreamable )cl; }

class _EXPORT TComboBoxData
{
public:
    PArray Strings;
    Pchar Selection;

    TComboBoxData();
    ~TComboBoxData();
    void AddString(Pchar AString, BOOL IsSelected = FALSE);
};

/* --------------------------------------------------------
  TCheckBox object
  -------------------------------------------------------- */

_CLASSDEF(TCheckBox)

class _EXPORT TCheckBox : public TButton
{
public:
    PTGroupBox Group;

    TCheckBox(PTWindowsObject AParent,int AnId, LPSTR ATitle, int X,
              int Y ,int W, int H, PTGroupBox AGroup,
	      PTModule AModule = NULL);
    TCheckBox(PTWindowsObject AParent, int ResourceId,
              PTGroupBox AGroup, PTModule AModule = NULL);
    void Check();
    void Uncheck();
    void Toggle();
    WORD GetCheck();
    void SetCheck(WORD CheckFlag);
    virtual WORD Transfer(Pvoid DataPtr, WORD TransferFlag);

    static PTStreamable build();

protected:
    virtual void BNClicked(RTMessage Msg) = [NF_FIRST + BN_CLICKED];

    /* Override TButton's processing so drawable check boxes and radio
       buttons work properly. */
    virtual void WMGetDlgCode(RTMessage Msg) =
                         [WM_FIRST + WM_GETDLGCODE]
        { DefWndProc(Msg); }

    TCheckBox(StreamableInit) : TButton(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TCheckBox"; }
};

inline Ripstream operator >> ( Ripstream is, RTCheckBox cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTCheckBox cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTCheckBox cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTCheckBox cl )
    { return os << (PTStreamable )cl; }

_CLASSDEF(TBCheckBox)

/* --------------------------------------------------------
  TBCheckBox object
  -------------------------------------------------------- */

class _EXPORT TBCheckBox : public TCheckBox
{
public:
    TBCheckBox(PTWindowsObject AParent,int AnId, LPSTR ATitle, int X,
	    int Y ,int W, int H, PTGroupBox AGroup,
	    PTModule AModule = NULL);
    TBCheckBox(PTWindowsObject AParent, int ResourceId,
	        PTGroupBox AGroup, PTModule AModule = NULL);
    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
	    {return "BORCHECK";}
    TBCheckBox(StreamableInit) : TCheckBox(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TBCheckBox"; }
};

inline Ripstream operator >> ( Ripstream is, RTBCheckBox cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTBCheckBox cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTBCheckBox cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTBCheckBox cl )
    { return os << (PTStreamable)cl; }

_CLASSDEF(TRadioButton)

/* --------------------------------------------------------
  TRadioButton object
  -------------------------------------------------------- */
class _EXPORT TRadioButton : public TCheckBox
{
public:
    TRadioButton(PTWindowsObject AParent, int AnId, LPSTR ATitle,
               int X, int Y, int W, int H, PTGroupBox AGroup,
               PTModule AModule = NULL);

    TRadioButton(PTWindowsObject AParent, int ResourceId, PTGroupBox AGroup,
               PTModule AModule = NULL)
              : TCheckBox(AParent, ResourceId, AGroup, AModule){};

    static PTStreamable build();

protected:
    virtual void BNClicked(RTMessage Msg) = [NF_FIRST + BN_CLICKED];

    TRadioButton(StreamableInit) : TCheckBox(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TRadioButton"; }
};

inline Ripstream operator >> ( Ripstream is, RTRadioButton cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTRadioButton cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTRadioButton cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTRadioButton cl )
    { return os << (PTStreamable)cl; }

_CLASSDEF(TBRadioButton)

/* --------------------------------------------------------
  TBRadioButton object
  -------------------------------------------------------- */

class _EXPORT TBRadioButton : public TRadioButton
{
public:
  TBRadioButton(PTWindowsObject AParent, int AnId, LPSTR ATitle,
                 int X, int Y, int W, int H, PTGroupBox AGroup,
		 PTModule AModule = NULL);
  TBRadioButton(PTWindowsObject AParent, int ResourceId, PTGroupBox AGroup,
		 PTModule AModule = NULL)
              : TRadioButton(AParent, ResourceId, AGroup, AModule){};
  static PTStreamable build();

protected:
  virtual LPSTR GetClassName()
	  {return "BORRADIO";}
  TBRadioButton(StreamableInit) : TRadioButton(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TBRadioButton"; }
};

inline Ripstream operator >> ( Ripstream is, RTBRadioButton cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTBRadioButton cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTBRadioButton cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTBRadioButton cl )
    { return os << (PTStreamable)cl; }

_CLASSDEF(TBStatic)

/* TBStatic */

class _EXPORT TBStatic : public TStatic
{
public:
    TBStatic(PTWindowsObject AParent, int AnId, LPSTR ATitle, int X,
            int Y, int W, int H, WORD ATextLen, PTModule AModule = NULL);
    TBStatic(PTWindowsObject AParent, int ResourceId, WORD ATextLen,
	      PTModule AModule = NULL);
    virtual Pchar nameOf() const
	    { return "TBStatic"; }

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
	    {return "BORSTATIC";}
    TBStatic(StreamableInit) : TStatic(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TBStatic"; }
};

inline Ripstream operator >> ( Ripstream is, RTBStatic cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTBStatic cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTBStatic cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTBStatic cl )
    { return os << (PTStreamable)cl; }

_CLASSDEF(TEdit)

  /* TEdit */
class _EXPORT TEdit : public TStatic
{
public:
    TEdit(PTWindowsObject AParent, int AnId, LPSTR AText, int X,
          int Y, int W, int H, WORD ATextLen, BOOL Multiline,
          PTModule AModule = NULL);
    TEdit(PTWindowsObject AParent, int ResourceId, WORD ATextLen,
          PTModule AModule = NULL);

    void Undo();
    BOOL CanUndo();
    void Paste();
    void Copy();
    void Cut();
    int GetNumLines();
    int GetLineLength(int LineNumber);
    BOOL GetLine(LPSTR ATextString, int StrSize, int LineNumber);
    void GetSubText(LPSTR ATextString, int StartPos, int EndPos);
    BOOL DeleteSubText(int StartPos, int EndPos);
    BOOL DeleteLine(int LineNumber);
    void GetSelection(Rint StartPos, Rint EndPos);
    BOOL DeleteSelection();
    BOOL IsModified();
    void ClearModify();
    int GetLineFromPos(int CharPos);
    int GetLineIndex(int LineNumber);
    void Scroll(int HorizontalUnit, int VerticalUnit);
    BOOL SetSelection(int StartPos, int EndPos);
    void Insert(LPSTR ATextString);
    int Search(int StartPos, LPSTR AText, BOOL CaseSensitive);

    static PTStreamable build();

protected:
    virtual LPSTR GetClassName()
	{ return "EDIT"; }
    virtual void SetupWindow();
    virtual void CMEditCut(RTMessage Msg) = [CM_FIRST + CM_EDITCUT];
    virtual void CMEditCopy(RTMessage Msg) = [CM_FIRST + CM_EDITCOPY];
    virtual void CMEditPaste(RTMessage Msg) = [CM_FIRST + CM_EDITPASTE];
    virtual void CMEditDelete(RTMessage Msg) =
                                        [CM_FIRST + CM_EDITDELETE];
    virtual void CMEditClear(RTMessage Msg) = [CM_FIRST + CM_EDITCLEAR];
    virtual void CMEditUndo(RTMessage Msg) = [CM_FIRST + CM_EDITUNDO];
    virtual void ENErrSpace(RTMessage Msg) = [NF_FIRST + EN_ERRSPACE];

    TEdit(StreamableInit) : TStatic(streamableInit) {};

private:
    virtual const Pchar streamableName() const
        { return "TEdit"; }
};

inline Ripstream operator >> ( Ripstream is, RTEdit cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTEdit cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTEdit cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTEdit cl )
    { return os << (PTStreamable )cl; }

struct _CLASSTYPE TSearchStruct { // _CLASSTYPE needed for BC++ 2.0
  char SearchText[81];
  BOOL CaseSensitive;
  char ReplaceText[81];
  BOOL ReplaceAll;
  BOOL PromptOnReplace;
};

_CLASSDEF(TEditWindow)
_CLASSDEF(TSearchDialog)

/* TEditWindow declaration */

class _EXPORT TEditWindow : public TWindow
{
public:
    PTEdit Editor;
    TSearchStruct SearchStruct;
    BOOL IsReplaceOp; // True if the search is a search and replace.

    TEditWindow(PTWindowsObject AParent, LPSTR ATitle,
	    PTModule AModule = NULL);
    void DoSearch();

    static PTStreamable build();

protected:
    virtual void WMSize(RTMessage Msg) = [WM_FIRST + WM_SIZE];
    virtual void WMSetFocus(RTMessage Msg) = [WM_FIRST + WM_SETFOCUS];
    virtual void CMEditFind(RTMessage Msg) = [CM_FIRST + CM_EDITFIND];
    virtual void CMEditFindNext(RTMessage Msg) =
                               [CM_FIRST + CM_EDITFINDNEXT];
    virtual void CMEditReplace(RTMessage Msg) =
                               [CM_FIRST + CM_EDITREPLACE];

    TEditWindow(StreamableInit) : TWindow(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TEditWindow"; }
};

inline Ripstream operator >> ( Ripstream is, RTEditWindow cl )
    { return is >> (RTStreamable )cl; }
inline Ripstream operator >> ( Ripstream is, RPTEditWindow cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTEditWindow cl )
    { return os << (RTStreamable )cl; }
inline Ropstream operator << ( Ropstream os, PTEditWindow cl )
    { return os << (PTStreamable )cl; }

class _EXPORT TSearchDialog : public TDialog
{
public:
  TSearchDialog(PTWindowsObject AParent, int ResourceId,
                TSearchStruct _FAR &SearchStruct,
                PTModule AModule = NULL);
};

 /* TFileWindow */

_CLASSDEF(TFileWindow)

class _EXPORT TFileWindow : public TEditWindow
{
public:
    LPSTR FileName;
    BOOL IsNewFile;

    TFileWindow(PTWindowsObject AParent, LPSTR ATitle, LPSTR AFileName,
                PTModule AModule = NULL);
    virtual ~TFileWindow();

    virtual BOOL CanClear();
    virtual BOOL CanClose();
    void NewFile();
    void Open();
    BOOL Read();
    void ReplaceWith(LPSTR AFileName);
    BOOL Save();
    BOOL SaveAs();
    void SetFileName(LPSTR AFileName);
    BOOL Write();

    static PTStreamable build();

protected:
    virtual void SetupWindow();
    virtual void CMFileNew(RTMessage Msg) = [CM_FIRST + CM_FILENEW];
    virtual void CMFileOpen(RTMessage Msg) = [CM_FIRST + CM_FILEOPEN];
    virtual void CMFileSave(RTMessage Msg) = [CM_FIRST + CM_FILESAVE];
    virtual void CMFileSaveAs(RTMessage Msg) =
                                         [CM_FIRST + CM_FILESAVEAS];

    TFileWindow(StreamableInit) : TEditWindow(streamableInit) {};
    virtual void write (Ropstream os);
    virtual Pvoid read (Ripstream is);

private:
    virtual const Pchar streamableName() const
        { return "TFileWindow"; }
};

inline Ripstream operator >> ( Ripstream is, RTFileWindow cl )
    { return is >> (RTStreamable)cl; }
inline Ripstream operator >> ( Ripstream is, RPTFileWindow cl )
    { return is >> (RPvoid)cl; }

inline Ropstream operator << ( Ropstream os, RTFileWindow cl )
    { return os << (RTStreamable)cl; }
inline Ropstream operator << ( Ropstream os, PTFileWindow cl )
    { return os << (PTStreamable)cl; }

// Application Class

_CLASSDEF(TApplication)

class _EXPORT TApplication : public TModule {
public:

    // WinMain arguments
    HINSTANCE 		hPrevInstance;
    int    		nCmdShow;

    PTWindowsObject MainWindow;
    HACCEL HAccTable;
    PTWindowsObject KBHandlerWnd;

#if defined(WIN31)
    // windows 3.1 interface
    TApplication(LPSTR AName, HINSTANCE AnInstance,
              HINSTANCE APrevInstance, LPSTR ACmdLine, int ACmdShow);
#endif
#if defined(WIN30)
    // windows 3.0 interface
    TApplication(LPSTR AName, HINSTANCE_30 AnInstance,
              HINSTANCE_30 APrevInstance, LPSTR ACmdLine, int ACmdShow);
#endif

    ~TApplication();
    virtual void Run();
    virtual BOOL CanClose();
    void SetKBHandler(PTWindowsObject AWindowsObject);

    // define pure virtual functions derived from Object class
    virtual classType  	  isA() const
         { return applicationClass; }
    virtual Pchar nameOf() const
         {return "TApplication";}
protected:
    virtual void InitApplication();  // "first"-instance initialization
    virtual void InitInstance();     // each-instance initialization
    virtual void InitMainWindow();   // init application main window

    virtual void MessageLoop();
    /* IdleAction may be redefined in derived classes to do some action when
       there are no messages pending. */
    virtual void IdleAction() {}
    virtual BOOL ProcessAppMsg(LPMSG PMessage);
    virtual BOOL ProcessDlgMsg(LPMSG PMessage);
    virtual BOOL ProcessAccels(LPMSG PMessage);
    virtual BOOL ProcessMDIAccels(LPMSG PMessage);

private:

    void __TApplication(LPSTR AName, HINSTANCE AnInstance,
                    HINSTANCE APrevInstance, LPSTR ACmdLine, int ACmdShow);

};	// end of Application class

/* Performs special handling for the message last retrieved.
   Translates keyboard input messages into control selections or
   command messages, when appropriate.  Dispatches message, if
   translated. */
inline BOOL TApplication::ProcessAppMsg(LPMSG PMessage)
       { if ( KBHandlerWnd )
           if ( KBHandlerWnd->IsFlagSet(WB_MDICHILD) )
             return ProcessMDIAccels(PMessage) ||
                    ProcessDlgMsg(PMessage) ||
                    ProcessAccels(PMessage);
           else
            return ProcessDlgMsg(PMessage) ||
                   ProcessMDIAccels(PMessage) ||
                   ProcessAccels(PMessage);
         else
           return ProcessMDIAccels(PMessage) ||
                  ProcessAccels(PMessage); }

/* Attempts to translate a message into a control selection if the
   currently active OWL window has requested "keyboard handling".
   (Some keyboard input messages are translated into control
   selection messages). Dispatches message, if translated. */
inline BOOL TApplication::ProcessDlgMsg(LPMSG PMessage)
    { if (KBHandlerWnd && KBHandlerWnd->HWindow)
           return IsDialogMessage(KBHandlerWnd->HWindow, PMessage);
         else
           return FALSE; }

/* Attempts to translate a message into a command message if the
   TApplication has loaded an accelerator table. (Keyboard input
   messages for which an entry exists in the accelerator table are
   translated into command messages.)  Dispatches message, if
   translated.  (Translation of MDI accelerator messages is performed
   in ProcessMDIAccels function.) */
inline BOOL TApplication::ProcessAccels(LPMSG PMessage)
       { return HAccTable &&
         TranslateAccelerator(
                 MainWindow->HWindow, HAccTable, PMessage); }

/* Attempts to translate a message into a system command message
   for MDI TApplications (whose main window is a TMDIFrame). (Some
   keyboard input messages are translated into system commands for
   MDI applications). Dispatches message, if translated. */
inline BOOL TApplication::ProcessMDIAccels(LPMSG PMessage)
       { return (PTWindowsObject)(MainWindow->GetClient()) &&
           TranslateMDISysAccel(
            ((PTWindowsObject)(MainWindow->GetClient()))->HWindow, PMessage); }

/* Activates and deactivates "keyboard handling" (translation of
   keyboard input into control selections) for the currently active
   TWindowsObject by setting the KBHandlerWnd to the parameter passed.
   This function is called internally by the OWL whenever a OWL window
   is activated.  If "keyboard handling" has been requested for the
   TWindowsObject, the parameter passed is non-NULL, else NULL is
   passed.  "Keyboard handling" is requested, by default, for all
   modeless dialogs and may be requested for a TWindow via a call to
   its EnableKBHandler function. */
inline void TApplication::SetKBHandler(PTWindowsObject AWindowsObject)
       { KBHandlerWnd = AWindowsObject; }

extern PTApplication _EXPFUNC GetApplicationObject();

const int DEFAULT_DICTIONARY_SIZE = 10;
const int DEFAULT_DICTIONARY_INCREMENT = 10;

class _CLASSTYPE TAppDictionaryEntry
{
public:
    HANDLE hTask;
    PTApplication pApplication;
};

class _CLASSTYPE TAppDictionary
{
    int NumEntries;
    TAppDictionaryEntry * Table;
public:
    TAppDictionary(int InitialCount = DEFAULT_DICTIONARY_SIZE);
    ~TAppDictionary();

    static TAppDictionaryEntry * AllocTable(int Count);
    static void FreeTable(TAppDictionaryEntry *pTable);

    TAppDictionaryEntry *GrowTable(int Increment =
                                   DEFAULT_DICTIONARY_INCREMENT);
    void Add(PTApplication pApplication);
    void Delete();
    PTApplication Lookup();
};

extern unsigned short far  _EXPFUNC OWLGetVersion();

const unsigned short OWLVersion = 0x0110; // Version 1.1

#endif  // __OWLHDR_H

