//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.11  $
//
// Implementation of class TImageList, an ImageList 'common control' wrapper
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_IMAGELST_H)
# include <owl/imagelst.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlCommCtrl);    // Common Controls diagnostic group

//
// Construct an empty ImageList of a given size
//
TImageList::TImageList(const TSize& size, uint flags, int initCount, int growBy)
{
  if (!TCommCtrl::IsAvailable())
    TXCommCtrl::Raise();

//  if (!(flags & ILC_COLOR))
//    flags |= ILC_COLORDDB;

  if (!initCount)
    initCount = 1;

  ImageSize = TSize(size.cx/initCount, size.cy);
  Bitmap = 0;
  Handle = TCommCtrl::Dll()->ImageList_Create(size.cx, size.cy, flags, initCount, growBy);

  CheckValid();
  WARNX(OwlCommCtrl, !Handle, 0, "Cannot create ImageList");
}

//
// Construct a TImageList from a bitmap, slicing a portion of the bitmap up
// into a horizontal array of specified sized images.
//
TImageList::TImageList(const TBitmap& bmp, uint flags, int initCount, int growBy)
{
  if (!TCommCtrl::IsAvailable())
    TXCommCtrl::Raise();

  if (!initCount)
    initCount = 1;

  ImageSize = TSize(bmp.Width() / initCount, bmp.Height());
  Bitmap = 0;

//  if (!(flags & 0xFE))
//    flags |= ILC_COLORDDB;         // default color type?
//  flags |= ILC_MASK;

  Handle = TCommCtrl::Dll()->ImageList_Create(ImageSize.cx, ImageSize.cy,
                                       flags, initCount, growBy);

  CheckValid();
  WARNX(OwlCommCtrl, !Handle, 0, "Cannot create ImageList");

#if   defined(BI_PLAT_WIN32)
  // Use masked support with 3dFace color as background color
  //
  Add(bmp, TColor::Sys3dFace);  
#elif defined(BI_PLAT_WIN16)
  // With no mask support, simply add the bitmap
  //
  Add(bmp);
#endif  
}

//
// Construct a TImageList from a dib, slicing the dib up into a horizontal array
// of even sized images
//
TImageList::TImageList(const TDib& dib, uint flags, int initCount, int growBy)
{
  if (!TCommCtrl::IsAvailable())
    TXCommCtrl::Raise();

  if (!initCount)
    initCount = 1;

  ImageSize = TSize(dib.Width() / initCount, dib.Height());
  Bitmap = 0;

//  if (!(flags & 0xFE))
//    flags |= ILC_COLORDDB;         // default color type?
//  flags |= ILC_MASK;

  Handle = TCommCtrl::Dll()->ImageList_Create(ImageSize.cx, ImageSize.cy,
                                       flags, initCount, growBy);

#if   defined(BI_PLAT_WIN32)
  // Use masked support with 3dFace color as background color
  //
  Add(TBitmap(dib, &TPalette((HPALETTE)::GetStockObject(DEFAULT_PALETTE))),
      TColor::Sys3dFace);
#elif defined(BI_PLAT_WIN16)
  // With no mask support, simply add the bitmap
  //
  Add(TBitmap(dib, &TPalette((HPALETTE)::GetStockObject(DEFAULT_PALETTE))));
#endif
}

#if defined(BI_PLAT_WIN32)

//
// Construct a ImageList right from a bmp, icon or cursor resource in a file.
// 'type' should be one of the consts from winuser.h:
//   IMAGE_BITMAP
//   IMAGE_ICON
//   IMAGE_CURSOR
//   IMAGE_ENHMETAFILE ?
//
TImageList::TImageList(HINSTANCE hI, TResId resName, int w, int growBy,
                       const TColor& mask, uint type, uint flags)
{
  if (!TCommCtrl::IsAvailable())
    TXCommCtrl::Raise();

  ImageSize = TSize(0); 
  Bitmap = 0;
  Handle = TCommCtrl::Dll()->ImageList_LoadImage(hI, resName, w, growBy, mask, type, flags);

  CheckValid();
  WARNX(OwlCommCtrl, !Handle, 0, "Cannot create ImageList");
}


//
// Construct a TImageList as a copy of an existing one.
//
TImageList::TImageList(const TImageList& src)
{
  if (!TCommCtrl::IsAvailable())
    TXCommCtrl::Raise();

  TImageInfo ii(src);

  // Initialize members using ii
  //
  ImageSize = ii.GetImageRect().Size();
  Bitmap = 0;
  Handle = TCommCtrl::Dll()->ImageList_Create(ImageSize.cx, ImageSize.cy, ILC_COLORDDB,
                                       src.GetImageCount(), 10);

  CheckValid();
  WARNX(OwlCommCtrl, !Handle, 0, "Cannot create ImageList");

  TCommCtrl::Dll()->ImageList_Add(Handle, ii.GetImageBM(), ii.GetMaskBM());
}

#endif  //  BI_PLAT_WIN32

//
// Construct a C++ alias for an existing imagelist
//
TImageList::TImageList(HIMAGELIST imageList)
{
  if (!TCommCtrl::IsAvailable())
    TXCommCtrl::Raise();

  Handle = imageList;
  Bitmap = 0;
  int cx = 0;
  int cy = 0;

#if defined(BI_PLAT_WIN32)
  TCommCtrl::Dll()->ImageList_GetIconSize(Handle, &cx, &cy);
#endif

  ImageSize.cx = cx;
  ImageSize.cy = cy;

  CheckValid();
  WARNX(OwlCommCtrl, !Handle, 0, "Cannot create ImageList");
}

#if defined(BI_PLAT_WIN32)
//
// Constructs a wrapper for the current drag imagelist and
// specifies the location and hotspot of the imagelist.
//
TImageList::TImageList(TPoint& pt, TPoint& hotspot)
{
  ImageSize = TSize(0); 
  Bitmap = 0;
  Handle = TCommCtrl::Dll()->ImageList_GetDragImage(&pt, &hotspot);

  CheckValid();
  WARNX(OwlCommCtrl, !Handle, 0, "Cannot create ImageList");
}
#endif  //  BI_PLAT_WIN32

//
// Destruct the ImageList and clean up the image list handle.
//
TImageList::~TImageList()
{
  TCommCtrl::Dll()->ImageList_Destroy(Handle);
  delete Bitmap;
}

//
// Throw an exception if this image list handle is invalid
//
void
TImageList::CheckValid()
{
  if (!Handle)
    TXCommCtrl::Raise();
}


#if defined(BI_PLAT_WIN32)

//
// Assign a ImageList over this ImageList, replacing all contents
//
TImageList&
TImageList::operator =(const TImageList& src)
{
  TCommCtrl::Dll()->ImageList_Remove(Handle, -1);  // -1 is to remove all

  TImageInfo ii(src);
  TCommCtrl::Dll()->ImageList_Add(Handle, ii.GetImageBM(), ii.GetMaskBM());

  return *this;
}

//
// Return the image bitmap used by this ImageList
//
TImageList::operator TBitmap&()
{
  // Build the bitmap object on the fly if needed
  //
  TImageInfo ii(*this);
  if (!Bitmap || (HBITMAP)*Bitmap != ii.GetImageBM()) {
    delete Bitmap;
    Bitmap = new TBitmap(TScreenDC(), TDib(TBitmap(ii.GetImageBM())));
  }

  return *Bitmap;
}

#endif  //  BI_PLAT_WIN32


//
// Draw an image onto a target DC at a given coordinate & with a given style
//
bool
TImageList::Draw(int index, TDC& dc, int x, int y, uint style, int overlay)
{
  if (overlay)
    style |= ILD_OVERLAYMASK | INDEXTOOVERLAYMASK(overlay);
  return TCommCtrl::Dll()->ImageList_Draw(Handle, index, dc, x, y, style);
}

#if defined(BI_PLAT_WIN32)

//
// Extended version of draw that takes a foreground color and background color
//
bool
TImageList::Draw(int index, TDC& dc, int x, int y, int dx, int dy,
                 const TColor& bgClr, const TColor& fgClr, uint style,
                 int overlay)
{
  if (overlay)
    style |= ILD_OVERLAYMASK | INDEXTOOVERLAYMASK(overlay);
  COLORREF bgCr = (bgClr == TColor::None) ? (COLORREF)CLR_NONE : (COLORREF)bgClr;
  COLORREF fgCr = (fgClr == TColor::None) ? (COLORREF)CLR_NONE : (COLORREF)fgClr;

  return TCommCtrl::Dll()->ImageList_DrawEx(Handle, index, dc, x, y, dx, dy, bgCr, fgCr, style);
}
#endif  //  BI_PLAT_WIN32

//
// Return number of images currently in this ImageList
//
int
TImageList::GetImageCount() const
{
  return TCommCtrl::Dll()->ImageList_GetImageCount(Handle);
}

//
// Add new image(s) to the ImageList - return index of new addition.
// No mask bitmap is added.
//
int
TImageList::Add(const TBitmap& image)
{
  return TCommCtrl::Dll()->ImageList_Add(Handle, image, 0);
}


//
// Add new image/mask pair(s) to the ImageList - return index of new
// addition.
//
int
TImageList::Add(const TBitmap& image, const TBitmap& mask)
{
  return TCommCtrl::Dll()->ImageList_Add(Handle, image, mask);
}

#if defined(BI_PLAT_WIN32)

//
// Add new image(s) to ImageList, specifying a mask color to generate a mask.
// return index of the new addition.
//
int
TImageList::Add(const TBitmap& image, const TColor& mskColor)
{
  return TCommCtrl::Dll()->ImageList_AddMasked(Handle, image, mskColor);
}
#endif  //  BI_PLAT_WIN32

//
// Add an icon to the ImageList - return index of new addition.
//
int
TImageList::Add(const TIcon& icon)
{
  return TCommCtrl::Dll()->ImageList_AddIcon(Handle, icon);
}

#if defined(BI_PLAT_WIN32)
//
// Remove an image (or all images if index is -1) from this ImageList.
//
bool
TImageList::Remove(int index)
{
  return TCommCtrl::Dll()->ImageList_Remove(Handle, index);
}

//
// Replace an image in this ImageList.
//
bool
TImageList::Replace(int index, const TBitmap& image)
{
  return TCommCtrl::Dll()->ImageList_Replace(Handle, index, image, 0);
}

//
// Replace an image and mask in the ImageList.
//
bool
TImageList::Replace(int index, const TBitmap& image, const TBitmap& mask)
{
  return TCommCtrl::Dll()->ImageList_Replace(Handle, index, image, mask);
}

//
// Create and retreive an icon from an image and mask in the ImageList.
//
HICON
TImageList::GetIcon(int index, uint flags) const
{
  return TCommCtrl::Dll()->ImageList_GetIcon(Handle, index, flags);
}
#endif  //  BI_PLAT_WIN32

//
// Replaces the image at index 'index' with the icon or cursor.
//
int
TImageList::ReplaceIcon(int index, HICON icon)
{
  return TCommCtrl::Dll()->ImageList_ReplaceIcon(Handle, index, icon);
}

#if defined(BI_PLAT_WIN32)
//
// Return the icon size
//
bool
TImageList::GetIconSize(int& cx, int& cy)
{
  return TCommCtrl::Dll()->ImageList_GetIconSize(Handle, &cx, &cy);
}

//
// Get general information about a given image
//
bool
TImageList::GetImageInfo(int index, TImageInfo& imageInfo) const
{
  return TCommCtrl::Dll()->ImageList_GetImageInfo(Handle, index, &(IMAGEINFO)imageInfo);
}
#endif  //  BI_PLAT_WIN32

//
// Get the current background color for this ImageList
//
TColor
TImageList::GetBkColor() const
{
  return TCommCtrl::Dll()->ImageList_GetBkColor(Handle);
}

//
// Set the current background color for this ImageList, returning the previous
// color.
//
TColor
TImageList::SetBkColor(const TColor& color)
{
  return TCommCtrl::Dll()->ImageList_SetBkColor(Handle, color);
}

//
// Select an image for use as an overlay. Up to four can be selected.
//
bool
TImageList::SetOverlayImage(int index, int overlay)
{
  return TCommCtrl::Dll()->ImageList_SetOverlayImage(Handle, index, overlay);
}

#if defined(BI_PLAT_WIN32)

//
// Combine the current drag image with another image in the list.
// Typically a mouse cursor would be added to the image list and merged
// with the drag image list.
//
bool
TImageList::SetDragCursorImage(int drag, int dxHotspot, int dyHotspot)
{
  return TCommCtrl::Dll()->ImageList_SetDragCursorImage(Handle, drag, dxHotspot, dyHotspot);
}

//
// BeginDrag sets this imagelist to be the drag imagelist.
// There can only be one drag imagelist at any time.
//
bool
TImageList::BeginDrag(int index, int dxHotspot, int dyHotspot)
{
  return TCommCtrl::Dll()->ImageList_BeginDrag(Handle, index, dxHotspot, dyHotspot);
}

//
// Typically, this function is called in response to a WM_LBUTTONDOWN message.
// The 'x' and 'y' parameters are relative to the upper-left corner of the
// window's rectangle and NOT the client area.
// The window 'hWndLock' is locked from further updates.
//
bool
TImageList::DragEnter(HWND hWndLock, int x, int y)
{
  return TCommCtrl::Dll()->ImageList_DragEnter(hWndLock, x, y);
}

//
// DragMove is typically called when receiving a WM_MOUSEMOVE message.
// The 'x' and 'y' parameters are generally passed from the message to this
// function.
//
bool
TImageList::DragMove(int x, int y)
{
  return TCommCtrl::Dll()->ImageList_DragMove(x, y);
}

//
// DragLeave is typically called when receiving a WM_LBUTTONUP message.
// The 'hWndLock' window is unlocked from updates.
//
bool
TImageList::DragLeave(HWND hWndLock)
{
  return TCommCtrl::Dll()->ImageList_DragLeave(hWndLock);
}

//
// EndDrag removes the current drag imagelist from the system.
//
void
TImageList::EndDrag()
{
  TCommCtrl::Dll()->ImageList_EndDrag();
}

//
// Lock or unlocks the window from updates.
//
bool
TImageList::DragShowNolock(bool show)
{
  return TCommCtrl::Dll()->ImageList_DragShowNolock(show);
}

#endif
