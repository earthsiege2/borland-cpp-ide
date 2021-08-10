//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(OWL_OLEDOC_H)
#define OWL_OLEDOC_H

#if !defined(OWL_STGDOC_H)
# include <owl/stgdoc.h>
#endif
#if !defined(OWL_OCFEVENT_H)
# include <owl/ocfevent.h>
#endif
#if !defined(OCF_OCDOC_H)
# include <ocf/ocdoc.h>
#endif

class _OWLCLASS TOleWindow;

//
// class TOleDocument
// ----- ------------
//
// The ole document class.
//
class _USERCLASS TOleDocument : public TStorageDocument {
  public:
    TOleDocument(TDocument* parent = 0);
   ~TOleDocument();

    // Accessors
    void          SetOcDoc(TOcDocument* doc) {OcDoc = doc;}
    TOcDocument*  GetOcDoc() {return OcDoc;}
    TOcApp*       GetOcApp();

    // Overridables
    virtual bool Commit(bool force);
    virtual bool CommitSelection(TOleWindow& oleWin, void* userData) {return true;}
    virtual bool Open(int mode, const char far* path = 0);
    virtual bool Close();

    bool Revert(bool clear);
    virtual void      PreOpen();
    virtual bool      Write();
    virtual bool      Read();
    virtual bool      SetStorage(IStorage* stg, bool remember = true);
    virtual bool      RestoreStorage();

    virtual bool      CanClose();
    virtual bool      ReleaseDoc();
    virtual bool      InitDoc();
    virtual IStorage* GetNewStorage();

    // Utilities
    bool         PathChanged();

  private:
    TOcDocument*      OcDoc;    // OCF document partner
    bool              Closing;  // shutdown in progress
};

#endif
