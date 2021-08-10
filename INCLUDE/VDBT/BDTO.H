//--------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// Definition of database access classes.
//--------------------------------------------------------------------------

#if !defined(BDTO_H)
#define BDTO_H

# define _BDTOCLASS
#if defined(__FLAT__)
# define _BDTOCALLBACK _pascal
#else
# define _BDTOCALLBACK _far _pascal
#endif

#if defined(__FLAT__)
# define INC_OLE2
# include <windows.h>
#else
# include <windows.h>
# include <ole2.h>
# include <dispatch.h>
#endif // __FLAT__

#include <systypes.h>
#include <cstring.h>

#if !defined(_BUILDBDTOLIB)
# define NOBDTCPROGIDS
# define NOBDTCFUNCTIONS
#endif
#define NOBDTCFORCEEXCEPTIONS
#include <vdbt\bdtc.h>

#include <vdbt\bdte.h>

class _BDTOCLASS TBDTObject; typedef TBDTObject far* PTBDTObject;
class _BDTOCLASS TBDTComponent; typedef TBDTComponent far* PTBDTComponent;
class _BDTOCLASS TStrings; typedef TStrings far* PTStrings;
class _BDTOCLASS TSession; typedef TSession far* PTSession;
class _BDTOCLASS TDatabase; typedef TDatabase far* PTDatabase;
class _BDTOCLASS TFieldDef; typedef TFieldDef far* PTFieldDef;
class _BDTOCLASS TFieldDefs; typedef TFieldDefs far* PTFieldDefs;
class _BDTOCLASS TDataSet; typedef TDataSet far* PTDataSet;
class _BDTOCLASS TDBDataSet; typedef TDBDataSet far* PTDBDataSet;
class _BDTOCLASS TDataSource; typedef TDataSource far* PTDataSource;
class _BDTOCLASS TIndexDef; typedef TIndexDef far* PTIndexDef;
class _BDTOCLASS TIndexDefs; typedef TIndexDefs far* PTIndexDefs;
class _BDTOCLASS TTable; typedef TTable far* PTTable;
class _BDTOCLASS TBatchMove; typedef TBatchMove far* PTBatchMove;
class _BDTOCLASS TParam; typedef TParam far* PTParam;
class _BDTOCLASS TParams; typedef TParams far* PTParams;
class _BDTOCLASS TStoredProc; typedef TStoredProc far* PTStoredProc;
class _BDTOCLASS TQuery; typedef TQuery far* PTQuery;
class _BDTOCLASS TMemoryStream; typedef TMemoryStream far* PTMemoryStream;
class _BDTOCLASS TField; typedef TField far* PTField;
class _BDTOCLASS TStringField; typedef TStringField far* PTStringField;
class _BDTOCLASS TNumericField; typedef TNumericField far* PTNumericField;
class _BDTOCLASS TIntegerField; typedef TIntegerField far* PTIntegerField;
class _BDTOCLASS TSmallintField; typedef TSmallintField far* PTSmallintField;
class _BDTOCLASS TWordField; typedef TWordField far* PTWordField;
class _BDTOCLASS TFloatField; typedef TFloatField far* PTFloatField;
class _BDTOCLASS TCurrencyField; typedef TCurrencyField far* PTCurrencyField;
class _BDTOCLASS TBCDField; typedef TBCDField far* PTBCDField;
class _BDTOCLASS TBooleanField; typedef TBooleanField far* PTBooleanField;
class _BDTOCLASS TDateTimeField; typedef TDateTimeField far* PTDateTimeField;
class _BDTOCLASS TDateField; typedef TDateField far* PTDateField;
class _BDTOCLASS TTimeField; typedef TTimeField far* PTTimeField;
class _BDTOCLASS TBytesField; typedef TBytesField far* PTBytesField;
class _BDTOCLASS TVarBytesField; typedef TVarBytesField far* PTVarBytesField;
class _BDTOCLASS TBlobField; typedef TBlobField far* PTBlobField;
class _BDTOCLASS TMemoField; typedef TMemoField far* PTMemoField;
class _BDTOCLASS TGraphicField; typedef TGraphicField far* PTGraphicField;
class _BDTOCLASS TVarRec; typedef TVarRec far* PTVarRec;
class _BDTOCLASS TVarRecs; typedef TVarRecs far* PTVarRecs;

#define BDTOCLASS( x )                                                        \
  public:                                                                     \
    typedef x ThisBDTOClass, * pThisBDTOClass

#define ARRAYCLASS( x )                                                       \
  public:                                                                     \
    typedef x ThisArrayClass, * pThisArrayClass

// macros for read only properties which return a simple type

#define DECLARE_BDTO_PROP_RO( type, name )                                    \
  public:                                                                     \
    void Get##name( type& );                                                  \
    class _BDTOCLASS prop##name                                               \
    {                                                                         \
    private:                                                                  \
	   prop##name& operator=( const prop##name& ); /* not allowed */           \
    public:                                                                   \
      operator type();                                                        \
    } name;                                                                   \
    friend prop##name

// macros for read write properties which return a simple type

#define DECLARE_BDTO_PROP_RW( type, name )                                    \
  public:                                                                     \
    void Get##name( type& );                                                  \
    void Set##name( type );                                                   \
    class _BDTOCLASS prop##name                                               \
    {                                                                         \
    public:                                                                   \
      operator type();                                                        \
      type operator=( type );                                                 \
      prop##name& operator=( const prop##name& );                             \
    } name;                                                                   \
    friend prop##name

// macros for read only properties which return an object

#define DECLARE_BDTO_OBJECTPROP_RO( type, name )                              \
  public:                                                                     \
    void Get##name( type& );                                                  \
    class _BDTOCLASS prop##name                                               \
    {                                                                         \
      friend type;                                                            \
    private:                                                                  \
	   prop##name& operator=( const prop##name& ); /* not allowed */           \
      type* p##name;                                                          \
    public:                                                                   \
      prop##name();                                                           \
      ~prop##name();                                                          \
      operator type*();                                                       \
      operator const type&();                                                 \
      type* operator->();                                                     \
      const type& operator*();                                                \
    } name;                                                                   \
    friend prop##name


// macros for read write properties which return an object

#define DECLARE_BDTO_OBJECTPROP_RW( type, name )                              \
  public:                                                                     \
    void Get##name( type& );                                                  \
    void Set##name( type& );                                                  \
    class _BDTOCLASS prop##name                                               \
    {                                                                         \
      friend type;                                                            \
    private:                                                                  \
      type* p##name;                                                          \
    public:                                                                   \
      prop##name();                                                           \
      ~prop##name();                                                          \
      operator type*();                                                       \
      operator const type&();                                                 \
      type* operator->();                                                     \
      const type& operator*();                                                \
      type* operator=( type* );                                               \
      type& operator=( type& );                                               \
      prop##name& operator=( const prop##name& );                             \
    } name;                                                                   \
    friend prop##name


// macros for read write array properties which return a simple type

#define DECLARE_BDTO_ARRAYPROP_RW( type, name, itype, itype2 )                \
  public:                                                                     \
    void Get##name( itype, type& );                                           \
    void Set##name( itype, type );                                            \
    class _BDTOCLASS prop##name                                               \
    {                                                                         \
      ARRAYCLASS( prop##name );                                               \
    private:                                                                  \
	   prop##name& operator=( const prop##name& ); /* not allowed */           \
      void CallGet##name( itype, type& );                                     \
      void CallSet##name( itype, type );                                      \
    public:                                                                   \
      class _BDTOCLASS setter##name                                           \
      {                                                                       \
      public:                                                                 \
        itype2 index;                                                         \
        operator type();                                                      \
        type operator=( type );                                               \
        setter##name& operator=( const setter##name& );                       \
      } name;                                                                 \
      friend setter##name;                                                    \
      setter##name& operator[]( itype );                                      \
    } name;                                                                   \
    friend prop##name


// macros for read only array properties which return an object

#define DECLARE_BDTO_ARRAYOBJECTPROP_RO( type, name, itype )                  \
  public:                                                                     \
    void Get##name( itype, type& );                                           \
    class _BDTOCLASS prop##name                                               \
    {                                                                         \
      friend type;                                                            \
    private:                                                                  \
	   prop##name& operator=( const prop##name& ); /* not allowed */           \
      type* p##name;                                                          \
    public:                                                                   \
      prop##name();                                                           \
      ~prop##name();                                                          \
      type* operator[]( itype );                                              \
    } name;                                                                   \
    friend prop##name

#define DECLARE_BDTO_ARRAYOBJECTPROP_RO_DEFAULT( type, name, itype )          \
  type* operator[]( itype i )                                                 \
  {                                                                           \
    return name[i];                                                           \
  }


// macros for read write array properties which return an object

#define DECLARE_BDTO_ARRAYOBJECTPROP_RW( type, name, itype, itype2 )          \
  public:                                                                     \
    void Get##name( itype, type& );                                           \
    void Set##name( itype, type& );                                           \
    class _BDTOCLASS prop##name                                               \
    {                                                                         \
      friend type;                                                            \
      ARRAYCLASS( prop##name );                                               \
    private:                                                                  \
	   prop##name& operator=( const prop##name& ); /* not allowed */           \
      type* p##name;                                                          \
      type* CallGet##name( itype i );                                         \
      void CallSet##name( itype i, type& v );                                 \
    public:                                                                   \
      prop##name();                                                           \
      ~prop##name();                                                          \
      class _BDTOCLASS setter##name                                           \
      {                                                                       \
      public:                                                                 \
        itype2 index;                                                         \
        operator type*();                                                     \
        operator const type&();                                               \
        type* operator->();                                                   \
        const type& operator*();                                              \
        type* operator=( type* );                                             \
        type& operator=( type& );                                             \
        setter##name& operator=( const setter##name& );                       \
      } name;                                                                 \
      friend setter##name;                                                    \
      setter##name& operator[]( itype i );                                    \
    } name;                                                                   \
    friend prop##name

#define DECLARE_BDTO_ARRAYOBJECTPROP_RW_DEFAULT( type, name, itype )          \
  prop##name::setter##name& operator[]( itype i )                             \
  {                                                                           \
    return name[i];                                                           \
  }


// macros for methods which return an object

#define DECLARE_BDTO_OBJECTMETHOD1( rettype, name, atype )                    \
  public:                                                                     \
    void Call##name( atype a, rettype& r );                                   \
    class _BDTOCLASS obj##name                                                \
    {                                                                         \
      friend type;                                                            \
    private:                                                                  \
	   obj##name& operator=( const obj##name& ); /* not allowed */             \
      rettype* p##name;                                                       \
    public:                                                                   \
      obj##name();                                                            \
      ~obj##name();                                                           \
      rettype* operator()( atype a );                                         \
    } name;                                                                   \
    friend obj##name


#define DECLARE_BDTO_OBJECTMETHOD3( rettype, name, atype, btype, ctype )      \
  public:                                                                     \
    void Call##name( atype a, btype b, ctype c, rettype& r );                 \
    class _BDTOCLASS obj##name                                                \
    {                                                                         \
      friend type;                                                            \
    private:                                                                  \
	   obj##name& operator=( const obj##name& ); /* not allowed */             \
      rettype* p##name;                                                       \
    public:                                                                   \
      obj##name();                                                            \
      ~obj##name();                                                           \
      rettype* operator()( atype a, btype b, ctype c );                       \
    } name;                                                                   \
    friend obj##name


typedef TBdtEventSourceV1<TStrings&> TStringsNotifySource;
typedef TBdtEventSinkV1<TStrings&> TStringsNotifySink;
#define TStringsNotify_FUNCTOR(func) \
        Functor((TStringsNotifySink::TFunctor*)0, func)
#define TStringsNotify_MFUNCTOR(object,memberFunc) \
        Functor((TStringsNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TSession&, bool&> TPasswordSource;
typedef TBdtEventSinkV2<TSession&, bool&> TPasswordSink;
#define TPassword_FUNCTOR(func) \
        Functor((TPasswordSink::TFunctor*)0, func)
#define TPassword_MFUNCTOR(object,memberFunc) \
        Functor((TPasswordSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDatabase&, TStrings&> TLoginSource;
typedef TBdtEventSinkV2<TDatabase&, TStrings&> TLoginSink;
#define TLogin_FUNCTOR(func) \
        Functor((TLoginSink::TFunctor*)0, func)
#define TLogin_MFUNCTOR(object,memberFunc) \
        Functor((TLoginSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV1<TDataSet&> TDataSetNotifySource;
typedef TBdtEventSinkV1<TDataSet&> TDataSetNotifySink;
#define TDataSetNotify_FUNCTOR(func) \
        Functor((TDataSetNotifySink::TFunctor*)0, func)
#define TDataSetNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDataSetNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV1<TDataSource&> TDataSourceNotifySource;
typedef TBdtEventSinkV1<TDataSource&> TDataSourceNotifySink;
#define TDataSourceNotify_FUNCTOR(func) \
        Functor((TDataSourceNotifySink::TFunctor*)0, func)
#define TDataSourceNotify_MFUNCTOR(object,memberFunc) \
        Functor((TDataSourceNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TDataSource&, TField*> TDataChangeSource;
typedef TBdtEventSinkV2<TDataSource&, TField*> TDataChangeSink;
#define TDataChange_FUNCTOR(func) \
        Functor((TDataChangeSink::TFunctor*)0, func)
#define TDataChange_MFUNCTOR(object,memberFunc) \
        Functor((TDataChangeSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV1<TField&> TFieldNotifySource;
typedef TBdtEventSinkV1<TField&> TFieldNotifySink;
#define TFieldNotify_FUNCTOR(func) \
        Functor((TFieldNotifySink::TFunctor*)0, func)
#define TFieldNotify_MFUNCTOR(object,memberFunc) \
        Functor((TFieldNotifySink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV3<TField&, string&, bool> TFieldGetTextSource;
typedef TBdtEventSinkV3<TField&, string&, bool> TFieldGetTextSink;
#define TFieldGetText_FUNCTOR(func) \
        Functor((TFieldGetTextSink::TFunctor*)0, func)
#define TFieldGetText_MFUNCTOR(object,memberFunc) \
        Functor((TFieldGetTextSink::TFunctor*)0, object, memberFunc)

typedef TBdtEventSourceV2<TField&, const string&> TFieldSetTextSource;
typedef TBdtEventSinkV2<TField&, const string&> TFieldSetTextSink;
#define TFieldSetText_FUNCTOR(func) \
        Functor((TFieldSetTextSink::TFunctor*)0, func)
#define TFieldSetText_MFUNCTOR(object,memberFunc) \
        Functor((TFieldSetTextSink::TFunctor*)0, object, memberFunc)

#define DECLARE_EVENT( name, type )                                           \
  protected:                                                                  \
    void Attach##name( const TBdtEventSourceBase& src, bool attach );         \
    bool Attached##name;                                                      \
  public:                                                                     \
    type##Source name##Source

#define DECLARE_BDTO_COMMON( type, pittype, pitname )                         \
  protected:                                                                  \
    pittype pitname;                                                          \
    void Set##type( PIUnknown );                                              \
    void Clear##type( void );                                                 \
  public:                                                                     \
    type( void );                                                             \
    type( pittype );                                                          \
    type( const type& );                                                      \
    type( P##type );                                                          \
    type& operator=( pittype );                                               \
    type& operator=( const type& );                                           \
    int operator==( const type& ) const;                                      \
    int operator!=( const type& ) const;                                      \
    virtual ~type();                                                          \
    pittype Get##pittype( void ) { return pitname; }                          \
    void Set##pittype( pittype p ) { SetPIT( p ); }                           \
    virtual void SetPIT( PIUnknown p )

#define DECLARE_BDTO_VBX( type )                                              \
  public:                                                                     \
    type( HWND hdlg, int idc );                                               \
    void AttachControl( HWND hdlg, int idc )

class _BDTOCLASS TBDTObject
{	
  BDTOCLASS( TBDTObject );
  DECLARE_BDTO_COMMON( TBDTObject, PITBDTObject, bdtobject );

public:
  void Detach( void );

  // public methods
  void Assign( TBDTObject& s );
};

class _BDTOCLASS TBDTComponent : public TBDTObject
{
  BDTOCLASS( TBDTComponent );
  DECLARE_BDTO_COMMON( TBDTComponent, PITBDTComponent, bdtcomponent );

public:
  // published properties
  DECLARE_BDTO_OBJECTPROP_RW( string, Name );
};

class _BDTOCLASS TStrings : public TBDTObject
{
  BDTOCLASS( TStrings );
  DECLARE_BDTO_COMMON( TStrings, PITStrings, strings );

protected:
  void DetachEvents( void );
  void ReattachEvents( void );

public:
  TStrings( const string& );

  // public methods
  int Add( const string& s );
  int AddObject( const string& s, LPVOID object );
  void AddStrings( TStrings& s );
  void BeginUpdate( void );
  void Clear( void );
  void Delete( int index );
  void EndUpdate( void );
  bool Equals( TStrings& s );
  void Exchange( int index1, int index2 );
  bool Find( const string& s, int& lpindex );
  int IndexOf( const string& s );
  int IndexOfObject( LPVOID object );
  void Insert( int index, const string& s );
  void InsertObject( int index, const string& s, LPVOID object );
  void LoadFromFile( const string& filename );
  void LoadFromStream( TMemoryStream& stream );
  void Move( int curIndex, int newIndex );
  void SaveToFile( const string& filename );
  void SaveToStream( TMemoryStream& stream );
  void Sort( void );

  // public properties
  DECLARE_BDTO_PROP_RO( int, Count );
  DECLARE_BDTO_ARRAYPROP_RW( LPVOID, Objects, int, int );
  DECLARE_BDTO_ARRAYOBJECTPROP_RW( string, Values, string&, string );
  DECLARE_BDTO_ARRAYOBJECTPROP_RW( string, Strings, int, int );
  DECLARE_BDTO_ARRAYOBJECTPROP_RW_DEFAULT( string, Strings, int );
  DECLARE_BDTO_OBJECTPROP_RW( string, Text );
  DECLARE_BDTO_PROP_RW( TDuplicates, Duplicates );
  DECLARE_BDTO_PROP_RW( bool, Sorted );

  // published events
  DECLARE_EVENT( OnChange, TStringsNotify );
  DECLARE_EVENT( OnChanging, TStringsNotify );
};


class _BDTOCLASS TSession : public TBDTComponent
{
  BDTOCLASS( TSession );
  DECLARE_BDTO_COMMON( TSession, PITSession, session );

protected:
  bool global;
  void CheckGlobalSession( void );
  void DetachEvents( void );
  void ReattachEvents( void );

public:
  TSession( bool createGlobal );

  // public methods
  void AddPassword( const string& p );
  void CloseDatabase( TDatabase& d );
  void DropConnections( void );
  DECLARE_BDTO_OBJECTMETHOD1( TDatabase, FindDatabase, string& );
  void GetAliasNames( TStrings& list );
  void GetAliasParams( const string& n, TStrings& list );
  void GetDatabaseNames( TStrings& list );
  void GetDriverNames( TStrings& list );
  void GetDriverParams( const string& n, TStrings& list );
  bool GetPassword( void );
  void GetTableNames( const string& DatabaseName, const string& Pattern, bool Extensions, bool SystemTables, TStrings& list );
  void GetStoredProcNames( const string& DatabaseName, TStrings& list );
  DECLARE_BDTO_OBJECTMETHOD1( TDatabase, OpenDatabase, string& );
  void RemoveAllPasswords( void );
  void RemovePassword( const string& p );

  // public properties
  DECLARE_BDTO_PROP_RO( int, DatabaseCount );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO( TDatabase, Databases, int );
  DECLARE_BDTO_PROP_RO( hDBISes, Handle );
  DECLARE_BDTO_PROP_RW( bool, KeepConnections );
  DECLARE_BDTO_PROP_RO( TLocale, Locale );
  DECLARE_BDTO_OBJECTPROP_RW( string, NetFileDir );
  DECLARE_BDTO_OBJECTPROP_RW( string, PrivateDir );

  // public events
  DECLARE_EVENT( OnPassword, TPassword );
};


class _BDTOCLASS TDatabase : public TBDTComponent
{
  BDTOCLASS( TDatabase );
  DECLARE_BDTO_COMMON( TDatabase, PITDatabase, database );
  DECLARE_BDTO_VBX( TDatabase );

protected:
  void DetachEvents( void );
  void ReattachEvents( void );

public:
  // public methods
  void Close( void );
  void CloseDatasets( void );
  void Commit( void );
  void Open( void );
  void Rollback( void );
  void StartTransaction( void );
  void ValidateName( const string& name );

  // public properties
  DECLARE_BDTO_PROP_RO( int, DatasetCount );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO( TDBDataSet, Datasets, int );
  DECLARE_BDTO_PROP_RO( hDBIDb, Handle );
  DECLARE_BDTO_PROP_RO( bool, IsSQLBased );
  DECLARE_BDTO_PROP_RO( TLocale, Locale );
  DECLARE_BDTO_PROP_RW( bool, Temporary );

  // published properties
  DECLARE_BDTO_OBJECTPROP_RW( string, AliasName );
  DECLARE_BDTO_PROP_RW( bool, Connected );
  DECLARE_BDTO_OBJECTPROP_RW( string, DatabaseName );
  DECLARE_BDTO_OBJECTPROP_RW( string, DriverName );
  DECLARE_BDTO_PROP_RW( bool, KeepConnection );
  DECLARE_BDTO_PROP_RW( bool, LoginPrompt );
  DECLARE_BDTO_OBJECTPROP_RW( TStrings, Params );
  DECLARE_BDTO_PROP_RW( TTransIsolation, TransIsolation );

  // published events
  DECLARE_EVENT( OnLogin, TLogin );
};

class _BDTOCLASS TFieldDef
{
  BDTOCLASS( TFieldDef );
  DECLARE_BDTO_COMMON( TFieldDef, PITFieldDef, fielddef );

public:
  TFieldDef( PTFieldDefs Owner, const string& Name, TFieldType DataType, uint16 Size, bool Required, int FieldNo );

  void Detach( void );

  // public methods
  DECLARE_BDTO_OBJECTMETHOD1( TField, CreateField, TBDTComponent& );

  // public properties
  DECLARE_BDTO_PROP_RO( TFieldType, DataType );
  DECLARE_BDTO_PROP_RO( int, FieldNo );
  DECLARE_BDTO_OBJECTPROP_RO( string, Name );
  DECLARE_BDTO_PROP_RO( bool, Required );
  DECLARE_BDTO_PROP_RO( uint16, Size );
};

class _BDTOCLASS TFieldDefs
{
  BDTOCLASS( TFieldDefs );
  DECLARE_BDTO_COMMON( TFieldDefs, PITFieldDefs, fielddefs );

public:
  TFieldDefs( TDataSet& DataSet );

  void Detach( void );

  // public methods
  void Add( const string& Name, TFieldType Type, uint16 Size, bool Required );
  void AddFieldDesc( pFLDDesc FieldDesc, bool Required, uint16 FieldNo );
  void Assign( TFieldDefs& f );
  void Clear( void );
  DECLARE_BDTO_OBJECTMETHOD1( TFieldDef, Find, string& );
  int IndexOf( const string& n );
  void Update( void );

  // public properties
  DECLARE_BDTO_PROP_RO( int, Count );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO( TFieldDef, Items, int );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO_DEFAULT( TFieldDef, Items, int );
};

class _BDTOCLASS TDataSet : public TBDTComponent
{
  BDTOCLASS( TDataSet );
  DECLARE_BDTO_COMMON( TDataSet, PITDataSet, dataset );

protected:
  void DetachEvents( void );
  void ReattachEvents( void );

public:
  // public methods
  LPSTR ActiveBuffer( void );
  void Append( void );
  void AppendRecord( TVarRecs& values );
  void Cancel( void );
  void CheckBrowseMode( void );
  void ClearFields( void );
  void Close( void );
  void CursorPosChanged( void );
  void Delete( void );
  void DisableControls( void );
  void Edit( void );
  void EnableControls( void );
  DECLARE_BDTO_OBJECTMETHOD1( TField, FieldByName, string& );
  DECLARE_BDTO_OBJECTMETHOD1( TField, FindField, string& );
  void First( void );
  void FreeBookmark( TBookmark bm );
  TBookmark GetBookmark( void );
  bool GetCurrentRecord( LPSTR buffer );
  void GetFieldNames( TStrings& list );
  void GotoBookmark( TBookmark bm );
  void Insert( void );
  void InsertRecord( TVarRecs& values );
  bool IsLinkedTo( TDataSource& source );
  void Last( void );
  void MoveBy( int distance );
  void Next( void );
  void Open( void );
  void Post( void );
  void Prior( void );
  void Refresh( void );
  void Resync( TResyncMode mode );
  void SetFields( TVarRecs& values );
  void UpdateCursorPos( void );
  void UpdateRecord( void );

  // public properties
  DECLARE_BDTO_PROP_RO( bool, AtBOF );
  DECLARE_BDTO_PROP_RO( bool, CanModify );
  DECLARE_BDTO_OBJECTPROP_RO( TDataSource, DataSource );
  DECLARE_BDTO_PROP_RO( bool, DefaultFields );
  DECLARE_BDTO_PROP_RO( bool, AtEOF );
  DECLARE_BDTO_PROP_RO( int, FieldCount );
  DECLARE_BDTO_OBJECTPROP_RO( TFieldDefs, FieldDefs );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO( TField, Fields, int );
  DECLARE_BDTO_PROP_RO( hDBICur, Handle );
  DECLARE_BDTO_PROP_RO( bool, Modified );
  DECLARE_BDTO_PROP_RO( int32, RecordCount );
  DECLARE_BDTO_PROP_RO( uint16, RecordSize );
  DECLARE_BDTO_PROP_RO( TDataSetState, State );
  DECLARE_BDTO_PROP_RO( TLocale, Locale );

  // published properties
  DECLARE_BDTO_PROP_RW( bool, Active );
  DECLARE_BDTO_PROP_RW( bool, AutoCalcFields );

  // published events
  DECLARE_EVENT( BeforeOpen, TDataSetNotify );
  DECLARE_EVENT( AfterOpen, TDataSetNotify );
  DECLARE_EVENT( BeforeClose, TDataSetNotify );
  DECLARE_EVENT( AfterClose, TDataSetNotify );
  DECLARE_EVENT( BeforeInsert, TDataSetNotify );
  DECLARE_EVENT( AfterInsert, TDataSetNotify );
  DECLARE_EVENT( BeforeEdit, TDataSetNotify );
  DECLARE_EVENT( AfterEdit, TDataSetNotify );
  DECLARE_EVENT( BeforePost, TDataSetNotify );
  DECLARE_EVENT( AfterPost, TDataSetNotify );
  DECLARE_EVENT( BeforeCancel, TDataSetNotify );
  DECLARE_EVENT( AfterCancel, TDataSetNotify );
  DECLARE_EVENT( BeforeDelete, TDataSetNotify );
  DECLARE_EVENT( AfterDelete, TDataSetNotify );
  DECLARE_EVENT( OnNewRecord, TDataSetNotify );
  DECLARE_EVENT( OnCalcFields, TDataSetNotify );
};

class _BDTOCLASS TDBDataSet : public TDataSet
{
  BDTOCLASS( TDBDataSet );
  DECLARE_BDTO_COMMON( TDBDataSet, PITDBDataSet, dbdataset );

public:
  // public properties
  DECLARE_BDTO_OBJECTPROP_RO( TDatabase, Database );
  DECLARE_BDTO_PROP_RO( hDBIDb, DBHandle );
  DECLARE_BDTO_PROP_RO( TLocale, DBLocale );

  // published properties
  DECLARE_BDTO_OBJECTPROP_RW( string, DatabaseName );
};


class _BDTOCLASS TDataSource : public TBDTComponent
{
  BDTOCLASS( TDataSource );
  DECLARE_BDTO_COMMON( TDataSource, PITDataSource, datasource );
  DECLARE_BDTO_VBX( TDataSource );

protected:
  void DetachEvents( void );
  void ReattachEvents( void );

public:
  // public methods
  void Edit( void );
  bool IsLinkedTo( TDataSet& DataSet );

  // public properties
  DECLARE_BDTO_PROP_RO( TDataSetState, State );

  // published properties
  DECLARE_BDTO_PROP_RW( bool, AutoEdit );
  DECLARE_BDTO_OBJECTPROP_RW( TDataSet, DataSet );
  DECLARE_BDTO_PROP_RW( bool, Enabled );

  // published events
  DECLARE_EVENT( OnStateChange, TDataSourceNotify );
  DECLARE_EVENT( OnDataChange, TDataChange );
  DECLARE_EVENT( OnUpdateData, TDataSourceNotify );
};


class _BDTOCLASS TIndexDef
{
  BDTOCLASS( TIndexDef );
  DECLARE_BDTO_COMMON( TIndexDef, PITIndexDef, indexdef );

public:
  TIndexDef( PTIndexDefs Owner, const string& Name, const string& Fields, TIndexOptions Options );

  void Detach( void );

  // public properties
  DECLARE_BDTO_OBJECTPROP_RO( string, Expression );
  DECLARE_BDTO_OBJECTPROP_RO( string, Fields );
  DECLARE_BDTO_OBJECTPROP_RO( string, Name );
  DECLARE_BDTO_PROP_RO( TIndexOptions, Options );
};

class _BDTOCLASS TIndexDefs
{
  BDTOCLASS( TIndexDefs );
  DECLARE_BDTO_COMMON( TIndexDefs, PITIndexDefs, indexdefs );

public:
  TIndexDefs( TTable& Table );

  void Detach( void );

  // public methods
  void Add( const string& name, const string& fields, TIndexOptions options );
  void Assign( TIndexDefs& i );
  void Clear( void );
  DECLARE_BDTO_OBJECTMETHOD1( TIndexDef, FindIndexForFields, string& );
  int IndexOf( const string& n );
  void Update( void );

  // public properties
  DECLARE_BDTO_PROP_RO( int, Count );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO( TIndexDef, Items, int );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO_DEFAULT( TIndexDef, Items, int );
};

class _BDTOCLASS TTable : public TDBDataSet
{
  BDTOCLASS( TTable );
  DECLARE_BDTO_COMMON( TTable, PITTable, table );
  DECLARE_BDTO_VBX( TTable );

public:
  // public methods
  int32 BatchMove( TDataSet& t, TBatchMode m );
  void AddIndex( const string& name, const string& fields, TIndexOptions options );
  void ApplyRange( void );
  void CancelRange( void );
  void CreateTable( void );
  void DeleteIndex( const string& n );
  void DeleteTable( void );
  void EditKey( void );
  void EditRangeEnd( void );
  void EditRangeStart( void );
  void EmptyTable( void );
  bool FindKey( TVarRecs& values );
  void FindNearest( TVarRecs& values );
  void GetIndexNames( TStrings& list );
  void GotoCurrent( TTable& t );
  bool GotoKey( void );
  void GotoNearest( void );
  void LockTable( TLockType t );
  void RenameTable( const string& newname );
  void SetKey( void );
  void SetRange( TVarRecs& startValues, TVarRecs& endValues );
  void SetRangeEnd( void );
  void SetRangeStart( void );
  void UnlockTable( TLockType t );

  // public properties
  DECLARE_BDTO_OBJECTPROP_RO( TIndexDefs, IndexDefs );
  DECLARE_BDTO_PROP_RO( int, IndexFieldCount );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO( TField, IndexFields, int );
  DECLARE_BDTO_PROP_RW( bool, KeyExclusive );
  DECLARE_BDTO_PROP_RW( int, KeyFieldCount );

  // published properties
  DECLARE_BDTO_PROP_RW( bool, Exclusive );
  DECLARE_BDTO_OBJECTPROP_RW( string, IndexFieldNames );
  DECLARE_BDTO_OBJECTPROP_RW( string, IndexName );
  DECLARE_BDTO_OBJECTPROP_RW( string, MasterFields );
  DECLARE_BDTO_OBJECTPROP_RW( TDataSource, MasterSource );
  DECLARE_BDTO_PROP_RW( bool, ReadOnly );
  DECLARE_BDTO_OBJECTPROP_RW( string, TableName );
  DECLARE_BDTO_PROP_RW( TTableType, TableType );
  DECLARE_BDTO_PROP_RW( TUpdateMode, UpdateMode );
};

class _BDTOCLASS TBatchMove : public TBDTComponent
{
  BDTOCLASS( TBatchMove );
  DECLARE_BDTO_COMMON( TBatchMove, PITBatchMove, batchmove );
  DECLARE_BDTO_VBX( TBatchMove );

public:
  // public methods
  void Execute( void );

  // public properties
  DECLARE_BDTO_PROP_RO( int32, ChangedCount );
  DECLARE_BDTO_PROP_RO( int32, KeyViolCount );
  DECLARE_BDTO_PROP_RO( int32, MovedCount );
  DECLARE_BDTO_PROP_RO( int32, ProblemCount );

  // published properties
  DECLARE_BDTO_PROP_RW( bool, AbortOnKeyViol );
  DECLARE_BDTO_PROP_RW( bool, AbortOnProblem );
  DECLARE_BDTO_OBJECTPROP_RW( string, ChangedTableName );
  DECLARE_BDTO_OBJECTPROP_RW( TTable, Destination );
  DECLARE_BDTO_OBJECTPROP_RW( string, KeyViolTableName );
  DECLARE_BDTO_OBJECTPROP_RW( TStrings, Mappings );
  DECLARE_BDTO_PROP_RW( TBatchMode, Mode );
  DECLARE_BDTO_OBJECTPROP_RW( string, ProblemTableName );
  DECLARE_BDTO_PROP_RW( int32, RecordCount );
  DECLARE_BDTO_OBJECTPROP_RW( TDataSet, Source );
  DECLARE_BDTO_PROP_RW( bool, Transliterate );
};

class _BDTOCLASS TParam
{
  BDTOCLASS( TParam );
  DECLARE_BDTO_COMMON( TParam, PITParam, param );

public:
  TParam( PTParams AParamList, TParamType AParamType );

  void Detach( void );

  // public methods
  void Assign( TParam& p );
  void AssignField( TField& f );
  void GetData( LPVOID buffer );
  uint16 GetDataSize( void );
  void SetData( LPVOID buffer );
  void Clear( void );

  // public properties
  DECLARE_BDTO_OBJECTPROP_RW( string, Name );
  DECLARE_BDTO_PROP_RW( TFieldType, DataType );
  DECLARE_BDTO_PROP_RW( bool, AsBoolean );
  DECLARE_BDTO_PROP_RW( double, AsFloat );
  DECLARE_BDTO_PROP_RW( int32, AsInteger );
  DECLARE_BDTO_OBJECTPROP_RW( string, AsString );
  DECLARE_BDTO_PROP_RW( DATE, AsDate );
  DECLARE_BDTO_PROP_RW( DATE, AsTime );
  DECLARE_BDTO_PROP_RW( DATE, AsDateTime );
  DECLARE_BDTO_PROP_RW( int32, AsSmallInt );
  DECLARE_BDTO_PROP_RW( int32, AsWord );
  DECLARE_BDTO_PROP_RW( double, AsCurrency );
  DECLARE_BDTO_PROP_RW( double, AsBCD );
  DECLARE_BDTO_PROP_RO( bool, IsNull );
  DECLARE_BDTO_PROP_RW( TParamType, ParamType );
  DECLARE_BDTO_PROP_RW( bool, Bound );
  DECLARE_BDTO_OBJECTPROP_RW( string, Text );
};

class _BDTOCLASS TParams : public TBDTObject
{
  BDTOCLASS( TParams );
  DECLARE_BDTO_COMMON( TParams, PITParams, params );

public:
  // public methods
  void AssignValues( TParams& p );
  void AddParam( TParam& p );
  void RemoveParam( TParam& p );
  DECLARE_BDTO_OBJECTMETHOD3( TParam, CreateParam, TFieldType, string&, TParamType );
  DECLARE_BDTO_PROP_RO( int, Count );
  void Clear( void );
  DECLARE_BDTO_OBJECTMETHOD1( TParam, ParamByName, string& );

  // public properties
  DECLARE_BDTO_ARRAYOBJECTPROP_RO( TParam, Items, uint16 );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO_DEFAULT( TParam, Items, uint16 );
};

class _BDTOCLASS TStoredProc : public TDBDataSet
{
  BDTOCLASS( TStoredProc );
  DECLARE_BDTO_COMMON( TStoredProc, PITStoredProc, storedproc );
  DECLARE_BDTO_VBX( TStoredProc );

public:
  // public methods
  void CopyParams( TParams& p );
  DECLARE_BDTO_PROP_RO( bool, DescriptionsAvailable );
  void ExecProc( void );
  DECLARE_BDTO_OBJECTMETHOD1( TParam, ParamByName, string& );
  void Prepare( void );
  void GetResults( void );
  void UnPrepare( void );

  // public properties
  DECLARE_BDTO_PROP_RO( uint16, ParamCount );
  DECLARE_BDTO_PROP_RO( hDBIStmt, StmtHandle );
  DECLARE_BDTO_PROP_RW( bool, Prepared );

  // published properties
  DECLARE_BDTO_OBJECTPROP_RW( string, StoredProcName );
  DECLARE_BDTO_PROP_RW( uint16, Overload );
  DECLARE_BDTO_OBJECTPROP_RW( TParams, Params );
  DECLARE_BDTO_PROP_RW( TParamBindMode, ParamBindMode );
};

class _BDTOCLASS TQuery : public TDBDataSet
{
  BDTOCLASS( TQuery );
  DECLARE_BDTO_COMMON( TQuery, PITQuery, query );
  DECLARE_BDTO_VBX( TQuery );

public:
  // public methods
  void ExecSQL( void );
  DECLARE_BDTO_OBJECTMETHOD1( TParam, ParamByName, string& );
  void Prepare( void );
  void UnPrepare( void );

  // public properties
  DECLARE_BDTO_PROP_RW( bool, Prepared );
  DECLARE_BDTO_PROP_RO( uint16, ParamCount );
  DECLARE_BDTO_PROP_RO( bool, Local );
  DECLARE_BDTO_PROP_RO( hDBIStmt, StmtHandle );
  DECLARE_BDTO_OBJECTPROP_RO( string, Text );

  // published properties
  DECLARE_BDTO_OBJECTPROP_RW( TStrings, SQL );
  DECLARE_BDTO_OBJECTPROP_RW( TDataSource, DataSource );
  DECLARE_BDTO_PROP_RW( bool, UniDirectional );
  DECLARE_BDTO_PROP_RW( bool, RequestLive );
  DECLARE_BDTO_OBJECTPROP_RW( TParams, Params );
  DECLARE_BDTO_PROP_RW( TUpdateMode, UpdateMode );
};

class _BDTOCLASS TMemoryStream
{
  BDTOCLASS( TMemoryStream );
  DECLARE_BDTO_COMMON( TMemoryStream, PITMemoryStream, stream );

public:
  void Detach( void );

  // public methods
  int32 Read( LPVOID Buffer, int32 Count );
  int32 Write( LPVOID Buffer, int32 Count );
  int32 Seek( int32 Offset, TSeekOrigin Origin );
  void ReadBuffer( LPVOID Buffer, int32 Count );
  void WriteBuffer( LPVOID Buffer, int32 Count );
  int32 CopyFrom( TMemoryStream& Source, int32 Count );

  // public properties
  DECLARE_BDTO_PROP_RW( int32, Position );
  DECLARE_BDTO_PROP_RO( int32, Size );
};


class _BDTOCLASS TField : public TBDTComponent
{
  BDTOCLASS( TField );
  DECLARE_BDTO_COMMON( TField, PITField, field );

protected:
  void DetachEvents( void );
  void ReattachEvents( void );

public:
  TField( PTBDTComponent Owner, TFieldType DataType );

  // public methods
  void AssignValue( TVarRec& v );
  void Clear( void );
  bool GetData( LPVOID buffer );
  void SetData( LPVOID buffer );
  bool IsValidChar( char c );

  // public properties
  DECLARE_BDTO_PROP_RW( bool, AsBoolean );
  DECLARE_BDTO_PROP_RW( DATE, AsDateTime );
  DECLARE_BDTO_PROP_RW( double, AsFloat );
  DECLARE_BDTO_PROP_RW( int32, AsInteger );
  DECLARE_BDTO_OBJECTPROP_RW( string, AsString );
  DECLARE_BDTO_PROP_RO( bool, CanModify );
  DECLARE_BDTO_OBJECTPROP_RW( TDataSet, DataSet );
  DECLARE_BDTO_PROP_RO( int, DataSize );
  DECLARE_BDTO_PROP_RO( TFieldType, DataType );
  DECLARE_BDTO_OBJECTPROP_RO( string, DisplayText );
  DECLARE_BDTO_OBJECTPROP_RW( string, EditMask );
  DECLARE_BDTO_PROP_RO( int, FieldNo );
  DECLARE_BDTO_PROP_RO( bool, IsIndexField );
  DECLARE_BDTO_PROP_RO( bool, IsNull );
  DECLARE_BDTO_PROP_RW( uint16, Size );
  DECLARE_BDTO_OBJECTPROP_RW( string, Text );

  // published properties
  DECLARE_BDTO_PROP_RW( bool, Calculated );
  DECLARE_BDTO_OBJECTPROP_RW( string, FieldName );
  DECLARE_BDTO_PROP_RW( int, Index );
  DECLARE_BDTO_PROP_RW( bool, ReadOnly );
  DECLARE_BDTO_PROP_RW( bool, Required );
  DECLARE_BDTO_PROP_RW( bool, Visible );

  // published events
  DECLARE_EVENT( OnChange, TFieldNotify );
  DECLARE_EVENT( OnGetText, TFieldGetText );
  DECLARE_EVENT( OnSetText, TFieldSetText );
  DECLARE_EVENT( OnValidate, TFieldNotify );
};

#define DECLARE_BDTO_DERIVEDFIELD_COMMON( type )                              \
  public:                                                                     \
    type( void );                                                             \
    type( PITField );                                                         \
    type( const TField& );                                                    \
    type( PTField );                                                          \
    type& operator=( PITField );                                              \
    type& operator=( const TField& );                                         \
    int operator==( const TField& ) const;                                    \
    int operator!=( const TField& ) const;                                    \
    virtual ~type()

class _BDTOCLASS TStringField : public TField
{
  BDTOCLASS( TStringField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TStringField );

public:
  TStringField( PTBDTComponent Owner );

  // public properties
  DECLARE_BDTO_OBJECTPROP_RW( string, Value );

  // published properties
  DECLARE_BDTO_PROP_RW( bool, Transliterate );
};

class _BDTOCLASS TNumericField : public TField
{
  BDTOCLASS( TNumericField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TNumericField );

public:
  TNumericField( PTBDTComponent Owner, TFieldType DataType );

  // published properties
  DECLARE_BDTO_OBJECTPROP_RW( string, DisplayFormat );
  DECLARE_BDTO_OBJECTPROP_RW( string, EditFormat );
};

class _BDTOCLASS TIntegerField : public TNumericField
{
  BDTOCLASS( TIntegerField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TIntegerField );

public:
  TIntegerField( PTBDTComponent Owner );
  TIntegerField( PTBDTComponent Owner, TFieldType DataType );

  // public properties
  DECLARE_BDTO_PROP_RW( int32, Value );

  // published properties
  DECLARE_BDTO_PROP_RW( int32, MaxValue );
  DECLARE_BDTO_PROP_RW( int32, MinValue );
};

class _BDTOCLASS TSmallintField : public TIntegerField
{
  BDTOCLASS( TSmallintField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TSmallintField );

public:
  TSmallintField( PTBDTComponent Owner );
};

class _BDTOCLASS TWordField : public TIntegerField
{
  BDTOCLASS( TWordField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TWordField );

public:
  TWordField( PTBDTComponent Owner );
};

class _BDTOCLASS TFloatField : public TNumericField
{
  BDTOCLASS( TFloatField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TFloatField );

public:
  TFloatField( PTBDTComponent Owner );
  TFloatField( PTBDTComponent Owner, TFieldType DataType );

  // public properties
  DECLARE_BDTO_PROP_RW( double, Value );

  // published properties
  DECLARE_BDTO_PROP_RW( bool, Currency );
  DECLARE_BDTO_PROP_RW( double, MaxValue );
  DECLARE_BDTO_PROP_RW( double, MinValue );
  DECLARE_BDTO_PROP_RW( int, Precision );
};

class _BDTOCLASS TCurrencyField : public TFloatField
{
  BDTOCLASS( TCurrencyField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TCurrencyField );

public:
  TCurrencyField( PTBDTComponent Owner );
};

class _BDTOCLASS TBCDField : public TFloatField
{
  BDTOCLASS( TBCDField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TBCDField );

public:
  TBCDField( PTBDTComponent Owner );
};

class _BDTOCLASS TBooleanField : public TField
{
  BDTOCLASS( TBooleanField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TBooleanField );

public:
  TBooleanField( PTBDTComponent Owner );

  // public properties
  DECLARE_BDTO_PROP_RW( bool, Value );

  // published properties
  DECLARE_BDTO_OBJECTPROP_RW( string, DisplayValues );
};

class _BDTOCLASS TDateTimeField : public TField
{
  BDTOCLASS( TDateTimeField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TDateTimeField );

public:
  TDateTimeField( PTBDTComponent Owner );
  TDateTimeField( PTBDTComponent Owner, TFieldType DataType );

  // public properties
  DECLARE_BDTO_PROP_RW( DATE, Value );

  // published properties
  DECLARE_BDTO_OBJECTPROP_RW( string, DisplayFormat );
};

class _BDTOCLASS TDateField : public TDateTimeField
{
  BDTOCLASS( TDateField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TDateField );

public:
  TDateField( PTBDTComponent Owner );
};

class _BDTOCLASS TTimeField : public TDateTimeField
{
  BDTOCLASS( TTimeField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TTimeField );

public:
  TTimeField( PTBDTComponent Owner );
};

class _BDTOCLASS TBytesField : public TField
{
  BDTOCLASS( TBytesField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TBytesField );

public:
  TBytesField( PTBDTComponent Owner );
};

class _BDTOCLASS TVarBytesField : public TField
{
  BDTOCLASS( TVarBytesField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TVarBytesField );

public:
  TVarBytesField( PTBDTComponent Owner );
};

class _BDTOCLASS TBlobField : public TField
{
  BDTOCLASS( TBlobField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TBlobField );

public:
  TBlobField( PTBDTComponent Owner );
  TBlobField( PTBDTComponent Owner, TFieldType DataType );

  // public methods
  void LoadFromFile( const string& filename );
  void LoadFromStream( TMemoryStream& stream );
  void SaveToFile( const string& filename );
  void SaveToStream( TMemoryStream& stream );
};

class _BDTOCLASS TMemoField : public TBlobField
{
  BDTOCLASS( TMemoField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TMemoField );

public:
  TMemoField( PTBDTComponent Owner );

  // public properties
  DECLARE_BDTO_PROP_RW( bool, Transliterate );
};

class _BDTOCLASS TGraphicField : public TBlobField
{
  BDTOCLASS( TGraphicField );
  DECLARE_BDTO_DERIVEDFIELD_COMMON( TGraphicField );

public:
  TGraphicField( PTBDTComponent Owner );

  // additional methods
  void SaveToBitmap( HBITMAP& hbitmap, HPALETTE& hpalette );
  void LoadFromBitmap( HBITMAP hbitmap, HPALETTE hpalette );
};

class _BDTOCLASS TVarRec
{
  BDTOCLASS( TVarRec );

protected:
  LPVARIANT lpvar;
  bool allocated;
  void Allocate( void );

public:
  TVarRec( void );
  TVarRec( LPVARIANT );
  TVarRec( const TVarRec& );
  TVarRec( PTVarRec );
  TVarRec( bool );
//  TVarRec( DATE );
  TVarRec( double );
  TVarRec( float );
  TVarRec( int32 );
  TVarRec( int );
  TVarRec( int16 );
  TVarRec( string& );
  TVarRec( LPSTR );
  TVarRec& operator=( const TVarRec& );
  virtual ~TVarRec();

  TVarRec& operator=( bool );
//  TVarRec& operator=( DATE );
  TVarRec& operator=( double );
  TVarRec& operator=( int32 );
  TVarRec& operator=( string& );

  operator bool();
//  operator DATE();
  operator double();
  operator int32();
  operator string();

  LPVARIANT GetVariant( void ) { return lpvar; }
  void SetVariant( LPVARIANT p );

  // properties
  DECLARE_BDTO_PROP_RW( bool, AsBoolean );
  DECLARE_BDTO_PROP_RW( DATE, AsDateTime );
  DECLARE_BDTO_PROP_RW( double, AsFloat );
  DECLARE_BDTO_PROP_RW( int32, AsInteger );
  DECLARE_BDTO_OBJECTPROP_RW( string, AsString );
};

class _BDTOCLASS TVarRecs
{
  BDTOCLASS( TVarRecs );

protected:
  int count;
  LPVARIANT lpvar;

public:
  TVarRecs( int c = 0, LPVARIANT p = 0 );
  TVarRecs( const TVarRecs& p );
  TVarRecs( PTVarRecs p );
  TVarRecs& operator=( TVarRecs& p );
  virtual ~TVarRecs();

  // methods
  void Add( void );
  void Add( TVarRec& v );
  void Clear( void );

  // properties
  DECLARE_BDTO_PROP_RO( int, Count );
  DECLARE_BDTO_PROP_RO( LPVARIANT, Variants );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO( TVarRec, Items, int );
  DECLARE_BDTO_ARRAYOBJECTPROP_RO_DEFAULT( TVarRec, Items, int );
};

extern TSession Session;        // global session variable

void VDBTEasterEgg( void );

#endif // BDTO_H
