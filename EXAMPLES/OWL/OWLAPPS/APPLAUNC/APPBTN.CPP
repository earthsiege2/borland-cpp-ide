//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\gdiobjec.h>
#include <owl\dc.h>
#include "appbtn.h"
#include "applaunc.rh"

int TAppButton::ButtonPixelSize = 32;

//
// Constructor.  Construct from a bitmap and id.
//
TAppButton::TAppButton(const TBitmap& bitmap, int id)
  : TButtonGadget(0, CM_DUMMY), RealId(id)
{
  CreateGlyph(bitmap);
}

//
// Constructor.  Construct given path to icon file and id.  An HINSTANCE
// is passed for use in extracting the icon from the given file.
//
TAppButton::TAppButton(HINSTANCE hInst, const string& iconPath, int id)
  : TButtonGadget(0, CM_DUMMY, Command, TRUE), RealId(id), Glyph(0)
{
  if (hInst)
    HInst = hInst;

  TBitmap   bitmap(TScreenDC(), TAppButton::ButtonPixelSize,
                                TAppButton::ButtonPixelSize);
  BitmapFromIconPath(iconPath, bitmap);
  CreateGlyph(bitmap);
}

//
// Destructor.  Delete the glyph that was created in ctor.
//
TAppButton::~TAppButton()
{
  delete Glyph;
}

//
// GetGlyphDib().  OWL calls this virtual to get the bitmap to be drawn on
// the button.
//
TDib*
TAppButton::GetGlyphDib()
{
  return Glyph;
}

//
// ReleaseGlyphDib().  Called by OWL to delete the dib returned by
// GetGlyphDib().  Since the dib is created in the constructor it
// is not deleted here.
//
void
TAppButton::ReleaseGlyphDib(TDib*)
{
}

//
// CreateGlyph().  Create and return a dib, created from given bitmap.
//
void
TAppButton::CreateGlyph(const TBitmap& bitmap)
{
  delete Glyph;
  Glyph = new TDib(bitmap);
}

//
// BitmapFromIconPath().  Create a TBitmap from an icon, specified by
// 'iconPath'.
//
void
TAppButton::BitmapFromIconPath(const string& iconPath, TBitmap& bitmap)
{
  int freeIcon = 0;

  // extract icon from source.
  //
  HICON icon = ExtractIcon(HInst, iconPath.c_str(), 0);

  // Use question icon if icon could not be found.
  //
  if (!icon || (int)icon == 1)
    icon = LoadIcon(0, IDI_QUESTION);
  else
    freeIcon = 1;

  // create bitmap from icon to be used with button gadget.
  //
  TMemoryDC memDC;              // screen capatable DC.

  memDC.SelectObject(bitmap);   // Use given bitmap to draw into.
                                // Initialize bitmap with button-face color.
  memDC.TextRect(0, 0, TAppButton::ButtonPixelSize, TAppButton::ButtonPixelSize,
                 GetSysColor(COLOR_WINDOW));
  memDC.DrawIcon(0, 0, TIcon(icon));
  if (freeIcon)
    ::DestroyIcon(icon);
}
