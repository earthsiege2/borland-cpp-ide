/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  iview.h
  Created: 11/01/95
  Copyright (c) 1995, Borland International
  $Header:   Y:\admin\bride\addon\deliver\interfac\iview.h_v   1.20   18 Nov 1996 11:30:14   JDOUGLAS  $
  $Revision:   1.20  $
    
 Interfaces declared in this file:

 implemented by IDE

    IViewParentWnd
    IViewType

 implemented by IDE client

    IViewClient
    IViewFile
    IUserViewFactory

Overview:

 Assuming client has impelemented IUserViewFactory and IViewClient interfaces.
 View is initialized in the following order:

  1) Create IUserViewFactory and IViewType.
     Register IUserViewFactory by calling IViewTye::Init() during startup.

  2) IDE calls IUserViewFactory::InitializeProperty() during startup.
     If you have any properties you need to initialize at this point, you can 
     call IViewType::InitFontAndColorProperty() now.
     IViewClient::PropertyChangeNotify() is called when user change any
     properties register. Adon client should call IViewType::Get*() to retrieve
     the new property value.  Unfortunately, thie notification does not tell
     you which property has changed, so you have to check every property that
     can be changed.

  3) Call IViewType::CreateInstance() to create a IViewClient.
     IViewType::CreateInstance() calls IUserViewFactory::CreateView()
     to return a IViewClient.
     Client can call IViewParentWnd::GetHwnd to get a valid window handle here.
     NOTE: An addon client never calls IUserViewFactory::CreateView().

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 

#ifndef __IVIEW_H
#define __IVIEW_H

#include <ideaddon\ipolystr.h>
#include <ideaddon\iview.uid>
#include <ideaddon\common.h>

//
// These are menu or toolbar commands that want to be enabled based on the
// active view. 
//

#define CMD_SEND      "FileSendMail"
#define CMD_SELECTALL "EditSelectAll"
#define CMD_CUT       "EditCut"
#define CMD_CLEAR     "EditClear"
#define CMD_COPY      "EditCopy"
#define CMD_PASTE     "EditPaste"
#define CMD_UNDO      "EditUndo"
#define CMD_REDO      "EditRedo"

#define CMD_FIND          "SearchFind"
#define CMD_REPLACE       "SearchReplace"
#define CMD_SEARCHAGAIN   "SearchAgain"

#define CMD_CLOSE         "FileClose"
#define CMD_SAVE          "FileSave"
#define CMD_SAVEAS        "FileSaveas"
#define CMD_PRINT         "FilePrint"

//
// return values of CommandSupported()
//
#define CMD_UNKNOWN        -1
#define CMD_UNAVAILABLE     0
#define CMD_AVAILABLE       1


enum FontAttribute {
  FA_Bold = 1,
  FA_Italic = 2,
  FA_Underline =4
};

//
// forward declaration
//
struct IViewType;

//.............................................................................
struct IViewClient : public IUnknown {
 public:
  //
  //  You must return the HWND of the view window associated with this
  // object.
  //
  virtual HWND BCWADDON_CMETHOD GetHwnd() = 0;
  //
  //  These methods are called by the IDE when it is ready to take
  // your restore data. Return -1 from GetRestoreDataLen() if you
  // don't wish to be restored when the project is re-opened. 
  //
  virtual long  BCWADDON_CMETHOD GetRestoreDataLen() = 0;
  virtual void* BCWADDON_CMETHOD GetRestoreData() = 0;
  //
  //  If your view is 'dirty', you should ask the user the appropriate
  // questions and either save or discard data associated with the 
  // view. Returning FALSE will cancel the window close.
  //
  virtual BOOL BCWADDON_CMETHOD CanClose() = 0;

  // 
  // Each view will be asked if it supports a polymorphic command such as "Save"
  // when the appropriate menu is opened or in some cases on a regular basis 
  // to allow tool bar buttons to be in the proper state when a view is 
  // active.
  // 
  virtual unsigned BCWADDON_CMETHOD CommandSupported( IPolyString* ) = 0;

  //
  //  If CommandSupported() returns TRUE for a particular polymorphic command,
  // the ExecuteCommand() method may be called.
  // See IviewFile for File menu command processing.
  //
  virtual void BCWADDON_CMETHOD ExecuteCommand( IPolyString* ) = 0;
  //
  // This method is called when the view property changed
  //
  virtual void BCWADDON_CMETHOD PropertyChangeNotify() = 0;
};


//
// IViewFile is used to support the following polymorphic command
//      CMD_CLOSE, CMD_SAVE ,CMD_SAVEAS adn CMD_PRINT.
// These commands are not invoked thru IViewClient::ExecuteCommand()
//
// It should be returned by IViewClient if client want to support any
// file menu commnad processing.
//
//
struct IViewFile : IUnknown  {
  // class TIFileSave
  virtual BOOL BCWADDON_CMETHOD IsDirty() = 0;
  virtual BOOL BCWADDON_CMETHOD Save() = 0;

  //  class TIFileSaveAs
  virtual BOOL BCWADDON_CMETHOD SaveAs(IPolyString* FileName) = 0;

  //  class TIFileClose
  virtual BOOL BCWADDON_CMETHOD Close() = 0;

  // class TIFilePrint
  virtual BOOL BCWADDON_CMETHOD Print(BOOL noDialogs) = 0;
};


//.............................................................................
//
//  Whenever your IUserViewFactory-derived CreateView() is called, it is handed
// an IViewParentWnd pointer. You will need its GetHwnd() method to set it
// as the parent of the window you are about to create. You can use its other
// methods to manipulate the parent window's attributes. You should use these
// methods instead of the Windows API whenever possible.
//
struct IViewParentWnd : public IUnknown {
  virtual HWND BCWADDON_CMETHOD GetHwnd() = 0;
  virtual void BCWADDON_CMETHOD Activate() = 0;
  virtual void BCWADDON_CMETHOD Move(int left, int top, int width, int height ) = 0;
  virtual void BCWADDON_CMETHOD Display() = 0;
  virtual void BCWADDON_CMETHOD SetTitle( IPolyString * title ) = 0;
  virtual IViewClient* BCWADDON_CMETHOD GetViewClient() = 0;
  virtual void BCWADDON_CMETHOD UpdateModifyState() = 0;
};

//.............................................................................
//
//  Derive a class from IUserViewFactory for each type of view you intend to 
// register with the IDE.
//
struct IUserViewFactory : public IUnknown {
public:
  //
  //  CreateView() will be called in response to an IViewType::CreateInstance()
  // call. Create your window as a child of wndServer->GetHwnd(). Return
  // a new instance of your IViewClient-derived class to describe the new
  // view window to the caller.
  //
  //  If you are being asked to restore a view from a previous project 
  // session, restoreData will be non-null and is a pointer to a copy
  // of the persistence data you passed to the ide in response to an
  // IViewClient::GetRestoreData() request.
  // 
  // Remember that the caller of createView owns the restoreData memory 
  // block, so you should copy it if you intend to use it after returning 
  // from this function call.
  //
  virtual IViewClient * BCWADDON_CMETHOD CreateView(IViewParentWnd * wndServer,
                                  void * restoreData = NULL ) = 0;
  //
  // call client to register properties
  //
  virtual void BCWADDON_CMETHOD InitializeProperty(IViewType* viewType) = 0;
};

//.............................................................................
//
//  This interface is used to register your view types and to instantiate new
// view windows. At IDE startup time, use helper function "CreateViewType" to 
// get an IViewType pointer for each view you need to register with the IDE. 
//
struct IViewType : public IUnknown {
  //
  // After getting an IViewType pointer, use Init() to register the ViewType's
  // properties. 
  // 
  // viewFactory: See the comments above under IUserViewFactory
  // viewTypeName: This must be unique name for the view, if it is already
  // registered with the IDE, Init will return FALSE.
  //
  virtual BOOL BCWADDON_CMETHOD Init(IUserViewFactory * viewFactory,
                    IPolyString* viewType, 
                    int left,
                    int top,
                    int right,
                    int bottom,
                    HINSTANCE hInstance = 0, 
                    DWORD iconResourceId = 0 ) = 0;

  //
  // Call CreateInstance() for each new view you wish to create. Your 
  // IUserViewFactory::CreateView() method will be called while inside
  // this method.
  //
  virtual IViewParentWnd* BCWADDON_CMETHOD CreateInstance(IPolyString* title) = 0;

  //
  //  If the view permits font and color selection, register its defaults
  // here. Both the viewTypeName and propName will appear in the 
  // environment/options/fonts dialog box and will be passed back to you 
  // through the IViewClient SetFont() and SetColor() callbacks. Once you 
  // set the initial property here, the IDE will call the set functions when 
  // the user requests a change and it will keep track of the on-going state 
  // for each property. This should be called after Init() at startup time.
  //
  virtual void BCWADDON_CMETHOD InitFontAndColorProperty(  IPolyString * propName, 
                                          IPolyString * fontName,
                                          int fontSize,
                                          FontAttribute attrib,
                                          DWORD foreColor,
                                          DWORD backColor ) = 0;

   virtual IPolyString* BCWADDON_CMETHOD GetFontName(IPolyString * propName) = 0;
   virtual int BCWADDON_CMETHOD GetFontSize(IPolyString * propName) = 0;
   virtual int BCWADDON_CMETHOD GetFontAttribute(IPolyString * propName) = 0;
   virtual DWORD BCWADDON_CMETHOD GetForegroundColor(IPolyString * propName) = 0;
   virtual DWORD BCWADDON_CMETHOD GetBackgroundColor(IPolyString * propName) = 0;
};

//.............................................................................
// IViewType2 is new as of BCW version 5.01. To get a pointer to this
// interface, query the IViewType interface returned from the IDEServer
// or through the CreateViewType() helper function. Be prepared to downgrade
// gracefully if this interface isn't available. Here's an example:
// 
//  IViewType * viewType = ::CreateViewType();
//  if ( viewType ) {
//    viewType->Init( myViewFactory, ::MakePolyString( "MyView" ), 0, 100, 100, 100 );
//    // you can call other IViewType methods using 'viewType'here
// 
//    IViewType2 * viewType2 = QUERY_INTERFACE( viewType, IViewType2 );
//    if ( viewType2 ) {
//      viewType2->SetDisplayName( ::MakePolyString( "MyDisplayName" ) );
//      // you can call other IViewType or IViewType2 methods using 'viewType2'
//    }
//  }
//  
//
struct IViewType2 : public IViewType {
 public:
  //
  // SetDisplayName(). The DisplayName is a string that will be used in the 
  // list of views for speedbar customization and per-view font optons (see
  // Environment|Options in the IDE).If you don't use SetDisplayName, the 
  // ViewType string passed to IViewType::Init() is used.
  // 
  virtual void BCWADDON_CMETHOD SetDisplayName( IPolyString * displayName ) = 0;
  //
  // SetFamilyName(). The FamilyName should be a unique string which is used
  // to group one or more views together. This determines which views will
  // be grouped together for things such as the Window|Close All sub-menu.
  //
  virtual void BCWADDON_CMETHOD SetFamilyName( IPolyString * familyName ) = 0;
  //
  // SetDisplayFamilyName(). DisplayFamilyName is what the end-user will 
  // see whenever FamilyNames are displayed. If this is not set, the 
  // FamilyName string will be displayed. 
  //
  virtual void BCWADDON_CMETHOD SetDisplayFamilyName( IPolyString * displayFamilyName ) = 0;  
};


#endif //  __IVIEW_H
