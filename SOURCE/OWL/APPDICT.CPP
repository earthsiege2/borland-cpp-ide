//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Implementation of class TAppDictionary, a dictionary of associations
// between pids (Process IDs) and TApplication pointers.
// Used to support GetApplicationObject().
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPDICT_H)
# include <owl/appdict.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if defined(BI_APP_DLL)
# include <dos.h>
# include <string.h>
#endif

// Defining LOCALALLOC_TABLE instructs OWL to use LocalAlloc for the table
//
//#define LOCALALLOC_TABLE  

OWL_DIAGINFO;

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Global dictionary used by OWL for EXE Application lookup
//
TAppDictionary& _OWLFUNC 
OWLGetAppDictionary()
{
  static TAppDictionary OwlAppDictionary;
  return OwlAppDictionary;
};

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------

//
// Dictionary implementation used to associate Pids (hTasks) with running Owl
// apps when Owl is in a DLL or used by a DLL. 32bit only needs this when
// running win32s (no per-instance data) since per-instance data makes it
// unnecesasry
//
#if defined(BI_APP_DLL) || defined(BI_PLAT_WIN32)

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

//
// Abstract Base for dictionary implementation
//
class TAppDictImp {
  public:
    virtual ~TAppDictImp() {}

    virtual void                       Add(unsigned pid, TApplication* app) = 0;
    virtual void                       Remove(unsigned pid) = 0;
    virtual TAppDictionary::TEntry*    Lookup(unsigned pid) = 0;
    virtual TAppDictionary::TEntry*    Lookup(TApplication* app) = 0;
    virtual void                       Iterate(TAppDictionary::TEntryIterator) = 0;
    virtual int                        GetCount() const = 0;
};

//
// Pid based Dictionary implementation for Win16, or Win32 w/o perinstance data
//
class TAppDictPidImp : public TAppDictImp {
  public:
    TAppDictPidImp();
   ~TAppDictPidImp();

    void                       Add(unsigned pid, TApplication* app);
    void                       Remove(unsigned pid);
    TAppDictionary::TEntry*    Lookup(unsigned pid);
    TAppDictionary::TEntry*    Lookup(TApplication* app);
    void                       Iterate(TAppDictionary::TEntryIterator iter);
    int                        GetCount() const;

  private:
    enum {DefDictionarySize      = 10};
    enum {DefDictionaryIncrement = 10};

    static TAppDictionary::TEntry*  AllocTable(int count);
    static void                     FreeTable(TAppDictionary::TEntry* table);
    TAppDictionary::TEntry*         GrowTable();

    int      NumEntries;
    TAppDictionary::TEntry*         Table;
};

#if defined(BI_PLAT_WIN32)
//
// Fast, small, per-instance data based Dictionary implementation (32bit only)
//
class TAppDictInstImp : public TAppDictImp {
  public:
    TAppDictInstImp() {Entry.App = 0;}

    void                       Add(unsigned pid, TApplication* app) {Entry.App = app;}
    void                       Remove(unsigned) {Entry.App = 0;}
    TAppDictionary::TEntry*    Lookup(unsigned) {return &Entry;}
    TAppDictionary::TEntry*    Lookup(TApplication* app) {return &Entry;}
    void                       Iterate(TAppDictionary::TEntryIterator iter)
                                 {(*iter)(Entry);}
    int                        GetCount() const {return Entry.App ? 1 : 0;}

  private:
    TAppDictionary::TEntry     Entry;
};
#endif

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// TAppDictionary implementation for DLLs only. EXE version is all inline.
// Flat model must implement here, not inline, because same lib is used by DLLs
//

//
// Application dictionary constructor
//
TAppDictionary::TAppDictionary()
{
#if defined(BI_PLAT_WIN32)
  if (TSystem::SupportsInstanceData())
    Imp = new TAppDictInstImp();   // Could also use this case if linked to exe
  else
    Imp = new TAppDictPidImp();
#else
  Imp = new TAppDictPidImp();
#endif
}

//
//
//
TAppDictionary::~TAppDictionary()
{
  DeleteCondemned();
  delete Imp;
}

//
// Lookup and return the app assiciated with a given pid. May return 0.
//
TApplication*
TAppDictionary::GetApplication(unsigned pid)
{
  if (!pid)
    pid = ::GetCurrentProcessId();
  TAppDictionary::TEntry* entry = Imp->Lookup(pid);
  return entry ? entry->App : 0;
}

//
// Add an app to this dictionary
//
void
TAppDictionary::Add(TApplication* app, unsigned pid)
{
  if (!pid)
    pid = ::GetCurrentProcessId();
  Imp->Add(pid, app);
}

//
// Remove a given app from this dictionary
//
void
TAppDictionary::Remove(TApplication* app)
{
  TAppDictionary::TEntry* entry = Imp->Lookup(app);
  if (entry) {
    entry->App = 0;
    entry->Pid = 0;
  }
}

//
// Remove the app associated with a given pid from this dictionary
//
void
TAppDictionary::Remove(unsigned pid)
{
  TAppDictionary::TEntry* entry = Imp->Lookup(pid);
  if (entry) {
    entry->App = 0;
    entry->Pid = 0;
  }
}

//
// Mark an app in this dictionary as being condemned by zeroing its pid.
// Can then be deleted later.
//
void
TAppDictionary::Condemn(TApplication* app)
{
  TAppDictionary::TEntry* entry = Imp->Lookup(app);
  if (entry)
    entry->Pid = 0;
}

//
//
//
static void _DeleteCondemnedIter(TAppDictionary::TEntry& entry)
{
  if (!entry.Pid) {
    delete entry.App;
    entry.App = 0;
  }
}

//
// Iterate over the entries, invoking the supplied callback function.
//
void
TAppDictionary::Iterate(TAppDictionary::TEntryIterator iter)
{
  Imp->Iterate(iter);
}

//
// Delete all of the condemned app objects in this dictionary
//
bool
TAppDictionary::DeleteCondemned()
{
  Imp->Iterate(_DeleteCondemnedIter);
  return Imp->GetCount() == 0;
}

//
// Exported entry for Debugger use
//
extern "C" TApplication* PASCAL _OWLFUNC
GetTaskApplicationObject(unsigned pid)
{
  return OWLGetAppDictionary().GetApplication(pid);
}

//----------------------------------------------------------------------------
// TAppDictPidImp for DLL when there are real guts for pid lookup
//

//
// Construct an app dictionary implementation that looks up apps based on
// process id
//
TAppDictPidImp::TAppDictPidImp()
{
  Table = AllocTable(DefDictionarySize);
  NumEntries = DefDictionarySize;
}

//
// Destruct the app dictionary implementation object
//
TAppDictPidImp::~TAppDictPidImp()
{
  FreeTable(Table);
}

//
// Add an app to the dictionary given a process id
//
void
TAppDictPidImp::Add(unsigned pid, TApplication* app)
{
  TAppDictionary::TEntry* freeEntry = 0;  // no free entry yet
  TAppDictionary::TEntry* entry = Table;

  // First see if there is already a table; if so, replace the entry
  //
  for (; entry < &Table[NumEntries]; entry++) {
    if (entry->Pid == pid) {
      // Old app gets stomped, user must manage its lifetime
      entry->App = app;        // already in table, update pointers
      return;
    }
    else if (!freeEntry && !entry->Pid) {
      freeEntry = entry;  // remember this first free entry for use later
    }
  }

  // Not in table. see if we encountered a free entry in the table
  // if so, use it; otherwise grow the table & put entry in first new slot
  //
  entry = freeEntry ? freeEntry : GrowTable();
  entry->Pid = pid;
  entry->App = app;
}

//
// Remove an entry from the dictionary by looking up the process id
//
void
TAppDictPidImp::Remove(unsigned pid)
{
  TAppDictionary::TEntry* entry = Lookup(pid);
  if (entry) {
    entry->App = 0;
    entry->Pid = 0;
  }
}

//
// Lookup and return the entry associated with a given pid. May return 0.
//
TAppDictionary::TEntry*
TAppDictPidImp::Lookup(unsigned pid)
{
  for (TAppDictionary::TEntry* entry = Table; entry < Table+NumEntries; entry++)
    if (entry->Pid == pid)
      return entry;

  return 0;
}

//
// Lookup and return the entry associated with a given app. May return 0.
//
TAppDictionary::TEntry*
TAppDictPidImp::Lookup(TApplication* app)
{
  for (TAppDictionary::TEntry* entry = Table; entry < Table+NumEntries; entry++)
    if (entry->App == app)
      return entry;

  return 0;
}

//
// Iterate over the entries, invoking the supplied callback function.
//
void
TAppDictPidImp::Iterate(TAppDictionary::TEntryIterator iter)
{
  for (TAppDictionary::TEntry* entry = Table; entry < Table+NumEntries; entry++)
    (*iter)(*entry);
}

//
// Return the count of entries in this dictionary.
//
int
TAppDictPidImp::GetCount() const
{
  int i = 0;
  for (TAppDictionary::TEntry* entry = Table; entry < Table+NumEntries; entry++)
    if (entry->App)
      i++;
  return i;
}

//
// Allocate the actual table for the dictionary.
// Optionally allocate the table from the local heap so that this DLL always
// owns it, needed only if the RTL 
//
TAppDictionary::TEntry*
TAppDictPidImp::AllocTable(int count)
{
  TAppDictionary::TEntry* entries;
#if defined(LOCALALLOC_TABLE)
  entries = (TAppDictionary::TEntry*)::LocalLock(::LocalAlloc(LMEM_ZEROINIT,
                count * sizeof(TAppDictionary::TEntry)));
  if (!entries)
    THROW( xalloc(__FILE__ __LINE__, count * sizeof(TAppDictionary::TEntry)) );
#else
  entries = new TAppDictionary::TEntry[count];
  memset(entries, 0, count * sizeof(TAppDictionary::TEntry));
#endif
  return entries;
}

//
// Free all memory used by the table itself.
//
void
TAppDictPidImp::FreeTable(TAppDictionary::TEntry* table)
{
#if defined(LOCALALLOC_TABLE)
  if (!table)
    return;
#if defined(BI_PLAT_WIN32)
  HLOCAL  hMem = ::LocalHandle(table);
#else
  HLOCAL  hMem = ::LocalHandle((void NEAR*)FP_OFF(table));  // strip off ds:
#endif
  if (::LocalUnlock(hMem))
    ::LocalFree(hMem);
#else
  delete[] table;
#endif
}

//
// Grow the size of the table by DefDictionaryIncrement delta
//
TAppDictionary::TEntry*
TAppDictPidImp::GrowTable()
{
  // Save current table & entry count, & create new ones
  //
  int     oldNumEntries = NumEntries;
  TAppDictionary::TEntry* oldTable = Table;

  NumEntries += DefDictionaryIncrement;
  Table = AllocTable(NumEntries);

  // Copy old table to new one
  //
  memcpy(Table, oldTable, oldNumEntries * sizeof(TAppDictionary::TEntry));

  // Free old table
  //
  FreeTable(oldTable);

  // Return pointer to first entry in new block
  //
  return Table + oldNumEntries;
}

#else  // 16bit static link exe models 

//
// Delete all of the condemned app objects in this dictionary
//
bool TAppDictionary::DeleteCondemned() {
  if (!E.Pid) {
    delete E.App;
    E.App = 0;
  }
  return false;
}

#endif  // if/else defined(BI_APP_DLL) || defined(BI_PLAT_WIN32)

//----------------------------------------------------------------------------

#if defined(BI_NAMESPACE)
namespace OWL {
#endif 

//
// Global function that calls GetApplication() on OWL's app-dictionary.
// Used by EXEs, or DLLs statically linking OWL. Never returns 0, will make
// an alias app if needed. Primarily for compatibility
//
TApplication* _OWLFUNC GetApplicationObject(unsigned pid)
{
  TApplication* app = OWLGetAppDictionary().GetApplication(pid);
  if (app)
    return app;

  // Make alias app (will add itself to dictionary) because OWL always needs an
  // app around. If the app is non-OWL, no TApplication will have been
  // constructed.
  // Override default constructor argument to prevent overwrite of ::Module,
  // and pass the default dictionary.
  //
  TModule* tempModule;
  return new TApplication("ALIAS", tempModule, &(OWLGetAppDictionary()));
}

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif 
