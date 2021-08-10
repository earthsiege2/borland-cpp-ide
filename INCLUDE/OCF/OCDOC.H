//
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Definition of TOcDocument Class
//----------------------------------------------------------------------------
#if !defined(OCF_OCDOC_H)
#define OCF_OCDOC_H

#if !defined(OCF_OCPART_H)
# include <ocf/ocpart.h>
#endif

#if !defined(OCF_LINK_H)
# include <ocf/oclink.h>
#endif

// Interfaces & Classes referenced
//
class _ICLASS IStorage;
class _ICLASS TOcStorage;
class _ICLASS TOcApp;
class _ICLASS TOcView;

//
// OC Document class, holds parts & is a owner of views
//
class _ICLASS TOcDocument {
  public:
    TOcDocument(TOcApp& app, const char far* fileName = 0);
    TOcDocument(TOcApp& app, const char far* fileName, IStorage far* storageI);
   ~TOcDocument();

    // collection management
    //
    TOcPartCollection& GetParts() {return PartCollection;}
    TOcViewCollection& GetViews() {return ViewCollection;}

    // Storage & streaming related
    //
    TOcStorage* GetStorage() {return Storage;}
    void        SetStorage(IStorage* storage, bool remember = true);
    void        SetStorage(const char far* path);
    bool        SaveToFile(const char far* newName);
    bool        RestoreStorage();

    // Load/Save part information
    //
    bool        LoadParts();
    bool        SaveParts(IStorage* storage = 0, bool sameAsLoaded = true,
                          bool remember = true);
    void        RenameParts(IBRootLinkable far* bLDocumentI);
    void        Close();

    // Get/Set active view
    //
    TOcView*    GetActiveView() {return ActiveView;}
    void        SetActiveView(TOcView* view);

    // Get/Set document name
    //
    string      GetName() const {return Name;}
    void        SetName(const string& newName);

  private:
    TOcView*       ActiveView;   // Active TOcView object
    TOcApp&        OcApp;        // Our OC application object
    TOcStorage*    Storage;      // root storage for embedded objects
    TOcStorage*    OrgStorage;   // original root storage for embedded objects

    int            NumViews;     // number of views. used to help in numbering
    int            PartID;
#if defined(BI_DATA_NEAR)
    string&        Name;         // Name of this document
    TOcPartCollection&    PartCollection; // Collection of parts in this document
    TOcViewCollection&    ViewCollection; // Collection of linked view in this document
#else
    string         Name;
    TOcPartCollection     PartCollection;
    TOcViewCollection     ViewCollection;
#endif

  friend TOcPartCollectionIter;      // To allow iterator access to collection
  friend TOcViewCollectionIter;      // To allow iterator access to collection
  friend TOcPart;
  friend TOcView;
  friend TOcRemVie;
};

#endif  // OCF_OCDOC_H

