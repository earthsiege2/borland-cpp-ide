//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation for GDI Font object
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/gdiobjec.h>

DIAG_DECLARE_GROUP(OwlGDI);          // General GDI diagnostic group
DIAG_DECLARE_GROUP(OwlGDIOrphan);    // Oprhan control tracing group

//
// Constructors
//
TFont::TFont(HFONT handle, TAutoDelete autoDelete)
:
  TGdiObject(handle, autoDelete)
{
#if !defined(NO_GDI_ORPHAN_CONTROL)
  if (ShouldDelete)
    OBJ_REF_ADD(Handle, Font);
#endif
}

TFont::TFont(const char far* facename,
             int height, int width, int escapement, int orientation, 
             int weight,
             uint8 pitchAndFamily,
             uint8 italic, uint8 underline, uint8 strikeout, uint8 charSet,
             uint8 outputPrecision, uint8 clipPrecision, uint8 quality)
{
  Handle = ::CreateFont(height, width, escapement, orientation, weight,
                        italic, underline, strikeout, charSet,
                        outputPrecision, clipPrecision, quality,
                        pitchAndFamily, facename);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TFont (" << TResId(facename) << 
        " " << height << "pt)");
  CheckValid();
  OBJ_REF_ADD(Handle, Font);
}

TFont::TFont(int height, int width, int escapement, int orientation,
             int weight,
             uint8 italic, uint8 underline, uint8 strikeout,
             uint8 charSet,
             uint8 outputPrecision,
             uint8 clipPrecision,
             uint8 quality,
             uint8 pitchAndFamily,
             const char far* facename)
{
  Handle = ::CreateFont(height, width, escapement, orientation, weight,
                        italic, underline, strikeout, charSet,
                        outputPrecision, clipPrecision, quality,
                        pitchAndFamily, facename);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TFont (" << TResId(facename) << 
        " " << height << "pt)");
  CheckValid();
  OBJ_REF_ADD(Handle, Font);
}

TFont::TFont(const LOGFONT far* logFont)
{
  PRECONDITION(logFont);
  Handle = ::CreateFontIndirect((LPLOGFONT)logFont);  // API typecast
  WARNX(OwlGDI, !Handle, 0, "Cannot create TFont from logfont @" << 
        hex << uint32(LPVOID(logFont)));
  CheckValid();
  OBJ_REF_ADD(Handle, Font);
}

TFont::TFont(const TFont& src)
{
  LOGFONT logFont;
  src.GetObject(logFont);
  Handle = ::CreateFontIndirect(&logFont);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TFont from TFont @" << 
        hex << uint32(LPVOID(&src)));
  CheckValid();
  OBJ_REF_ADD(Handle, Font);
}
