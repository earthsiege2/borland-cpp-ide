/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  menutest.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "menutest.h"

static BOOL gCommandsEnabled = TRUE;

/*============================================================================

      MenuTestA
            
============================================================================*/            

BOOL PASCAL globalCommandEnabler() {
  return gCommandsEnabled;
} 

//.............................................................................
MenuTestA::MenuTestA() 
  {
  _startInitFailed = FALSE;
  _menuServer = NULL;
  _windowCmd = NULL;
  _openFileCmd = NULL;
  _pWindowMenuItem = NULL;
  _pOpenFileMenu1 = NULL;
  _pOpenFileMenu2 = NULL;
  _pEditorMenu = NULL;
  _pWindowRestoreMenu = NULL;
  _myMenuClient = new myMenuClient;

  _cmdServer  = GET_INTERFACE(ICommandServer);
  if ( !_cmdServer )
    {     
    _startInitFailed = TRUE;
    return;
    }

  _menuServer = GET_INTERFACE(IMenuServer);
  if ( !_menuServer )
    {     
    _startInitFailed = TRUE;
    return;
    }

  // add a cmd and a menu to the windows menu
  _windowCmd = _cmdServer->CreateCommand();
  if ( _windowCmd )
    {
    // Fill in the cmd
    _windowCmd->SetName( ::MakePolyString ("MinimizeAllExceptMessageView") );
    _windowCmd->SetDescription( ::MakePolyString ("Mininimize all except the message view.") );
    _windowCmd->SetScriptCommand( ::MakePolyString ("IDE.WindowMinimizeAll();IDE.ViewMessage();") );
    _windowCmd->SetToolTip( ::MakePolyString ("Mininimize all except the message view.") );
    _windowCmd->SetHelpHint( ::MakePolyString ("Mininimize all except the message view.")  );
    _windowCmd->SetEnableFunction( globalCommandEnabler );
    _windowCmd->AddRef();
    _cmdServer->AddCommand( _windowCmd );
    _pWindowMenuItem = _menuServer->CreateItem();
    if ( _pWindowMenuItem )
      {
      _windowCmd->AddRef();
      _pWindowMenuItem->SetCommand( _windowCmd );
      _pWindowMenuItem->SetMenuText( ::MakePolyString ("&Window|AddOn Minimize All and Show Message View") );
      _pWindowMenuItem->SetMenuType( MT_IDE );
      //
      // We've done everything except register this menu item, which won't
      // work properly unless we defer it until after the IDE has had a 
      // chance to assign a unique command ID for this command. It
      // is safe to register the menu item when scripts are loading (your
      // script could call back to your dll), when the first project open
      // event arrives (by registering a project client with the project
      // server) or in the case of this example, by waiting for some user 
      // driven event - here it is the init of this test. (See 
      // MenuTestA::Init() below)
      //
      }
    }

  // add a file open cmd
  _openFileCmd = _cmdServer->CreateCommand();
  if ( _openFileCmd )
    {
    // Fill in the cmd
    _openFileCmd->SetName( ::MakePolyString ("AnotherFileOpen") );
    _openFileCmd->SetDescription( ::MakePolyString ("Another File Open") );
    _openFileCmd->SetScriptCommand( ::MakePolyString ("IDE.FileOpen();") );
    _openFileCmd->SetToolTip( ::MakePolyString ("A test of the command interface") );
    _openFileCmd->SetHelpHint( ::MakePolyString ("A test of the command interface")  );
    _openFileCmd->SetEnableFunction( globalCommandEnabler );
    _openFileCmd->AddRef();
    _cmdServer->AddCommand( _openFileCmd );
    }
  }

//.............................................................................
MenuTestA::~MenuTestA() 
  {
  UnInit();

  // Remove the 2 commands we added
  if ( _windowCmd )
    {
    _cmdServer->RemoveCommand( _windowCmd );
    _windowCmd = NULL;
    }
  if ( _openFileCmd )
    {
    _cmdServer->RemoveCommand( _openFileCmd );
    _openFileCmd = NULL;
    }

  // Remove the menus we added
  if ( _pWindowMenuItem )
    {
    _menuServer->UnRegisterItem( _pWindowMenuItem );
    _pWindowMenuItem = NULL;
    }
  if ( _pOpenFileMenu1 )
    {
    _menuServer->UnRegisterItem( _pOpenFileMenu1 );
    _pOpenFileMenu1 = NULL;
    }
  if ( _pOpenFileMenu2 )
    {
    _menuServer->UnRegisterItem( _pOpenFileMenu2 );
    _pOpenFileMenu2 = NULL;
    }
  if ( _pWindowRestoreMenu )
    {
    _menuServer->UnRegisterItem( _pWindowRestoreMenu );
    _pWindowRestoreMenu = NULL;
    }
  if ( _pEditorMenu )
    {
    _menuServer->UnRegisterItem( _pEditorMenu );
    _pEditorMenu = NULL;
    }

  // Release the 2 servers
  if ( _cmdServer ) 
    {
    _cmdServer->Release();
    _cmdServer = NULL;
    }
  if ( _menuServer ) 
    {
    _menuServer->Release();
    _menuServer = NULL;
    }
  if ( _myMenuClient ) 
    {
    _myMenuClient->Release();
    }
  }
//.............................................................................
BOOL MenuTestA::Init() 
  {
  if ( _startInitFailed )
    {
    OutStr( "MenuTestA was inited at startup but it faiuled" );
    }
  else
    {
    _pWindowMenuItem->AddRef();
    _menuServer->RegisterItem( _pWindowMenuItem, NULL );
    OutStr( "MenuTestA Init()" );
    }
  return TRUE;
}
//.............................................................................
void MenuTestA::UnInit() 
  {
  OutStr( "MenuTestA::UnInit()" );
  }
//.............................................................................
const char * MenuTestA::GetName() 
  {
  return "MenuTestA";
  }
//.............................................................................
const char * MenuTestA::GetTestDescription( int testNum ) 
  {
  switch ( testNum )
    {
    case 1:
      return "Add Addon menus to frame, Window|Restore all, and editor popup menus.";
    case 2:
      return "Toggle command enabler for all addon menu items.";
    case 3:
      return "Toggle editor popup Addon item availability.";
    case 4:
      return "Remove all menus added";
    }
  return "This test not implemented.";
  }  
//.............................................................................
void MenuTestA::DoTest( int testNum ) 
  {
  if ( !_menuServer ) 
    {
    OutStr( "Menu Server not initialized!" );
    return;
    }
  switch ( testNum ) 
    {
    case 1:
      if ( _openFileCmd )
        {
        _pOpenFileMenu1 = _menuServer->CreateItem();
        if ( _pOpenFileMenu1 )
          {
          _openFileCmd->AddRef();
          _pOpenFileMenu1->SetCommand( _openFileCmd );
          _pOpenFileMenu1->SetMenuText( ::MakePolyString ("&Addon|AddOnOpenFile...") );
          _pOpenFileMenu1->SetMenuType( MT_IDE );
          _pOpenFileMenu1->AddRef();
          _menuServer->RegisterItem( _pOpenFileMenu1, NULL );
          }
        _pOpenFileMenu2 = _menuServer->CreateItem();
        if ( _pOpenFileMenu2 )
          {
          _openFileCmd->AddRef();
          _pOpenFileMenu2->SetCommand( _openFileCmd );
          _pOpenFileMenu2->SetMenuText( ::MakePolyString ("&Addon|Another|AddOnOpenFile...") );
          _pOpenFileMenu2->SetMenuType( MT_IDE );
          _pOpenFileMenu2->AddRef();
          _menuServer->RegisterItem( _pOpenFileMenu2, NULL );
          }
        _pWindowRestoreMenu = _menuServer->CreateItem();
        if ( _pWindowRestoreMenu )
          {
          _openFileCmd->AddRef();
          _pWindowRestoreMenu->SetCommand( _openFileCmd );
          _pWindowRestoreMenu->SetMenuText( ::MakePolyString ("&Window|&Restore all|AddOnOpenFile...") );
          _pWindowRestoreMenu->SetMenuType( MT_IDE );
          _pWindowRestoreMenu->AddRef();
          _menuServer->RegisterItem( _pWindowRestoreMenu, NULL );
          }
        _pEditorMenu = _menuServer->CreateItem();
        if ( _pEditorMenu )
          {
          _openFileCmd->AddRef();
          _pEditorMenu->SetCommand( _openFileCmd );
          _pEditorMenu->SetMenuText( ::MakePolyString ("AddOnOpenFile...") );
          _pEditorMenu->SetMenuType( MT_Editor );
          _pEditorMenu->AddRef();
          _menuServer->RegisterItem( _pEditorMenu, _myMenuClient );
          }
        }
      break;
    case 2:
      gCommandsEnabled = !gCommandsEnabled;
      OutStr( FormatStr( "Addon menu commands %s", gCommandsEnabled? "Enabled" : "Disabled" ) );
      break;      
      
    case 3:
      _myMenuClient->MenuAvailable( !_myMenuClient->MenuAvailable() );
      OutStr( FormatStr( "Edit menu AddOn item is %s", 
            _myMenuClient->MenuAvailable()? "Available" : "Unavailable" ) );
      break;
    case 4:
      {
      OutStr( "Removing all AddOn menu items." );
      if ( _pOpenFileMenu1 )
        {
        _menuServer->UnRegisterItem( _pOpenFileMenu1 );
        _pOpenFileMenu1 = NULL;
        }
      if ( _pOpenFileMenu2 )
        {
        _menuServer->UnRegisterItem( _pOpenFileMenu2 );
        _pOpenFileMenu2 = NULL;
        }
      if ( _pWindowRestoreMenu )
        {
        _menuServer->UnRegisterItem( _pWindowRestoreMenu );
        _pWindowRestoreMenu = NULL;
        }
      if ( _pEditorMenu )
        {
        _menuServer->UnRegisterItem( _pEditorMenu );
        _pEditorMenu = NULL;
        }
      }
      break;

    default: 
      {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      }
    }
  }

/*============================================================================

  MenuTestB
  
=============================================================================*/ 

//.......... command enablers ---------------
static BOOL cmd1Enabled = FALSE;
static BOOL cmd2Enabled = TRUE;
static BOOL cmd3Enabled = FALSE;
static BOOL cmd4Enabled = TRUE;


BOOL PASCAL cmd1Enabler() {
  return cmd1Enabled;
} 
BOOL PASCAL cmd2Enabler() {
  return cmd2Enabled;
} 
BOOL PASCAL cmd3Enabler() {
  return cmd3Enabled;
} 
BOOL PASCAL cmd4Enabler() {
  return cmd4Enabled;
} 


//.............................................................................
MenuTestB::MenuTestB() {
  _cmdServer  = GET_INTERFACE(ICommandServer);
  _menuServer = GET_INTERFACE(IMenuServer);
  _cmd1 = _cmdServer->CreateCommand();
  _cmd2 = _cmdServer->CreateCommand();
  _cmd3 = _cmdServer->CreateCommand();
  _cmd4 = _cmdServer->CreateCommand();
  _cmd1->SetName( MakePolyString( "AddonCommand1" ) );
  _cmd2->SetName( MakePolyString( "AddonCommand2" ) );
  _cmd3->SetName( MakePolyString( "AddonCommand3" ) );
  _cmd4->SetName( MakePolyString( "AddonCommand4" ) );
  _cmd1->SetScriptCommand( MakePolyString( "AddonTestCommand1();" ) );
  _cmd2->SetScriptCommand( MakePolyString( "AddonTestCommand2();" ) );
  _cmd3->SetScriptCommand( MakePolyString( "AddonTestCommand3();" ) );
  _cmd4->SetScriptCommand( MakePolyString( "AddonTestCommand4();" ) );
  _cmd1->SetEnableFunction( cmd1Enabler );
  _cmd2->SetEnableFunction( cmd2Enabler );
  _cmd3->SetEnableFunction( cmd3Enabler );
  _cmd4->SetEnableFunction( cmd4Enabler );
  _cmd1->SetHelpHint( MakePolyString( "Help for addon command #1" ) );
  _cmd2->SetHelpHint( MakePolyString( "Help for addon command #2" ) );
  _cmd3->SetHelpHint( MakePolyString( "Help for addon command #3" ) );
  _cmd4->SetHelpHint( MakePolyString( "Help for addon command #4" ) );
  _menu1 = _menuServer->CreateItem();
  _menu2 = _menuServer->CreateItem();
  _menu3 = _menuServer->CreateItem();
  _menu4 = _menuServer->CreateItem();
  _cmd1->AddRef();
  _cmd2->AddRef();
  _cmd3->AddRef();
  _cmd4->AddRef();
  _cmdServer->AddCommand( _cmd1 );
  _cmdServer->AddCommand( _cmd2 );
  _cmdServer->AddCommand( _cmd3 );
  _cmdServer->AddCommand( _cmd4 );
  _cmd1->AddRef();
  _cmd2->AddRef();
  _cmd3->AddRef();
  _cmd4->AddRef();
  _menu1->SetCommand( _cmd1 );
  _menu2->SetCommand( _cmd2 );
  _menu3->SetCommand( _cmd3 );
  _menu4->SetCommand( _cmd4 );
  _menu1->SetMenuText( MakePolyString( "&AddOn Test|Command &1" ) );
  _menu2->SetMenuText( MakePolyString( "&AddOn Test|Command &2" ) );
  _menu3->SetMenuText( MakePolyString( "&AddOn Test|Command &3" ) );
  _menu4->SetMenuText( MakePolyString( "&AddOn Test|Command &4" ) );
  _menu1->SetMenuType( MT_IDE );
  _menu2->SetMenuType( MT_IDE );
  _menu3->SetMenuType( MT_IDE );
  _menu4->SetMenuType( MT_IDE );
}

//.............................................................................
MenuTestB::~MenuTestB() {
  UnInit();
  _menuServer->UnRegisterItem( _menu1 );
  _menuServer->UnRegisterItem( _menu2 );
  _menuServer->UnRegisterItem( _menu3 );
  _menuServer->UnRegisterItem( _menu4 );
  _cmdServer->RemoveCommand( _cmd1 ); 
  _cmdServer->RemoveCommand( _cmd2 ); 
  _cmdServer->RemoveCommand( _cmd3 ); 
  _cmdServer->RemoveCommand( _cmd4 ); 
  _menuServer->Release();
  _cmdServer->Release();
}
//.............................................................................
BOOL MenuTestB::Init()  {
  OutStr( "MenuTestB::Init()" );
  return TRUE;
}
//.............................................................................
void MenuTestB::UnInit() {
  OutStr( "MenuTestB::UnInit()" );
}
//.............................................................................
const char * MenuTestB::GetName() {
  return "MenuTestB";
}
//.............................................................................
const char * MenuTestB::GetTestDescription( int testNum ) {
  switch ( testNum ) {
    case 1:
      return "Add menu Items.";
    case 2:
      return "Toggle enablers.";
  }
  return "This test not implemented.";
}  
//.............................................................................
void MenuTestB::DoTest( int testNum ) {
  switch ( testNum ) {
    case 1:
      OutStr( "Adding menu items." );
      _menu1->AddRef(); 
      _menu2->AddRef(); 
      _menu3->AddRef(); 
      _menu4->AddRef(); 
      _menuServer->RegisterItem( _menu1, NULL );
      _menuServer->RegisterItem( _menu2, NULL );
      _menuServer->RegisterItem( _menu3, NULL );
      _menuServer->RegisterItem( _menu4, NULL );
      break;        
    case 2:
      OutStr( "Toggling enablers." );
      cmd1Enabled = !cmd1Enabled;
      cmd2Enabled = !cmd2Enabled;
      cmd3Enabled = !cmd3Enabled;
      cmd4Enabled = !cmd4Enabled;
      break;            
    default: 
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
  }
}
