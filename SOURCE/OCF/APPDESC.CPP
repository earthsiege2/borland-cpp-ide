//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.14  $
//
// Application class factory and type library implementation
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#if !defined(OCF_APPDESC_H)
# include <ocf/appdesc.h>
#endif
#if !defined(OCF_OCREG_H)
# include <ocf/ocreg.h>
#endif
#if !defined(CLASSLIB_CMDLINE_H)
# include <classlib/cmdline.h>
#endif
#if !defined(CLASSLIB_OBJSTRM_H)
# include <classlib/objstrm.h>
#endif
#include <strstrea.h>

DIAG_DECLARE_GROUP(OcDll);

static TLangId ParseLangId(const char* text);

//----------------------------------------------------------------------------
// TAppDescriptor implementation
//

// Provides access to the AppDescriptor of this component
//
TAppDescriptor* TAppDescriptor::This = 0;

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

  // Provide direct access for destructors from component main module
  //
  This = this;
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
  // NOTE: InProc servers are multiple-user
  //
  if (Options & amExeModule) {
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
  // Check if alternate debug registration has been provided and allocated GUID
  //
  if ((Options & amExeModule) && RegInfo.Lookup("debugprogid"))
    DebugGuidOffset = AppClassId.AllocId();

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

  // Following should not normally happen - but just in case
  //
  if (RefCnt > 0)
    ::CoDisconnectObject(this,0);

  // And last, uninitialize OLE
  //
  if (Options & amExeModule)
    ::OleUninitialize();
}

// Creates a TServedObject helper object which implements an IDispatch
// implementation on behalf of the 'Application' object.
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

  // NOTE: Creator is destroyed via delegation
  //
  Creator = new TServedObjectCreator(*this);

  // NOTE : Object is created with ref. count of '0'
  //
  TUnknown* obj = Creator->CreateObject(objDesc, outer);

  // NOTE: OLE's 'RegisterActiveObject' will do an 'AddRef()'
  //
  RegisterObject(objDesc);

  // NOTE: Object will be RefCnt++ when aggregated or converted to IUnknown*
  //
  return obj;
}

// Releases the helper object (TServedObject) implementing IDispatch on behalf
// of the 'Application' object.
//
void
TAppDescriptor::ReleaseAutoApp(TObjectDescriptor app)
{
  TServedObject* obj;
  if (ActiveObject && (obj = FindServed(app)) != 0 && obj == ActiveObject)
    UnregisterObject();
}

// Creates a TServedObject helper which implements IDispatch on behalf of
// the class described via the 'objDesc' parameter.
// NOTE: The returned object initial ref. count is '0'.
//
TUnknown*
TAppDescriptor::CreateAutoObject(TObjectDescriptor objDesc, TServedObject& app,
                                 IUnknown* outer)
{
  return app.Creator.CreateObject(objDesc, outer);
}

// Creates a TServedObject helper which implements IDispatch on behalf of the
// class instance passed in via 'obj' and 'objInfo' parameters.
//
TUnknown*
TAppDescriptor::CreateAutoObject(const void* obj, const typeinfo& objInfo,
                                 const void* app, const typeinfo& appInfo,
                                 IUnknown* outer)
{
  TServedObject* autoApp = FindServed(MostDerived(app, appInfo));
  TServedObjectCreator *creator = autoApp ? &(autoApp->Creator) : Creator;
  if (!creator) {
    // NOTE: Destroyed through delegation
    //
    Creator = new TServedObjectCreator(*this);
    creator = Creator;
  }

  TAutoClass::TAutoClassRef* ref = ClassList;
  for (int i = 0; i < ClassCount; i++, ref++)
    if (objInfo == ref->Class->TypeInfo)
      return creator->CreateObject(TObjectDescriptor(obj, *ref->Class), outer);
  return 0;
}

// QueryInterface: Hands out IUnknown or IClassFactory
//
HRESULT _IFUNC
TAppDescriptor::QueryInterface(const IID& riid, void** retIface)
{
  if (riid == IID_IUnknown || riid == IID_IClassFactory) {
    AddRef();
    *retIface = (IUnknown*)this;
    return HR_NOERROR;
  }
  *retIface = 0;
  return HR_NOINTERFACE;
}

// Usual IUnknown 'AddRef'
//
ulong _IFUNC
TAppDescriptor::AddRef()
{
  return ++RefCnt;
}

// Usual IUnknown 'Release'
// NOTE: This object does *NOT* delete itself
//
ulong _IFUNC
TAppDescriptor::Release()
{
  return --RefCnt;
}

//
//
//
HRESULT _IFUNC
TAppDescriptor::CreateInstance(IUnknown* outer, const IID& riid,
                               void** ppv)
{

#if   0  

  // Display which interface is being asked for
  //
  const char* p = OCFStringFromIID(riid);

  TOcOleCtl* oleCtl = new TOcOleCtl(outer);
  return SUCCEEDED(oleCtl->QueryInterface(riid, ppv));

#else

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

    // Cannot return outer if aggregated
    //
    if (riid == IID_IUnknown) {
      *ppv = obj;
      return HR_OK;
    }
    HRESULT stat = obj->QueryInterface(riid, ppv);
    obj->Release();
    return stat;
  }
  catch (...) {
    // NOTE: Cannot throw any exception through OLE
    //       We'll assume a resource problem;
    //       Is there a better error code to express an exception ??
    //
    return HR_OUTOFMEMORY;
  }

#endif
}

// LockServer [IClassFactory]
//
HRESULT _IFUNC
TAppDescriptor::LockServer(int lock)
{
  if (lock)
    LockCount++;
  else {
    // NOTE: Should we notify app when count reaches 0?
    //
    LockCount--;
  }

  TRACEX(OcDll, 1, "LockServer(" << lock << ") Count:" << LockCount);

  return HR_NOERROR;
}

// Returns version as a whole number
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


// Register an EXE class object with OLE so that other applications can connect to it
//
void
TAppDescriptor::RegisterClass()
{
  int guidOffset = IsOptionSet(amDebug) ? DebugGuidOffset : 0;
  if (!RegClassHdl) {
    OLECALL(::CoRegisterClassObject(AppClassId[guidOffset], this,
                                    CLSCTX_LOCAL_SERVER,
                                    (Options & amSingleUse) ? REGCLS_SINGLEUSE :
                                                              REGCLS_MULTIPLEUSE,
                                    &RegClassHdl),
                                    "Register App class");
  }
}

// Invalidates application class registered earlier with 'RegisterClass'
//
void
TAppDescriptor::UnregisterClass()
{
  if (RegClassHdl) {
    OLECALL(::CoRevokeClassObject(RegClassHdl), "Unregister App class");
    RegClassHdl = 0;
  }
}

// Registers the helper object (TServedObject) of the class described via
// the 'app' parameter as the active object for its classId.
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

// Invalidates a helper object registers with RegisterObject earlier
//
void
TAppDescriptor::UnregisterObject()
{
  if (RegObjectHdl) {
    // NOTE: Zero before OLE call in case obj. destructor is invoked
    //
    ActiveObject = 0;
    OLECALL(::RevokeActiveObject(RegObjectHdl, 0), "Unregister App");
    RegObjectHdl = 0;
  }
}

// Returns the index of a 'TAutoClass' instance
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

// Retrieves the GUID of the specified TAutoClass instance.
// NOTE: Passing '0' as the 'cls' return the GUID of the type Library.
// Returns 'true' if successful, or 'false' otherwise.
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
  } else {
    offset = LibGuidOffset;
  }
  retId = AppClassId[offset];
  return true;
}

// Returns the GUID allocated as the specified index.
// NOTE: Will allocate a new GUID if 'index' has not been allocated yet.
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

// Returns the TAutoClass instance as the specified index.
//
TAutoClass*
TAppDescriptor::GetAutoClass(unsigned index)
{
  if (index >= ClassCount)
    return 0;
  return ClassList[index].Class;
}

// Returns the TAutoClass instance assigned the specified GUID.
//
TAutoClass*
TAppDescriptor::GetAutoClass(const GUID& clsid)
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

// Returns the 'ITypeLib' interface pointer describing the objects exposed by
// this instance of 'TAppDescriptor'.
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
        NS_OCF::OcRegisterClass(
          RegInfo, AppInstance, vstrm, lang, "\001\002\006");
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
            NS_OCF::OcRegisterClass(
              RegInfo, AppInstance, *strm, lang, 0, 0, OcRegNoDebug);
            NS_OCF::OcRegisterClass(
              RegInfo, AppInstance, *strm, lang, AppDebugFilter, 0, regDebug);
          }
          else {
            debugGuid = 0;  // if debug registration fails, use normal
          }
        }
        if (!debugGuid)
          NS_OCF::OcRegisterClass(RegInfo, AppInstance, *strm, lang, 0, 0,
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
                        NS_OCF::OcSetupDebugReg(regList, regDebug, lang,
                                                guidStr) : 0;
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
          NS_OCF::OcRegisterClass(regList, AppInstance, checkStrm, lang,
                            "\001\002\006", 0, clsInfo);
          if (NS_OCF::OcRegistryValidate(checkStrm) == 0)
            continue;
        }
        if (debugStat) {
          NS_OCF::OcRegisterClass(
            regList, AppInstance, *strm, lang, 0, regAppName, regClsid);
          if (debugStat == 1) {   // needs generated guid string
            TClassId linkClsid(GetLinkGuid(linkGuidIndex++));
            strcpy(guidStr, linkClsid);
          }
          NS_OCF::OcRegisterClass(
            regList, AppInstance, *strm, lang, DocDebugFilter, regAppName,
            regDebug);
        }
        else {
          NS_OCF::OcRegisterClass(regList, AppInstance, *strm, lang, 0,
                                  regAppName, clsInfo);
        }
        forceReg = true;
      }
    }
    if (forceReg && !regFilename)
      NS_OCF::OcRegistryUpdate(regStrm);
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
    NS_OCF::OcUnregisterClass(RegInfo, debugInfo);   // unregister app
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
        NS_OCF::OcUnregisterClass(regList, &clsItem);
      }
      else
        NS_OCF::OcUnregisterClass(regList);
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

// NOTE: 'TAppDescriptor::WriteTypeLibrary' is implemented in the
//        module TYPELIB.CPP
//

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
        int i;
        for (i = 0; i < optionTblCount; i++) {
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

    // Allocated GUID for type Library
    //
    if (!LibGuidOffset)
      LibGuidOffset = AppClassId.AllocId();

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

