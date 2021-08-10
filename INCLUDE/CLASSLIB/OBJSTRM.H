/*------------------------------------------------------------------------*/
/*                                                                        */
/*  OBJSTRM.H                                                             */
/*                                                                        */
/*  Copyright (c) 1992, 1993 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CLASSLIB_OBJSTRM_H )
#define __CLASSLIB_OBJSTRM_H

#if !defined( __IOSTREAM_H )
#include <iostream.h>
#endif  // __IOSTREAM_H

#if !defined( __FSTREAM_H )
#include <fstream.h>
#endif  // __FSTREAM_H

#if !defined( __SYSTYPES_H )
#include <systypes.h>
#endif  // __SYSTYPES_H

#if !defined( __TYPEINFO_H )
#include <typeinfo.h>
#endif  // __TYPEINFO_H

#if !defined( __CHECKS_H )
#include <checks.h>
#endif  // __CHECKS_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if !defined( __CLASSLIB_STREAMBL_H )
#include "classlib\streambl.h"
#endif  // __CLASSLIB_STREAMBL_H

#if !defined( __CLASSLIB_VECTIMP_H )
#include "classlib\vectimp.h"
#endif  // __CLASSLIB_VECTIMP_H

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
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

    virtual ~TStreamableBase();

#if defined( BI_NO_RTTI )
    typedef const char *Type_id;
    virtual void *FindBase( Type_id id ) const;

public:

    virtual Type_id CastableID() const = 0;
    virtual void *MostDerived() const = 0;
#endif  // BI_NO_RTTI

};

class _BIDSCLASS _RTTI TStreamable : public TStreamableBase
{

    friend class _BIDSCLASS _RTTI TOldStreamer;

protected:

    virtual const char *streamableName() const = 0;

    virtual void *read( ipstream& );
    virtual void write( opstream& );

#if defined( BI_NO_RTTI )
public:
    virtual void *FindBase( Type_id id ) const;
protected:
    virtual Type_id CastableID() const { return streamableName(); }
    virtual void *MostDerived() const { return 0; }
#endif
};

class _BIDSCLASS _RTTI TStreamer
{

    friend class ipstream;
    friend class opstream;

public:

    TStreamableBase *GetObject() const { return object; }

protected:

    TStreamer( TStreamableBase *obj ) : object(obj) {}

    virtual const char *StreamableName() const = 0;

    virtual void *Read( ipstream&, uint32 ) const = 0;
    virtual void Write( opstream& ) const = 0;

private:

    virtual uint32 ClassVersion() const = 0;

    TStreamableBase *object;

};

class _BIDSCLASS _RTTI TOldStreamer : public TStreamer
{

public:

    TOldStreamer( TStreamable *obj ) : TStreamer(obj) {};

protected:

    virtual const char *StreamableName() const
        {
        return STATIC_CAST(TStreamable *,GetObject())->streamableName();
        }

    virtual void *Read( ipstream& is, uint32 ) const
        {
        return STATIC_CAST(TStreamable *,GetObject())->read( is );
        }

    virtual void Write( opstream& os ) const
        {
        STATIC_CAST(TStreamable *,GetObject())->write( os );
        }

private:

    virtual uint32 ClassVersion() const
        {
        return 0;
        }

};

class _BIDSCLASS _RTTI TNewStreamer : public TStreamer
{

public:

    TNewStreamer( TStreamableBase *obj ) : TStreamer(obj) {};

protected:

    virtual const char *StreamableName() const
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

    void RemoveAll();

    class _BIDSCLASS TPWObj
    {

    public:

        TPWObj() : Address(0), Ident(0) {}
        TPWObj( const void *adr, P_id_type id ) : 
            Address(adr), Ident(id) {}

        friend int operator == ( const TPWObj& o1, const TPWObj& o2 )
            { return o1.Address == o2.Address; }

        friend int operator < ( const TPWObj& o1, const TPWObj& o2 )
            { return o1.Address < o2.Address; }

        const void *Address;
        P_id_type Ident;

    };

private:

    TPWrittenObjects();

    void RegisterObject( TStreamableBase *adr );
    void RegisterVB( const TStreamableBase *adr );
    P_id_type FindObject( TStreamableBase *adr );
    P_id_type FindVB( TStreamableBase *adr );

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

    void RemoveAll();

private:

    TPReadObjects();

    void RegisterObject( TStreamableBase *adr );
    TStreamableBase *Find( P_id_type id );

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

    _Cdecl pstream( streambuf _BIDSFAR * );
    virtual _Cdecl ~pstream();

    int _Cdecl rdstate() const;
    int _Cdecl eof() const;
    int _Cdecl fail() const;
    int _Cdecl bad() const;
    int _Cdecl good() const;
    void _Cdecl clear( int = 0 );
    _Cdecl operator void *() const;
    int _Cdecl operator ! () const;

    streambuf _BIDSFAR * _Cdecl rdbuf() const;

    static void initTypes();

    static void registerType( TStreamableClass *ts );

protected:

    _Cdecl pstream();

    streambuf _BIDSFAR *bp;
    int state;

    void _Cdecl init( streambuf _BIDSFAR * );
    void _Cdecl setstate( int );

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

    _Cdecl ipstream( streambuf _BIDSFAR * );

    streampos _Cdecl tellg();
    ipstream& _Cdecl seekg( streampos );
    ipstream& _Cdecl seekg( streamoff, ios::seek_dir );

    uint8 _Cdecl readByte();
    void _Cdecl readBytes( void _BIDSFAR *, size_t );
    void _Cdecl freadBytes( void _BIDSFARDATA *data, size_t sz );

    uint32 _Cdecl readWord();
    uint16 _Cdecl readWord16();
    uint32 _Cdecl readWord32();

    char _BIDSFAR * _Cdecl readString();
    char _BIDSFAR * _Cdecl readString( char _BIDSFAR *, unsigned );
    char _BIDSFARDATA *freadString();
    char _BIDSFARDATA *freadString( char _BIDSFARDATA *buf, unsigned maxLen );

    friend ipstream& _Cdecl operator >> ( ipstream&, signed char& );
    friend ipstream& _Cdecl operator >> ( ipstream&, unsigned char& );
    friend ipstream& _Cdecl operator >> ( ipstream&, char& );
    friend ipstream& _Cdecl operator >> ( ipstream&, signed short& );
    friend ipstream& _Cdecl operator >> ( ipstream&, unsigned short& );
    friend ipstream& _Cdecl operator >> ( ipstream&, signed int& );
    friend ipstream& _Cdecl operator >> ( ipstream&, unsigned int& );
    friend ipstream& _Cdecl operator >> ( ipstream&, signed long& );
    friend ipstream& _Cdecl operator >> ( ipstream&, unsigned long& );
    friend ipstream& _Cdecl operator >> ( ipstream&, float& );
    friend ipstream& _Cdecl operator >> ( ipstream&, double& );
    friend ipstream& _Cdecl operator >> ( ipstream&, long double& );

    uint32 getVersion() const;

    TStreamableBase _BIDSFAR *readObject( TStreamableBase _BIDSFAR *&mem, ModuleId mid = GetModuleId() );
    TStreamableBase _BIDSFAR *readObjectPointer( TStreamableBase _BIDSFAR *&mem, ModuleId mid = GetModuleId() );

    TStreamableBase _BIDSFAR * _Cdecl find( P_id_type );
    void _Cdecl registerObject( TStreamableBase _BIDSFAR *adr );

protected:

    _Cdecl ipstream();

    const ObjectBuilder _BIDSFAR * _Cdecl readPrefix( ModuleId mid );
    void _Cdecl readData( const ObjectBuilder _BIDSFAR *,
                          TStreamableBase _BIDSFAR *& );
    void _Cdecl readSuffix();

    void readVersion();

private:

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

    _Cdecl opstream( streambuf _BIDSFAR * );
    _Cdecl ~opstream();

    streampos _Cdecl tellp();
    opstream& _Cdecl seekp( streampos );
    opstream& _Cdecl seekp( streamoff, ios::seek_dir );
    opstream& _Cdecl flush();

    void _Cdecl writeByte( uint8 );
    void _Cdecl writeBytes( const void _BIDSFAR *, size_t );
    void _Cdecl fwriteBytes( const void _BIDSFARDATA *data, size_t sz );

    void _Cdecl writeWord( uint32 );
    void _Cdecl writeWord16( uint16 );
    void _Cdecl writeWord32( uint32 );

    void _Cdecl writeString( const char _BIDSFAR * );
    void _Cdecl fwriteString( const char _BIDSFARDATA * str );

    friend opstream& _Cdecl operator << ( opstream&, signed char );
    friend opstream& _Cdecl operator << ( opstream&, unsigned char );
    friend opstream& _Cdecl operator << ( opstream&, char );
    friend opstream& _Cdecl operator << ( opstream&, signed short );
    friend opstream& _Cdecl operator << ( opstream&, unsigned short );
    friend opstream& _Cdecl operator << ( opstream&, signed int );
    friend opstream& _Cdecl operator << ( opstream&, unsigned int );
    friend opstream& _Cdecl operator << ( opstream&, signed long );
    friend opstream& _Cdecl operator << ( opstream&, unsigned long );
    friend opstream& _Cdecl operator << ( opstream&, float );
    friend opstream& _Cdecl operator << ( opstream&, double );
    friend opstream& _Cdecl operator << ( opstream&, long double );

    void writeObject( const TStreamableBase _BIDSFAR *t, int isPtr = 0, ModuleId mid = GetModuleId() );
    void writeObjectPointer( const TStreamableBase _BIDSFAR *t, ModuleId mid = GetModuleId() );

    P_id_type _Cdecl findObject( TStreamableBase _BIDSFAR *adr );
    void _Cdecl registerObject( TStreamableBase _BIDSFAR *adr );

    P_id_type _Cdecl findVB( TStreamableBase _BIDSFAR *adr );
    void _Cdecl registerVB( TStreamableBase _BIDSFAR *adr );

protected:

    _Cdecl opstream();

    void _Cdecl writePrefix( const TStreamableBase _BIDSFAR * );
    void _Cdecl writeData( const TStreamableBase _BIDSFAR *, ModuleId mid );
    void _Cdecl writeSuffix( const TStreamableBase _BIDSFAR * );

private:

    void writeVersion();

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

    _Cdecl fpbase();
    _Cdecl fpbase( const char _BIDSFAR *, int, int = filebuf::openprot );
    _Cdecl fpbase( int );
    _Cdecl fpbase( int, char _BIDSFAR *, int );

    void _Cdecl open( const char _BIDSFAR *, int, int = filebuf::openprot );
    void _Cdecl attach( int );
    void _Cdecl close();
    void _Cdecl setbuf( char _BIDSFAR *, int );
    filebuf _BIDSFAR * _Cdecl rdbuf();

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

    _Cdecl ifpstream();
    _Cdecl ifpstream( const char _BIDSFAR *,
                      int = ios::in,
                      int = filebuf::openprot
                    );
    _Cdecl ifpstream( int );
    _Cdecl ifpstream( int, char _BIDSFAR *, int );

    filebuf _BIDSFAR * _Cdecl rdbuf();
    void _Cdecl open( const char _BIDSFAR *,
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

    _Cdecl ofpstream();
    _Cdecl ofpstream( const char _BIDSFAR *,
                      int = ios::out,
                      int = filebuf::openprot
                    );
    _Cdecl ofpstream( int );
    _Cdecl ofpstream( int, char _BIDSFAR *, int );

    filebuf _BIDSFAR * _Cdecl rdbuf();
    void _Cdecl open( const char _BIDSFAR *,
                      int = ios::out,
                      int = filebuf::openprot
                    );

};

/* ------------------------------------------------------------------------*/
/*                                                                         */
/*   Inline functions                                                      */
/*                                                                         */
/* ------------------------------------------------------------------------*/

inline pstream::pstream( streambuf _BIDSFAR *sb )
{
    init( sb );
}

inline int pstream::rdstate() const
{
    return state;
}

inline int pstream::eof() const
{
    return state & ios::eofbit;
}

inline int pstream::fail() const
{
    return state & (ios::failbit | ios::badbit | ios::hardfail);
}

inline int pstream::bad() const
{
    return state & (ios::badbit | ios::hardfail);
}

inline int pstream::good() const
{
    return state == 0;
}

inline void pstream::clear( int i )
{
    state = (i & 0xFF) | (state & ios::hardfail);
}

inline pstream::operator void _BIDSFAR *() const
{
    return fail() ? 0 : (void *)this;
}

inline int pstream::operator! () const
{
    return fail();
}

inline streambuf _BIDSFAR * pstream::rdbuf() const
{
    return bp;
}

inline pstream::pstream()
{
}

inline void pstream::init( streambuf *sbp )
{
    state = 0;
    bp = sbp;
}

inline void pstream::setstate( int b )
{
    state |= (b&0xFF);
}

inline ipstream::ipstream( streambuf _BIDSFAR *sb )
{
    pstream::init( sb );
    readVersion();
}

inline ipstream::ipstream()
{
    if( bp != 0 )
        readVersion();
}

inline TStreamableBase *ipstream::find( P_id_type id )
{
    return objs.Find( id );
}

inline void ipstream::registerObject( TStreamableBase *adr )
{
    objs.RegisterObject( adr );
}

inline uint32 ipstream::getVersion() const
{
    return version;
}

inline void pstream::registerType( TStreamableClass *ts )
{
    types->RegisterType( GetModuleId(), *ts );
}

inline opstream::~opstream()
{
    delete objs;
}

inline void opstream::writeWord( uint32 word32 )
{
    writeWord32( word32 );
}

inline void opstream::writeSuffix( const TStreamableBase * )
{
    writeByte( ']' );
}

inline P_id_type opstream::findObject( TStreamableBase *adr )
{
    return objs->FindObject( adr );
}

inline void opstream::registerObject( TStreamableBase *adr )
{
    objs->RegisterObject( adr );
}

inline P_id_type opstream::findVB( TStreamableBase *adr )
{
    return objs->FindVB( adr );
}

inline void opstream::registerVB( TStreamableBase *adr )
{
    objs->RegisterVB( adr );
}

inline fpbase::fpbase()
{
    pstream::init( &buf );
}

inline fpbase::fpbase( const char *name, int omode, int prot )
{
    pstream::init( &buf );
    open( name, omode, prot );
}

inline fpbase::fpbase( int f ) : buf( f )
{
    pstream::init( &buf );
}

inline fpbase::fpbase( int f, char *b, int len ) : buf( f, b, len )
{
    pstream::init( &buf );
}

inline filebuf *fpbase::rdbuf()
{
    return &buf;
}

inline ifpstream::ifpstream()
{
}

inline ifpstream::ifpstream( const char* name, int omode, int prot ) :
    fpbase( name, omode | ios::in | ios::binary, prot )
{
}

inline ifpstream::ifpstream( int f ) : fpbase( f )
{
}

inline ifpstream::ifpstream(int f, char* b, int len) : fpbase(f, b, len)
{
}

inline filebuf *ifpstream::rdbuf()
{
    return fpbase::rdbuf();
}

inline void ifpstream::open( const char _BIDSFAR *name, int omode, int prot )
{
    fpbase::open( name, omode | ios::in | ios::binary, prot );
    readVersion();
}

inline ofpstream::ofpstream()
{
}

inline ofpstream::ofpstream( const char* name, int omode, int prot ) :
    fpbase( name, omode | ios::out | ios::binary, prot )
{
}

inline ofpstream::ofpstream( int f ) : fpbase( f )
{
}

inline ofpstream::ofpstream(int f, char* b, int len) : fpbase(f, b, len)
{
}

inline filebuf *ofpstream::rdbuf()
{
    return fpbase::rdbuf();
}

inline void ofpstream::open( const char _BIDSFAR *name, int omode, int prot )
{
    fpbase::open( name, omode | ios::out | ios::binary, prot );
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, signed char &ch )
{
    ch = ps.readByte();
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, unsigned char &ch )
{
    ch = ps.readByte();
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, char &ch )
{
    ch = ps.readByte();
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, signed short &sh )
{
    sh = ps.readWord16();
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, unsigned short &sh )
{
    sh = ps.readWord16();
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, signed int &i )
{
    i = (int)(ps.readWord32());
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, unsigned int &i )
{
    i = (unsigned int)(ps.readWord32());
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, signed long &l )
{
    ps.readBytes( &l, sizeof(l) );
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, unsigned long &l )
{
    ps.readBytes( &l, sizeof(l) );
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, float &f )
{
    ps.readBytes( &f, sizeof(f) );
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, double &d )
{
    ps.readBytes( &d, sizeof(d) );
    return ps;
}

inline ipstream& _Cdecl operator >> ( ipstream& ps, long double &l )
{
    ps.readBytes( &l, sizeof(l) );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, signed char ch )
{
    ps.writeByte( ch );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, unsigned char ch )
{
    ps.writeByte( ch );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, char ch )
{
    ps.writeByte( ch );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, signed short sh )
{
    ps.writeWord16( sh );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, unsigned short sh )
{
    ps.writeWord16( sh );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, signed int i )
{
    ps.writeWord32( i );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, unsigned int i )
{
    ps.writeWord32( i );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, signed long l )
{
    ps.writeBytes( &l, sizeof(l) );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, unsigned long l )
{
    ps.writeBytes( &l, sizeof(l) );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, float f )
{
    ps.writeBytes( &f, sizeof(f) );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, double d )
{
    ps.writeBytes( &d, sizeof(d) );
    return ps;
}

inline opstream& _Cdecl operator << ( opstream& ps, long double l )
{
    ps.writeBytes( &l, sizeof(l) );
    return ps;
}

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

/*  Individual Components for Streamable Declarations */

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

#if defined( BI_NO_RTTI )
#define DECLARE_CASTABLE                                            \
public:                                                             \
    virtual void *FindBase( Type_id id ) const;                     \
public:                                                             \
    virtual Type_id CastableID() const;                             \
    virtual void *MostDerived() const { return (void *)this; }      \
    static Type_id CastableIdent
#else
#define DECLARE_CASTABLE friend class Type_info
#endif

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

#if defined( BI_NO_RTTI )
#   define IMPLEMENT_STREAMABLE_CLASS( cls )    \
    TStreamableClass r ## cls( cls::CastableIdent, &cls::Streamer::Build )
#else
#   define IMPLEMENT_STREAMABLE_CLASS( cls )    \
    TStreamableClass r ## cls( typeid(cls).name(), &cls::Streamer::Build )
#endif

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

#define IMPLEMENT_STREAMER( cls )                                             \
cls::Streamer::Streamer( TStreamableBase *obj ) :                   \
    TNewStreamer(obj), object(TYPESAFE_DOWNCAST(obj,cls)){}
                                                                    \
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

/*  Standard Combinations of Streamable Implementations */

#define IMPLEMENT_ABSTRACT_STREAMABLE( cls )                        \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR( cls );                                   \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE1( cls, base1 )                \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR1( cls, base1 );                           \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE2( cls, base1, base2 )         \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR2( cls, base1, base2 );                    \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE3( cls, base1, base2, base3 )  \
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR3( cls, base1, base2, base3 );             \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE4( cls, base1, base2, base3, base4 )\
IMPLEMENT_STREAMER( cls );                                          \
IMPLEMENT_STREAMABLE_CTOR4( cls, base1, base2, base3, base4 );      \
IMPLEMENT_STREAMABLE_POINTER( cls )

#define IMPLEMENT_ABSTRACT_STREAMABLE5( cls, base1, base2, base3, base4, base5 )\
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

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#endif  // __CLASSLIB_OBJSTRM_H

