//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.20  $
//
// General Registry access & registration implementation
//   TRegKey, TRegValue, TRegKeyIterator, TRegValueIterator
//   TXRegistry
//   TRegItem, TRegList, TRegLink - associative array of localizable string parameters
//   OC registry functions
//----------------------------------------------------------------------------
#if !defined(WINSYS_REGISTRY_H)
#define WINSYS_REGISTRY_H

#if !defined(WINSYS_EXBASE_H)
# include <winsys/exbase.h>
#endif
#if !defined(WINSYS_WSYSINC_H)
# include <winsys/wsysinc.h>
#endif
#if !defined(WINSYS_LCLSTRNG_H)
# include <winsys/lclstrng.h>
#endif
#if !defined(SERVICES_MEMORY_H)
# include <services/memory.h>
#endif
#if !defined(SERVICSE_CHECKS_H)
# include <services/checks.h>
#endif
#if defined(BI_PLAT_WIN16)
# if !defined(_INC_SHELLAPI)
#   include <shellapi.h>
# endif
# if !defined(_STORAGE_H_)
#   include <storage.h>
# endif
#endif
#if defined(BI_PLAT_WIN16)
  typedef uint32 REGSAM;
  typedef uint32 SECURITY_INFORMATION;
  typedef void*  PSECURITY_DESCRIPTOR;
# define KEY_ALL_ACCESS 0    // Value doesn't matter since never seen
#endif

class _EXPCLASS istream;
class _EXPCLASS ostream;

//----------------------------------------------------------------------------
// Direct registry access classes. Can read & iterate as well as create and
// write keys and value-data pairs
//

//
// class TRegKey
// ~~~~~ ~~~~~~~
// Encapsulation of a registration key
//
class TRegKeyIterator;
class TRegKey {
  public:
    typedef HKEY THandle;

    // Enumeration used to specify whether a key should be created (or 
    // simply opened).
    //
    enum TCreateOK {
      CreateOK,             // Create key if it does not exist
      NoCreate              // Don't create, simply open
    };

    // Create or open a key given a base key and a subkeyname. Security
    // information is ignored in 16bit (and under Win95)
    // Can also provide an ok-to-create or open-only indicator.
    //
    TRegKey(THandle baseKey,
            const char far* keyName,
            REGSAM samDesired = KEY_ALL_ACCESS,
            TCreateOK createOK = CreateOK);

    // Construct a key give the current position of a regkey iterator
    //
    TRegKey(const TRegKeyIterator& iter, REGSAM samDesired = KEY_ALL_ACCESS);

    // Contruct a key that is an alias to an existing HKEY
    //
    TRegKey(THandle aliasKey, bool shouldClose=false, const char far* keyName = 0);
   ~TRegKey();

    operator THandle() const;

    long DeleteKey(const char far* subKeyName);
    long NukeKey(const char far* subKeyName);
    long Flush() const;

    long GetSecurity(SECURITY_INFORMATION secInf, PSECURITY_DESCRIPTOR secDesc,
                     uint32* secDescSize);
    long SetSecurity(SECURITY_INFORMATION secInf, PSECURITY_DESCRIPTOR secDesc);

    // Saving & loading of this key & subKeys
    //
    long Save(const char far* fileName);
    long LoadKey(const char far* subKeyName, const char far* fileName);
    long ReplaceKey(const char far* subKeyName, const char far* newFileName,
                    const char far* oldFileName);
    long Restore(const char far* fileName, uint32 options=0);
    long UnLoadKey(const char far* subKeyName);

    //long NotifyChangeKeyValue();

    // Some of these are initialized at ctor
    //
    long QueryInfo(char far* class_, uint32* classSize, uint32* subkeyCount,
                   uint32* maxSubkeySize, uint32* maxClassSize,
                   uint32* valueCount, uint32* maxValueName,
                   uint32* maxValueData, uint32* secDescSize,
                   FILETIME far* lastWriteTime);

    const char far* GetName() const;
    uint32 GetSubkeyCount() const;
    uint32 GetValueCount() const;

    // Special predefined root keys
    //
    static TRegKey ClassesRoot;
    static TRegKey ClassesRootClsid;  // Commonly used subkey
    static TRegKey CurrentUser;
    static TRegKey LocalMachine;
    static TRegKey Users;
    static TRegKey CurrentConfig;
    static TRegKey DynData;
    static TRegKey PerformanceData;

    //-------

    // Friend iterators only...?
    //
    long EnumKey(int index, char far* subKeyName, int subKeyNameSize) const;

    // Older, nameless subkey+(Default) value access
    //
    long SetDefValue(const char far* subkeyName, uint32 type,
                     const char far* data, uint32 dataSize);
    long QueryDefValue(const char far* subkeyName, char far* data,
                       uint32* dataSize) const;

    // Newer, named value set & get functions. Subkeys must be opened
    //
    long SetValue(const char far* valName, uint32 type, const uint8* data,
                  uint32 dataSize) const;
    long SetValue(const char far* valName, uint32 data) const;
    long QueryValue(const char far* valName, uint32* type, uint8* data,
                    uint32* dataSize) const;
    long DeleteValue(const char far* valName) const;

    // Friend iterators only...?
    //
    long EnumValue(int index, char far* valueName, uint32& valueNameSize,
                   uint32* type = 0, uint8* data = 0, uint32* dataSize = 0) const;

  protected:
    THandle   Key;          // This Key's Handle
    char far* Name;         // This Key's Name
    uint32    SubkeyCount;  // Number of subkeys
    uint32    ValueCount;   // Number of value entries
    bool      ShouldClose;  // Should this key be closed on destruction
};


//
// class TRegValue
// ~~~~~ ~~~~~~~~~
// Encapsulation of a value-data entry within one registration key.
//
class TRegValueIterator;
class TRegValue {
  public:
    TRegValue(const TRegKey& key, const char far* name);
    TRegValue(const TRegValueIterator& iter);
   ~TRegValue();

    const char far* GetName() const;
    const uint32 GetDataType() const;
    const uint32 GetDataSize() const;
    const uint8* GetData() const;
    operator uint32() const;
    operator const char far*() const;

    // Set the data and possibly type of this value
    //
    long Set(uint32 type, uint8* data, uint32 dataSize);
    long Set(uint32 data);
    long Set(const char far* data);
    void operator =(uint32 v);
    long Delete();
    void operator =(const char far* v);

    void RetrieveOnDemand() const;

  private:
    const TRegKey&  Key;      // Key that this value lives in
    const char far* Name;     // Working name pointer
    char far*       AName;    // Allocated space for name if needed

    // Data information. 
    uint32          DataType; // Type code for value data
    mutable uint8*  Data;     // Value data itself, allocated
    uint32          DataSize; // Size in bytes of Data
};

//
// class TRegKeyIterator
// ~~~~~ ~~~~~~~~~~~~~~~
// Iterator for walking thru the subkeys of a key
//
class TRegKeyIterator {
  public:
    TRegKeyIterator(const TRegKey& key);

    operator bool();

    uint32 operator ++();
    uint32 operator ++(int);
    uint32 operator --();
    uint32 operator --(int);
    uint32 operator [](int index);

    int             Current() const;
    const TRegKey&  BaseKey() const;

    void Reset();

  private:
    const TRegKey& Key;
    int            Index;
};

//
// class TRegValueIterator
// ~~~~~ ~~~~~~~~~~~~~~~~~
// Iterator for walking thru the values of a key
//
class TRegValueIterator {
  public:
    TRegValueIterator(const TRegKey& regKey);

    operator bool();

    uint32 operator ++();
    uint32 operator ++(int);
    uint32 operator --();
    uint32 operator --(int);
    uint32 operator [](int index);

    int            Current() const;
    const TRegKey& BaseKey() const;

    void Reset();

  private:
    const TRegKey& Key;
    int            Index;
};

//----------------------------------------------------------------------------

//
// class TXRegistry
// ~~~~~ ~~~~~~~~~~
// Registry related exception class
//
class TXRegistry : public TXBase {
  public:
    TXRegistry(const char* msg, const char* key);
    TXRegistry(const TXRegistry& copy);

    static void Check(long stat, const char* key);

    const char* Key;
};


//----------------------------------------------------------------------------
// Registration parameter structures and formatting functions
//

//
// class TRegFormatHeap
// ~~~~~ ~~~~~~~~~~~~~~
// Used internally to provide buffers for formating registration strings
//
class TRegFormatHeap {
  public:
    TRegFormatHeap();
   ~TRegFormatHeap();
    char*  Alloc(int spaceNeeded);
  private:
    struct TBlock {
      TBlock*  Next;     // Next heap in chain
      char     Data[1];  // Allocated memory starts here
    };
    TBlock* Head;
};

//
// struct TRegItem
// ~~~~~~ ~~~~~~~~
// A single registration list entry
//
struct TRegItem {
  char*         Key;           // Non-localized parameter or registry subkey
  TLocaleString Value;         // Localizable value for parameter or subkey

  // Used privately by REGFORMAT, REGSTATUS macros
  //
  static char* RegFormat(int f, int a, int t, int d, TRegFormatHeap& heap);
  static char* RegFormat(const char* f, int a, int t, int d, TRegFormatHeap& heap);
  static char* RegFlags(long flags, TRegFormatHeap& heap);
  static char* RegVerbOpt(int mf, int sf, TRegFormatHeap& heap);
  static void  OverflowCheck();
};

//
// class TRegList
// ~~~~~ ~~~~~~~~
// A registration parameter table, composed of a list of TRegItems
//
class TRegList {
  public:
    TRegList(TRegItem* list);
    const char* Lookup(const char* key,
                       TLangId lang = TLocaleString::UserDefaultLangId);
    TLocaleString& LookupRef(const char* key);
    const char* operator[](const char* key);

    TRegItem* Items;
};

//
// class TRegLink
// ~~~~~ ~~~~~~~~
// Registration link node, holding a pointer to a TRegList. Can be one in a
// linked list.
//
class _WSYSCLASS TRegLink {
  public:
    TRegLink(TRegList& regList, TRegLink*& head);
   ~TRegLink();
    TRegLink*   GetNext() const;
    TRegList&   GetRegList() const;

    static void AddLink(TRegLink*& head, TRegLink& newLink);
    static bool RemoveLink(TRegLink*& head, TRegLink& remLink);

  protected:
    TRegLink();           // Derived class must fill in ptrs
    TRegLink*  Next;      // Next RegLink
    TRegList*  RegList;   // Pointer to registration parameter table
};

//
// Registration parameter table macro definitions
//
#define BEGIN_REGISTRATION(regname) extern TRegItem regname##_list[]; \
                                    extern TRegFormatHeap __regHeap; \
                                    TRegList regname(regname##_list); \
                                    static TRegItem regname##_list[] = {
#define END_REGISTRATION {0,{0}} };

#define REGDATA(var,val) {#var, {val}},
#define REGXLAT(var,val) {#var, {AUTOLANG_XLAT val}},
#define REGITEM(key,val) {" " key, {val}},
#define REGFORMAT(i,f,a,t,d) {"format" #i,{TRegItem::RegFormat(f,a,t,d,__regHeap)}},
#define REGSTATUS(a,f) {"aspect" #a, {TRegItem::RegFlags(f,__regHeap)}},
#define REGVERBOPT(v,mf,sf) {#v "opt",{TRegItem::RegVerbOpt(mf,sf,__regHeap)}},
#define REGICON(i) {"iconindex",{TRegItem::RegFlags(i,__regHeap)}},
#define REGDOCFLAGS(i) {"docflags",{TRegItem::RegFlags(i,__regHeap)}},

//
// Buffer size is no longer needed, use the macro below
//
#define REGISTRATION_FORMAT_BUFFER(n) \
  TRegFormatHeap __regHeap;

#define REGISTRATION_FORMAT_HEAP \
  TRegFormatHeap __regHeap;

//----------------------------------------------------------------------------
// Clipboard and registry data transfer format definitions
//

const int ocrVerbLimit   = 8;  // maximum number of verbs registered per class
const int ocrFormatLimit = 8;  // maximum number of data formats per class

//
// Format: standard clipboard numeric format, or name of custom format
//
enum ocrClipFormat {
  ocrText           =  1,  // CF_TEXT
  ocrBitmap         =  2,  // CF_BITMAP
  ocrMetafilePict   =  3,  // CF_METAFILEPICT
  ocrSylk           =  4,  // CF_SYLK
  ocrDif            =  5,  // CF_DIF
  ocrTiff           =  6,  // CF_TIFF
  ocrOemText        =  7,  // CF_OEMTEXT
  ocrDib            =  8,  // CF_DIB
  ocrPalette        =  9,  // CF_PALETTE
  ocrPenData        = 10,  // CF_PENDATA
  ocrRiff           = 11,  // CF_RIFF
  ocrWave           = 12,  // CF_WAVE
  ocrUnicodeText    = 13,  // CF_UNICODETEXT  Win32 only
  ocrEnhMetafile    = 14,  // CF_ENHMETAFILE  Win32 only
};
#define ocrRichText          "Rich Text Format"
#define ocrEmbedSource       "Embed Source"
#define ocrEmbeddedObject    "Embedded Object"
#define ocrLinkSource        "Link Source"
#define ocrObjectDescriptor  "Object Descriptor"
#define ocrLinkSrcDescriptor "Link Source Descriptor"

//
// Aspect: view types supported by transfer
//
enum ocrAspect {
  ocrContent   = 1,  // DVASPECT_CONTENT    normal display representation
  ocrThumbnail = 2,  // DVASPECT_THUMBNAIL  picture appropriate for browser
  ocrIcon      = 4,  // DVASPECT_ICON       iconized representation of object
  ocrDocPrint  = 8,  // DVASPECT_DOCPRINT   print preview representation
};

//
// Medium: means of data transfer
//
enum ocrMedium {
  ocrNull       = 0,
  ocrHGlobal    = 1,  // TYMED_HGLOBAL  global memory handle
  ocrFile       = 2,  // TYMED_FILE     data as contents of file
  ocrIStream    = 4,  // TYMED_ISTREAM  instance of an IStream object
  ocrIStorage   = 8,  // TYMED_ISTORAGE streams within an instance of IStorage
  ocrGDI        = 16, // TYMED_GDI      GDI object in global handle
  ocrMfPict     = 32, // TYMED_MFPICT   CF_METAFILEPICT containing global handle
  ocrStaticMed  = 1024 // OLE 2 static object
};

//
// Direction: transfer directions supported
//
enum ocrDirection {
  ocrGet    = 1,
  ocrSet    = 2,
  ocrGetSet = 3,
};

//----------------------------------------------------------------------------
// Miscellaneous registry definitions
//

//
// IOleObject miscellaneous status flags, defined for each or all aspects
//
enum ocrObjectStatus {
  ocrRecomposeOnResize           = 1,   // request redraw on container resize
  ocrOnlyIconic                  = 2,   // only useful context view is Icon
  ocrInsertNotReplace            = 4,   // should not replace current select.
  ocrStatic                      = 8,   // object is an OLE static object
  ocrCantLinkInside              = 16,  // should not be the link source
  ocrCanLinkByOle1               = 32,  // only used in OBJECTDESCRIPTOR
  ocrIsLinkObject                = 64,  // set by OLE2 link for OLE1 compat.
  ocrInsideOut                   = 128, // can be activated concurrently
  ocrActivateWhenVisible         = 256, // hint to cntnr when ocrInsideOut set
  ocrRenderingIsDeviceIndependent= 512, // no decisions made based on target
  ocrNoSpecialRendering          = 512, // older enum for previous entry
};

//
// IOleObject verb menu flags
//
enum ocrVerbMenuFlags {
  ocrGrayed      = 1,   // MF_GRAYED
  ocrDisabled    = 2,   // MF_DISABLED
  ocrChecked     = 8,   // MF_CHECKED
  ocrMenuBarBreak= 32,  // MF_MENUBARBREAK
  ocrMenuBreak   = 64,  // MF_MENUBAR
};

//
// IOleObject verb attribute flags
//
enum ocrVerbAttributes {
  ocrNeverDirties      = 1,   // verb can never cause object to become dirty
  ocrOnContainerMenu   = 2,   // only useful context view is Icon
};

//
// Entries for <usage> registration parameter, class factory registration mode
//
#define ocrSingleUse     "1"  // single client per instance
#define ocrMultipleUse   "2"  // multiple clients per instance
#define ocrMultipleLocal "3"  // multiple clients, separate inproc server

//----------------------------------------------------------------------------
// High-level table based registration support
//

//
// class TRegTemplateList
// ~~~~~ ~~~~~~~~~~~~~~~~
// List of parameterized template strings that represent the actual entries to
// be registered. List is indexed from 1 for used with param-list template
// activation strings. See TRegParamList below.
//
class TRegTemplateList {
  public:
    TRegTemplateList(TRegKey& basekey, const char* list[]);
   ~TRegTemplateList();

    int      GetCount() const;
    TRegKey& GetBaseKey();

    const char* operator [](int i);

    // Enable/Disable and activate templates
    //
    void  DisableAll();
    void  EnableAll();
    void  Enable(int i);
    void  Enable(const char* set);

    void  Activate(int i);
    void  Activate(const char* set);

    bool  IsActive(int i) const;

  private:
    TRegKey&     BaseKey;       // Registry key that these templates are based
    const char** List;          // List of templates
    int          Count;         // # of templates in list
    char*        EnabledFlags;  // Which templates are currently enabled/active
};

//
// class TRegParamList
// ~~~~~ ~~~~~~~~~~~~~
// A list of param entries for use as an intermediate between a TRegList and
// the actual template list used to generate the registration. Provides default
// values in 'Default', and tags required templates using octal char entries in
// 'TemplatesNeeded'
//
class TRegParamList {
  public:
    struct TEntry {
      char*  Param;    // Substituted parameter name
      char*  Default;  // Default value, 0 if no default & param is required
      char*  TemplatesNeeded; // Octal string list of template indices to activate
    };

    TRegParamList(TEntry* list);
   ~TRegParamList();

    int Find(const char* param);   // Associative lookup of value by param
    int GetCount() const;

    TEntry& operator [](int i);

    const char*& Value(int i);
    void   ResetDefaultValues();

  private:
    TEntry*        List;
    int            Count;
    const char**   Values;
};

//
// class TRegSymbolTable
// ~~~~~ ~~~~~~~~~~~~~~~
// High level symbol-based registry entry manipulation
//
class TRegSymbolTable {
  public:
    TRegSymbolTable(TRegKey& basekey, const char* tplList[], TRegParamList::TEntry* paramList);

    void Init(char* filter);
    void UpdateParams(TLangId lang, TRegItem* item);
    void StreamOut(TRegItem* item, ostream& out);
//    void StreamIn(TRegItem* item, istream& in);

    TRegTemplateList Templates;
    TRegParamList    Params;
    int              UserKeyCount;
};

//
// class TRegistry
// ~~~~~ ~~~~~~~~~
// High level stream & list access to registry
//
class TRegistry {
  public:
    static int  Validate(TRegKey& baseKey, istream& in);  // Returns number of mismatched entries
    static void Update(TRegKey& baseKey, istream& in);   // Writes lines to registry
#pragma pack(push,4)
    struct TUnregParams {
      char     Prepend;  // Optional char to prepend to key before removing
      char*    Name;     // Name of param
      TRegKey* BaseKey;  // Key that that the param is based upon
    };
#pragma pack(pop)
    static int  Unregister(TRegList& regInfo, TUnregParams* params, TRegItem* overrides = 0);
};

//----------------------------------------------------------------------------
// TRegKey inlines
//

//
// Return the HANDLE identifying this registry key.
//
inline
TRegKey::operator TRegKey::THandle() const
{
  return Key;
}

//
// Enumerate the subkeys of this registry key
//
inline long
TRegKey::EnumKey(int index, char far* subKeyName, int subKeyNameSize) const
{
  return ::RegEnumKey(Key, index, subKeyName, subKeyNameSize);
  //::RegEnumKeyEx(); ??
}

//
// Delete the specified subkey of this registry key
//
inline long
TRegKey::DeleteKey(const char far* subKeyName)
{
  return ::RegDeleteKey(Key, subKeyName);
}

//
// Write the attribute of this key in the registry
// Note: 32 bit only
//
inline long
TRegKey::Flush() const
{
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  return ::RegFlushKey(Key);
#endif
}

//
// Retrieve a copy of the security descriptor protecting this registry key. 
// Note: 32 bit only
//
inline long
TRegKey::GetSecurity(SECURITY_INFORMATION secInf, PSECURITY_DESCRIPTOR secDesc,
                     uint32* secDescSize)
{
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  return ::RegGetKeySecurity(Key, secInf, secDesc, secDescSize);
#endif
}

//
// Set the security descriptor of this key
// Note: 32 bit only
//
inline long
TRegKey::SetSecurity(SECURITY_INFORMATION secInf, PSECURITY_DESCRIPTOR secDesc)
{
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  return ::RegSetKeySecurity(Key, secInf, secDesc);
#endif
}

//
// Save this key and all of its subkeys and values to the specified file.
// Note: 32 bit only
//
inline long
TRegKey::Save(const char far* fileName)
{
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  return ::RegSaveKey(Key, fileName, 0/*Security*/);
#endif
}

//
// Create a subkey under HKEY_USER or HKEY_LOCAL_MACHINE and stores 
// registration information from a specified file into that subkey. This 
// registration information is in the form of a hive. A hive is a discrete 
// body of keys, subkeys, and values that is rooted at the top of the 
// registry hierarchy. A hive is backed by a single file and .LOG file. 
// Note: 32 bit only
//
inline long
TRegKey::LoadKey(const char far* subKeyName, const char far* fileName)
{
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  return ::RegLoadKey(Key, subKeyName, fileName);
#endif
}

//
// Replace the file backing this key and all its subkeys with another file, 
// so that when the system is next started, the key and subkeys will have 
// the values stored in the new file. 
// Note: 32 bit only
//
inline long
TRegKey::ReplaceKey(const char far* subKeyName, const char far* newFileName,
                    const char far* oldFileName)
{
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  return ::RegReplaceKey(Key, subKeyName, newFileName, oldFileName);
#endif
}

//
// Read the registry information in a specified file and copies it over this
// key. This registry information may be in the form of a key and multiple 
// levels of subkeys. 
// Note: 32 bit only
//
inline long
TRegKey::Restore(const char far* fileName, uint32 options)
{
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  return ::RegRestoreKey(Key, fileName, options);
#endif
}

//
// Unload this key and its subkeys from the registry. 
//
// Note: 32 bit only
inline long
TRegKey::UnLoadKey(const char far* subKeyName)
{
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  return ::RegUnLoadKey(Key, subKeyName);
#endif
}

//inline long TRegKey::NotifyChangeKeyValue() {}

//
// Return the number of subkeys attached to this key
//
inline uint32
TRegKey::GetSubkeyCount() const
{
  return SubkeyCount;
}

//
// Return the number of values attached to this key
//
inline uint32
TRegKey::GetValueCount() const
{
  return ValueCount;
}

//
// Return a string identifying this key
//
inline const char far*
TRegKey::GetName() const
{
  return Name;
}

//
// Associate a value with this key
//
inline long
TRegKey::SetValue(const char far* valName, uint32 type, const uint8* data,
                  uint32 dataSize) const
{
#if defined(BI_PLAT_WIN16)
  return ::RegSetValue(Key, 0, type, (LPCSTR)data, dataSize);
#else
  return ::RegSetValueEx(Key, valName, 0, type, data, dataSize);
#endif
}

//
// Associate a 4-byte value with this key
// Note: 32 bit only
//
inline long
TRegKey::SetValue(const char far* valName, uint32 data) const
{
#if defined(BI_PLAT_WIN16)
  return 0;  
#else
  return SetValue(valName, REG_DWORD, (uint8*)&data, sizeof data);
#endif
}

//
// Retrieve the value associated with the unnamed value for this key 
//
inline long
TRegKey::QueryValue(const char far* valName, uint32* type, uint8* data,
                    uint32* dataSize) const
{
#if defined(BI_PLAT_WIN16)
  return ::RegQueryValue(Key, 0, (LPSTR)data, (long*)dataSize);
#else
  return ::RegQueryValueEx(Key, valName, 0, type, data, dataSize);
#endif
}

//
// Remove a named value from this registry key
// Note: 32 bit only
//
inline long
TRegKey::DeleteValue(const char far* valName) const
{
#if defined(BI_PLAT_WIN16)
  return 0;
#else
  return ::RegDeleteValue(Key, valName);
#endif
}

//
// Set the default [unnamed] value associated with this key
//
inline long
TRegKey::SetDefValue(const char far* subkeyName, uint32 type,
                     const char far* data, uint32 dataSize)
{
  return ::RegSetValue(Key, subkeyName, type, data, dataSize);
}

//
// Retrieve the default [unnamed] value associated with this key
//
inline long
TRegKey::QueryDefValue(const char far* subkeyName, char far* data,
                       uint32* dataSize) const
{
  return ::RegQueryValue(Key, subkeyName, data, (long*)dataSize);
}

//
// Enumerate the values associated with this key.  Copy the value name and
// data block associated with the passed index.
// Note: 32 bit only
//
inline long
TRegKey::EnumValue(int index, char far* valueName, uint32& valueNameSize,
                   uint32* type, uint8* data, uint32* dataSize) const
{
#if defined(BI_PLAT_WIN16)
  if (valueName)
    *valueName = 0;
  return 0;
#else
  return ::RegEnumValue(Key, index, valueName, &valueNameSize, 0, type, data, dataSize);
#endif
}

//----------------------------------------------------------------------------
// TRegValue inlines
//

//
// Return a string identifying this value
//
inline const char far*
TRegValue::GetName() const
{
  return Name;
}

//
// Return the type code for the data associated with this value
//
inline const uint32
TRegValue::GetDataType() const
{
  return DataType;
}

//
// Return the size in bytes of the data associated with this value
//
inline const uint32
TRegValue::GetDataSize() const
{
  return DataSize;
}

//
// Return the data associated with this value.
//
inline const uint8*
TRegValue::GetData() const {
  RetrieveOnDemand();
  return Data;
}

//
// Return the data associated with this value as a 32bit unsigned integer
//
inline TRegValue::operator uint32() const
{
  return *(uint32*)GetData();           // Assumes dataType==REG_DWORD
}

//
// Return the data associated with this value as a const char*
//
inline TRegValue::operator const char far*() const
{
  return (const char far*)GetData();  // Assumes DataType==REG_SZ or sim.
}

//
// Set the data associated with this value
// Note: 32 bit only
//
inline long
TRegValue::Set(uint32 data)
{
#if defined(BI_PLAT_WIN16)
  return 0; 
#else
  return Set(REG_DWORD, (uint8*)&data, sizeof data);
#endif
}

//
// Set the data associated with this value
//
inline long
TRegValue::Set(const char far* data)
{
//  TString strData(data);
//  wchar_t* ustrData = strData;  
  return Set(REG_SZ, (uint8*)data, strlen(data));
}

//
// Remove this value from its associated key.
// Note: the state of this value object becomes undefined.
//
inline long
TRegValue::Delete()
{
  return Key.DeleteValue(Name);
}

//
// Set the data for this value to v
//
inline void
TRegValue::operator =(uint32 v)
{
  Set(DataType, (uint8*)&v, DataSize);
}

//
// Set the data for this value to v
//
inline void
TRegValue::operator =(const char far* v)
{
  Set(DataType, (uint8*)v, strlen(v) + 1);
}

//----------------------------------------------------------------------------
// TRegKeyIterator inlines
//

//
// Create a subkey iterator for a registration key
//
inline
TRegKeyIterator::TRegKeyIterator(const TRegKey& key)
:
  Key(key),
  Index(0)
{
}

//
// Test the validity of this iterator.  True if the iterator's
// index is greater than or equal to 0 and less than the number
// of subkeys.
//
inline
TRegKeyIterator::operator bool()
{
  return Index >= 0 && Index < int(Key.GetSubkeyCount());
}

//
// Preincrement to the next subkey
//
inline uint32
TRegKeyIterator::operator ++()
{
  return ++Index;
}

//
// Postincrement to the next subkey
//
inline uint32
TRegKeyIterator::operator ++(int)
{
  return Index++;
}

//
// Predecrement to the previous subkey
//
inline uint32
TRegKeyIterator::operator --()
{
  return --Index;
}

//
// Postdecrement to the previous subkey
//
inline uint32
TRegKeyIterator::operator --(int)
{
  return Index--;
}

//
// Set the index of the iterator to the passed value.  Return the new index.
//
inline uint32
TRegKeyIterator::operator [](int index)
{
  PRECONDITION((index >= 0) && (index < int(Key.GetSubkeyCount())));
  return Index = index;
}

//
// Return the index to the current subkey
//
inline int
TRegKeyIterator::Current() const
{
  return Index;
}

//
// Return the registration key this iterator is bound to
//
inline const TRegKey&
TRegKeyIterator::BaseKey() const
{
  return Key;
}

//
// Reset the subkey index to zero
//
inline void
TRegKeyIterator::Reset()
{
  Index = 0;
}

//----------------------------------------------------------------------------
// TRegValueIterator inlines
//

//
// Create a value iterator for a registration key
//
inline
TRegValueIterator::TRegValueIterator(const TRegKey& regKey)
:
  Key(regKey),
  Index(0)
{
}

//
// Test the validity of this iterator.  True if the iterator's
// index is greater than or equal to 0 and less than the number
// of values.
//
inline
TRegValueIterator::operator bool()
{
  return Index >= 0 && Index < int(Key.GetValueCount());
}

//
// Preincrement to the next value
//
inline uint32
TRegValueIterator::operator ++()
{
  return ++Index;
}

//
// Postincrement to the next value
//
inline uint32
TRegValueIterator::operator ++(int)
{
  return Index++;
}

//
// Predecrement to the previous value
//
inline uint32
TRegValueIterator::operator --()
{
  return --Index;
}

//
// Postdecrement to the previous value
//
inline uint32
TRegValueIterator::operator --(int)
{
  return Index--;
}

//
// Set the index of the iterator to the passed value.  Return the new index.
//
inline uint32
TRegValueIterator::operator [](int index)
{
  PRECONDITION((index >= 0) && (index < int(Key.GetValueCount())));
  return Index = index;
}

//
// Return the index to the current value
//
inline int
TRegValueIterator::Current() const
{
  return Index;
}

//
// Return the registration key this iterator is bound to
//
inline const TRegKey&
TRegValueIterator::BaseKey() const
{
  return Key;
}

//
// Reset the value index to zero
//
inline void
TRegValueIterator::Reset()
{
  Index = 0;
}


//----------------------------------------------------------------------------
// TXRegistry inlines
//

//
// Creates a registry exception object.  msg points to an error message and
// key points to the name of the registry key that ObjectComponents was
// processing when the exception occurred.
//
inline
TXRegistry::TXRegistry(const char* msg, const char* key)
:
  TXBase(msg),
  Key(key)
{
}

//
// The copy constructor constructs a new registry exception object by copying
// the one passed as copy. 
//
inline
TXRegistry::TXRegistry(const TXRegistry& src)
:
  TXBase(src),
  Key(src.Key)
{
}


//----------------------------------------------------------------------------
// TRegList inlines
//

//
// Create a registration parameter table, composed of a list of TRegItems
//
inline
TRegList::TRegList(TRegItem* list)
:
  Items(list)
{
  PRECONDITION(list);
}

//
// Return the value of the passed key as a const char*
//
inline const char*
TRegList::operator[](const char* key)
{
  PRECONDITION(key);
  return Lookup(key);
}


//----------------------------------------------------------------------------
// TRegLink inlines
//

//
// Registration link node destructor
//
inline
TRegLink::~TRegLink()
{
}

//
// Return a pointer to the next link
//
inline TRegLink*
TRegLink::GetNext() const
{
  return Next;
}

//
// Return a pointer to registration parameter table (reglist)
//
inline TRegList&
TRegLink::GetRegList() const
{
  return *RegList;
}

//
// Protected constructor where the derived class must initialize all pointers
//
inline
TRegLink::TRegLink()
:
  Next(0),
  RegList(0)
{

}


//----------------------------------------------------------------------------
// TRegTemplateList
//

//
// Return the number of templates in this list
//
inline int
TRegTemplateList::GetCount() const
{
  return Count;
}

//
// Return the registry key upon which these templates are based
//
inline TRegKey&
TRegTemplateList::GetBaseKey()
{
  return BaseKey;
}

//
// Return the template string at the passed index.
// Note: The list is indexed beginning with 1 not 0.
//
inline const char*
TRegTemplateList::operator [](int i)
{
  PRECONDITION(i > 0 && i <= Count);
  if (i <= 0 || i > Count) 
    return 0;
  else
    return List[i-1];
}

//
// Disable all templates in this list
//
inline void
TRegTemplateList::DisableAll()
{
  memset(EnabledFlags, 0x80, Count);
}

//
// Enable all templates in this list
//
inline void
TRegTemplateList::EnableAll()
{
  memset(EnabledFlags, 0x00, Count);
}

//
// Enable the template at the passed index
// Note: The list is indexed beginning with 1 not 0.
//
inline void
TRegTemplateList::Enable(int i)
{
  PRECONDITION(i > 0 && i <= Count);
  if (i > 0 && i <= Count) 
    EnabledFlags[i-1] = 0;
}

//
// Activate the template at the passed index
// Note: The list is indexed beginning with 1 not 0.
//
inline void
TRegTemplateList::Activate(int i)
{
  PRECONDITION(i > 0 && i <= Count);
  if (i > 0 && i <= Count) 
    EnabledFlags[i-1]++;
}

//
// Returns true if the template at the passed index is active, false otherwise.
// Note: The list is indexed beginning with 1 not 0.
//
inline bool
TRegTemplateList::IsActive(int i) const
{
  PRECONDITION(i > 0 && i <= Count);
  if (i > 0 && i <= Count) 
    return EnabledFlags[i-1] > 0;
  else
    return false;
}

//----------------------------------------------------------------------------
// TRegParamList
//

//
// Return the number of param entries in this list
//
inline int
TRegParamList::GetCount() const
{
  return Count;
}

//
// Return the template string at the passed index.
//
inline TRegParamList::TEntry&
TRegParamList::operator [](int i)
{
  PRECONDITION(i >= 0 && i < Count);
  if (i < 0 || i >= Count) 
    TXRegistry::Check(1,0);
  return List[i];
}
 

//
// Return the value of the param entry at the passed index
//
inline const char*&
TRegParamList::Value(int i)
{
  PRECONDITION(i >= 0 && i < Count);
  return Values[i];
}

#endif  // WINSYS_REGISTRY_H
