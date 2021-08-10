//----------------------------------------------------------------------------
//    hscroll.h
//----------------------------------------------------------------------------
//    copyright (c) 1993 Borland International
//----------------------------------------------------------------------------
#ifndef HSCROLLINC

#define HSCROLLINC
#include <owl\window.h>
//----------------------------------------------------------------------------
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
//----------------------------------------------------------------------------
#define NW_HSCROLL	WM_USER+0x2801	// custom message used to talk to parent
			// (params are same as for WM_HSCROLL msg)

//---- all 3 defines below use currently selected brush ----
#define FASTRECT(dc,l,t,w,h)  dc.PatBlt(l, t, w, h, PATCOPY)
#define FASTVLINE(dc,l,t,h)  dc.PatBlt(l, t, 1, h, PATCOPY)
#define FASTHLINE(dc,l,t,w)  dc.PatBlt(l, t, w, 1, PATCOPY)

#define HSB_NOTDOWN	1	// mouse not currently down
#define HSB_LEFTARROW	2	// mouse went down at tab scroll left button
#define HSB_RIGHTARROW	3	// mouse went down at tab scroll right button
#define HSB_LEFTTHUMB	4	// mouse went down at tab to left of thumb
#define HSB_RIGHTTHUMB	5	// mouse went down at tab to right of thumb

#define HSB_FORCEALL	6	// force entire scrollbar redraw
#define HSB_THUMB	7	// mouse went down at tab scroll thumb button
#define HSB_THUMBFOCUS	8	// draw solid at origval and focus rect at new

// repaint param values to SetValue()
#define SV_NOREPAINT   0	// don't update thumb display
#define SV_REPAINT     1	// repaint thumb position
#define SV_THUMBTRACK  2	// paint thumb position in thumb tracking style
//----------------------------------------------------------------------------
class THScroll 		
{
  public:
    THScroll(TWindow *Parent, int x, int y, int width, int height, 
 	int idnum = 0, int Lowval = 0, int Highval = 100, int initval = 0, 
	BOOL frame3d = FALSE, BOOL Arrowline = TRUE, BOOL Thumbmove = FALSE, 
	int Repeatdelay = 250);
    ~THScroll();

    int GetScrollPos();
    void GetScrollRange(int &low, int &high);
    int SetScrollPos(int newval, int repaint);
    void SetScrollRange(int lowval, int highval, BOOL redraw);
    void ShowScrollBar(BOOL show);

    void ForcePaint();
    void ChangeRect(TRect &newrect, BOOL repaint = TRUE);
    void SysColorChange();
    //----- use below 3 funcs to pass along mouse events --------
    BOOL MyLButtonDown(UINT hitTest, TPoint& winpt);
    BOOL MyMouseMove(UINT hitTest, TPoint& winpt);
    BOOL MyLButtonUp(UINT hitTest, TPoint& winpt);
  protected:
    //----- various measurements (window-relative coordinates) ------
    TRect framerect;		// rect for 3d frame
    TRect sbrect;		// rect for actual scrollbar 
    int sbheight;		// height of actual scrollbar
    int sbwidth;		// width of actual scrollbar
    int sqsize;			// size of arrow & thumb squares
    int barsize;		// 1 or 2 (width of arrow button inner lines)
    int trackwidth;		// width of thumb track (overlaps 2 black lines)
    int trackxoff;		// xoffset where thumb track starts
    int thumbxoff;		// where thumb is currently sitting
    int thumbgrabxoff;		// offset from start of thumb to mouse pt
    int lastfocusxoff;		// last xoff of thumb focus rect
    //---- non measurement items --------
    TWindow *parent;		// parent window of this sb
    int trange;			// cnt-1 of # of thumb positions in mouse track
    int vrange;			// cnt-1 of # of values in low...high range
    int mousedown;		// part of sb that mouse went down on
    int newloc;			// new value for mousedown
    int displaystate;		// state of scrollbar as currently displayed
    int lowval;			// lowest value for scrollbar
    int highval;		// highest value for scrollbar
    int curval;			// current value (position) of scrollbar
    int origval;		// value before mouse capture
    int scrollmsg;		// WM_HSCROLL or NW_HSCROLL
    int repeatdelay;		// # of milliseconds to delay mouse repeat
    long mylongid;		// my idnum as HIWORD() of a long value
    BOOL frame3d;		// TRUE if 3d frame around sb requested
    BOOL arrowline;		// TRUE if line of arrow needed on scroll button
    BOOL thumbmove;		// TRUE if tracking thumb moved (vs. focus rect)
    BOOL showit;		// TRUE if sb should be shown and enabled
    //------------------------------------------
    TBrush *framebrush;
    TBrush *trackbrush;
    TBrush *hilitebrush;
    TBrush *shadowbrush;
    TBrush *facebrush;
    //------------------------------------------
    void BuildBrushes();
    void DeleteBrushes();
    int GetMouseLoc(TPoint &winpt);
    void AutoScrollMouse();
    void AutoScrollAction();
    void MyPaint(int newstate);
    void DrawFrames(TDC &mydc);
    void DrawLeftArrow(TDC &mydc, BOOL isdown);
    void DrawRightArrow(TDC &mydc, BOOL isdown);
    void DrawLeftTrack(TDC &mydc, BOOL isdown);
    void DrawRightTrack(TDC &mydc, BOOL isdown);
    void DrawThumb(TDC &mydc, BOOL drawfocus, BOOL erasefocus);
    void DrawArrowButton(TDC &mydc, TRect brect, BOOL isdown, BOOL left);
    void DrawShadeFrame(TDC &mydc, TRect &myrect, BOOL forthumb);
    void DrawDownFrame(TDC &mydc, TRect &myrect);
};
//----------------------------------------------------------------------------
#endif
