//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implementation of a bitmap Cel array class.
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/celarray.h>

//
// Construct a TCelArray from a bitmap, slicing a portion of the bitmap up
// into a horizontal array of specified sized cels.
// The CelArray can own (& delete) the bitmap or not, determined by autoDelete
//
TCelArray::TCelArray(TBitmap* bmp, int numCels, TSize celSize,
                     TPoint offset, TAutoDelete autoDelete)
{
  PRECONDITION(bmp);
  Bitmap = bmp;
  ShouldDelete = ToBool(autoDelete == AutoDelete);
  
  NCels = numCels < 1 ? 1 : numCels;
  CSize = celSize.cx && celSize.cy ?
            celSize :
            TSize(bmp->Width() / NCels, bmp->Height());
  Offs = offset;
}

//
// Construct a TCelArray from a dib, slicing the dib up into a horizontal
// array of even sized cels
//
TCelArray::TCelArray(TDib& dib, int numCels)
{
  Bitmap = new TBitmap(dib, &TPalette((HPALETTE)::GetStockObject(DEFAULT_PALETTE)));
  ShouldDelete = true;

  NCels = numCels < 1 ? 1 : numCels;
  CSize = TSize(dib.Width() / NCels, dib.Height());
  Offs = 0;
}

//
// Construct a TCelArray as a copy of an existing one. Copy Bitmap iff
// original owned its Bitmap, else just keep a ref to it also.
//
TCelArray::TCelArray(const TCelArray& src)
{
  ShouldDelete = src.ShouldDelete;
  Bitmap = ShouldDelete ? new TBitmap(*src.Bitmap) : src.Bitmap;
  
  NCels = src.NCels;
  CSize =  src.CSize;
  Offs = src.Offs;
}

TCelArray::~TCelArray()
{
  if (ShouldDelete)
    delete Bitmap;
}

TCelArray&
TCelArray::operator =(const TCelArray& src)
{
  if (ShouldDelete)
    delete Bitmap;

  ShouldDelete = src.ShouldDelete;
  Bitmap = ShouldDelete ? new TBitmap(*src.Bitmap) : src.Bitmap;
  
  NCels = src.NCels;
  CSize =  src.CSize;
  Offs = src.Offs;

  return *this;
}

TPoint
TCelArray::CelOffset(int cel) const
{
  return TPoint(Offs.x+cel*CSize.cx, Offs.y);
}

TRect
TCelArray::CelRect(int cel) const
{
  return TRect(TPoint(Offs.x+cel*CSize.cx, Offs.y), CSize);
}
