//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\appdict.cpp
//   Implementation of class TAppDictionary, a dictionary of
//   associations between task handles and TApplication pointers.
//   Used to support GetApplicationObject().
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\owldefs.h>
#include <owl\applicat.h>
#if defined(__DLL__)
  #include <dos.h>
  #include <string.h>
#endif

//
// Dictionary class used to associate Pids (hTasks) with running Owl apps when
// Owl is in a DLL. 32bit only needs this when running win32s since
// per-instance data is not available.
//
#if defined(__DLL__)

const int DefDictionarySize      = 10;
const int DefDictionaryIncrement = 10;

#if !defined(__WIN32__)
  inline unsigned GetCurrentProcessId() {return (unsigned)GetCurrentTask();}
#endif

//
//  class TAppDictionaryEntry
//  ----- -------------------
//
class TAppDictionaryEntry {
  public:
    unsigned       Pid;
    TApplication*  Application;
};

//
//  class TAppDictionary
//  ----- --------------
//
class TAppDictionary {
  public:
    TAppDictionary(int initialCount = DefDictionarySize);

   ~TAppDictionary();
    
    static TAppDictionaryEntry*  AllocTable(int count);
    static void                  FreeTable(TAppDictionaryEntry* table);

    TAppDictionaryEntry*  GrowTable(int increment = DefDictionaryIncrement);
    void                  Add(unsigned pid, TApplication*);
    void                  Delete(unsigned pid);
    TApplication*         LookupApp(unsigned pid);

  private:
    int                   NumEntries;
    TAppDictionaryEntry*  Table;
};

//
// Dictionary implementation
//
TAppDictionary::TAppDictionary(int initialCount)
{
  if (initialCount != 0)
    Table = AllocTable(initialCount);

  NumEntries = Table ? initialCount : 0;
}

TAppDictionary::~TAppDictionary()
{
  if (NumEntries != 0 && Table)
    FreeTable(Table);
}

//
// Allocate the table from the local heap so that this DLL always owns it.
//
TAppDictionaryEntry*
TAppDictionary::AllocTable(int count)
{
  return (TAppDictionaryEntry*)LocalLock(
           LocalAlloc(LMEM_ZEROINIT, count * sizeof(TAppDictionaryEntry))
         );
}

void
TAppDictionary::FreeTable(TAppDictionaryEntry* table)
{
#if defined(__WIN32__)
  HLOCAL  hMem = LocalHandle(table);
#else
  HLOCAL  hMem = LocalHandle((void NEAR*)FP_OFF(table));  // strip off ds:
#endif
  if (LocalUnlock(hMem))
    LocalFree(hMem);
}

TAppDictionaryEntry*
TAppDictionary::GrowTable(int increment)
{
  int                   oldNumEntries = NumEntries;
  TAppDictionaryEntry*  oldTable = Table;

  NumEntries = NumEntries + increment;
  Table = AllocTable(NumEntries);

  //
  // copy old table to new location
  //
  memcpy(Table, oldTable, oldNumEntries * sizeof(TAppDictionaryEntry));

  FreeTable(oldTable);

  //
  // return pointer to first entry in new block
  //
  return &Table[oldNumEntries];
}

void
TAppDictionary::Add(unsigned pid, TApplication* app)
{
  TAppDictionaryEntry* freeEntry = 0;  // no free entry yet

  //
  // first see if there is already a table; if so, replace the entry
  //
  for (TAppDictionaryEntry* entry = Table; entry < &Table[NumEntries]; entry++) {
    if (entry->Pid == pid) {
      entry->Application = app;        // already in table, update pointers
      return;

    } else if (!freeEntry && !entry->Pid) {
      freeEntry = entry;  // remember this free entry for use later
    }
  }

  //
  // not in table. see if we encountered a free entry in the table
  // if so, use it; otherwise grow the table
  //
  if ((entry = (freeEntry ? freeEntry : GrowTable())) != 0) {
    entry->Pid = pid;
    entry->Application = app;
  }
}

TApplication*
TAppDictionary::LookupApp(unsigned pid)
{
  for (TAppDictionaryEntry* entry = Table; entry < &Table[NumEntries]; entry++)
    if (entry->Pid == pid)
      return entry->Application;
  //
  // Make alias app (will add itself) because Owl always needs an app around
  // If the app is non-Owl, no TApplication will have been constructed.
  // Override default constructor argument to prevent overwrite of ::Module
  //
  TModule* tempModule;
  return new TApplication("ALIAS",tempModule);
}

void
TAppDictionary::Delete(unsigned pid)
{
  for (TAppDictionaryEntry* entry = Table; entry < &Table[NumEntries]; entry++)
    if (entry->Pid == pid) {
      entry->Pid = 0;  // found entry.  Zero it.
      return;
    }
}

//
// Static instance of the application dictionary
//
static TAppDictionary* AppDictionary = new TAppDictionary();

//
// Locals used for Win32 to skip dictionary when perinstance data is available
//
#if defined(__WIN32__)
static TApplication*   __OwlThisApplication;
static int      PerInstanceData = -1;   // Is per-instance data supported?
                                        // -1 for don't-know-yet
#endif

//
// Exported, public functions used to add, delete & get apps from the
// dictionary in the DLL case
//
TApplication* _OWLFUNC 
GetApplicationObject()
{
#if defined(__WIN32__)
  if (PerInstanceData)
    return __OwlThisApplication;
#endif
  return AppDictionary->LookupApp(::GetCurrentProcessId());
}

extern "C" TApplication* PASCAL _OWLFUNC 
GetTaskApplicationObject(unsigned pid)
{
#if defined(__WIN32__)
  if (PerInstanceData)
    return __OwlThisApplication;
#endif
  return AppDictionary->LookupApp(pid);
}

void _OWLFUNC
AddApplicationObject(TApplication* app)
{
#if defined(__WIN32__)
  if (PerInstanceData < 0)
    PerInstanceData = !(HIWORD(::GetVersion())&0x8000);  // not in win32s

  if (PerInstanceData)
    __OwlThisApplication = app;
#endif
     
  AppDictionary->Add(::GetCurrentProcessId(), app);
}

void _OWLFUNC
DeleteApplicationObject()
{
#if defined(__WIN32__)
  if (PerInstanceData)
    __OwlThisApplication = 0;
#endif
  AppDictionary->Delete(::GetCurrentProcessId());
}

//----------------------------------------------------------------------------

#else  // defined(__DLL__)

//
// Global statics containing the single application pointer
//
static TApplication*   __OwlThisApplication;

//
// Exported, public functions used to add, delete & get apps from the
// 'dictionary' in the non-DLL case
//

TApplication* _OWLFUNC 
GetApplicationObject()
{
  return __OwlThisApplication;
}

void _OWLFUNC
AddApplicationObject(TApplication* app)
{
  __OwlThisApplication = app;
}

void _OWLFUNC
DeleteApplicationObject()
{
  __OwlThisApplication = 0;
}

#endif  // defined(__DLL__)
