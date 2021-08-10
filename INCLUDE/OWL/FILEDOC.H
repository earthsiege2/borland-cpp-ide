//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition of class TFileDocument
//----------------------------------------------------------------------------
#if !defined(OWL_FILEDOC_H)
#define OWL_FILEDOC_H

#if !defined(OWL_DOCVIEW_H)
# include <owl/docview.h>
#endif
#if !defined(__IOSTREAM_H)
# include <iostream.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TFileDocument
// ~~~~~ ~~~~~~~~~~~~~
class _OWLCLASS TFileDocument : public TDocument {
  public:
    enum TFileDocProp {
      PrevProperty = TDocument::NextProperty-1,
      CreateTime,        // FILETIME
      ModifyTime,        // FILETIME
      AccessTime,        // FILETIME
      StorageSize,       // ulong
      FileHandle,        // platform file handle (HFILE if Windows)
      NextProperty,
    };

    TFileDocument(TDocument* parent = 0);
   ~TFileDocument();

    // Implement virtual methods of TDocument
    //
    bool        Open(int mode, const char far* path=0);
    bool        Close();
    TInStream*  InStream(int mode, const char far* strmId=0);
    TOutStream* OutStream(int mode, const char far* strmId=0);
    bool        Commit(bool force = false);
    bool        Revert(bool clear = false);
    bool        IsOpen();

    int         FindProperty(const char far* name);  // return index
    int         PropertyFlags(int index);
    const char* PropertyName(int index);
    int         PropertyCount();
    int         GetProperty(int index, void far* dest, int textlen=0);
    bool        SetProperty(int index, const void far* src);

    // Additional methods for file document
    //
    bool        Open(HFILE fhdl);     // open on existing file handle

  protected:
    HFILE OpenThisFile(int omode, const char far* name, streampos* pseekpos);
    void  CloseThisFile(HFILE fhdl, int omode);

  protected_data:
    HFILE    FHdl;         // file handle if held open at the document level

  private:                 // cached info for property access
    bool     InfoPresent;
    ulong    FileLength;

#if defined(BI_PLAT_WIN32)
    FILETIME FileCreateTime;
    FILETIME FileAccessTime;
    FILETIME FileUpdateTime;
#else
    ulong    CalcFileLength(HFILE file);
    ulong    FileTime;
#endif

  DECLARE_STREAMABLE(_OWLCLASS, TFileDocument,1);
  friend class _OWLCLASS_RTL TFileInStream;
  friend class _OWLCLASS_RTL TFileOutStream;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline TFileDocument::TFileDocument(TDocument* parent)
:
  TDocument(parent), FHdl(HFILE_ERROR), InfoPresent(false)
{
}

//
inline TFileDocument::~TFileDocument()
{
}

//
inline bool TFileDocument::IsOpen()
{
  return FHdl != HFILE_ERROR || TDocument::IsOpen();
}

//
// Return the number of property support by this document.
// NOTE: The property count includes properties inherited from base document
//       classes.
//
inline int TFileDocument::PropertyCount()
{
  return NextProperty - 1;
}

#endif  // OWL_FILEDOC_H
