//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.18  $
//
// Definitions of Win95 Shell Clases:
//   TShellItem, TShellItemIterator, TPidl, TShellMalloc
//
// Also the following lightweight "wrapper" classes are defined:
//   TExtractIcon, TContextMenu, TDataObject, TDropTarget
//
// These are wrapper classes for the Win95 deskop.
//----------------------------------------------------------------------------
#if !defined(OWL_SHELLITM_H)
#define OWL_SHELLITM_H

#if !defined(OWL_EXCEPT_H)
# include <owl/except.h>
#endif
#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OCF_OLEUTIL_H)
# include <ocf/oleutil.h>
#endif
#if !defined(WINSYS_STRING_H)
# include <winsys/string.h>
#endif
#if !defined(_SHLOBJ_H_)
# include <shlobj.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// class TShellMalloc
// ~~~~~ ~~~~~~~~~~~~
// wraps the shell's IMalloc interface
// Default constructor obtains shell's IMalloc interface
// TComRef<IMalloc> and copy constructors supplied
// TComRef<IMalloc> and TShellMalloc assignment operators also supplied
//
//
class TShellMalloc: public TComRef<IMalloc> {
  public:
    TShellMalloc();
    TShellMalloc(const TComRef<IMalloc>& source);
    TShellMalloc(const TShellMalloc& source);
    TShellMalloc& operator = (const TComRef<IMalloc>& source);
    TShellMalloc& operator = (const TShellMalloc& source);
};

//
// class TExtractIcon
// ~~~~~ ~~~~~~~~~~~~
// Wraps the IExtractIcon interface (currently lightweight)
// A TExtractIcon is returned by TShellItem::GetExtractIcon
// Default, TComRef<IExtractIcon> and copy constructors supplied
// TComRef<IExtractIcon> and TExtractIcon assignment opreators also supplied
//
class TExtractIcon: public TComRef<IExtractIcon> {
  public:
    TExtractIcon(IExtractIcon* iface = 0);
    TExtractIcon(const TComRef<IExtractIcon>& source);
    TExtractIcon(const TExtractIcon& source);
    TExtractIcon& operator= (const TComRef<IExtractIcon>& source);
    TExtractIcon& operator= (const TExtractIcon& source);
};

//
// class TContextMenu
// ~~~~~ ~~~~~~~~~~~~
// Wraps the IContextMenu interface (currently lightweight)
// A TContextMenu is returned by TShellItem::GetContextMenu
// Default, TComRef<IContextMenu> and copy constructors supplied
// TComRef<IContextMenu> and TContextMenu assignment opreators also supplied
//
class TContextMenu: public TComRef<IContextMenu> {
  public:
    TContextMenu(IContextMenu* iface = 0);
    TContextMenu(const TComRef<IContextMenu>& source);
    TContextMenu(const TContextMenu& source);
    TContextMenu& operator = (const TComRef<IContextMenu>& source);
    TContextMenu& operator = (const TContextMenu& source);
};

//
// class TDataObject
// ~~~~~ ~~~~~~~~~~~
// Wraps the IDataObject interface (currently lightweight)
// A TDataObject is returned by TShellItem::GetDataObject
// Default, TComRef<IDataObject> and copy constructors supplied
// TComRef<IDataObject> and TDataObject assignment opreators also supplied
//
class TDataObject: public TComRef<IDataObject> {
  public:
    TDataObject(IDataObject* iface = 0);
    TDataObject(const TComRef<IDataObject>& source);
    TDataObject(const TDataObject& source);
    TDataObject& operator = (const TComRef<IDataObject>& source);
    TDataObject& operator = (const TDataObject& source);
};

//
// class TDropTarget
// ~~~~~ ~~~~~~~~~~~
// Wraps the IDropTarget interface (currently lightweight)
// A TDropTarget is returned by TShellItem::GetDropTarget
// Default, TComRef<IDropTarget> and copy constructors supplied
// TComRef<IDropTarget> and TDropTarget assignment opreators also supplied
//
class TDropTarget: public TComRef<IDropTarget> {
  public:
    TDropTarget(IDropTarget* iface = 0);
    TDropTarget(const TComRef<IDropTarget>& source);
    TDropTarget(const TDropTarget& source);
    TDropTarget& operator = (const TComRef<IDropTarget>& source);
    TDropTarget& operator = (const TDropTarget& source);
};

//
// class TPidl
// ~~~~~ ~~~~~
// item identifier list class (ITEMIDLIST)
// constructor takes an ITEMIDLIST* (a.k.a., pidl)
// copy constructor and assignement operators supplied
// functions to manipulate the ITEMIDLIST, get the size, get the number
// of items in the list, etc, supplied
// Normally, the programmer will not have to be concerned with ITEMIDLISTs
// nor with the TPidl class.  The TShellItem class hides all this.
//
class TPidl {
  public:
    static ITEMIDLIST* Next(ITEMIDLIST *pidl);

    // TPidl constructors and destructor
    //
    TPidl(ITEMIDLIST* pidl = 0);
    TPidl(const TPidl& source);
    virtual ~TPidl();

    // Assignment operators
    //
    TPidl& operator = (const TPidl& source);
    TPidl& operator = (ITEMIDLIST* pidl);

    // Test to see if valid pidl
    operator !() const;

    // Use TPidl in place of pidl
    operator const ITEMIDLIST* () const;

    // Use TPidl in place of pointer to a pidl (const)
    //
    operator const ITEMIDLIST ** () const;

    // Used to assign a new pidl
    //
    operator ITEMIDLIST** ();

    // Get size (in bytes) of a pidl
    //
    ulong GetSize() const;

    // Get number of item ids in the TPidl (the TPidl can be a list of ids)
    //
    long GetItemCount() const;

    // Get the last item id in the TPidl
    //
    TPidl GetLastItem() const;

    // Return a TPidl with the last item id stripped off of it
    //
    TPidl StripLastItem() const;

    // Copy a pidl
    //
    ITEMIDLIST* CopyPidl() const;

  protected:
    // Free a pidl with the shell's allocator
    //
    void FreePidl();

  protected_data:

    // A PIDL
    //
    ITEMIDLIST* Pidl;
};

//
// class TShellItem
// ~~~~~ ~~~~~~~~~~
// An item in the shell's name space.  All items in the shell's
// namespace can be identified by a fully qualified pidl.  Another
// way to uniquely identify an item is via it's parent and an item id
// (i.e., a single item rather than a list).  A TShellItem contains a
// parent (TComRef<IShellFolder> ParentFolder) and the item id (TPidl pidl)
//
class TShellItem: public TComRef<IShellFolder> {
  public:
    // Used by TShelItem::GetDisplayName() and TShellItem::Rename()
    // See MS doc for SHGNO for more information, Programmer's
    // Guide to MS Windows 95, MS Press, p. 218.
    //
    enum TDisplayNameKind { 
      Normal     = SHGDN_NORMAL,
      InFolder   = SHGDN_INFOLDER,
      ForParsing = SHGDN_FORPARSING
    };
    // Used by TShellItem::GetIcon
    // See MS doc for SHGetFileInfo for more information, Programmer's
    // Guide to MS Windows 95, MS Press, pp. 205-207.
    enum TIconSize { Large    = SHGFI_LARGEICON,
                     Small    = SHGFI_SMALLICON,
                     Shell    = SHGFI_SHELLICONSIZE
    };

    // Used by TShellItem::GetIcon
    // See MS doc for SHGetFileInfo for more information, Programmer's
    // Guide to MS Windows 95, MS Press, pp. 205-207.
    //
    enum TIconKind { 
      Link     = SHGFI_LINKOVERLAY,
      Open     = SHGFI_OPENICON,
      Selected = SHGFI_SELECTED
    };

    // Used by TShellItem::TShellItem(const TSpecialFolderKind kind,
    //                                HWND windowOwner = 0)
    // See MS doc for SHGetSpecialFolderLocation for more information,
    // Programmer's Guide to MS Windows 95, MS Press, pp. 209-210.
    //
    enum TSpecialFolderKind { 
      RecycleBin                  = CSIDL_BITBUCKET,
      ControlPanel                = CSIDL_CONTROLS,
      Desktop                     = CSIDL_DESKTOP,
      DesktopFileDir              = CSIDL_DESKTOPDIRECTORY,
      MyComputer                  = CSIDL_DRIVES,
      Fonts                       = CSIDL_FONTS,
      NetworkNeighborhoodFileDir  = CSIDL_NETHOOD,
      NetworkNeighborhood         = CSIDL_NETWORK,
      CommonDocuments             = CSIDL_PERSONAL,
      Printers                    = CSIDL_PRINTERS,
      Programs                    = CSIDL_PROGRAMS,
      RecentDocuments             = CSIDL_RECENT,
      SendTo                      = CSIDL_SENDTO,
      StartMenu                   = CSIDL_STARTMENU,
      Startup                     = CSIDL_STARTUP,
      CommonTemplates             = CSIDL_TEMPLATES,
      Favorites                   = CSIDL_FAVORITES
    };

    // Used by TShellItem::GetAttributes
    // See MS doc for IShellFolder::GetAttributesOf for more information,
    // Programmer's Guide to MS Windows 95, MS Press, pp. 194-196.
    //
    enum TAttribute { 
      // Capabilities
      //
      atCapabilityMask           = SFGAO_CAPABILITYMASK,
      atCanBeCopied              = SFGAO_CANCOPY,
      atCanBeDeleted             = SFGAO_CANDELETE,
      atCanCreateShortcut        = SFGAO_CANLINK,
      atCanBeMoved               = SFGAO_CANMOVE,
      atCanBeRenamed             = SFGAO_CANRENAME,
      atIsADropTarget            = SFGAO_DROPTARGET,
      atHasAPropertySheet        = SFGAO_HASPROPSHEET,

      // Display Attributes
      //
      atDisplayAttributeMask     = SFGAO_DISPLAYATTRMASK,
      atDisplayGhosted           = SFGAO_GHOSTED,
      atIsShortcut               = SFGAO_LINK,
      atIsReadOnly               = SFGAO_READONLY,
      atIsShared                 = SFGAO_SHARE,

      // Contents
      //
      atContentsMask             = SFGAO_CONTENTSMASK,
      atContainsSubFolder        = SFGAO_HASSUBFOLDER,

      // Miscellaneous
      //
      atContainsFileSystemFolder = SFGAO_FILESYSANCESTOR,
      atIsPartOfFileSystem       = SFGAO_FILESYSTEM,
      atIsFolder                 = SFGAO_FOLDER,
      atCanBeRemoved             = SFGAO_REMOVABLE
    };

    // Used by TShellItem::Rename,Copy,Move,Delete
    // See MS doc for SHFILEOPSTRUCT for more information, Programmer's
    // Guide to MS Windows 95, MS Press, pp. 214-215.
    //
    enum TFileOpFlags { 
      AllowUndo         = FOF_ALLOWUNDO,
      NoConfirmation    = FOF_NOCONFIRMATION,
      NoConfirmMkDir    = FOF_NOCONFIRMMKDIR,
      RenameOnCollision = FOF_RENAMEONCOLLISION,
      Silent            = FOF_SILENT,
      SimpleProgress    = FOF_SIMPLEPROGRESS
    };

    // Used by TShellItem::BrowseForFolder
    // See MS doc for BROWSEINFO for more information, Programmer's
    // Guide to MS Windows 95, MS Press, pp. 211-212.
    //
    enum TBrowseFlags { 
      OnlyComputers,
      OnlyPrinters,
      NoNetorkFoldersBelowDomain,
      OnlyFSAncestors,
      OnlyFSDirs
    };

    // Returned by TShellItem::GetExeType
    // See MS doc for SHGetFileInfo for more information, Programmer's
    // Guide to MS Windows 95, MS Press, pp. 205-207.
    //
    enum TExeKind { 
      NonExecutable,
      WindowsNE,
      WindowsPE,
      MSDOS,
      Win32Console
    };

    // TCreateStruct contains information to construct a TShellItem
    // Typically a TCreateStruct is returned (for example by GetParentFolder)
    // and this TCreateStruct is used to construct a TshellItem
    // Passed in as arguments to:
    //    TShellItem::TShellItem(const TCreateStruct& cs)
    //    TShellItem::operator =(const TCreateStruct& cs)
    // Returned as an out argument by:
    //    TShellItem::BrowseForFolder
    //    TShellItem::ParseDisplayName
    // Returned by:
    //    TShellItem::GetParentFolder
    //    TShellItemIterator::operator ++ ();
    //    TShellItemIterator::operator ++ (int);
    //    TShellItemIterator::operator -- ();
    //    TShellItemIterator::operator -- (int);
    //    TShellItemIterator::operator [] (const long index);
    //    TShellItemIterator::Current();
    //
    struct TCreateStruct {
      TCreateStruct();
      TCreateStruct(TPidl& ptr, TComRef<IShellFolder>& parentFolder);
      TCreateStruct(const TCreateStruct& source);

      TPidl                 Pidl;
      TComRef<IShellFolder> ParentFolder;
    };

    // Constructors for TShellItem
    //
    TShellItem(const char* path, bool throwOnInvalidPath = true, HWND windowOwner = 0);
    TShellItem(const TSpecialFolderKind kind, HWND windowOwner = 0);
    TShellItem(const TCreateStruct& cs);  // used with TShellItemIterator
    TShellItem(const TPidl& Pidl, const TComRef<IShellFolder>& parentFolder);
    TShellItem(ITEMIDLIST* pidl = 0,
               const TComRef<IShellFolder>& parentFolder = 0);
    TShellItem(const TShellItem& source);

    // Assignment operators
    //
    TShellItem& operator =(const TShellItem& source);
    TShellItem& operator =(const TCreateStruct& cs);

    // Determine if TShellItem reprsents a valid item
    //
    bool Valid() const;

    // Allow TShellItems to be used in place of pidls
    operator ITEMIDLIST*();

    // Get TExtractIcon, TContextMenu, TDataObject, TDropTarget for a TShellItem
    TExtractIcon  GetExtractIcon(HWND windowOwner = 0);
    TContextMenu  GetContextMenu(HWND windowOwner = 0);
    TDataObject   GetDataObject(HWND windowOwner = 0);
    TDropTarget   GetDropTarget(HWND windowOwner = 0);
    HICON         GetIcon(TIconSize size = Shell, uint kind = 0);

    // Get Attributes of a TShellItem
    // GetAttributes - Get Capabilities, Display, Contents, & Misc. Attributes with one call
    //
    ulong GetAttributes(const ulong reqAttrib, const bool validateCachedInfo = false) const;

    // Attributes - Capabilties
    //
    bool CanBeCopied(const bool validateCachedInfo = false) const;
    bool CanBeDeleted(const bool validateCachedInfo = false) const;
    bool CanCreateShortcut(const bool validateCachedInfo = false) const;
    bool CanBeMoved(const bool validateCachedInfo = false) const;
    bool CanBeRenamed(const bool validateCachedInfo = false) const;
    bool IsADropTarget(const bool validateCachedInfo = false) const;
    bool HasAPropertySheet(const bool validateCachedInfo = false)const;

    // Attributes - Display
    //
    bool DisplayGhosted(const bool validateCachedInfo = false) const;
    bool IsShortcut(const bool validateCachedInfo = false) const;
    bool IsReadOnly(const bool validateCachedInfo = false) const;
    bool IsShared(const bool validateCachedInfo = false) const;

    // Attributes - Contents
    //
    bool ContainsSubFolder(const bool validateCachedInfo = false) const;

    // Attributes - Miscellaneous
    //
    bool ContainsFileSystemFolder(const bool validateCachedInfo = false) const;
    bool IsPartOfFileSystem(const bool validateCachedInfo = false) const;
    bool IsFolder(const bool validateCachedInfo = false) const;
    bool CanBeRemoved(const bool validateCachedInfo = false) const;

    // Attributes - Additional (Not part of GetAttributes)
    //
    bool IsDesktop() const;

    // Get TPidl (relative to parent)
    //
    TPidl GetPidl() const;

    // Get fully qualified TPidl
    //
    TPidl GetFullyQualifiedPidl() const;

    // Get Parent Folder
    //
    TCreateStruct GetParentFolder() const;

    // Get type of executable file (may return NonExecutable)
    //
    TExeKind GetExeType(uint* major = 0, uint* minor = 0) const;

    // Get type of file (e.g., "Borland C++ Header File", "Notepad File")
    //
    TString GetTypeName() const;

    // Get Displayname (for a TShellItem that's part of the filesystem, this is the filename)
    //
    TString GetDisplayName(const TDisplayNameKind kind = Normal) const;

    // Get path (only call if the TShellItem is part of the file system (IsPartOfFileSystem == true)
    //
    TString GetPath() const;

    // File Opertations (Rename, Copy, Move, Delete)
    //
    void Rename(const char* newName, HWND windowOwner = 0,
                const TDisplayNameKind kind = Normal);
    bool Copy(const char* dest, const bool destIsFolder = true,
              const ushort flags = 0, const char* title = 0,
              HWND windowOwner = 0) const;
    bool Copy(const TShellItem& dest, const ushort flags = 0, const char* title = 0,
              HWND windowOwner = 0) const;
    bool Move(const char* destFolder, const ushort flags = 0,
              const char* title = 0, HWND windowOwner = 0);
    bool Move(const TShellItem& destFolder, const ushort flags = 0,
              const char* title = 0, HWND windowOwner = 0);
    bool Delete(const ushort flags = 0, const char* title = 0,
                HWND windowOwner = 0);

    // Add to recent docs (Win95 taskbar:Start:Documents)
    //
    void AddToRecentDocs() const;

    // Get the TShellItem that a shortcut points to
    //
    TShellItem ResolveShortcut(HWND windowOwner = 0);

    // Create a shortcut
    //
    static HRESULT CreateShortCut(LPCSTR objPath, LPSTR pathLink, 
                                  LPSTR description);
    static HRESULT CreateShortCut(LPCITEMIDLIST pidl, LPSTR pathLink,
                                  LPSTR description);
    TShellItem     CreateShortCut(LPSTR pathLink, LPSTR description);  

    // Pidl compares (so that they can be ordered)
    //
    bool operator==(const TShellItem& rhs) const;
    bool operator!=(const TShellItem& rhs) const;
    bool operator<(const TShellItem& rhs) const;
    bool operator<=(const TShellItem& rhs) const;
    bool operator>(const TShellItem& rhs) const;
    bool operator>=(const TShellItem& rhs) const;

    // Folder Only Functions
    // EnumObjects is called by TShellItemIterator
    //
    void EnumObjects(IEnumIDList** iface, HWND windowOwner = 0,
                     const int kind = -1) const;
    // Select a Foler under this TShellItem
    //
    bool BrowseForFolder(TCreateStruct& cs, HWND windowOwner = 0,
                         const char* title = 0, const UINT flags = 0,
                         int* image = 0, const bool includeStatus = false,
                         BFFCALLBACK func = 0, const LPARAM param = 0) const;

    // Parse a display name into a TShellItem (actually, into a TCreateStruct)
    //
    HRESULT ParseDisplayName(TCreateStruct& cs, const char* displayName,
                             ulong* eaten = 0, HWND windowOwner = 0,
                             ulong* attrib = 0) const;
  protected:
    // CompareIDs is used by the pidl compare functions above
    //
    short CompareIDs(const TShellItem& rhs) const;
    void  EnforceValidity() const;
    void  RetrieveIShellFolder() const;
    bool  HaveSameParent(const TShellItem& other) const;
    bool  GetAttribute(const TAttribute at, const bool validateCachedInfo) const;
  protected_data:
    TPidl                 Pidl;
    TComRef<IShellFolder> ParentFolder;
};

//
// class TShellItemIterator
// ~~~~~ ~~~~~~~~~~~~~~~~~~
//
class TShellItemIterator: public TComRef<IEnumIDList> {
  public:
    // Used by TShellItemIterator::TShellItemIterator(const TShellItem& folder,
    // HWND windowOwner = 0, const UINT kind = Folders | NonFolders)
    // See MS doc for SHCONTF for more information, Programmer's Guide to
    // MS Windows 95, MS Press, p. 213.
    enum TIncludeKind { 
      Folders         = SHCONTF_FOLDERS,
      NonFolders      = SHCONTF_NONFOLDERS,
      HiddenAndSystem = SHCONTF_INCLUDEHIDDEN
    };

    // constructor for TShellItemIterator
    //
    TShellItemIterator(const TShellItem& folder, HWND windowOwner = 0,
                       const int kind = Folders | NonFolders);
    TShellItemIterator(const TShellItemIterator& source);

    // Assignment operator
    //
    TShellItemIterator& operator= (const TShellItemIterator& source);

    // True if iterator is still valid
    //
    bool Valid() const;

    // Get number of TShellItems in the list
    //
    long GetCount() const;

    // Get next item, previous item, item at index, and current item
    //
    TShellItem::TCreateStruct operator ++ ();
    TShellItem::TCreateStruct operator ++ (int);
    TShellItem::TCreateStruct operator -- ();
    TShellItem::TCreateStruct operator -- (int);
    TShellItem::TCreateStruct operator [] (const long index);
    TShellItem::TCreateStruct Current();

    // Skip count items
    //
    void Skip(const ulong count);

    // Reset list
    //
    void Reset();

  protected:
    void Next();
    void EnforceValidInterface() const;

  protected_data:
    long                  Index;
    TPidl                 Pidl;
    TComRef<IShellFolder> Folder;
    operator IEnumIDList**();
};

//
// class TXShell
// ~~~~~ ~~~~~~~
// Base Shell exception class. Handles all TShellItem and related class exceptions
//
class _OWLCLASS_RTL TXShell: public TXOwl {
  public:
    // Constructor for TXShell
    //
    TXShell(uint resId = IDS_SHELLFAILURE, HANDLE handle = 0);

    // Clone a TXShell
    //
#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXShell* Clone();
#endif
    // Throw an exception
    //
    void Throw();

    // Construct a TXShell exception from scratch, and throw it.
    //
    static void Raise(uint resId = IDS_SHELLFAILURE, HANDLE handle = 0);

    // Check an HRESULT and throw a TXShell if not SUCCEEDED(hr)
    //
    static void Check(HRESULT hr, uint resId = IDS_SHELLFAILURE, HANDLE handle = 0);
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

// Default constructor for TShellMalloc.  For more info, see MS doc for
//   SHGetMalloc (Prog. Guide to MS Win95, p. 208)
//
inline TShellMalloc::TShellMalloc()
{
  HRESULT hr = ::SHGetMalloc(*this);
  TXShell::Check(hr, IDS_SHGETMALLOCFAIL);
}

// TShellMalloc constructor to construct from TComRef<IMalloc>
//
inline TShellMalloc::TShellMalloc(const TComRef<IMalloc>& source)
                    :TComRef<IMalloc>(source)
{
}

// TShellMalloc copy constructor
//
inline TShellMalloc::TShellMalloc(const TShellMalloc& source)
                    :TComRef<IMalloc>(source)
{
}

// TShellMalloc assignment operator (from TComRef<IMalloc>)
//
inline TShellMalloc& 
TShellMalloc::operator =(const TComRef<IMalloc>& source)
{
  if (&source != this)
    TComRef<IMalloc>::operator=(source);
  return *this;
}

// TShellMalloc assignment operator (from another TShellMalloc)
//
inline TShellMalloc& 
TShellMalloc::operator =(const TShellMalloc& source)
{
  if (&source != this)
    TComRef<IMalloc>::operator=(source);
  return *this;
}

// Default constructor for TExtractIcon
//
inline TExtractIcon::TExtractIcon(IExtractIcon* iface)
                    :TComRef<IExtractIcon>(iface)
{
}

// TExtractIcon constructor to construct from TComRef<IExtractIcon>
//
inline TExtractIcon::TExtractIcon(const TComRef<IExtractIcon>& source)
                    :TComRef<IExtractIcon>(source)
{
}

// TExtractIcon copy constructor
//
inline TExtractIcon::TExtractIcon(const TExtractIcon& source)
                    :TComRef<IExtractIcon>(source)
{
}

// TExtractIcon assignment operator (from TComRef<IExtractIcon>)
//
inline TExtractIcon& 
TExtractIcon::operator =(const TComRef<IExtractIcon>& source)
{
  if (&source != this)
    TComRef<IExtractIcon>::operator=(source);
  return *this;
}

// TExtractIcon assignment operator (from another TExtractIcon)
//
inline TExtractIcon& 
TExtractIcon::operator =(const TExtractIcon& source)
{
  if (&source != this)
    TComRef<IExtractIcon>::operator=(source);
  return *this;
}

// Default constructor for TContextMenu
//
inline TContextMenu::TContextMenu(IContextMenu* iface)
                    :TComRef<IContextMenu>(iface)
{
}

// TContextMenu constructor to construct from TComRef<IContextMenu>
//
inline TContextMenu::TContextMenu(const TComRef<IContextMenu>& source)
                    :TComRef<IContextMenu>(source)
{
}

// TContextMenu copy constructor
//
inline TContextMenu::TContextMenu(const TContextMenu& source)
                    :TComRef<IContextMenu>(source)
{
}

// TContextMenu assignment operator (from TComRef<IContextMenu>)
//
inline TContextMenu& 
TContextMenu::operator =(const TComRef<IContextMenu>& source)
{
  if (&source != this)
    TComRef<IContextMenu>::operator=(source);
  return *this;
}

// TContextMenu assignment operator (from another TContextMenu)
//
inline TContextMenu& 
TContextMenu::operator = (const TContextMenu& source)
{
  if (&source != this)
    TComRef<IContextMenu>::operator=(source);
  return *this;
}

// Default constructor for TDataObject
//
inline TDataObject::TDataObject(IDataObject* iface)
:
  TComRef<IDataObject>(iface)
{
}

// TDataObject constructor to construct from TComRef<IDataObject>
//
inline TDataObject::TDataObject(const TComRef<IDataObject>& source)
                   :TComRef<IDataObject>(source)
{
}

// TDataObject copy constructor
//
inline TDataObject::TDataObject(const TDataObject& source)
                   :TComRef<IDataObject>(source)
{
}

// TDataObject assignment operator (from TComRef<IDataObject>)
//
inline TDataObject& 
TDataObject::operator =(const TComRef<IDataObject>& source)
{
  if (&source != this)
    TComRef<IDataObject>::operator=(source);
  return *this;
}

// TDataObject assignment operator (from another TDataObject)
//
inline TDataObject& 
TDataObject::operator =(const TDataObject& source)
{
  if (&source != this)
    TComRef<IDataObject>::operator=(source);
  return *this;
}

// Default constructor for TDropTarget
//
inline TDropTarget::TDropTarget(IDropTarget* iface)
                   :TComRef<IDropTarget>(iface)
{
}

// TDropTarget constructor to construct from TComRef<IDropTarget>
//
inline TDropTarget::TDropTarget(const TComRef<IDropTarget>& source)
                   :TComRef<IDropTarget>(source)
{
}

// TDropTarget copy constructor
//
inline TDropTarget::TDropTarget(const TDropTarget& source)
                   :TComRef<IDropTarget>(source)
{
}

// TDropTarget assignment operator (from TComRef<IDropTarget>)
//
inline TDropTarget& 
TDropTarget::operator =(const TComRef<IDropTarget>& source)
{
  if (&source != this)
    TComRef<IDropTarget>::operator=(source);
  return *this;
}

// TDropTarget assignment operator (from another TDropTarget)
//
inline TDropTarget& 
TDropTarget::operator =(const TDropTarget& source)
{
  if (&source != this)
    TComRef<IDropTarget>::operator=(source);
  return *this;
}

// Check to see if TPidl represents an ITEMIDLIST (return true if it does not)
//
inline TPidl::operator !() const
{
  return Pidl == 0;
}

// Return next item id (in the list)
//
inline ITEMIDLIST* 
TPidl::Next(ITEMIDLIST* pidl)
{
  return REINTERPRET_CAST(ITEMIDLIST*, REINTERPRET_CAST(char*, pidl) + pidl->mkid.cb);
}

// TPidl copy constructor
//
inline TPidl::TPidl(const TPidl& source)
             :Pidl(source.CopyPidl())
{
}

// Construct a TPidl from an ITEMIDLIST* (pidl)
//
inline TPidl::TPidl(ITEMIDLIST* pidl)
             :Pidl(pidl)
{
}

// TPidl assignement operator (from another TPidl)
//
inline TPidl& 
TPidl::operator =(const TPidl& source)
{
  if (&source == this)
    return *this;
  Pidl = source.CopyPidl();
  return *this;
}

// TPidl assignement operator (from an ITEMIDLIST* (pidl))
//
inline TPidl& 
TPidl::operator =(ITEMIDLIST* pidl)
{
  FreePidl();
  Pidl = pidl;
  return *this;
}

// TPidl destructor
//
inline TPidl::~TPidl()
{
  FreePidl();
}

// use TPidl in place of ITEMIDLIST* (pidl)
//
inline TPidl::operator const ITEMIDLIST*() const
{
  return Pidl;
}

// use TPidl in place of const ITEMIDLIST** (pointer to pidl) (const)
//
inline TPidl::operator const ITEMIDLIST **() const
{
  return CONST_CAST(const ITEMIDLIST**, &Pidl);
}

// Used to set the ITEMIDLIST*
//
inline TPidl::operator ITEMIDLIST**()
{
  if (Pidl)
    FreePidl();
  return &Pidl;
}

// Return true if the TShellItem represents an item in the namespace
//
inline bool TShellItem::Valid() const
{
  return !!Pidl && !!ParentFolder;
}

// Attributes - Capabilties

// Return true if the TShellItem represents an item that can be copied
//
inline bool TShellItem::CanBeCopied(const bool validateCachedInfo) const
{
  return GetAttribute(atCanBeCopied, validateCachedInfo);
}

// Return true if the TShellItem represents an item that can be deleted
//
inline bool TShellItem::CanBeDeleted(const bool validateCachedInfo) const
{
  return GetAttribute(atCanBeDeleted, validateCachedInfo);
}

// Return true if the TShellItem represents an item for which a shortcut can
// be created
//
inline bool TShellItem::CanCreateShortcut(const bool validateCachedInfo) const
{
  return GetAttribute(atCanCreateShortcut, validateCachedInfo);
}

// Return true if the TShellItem represents an item that can be moved
//
inline bool TShellItem::CanBeMoved(const bool validateCachedInfo) const
{
  return GetAttribute(atCanBeMoved, validateCachedInfo);
}

// Return true if the TShellItem represents an item that can be renamed
//
inline bool TShellItem::CanBeRenamed(const bool validateCachedInfo) const
{
  return GetAttribute(atCanBeRenamed, validateCachedInfo);
}

// Return true if the TShellItem represents an item is a drop target
//
inline bool TShellItem::IsADropTarget(const bool validateCachedInfo) const
{
  return GetAttribute(atIsADropTarget, validateCachedInfo);
}

// Return true if the TShellItem represents an item that has a property sheet
//
inline bool TShellItem::HasAPropertySheet(const bool validateCachedInfo) const
{
  return GetAttribute(atHasAPropertySheet, validateCachedInfo);
}

// Attributes - Display

// Return true if the TShellItem represents an item that should be displayed
// as ghosted
//
inline bool TShellItem::DisplayGhosted(const bool validateCachedInfo) const
{
  return GetAttribute(atDisplayGhosted, validateCachedInfo);
}

// Return true if the TShellItem represents an item that is a shortcut
//
inline bool TShellItem::IsShortcut(const bool validateCachedInfo) const
{
  return GetAttribute(atIsShortcut, validateCachedInfo);
}

// Return true if the TShellItem represents an item that is read only
//
inline bool TShellItem::IsReadOnly(const bool validateCachedInfo) const
{
  return GetAttribute(atIsReadOnly, validateCachedInfo);
}

// Return true if the TShellItem represents an item that is shared
//
inline bool TShellItem::IsShared(const bool validateCachedInfo) const
{
  return GetAttribute(atIsShared, validateCachedInfo);
}

// Attributes - Contents

// Return true if the TShellItem represents an item that contains a subfolder
//
inline bool TShellItem::ContainsSubFolder(const bool validateCachedInfo) const
{
  return GetAttribute(atContainsSubFolder, validateCachedInfo);
}

// Attributes - Miscellaneous

// Return true if the TShellItem represents an item that contains a file system folder
//
inline bool TShellItem::ContainsFileSystemFolder(const bool validateCachedInfo) const
{
  return GetAttribute(atContainsFileSystemFolder, validateCachedInfo);
}

// Return true if the TShellItem represents an item that is part of the file system
//
inline bool TShellItem::IsPartOfFileSystem(const bool validateCachedInfo) const
{
  return GetAttribute(atIsPartOfFileSystem, validateCachedInfo);
}

// Return true if the TShellItem represents an item that is a folder
//
inline bool TShellItem::IsFolder(const bool validateCachedInfo) const
{
  return GetAttribute(atIsFolder, validateCachedInfo);
}

// Return true if the TShellItem represents an item that can be removed
//
inline bool TShellItem::CanBeRemoved(const bool validateCachedInfo) const
{
  return GetAttribute(atCanBeRemoved, validateCachedInfo);
}

// TShellItem::TCreateStruct default constructor
//
inline TShellItem::TCreateStruct::TCreateStruct()
{
}

// TShellItem::TCreateStruct constructor (takes a TPidl and TComRef<IShellFolder>
//
inline TShellItem::TCreateStruct::TCreateStruct(
                            TPidl& pidl, TComRef<IShellFolder>& parentFolder)
:
  Pidl(pidl),
  ParentFolder(parentFolder)
{
}

// TShellItem::TCreateStruct copy constructor
//
inline TShellItem::TCreateStruct::TCreateStruct(const TCreateStruct& source)
:
Pidl(source.Pidl),
ParentFolder(source.ParentFolder)
{
}

// use TShellItem in place of an ITEMIDLIST* (pidl)
//
inline TShellItem::operator ITEMIDLIST*()
{
  return Pidl;
}

// Get a TShellItem's TPidl
//
inline TPidl TShellItem::GetPidl() const
{
  return Pidl;  // Return a copy
}

// Compare sort order of this TShellItem equals another TShellItem
//
inline bool TShellItem::operator ==(const TShellItem& rhs) const
{
  return CompareIDs(rhs) == 0;
}

// Compare sort order of this TShellItem is less than another TShellItem
//
inline bool TShellItem::operator <(const TShellItem& rhs) const
{
  return CompareIDs(rhs) < 0;
}

// Compare sort order of this TShellItem is greater than another TShellItem
//
inline bool TShellItem::operator >(const TShellItem& rhs) const
{
  return CompareIDs(rhs) > 0;
}

// Compare sort order of this TShellItem is not equal to another TShellItem
//
inline bool TShellItem::operator !=(const TShellItem& rhs) const
{
  return !operator==(rhs);
}

// Compare sort order of this TShellItem <= another TShellItem
//
inline bool TShellItem::operator <=(const TShellItem& rhs) const
{
  return !operator>(rhs);
}

// Compare sort order of this TShellItem >= another TShellItem
//
inline bool TShellItem::operator >=(const TShellItem& rhs) const
{
  return !operator<(rhs);
}

// HaveSameParent returns true if this TShellItem and other TShellItem have the
// same immediate parent folder.
//
inline bool TShellItem::HaveSameParent(const TShellItem& other) const
{
  TShellItem* constThis = CONST_CAST(TShellItem*, this);
  TShellItem* constOther = CONST_CAST(TShellItem*, &other);

  return STATIC_CAST(IShellFolder*, constThis->ParentFolder) !=
         STATIC_CAST(IShellFolder*, constOther->ParentFolder);
}

// Return true if TShellItemIterator is valid and not at end of list of items
//
inline bool TShellItemIterator::Valid() const
{
  return Index != -1;
}

#endif  // OWL_SHELLITM_H

