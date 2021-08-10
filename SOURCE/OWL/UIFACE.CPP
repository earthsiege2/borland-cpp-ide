//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implements TUIFace
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_UIHELPER_H)
# include <owl/uihelper.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

const long RopPSDPxax = 0x00B8074AL;  //
const long RopDSPDxax = 0x00E20746L;  //

//
// Return a brush created using a hatched [checkerboard] pattern of the button
// highlight color. This brush is commonly used for rendering 'indeterminate'
// or 'mixed-value' appearances.
//
// NOTE: Automatically reconstructs the brush if the relevant system color
//       changed during a session...
//
THatch8x8Brush&
TUIFace::GetDitherBrush()
{
  static uint32 ditherColor = TColor::Sys3dHilight;
  static THatch8x8Brush ditherBrush(THatch8x8Brush::Hatch11F1,
                                    TColor::Sys3dFace,
                                    TColor::Sys3dHilight);

  // Reconstruct the brush in case the system colors have changed
  // since the brush was constructed
  //
  if (ditherColor != TColor::Sys3dHilight) {
    ditherBrush.Reconstruct(THatch8x8Brush::Hatch11F1,
                            TColor::Sys3dFace,
                            TColor::Sys3dHilight);
    ditherColor = TColor::Sys3dHilight;
  }

  // Return ref. to static brush
  //
  return ditherBrush;
}

//
// Return a reference to a static monochrome bitmap. The optional TSize
// pointer allows the routine to ensure that the bitmap is big enough for a
// given use.
//
TBitmap&
TUIFace::GetGlyphMask(const TSize& minSize)
{
  // Start off with no bitmap, allocate below with requested or default size
  //
  static TSize maskSize(0,0);      // Current mask size
  static TPointer<TBitmap> maskBm; // Current mask bm

  // (Re)allocate mask bitmap if we need a bigger one
  //
  if (minSize.cx > maskSize.cx || minSize.cy > maskSize.cy) {
    if (maskSize.cx < minSize.cx)
      maskSize.cx = minSize.cx;
    if (maskSize.cy < minSize.cy)
      maskSize.cy = minSize.cy;
    maskBm = new TBitmap(maskSize.cx, maskSize.cy, 1, 1, 0);
  }
  return *maskBm;
}

//
// Build a monochrome mask bitmap for the glyph that has 1's where color
// Sys3dFace is and 0's everywhere else.
//
// NOTE: Assumes DC's are already setup - i.e. maskDC has the destination
//       monochrome bitmap selected in it and glyphDC has the image selected
//       in it..
//
void
TUIFace::BuildMask(TDC& maskDC, const TPoint& maskDst, const TSize& maskSize,
                   TDC& glyphDC, const TRect& glyphRect,
                   const TColor& maskedColor)
{
  maskDC.PatBlt(0, 0, maskSize.cx, maskSize.cy, WHITENESS);
  if (maskedColor != TColor::None) {
    TColor bkColor = glyphDC.SetBkColor(TColor::Sys3dFace);
    maskDC.BitBlt(maskDst.x, maskDst.y, glyphRect.Width(), glyphRect.Height(),
                  glyphDC, glyphRect.left, glyphRect.top, SRCCOPY);
    glyphDC.SetBkColor(bkColor);
  }
}

//
// Paint onto a given DC withing a given rect using a monochrome BM in a dc as
// a stencil and an arbitrary brush
//
void
TUIFace::FillBackground(TDC& dc, TDC& maskDC, const TRect& dstRect,
                        const TBrush& brush)
{
  dc.SelectObject(brush);
  TColor txtClr = dc.SetTextColor(TColor::Black);
  TColor bkClr = dc.SetBkColor(TColor::White);

  dc.BitBlt(dstRect, maskDC, TPoint(0, 0), RopDSPDxax);

  dc.SetTextColor(txtClr);
  dc.SetBkColor(bkClr);
  dc.RestoreBrush();
}

//
// Tiles the rectangle with a even dithered (checkerboard) pattern
// maskDC determines the stencil area of dither
//
void
TUIFace::DitherBackground(TDC& dc, TDC& maskDC, const TRect& dstRect)
{
  FillBackground(dc, maskDC, dstRect, GetDitherBrush());
}

//
// An extension to ::DrawText that draws etched text by writing twice, the
// first one offset down & right in a light color, and the second not offset
//
int
TUIFace::DrawTextEtched(TDC& dc, const char far* str, int count,
                        const TRect& rect, uint16 format)
{
  TColor txtColor = dc.SetTextColor(TColor::Sys3dHilight);
  int height = dc.DrawText(str, count, rect.OffsetBy(1, 1), format);

  if (!(format & DT_CALCRECT)) {
    dc.SetTextColor(TColor::Sys3dShadow);
    height = dc.DrawText(str, count, rect, format);
  }
  dc.SetTextColor(txtColor);
  return height;
}

//
// Internal bitmap painting function
//
void
TUIFace::PaintBm(const TBitmap& glyph, const TRect& glyphSrcRect,
                 TDC& dc, const TRect& faceRect, const TPoint& dstPoint,
                 TState state, bool pressed, bool fillFace,
                 const TColor& maskColor, const TColor& fillColor)
{
  // Select our glyph in a working memory DC
  //
  TMemoryDC memDC(CONST_CAST(TBitmap&,glyph));
  memDC.SetTextColor(TColor::Black);
  memDC.SetBkColor(TColor::White);

  // Calculate the glyph's destination rect.
  // Calculate the rect to fill in, depending on fill-face flag
  //
  TRect glyphDstRect(faceRect.TopLeft() + dstPoint, glyphSrcRect.Size());
  glyphDstRect &= faceRect;
  TRect fillRect(fillFace ? faceRect : glyphDstRect);
  TPoint dstPt(dstPoint);

  // When the glyph is down, offset it's origin one pixel to the lower right.
  // Make sure the glyph rect doesn't hang outside the face
  //
  if (pressed || state == Down) {
    dstPt.Offset(1,1);
    glyphDstRect.Offset(1,1);
    glyphDstRect &= faceRect;
  }
  TSize glyphSize = glyphDstRect.Size(); // Get last in case it's clipped

  // Draw according the specified state
  //
  switch (state) {
    case Normal: {
      if (fillFace) {

        // Build mask of bitmap
        //
        TMemoryDC maskDC(GetGlyphMask(fillRect.Size()));
        BuildMask(maskDC, dstPt, fillRect.Size(), memDC, glyphSrcRect, maskColor);

        // Fill background around mask with button face
        //
        FillBackground(dc, maskDC, fillRect, TBrush(TColor::Sys3dFace));
      }

      dc.BitBlt(glyphDstRect, memDC, glyphSrcRect.TopLeft());
      break;
    }

    case Down: {
      // Start with normal glyph
      //
      dc.BitBlt(glyphDstRect, memDC, glyphSrcRect.TopLeft(), SRCCOPY);

      // Build a mask of the glyph & dither the background around the glyph
      //
      TMemoryDC maskDC(GetGlyphMask(fillRect.Size()));
      BuildMask(maskDC, dstPt, fillRect.Size(), memDC, glyphSrcRect, maskColor);
      DitherBackground(dc, maskDC, fillRect);
      break;
    }

    case Indeterm: {
      TMemoryDC maskDC(GetGlyphMask(fillRect.Size()));
      BuildMask(maskDC, dstPt, fillRect.Size(), memDC, glyphSrcRect, maskColor);

      // Inactivate mask--convert the highlight color to 1's on existing
      // mask
      //
      dc.SetBkColor(TColor::Sys3dHilight);
      maskDC.BitBlt(glyphDstRect, memDC, glyphSrcRect.TopLeft(), SRCPAINT);

      // Fade the image by replacing the button text color with the button
      // shadow color
      //
      TBrush  shadowBrush(TColor::Sys3dShadow);
      dc.SelectObject(shadowBrush);
      dc.BitBlt(fillRect, maskDC, TPoint(0,0), RopPSDPxax);

      // Dither the background everywhere except where the glyph is
      //
      DitherBackground(dc, maskDC, faceRect);
      dc.RestoreBrush();
      maskDC.RestoreBitmap();
      break;
    }

    case Disabled: {

      // Fill background..
      //
      dc.TextRect(fillFace ? faceRect : glyphDstRect, fillColor);

      TMemoryDC maskDC(GetGlyphMask(glyphSize));
      BuildMask(maskDC, TPoint(0, 0), glyphSize, memDC, glyphSrcRect, maskColor);

      // Inactivate mask--convert the highlight color to 1's on existing mask
      //
      memDC.SetBkColor(TColor::Sys3dHilight);
      maskDC.BitBlt(glyphSrcRect, memDC, TPoint(0,0), SRCPAINT);

      // Make the image look embossed - highlight color offset down and right
      //
      dc.SetTextColor(TColor::Black);
      dc.SetBkColor(TColor::White);

      TBrush hiliteBrush(TColor::Sys3dHilight);
      dc.SelectObject(hiliteBrush);
      dc.BitBlt(glyphDstRect.left+1, glyphDstRect.top+1,
                glyphDstRect.Width()-1, glyphDstRect.Height()-1,
                maskDC, 0, 0, RopPSDPxax);
      dc.RestoreBrush();

      // Fade the image by replacing the button text color with the button
      // shadow color
      //
      TBrush shadowBrush(TColor::Sys3dShadow);
      dc.SelectObject(shadowBrush);   // 0 -> shadow
      dc.BitBlt(glyphDstRect, maskDC, TPoint(0, 0), RopPSDPxax);
      dc.RestoreBrush();

      maskDC.RestoreBitmap();
      break;
    }
    case Default: {
      dc.BitBlt(glyphDstRect, memDC, TPoint(0,0));  
      break;
    }
  }
}

//
//
//
void
TUIFace::PaintText(const char far*, TDC&, const TRect&,
                   const TPoint&, TState, bool)
{
}

//
// Paint the face of a button onto a DC.
// Assumes the entire bitmap is the face.
//
void
TUIFace::Paint(TDC& dc, const TPoint& pt, TState state, bool pressed,
               bool fillFace)
{
  if (Text)
    PaintText(Text, dc, Rect, pt, state, fillFace);
  else if (Bm)
    PaintBm(*Bm, TRect(TPoint(0,0),Bm->Size()), dc, Rect, pt, state, pressed,
            fillFace, BkgndColor, FillColor);
}

//
// Paint a portion of the source bitmap onto a DC.
// This allows one bitmap to be the source for multiple TUIFaces.
//
void
TUIFace::Paint(TDC& dc, const TRect& srcRect, const TPoint& pt, TState state,
               bool pressed, bool fillFace)
{
  if (Text)
    PaintText(Text, dc, Rect, pt, state, fillFace);
  else if (Bm)
    PaintBm(*Bm, srcRect, dc, Rect, pt, state, pressed,
            fillFace, BkgndColor, FillColor);
}

//
// Encapsulates and emulate the 32-bit DrawState API.
//
bool
TUIFace::Draw(TDC& dc, HBRUSH hbr, LPARAM lp, WPARAM wp,
              int x, int y, int cx, int cy, uint flags)
{
#if defined(BI_PLAT_WIN32)
  static bool hasDrawState = true;

  // Try once to see if the API call is available. If not, do ourselves.
  //
  if (hasDrawState) {
    if (::DrawState(dc, hbr, 0, lp, wp, x, y, cx, cy, flags))
      return true;
    if (::GetLastError() == ERROR_CALL_NOT_IMPLEMENTED)
      hasDrawState = false;  // No DrawState(). Don't try again, just emulate
    else
      return false;  // Some other error, just return
  }

  return false;
#else
  uint type = flags & 0x000F;
  uint state= flags & 0xFFF0;

  switch (type) {
    case DST_BITMAP:
    case DST_ICON:
    case DST_PREFIXTEXT:
    case DST_TEXT:
    default:
      break;
  }
  return true;
#endif
}

//
// Paint the mask onto a DC.
//
void
TUIFace::PaintMaskBm(const TBitmap& glyph, TDC& dc, const TPoint& pt,
                     const TColor& maskColor)
{
  // Create a DC to hold the image bitmap
  //
  TMemoryDC memDC;
  memDC.SelectObject(glyph);

  // Create a DC to hold an "AND mask" of image and build the mask
  //
  TMemoryDC maskDC;
  maskDC.SelectObject(GetGlyphMask(glyph.Size()));

  // Rectangle to hold mask of glyph
  //
  TRect  maskRect(TPoint(0,0), glyph.Size());

  // Build the mask
  //
  BuildMask(maskDC, TPoint(0, 0), glyph.Size(), memDC, maskRect, maskColor);

  // Make sure area under highlight color ends up fill color
  //
  // dc.TextRect(maskRect, FillColor);

  // Inactivate mask--convert the highlight color to 1's on existing mask
  //
  memDC.SetBkColor(TColor::Sys3dHilight);
  maskDC.BitBlt(maskRect, memDC, maskRect.TopLeft(), SRCPAINT);

  dc.BitBlt(TRect(pt, maskRect.Size()), maskDC, TPoint(0,0));
}

//
// Paint the mask onto a DC.
//
void
TUIFace::PaintMask(TDC& dc, const TPoint& pt)
{
  // ::DrawState()...

  if (Bm)
    PaintMaskBm(*Bm, dc, pt, BkgndColor);
  //else if (Text)
  //  PaintMaskText(Text, dc, pt);
}

