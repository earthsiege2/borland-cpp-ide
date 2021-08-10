//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Definition of TMDIClient and TMDIFrame classes
//----------------------------------------------------------------------------
#if !defined(OWL_MDI_H)
#define OWL_MDI_H

#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_MDICHILD_H)
# include <owl/mdichild.h>
#endif
#include <owl/mdi.rh>

class _OWLCLASS TMDIFrame;

//
//  class TMDIClient
//  ----- ----------
//
class _OWLCLASS TMDIClient : public virtual TWindow {
  public:
    LPCLIENTCREATESTRUCT  ClientAttr;

    TMDIClient(TModule* module = 0);
   ~TMDIClient();

    virtual bool        CloseChildren();

    TMDIChild*          GetActiveMDIChild();

    //
    // member functions to arrange the MDI children
    //
    virtual void        ArrangeIcons();
    virtual void        CascadeChildren();
    virtual void        TileChildren(int tile = MDITILE_VERTICAL);

    //
    // override member functions defined by TWindow
    //
    bool                PreProcessMsg(MSG& msg);
    bool                Create();

    virtual TWindow*    CreateChild();

    //
    // constructs a new MDI child window object. by default, constructs an
    // instance of TWindow as an MDI child window object
    //
    // will almost always be overriden by derived classes to construct an
    // instance of a user-defined TWindow derived class as an MDI child window
    // object
    //
    virtual TMDIChild*  InitChild();

  protected:
    char far*           GetClassName();

    //
    // menu command handlers & enabler
    //
    void                CmCreateChild() {CreateChild();}  // CM_CREATECHILD
    void                CmTileChildren() {TileChildren();}  // CM_TILECHILDREN
    void                CmTileChildrenHoriz() {TileChildren(MDITILE_HORIZONTAL);}  // CM_TILECHILDREN
    void                CmCascadeChildren() {CascadeChildren();}  // CM_CASCADECHILDREN
    void                CmArrangeIcons() {ArrangeIcons();}  // CM_ARRANGEICONS
    void                CmCloseChildren() {CloseChildren();}  // CM_CLOSECHILDREN
    void                CmChildActionEnable(TCommandEnabler& commandEnabler);

    LRESULT             EvMDICreate(MDICREATESTRUCT far& createStruct);
    void                EvMDIDestroy(HWND hWnd);

  private:
    friend class TMDIFrame;
    TMDIClient(HWND hWnd, TModule*   module = 0);

    //
    // hidden to prevent accidental copying or assignment
    //
    TMDIClient(const TMDIClient&);
    TMDIClient& operator =(const TMDIClient&);

  DECLARE_RESPONSE_TABLE(TMDIClient);
  DECLARE_STREAMABLE(_OWLCLASS, TMDIClient, 1);
};

//
//  class TMDIFrame
//  ----- ---------
//
class _OWLCLASS TMDIFrame : virtual public TFrameWindow {
  public:
    TMDIFrame(const char far* title,
              TResId          menuResId,
              TMDIClient&     clientWnd = *new TMDIClient,
              TModule*        module = 0);


    TMDIFrame(HWND hWindow, HWND clientHWnd, TModule*   module = 0);

    //
    // override virtual functions defined by TFrameWindow or TWindow
    //
    bool         SetMenu(HMENU);
    TMDIClient*  GetClientWindow();
    virtual HWND GetCommandTarget();
    void         PerformCreate(int menuOrId);

    //
    // find & return the child menu of an MDI frame's (or anyone's) menu bar.
    //
    static HMENU FindChildMenu(HMENU);

  protected:
    //
    // call ::DefFrameProc() instead of ::DefWindowProc()
    //
    LRESULT      DefWindowProc(uint message, WPARAM wParam, LPARAM lParam);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TMDIFrame(const TMDIFrame&);
    TMDIFrame& operator=(const TMDIFrame&);

  DECLARE_RESPONSE_TABLE(TMDIFrame);
  DECLARE_STREAMABLE(_OWLCLASS, TMDIFrame, 1);
};

#endif  // OWL_MDI_H
