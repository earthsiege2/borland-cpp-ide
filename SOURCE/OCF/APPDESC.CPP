//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.9  $
//
// Application class factory and type library implementation
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/appdesc.h>
#include <ocf/ocreg.h>
#include <classlib/cmdline.h>
#include <strstrea.h>

DIAG_DECLARE_GROUP(OcDll);

static TLangId ParseLangId(const char* text);

//----------------------------------------------------------------------------
// TAppDescriptor implementation
//

//
//
//
TAppDescriptor* TAppDescriptor::This = 0;// for components, other DLL use table

//
//
//
TAppDescriptor::TAppDescriptor(TRegList& regInfo, TComponentFactory callback,
                               string& cmdLine, HINSTANCE hInst,
                               const TRegLink* linkHead)
:
  AppClassId(regInfo), RegInfo(regInfo),
  AppInstance (hInst), LinkHead(linkHead),
  FactoryCallback(callback)
{
  Init(0);
  ProcessCmdLine(cmdLine);
}

//
//
//
void
#if defined(BI_PLAT_WIN16)
TAppDescriptor::Init(IMalloc* alloc)
#else
TAppDescriptor::Init(IMalloc*)
#endif
{
  AppProgId= &RegInfo.LookupRef("progid");
  AppName  = &RegInfo.LookupRef("appname");
  AppDoc   = &RegInfo.LookupRef("description");
  HelpFile = &RegInfo.LookupRef("typehelp");
  This = this;    // direct access for destructors from component main module
  RegClassHdl = RegObjectHdl = ClassCount = LinkGuidCount = 0;
  DebugGuidOffset = LinkGuidOffset = LibGuidOffset = 0;
  ServedList = ActiveObject = 0;
  RefCnt = 0;
  LockCount = 0;
  TypeLib = 0;
  Options = 0;
  ClassList = 0;
  //-------
  Creator = 0;

  // Determine if we are running an EXE or a DLL, initialize OLE if an EXE
  //
#if defined(BI_PLAT_WIN16)
  if ((unsigned)AppInstance + 1 == _SS) { // check instance handle for EXE
    Options = amExeModule | amExeMode;
    OLECALL(OleInitialize(alloc), "OleInitialize");
  }
#else
  if (::GetModuleHandle(0) == AppInstance) { // check instance handle for EXE
    Options = amExeModule | amExeMode;
    OLECALL(OleInitialize(0), "OleInitialize");
  }
#endif

  // Set the initial usage mode based on the reglist entry and module type
  //
  if (Options & amExeModule) {   // inproc servers are multiple-use
    const char* usage = RegInfo.Lookup("usage");
    char su[] = ocrSingleUse;
    if (usage && *usage == *su)
      Options |= amSingleUse;
  }

  // Set the app language to the one in the reglist if provided
  //
  const char* regLang = RegInfo.Lookup("language");
  AppLang = regLang ? ParseLangId(regLang) : TLocaleString::UserDefaultLangId;

  // Lookup the version, providing a default of 1.0
  //
  Version = RegInfo.Lookup("version", AppLang);
  if (!Version)
    Version = "1.0";

  // Assign GUID for debug registration
  //
  if ((Options & amExeModule) &&
      RegInfo.Lookup("debugprogid"))  // check if alternate debug registration
    DebugGuidOffset = AppClassId.AllocId();  // allocate GUID for debugging

  // Generate array of all automated classes and assign GUIDs
  //
  MergeAutoClasses();
}

//
//
//
TAppDescriptor::~TAppDescriptor()
{
  UnregisterClass();
  delete TypeLib;
  delete[] ClassList;
  This = 0;
  if (RefCnt > 0)
    ::CoDisconnectObject(this,0);   // should not normally happen
  if (Options & amExeModule)
    ::OleUninitialize();       // must happen after everything is unregistered
}

//
//
//
TUnknown*
TAppDescriptor::CreateAutoApp(TObjectDescriptor objDesc, uint32 options,
                              IUnknown* outer)
{
  if (objDesc.Destruct == TObjectDescriptor::Delete) {
    if (!(options & (amServedApp | amAutomation)))
      objDesc.Destruct = TObjectDescriptor::Quiet;
    else if (options & amExeMode)
      objDesc.Destruct = TObjectDescriptor::PostQuit;
  }
  Creator = new TServedObjectCreator(*this);  // destructed through delegation model
  TUnknown* obj = Creator->CreateObject(objDesc, outer); // RefCnt=0
  RegisterObject(objDesc);                        // OLE will do an AddRef()
  return obj;     // RefCnt++ when Aggregated or converted to IUnknown*
}

//
//
//
void
TAppDescriptor::ReleaseAutoApp(TObjectDescriptor app)
{
  TServedObject* obj;
  if (ActiveObject && (obj = FindServed(app)) != 0 && obj == ActiveObject)
    UnregisterObject();
}

//
//
//
TUnknown*
TAppDescriptor::CreateAutoObject(TObjectDescriptor objDesc, TServedObject& app,
                                 IUnknown* outer)
{
  return app.Creator.CreateObject(objDesc, outer); // RefCnt initially 0
}

//
//
//
TUnknown*
TAppDescriptor::CreateAutoObject(const void* obj, const typeinfo& objInfo,
                                 const void* app, const typeinfo& appInfo,
                                 IUnknown* outer)
{
  TServedObject* autoApp = FindServed(MostDerived(app, appInfo));
  TServedObjectCreator *creator = autoApp ? &(autoApp->Creator) : Creator;
  if (!creator) {
    Creator = new TServedObjectCreator(*this);  // destructed through delegation model
    creator = Creator;
  }

  TAutoClass::TAutoClassRef* ref = ClassList;
  for (int i = 0; i < ClassCount; i++, ref++)
    if (objInfo == ref->Class->TypeInfo)
      return creator->CreateObject(TObjectDescriptor(obj, *ref->Class), outer);
  return 0;
}

//
//
//
HRESULT _IFUNC
TAppDescriptor::QueryInterface(const IID far& riid, void far* far* retIface)
{
  if (riid == IID_IUnknown || riid == IID_IClassFactory) {
    AddRef();
    *retIface = (IUnknown*)this;
    return HR_NOERROR;
  }
  *retIface = 0;
  return HR_NOINTERFACE;
}

//
//
//
ulong _IFUNC
TAppDescriptor::AddRef()
{
  return ++RefCnt;
}

//
//
//
ulong _IFUNC
TAppDescriptor::Release()
{
  return --RefCnt;  // note: this object will not delete itself
}

//
//
//
HRESULT _IFUNC
TAppDescriptor::CreateInstance(IUnknown* outer, const IID far& riid,
                               void far* far* ppv)
{
  *ppv = 0;
  IUnknown* obj;
  if (!FactoryCallback)
    return HR_FAIL;

  try {
    // Test for special condition to force run DLL as an EXE
    //
    if (outer && outer->QueryInterface(IID_NULL, ppv) == HR_NOERROR)
      obj = FactoryCallback(0, Options | amServedApp | amExeMode | amRun);
    else
      obj = FactoryCallback(outer, Options | amServedApp);
    if (!obj)
      return HR_FAIL;
    if (Options & amSingleUse)
      UnregisterClass();
    if (riid == IID_IUnknown) {  // can't return outer if aggregated
      *ppv = obj;
      return HR_OK;
    }
    HRESULT stat = obj->QueryInterface(riid, ppv);
    obj->Release();
    return stat;
  }
  catch (...) {  // we can't throw any exception through OLE
    return HR_OUTOFMEMORY;  // probably a resource problem, better error code?
  }
}

//
//
//
HRESULT _IFUNC
TAppDescriptor::LockServer(int lock)
{
  if (lock)
    LockCount++;
  else
    LockCount--;    // should notify app when count reaches 0?

  TRACEX(OcDll, 1, "LockServer(" << lock << ") Count:" << LockCount);

  return HR_NOERROR;
}

//
//
//
uint16
TAppDescriptor::GetVersionField(unsigned field)
{
  const char* cp = Version;
  char c;
  while (field--) {
    while ((c = *cp++) != '.') {
      if (c < '0' || c > '9')
        return 0;    // terminate on null or invalid digit
    }
  }
  uint16 ver = 0;
  while ((c = *cp++) >= '0' && c <= '9')
    ver = uint16(ver * 10 + c - '0');
  return ver;
}

//
//
//
void
TAppDescriptor::RegisterClass()
{
  int guidOffset = IsOptionSet(amDebug) ? DebugGuidOffset : 0;
  if (!RegClassHdl) {
    OLECALL(::CoRegisterClassObject(AppClassId[guidOffset], this,
                      CLSCTX_LOCAL_SERVER, (Options & amSingleUse) ?
                      REGCLS_SINGLEUSE : REGCLS_MULTIPLEUSE, &RegClassHdl),
                      "Register App class");
  }
}

//
//
//
void
TAppDescriptor::UnregisterClass()
{
  if (RegClassHdl) {
    OLECALL(::CoRevokeClassObject(RegClassHdl), "Unregister App class");
    RegClassHdl = 0;
  }
}

//
//
//
bool
TAppDescriptor::RegisterObject(TObjectDescriptor app)
{
  if (ActiveObject)
    return false;
  TServedObject* obj = FindServed(app);
  if (!obj)
    return false;
  int guidOffset = IsOptionSet(amDebug) ? DebugGuidOffset : 0;

  // Refcnt may be zero, protect against AddRef/Release
  //
  obj->AdjustRefCount(+1);

  // Register object with Ole. OLE 2.02 suggests ACTIVEOBJECT_WEAK, but that
  // does not appear to provide adequate locking.
  //
  OLECALL(::RegisterActiveObject(&(IUnknown&)*obj,
                                 AppClassId[guidOffset],
                                 ACTIVEOBJECT_STRONG,
                                 &RegObjectHdl),
          "Register App as active");

  obj->AdjustRefCount(-1);
  ActiveObject = obj;
  return true;
}

//
//
//
void
TAppDescriptor::UnregisterObject()
{
  if (RegObjectHdl) {
    ActiveObject = 0;  // must zero before OLE call in case obj destructor run
    OLECALL(::RevokeActiveObject(RegObjectHdl, 0), "Unregister App");
    RegObjectHdl = 0;
  }
}

//
//
//
int
TAppDescriptor::GetClassIndex(TAutoClass* cls)
{
  TAutoClass::TAutoClassRef* ref = ClassList;
  for (int index = 0; index < ClassCount; ref++, index++) {
    if (ref->Class == cls)
      return index;
  }
  return -1;
}

//
//
//
bool
TAppDescriptor::GetClassId(TAutoClass* cls, GUID& retId)
{
  int offset;
  if (cls) {
    int index = GetClassIndex(cls);
    if (index == -1)
      return false;
    offset = ClassList[index].GuidOffset;
  } else {          // null class arg means type library itself
    offset = LibGuidOffset;
  }
  retId = AppClassId[offset];
  return true;
}

//
//
//
TClassId
TAppDescriptor::GetLinkGuid(int index)
{
  while (index >= LinkGuidCount) {
    int id = AppClassId.AllocId();
    if (!LinkGuidOffset)
      LinkGuidOffset = id;
    LinkGuidCount++;
  }
  return AppClassId[LinkGuidOffset + index];
}

//
//
//
TAutoClass*
TAppDescriptor::GetAutoClass(unsigned index)
{
  if (index >= ClassCount)
    return 0;
  return ClassList[index].Class;
}

//
//
//
TAutoClass*
TAppDescriptor::GetAutoClass(const GUID far& clsid)
{
  int offset = AppClassId.GetOffset(clsid);
  if (offset != -1) {
    TAutoClass::TAutoClassRef* ref = ClassList;
    for (int count = ClassCount; count--; ref++) {
      if (ref->GuidOffset == offset)
        return ref->Class;
    }
  }
  return 0;
}

//
// Get the document template with the given GUID
//
TRegLink*
TAppDescriptor::GetRegLink(const GUID far& clsid)
{
  int linkGuidIndex = 0;
  for (const TRegLink* link = LinkHead; link; link=link->GetNext()) {
    TRegList& regList = link->GetRegList();
    if (regList["progid"]) {
      const char* id = regList["clsid"];
      if (!id) {
        if (clsid == (GUID&)GetLinkGuid(linkGuidIndex++))
          return const_cast<TRegLink*>(link);
      }
      else {
        TClassId classId(id);
        if (clsid == (GUID&) classId)
          return const_cast<TRegLink*>(link);
      }
    }
  }

  return 0;
}

//
//
//
ITypeLib*
TAppDescriptor::GetTypeLibrary()
{
  if (!ClassCount)
    return 0;
  if (!TypeLib) {
    TypeLib = new TTypeLibrary(*this, AppLang);
  }
  ((IUnknown&)*TypeLib).AddRef();
  return TypeLib;
}

//----------------------------------------------------------------------------
// TServedObject list management
//

//
//
//
TServedObject*
TAppDescriptor::FindServed(const void far* mostDerivedObj)
{
  TServedObject* p = ServedList;
  for (; p; p = p->Next)
    if (p->RootObject == mostDerivedObj)
      break;
  return p;
}

//
//
//
TServedObject*
TAppDescriptor::FindServed(TObjectDescriptor& objDesc)
{
  if (objDesc.Object)
    return FindServed(objDesc.MostDerived());
  for (TServedObject* p = ServedList; p; p = p->Next)
    if (p->Object == 0 && p->Class == objDesc.Class)
      return p;
  return 0;
}

//
//
//
void
TAppDescriptor::AddServed(TServedObject& obj) {
  if (ServedList)
    ServedList->Prev = &obj.Next;
  obj.Next = ServedList;
  obj.Prev = &ServedList;
  ServedList = &obj;
}

//
//
//
void
TAppDescriptor::RemoveServed(TServedObject& obj) {
  *obj.Prev = obj.Next;
  if (obj.Next)
    obj.Next->Prev = obj.Prev;
}

//
//
//
void
TAppDescriptor::FlushServed() {
  while (ServedList)
    delete ServedList;
}

//
//
//
void
TAppDescriptor::InvalidateObject(const void far* obj)
{
  TServedObject* p = FindServed(obj);
  if (p) {
    p->RootObject = 0;
    p->Object = 0;
  }
}

//
//
//
void
TAppDescriptor::ReleaseObject(const void far* obj)
{
  TServedObject* p = FindServed(obj);
  if (p) {
    p->RootObject = 0;
    p->Object = 0;
    ((IUnknown&)*p).Release();   // destructs if no external connections
  }
}

//
//
//
ITypeInfo*
TAppDescriptor::CreateITypeInfo(TAutoClass& cls)
{
  TServedObjectCreator& creator = ServedList ? ServedList->Creator
                                             : *new TServedObjectCreator(*this);
  TUnknown* obj = creator.CreateObject(TObjectDescriptor(0, cls));
  IUnknown& unk = (IUnknown&)*obj;
  ITypeInfo* typeInfo = 0;
  unk.QueryInterface(IID_ITypeInfo, (void far* far*) &typeInfo);
  return typeInfo;
}

//
// Parse command line for Ole flags.
// Check for [-/] and remove options that are found. Gets option arguments
// and performs any immediate option actions
//
void
TAppDescriptor::RegisterServer(TLangId lang, const char* regFilename)
{
  try {
    TRegItem regDebug[DebugRegCount];

    // Check if registration output to Registry or to user-specified reg file
    //
    char guidStr[40];
    strstream regStrm;
    ostream* strm = &regStrm;
    bool alwaysReg = IsOptionSet(amRegServer);
    ofstream  fileStrm;
    if (regFilename) {
      fileStrm.open(regFilename);
      if (!fileStrm.good())
        throw TXRegistry(regFilename, "file");
      strm = &fileStrm;
      fileStrm << "REGEDIT\n";  // write registration file header
      alwaysReg = true;
    }
    SetOption(amUnregServer, false);// cancel unregister on reregister

    // Make sure that the app reginfo is in the registry
    //
    bool forceReg = alwaysReg;
    if (AppProgId) {       // don't attempt register app if no progid reg key
      if (!forceReg) {
        strstream vstrm;
        ::OcRegisterClass(RegInfo, AppInstance, vstrm, lang, "\001\002\006");
        if (::OcRegistryValidate(vstrm) != 0)
          forceReg = true;
      }
      if (forceReg) {
        char* debugGuid = 0;
        if (DebugGuidOffset) {                // setup reg item for debug reg
          TClassId debugClsid(AppClassId[DebugGuidOffset]);
          strcpy(guidStr, debugClsid);
          debugGuid = guidStr;
          if (::OcSetupDebugReg(RegInfo, regDebug, lang, debugGuid)) {
            ::OcRegisterClass(RegInfo, AppInstance, *strm, lang, 0, 0, OcRegNoDebug);
            ::OcRegisterClass(RegInfo, AppInstance, *strm, lang, AppDebugFilter,
                                                                    0, regDebug);
          }
          else {
            debugGuid = 0;  // if debug registration fails, use normal
          }
        }
        if (!debugGuid)
          ::OcRegisterClass(RegInfo, AppInstance, *strm, lang, 0, 0,
                            (Options & amExeModule) ? 0 : OcRegNotDll);
      }
    }

    // Write templates to registration file as needed
    //
    int linkGuidIndex = 0;
    TRegItem regAppName[2] = {{"appname",{RegInfo["appname"]}}, {0,{0}}};
    for (const TRegLink* link = LinkHead; link; link=link->GetNext()) {
      TRegList& regList = link->GetRegList();
      if (regList["progid"]) {
        char guidStr[40];
        int debugStat = (Options & amExeModule) ?
                        ::OcSetupDebugReg(regList, regDebug, lang, guidStr) : 0;
        TRegItem regClsid[3] = {{"debugger",{""}}, {"clsid",{guidStr}}, {0,{0}}};
        TRegItem* clsInfo = regClsid;
        if (!debugStat && Options & amExeModule)
          clsInfo++;     // no cancel debugger if no debugprogid
        if (!regList["clsid"]) {      // check if GUID needs to be assigned
          TClassId linkClsid(GetLinkGuid(linkGuidIndex++));
          strcpy(guidStr, linkClsid);
        }
        else {
          regClsid[1].Key = 0;  // shorten list to exclude auto-assigned clsid
        }
        if (!alwaysReg) {
          strstream checkStrm;
          ::OcRegisterClass(regList, AppInstance, checkStrm, lang,
                            "\001\002\006", 0, clsInfo);
          if (::OcRegistryValidate(checkStrm) == 0)
            continue;
        }
        if (debugStat) {
          ::OcRegisterClass(regList, AppInstance, *strm, lang, 0, regAppName, regClsid);
          if (debugStat == 1) {   // needs generated guid string
            TClassId linkClsid(GetLinkGuid(linkGuidIndex++));
            strcpy(guidStr, linkClsid);
          }
          ::OcRegisterClass(regList, AppInstance, *strm, lang, DocDebugFilter,
                                                        regAppName, regDebug);
        }
        else {
          ::OcRegisterClass(regList, AppInstance, *strm, lang, 0, regAppName, clsInfo);
        }
        forceReg = true;
      }
    }
    if (forceReg && !regFilename)
      ::OcRegistryUpdate(regStrm);
    if (forceReg)
      ::RegDeleteKey(TRegKey::ClassesRoot, "OcErr_RegServer");
  }
  catch (TXBase& xcpt) {
    ::RegSetValue(TRegKey::ClassesRoot, "OcErr_RegServer", REG_SZ, AppClassId, 0);
    if (!(Options & amQuietReg))
      throw;
  }
  return;
}

//
//
//
void
TAppDescriptor::UnregisterServer(TLangId, const char*)
{
  // Remove application and all type library info from registry
  //
  HKEY key;
  char guidStr[40];
  TRegItem debugItem = {"debugclsid", {guidStr}};
  TRegItem* debugInfo = 0;              // init to no debug registration
  if (AppProgId) {          // don't attempt unregister app if no progid reg key
    if (DebugGuidOffset) {                // setup reg item for debug reg
      TClassId debugClsid(AppClassId[DebugGuidOffset]);
      strcpy(guidStr, debugClsid);
      debugInfo = &debugItem;
    }
    ::OcUnregisterClass(RegInfo, debugInfo);   // unregister app
    if (LibGuidOffset) {
      ::RegOpenKey(TRegKey::ClassesRoot, "TypeLib", &key);
      ::RegDeleteKey(key, AppClassId[LibGuidOffset]);
      ::RegCloseKey(key);
    }
    if (ClassCount) {
      ::RegOpenKey(TRegKey::ClassesRoot, "Interface", &key);
      for (int i= 0; i < ClassCount; i++)
        ::RegDeleteKey(key, AppClassId[ClassList[i].GuidOffset]);
      ::RegCloseKey(key);
    }
  }

  // Remove templates from registration file as needed
  //
  int linkGuidIndex = 0;
  for (const TRegLink* link = LinkHead; link; link=link->GetNext()) {
    TRegList& regList = link->GetRegList();
    if (regList["progid"]) {
      if (!regList["clsid"]) {      // check if GUID needs to be computed
        TClassId linkClsid(GetLinkGuid(linkGuidIndex++));
        strcpy(guidStr, linkClsid);
        TRegItem clsItem = {"clsid", {guidStr}};
        ::OcUnregisterClass(regList, &clsItem);
      }
      else
        ::OcUnregisterClass(regList);
    }
  }
}

//
//
//
void
TAppDescriptor::SetLangId(TLangId /*prevLang*/, const char* langIdStr)
{
  AppLang = ParseLangId(langIdStr);
}

//
//
//
void
TAppDescriptor::MakeTypeLib(TLangId lang, const char* typeLibName)
{
  if (!ClassCount)
    return;

  // Write the typelib file to <typeLibName>
  //
  char fullPath[_MAX_PATH];
  char exeDrive[_MAX_DRIVE];
  char exeDir  [_MAX_DIR];
  char exeFName[_MAX_FNAME];
  char exeExt  [_MAX_EXT];
  char libDrive[_MAX_DRIVE];
  char libDir  [_MAX_DIR];
  char libFName[_MAX_FNAME];
  char libExt  [_MAX_EXT];
  ::GetModuleFileName(AppInstance, fullPath, sizeof(fullPath));
  _splitpath(typeLibName? typeLibName:"", libDrive, libDir, libFName, libExt);
  _splitpath(fullPath, exeDrive, exeDir, exeFName, exeExt);
  _makepath (fullPath,
             libDrive[0] ? libDrive : exeDrive,
             libDir[0]   ? libDir   : exeDir,
             libFName[0] ? libFName : exeFName,
             libExt[0]   ? libExt   : "OLB");

  try {
    WriteTypeLibrary(lang, fullPath);
    ::RegDeleteKey(TRegKey::ClassesRoot, "OcErr_Typelib");
  }
  catch (TXOle&) {
    ::RegSetValue(TRegKey::ClassesRoot, "OcErr_Typelib", REG_SZ, AppClassId, 0);
    if (!(Options & amQuietReg))
      throw;
  }
}

//
//
//
void
TAppDescriptor::ProcessCmdLine(string& cmdLine)
{
  struct {
    uint32 Flag;
    char*  String;
    void   (TAppDescriptor::*Action)(TLangId, const char*);
  }
  optionTbl[] = {
    { amRegServer,    "RegServer",     &TAppDescriptor::RegisterServer },
    { amUnregServer,  "UnregServer",   &TAppDescriptor::UnregisterServer },
    { amAutomation,   "Automation",    0 },
    { amEmbedding,    "Embedding",     0 },
    { amLangId,       "Language",      &TAppDescriptor::SetLangId },
    { amTypeLib,      "TypeLib",       &TAppDescriptor::MakeTypeLib },
    { amNoRegValidate,"NoRegValidate", 0 },
    { amQuietReg ,    "QuietReg",      0 },
    { amDebug,        "Debug",         0 },
    { amUnregServer,  "Unregister",    &TAppDescriptor::UnregisterServer },
  };
  const int optionTblCount = sizeof(optionTbl)/sizeof(optionTbl[0]);
  TCmdLine cmd(cmdLine.c_str());

  while (cmd.Kind != TCmdLine::Done) {
    switch (cmd.Kind) {
      default: {
        cmd.NextToken();        // ignore token, not one of ours
        break;
      }
      case TCmdLine::Option: {
        int i = 0;
        for (; i < optionTblCount; i++) {
          if (strnicmp(cmd.Token, optionTbl[i].String, cmd.TokenLen) == 0) {
            Options |= optionTbl[i].Flag;
            cmd.NextToken(true);    // eat token & get next
            if (cmd.Kind == TCmdLine::Value) {
              string optionArg(cmd.Token, 0, cmd.TokenLen);
              while (cmd.NextToken(true) == TCmdLine::Value)
                ; // eat token & get next (keep going if more Values are there)
              if (optionTbl[i].Action)
                (this->*optionTbl[i].Action)(AppLang, optionArg.c_str());
            }
            else {
              if (optionTbl[i].Action)
                (this->*optionTbl[i].Action)(AppLang, 0);
            }
            break; // out of for loop
          }
        }
        if (i >= optionTblCount)
          cmd.NextToken();        // ignore token, wasn't one of ours
        break;
      }
    }
  }
  cmdLine = cmd.GetLine();

  // Set single use if this is an automated exe server
  //
  if ((Options & (amAutomation | amExeModule)) == (amAutomation | amExeModule))
    Options |= amSingleUse;

  // Perform normal registry update if no other registry option was specified
  //
  if (!(Options & (amRegServer | amUnregServer | amNoRegValidate)))
    RegisterServer(0);
}

//
//
//
static TLangId ParseLangId(const char* text)
{
  static char HexChar[] = "0123456789ABCDEF0123456789abcdef";
  TLangId lang = 0;
  unsigned char c;
  char* pc;
  while (text && (c = *text++) != 0) {
    if ((pc = strchr(HexChar, c)) == 0)
      return 0;   // illegal character
    lang = TLangId((lang << 4) + (short(pc-HexChar) & 15));
  }
  return lang ? lang : TLocaleString::UserDefaultLangId;
}

//
//
//
void
TAppDescriptor::MergeAutoClasses()
{
  int oldCount = ClassCount;
  ClassCount = TAutoClass::ClassList.CountAutoClasses();
  if (ClassCount) {
    if (!LibGuidOffset)
      LibGuidOffset = AppClassId.AllocId();  // allocate GUID for type library
    TAutoClass::TAutoClassRef* oldList  = ClassList;
    ClassList = new TAutoClass::TAutoClassRef[ClassCount];
    TAutoClass::ClassList.MergeAutoClasses(ClassList);
    TAutoClass::TAutoClassRef* ref = ClassList;
    for (int count = ClassCount; count--; ref++) {
      if (oldCount) {
        ref->GuidOffset = oldList->GuidOffset;
        oldCount--;
        oldList++;
      }
      else {
        ref->GuidOffset = AppClassId.AllocId();
      }
    }
  }
}

//
//
//
int
TAutoClass::TClassList::CountAutoClasses()
{
  int count = Count;
  for (TExtLink* link = Link; link; link = link->Next)
    count += link->Classes->CountAutoClasses();
  return count;
}

//
//
//
TAutoClass::TAutoClassRef*
TAutoClass::TClassList::MergeAutoClasses(TAutoClass::TAutoClassRef* array)
{
  for (TAutoClass* cls = List; cls; cls = cls->NextClass, array++)
    array->Class = cls;
  for (TExtLink* link = Link; link; link = link->Next)
    array = link->Classes->MergeAutoClasses(array);
  return array;
}
