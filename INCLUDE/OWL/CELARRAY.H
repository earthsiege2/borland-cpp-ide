//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of a bitmap Cel array class.
//----------------------------------------------------------------------------
#if !defined(OWL_CELARRAY_H)
#define OWL_CELARRAY_H

#if !defined(OWL_GDIOBJCT_H)
# include <owl/gdiobjec.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TCelArray
// ~~~~~ ~~~~~~~~~
class _OWLCLASS TCelArray {
  public:
    // Constructors
    //
    TCelArray(TBitmap* bmp, int numCels, TSize celSize = 0,
              TPoint offset = 0, TAutoDelete = AutoDelete);
    TCelArray(const TDib& dib, int numCels);
    TCelArray(const TCelArray& src);
    TCelArray(const TSize& size, uint flags, int init, int grow);

    virtual   ~TCelArray();

    TCelArray& operator =(const TCelArray&);
    operator   TBitmap&();

    // 'Get' accessors
    //
    TPoint     Offset() const;
    int        NumCels() const;
    TSize      CelSize() const;
    TPoint     CelOffset(int cel) const;
    TRect      CelRect(int cel) const;
    TRect      operator [](int cel) const;

    // 'Set' accessors
    //
    void       SetNumCels(int numCels);
    void       SetCelSize(TSize size);
    void       SetOffset(TPoint offs);
    void       SetNGrowBy(int growBy);

    // Manipulating cel images
    //
    int        Add(const TBitmap& image);
    int        Add(const TCelArray& src, int index);

    bool       Remove(int index = -1);
    bool       RemoveAll();
    bool       Replace(int index, const TBitmap& image);
    TColor     GetBkColor() const;
    TColor     SetBkColor(const TColor&);

    bool       BitBlt(int index, TDC& dc, int x, int y);
    bool       BitBlt(int index, TDC&, int x, int y, int dx, int dy,
                      const TColor& bgClr, const TColor& fgClr);

  protected_data:
    TBitmap*    Bitmap;         // Main Cel bitmap
    bool        ShouldDelete;   // Does this CelArray own the Bitmap?
    TPoint      Offs;           // Offset within Bitmap of actual CelArray
    int         NCels;          // Number of cels allocated in Bitmap
    TSize       CSize;          // Size of one cel
    int         NGrowBy;        // How much to grow the array by when full
    TColor      BkColor;        // Background color used when image < cellsize
    int         NCelsUsed;      // Numbers of cels currently in use

  private:
    bool        MaybeResize(int need);
    bool        Resize(int newCount);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//------------------------------------------------------------------------
// Inline implementations
//

//
// Return the offset within the bitmap for the celarray.
//
inline TPoint TCelArray::Offset() const {
  return Offs;
}

//
// Return the size of the celarray.
//
inline TSize TCelArray::CelSize() const {
  return CSize;
}

//
// Return number of cels currently in this CelArray
//
inline int TCelArray::NumCels() const {
  return NCelsUsed;
}

//
// Retrieve the 'cel'th image from the celarray.
//
inline TRect TCelArray::operator [](int cel) const {
  return CelRect(cel);
}

//
// Set the number of cels within the celarary.
//
inline void TCelArray::SetNumCels(int numCels) {
  NCels = numCels < 1 ? 1 : numCels;
}

//
// Set the size of each cel.
// They are all assumed to be the same.
//
inline void TCelArray::SetCelSize(TSize size) {
  CSize = size;
}

//
// Set the increment by which the bitmap is resized
//
inline void TCelArray::SetNGrowBy(int growBy) {
  NGrowBy = growBy;
}

//
// Set the offset within a bitmap for the start of the celarray.
//
inline void TCelArray::SetOffset(TPoint offs) {
  Offs = offs;
}

//
// Remove all the cels from the array.
//
inline bool TCelArray::RemoveAll() {
  return Remove(-1);
}

//
// Return the image bitmap used by this CelArray
//
//inline TCelArray::operator const TBitmap&() const  {
//  return *Bitmap;
//}

//
// Return the image bitmap used by this CelArray
//
inline TCelArray::operator TBitmap&() {
  return *Bitmap;
}

#if !defined(OWL_NATIVECTRL_NEVER)
//
//inline TCelArray::operator HIMAGELIST() const {
//  return ;
//}
#endif

//
// Get the current background color for this CelArray
//
inline TColor TCelArray::GetBkColor() const {
  return BkColor;
}

//
// Set the current background color for this CelArray, returning the previous
// color.
//
inline TColor TCelArray::SetBkColor(const TColor& color) {
  TColor obkColor = BkColor;
  BkColor = color;
  return obkColor;
}

#endif  // OWL_CELARRAY_H
