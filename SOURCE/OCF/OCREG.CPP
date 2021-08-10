//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.5  $
//
//   OLE Registration implementation
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/ocreg.h>
#include <ocf/appdesc.h>
#include <classlib/pointer.h>
#include <shellapi.h>
#include <string.h>
#include <stdlib.h>  // atol()
#include <stdio.h>   // sprintf()

DIAG_DEFINE_GROUP(OcDll, true, 1);
DIAG_DECLARE_GROUP(OcRefCount);

#if defined(BI_APP_DLL)
  extern TRegistrar* DllRegistrar;
#endif

//----------------------------------------------------------------------------
// Internal registration template table and registration item key table
//

//
// Registration template table, ordering determines sequence of registration
//  Also, these are all based on HKEY_CLASSES_ROOT
//  Note: the parameter table is dependent on template indices in this table
//
static const char* OcRegTemplates[] = {
#if defined(BI_PLAT_WIN32)
/* 001 */ "CLSID\\<clsid>\\<serverctx>Server32 = <debugger> <path> <cmdline><extraopt>",
#else
/* 001 */ "CLSID\\<clsid>\\<serverctx>Server = <debugger> <path> <cmdline><extraopt>",
#endif
/* 002 */ "CLSID\\<clsid>\\ProgID = <progid>",
/* 003 */ "CLSID\\<clsid> = <description>",
/* 004 */ "CLSID\\<clsid>\\DefaultIcon = <path>,<iconindex>",
#if defined(BI_PLAT_WIN32)
/* 005 */ "CLSID\\<clsid>\\InprocHandler32 = <handler>",
#else
/* 005 */ "CLSID\\<clsid>\\InprocHandler = <handler>",
#endif
/* 006 */ "<progid>\\CLSID = <clsid>",
/* 007 */ "<progid> = <description>",

/* 010 */ "<progid>\\protocol\\StdFileEditing\\verb\\0 = <verb0>",
/* 011 */ "<progid>\\protocol\\StdFileEditing\\verb\\1 = <verb1>",
/* 012 */ "<progid>\\protocol\\StdFileEditing\\verb\\2 = <verb2>",
/* 013 */ "<progid>\\protocol\\StdFileEditing\\verb\\3 = <verb3>",
/* 014 */ "<progid>\\protocol\\StdFileEditing\\verb\\4 = <verb4>",
/* 015 */ "<progid>\\protocol\\StdFileEditing\\verb\\5 = <verb5>",
/* 016 */ "<progid>\\protocol\\StdFileEditing\\verb\\6 = <verb6>",
/* 017 */ "<progid>\\protocol\\StdFileEditing\\verb\\7 = <verb7>",

/* 020 */ "CLSID\\<clsid>\\Verb\\0 = <verb0>,<verb0opt>",
/* 021 */ "CLSID\\<clsid>\\Verb\\1 = <verb1>,<verb1opt>",
/* 022 */ "CLSID\\<clsid>\\Verb\\2 = <verb2>,<verb2opt>",
/* 023 */ "CLSID\\<clsid>\\Verb\\3 = <verb3>,<verb3opt>",
/* 024 */ "CLSID\\<clsid>\\Verb\\4 = <verb4>,<verb4opt>",
/* 025 */ "CLSID\\<clsid>\\Verb\\5 = <verb5>,<verb5opt>",
/* 026 */ "CLSID\\<clsid>\\Verb\\6 = <verb6>,<verb6opt>",
/* 027 */ "CLSID\\<clsid>\\Verb\\7 = <verb7>,<verb7opt>",

/* 030 */ "CLSID\\<clsid>\\DataFormats\\GetSet\\0 = <format0>",
/* 031 */ "CLSID\\<clsid>\\DataFormats\\GetSet\\1 = <format1>",
/* 032 */ "CLSID\\<clsid>\\DataFormats\\GetSet\\2 = <format2>",
/* 033 */ "CLSID\\<clsid>\\DataFormats\\GetSet\\3 = <format3>",
/* 034 */ "CLSID\\<clsid>\\DataFormats\\GetSet\\4 = <format4>",
/* 035 */ "CLSID\\<clsid>\\DataFormats\\GetSet\\5 = <format5>",
/* 036 */ "CLSID\\<clsid>\\DataFormats\\GetSet\\6 = <format6>",
/* 037 */ "CLSID\\<clsid>\\DataFormats\\GetSet\\7 = <format7>",

/* 040 */ "CLSID\\<clsid>\\MiscStatus = <aspectall>",
/* 041 */ "CLSID\\<clsid>\\MiscStatus\\1 = <aspectcontent>",
/* 042 */ "CLSID\\<clsid>\\MiscStatus\\2 = <aspectthumbnail>",
/* 043 */ "CLSID\\<clsid>\\MiscStatus\\4 = <aspecticon>",
/* 044 */ "CLSID\\<clsid>\\MiscStatus\\8 = <aspectdocprint>",
/* 045 */ "CLSID\\<clsid>\\AuxUserType\\2 = <menuname>",
/* 046 */ "CLSID\\<clsid>\\AuxUserType\\3 = <appname>",
/* 047 */ "CLSID\\<clsid>\\Insertable",

/* 050 */ "<permid> = <permname>",
/* 051 */ "<permid>\\CLSID = <clsid>",
/* 052 */ "<permid>\\CurVer = <progid>",
/* 053 */ "CLSID\\<clsid>\\VersionIndependentProgID = <permid>",

/* 054 */ "CLSID\\<clsid>\\Version = <version>",
/* 055 */ "CLSID\\<clsid>\\DataFormats\\DefaultFile = <filefmt>",
/* 056 */ "CLSID\\<clsid>\\Ole1Class = <progid>",  // is this really needed?
/* 057 */ ".<extension> = <progid>",

/* 060 */ "<progid>\\Shell\\Print\\Command = <path> %1",
/* 061 */ "<progid>\\Shell\\Open\\Command = <path> %1",
/* 062 */ "<progid>\\protocol\\StdFileEditing\\server = <debugger> <path><extraopt>",
/* 063 */ "<progid>\\Insertable",
          0,
};

//
// Registration parameter table, ordering is arbitrary, parameters lowercase
//
static TRegParamList::TEntry OcRegParams[] = {
  {"clsid",             0, ""                },// GUID standard string form
  {"progid",            0, "\001\002\003\005\006\007"},// A unique name
  {"insertable",        0, "\046\047\062\063"},// Defined to publish server
  {"usage",  ocrSingleUse, ""                },// Class factory registration
  {"description",       0, ""                },// Human readable, 40 chars max
#if defined(BI_PLAT_WIN32)
  {"handler", "ole32.dll", "\005"            },// Inproc handler
#else
  {"handler",  "ole2.dll", "\005"            },// Inproc handler
#endif
  {"serverctx",         0, "\001"            },// "Local"(EXE) or "Inproc"(DLL)
  {"path",              0, ""                },// OC defaults to load path
  {"cmdline",          "", ""                },// /Automation if app class
  {"debugger",         "", ""                },// Debugger to invoke server
  {"permid",            0, "\050\051\053"    },// Version independent clsid
  {"permname",          0, "\052"            },// Version independent progid
  {"iconindex",       "0", "\004"            },// Zero-based resource icon
  {"menuname",         "", "\045"            },// 15 characters maximum
  {"appname",           0, ""                },// AppName, AuxUserType/3
  {"verb0",             0, "\010\020"        },// Name of primary verb
  {"verb1",             0, "\011\021"        },
  {"verb2",             0, "\012\022"        },
  {"verb3",             0, "\013\023"        },
  {"verb4",             0, "\014\024"        },
  {"verb5",             0, "\015\025"        },
  {"verb6",             0, "\016\026"        },
  {"verb7",             0, "\017\027"        },
  {"verb8",             0, "\018\028"        },
  {"verb0opt",      "0,2", "\020"            },// From REGVERBOPT macro
  {"verb1opt",      "0,2", "\021"            },
  {"verb2opt",      "0,2", "\022"            },
  {"verb3opt",      "0,2", "\023"            },
  {"verb4opt",      "0,2", "\024"            },
  {"verb5opt",      "0,2", "\025"            },
  {"verb6opt",      "0,2", "\026"            },
  {"verb7opt",      "0,2", "\027"            },
  {"verb8opt",      "0,2", "\028"            },
  {"format0",           0, "\030"            },// From REGFORMAT macro
  {"format1",           0, "\031"            },
  {"format2",           0, "\032"            },
  {"format3",           0, "\033"            },
  {"format4",           0, "\034"            },
  {"format5",           0, "\035"            },
  {"format6",           0, "\036"            },
  {"format7",           0, "\037"            },
  {"format8",           0, "\038"            },
  {"filefmt",           0, "\055"            },// Default file format name
  {"aspectall",       "0", "\040"            },// Option flags for all aspects
  {"aspectcontent",     0, "\041"            },// Option flags for content view
  {"aspectthumbnail",   0, "\042"            },// Option flags thumbnail view
  {"aspecticon",        0, "\043"            },// Option flags for icon view
  {"aspectdocprint",    0, "\044"            },// Option flags docprint view
  {"extension",         0, "\057\060\061"    },// Extension for shell loading
  {"version",           0, "\054"            },// App/typelib version string
  {"helpdir",           0, ""                },// Help directory for typehelp
  {"typehelp",          0, ""                },// Help file for type library
  {"language",          0, ""                },// Set internally from func arg
  {"docflags",        "0", ""                },
  {"directory",         0, ""                },
  {"docfilter",         0, ""                },
  {"debugclsid",        0, ""/*INTERNAL GEN*/},// Internal,NOT USER SPECIFIED 
  {"extraopt",         "", ""/*INTERNAL USE*/},// Cmdline debug/non-debug flag
  {"debugprogid",       0, ""                },// Define to force debug reg
  {"debugdesc",         0, ""                },// Different string for debug
  {0,                   0, 0                 },// End
};

//
// Generate OLE registration file image to an output stream
//
// Process a given regInfo table to produce an ascii registration list out to
// an ostream. Arguments are:
//  regInfo  - main registration list to work from
//  module   - hinstance of program module for 'path' & 'serverctx' entries
//  out      - output stream to receive reg entry lines
//  lang     - language id for 'language' entry & string translation
//  filter   - optional template restricting filter
//  defaults - optional reg entries processed before main list
//  overrides- optional reg entries processed after main list
//
long OcRegisterClass(TRegList& regInfo, HINSTANCE module, ostream& out,
                     TLangId lang, char* filter, TRegItem* defaults,
                     TRegItem* overrides)
{
  // Use OCF global registration templates & parameters
  //
  TRegSymbolTable symbolTable(TRegKey::ClassesRoot, OcRegTemplates, OcRegParams);

  // Initialize the symbol table
  //
  symbolTable.Init(filter);
  
  // Check for language defaulted to system or user configuration & 
  // assign language parameter based on TLocaleString's setting
  //
  if (lang == LangSysDefault)
    lang = TLocaleString::SystemDefaultLangId;
  else if (lang == LangUserDefault)
    lang = TLocaleString::UserDefaultLangId;

  int langIdx = symbolTable.Params.Find("language");
  char langBuf[10];
  sprintf(langBuf, "%X", lang);
  symbolTable.Params.Value(langIdx) = langBuf;
  
  // Assign path parameter initially to module load path of the given HINSTANCE
  //
  const int pathSize = 512;
  TAPointer<char> path = new char[pathSize];
  ::GetModuleFileName(module, path, pathSize);
  symbolTable.Params.Value(symbolTable.Params.Find("path")) = path;

  // Assign server context based on whether it is an EXE or a DLL
  //
  // NOTE: Assumes that this code is linked into server's module
  //
  {
  int svrIdx = symbolTable.Params.Find("serverctx");
  if (svrIdx >= 0)
#if defined (BI_PTR_0_32)
    if (::GetModuleHandle(0) == module) // Check instance handle for 32bit EXE
      symbolTable.Params.Value(svrIdx) = "Local";
    else
      symbolTable.Params.Value(svrIdx) = "Inproc";
#else
    if (((unsigned)module | 1) == _SS)  // Check instance handle for 16bit EXE
      symbolTable.Params.Value(svrIdx) = "Local";
    else
      symbolTable.Params.Value(svrIdx) = "Inproc";
#endif
  }

  // Build params from the 3 lists provided in this order:
  //
  //  0: defaults list (defaults)
  //  1: user list of parameters and custom keys (regList)
  //  2: and overrides list (overrides)
  //
  symbolTable.UpdateParams(lang, defaults);
  symbolTable.UpdateParams(lang, regInfo.Items);
  symbolTable.UpdateParams(lang, overrides);

  symbolTable.StreamOut(regInfo.Items, out);

  // Decode & return document template flags
  //
  int i = symbolTable.Params.Find("docflags");
  if (i >= 0)
    return atol(symbolTable.Params.Value(i));
  return 0;
}

//
// Unregister application or class from registration database
//
// These params are the only ones needed to unregister an OLE program or class
//
int OcUnregisterClass(TRegList& regInfo, TRegItem* overrides)
{
  static TRegistry::TUnregParams unregParams[] = {
    { '.', "extension",   &TRegKey::ClassesRoot },
    {  0,  "debugclsid",  &TRegKey::ClassesRootClsid },
    {  0,  "debugprogid", &TRegKey::ClassesRoot },
    {  0,  "clsid",       &TRegKey::ClassesRootClsid },
    {  0,  "progid",      &TRegKey::ClassesRoot },
    {  0,  "permid",      &TRegKey::ClassesRoot },
    {  0,   0,            0 },
  };
  return TRegistry::Unregister(regInfo, unregParams, overrides);
}

//----------------------------------------------------------------------------
// Separate debugging registration for application and documents
// Overrides non-debug values with values from debug keys
//

//
//
//
TRegItem OcRegNoDebug[] = { {"debugger", {""}}, {0,{0}} };
TRegItem OcRegNotDll[]  = { {"cmdline", {""}}, {"debugger", {""}}, {0,{0}} };

//
// Filters limit the templates used when setting up debug registration
//
char AppDebugFilter[] = "\001\002\003\005\006\007";
char DocDebugFilter[] = "\001\002\003\005\006\007"
                        "\020\021\022\023\024\025\026\027"
                        "\030\031\032\033\034\035\036\037"
                        "\040\041\042\043\044\045\046\047"
                        "\054\055\062\063";

//
//
//
struct TDebugRegKey { enum { progid,        clsid,   description,   extraopt};};
char* OcReplaceKeys[] =  {  "progid",      "clsid", "description", "extraopt"};
char* OcDebugKeys[] = {"debugprogid", "debugclsid", "debugdesc",   "debugopt"};

//
// Walk thru a reginfo list using debug entries to create a parallel non-debug
// set for alternate, debug registration.
// Return:
//   0 - No debug registration needed / available
//   1 - Debug registration using passed classid
//  -1 - Debug registration using classid found in reginfo
//
int OcSetupDebugReg(TRegList& regInfo, TRegItem* regDebug, TLangId lang,
                    char* clsid)
{
  char** oldKey = OcReplaceKeys;
  char** newKey = OcDebugKeys;

  // Walk thru the special keys with debug alternates
  //
  int stat = -1;         // Initialize for regInfo-supplied clsid
  for (int i = 0; i < COUNTOF(OcReplaceKeys); i++,oldKey++,newKey++,regDebug++) {
    const char* value = regInfo.Lookup(*newKey, lang);

    // If not value found for a given key, supply a default if possible, else
    // throw an exception.
    //
    if (!value) {
      switch (i) {
        case TDebugRegKey::progid:
          return 0;                   // No debug registration if progid missing
        case TDebugRegKey::extraopt:
          value = " /Debug";          // Default to "/Debug" on command line
          break;
        case TDebugRegKey::clsid:
          if (clsid) {
            value = clsid;
            stat = 1;                 // Flag use of supplied clsid
            break;
          }       // else fall through to throw exception--clsid is required
        case TDebugRegKey::description:
          TXRegistry::Check(1, *newKey); // incomplete debug registration
      }
    }
    regDebug->Key   = *oldKey;         // Write normal key + debug value to 
    regDebug->Value = value;           // output reg list
  }
  regDebug->Key = 0;                   // 0-terminate reg list
  return stat;
}

//----------------------------------------------------------------------------
// TRegistrar - Application registration manager interface class
//

//
//
//
TRegistrar* TRegistrar::RegistrarList = 0;

//
//
//
TRegistrar::TRegistrar(TRegList& regInfo, TComponentFactory callback,
                       string& cmdLine, HINSTANCE hInst)
:
  AppDesc(*new TAppDescriptor(regInfo, callback, cmdLine, hInst))
{
  Next = RegistrarList;
  RegistrarList = this;
  TRACEX(OcRefCount, 1, "TRegistrar() @" << (void*)this);
}

//
//
//
TRegistrar::TRegistrar(TAppDescriptor& appDesc)
:
  AppDesc(appDesc)
{
  Next = RegistrarList;
  RegistrarList = this;
}

//
//
//
TRegistrar::~TRegistrar()
{
  // Since TRegistrars are destroyed when the module is shutdown
  // we do not need to detach each registrar from the linked list
  //
  delete &AppDesc;
}

//
//
//
TRegistrar* TRegistrar::GetNext(TRegistrar* reg)
{
  return reg ? reg->Next : RegistrarList;
}

//
//
//
void far* TRegistrar::GetFactory(const GUID& clsid, const GUID far& iid)
{
  void far* retObj = 0;
  if (clsid != AppDesc.AppClassId)
    return 0;
  ((IUnknown&)AppDesc).QueryInterface(iid, &retObj);
  return retObj;   // QueryInterface sets to null if fails
}

//
//
//
bool TRegistrar::CanUnload()
{
  return static_cast<bool>(!AppDesc.IsBound());
}

//
//
//
int TRegistrar::Run()
{
  if (!IsOptionSet(amExeModule))
    return 0;    // inproc server waits until class factory created and called
  TComponentFactory factory = AppDesc.GetFactory();
  if (!factory)
    return 1;
  if (AppDesc.IsAutomated() && IsOptionSet(amAutomation))
    RegisterAppClass();
  IUnknown* ifc = factory(0, GetOptions() | amRun);  // create app and run it

  // App is now running its message loop, factory may get called again by OLE
  //
  ifc = factory(ifc, GetOptions() | amShutdown);  // EXE finished, destroy it
  if (ifc && !(GetOptions() & amServedApp))
    ifc->Release();  // we own the reference count, else container released it
  return 0;
}

//
//
//
void TRegistrar::Shutdown(IUnknown* releasedObj, uint32 options)
{
  if (!AppDesc.GetFactory())
    return;
  releasedObj = AppDesc.GetFactory()(releasedObj, options|amShutdown);
  if (releasedObj)
    releasedObj->Release();
}

//----------------------------------------------------------------------------
// DLL server entry points
//

//
// Entry point for complete registration management via command line
// Don't let any exceptions blow back to OLE.
//
STDAPI __export DllRegisterCommand(const char far* cmdLine)
{
  try {
    bool isDebug = false;
    TRegistrar* registrar = 0;

    // Need to set up typelibrary state information in case multiple components
    //
    while ((registrar = TRegistrar::GetNext(registrar)) != 0) {
      string cmd(cmdLine);
      registrar->ProcessCmdLine(cmd);
      if (registrar->IsOptionSet(amDebug))
        isDebug = true;
    }
    if (isDebug)
      __emit__(0xCC); // force debugg trap if REGISTER.EXE loaded with debugger
    return HR_OK;
  }
  catch (...) {
    return HR_FAIL;
  }
}

//
// OLE 2.0 entry point for obtaining a class factory for a particular CLSID
// Don't let any exceptions blow back to OLE.
//
STDAPI __export DllGetClassObject(const GUID far& clsid, const GUID far& iid,
                                  void far* far* retObj)
{
  try {
    TRegistrar* registrar = 0;
    while ((registrar = TRegistrar::GetNext(registrar)) != 0) {
      *retObj = registrar->GetFactory(clsid, iid);
      if (*retObj)
        return HR_OK;
    }
    return HR_FAIL;
  }
  catch (...) {
    return HR_FAIL;
  }
}

//
// OLE 2.0 entry point for checking if DLL has no clients and can be unloaded
//
STDAPI __export DllCanUnloadNow()
{  
  TRegistrar* registrar = 0;
  while ((registrar = TRegistrar::GetNext(registrar)) != 0) {
    if (!registrar->CanUnload()) {
      TRACEX(OcDll, 1, "DllCanUnloadNow returning " << hex << uint32(HR_FALSE));
      return HR_FALSE;
    }
  }
  TRACEX(OcDll, 1, "DllCanUnloadNow returning " << hex << uint32(HR_OK));
  return HR_OK;
}     

//
// OLE 2.0 entry point for registering DLL, no locale info passed
//
STDAPI __export DllRegisterServer()
{
  return DllRegisterCommand("/RegServer");
}

//
// OLE 2.0 entry point for unregistering DLL
//
STDAPI __export DllUnregisterServer()
{
  return DllRegisterCommand("/UnregServer");
}
