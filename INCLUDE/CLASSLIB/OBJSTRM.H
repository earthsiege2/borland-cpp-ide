//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.10  $
//
//----------------------------------------------------------------------------
#if !defined(CLASSLIB_OBJSTRM_H)
#define CLASSLIB_OBJSTRM_H

#if !defined(CLASSLIB_DEFS_H)
# include <classlib/defs.h>
#endif
#if !defined(SERVICES_CHECKS_H)
# include <services/checks.h>
#endif
#if !defined(CLASSLIB_STREAMBL_H)
# include <classlib/streambl.h>
#endif
#if !defined(CLASSLIB_VECTIMP_H)
# include <classlib/vectimp.h>
#endif
#if !defined(__IOSTREAM_H) && !defined(_INC_IOSTREAM)
# include <iostream.h>
#endif
#if !defined(__FSTREAM_H) && !defined(_INC_FSTREAM)
# include <fstream.h>
#endif
#if !defined(BI_NO_RTTI) && !defined(__TYPEINFO_H) && !defined(_INC_TYPEINFO)
# include <typeinfo.h>
#endif

#if defined( BI_CLASSLIB_NO_po )
# pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  The __link() macro forces the compiler to link in a static instance   */
/*  of class TStreamableClass, which in turn registers its associated     */
/*  TStreamable object with the stream manager.  Applications that do     */
/*  not use streaming won't use __link(), and that will reduce the amount */
/*  of code that is linked into the application.                          */
/*                                                                        */
/*------------------------------------------------------------------------*/

struct fLink
{
    struct fLink *f;
    class TStreamableClass *t;
};

#define __link( s )             \
  extern TStreamableClass s;    \
  static fLink force ## s =     \
    { (fLink *)&force ## s, (TStreamableClass *)&s };

typedef unsigned P_id_type;

class _BIDSCLASS _RTTI TStreamable;
class _BIDSCLASS TStreamableTypes;
class _BIDSCLASS opstream;
class _BIDSCLASS ipstream;

class _EXPCLASS string;

ipstream _BIDSFAR& _BIDSENTRY _BIDSFUNC operator >> ( ipstream _BIDSFAR& is,
                                                      string _BIDSFAR& str );

opstream _BIDSFAR& _BIDSENTRY _BIDSFUNC operator << ( opstream _BIDSFAR& os,
                                                      const string _BIDSFAR& str );

/* -----------------------------------------------------------------------*/
/*                                                                        */
/*  _TYPENAME(obj) provides a macro for getting the type name from a      */
/*  pointer to an object. If runtime type information is available, this  */
/*  macro uses the typeid of the object to get its name. If runtime type  */
/*  information is not available, it uses the CastableID() for the object.*/
/*                                                                        */
/* -----------------------------------------------------------------------*/

#if defined( BI_NO_RTTI )
#   define _TYPENAME(obj) (obj)->CastableID()
#else
#   define _TYPENAME(obj) typeid(*obj).name()
#endif

/* -----------------------------------------------------------------------*/
/*                                                                        */
/*  class TStreamable                                                     */
/*                                                                        */
/*  This is the base class from which all streamable objects must be      */
/*  derived.                                                              */
/*                                                                        */
/* -----------------------------------------------------------------------*/

enum StreamableInit { streamableInit };

class _BIDSCLASS _RTTI TStreamableBase
{

public:

    virtual _BIDSCTOR ~TStreamableBase();

#if defined( BI_NO_RTTI )
    typedef const char * /*_BIDSENTRY*/ Type_id;
    virtual void * /*_BIDSENTRY*/ FindBase( Type_id id ) const;

public:

    virtual Type_id /*_BIDSENTRY*/ CastableID() const = 0;
    virtual void * /*_BIDSENTRY*/ MostDerived() const = 0;
#endif
};

class _BIDSCLASS _RTTI TStreamable : public TStreamableBase
{

    friend class _BIDSCLASS _RTTI TOldStreamer;

protected:

    virtual const char * _BIDSENTRY streamableName() const = 0;

    virtual void * _BIDSENTRY read( ipstream& );
    virtual void _BIDSENTRY write( opstream& );

#if defined( BI_NO_RTTI )
public:
    virtual void * /*_BIDSENTRY*/ FindBase( Type_id id ) const;
protected:
    virtual Type_id /*_BIDSENTRY*/ CastableID() const { return streamableName(); }
    virtual void * /*_BIDSENTRY*/ MostDerived() const { return 0; }
#endif
};

class _BIDSCLASS _RTTI TStreamer
{

    friend class ipstream;
    friend class opstream;

public:

    TStreamableBase * _BIDSENTRY GetObject() const { return object; }

protected:

    TStreamer( TStreamableBase *obj ) : object(obj) {}

    virtual const char * _BIDSENTRY StreamableName() const = 0;

    virtual void * _BIDSENTRY Read( ipstream&, uint32 ) const = 0;
    virtual void _BIDSENTRY Write( opstream& ) const = 0;

private:

    virtual uint32 _BIDSENTRY ClassVersion() const = 0;

    TStreamableBase *object;

};

class _BIDSCLASS _RTTI TOldStreamer : public TStreamer
{

public:

    _BIDSCTOR TOldStreamer( TStreamable *obj ) : TStreamer(obj) {};

protected:

    virtual const char * _BIDSENTRY StreamableName() const
        {
        return STATIC_CAST(TStreamable *,GetObject())->streamableName();
        }

    virtual void * _BIDSENTRY Read( ipstream& is, uint32 ) const
        {
        return STATIC_CAST(TStreamable *,GetObject())->read( is );
        }

    virtual void _BIDSENTRY Write( opstream& os ) const
        {
        STATIC_CAST(TStreamable *,GetObject())->write( os );
        }

private:

    virtual uint32 _BIDSENTRY ClassVersion() const
        {
        return 0;
        }

};

class _BIDSCLASS _RTTI TNewStreamer : public TStreamer
{

public:

    _BIDSCTOR TNewStreamer( TStreamableBase *obj ) : TStreamer(obj) {};

protected:

    virtual const char * _BIDSENTRY StreamableName() const
        {
        return _TYPENAME(GetObject());
        }

};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class TPWrittenObjects                                                */
/*                                                                         */
/*   Maintains a database of all objects that have been written to the     */
/*   current persistent stream.                                            */
/*                                                                         */
/*   Used by opstream when it writes a pointer from a stream to save the   */
/*   address and ID of the object being written.                           */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _BIDSCLASS TPWrittenObjects
{

    friend opstream;

public:

    void _BIDSENTRY RemoveAll();

    class _BIDSCLASS TPWObj
    {
    public:

        _BIDSCTOR TPWObj() : Address(0), Ident(0) {}
        _BIDSCTOR TPWObj( const void *adr, P_id_type id ) :
            Address(adr), Ident(id) {}

        friend int _BIDSENTRY operator == ( const TPWObj& o1, const TPWObj& o2 )
            { return TAddrInt(o1.Address) == TAddrInt(o2.Address); }

        friend int _BIDSENTRY operator < ( const TPWObj& o1, const TPWObj& o2 )
            { return TAddrInt(o1.Address) < TAddrInt(o2.Address); }

        const void *Address;
        P_id_type Ident;
#if defined(BI_DATA_NEAR)
        typedef uint16 TAddrInt;
#else
        typedef uint32 TAddrInt;
#endif
    };

private:

    _BIDSCTOR TPWrittenObjects();

    void _BIDSENTRY RegisterObject( TStreamableBase *adr );
    void _BIDSENTRY RegisterVB( const TStreamableBase *adr );
    P_id_type _BIDSENTRY FindObject( TStreamableBase *adr );
    P_id_type _BIDSENTRY FindVB( TStreamableBase *adr );

    P_id_type CurId;

    TSVectorImp<TPWObj> Data;
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

class _BIDSCLASS TPReadObjects
{
    friend ipstream;

public:

    void _BIDSENTRY RemoveAll();

private:

    _BIDSCTOR TPReadObjects();

    void _BIDSENTRY RegisterObject( TStreamableBase *adr );
    TStreamableBase * _BIDSENTRY Find( P_id_type id );

    TCVectorImp<TStreamableBase *> Data;
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class pstream                                                         */
/*                                                                         */
/*   Base class for handling streamable objects.                           */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _BIDSCLASS pstream
{
    friend TStreamableTypes;
    friend TStreamableClass;

public:

    enum PointerTypes { ptNull, ptIndexed, ptObject };

    _BIDSCTOR pstream( streambuf _BIDSFAR * );
    virtual _BIDSCTOR ~pstream();

    int _BIDSENTRY rdstate() const;
    int _BIDSENTRY eof() const;
    int _BIDSENTRY fail() const;
    int _BIDSENTRY bad() const;
    int _BIDSENTRY good() const;
    void _BIDSENTRY clear( int = 0 );
    _BIDSENTRY operator void *() const;
    int _BIDSENTRY operator ! () const;

    streambuf _BIDSFAR * _BIDSENTRY rdbuf() const;

    static void _BIDSENTRY initTypes();
    static void _BIDSENTRY releaseTypes();

    static void _BIDSENTRY registerType( TStreamableClass *ts );

protected:

    _BIDSCTOR pstream();

    streambuf _BIDSFAR *bp;
    int state;

    void _BIDSENTRY init( streambuf _BIDSFAR * );
    void _BIDSENTRY setstate( int );

    static TStreamableTypes *types;
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class ipstream                                                        */
/*                                                                         */
/*   Base class for reading streamable objects                             */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _BIDSCLASS ipstream : virtual public pstream
{
    friend class TStreamableClass;

public:

    _BIDSCTOR ipstream( streambuf _BIDSFAR * );

    streampos _BIDSENTRY tellg();
    ipstream& _BIDSENTRY seekg( streampos );
    ipstream& _BIDSENTRY seekg( streamoff, ios::seek_dir );

    uint8 _BIDSENTRY readByte();
    void _BIDSENTRY readBytes( void _BIDSFAR *, size_t );
    void _BIDSENTRY freadBytes( void _BIDSFARDATA *data, size_t sz );

    uint32 _BIDSENTRY readWord();
    uint16 _BIDSENTRY readWord16();
    uint32 _BIDSENTRY readWord32();

    char _BIDSFAR * _BIDSENTRY readString();
    char _BIDSFAR * _BIDSENTRY readString( char _BIDSFAR *, unsigned );
    char _BIDSFARDATA * _BIDSENTRY freadString();
    char _BIDSFARDATA * _BIDSENTRY freadString( char _BIDSFARDATA *buf,
                                            unsigned maxLen );

    friend ipstream& _BIDSENTRY operator >> ( ipstream&, signed char& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, unsigned char& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, char& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, signed short& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, unsigned short& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, signed int& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, unsigned int& );
#if defined(BI_UNIQUE_BOOL)
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, bool& );
#endif
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, signed long& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, unsigned long& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, float& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, double& );
    friend ipstream& _BIDSENTRY operator >> ( ipstream&, long double& );

    friend ipstream _BIDSFAR& _BIDSENTRY _BIDSFUNC
            operator >> ( ipstream _BIDSFAR& is, string _BIDSFAR& str );

    uint32 _BIDSENTRY getVersion() const;

    TStreamableBase _BIDSFAR * _BIDSENTRY readObject( TStreamableBase _BIDSFAR *&mem, ModuleId mid = GetModuleId() );
    TStreamableBase _BIDSFAR * _BIDSENTRY readObjectPointer( TStreamableBase _BIDSFAR *&mem, ModuleId mid = GetModuleId() );

    TStreamableBase _BIDSFAR * _BIDSENTRY find( P_id_type );
    void _BIDSENTRY registerObject( TStreamableBase _BIDSFAR *adr );

protected:

    _BIDSCTOR ipstream();

    const ObjectBuilder _BIDSFAR * _BIDSENTRY readPrefix( ModuleId mid );
    void _BIDSENTRY readData( const ObjectBuilder _BIDSFAR *,
                          TStreamableBase _BIDSFAR *& );
    void _BIDSENTRY readSuffix();

    void _BIDSENTRY readVersion();

private:

    uint32 readStringLength();
    TPReadObjects objs;
    uint32 version;
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class opstream                                                        */
/*                                                                         */
/*   Base class for writing streamable objects                             */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _BIDSCLASS opstream : virtual public pstream
{
public:

    _BIDSCTOR opstream( streambuf _BIDSFAR * );
    _BIDSCTOR ~opstream();

    streampos _BIDSENTRY tellp();
    opstream& _BIDSENTRY seekp( streampos );
    opstream& _BIDSENTRY seekp( streamoff, ios::seek_dir );
    opstream& _BIDSENTRY flush();

    void _BIDSENTRY writeByte( uint8 );
    void _BIDSENTRY writeBytes( const void _BIDSFAR *, size_t );
    void _BIDSENTRY fwriteBytes( const void _BIDSFARDATA *data, size_t sz );

    void _BIDSENTRY writeWord( uint32 );
    void _BIDSENTRY writeWord16( uint16 );
    void _BIDSENTRY writeWord32( uint32 );

    void _BIDSENTRY writeString( const char _BIDSFAR * );
    void _BIDSENTRY fwriteString( const char _BIDSFARDATA * str );

    friend opstream& _BIDSENTRY operator << ( opstream&, signed char );
    friend opstream& _BIDSENTRY operator << ( opstream&, unsigned char );
    friend opstream& _BIDSENTRY operator << ( opstream&, char );
    friend opstream& _BIDSENTRY operator << ( opstream&, signed short );
    friend opstream& _BIDSENTRY operator << ( opstream&, unsigned short );
    friend opstream& _BIDSENTRY operator << ( opstream&, signed int );
    friend opstream& _BIDSENTRY operator << ( opstream&, unsigned int );
#if defined(BI_UNIQUE_BOOL)
    friend opstream& _BIDSENTRY operator << ( opstream&, bool );
#endif
    friend opstream& _BIDSENTRY operator << ( opstream&, signed long );
    friend opstream& _BIDSENTRY operator << ( opstream&, unsigned long );
    friend opstream& _BIDSENTRY operator << ( opstream&, float );
    friend opstream& _BIDSENTRY operator << ( opstream&, double );
    friend opstream& _BIDSENTRY operator << ( opstream&, long double );

    void _BIDSENTRY writeObject( const TStreamableBase _BIDSFAR *t, int isPtr = 0, ModuleId mid = GetModuleId() );
    void _BIDSENTRY writeObjectPointer( const TStreamableBase _BIDSFAR *t, ModuleId mid = GetModuleId() );

    P_id_type _BIDSENTRY findObject( TStreamableBase _BIDSFAR *adr );
    void _BIDSENTRY registerObject( TStreamableBase _BIDSFAR *adr );

    P_id_type _BIDSENTRY findVB( TStreamableBase _BIDSFAR *adr );
    void _BIDSENTRY registerVB( TStreamableBase _BIDSFAR *adr );

protected:

    _BIDSCTOR opstream();

    void _BIDSENTRY writePrefix( const TStreamableBase _BIDSFAR * );
    void _BIDSENTRY writeData( const TStreamableBase _BIDSFAR *, ModuleId mid );
    void _BIDSENTRY writeSuffix( const TStreamableBase _BIDSFAR * );

private:

    void _BIDSENTRY writeVersion();

    TPWrittenObjects *objs;
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   class fpbase                                                          */
/*                                                                         */
/*   Base class for handling streamable objects on file streams            */
/*                                                                         */
/* ------------------------------------------------------------------------*/

class _BIDSCLASS fpbase : virtual public pstream
{
public:

    _BIDSCTOR fpbase();
    _BIDSCTOR fpbase( const char _BIDSFAR *, int, int = filebuf::openprot );
    _BIDSCTOR fpbase( int );
    _BIDSCTOR fpbase( int, char _BIDSFAR *, int );

    void _BIDSENTRY open( const char _BIDSFAR *, int, int = filebuf::openprot );
    void _BIDSENTRY attach( int );
    void _BIDSENTRY close();
    void _BIDSENTRY setbuf( char _BIDSFAR *, int );
    filebuf _BIDSFAR * _BIDSENTRY rdbuf();

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

class _BIDSCLASS ifpstream : public fpbase, public ipstream
{
public:

    _BIDSCTOR ifpstream();
    _BIDSCTOR ifpstream( const char _BIDSFAR *,
                      int = ios::in,
                      int = filebuf::openprot
                    );
    _BIDSCTOR ifpstream( int );
    _BIDSCTOR ifpstream( int, char _BIDSFAR *, int );

    filebuf _BIDSFAR * _BIDSENTRY rdbuf();
    void _BIDSENTRY open( const char _BIDSFAR *,
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

class _BIDSCLASS ofpstream : public fpbase, public opstream
{

public:

    _BIDSCTOR ofpstream();
    _BIDSCTOR ofpstream( const char _BIDSFAR *,
                      int = ios::out,
                      int = filebuf::openprot
                    );
    _BIDSCTOR ofpstream( int );
    _BIDSCTOR ofpstream( int, char _BIDSFAR *, int );

    filebuf _BIDSFAR * _BIDSENTRY rdbuf();
    void _BIDSENTRY open( const char _BIDSFAR *,
                      int = ios::out,
                      int = filebuf::openprot
                    );
};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   Inline functions                                                      */
/*                                                                         */
/* ------------------------------------------------------------------------*/

inline _BIDSCTOR pstream::pstream( streambuf _BIDSFAR *sb )
{
    init( sb );
}

inline int _BIDSENTRY pstream::rdstate() const
{
    return state;
}

inline int _BIDSENTRY pstream::eof() const
{
    return state & ios::eofbit;
}

#if defined(BI_COMP_MSC)
# define hardfail    goodbit   // MSC ios does not support hardfail, use goodbit (0)
#endif

inline int _BIDSENTRY pstream::fail() const
{
    return state & (ios::failbit | ios::badbit | ios::hardfail);
}

inline int _BIDSENTRY pstream::bad() const
{
    return state & (ios::badbit | ios::hardfail);
}

inline int _BIDSENTRY pstream::good() const
{
    return state == 0;
}

inline void _BIDSENTRY pstream::clear( int i )
{
    state = (i & 0xFF) | (state & ios::hardfail);
}

#if defined(BI_COMP_MSC)
# undef hardfail
#endif

inline _BIDSENTRY pstream::operator void _BIDSFAR *() const
{
    return fail() ? 0 : (void *)this;
}

inline int _BIDSENTRY pstream::operator! () const
{
    return fail();
}

inline streambuf _BIDSFAR * _BIDSENTRY pstream::rdbuf() const
{
    return bp;
}

inline _BIDSCTOR pstream::pstream()
{
}

inline void _BIDSENTRY pstream::init( streambuf *sbp )
{
    state = 0;
    bp = sbp;
}

inline void _BIDSENTRY pstream::setstate( int b )
{
    state |= (b&0xFF);
}

inline _BIDSCTOR ipstream::ipstream( streambuf _BIDSFAR *sb )
{
    pstream::init( sb );
    readVersion();
}

inline _BIDSCTOR ipstream::ipstream()
{
    if( bp != 0 )
        readVersion();
}

inline TStreamableBase * _BIDSENTRY ipstream::find( P_id_type id )
{
    return objs.Find( id );
}

inline void _BIDSENTRY ipstream::registerObject( TStreamableBase *adr )
{
    objs.RegisterObject( adr );
}

inline uint32 _BIDSENTRY ipstream::getVersion() const
{
    return version;
}

inline void _BIDSENTRY pstream::registerType( TStreamableClass *ts )
{
    types->RegisterType( GetModuleId(), *ts );
}

inline _BIDSCTOR opstream::~opstream()
{
    delete objs;
}

inline void _BIDSENTRY opstream::writeWord( uint32 word32 )
{
    writeWord32( word32 );
}

inline void _BIDSENTRY opstream::writeSuffix( const TStreamableBase * )
{
    writeByte( ']' );
}

inline P_id_type _BIDSENTRY opstream::findObject( TStreamableBase *adr )
{
    return objs->FindObject( adr );
}

inline void _BIDSENTRY opstream::registerObject( TStreamableBase *adr )
{
    objs->RegisterObject( adr );
}

inline P_id_type _BIDSENTRY opstream::findVB( TStreamableBase *adr )
{
    return objs->FindVB( adr );
}

inline void _BIDSENTRY opstream::registerVB( TStreamableBase *adr )
{
    objs->RegisterVB( adr );
}

inline _BIDSCTOR fpbase::fpbase()
{
    pstream::init( &buf );
}

inline _BIDSCTOR fpbase::fpbase( const char *name, int omode, int prot )
{
    pstream::init( &buf );
    open( name, omode, prot );
}

inline _BIDSCTOR fpbase::fpbase( int f ) : buf( f )
{
    pstream::init( &buf );
}

inline _BIDSCTOR fpbase::fpbase( int f, char *b, int len ) : buf( f, b, len )
{
    pstream::init( &buf );
}

inline filebuf * _BIDSENTRY fpbase::rdbuf()
{
    return &buf;
}

inline _BIDSCTOR ifpstream::ifpstream()
{
}

inline _BIDSCTOR ifpstream::ifpstream( const char* name, int omode, int prot ) :
    fpbase( name, omode | ios::in | ios::binary, prot )
{
}

inline _BIDSCTOR ifpstream::ifpstream( int f ) : fpbase( f )
{
}

inline _BIDSCTOR ifpstream::ifpstream(int f, char* b, int len) : fpbase(f, b, len)
{
}

inline filebuf * _BIDSENTRY ifpstream::rdbuf()
{
    return fpbase::rdbuf();
}

inline void _BIDSENTRY ifpstream::open( const char _BIDSFAR *name,
                                    int omode,
                                    int prot )
{
    fpbase::open( name, omode | ios::in | ios::binary, prot );
    readVersion();
}

inline _BIDSCTOR ofpstream::ofpstream()
{
}

inline _BIDSCTOR ofpstream::ofpstream( const char* name, int omode, int prot ) :
    fpbase( name, omode | ios::out | ios::binary, prot )
{
}

inline _BIDSCTOR ofpstream::ofpstream( int f ) : fpbase( f )
{
}

inline _BIDSCTOR ofpstream::ofpstream(int f, char* b, int len) :
    fpbase(f, b, len)
{
}

inline filebuf * _BIDSENTRY ofpstream::rdbuf()
{
    return fpbase::rdbuf();
}

inline void _BIDSENTRY ofpstream::open( const char _BIDSFAR *name,
                                    int omode,
                                    int prot )
{
    fpbase::open( name, omode | ios::out | ios::binary, prot );
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, signed char &ch )
{
    ch = ps.readByte();
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, unsigned char &ch )
{
    ch = ps.readByte();
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, char &ch )
{
    ch = ps.readByte();
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, signed short &sh )
{
    sh = ps.readWord16();
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, unsigned short &sh )
{
    sh = ps.readWord16();
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, signed int &i )
{
    i = (int)(ps.readWord());
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, unsigned int &i )
{
    i = (unsigned int)(ps.readWord());
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, signed long &l )
{
    ps.readBytes( &l, sizeof(l) );
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, unsigned long &l )
{
    ps.readBytes( &l, sizeof(l) );
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, float &f )
{
    ps.readBytes( &f, sizeof(f) );
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, double &d )
{
    ps.readBytes( &d, sizeof(d) );
    return ps;
}

inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, long double &l )
{
    ps.readBytes( &l, sizeof(l) );
    return ps;
}

#if defined(BI_UNIQUE_BOOL)
inline ipstream& _BIDSENTRY operator >> ( ipstream& ps, bool &b )
{
    b = static_cast<bool>(ps.readWord32());
    return ps;
}
#endif

inline opstream& _BIDSENTRY operator << ( opstream& ps, signed char ch )
{
    ps.writeByte( ch );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, unsigned char ch )
{
    ps.writeByte( ch );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, char ch )
{
    ps.writeByte( ch );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, signed short sh )
{
    ps.writeWord16( sh );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, unsigned short sh )
{
    ps.writeWord16( sh );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, signed int i )
{
    ps.writeWord32( i );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, unsigned int i )
{
    ps.writeWord32( i );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, signed long l )
{
    ps.writeBytes( &l, sizeof(l) );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, unsigned long l )
{
    ps.writeBytes( &l, sizeof(l) );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, float f )
{
    ps.writeBytes( &f, sizeof(f) );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, double d )
{
    ps.writeBytes( &d, sizeof(d) );
    return ps;
}

inline opstream& _BIDSENTRY operator << ( opstream& ps, long double l )
{
    ps.writeBytes( &l, sizeof(l) );
    return ps;
}

#if defined(BI_UNIQUE_BOOL)
inline opstream& _BIDSENTRY operator << ( opstream& ps, bool b )
{
    ps.writeWord32( b );
    return ps;
}
#endif

template <class Base> void WriteBaseObject( Base *base, opstream& out )
{
    Base::Streamer strmr(base);
    out << strmr.ClassVersion();
    strmr.Write( out );
}

template <class Base> void ReadBaseObject( Base *base, ipstream& in )
{
    uint32 version = 0;
    if( in.getVersion() > 0 )
        in >> version;
    Base::Streamer(base).Read( in, version );
}

template <class Base> void WriteVirtualBase( Base *base, opstream& out )
{
    if( !out.good() )
        return;
    if( out.findVB( base ) != 0 )
        {
        out.writeByte( pstream::ptIndexed );    // use ptIndexed to indicate
                                                // that we've already seen
                                                // this virtual base. Don't
                                                // need to actually write it.
        }
    else
        {
        Base::Streamer strmr(base);
        out.registerObject( (TStreamableBase *)((char *)base + 1) );
        out.writeByte( pstream::ptObject );
        out.writeWord32( strmr.ClassVersion() );
        strmr.Write( out );
        }
}

template <class Base> void ReadVirtualBase( Base *base, ipstream& in )
{
    char ch;
    in >> ch;
    switch( ch )
        {
        case pstream::ptIndexed:
            {
            break;      // We've already read this virtual base
            }
        case pstream::ptObject:
            {
            uint32 ver = 0;
            if( in.getVersion() > 0 )
                ver = in.readWord32();
            Base::Streamer strmr(base);
            // register the address
            in.registerObject(strmr.GetObject());
            strmr.Read( in, ver );
            break;
            }
        }
}

//
//  Individual Components for Streamable Declarations
//

#define DECLARE_STREAMER( exp, cls, ver )                           \
public:                                                             \
    class exp Streamer : public TNewStreamer                        \
        {                                                           \
        public:                                                     \
                                                                    \
        Streamer( TStreamableBase *obj );                           \
                                                                    \
        virtual uint32 ClassVersion() const                         \
            { return ver; }                                         \
                                                                    \
        virtual void Write( opstream& ) const;                      \
        virtual void *Read( ipstream&, uint32 ) const;              \
                                                                    \
        cls *GetObject() const                                      \
            {                                                       \
            return object;                                          \
            }                                                       \
                                                                    \
        static TStreamer *Build( TStreamableBase *obj )             \
            {                                                       \
            return new Streamer( obj ? obj : new cls(streamableInit) ); \
            }                                                       \
                                                                    \
        private:                                                    \
            cls *object;                                            \
                                                                    \
        };                                                          \
    friend Streamer;                                                \
    friend void ReadBaseObject( cls *, ipstream& );                 \
    friend void WriteBaseObject( cls *, opstream& );                \
    friend void ReadVirtualBase( cls *, ipstream& );                \
    friend void WriteVirtualBase( cls *, opstream& )

#define DECLARE_STREAMER_FROM_BASE( exp, cls, base )                \
public:                                                             \
    class exp Streamer : public base::Streamer                      \
        {                                                           \
        public:                                                     \
                                                                    \
        Streamer( TStreamableBase *obj ) : base::Streamer(obj){}    \
                                                                    \
        cls *GetObject() const                                      \
            {                                                       \
            return object;                                          \
            }                                                       \
                                                                    \
        static TStreamer *Build( TStreamableBase *obj )             \
            {                                                       \
            return new Streamer( obj ? obj : new cls(streamableInit) ); \
            }                                                       \
                                                                    \
        private:                                                    \
            cls *object;                                            \
                                                                    \
        };                                                          \
    friend Streamer;                                                \
    friend void ReadBaseObject( cls *, ipstream& );                 \
    friend void WriteBaseObject( cls *, opstream& );                \
    friend void ReadVirtualBase( cls *, ipstream& );                \
    friend void WriteVirtualBase( cls *, opstream& )

#define DECLARE_ABSTRACT_STREAMER( exp, cls, ver )                  \
public:                                                             \
    class exp Streamer : public TNewStreamer                        \
        {                                                           \
        public:                                                     \
                                                                    \
        Streamer( TStreamableBase *obj );                           \
                                                                    \
        virtual uint32 ClassVersion() const                         \
            { return ver; }                                         \
                                                                    \
        virtual void Write( opstream& ) const;                      \
        virtual void *Read( ipstream&, uint32 ) const;              \
                                                                    \
        cls *GetObject() const                                      \
            {                                                       \
            return object;                                          \
            }                                                       \
                                                                    \
        private:                                                    \
            cls *object;                                            \
                                                                    \
        };                                                          \
    friend Streamer;                                                \
    friend void ReadBaseObject( cls *, ipstream& );                 \
    friend void WriteBaseObject( cls *, opstream& );                \
    friend void ReadVirtualBase( cls *, ipstream& );                \
    friend void WriteVirtualBase( cls *, opstream& )


#define DECLARE_STREAMABLE_OPS( cls )                               \
static ipstream& readRef( ipstream& is, cls& cl );                  \
friend inline ipstream& operator >> ( ipstream& is, cls& cl )       \
    { return cls::readRef( is, cl ); }                              \
static ipstream& readPtr( ipstream& is, cls*& cl );                 \
friend inline ipstream& operator >> ( ipstream& is, cls*& cl )      \
    { return cls::readPtr( is, cl ); }                              \
static opstream& writeRef( opstream& is, const cls& cl );           \
friend inline opstream& operator << ( opstream& os, const cls& cl ) \
    { return cls::writeRef( os, cl ); }                             \
static opstream& writePtr( opstream& is, const cls* cl );           \
friend inline opstream& operator << ( opstream& os, const cls* cl ) \
    { return cls::writePtr( os, cl ); }

#define DECLARE_STREAMABLE_CTOR( cls )                              \
public:                                                             \
    cls ( StreamableInit )


//
// Castable declaration macros
//
#if defined( BI_NO_RTTI )
# define DECLARE_CASTABLE                                           \
public:                                                             \
    virtual void *FindBase( Type_id id ) const;                     \
public:                                                             \
    virtual Type_id CastableID() const;                             \
    virtual void *MostDerived() const { return (void *)this; }      \
    static Type_id CastableIdent
#else
# define DECLARE_CASTABLE friend class typeinfo
#endif

//
// Streamable declaration macros
//
#if !defined(BI_NO_OBJ_STREAMING)

#define DECLARE_STREAMABLE( exp, cls, ver )                         \
    DECLARE_CASTABLE;                                               \
    DECLARE_STREAMER( exp, cls, ver );                              \
    DECLARE_STREAMABLE_OPS( cls );                                  \
    DECLARE_STREAMABLE_CTOR( cls )

#define DECLARE_STREAMABLE_FROM_BASE( exp, cls, base )              \
    DECLARE_CASTABLE;                                               \
    DECLARE_STREAMER_FROM_BASE( exp, cls, base );                   \
    DECLARE_STREAMABLE_OPS( cls );                                  \
    DECLARE_STREAMABLE_CTOR( cls )

#define DECLARE_ABSTRACT_STREAMABLE( exp, cls, ver )                \
    DECLARE_CASTABLE;                                               \
    DECLARE_ABSTRACT_STREAMER( exp, cls, ver );                     \
    DECLARE_STREAMABLE_OPS( cls );                                  \
    DECLARE_STREAMABLE_CTOR( cls )

#else  // if BI_NO_OBJ_STREAMING

#define DECLARE_STREAMABLE( exp, cls, ver )                         \
    DECLARE_CASTABLE;

#define DECLARE_STREAMABLE_FROM_BASE( exp, cls, base )              \
    DECLARE_CASTABLE;

#define DECLARE_ABSTRACT_STREAMABLE( exp, cls, ver )                \
    DECLARE_CASTABLE;

#endif  // if/else BI_NO_OBJ_STREAMING

//
// Castable implementation macros
//
#if !defined( BI_NO_RTTI )

#define IMPLEMENT_CASTABLE( cls )
#define IMPLEMENT_CASTABLE1( cls, base1 )
#define IMPLEMENT_CASTABLE2( cls, base1, base2 )
#define IMPLEMENT_CASTABLE3( cls, base1, base2, base3 )
#define IMPLEMENT_CASTABLE4( cls, base1, base2, base3, base4 )
#define IMPLEMENT_CASTABLE5( cls, base1, base2, base3, base4, base5 )

#else   // BI_NO_RTTI

#define IMPLEMENT_CASTABLE_ID( cls )                                \
TStreamableBase::Type_id cls::CastableIdent = #cls;                 \
TStreamableBase::Type_id cls::CastableID() const                    \
{                                                                   \
    return cls::CastableIdent;                                      \
}                                                                   \

#define IMPLEMENT_CASTABLE( cls )                                   \
IMPLEMENT_CASTABLE_ID( cls );                                       \
void *cls::FindBase( Type_id id ) const                             \
{                                                                   \
    return (strcmp( id, CastableIdent ) == 0) ? (void *)this : 0;   \
}                                                                   \

                                                                    \
#define IMPLEMENT_CASTABLE1( cls, base1 )                           \
IMPLEMENT_CASTABLE_ID( cls );                                       \
void *cls::FindBase( Type_id id ) const                             \
{                                                                   \
    if(strcmp( id, CastableIdent ) == 0)                            \
        return (void *)this;                                        \
    else                                                            \
        return base1::FindBase(id);                                 \
}                                                                   \

#define IMPLEMENT_CASTABLE2( cls, base1, base2 )                    \
IMPLEMENT_CASTABLE_ID( cls );                                       \
void *cls::FindBase( Type_id id ) const                             \
{                                                                   \
    void *res = 0;                                                  \
    if(strcmp( id, CastableIdent ) == 0)                            \
        return (void *)this;                                        \
    else if( (res = base1::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base2::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else                                                            \
        return 0;                                                   \
}                                                                   \

#define IMPLEMENT_CASTABLE3( cls, base1, base2, base3 )             \
IMPLEMENT_CASTABLE_ID( cls );                                       \
void *cls::FindBase( Type_id id ) const                             \
{                                                                   \
    void *res = 0;                                                  \
    if(strcmp( id, CastableIdent ) == 0)                            \
        return (void *)this;                                        \
    else if( (res = base1::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base2::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base3::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else                                                            \
        return 0;                                                   \
}                                                                   \

#define IMPLEMENT_CASTABLE4( cls, base1, base2, base3, base4 )      \
IMPLEMENT_CASTABLE_ID( cls );                                       \
void *cls::FindBase( Type_id id ) const                             \
{                                                                   \
    void *res = 0;                                                  \
    if(strcmp( id, CastableIdent ) == 0)                            \
        return (void *)this;                                        \
    else if( (res = base1::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base2::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base3::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base4::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else                                                            \
        return 0;                                                   \
}                                                                   \

#define IMPLEMENT_CASTABLE5( cls, base1, base2, base3, base4, base5 )\
IMPLEMENT_CASTABLE_ID( cls );                                       \
void *cls::FindBase( Type_id id ) const                             \
{                                                                   \
    void *res = 0;                                                  \
    if(strcmp( id, CastableIdent ) == 0)                            \
        return (void *)this;                                        \
    else if( (res = base1::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base2::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base3::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base4::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else if( (res = base5::FindBase(id)) != 0 )                     \
        return res;                                                 \
    else                                                            \
        return 0;                                                   \
}                                                                   \

#endif  // BI_NO_RTTI

//
// Streamable implementation mactos
//
#if !defined(BI_NO_OBJ_STREAMING)
# if defined( BI_NO_RTTI )
#   define IMPLEMENT_STREAMABLE_CLASS( cls )    \
    TStreamableClass r ## cls( cls::CastableIdent, &cls::Streamer::Build )
# else
#   define IMPLEMENT_STREAMABLE_CLASS( cls )    \
    TStreamableClass r ## cls( typeid(cls).name(), &cls::Streamer::Build )
# endif
#else
# define IMPLEMENT_STREAMABLE_CLASS( cls )
#endif

#if !defined(BI_NO_OBJ_STREAMING)
#define IMPLEMENT_STREAMABLE_POINTER( cls )                         \
ipstream& cls::readPtr( ipstream& is, cls*& cl )                    \
    {                                                               \
    TStreamableBase *temp = 0;                                      \
    is.readObjectPointer( temp );                                   \
    cl = TYPESAFE_DOWNCAST(temp,cls);                               \
    return is;                                                      \
    }                                                               \
ipstream& cls::readRef( ipstream& is, cls& cl )                     \
    {                                                               \
    TStreamableBase *ptr = &cl;                                     \
    is.readObject( ptr );                                           \
    return is;                                                      \
    }                                                               \
opstream& cls::writeRef( opstream& os, const cls& cl )              \
    {                                                               \
    os.writeObject( &cl );                                          \
    return os;                                                      \
    }                                                               \
opstream& cls::writePtr( opstream& os, const cls* cl )              \
    {                                                               \
    os.writeObjectPointer( cl );                                    \
    return os;                                                      \
    }
#else
#define IMPLEMENT_STREAMABLE_POINTER( cls )
#endif

#if !defined(BI_NO_OBJ_STREAMING)

#define IMPLEMENT_STREAMER( cls )                                   \
cls::Streamer::Streamer( TStreamableBase *obj ) :                   \
    TNewStreamer(obj), object(TYPESAFE_DOWNCAST(obj,cls)){}

#define IMPLEMENT_STREAMABLE_CTOR( cls )                            \
cls::cls ( StreamableInit ) {}

#define IMPLEMENT_STREAMABLE_CTOR1( cls, base1 )                    \
cls::cls ( StreamableInit ) : base1( streamableInit ) {}

#define IMPLEMENT_STREAMABLE_CTOR2( cls, base1, base2 )             \
cls::cls ( StreamableInit ) :                                       \
    base1 ( streamableInit ),                                       \
    base2 ( streamableInit ) {}

#define IMPLEMENT_STREAMABLE_CTOR3( cls, base1, base2, base3 )      \
cls::cls ( StreamableInit ) :                                       \
    base1 ( streamableInit ),                                       \
    base2 ( streamableInit ),                                       \
    base3 ( streamableInit ) {}

#define IMPLEMENT_STREAMABLE_CTOR4( cls, base1, base2, base3, base4 )\
cls::cls ( StreamableInit ) :                                       \
    base1 ( streamableInit ),                                       \
    base2 ( streamableInit ),                                       \
    base3 ( streamableInit ),                                       \
    base4 ( streamableInit ) {}

#define IMPLEMENT_STREAMABLE_CTOR5( cls, base1,base2,base3,base4,base5)\
cls::cls ( StreamableInit ) :                                       \
    base1 ( streamableInit ),                                       \
    base2 ( streamableInit ),                                       \
    base3 ( streamableInit ),                                       \
    base4 ( streamableInit ),                                       \
    base5 ( streamableInit ) {}

#else  // if !defined(BI_NO_OBJ_STREAMING)
# define IMPLEMENT_STREAMER( cls )
# define IMPLEMENT_STREAMABLE_CTOR( cls )
# define IMPLEMENT_STREAMABLE_CTOR1( cls, base1 )
# define IMPLEMENT_STREAMABLE_CTOR2( cls, base1, base2 )
# define IMPLEMENT_STREAMABLE_CTOR3( cls, base1, base2, base3 )
# define IMPLEMENT_STREAMABLE_CTOR4( cls, base1, base2, base3, base4 )
# define IMPLEMENT_STREAMABLE_CTOR5( cls, base1,base2,base3,base4,base5)
#endif
                                                                    \

//
//  Standard Combinations of Streamable Implementations
//

#if !defined(BI_NO_OBJ_STREAMING)
#define IMPLEMENT_ABSTRACT_STREAMABLE( cls )                        \
IMPLEMENT_CASTABLE( cls );                                          \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR( cls );                                   \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE1( cls, base1 )                \
IMPLEMENT_CASTABLE1( cls, base1 );                                  \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR1( cls, base1 );                           \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE2( cls, base1, base2 )         \
IMPLEMENT_CASTABLE2( cls, base1, base2 );                    \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR2( cls, base1, base2 );                    \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE3( cls, base1, base2, base3 )  \
IMPLEMENT_CASTABLE3( cls, base1, base2, base3 );                    \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR3( cls, base1, base2, base3 );             \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE4( cls, base1, base2, base3, base4 )\
IMPLEMENT_CASTABLE4( cls, base1, base2, base3, base4 );             \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR4( cls, base1, base2, base3, base4 );      \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE5( cls, base1, base2, base3, base4, base5 )\
IMPLEMENT_CASTABLE5( cls, base1, base2, base3, base4, base5 );      \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR5( cls, base1, base2, base3, base4, base5 );\
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_STREAMABLE( cls )                                 \
IMPLEMENT_STREAMABLE_CLASS( cls );                                  \
IMPLEMENT_ABSTRACT_STREAMABLE( cls )

#define IMPLEMENT_STREAMABLE1( cls, base1 )                         \
IMPLEMENT_STREAMABLE_CLASS( cls );                                  \
IMPLEMENT_ABSTRACT_STREAMABLE1( cls, base1 )

#define IMPLEMENT_STREAMABLE2( cls, base1, base2 )                  \
IMPLEMENT_STREAMABLE_CLASS( cls );                                  \
IMPLEMENT_ABSTRACT_STREAMABLE2( cls, base1, base2 )

#define IMPLEMENT_STREAMABLE3( cls, base1, base2, base3 )           \
IMPLEMENT_STREAMABLE_CLASS( cls );                                  \
IMPLEMENT_ABSTRACT_STREAMABLE3( cls, base1, base2, base3 )

#define IMPLEMENT_STREAMABLE4( cls, base1, base2, base3, base4 )    \
IMPLEMENT_STREAMABLE_CLASS( cls );                                  \
IMPLEMENT_ABSTRACT_STREAMABLE4( cls, base1, base2, base3, base4 )

#define IMPLEMENT_STREAMABLE5( cls, base1, base2, base3, base4, base5 )\
IMPLEMENT_STREAMABLE_CLASS( cls );                                  \
IMPLEMENT_ABSTRACT_STREAMABLE5( cls, base1, base2, base3, base4, base5 )

#define IMPLEMENT_STREAMABLE_FROM_BASE( cls, base1 )                \
IMPLEMENT_STREAMABLE_CLASS( cls );                                  \
IMPLEMENT_STREAMABLE_CTOR1( cls, base1 );                           \
IMPLEMENT_STREAMABLE_POINTER( cls )

#else  // if BI_NO_OBJ_STREAMING

#define IMPLEMENT_ABSTRACT_STREAMABLE( cls )                        \
IMPLEMENT_CASTABLE( cls );
#define IMPLEMENT_ABSTRACT_STREAMABLE1( cls, base1 )                \
IMPLEMENT_CASTABLE1( cls, base1 );
#define IMPLEMENT_ABSTRACT_STREAMABLE2( cls, base1, base2 )         \
IMPLEMENT_CASTABLE2( cls, base1, base2 )
#define IMPLEMENT_ABSTRACT_STREAMABLE3( cls, base1, base2, base3 )  \
IMPLEMENT_CASTABLE3( cls, base1, base2, base3 );
#define IMPLEMENT_ABSTRACT_STREAMABLE4( cls, base1, base2, base3, base4 ) \
IMPLEMENT_CASTABLE4( cls, base1, base2, base3, base4 );
#define IMPLEMENT_ABSTRACT_STREAMABLE5( cls, base1, base2, base3, base4, base5 ) \
IMPLEMENT_CASTABLE5( cls, base1, base2, base3, base4, base5 );
#define IMPLEMENT_STREAMABLE( cls )                                \
IMPLEMENT_CASTABLE( cls );
#define IMPLEMENT_STREAMABLE1( cls, base1 )                        \
IMPLEMENT_CASTABLE1( cls, base1 );
#define IMPLEMENT_STREAMABLE2( cls, base1, base2 )                 \
IMPLEMENT_CASTABLE2( cls, base1, base2 )
#define IMPLEMENT_STREAMABLE3( cls, base1, base2, base3 )          \
IMPLEMENT_CASTABLE3( cls, base1, base2, base3 );
#define IMPLEMENT_STREAMABLE4( cls, base1, base2, base3, base4 )   \
IMPLEMENT_CASTABLE4( cls, base1, base2, base3, base4 );
#define IMPLEMENT_STREAMABLE5( cls, base1, base2, base3, base4, base5 ) \
IMPLEMENT_CASTABLE5( cls, base1, base2, base3, base4, base5 );
#define IMPLEMENT_STREAMABLE_FROM_BASE( cls, base1 )

#endif  // if/else BI_NO_OBJ_STREAMING


#if defined(BI_CLASSLIB_NO_po)
# pragma option -po.
#endif

#endif  // CLASSLIB_OBJSTRM_H
