//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
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

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TOleWindow;

//
// class TOleDocument
// ~~~~~ ~~~~~~~~~~~~
// The ole document class.
//
class _USERCLASS TOleDocument : public TStorageDocument {
  public:
    TOleDocument(TDocument* parent = 0);
   ~TOleDocument();

    // Accessors
    //
    void          SetOcDoc(TOcDocument* doc);
    TOcDocument*  GetOcDoc();
    TOcApp*       GetOcApp();

    // Overridables:
    //   TDocument:
    //
    bool          Commit(bool force);
    bool          Open(int mode, const char far* path = 0);
    bool          Close();
    bool          InitDoc();
    bool          CanClose();
    bool          Revert(bool clear);

    //   TStorageDocument:
    bool          SetStorage(IStorage* stg, bool remember = true);
    bool          RestoreStorage();
    bool          ReleaseDoc();

    //   TOleDocument:
    virtual void  PreOpen();
    virtual bool  Read();
    virtual bool  Write();
    virtual bool  CommitSelection(TOleWindow& oleWin, void* userData);

    // Utilities
    //
    bool PathChanged();
    void OleViewClose();

  private:
    TOcDocument*      OcDoc;    // OCF document partner
    bool              Closing;  // shutdown in progress
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
inline void TOleDocument::SetOcDoc(TOcDocument* doc)
{
  OcDoc = doc;
}

//
inline TOcDocument* TOleDocument::GetOcDoc()
{
  return OcDoc;
}

//
// Virtual function to be overriden in TOleDocument-derived class which
// serve or support linking to portions of a document's data.
//
inline bool TOleDocument::CommitSelection(TOleWindow& oleWin, void* userData)
{
  return true;
}

#endif
