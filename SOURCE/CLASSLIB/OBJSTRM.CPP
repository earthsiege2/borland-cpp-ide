/*------------------------------------------------------------------------*/
/*                                                                        */
/*  OBJSTRM.CPP                                                           */
/*                                                                        */
/*  Copyright (c) 1992, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( _Windows )
#define _Windows
#endif

#if !defined( __ALLOC_H )
#include <alloc.h>
#endif

#if !defined( __CHECKS_H )
#include <checks.h>
#endif

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif

#if !defined( CLASSLIB_STREAMBL_H )
#include <classlib/streambl.h>
#endif

#if !defined( CLASSLIB_OBJSTRM_H )
#include <classlib/objstrm.h>
#endif

#if defined( __FLAT__ )
#define _fstrncpy strncpy
#define _fstrcpy  strcpy
#define _fstrlen  strlen
#define _fmemcpy  memcpy
#define farmalloc malloc
#endif

DIAG_DEFINE_GROUP(Objstrm,1,0);

const uint32 streamVersion = 0x0101;
const char versionIndicator = ':';

const char EOS = '\0';

const uint8  oldNullStringLen = UCHAR_MAX;
const uint32 nullStringLen = ULONG_MAX;

TStreamableTypes *pstream::types = 0;

const char *TStreamer::StreamableName() const
{
    return 0;
}

TStreamableClass::TStreamableClass( const char *n,
                                    BUILDER b,
                                    int d,
                                    ModuleId id ) :
    ObjectBuilder( b, d ),
    ModId(id)
{
    ObjectId = new char[strlen(n)+1];
    strcpy( CONST_CAST(char *,ObjectId), n );
    pstream::initTypes();
    if( id != 0 )   // id == 0 is used only during lookup.
                    // It flags an instance that shouldn't be registered
        pstream::types->RegisterType( id, *this );
}

TStreamableClass::~TStreamableClass()
{
    if( ModId != 0 )
        pstream::types->UnRegisterType( ModId, *this );

    delete [] CONST_CAST(char *,ObjectId);
}

void TStreamableTypes::RegisterType( ModuleId, TStreamableClass& ts )
{
    Types.Add(&ts);
}

void TStreamableTypes::UnRegisterType( ModuleId, TStreamableClass& ts )
{
    Types.Detach(&ts);
    if( Types.Count() == 0 )
        pstream::releaseTypes();
}

const ObjectBuilder *TStreamableTypes::Lookup( ModuleId,
                                               const char *name ) const
{
    unsigned loc = Types.Find(&TStreamableClass(name,0,0,0));
    if( loc == UINT_MAX )
        {
        string msg;
        msg.reserve(128);
        msg = "Attempt to stream unregistered type '";
        msg += name;
        msg += "'";
        throw xmsg(msg);
        }
    return Types[loc];
}

void TPReadObjects::RemoveAll()
{
    Data.Flush();
}

void TPReadObjects::RegisterObject( TStreamableBase *adr )
{
    Data.Add( adr );
}

TStreamableBase *TPReadObjects::Find( P_id_type id )
{
    return Data[id];
}

TPReadObjects::TPReadObjects() : Data(5,5)
{
    Data.Add(0);    // prime it: 0 is not a legal index.
}

TPWrittenObjects::TPWrittenObjects() : CurId(0), Data(5,5)
{
}

void TPWrittenObjects::RemoveAll()
{
    CurId = 0; Data.Flush();
}

void TPWrittenObjects::RegisterObject( TStreamableBase *adr )
{
    Data.Add( TPWObj( ((char *)(void *)adr)+1, ++CurId ) );
}

void TPWrittenObjects::RegisterVB( const TStreamableBase *adr )
{
    Data.Add( TPWObj( adr, ++CurId ) );
}

P_id_type TPWrittenObjects::FindObject( TStreamableBase *d )
{
    unsigned res = Data.Find( TPWObj(((char *)(void *)d)+1,0) );
    if( res == UINT_MAX )
        return 0;
    else
        return Data[res].Ident;
}

P_id_type TPWrittenObjects::FindVB( TStreamableBase *d )
{
    unsigned res = Data.Find( TPWObj(d,0) );
    if( res == UINT_MAX )
        return 0;
    else
        return Data[res].Ident;
}

pstream::~pstream()
{
}

void pstream::initTypes()
{
    if( types == 0 )
        types = new TStreamableTypes;
}

void pstream::releaseTypes()
{
    delete types;
    types = 0;
}

streampos ipstream::tellg()
{
    streampos res;
    if( !good() )
        res = streampos(EOF);
    else
        {
        res = bp->seekoff( 0, ios::cur, ios::in );
        if( res == streampos(EOF) )
            clear( ios::failbit );
        }
    return res;
}

ipstream& ipstream::seekg( streampos pos )
{
    if( good() )
        {
        objs.RemoveAll();
        if( bp->seekoff( pos, ios::beg, ios::in ) == streampos(EOF) )
            clear( ios::failbit );
        }
    return *this;
}

ipstream& ipstream::seekg( streamoff off, ios::seek_dir dir )
{
    if( good() )
        {
        objs.RemoveAll();
        if( bp->seekoff( off, dir, ios::in ) == streampos(EOF) )
            clear( ios::failbit );
        }
    return *this;
}

uint8 ipstream::readByte()
{
    int res;
    if( !good() )
        res = uint8(0);
    else
        {
        res = bp->sbumpc();
        if( res == EOF )
            clear( ios::failbit );
        }
    return uint8(res);
}

void ipstream::readBytes( void *data, size_t sz )
{
    PRECONDITION( data != 0 );
    if( good() && sz > 0 )
        {
        if( bp->sgetn( (char *)data, sz ) != sz )
            clear( ios::failbit );
        }
}

void ipstream::freadBytes( void _BIDSFARDATA *data, size_t sz )
{
    PRECONDITION( data != 0 );

    if( good() && sz > 0 )
        {
        char *buf = new char[sz];

        if( bp->sgetn( buf, sz ) != sz )
            clear( ios::failbit );
        else
            _fmemcpy( data, buf, sz);

        delete [] buf;
        }
}

uint32 ipstream::readWord()
{
    if( getVersion() > 0 )
        return readWord32();
    else
        return readWord16();
}

uint16 ipstream::readWord16()
{
    if( !good() )
        return 0;
    else
        {
        uint16 temp;
        if( bp->sgetn( (char *)&temp, sizeof( temp ) ) != sizeof( temp ) )
            clear( ios::failbit );
        return temp;
        }
}

uint32 ipstream::readWord32()
{
    if( !good() )
        return 0;
    else
        {
        uint32 temp;
        if( bp->sgetn( (char *)&temp, sizeof( temp ) ) != sizeof( temp ) )
            clear( ios::failbit );
        return temp;
        }
}

uint32 ipstream::readStringLength()
{
    uint32 len;
    if( getVersion() > 0x0100 )
        {
        len = readWord32();
        }
    else
        {
        len = readByte();
        if( len == oldNullStringLen )
            len = nullStringLen;
        }
    return len;
}

char *ipstream::readString()
{
    if( !good() )
        return 0;
    else
        {
        uint32 len = readStringLength();
        if( len == nullStringLen )
            return 0;

        char *buf = new char[len+1];
        if( buf == 0 )
            return 0;
        readBytes( buf, len );
        buf[len] = EOS;
        return buf;
        }
}

char *ipstream::readString( char *buf, unsigned maxLen )
{
    PRECONDITION( buf != 0 );

    if( !good() )
        return 0;
    else
        {
        uint32 len = readStringLength();
        if( len == nullStringLen || len > maxLen-1 )
            return 0;
        readBytes( buf, len );
        buf[len] = EOS;
        return buf;
        }
}

char _BIDSFARDATA *ipstream::freadString()
{
    if( !good() )
        return 0;
    else
        {
        uint32 len = readStringLength();
        if( len == nullStringLen )
            return 0;

        char _BIDSFARDATA *buf = new _BIDSFARDATA char[len+1];
        freadBytes(buf, len);
        buf[len] = EOS;
        return buf;
        }
}

char _BIDSFARDATA *ipstream::freadString( char _BIDSFARDATA *buf, unsigned maxLen )
{
    PRECONDITION(buf != 0 );

    if( !good() )
        return 0;
    else
        {
        uint32 len = readStringLength();
        if( len == nullStringLen || len > maxLen-1 )
            return 0;

        freadBytes( buf, len);
        buf[len] = EOS;
        return buf;
        }
}

void ipstream::readVersion()
{
    if( !good() )
        version = 0;
    else
        {
        int res = bp->sgetc();
        if( res == EOF )
            {
            clear( ios::eofbit );
            version = 0;
            return;
            }
        if( res != versionIndicator )
            version = 0;
        else
            {
            bp->sbumpc();
            version = readWord32();
            }
        }
}

TStreamableBase _FAR *ipstream::readObject( TStreamableBase _FAR *&mem,
                                            ModuleId mid )
{
    if( good() )
        {
        const ObjectBuilder *pc = readPrefix( mid );
        if( pc == 0 )
            mem = 0;
        else
            {
            readData( pc, mem );
            readSuffix();
            }
        }
    return mem;
}

const ObjectBuilder *ipstream::readPrefix( ModuleId mid )
{
    char ch = readByte();
    if( ch != '[' )
        {
        clear( ios::failbit );
        return 0;
        }

    char name[128];
    name[0] = EOS;
    readString( name, sizeof name );
    if( name[0] == EOS )
        {
        clear( ios::failbit );
        return 0;
        }

    TRACEX(Objstrm,0,"Reading " << name);
    const ObjectBuilder *res = types->Lookup( mid, name );
    WARNX(Objstrm,res==0,0,"Unrecognized class identifier: " << name);
    if( res == 0 )
        {
        clear( ios::failbit );
        return 0;
        }

    return res;
}

void ipstream::readData( const ObjectBuilder *c, TStreamableBase _FAR *&mem )
{
    TStreamer *strmr = c->Builder(mem);
    mem = strmr->GetObject();

    // register the address
    registerObject( mem );

    uint32 classVer = 0;
    if( getVersion() > 0 )
        classVer = readWord32();

    strmr->Read( *this, classVer );
    delete strmr;
}

void ipstream::readSuffix()
{
    if( !good() )
        return;
    char ch = readByte();
    if( ch != ']' )
        clear( ios::failbit );
}

TStreamableBase _FAR *ipstream::readObjectPointer( TStreamableBase _FAR *&mem,
                                                   ModuleId mid )
{
    if( !good() )
        return 0;

    char ch = readByte();
    switch( ch )
        {
        case pstream::ptNull:
            mem = 0;
            break;
        case pstream::ptIndexed:
            {
            P_id_type index = P_id_type(readWord());
            mem = find( index );
            CHECK( mem != 0 );
            break;
            }
        case pstream::ptObject:
            {
            const ObjectBuilder *pc = readPrefix( mid );
            readData( pc, mem );
            readSuffix();
            break;
            }
        default:
            clear( ios::failbit );
            break;
        }
    return mem;
}

opstream::opstream()
{
    objs = new TPWrittenObjects;
    if( bp != 0 )
        writeVersion();
}

opstream::opstream( streambuf * sb )
{
    objs = new TPWrittenObjects;
    pstream::init( sb );
    writeVersion();
}

streampos opstream::tellp()
{
    streampos res;
    if( !good() )
        res = streampos(EOF);
    else
        {
        res = bp->seekoff( 0, ios::cur, ios::out );
        if( res == streampos(EOF) )
            clear( ios::failbit );
        }
    return res;
}

opstream& opstream::seekp( streampos pos )
{
    if( good() )
        {
        objs->RemoveAll();
        if( bp->seekoff( pos, ios::beg, ios::out ) == streampos(EOF) )
            clear( ios::failbit );
        }
    return *this;
}

opstream& opstream::seekp( streamoff pos, ios::seek_dir dir )
{
    if( good() )
        {
        objs->RemoveAll();
        if( bp->seekoff( pos, dir, ios::out ) == streampos(EOF) )
            clear( ios::failbit );
        }
    return *this;
}

void opstream::writeVersion()
{
    if( good() )
        {
        writeByte( versionIndicator );
        writeWord32( streamVersion );
        }
}

opstream& opstream::flush()
{
    if( bp->sync() == EOF )
        clear( ios::badbit );
    return *this;
}

void opstream::writeByte( uint8 ch )
{
    if( good() )
        {
        if( bp->sputc( ch ) == EOF )
            clear( ios::failbit );
        }
}

void opstream::writeBytes( const void *data, size_t sz )
{
    PRECONDITION( data != 0 );

    if( good() && sz > 0 )
        {
        if( bp->sputn( (char *)data, sz ) != sz )
            clear( ios::failbit );
        }
}

void opstream::writeWord16( uint16 word16 )
{
    if( good() )
        {
        if( bp->sputn( (char *)&word16, sizeof(word16) ) != sizeof(word16) )
            clear( ios::failbit );
        }
}

void opstream::writeWord32( uint32 word32 )
{
    if( good() )
        {
        if( bp->sputn( (char *)&word32, sizeof(word32) ) != sizeof(word32) )
            clear( ios::failbit );
        }
}

void opstream::fwriteBytes( const void _BIDSFARDATA *data, size_t sz )
{
    PRECONDITION( data != 0 );

    if( good() && sz > 0 )
        {
        char *buf = new char[sz];

        _fmemcpy( buf, data, sz );
        if( bp->sputn( (char *)buf, sz ) != sz )
            clear( ios::failbit );

        delete buf;
        }
}

void opstream::writeString( const char *str )
{
    if( !good() )
        return;

    if( str == 0 )
        {
        writeWord32( nullStringLen );
        return;
        }
    size_t len = strlen( str );
    writeWord32( len );
    writeBytes( str, len );
}

void opstream::fwriteString( const char _BIDSFARDATA * str )
{
    if( !good() )
        return;

    if( str == 0 )
        {
        writeWord32( nullStringLen );
        return;
        }
    size_t len = _fstrlen( str );
    writeWord32( len );
    fwriteBytes(str, len);
}

#pragma warn -par
void opstream::writeObject( const TStreamableBase _FAR *mem, int isPtr, ModuleId mid )
{
    WARNX(Objstrm,
          !isPtr && findObject( CONST_CAST(TStreamableBase *,mem) ),
          0,
          "Pointer written before object: "     \
              << _TYPENAME(mem) << '(' << (void _FAR *)mem << ')' );
    if( good() )
        {
        writePrefix( mem );
        writeData( mem, mid );
        writeSuffix( mem );
        }
}
#pragma warn +par

void opstream::writeObjectPointer( const TStreamableBase *t, ModuleId mid )
{
    if( good() )
        {
        P_id_type index;
        if( t == 0 )
            writeByte( pstream::ptNull );
        else if( (index = findObject( CONST_CAST(TStreamableBase *,t) )) != 0 )
            {
            writeByte( pstream::ptIndexed );
            writeWord( index );
            }
        else
            {
            writeByte( pstream::ptObject );
            writeObject( t, 1, mid );
            }
        }
}

void opstream::writePrefix( const TStreamableBase *t )
{
    if( good() )
        {
        writeByte( '[' );
        writeString( _TYPENAME(t) );
        }
}

void opstream::writeData( const TStreamableBase *t, ModuleId mid )
{
    if( good() )
        {
        registerObject( CONST_CAST(TStreamableBase *,t) );
        const ObjectBuilder *res = types->Lookup( mid, _TYPENAME(t) );
        CHECKX(res,_TYPENAME(t));
        TStreamer *strmr = res->Builder(CONST_CAST(TStreamableBase *,t));
        writeWord32( strmr->ClassVersion() );
        strmr->Write( *this );
        delete strmr;
        }
}

void fpbase::open( const char *b, int m, int prot )
{
    if( buf.is_open() )
        clear(ios::failbit);        // fail - already open
    else if( buf.open(b, m, prot) )
        clear(ios::goodbit);        // successful open
    else
        clear(ios::badbit);         // open failed
}

void fpbase::attach( int f )
{
    if( buf.is_open() )
        clear(ios::failbit);
    else if( buf.attach(f) )
        clear(ios::goodbit);
    else
        clear(ios::badbit);
}

void fpbase::close()
{
    if( buf.close() )
        clear(ios::goodbit);
    else
        clear(ios::failbit);
}

void fpbase::setbuf(char* b, int len)
{
    if( buf.setbuf(b, len) )
        clear(ios::goodbit);
    else
        clear(ios::failbit);
}

//
//  These operators are not friends of string, so
//  they must use only the public interface.
//
opstream _BIDSFAR& _BIDSENTRY _BIDSFUNC operator << ( opstream _BIDSFAR& os,
                                                      const string _BIDSFAR& str )
{
    os.writeString( str.c_str() );
    return os;
}

ipstream _BIDSFAR& _BIDSENTRY _BIDSFUNC operator >> ( ipstream _BIDSFAR& is,
                                                      string _BIDSFAR& str )
{
    if( is.good() )
        {
        uint32 len = is.readStringLength();
        if( len == nullStringLen )
            str = "";
        else
            {
            char *temp = new char[len+1];
            is.readBytes( temp, len );
            temp[len] = EOS;
            str = temp;
            delete [] temp;
            }
        }
    return is;
}


