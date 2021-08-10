//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.14  $
//
// Definition of Pane Splitter classes
//----------------------------------------------------------------------------
#if !defined(OWL_PANESPLI_H)
#define OWL_PANESPLI_H

#if !defined(OWL_SPLITTER_H)
# include <owl/splitter.h>
#endif
#if !defined(OWL_PANESPLI_RH)
# include <owl/panespli.rh>
#endif
#if !defined(CLASSLIB_LISTIMP_H)
# include <classlib/listimp.h>
#endif
#if !defined(CLASSLIB_ALLOCTR_H)
# include <classlib/alloctr.h>
#endif
#if !defined(CLASSLIB_MEMMGR_H)
# include <classlib/memmgr.h>
#endif

//
// Define macro [missing from 16-bit headers]used by PANESPLI.CPP
//
#if !defined(IDC_SIZEALL)
# define IDC_SIZEALL         MAKEINTRESOURCE(32646)
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// ObjectWindows provides explicitly instantiation of these templates [see
// TMPLINST.CPP]. Provide an '__import' version so that modules using the OWL
// DLL rely on the code generated within ObjectWindows.
//
#if defined(BI_COMP_BORLANDC)
# if defined(_OWLDLL) && !defined(_BUILDOWLDLL)
    template class _OWLCLASS TMListElement<TVoidPointer, TStandardAllocator>;
    template class _OWLCLASS TMListBlockInitializer<TVoidPointer, TStandardAllocator>;
    template class _OWLCLASS TMListImp<TVoidPointer, TStandardAllocator>;
# endif
#endif

//
// class TPaneSplitter
// ~~~~~ ~~~~~~~~~~~~~
// TPaneSplitter is a class that acts as a container for child windows (called
// panes) and splitters (pane mover, separator).  Supports operatations for
// manipulating panes (add, remove, move, resize, etc) and splitters (drawing,
// width, etc).  Splitters can be moved (thus resizing the panes) by function
// call or mouse input.  Using the mouse, multiple splitters could be moved
// at once. The splitter width indicates the width of the separators and the 
// splitter cushion is the minimum distance btwn separators (to prevent 
// accidental closure of panes).
//
class _OWLCLASS TPaneSplitter : public TLayoutWindow
{
  public:
    typedef TShouldDelete::TDelete TDelete;

    TPaneSplitter(TWindow*        parent,
                  const char far* title = 0,
                  int             splitterWidth = 0,
                  TModule*        module = 0);
   ~TPaneSplitter();

    // Pane functions
    //
    bool          SplitPane(TWindow* target, TWindow* newPane,
                            TSplitDirection splitDir, float percent = .50);
    bool          RemovePane(TWindow* pane, TDelete dt = TShouldDelete::DefDelete);
    bool          ReplacePane(TWindow* target, TWindow* newPane,
                              TDelete dt = TShouldDelete::DefDelete);
    bool          SwapPanes(TWindow* pane1, TWindow* pane2);
    int           PaneCount();
    void          RemoveAllPanes(TDelete dt = TShouldDelete::DefDelete);

    typedef int (*TForEachPaneCallback)(TWindow&, void*);
    void          ForEachPane(TForEachPaneCallback callback, void* p);

    // Splitter functions
    //
    int           GetSplitterWidth();
    int           SetSplitterWidth(int newWidth);
    void          SetSplitterCushion(uint cushion);
    bool          MoveSplitter(TWindow* pane, int dist);

    bool          DelObj(TDelete dt);

  protected:
    void          SetupWindow();
    void          CleanupWindow();
    void          EvSize(uint sizeType, TSize& size);
    virtual void  DrawSplitter(TDC& dc, const TRect& splitter);

  private:
    enum    TTraversalOrder {psPreOrder, psInOrder, psPostOrder};
    typedef int (TPaneSplitter::*TForEachObjectCallback)(TWindow*, void*, void*);

    TSplitterIndicatorList SplitterIndicatorList;
    TSplitterIndicatorMgr  SplitterIndicatorMgr;
    int                    SplitterWidth;
    uint                   SplitterCushion;
    bool                   Dragging;
    HCURSOR                ResizeCursorH;
    HCURSOR                ResizeCursorV;
    HCURSOR                ResizeCursorHV;
    bool                   PaneSplitterResizing;
    TDelete                ShouldDelete;

    void          MouseMoved(const TPoint& point);
    void          StartSplitterMove(TSplitter* splitter, const TPoint& point);
    void          EndSplitterMove();
    void          SetSplitterMoveCursor(TSplitter* splitter, const TPoint& point);

    void          ForEachObject(TWindow* o,
                                TForEachObjectCallback callback,
                                void* p1, void* p2 = 0,
                                TTraversalOrder order = psPostOrder);
    void          GetDefLM(TLayoutMetrics& lm);
    void          ScreenToClientRect(TRect& rect);
    void          ClientToScreenRect(TRect& rect);
    bool          HasPane(TWindow* p);
    TLayoutWindow* DoRemovePane(TWindow* pane, TDelete dt = TShouldDelete::DefDelete);
    void          FindIntersectingSplitters(const TPoint& point);
    virtual int   RemovePanes();
    void          MoveSplitters();
    void          DestroyPane(TWindow* pane, TDelete dt = TShouldDelete::DefDelete);

    // ForEachObject() callbacks..
    //
    int           DoForEachPane(TWindow* splitter, void* p1, void* p2);
    int           DoFindIntersectingSplitters(TWindow* splitter, void* p1, void* p2);
    int           GetListOfPanesToRemove(TWindow* splitter, void* p1, void* p2);
    int           AdjSplitterWidth(TWindow* splitter, void* p1, void* p2);
    int           DoPaneCount(TWindow* splitter, void* p1, void* p2);
    int           GetPanes(TWindow* splitter, void* p1, void* p2);
    int           GetSplitters(TWindow* splitter, void* p1, void* p2);

  friend class _OWLCLASS TSplitter;
  friend class _OWLCLASS THSplitter;
  friend class _OWLCLASS TVSplitter;

  DECLARE_RESPONSE_TABLE(TPaneSplitter);
};

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
// Return the width of the splitter widget.
//
inline int
TPaneSplitter::GetSplitterWidth()
{
  return SplitterWidth;
}

//
// Set the cushion for the splitter widget.
//
inline void
TPaneSplitter::SetSplitterCushion(uint cushion)
{
  SplitterCushion = cushion;
}

//
// Return true if the object should be deleted.
//
inline bool
TPaneSplitter::DelObj(TDelete dt)
{
  return dt == TShouldDelete::Delete ||
         (dt==TShouldDelete::DefDelete && ShouldDelete==TShouldDelete::Delete);
}

#endif // OWL_PANESPLI_H
