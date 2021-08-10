/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   imenu.h
   Created: 11/21/95
   Copyright (c) 1987, 1995 Borland International Inc.  All Rights Reserved.
   $Header:   Y:\admin\bride\addon\deliver\interfac\imenu.h_v   1.16   18 Nov 1996 11:29:38   JDOUGLAS  $
   $Revision:   1.16  $

   Menu Interface
   
   Get an instance of IMenuServer using GET_INTERFACE()
   and use it to create IMenuItem instances for each menu item you wish to
   register. Before registering a menu item, you must set it's command by
   passing in a *registered* ICommand object pointer. When an end-user 
   selects one of your menu items, the script command associated with the 
   ICommand object is called (see icmd.h). 
   
   
   Which menu a menu item will appear on depends on its type (SetMenuType())
   and its text (see the comments below above SetMenuText()).
   
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef _IMENU_H_
#define _IMENU_H_

#include <objbase.h>
#include <ideaddon\icmd.h>
#include <ideaddon\ipolystr.h>
#include <ideaddon\imenu.uid>
#include <ideaddon\common.h>

enum MenuType {
   MT_IDE,           // the IDE frame menu
   MT_Editor,        // right-click popup editor menu
   MT_Project        // right-click project node menu
};

//.............................................................................
class IMenuItem : public IUnknown {
 public:
   //
   // Provide a registered command object using the interfaces in icmd.h.
   // No command need be set if adding a seperator
   //
   virtual void BCWADDON_CMETHOD SetCommand( ICommand * cmd ) = 0;
   
   //
   // For a sub-menu item (one level deep support only) include the parent
   // menu item followed by a vertical bar and the menu item text, using
   // ampersands in the usual way to underline a pick-letter. A seperator
   // item is indicated with a hyphen.
   // 
   // e.g. Sample menu text for a view menu item and submenu:
   // "&View|Grou&cho"
   // "&View|Grou&cho|&Horse"
   // "&View|Grou&cho|-"         // this will become a seperator
   // "&View|Grou&cho|&Feathers"
   //
   virtual void BCWADDON_CMETHOD SetMenuText( IPolyString * menuText ) = 0;
   virtual void BCWADDON_CMETHOD SetMenuType( MenuType type ) = 0;
   
   //
   // When your IMenuClient::AddItemToMenu() is called, you may need 
   // the following methods to retrieve info about the menu item in 
   // question.
   //
   virtual ICommand * BCWADDON_CMETHOD GetCommand() = 0;
   virtual MenuType BCWADDON_CMETHOD GetMenuType() = 0;
};

//.............................................................................
class IMenuClient : public IUnknown {
 public:
   //
   // If you register your IMenuClient-derived object with IMenuServer, 
   // AddItemToMenu() will be called for each menu item you registered
   // whenever a menu is being created that would potentially contain the 
   // menu item. Return TRUE if it is appropriate to add the item to the 
   // menu at the time of this call. In other words, if you want to add
   // a menu item to the project node menu, but only when the user has
   // right-clicked on a particular type of node, you would check the type
   // of the currently selected node before returning TRUE here.
   // 
   // If you don't choose to register an IMenuClient, your registered menu 
   // items will always be added (which may not be appropriate behavior).
   //
   virtual BOOL BCWADDON_CMETHOD AddItemToMenu( IMenuItem * item ) = 0;
};

//.............................................................................
class IMenuServer : public IUnknown {
 public:
   // 
   // Get an instance of an IMenuItem to register.
   //
   virtual IMenuItem * BCWADDON_CMETHOD CreateItem() = 0;
   //    
   // After setting the properties of IMenuItem, register it with the AddOn dll
   // using RegisterItem(). If you pass in a a client, it will be called before
   // the menu item will be put on a menu to give you a chance to disallow it.
   // Pass NULL if you want the item to always be put on the menu. You may
   // choose to pass a single client for all of your menus and handle them all
   // there, or you may pass a new client for each menu.
   // 
   // It is important to defer calling RegisterItem until the IDE has had
   // a chance to assign an internal command id for the command associated
   // with the menu item. If you register your commands at startup time, 
   // wait until you get an initial project open notification (see iproject.h)
   // or a scheduled script has been loaded (you can call back into your dll 
   // from the script to trigger this - see iscript.h for script scheduling)
   // before calling RegisterItem(). All other preperation of the commands
   // and menuitems can be done at startup time.
   //
   virtual void BCWADDON_CMETHOD RegisterItem( IMenuItem * item, IMenuClient * client) = 0;
   //    
   // Use UnRegisterItem() to remove a menu item from the menu system.
   //
   virtual void BCWADDON_CMETHOD UnRegisterItem( IMenuItem * item ) = 0;
};

#endif
