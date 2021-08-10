/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  iview.h
  Created: 11/01/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $
  
  Overview:

  For each type of view window you would like the IDE to manage:

  1) Derive a class from IUserViewFactory and implement its CreateView()
    method. Your CreateView() implementation should return a pointer to
    an instance of a new IViewClient-derived class.

  2) At startup time, get an instance of the IViewType interface using 
    helper function "CreateViewType" and call its Init() function to 
    register it with the IDE. Hold on to the IViewType pointer, you'll
    need it later to create an instance of the view.

  For each view window you wish to create:

  1) Call the IViewType::CreateInstance() function. The IDE will call you
    back through your IUserViewFactory::CreateView() method, at which time
    you should create a child window using the parent hwnd which is 
    available through the passed in IViewParentWnd's GetHwnd() method. Return
    a pointer to a new instance of your IViewClient-derived class.

  2) Manipulate the parent window through the IViewParentWnd interface which 
    was passed in through IUserViewFactory's CreateView() method.
   
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __IVIEW_H
#define __IVIEW_H

#include <ideaddon\ipolystr.h>
#include <ideaddon\iview.uid>

//
// These are menu or toolbar commands that want to be enabled based on the
// active view. 
//

#define CMD_SEND    "FileSendMail"
#define CMD_SELECTALL "EditSelectAll"
#define CMD_CUT    "EditCut"
#define CMD_CLEAR   "EditClear"
#define CMD_COPY    "EditCopy"
#define CMD_PASTE   "EditPaste"
#define CMD_UNDO    "EditUndo"
#define CMD_REDO    "EditRedo"

#define CMD_FIND       "SearchFind"
#define CMD_REPLACE    "SearchReplace"
#define CMD_SEARCHAGAIN "SearchAgain"

#define CMD_CLOSE     "FileClose"
#define CMD_SAVE       "FileSave"
#define CMD_SAVEAS      "FileSaveas"
#define CMD_PRINT     "FilePrint"

//
// return values of CommandSupported()
//
#define CMD_UNKNOWN     -1
#define CMD_UNAVAILABLE   0
#define CMD_AVAILABLE    1
//
// IDE Regions can be defined by an end-user through script. These are 
// managed areas. A cascade or tile command will result in the open views of 
// each region being grouped together within the region boundaries. The
// following string ID's are used to associate an add-on view with the region
// assigned to the named view type. For example, if your add-on view wants to
// get tiled and cascaded along with editor views, then register it using
// VIEWREGION_EDITOR (see IViewManagerServer::RegisterView()).
//

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
  // You must return the HWND of the view window associated with this
  // object.
  //
  virtual HWND  GetHwnd() = 0;
  //
  // These methods are called by the IDE when it is ready to take
  // your restore data. Return 0 from GetRestoreDataLen() if you
  // don't wish to be restored when the project is re-opened. 
  //
  virtual long  GetRestoreDataLen() = 0;
  virtual void* GetRestoreData() = 0;
  //
  // If your view is 'dirty', you should ask the user the appropriate
  // questions and either save or discard data associated with the 
  // view. Returning FALSE will cancel the window close.
  //
  virtual BOOL  CanClose() = 0;

  // 
  // Each view will be asked if it supports a polymorphic command such as "Save"
  // when the appropriate menu is opened or in some cases on a regular basis 
  // to allow tool bar buttons to be in the proper state when a view is 
  // active.
  // 
  virtual unsigned CommandSupported( IPolyString* ) = 0;

  //
  // If CommandSupported() returns TRUE for a particular polymorphic command,
  // the ExecuteCommand() method may be called.
  //
  virtual void ExecuteCommand( IPolyString* ) = 0;
  //
  // This method is called when the view property changed
  //
  virtual void PropertyChangeNotify() = 0;
};

//.............................................................................
//
// Whenever your IUserViewFactory-derived CreateView() is called, it is handed
// an IViewParentWnd pointer. You will need its GetHwnd() method to set it
// as the parent of the window you are about to create. You can use its other
// methods to manipulate the parent window's attributes. You should use these
// methods instead of the Windows API whenever possible.
//
struct IViewParentWnd : public IUnknown {
public:
  virtual HWND       GetHwnd() = 0;
  virtual void       Activate() = 0;
  virtual void       Move(int left, int top, int width, int height ) = 0;
  virtual void       Display() = 0;
  virtual void       SetTitle( IPolyString * title ) = 0;
  virtual IViewClient*  GetViewClient() = 0;
  virtual void       UpdateModifyState() = 0;
};

//.............................................................................
//
// Derive a class from IUserViewFactory for each type of view you intend to 
// register with the IDE.
//
struct IUserViewFactory : public IUnknown {
public:
  //
  // CreateView() will be called in response to an IViewType::CreateInstance()
  // call. Create your window as a child of wndServer->GetHwnd(). Return
  // a new instance of your IViewClient-derived class to describe the new
  // view window to the caller.
  //
  // If you are being asked to restore a view from a previous project 
  // session, restoreData will be non-null and is a pointer to a copy
  // of the persistence data you passed to the ide in response to an
  // IViewClient::GetRestoreData() request.
  // 
  // Remember that the caller of createView owns the restoreData memory 
  // block, so you should copy it if you intend to use it after returning 
  // from this function call.
  //
  virtual IViewClient * CreateView(IViewParentWnd * wndServer,
                                void * restoreData = NULL ) = 0;
  //
  // call client to register properties
  //
  virtual void InitializeProperty(IViewType* viewType) = 0;
};

//.............................................................................
//
// This interface is used to register your view types and to instantiate new
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
  virtual BOOL Init(IUserViewFactory * viewFactory,
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
  virtual IViewParentWnd* CreateInstance(IPolyString* title) = 0;

  //
  // If the view permits font and color selection, register its defaults
  // here. Both the viewTypeName and propName will appear in the 
  // environment/options/fonts dialog box and will be passed back to you 
  // through the IViewClient SetFont() and SetColor() callbacks. Once you 
  // set the initial property here, the IDE will call the set functions when 
  // the user requests a change and it will keep track of the on-going state 
  // for each property. This should be called after Init() at startup time.
  //
  virtual void InitFontAndColorProperty(  IPolyString * propName, 
                                    IPolyString * fontName,
                                    int fontSize,
                                    FontAttribute attrib,
                                    DWORD foreColor,
                                    DWORD backColor ) = 0;

  virtual IPolyString*  GetFontName(IPolyString * propName) = 0;
  virtual int       GetFontSize(IPolyString * propName) = 0;
  virtual int       GetFontAttribute(IPolyString * propName) = 0;
  virtual DWORD     GetForegroundColor(IPolyString * propName) = 0;
  virtual DWORD     GetBackgroundColor(IPolyString * propName) = 0;
};



struct IViewFile : IUnknown  {
  // class TIFileSave
  virtual BOOL IsDirty() = 0;
  virtual BOOL Save() = 0;

  //  class TIFileSaveAs
  virtual BOOL SaveAs(IPolyString* FileName) = 0;

  //  class TIFileClose
  virtual BOOL Close() = 0;

  // class TIFilePrint
  virtual BOOL Print(BOOL noDialogs) = 0;
};

#endif //  __IVIEW_H
