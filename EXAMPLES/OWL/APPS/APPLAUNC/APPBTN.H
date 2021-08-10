//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#if !defined(__APPBTN_H)
#define __APPBTN_H

#if !defined(__OWL_BUTTONGA_H)
#  include <owl\buttonga.h>
#endif
class _OWLCLASS TDib;
class _OWLCLASS TBitmap;

//
// class TAppButton.  Derived from TButtonGadget.  The only difference
// between this class and its derived class is in the handling of the
// button id.  Every button has an id of CM_DUMMY, which is a place holder
// for the frame's response table.  This class defines a new data member
// called 'RealId' which is different for each button.  The 'ReadId' is
// used by the frame window to determine which button has been pressed.
//
class TAppButton : public TButtonGadget {
  public:
    int         RealId;                   // id of button.
    static int  ButtonPixelSize;          // size of button.

    TAppButton(const TBitmap& bitmap, int id);
    TAppButton(HINSTANCE hInst, const string& iconPath, int id);
    ~TAppButton();

  protected:
    TDib*     GetGlyphDib();              // Dib to draw on button face.
    HINSTANCE HInst;                      // cached to use in member functions.

    void  ReleaseGlyphDib(TDib* glyph);
    void  CreateGlyph(const TBitmap& bitmap);
    void  BitmapFromIconPath(const string& iconPath, TBitmap& bitmap);

  private:
    TDib*   Glyph;
};

#endif // __APPBTN_H

