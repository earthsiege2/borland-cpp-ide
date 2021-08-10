/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  icmd.h
  Created: 08/28/95
  Copyright (c) 1995, Borland International
  $Revision:   1.13  $

  command interface 
  
  Register a command with the IDE and supply an optional tool bar icon for it.
  To make the command available from a menu, use the registered command to
  create a menu item on one or more of the IDE's menus (see imenu.h).
  
  To register a command, at startup time, get an instance of ICommandServer
  (through GET_INTERFACE()) and call CreateCommand to get a new command. Fill
  in the command with the desired params then add it to the IDE with
  AddCommand.
  
  All IDE commands are routed through script, allowing end-users the ability
  to customize the application. It is therefore necessary to supply a script
  command string that will be executed when your command is selected either
  through a menu or a tool bar button. You can expose dll functions to script
  in order to establish a communication path back to your addon application.
  
  So, if the script command is "JazzyAddOnOpenView()" and the dll callback
  signature is: void OpenView( void ), then your script would contain:
  
  import "jazadon.dll" {
    void OpenView( void );
    ... // other exposed methods of jazadon.dll
  }
  
  JazzyAddOnOpenView() {
    OpenView();
  }

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef _ICMD_H_
#define _ICMD_H_

#include <objbase.h>
#include <ideaddon\ipolystr.h>
#include <ideaddon\icmd.uid>

//
// Function prototype of enable function that is set by SetEnableFunction
//
typedef BOOL PASCAL (*CmdEnableFunc)(void);

//.............................................................................
class ICommand : public IUnknown {
 public:
  virtual void SetName( IPolyString * name ) = 0;  // unique string identifier
  virtual void SetDescription( IPolyString * desc ) = 0;
  virtual void SetScriptCommand( IPolyString * script ) = 0;
  virtual void SetToolTip( IPolyString * toolTip ) = 0;
  virtual void SetHelpHint( IPolyString * helpHint ) = 0;
  virtual void SetHelpId( DWORD helpId ) = 0;
  virtual void SetHelpFile( IPolyString * helpFile ) = 0;
  virtual void SetIcons( HBITMAP smallBmp, HBITMAP largeBmp, DWORD offset = 0 ) = 0;
  virtual void SetEnableFunction( CmdEnableFunc ceFunc ) = 0;
  virtual void SetUserData( DWORD userData ) = 0;
  
  virtual DWORD GetUserData() = 0;
};
//.............................................................................
class ICommandServer : public IUnknown {
 public:
  virtual ICommand * CreateCommand() = 0;
  //
  // The continuosQueryEnable flag will request that the enable function
  // be called during idle time.
  //
  virtual void AddCommand( ICommand * cmd, BOOL continuousQueryEnable = FALSE ) = 0;
  virtual void RemoveCommand( ICommand * cmd ) = 0;
};

#endif
