//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
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
//  class TDecoratedFrame
//  ----- ---------------
//
//  automatically positions its client window(you must supply a client window)
//  so that it is the same size as the client rect
//
//  you can add additional decorations like toolbars and status lines
//
class _OWLCLASS TDecoratedFrame : virtual public TFrameWindow, public TLayoutWindow {
  public:
    TDecoratedFrame(TWindow*        parent,
                    const char far* title,
                    TWindow*        clientWnd,
                    bool            trackMenuSelection = false,
                    TModule*        module = 0);

    enum TLocation {Top = 0x0100,  Bottom = 0x0200,
                    Left = 0x0400, Right = 0x0800};

    virtual void  Insert(TWindow& decoration, TLocation = Top);

    //
    // override TFrameWindow member function to give decorations an opportunity
    // to do pre-processing (e.g. mnemonic access)
    //
    bool      PreProcessMsg(MSG& msg);
    TWindow*  SetClientWindow(TWindow* clientWnd);

  protected:
    bool   TrackMenuSelection;
    uint   MenuItemId;

    void      SetupWindow();

    void      RemoveChild(TWindow* child);
    
    //
    // automatic showing/hiding of tool bars and status bars
    //
    LRESULT   EvCommand(uint id, HWND hWndCtl, uint notifyCode);
    void      EvCommandEnable(TCommandEnabler& ce);

    //
    // message response functions
    //
    void      EvMenuSelect(uint menuItemId, uint flags, HMENU hMenu);
    void      EvEnterIdle(uint source, HWND hWndDlg);
    void      EvSize(uint sizeType, TSize& size) {TLayoutWindow::EvSize(sizeType, size);}

  private:
    void      InsertAtTop(TWindow& decoration, TWindow* insertAbove);
    void      InsertAtBottom(TWindow& decoration, TWindow* insertBelow);
    void      InsertAtLeft(TWindow& decoration, TWindow* insertLeftOf);
    void      InsertAtRight(TWindow& decoration, TWindow* insertRightOf);

    bool      SettingClient;

    //
    // hidden to prevent accidental copying or assignment
    //
    TDecoratedFrame(const TDecoratedFrame&);
    TDecoratedFrame& operator =(const TDecoratedFrame&);

  DECLARE_RESPONSE_TABLE(TDecoratedFrame);
  DECLARE_STREAMABLE(_OWLCLASS, TDecoratedFrame, 1);
};

#endif  // OWL_DECFRAME_H
