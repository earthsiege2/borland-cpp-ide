//----------------------------------------------------------------------------
//  Project Shell
//  Borland International
//  Copyright © 1995, 1996 Borland International. All Rights Reserved.
//
//  SUBSYSTEM:    shell.exe Application
//  FILE:         shellwin.h
//  AUTHOR:       The OWL Team
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TShellWindow (TWindow).
//
//----------------------------------------------------------------------------
#if !defined(shellwin_h)              // Sentry, use file only if it's not already included.
#define shellwin_h

#include <owl/shellitm.h>
#include <owl/contain.h>

#include "shellapp.rh"            // Definition of all resources.


//{{TWindow = TShellWindow}}
class TShellWindow : public TWindow {
  public:
    TShellWindow(TWindow* parent, TShellItem* item = 0,
                const char far* title = 0, TModule* module = 0);
    virtual ~TShellWindow();

//{{ShellWindowVIRTUAL_BEGIN}}
  public:
    virtual void Paint(TDC& dc, bool erase, TRect& rect);
//{{ShellWindowVIRTUAL_END}}
//{{ShellWindowRSP_TBL_BEGIN}}
  protected:
    int  EvCreate(CREATESTRUCT far &);
    void EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);
    void EvSize(uint sizeType, TSize& size);
    void EvLButtonUp(uint modKeys, TPoint& point);
    void EvRButtonUp(uint modKeys, TPoint& point);
    void EvLButtonDblClk(uint modKeys, TPoint& point);
    void EvChar(uint key, uint repeatCount, uint flags);
//{{ShellWindowRSP_TBL_END}}
DECLARE_RESPONSE_TABLE(TShellWindow);
    //
    void TShellWindow::ComputeItemGrids();
    void DrawIconTitle(TDC& dc, TString& name, int x, int y, int gridWidth);
    void DrawLongWord(TDC& dc, int x, int y, int gridWidth, const char* begin, const char* end);
    void DisplayProperties(TShellItem& item);
    int ComputeItemsPerRow();
    void OpenExec();
    void DisplayShellExecuteError(int error, const char* itemName);
    //
    class ItemGrid {
      public:
        ItemGrid();
        ItemGrid(TShellItem& item, const TRect& grid, const TPoint& iconPt,
                 const TPoint& titlePt);
        ItemGrid(const ItemGrid& source);
        ItemGrid& operator =(const ItemGrid& source);
        bool operator ==(const ItemGrid& rhs);
        TShellItem Item;
        TRect Grid;
        TPoint IconPt;
        TPoint TitlePt;
    };
    // Member Variables
    enum Spacing { IconSpacingX = 2,
                   IconSpacingY = 2
    };
    TShellItem Folder;
    TArray<ItemGrid>* ItemGrids;
    int SelectedItem;
    int ClientRectWidth;
    int ItemsPerRow;
};    //{{TShellWindow}}

inline TShellWindow::ItemGrid::ItemGrid()
{
}

inline TShellWindow::ItemGrid::ItemGrid(TShellItem& item, const TRect& grid,
                                       const TPoint& iconPt, const TPoint& titlePt)
:
  Item(item),
  Grid(grid),
  IconPt(iconPt),
  TitlePt(titlePt)
{
}

inline TShellWindow::ItemGrid::ItemGrid(const ItemGrid& source)
:
  Item(source.Item),
  Grid(source.Grid),
  IconPt(source.IconPt),
  TitlePt(source.TitlePt)
{
}

inline TShellWindow::ItemGrid& TShellWindow::ItemGrid::operator =(const ItemGrid& source)
{
  if (this != &source) {
    Item = source.Item;
    Grid = source.Grid;
    IconPt = source.IconPt;
    TitlePt = source.TitlePt;
  }
  return *this;
}

inline bool TShellWindow::ItemGrid::operator ==(const ItemGrid& rhs)
{
  return this == &rhs || (Item == rhs.Item && Grid == rhs.Grid && IconPt ==
                          rhs.IconPt && TitlePt == rhs.TitlePt);
}

#endif  // shellwin_h sentry.

