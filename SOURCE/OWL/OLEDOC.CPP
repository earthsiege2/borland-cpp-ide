//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of TOleDocument. Doc/View document that supports OLE 2
// using OCF TOcDocument
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/pch.h>
#if !defined(OWL_DOCMANAG_H)
# include <owl/docmanag.h>
#endif
#if !defined(OWL_OLEMDIFR_H)
# include <owl/olemdifr.h>
#endif
#if !defined(OCF_OCDOC_H)
# include <ocf/ocdoc.h>
#endif
#if !defined(OCF_OCAPP_H)
# include <ocf/ocapp.h>
#endif
#if !defined(OWL_OLEDOC_H)
# include <owl/oledoc.h>
#endif
#if !defined(OWL_OLEFRAME_H)
# include <owl/oleframe.h>
#endif
#if !defined(OWL_OLEVIEW_H)
# include <owl/oleview.h>
#endif

//
//
//
TOleDocument::TOleDocument(TDocument* parent)
:
  TStorageDocument(parent),
  OcDoc(0),
  Closing(false)
{
}

//
// For an OLE container the compound file remains open
// until the application shuts down
//
TOleDocument::~TOleDocument()
{
  delete OcDoc;
}

//
// Prepare document shutdown
//
bool
TOleDocument::CanClose()
{
	//
	// if it's an open edit dll stop the closing process
  TView* curView = GetViewList();
  while (curView) {
  	// get the ole view
    TOleView* oleView = TYPESAFE_DOWNCAST(curView, TOleView);
    if (oleView && oleView->IsOpenEditing() && !GetOcApp()->IsOptionSet(amExeMode)) {
	    TOleFrame* olefr = TYPESAFE_DOWNCAST(oleView->GetApplication()->GetMainWindow(), TOleFrame);
  	  CHECK(olefr);
    	olefr->ShowWindow(SW_HIDE);
    	oleView->OleShutDown();
    	return false; // don't close
    }
    curView = curView->GetNextView();
  }

  // Just say yes if we are already in the closing process, or are embedded,
  // or have multiple views open
  //

  if (Closing || IsEmbedded())
    return true;

  return TDocument::CanClose();
}

//
//  Shut down the TOleView's
//
void
TOleDocument::OleViewClose()
{
  TView* curView = GetViewList();
  while (curView) {
    TOleView* oleView = TYPESAFE_DOWNCAST(curView, TOleView);
    if (oleView)
      oleView->OleShutDown();

    curView = curView->GetNextView();
  }
}

//
// Close the compound file
//
bool
TOleDocument::Close()
{
  // Make sure that TOleView's are closed first
  //
  OleViewClose();
  OcDoc->Close();
  return TStorageDocument::Close();
}

//
// Close the OLE document when the server is done with the
// given IStorage from its container
//
bool
TOleDocument::ReleaseDoc()
{
  PRECONDITION(OcDoc);

  TStorageDocument::ReleaseDoc();
  OcDoc->SetStorage((IStorage*)0);

  return true;
}

//
// Open the OLE document when the server is provided with an
// IStorage from its container
//
bool
TOleDocument::SetStorage(IStorage* stg, bool remember)
{
  PRECONDITION(OcDoc);

  // If a storage is provided, then we are now using container's IStorage
  //
  if (stg)
    Embedded = true;

  OcDoc->SetStorage(stg, remember);
  TStorageDocument::SetStorage(stg, remember);

  return true;
}

//
// Restores the original root IStorage before the save operation
//
bool
TOleDocument::RestoreStorage()
{
  PRECONDITION(OcDoc);

  OcDoc->RestoreStorage();
  TStorageDocument::RestoreStorage();

  return true;
}

//
// Set the initial open mode
//
void
TOleDocument::PreOpen()
{
  SetOpenMode(ofReadWrite | ofTransacted);
}

//
// Open the compound file so that we have an IStorage for use
// with embedded objects. A document partner is created
// to handle OLE related stuff.
//
bool
TOleDocument::InitDoc()
{
  if (IsOpen())
    return true; // compound file already open

  // Give user a chance to set a different open mode
  //
  PreOpen();

  if (GetDocPath())
    SetOpenMode(GetOpenMode() | ofNoCreate);
  else
    SetOpenMode(GetOpenMode() | ofTemporary);

  if (TStorageDocument::Open(GetOpenMode(), GetDocPath())) {
    if (OcDoc) { // use the existing ocdoc
      OcDoc->SetStorage(StorageI);
    }
    else if (GetOcApp()) {
      OcDoc = new TOcDocument(*GetOcApp(), GetDocPath(), StorageI);
    }

    return true;
  }

  return false;
}

//
// Save the embedded objects, if any
//
bool
TOleDocument::Commit(bool force)
{
  if (Write())
    return TStorageDocument::Commit(force);
  else
    return false;
}

//
// Load the embedded objects, if any
//
bool
TOleDocument::Open(int, const char far* path)
{
  if (path)
    SetDocPath(path);

  return Read();
}

//
// Check if current document path is the same as the
// OcDoc's.
//
bool TOleDocument::PathChanged()
{
  string::set_case_sensitive(false);
  return OcDoc->GetName() != string(GetDocPath());
}

//
// Save embed objects to the compound file
//
bool
TOleDocument::Write()
{
  // Switch to new storage if path has changed & it is permanent ("SaveAs")
  //
  IStorage* newStorageI;
  bool saveAs = PathChanged() && !OrgStorageI;      // also is 'remember'
  bool sameAsLoad = !PathChanged() && !OrgStorageI; // use current storage
  if (saveAs) {
    // Update link monikers
    //
    string newName(GetDocPath());
    OcDoc->SetName(newName);

    if (IsEmbedded())
      newStorageI = StorageI; // Use the one assigned by container
    else
      newStorageI = GetNewStorage();
  }
  else
    newStorageI = StorageI;

  return newStorageI ?
    OcDoc->SaveParts(newStorageI, sameAsLoad, saveAs) :
    false;
}

//
// Load embed objects from the compound file
//
bool
TOleDocument::Read()
{
  // Load the embedded objects, if any
  //
  return OcDoc->LoadParts();
}

//
// Revert to last saved compound file
//
bool
TOleDocument::Revert(bool clear)
{
  if (!StorageI)
    return true;                    // return OK if storage already released

  if (!TDocument::Revert(clear) || !ReleaseDoc())
    return false;

  if (!clear) {
    InitDoc();
    Open(0);
  }

  SetDirty(false);
  return true;
}

//
// Get OCF application partner
//
TOcApp*
TOleDocument::GetOcApp()
{
  TOleFrame* olefr = TYPESAFE_DOWNCAST(GetDocManager().GetApplication()->GetMainWindow(), TOleFrame);

  return olefr->GetOcApp();
}
