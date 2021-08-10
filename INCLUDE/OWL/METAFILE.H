//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of a MetaFile wrapper class
//----------------------------------------------------------------------------
#if !defined(OWL_METAFILE_H)
#define OWL_METAFILE_H

#if !defined(OWL_GDIBASE_H)
# include <owl/gdibase.h>
#endif
class _OWLCLASS TClipboard;
class _OWLCLASS TDC;

//
// class TMetafilePict
// ----- -------------
//
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

    operator    HMETAFILE() const {return HMETAFILE(Handle);}

#if defined(BI_PLAT_WIN32)
    uint32      GetMetaFileBitsEx(uint size, void* data);
#else
    HANDLE      GetMetaFileBits() {return ::GetMetaFileBits(HMETAFILE(Handle));}
#endif

    // Play this metafile onto a dc
    TSize     CalcPlaySize(TDC& dc, const TSize& defSize) const;
    bool      PlayOnto(TDC& dc, const TSize& defSize) const;

    // Put this MetaFilePict onto the clipboard
    void      ToClipboard(TClipboard& clipboard, 
                          unsigned mapMode = MM_ANISOTROPIC,
                          const TSize& extent=TSize(0,0));

    // Retrieve attributes of this metafile
    unsigned  MappingMode() const {return Mm;}
    int       Width() const {return Extent.cx;}
    int       Height() const {return Extent.cy;}
    TSize     Size() const {return Extent;}
    
    // Set attributes of this metafile
    void      SetMappingMode(unsigned mm) {Mm = mm;}
    void      SetSize(const TSize& size) {Extent = size;}
    
  protected:
    int    Mm;        // Mapping mode
    TSize  Extent;

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TMetaFilePict& operator=(const TMetaFilePict&);
};

//----------------------------------------------------------------------------
// Inlines
//----------------------------------------------------------------------------

inline TClipboard& operator <<(TClipboard& clipboard, TMetaFilePict& mfp)
      {mfp.ToClipboard(clipboard); return clipboard;}

#endif  // OWL_METAFILE_H
