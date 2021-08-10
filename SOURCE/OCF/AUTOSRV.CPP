//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.15  $
//
// OLE Automation Server Implementation: TServedObject
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#if !defined(OCF_APPDESC_H)
# include <ocf/appdesc.h>
#endif
#if !defined(OCF_OCREG_H)
# include <ocf/ocreg.h>
#endif
#if !defined(OCF_OCCTRL_H) && defined(BI_PLAT_WIN32)
# include <ocf/occtrl.h>
#endif

//----------------------------------------------------------------------------
// TServedObject implementation
//

TServedObjectCreator::TServedObjectCreator(TAppDescriptor& appDesc)
:
  AppDesc(appDesc),
  AppObject(0)
{
}

TUnknown*
TServedObjectCreator::CreateObject(TObjectDescriptor objDesc,
                                   IUnknown* outer)
{
  TServedObject* ifc = AppDesc.FindServed(objDesc);
  if (!ifc)
    ifc = new TServedObject(objDesc, *this, outer);
  if (!AppObject)
    AppObject = ifc;
  return ifc;
}

IDispatch*
TServedObjectCreator::CreateDispatch(TObjectDescriptor objDesc, IUnknown* outer)
{
  TServedObject* obj = AppDesc.FindServed(objDesc);
  if (!obj)
    obj = new TServedObject(objDesc, *this, outer);
  if (!AppObject)
    AppObject = obj;
  return *obj;
}

void
TServedObjectCreator::Attach(TServedObject& obj)
{
  AppDesc.AddServed(obj);
  ++ObjCount;
}

void
TServedObjectCreator::Detach(TServedObject& obj)
{
  AppDesc.RemoveServed(obj);
  if (--ObjCount == 0)
    delete this;
}

#if defined(BI_NAMESPACE)
namespace OCF {
#endif

const GUID __cdecl _OCFDATA IID_TServedObject = {0x02A101L,0,0,{0xC0,0,0,0,0,0,0,0x46}};

#if defined(BI_NAMESPACE)
} // namespace OCF
#endif

DEFINE_QI_OLEBASE(IDispatch,      0x20400L)
DEFINE_QI_OLEBASE(ITypeInfo,      0x20401L)

DEFINE_COMBASES2(TServedCOM, IDispatch, ITypeInfo)

HRESULT TServedObject::QueryObject(const GUID far& iid, void far* far* pif)
{
  GUID qid = iid;

  if (iid == IID_TServedObject) {
    *pif = this;       // return actual pointer to this object
    return HR_NOERROR; // non-interface returned, no AddRef(), do not Release
  }
  if ((iidEvent != IID_NULL) && (iid == iidEvent))
    qid = IID_IDispatch;
  return TServedCOM::QueryObject (qid, pif);  // query inherited bases
}

TServedObject::TServedObject(TObjectDescriptor& objDesc,
                             TServedObjectCreator& creator,
                             IUnknown* outer)
:
  Object(const_cast<void*>(objDesc.Object)), Destruct(objDesc.Destruct),
  Creator(creator), Class(objDesc.Class), iidEvent(IID_NULL)
{
  SetOuter(outer ? outer
       : &objDesc.Class->Aggregate(const_cast<void*>(objDesc.Object), *this));
  ReqLang = creator.AppDesc.GetAppLang();  // do we really need to initialize here?
  creator.Attach(*this);
  RootObject = objDesc.MostDerived();
} // note: RefCnt = 0 on creation, will ++ in TAutoVal operator(IDispatch*)

TServedObject::~TServedObject()
{
  if (Object && Destruct != TObjectDescriptor::Quiet) {
    TAutoCommand* cmdobj;
    try {
      cmdobj = Class->GetDestructor()(Object, Destruct);
      cmdobj->Invoke();
    }
    catch(TXAuto&) {
      // we can't indicate any error here
    }
    delete cmdobj;
  }
  Creator.Detach(*this);
}

//
// IDispatch implementation
//

HRESULT _IFUNC
TServedObject::GetTypeInfoCount(unsigned int far* pctinfo)
{
  *pctinfo = 1;
  return HR_NOERROR;
}

HRESULT _IFUNC
TServedObject::GetTypeInfo(unsigned int /*itinfo*/, LCID lcid,
                           ITypeInfo* far* pptinfo)
{
  ReqLang = LANGIDFROMLCID(lcid);
  *pptinfo = static_cast<ITypeInfo*>(this);
  AddRef();
  return HR_NOERROR;
}

HRESULT _IFUNC
TServedObject::GetIDsOfNames(const IID far& riid, OLECHAR far* far* names,
                          unsigned int cNames, LCID lcid, DISPID far* dispIds)
{
  if (riid != IID_NULL)
    return HR_DISP_UNKNOWNINTERFACE;

  HRESULT retval = HR_NOERROR;
  TAutoSymbol* symbol;
  for (int i = 0; i < cNames; i++) {
    dispIds[i] = -1;
    if (i == 0) {
      symbol = Class->Lookup(OleStr(names[0]), LANGIDFROMLCID(lcid),
                             asAnyCommand, dispIds[0]);
      if (!symbol)
        retval = HR_DISP_UNKNOWNNAME;
    }
    else if (symbol) {
      if (!Class->LookupArg(OleStr(names[i]), LANGIDFROMLCID(lcid), symbol, dispIds[i]))
        retval = HR_DISP_UNKNOWNNAME;
    }
  }
  return retval;
}

//
//
//
HRESULT _IFUNC
TServedObject::Invoke(DISPID dispidMember, const IID far& /*riid*/, LCID lcid,
                      unsigned short wFlags, DISPPARAMS far* dispparams,
                      VARIANT far* varResult, EXCEPINFO far* exceptInfo,
                      unsigned int far* retArgErr)
{
  // Make a copy of the object in case there's this pointer adjustment
  //
  ObjectPtr object = Object;

  // Make sure our object is still valid
  //
  if (!object) {
    return HR_DISP_MEMBERNOTFOUND;
  }

  // Build an object representing the data passed in
  //
  TAutoStack stack(dispidMember, dispparams->rgvarg, lcid, dispparams->cArgs,
                   dispparams->cNamedArgs, dispparams->rgdispidNamedArgs,
                   this);

  // Find the symbol we're asked to dispatch to
  //
  stack.Symbol = Class->FindId(dispidMember, object);

  if (!stack.Symbol) {
#if defined(BI_PLAT_WIN32)
    // NOTE: This is a 'hack' that allows TServedObject to expose a generic method
    //       that's used for cases when the object does not provide a method
    //       that matches the dispId invoked.
    //       It is used by our container support for sinking non-standard events.
    //
    if ((stack.Symbol = Class->FindId(DISPID_CATCH_ALL, object)) == NULL)
#endif
      return HR_DISP_MEMBERNOTFOUND;
  }

  // Check the attribute bits to ensure we support the type
  //
  if (!stack.Symbol->TestFlag(wFlags)) {
    return HR_DISP_MEMBERNOTFOUND;
  }

  // Check if we need return result
  // NOTE: Some servers [such as Word.Basic] seem to be very picky about
  //       the distinction between a function and procedure. They are not
  //       as flexible as we are here..
  //
  if (wFlags & (DISPATCH_PROPERTYPUT | DISPATCH_PROPERTYPUTREF))
    varResult = 0;


  // Check that the number of arguments sent matches what we're expecting
  //
#if defined(BI_PLAT_WIN16)
  if ((stack.ArgSymbolCount = Class->GetArgCount(*stack.Symbol)) +
      ((wFlags & (DISPATCH_PROPERTYPUT|DISPATCH_PROPERTYPUTREF)) != 0) < stack.ArgCount)
    return HR_DISP_BADPARAMCOUNT;

#elif defined(BI_PLAT_WIN32)
  // Again here we'll have to relax a little on the param count check since in the
  // case of the DISPID_CATCH_ALL, the handler is a generic one that can handle
  // any number of parameters.
  //
  if (((stack.ArgSymbolCount = Class->GetArgCount(*stack.Symbol)) +
      ((wFlags & (DISPATCH_PROPERTYPUT|DISPATCH_PROPERTYPUTREF)) != 0) < stack.ArgCount) &&
        (stack.Symbol->DispId != DISPID_CATCH_ALL))
    return HR_DISP_BADPARAMCOUNT;

#endif

  // Dispatch via the command object and hope we're OK
  //
  switch(Class->Dispatch(object, Creator, *this, wFlags, stack, (TAutoVal*)varResult)) {
    case TXAuto::xNoError:
          return HR_NOERROR;

    case TXAuto::xNotIDispatch:
    case TXAuto::xForeignIDispatch:
          return HR_DISP_BADVARTYPE;

    case TXAuto::xValidateFailure:
         *retArgErr = stack.CurrentArg;
          return HR_DISP_OVERFLOW;

    case TXAuto::xConversionFailure:
    case TXAuto::xTypeMismatch:
         *retArgErr = stack.CurrentArg;
          return HR_DISP_TYPEMISMATCH;

    case TXAuto::xNoArgSymbol:
         *retArgErr = stack.CurrentArg;
          return HR_DISP_PARAMNOTFOUND;

    case TXAuto::xParameterMissing:
    case TXAuto::xNoDefaultValue:
          return HR_DISP_PARAMNOTOPTIONAL;

    case TXAuto::xErrorStatus:
      if (exceptInfo) {
        exceptInfo->wCode = (unsigned short)stack.ErrorCode;
        exceptInfo->wReserved = 0;
        exceptInfo->bstrSource = NS_CLASSLIB::SysAllocString(
          Creator.AppDesc.GetAppName(LANGIDFROMLCID(lcid)));
        exceptInfo->bstrDescription = NS_CLASSLIB::SysAllocString(
          stack.ErrorMsg);
        exceptInfo->bstrHelpFile = 0;
        exceptInfo->pfnDeferredFillIn = 0;

        // INVESTIGATE: Is there a method to relay better SCODEs ?
        //
        exceptInfo->scode = E_FAIL;
      }
      return HR_DISP_EXCEPTION;

  case TXAuto::xExecutionFailure:
  default:
        // INVESTIGATE: Is there a better error code here ?
        //
        return HR_DISP_OVERFLOW;
  }
}


//----------------------------------------------------------------------------
// ITypeInfo implementation
//

HRESULT _IFUNC
TServedObject::GetTypeAttr(TYPEATTR far* far* retTypeAttr)
{
  Class->CountCommands();    // force update of symbol counts;
  TYPEATTR* ta = (TYPEATTR*)new char[sizeof(TYPEATTR)];
  memset(ta, 0, sizeof(TYPEATTR));
  Creator.AppDesc.GetClassId(Class, ta->guid);
  ta->lcid = ReqLang;
  ta->typekind = TKIND_DISPATCH;
  ta->wTypeFlags = Class->GetTypeFlags();
  ta->cFuncs = Class->FunctionCount;
  ta->cVars  = Class->VariableCount;
  ta->wMajorVerNum = Creator.AppDesc.GetVersionField(0);
  ta->wMinorVerNum = Creator.AppDesc.GetVersionField(1);
  *retTypeAttr = ta;
  return HR_NOERROR;
}

void _IFUNC
TServedObject::ReleaseTypeAttr(TYPEATTR far* ptypeattr)
{
  delete [] (char*)ptypeattr;
}

HRESULT _IFUNC
TServedObject::GetFuncDesc(unsigned int index, FUNCDESC far* far* retDesc)
{
  MEMBERID cmdId = 0;   // must initialize, FindFunction recursively adjusts it
  TAutoSymbol* sym = Class->FindFunction(index, cmdId);
  if (!sym || !retDesc)
    return HR_INVALIDARG;
  int kind = (sym->GetFlags() & asOleType);
  bool isPropSet = kind==INVOKE_PROPERTYPUT || kind==INVOKE_PROPERTYPUTREF;
  int argCount = Class->GetArgCount(*sym);
  int asize = sizeof(ELEMDESC) * (argCount+isPropSet) + sizeof(FUNCDESC);
  int size = (argCount+1) * sizeof(TYPEDESC) + asize;
  FUNCDESC* fd = (FUNCDESC*)new char[size];
  TYPEDESC* ptrtd = (TYPEDESC*)((char*)fd + asize); // for indirected types
  memset(fd, 0, size);
  fd->cParams = short(argCount + isPropSet);
  fd->lprgelemdescParam = (ELEMDESC*)(fd+1);
  fd->memid = cmdId;
  fd->funckind = FUNC_DISPATCH;
  fd->invkind = (INVOKEKIND)kind;
  fd->callconv = CC_CDECL;  // need to set to prevent typelib.dll asserts
  fd->cScodes = -1;
  ELEMDESC* argDesc = &fd->elemdescFunc;
  if (isPropSet){
    argDesc->tdesc.vt = VT_EMPTY;
    argDesc = (ELEMDESC*)(fd+1);
  }
  for (int argIndex = 0; argIndex <= argCount; argIndex++, sym++, ptrtd++) {
    TAutoClass* cls = sym->GetClass();
    if (cls) {
      argDesc->tdesc.vt = VT_USERDEFINED;
      argDesc->tdesc.hreftype = (HREFTYPE)cls;
    } else if (sym->IsEnum()) {
      argDesc->tdesc.vt = atString;  // expose enumerated type as string
    } else if (sym->IsArray()) {
      argDesc->tdesc.vt = VT_SAFEARRAY;
      argDesc->tdesc.lptdesc = ptrtd;
      ptrtd->vt = sym->GetDataType();
    } else if (sym->IsByRef()) {
      argDesc->tdesc.vt = VT_PTR;
      argDesc->tdesc.lptdesc = ptrtd;
      ptrtd->vt = sym->GetDataType();
    } else {
      argDesc->tdesc.vt = sym->GetDataType();
    }
    argDesc++;
    if (argIndex == 0) {
      if (!isPropSet)
        argDesc = (ELEMDESC*)(fd+1);
    } else {
      if (sym->Doc)    // argument optional if has default string
        fd->cParamsOpt++;
    }
  }
  *retDesc = fd;
  return HR_NOERROR;
}

void _IFUNC
TServedObject::ReleaseFuncDesc(FUNCDESC far* pfuncdesc)
{
  delete [] (char*)pfuncdesc;
}

HRESULT _IFUNC
TServedObject::GetVarDesc(unsigned int index, VARDESC far* far* retDesc)
{
  VARDESC* vd = (VARDESC*)new char[sizeof(VARDESC) + sizeof(TYPEDESC)];
  TYPEDESC* ptrtd = (TYPEDESC*)((char*)vd + sizeof(VARDESC));
  memset(vd, 0, sizeof(VARDESC)+sizeof(TYPEDESC));
  MEMBERID cmdId = 0;   // must initialize, FindVariable recursively adjusts it
  TAutoSymbol* sym = Class->FindVariable(index, cmdId);
  if (!sym || !retDesc)
    return HR_INVALIDARG;
  TAutoClass* cls = sym->GetClass();
  vd->memid = cmdId;
  vd->varkind = VAR_DISPATCH;
  if (cls) {
    vd->elemdescVar.tdesc.vt = VT_USERDEFINED;
    vd->elemdescVar.tdesc.hreftype = (HREFTYPE)cls;
  } else if (sym->IsEnum()) {
      vd->elemdescVar.tdesc.vt = atString;  // expose enumerated type as string
  } else if (sym->IsArray()) {
    vd->elemdescVar.tdesc.vt = VT_SAFEARRAY;
    vd->elemdescVar.tdesc.lptdesc = ptrtd;
    ptrtd->vt = sym->GetDataType();
  } else if (sym->IsByRef()) {
    vd->elemdescVar.tdesc.vt = VT_PTR;
    vd->elemdescVar.tdesc.lptdesc = ptrtd;
    ptrtd->vt = sym->GetDataType();
  } else {
    vd->elemdescVar.tdesc.vt = sym->GetDataType();
  }
  *retDesc = vd;
  return HR_NOERROR;
}

void _IFUNC
TServedObject::ReleaseVarDesc(VARDESC far* pvardesc)
{
  delete pvardesc;
  return;
}

HRESULT _IFUNC
TServedObject::GetNames(MEMBERID memid, BSTR far* rgbstrNames,
                        unsigned int cMaxNames, unsigned int far* pcNames)
{
  ObjectPtr noObj = 0;
  TAutoSymbol* sym = Class->FindId(memid, noObj);
  if (!sym)
    return HR_DISP_MEMBERNOTFOUND;
  int nameCount = Class->GetArgCount(*sym) + 1;
  if (nameCount > cMaxNames)
    nameCount = cMaxNames;
  for (int index = 0; index < nameCount; index++, sym++)
    rgbstrNames[index] = NS_CLASSLIB::SysAllocString(sym->Name.Translate(ReqLang));
  *pcNames = nameCount;
  return HR_NOERROR;
}

HRESULT _IFUNC
TServedObject::GetIDsOfNames(OLECHAR far* far* names, uint cNames,
                             MEMBERID far* retIds)
{
  HRESULT retval = HR_NOERROR;
  TAutoSymbol* symbol;
  for (int i = 0; i < cNames; i++) {
    retIds[i] = -1;
    if (i == 0) {
      symbol = Class->Lookup(OleStr(names[0]), ReqLang, asAnyCommand, retIds[0]);
      if (!symbol)
        retval = HR_DISP_UNKNOWNNAME;
    }
    else if (symbol) {
      if (!Class->LookupArg(OleStr(names[i]), ReqLang, symbol, retIds[i]))
        retval = HR_DISP_UNKNOWNNAME;
    }
  }
  return retval;
}

HRESULT _IFUNC
TServedObject::Invoke(void far* pvInstance, MEMBERID memid,
                      unsigned short wFlags, DISPPARAMS far *dispparams,
                      VARIANT far *varResult, EXCEPINFO far *exceptinfo,
                      unsigned int far *retArgErr)
{
  if (Object)   // cannot invoke if active object obtained from IDispatch ifc
    return HR_TYPE_INVALIDSTATE;
  Object = (void*)pvInstance; // going on faith that caller has valid instance
  RootObject = NS_OCF::MostDerived(Object, Class->GetTypeInfo());
  HRESULT stat = Invoke(memid, IID_NULL, ReqLang, wFlags, dispparams,
                        varResult, exceptinfo, retArgErr);
  Object = 0;
  RootObject = 0;
  return stat;
}

HRESULT _IFUNC
TServedObject::GetDocumentation(MEMBERID memid,
                                BSTR far* retName, BSTR far* retDoc,
                                ulong far* retHelpContext,
                                BSTR far* retHelpFile)
{
  TAutoSymbol* sym;
  if (memid == -1) {       // request info on type library itself
    sym = Class->GetClassSymbol();
  } else {
    ObjectPtr noObj = 0;
    if ((sym = Class->FindId(memid, noObj)) == 0)
      return HR_DISP_MEMBERNOTFOUND;
  }
  if (retName)
    *retName = NS_CLASSLIB::SysAllocString(sym->Name.Translate(ReqLang));
  if (retDoc)
    *retDoc  = NS_CLASSLIB::SysAllocString(sym->Doc.Translate(ReqLang));
  if (retHelpContext)
    *retHelpContext = sym->HelpId;
  if (retHelpFile)
    *retHelpFile = NS_CLASSLIB::SysAllocString(
      Creator.AppDesc.GetHelpFile(ReqLang));
  return HR_NOERROR;
}

HRESULT _IFUNC
TServedObject::GetFuncDocFromIndex(unsigned index,
                                   BSTR far* retName, BSTR far* retDoc,
                                   ulong far* retHelpContext,
                                   BSTR far* retHelpFile)
{
  MEMBERID cmdId = 0;
  TAutoSymbol* sym = Class->FindFunction(index, cmdId);
  if (!sym)
    return HR_INVALIDARG;
  return GetDocFromSym(sym, retName, retDoc,retHelpContext, retHelpFile);
}

HRESULT _IFUNC
TServedObject::GetVarDocFromIndex(unsigned index,
                                  BSTR far* retName, BSTR far* retDoc,
                                  ulong far* retHelpContext,
                                  BSTR far* retHelpFile)
{
  MEMBERID cmdId = 0;
  TAutoSymbol* sym = Class->FindVariable(index, cmdId);
  if (!sym)
    return HR_INVALIDARG;
  return GetDocFromSym(sym, retName, retDoc,retHelpContext, retHelpFile);
}

HRESULT _IFUNC
TServedObject::GetDocFromSym(TAutoSymbol* sym,
                             BSTR far* retName, BSTR far* retDoc,
                             ulong far* retHelpContext,
                             BSTR far* retHelpFile)
{
  if (retName)
    *retName = NS_CLASSLIB::SysAllocString(sym->Name.Translate(ReqLang));
  if (retDoc)
    *retDoc  = NS_CLASSLIB::SysAllocString(sym->Doc.Translate(ReqLang));
  if (retHelpContext)
    *retHelpContext = sym->HelpId;
  if (retHelpFile)
    *retHelpFile = NS_CLASSLIB::SysAllocString(Creator.AppDesc.GetHelpFile(ReqLang));
  return HR_NOERROR;
}

HRESULT _IFUNC
TServedObject::CreateInstance(IUnknown* /*punkOuter*/, const IID far& /*riid*/,
                              void far* far* /*ppvObj*/)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TServedObject::GetContainingTypeLib(ITypeLib* far* retLib,
                                                unsigned int far* retIndex)
{
  *retLib = Creator.AppDesc.GetTypeLibrary();
  if (retIndex)
    *retIndex = Creator.AppDesc.GetClassIndex(Class);
  return HR_NOERROR;  // is it really possible to fail?
}

HRESULT _IFUNC
TServedObject::GetRefTypeInfo(HREFTYPE hreftype, ITypeInfo* far* retInfo)
{
  TAutoClass* cls = (TAutoClass*)hreftype;
  if (Creator.AppDesc.GetClassIndex(cls) == -1)  // validate pointer to avoid crash
    return HR_TYPE_WRONGTYPEKIND;
  *retInfo = Creator.AppDesc.CreateITypeInfo(*cls);
  return HR_NOERROR;
}

// The following methods of ITypeInfo are not relevant for Dispatch interfaces

HRESULT _IFUNC
TServedObject::GetTypeComp(ITypeComp* far* /*pptcomp*/)
{
  return HR_TYPE_LIBNOTREGISTERED;
}

HRESULT _IFUNC
TServedObject::GetMops(MEMBERID /*memid*/, BSTR far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TServedObject::GetImplTypeFlags(unsigned int /*index*/, int far*)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TServedObject::GetRefTypeOfImplType(unsigned int /*index*/,
                                    HREFTYPE far* /*phreftype*/)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TServedObject::GetDllEntry(MEMBERID /*memid*/, INVOKEKIND /*invkind*/,
                           BSTR far* /*pbstrDllName*/, BSTR far* /*pbstrName*/,
                           unsigned short far* /*pwOrdinal*/)
{
  return HR_TYPE_WRONGTYPEKIND;
}

HRESULT _IFUNC
TServedObject::AddressOfMember(MEMBERID /*memid*/, INVOKEKIND /*invkind*/,
                               void far* far* /*ppv*/)
{
  return HR_TYPE_WRONGTYPEKIND;
}
