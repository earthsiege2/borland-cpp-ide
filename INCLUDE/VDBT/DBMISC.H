//--------------------------------------------------------
// DBMISC.H
// Copyrights (C) 1996 Borland International
// All Rights Reserved
//--------------------------------------------------------

#if !defined(DBMISC_H_)
#define DBMISC_H_

#include <owl/vbxctl.h>
#include <vdbt/bdto.h>


//------------------------------------------------------------------------------
// Foreward Declarations
//------------------------------------------------------------------------------
extern TDataSource* PASCAL GetSource( TVbxControl*, LPCSTR, TDataSource* );
extern TDataSource* PASCAL SetSource( TVbxControl*, LPCSTR, TDataSource* );
extern TField*      PASCAL GetField( TVbxControl*, int, TDataSource*, TField* );
extern TField*      PASCAL SetField( TVbxControl*, int, TField* );
extern TStrings*    PASCAL GetStrings( TVbxControl*, int, TStrings* );
extern TStrings*    PASCAL SetStrings( TVbxControl*, int, TStrings* );
extern string*      PASCAL Getstring( TVbxControl*, int, string* );
extern string*      PASCAL Setstring( TVbxControl*, int, string* );
extern void         PASCAL ThrowException( LPCSTR );
extern bool         DBEqualOperator( TGenericTableEntry __RTFAR&
                                         , TEventHandler::TEventInfo&);
extern "C"  extern FAR PASCAL HCTL VBGetDataSourceControl( HCTL, BOOL* );
extern "C"  extern FAR PASCAL HCTL VBXFindControl( HWND, LPCSTR );


//------------------------------------------------------------------------------

#ifdef __FLAT__
#  define Debug( x ) { char Msg[ 128 ]; wsprintf x; \
                       ::MessageBox( 0, Msg, "Debug", MB_OK ); }
#else
#  define Debug( x ) { char Msg[ 128 ]; wsprintf x; OutputDebugString( Msg ); }
#endif

#define DEFINE_DB_RESPONSE_TABLE1(cls, base)                  \
bool  cls::Find( TEventInfo& eventInfo, TEqualOperator equal )\
{                                                             \
  eventInfo.Object = (GENERIC*)this;                          \
  return SearchEntries( (TGenericTableEntry __RTFAR*)__entries\
                      , eventInfo, ::DBEqualOperator )        \
      || base::Find( eventInfo, equal );                      \
}                                                             \
DEFINE_RESPONSE_TABLE_ENTRIES(cls)


#define DECLARE_CONSTRUCTORS( TDBClass )                                \
  public:                                                               \
    TDBClass( TWindow*, int, LPCSTR, int, int, int, int, TModule*x=0 ); \
    TDBClass( TWindow*, int, TModule*x=0 )

#define DEFINE_DB_PROP_STRING( cls, name )                          \
inline string* cls::pr##name::Set()                                 \
{                                                                   \
  return p = ::Setstring( DBOUTER( name ), Prop_##cls##_##name, p );\
}                                                                   \
inline string* cls::pr##name::Get()                                 \
{                                                                   \
  return p = ::Getstring( DBOUTER( name ), Prop_##cls##_##name, p );\
}

#define DEFINE_DB_PROP_SOURCE( cls, name )            \
inline TDataSource* cls::pr##name::Set()              \
{                                                     \
  return p = ::SetSource( DBOUTER( name ), #name, p );\
}                                                     \
inline TDataSource* cls::pr##name::Get()              \
{                                                     \
  return p = ::GetSource( DBOUTER( name ), #name, p );\
}

#define DEFINE_DB_PROP_DATASOURCE( cls ) \
        DEFINE_DB_PROP_SOURCE( cls, DataSource )

#define DEFINE_DB_PROP_LOOKUPSOURCE( cls ) \
        DEFINE_DB_PROP_SOURCE( cls, LookupSource )

#define DEFINE_DB_PROP_FIELD( cls, name )                                      \
inline TField* cls::pr##name##Field::Get()                                     \
{                                                                              \
  cls *c = DBOUTER( name##Field );                                             \
                                                                               \
  return p = ::GetField( c, Prop_##cls##_##name##Field, c->##name##Source, p );\
}                                                                              \
inline TField* cls::pr##name##Field::Set()                                     \
{                                                                              \
  return p = ::SetField( DBOUTER( name##Field ), Prop_##cls##_##name##Field, p );\
}

#define DEFINE_DB_PROP_DATAFIELD( cls )   DEFINE_DB_PROP_FIELD( cls, Data )
#define DEFINE_DB_PROP_LOOKUPFIELD( cls ) DEFINE_DB_PROP_FIELD( cls, Lookup )


//----------------------------------------------------------------------------
#define DECLARE_DB_PROP_RWS( cls, name )                                     \
  public:                                                                    \
    struct _DBAWARECLASS pr##name : TDBPropertyRwx< TStrings >               \
    {                                                                        \
      pr##name()                                                             \
      : OnChangeSink( TStringsNotify_MFUNCTOR( *this, &pr##name::OnChange ) )\
      {                                                                      \
      }                                                                      \
                                                                             \
      struct pr##name& operator=( struct pr##name& arg )                     \
      {                                                                      \
        *this = (TStrings*)arg;                                              \
        return *this;                                                        \
      }                                                                      \
      TStrings* operator=( TStrings* arg )                                   \
      {                                                                      \
        return TDBPropertyRwx< TStrings >::operator=( arg );                 \
      }                                                                      \
      TStrings& operator=( TStrings& arg )                                   \
      {                                                                      \
        return TDBPropertyRwx<TStrings>::operator=( arg );                   \
      }                                                                      \
      TStrings* Get();                                                       \
      TStrings* Set();                                                       \
                                                                             \
      void OnChange( TStringsNotifySink& sink, TStrings& sender )            \
      {                                                                      \
        *this = &sender;                                                     \
        sink.Pass( sender );                                                 \
      }                                                                      \
                                                                             \
      TStringsNotifySink OnChangeSink;                                       \
    } name;                                                                  \
    friend struct pr##name

#define DEFINE_DB_PROP_TSTRINGS( cls, name )                                 \
inline TStrings* cls::pr##name::Get()                                        \
{                                                                            \
  if( p )                                                                    \
    p->OnChangeSource -= OnChangeSink;                                       \
  if( (p = ::GetStrings( DBOUTER( name ), Prop_##cls##_##name, p )) != NULL )\
    p->OnChangeSource += OnChangeSink;                                       \
  return p;                                                                  \
}                                                                            \
inline TStrings* cls::pr##name::Set()                                        \
{                                                                            \
  if( p )                                                                    \
    p->OnChangeSource -= OnChangeSink;                                       \
  if( (p = ::SetStrings( DBOUTER( name ), Prop_##cls##_##name, p )) != NULL )\
    p->OnChangeSource += OnChangeSink;                                       \
  return p;                                                                  \
}

#endif DBMISC_H_
