//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// Definition of class TImageList, an ImageList Common Control wrapper.
//----------------------------------------------------------------------------
#if !defined(OWL_IMAGELST_H)
#define OWL_IMAGELST_H

#if !defined(OWL_GDIOBJCT_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TImageList;

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

// TImageInfo is only usable in 32-bit - It requires 
// 'ImageList_GetImageInfo' support
//
#if defined(BI_PLAT_WIN32)

//
// class TImageInfo
// ~~~~~ ~~~~~~~~~~
// Wrapper class for a structure that describes an image within
// an image list.
//
class _OWLCLASS TImageInfo {
  public:
    TImageInfo();
    TImageInfo(const TImageList& list, int index = 0);

    HBITMAP GetImageBM() const;
    HBITMAP GetMaskBM() const;
    TRect   GetImageRect() const;  

    operator _IMAGEINFO&();

  private:
    _IMAGEINFO rep;

  friend class _OWLCLASS TImageList;
};

#endif  //  BI_PLAT_WIN32


//
// class TImageList
// ~~~~~ ~~~~~~~~~~
// Wrapper class for the ImageList common "control".
//
class _OWLCLASS TImageList {
  public:
    // Constructors
    //
    TImageList(const TSize& size, uint flags, int initCount, int growBy);
    TImageList(const TBitmap& bmp, uint flags, int initCount, int growBy);
    TImageList(const TDib& dib, uint flags, int initCount, int growBy);

#if defined(BI_PLAT_WIN32)
    // 32-bit only: Requires 'ImageList_LoadImage' support
    //
    TImageList(HINSTANCE hI, TResId resName, int w, int growBy,
               const TColor& mask, uint type, uint flags);
    TImageList(const TImageList& src);
#endif

    TImageList(HIMAGELIST imageList);

#if defined(BI_PLAT_WIN32)
    // 32-bit only: Requires 'ImageList_GetDragImage' support
    //
    TImageList(TPoint& pt, TPoint& hotspot);
#endif

    /*virtual*/ ~TImageList();

#if defined(BI_PLAT_WIN32)
    TImageList& operator =(const TImageList&);
    operator TBitmap&();
#endif

    operator HIMAGELIST() const;

    // 'Get' accessors
    //
    int        GetImageCount() const;
    TSize      GetImageSize() const;
    TPoint     GetImageOffset(int cel) const;
    TRect      GetImageRect(int cel) const;
    TRect      operator [](int cel) const;

    // Add an image into the list
    //
    int        Add(const TBitmap& image);
    int        Add(const TBitmap& image, const TBitmap& mask);
#if defined(BI_PLAT_WIN32)
    int        Add(const TBitmap& image, const TColor& mask);
#endif
    int        Add(const TIcon&);

#if defined(BI_PLAT_WIN32)
    // Remove an image from the list
    // NOTE: 32-bits only - requires support of 'ImageList_Remove'
    //
    bool       Remove(int index);
    bool       RemoveAll();
#endif

#if defined(BI_PLAT_WIN32)
    // Replace the image at an index with another
    //
    bool       Replace(int index, const TBitmap& image);
    bool       Replace(int index, const TBitmap& image, const TBitmap& mask);
#endif

    // Get an icon or cursor from an image based on masks
    //
    int        ReplaceIcon(int index, HICON hicon);
#if defined(BI_PLAT_WIN32)
    HICON      GetIcon(int index, uint flags) const;
    bool       GetIconSize(int& cx, int& cy);
#endif

#if defined(BI_PLAT_WIN32)
    bool       GetImageInfo(int index, TImageInfo& celInfo) const;
#endif    

    TColor     GetBkColor() const;
    TColor     SetBkColor(const TColor& newColor);

    // Draw the image
    //
    bool       Draw(int index, TDC&, int x, int y, uint style = ILD_NORMAL,
                    int overlay = 0);

#if defined(BI_PLAT_WIN32)
    // 32-bit only: requires 'ImageList_DrawEx' support
    //
    bool       Draw(int index, TDC&, int x, int y, int dx, int dy,
                    const TColor& bgClr, const TColor& fgClr,
                    uint style = ILD_NORMAL, int overlay = 0);
#endif

    bool       SetOverlayImage(int index, int overlay);

    // Routines related to dragging
    //
#if defined(BI_PLAT_WIN32)
    bool       SetDragCursorImage(int drag, int dxHotspot, int dyHotspot);
    bool        BeginDrag(int index, int dxHotspot, int dyHotspot);
    static bool DragEnter(HWND hwndLock,  int x, int y);
    static bool DragMove(int x, int y);
    static bool DragLeave(HWND hwndLock);
    static void EndDrag();
    static bool DragShowNolock(bool show);
#endif

  protected:
    void        CheckValid();

  protected_data:
    HIMAGELIST  Handle;      // Handle of ImageList

  private:
#if !defined(BI_PLAT_WIN32)
    // Prevent accidental copy when not compiling for environment which
    // supports ability to retrieve/duplicate imagelists.
    //
    TImageList& operator =(const TImageList&);
    operator TBitmap&();
#endif

    TBitmap*    Bitmap;      // Copy of image BM to work around Win95 BUG
    TSize       ImageSize;   // Size of images in ImageList
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//------------------------------------------------------------------------
// Inline implementations

#if defined(BI_PLAT_WIN32)

//
inline TImageInfo::TImageInfo() {
}

//
// Construct based on an image within the image list.
//
inline TImageInfo::TImageInfo(const TImageList& array, int index) {
  array.GetImageInfo(index, *this);
}

//
// Get the image bitmap
//
inline HBITMAP TImageInfo::GetImageBM() const {
  return rep.hbmImage;
}

//
// Get the image's mask
//
inline HBITMAP TImageInfo::GetMaskBM() const {
  return rep.hbmImage;
}

//
// Get the area of the image
//
inline TRect TImageInfo::GetImageRect() const {
  return rep.rcImage;
}

//
// Convert to an _IMAGEINFO structure
//
inline TImageInfo::operator _IMAGEINFO&() {
  return rep;
}

#endif  //  BI_PLAT_WIN32

//
// Return the size each image.
// Each image of the list must be the same size.
//
inline TSize TImageList::GetImageSize() const {
  return ImageSize;
}

//
// Return the offset of a given image in the ImageList's bitmap
//
inline TPoint TImageList::GetImageOffset(int index) const {
  return TPoint(index*ImageSize.cx, 0);
}

//
// Return the bounding rect of a given image in the ImageList's bitmap
//
inline TRect TImageList::GetImageRect(int index) const {
  return TRect(TPoint(index*ImageSize.cx, 0), ImageSize);
}

//
// Return the rectangle of the image at index 'index'.
//
inline TRect TImageList::operator [](int index) const {
  return GetImageRect(index);
}

#if defined(BI_PLAT_WIN32)
//
// Removes all images from the list.
//
inline bool TImageList::RemoveAll() {
  return Remove(-1);
}
#endif  //  BI_PLAT_WIN32

//
// Convert to the HIMAGELIST structure.
//
inline TImageList::operator HIMAGELIST() const {
  return Handle;
}

#endif  // OWL_IMAGELST_H
