//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of TMDIClient and TMDIFrame classes
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

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TMDIFrame;

//
// class TMDIClient
// ~~~~~ ~~~~~~~~~~
class _OWLCLASS TMDIClient : public virtual TWindow {
  public:
    TMDIClient(TModule* module = 0);
   ~TMDIClient();

    virtual bool        CloseChildren();
    TMDIChild*          GetActiveMDIChild();

    // Member functions to arrange the MDI children
    //
    virtual void        ArrangeIcons();
    virtual void        CascadeChildren();
    virtual void        TileChildren(int tile = MDITILE_VERTICAL);

    // Override member functions defined by TWindow
    //
    bool                PreProcessMsg(MSG& msg);
    bool                Create();

    virtual TWindow*    CreateChild();

    // Constructs a new MDI child window object. By default, constructs an
    // instance of TWindow as an MDI child window object
    //
    virtual TMDIChild*  InitChild();

    LPCLIENTCREATESTRUCT  GetClientAttr();
    void   SetClientAttr(LPCLIENTCREATESTRUCT clientattr);

  protected:
    char far*           GetClassName();

    // Menu command handlers & enabler
    //
    void                CmCreateChild();        // CM_CREATECHILD
    void                CmTileChildren();       // CM_TILECHILDREN
    void                CmTileChildrenHoriz();  // CM_TILECHILDREN
    void                CmCascadeChildren();    // CM_CASCADECHILDREN
    void                CmArrangeIcons();       // CM_ARRANGEICONS
    void                CmCloseChildren();      // CM_CLOSECHILDREN
    void                CmChildActionEnable(TCommandEnabler& commandEnabler);

    TResult             EvMDICreate(MDICREATESTRUCT far& createStruct);
    void                EvMDIDestroy(HWND hWnd);

    void                EvDropFiles(TDropInfo);

  public_data:
    LPCLIENTCREATESTRUCT  ClientAttr;

  private:
    TMDIClient(HWND hWnd, TModule*   module = 0);

    // Hidden to prevent accidental copying or assignment
    //
    TMDIClient(const TMDIClient&);
    TMDIClient& operator =(const TMDIClient&);

  DECLARE_RESPONSE_TABLE(TMDIClient);
  DECLARE_STREAMABLE(_OWLCLASS, TMDIClient, 1);
  friend class TMDIFrame;  // To allow access to private ctor
};

typedef TMDIClient TMdiClient;

//
// class TMDIFrame
// ~~~~~ ~~~~~~~~~
class _OWLCLASS TMDIFrame : virtual public TFrameWindow {
  public:
    TMDIFrame(const char far* title,
              TResId          menuResId,
              TMDIClient&     clientWnd = *new TMDIClient,
              TModule*        module = 0);


    TMDIFrame(THandle frameHandle, HWND clientHandle, TModule* module = 0);

    // Override virtual functions defined by TFrameWindow or TWindow
    //
    bool         SetMenu(HMENU);
#if defined(BI_NO_COVAR_RET)
    TWindow*     GetClientWindow();
#else
    TMDIClient*  GetClientWindow();
#endif
    virtual HWND GetCommandTarget();
    void         PerformCreate(int menuOrId);

    // Find & return the child menu of an MDI frame's (or anyone's) menu bar.
    //
    static HMENU FindChildMenu(HMENU);

  protected:
    // Override to call ::DefFrameProc() instead of ::DefWindowProc()
    //
    TResult      DefWindowProc(uint message, TParam1 param1, TParam2 param2);

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TMDIFrame(const TMDIFrame&);
    TMDIFrame& operator=(const TMDIFrame&);

  DECLARE_RESPONSE_TABLE(TMDIFrame);
  DECLARE_STREAMABLE(_OWLCLASS, TMDIFrame, 1);
};

typedef TMDIFrame TMdiFrame;

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the client create struct for the MDI client.
//
inline LPCLIENTCREATESTRUCT TMDIClient::GetClientAttr() {
  return ClientAttr;
}

//
// Set the client create struct for the MDI client.
//
inline void TMDIClient::SetClientAttr(LPCLIENTCREATESTRUCT clientattr) {
  ClientAttr = clientattr;
}

//
inline void TMDIClient::CmCreateChild() {
  CreateChild();
}

//
inline void TMDIClient::CmTileChildren() {
  TileChildren();
}

//
inline void TMDIClient::CmTileChildrenHoriz() {
  TileChildren(MDITILE_HORIZONTAL);
}

//
inline void TMDIClient::CmCascadeChildren() {
  CascadeChildren();
}

//
inline void TMDIClient::CmArrangeIcons() {
  ArrangeIcons();
}

//
inline void TMDIClient::CmCloseChildren() {
  CloseChildren();
}


#endif  // OWL_MDI_H
