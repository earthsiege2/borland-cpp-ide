//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Defines class TFileDocument
//----------------------------------------------------------------------------
#if !defined(OWL_FILEDOC_H)
#define OWL_FILEDOC_H

#if !defined(OWL_DOCVIEW_H)
# include <owl/docview.h>
#endif
#if !defined(__IOSTREAM_H)
# include <iostream.h>
#endif

//
//  class TFileDocument
//  ----- -------------
//
class _OWLCLASS TFileDocument : public TDocument {
  public:
    enum TFileDocProp {
      PrevProperty = TDocument::NextProperty-1,
      CreateTime,        // FILETIME
      ModifyTime,        // FILETIME
      AccessTime,        // FILETIME
      StorageSize,       // unsigned long
      FileHandle,        // platform file handle (HFILE if Windows)
      NextProperty,
    };

    TFileDocument(TDocument* parent = 0)
                 : TDocument(parent), FHdl(HFILE_ERROR), InfoPresent(false) {}
   ~TFileDocument() {}

    // implement virtual methods of TDocument
    //
    bool        Open(int mode, const char far* path=0);
    bool        Close();
    TInStream*  InStream(int mode, const char far* strmId=0);
    TOutStream* OutStream(int mode, const char far* strmId=0);
    bool        Commit(bool force = false);
    bool        Revert(bool clear = false);
    bool        IsOpen() {return FHdl != HFILE_ERROR || TDocument::IsOpen();}

    int         FindProperty(const char far* name);  // return index
    int         PropertyFlags(int index);
    const char* PropertyName(int index);
    int         PropertyCount() {return NextProperty - 1;}
    int         GetProperty(int index, void far* dest, int textlen=0);
    bool        SetProperty(int index, const void far* src);

    // additional methods for file document
    //
    bool        Open(HFILE fhdl);     // open on existing file handle

  protected:
    HFILE FHdl;  // file handle if held open at the document level
    HFILE OpenThisFile(int omode, const char far* name, streampos* pseekpos);
    void  CloseThisFile(HFILE fhdl, int omode);

  private:  // cached info for property access
    bool          InfoPresent;
    unsigned long FileLength;

#if defined(BI_PLAT_WIN32)
    FILETIME FileCreateTime;
    FILETIME FileAccessTime;
    FILETIME FileUpdateTime;
#else
    unsigned long FileTime;
#endif

  DECLARE_STREAMABLE(_OWLCLASS, TFileDocument,1);
  friend class _OWLCLASS_RTL TFileInStream;
  friend class _OWLCLASS_RTL TFileOutStream;
};

#endif  // OWL_FILEDOC_H
