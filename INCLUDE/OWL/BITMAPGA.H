//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.2  $
//
// Definition of class TBitmapGadget
//----------------------------------------------------------------------------
#if !defined(OWL_BITMAPGA_H)
#define OWL_BITMAPGA_H

#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TCelArray;

//
// class TBitmapGadget
// ~~~~~ ~~~~~~~~~~~~~
// Simple gadget that can display an array of bitmap images, one at a time.
//
class _OWLCLASS TBitmapGadget : public TGadget {
  public:
    TBitmapGadget(TResId imageResIdOrIndex,
                  int    id,
                  TBorderStyle borderStyle,
                  int    numImages,
                  int    startImage = 0,
                  bool   sharedCels = false);
   ~TBitmapGadget();

    int  SelectImage(int imageNum, bool immediate);
    int  GetImage() const;

    void SysColorChange();

  protected:
    void Paint(TDC& dc);

    void SetBounds(const TRect& boundRect);
    void GetDesiredSize(TSize& size);

  private:
    TResId     ResId;
    TCelArray* ImageArray;
    int        ImageIndex;
    int        CurrentImage;
    int        NumImages;
    TPoint     BitmapOrigin;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//
// Inline implementations
//
//
inline int TBitmapGadget::GetImage() const {
  return CurrentImage;
}

#endif  // OWL_BITMAPGA_H
