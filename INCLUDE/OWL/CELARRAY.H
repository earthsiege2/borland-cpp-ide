//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of a bitmap Cel array class.
//----------------------------------------------------------------------------
#if !defined(OWL_CELARRAY_H)
#define OWL_CELARRAY_H

#if !defined(OWL_GDIOBJCT_H)
# include <owl/gdiobjec.h>
#endif


class _OWLCLASS TCelArray {
  public:
    // Constructors
    TCelArray(TBitmap* bmp, int numCels, TSize celSize = 0,
              TPoint offset = 0, TAutoDelete = AutoDelete);
    TCelArray(TDib& dib, int numCels);
    TCelArray(const TCelArray& src);

    virtual   ~TCelArray();

    TCelArray& operator =(const TCelArray&);
    operator   TBitmap&() {return *Bitmap;}

    TPoint     Offset() const {return Offs;}

    int        NumCels() const {return NCels;}
    TSize      CelSize() const {return CSize;}
    TPoint     CelOffset(int cel) const;
    TRect      CelRect(int cel) const;
    TRect      operator [](int cel) const {return CelRect(cel);}

    void       SetNumCels(int numCels) {NCels = numCels < 1 ? 1 : numCels;}
    void       SetCelSize(TSize size) {CSize = size;}
    void       SetOffset(TPoint offs) {Offs = offs;}

  protected:
    TBitmap*  Bitmap;
    bool      ShouldDelete;

    TPoint    Offs;
    int       NCels;
    TSize     CSize;

  private:
};

#endif  // OWL_CELARRAY_H
