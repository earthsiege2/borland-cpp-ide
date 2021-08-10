//--------------------------------------------------------
// DBMISC.CPP
// Copyrights (C) 1996 Borland International
// All rights reserved.
//--------------------------------------------------------

#include <vdbt/dbmisc.h>


typedef HCTL (FAR PASCAL _export *LPFNCTLNITROFIND)( HCTL, LPSTR, PIUnknown );

//--------------------------------------------------------
// Helper Functions
//--------------------------------------------------------
extern bool DBEqualOperator( TGenericTableEntry __RTFAR& entry
                           , TEventHandler::TEventInfo& info )
{
  return entry.Msg == info.Msg && entry.Pmf != NULL;
}

extern void PASCAL ThrowException( LPCSTR lpError )
{
  TXOwl( lpError ).Throw();
}

static VOID PASCAL
ThrowException( LPCSTR lpError0, LPCSTR lpError1, LPCSTR lpName )
{
  char szError[ 256 ];

  wsprintf( szError, "%s!\r\n%s [%s]", lpError0, lpError1, lpName );
  TXOwl( szError ).Throw();
}

static HCTL PASCAL
GetNitroControl( TVbxControl *pCtl, PIUnknown p )
{
#ifdef __FLAT__
  LPCSTR lpEXTDLL = "BDT50EXF.DLL";
#else  __FLAT__
  LPCSTR lpEXTDLL = "BDT50EX.DLL";
#endif __FLAT__
  LPFNCTLNITROFIND pCtlNitroFind;
  HCTL hCtl = NULL;
  HINSTANCE hEXTDLL = LoadLibrary( lpEXTDLL );

  if( hEXTDLL > HINSTANCE( HINSTANCE_ERROR ) )
  {
    pCtlNitroFind
               =  LPFNCTLNITROFIND( GetProcAddress( hEXTDLL, "CtlNitroFind" ) );

    if( pCtlNitroFind )
      hCtl = (*pCtlNitroFind)( pCtl->GetHCTL(), "BIDATASET", p );
    else
      ThrowException( "Finding DataSource Failed"
                    , "Can't Find Dyna-Link", "CtlNitroFind()" );

    FreeLibrary( hEXTDLL );
  }
  else
    ThrowException( "Finding DataSource Failed"
                  , "Can't Load DLL", lpEXTDLL );

  return hCtl;
}

static HCTL PASCAL
FindNitroControl( TVbxControl *pCtl, LPCSTR lpName, TDataSource* DataSource )
{
  HCTL hCtl = ::GetNitroControl( pCtl, DataSource->GetPITDataSource() );

  if( hCtl )
  {
    HSZ  hszName;
    char szName[ 256 ];

    if( ::VBXGetProp( hCtl, 0, &hszName ) && hszName
     && ::VBXGetCStringBuf( hszName, szName, sizeof( szName ) ) )
    {
      if( ! pCtl->SetProp( lpName, szName ) )
        ThrowException( "Finding DataSource Failed"
                      , "Control Has No Name", lpName );
    }
    else
      ThrowException( "Finding DataSource Failed"
                    , "Can't Get New Name", lpName );
  }

  return hCtl;
}

extern TDataSource* PASCAL
GetSource( TVbxControl *pCtl, LPCSTR lpName, TDataSource* DataSource )
{
  string sName;

  if( pCtl->GetProp( lpName, sName ) )
  {
    HCTL hCtl = NULL;

    // first time initialization
    if( ! DataSource && (DataSource = new TDataSource()) == NULL )
      ThrowException( "Memory Allocation Failed in GetSource()!" );

    if( sName.length() )
      hCtl = ::VBXFindControl( pCtl->Parent->HWindow, sName.c_str() );
    else
      hCtl = ::FindNitroControl( pCtl, lpName, DataSource );

    if( hCtl )
    {
#ifdef __FLAT__
      int  nID  = ::GetWindowLong( ::VBXGetHwnd( hCtl ), GWL_ID );
#else  __FLAT__
      int  nID  = ::GetWindowWord( ::VBXGetHwnd( hCtl ), GWW_ID );
#endif __FLAT__

      *DataSource = TDataSource( pCtl->Parent->HWindow, nID );
    }
    else
      *DataSource = TDataSource();
  }
  else
    ThrowException( "Getting DataSource Failed"
                  , "Can't Get Property", lpName );

  return DataSource;
}

static VOID PASCAL
SetNameFromHCTL( HCTL hCtl, TVbxControl *pCtl, LPCSTR lpName )
{
  HSZ  hszName;
  char szName[ 256 ];

  if( ! ::VBXGetProp( hCtl, 0, &hszName ) || ! hszName )
    ThrowException( "Setting DataSource Failed", "Can't Get Property", "Name" );
  if( ! ::VBXGetCStringBuf( hszName, szName, sizeof( szName ) ) )
    ThrowException( "Setting DataSource Failed", "Can't Get String", "Name" );
  if( ! pCtl->SetProp( lpName, szName ) )
    ThrowException( "Setting DataSource Failed", "Can't Set Property", lpName );
}

extern TDataSource* PASCAL
SetSource( TVbxControl *pCtl, LPCSTR lpName, TDataSource *DataSource )
{
  string sName;

  if( pCtl->GetProp( lpName, sName ) )
  {
    HCTL hCtl;

    if( sName.length() )
    {
      // Control was previously bounded to a DataAccess VBX
      if( ! DataSource )
      {
        // Set to NULL DataSource
        if( ! pCtl->SetProp( lpName, string( "" ) ) )
          ThrowException( "Setting DataSource Failed"
                        , "Can't Set Object to NULL", lpName );
      }
      else if( (hCtl = ::FindNitroControl( pCtl, lpName, DataSource )) != NULL )
      {
        // Switch to another DataAccess VBX with a Matching TDataSource Object
        SetNameFromHCTL( hCtl, pCtl, lpName );
      }
      else if( (hCtl = ::VBXFindControl( pCtl->Parent->HWindow, sName.c_str() ))
                                                                       != NULL )
      {
        // Switch the Bounded Control to the New DataSource
        if( ! ::VBXSetPropByName( hCtl, "Object"
                                , LONG( DataSource->GetPITDataSource() ) ) )
          ThrowException( "Setting DataSource Failed"
                        , "Can't Set Property", "Object" );
      }
      else
        ThrowException( "Setting DataSource Failed"
                      , "No Such VBX Exists", lpName );
    }
    else if( DataSource )
    {
      if( (hCtl = ::FindNitroControl( pCtl, lpName, DataSource )) != NULL )
      {
        // Bound to a Control with the Same TDataSource
        SetNameFromHCTL( hCtl, pCtl, lpName );
      }
      else
        ThrowException( "Setting DataSource Failed"
                      , "Can't Find VBX Control", "" );
    }
  }
  else
    ThrowException( "Setting DataSource Failed"
                  , "Can't Get Property", lpName );

  return DataSource;
}

extern TField* PASCAL
GetField( TVbxControl *pCtl, int Prop_Field
        , TDataSource* DataSource, TField* pField )
{
  // first time initialization
  if( ! pField && (pField = new TField()) == NULL )
    ThrowException( "Memory Allocation Failed in GetField()!" );

  if( DataSource )
  {
    string s;

    if( ! pCtl->GetProp( Prop_Field, s ) )
      ThrowException( "Getting Field Failed!" );

    if( s.is_null() )
      *pField = TField();
    else
      *pField = TField( DataSource->DataSet->FieldByName( s ) );
  }
  else
    *pField = TField();

  return pField;
}

extern TField* PASCAL
SetField( TVbxControl *pCtl, int Prop_Field, TField *pField )
{
  string s;

  if( ! pCtl->SetProp( Prop_Field, pField ? *pField->FieldName : s ) )
    ThrowException( "Setting Field Failed!" );

  return pField;
}

extern TStrings* PASCAL
GetStrings( TVbxControl *pCtl, int iIndex, TStrings* pStrings )
{
  HLSTR hlstrStrings;

  if( ! pCtl->GetProp( iIndex, LONG( hlstrStrings ) ) )
    ThrowException( "GetStrings(): Getting HLSTR Failed!" );

  // first time initialization
  if( ! pStrings && (pStrings = new TStrings()) == NULL )
    ThrowException( "Memory Allocation Failed in GetStrings()!" );

  if( hlstrStrings )
  {
    int nStrings = ::VBXGetBasicStringLength( hlstrStrings );

    if( nStrings )
#ifdef __FLAT__
    {
      LPSTR lpStrings = new char[ nStrings + 2 ];

      if( lpStrings )
      {
        int nLen
              = ::VBXGetBasicStringBuf( hlstrStrings, lpStrings, nStrings + 2 );

        lpStrings[ nLen + 1 ] = '\0';
        pStrings->SetText( string( lpStrings ) );
        delete[] lpStrings;
      }
      else
        ThrowException( "GetStrings(): Memory Allocation Failed!" );
    }
    else
      pStrings->SetText( string() );
#else __FLAT__
      pStrings->SetText( string( ::VBXGetBasicStringPtr( hlstrStrings ) ) );
#endif __FLAT__

    ::VBXDestroyBasicString( hlstrStrings );
  }
  else
    pStrings->SetText( string() );

  return pStrings;
}

extern TStrings* PASCAL
SetStrings( TVbxControl *pCtl, int iIndex, TStrings* pStrings )
{
  HLSTR  hlstrStrings;
  string sStrings;

  pStrings->GetText( sStrings );
  hlstrStrings = ::VBXCreateBasicString( (void*)sStrings.c_str()
                                       , short( sStrings.length() ) );
  if( ! pCtl->SetProp( iIndex, LONG( hlstrStrings ) ) )
    ThrowException( "SetStrings(): Setting HLSTR Failed!" );

  if( hlstrStrings )
    ::VBXDestroyBasicString( hlstrStrings );

  return pStrings;
}

extern string* PASCAL
Getstring( TVbxControl* pCtl, int iIndex, string* String )
{
  // first time initialization
  if( ! String && (String = new string()) == NULL )
    ThrowException( "Memory Allocation Failed in GetSstring()!" );

  if( ! pCtl->GetProp( iIndex, *String ) )
    ThrowException( "Getstring(): Getting string Failed!" );

  return String;
}

extern string* PASCAL
Setstring( TVbxControl* pCtl, int iIndex, string* String )
{
  if( ! pCtl->SetProp( iIndex, *String ) )
    ThrowException( "Setstring(): Setting string Failed!" );

  return String;
}
