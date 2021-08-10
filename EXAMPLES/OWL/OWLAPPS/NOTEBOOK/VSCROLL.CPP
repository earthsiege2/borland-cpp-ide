//----------------------------------------------------------------------------
//    vscroll.cpp - class for vscroll bar gadget (non-window based) 
//----------------------------------------------------------------------------
//    Copyright (c) 1993 Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\dc.h>

#include "utils.h"		// for debugging support
#include "vscroll.h"
//---------------------------------------------------------------------------- 
TVScroll::TVScroll(TWindow *Parent, int x, int y, int width, int height, 
    int idnum, int Lowval, int Highval, int initval, BOOL Frame3d, 
    BOOL Arrowline, BOOL Thumbmove, int Repeatdelay)
{
  parent = Parent;
  frame3d = Frame3d;
  lastfocusyoff = -1;
  arrowline = Arrowline;
  thumbmove = Thumbmove;
  repeatdelay = Repeatdelay;
  showit = TRUE;
  if (arrowline)
    barsize = 1;
  else
    barsize = 2;

  BuildBrushes();
  SetScrollRange(Lowval, Highval, FALSE);
  SetScrollPos(initval, FALSE);

  mousedown = VSB_NOTDOWN;
  displaystate = VSB_NOTDOWN;
  mylongid = MAKELONG(0, idnum);
  if (! idnum)
    scrollmsg = WM_VSCROLL;
  else
    scrollmsg = NW_VSCROLL;

  ChangeRect(TRect(x, y, x+width, y+height), FALSE);
}
//----------------------------------------------------------------------------
TVScroll::~TVScroll()
{
  DeleteBrushes();
}
//----------------------------------------------------------------------------
void TVScroll::ShowScrollBar(BOOL show)
{
  showit = show;
}
//----------------------------------------------------------------------------
void TVScroll::DeleteBrushes()
{
  delete framebrush;
  delete trackbrush;
  delete hilitebrush;
  delete shadowbrush;
  delete facebrush;
}
//----------------------------------------------------------------------------
void TVScroll::BuildBrushes()
{
  framebrush = new TBrush(GetSysColor(COLOR_WINDOWFRAME));
  trackbrush = new TBrush(GetSysColor(COLOR_SCROLLBAR));
  hilitebrush = new TBrush(GetSysColor(COLOR_BTNHIGHLIGHT));
  shadowbrush = new TBrush(GetSysColor(COLOR_BTNSHADOW));
  facebrush = new TBrush(GetSysColor(COLOR_BTNFACE));
}
//----------------------------------------------------------------------------
void TVScroll::SysColorChange()
{
  DeleteBrushes();
  BuildBrushes();
}
//----------------------------------------------------------------------------
void TVScroll::ChangeRect(TRect &newrect, BOOL repaint)
{
  int width = newrect.Width();
  int height = newrect.Height();

  // set minimum sizes
  if (height < 14)
    height = 14;
  if (width < 4)
    width = 4;
  framerect = TRect(newrect.left, newrect.top, newrect.left+width,
    newrect.top+height);

  if (frame3d)		// will add 3d frame on outside
    sbrect = framerect.InflatedBy(-1, -1);
  else
    sbrect = framerect;

  // compute a few measurements here to make our life easier 
  sbheight = sbrect.bottom - sbrect.top;
  sbwidth = sbrect.right - sbrect.left;
  sqsize = sbwidth - 2;
  trackheight = sbheight - 2*(sqsize+barsize);    // overlaps arrow lines
  trange = trackheight - (sqsize+2);
  trackyoff = sbrect.top + sqsize + barsize;	// start on 2nd left arrow bar

  SetScrollPos(curval, SV_NOREPAINT);

  if (repaint)
    MyPaint(VSB_FORCEALL);
}
//----------------------------------------------------------------------------
void TVScroll::ForcePaint()
{
  MyPaint(VSB_FORCEALL);
}
//----------------------------------------------------------------------------
void TVScroll::DrawFrames(TDC &mydc)
{
  if (frame3d)			// outer 3d frame
	  DrawShadeFrame(mydc, framerect, FALSE);

  // draw inner frame (avoid flicker by not painting interrior)
  mydc.FrameRect(sbrect, *framebrush);

  // draw single/double black lines for top and bottom buttons
  mydc.SelectObject(*framebrush);
  FASTRECT(mydc, sbrect.left, sbrect.top+sqsize+1, sbwidth, barsize);
  FASTRECT(mydc, sbrect.left, sbrect.bottom-(sqsize+barsize+1), sbwidth, 
    barsize);
}
//----------------------------------------------------------------------------
void TVScroll::DrawTopArrow(TDC &mydc, BOOL isdown)
{
  TRect myrect(sbrect.left+1, sbrect.top+1, sbrect.left+sqsize+1,
    sbrect.top+sqsize+1);
  DrawArrowButton(mydc, myrect, isdown, TRUE);
}
//----------------------------------------------------------------------------
void TVScroll::DrawBottomArrow(TDC &mydc, BOOL isdown)
{
  TRect myrect(sbrect.left+1, sbrect.bottom-(sqsize+1), 
    sbrect.left+sqsize+1, sbrect.bottom-1);
  DrawArrowButton(mydc, myrect, isdown, FALSE);
}
//----------------------------------------------------------------------------
void TVScroll::DrawTopTrack(TDC &mydc, BOOL isdown)
{
  if (isdown)
    mydc.SelectObject(*shadowbrush);
  else
    mydc.SelectObject(*trackbrush);
  FASTRECT(mydc, sbrect.left+1, trackyoff, sbwidth-2, thumbyoff-trackyoff);
}
//----------------------------------------------------------------------------
void TVScroll::DrawBottomTrack(TDC &mydc, BOOL isdown)
{
  int yoff = thumbyoff+sqsize+2;
  int lasty = trackyoff + trackheight - 1;

  if (isdown)
    mydc.SelectObject(*shadowbrush);
  else
    mydc.SelectObject(*trackbrush);
  FASTRECT(mydc, sbrect.left+1, yoff, sbwidth-2, lasty-yoff+1);
}
//----------------------------------------------------------------------------
void TVScroll::DrawThumb(TDC &mydc, BOOL drawfocus, BOOL erasefocus)
{
  if ((erasefocus) && (lastfocusyoff >= 0)) {
    mydc.DrawFocusRect(sbrect.left, lastfocusyoff, sbrect.right,
	  lastfocusyoff+sqsize+2);
  }

  if (drawfocus) {
    mydc.DrawFocusRect(sbrect.left, thumbyoff, sbrect.left+sbwidth,
	    thumbyoff+sqsize+2);
    lastfocusyoff = thumbyoff;
    return;
  }

  // draw thumb track (but don't cover two outside black lines)
  mydc.SelectObject(*trackbrush);
  FASTRECT(mydc, sbrect.left+1, trackyoff+1, sbwidth-2, trackheight-2);

  // draw black lines on each side of solid thumb
  mydc.SelectObject(*framebrush);
  FASTHLINE(mydc, sbrect.left, thumbyoff, sbwidth);
  FASTHLINE(mydc, sbrect.left, thumbyoff+sqsize+1, sbwidth);

  // draw solid thumb
  mydc.SelectObject(*facebrush);
  FASTRECT(mydc, sbrect.left+1, thumbyoff+1, sqsize-2, sqsize-2);

  // draw shaded frame and extra "_|" design for solid thumb
  TRect myrect(sbrect.left+1, thumbyoff+1, sbrect.right-1, 
    thumbyoff+sqsize+1);
  DrawShadeFrame(mydc, myrect, TRUE);

  lastfocusyoff = -1;
}
//----------------------------------------------------------------------------
void TVScroll::DrawDownFrame(TDC &mydc, TRect &myrect)
{
  // always a single width shadow line
  mydc.SelectObject(*shadowbrush);
  FASTHLINE(mydc, myrect.left, myrect.top, myrect.right-myrect.left);
  FASTVLINE(mydc, myrect.left, myrect.top, myrect.bottom-myrect.top);
}
//----------------------------------------------------------------------------
void TVScroll::DrawShadeFrame(TDC &mydc, TRect &myrect, BOOL forthumb)
{
  int width = myrect.right - myrect.left;
  int height = myrect.bottom - myrect.top;

  mydc.SelectObject(*hilitebrush);
  FASTHLINE(mydc, myrect.left, myrect.top, width);
  FASTVLINE(mydc, myrect.left, myrect.top, height);
  if (sqsize > 15) {		// double highlight
    FASTHLINE(mydc, myrect.left, myrect.top+1, width);
    FASTVLINE(mydc, myrect.left+1, myrect.top, height);
  }

  mydc.SelectObject(*shadowbrush);
  FASTHLINE(mydc, myrect.left, myrect.bottom-1, width);
  FASTVLINE(mydc, myrect.right-1, myrect.top, height);
  if ((forthumb) || (sqsize >= 15)) {		// double shadow 
    FASTHLINE(mydc, myrect.left+1, myrect.bottom-2, width-1);
    FASTVLINE(mydc, myrect.right-2, myrect.top+1, height-1);
  }
}
//---------------------------------------------------------------------------
void TVScroll::DrawArrowButton(TDC &mydc, TRect brect, BOOL isdown, BOOL top)
{
  int xoff, yoff, width, height, downoff, aheight, awidth;
  int lheight, lwidth, myheight, delta;

  // draw button background 
  mydc.FillRect(brect, *facebrush);

  // draw frame around button
  if (isdown)
    DrawDownFrame(mydc, brect);
  else
    DrawShadeFrame(mydc, brect, FALSE);

  // calculations for drawing arrow line and head
  width = brect.right - brect.left;
  height = brect.bottom - brect.top;

  if (isdown)
    downoff = 1;
  else
    downoff = 0;

  mydc.SelectObject(*framebrush);	// for drawing arrows

  awidth = 2 + (width+1)/3;
  if (! (awidth%2))		// need an odd numbered arrow width
    awidth--;
  aheight = (awidth+1)/2;
  if (arrowline)
    lheight = aheight-1;
  else
    lheight = 0;

  myheight = aheight + lheight;
  delta = height - myheight;
  yoff = brect.top + delta/2;		// where whole object should start
  if (delta%2)	// odd number - put extra space on left
    yoff++;

  if (arrowline) {		// draw arrow line
    if (top)
	    yoff += aheight;		// yoff is now where line starts
    lwidth = (awidth+2)/3;
    xoff = brect.left + (width/2 - lwidth/2);
    FASTRECT(mydc, xoff+downoff, yoff+downoff, lwidth, lheight);
    if (top)
	    yoff--;
    else
	    yoff += lheight;
    } else if (top)
      yoff += (aheight-1);

  // yoff is now where back line of arrow should be drawn
  xoff = brect.left + (width/2 - awidth/2);

  // draw arrow head
  while (awidth > 0) {
    FASTHLINE(mydc, xoff+downoff, yoff+downoff, awidth);
    awidth -= 2;
    if (top)
	    yoff--;
    else
	    yoff++;
    xoff++;
    }
}
//---------------------------------------------------------------------------
void TVScroll::MyPaint(int newstate)
{
  if ((! parent->HWindow) || (parent->IsIconic()) || (! showit))
    return;

  BOOL forceall = (newstate == VSB_FORCEALL);

  if ((! forceall) && (newstate == displaystate) && 
    (newstate <= VSB_BOTTOMTHUMB))
    return;			// already drawn

  BOOL dotop = (displaystate==VSB_TOPARROW) || (newstate==VSB_TOPARROW);
  BOOL dobottom = (displaystate==VSB_BOTTOMARROW) || 
    (newstate==VSB_BOTTOMARROW);
  BOOL dothumb = (displaystate>=VSB_TOPTHUMB) || (newstate>=VSB_TOPTHUMB);

  if (newstate <= VSB_BOTTOMTHUMB)
    displaystate = newstate;

  TWindowDC mydc(*parent);

  if (forceall)
    DrawFrames(mydc);

  if ((forceall) || (dotop))
    DrawTopArrow(mydc, (displaystate==VSB_TOPARROW));
  
  if ((forceall) || (dobottom))
    DrawBottomArrow(mydc, (displaystate==VSB_BOTTOMARROW));
  
  if ((forceall) || (dothumb)) {
    DrawThumb(mydc, (displaystate==VSB_THUMBFOCUS), 
	    (displaystate==VSB_THUMBFOCUS));
    if (displaystate == VSB_TOPTHUMB)	    // gray to top of thumb
    	DrawTopTrack(mydc, TRUE);
    else if (displaystate == VSB_BOTTOMTHUMB)    // gray to right of thumb
    	DrawBottomTrack(mydc, TRUE);
  }
}
//----------------------------------------------------------------------------
int TVScroll::GetScrollPos()
{
  return(curval);
}
//----------------------------------------------------------------------------
void TVScroll::GetScrollRange(int &low, int &high)
{
  low = lowval;
  high = highval;
}
//----------------------------------------------------------------------------
int TVScroll::SetScrollPos(int newval, int repaint)
{
  int oldval = curval;
  curval = min(max(newval, lowval), highval);

  // reposition thumb to match new value
  thumbyoff = (int)(trackyoff + ((LONG)trange*(curval-lowval))/vrange);

  if (repaint == SV_REPAINT)
    MyPaint(VSB_THUMB);
  else if (repaint == SV_THUMBTRACK)
    MyPaint(thumbmove ? VSB_THUMB : VSB_THUMBFOCUS);

  return(oldval);
}
//----------------------------------------------------------------------------
void TVScroll::SetScrollRange(int Lowval, int Highval, BOOL redraw)
{
  lowval = Lowval;
  highval = Highval;
  if (highval <= lowval)
    highval = lowval + 1;
  vrange = highval - lowval;

  if (redraw)
    MyPaint(VSB_FORCEALL);
}
//----------------------------------------------------------------------------
int TVScroll::GetMouseLoc(TPoint &winpt)
{
  if ((parent->IsIconic()) || (! sbrect.Contains(winpt)) || (! showit)) 
    return(VSB_NOTDOWN);

  int myy = winpt.y;
  int top = sbrect.top;

  if (myy < top+sqsize+2)
    return(VSB_TOPARROW);
  if (myy > (top+sqsize+2+trackheight))
    return(VSB_BOTTOMARROW);
  if (myy < thumbyoff)
    return(VSB_TOPTHUMB);
  if (myy > thumbyoff+sqsize+2)
    return(VSB_BOTTOMTHUMB);
  return(VSB_THUMB);
}
//----------------------------------------------------------------------------
BOOL TVScroll::MyLButtonDown(UINT /*hitTest*/, TPoint& winpt)
{
  mousedown = GetMouseLoc(winpt);
  if (mousedown == VSB_NOTDOWN)	// mousedown not in scrollbar
    return(FALSE);

  origval = curval;
  newloc = mousedown;

  switch (mousedown) {
    case VSB_TOPARROW:
    case VSB_BOTTOMARROW:
	    MyPaint(mousedown);
	    break;

    case VSB_TOPTHUMB:
   	  MyPaint(mousedown);
	    parent->SendMessage(scrollmsg, SB_PAGEUP, mylongid);
	    break;

    case VSB_BOTTOMTHUMB:
	    MyPaint(mousedown);
	    parent->SendMessage(scrollmsg, SB_PAGEDOWN, mylongid);
	    break;

    case VSB_THUMB:
	    thumbgrabyoff = winpt.y - thumbyoff;
	    SetScrollPos(curval, SV_THUMBTRACK);
  }

  AutoScrollMouse();

  return(TRUE);
}
//----------------------------------------------------------------------------
BOOL TVScroll::MyMouseMove(UINT /*hitTest*/, TPoint& winpt)
{
  if (mousedown == VSB_NOTDOWN)	// mousedown was not in our scrollbar
    return(FALSE);

  newloc = GetMouseLoc(winpt);

  switch (mousedown){
    case VSB_TOPARROW:
    case VSB_BOTTOMARROW:
    case VSB_TOPTHUMB:
    case VSB_BOTTOMTHUMB:
	    if (newloc == mousedown)
	      MyPaint(mousedown);
	    else
	      MyPaint(VSB_NOTDOWN);
	    break;

    case VSB_THUMB:
	    if (newloc != VSB_NOTDOWN){		// anywhere inside sb
	      int newpos = (winpt.y - thumbgrabyoff) - trackyoff;
	      if (newpos < 0)
		      newpos = 0;
	      else if (newpos > trange)
		      newpos = trange;
    	  int newval = (int)(lowval + ((LONG)vrange*newpos)/trange);
	      SetScrollPos(newval, SV_THUMBTRACK);
	      parent->SendMessage(scrollmsg, SB_THUMBTRACK, 
		      mylongid | newval);
	    } else {
	      SetScrollPos(origval, SV_THUMBTRACK);
	      parent->SendMessage(scrollmsg, SB_THUMBTRACK, 
		      mylongid | origval);
	    }
	    break;
  }
  return(TRUE);
}
//----------------------------------------------------------------------------
BOOL TVScroll::MyLButtonUp(UINT /*hitTest*/, TPoint& winpt)
{
  int sendval;

  if (mousedown == VSB_NOTDOWN)	// mousedown was not in our scrollbar
    return(FALSE);

  newloc = GetMouseLoc(winpt);

  switch (mousedown) {
    case VSB_TOPARROW:
	    MyPaint(VSB_NOTDOWN);
	    if (newloc == mousedown)
	      parent->SendMessage(scrollmsg, SB_LINEUP, mylongid);
	    break;

    case VSB_BOTTOMARROW:
    	MyPaint(VSB_NOTDOWN);
	    if (newloc == mousedown)
	      parent->SendMessage(scrollmsg, SB_LINEDOWN, mylongid);
	    break;

    case VSB_THUMB:
	    sendval = curval;		// save off before overwritting
	    SetScrollPos(origval, SV_REPAINT);
	    parent->SendMessage(scrollmsg, SB_THUMBPOSITION, 
	      mylongid | sendval);
	    break;
	
    default:
	    MyPaint(VSB_NOTDOWN);
	    break;
  }

  parent->SendMessage(scrollmsg, SB_ENDSCROLL, mylongid);
  mousedown = VSB_NOTDOWN;
  return(TRUE);
}
//----------------------------------------------------------------------------
void TVScroll::AutoScrollMouse()
{
  MSG  loopMsg;
  DWORD delayticks;

  loopMsg.message = 0;
  parent->SetCapture();
  
  delayticks = repeatdelay + GetTickCount();	

  while (loopMsg.message != WM_LBUTTONUP && 
    (loopMsg.message != WM_MOUSEMOVE ||(loopMsg.wParam&MK_LBUTTON))) {
    if (::PeekMessage(&loopMsg, 0, 0, 0, PM_REMOVE)) {
      ::TranslateMessage(&loopMsg);
      ::DispatchMessage(&loopMsg);
    }
    if (GetTickCount() > delayticks)
	    AutoScrollAction();
  }

  parent->ReleaseCapture();
}
//----------------------------------------------------------------------------
void TVScroll::AutoScrollAction()
{
  if (newloc != mousedown)
	  return;

  switch (mousedown){
	  case VSB_TOPARROW:
	    parent->SendMessage(scrollmsg, SB_LINEUP, mylongid);
	    break;

	  case VSB_BOTTOMARROW:
	    parent->SendMessage(scrollmsg, SB_LINEDOWN, mylongid);
	    break;

	  case VSB_TOPTHUMB:
	    parent->SendMessage(scrollmsg, SB_PAGEUP, mylongid);
	    break;

	  case VSB_BOTTOMTHUMB:
	    parent->SendMessage(scrollmsg, SB_PAGEDOWN, mylongid);
	    break;
  }
}
//----------------------------------------------------------------------------

