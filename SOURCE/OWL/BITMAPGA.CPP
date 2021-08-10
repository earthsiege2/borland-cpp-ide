//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\bitmapga.cpp
//   Implementation of class TBitmapGadget
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\bitmapga.h>
#include <owl\gadgetwi.h>
#include <owl\celarray.h>

TBitmapGadget::TBitmapGadget(TResId bmpResId,
                             int id,
                             TBorderStyle borderStyle,
                             int numImages, int startImage)
  : TGadget(id,borderStyle),
    ResId(bmpResId),
    NumImages(numImages)
{
  ImageArray = 0;
  CurrentImage = startImage;
  BitmapOrigin.x = BitmapOrigin.y = 0;
}

TBitmapGadget::~TBitmapGadget()
{
  delete ImageArray;
}

//
// Handle a system color change by cleaning up & reloading & processing the
// bitmap. Can also be called to create the initial bitmap.
//
void
TBitmapGadget::SysColorChange()
{
  if (ImageArray)
    delete ImageArray;
  
  TDib dib(*Window->GetModule(), ResId);
  dib.MapUIColors(
    TDib::MapFace | TDib::MapText | TDib::MapShadow | TDib::MapHighlight
  );
  ImageArray = new TCelArray(dib, NumImages);
}

void
TBitmapGadget::SetBounds(TRect& boundRect)
{
  TGadget::SetBounds(boundRect);
  TRect  innerRect;
  TSize  bitmapSize = ImageArray->CelSize();
  GetInnerRect(innerRect);
  
  BitmapOrigin.x = innerRect.left + (innerRect.Width()-bitmapSize.cx)/2;
  BitmapOrigin.y = innerRect.top + (innerRect.Height()-bitmapSize.cy)/2;
}

void
TBitmapGadget::GetDesiredSize(TSize& size)
{
  TGadget::GetDesiredSize(size);

  if (!ImageArray)
    SysColorChange();   // Get the initial bitmap

  size += ImageArray->CelSize();
}

int
TBitmapGadget::SelectImage(int imageNum, BOOL immediate)
{
  UINT oldImageNum = CurrentImage;
  if (imageNum != CurrentImage) {
    CurrentImage = imageNum;
    Invalidate(FALSE);
  }
  if (immediate)
    Update();
  return oldImageNum;
}

void
TBitmapGadget::Paint(TDC& dc)
{
  PaintBorder(dc);

  TMemoryDC imageDC;
  imageDC.SelectObject(*ImageArray);

  TRect sourceRect = ImageArray->CelRect(CurrentImage);
  TRect destRect;
  GetInnerRect(destRect);
  dc.BitBlt(destRect.left, destRect.top,
            sourceRect.Width(), sourceRect.Height(),
            imageDC, sourceRect.left, sourceRect.top);
}
