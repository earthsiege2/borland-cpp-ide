//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TBitmapGadget
//----------------------------------------------------------------------------
#if !defined(OWL_BITMAPGA_H)
#define OWL_BITMAPGA_H

#if !defined(OWL_GADGET_H)
# include <owl/gadget.h>
#endif
class _OWLCLASS TCelArray;

//
//  class TBitmapGadget
//  ----- -------------
//
//  simple gadget that can display an array of bitmap images, one at a time.
//
class _OWLCLASS TBitmapGadget : public TGadget {
  public:
    TBitmapGadget(TResId bmpResId,
                  int id,
                  TBorderStyle borderStyle,
                  int numImages, 
                  int startImage);
   ~TBitmapGadget();
    
    int  SelectImage(int imageNum, bool immediate);
    int  GetImage() const {return CurrentImage;}

    void SysColorChange();

  protected:
    void Paint(TDC& dc);
    
    void SetBounds(TRect& boundRect);
    void GetDesiredSize(TSize& size);
    
  private:
    TResId     ResId;
    TCelArray* ImageArray;
    int        CurrentImage;
    int        NumImages;
    TPoint     BitmapOrigin;
};

#endif  // OWL_BITMAPGA_H
