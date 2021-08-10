//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.15  $
//
// TServedObject implementation and OLE Type library generation
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#if !defined(OCF_APPDESC_H)
# include <ocf/appdesc.h>
#endif
#if !defined(SERVICES_MEMORY_H)
# include <services/memory.h>
#endif
#if !defined(OCF_OCCTRL_H) && defined(BI_PLAT_WIN32)
# include <ocf/occtrl.h>
#endif

#if defined(BI_PLAT_WIN32)
# define OLE_TYPELIB_FILE L"stdole32.tlb"
#elif defined(BI_PLAT_WIN16)
# define OLE_TYPELIB_FILE "stdole.tlb"
#endif

//____________________________________________________________________________
//
// TypeLibrary generation
//____________________________________________________________________________

// local class to hold ICreateTypeLib interface pointers for each class

struct TOleCreateInfo {
  int FuncCount;
  int VarCount;
  int ImplCount;
  TYPEKIND TypeKind;
  ITypeInfo*       OurTypeInfo;  // our type info implementation
  ITypeInfo*       OleTypeInfo;  // type info obtained from ICreatTypeInfo
  ICreateTypeInfo* CreateInfo;   // interface obtained from ICreateTypeLib
  TOleCreateInfo() : OurTypeInfo(0), OleTypeInfo(0), CreateInfo(0) {}
 ~TOleCreateInfo();
};

TOleCreateInfo::~TOleCreateInfo()
{
  if (OurTypeInfo)
    OurTypeInfo->Release();
  if (OleTypeInfo)
    OleTypeInfo->Release();
  if (CreateInfo)
    CreateInfo->Release();
}

struct TOleCreateList {
  int             Count;
  ITypeLib*       TypeLib;
  const char far* FileName;
  TOleCreateInfo* List;
  ITypeLib*       OleLib;
  ITypeComp*      OleComp;
  ITypeInfo*      OleInfo;
  ICreateTypeLib* CreateLib;
  TLIBATTR far*   LibAttr;
  TYPEATTR far*   TypeAttr;
  ITypeInfo*      AttrTypeInfo;  // valid only when TypeAttr!=0, not refcnt'd
  TBSTR* FuncNames;              // temporary transfer of BSTR name arrays

  TOleCreateList(ITypeLib* typeLib, const char far* fileName);
  void FixupTypeDescRef(int typeIndex, TYPEDESC far& typeDesc);
  void Close(const char far* helpDir);
  void Clear();
 ~TOleCreateList() {Clear();}
};

TOleCreateList::TOleCreateList(ITypeLib* typeLib, const char far* fileName)
:
  TypeLib(typeLib),
  FileName(fileName),
  OleLib(0), OleComp(0), OleInfo(0),
  CreateLib(0), TypeAttr(0), LibAttr(0), List(0), FuncNames(0)
{
  TBSTR libName;
  TBSTR libDoc;
  TBSTR helpFile;
  ulong helpId;
  TypeLib->AddRef();
  OLECALL(::LoadTypeLib(OLE_TYPELIB_FILE, &OleLib), "Load stdole.tlb");
  OLECALL(OleLib->GetTypeComp(&OleComp), "GetTypeComp");
  ITypeComp* tempComp;     // required as reference arg, but always set to 0
  OLECALL(OleComp->BindType(OleText("IDispatch"),
                            ::LHashValOfName(0, OleText("IDispatch")),
                            &OleInfo,&tempComp), "BindType");
  OLECALL(TypeLib->GetLibAttr(&LibAttr), "GetLibAttr");
  OLECALL(TypeLib->GetDocumentation(-1, libName, libDoc, &helpId, helpFile),
                                         "GetDocumentation for library");
  OLECALL(::CreateTypeLib(LibAttr->syskind, OleStr((char far*)FileName), &CreateLib), "CreateTypeLib");
  OLECALL(CreateLib->SetGuid(LibAttr->guid), "Set TypeLib GUID");
  OLECALL(CreateLib->SetLcid(LibAttr->lcid), "Set TypeLib language");
  OLECALL(CreateLib->SetLibFlags(LibAttr->wLibFlags), "Set TypeLib flags");
  if (!!libName)
    OLECALL(CreateLib->SetName(libName), "Set TypeLib name");
  if (!!libDoc)
    OLECALL(CreateLib->SetDocString(libDoc), "Set TypeLib doc");
  if (!!helpFile)
  {
    OLECALL(CreateLib->SetHelpFileName(helpFile), "SetHelpFileName");
    OLECALL(CreateLib->SetHelpContext(helpId), "HelpContext");
  }
  OLECALL(CreateLib->SetVersion(LibAttr->wMajorVerNum,
                                LibAttr->wMinorVerNum), "Set TypeLib version");
  //  allocate all ITypeInfo's upfront to force consistent references
  Count = TypeLib->GetTypeInfoCount();
  List = new TOleCreateInfo[Count];
  for (int nInfo = 0; nInfo < Count; nInfo++) {
    TOleCreateInfo& info = List[nInfo];
    ICreateTypeInfo* newInfo;
    OLECALL(TypeLib->GetTypeInfo(nInfo, &AttrTypeInfo), "GetTypeInfo");
    info.OurTypeInfo = AttrTypeInfo;
    OLECALL(info.OurTypeInfo->GetTypeAttr(&TypeAttr), "GetTypeAttr");
    OLECALL(TypeLib->GetDocumentation(nInfo,libName,libDoc,&helpId,helpFile),
                                             "GetDocumentation for TypeInfo");
    OLECALL(CreateLib->CreateTypeInfo(libName, TypeAttr->typekind, &newInfo),
                                   "Create CreateTypeInfo");
    info.CreateInfo = newInfo;
    OLECALL(newInfo->QueryInterface(IID_ITypeInfo,
           (void far*far*)&info.OleTypeInfo), "QueryInterface for ITypeInfo");
    if (!!libDoc)
      OLECALL(newInfo->SetDocString(libDoc), "Set TypeInfo doc");
    OLECALL(newInfo->SetHelpContext(helpId), "SetHelpContext");
    OLECALL(newInfo->SetVersion(TypeAttr->wMajorVerNum,
                                  TypeAttr->wMinorVerNum),"Set TypeInfo version");
    OLECALL(newInfo->SetGuid(TypeAttr->guid), "SetTypeInfo GUID");
    OLECALL(newInfo->SetTypeFlags(TypeAttr->wTypeFlags), "SetTypeFlags");
    if (TypeAttr->typekind == TKIND_DISPATCH) {
      HREFTYPE hreftype;
      OLECALL(newInfo->AddRefTypeInfo(OleInfo, &hreftype), "AddRefTypeInfo");
      OLECALL(newInfo->AddImplType(0, hreftype), "AddImplType");
    }
    info.TypeKind  = TypeAttr->typekind;
    info.FuncCount = TypeAttr->cFuncs;
    info.VarCount  = TypeAttr->cVars;
    info.ImplCount = TypeAttr->cImplTypes;
    info.OurTypeInfo->ReleaseTypeAttr(TypeAttr), TypeAttr = 0;
  }
}

void TOleCreateList::Close(const char far* helpDir)
{
  OLECALL(CreateLib->SaveAllChanges(), "Write and close TypeLib file");
  CreateLib->Release();
  CreateLib = 0;
  OLECALL(::RegisterTypeLib(TypeLib,
                            OleStr((char far*)FileName),
                            OleStr((char far*)helpDir)),
          "Register type library");
}

void TOleCreateList::Clear()
{
  delete[] List;  // releases all interface pointers
  delete[] FuncNames;  // in case exception thrown while in use
  if (LibAttr)
    TypeLib->ReleaseTLibAttr(LibAttr);
  if (TypeAttr)
    AttrTypeInfo->ReleaseTypeAttr(TypeAttr);
  if (OleInfo)
    OleInfo->Release();
  if (OleComp)
    OleComp->Release();
  if (OleLib)
    OleLib->Release();
  if (CreateLib)
    CreateLib->Release();
  TypeLib->Release();  // finally release typelib called at constructor
}

void
TOleCreateList::FixupTypeDescRef(int typeIndex, TYPEDESC far& typeDesc)
{
  if (typeDesc.vt == VT_USERDEFINED) {
    ITypeInfo* refInfo;
    OLECALL(List[typeIndex].OurTypeInfo->GetRefTypeInfo(typeDesc.hreftype,
                                                 &refInfo), "GetRefTypeInfo");
    refInfo->Release();   // ok to release here, we're only using its pointer
    for (int nInfo = 0; nInfo < Count; nInfo++) {
       if (List[nInfo].OurTypeInfo == refInfo) {
         OLECALL(List[typeIndex].CreateInfo->AddRefTypeInfo(List[nInfo].OleTypeInfo,
                                       &typeDesc.hreftype), "AddRefTypeInfo");
         return;
       }
    }
    OLECALL(HR_TYPE_ELEMENTNOTFOUND, "Unknown reference type");
  }
}

void
TAppDescriptor::WriteTypeLibrary(TLangId lang, const char far* file)
{
  TServedObject* servedObject;
  TBSTR libName;
  TBSTR libDoc;
  ulong helpId;
  FUNCDESC far* funcDesc = 0;
  VARDESC far* varDesc = 0;
  TOleCreateList typeList(new TTypeLibrary(*this, lang), file);
  for (int nInfo = 0; nInfo < typeList.Count; nInfo++) {
    TOleCreateInfo& curInfo = typeList.List[nInfo];
    ITypeInfo* typeInfo = curInfo.OurTypeInfo;
    ICreateTypeInfo* newInfo  = curInfo.CreateInfo;
    int index;
    for (index = 0; index < curInfo.FuncCount; index++) {
      OLECALL(typeInfo->GetFuncDesc(index, &funcDesc), "GetFuncDesc");
      // Using the GetDocumentation call fails when creating a typelib, so attempt to
      // use the function GetFuncDocFromIndex to get around this problem
      servedObject = dynamic_cast<TServedObject*>(typeInfo);
      if (servedObject)
        OLECALL(servedObject->GetFuncDocFromIndex(index, libName, libDoc,
                                                  &helpId, 0), "Get method name and doc");
      else
        OLECALL(typeInfo->GetDocumentation(funcDesc->memid, libName, libDoc,
                                           &helpId, 0), "Get method name and doc");
      for (int nArg = funcDesc->cParams; nArg-- >=0; ) {
        ELEMDESC far* elem = nArg < 0 ? &funcDesc->elemdescFunc
                                      : &funcDesc->lprgelemdescParam[nArg];
        typeList.FixupTypeDescRef(nInfo, elem->tdesc);
      }
      OLECALL(newInfo->AddFuncDesc(index, funcDesc), "AddFuncDesc");
      unsigned nNames = funcDesc->cParams + 1;
      typeList.FuncNames = new TBSTR[nNames];
      OLECALL(typeInfo->GetNames(funcDesc->memid, (BSTR*)typeList.FuncNames,
                              nNames, &nNames), "Get method parameter names");
      OLECALL(newInfo->SetFuncAndParamNames(index, (BSTR*)typeList.FuncNames,
                                       nNames), "Set method parameter names");
      delete[] typeList.FuncNames;
      typeList.FuncNames = 0;
      if (!!libDoc)
        OLECALL(newInfo->SetFuncDocString(index, libDoc),"Set method doc");
      OLECALL(newInfo->SetFuncHelpContext(index, helpId), "HelpContext");
      typeInfo->ReleaseFuncDesc(funcDesc), funcDesc = 0;
    }
    for (index = 0; index < curInfo.VarCount; index++) {
      OLECALL(typeInfo->GetVarDesc(index, &varDesc), "GetVarDesc");
      // Using the GetDocumentation call fails when creating a typelib, so attempt to
      // use the function GetVarDocFromIndex to get around this problem
      servedObject = dynamic_cast<TServedObject*>(typeInfo);
      if (servedObject)
        OLECALL(servedObject->GetVarDocFromIndex(index, libName, libDoc,
                                                 &helpId, 0), "Get propery name and doc");
      else
        OLECALL(typeInfo->GetDocumentation(varDesc->memid, libName, libDoc,
                                           &helpId, 0), "Get propery name and doc");
      typeList.FixupTypeDescRef(nInfo, varDesc->elemdescVar.tdesc);
      OLECALL(newInfo->AddVarDesc(index, varDesc), "AddVarDesc");
      OLECALL(newInfo->SetVarName(index, libName),"Set property name");
      if (!!libDoc)
        OLECALL(newInfo->SetVarDocString(index, libDoc),"Set property doc");
      OLECALL(newInfo->SetVarHelpContext(index, helpId), "HelpContext");
      typeInfo->ReleaseVarDesc(varDesc), varDesc = 0;
    }
    if (curInfo.TypeKind == TKIND_COCLASS) {
      for (index = 0; index < curInfo.ImplCount; index++) {
        HREFTYPE hreftype;
        ITypeInfo* refInfo;
        OLECALL(typeInfo->GetRefTypeOfImplType(index, &hreftype),"GetCoClassRef");
        OLECALL(typeInfo->GetRefTypeInfo(hreftype, &refInfo), "GetCoClassTypeInfo");
        refInfo->Release();   // ok to release here, only using its pointer
        for (int iInfo = 0; iInfo < typeList.Count; iInfo++) {
          if (typeList.List[iInfo].OurTypeInfo == refInfo) {
            OLECALL(newInfo->AddRefTypeInfo(typeList.List[iInfo].OleTypeInfo, &hreftype), "AddRefTypeInfo");
            OLECALL(newInfo->AddImplType(index, hreftype), "AddImplType");
            int implflags;
            OLECALL(typeInfo->GetImplTypeFlags(index, &implflags), "GetImplTypeFlags");
            OLECALL(newInfo->SetImplTypeFlags(index, implflags), "SetImplTypeFlags");
          }
        }
      }
    }
    OLECALL(newInfo->LayOut(), "Layout typeinfo");
  }
  const char* helpDir = RegInfo.Lookup("helpdir");
  if (!helpDir || *helpDir == 0) {
    char path [_MAX_PATH];
    char drive[_MAX_DRIVE];
    char dir  [_MAX_DIR];
    ::GetModuleFileName(AppInstance, path, sizeof(path));
    _splitpath(path, drive, dir, 0, 0);
    _makepath (path, drive, dir, 0, 0);
    helpDir = path;
  }
  typeList.Close(helpDir);

  int iGuid = 0;   // first pass for app, second for debug app if present
  do {
    char buf[80];
    strcpy(buf, "CLSID\\");
    strcat(buf, AppClassId[iGuid]);
    strcat(buf, "\\TypeLib");
    ::RegSetValue(TRegKey::ClassesRoot,buf,REG_SZ, AppClassId[LibGuidOffset], 0);
    iGuid ^= DebugGuidOffset;    // remains 0 if no debug guid assigned
  } while (iGuid);
}

//____________________________________________________________________________
//
// TTypeLibrary implementation
//____________________________________________________________________________

TTypeLibrary::TTypeLibrary(TAppDescriptor& appDesc, TLangId lang)
               : AppDesc(appDesc), Lang(lang), RefCnt(0)
{
  CoClassFlags = 0;
  CoClassImplCount = 0;
  TAutoClass::TAutoClassRef* ref = AppDesc.ClassList;
  for (int index = 0; index < AppDesc.ClassCount; index++, ref++) {
    TAutoClass* cls = ref->Class;
    int    implFlags = cls->GetImplTypeFlags();
    uint16 typeFlags = cls->GetCoClassFlags();
    if (implFlags != 0 || typeFlags != 0) {
      CoClassImplCount++;
      CoClassFlags |= typeFlags;
    }
  }
}

TTypeLibrary::~TTypeLibrary()
{
  if (AppDesc.TypeLib == this)
    AppDesc.TypeLib = 0;    // remove pointer to this
  if (RefCnt > 0)
    ::CoDisconnectObject(this,0);   // should not normally happen
}

ITypeInfo*
TTypeLibrary::CreateCoClassInfo()
{
  ITypeInfo* ifc = new TCoClassInfo(AppDesc, CoClassFlags, CoClassImplCount);
  ifc->AddRef();
  return ifc;
}

HRESULT _IFUNC
TTypeLibrary::QueryInterface(const IID far& riid, void far* far* retIface)
{
  if (riid == IID_IUnknown || riid == IID_ITypeLib) {
    AddRef();
    *retIface = (IUnknown*)this;
    return HR_NOERROR;
  }
  *retIface = 0;
  return HR_NOINTERFACE;
}

unsigned long _IFUNC

TTypeLibrary::AddRef()
{
  return ++RefCnt;
}

unsigned long _IFUNC
TTypeLibrary::Release()
{
  if (--RefCnt != 0)
    return RefCnt;
  delete this;
  return 0;
}

unsigned int _IFUNC
TTypeLibrary::GetTypeInfoCount()
{
  return AppDesc.GetClassCount() + (CoClassImplCount > 0);  // +1 for CoClass
}

HRESULT _IFUNC
TTypeLibrary::GetTypeInfo(unsigned index, ITypeInfo* far* retInfo)
{
  if (CoClassImplCount > 0 && index == AppDesc.GetClassCount()) {
    *retInfo = CreateCoClassInfo();
  } else {
    TAutoClass* cls = AppDesc.GetAutoClass(index);
    if (!cls)
      return HR_TYPE_ELEMENTNOTFOUND;
    *retInfo = AppDesc.CreateITypeInfo(*cls);
  }
  return HR_NOERROR;
}

HRESULT _IFUNC
TTypeLibrary::GetTypeInfoType(unsigned index, TYPEKIND far* retKind)
{
  unsigned int count = AppDesc.GetClassCount();
  if (index > count)
    return HR_TYPE_ELEMENTNOTFOUND;
  *retKind = (index == count ? TKIND_COCLASS : TKIND_DISPATCH);
  return HR_NOERROR;
}

HRESULT _IFUNC
TTypeLibrary::GetTypeInfoOfGuid(const GUID far& guid, ITypeInfo* far* retInfo)
{
  if (AppDesc.AppClassId.GetOffset(guid) == 0) {
    *retInfo = CreateCoClassInfo();
  } else {
    TAutoClass* cls = AppDesc.GetAutoClass(guid);
    if (!cls)
      return HR_TYPE_ELEMENTNOTFOUND;
    *retInfo = AppDesc.CreateITypeInfo(*cls);
  }
  return HR_NOERROR;
}

HRESULT _IFUNC
TTypeLibrary::GetLibAttr(TLIBATTR far* far* retAttr)
{
  TLIBATTR* libAttr = new TLIBATTR;
  memset(libAttr, 0, sizeof(TLIBATTR));
#if defined(BI_PLAT_WIN32)
  libAttr->syskind = SYS_WIN32;
#elif defined(BI_PLAT_WIN16)
  libAttr->syskind = SYS_WIN16;
#endif
  libAttr->lcid = Lang;
  AppDesc.GetClassId(0, libAttr->guid);
  libAttr->wMajorVerNum = AppDesc.GetVersionField(0);
  libAttr->wMinorVerNum = AppDesc.GetVersionField(1);
  *retAttr = libAttr;
  return HR_NOERROR;
}

void _IFUNC
TTypeLibrary::ReleaseTLibAttr(TLIBATTR far* attr)
{
  delete attr;
}

HRESULT _IFUNC
TTypeLibrary::GetTypeComp(ITypeComp* far* /*retComp*/)
{
  return HR_TYPE_UNSUPFORMAT;
}

HRESULT _IFUNC
TTypeLibrary::GetDocumentation(int index, BSTR far* retName,
                               BSTR far* retDoc,
                               ulong far* retHelpContext,
                               BSTR far* retHelpFile)
{
  if (retHelpFile)
     *retHelpFile = NS_CLASSLIB::SysAllocString(AppDesc.GetHelpFile(Lang));
  if (retHelpContext)
     *retHelpContext = 0;
  if (index == -1 || index == AppDesc.GetClassCount()) { // library itself
    if (retName)
      *retName = NS_CLASSLIB::SysAllocString(AppDesc.GetAppName(Lang));
    if (retDoc)
      *retDoc  = NS_CLASSLIB::SysAllocString(AppDesc.GetAppDoc(Lang));
    if (retHelpContext)
      *retHelpContext = 0;
  } else {
    TAutoClass* cls = AppDesc.GetAutoClass(index);
    if (!cls)
      return HR_TYPE_ELEMENTNOTFOUND;
    if (retName)
      *retName = NS_CLASSLIB::SysAllocString(cls->GetName(Lang));
    if (retDoc)
      *retDoc  = NS_CLASSLIB::SysAllocString(cls->GetDoc(Lang));
    if (retHelpContext)
      *retHelpContext = cls->GetHelpId();
  }
  return HR_NOERROR;
}

HRESULT _IFUNC
TTypeLibrary::IsName(OLECHAR far* nameBuf, ulong /*hashVal*/, int far* retFound)
{
  TAutoClass::TAutoClassRef* ref = AppDesc.ClassList;
  for (int index = 0; index < AppDesc.ClassCount; index++, ref++) {
    TAutoClass* cls = ref->Class;
    // not clear from doc if we should check names of classes as well as members
    long id;
    TAutoSymbol* sym = cls->Lookup(OleStr(nameBuf), Lang, asOleType, id);
    if (sym) {
#if defined(BI_OLECHAR_WIDE)
      lstrcpyW(nameBuf, OleStr(sym->Name));
#else
      strcpy(nameBuf, sym->Name);
#endif
      *retFound = 1;
      return HR_NOERROR;
    }
  }
  return ResultFromScode(TYPE_E_ELEMENTNOTFOUND);
}

HRESULT _IFUNC
TTypeLibrary::FindName(OLECHAR far* nameBuf, ulong /*lHashVal*/,
                       ITypeInfo* far* retInfo, MEMBERID far* retId,
                       unsigned short far* inoutCount)
{
  unsigned short found = 0;
  TAutoClass::TAutoClassRef* ref = AppDesc.ClassList;
  for (int index = 0; index < AppDesc.ClassCount && found < *inoutCount;
                      index++, ref++) {
    TAutoClass* cls = ref->Class;
    long id;
    TAutoSymbol* sym = cls->Lookup(OleStr(nameBuf), Lang, asOleType, id);
    if (sym) {
      retId[found] = id;
      retInfo[found] = AppDesc.CreateITypeInfo(*cls);
      found++;
    }
  }
  *inoutCount = found;
  return found ? HR_NOERROR : HR_TYPE_ELEMENTNOTFOUND;
}

//____________________________________________________________________________
//
// TCoClassInfo implementation
//____________________________________________________________________________

TCoClassInfo::TCoClassInfo(TAppDescriptor& appDesc, uint16 typeFlags, int implCount)
: AppDesc(appDesc), RefCnt(0), TypeFlags(typeFlags), ImplCount(implCount)
{
  ImplList = new unsigned[implCount];
  TAutoClass::TAutoClassRef* ref = AppDesc.ClassList;
  int iapp     = -1;
  int ievent   = -1;
  Default      = -1;
  DefaultEvent = -1;
  int iclass   =  0;
  for (int index = 0; iclass < implCount; index++, ref++) {
    TAutoClass* cls = ref->Class;
    int    implFlags = cls->GetImplTypeFlags();
    uint16 typeFlags = cls->GetCoClassFlags();
    if (implFlags || typeFlags) {
      if (implFlags & IMPLTYPEFLAG_FSOURCE) {
        ievent = iclass;
        if (implFlags & IMPLTYPEFLAG_FDEFAULT)
          DefaultEvent = iclass;
      } else {
        if (typeFlags & TYPEFLAG_FAPPOBJECT)
          iapp = iclass;
        if (implFlags & IMPLTYPEFLAG_FDEFAULT)
          Default = iclass;
      }
      ImplList[iclass++] = index;
    }
  }
  if (Default == -1)
    Default = iapp;
  if (DefaultEvent == -1)
    DefaultEvent = ievent;
}

TCoClassInfo::~TCoClassInfo()
{
  delete ImplList;
}

HRESULT _IFUNC
TCoClassInfo::QueryInterface(const IID far& riid, void far* far* retIface)
{
  if (riid == IID_IUnknown || riid == IID_ITypeInfo) {
    AddRef();
    *retIface = (IUnknown*)this;
    return HR_NOERROR;
  }
  *retIface = 0;
  return HR_NOINTERFACE;
}

unsigned long _IFUNC

TCoClassInfo::AddRef()
{
  return ++RefCnt;
}

unsigned long _IFUNC
TCoClassInfo::Release()
{
  if (--RefCnt != 0)
    return RefCnt;
  delete this;
  return 0;
}

HRESULT _IFUNC
TCoClassInfo::GetTypeAttr(TYPEATTR far* far* retTypeAttr)
{
  TYPEATTR* ta = (TYPEATTR*)new char[sizeof(TYPEATTR)];
  memset(ta, 0, sizeof(TYPEATTR));
  ta->guid = AppDesc.AppClassId;
  ta->lcid = AppDesc.GetAppLang();
  ta->typekind = TKIND_COCLASS;
  ta->cImplTypes = (unsigned short)ImplCount;
  ta->wMajorVerNum = AppDesc.GetVersionField(0);
  ta->wMinorVerNum = AppDesc.GetVersionField(1);
  ta->wTypeFlags = TypeFlags;
  *retTypeAttr = ta;
  return HR_NOERROR;
}

void _IFUNC
TCoClassInfo::ReleaseTypeAttr(TYPEATTR far* ptypeattr)
{
  delete [] (char*)ptypeattr;
}

HRESULT _IFUNC
TCoClassInfo::GetDocumentation(MEMBERID memid,
                                BSTR far* retName, BSTR far* retDoc,
                                ulong far* retHelpContext,
                                BSTR far* retHelpFile)
{
  if (retHelpFile)
    *retHelpFile = NS_CLASSLIB::SysAllocString(AppDesc.GetHelpFile(AppDesc.GetAppLang()));
  if (memid == -1) {       // request info on type library itself
    if (retName)
      *retName = NS_CLASSLIB::SysAllocString(AppDesc.GetAppName(AppDesc.GetAppLang()));
    if (retDoc)
      *retDoc  = NS_CLASSLIB::SysAllocString(AppDesc.GetAppDoc(AppDesc.GetAppLang()));
    if (retHelpContext)
      *retHelpContext = 0;
  } else {
    return HR_TYPE_WRONGTYPEKIND;
  }
  return HR_NOERROR;
}

HRESULT _IFUNC
TCoClassInfo::CreateInstance(IUnknown* /*punkOuter*/, const IID far& /*riid*/,
                              void far* far* /*ppvObj*/)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TCoClassInfo::GetContainingTypeLib(ITypeLib* far* retLib,
                                                unsigned int far* retIndex)
{
  *retLib = AppDesc.GetTypeLibrary();
  if (retIndex)
    *retIndex = AppDesc.GetClassCount();
  return HR_NOERROR;
}

HRESULT _IFUNC
TCoClassInfo::GetRefTypeInfo(HREFTYPE hreftype, ITypeInfo* far* retInfo)
{
  TAutoClass* cls = (TAutoClass*)hreftype;
  if (AppDesc.GetClassIndex(cls) == -1)  // validate pointer to avoid crash
    return HR_TYPE_WRONGTYPEKIND;
  *retInfo = AppDesc.CreateITypeInfo(*cls);
  return HR_NOERROR;
}

HRESULT _IFUNC
TCoClassInfo::GetImplTypeFlags(unsigned int index, int far* retflags)
{
  TAutoClass* cls = index<ImplCount ? AppDesc.GetAutoClass(ImplList[index]):0;
  if (!cls)
    return HR_TYPE_ELEMENTNOTFOUND;
  int implFlags = cls->GetImplTypeFlags();
  if (implFlags & IMPLTYPEFLAG_FSOURCE) {
    if (index == DefaultEvent)
      implFlags |= IMPLTYPEFLAG_FDEFAULT;
  } else {
    if (index == Default)
      implFlags |= IMPLTYPEFLAG_FDEFAULT;
  }
  *retflags = implFlags;
  return HR_NOERROR;
}

HRESULT _IFUNC
TCoClassInfo::GetRefTypeOfImplType(unsigned int index,
                                    HREFTYPE far* retreftype)
{
  TAutoClass* cls = index<ImplCount ? AppDesc.GetAutoClass(ImplList[index]):0;
  *retreftype = (HREFTYPE)cls;
  return cls ? HR_NOERROR : HR_TYPE_ELEMENTNOTFOUND;
}

// The following methods of ITypeInfo are not relevant for a COCLASS typeinfo

HRESULT _IFUNC
TCoClassInfo::GetFuncDesc(unsigned int, FUNCDESC far* far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

void _IFUNC
TCoClassInfo::ReleaseFuncDesc(FUNCDESC far*)
{
}

HRESULT _IFUNC
TCoClassInfo::GetVarDesc(unsigned int, VARDESC far* far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

void _IFUNC
TCoClassInfo::ReleaseVarDesc(VARDESC far*)
{
}

HRESULT _IFUNC
TCoClassInfo::GetNames(MEMBERID, BSTR far*, unsigned int, unsigned int far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TCoClassInfo::GetIDsOfNames(OLECHAR far* far*, uint, MEMBERID far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TCoClassInfo::Invoke(void far*, MEMBERID, unsigned short, DISPPARAMS far*,
                      VARIANT far*, EXCEPINFO far*, unsigned int far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TCoClassInfo::GetTypeComp(ITypeComp* far*)
{
  return HR_TYPE_LIBNOTREGISTERED;
}

HRESULT _IFUNC
TCoClassInfo::GetMops(MEMBERID, BSTR far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TCoClassInfo::GetDllEntry(MEMBERID, INVOKEKIND, BSTR far*, BSTR far*,
                          unsigned short far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TCoClassInfo::AddressOfMember(MEMBERID, INVOKEKIND, void far* far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

