//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.23  $
//
// Implementation of TGlyphButton
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_GLYPHBTN_H)
# include <owl/glyphbtn.h>
#endif
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif
#if !defined(WINSYS_SYSTEM_H)
# include <winsys/system.h>
#endif

const int  LayoutMargin         = 4;
const int  FaceToFocusRectDelta = -1;
const int  BUTTONSTATE_PUSHED   = 0x0004;
const int  BUTTONSTATE_FOCUS    = 0x0008;
const int  BUTTONSTYLE_MASK     = 0x00FF;
const long RopDSPDxax           = 0x00E20746L;

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlControl);        // General Controls diagnostic group

// Hard-coded color constant that a bitmap designer can use as background.
// This color RGB(192, 192, 192) can then be mapped to the BTNFACE color
// at runtime.
//
TColor TBtnBitmap::DefaultFaceColor = TColor::LtGray;

//
// Constructor of BtnBitmap - Loads the specified bitmap and updates the
// face color if necessary.
//
TBtnBitmap::TBtnBitmap(HINSTANCE hInstance, TResId resId,
                       const TColor& faceColor)
:
  TBitmap(hInstance, resId),
  FaceColor(faceColor)
{
  UpdateFaceColor();
}

//
// Constructor of BtnBitmap - aliases the specified bitmap handle and
// updates the face color if necessary
//
TBtnBitmap::TBtnBitmap(HBITMAP hBitmap, const TColor& faceColor,
                       TAutoDelete autoDelete)
:
  TBitmap(hBitmap, autoDelete),
  FaceColor(faceColor)
{
  UpdateFaceColor();
}

//
// Updates the face color of the associated bitmap if the current face
// color does not match the 3DFACE system color.
//
void
TBtnBitmap::UpdateFaceColor()
{
  if (FaceColor != TColor::Sys3dFace) {
    TBitmap copy(*this);
    TMemoryDC dstDC, srcDC;
    dstDC.SelectObject(*this);
    srcDC.SelectObject(copy);
    MapColor(dstDC, srcDC, TColor::Sys3dFace, FaceColor, Width(), Height());
    dstDC.RestoreBitmap();
    srcDC.RestoreBitmap();
    FaceColor = TColor::Sys3dFace;
  }
}

//
// Helper routine used to map the face color of the underlying bitmap
//
void
TBtnBitmap::MapColor(TDC& dc, TDC& srcDC, const TColor& toColor,
                     const TColor& fromColor, int width, int height)
{
  // Create a monochrome mask
  //
  TMemoryDC hMemDC(srcDC);
  TBitmap hMask(width, height);
  hMemDC.SelectObject(hMask);

  // Build a mask where the source color is zeroed
  //
  TColor crBack = srcDC.SetBkColor(fromColor);
  hMemDC.BitBlt(0, 0, width, height, srcDC, 0, 0, SRCCOPY);
  srcDC.SetBkColor(crBack);

  // Make a brush out of the destination color
  //
  TBrush brush(toColor);
  dc.SelectObject(brush);

  // Copy the mask to the destination
  //
  dc.BitBlt(0, 0, width, height, srcDC, 0, 0, SRCCOPY);

  // Copy the source bitmap to the destination by applying the
  // brush where pixels are zeroed
  //
  dc.BitBlt(0, 0, width, height, hMemDC, 0, 0, RopDSPDxax);
  dc.RestoreBrush();
}

//
// Constructor of TGlyphButton - Use this constructor to create a GlyphBtn
// from scratch.
//
TGlyphButton::TGlyphButton(TWindow* parent, int id, const char far* text,
                           int X, int Y, int W, int H, bool isDefault,
                           TModule* module)
:
  TButton(parent, id, text, X, Y, W, H, isDefault, module)
{
  InitVars();
}

//
// Constructor of TGlyphButton - Use this constructor to alias a glyph button
// control specified in a dialog template.
//
TGlyphButton::TGlyphButton(TWindow* parent, int resourceId, TModule* module)
:
  TButton(parent, resourceId, module)
{
  InitVars();
}

//
// Method used to initialized variables used by GlyphButton's implementation
//
void
TGlyphButton::InitVars()
{
  UpBmp = 0;
  DownBmp = 0;
  FocusBmp = 0;
  DisabledBmp = 0;
  BtnFont = new TDefaultGUIFont;
  xText = yText = -1;
  xGlyph = yGlyph = -1;
  LayStyle = lsH_GST;
  Set(biShowText);
}

//
// Destructor - Cleanup resources used by Glyph Button object
//
TGlyphButton::~TGlyphButton()
{
  delete UpBmp;
  delete DownBmp;
  delete FocusBmp;
  delete DisabledBmp;
  delete BtnFont;
}

//
// Response Table
//
DEFINE_RESPONSE_TABLE1(TGlyphButton, TButton)
  EV_WM_PAINT,
  EV_WM_ERASEBKGND,
  EV_WM_SETFOCUS,
  EV_WM_KILLFOCUS,
  EV_WM_GETFONT,
  EV_WM_SETFONT,
  EV_WM_GETDLGCODE,
  EV_WM_LBUTTONDOWN,
  EV_WM_LBUTTONDBLCLK,
  EV_WM_LBUTTONUP,
  EV_WM_MOUSEMOVE,
  EV_WM_KEYDOWN,
  EV_WM_KEYUP,
  EV_WM_ENABLE,
  EV_WM_CANCELMODE,
  EV_MESSAGE(BM_SETSTATE, BmSetState),
  EV_MESSAGE(BM_GETSTATE, BmGetState),
  EV_MESSAGE(BM_SETSTYLE, BmSetStyle),
END_RESPONSE_TABLE;

//
// Window proc. of control to handle messages sent before OWL thunks
//
LRESULT CALLBACK OWL_EXPORT16
BButtonProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch(msg) {
    case WM_GETDLGCODE: {
      uint32 style = GetWindowLong(hwnd, GWL_STYLE);
      uint16 btnStyle = uint16(LoUint16(style) & BUTTONSTYLE_MASK);
      if (btnStyle == BS_DEFPUSHBUTTON)
        return DLGC_BUTTON|DLGC_DEFPUSHBUTTON;
      else
        return DLGC_BUTTON|DLGC_UNDEFPUSHBUTTON;
    }
  }
  return DefWindowProc(hwnd, msg, wParam, lParam);
}

//
// Overriden virtual of TWindow - Fills out information about the Window
// class associated with a glyph button.
// NOTE: The class information is based on the system's "BUTTON" class.
//
void
TGlyphButton::GetWindowClass(WNDCLASS& wndClass)
{
  // Grab a the attributes of the native "BUTTON" control
  //
  if (::GetClassInfo(0, "BUTTON", &wndClass)) {
    wndClass.hInstance = *GetModule();
    wndClass.lpszClassName = GetClassName();
    wndClass.lpfnWndProc = BButtonProc;
  }
  else {
    TControl::GetWindowClass(wndClass);
    wndClass.style = CS_HREDRAW|CS_VREDRAW|CS_PARENTDC;
    wndClass.hbrBackground = HBRUSH(COLOR_BTNFACE+1);
  }
}

//
// Return name of window class associated with a glyph button control.
//
char far*
TGlyphButton::GetClassName()
{
  return OWL_GLYPHBTN;
}

//
// Overriden virtual of TWindow - Updates internal flags based on style of
// underlying window.
//
void
TGlyphButton::SetupWindow()
{
  TButton::SetupWindow();

  // Update state flags based on current style
  //
  uint32 style = GetStyle();
  if (style & BS_DEFPUSHBUTTON)
    Set(biDefault);
  if (style & WS_DISABLED)
    Set(biDisabled);
}

//
// Specifies a bitmap to be used as glyph
//
void
TGlyphButton::SetGlyph(HBITMAP hBitmap, TGlyphType type, TAutoDelete autoDelete)
{
#if defined(BI_PLAT_WIN16)
  PRECONDITION(!hBitmap || ::IsGDIObject(hBitmap) != 0);
#else
  PRECONDITION(!hBitmap || ::GetObjectType(hBitmap) == OBJ_BITMAP);
#endif

  SetGlyph(hBitmap ? new TBitmap(hBitmap, autoDelete) : (TBitmap*)0, type);
}

//
// Specify the resource identifier of a bitmap to be used as glyph
//
void
TGlyphButton::SetGlyph(TResId resId, TModule* module, TGlyphType type)
{
  PRECONDITION(module != 0 || GetModule());
  SetGlyph(new TBitmap(module ? *module : *GetModule(), resId), type);
}

//
// Specify a bitmap object to be used as glyph
// NOTE: The 'bitmap' parameter can be 0 to reset the glyph stored by the
//       glyph button object.
//
void
TGlyphButton::SetGlyph(TBitmap* bitmap, TGlyphType type)
{
  PRECONDITION(!bitmap || bitmap->IsGDIObject());

  switch (type) {
    case gtUp:
      delete UpBmp;
      UpBmp = bitmap;
      break;

    case gtDown:
      delete DownBmp;
      DownBmp = bitmap;
      break;

    case gtFocus:
      delete FocusBmp;
      FocusBmp = bitmap;
      break;

    case gtDisabled:
      delete DisabledBmp;
      DisabledBmp = bitmap;
      break;

    default:
      break;
  }

  // Update status flag
  //
  if (UpBmp)
    Set(biShowGlyph);
  else
    Clear(biShowGlyph);
}

//
// WM_PAINT handler - Invokes 'Paint' method to display glyph and/or text.
//
void
TGlyphButton::EvPaint()
{
  TPaintDC dc(*this);
  TRect&   rect = *(TRect*)&dc.Ps.rcPaint;
  Paint(dc, dc.Ps.fErase, rect);
}

//
// Invoke 'PaintButton' to display glyph and/or text.
//
void
TGlyphButton::Paint(TDC& dc, bool /*erase*/, TRect& /*rect*/)
{
  PaintButton(dc);
}


//
// WM_ERASEBKGND handler - Return true to prevent background from being
// erased. (WM_PAINT handler paints whole client area).
//
bool
TGlyphButton::EvEraseBkgnd(HDC /*dc*/)
{
  return true;
}

//
// WM_SETFOCUS handler - Updates internal flag and forces button to redraw
//
void
TGlyphButton::EvSetFocus(THandle /*hWndLostFocus*/)
{
  Set(biFocus);
  Invalidate(true);
}

//
// WM_KILLFOCUS handler - Updates internal flag and forces button to redraw
//
void
TGlyphButton::EvKillFocus(THandle /*hWndGetFocus*/)
{
  Clear(biFocus);
  if (IsSet(biPushed))
    ClearCapture();
  else
    Invalidate(true);
}

//
// WM_GETFONT handler - Returns font used by control if one was specified
// earlier. Otherwise, returns 0.
//
HFONT
TGlyphButton::EvGetFont()
{
  PRECONDITION(!BtnFont || BtnFont->IsGDIObject());
  return BtnFont ? HFONT(*BtnFont) : HFONT(0);
}

//
// WM_SETFONT Handler. Deletes any cached font and stores copy of new one.
//
void
TGlyphButton::EvSetFont(HFONT hFont, bool redraw)
{
  delete BtnFont;
  BtnFont = new TFont(hFont);
  if (redraw)
    Invalidate();
}

//
// WM_GETDLGCODE handler. Inform dialog manager that we're a 'normal' push
// button or the default push button according to our style.
//
uint
TGlyphButton::EvGetDlgCode(MSG* /*msg*/)
{
  if (IsSet(biDefault))
    return DLGC_BUTTON|DLGC_DEFPUSHBUTTON;
  else
    return DLGC_BUTTON|DLGC_UNDEFPUSHBUTTON;
}

//
// WM_LBUTTONDOWN handler. Grab focus and update button's state to be in
// 'pushed' mode.
//
void
TGlyphButton::EvLButtonDown(uint /*modKeys*/, TPoint& /*point*/)
{
  SetCapture();
  SendMessage(BM_SETSTATE, TRUE);
  if (!IsSet(biFocus))
    SetFocus();
}

//
// WM_LBUTTONDBLCLK handler. Simply forward to LBUTTONDOWN handler
//
void
TGlyphButton::EvLButtonDblClk(uint modKeys, TPoint& point)
{
  EvLButtonDown(modKeys, point);
}

//
// WM_LBUTTONUP handler. Restore state of button and notify parent with a
// CLICKED message if necessary.
//
void
TGlyphButton::EvLButtonUp(uint /*modKeys*/, TPoint& point)
{
  if (GetCapture() == *this) {
    ReleaseCapture();

    SendMessage(BM_SETSTATE, FALSE);

    TRect rect;
    GetClientRect(rect);

    if (rect.Contains(point)) {
      SendNotification(::GetParent(*this), GetDlgCtrlID(),
                       BN_CLICKED, *this);
    }
  }
}

//
// WM_MOUSEMOVE handler. Update state of button if we're in 'capture' mode.
//
void
TGlyphButton::EvMouseMove(uint modKeys, TPoint& point)
{
  if (modKeys & MK_LBUTTON && GetCapture() == *this) {
    TRect rect;
    GetClientRect(rect);

    if (rect.Contains(point))
      SendMessage(BM_SETSTATE, TRUE);
    else
      SendMessage(BM_SETSTATE, FALSE);
  }
}

//
// WM_KEYDOWN handler. Update state of button upon detecting that user
// pressed the space bar.
//
void
TGlyphButton::EvKeyDown(uint key, uint /*repeatCount*/, uint /*flags*/)
{
  if (key == VK_SPACE)
    SendMessage(BM_SETSTATE, TRUE);
}

//
// WM_KEYUP handler. Restore state of button and notify parent
//
void
TGlyphButton::EvKeyUp(uint key, uint /*repeatCount*/, uint /*flags*/)
{
  if (IsSet(biPushed) && key == VK_SPACE) {
    SendMessage(BM_SETSTATE, FALSE);

    SendNotification(::GetParent(*this), GetDlgCtrlID(),
                      BN_CLICKED, *this);
  }
}

//
// WM_ENABLE handler. Update internal flags and invalidate control if
// necessary.
//
void
TGlyphButton::EvEnable(bool enabled)
{
  if (enabled) {
    Clear(biDisabled);
  }
  else {
    ClearCapture();
    Set(biDisabled);
  }
  Invalidate(true);
}

//
//
//
void
TGlyphButton::EvCancelMode()
{
  ClearCapture();
}

//
// BM_GETSTATE handler. Return the current state of the window.
//
TResult
TGlyphButton::BmGetState(TParam1 /*param1*/, TParam2 /*param2*/)
{
  TResult result = 0;
  if (IsSet(biPushed))
    result |= BUTTONSTATE_PUSHED;

  if (IsSet(biFocus))
    result |= BUTTONSTATE_FOCUS;

  return result;
}

//
// BM_SETSTATE handler. Update internal state flags based on parameters and
// redraw control if necessary.
//
TResult
TGlyphButton::BmSetState(TParam1 param1, TParam2 /*param2*/)
{
  if (param1) {
    // Needs hilight look
    //
    if (!IsSet(biPushed)) {
      Set(biPushed);
      PaintNow();
    }
  }
  else {
    // Needs normal look
    //
    if (IsSet(biPushed)) {
      Clear(biPushed);
      PaintNow();
    }
  }
  return 0;
}

//
// BM_SETSTYLE handler. Update internal flags to match specified parameters
// and invalidate the window if necessary.
//
TResult
TGlyphButton::BmSetStyle(TParam1 param1, TParam2 /*param2*/)
{
  // Grab and splice the styles
  //
  uint32 style = GetStyle();
  uint16 winStyle = HiUint16(style);
  uint16 btnStyle = uint16(LoUint16(style) & BUTTONSTYLE_MASK);

  // Check against passed in parameter
  // NOTE: We only cater to PUSHBUTTON and DEFPUSHBUTTON
  //       The current definition so BS_PUSHBUTTON is 0L
  //
  if (LOWORD(param1) == BS_PUSHBUTTON  &&  btnStyle != BS_PUSHBUTTON) {

    // Make 'simple' push button
    //
    TWindow::SetStyle(MAKELONG(param1, winStyle));
    Clear(biDefault);
    Invalidate(true);
  }
  else if (LOWORD(param1)==BS_DEFPUSHBUTTON && btnStyle != BS_DEFPUSHBUTTON){

    // Make 'default' push button
    //
    TWindow::SetStyle(MAKELONG(param1, winStyle));
    Set(biDefault);
    Invalidate(true);
  }

#if defined(__DEBUG) || defined(__TRACE) || defined(__WARN)
  if (LOWORD(param1) != BS_PUSHBUTTON &&
      LOWORD(param1) != BS_DEFPUSHBUTTON)
    TRACEX(OwlControl, 0, "BmSetStyle: Invalid style specified");
#endif

  return 0;
}

//
// Release caption if we are in 'capture' mode. Reset internal flags
// appropriately.
//
void
TGlyphButton::ClearCapture()
{
  if (GetCapture() == *this)
    ReleaseCapture();
  Clear(biPushed);
  Invalidate(true);
}

//
// Paint the button into a memory DC and bitblt the final rendering to the
// specified 'dc'.
//
void
TGlyphButton::PaintButton(TDC& dc)
{
  TRect rect;
  GetClientRect(rect);

  // Create compatible bitmap
  //
  TBitmap memBmp(dc, rect.Width(), rect.Height());

  // Create compatible memory DC
  //
  TMemoryDC memDC(dc);

  // Select and init memory bitmap
  //
  memDC.SelectObject(memBmp);

  // Save the rectangle for bitblt'ing - 'rect' will be adjusted
  // as we move from defaultFrame, border and face...
  //
  TRect bltRect = rect;

  // Paint the button into the memory DC
  //
  PaintDefaultRect(memDC, rect);
  PaintFrame(memDC, rect);
  PaintFace(memDC, rect);

  // Bitblt the button to the output device
  //
  dc.BitBlt(bltRect, memDC, TPoint(bltRect.left, bltRect.top));

  // Cleanup
  //
  memDC.RestoreBitmap();
}

//
// Draw the border of the button
//
void
TGlyphButton::PaintFrame(TDC& dc, TRect& rect)
{
  // Paint the border
  //
  TUIBorder uiBorder(rect, IsSet(biPushed) ? TUIBorder::ButtonDn :
                                             TUIBorder::ButtonUp);
  uiBorder.Paint(dc);

  // Shrink the rectangle to leave the face
  //
  rect = uiBorder.GetClientRect();
}

//
// Draw a frame around the button if it's a default push button.
//
void
TGlyphButton::PaintDefaultRect(TDC& dc, TRect& rect)
{
  if (IsSet(biDefault)) {
    if (rect.Width() > 2 && rect.Height() > 2) {
      TPen framePen(TColor::SysWindowFrame);
      dc.SelectObject(framePen);
      TBrush nullBrush(HBRUSH(::GetStockObject(NULL_BRUSH)));
      dc.SelectObject(nullBrush);
      dc.Rectangle(rect);
      rect.Inflate(-1, -1);
      dc.RestoreBrush();
      dc.RestorePen();
    }
  }
}

//
// Draw the face of the button [i.e. text and glyph portions]
//
void
TGlyphButton::PaintFace(TDC& dc, TRect& rect)
{
  // Fill the background with the face color
  //
  TBrush brush(TColor::Sys3dFace);
  dc.FillRect(rect, brush);

  // Grab the glyph and it's size
  //
  TBitmap* glyph = 0;             // Pointer to glyph
  TRect glyphRect(0, 0, 0, 0);    // Size of glyph
  if (IsSet(biShowGlyph)) {
    // Start with the up bitmap
    //
    glyph = UpBmp;

    // Switch to more appropriate bitmap if applicable
    //
    if (IsSet(biPushed) && DownBmp)
      glyph = DownBmp;
    else if (IsSet(biDisabled) && DisabledBmp)
      glyph = DisabledBmp;

    CHECK(glyph && glyph->IsGDIObject());
    glyphRect.Set(0, 0, glyph->Width(), glyph->Height());
  }

  // Grab some information about the text/caption
  //
  int len = 0;                    // Length of Caption
  TRect textRect(0, 0, 0, 0);     // Size of text
  TAPointer<char> text;           // Pointer to caption dynamic buffer
  TPointer<TFont> tmpFnt;         // Object wrapping font handle
  TColor textColor;               // Color used for button's text

  if (IsSet(biShowText)) {
    len = GetWindowTextLength();
    if (len) {

      // Select the font
      //
      if (!BtnFont) {
        HFONT hFont = HFONT(::SendMessage(::GetParent(*this), WM_GETFONT,
                                          0, 0));
        if (!hFont)
          hFont = HFONT(GetStockObject(TSystem::Has3dUI() ? ANSI_VAR_FONT :
                                                            SYSTEM_FONT));
        if (hFont)
          tmpFnt = new TFont(hFont);
      }
      if (BtnFont) {
        CHECK(BtnFont->IsGDIObject());
        dc.SelectObject(*BtnFont);
      }
      else if (tmpFnt) {
        CHECK(((TFont&)tmpFnt).IsGDIObject());
        dc.SelectObject((TFont&)tmpFnt);
      }

      text = new char[len+1];
      GetWindowText(text, len+1);
      textRect.Set(0, 0, rect.Width() - glyphRect.Width(), SHRT_MAX);

      // Display text in proper color
      //
      // Under NT 3.51 and Window 3.1, the system inexplicably returns values
      // for gray text that are the same as either button text (so text never
      // looks grayed) or as button face (so grayed text is invisible).  The
      // extra if statement guards against those problems.
      //
      if (IsSet(biDisabled)) {
        textColor = TColor::SysGrayText;
        if ((textColor == TColor::Sys3dFace.GetValue()) || 
            (textColor == TColor::SysBtnText.GetValue())) {
          textColor = TColor::Sys3dShadow;
        }
      } else {
        textColor = TColor::SysBtnText;
      }

      TColor oldColor = dc.SetTextColor(textColor); 
      dc.DrawText(text, len, textRect, DT_WORDBREAK|DT_CALCRECT);
      dc.SetTextColor(oldColor);                    
    }
  }

  // If we have text and/or glyph, lay them out and paint them
  //
  if (!textRect.IsNull() || !glyphRect.IsNull()) {

    LayoutTextGlyph(rect, textRect, glyphRect);

    // Offset things to the lower right if we're in down
    //
    if (IsSet(biPushed)) {
      if (!glyphRect.IsNull() && glyph == UpBmp)
        glyphRect.Offset(1, 1);
      if (!textRect.IsNull())
        textRect.Offset(1, 1);
    }

    // Paint the components of the button
    //
    if (!glyphRect.IsNull()) {
      PRECONDITION(glyph && glyph->IsGDIObject());
      TUIFace uiFace(glyphRect, *glyph);
      uiFace.Paint(dc, TPoint(0, 0), TUIFace::Normal, false, true);
    }
    if (!textRect.IsNull()) {
      int mode = dc.SetBkMode(TRANSPARENT);
      TColor oldColor = dc.SetTextColor(textColor);
      dc.DrawText(text, len, textRect, DT_WORDBREAK);
      dc.SetTextColor(oldColor);
      dc.SetBkMode(mode);
    }
  }

  // Paint the focus rect [if necessary]
  //
  if (IsSet(biFocus))
    PaintFocusRect(dc, rect);

  // Restore font
  //
  if (len && (BtnFont || tmpFnt))
    dc.RestoreFont();
}

//
// Virtual routine invoked to retrieve the placement of text and glyph
// when drawing the button.
// Override this routine to customize the layout logic and support
// custom layout styles.
//
void
TGlyphButton::LayoutTextGlyph(const TRect& faceRect, TRect& textRect,
                              TRect& glyphRect)
{
  // Must have either text or a glyph
  //
  PRECONDITION(!textRect.IsNull() || !glyphRect.IsNull());

  // First check for the case where we've got either
  // text or glyph - but not both
  //
  if (textRect.IsNull() || glyphRect.IsNull()) {
    TRect& centerRect = textRect.IsNull() ? glyphRect : textRect;

    centerRect.Offset(faceRect.left, faceRect.top);
    if (centerRect.Width() < faceRect.Width())
      centerRect.Offset((faceRect.Width() - centerRect.Width())/2, 0);
    else
      centerRect.right = faceRect.right;
    if (centerRect.Height() < faceRect.Height())
      centerRect.Offset(0, (faceRect.Height() - centerRect.Height())/2);
    else
      centerRect.bottom = faceRect.bottom;
  }

  // Here we attempt to layout both the glyph and text
  //
  else {

    // Align upper left corners of face, text and glyph rectangles
    //
    glyphRect.Offset(faceRect.left, faceRect.top);
    textRect.Offset(faceRect.left, faceRect.top);

    // Compute amount of 'extra' space, if any, and how to partition it
    // between the two items
    //
    int space  = faceRect.Width() - glyphRect.Width()- textRect.Width() -
                 LayoutMargin*2;
    int gDelta;
    int tDelta;

    switch (LayStyle) {
     case lsH_SGST: {
              gDelta = space >= 0 ? LayoutMargin + space/3 :
                                    LayoutMargin + space/2;
              tDelta = space >= 0 ? gDelta + glyphRect.Width() + space/3 :
                                    gDelta + glyphRect.Width();
            }
            break;

      case lsH_GST: {
              gDelta = space >= 0 ? LayoutMargin : LayoutMargin + space/2;
              tDelta = space >= 0 ? gDelta + glyphRect.Width() + space/2 :
                                    gDelta + glyphRect.Width();
            }
            break;


      default:
        break;
    }

    if (LayStyle == lsH_SGST || LayStyle == lsH_GST) {

      // Center vertically
      //
      if (textRect.Height() < faceRect.Height())
        textRect.Offset(0, (faceRect.Height() - textRect.Height())/2);
      if (glyphRect.Height() < faceRect.Height())
        glyphRect.Offset(0, (faceRect.Height() - glyphRect.Height())/2);

      // Layout horizontally
      //
      glyphRect.Offset(gDelta, 0);
      textRect.Offset(tDelta, 0);
    }
  }
}

//
// Specify a 'style' describing how text and glyph should be laid out.
// Invalidate the window if necessary.
//
void
TGlyphButton::SetLayoutStyle(TLayoutStyle style)
{
  if (style != LayStyle) {
    LayStyle = style;
    if (GetHandle())
      Invalidate();
  }
}

//
// Sets text coordinates and invalidates window if necessary
//
void
TGlyphButton::SetTextOrigin(int x, int y)
{
  if (x != xText || y != yText) {
    xText = x;
    yText = y;
    if (GetHandle())
      Invalidate();
  }
}

//
// Set the upper left corner of glyphs and invalidates window if necessary
//
void
TGlyphButton::SetGlyphOrigin(int x, int y)
{
  if (x != xGlyph || y != yGlyph) {
    xGlyph = x;
    yGlyph = y;
    if (GetHandle())
      Invalidate();
  }
}

//
// Display a focus rectangle
//
void
TGlyphButton::PaintFocusRect(TDC& dc, const TRect& faceRect)
{
  PRECONDITION(IsSet(biFocus));
  TRect focusRect = faceRect;
  focusRect.Inflate(FaceToFocusRectDelta, FaceToFocusRectDelta);
  dc.DrawFocusRect(focusRect);
}

//
// Repaints window right away by retrieving a client DC and invoking the
// 'Paint' method.
//
void
TGlyphButton::PaintNow()
{
  TRect rect;
  GetClientRect(rect);
  TClientDC dc(*this);
  Paint(dc, false, rect);
}
