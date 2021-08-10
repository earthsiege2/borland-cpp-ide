//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// Definition of TOcDocument Class
//----------------------------------------------------------------------------
#if !defined(OCF_OCDOC_H)
#define OCF_OCDOC_H

#if !defined(OCF_OCPART_H)
# include <ocf/ocpart.h>
#endif
#if !defined(OCF_LINK_H)
# include <ocf/oclink.h>
#endif

//
// Interfaces & Classes referenced
//
class _ICLASS IStorage;
class _ICLASS TOcStorage;
class _ICLASS TOcApp;
class _ICLASS TOcControl;
class _ICLASS TOcView;

//
// class TOcDocument
// ~~~~~ ~~~~~~~~~~~
// OC Document class, holds parts & is a owner of views
//
class _ICLASS TOcDocument {
  public:
    TOcDocument(TOcApp& app, const char far* fileName = 0);
    TOcDocument(TOcApp& app, const char far* fileName, IStorage far* storageI);
   ~TOcDocument();

    // Collection management
    //
    TOcPartCollection& GetParts() {return PartCollection;}
    TOcLinkCollection& GetLinks() {return LinkCollection;}
    TOcLinkCollection& GetViews() {return LinkCollection;} // Compatibility

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

    int         AllocPartID() {return ++PartID;}
    TOcApp&     GetOcApp() {return OcApp;}

  private:
    TOcView*       ActiveView;   // Active TOcView object
    TOcApp&        OcApp;        // Our OC application object
    TOcStorage*    Storage;      // root storage for embedded objects
    TOcStorage*    OrgStorage;   // original root storage for embedded objects

    int            PartID;
#if defined(BI_DATA_NEAR)
    string&        Name;         // Name of this document
    TOcPartCollection& PartCollection; // Collection of parts in this document
    TOcLinkCollection& LinkCollection; // Collection of link views in this document
#else
    string         Name;
    TOcPartCollection  PartCollection;
    TOcLinkCollection  LinkCollection;
#endif

  friend TOcPartCollectionIter;      // To allow iterator access to collection
  friend TOcLinkCollectionIter;      // To allow iterator access to collection
//  friend TOcPart;
  friend TOcControl;
  friend TOcView;
  friend TOcRemVie;
};

#endif  // OCF_OCDOC_H

