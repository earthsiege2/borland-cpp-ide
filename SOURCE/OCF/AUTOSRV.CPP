//
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
// OLE Automation Server Implementation, except TServedObject (in typelib.cpp)
//----------------------------------------------------------------------------
#include <ocf/ocfpch.h>
#include <ocf/appdesc.h>
#include <ocf/ocreg.h>

TAutoType TAutoVoid       ::ClassInfo = {atVoid};
TAutoType TAutoByte       ::ClassInfo = {atByte};
TAutoType TAutoShort      ::ClassInfo = {atShort};
TAutoType TAutoLong       ::ClassInfo = {atLong};
TAutoType TAutoFloat      ::ClassInfo = {atFloat};
TAutoType TAutoDouble     ::ClassInfo = {atDouble};
TAutoType TAutoCurrency   ::ClassInfo = {atCurrency};
TAutoType TAutoDate       ::ClassInfo = {atDatetime};
TAutoType TAutoString     ::ClassInfo = {atString};
TAutoType TAutoBool       ::ClassInfo = {atBool};
TAutoType TAutoUnknown    ::ClassInfo = {atUnknown};
TAutoType TAutoDispatch   ::ClassInfo = {atObject};
TAutoType TAutoShortRef   ::ClassInfo = {atByRef|atShort};
TAutoType TAutoLongRef    ::ClassInfo = {atByRef|atLong};
TAutoType TAutoFloatRef   ::ClassInfo = {atByRef|atFloat};
TAutoType TAutoDoubleRef  ::ClassInfo = {atByRef|atDouble};
TAutoType TAutoCurrencyRef::ClassInfo = {atByRef|atCurrency};
TAutoType TAutoDateRef    ::ClassInfo = {atByRef|atDatetime};
TAutoType TAutoStringRef  ::ClassInfo = {atByRef|atString};
TAutoType TAutoVariantRef ::ClassInfo = {atByRef|atVariant};
TAutoType TAutoBoolRef    ::ClassInfo = {atByRef|atBool};
TAutoType TAutoByteRef    ::ClassInfo = {atByRef|atByte};

void SendObituary(const void far* obj, const typeinfo& typeInfo)
{
  TAppDescriptor* appDesc = ::GetAppDescriptor();
  if (appDesc)
    appDesc->InvalidateObject(::MostDerived(obj, typeInfo));
}

//____________________________________________________________________________
//
// TAutoClass implementation
//____________________________________________________________________________

TAutoClass::TClassList TAutoClass::ClassList = {0,0,0};// MUST BE MODULE GLOBAL

TAutoClass::TAutoClass(TAutoSymbol* table, TAutoSymbol* classSymbol,
             const typeinfo& typeInfo, TAggregator aggregator)
           : Table(table), ClassSymbol(classSymbol), TypeInfo(typeInfo),
             Aggregator(aggregator)
{
  Type = atObject | atAutoClass;
  NextClass = ClassList.List;
  ClassList.List = this;
  ClassList.Count++;
}

TAutoClass::~TAutoClass()  // do we really need to support dynamic AutoClass?
{
  for (TAutoClass** link = &ClassList.List; *link != 0; link = &(*link)->NextClass)
    if (*link == this) {
      *link = NextClass;
      break;
    }
}

short TAutoClass::CountCommands()
{
  TAutoSymbol* sym;
  if (!CommandCount) {
    for (sym = Table; !sym->IsTerminator(); sym++) {
      int attr = sym->GetFlags();
      if (attr & asAnyCommand) {
        CommandCount++;
        if (attr & asOleType) {
          if ((attr & asGetSet) == asGetSet)
            VariableCount++;
          else
            FunctionCount++;
        }
      } else if (sym->TestFlag(asClass)) {
        TAutoClass* cls = sym->GetClass();
        if (!sym->SymCount)
          sym->SymCount = cls->CountCommands();
        CommandCount  += cls->CommandCount;
        VariableCount += cls->VariableCount;
        FunctionCount += cls->FunctionCount;
      }
    }
  }
  return CommandCount;
}

TAutoSymbol* TAutoClass::FindId(short id, ObjectPtr& obj)
{
  TAutoSymbol* sym;
  int cmdId;
  if (id <= 0) {         // reserved dispatch ID if negative or zero
    for (sym = Table; !sym->IsTerminator(); sym++) {
      if (sym->TestFlag(asAnyCommand) && sym->DispId == id)
        return sym;

      if (sym->TestFlag(asClass)) {
        ObjectPtr adjObj = sym->Convert(obj);  // this pointer adjustment
        TAutoSymbol* fsym = sym->GetClass()->FindId(id, adjObj);
        if (fsym) {
          obj = adjObj;
          return fsym;
        }
      }
    }
  } else {
    for (cmdId = 0, sym = Table; !sym->IsTerminator(); sym++) {
      if (sym->TestFlag(asClass)) {
        if (!sym->SymCount)
          sym->SymCount = sym->GetClass()->CountCommands();
        if (cmdId + sym->SymCount >= id) {    // symbol in nested class
          obj = sym->Convert(obj);
          return sym->GetClass()->FindId(short(id-cmdId), obj);
        }
        cmdId += sym->SymCount;
      }
      else if (sym->TestFlag(asAnyCommand)) {
        cmdId++;
        if (cmdId == id)
          return sym;
      }
    }
  }
  return 0;
}

TAutoSymbol* TAutoClass::FindFunction(unsigned index, int& retId)
{
  TAutoSymbol* sym;
  int funcCount = 0;
  int cmdId = retId;
  for (sym = Table; !sym->IsTerminator(); sym++) {
    int attr = sym->GetFlags();
    if (attr & asAnyCommand) {
      cmdId++;
      if ((attr & asOleType) != 0 && (attr & asGetSet) != asGetSet) {
        if (funcCount++ == index) {
          retId = sym->DispId == -1 ? cmdId : sym->DispId;
          return sym;
        }
      }
    } else if (sym->TestFlag(asClass)) {
      TAutoClass* cls = sym->GetClass();
      if (!sym->SymCount)
        sym->SymCount = cls->CountCommands();
      if (funcCount + cls->FunctionCount > index) {
        retId = cmdId;
        return cls->FindFunction(index - funcCount, retId);
      }
      funcCount += cls->FunctionCount;
      cmdId     += cls->CommandCount;
    }
  }
  return 0;  // should never happen unless caller overruns total count
}

TAutoSymbol* TAutoClass::FindVariable(unsigned index, int& retId)
{
  TAutoSymbol* sym;
  int varCount = 0;
  int cmdId = retId;
  for (sym = Table; !sym->IsTerminator(); sym++) {
    int attr = sym->GetFlags();
    if (attr & asAnyCommand) {
      cmdId++;
      if ((attr & asGetSet) == asGetSet) {
        if (varCount++ == index) {
          retId = sym->DispId == -1 ? cmdId : sym->DispId;
          return sym;
        }
      }
    } else if (sym->TestFlag(asClass)) {
      TAutoClass* cls = sym->GetClass();
      if (!sym->SymCount)
        sym->SymCount = cls->CountCommands();
      if (varCount + cls->VariableCount > index) {
        retId = cmdId;
        return cls->FindVariable(index - varCount, retId);
      }
      varCount += cls->VariableCount;
      cmdId    += cls->CommandCount;
    }
  }
  return 0;  // should never happen unless caller overruns total count
}

short TAutoClass::GetArgCount(TAutoSymbol& sym)
{
  short count = 0;
  TAutoSymbol* arg = &sym;
  while ((++arg)->TestFlag(asArgument))
    count++;
  return count;
}

TAutoSymbol* TAutoClass::Lookup(char far* name, TLangId lang, short symflags,
                                long far& retid)
{
  int cmdId = 0;
  for (TAutoSymbol* sym = Table; !sym->IsTerminator(); sym++) {
    if (sym->TestFlag(asAnyCommand))
      cmdId++;
    if (sym->TestFlag(symflags) && sym->Name.Compare(name, lang) == 0) {
      retid = sym->DispId == -1 ? (long)cmdId : (long)sym->DispId;
      return sym;
    }
    else if (sym->TestFlag(asClass)) {
      TAutoClass* cls = sym->GetClass();
      if (!sym->SymCount)
        sym->SymCount = cls->CountCommands();
      long id;
      TAutoSymbol* found = cls->Lookup(name, lang, symflags, id);
      if (found) {
        retid = id > 0 ? id + (long)cmdId : id;
        return found;
      }
      cmdId += sym->SymCount;
    }
  }
  return 0;
}

TAutoSymbol* TAutoClass::LookupArg(char far* name, TLangId lang,
                                   TAutoSymbol* sym, long far& retid)
{
  PRECONDITION(sym);

   for (int i = 0; (++sym)->TestFlag(asArgument); ++i)
     if (sym->Name.Compare(name, lang) == 0) {
       retid = (long)i;
       return sym;
     }
   return 0;
}

TAutoCommand* AutoQuitBuild(ObjectPtr obj, int/*attr*/, TAutoStack& args)
{
  TServedObject& owner = *args.Owner;

  // if the automation object is not in control of the app, execute a no-op
  //
  if (owner.Destruct == TObjectDescriptor::Quiet)
    return new TAutoCommand(0);

  // if registered as the active object, free it to release OLE's refcnt
  //
  if (owner.Creator.AppDesc.IsActiveObject(&owner))
    owner.Creator.AppDesc.UnregisterObject();

  // disconnect automation from app to prevent further access
  //
  owner.Object = 0; 
  owner.RootObject = 0;

  // build command object for destructor, will either delete or PostQuitMsg
  //
  return owner.Class->GetDestructor()(obj, owner.Destruct);
}

TXAuto::TError TAutoClass::Dispatch(ObjectPtr obj, TAutoCreator& creator,
            TUnknown& owner, int attr, TAutoStack& args, TAutoVal far* retval)
{
  TAutoCommand*  cmdobj = 0;
  TAutoIterator* iterator = 0;
  try {
    if (args.Symbol->IsIterator()) {
      iterator = args.Symbol->BuildIter(obj, creator, owner, args.LangId);
      iterator->SetSymbol(args.Symbol);
      iterator->Init();
      *retval = (IUnknown*)*iterator; // remains until RefCnt->0
    } else {
      cmdobj = args.Symbol->Build(obj, attr, args);
      cmdobj->SetSymbol(args.Symbol);
      if (args.ArgCount>0 && !cmdobj->Validate()) {// no validate for prop get
        delete cmdobj;
        return TXAuto::xValidateFailure;
      }
      cmdobj->Invoke();
      if ((args.ErrorCode = cmdobj->Report()) != 0) {
        args.ErrorMsg = TAutoCommand::LookupError(args.ErrorCode);
        if (!args.ErrorMsg && args.Symbol)  // if no error message available
          args.ErrorMsg = args.Symbol->Name.Translate(args.LangId);
        delete cmdobj;
        return TXAuto::xErrorStatus;
      }
      if (retval) {
        cmdobj->Return(*retval);
        if (args.Symbol->IsEnum())
          args.Symbol->GetEnum()->Convert(*retval, args.LangId);
        TObjectDescriptor objDesc;
        if (retval->GetObjDesc(objDesc)) {
          if (!objDesc.Object)     // null pointer returned from function
            // there are three choices for behavior here:
            // 1. Allow a dead object to be returned, fail when passed back
            // 2. Fail now, however this prevents testing for null pointer
            // 3. Return an empty variant, causing script to fail when used
            *retval = TAutoVoid();  // return an empty value if no object
          else
            *retval = creator.CreateDispatch(objDesc);
        }
      }
      delete cmdobj;
    }
  }
  catch(TXAuto& xobj) {
    delete cmdobj;
    delete iterator;
    return xobj.ErrorCode;
  }
  return TXAuto::xNoError;
}

TAutoClass::TExtLink::TExtLink(TClassList* list, HINSTANCE module)
           : Classes(list), Module(module), Next(0)
{
  for (Prev = &ClassList.Link; *Prev; Prev = &(*Prev)->Next)
    ;               // link to end of list
}

TAutoClass::TExtLink::~TExtLink()
{
  *Prev = Next;
  if (Next)
    Next->Prev = Prev;
}

//____________________________________________________________________________
//
// TAutoStack implementation
//____________________________________________________________________________

TAutoStack::TAutoStack(VARIANT far* stack, TLocaleId locale, int argcount,
                       int named, long far* map, TServedObject* owner)
:
  Owner(owner), Stack((TAutoVal far*)stack), LangId(LANGIDFROMLCID(locale)),
  ArgCount(argcount), NamedCount(named), NamedIds(map), CurrentArg(-1)
{
}

TAutoStack::~TAutoStack()
{
  TAutoVal far* val;
  for (val = Stack; ArgCount; --*const_cast<int*>(&ArgCount), val++)
    val->Restore();
}

TAutoVal& TAutoStack::operator [](int index)
{
  if (index >= ArgSymbolCount /* && index != TAutoStack::SetValue */)
    throw TXAuto(TXAuto::xNoArgSymbol);
  TAutoSymbol* argSymbol = index >= 0 ? Symbol + index + 1 : Symbol;
  int vIndex = ArgCount - index - 1;        // index if not a named argument
  if (index == TAutoStack::SetValue ||      // property value to set
      index >= ArgCount-NamedCount) { // named or out of range
    for (vIndex = NamedCount; --vIndex >= 0; )
      if (NamedIds[vIndex] == index) {
        break;
      }
  }
  TAutoVal far* val;
  if (vIndex >= 0) {
    CurrentArg = vIndex;   // save index for error return
    val = Stack[vIndex].DereferenceVariant();
    val->SetLocale(LangId);
    if (val->GetDataType() == atString &&
        argSymbol->IsEnum() &&
        argSymbol->GetEnum()->Convert(*val, Default))
      return Default;
  }
  else if (index == TAutoStack::SetValue) {
    throw TXAuto(TXAuto::xParameterMissing);
  }
  else {
    val = &Default;
    val->SetLocale(LangId);
    const char* dfltStr = argSymbol->Doc.Translate(LangId); // load default
    if (!dfltStr)
      throw TXAuto(TXAuto::xNoDefaultValue);
    Default = dfltStr;    // makes a BSTR in order to use OLE conversions
  }
  return *val;
}

//____________________________________________________________________________
//
// Dynamic casting routines implementation
//____________________________________________________________________________

// temporary defines for using typeinfo with dynamic cast

void far* __cdecl __DynamicCast(void far* object, void far* vtable,
                                void far* srctyp, void far* dsttyp,
                                int reference = 0);
struct tpid {int s; short m; short n; int VptrOffs; int Flags;};  // partial
#define CF_HAS_FARVPTR  0x1000

const void far*
DynamicCast(const void far* obj, const typeinfo& src, const typeinfo& dst)
{
  int vtblOff;
  if (!obj)
    return obj;
  else if ((vtblOff = src.tpp->VptrOffs) == -1)
    return src==dst ? obj : 0;
  else if (src.tpp->Flags & CF_HAS_FARVPTR)
    return __DynamicCast(const_cast<void far*>(obj),
                         *(void far**)((char*)obj+vtblOff), src.tpp, dst.tpp);
  else
    return __DynamicCast(const_cast<void far*>(obj),
                         *(void near**)((char*)obj+vtblOff), src.tpp,dst.tpp);
}

const void far*
MostDerived(const void far* obj, const typeinfo& src)
{
  int vtblOff;
  if (!obj || (vtblOff = src.tpp->VptrOffs) == -1)
    return obj;

  else if (src.tpp->Flags & CF_HAS_FARVPTR)
    return __DynamicCast(const_cast<void far*>(obj),
                         *(void far**)((char*)obj+vtblOff), src.tpp, 0);
  else
    return __DynamicCast(const_cast<void far*>(obj),
                         *(void near**)((char*)obj+vtblOff), src.tpp, 0);
}

//____________________________________________________________________________
//
// TAutoCommand implementation - inlined to allow definition of _AUTOCLASS
//____________________________________________________________________________

TAutoCommand::TErrorMsgHook TAutoCommand_ErrorLookup = 0; // module static

TAutoCommand::TCommandHook  TAutoCommand_InvokeHook = 0;  // module static

//____________________________________________________________________________
//
// TAutoIterator implementation
//____________________________________________________________________________

TAutoIterator::TAutoIterator(TAutoCreator& creator,IUnknown* owner,TLangId lang)
: Creator(creator), Owner(owner), Symbol(0), RefCnt(0), Class(0), Lang(lang) {}
     // note: RefCnt = 0 on creation, will ++ in TAutoVal operator(IUnknown*)

TAutoIterator::TAutoIterator(TAutoIterator& copy)
:
  Symbol(copy.Symbol), Owner(copy.Owner), Class(copy.Class), Lang(copy.Lang),
  Creator(copy.Creator), RefCnt(1)
{
  Owner->AddRef();
}

TAutoIterator::~TAutoIterator()
{
  Owner->Release();
}

//
// IEnumVARIANT implementation
//

HRESULT _IFUNC
TAutoIterator::QueryInterface(const GUID far& iid, void far*far* pif)
{
  if (iid!=IID_IUnknown && iid!=IID_IEnumVARIANT) {
    *pif = 0;
    return HR_NOINTERFACE;
  }
  *pif = this;
  ++RefCnt;
  return HR_NOERROR;
}
unsigned long _IFUNC TAutoIterator::AddRef()
{
  return ++RefCnt;
}
unsigned long _IFUNC TAutoIterator::Release()
{
  return --RefCnt==0 ? delete this,0 : RefCnt;
}

HRESULT _IFUNC TAutoIterator::Next(unsigned long count, VARIANT far* retvals,
                    unsigned long far* retcount)
{
  unsigned long index = 0;
  try {
    while(index < count) {
      if (!Test())
        break;
      TAutoVal far& retval = ((TAutoVal far*)retvals)[(int)index];
      Return(retval);
      if (Symbol->IsEnum())
        Symbol->GetEnum()->Convert(retval, Lang);
      TObjectDescriptor objDesc;
      if (retval.GetObjDesc(objDesc)) {
        if (!objDesc.Object)     // null pointer returned from function
          retval = TAutoVoid();  // return an empty value if no object
        else
          retval = Creator.CreateDispatch(objDesc);
      }
      Step();
      index++;
    }
  }
  catch(...) {
  }
  if (retcount)
    *retcount = index;
  return index==count ? HR_NOERROR : HR_FALSE;
}

HRESULT _IFUNC TAutoIterator::Skip(unsigned long count)
{
  while(count--) {
    if (!Test())
      return HR_FALSE;
    Step();
  }
  return HR_NOERROR;
}

HRESULT _IFUNC TAutoIterator::Reset()
{
  Init();
  return HR_NOERROR;
}

HRESULT _IFUNC TAutoIterator::Clone(IEnumVARIANT* FAR* ppenum)
{
  try {
    *ppenum = Copy();
    return HR_NOERROR;
  }
  catch (...) {
    return HR_OUTOFMEMORY;
  }
}

//____________________________________________________________________________
//
// TDispatch implementation
//____________________________________________________________________________

TUnknown* TDispatchCreator::CreateObject(TObjectDescriptor objDesc,
                                   IUnknown* outer)
{
  return new TDispatch(objDesc, outer);
}

IDispatch* TDispatchCreator::CreateDispatch(TObjectDescriptor objDesc,
                                            IUnknown* outer)
{
  TDispatch* obj = new TDispatch(objDesc, outer);
  return *obj;
}

DEFINE_QI_OLEBASE(IDispatch,      0x20400L)

DEFINE_COMBASES1(TDispatchCOM, IDispatch)

TDispatch::TDispatch(TObjectDescriptor& objDesc, IUnknown* outer)
:
  Object(const_cast<void*>(objDesc.Object)), Class(objDesc.Class)
{
  SetOuter(outer ? outer
       : &objDesc.Class->Aggregate(const_cast<void*>(objDesc.Object), *this));
} // note: RefCnt = 0 on creation, will ++ in TAutoVal operator(IDispatch*)

// IDispatch implementation

HRESULT _IFUNC
TDispatch::GetTypeInfoCount(unsigned int far* pctinfo)
{
  *pctinfo = 0;
  return HR_NOERROR;
}

HRESULT _IFUNC
TDispatch::GetTypeInfo(unsigned int, LCID, ITypeInfo* far*)
{
  return HR_NOTIMPL;
}

HRESULT _IFUNC
TDispatch::GetIDsOfNames(const IID far& riid, OLECHAR far* far* names,
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

HRESULT _IFUNC
TDispatch::Invoke(DISPID dispidMember, const IID far& /*riid*/, LCID lcid,
                      unsigned short wFlags, DISPPARAMS far* dispparams,
                      VARIANT far* varResult, EXCEPINFO far* exceptInfo,
                      unsigned int far* retArgErr)
{
  ObjectPtr object = Object;  // make copy in case of this pointer adjustment
  if (!object)      // check if C++ object still exists
    return HR_DISP_MEMBERNOTFOUND;
  TAutoStack stack(dispparams->rgvarg, lcid, dispparams->cArgs,
                   dispparams->cNamedArgs, dispparams->rgdispidNamedArgs, 0);
  stack.Symbol = Class->FindId((short)dispidMember, object);
  if (!stack.Symbol)
    return HR_DISP_MEMBERNOTFOUND;
  if (!stack.Symbol->TestFlag(wFlags)) // check attr bits for supported type
    return HR_DISP_MEMBERNOTFOUND;
  if (wFlags & (DISPATCH_PROPERTYPUT | DISPATCH_PROPERTYPUTREF))
    varResult = 0;
  if ((stack.ArgSymbolCount=Class->GetArgCount(*stack.Symbol)) +
  ((wFlags&(DISPATCH_PROPERTYPUT|DISPATCH_PROPERTYPUTREF))!=0) < stack.ArgCount)
    return HR_DISP_BADPARAMCOUNT;

  switch(Class->Dispatch(object, TDispatchCreator(), *this, wFlags, stack,
                         (TAutoVal far*)varResult)) {
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
      exceptInfo->bstrSource = 0; //::SysAllocString(AppDesc.GetAppName(LANGIDFROMLCID(lcid)));
      exceptInfo->bstrDescription = ::SysAllocString(stack.ErrorMsg);
      exceptInfo->bstrHelpFile = 0;
      exceptInfo->pfnDeferredFillIn = 0;
      exceptInfo->scode = E_FAIL;  // how to get better code? matters?
    }
    return HR_DISP_EXCEPTION;

  case TXAuto::xExecutionFailure:
  default:
    return HR_DISP_OVERFLOW;  // no appropriate error for other
  }
}


