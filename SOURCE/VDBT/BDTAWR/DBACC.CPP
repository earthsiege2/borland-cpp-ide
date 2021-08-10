//--------------------------------------------------------
// DBACC.CPP
// Copyrights (C) 1996 Borland International
// All Rights Reserved
//--------------------------------------------------------

#include <vdbt/dbacc.h>


bool TDBDataSource::Create()
{
  if( TVbxControl::Create() )
  {
    if( IsFlagSet( wfFromResource ) )
    {
      AttachToControl( Parent->HWindow, GetId() );
      return true;
    }
    else
    {
      char    szName[ 32 ];

      return ::VBXMakeDefCtlNameBuf( GetHCTL(), szName, sizeof( szName ) )
          && SetProp( 0, szName )
          && SetProp( "Object", LONG( GetPITDataSource() ) );
    }
  }
  else
    return false;
}

bool TDBTable::Create()
{
  if( TVbxControl::Create() )
  {
    if( IsFlagSet( wfFromResource ) )
    {
      AttachToControl( Parent->HWindow, GetId() );
      return true;
    }
    else
    {
      char    szName[ 32 ];

      return ::VBXMakeDefCtlNameBuf( GetHCTL(), szName, sizeof( szName ) )
          && SetProp( 0, szName )
          && SetProp( "Object", LONG( GetPITTable() ) );
    }
  }
  else
    return false;
}

bool TDBQuery::Create()
{
  if( TVbxControl::Create() )
  {
    if( IsFlagSet( wfFromResource ) )
    {
      AttachToControl( Parent->HWindow, GetId() );
      return true;
    }
    else
    {
      char    szName[ 32 ];

      return ::VBXMakeDefCtlNameBuf( GetHCTL(), szName, sizeof( szName ) )
          && SetProp( 0, szName )
          && SetProp( "Object", LONG( GetPITQuery() ) );
    }
  }
  else
    return false;
}

bool TDBBatchMove::Create()
{
  if( TVbxControl::Create() )
  {
    if( IsFlagSet( wfFromResource ) )
    {
      AttachToControl( Parent->HWindow, GetId() );
      return true;
    }
    else
    {
      char    szName[ 32 ];

      return ::VBXMakeDefCtlNameBuf( GetHCTL(), szName, sizeof( szName ) )
          && SetProp( 0, szName )
          && SetProp( "Object", LONG( GetPITBatchMove() ) );
    }
  }
  else
    return false;
}

bool TDBDatabase::Create()
{
  if( TVbxControl::Create() )
  {
    if( IsFlagSet( wfFromResource ) )
    {
      AttachToControl( Parent->HWindow, GetId() );
      return true;
    }
    else
    {
      char    szName[ 32 ];

      return ::VBXMakeDefCtlNameBuf( GetHCTL(), szName, sizeof( szName ) )
          && SetProp( 0, szName )
          && SetProp( "Object", LONG( GetPITDatabase() ) );
    }
  }
  else
    return false;
}

bool TDBStoredProc::Create()
{
  if( TVbxControl::Create() )
  {
    if( IsFlagSet( wfFromResource ) )
    {
      AttachToControl( Parent->HWindow, GetId() );
      return true;
    }
    else
    {
      char    szName[ 32 ];

      return ::VBXMakeDefCtlNameBuf( GetHCTL(), szName, sizeof( szName ) )
          && SetProp( 0, szName )
          && SetProp( "Object", LONG( GetPITStoredProc() ) );
    }
  }
  else
    return false;
}

