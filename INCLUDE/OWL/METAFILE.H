//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of TMetafilePict, a MetaFile wrapper class
//----------------------------------------------------------------------------
#if !defined(OWL_METAFILE_H)
#define OWL_METAFILE_H

#if !defined(OWL_GDIBASE_H)
# include <owl/gdibase.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TClipboard;
class _OWLCLASS TDC;

//
// class TMetafilePict
// ~~~~~ ~~~~~~~~~~~~~
// A class that wraps a windows metafile that can be played into a DC, or
// put on the clipboard, etc.
//
class _OWLCLASS TMetaFilePict : private TGdiBase {
  public:
    TMetaFilePict(HMETAFILE handle, TAutoDelete autoDelete);
    TMetaFilePict(const TClipboard& clipboard);
    TMetaFilePict(const char* filename);
#if defined(BI_PLAT_WIN32)
    TMetaFilePict(uint size, void far* data);
#else
    TMetaFilePict(HGLOBAL data);
#endif
    TMetaFilePict(const TMetaFilePict&, const char far* fileName = 0);
   ~TMetaFilePict();

    operator    HMETAFILE() const;

#if defined(BI_PLAT_WIN32)
    uint32      GetMetaFileBitsEx(uint size, void* data);
#else
    HANDLE      GetMetaFileBits();
#endif

    // Play this metafile onto a dc
    //
    TSize     CalcPlaySize(TDC& dc, const TSize& defSize) const;
    bool      PlayOnto(TDC& dc, const TSize& defSize) const;

    // Put this MetaFilePict onto the clipboard
    //
    void      ToClipboard(TClipboard& clipboard,
                          uint mapMode = MM_ANISOTROPIC,
                          const TSize& extent=TSize(0,0));

    // Retrieve attributes of this metafile
    //
    uint      MappingMode() const;
    int       Width() const;
    int       Height() const;
    TSize     Size() const;

    // Set attributes of this metafile
    //
    void      SetMappingMode(uint mm);
    void      SetSize(const TSize& size);

  protected_data:
    int    Mm;        // Mapping mode
    TSize  Extent;

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TMetaFilePict& operator=(const TMetaFilePict&);
};

#if defined(BI_PLAT_WIN32)
//
// class TEnhMetaFilePict
// ~~~~~ ~~~~~~~~~~~~~~~~
// A class that encapsulates the enhanced metafile.
//
class _OWLCLASS TEnhMetaFilePict : private TGdiBase {
  public:
    TEnhMetaFilePict(HENHMETAFILE handle, TAutoDelete autoDelete);
    TEnhMetaFilePict(const char* filename);
    TEnhMetaFilePict(const TEnhMetaFilePict& metafilepict, const char far* filename);
    TEnhMetaFilePict(uint bytes, const void* buffer);
   ~TEnhMetaFilePict();

    operator HENHMETAFILE() const;

    // Play this metafile onto a dc
    //
    bool PlayOnto(TDC& dc, const TRect* rect) const;

    // Retrieve attributes of this metafile
    //
    uint GetBits(uint bytes, void* buffer);
    uint GetDescription(uint bytes, void* buffer);
    uint GetHeader(uint bytes, ENHMETAHEADER* record);
    uint GetPaletteEntries(uint count, PALETTEENTRY* entries);

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TEnhMetaFilePict& operator=(const TEnhMetaFilePict&);
};
#endif

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>


//----------------------------------------------------------------------------
// Inline implementations
//

//
// Inserts the metafile picture onto the clipboard.
//
inline TClipboard& operator <<(TClipboard& clipboard, TMetaFilePict& mfp) {
  mfp.ToClipboard(clipboard);
  return clipboard;
}

//
// Return the associated handle for the metafile object.
//
inline TMetaFilePict::operator HMETAFILE() const {
  return HMETAFILE(Handle);
}

#if !defined(BI_PLAT_WIN32)
//
// Retrieve the bits for the metafile.
//
inline HANDLE TMetaFilePict::GetMetaFileBits() {
  return ::GetMetaFileBits(HMETAFILE(Handle));
}
#endif

//
// Return the mapping mode of the metafile.
//
inline uint TMetaFilePict::MappingMode() const {
  return Mm;
}

//
// Return the width of the metafile.
//
inline int TMetaFilePict::Width() const {
  return Extent.cx;
}

//
// Return the height of the metafile.
//
inline int TMetaFilePict::Height() const {
  return Extent.cy;
}

//
// Return the size of the metafile.
//
inline TSize TMetaFilePict::Size() const {
  return Extent;
}

//
// Set the mapping mode for the metafile.
//
inline void TMetaFilePict::SetMappingMode(uint mm) {
  Mm = mm;
}

//
// Set the size of the metafile.
//
inline void TMetaFilePict::SetSize(const TSize& size) {
  Extent = size;
}

#if defined(BI_PLAT_WIN32)
//
// Return the associated handle of the enhanced metafile.
//
inline TEnhMetaFilePict::operator HENHMETAFILE() const {
  return HENHMETAFILE(Handle);
}

//
// Return the bits of the metafile.
//
inline uint TEnhMetaFilePict::GetBits(uint bytes, void* buffer) {
  return ::GetEnhMetaFileBits(*this, bytes, (BYTE*)buffer);
}

//
// Retrieve the description of this enhanced metafile.
//
inline uint TEnhMetaFilePict::GetDescription(uint bytes, void* buffer) {
  return ::GetEnhMetaFileDescription(*this, bytes, (LPTSTR)buffer);
}

//
// Retrieve the header information for the enhanced metafile.
//
inline uint TEnhMetaFilePict::GetHeader(uint bytes, ENHMETAHEADER* record) {
  return ::GetEnhMetaFileHeader(*this, bytes, record);
}

//
// Retrieve the palette entries of the enhanced metafile.
//
inline uint TEnhMetaFilePict::GetPaletteEntries(uint count, PALETTEENTRY* entries) {
  return ::GetEnhMetaFilePaletteEntries(*this, count, entries);
}

#endif  // BI_PLAT_WIN32

#endif  // OWL_METAFILE_H
