//----------------------------------------------------------------------------
//    hscroll.cpp - class for hscroll bar gadget (non-window based) 
//----------------------------------------------------------------------------
//    Copyright (c) 1993 Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\dc.h>

#include "utils.h"		// for debugging support
#include "hscroll.h"
//---------------------------------------------------------------------------- 
THScroll::THScroll(TWindow *Parent, int x, int y, int width, int height, 
    int idnum, int Lowval, int Highval, int initval, BOOL Frame3d, 
    BOOL Arrowline, BOOL Thumbmove, int Repeatdelay)
{
  parent = Parent;
  frame3d = Frame3d;
  lastfocusxoff = -1;
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

  mousedown = HSB_NOTDOWN;
  displaystate = HSB_NOTDOWN;
  mylongid = MAKELONG(0, idnum);
  if (! idnum)
  	scrollmsg = WM_HSCROLL;
  else
	  scrollmsg = NW_HSCROLL;

  ChangeRect(TRect(x, y, x+width, y+height), FALSE);
}
//----------------------------------------------------------------------------
THScroll::~THScroll()
{
  DeleteBrushes();
}
//----------------------------------------------------------------------------
void THScroll::ShowScrollBar(BOOL show)
{
  showit = show;
}
//----------------------------------------------------------------------------
void THScroll::DeleteBrushes()
{
  delete framebrush;
  delete trackbrush;
  delete hilitebrush;
  delete shadowbrush;
  delete facebrush;
}
//----------------------------------------------------------------------------
void THScroll::BuildBrushes()
{
  framebrush = new TBrush(GetSysColor(COLOR_WINDOWFRAME));
  trackbrush = new TBrush(GetSysColor(COLOR_SCROLLBAR));
  hilitebrush = new TBrush(GetSysColor(COLOR_BTNHIGHLIGHT));
  shadowbrush = new TBrush(GetSysColor(COLOR_BTNSHADOW));
  facebrush = new TBrush(GetSysColor(COLOR_BTNFACE));
}
//----------------------------------------------------------------------------
void THScroll::SysColorChange()
{
  DeleteBrushes();
  BuildBrushes();
}
//----------------------------------------------------------------------------
void THScroll::ChangeRect(TRect &newrect, BOOL repaint)
{
  int height = newrect.Height();
  int width = newrect.Width();

  // set minimum sizes
  if (height < 4)
	  height = 4;

  if (width < 14)
	  width = 14;
    
  framerect = TRect(newrect.left, newrect.top, newrect.left+width, 
	newrect.top+height);

  if (frame3d)		// will add 3d frame on outside
    sbrect = framerect.InflatedBy(-1, -1);
  else
    sbrect = framerect;

  // compute a few measurements here to make our life easier 
  sbheight = sbrect.bottom - sbrect.top;
  sbwidth = sbrect.right - sbrect.left;
  sqsize = sbheight - 2;
  trackwidth = sbwidth - 2*(sqsize + barsize);	// overlaps arrow lines
  trange = trackwidth - (sqsize+2);
  trackxoff = sbrect.left + sqsize + barsize;	// start on outer left arrow bar

  SetScrollPos(curval, SV_NOREPAINT);

  if (repaint)
    MyPaint(HSB_FORCEALL);
}
//----------------------------------------------------------------------------
void THScroll::ForcePaint()
{
  MyPaint(HSB_FORCEALL);
}
//----------------------------------------------------------------------------
void THScroll::DrawFrames(TDC &mydc)
{
  if (frame3d)			// outer 3d frame
	  DrawShadeFrame(mydc, framerect, FALSE);

  // draw inner frame (avoid flicker by not painting interrior)
  mydc.FrameRect(sbrect, *framebrush);

  // draw double black lines for left and right buttons
  mydc.SelectObject(*framebrush);
  FASTRECT(mydc, sbrect.left+sqsize+1, sbrect.top, barsize, sbheight);
  FASTRECT(mydc, sbrect.right-(sqsize+1+barsize), sbrect.top, barsize, 
	  sbheight);
}

//----------------------------------------------------------------------------
void THScroll::DrawLeftArrow(TDC &mydc, BOOL isdown)
{
  TRect myrect(sbrect.left+1, sbrect.top+1, sbrect.left+sqsize+1,
  	sbrect.bottom-1);
  DrawArrowButton(mydc, myrect, isdown, TRUE);
}

//----------------------------------------------------------------------------
void THScroll::DrawRightArrow(TDC &mydc, BOOL isdown)
{
  TRect myrect(sbrect.right-(sqsize+1), sbrect.top+1, sbrect.right-1,
	  sbrect.bottom-1);
  DrawArrowButton(mydc, myrect, isdown, FALSE);
}

//----------------------------------------------------------------------------
void THScroll::DrawLeftTrack(TDC &mydc, BOOL isdown)
{
  if (isdown)
    mydc.SelectObject(*shadowbrush);
  else
    mydc.SelectObject(*trackbrush);
  FASTRECT(mydc, trackxoff, sbrect.top+barsize, thumbxoff-trackxoff, 
	  sbheight-2);
}

//----------------------------------------------------------------------------
void THScroll::DrawRightTrack(TDC &mydc, BOOL isdown)
{
  int xoff = thumbxoff+sqsize+2;
  int lastx = trackxoff + trackwidth - 1;

  if (isdown)
    mydc.SelectObject(*shadowbrush);
  else
    mydc.SelectObject(*trackbrush);

  FASTRECT(mydc, xoff, sbrect.top+1, lastx-xoff+1, sbheight-2);
}
//----------------------------------------------------------------------------
void THScroll::DrawThumb(TDC &mydc, BOOL drawfocus, BOOL erasefocus)
{
  if ((erasefocus) && (lastfocusxoff >= 0)){
    mydc.DrawFocusRect(lastfocusxoff, sbrect.top, lastfocusxoff+sqsize+2, 
	    sbrect.top+sbheight);
  }

  if (drawfocus){
    mydc.DrawFocusRect(thumbxoff, sbrect.top, thumbxoff+sqsize+2, 
	    sbrect.top+sbheight);
    lastfocusxoff = thumbxoff;
    return;
  }

  // draw thumb track (but don't cover two outside black lines)
  mydc.SelectObject(*trackbrush);
  FASTRECT(mydc, trackxoff+1, sbrect.top+1, trackwidth-2, sbheight-2);

  // draw black lines on each side of solid thumb
  mydc.SelectObject(*framebrush);
  FASTVLINE(mydc, thumbxoff, sbrect.top, sbheight);
  FASTVLINE(mydc, thumbxoff+sqsize+1, sbrect.top, sbheight);

  // draw solid thumb
  mydc.SelectObject(*facebrush);
  FASTRECT(mydc, thumbxoff+1, sbrect.top+1, sqsize, sqsize);

  // draw shaded frame and extra "_|" design for solid thumb
  TRect myrect(thumbxoff+1, sbrect.top+1, thumbxoff+sqsize+1, 
    sbrect.bottom-1);

  DrawShadeFrame(mydc, myrect, TRUE);

  lastfocusxoff = -1;
}

//----------------------------------------------------------------------------
void THScroll::DrawDownFrame(TDC &mydc, TRect &myrect)
{
  // always a single width shadow line
  mydc.SelectObject(*shadowbrush);
  FASTHLINE(mydc, myrect.left, myrect.top, myrect.right-myrect.left);
  FASTVLINE(mydc, myrect.left, myrect.top, myrect.bottom-myrect.top);
}
//----------------------------------------------------------------------------
void THScroll::DrawShadeFrame(TDC &mydc, TRect &myrect, BOOL forthumb)
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
void THScroll::DrawArrowButton(TDC &mydc, TRect brect, BOOL isdown, BOOL left)
{
  int xoff, yoff, width, height, downoff, aheight, awidth;
  int lheight, lwidth, mywidth, delta;

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

  aheight = 2 + (height+1)/3;
  if (! (aheight%2))		// need an odd numbered arrow height
    aheight--;

  awidth = (aheight+1)/2;
  if (arrowline)
    lwidth = awidth-1;
  else
    lwidth = 0;

  mywidth = awidth + lwidth;
  delta = width - mywidth;
  xoff = brect.left + delta/2;	// where whole object should start
  if (delta%2)	// odd number - put extra space on left
    xoff++;

  if (arrowline) {		// draw arrow line
    if (left)
	    xoff += awidth;		// xoff is now where line starts
    lheight = (aheight+2)/3;
    yoff = brect.top + (height/2 - lheight/2);
    FASTRECT(mydc, xoff+downoff, yoff+downoff, lwidth, lheight);
    if (left)
	    xoff--;
    else
  	  xoff += lwidth;
  }else if (left)
    xoff += (awidth-1);

  // xoff is now where back line of arrow should be drawn
  yoff = brect.top + (height/2 - aheight/2);

  // draw arrow head
  while (aheight > 0) {
    FASTVLINE(mydc, xoff+downoff, yoff+downoff, aheight);
    aheight -= 2;
    if (left)
      xoff--;
    else
	    xoff++;
    yoff++;
  }
}
//---------------------------------------------------------------------------
void THScroll::MyPaint(int newstate)
{
  if ((! parent->HWindow) || (parent->IsIconic()) || (! showit))
    return;

  BOOL forceall = (newstate == HSB_FORCEALL);

  if ((! forceall) && (newstate == displaystate) && 
    (newstate <= HSB_RIGHTTHUMB))
    return;			// already drawn

  BOOL doleft = (displaystate==HSB_LEFTARROW) || (newstate==HSB_LEFTARROW);
  BOOL doright = (displaystate==HSB_RIGHTARROW) || (newstate==HSB_RIGHTARROW);
  BOOL dothumb = (displaystate>=HSB_LEFTTHUMB) || (newstate>=HSB_LEFTTHUMB);

  if (newstate <= HSB_RIGHTTHUMB)
    displaystate = newstate;

  TWindowDC mydc(*parent);

  if (forceall)
    DrawFrames(mydc);

  if ((forceall) || (doleft))
    DrawLeftArrow(mydc, (displaystate==HSB_LEFTARROW));
  
  if ((forceall) || (doright))
    DrawRightArrow(mydc, (displaystate==HSB_RIGHTARROW));
  
  if ((forceall) || (dothumb)) {
    DrawThumb(mydc, (displaystate==HSB_THUMBFOCUS), 
	    (displaystate==HSB_THUMBFOCUS));
    if (displaystate == HSB_LEFTTHUMB)	    // gray to left of thumb
  	  DrawLeftTrack(mydc, TRUE);
    else if (displaystate == HSB_RIGHTTHUMB)    // gray to right of thumb
  	  DrawRightTrack(mydc, TRUE);
  }
}
//----------------------------------------------------------------------------
int THScroll::GetScrollPos()
{
  return(curval);
}
//----------------------------------------------------------------------------
void THScroll::GetScrollRange(int &low, int &high)
{
  low = lowval;
  high = highval;
}
//----------------------------------------------------------------------------
int THScroll::SetScrollPos(int newval, int repaint)
{
  int oldval = curval;
  curval = min(max(newval, lowval), highval);

  // reposition thumb to match new value
  thumbxoff = (int)(trackxoff + ((LONG)trange*(curval-lowval))/vrange);

  if (repaint == SV_REPAINT)
    MyPaint(HSB_THUMB);
  else if (repaint == SV_THUMBTRACK)
    MyPaint(thumbmove ? HSB_THUMB : HSB_THUMBFOCUS);

  return(oldval);
}
//----------------------------------------------------------------------------
void THScroll::SetScrollRange(int Lowval, int Highval, BOOL redraw)
{
  lowval = Lowval;
  highval = Highval;
  if (highval <= lowval)
    highval = lowval + 1;

  vrange = highval - lowval;

  if (redraw)
    MyPaint(HSB_FORCEALL);
}
//----------------------------------------------------------------------------
int THScroll::GetMouseLoc(TPoint &winpt)
{
  if ((parent->IsIconic()) || (! sbrect.Contains(winpt)) || (! showit)) 
    return(HSB_NOTDOWN);

  int myx = winpt.x;
  int left = sbrect.left;

  if (myx < left+sqsize+2)
    return(HSB_LEFTARROW);
  if (myx > (left+sqsize+2+trackwidth))
    return(HSB_RIGHTARROW);
  if (myx < thumbxoff)
    return(HSB_LEFTTHUMB);
  if (myx > thumbxoff+sqsize+2)
    return(HSB_RIGHTTHUMB);
  return(HSB_THUMB);
}
//----------------------------------------------------------------------------
BOOL THScroll::MyLButtonDown(UINT /*hitTest*/, TPoint& winpt)
{
  mousedown = GetMouseLoc(winpt);
  if (mousedown == HSB_NOTDOWN)	// mousedown not in scrollbar
    return(FALSE);

  origval = curval;
  newloc = mousedown;

  switch (mousedown) {
    case HSB_LEFTARROW:
    case HSB_RIGHTARROW:
	    MyPaint(mousedown);
	    break;

    case HSB_LEFTTHUMB:
   	  MyPaint(mousedown);
	    parent->SendMessage(scrollmsg, SB_PAGELEFT, mylongid);
	    break;

    case HSB_RIGHTTHUMB:
	    MyPaint(mousedown);
	    parent->SendMessage(scrollmsg, SB_PAGERIGHT, mylongid);
	    break;

    case HSB_THUMB:
	    thumbgrabxoff = winpt.x - thumbxoff;
	    SetScrollPos(curval, SV_THUMBTRACK);
  }

  AutoScrollMouse();

  return(TRUE);
}
//----------------------------------------------------------------------------
BOOL THScroll::MyMouseMove(UINT /*hitTest*/, TPoint& winpt)
{
  if (mousedown == HSB_NOTDOWN)	// mousedown was not in our scrollbar
    return(FALSE);

  newloc = GetMouseLoc(winpt);

  switch (mousedown) {
    case HSB_LEFTARROW:
    case HSB_RIGHTARROW:
    case HSB_LEFTTHUMB:
    case HSB_RIGHTTHUMB:
      if (newloc == mousedown)
  	    MyPaint(mousedown);
	    else
	      MyPaint(HSB_NOTDOWN);
	    break;

    case HSB_THUMB:
	    if (newloc != HSB_NOTDOWN){		// anywhere inside sb
  	    int newpos = (winpt.x - thumbgrabxoff) - trackxoff;
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
BOOL THScroll::MyLButtonUp(UINT /*hitTest*/, TPoint& winpt)
{
  int sendval;

  if (mousedown == HSB_NOTDOWN)	// mousedown was not in our scrollbar
    return(FALSE);

  newloc = GetMouseLoc(winpt);

  switch (mousedown){
    case HSB_LEFTARROW:
	    MyPaint(HSB_NOTDOWN);
	    if (newloc == mousedown)
	      parent->SendMessage(scrollmsg, SB_LINELEFT, mylongid);
	    break;

    case HSB_RIGHTARROW:
      MyPaint(HSB_NOTDOWN);
	    if (newloc == mousedown)
	      parent->SendMessage(scrollmsg, SB_LINERIGHT, mylongid);
	    break;

    case HSB_THUMB:
	    sendval = curval;		// save off before overwritting
	    SetScrollPos(origval, SV_REPAINT);
	    parent->SendMessage(scrollmsg, SB_THUMBPOSITION, 
	      mylongid | sendval);
	    break;
	
    default:
	    MyPaint(HSB_NOTDOWN);
	    break;
  }

  parent->SendMessage(scrollmsg, SB_ENDSCROLL, mylongid);
  mousedown = HSB_NOTDOWN;
  return(TRUE);
}
//----------------------------------------------------------------------------
void THScroll::AutoScrollMouse()
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
void THScroll::AutoScrollAction()
{
  if (newloc != mousedown)
    return;

  switch (mousedown) {
    case HSB_LEFTARROW:
	    parent->SendMessage(scrollmsg, SB_LINELEFT, mylongid);
	    break;

    case HSB_RIGHTARROW:
	    parent->SendMessage(scrollmsg, SB_LINERIGHT, mylongid);
	    break;

    case HSB_LEFTTHUMB:
	    parent->SendMessage(scrollmsg, SB_PAGELEFT, mylongid);
	    break;

    case HSB_RIGHTTHUMB:
	    parent->SendMessage(scrollmsg, SB_PAGERIGHT, mylongid);
	    break;
  }
}
//----------------------------------------------------------------------------
