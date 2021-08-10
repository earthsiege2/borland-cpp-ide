//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.17  $
//
// General Registry access & registration implementation
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/registry.h>
#include <winsys/system.h>
#include <classlib/pointer.h>
#include <services/checks.h>
#include <stdlib.h>  // atol()
//#include <stdio.h>   // sprintf()

//
// Predefined constant registry keys
//
#if defined(BI_PLAT_WIN16)
# define HKEY_CURRENT_USER           ((HKEY)0x80000001L)
# define HKEY_LOCAL_MACHINE          ((HKEY)0x80000002L)
# define HKEY_USERS                  ((HKEY)0x80000003L)
# define HKEY_PERFORMANCE_DATA       ((HKEY)0x80000004L)
# define HKEY_PERFORMANCE_TEXT       ((HKEY)0x80000050L)
# define HKEY_PERFORMANCE_NLSTEXT    ((HKEY)0x80000060L)
# define HKEY_CURRENT_CONFIG         ((HKEY)0x80000005L)
# define HKEY_DYN_DATA               ((HKEY)0x80000006L)
TRegKey TRegKey::ClassesRoot((TSystem::IsWin95())? ((HKEY)0x80000000L):
                              HKEY_CLASSES_ROOT, true, "HKEY_CLASSES_ROOT");
#else
TRegKey TRegKey::ClassesRoot(HKEY_CLASSES_ROOT, true, "HKEY_CLASSES_ROOT");
#endif

TRegKey TRegKey::ClassesRootClsid(ClassesRoot, "CLSID", KEY_ALL_ACCESS, NoCreate);
TRegKey TRegKey::CurrentUser(HKEY_CURRENT_USER, true, "HKEY_CURRENT_USER");
TRegKey TRegKey::LocalMachine(HKEY_LOCAL_MACHINE, true, "HKEY_LOCAL_MACHINE");
TRegKey TRegKey::Users(HKEY_USERS, true, "HKEY_USERS");

// Win4.0 only, handles end up 0 during object construction
//
TRegKey TRegKey::CurrentConfig(HKEY_CURRENT_CONFIG, true, "HKEY_CURRENT_CONFIG");
TRegKey TRegKey::DynData(HKEY_DYN_DATA, true, "HKEY_DYN_DATA");

// Win32 3.51 or greater?
//
TRegKey TRegKey::PerformanceData(HKEY_PERFORMANCE_DATA, true, "HKEY_PERFORMANCE_DATA");

//
// Different parameter usage & initial code for Win16 vs Win32
//
#if defined(BI_PLAT_WIN16)
//
// Initialize the object with the passed-in data.
//
TRegKey::TRegKey(THandle baseKey, const char far* keyName, REGSAM /*samDesired*/, TCreateOK createOK)
:
  Name(strnewdup(keyName))
{
  if (createOK == CreateOK) {
    ::RegCreateKey(baseKey, Name, &Key);
  }
  else
    ::RegOpenKey(baseKey, Name, &Key);

#else
//
// Initialize the object with the passed-in data.
//
TRegKey::TRegKey(THandle baseKey, const char far* keyName, REGSAM samDesired, TCreateOK createOK)
:
  Name(strnewdup(keyName))
{
  if (createOK == CreateOK) {
    uint32 disposition;
    ::RegCreateKeyEx(baseKey, Name, 0, ""/*class*/, REG_OPTION_NON_VOLATILE,
                     samDesired, 0/*SecurityAttributes*/, &Key,
                     &disposition);
  }
  else
    ::RegOpenKeyEx(baseKey, Name, 0, samDesired, &Key);
#endif

  QueryInfo(0, 0, &SubkeyCount, 0, 0, &ValueCount, 0, 0, 0, 0);

  ShouldClose = true;

//  TXRegistry::Check(long(Key), Name);
}

//
// Initialize object with the key pointed to by the iterator.
//
#if defined(BI_PLAT_WIN16)
TRegKey::TRegKey(const TRegKeyIterator& iter, REGSAM /*samDesired*/)
#else
TRegKey::TRegKey(const TRegKeyIterator& iter, REGSAM samDesired)
#endif
:
  Key(0),
  Name(new char[_MAX_PATH+1])
{
  iter.BaseKey().EnumKey(iter.Current(), Name, _MAX_PATH+1);
#if defined(BI_PLAT_WIN16)
  ::RegOpenKey(iter.BaseKey(), Name, &Key);
#else
  ::RegOpenKeyEx(iter.BaseKey(), Name, 0, samDesired, &Key);
#endif

  ShouldClose = true;
  QueryInfo(0, 0, &SubkeyCount, 0, 0, &ValueCount, 0, 0, 0, 0);
}

//
// Construct a TRegKey object around an existing key. Commonly used for
// wrapping the preexisting pseudo-keys.
//
TRegKey::TRegKey(THandle aliasKey, bool shouldClose, const char far* keyName)
:
  Key(aliasKey),
  Name(strnewdup(keyName))
{
  ShouldClose = shouldClose;

#if defined(BI_PLAT_WIN16)
    long err = QueryInfo(0, 0, &SubkeyCount, 0, 0, &ValueCount, 0, 0, 0, 0);
    if (err != S_OK)
      Key = 0;
#else
# if defined(BI_COMP_MSC)
  __try {
# else
  try {
# endif
    long err = QueryInfo(0, 0, &SubkeyCount, 0, 0, &ValueCount, 0, 0, 0, 0);
    if (err != S_OK && err != ERROR_INSUFFICIENT_BUFFER)
      Key = 0;
  }
  // Some key handles are unsupported & sometimes the OS crashes, & doesn't
  // just return an error. Catch it here & zero out this key.
  //
  __except ((GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION) ?
              EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
    Key = 0;
  }
#endif
}

//
// Destructor closes the key if necessary and deletes any previously
// allocated memory by the object.
//
TRegKey::~TRegKey()
{
  if (Key && ShouldClose)
    ::RegCloseKey(Key);
  delete[] Name;
}

#if defined(BI_PLAT_WIN16)
//
// Query information about the key.
// Emulation for 16-bits.
//
long
TRegKey::QueryInfo(char far* /*class_*/, uint32* /*classSize*/,
                        uint32* subkeyCount,
                        uint32* /*maxSubkeySize*/, uint32* /*maxClassSize*/,
                        uint32* valueCount, uint32* /*maxValueName*/,
                        uint32* /*maxValueData*/, uint32* /*secDescSize*/,
                        FILETIME far* /*lastWriteTime*/)
{
  // Ug. Enum all subkeys to count them ahead of time for iterator
  //
  if (subkeyCount) {
    int i = 0;
    for (;; i++) {
      char dummy[_MAX_PATH+1];
      long r = ::RegEnumKey(Key, i, dummy, sizeof dummy);
      if (r != 0/* && r != ERROR_MORE_DATA*/)
        break;
    }
    *subkeyCount = i;
  }
  if (valueCount)
    *valueCount = 1;    // Cannot access named values with Win16 API
  return 0;
}
#else
//
// Wrapper for RegQueryInfoKey API.
//
long
TRegKey::QueryInfo(char far* class_, uint32* classSize,
                   uint32* subkeyCount,  uint32* maxSubkeySize,
                   uint32* maxClassSize, uint32* valueCount,
                   uint32* maxValueName, uint32* maxValueData,
                   uint32* secDescSize, PFILETIME lastWriteTime)
{
  char      db[256];
  uint32    d1 = sizeof db;
  uint32    d2 = 0;
  uint32    d3 = 0;
  uint32    d4 = 0;
  uint32    d5 = 0;
  uint32    d6 = 0;
  uint32    d7 = 0;
  uint32    d8 = 0;
  FILETIME  ft;

  // NT 3.50 has trouble with 0 ptrs for some of these
  //
  return ::RegQueryInfoKey(Key, class_ ? class_ : db,
                           classSize ? classSize : &d1, 0,
                           subkeyCount ? subkeyCount : &d2,
                           maxSubkeySize ? maxSubkeySize : &d3,
                           maxClassSize ? maxClassSize : &d4,
                           valueCount ? valueCount : &d5,
                           maxValueName ? maxValueName : &d6,
                           maxValueData ? maxValueData : &d7,
                           secDescSize ? secDescSize : &d8,
                           lastWriteTime ? lastWriteTime : &ft);
}
#endif

//
// Completely nuke a child key, including any of its subkeys. RegDeleteKey
// fails if a key has subkeys, so must tail-recurse to clean them up first.
//
long
TRegKey::NukeKey(const char far* subKeyName)
{
  {
    TRegKey subKey(*this, subKeyName, KEY_ALL_ACCESS, TRegKey::NoCreate);

    // Don't increment since deleting & all subkeys will slide down to 0
    //
    for (TRegKeyIterator i(subKey); i; ) {
      TRegKey subSubKey(i);
      if (!subSubKey)
        break;     // All done, ran out before iterator knew, since deleting
      long err = subKey.NukeKey(subSubKey.GetName());
      if (err)
        return err;
    }
  }
  return DeleteKey(subKeyName);
}

//
// Create a value object named 'name' associated with the the current key.
//
TRegValue::TRegValue(const TRegKey& key, const char far* name)
:
  Key(key), Name(name), AName(0), Data(0)
{
  DataSize = 0;
  Key.QueryValue(Name, &DataType, 0, &DataSize); // Get type & size only
}

//
// Create a value object pointed to by the current position of the iterator.
//
TRegValue::TRegValue(const TRegValueIterator& iter)
:
  Key(iter.BaseKey()), Data(0)
{
  uint32 nameSize = _MAX_PATH; //0;  
  Name = AName = new char[(int)nameSize];
  DataSize = 0;
  Key.EnumValue(iter.Current(), AName, nameSize, &DataType, 0, &DataSize);
}

//
// Destructor deletes any previously allocated memory.
//
TRegValue::~TRegValue()
{
  delete[] AName;
  delete[] Data;
}

//
// Retrieve the data for the value.
//
void
TRegValue::RetrieveOnDemand() const
{
  if (!Data) {
#if defined(BI_NO_MUTABLE)
    CONST_CAST(TRegValue*,this)->Data = new uint8[DataSize];
#else
    Data = new uint8[(int)DataSize];
#endif
    uint32 ds = DataSize;
    Key.QueryValue(Name, 0, Data, &ds);  // DataSize shouldn't change...
  }
}

//
// Set the data for the value.
//
long
TRegValue::Set(uint32 type, uint8* data, uint32 dataSize)
{
  long ret = Key.SetValue(Name, type, data, dataSize);
  if (ret == 0) {
    DataType = type;
    if (dataSize == DataSize) {
      memcpy(Data, data, (int)DataSize);  // resync w/ new data if same size
    }
    else {
      DataSize = dataSize;           // Otherwise retrieve on demand later
      delete[] Data;
      Data = 0;
    }
  }
  return ret;
}

//----------------------------------------------------------------------------

//
// Registry exception checking. Throw a TXRegistry if arg is non-zero
//
void
TXRegistry::Check(long stat, const char* key)
{
  if (stat != 0 && !InstanceCount) {
    if (stat == 1)      // default bool true to a generic E_FAIL
      stat = E_FAIL;
    char buf[100];
    if (key)
      wsprintf(buf, "Registry failure on key: %s, ErrorCode = %lX\n",
               (const char far*)key, stat);
    else
      wsprintf(buf, "Registry failure on unknown key: ErrorCode = %lX\n",
               stat);
    WARN(stat != 0, buf);
    throw TXRegistry(buf, key);
  }
}

//----------------------------------------------------------------------------

//
// Initialize object with the passed-in data.
// Counts the number of items in the list.
//
TRegTemplateList::TRegTemplateList(TRegKey& basekey, const char* list[])
:
  BaseKey(basekey),
  List(list)
{
  PRECONDITION(List);

  for (Count = 0; List[Count]; Count++)
    ;
  EnabledFlags = new char[Count];
}

//
// Destructor deletes any previously allocated memory.
//
TRegTemplateList::~TRegTemplateList()
{
  delete[] EnabledFlags;
}

//
// Enable items from the set.
//
void
TRegTemplateList::Enable(const char* set)
{
  for (const char* pc = set; *pc != 0; pc++)
    EnabledFlags[*pc - 1] = 0;                 // Selectively allow enable
}

//
// Activate the items in the set.
//
void
TRegTemplateList::Activate(const char* set)
{
  for (const char* pc = set; *pc != 0; pc++)
    EnabledFlags[*pc - 1]++;  
}

//----------------------------------------------------------------------------

//
// Initialize the object with the passed-in data.
// Counts the number of items in the list.
//
TRegParamList::TRegParamList(TEntry* list)
:
  List(list)
{
  PRECONDITION(List);

  for (Count = 0; List[Count].Param; Count++)
    ;
  typedef const char* cpchar;
  Values = new cpchar[Count];
}

//
// Destructor deletes any previously allocated memory.
//
TRegParamList::~TRegParamList()
{
  delete[] Values;
}

//
// Reset all values to their default values.
//
void
TRegParamList::ResetDefaultValues()
{
  for (int i = Count; --i >= 0; )
    Values[i] = List[i].Default;
}

//
// Look for a given param in this param list
//
int TRegParamList::Find(const char* param)
{
  PRECONDITION(param);
  if (!param)
    return -1;

  int i = Count;
  while (--i >= 0) {
    if (strcmp(List[i].Param, param) == 0)
      break;
  }
  return i;
}

//----------------------------------------------------------------------------

//
// Initialize the symbol table with the data.
//
TRegSymbolTable::TRegSymbolTable(TRegKey& basekey, const char* tplList[],
                                 TRegParamList::TEntry* paramList)
:
  Templates(basekey, tplList),
  Params(paramList)
{
  UserKeyCount = 0;
}

//
// Enable all templates, or if filter is given enable only those
// Initialize paramater values with defaults
//
void
TRegSymbolTable::Init(char* filter)
{
  if (filter) {
    Templates.DisableAll();
    Templates.Enable(filter);
  }
  else {
    Templates.EnableAll();
  }

  Params.ResetDefaultValues();
  UserKeyCount = 0;
}

//
// Scan through provided items assinging values from the item to the matching
// param. A langId is needed for locale translation on assignment.
//
void
TRegSymbolTable::UpdateParams(TLangId lang, TRegItem* item)
{
  for (; item && item->Key; item++) {
    // Note presence of user-specified key and value, process when streaming
    //
    if (*item->Key == ' ') {
      UserKeyCount++;
    }
    else {
      // Replace default with user-specified parameter value
      //
      int i = Params.Find(item->Key);
      TXRegistry::Check(i < 0, item->Key);
      Params.Value(i) = item->Value.Translate(lang);

      // Activate all templates invoked by parameter
      //
      Templates.Activate(Params[i].TemplatesNeeded);
    }
  }
}

//
// Scan thru and process enabled templates, substituting filled in parameter
// values and streaming the resulting strings into the out stream provided.
//
void
TRegSymbolTable::StreamOut(TRegItem* item, ostream& out)
{
  for (int itpl = 1; itpl <= Templates.GetCount() || UserKeyCount--; itpl++) {

    // Setup pt from standard templates, or from userKeys in item prepended
    // by spaces.
    //
    const char* userval = 0;
    const char* pt;
    if (itpl <= Templates.GetCount()) {  // Processing standard template array
      if (!Templates.IsActive(itpl))
        continue;
      pt = Templates[itpl];
    }
    else {                            // Now processing user-defined templates
      while (*(pt = item->Key) != ' ')
        item++;
      pt++;
      userval = item->Value;
    }

    // Walk thru template (pt) copying it into buf, replacing <params> on the
    // way.
    //
    const int bufSize  = 512;
    TAPointer<char> buf = new char[bufSize];

    char*       data = 0; // Optional data for keys-value=data
    const char* pc;       // Point where param token began
    char*       pb = buf; // Working buffer write pointer
    for (;;) {
      char  c = *pt++;  // Current character being copied
      switch (c) {
        case '<':
          pc = pb;      // Remember where param token starts
          continue;
        case '>': {
          *pb = 0;        // Terminate param token

          // Lookup param in param list
          //
          int i = Params.Find(pc);
          TXRegistry::Check(i < 0, pc); // internal err

          // Now get the value obtained above
          //
          pb = (char*)pc; // Move buffer ptr back
          TXRegistry::Check((pc = Params.Value(i)) == 0, Params[i].Param);

          if (*pc == 0 && *pt == ' ')  
            pt++;

          // Copy value to buf
          //
          while (*pc != 0)
            *pb++ = *pc++;
          continue;
        }
        case '=':
          while (*(pb-1) == ' ')  // Remove trailing space before =
            pb--;
          *pb++ = 0;              // Terminate keys-value
          data = pb;              // Rest of pt will be data written from here
          while (*pt == ' ')
            pt++;
          continue;
        default:
          *pb++ = c;  // Copy character to buf. Param name will be overwriten
          continue;
        case 0:
          *pb++ = 0;
          if (!userval)
            break;
          pt = userval;
          userval = 0;
          data = pb;
          continue;
      }
      if (!c)
        break;
    }
    // Now write out a key with an optional assignment value to output stream
    //
    out
#if defined(BI_DATA_NEAR)
      << TResId(Templates.GetBaseKey().GetName())
#else
      << Templates.GetBaseKey().GetName()
#endif
      << '\\' << (const char*)buf;
    if (data)
      out << " = " << data;
    out << '\n';
  }
}

//----------------------------------------------------------------------------

//
// Walk thru an input stream and use "basekey\key\key=data" lines to set
// registry entries
// Has named value support in the form "basekey\key\key|valuename=data"
//
void TRegistry::Update(TRegKey& baseKey, istream& in)
{
  // Loop thru all lines in input stream
  //
  while (!in.eof()) {
    // Get line into entry buffer, skip over base key if it exists, ignore line
    // if it doesn't
    //
    char entry[512];
    in.getline(entry, strlen(baseKey.GetName())+1);
    if (strcmp(entry, baseKey.GetName()) != 0)
      continue;
    in.getline(entry, 1+1);  // Eat the '\' separator
    in.getline(entry, sizeof entry);

    // Split entry into keys-value and data strings
    //
    char* data = strchr(entry, '=');
    if (data) {
      char* pc = data;
      while (*(pc-1) == ' ')
        pc--;
      *pc = 0;
      while (*(++data) == ' ')
        ;
    }
    else
      data = "";
    char* valName = strchr(entry, '|');
    if (valName)
      *valName++ = 0;  // Terminate key at value name separator

    // Set default value
    //
    if (valName) {
      TRegKey subKey(baseKey, entry);
      TXRegistry::Check(subKey.SetValue(valName, REG_SZ, (const uint8*)data, 0), entry);
    }
    else {
      TXRegistry::Check(baseKey.SetDefValue(entry, REG_SZ, data, 0), entry);
    }
  }
}

//
// Walk thru an input stream and use "basekey\key\key=data" lines to check
// registry entries.
// Return the number of differences. Zero means a complete match
//
// Has named value support in the form "basekey\key\key|valuename=data"
//
int TRegistry::Validate(TRegKey& baseKey, istream& in)
{
  int diffCount = 0;
  while (!in.eof()) {
    // Get line into entry buffer, skip over hive key if it exists, ignore line
    // if it doesn't
    //
    char entry[512];
    in.getline(entry, strlen(baseKey.GetName())+1);  // 1 for '\', 1 for 0
    if (strcmp(entry, baseKey.GetName()) != 0)
      continue;
    in.getline(entry, 1+1);  // Eat the '\' separator
    in.getline(entry, sizeof entry);

    // Split entry into keys-value and data strings
    //
    char* data = strchr(entry, '=');
    if (data) {
      char* pc = data;
      while (*(pc-1) == ' ')
        pc--;
      *pc = 0;
      while (*(++data) == ' ')
        ;
    }
    char* valName = strchr(entry, '|');
    if (valName)
      *valName = '\\';  // Replace value name separator with \ for query

    // Now lookup keys-value part to get its data and see if it matches the
    // data value from the instream
    //
    char buf[300];
    uint32 bufSize = sizeof buf;
    if (baseKey.QueryDefValue(entry, buf, &bufSize) != S_OK
        || (data && strcmp(data, buf) != 0))
      diffCount++;
  }
  return diffCount;
}

//
// Unregisters entries given a reglist, an optional overrides regItem.
// Return the # of errors deleting keys
//
int
TRegistry::Unregister(TRegList& regInfo, TUnregParams* params, TRegItem* overrides)
{
  int  errorCount = 0;

  // Loop thru unregister params to nuke each root level key, thus cleaning
  // up all nested keys too
  //
  for (int i = 0; params[i].Name && params[i].BaseKey; i++) {
    const char* regKey = regInfo[params[i].Name];

    // If the param not found & it matches the overrides item, then use that
    // value
    //
    if (!regKey && overrides && strcmp(overrides->Key, params[i].Name) == 0)
      regKey = overrides->Value;

    // If key-value was found, unregister it
    //
    if (regKey) {
      char buff[16];
      if (params[i].Prepend) { // Special case prepending char to key
        buff[0] = '.';
        strcpy(buff+1, regKey);
        regKey = buff;
      }

      // Nuke the key, using the basekey as a reference point
      //
      if (params[i].BaseKey->NukeKey(regKey))
        errorCount++;         // Should throw exception if certain errors?
    }
  }
  return errorCount;
}

