//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of class TBitmapGadget
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_BITMAPGA_H)
# include <owl/bitmapga.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif
#if !defined(OWL_CELARRAY_H)
# include <owl/celarray.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGadget);  // diagnostic group for gadgets

//
// Construct a bitmap gadget
//
TBitmapGadget::TBitmapGadget(TResId imageResIdOrIndex,
                             int    id,
                             TBorderStyle borderStyle,
                             int    numImages,
                             int    startImage,
                             bool   sharedCels)
:
  TGadget(id, borderStyle),
  NumImages(numImages),
  CurrentImage(startImage),
  ImageArray(0),            // Created on first call to GetDesiredSize
  BitmapOrigin(0)
{
  if (sharedCels) {
    ResId = 0;
    ImageIndex = (int)(const char far*)imageResIdOrIndex;
  }
  else {
    ResId = imageResIdOrIndex;
    ImageIndex = 0;
  }

  TRACEX(OwlGadget, OWL_CDLEVEL, "TBitmapGadget constructed @" << this);
}

//
// Destruct a bitmap gadget and free its resources
//
TBitmapGadget::~TBitmapGadget()
{
  delete ImageArray;
  TRACEX(OwlGadget, OWL_CDLEVEL, "TBitmapGadget destructed @" << this);
}

//
// Handle a system color change by cleaning up & reloading & processing the
// bitmap. Is also called to create the initial bitmap.
//
void
TBitmapGadget::SysColorChange()
{
  delete ImageArray;

  if (ResId) {
    TDib dib(*Window->GetModule(), ResId);
    dib.MapUIColors(TDib::MapFace | TDib::MapText | TDib::MapShadow |
      TDib::MapHighlight);
    ImageArray = new TCelArray(dib, NumImages);
  }
}

//
// Set the bounding rect for this button gadget. Also takes care of
// re-centering the image
//
void
TBitmapGadget::SetBounds(const TRect& boundRect)
{
  TRACEX(OwlGadget, 1, "TBitmapGadget::SetBounds() called @" << this);
  TGadget::SetBounds(boundRect);

  TRect innerRect;
  GetInnerRect(innerRect);

  TSize bitmapSize = ImageArray->CelSize();

  BitmapOrigin.x = innerRect.left + (innerRect.Width()-bitmapSize.cx)/2;
  BitmapOrigin.y = innerRect.top + (innerRect.Height()-bitmapSize.cy)/2;
}

//
// Find out how big this bitmap gadget wants to be. Calculated using the base
// size to get the borders, etc. plus the image size.
//
void
TBitmapGadget::GetDesiredSize(TSize& size)
{
  TRACEX(OwlGadget, 1, "TBitmapGadget::GetDesiredSize() called @" << this);
  TGadget::GetDesiredSize(size);

  if (!ImageArray)
    SysColorChange();   // Get the initial bitmap

  size += (ImageArray ? ImageArray->CelSize() : Window->GetCelArray().CelSize());
}

//
// Choose the relative image to display. If immediate is true, this gadget is
// repainted immediately
//
int
TBitmapGadget::SelectImage(int imageNum, bool immediate)
{
  PRECONDITION(imageNum >=0 && imageNum < NumImages);

  uint oldImageNum = CurrentImage;

  if (imageNum != CurrentImage) {
    CurrentImage = imageNum;
    Invalidate(false);
  }

  if (immediate)
    Update();
  return oldImageNum;
}

//
// Paint this bitmap gadget. Uses normal borders, plus draws the image centered
//
void
TBitmapGadget::Paint(TDC& dc)
{
  PaintBorder(dc);

  TRect destRect;
  GetInnerRect(destRect);

  TCelArray& imageArray = ImageArray ? *ImageArray : Window->GetCelArray();

  imageArray.BitBlt(ImageIndex+CurrentImage, dc, destRect.left, destRect.top);
}
