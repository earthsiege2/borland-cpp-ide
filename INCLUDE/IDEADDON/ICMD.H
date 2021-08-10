/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	icmd.h
	Created: 08/28/95
	Copyright (c) 1995, Borland International
	$Header:   Y:\admin\bride\addon\deliver\interfac\icmd.h_v   1.18   18 Nov 1996 11:29:22   JDOUGLAS  $
	$Revision:   1.18  $

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
      ...   // other exposed methods of jazadon.dll
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
#include <ideaddon\common.h>

//
//	Function prototype of enable function that is set by SetEnableFunction
//
typedef BOOL PASCAL (*CmdEnableFunc)(void);

//.............................................................................
class ICommand : public IUnknown {
 public:
	virtual void BCWADDON_CMETHOD SetName( IPolyString * name ) = 0;    // unique string identifier
	virtual void BCWADDON_CMETHOD SetDescription( IPolyString * desc ) = 0;
	virtual void BCWADDON_CMETHOD SetScriptCommand( IPolyString * script ) = 0;
	virtual void BCWADDON_CMETHOD SetToolTip( IPolyString * toolTip ) = 0;
	virtual void BCWADDON_CMETHOD SetHelpHint( IPolyString * helpHint ) = 0;
	virtual void BCWADDON_CMETHOD SetHelpId( DWORD helpId ) = 0;
	virtual void BCWADDON_CMETHOD SetHelpFile( IPolyString * helpFile ) = 0;
   //
   // SetIcons() is provided for commands that wish to appear in the speedbar
   // editor. If this method is not called for a particular command, it will
   // not appear in the speedbar editor (Options|Environment).
   //
	virtual void BCWADDON_CMETHOD SetIcons( HBITMAP smallBmp, HBITMAP largeBmp, DWORD offset = 0 ) = 0;
   virtual void BCWADDON_CMETHOD SetEnableFunction( CmdEnableFunc ceFunc ) = 0;
   virtual void BCWADDON_CMETHOD SetUserData( DWORD userData ) = 0;
   
   virtual DWORD BCWADDON_CMETHOD GetUserData() = 0;
};
//.............................................................................
class ICommandServer : public IUnknown {
 public:
	virtual ICommand * BCWADDON_CMETHOD CreateCommand() = 0;
   //
   // The continuosQueryEnable flag will request that the enable function
   // be called during idle time.
   //
	virtual void BCWADDON_CMETHOD AddCommand( ICommand * cmd, BOOL continuousQueryEnable = FALSE ) = 0;
	virtual void BCWADDON_CMETHOD RemoveCommand( ICommand * cmd ) = 0;
};

#endif



