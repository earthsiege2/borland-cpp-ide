//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.6  $
//
// Implementation of TOcDocument Class
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/ocstorag.h>
#include <ocf/ocdoc.h>
#include <ocf/ocpart.h>
#include <ocf/ocapp.h>
#include <ocf/ocremvie.h>

DIAG_DECLARE_GROUP(OcRefCount);

const char  DocStreamName[] = "OcDocument";

//
//
//
TOcDocument::TOcDocument(TOcApp& app, const char far* fileName)
:
  OcApp(app),
#if defined(BI_DATA_NEAR)
  Name(*new string(fileName)),
  PartCollection(*new TOcPartCollection),
  LinkCollection(*new TOcLinkCollection)
#else
  Name(fileName),
  PartCollection(),
  LinkCollection()
#endif
{
  // Host support...
  //
  ActiveView = 0;
  PartID     = 0;
  Storage    = 0;

  bool createNew = ToBool(!fileName || !fileName[0]);
  Storage = new TOcStorage(fileName, createNew);
  TRACEX(OcRefCount, 1, "TOcDocument() @" << (void*)this);
}

//
//
//
TOcDocument::TOcDocument(TOcApp& app, const char far* fileName, IStorage far* storageI)
:
  OcApp(app),
#if defined(BI_DATA_NEAR)
  Name(*new string(fileName)),
  PartCollection(*new TOcPartCollection),
  LinkCollection(*new TOcLinkCollection)
#else
  Name(fileName),
  PartCollection(),
  LinkCollection()
#endif
{
  // Host support...
  //
  ActiveView = 0;
  PartID     = 0;
  Storage    = 0;
  OrgStorage = 0;

  if (storageI)   // Storage already created by host application
    Storage = new TOcStorage(storageI);
  else
    Storage = 0;  // No storage yet, wait until a SetStorage() is called
  TRACEX(OcRefCount, 1, "TOcDocument() @" << (void*)this);
}

//
//
//
TOcDocument::~TOcDocument()
{
  delete Storage;
#if defined(BI_DATA_NEAR)
  delete &PartCollection;
  delete &LinkCollection;
  delete &Name;
#endif
}

//----------------------------------------------------------------------------

//
// Set the storage for this document
//
void
TOcDocument::SetStorage(IStorage* storage, bool remember)
{
  if (Storage && storage == Storage->GetIStorage())
    return;

  if (remember) {
    delete Storage;
    OrgStorage = 0;
  }
  else
    OrgStorage = Storage;

  if (storage)
    Storage = new TOcStorage(storage);
  else
    Storage = 0;
}

//
// Set the storage for this document
//
void
TOcDocument::SetStorage(const char far* path)
{
  delete Storage;
  Storage = new TOcStorage(path, false);
  SetName(path);    // new Storage now has path as a name
}

//
// Restore the original root IStorage before the save operation
//
bool
TOcDocument::RestoreStorage()
{
  if (OrgStorage) {
    delete Storage;

    Storage    = OrgStorage;
    OrgStorage = 0;
  }

  return true;
}

//
// Perform saveas operation
//
bool
TOcDocument::SaveToFile(const char far* newName)
{
  PRECONDITION(newName);

  TOcStorage newStorage(newName, true);
  Name = newName;
  return SaveParts(newStorage.GetIStorage(), false);
}

//
// Save the embedded parts to the provided storage. 'remember' flag is not
// really used here, as our save/restore is done outside here.
//
bool
TOcDocument::SaveParts(IStorage* storage, bool sameAsLoaded, bool remember)
{
  if (!Storage)
    return true;

  TOcStorage* oldStorage = 0;

  // If the storage passed is not the same as the one we loaded, wrap the new
  // one & use it in here.
  //
  if (!sameAsLoaded) {
    CHECK(storage);

    // If we are switching storages, make sure parts all all pulled in now
    //
    for (TOcPartCollectionIter i(PartCollection); i; i++) {
      TOcPart& part = *i.Current();
      part.FinishLoading();
    }
    oldStorage = Storage;
    Storage = new TOcStorage(storage);
  }

  // Create a stream for part information
  //
  STATSTG statstg;
  if (!HRSucceeded(Storage->Stat(&statstg, STATFLAG_NONAME)))
    return false;

  TOcStream  stream(*Storage, ::DocStreamName, true, statstg.grfMode);

  // Write TOcDocument data into stream
  //
  ulong count;
  bool  ok;
  ulong value = PartCollection.Count();
  ok = ToBool(HRSucceeded(stream.Write(&PartID, sizeof PartID, &count)) &&
              HRSucceeded(stream.Write(&value, sizeof value, &count)));

  if (ok) {
    for (TOcPartCollectionIter i(PartCollection); i; i++) {
      TOcPart& part = *i.Current();
      int16 len = int16(part.GetName().Length());

      // Write the part name string, pascal style [len]+chars, no 0
      //
      ok = ToBool(HRSucceeded(stream.Write(&len, sizeof len, &count)) &&
                  HRSucceeded(stream.Write((char far*)part.GetName(), len, &count)) &&
                  part.Save(sameAsLoaded, remember));

      if (!ok)
        break;
    }
  }

  // Deal with the alloc'd storage if there was one. Either put things back on
  // failure, or keep the new storage around for a while
  //
  if (!sameAsLoaded) {
    if (!ok) {
      delete Storage;
      Storage = oldStorage;
    }
    else
      delete oldStorage;
  }

  return ok;
}

//
// Loads the parts from the current storage into the PartCollection. Return
// false if a serious error occurs. Having no part stream at all is OK.
//
bool
TOcDocument::LoadParts()
{
  if (!Storage)
    return true;

  // Clear the part collection
  //
  //PartCollection.Clear(); 
                            // There is a case when clearing now causes a crash

  // Open a stream with part information
  //
  STATSTG statstg;
  if (!HRSucceeded(Storage->Stat(&statstg, STATFLAG_NONAME)))
    return false;

  try {
    TOcStream  stream(*Storage, ::DocStreamName, false, statstg.grfMode);

    // Read TOcDocument data from stream. Return false if any of the data
    // is missing--something must have been corrupted.
    //
    if (!HRSucceeded(stream.Read(&PartID, sizeof PartID)))
      return false;

    ulong value;
    if (!HRSucceeded(stream.Read(&value, sizeof value)))
      return false;

    // Clear the part collection
    //
    PartCollection.Clear();

    // Rebuild the part collection
    //
    for (int i = (int)value; i; i--) {
      char name[33];
      int16 len;

      // Read the part name string, pascal style [len]+chars, no 0
      //
      if (!HRSucceeded(stream.Read(&len, sizeof len)))
        return false;

      if (len >= sizeof name) // too big for our buffer, how could that happen?
        return false;

      if (!HRSucceeded(stream.Read(name, len)))
        return false;
      name[len] = 0;  // 0 was not written

      new TOcPart(*this, name);
    }
  }
  catch (TXObjComp&) {
    // There is no part related info stream. Thats OK, we then have a document
    // with no parts
  }
  return true;
}

//
//
//
void
TOcDocument::RenameParts(IBRootLinkable far* bLDocumentI)
{
  if (Name.is_null())
    return; // Temporary file does not have moniker

  for (TOcPartCollectionIter i(PartCollection); i; i++) {
    TOcPart& part = *i.Current();

    IBLinkable far* linkI;
    if (HRSucceeded(part.QueryInterface(IID_IBLinkable, &(LPVOID)linkI))) {
      linkI->OnRename(bLDocumentI, part.GetName());
      linkI->Release();
    }
  }
}

//
//
//
void
TOcDocument::Close()
{
  for (TOcPartCollectionIter i(PartCollection); i; i++) {
    TOcPart& part = *i.Current();
    part.Close();
  }

  for (TOcLinkCollectionIter j(LinkCollection); j; j++) {
    TOcLinkView& link = *j.Current();
    link.Disconnect();
  }

  LinkCollection.Clear();  // Remove the link views now
}

//
//
//
void
TOcDocument::SetActiveView(TOcView* view)
{
  ActiveView = view;
}

//
// Notify container that doc pathname has changed
//
void
TOcDocument::SetName(const string& newName)
{
  Name = newName;

  // Create a moniker for this document
  //
  if (!Name.is_null() && ActiveView)
    ActiveView->Rename();
}
