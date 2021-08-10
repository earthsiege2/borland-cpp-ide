//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Definition of class TDecoratedFrame, a TFrameWindow that can manage
// decorations around the client window.
//----------------------------------------------------------------------------
#if !defined(OWL_DECFRAME_H)
#define OWL_DECFRAME_H

#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_LAYOUTWI_H)
# include <owl/layoutwi.h>
#endif

const int IDW_TOOLBAR       = 32041;  // Standard toolbar child window ID

//
// General use absolute 2-D rectangular location enum
// [Used mainly to describe the locations of a gadgetwindow, such a toolbar
//  or statusbar, within a decorated frame]
//
enum TAbsLocation {
  alNone   = 0,          // No location specified
  alTop    = 1,          // Refers to top edge of frame
  alBottom = 2,          // Refers to bottom edge of frame
  alLeft   = 3,          // Refers to left edge of frame
  alRight  = 4,          // Refers to right edge of frame
};

//
// enum THintText
// ~~~~~~~~~~~~~~
enum THintText {
  htStatus    = 0x0001,         // Text displayed on status bar
  htTooltip   = 0x0002,         // Shorter text displayed in a tooltip
  htUserDefined                 // Can be used when enhancing 'GetHintText'
};                              // to support balloon text etc..

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TDecoratedFrame
// ~~~~~ ~~~~~~~~~~~~~~~
// Automatically positions its client window so that it is the same size as
// the client rect
//
// You can add additional decorations like toolbars and status lines
//
class _OWLCLASS TDecoratedFrame : virtual public TFrameWindow,
                                          public TLayoutWindow {
  public:
    TDecoratedFrame(TWindow*        parent,
                    const char far* title,
                    TWindow*        clientWnd,
                    bool            trackMenuSelection = false,
                    TModule*        module = 0);

    // Enumeration describing the possible locations of a Gadgetwindow
    // [Used mainly for location of Toolbar and Statusbar standalone
    //  and in the context of docking windows]
    //
    enum TLocation {
      None   = alNone,            // No location specified
      Top    = alTop,             // Refers to top edge of frame
      Bottom = alBottom,          // Refers to bottom edge of frame
      Left   = alLeft,            // Refers to left edge of frame
      Right  = alRight,           // Refers to right edge of frame
    };
//    typedef TAbsLocation TLocation;

    virtual void  Insert(TWindow& decoration, TLocation location = Top);

    // Hint/Status/Tip text
    //
    virtual int     GetHintText(uint id, char* buf, int size,
                                THintText hintType) const;

    // Override TFrameWindow member function to give decorations an opportunity
    // to do pre-processing (e.g. mnemonic access)
    //
    bool      PreProcessMsg(MSG& msg);
    TWindow*  SetClientWindow(TWindow* clientWnd);

  protected:
    bool      GetTrackMenuSelection() const;
    void      SetTrackMenuSelection(bool tr=true);

    uint      GetMenuItemId() const;
    void      SetMenuItemId(uint menuitemid);

    // Override TWindow virtuals
    //
    void      SetupWindow();
    void      RemoveChild(TWindow* child);

    // Automatic showing/hiding of tool bars and status bars
    //
    TResult   EvCommand(uint id, HWND hWndCtl, uint notifyCode);
    void      EvCommandEnable(TCommandEnabler& ce);

    // Message response functions
    //
    void      EvMenuSelect(uint menuItemId, uint flags, HMENU hMenu);
    void      EvEnterIdle(uint source, HWND hWndDlg);
    void      EvSize(uint sizeType, TSize& size);

  protected_data:
    bool      TrackMenuSelection;       // track menu select for status hints?
    uint      MenuItemId;               // id of current menu selection

  private:
    void      InsertAtTop(TWindow& decoration, TWindow* insertAbove);
    void      InsertAtBottom(TWindow& decoration, TWindow* insertBelow);
    void      InsertAtLeft(TWindow& decoration, TWindow* insertLeftOf);
    void      InsertAtRight(TWindow& decoration, TWindow* insertRightOf);

    bool      SettingClient;

    // Hidden to prevent accidental copying or assignment
    //
    TDecoratedFrame(const TDecoratedFrame&);
    TDecoratedFrame& operator =(const TDecoratedFrame&);

  DECLARE_RESPONSE_TABLE(TDecoratedFrame);
  DECLARE_STREAMABLE(_OWLCLASS, TDecoratedFrame, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Returns true if the decorated frame is tracking the menu selections.
// Sends a message to the status bar to display the hint text.
//
inline bool
TDecoratedFrame::GetTrackMenuSelection() const {
  return TrackMenuSelection;
}

//
// Set the flag for tracking menu selection.
//
inline void
TDecoratedFrame::SetTrackMenuSelection(bool tr) {
  TrackMenuSelection = tr;
}

//
// Return cached id of the current menu item.
//
inline uint
TDecoratedFrame::GetMenuItemId() const {
  return MenuItemId;
}

//
// Set the cached id of the current menu item.
//
inline void
TDecoratedFrame::SetMenuItemId(uint menuitemid) {
  MenuItemId = menuitemid;
}

#endif  // OWL_DECFRAME_H
