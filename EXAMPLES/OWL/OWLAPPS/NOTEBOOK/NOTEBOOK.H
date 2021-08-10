//----------------------------------------------------------------------------
//    notebook.h - defines TNotebook class 
//----------------------------------------------------------------------------
//    copyright (c) 1993 Borland International
//----------------------------------------------------------------------------
#ifndef NOTEBOOKINC

#define NOTEBOOKINC
#include "hscroll.h"
#include "vscroll.h"

#define MAXTABNAMELEN   30
#define MAXTABSSHOWN    99

#define NB_TABCHANGED	20099

#define ID_TABSB	3001
#define ID_WINHSB	0
#define ID_WINVSB	0

#define NBC_PAINTALL    0
#define NBC_PAINTTABS   1

#define TABSAFETY	8		// pixels after last tab

// values for tabloc
#define LOC_TOP		0
#define LOC_RIGHT	1
#define LOC_BOTTOM	2
#define LOC_LEFT	3
//----------------------------------------------------------------------------
class TNotebook : public virtual TWindow
{
  public:
    //--- redefined functions ---
    TNotebook(int TabLoc = 0);
    ~TNotebook();
    void SetTabCnt(int tabcnt, int firsttab = 0, int activetab = 0);

    int GetScrollPos(int bar);
    void GetScrollRange(int bar, int &low, int &high);
    int SetScrollPos(int bar, int pos, BOOL redraw = TRUE);
    void SetScrollRange(int  bar, int  minPos, int  maxPos, BOOL redraw = TRUE);

  protected:
    TRect nbcrect;		// current rect for notebook control area
    TRect vsbrect;		// rect for vertical scroll bar
    TRect hsbrect;		// rect for horizontal scroll bar
    TRect tsbrect;		// rect for tabs scroll bar
    TRect tabsrect;		// rect for set of tabs
    TRect clientrect;		// size of client area after our controls
    TRect clientprev;		// to detect window size changes
    TSize Frame;		// actual window frame sizes
    POINT tabpoints[MAXTABSSHOWN] [5];
    int tabcnt;			// # of tabs to move thru
    int firsttab;		// # of first tab displayed (0-rel)
    int activetab;		// # of active tab (0-rel)
    int nbcheight;		// height of notebook control area
    int textextra;
    int fillmode;		// polygon fill mode used
    int rgncnt;			// number of tabs showing & regions allocated
    int toffs[MAXTABSSHOWN];	// toffset (x or y) of each tab drawing
    int defer_ncpaint;		// if nonzero, don't paint nonclient area
    int tabloc;			// position of tabs on client rectangle
    BOOL tabhorz;		// TRUE if tabloc is LOC_TOP or LOC_BOTTOM
    BOOL wanthscroll;		// TRUE if WS_HSCROLL specified in style bits
    BOOL wantvscroll;		// TRUE if WS_VSCROLL specified in style bits
    BOOL hscrollon;		// TRUE if horz scrollbar being shown now
    BOOL vscrollon;		// TRUE if vert scrollbar being shown now
    BOOL erasetabs;		// TRUE if tabs should be erased as drawn
    TPen *framepen;		// for drawing gray stuff over and over
    TPen *shadowpen;		// for drawing gray stuff over and over
    TFont *tabfont;		// font for tabs
    TBrush *bgbrush;		// white/ltgray dither pattern brush
    TBrush *framebrush;
    TBrush *hilitebrush;
    TBrush *shadowbrush;
    TBrush *facebrush;
    TBrush *trackbrush;
    TBrush *tabbrush;		// bg color of current tab
    TBrush *default_tabbrush;	// bg color of most tabs
    THScroll *tabhscroll;	// horizontal scrollbar for tabs
    TVScroll *tabvscroll;	// vertical scrollbar for tabs 
    THScroll *winhscroll;	// horizontal scrollbar for window		
    TVScroll *winvscroll;	// vertical scrollbar for window		
    //------------------------------------------
    BOOL EvNCCreate(CREATESTRUCT far& createStruct);
    void EvSize(UINT sizeType, TSize& newsize);
    void EvGetMinMaxInfo(MINMAXINFO far& minmaxinfo);
    UINT EvNCCalcSize(BOOL calcValidRects, NCCALCSIZE_PARAMS far& calcSize);
    UINT EvNCHitTest(TPoint& screenPt);
    void EvNCPaint();
    void EvNCLButtonDown(UINT hitTest, TPoint& screenPt);
    void EvNCLButtonDblClk(UINT hitTest, TPoint& screenPt);
    void EvMouseMove(UINT hitTest, TPoint& clientpt);
    void EvLButtonUp(UINT hitTest, TPoint& clientpt);
    void EvSysColorChange();
    //------------------------------------------
    void virtual GetTabName(int tabnum, char *tabname);
    void virtual ActivateTab(int tabnum);
    //------------------------------------------
    void BuildPaintObjects();
    void DeletePaintObjects();
    void ComputeSizes();
    void CalcTabRects();
    void ForceResize(BOOL repaint);
    void CreateScrollBars();
    BOOL MyLButtonDown(UINT hitTest, TPoint& screenPt);
    LRESULT NWHscroll(WPARAM wparam, LPARAM lparam);
    void ScrollTabs(int delta);
    void PaintNBC(int paintcontrol);
    void DrawShadeFrame(TDC &mydc, TRect &myrect);
    void DrawDownFrame(TDC &mydc, TRect &myrect);
    void DrawTabs(TDC &mydc);
    int DrawHorzTab(TDC &mydc, int tabnum, int rgnnum, int xoff);
    int DrawVertTab(TDC &mydc, int tabnum, int rgnnum, int xoff);
    void EraseLastHorz(TDC &mydc, int toff);
    void EraseLastVert(TDC &mydc, int toff);
    void DrawBackground(TDC &mydc, TRect &myrect, int paintcontrol);
    void DrawTabLines(TDC &mydc, TRect &myrect, BOOL shadowline);
    void BuildBgBrush();
    //------------------------------------------
    DECLARE_RESPONSE_TABLE(TNotebook);
};
//----------------------------------------------------------------------------
#endif
