/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  edittool.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.13  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "edittool.h"

//.............................................................................
EditToolTest::EditToolTest() 
  {
  _toolServer = NULL;
  }
//.............................................................................
EditToolTest::~EditToolTest() 
  {
  UnInit();
  }
//.............................................................................
BOOL EditToolTest::Init() 
  {
  if ( !_toolServer ) 
    {
    OutStr( "EditToolTest::Init()" );
    _toolServer = GET_INTERFACE(IToolServer);
    if ( _toolServer == NULL ) 
      {
      return FALSE;
      }
    }
  return TRUE;
}
//.............................................................................
void EditToolTest::UnInit() 
  {
  OutStr( "EditToolTest::UnInit()" );
  if ( _toolServer ) 
    {
    _toolServer->Release();
    _toolServer = NULL;
    }
  }
//.............................................................................
const char * EditToolTest::GetName() 
  {
  return "Tool info (editor as tool)";
  }
//.............................................................................
const char * EditToolTest::GetTestDescription( int testNum ) 
  {
  switch ( testNum )
    {
    case 1: 
      return "Returns info about the edit tool.";
    case 2: 
      return "Add .bat to list of supported types.";
    }
  return "This test not implemented.";
  }  
//.............................................................................
void EditToolTest::DoTest( int testNum ) 
  {
  if ( !_toolServer ) 
    {
    OutStr( "Tool Server not initialized!" );
    return;
    }
  switch ( testNum ) 
    {  
    case 1: 
      {
      ToolObj toolObj = _toolServer->ToolFind( ::MakePolyString ( "EditText" ) );
      if ( toolObj ) 
        {
        IToolInfo * pToolInfo = _toolServer->QueryToolInfo ( toolObj );
        if ( pToolInfo != NULL )
          {
          ShowPolyStr ( "Name = ", pToolInfo->GetName(), TRUE );
          ShowPolyStr ( "Menu Name = ", pToolInfo->GetMenuName(), TRUE );
          ShowPolyStr ( "Help Hint = ", pToolInfo->GetHelpHint(), TRUE );
          ShowPolyStr ( "Path = ", pToolInfo->GetPath(), TRUE );
          ShowPolyStr ( "Cmd Line = ", pToolInfo->GetDefCmdLine(), TRUE );
          ShowPolyStr ( "Supported Types = ", pToolInfo->GetSupportedTypes(), TRUE );
          ShowPolyStr ( "DefForTypes = ", pToolInfo->GetDefaultForTypes(), TRUE );
          ShowPolyStr ( "TranslateTo = ", pToolInfo->GetTranslateTo(), TRUE ); 
          OutStr( FormatStr( "ToolTypes = %d", pToolInfo->GetTypes() ) );
          OutStr( FormatStr( "ToolFlags = %d", pToolInfo->GetFlags() ) );
          OutStr( FormatStr( "LaunchType = %d", pToolInfo->GetLaunchType() ) );

          pToolInfo->Release();
          }
        } 
      else 
        {
        OutStr( FormatStr( "Couldn't find tool named %s.", "EditText" ) );
        }
      break;
      }

    case 2: 
      {
      ToolObj toolObj = _toolServer->ToolFind( ::MakePolyString ( "EditText" ) );
      if ( toolObj ) 
        {
        IToolInfo * pToolInfo = _toolServer->QueryToolInfo ( toolObj );
        if ( pToolInfo != NULL )
          {
          IPolyString *pSupported = pToolInfo->GetSupportedTypes();
          if ( pSupported )
            {
            const char *pcSupport = pSupported->GetCstr();
            if ( pcSupport )
              {
              char buf[256];
              strncpy ( buf, pcSupport, 255);
              strcat  ( buf, ".bat" );
              pToolInfo->SetSupportedTypes ( ::MakePolyString( buf ) );
              }
            }
          else
            {
            pToolInfo->SetSupportedTypes ( ::MakePolyString( ".bat" ) );
            }
          _toolServer->ToolAdd( pToolInfo );
          pToolInfo->Release();
          }
        }
      }
      break;


    default: 
      {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      }
    }
  }
