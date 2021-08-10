//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   include\owl\filedoc.h
//   Defines class TFileDocument
//----------------------------------------------------------------------------
#if !defined(__OWL_FILEDOC_H)
#define __OWL_FILEDOC_H

#if !defined(__OWL_DOCVIEW_H)
  #include "owl\docview.h"
#endif
#if !defined(__IOSTREAM_H)
  #include <iostream.h>
#endif

//
//  class TFileDocument
//  ----- -------------
//
class _OWLCLASS TFileDocument : public TDocument {
  public:
    enum {
      PrevProperty = TDocument::NextProperty-1,
      CreateTime,        // FILETIME
      ModifyTime,        // FILETIME
      AccessTime,        // FILETIME
      StorageSize,       // unsigned long
      FileHandle,        // platform file handle (HFILE if Windows)
      NextProperty,
    };

    TFileDocument(TDocument* parent = 0)
                 : TDocument(parent), FHdl(HFILE_ERROR), InfoPresent(FALSE) {}
   ~TFileDocument() {}

    // implement virtual methods of TDocument
    //
    BOOL        Open(int mode, LPCSTR path=0);
    BOOL        Close();
    TInStream*  InStream (int mode, LPCSTR strmId=0);
    TOutStream* OutStream(int mode, LPCSTR strmId=0);
    BOOL        Commit(BOOL force = FALSE);
    BOOL        Revert(BOOL clear = FALSE);
    BOOL        IsOpen() {return FHdl != HFILE_ERROR || TDocument::IsOpen();}

    int         FindProperty(const char far* name);  // return index
    int         PropertyFlags(int index);
    const char* PropertyName(int index);
    int         PropertyCount() {return NextProperty - 1;}
    int         GetProperty(int index, void far* dest, int textlen=0);
    BOOL        SetProperty(int index, const void far* src);

    // additional methods for file document
    //
    BOOL        Open(HFILE fhdl);     // open on existing file handle

  protected:
    HFILE FHdl;  // file handle if held open at the document level
    HFILE OpenThisFile(int omode, LPCSTR name, streampos* pseekpos);
    void  CloseThisFile(HFILE fhdl, int omode);
    friend class _OWLCLASS_RTL TFileInStream;
    friend class _OWLCLASS_RTL TFileOutStream;

  private:  // cached info for property access
    BOOL          InfoPresent;
    unsigned long FileLength;
#if defined(__WIN32__)
    FILETIME FileCreateTime;
    FILETIME FileAccessTime;
    FILETIME FileUpdateTime;
#else
    unsigned long FileTime;
#endif

  DECLARE_STREAMABLE (_OWLCLASS, TFileDocument,1);
};

#endif  // __OWL_FILEDOC_H
