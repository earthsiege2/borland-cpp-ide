//
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   OLE Registration implementation
//----------------------------------------------------------------------------
#include <ocf/ocfpch.h>
#include <ocf/ocreg.h>
#include <ocf/appdesc.h>
#include <shellapi.h>
#include <string.h>
#include <stdlib.h>  // atol()

DIAG_DEFINE_GROUP(OcDll, true, 1);
DIAG_DECLARE_GROUP(OcRefCount);

#if defined(BI_APP_DLL)
  extern TRegistrar* DllRegistrar;
#endif

void TXRegistry::Check(long stat, const char* key)
{
  if (stat != 0 && !InstanceCount) {
    if (stat == 1)      // default bool true to a generic E_FAIL
      stat = E_FAIL;
    char buf[100];
    wsprintf(buf, "Registry failure on key: %s, ErrorCode = %lX\n",
             (const char far*)key, stat); 
    WARN(stat != 0, buf);
    throw TXRegistry(buf, key);
  }
}

//____________________________________________________________________________
//
// Internal registration template table and registration item key table
//____________________________________________________________________________

char OcRegEntryHeader[] = "HKEY_CLASSES_ROOT\\";
char OcRegEntryAssign[] = " = ";

struct TRegParam {
  char*  Param;    // substituted parameter name
  char*  Default;  // default value, 0 if required
  char*  TplList;  // list of template indices to invoke
  static int Find(const char* param); // associative lookup of value by param
};

//
// Registration template table, ordering determines sequence of registration
//  note: the parameter table is dependent on template indices in this table
//
char* OcRegTemplates[] = {
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
           };

const int OcRegTemplateCount   = sizeof(OcRegTemplates)/sizeof(char*);

//
// Registration parameter table, ordering is arbitrary, parameters lowercase
//
TRegParam OcRegParams[] = {
  {"clsid",             0, ""                },// GUID standard string form
  {"progid",            0, "\001\002\003\005\006\007"},// a unique string
  {"insertable",        0, "\046\047\062\063" },// defined to publish server
  {"usage",  ocrSingleUse, ""                },// class factory registration
  {"description",       0, ""                },// human readable, 40 chars max
#if defined(BI_PLAT_WIN32)
  {"handler", "ole32.dll", "\005"            },// inproc handler
#else
  {"handler",  "ole2.dll", "\005"            },// inproc handler
#endif
  {"serverctx",         0, "\001"            },// "Local"(EXE) or "Inproc"(DLL)
  {"path",              0, ""                },// OC defaults to load path
  {"cmdline",          "", ""                },// /Automation if app class
  {"debugger",         "", ""                },// debugger to invoke server
  {"permid",            0, "\050\051\053"    },// version independent clsid
  {"permname",          0, "\052"            },// version independent progid
  {"iconindex",       "0", "\004"            },// zero-based resource icon
  {"menuname",         "", "\045"            },// 15 characters maximum
  {"appname",           0, ""                },// AppName, AuxUserType/3
  {"verb0",             0, "\010\020"        },// name of primary verb
  {"verb1",             0, "\011\021"        },
  {"verb2",             0, "\012\022"        },
  {"verb3",             0, "\013\023"        },
  {"verb4",             0, "\014\024"        },
  {"verb5",             0, "\015\025"        },
  {"verb6",             0, "\016\026"        },
  {"verb7",             0, "\017\027"        },
  {"verb8",             0, "\018\028"        },
  {"verb0opt",      "0,2", "\020"            },//generated from REGVERBOBT macro
  {"verb1opt",      "0,2", "\021"            },
  {"verb2opt",      "0,2", "\022"            },
  {"verb3opt",      "0,2", "\023"            },
  {"verb4opt",      "0,2", "\024"            },
  {"verb5opt",      "0,2", "\025"            },
  {"verb6opt",      "0,2", "\026"            },
  {"verb7opt",      "0,2", "\027"            },
  {"verb8opt",      "0,2", "\028"            },
  {"format0",           0, "\030"            },//generated from REGFORMAT macro
  {"format1",           0, "\031"            },
  {"format2",           0, "\032"            },
  {"format3",           0, "\033"            },
  {"format4",           0, "\034"            },
  {"format5",           0, "\035"            },
  {"format6",           0, "\036"            },
  {"format7",           0, "\037"            },
  {"format8",           0, "\038"            },
  {"filefmt",           0, "\055"            },// default file format name
  {"aspectall",       "0", "\040"            },// option flags for all aspects
  {"aspectcontent",     0, "\041"            },// option flags for content view
  {"aspectthumbnail",   0, "\042"            },// option flags thumbnail view
  {"aspecticon",        0, "\043"            },// option flags for icon view
  {"aspectdocprint",    0, "\044"            },// option flags docprint view
  {"extension",         0, "\057\060\061"    },// extension for shell loading
  {"version",           0, "\054"            },// app/typelib version string
  {"helpdir",           0, ""                },// help directory for typehelp
  {"typehelp",          0, ""                },// help file for type library
  {"language",          0, ""                },// set internally from func arg
  {"docflags",        "0", ""                },
  {"directory",         0, ""                },
  {"docfilter",         0, ""                },
  {"debugclsid",        0, ""/*INTERNAL GEN*/},// internal,NOT USER SPECIFIED 
  {"extraopt",         "", ""/*INTERNAL USE*/},// cmdline debug/non-debug flag
  {"debugprogid",       0, ""                },// define to force debug reg
  {"debugdesc",         0, ""                },// different string for debug
};
const int OcRegParamCount = sizeof(OcRegParams)/sizeof(TRegParam);

int TRegParam::Find(const char* param)
{
  PRECONDITION(param);

  int i = ::OcRegParamCount;
  while (--i >= 0) {
    if (strcmp(::OcRegParams[i].Param, param) == 0)
      break;
  }
  return i;
}

//____________________________________________________________________________
//
// Generate registration file image to an output stream
//____________________________________________________________________________

static int OcRegWrite(const char* key, const char* val, ostream& out)
{
  PRECONDITION(key);

  out << OcRegEntryHeader << key;
  if (val)
    out << OcRegEntryAssign << val;
  out << '\n';
  return 0;
}

long OcRegisterClass(TRegList& regInfo, HINSTANCE module, ostream& out,
                     TLangId lang, char* filter, TRegItem* defaults,
                     TRegItem* extra)
{
  long docFlags = 0;
  const char* pc;
  int i;
  TRegItem* regItem;
  const int bufSize  = 512;
  const int pathSize = 512;
  const int langSize = 10;
  const int guidSize = 64;
  struct _buf {
    char* buf;
    _buf() { buf = new char[ bufSize + pathSize + langSize + guidSize
                           + OcRegTemplateCount * sizeof(char)
                           + OcRegParamCount * sizeof(char*) ]; }
   ~_buf() {delete[] buf;}
    operator char*() {return buf;}
  } buf;
  char*  path = buf + bufSize;
  char*  langBuf = path + pathSize;
  char*  guidBuf = langBuf + langSize;
  signed char* tplEnab = (signed char*)(guidBuf + guidSize);
  const char** paramVal = (const char**)(tplEnab + OcRegTemplateCount);
  ::GetModuleFileName(module, path, pathSize);

  // Check to see if the reg format buffer overflowed during startup
  //
  if (TRegItem::Heap.Used > TRegItem::Heap.Size) {
    const char frmt[] = "REGISTRATION_FORMAT_BUFFER Overflow. Need %d bytes total.";
    char msg[sizeof frmt + 11];
    wsprintf(msg, frmt, TRegItem::Heap.Used);
    throw TXRegistry(msg, 0);
  }

  // Check for language defaulted to system configuration
  //
  if (lang == LangSysDefault)
    lang = TLocaleString::SystemDefaultLangId;
  else if (lang == LangUserDefault)
    lang = TLocaleString::UserDefaultLangId;

  // initialize local arrays of paramater values and template enable flags
  //
  int userKeyCount = 0;
  for (i = OcRegParamCount; --i >= 0; paramVal[i] = OcRegParams[i].Default)
    ;
  if (filter) {
    memset(tplEnab, 0x80, OcRegTemplateCount);  // disable all templates
    for (pc = filter; (i = *pc++) != 0; )
      tplEnab[i-1] = 0;                         // selectively allow enable
  }
  else {
    memset(tplEnab, 0, OcRegTemplateCount);     // initialize to unselected
  }

  // assign path parameter initially to current module load path
  //
  i = TRegParam::Find("path");
  paramVal[i] = path;

  // assign server context based on whether it is an EXE or a DLL
  //
  i = TRegParam::Find("serverctx");
#if defined (BI_PTR_0_32)
  if (::GetModuleHandle(0) == module)   // check instance handle for EXE
    paramVal[i] = "Local";
  else
    paramVal[i] = "Inproc";
#else
  if (((unsigned)module | 1) == _SS) // check instance handle for 16-bit EXE
    paramVal[i] = "Local";
  else
    paramVal[i] = "Inproc";
#endif

  // assign language parameter to value passed in function argument
  //
  i = TRegParam::Find("language");
  wsprintf(langBuf, "%X", lang);
  paramVal[i] = langBuf;

  // scan through defaults list(0), user list of parameters and custom keys(1),
  // and extra list(2)
  //
  int step = 0;
  for (regItem = defaults; ; regItem++) {

    while (step <= 2 && (!regItem || (pc = regItem->Key) == 0)) {
      switch (step++) {
        case 0:
          regItem = regInfo.Items;
          break;
        case 1:
          regItem = extra;
          break;
        case 2:
          regItem = 0;
      }
    }
    if (!regItem || !pc)
      break;

    // note presence of user-specified key and value, process afterwards
    //
    if (*pc == ' ') {
      userKeyCount++;
    }
    else {
      // replace default with user-specified parameter value
      //
      TXRegistry::Check((i = TRegParam::Find(pc)) < 0, pc);
      paramVal[i] = regItem->Value.Translate(lang);

      // enable all templates invoked by parameter
      //      
      for (char* pEnab = OcRegParams[i].TplList; (i = *pEnab++) != 0; )
        tplEnab[i-1]++;
    }
  }

  // decode document template flags
  //
  if ((i = TRegParam::Find("docflags")) >= 0)
    docFlags = atol(paramVal[i]);

  // process enabled templates, substituting parameter values
  //
  regItem = regInfo.Items;
  for (int itpl = 0; itpl < OcRegTemplateCount || userKeyCount--; itpl++) {
    char* val = 0;
    char* pb = buf;
    const char* pt;
    char c;
    const char* userval = 0;
    if (itpl < OcRegTemplateCount) {  // processing standard template array
      if (tplEnab[itpl] <= 0)
        continue;
      pt = OcRegTemplates[itpl];
    }
    else {                       // now processing user-defined templates
      while (*(pt = regItem->Key) != ' ')
        regItem++;
      pt++;
      userval = regItem->Value;
    }
    do switch (c = *pt++) {
      case 0:
        *pb++ = 0;
        if (!userval)
          break;
        pt = userval;
        userval = 0;
        val = pb;
        c++;
        continue;
      case '<':
        pc = pb;
        continue;
      case '>':
        *pb = 0;
        pb = (char*)pc;
        TXRegistry::Check((i = TRegParam::Find(pc)) < 0, pc); // internal err
        TXRegistry::Check((pc = paramVal[i]) == 0, OcRegParams[i].Param);
        if (*pc == 0 && *pt == ' ')
          pt++;
        while (*pc != 0)
          *pb++ = *pc++;
        continue;
      case '=':
        while (*(pb-1) == ' ')
          pb--;
        *pb++ = 0;
        val = pb;
        while (*pt == ' ')
          pt++;
        continue;
      default:
        *pb++ = c;
    } while (c);
    OcRegWrite(buf, val, out);
  }
  return docFlags;
}

void OcRegistryUpdate(istream& in)
{
  struct TempKey {
    HKEY key;
    TempKey() {::RegOpenKey(HKEY_CLASSES_ROOT, "CLSID", &key);}
   ~TempKey() {::RegCloseKey(key);}
  } tempKey;
  while (!in.eof()) {
    char buf[512];
    char* pc;
    char* val;
    in.getline(buf, sizeof(OcRegEntryHeader));
    if (strcmp(buf,        OcRegEntryHeader) != 0)
      continue;
    in.getline(buf, sizeof(buf));
    if ((val = pc = strchr(buf, '=')) != 0) {
      while (*(pc-1) == ' ')
        pc--;
      *pc = 0;
      while (*(++val) == ' ')
        ;
    }
    else
      val = "";
    TXRegistry::Check(::RegSetValue(HKEY_CLASSES_ROOT,buf, REG_SZ,val,0),buf);
  }
}

//____________________________________________________________________________
//
// Unregister application or class from registration database
//____________________________________________________________________________

char* OcUnregParams[] = {
  "extension",    // special case: extension key needs '.' prepended
  "debugclsid",
  "debugprogid",
  "clsid",
  "progid",
  "permid",
};
const int OcUnregParamCount = sizeof(OcUnregParams)/sizeof(char*);

int OcUnregisterClass(TRegList& regInfo, TRegItem* extra)
{
  struct TempKey {
    HKEY Key;
    TempKey() {::RegOpenKey(HKEY_CLASSES_ROOT, "CLSID", &Key);}
   ~TempKey() {::RegCloseKey(Key);}
  } tempKey;
  int  errorCount = 0;

  // Loop to remove each root level key, thus cleaning up all nested keys too
  //
  for (int i = 0; i < OcUnregParamCount; i++) {
    const char* regKey = regInfo[OcUnregParams[i]];
    if (!regKey && extra && strcmp(extra->Key, OcUnregParams[i]) == 0)
      regKey = extra->Value;
    if (regKey) {
      char buff[16];
      if (i == 0) {       // special case prepending of '.' to extension
        buff[0] = '.';
        strcpy(buff+1, regKey);
        regKey = buff;
      }
      if (::RegDeleteKey(*regKey=='{' ? tempKey.Key : HKEY_CLASSES_ROOT, regKey)
          != ERROR_SUCCESS)   // }matching brace for brace counting editors
        errorCount++;         // should throw exception if certain errors?
    }
  }
  return errorCount;
}

int OcRegistryValidate(istream& in)
{
  struct TempKey {
    HKEY key;
    TempKey() {::RegOpenKey(HKEY_CLASSES_ROOT, "CLSID", &key);}
   ~TempKey() {::RegCloseKey(key);}
  } tempKey;
  int diffCount = 0;
  while (!in.eof()) {
    char entry[512];
    char buf[300];
    long bufSize = sizeof(buf);
    char* pc;
    char* val;
    in.getline(entry, sizeof(OcRegEntryHeader));
    if (strcmp(entry,        OcRegEntryHeader) != 0)
      continue;
    in.getline(entry, sizeof(entry));
    if ((val = pc = strchr(entry, '=')) != 0) {
      while (*(pc-1) == ' ')
        pc--;
      *pc = 0;
      while (*(++val) == ' ')
        ;
    }
    if (::RegQueryValue(HKEY_CLASSES_ROOT,entry,buf,&bufSize) != ERROR_SUCCESS
        || (val && strcmp(val, buf) != 0))
      diffCount++;
  }
  return diffCount;
}

//____________________________________________________________________________
//
// Separate debugging registration for application and documents
// Overrides non-debug values with values from debug keys
//____________________________________________________________________________

struct DebugRegKey { enum {  progid,        clsid,  description,   extraopt};};
char* OcReplaceKeys[] =  {  "progid",      "clsid","description", "extraopt"};
char* OcDebugKeys[] = {"debugprogid", "debugclsid","debugdesc",   "debugopt"};
const int DebugReplaceCount = sizeof(OcReplaceKeys)/sizeof(char*);

TRegItem OcRegNoDebug[] = { {"debugger", {""}}, {0,{0}} };
TRegItem OcRegNotDll[]  = { {"cmdline", {""}}, {"debugger", {""}}, {0,{0}} };
char AppDebugFilter[] = "\001\002\003\005\006\007";
char DocDebugFilter[] = "\001\002\003\005\006\007"
                        "\020\021\022\023\024\025\026\027"
                        "\030\031\032\033\034\035\036\037"
                        "\040\041\042\043\044\045\046\047"
                        "\054\055\062\063";

int OcSetupDebugReg(TRegList& regInfo, TRegItem* regDebug, TLangId lang,
                    char* clsid)
{
  int stat = -1;  // initialize for user-supplied clsid
  char** oldKey = OcReplaceKeys;
  char** newKey = OcDebugKeys;
  for (int i = 0; i < DebugReplaceCount; i++,oldKey++,newKey++,regDebug++) {
    const char* value = regInfo.Lookup(*newKey, lang);
    if (!value) {
      switch(i) {
        case DebugRegKey::progid:
          return 0;                   // no debug registration
        case DebugRegKey::extraopt:
          value = " /Debug";
          break;
        case DebugRegKey::clsid:
          if (clsid) {
            value = clsid;
            stat = 1;    // flag use of supplied clsid
            break;
          } // else fall through to throw exception
        case DebugRegKey::description:
          TXRegistry::Check(1, *newKey); // incomplete debug registration
      }
    }
    regDebug->Key  = *oldKey;
    regDebug->Value = value;
  }
  regDebug->Key = 0;    // null-terminate reg list
  return stat;
}

//____________________________________________________________________________
//
// TRegistrar - Application registration manager interface class
//____________________________________________________________________________

TRegistrar* TRegistrar::RegistrarList = 0;

TRegistrar::TRegistrar(TRegList& regInfo, TComponentFactory callback,
                       string& cmdLine, HINSTANCE hInst)
:
  AppDesc(*new TAppDescriptor(regInfo, callback, cmdLine, hInst))
{
  Next = RegistrarList;
  RegistrarList = this;
  TRACEX(OcRefCount, 1, "TRegistrar() @" << (void*)this);
}

TRegistrar::TRegistrar(TAppDescriptor& appDesc) : AppDesc(appDesc)
{
  Next = RegistrarList;
  RegistrarList = this;
}

TRegistrar::~TRegistrar()
{
  // since TRegistrars are destroyed when the module is shutdown
  // we do not need to detach each registrar from the linked list
  delete &AppDesc;
}

TRegistrar* TRegistrar::GetNext(TRegistrar* reg)
{
  return reg ? reg->Next : RegistrarList;
}

void far* TRegistrar::GetFactory(const GUID& clsid, const GUID far& iid)
{
  void far* retObj = 0;
  if (clsid != AppDesc.AppClassId)
    return 0;
  ((IUnknown&)AppDesc).QueryInterface(iid, &retObj);
  return retObj;   // QueryInterface sets to null if fails
}

bool TRegistrar::CanUnload()
{
  return static_cast<bool>(!AppDesc.IsBound());
}

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

  // app is now running its message loop, factory may get called again by OLE
  //
  ifc = factory(ifc, GetOptions() | amShutdown);  // EXE finished, destroy it
  if (ifc && !(GetOptions() & amServedApp))
    ifc->Release();  // we own the reference count, else container released it
  return 0;
}

void TRegistrar::Shutdown(IUnknown* releasedObj, uint32 options)
{
  if (!AppDesc.GetFactory())
    return;
  releasedObj = AppDesc.GetFactory()(releasedObj, options|amShutdown);
  if (releasedObj)
    releasedObj->Release();
}

//____________________________________________________________________________
//
// DLL server entry points
//____________________________________________________________________________

//
// Entry point for complete registration management via command line
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
STDAPI __export DllCanUnloadNow(void)
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

