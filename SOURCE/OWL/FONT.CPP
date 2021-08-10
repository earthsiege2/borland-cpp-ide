//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\font.cpp
//   Implementation for GDI Font object
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\gdiobjec.h>

DIAG_DECLARE_GROUP(OwlGDI);          // General GDI diagnostic group
DIAG_DECLARE_GROUP(OwlGDIOrphan);    // Oprhan control tracing group

//
// Constructors
//
TFont::TFont(HFONT handle, TAutoDelete autoDelete)
  : TGdiObject(handle, autoDelete)
{
  #if !defined(NO_GDI_ORPHAN_CONTROL)
    if (ShouldDelete)
      OBJ_REF_ADD(Handle, Font);
  #endif
}

TFont::TFont(const char far* facename,
             int height, int width, int escapement, int orientation, 
             int weight,
             BYTE pitchAndFamily,
             BYTE italic, BYTE underline, BYTE strikeout, BYTE charSet,
             BYTE outputPrecision, BYTE clipPrecision, BYTE quality)
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
             BYTE italic, BYTE underline, BYTE strikeout,
             BYTE charSet,
             BYTE outputPrecision,
             BYTE clipPrecision,
             BYTE quality,
             BYTE pitchAndFamily,
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
        hex << DWORD(LPVOID(logFont)));
  CheckValid();
  OBJ_REF_ADD(Handle, Font);
}

TFont::TFont(const TFont& src)
{
  LOGFONT logFont;
  src.GetObject(logFont);
  Handle = ::CreateFontIndirect(&logFont);
  WARNX(OwlGDI, !Handle, 0, "Cannot create TFont from TFont @" << 
        hex << DWORD(LPVOID(&src)));
  CheckValid();
  OBJ_REF_ADD(Handle, Font);
}
