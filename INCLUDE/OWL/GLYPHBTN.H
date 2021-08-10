//-------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.15  $
//
// Definition of class TGlyphButton
//-------------------------------------------------------------------------
#if !defined(OWL_GLYPHBTN_H)
#define OWL_GLYPHBTN_H

// Macro defining class name (usable in resource definition)
//
#if !defined(OWL_GLYPHBTN)
# define OWL_GLYPHBTN  "OWL_GlyphBtn"
#endif

#if !defined(RC_INVOKED)

#if !defined(OWL_BUTTON_H)
# include <owl/button.h>
#endif
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(OWL_BITSET_H)
# include <owl/bitset.h>
#endif
#if !defined(WINSYS_COLOR_H)
# include <winsys/color.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TFont;

//
//
// class TBtnBitmap
// ~~~~~ ~~~~~~~~~~
// TBtnBitmap is an enhanced version of TBitmap with the ability to update
// the face color of a bitmap to match the current system BTNFACE color.
//
class _OWLCLASS TBtnBitmap : public TBitmap {
  public:
    TBtnBitmap(HINSTANCE hInstance, TResId resId,
               const TColor& faceColor = DefaultFaceColor);
    TBtnBitmap(HBITMAP hBitmap,
               const TColor& faceColor = DefaultFaceColor,
               TAutoDelete autoDelete = NoAutoDelete);

    void        UpdateFaceColor();
    static void MapColor(TDC& dc, TDC& srcDC, const TColor& toColor,
                         const TColor& fromColor, int width, int height);

    // By default, we'll assume that bitmaps were designed with a gray background
    //
    static TColor DefaultFaceColor;

  protected:
    TColor      FaceColor;    // Current face color of bitmap
};

//
// class TGlyphButton
// ~~~~~ ~~~~~~~~~~~~
// TGlyphButton encapsulates a control which is capable of displaying a
// bitmap (or glyph) and/or text.
//
class _OWLCLASS TGlyphButton : public TButton  {
  public:
    TGlyphButton(TWindow*        parent,
                 int             id,
                 const char far* text,
                 int X, int Y, int W, int H,
                 bool            isDefault = false,
                 TModule*        module = 0);
    TGlyphButton(TWindow* parent, int resourceId, TModule* module = 0);
   ~TGlyphButton();

    // Enumeration describing the state when a particular bitmap should
    // be displayed. Used with the 'SetGlyph' method.
    // NOTE: If only a single 'up' bitmap is specified, TGlyphBtn will
    //       automatically generate the bitmaps for the other states.
    //
    enum TGlyphType {
      gtUp       = TUIFace::Normal,   // Bitmap for when button is up
      gtDisabled = TUIFace::Disabled, // Bitmap for when button is disabled
      gtDown,                         // Bitmap for when button is depressed
      gtFocus                         // Bitmap for when button has focus
    };

    // Methods to specify the glyphs that should be used
    //
    void      SetGlyph(TBitmap* bitmap, TGlyphType = gtUp);
    void      SetGlyph(TResId resId, TModule* module = 0, TGlyphType = gtUp);
    void      SetGlyph(HBITMAP hBitmap, TGlyphType = gtUp,
                       TAutoDelete autoDelete = NoAutoDelete);

    // Enumeration describing how to position the text and glyph
    // of the button.
    //
    enum  TLayoutStyle {
      lsNone,                   // Use specified coordinates

      // Horizontal layouts [center vertically]
      //
      lsH_SGST,                 // Space Glyph Space Text
      lsH_GST,                  // Glyph Space Text
      lsH_STSG,                 // Space Text  Space Glyph
      lsH_TSGS,                 // Text  Space Glyph Space

      // Vertical layouts [center horizontally]
      //
      lsV_SGST,                 // Space Glyph Space Text
      lsV_GST,                  // Glyph Space Text
      lsV_STSG,                 // Space Text  Space Glyph
      lsV_TSGS,                 // Text  Space Glyph Space
    };

    // Methods to specify how the glyph and/or text should be laid out
    //
    void      SetLayoutStyle(TLayoutStyle style);
    void      SetTextOrigin(int x, int y);
    void      SetGlyphOrigin(int x, int y);

    // Set, clear, query flags about the state of the control
    //
    int       Clear(int t);
    int       Set(int t);
    bool      IsSet(int t) const;

  protected:
    // Overriden TWindow virtuals
    //
    void      SetupWindow();
    void      Paint(TDC& dc, bool erase, TRect& rect);
    void      GetWindowClass(WNDCLASS& wndClass);
    char far* GetClassName();

    // Routine which determines location of text and glyph
    //
    virtual void LayoutTextGlyph(const TRect& faceRect, TRect& textRect,
                                 TRect& glyphRect);
    // Initialization routine
    //
    void      InitVars();

    // Enumeration describing the current state of the button.
    //
    enum  TButtonInfo {
      biPushed   = 0x0001,      // Button is currently depressed
      biFocus    = 0x0002,      // Button has focus
      biDefault  = 0x0004,      // Button is a 'DefaultPushButton'
      biDisabled = 0x0008,      // Button is disabled
      biShowText = 0x0010,      // Button should display its caption
      biShowGlyph= 0x0020       // Button should draw its glyph
    };

    // Event handlers
    //
    void        EvPaint();
    bool        EvEraseBkgnd(HDC);
    void        EvSetFocus(THandle hWndLostFocus);
    void        EvKillFocus(THandle hWndGetFocus);
    HFONT       EvGetFont();
    void        EvSetFont(HFONT hFont, bool redraw);
    uint        EvGetDlgCode(MSG far* msg);
    void        EvLButtonDown(uint modKeys, TPoint& point);
    void        EvLButtonDblClk(uint modKeys, TPoint& point);
    void        EvLButtonUp(uint modKeys, TPoint& point);
    void        EvMouseMove(uint modKeys, TPoint& point);
    void        EvKeyDown(uint key, uint repeatCount, uint flags);
    void        EvKeyUp(uint key, uint repeatCount, uint flags);
    void        EvEnable(bool enabled);
    void        EvCancelMode();
    TResult     BmGetState(TParam1 param1, TParam2 param2);
    TResult     BmSetState(TParam1 param1, TParam2 param2);
    TResult     BmSetStyle(TParam1 param1, TParam2 param2);

    // Helper functions
    //
    void        PaintNow();
    void        PaintButton(TDC& dc);
    void        PaintFrame(TDC& dc, TRect& rect);
    void        PaintDefaultRect(TDC& dc, TRect& rect);
    void        PaintFace(TDC& dc, TRect& rect);
    void        PaintFocusRect(TDC& dc, const TRect& faceRect);
    void        ClearCapture();

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TGlyphButton(const TGlyphButton&);
    TGlyphButton& operator =(const TGlyphButton&);

    TBitmap*        UpBmp;          // Pointer to 'normal' glyph
    TBitmap*        DownBmp;        // Pointer to 'pushed' glyph
    TBitmap*        FocusBmp;       // Pointer to 'focused' glyph
    TBitmap*        DisabledBmp;    // Pointer to disabled' glyph
    TFont*          BtnFont;        // Pointer to font used by button
    int             xGlyph;         // x (left) coordinate of glyph
    int             yGlyph;         // y (top ) coordinate of glyph
    int             xText;          // x (left) coordinate of text
    int             yText;          // y (top ) coordinate of text
    TLayoutStyle    LayStyle;       // How text & glyph should be laid out
    TBitFlags<int>  Flags;          // Status flags
  DECLARE_RESPONSE_TABLE(TGlyphButton);
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Clear a flag
//
inline int
TGlyphButton::Clear(int t)
{
  return Flags.Clear(t);
}

//
// Set a flag
//
inline int
TGlyphButton::Set(int t)
{
  return Flags.Set(t);
}

//
// Test if a flag is set
//
inline bool
TGlyphButton::IsSet(int t) const
{
  return Flags.IsSet(t);
}

#endif  // !RC_INVOKED
#endif  // OWL_GLYPHBTN_H
