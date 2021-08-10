//----------------------------------------------------------------------------
// ObjectConnections - (C) Copyright 1994 by Borland International
//
// This program reads type libraries (*.OLB; *.TLB) and emits C++ source files
// A typelib filename on the command line forces non-interactive operation.
// Normally generates .HXX and .CXX files for use by OCF automation controller
// A C++ compatible .HPP file can be generated using the entire type library
// by selecting the dialog box option, or by use of the command line options.
//----------------------------------------------------------------------------
#include <ocf/ocdefs.h>  // TComRef
#include <osl/except.h>  // TXBase
#include <olenls.h>      // LANGIDFROMCLSID
#include <iostream.h>
#include <commdlg.h>     // GetFileTitle
#include "autogen.rh"

//____________________________________________________________________________
//
// ITypeInfo and ITypeLib encapsulations
//____________________________________________________________________________

class TComRef<ITypeInfo> : public TComRefBase<ITypeInfo> {
  public:
    TComRef();
    TComRef(ITypeInfo* iface);
    TComRef(const TComRef<ITypeInfo>& i);
   ~TComRef();
    ITypeInfo* operator =(ITypeInfo* iface);
    TComRef<ITypeInfo>& operator =(const TComRef<ITypeInfo>& i);
    ITypeInfo* operator->() {return I;}
    operator ITypeInfo* far*();

    void GetAttr();
    void GetFuncDesc(unsigned int index);
    void GetVarDesc( unsigned int index);
    void GetDocumentation(MEMBERID memberid = MEMBERID_NIL);
    TYPEATTR far* Attr;
    FUNCDESC far* FuncDesc;
    VARDESC  far* VarDesc;
    BSTR Name;
    BSTR Doc;
  private:
    void ClearData();
};
inline void TComRef<ITypeInfo>::ClearData()
{
  memset((char*)this  + sizeof(TComRefBase<ITypeInfo>), 0,
        sizeof(*this) - sizeof(TComRefBase<ITypeInfo>) );
};
TComRef<ITypeInfo>::TComRef() : TComRefBase<ITypeInfo>()
{
  ClearData();
}
TComRef<ITypeInfo>::TComRef(ITypeInfo* i) : TComRefBase<ITypeInfo>(i)
{
  ClearData();
}
TComRef<ITypeInfo>::TComRef(const TComRef<ITypeInfo>& i)
                  : TComRefBase<ITypeInfo>(i)
{
  ClearData();
}
TComRef<ITypeInfo>::~TComRef()
{
  if (Attr) I->ReleaseTypeAttr(Attr);
  if (FuncDesc) I->ReleaseFuncDesc(FuncDesc);
  if (VarDesc)  I->ReleaseVarDesc(VarDesc);
  ::SysFreeString(Name);
  ::SysFreeString(Doc);
}
inline ITypeInfo*
TComRef<ITypeInfo>::operator =(ITypeInfo* iface)
{
  TComRef<ITypeInfo>::~TComRef();
  ClearData();
  return I = iface;
}
inline TComRef<ITypeInfo>&
TComRef<ITypeInfo>::operator =(const TComRef<ITypeInfo>& i)
{
  TComRef<ITypeInfo>::~TComRef();
  ClearData();
  I = i.I;
  return *this;
}
inline
TComRef<ITypeInfo>::operator ITypeInfo* far*()
{ 
  TComRef<ITypeInfo>::~TComRef();
  ClearData();
  return &I;
}
void TComRef<ITypeInfo>::GetDocumentation(MEMBERID memberid)
{
  ::SysFreeString(Name);
  ::SysFreeString(Doc);
  OLECALL(I->GetDocumentation(memberid, &Name, &Doc, 0, 0),"TypeInfo::GetDoc");
}
void TComRef<ITypeInfo>::GetAttr()
{
  if (Attr) I->ReleaseTypeAttr(Attr);
  OLECALL(I->GetTypeAttr(&Attr),"TypeInfo::GetTypeAttr");
}
void TComRef<ITypeInfo>::GetFuncDesc(unsigned int index)
{
  if (FuncDesc) I->ReleaseFuncDesc(FuncDesc);
  OLECALL(I->GetFuncDesc(index, &FuncDesc),"TypeInfo::GetFuncDesc");
}
void TComRef<ITypeInfo>::GetVarDesc( unsigned int index)
{
  if (VarDesc)  I->ReleaseVarDesc(VarDesc);
  OLECALL(I->GetVarDesc(index, &VarDesc),"TypeInfo::GetVarDesc");
}

class TComRef<ITypeLib> : public TComRefBase<ITypeLib> {
  public:
    TComRef();
    TComRef(ITypeLib* iface);
    TComRef(const TComRef<ITypeLib>& i);
   ~TComRef();
    ITypeLib* operator =(ITypeLib* iface) {if(I)I->Release(); return I = iface;}
    ITypeLib* operator =(const TComRef<ITypeLib>& i){if(I)I->Release(); return I=i.I;}
    ITypeLib* operator->() {return I;}
    void GetAttr();
    void GetDocumentation(int index = -1);
    TLIBATTR far* Attr;
    BSTR Name;
    BSTR Doc;
};
TComRef<ITypeLib>::TComRef() : TComRefBase<ITypeLib>(),
                               Name(0), Doc(0), Attr(0){}
TComRef<ITypeLib>::TComRef(ITypeLib* i) : TComRefBase<ITypeLib>(i),
                               Name(0), Doc(0), Attr(0){}
TComRef<ITypeLib>::TComRef(const TComRef<ITypeLib>& i) : TComRefBase<ITypeLib>(i),
                               Name(0), Doc(0), Attr(0){}
TComRef<ITypeLib>::~TComRef()
{
  if (Attr) I->ReleaseTLibAttr(Attr);
  ::SysFreeString(Name);
  ::SysFreeString(Doc);
}
void TComRef<ITypeLib>::GetDocumentation(int index)
{
  ::SysFreeString(Name);
  ::SysFreeString(Doc);
  OLECALL(I->GetDocumentation(index, &Name, &Doc, 0, 0),"TypeLib::GetDoc");
}
void TComRef<ITypeLib>::GetAttr()
{
  if (Attr) I->ReleaseTLibAttr(Attr);
  OLECALL(I->GetLibAttr(&Attr),"TypeLib::GetAttr");
}

//____________________________________________________________________________
//
// Error handling facility using local exception object
//____________________________________________________________________________

struct TLocalError {   // local exception object for this program
  TLocalError(const char* title, const char* message)
                  : Title(title),    Message(message) {}
  const char* Title;
  const char* Message;
};

static void Error(const char* title, const char* message)
{
  throw TLocalError(title,message);
}

static inline void ErrorIf(int error, const char* title, int resId)
{
  if (error)
    Error(title, (char*)resId);
}
static inline void ErrorIf(int error, int resId, const char* message)
{
  if (error)
    Error((char*)resId, message);
}
static inline void ErrorIf(int error, const char* title, const char* message)
{
  if (error)
    Error(title,message);
}

//____________________________________________________________________________
//
// ITypeInfo iterator, emits C++ code
//____________________________________________________________________________

// TypeInfo/TypeLib processing flags

const int tfEnum      = 1<<TKIND_ENUM;
const int tfRecord    = 1<<TKIND_RECORD;
const int tfModule    = 1<<TKIND_MODULE;
const int tfInterface = 1<<TKIND_INTERFACE;
const int tfDispatch  = 1<<TKIND_DISPATCH;
const int tfCoClass   = 1<<TKIND_COCLASS;
const int tfAlias     = 1<<TKIND_ALIAS;
const int tfUnion     = 1<<TKIND_UNION;
const int tfAllKinds  =(1<<TKIND_MAX)-1;
const int tfScanOnly  = 1<<15;
const int tfLibHeader = 1<<14;
const int tfDispHeader= 1<<13;
const int tfDispImpl  = 1<<12;
const int tfBoolType  = 1<<11;  // OR into libMode[1] if compiler bool support

char* infoKind[] = 
  {"ENUM","RECORD","MODULE","INTERFACE","DISPATCH","COCLASS","ALIAS","UNION"};

char* typeFlagText[] = {
  "appobject",     // 1   TYPEFLAG_FAPPOBJECT
  "cancreate",     // 2   TYPEFLAG_FCANCREATE
  "licensed",      // 4   TYPEFLAG_FLICENSED
  "predeclid",     // 8   TYPEFLAG_FPREDECLID
  "hidden",        // 16  TYPEFLAG_FHIDDEN
  "control",       // 32  TYPEFLAG_FCONTROL
  "dual",          // 64  TYPEFLAG_FDUAL
  "nonextensible", // 128 TYPEFLAG_FNONEXTENSIBLE
  "oleautomation", // 256 TYPEFLAG_FOLEAUTOMATION
  "TYPEFLAG256",
  "TYPEFLAG512",
};
const int typeFlagCount = sizeof(typeFlagText)/sizeof(char*);

char* implFlagText[] = {
  "default",       // 1 IMPLTYPEFLAG_FDEFAULT
  "source",        // 2 IMPLTYPEFLAG_FSOURCE
  "restricted",    // 4 IMPLTYPEFLAG_FRESTRICTED
  "IMPLTYPEFLAG8",
  "IMPLTYPEFLAG16",
  "IMPLTYPEFLAG32",
};
const int implFlagCount = sizeof(implFlagText)/sizeof(char*);

char* memberFlagText[] = {
  "restricted",   // 1   FUNCFLAG_FRESTRICTED (VARFLAG_FREADONLY->invokeKind)
  "source",       // 2   FUNCFLAG_FSOURCE       VARFLAG_FSOURCE
  "bindable",     // 4   FUNCFLAG_FBINDABLE     VARFLAG_FBINDABLE
  "requestedit",  // 8   FUNCFLAG_FREQUESTEDIT  VARFLAG_FREQUESTEDIT
  "displaybind",  // 16  FUNCFLAG_FDISPLAYBIND  VARFLAG_FDISPLAYBIND
  "defaultbind",  // 32  FUNCFLAG_FDEFAULTBIND  VARFLAG_FDEFAULTBIND
  "hidden",       // 64  FUNCFLAG_FHIDDEN       VARFLAG_FHIDDEN
  "FUNCFLAG128",
  "FUNCFLAG256",
};
const int memberFlagCount = sizeof(memberFlagText)/sizeof(char*);

char* infoCpp[] =     // add delimiting space after identifier as needed
  {"enum ","struct ","","class _ICLASS ","class ","//","typedef ","union "};

char* invokeKind[] = {
  "",              // 0 no INVOKEKIND flags
  "method",        // 1 INVOKE_FUNC
  "propget",       // 2 INVOKE_PROPERTYGET
  "prop r/o",      // 3 VAR_DISPATH + VARFLAG_FREADONLY
  "propset",       // 4 INVOKE_PROPERTYPUT
  "?"       ,      // 5
  "propgetset",    // 6 
  "prop r/w",      // 7 VAR_DISPATCH
  "propputref",    // 8 INVOKE_PROPERTYPUTREF
  "?",             // 9
  "?"              // 10
};

char* dataType[] = {
  "void",          //  0 void
  "NULL",          //  1 SQL NULL
  "short",         //  2 signed short
  "long",          //  3 signed long
  "float",         //  4 IEEE 4-byte
  "double",        //  5 IEEE 8-byte
  "CY",            //  6 currency
  "DATE",          //  7 datetime as double
  "BSTR",          //  8 char far* global mem with int size before
  "IDispatch*",    //  9 dispatch interface
  "SCODE",         // 10 OLE return status
  "bool",          // 11 boolean
  "VARIANT far*",  // 12 pointer to VARIANT union
  "IUnknown*",     // 13 unspecified COM interface
  "<14>",
  "<15>",
  "signed char",   // 17 unsigned char, byte
  "unsigned char",
  "unsigned short",
  "unsigned long",
  "LARGE_INTEGER",
  "ULARGE_INTEGER",
  "signed int",
  "unsigned int",
  "void",
  "HRESULT",
  "<ptr>",
  "<27>",
  "<array>",
  "<userdef>",
  "char far*",
  "wchar far*",
};
const int dataTypeCount = sizeof(dataType)/sizeof(char*);

char* autoType[] = {
  "void",          //  0 void
  "NULL",          //  1 SQL NULL
  "short",         //  2 signed short
  "long",          //  3 signed long
  "float",         //  4 IEEE 4-byte
  "double",        //  5 IEEE 8-byte
  "TAutoCurrency", //  6 currency
  "TAutoDate",     //  7 datetime as double
  "TAutoString",   //  8 char far* global mem with int size before
};
const int autoTypeCount = sizeof(autoType)/sizeof(char*);

  char foldName[256+1] = {
  "_\0_\0_\0f\0_\0_\0_\0_\0_\0_\0S\0_\0OE_\0_\0_\0"
  "_\0_\0_\0_\0_\0_\0_\0_\0_\0TMs\0_\0oe_\0_\0Y\0"
  "_\0_\0c\0L\0_\0Y\0_\0_\0_\0c\0a\0_\0_\0_\0r\0_\0"
  "0\0_\0\062\0\063\0_\0u\0_\0_\0_\0\061\0o\0_\0_\0_\0_\0_\0"
  "A\0A\0A\0A\0AEA\0AEC\0E\0E\0E\0E\0I\0I\0I\0I\0"
  "D\0N\0O\0O\0O\0O\0OEx\0O\0U\0U\0U\0UEY\0_\0ss"
  "a\0a\0a\0a\0aea\0aec\0e\0e\0e\0e\0i\0i\0i\0i\0"
  "o\0n\0o\0o\0o\0o\0oe_\0o\0u\0u\0u\0uey\0_\0y\0"
};

const int fnObjectByRef = 1;  // generate code passing proxy object by ref
const int fnPrefixGet   = 2;  // prefix identifier name with "Get"
const int fnPrefixSet   = 4;  // prefix identifier name with "Set"
const int fnClassName   = 8;  // add classname:: before identifier
const int fnAutoTypes   = 16; // translate types to wrappered TAuto...
const int fnIterator    = 32; // emit TAutoIterator<type>&

bool IsDispObject(ITypeInfo* typeInfo, TYPEDESC far& typeDesc)
{
  if (typeDesc.vt != VT_USERDEFINED)
    return false;
  TComRef<ITypeInfo> refTypeInfo;
  OLECALL(typeInfo->GetRefTypeInfo(typeDesc.hreftype,refTypeInfo),"TypeInfo::GetRefTypeInfo");
  refTypeInfo.GetAttr();
  return refTypeInfo.Attr->typekind==TKIND_DISPATCH;
}

char* ClassName = 0;   // will become member variable

bool FormatTypeName(ITypeInfo* typeInfo, TYPEDESC far& typeDescRef,
                   char far* name, ostream& out, int flags = 0)
{
  bool isDispObject = false;
  TYPEDESC far* typeDesc = &typeDescRef;
  ARRAYDESC far* arrayDesc = 0;
  if (flags & fnIterator)
    out << "TAutoEnumerator<";
  for (int derefCount = 0; typeDesc->vt == VT_PTR; derefCount++)
    typeDesc = typeDesc->lptdesc;
  if (typeDesc->vt == VT_USERDEFINED) {
    TComRef<ITypeInfo> refTypeInfo;
    OLECALL(typeInfo->GetRefTypeInfo(typeDesc->hreftype,refTypeInfo),"TypeInfo::GetRefTypeInfo");
    refTypeInfo.GetDocumentation();
    out << refTypeInfo.Name;
    refTypeInfo.GetAttr();
    if (flags & fnObjectByRef && refTypeInfo.Attr->typekind==TKIND_DISPATCH &&
        !(flags & fnIterator)){
      out << '&';    // need reference for automation proxy class
    } isDispObject = true;
  } else if (typeDesc->vt == VT_CARRAY) {
    arrayDesc = typeDesc->lpadesc;
    FormatTypeName(typeInfo, arrayDesc->tdescElem, 0, out);
  } else {
    if ((flags & fnAutoTypes) && (typeDesc->vt & 31) < autoTypeCount)
      out << autoType[typeDesc->vt & 31];
    else
      out << dataType[typeDesc->vt & 31];
  }
  if (typeDesc->vt & VT_BYREF)  // should never happen
    derefCount++;
  while (derefCount--)
    out << " far*";
  if (flags & fnIterator)
    out << ">&";
  if (name) {
    char* buf;
    int len = lstrlen(name);
    int nonascii = 0;
    for (unsigned char far* pc = (unsigned char far*)name; *pc; pc++)
      if (*pc >= 128)
        nonascii++;
    if (nonascii) {
      unsigned char far* pn = (unsigned char far*)name;
      buf = new char[nonascii + len + 1];
      name = buf;
      unsigned char c;
      do {
        c = *pn++;
        if (c < 128) {
          *buf++ = c;
        } else {
          char* px = foldName + (c-128)*2;
          *buf++ = *px++;
          if (*px)
            *buf++ = *px;
        }
      } while (c);
    }
    out << ' ';
    if (ClassName && (flags & fnClassName))
      out << ClassName << "::";
    if (flags & fnPrefixGet)
      out << "Get";
    if (flags & fnPrefixSet)
      out << "Set";
    out << name;
    if (nonascii)
      delete name;
  }
  if (arrayDesc)
    for (int dim = 0; dim < arrayDesc->cDims; dim++)
      out << '[' << arrayDesc->rgbounds[dim].cElements << ']';
  return isDispObject;
}

void FormatGuidLang(GUID far& guid, LCID locale, ostream& out)
{
  char guidBuf[38+1] = "{NULL}"; 
  int notNull = 0;
  int far* pg = (int far*)&guid;
  for (int i = sizeof(GUID)/sizeof(int); i--; pg++)
    notNull |= *pg;
  if (notNull)
    wsprintf(guidBuf, "{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
             guid.Data1, guid.Data2, guid.Data3,
             guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3],
             guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
  out << ' ' << guidBuf << '\\' << hex << LANGIDFROMLCID(locale) << dec;
}

void FormatVers(int major, int minor, ostream& out)
{
  if (major)
    out << ' ' << major << '.' << minor;
}

void FormatDispId(DISPID id, int invKind, uint16 flags, ostream& out)
{
  out << "[id(";
  if ((long)id > 9999 || (long)id < -9999)
    out << "0x" << hex << id << dec;
  else
    out << id;
  out << ')';
  if (invKind)
    out << ", " << invokeKind[invKind];
  for (int i = 0; flags; i++, flags >>= 1) {
    if (flags & 1)
      out << ", " << memberFlagText[i];
  }
  out << ']';
}

// assumed that caller of this function called GetDocumenation() on typeInfo

void FormatTypeInfo(TComRef<ITypeInfo>& typeInfo, int mode, ostream& out)
{
//typeInfo.GetDocumentation();
  typeInfo.GetAttr();
  int kind = typeInfo.Attr->typekind;
  if (typeInfo.Attr->typekind != TKIND_ALIAS) {
    out << "\n// TKIND_" << infoKind[kind] << ": " << typeInfo.Name;
    FormatVers(typeInfo.Attr->wMajorVerNum,typeInfo.Attr->wMinorVerNum,out);
    FormatGuidLang(typeInfo.Attr->guid, typeInfo.Attr->lcid, out);
    out << ' ' << typeInfo.Doc << '\n';
    int typeFlags = typeInfo.Attr->wTypeFlags;
    if (typeFlags && !(mode & (tfDispHeader | tfDispImpl))) {
      char* delim = "//  [";
      for (int tflag = 0; tflag < implFlagCount; tflag++, typeFlags >>= 1)
        if (typeFlags & 1) {  
          out << delim << typeFlagText[tflag];
          delim = ", ";
      }
      out << "]\n";
    }
    out << '\n';
    if (!(mode & tfDispImpl))
      out << infoCpp[kind];
  }
  switch (kind) {
    case TKIND_MODULE: {
      for (int varIndex = 0; varIndex < typeInfo.Attr->cVars; varIndex++) {
        typeInfo.GetVarDesc(varIndex);
        typeInfo.GetDocumentation(typeInfo.VarDesc->memid);
        out << "    ";
        FormatTypeName(typeInfo, typeInfo.VarDesc->elemdescVar.tdesc, typeInfo.Name, out);
        out << "; // ";
        int invKind = typeInfo.VarDesc->wVarFlags & VARFLAG_FREADONLY ? 3 : 7;
        FormatDispId(typeInfo.VarDesc->memid, invKind,
                     typeInfo.VarDesc->wVarFlags & ~VARFLAG_FREADONLY, out);
        out << '\n';
      }
      for (int funcIndex = 0; funcIndex < typeInfo.Attr->cFuncs; funcIndex++) {
        typeInfo.GetFuncDesc(funcIndex);
        typeInfo.GetDocumentation(typeInfo.FuncDesc->memid);
        int argCount = typeInfo.FuncDesc->cParams;
        int argIndex;
        TBSTR argName[35];      // max. arg count + 1, minimum 35 for MSWord6
        unsigned int nameCount;
        OLECALL(typeInfo->GetNames(typeInfo.FuncDesc->memid, argName[0],
                                   sizeof(argName)/sizeof(TBSTR), &nameCount),"TKIND_INTERFACE GetNames");
        if (typeInfo.Doc)
          out << "    // " << typeInfo.Doc << '\n';
        out << "    ";
        for (argIndex = 0; argIndex <= argCount; argIndex++) {
          ELEMDESC far* elemDesc = argIndex==0 ?
                          &typeInfo.FuncDesc->elemdescFunc :
                          typeInfo.FuncDesc->lprgelemdescParam + (argIndex-1);
          FormatTypeName(typeInfo, elemDesc->tdesc, argIndex < nameCount ?
                         (char far*)argName[argIndex] : (char far*)0, out);
          if (argIndex == 0)
            out << '(';
          else if (argIndex != argCount)
            out << ", ";
        }
        out << "); // ";
        FormatDispId(typeInfo.FuncDesc->memid, 0,
                     typeInfo.FuncDesc->wFuncFlags, out);
        out << '\n';
      }
      out << "\n";
      break;
    }

    case TKIND_UNION:
    case TKIND_RECORD: {
      out << typeInfo.Name << " {\n"; /*}*/
      for (int membIndex = 0; membIndex < typeInfo.Attr->cVars; membIndex++) {
        typeInfo.GetVarDesc(membIndex);
        typeInfo.GetDocumentation(typeInfo.VarDesc->memid);
        out << "  ";
        FormatTypeName(typeInfo, typeInfo.VarDesc->elemdescVar.tdesc, typeInfo.Name, out);
        out << ";\n";
      }
      /*{*/ out << "};\n";
      break;
    }
    case TKIND_ALIAS: {
      out << infoCpp[kind] << ' ';
      FormatTypeName(typeInfo, typeInfo.Attr->tdescAlias, typeInfo.Name, out);
      out << ";\n";
      break;
    }
    case TKIND_ENUM: {
      out << typeInfo.Name << " {\n"; /*}*/
      for (int enumIndex = 0; enumIndex < typeInfo.Attr->cVars; enumIndex++) {
        typeInfo.GetVarDesc(enumIndex);
        typeInfo.GetDocumentation(typeInfo.VarDesc->memid);
        out << "  " << typeInfo.Name;
        if (typeInfo.VarDesc->varkind == VAR_CONST
         && typeInfo.VarDesc->lpvarValue->vt == VT_I2)
          out << " = " << typeInfo.VarDesc->lpvarValue->iVal;
        out << ",\n";
      }
      /*{*/ out << "};\n";
      break;
    }
    case TKIND_INTERFACE: {
      out << typeInfo.Name;
      int baseCount = typeInfo.Attr->cImplTypes;
      for (int baseIndex = 0; baseIndex < baseCount; baseIndex++) {
        out << (baseIndex ==0 ? " : public " : ", public ");
        HREFTYPE hrefType;
        OLECALL(typeInfo->GetRefTypeOfImplType(baseIndex, &hrefType),"TKIND_INTERFACE GetRefTypeofImplType");
        TComRef<ITypeInfo> refTypeInfo;
        OLECALL(typeInfo->GetRefTypeInfo(hrefType, refTypeInfo),"TKIND_INTERFACE GetRefTypeInfo"); 
        refTypeInfo.GetDocumentation();
        out << refTypeInfo.Name;
      }
      out << " {\n  public:\n"; /*}*/
      for (int funcIndex = 0; funcIndex < typeInfo.Attr->cFuncs; funcIndex++) {
        typeInfo.GetFuncDesc(funcIndex);
        typeInfo.GetDocumentation(typeInfo.FuncDesc->memid);
        int argCount = typeInfo.FuncDesc->cParams;
        int argIndex;
        TBSTR argName[35];      // max. arg count + 1, minimum 35 for MSWord6
        unsigned int nameCount;
        OLECALL(typeInfo->GetNames(typeInfo.FuncDesc->memid, argName[0],
                                   sizeof(argName)/sizeof(TBSTR), &nameCount),"TKIND_INTERFACE GetNames");
        if (typeInfo.Doc)
          out << "    // " << typeInfo.Doc << '\n';
        if (typeInfo.FuncDesc->wFuncFlags & FUNCFLAG_FRESTRICTED)
          out << "//  ";    // not accessible from dispatch controller
        else
          out << "    ";
        for (argIndex = 0; argIndex <= argCount; argIndex++) {
          ELEMDESC far* elemDesc = argIndex==0 ?
                          &typeInfo.FuncDesc->elemdescFunc :
                          typeInfo.FuncDesc->lprgelemdescParam + (argIndex-1);
          FormatTypeName(typeInfo, elemDesc->tdesc, argIndex < nameCount ?
                         (char far*)argName[argIndex] : (char far*)0, out);
          if (argIndex == 0)
            out << '(';
          else if (argIndex != argCount)
            out << ", ";
        }
        out << ") = 0; // ";
        FormatDispId(typeInfo.FuncDesc->memid, 0,
                     typeInfo.FuncDesc->wFuncFlags, out);
        out << '\n';
      }
      /*{*/ out << "};\n";
      break;
    }
    case TKIND_DISPATCH: {
      TYPEDESC typeDescVoid;
      typeDescVoid.vt = VT_VOID;
      char semi;
      if (mode & tfDispImpl) {
        ClassName = new char[lstrlen(typeInfo.Name)+1];
        lstrcpy(ClassName, typeInfo.Name);
        semi = ' ';
      } else {
        semi = ';';
        out << typeInfo.Name;
        if (mode & tfDispHeader)
          out << " : public TAutoProxy";
        out << " {\n  public:\n"; /*}*/
        if (mode & tfDispHeader)
          out << "    " << typeInfo.Name << "() : TAutoProxy(0x"
              << hex << LANGIDFROMLCID(typeInfo.Attr->lcid) << dec << ") {}\n";
      }
      for (int varIndex = 0; varIndex < typeInfo.Attr->cVars; varIndex++) {
        int formatFlags = 0;
        if (mode & tfDispHeader)
          formatFlags = fnObjectByRef | fnPrefixGet | fnAutoTypes;
        if (mode & tfDispImpl)
          formatFlags = fnObjectByRef | fnPrefixGet | fnClassName | fnAutoTypes;
        typeInfo.GetVarDesc(varIndex);
        TYPEDESC& typeDesc = typeInfo.VarDesc->elemdescVar.tdesc;
        int invKind = typeInfo.VarDesc->wVarFlags & VARFLAG_FREADONLY ? 3 : 7;
        // should we insure that (type.Info.VarDesc->varkind==VAR_DISPATCH) ?
        typeInfo.GetDocumentation(typeInfo.VarDesc->memid);
        if (!(mode & tfDispImpl) && typeInfo.Doc)
          out << "    // " << typeInfo.Doc << '\n';
        bool isDispObject = IsDispObject(typeInfo, typeDesc);
        bool boolProp = !(mode & tfBoolType) && typeDesc.vt == VT_BOOL;
        bool boolRef  = !(mode & tfBoolType) && typeDesc.vt == VT_PTR
                                    && typeDesc.lptdesc->vt == VT_BOOL;
        do {
          char* argName = 0;
          if (!(mode & tfDispImpl))
            out << "    ";
          if (formatFlags == 0 || 
             !((formatFlags & fnPrefixSet) || isDispObject)){
            FormatTypeName(typeInfo, typeDesc, typeInfo.Name, out, formatFlags);
            if (formatFlags & fnPrefixGet)
              out << "()";
            out << semi << "    ";
          } else {
            FormatTypeName(typeInfo,typeDescVoid,typeInfo.Name,out,formatFlags);
            if (mode & tfDispImpl)
              argName = isDispObject ? "obj" : "val";
            out << '(';
            FormatTypeName(typeInfo,typeDesc,argName,out,
                           formatFlags & (fnObjectByRef | fnAutoTypes));
            out << ')' << semi;
          }
          if (mode & tfDispImpl) {
            out << "\n{\n  AUTONAMES0(\"" << typeInfo.Name
                << "\")\n  AUTOARGS0()\n  AUTOCALL_PROP_"; /*}*/
            if (formatFlags & fnPrefixSet)
              out << "SET";
            else if (isDispObject)
              out << "REF";
            else if (boolProp)
              out << "CONV(TAutoBool)";
            else if (boolRef)
              out << "CONV(TAutoBoolRef)";
            else
              out << "GET";
            if (argName) {
              if (boolProp)
                out << "(TAutoBool(" << argName << "))";
              else if (boolRef)
                out << "(TAutoBoolRef(" << argName << "))";
              else
                out << '(' << argName << ')';
            }
            /*{*/ out << "\n}\n";
          } else {
            out << " // ";
            FormatDispId(typeInfo.VarDesc->memid, invKind,
                         typeInfo.VarDesc->wVarFlags & ~VARFLAG_FREADONLY, out);
          }
          out << '\n';
          if ((formatFlags & fnPrefixGet) && invKind == 7)
            formatFlags ^= (fnPrefixGet | fnPrefixSet);
          else
            formatFlags = 0;
        } while (formatFlags & fnPrefixSet);
      }
      for (int funcIndex = 0; funcIndex < typeInfo.Attr->cFuncs; funcIndex++) {
        int formatFlags = 0;
        if (mode & tfDispHeader)
          formatFlags = fnObjectByRef | fnAutoTypes;
        if (mode & tfDispImpl)
          formatFlags = fnObjectByRef | fnAutoTypes | fnClassName;
        typeInfo.GetFuncDesc(funcIndex);
        if (typeInfo.FuncDesc->wFuncFlags & FUNCFLAG_FRESTRICTED)
          continue;                 // not accessible from dispatch controller
        typeInfo.GetDocumentation(typeInfo.FuncDesc->memid);
        int argCount = typeInfo.FuncDesc->cParams;
        TBSTR argNames[35];     // max. arg count + 1, minimum 35 for MSWord6
        unsigned int nameCount;
        OLECALL(typeInfo->GetNames(typeInfo.FuncDesc->memid, argNames[0],
                sizeof(argNames)/sizeof(TBSTR), &nameCount),"TKIND_DISPATCH GetNames");
        if (!(mode & tfDispImpl)) {
          if (typeInfo.Doc)
            out << "    // " << typeInfo.Doc << '\n';
          out << "    ";
        }
        int argIndex  = -1;   // index into ELEMDESC[], -1 for return type
        int nameIndex = 0;    // index into name table, no propset param name
        int outParam  = 0;    // index of type/name being output
        bool voidRet = false;
        bool boolRet = false;
        bool boolRetRef = false;
        bool isObject = false;
        bool isIterator = (typeInfo.FuncDesc->memid == DISPID_NEWENUM);
        for ( ; argIndex<argCount; argIndex++, outParam++) {
          TYPEDESC far* typeDesc = &typeInfo.FuncDesc->elemdescFunc.tdesc;
          if (argIndex >= 0)  {        // processing an argument
            typeDesc = &typeInfo.FuncDesc->lprgelemdescParam[argIndex].tdesc;
          } else if (outParam == 0 && (mode & (tfDispHeader | tfDispImpl)) &&
                     (IsDispObject(typeInfo, *typeDesc) || isIterator)) {
            typeDesc = &typeDescVoid;
            argIndex--;           // reprocess return as first arg
            isObject = true;
          } else if (typeDesc->vt == VT_VOID || typeDesc->vt == VT_EMPTY) {
            voidRet = true;
          } else if (!(mode & tfBoolType) && typeDesc->vt == VT_BOOL) {
            boolRet = true;
          } else if (!(mode & tfBoolType) && typeDesc->vt == VT_PTR
                                 && typeDesc->lptdesc->vt == VT_BOOL) {
            boolRetRef = true;
          }
          char far* name = 0;
          char argName[10];
          if (isObject && argIndex == -1) {
            if (mode & tfDispImpl)
              name = "obj";
            if (isIterator)
              formatFlags |= fnIterator;
          } else if (argIndex==0 && typeInfo.FuncDesc->invkind>=INVOKE_PROPERTYPUT) {
            if (mode & tfDispImpl)
              name = "val";
          } else if (nameIndex >= nameCount) {
            if (mode & tfDispImpl)
              wsprintf(name = argName, "arg%d", argIndex+1);
          } else
            name = argNames[nameIndex++];
          if (outParam == 0 && (mode & (tfDispHeader | tfDispImpl))) {
            if (typeInfo.FuncDesc->invkind>=INVOKE_PROPERTYPUT)
              formatFlags |= fnPrefixSet;  // must differentiate from get
            else if (typeInfo.FuncDesc->invkind==INVOKE_PROPERTYGET) {
              if (isIterator)
                name = "Enumerate";
              else
                formatFlags |= fnPrefixGet;  // get&set may have same name
            }
          }
          FormatTypeName(typeInfo, *typeDesc, name, out, formatFlags);
          formatFlags &= ~fnIterator;
          if (outParam == 0) {
            out << '(';
            formatFlags &= ~(fnClassName | fnPrefixGet | fnPrefixSet);
          }
          else if (argIndex != argCount-1)
            out << ", ";
        }
        out << ')' << semi;
        if (mode & tfDispImpl) {
          out << "\n{\n  AUTONAMES0("; /*}*/
          if (isIterator)
            out << "DISPID_NEWENUM";
          else
            out << '"' << typeInfo.Name << '"';
          if (typeInfo.FuncDesc->invkind>=INVOKE_PROPERTYPUT)
            argCount--;
          out << ")\n  AUTOARGS" << argCount << '(';
          argIndex = 1;                 // 1-based for following loop
          for ( ; argIndex <= argCount; argIndex++) { // 1-based
            if (argIndex != 1)
              out << ", ";
            TYPEDESC far& typeDesc =
                       typeInfo.FuncDesc->lprgelemdescParam[argIndex-1].tdesc;
            bool boolArg = !(mode & tfBoolType) && typeDesc.vt == VT_BOOL;
            bool boolRef = !(mode & tfBoolType) && typeDesc.vt == VT_PTR
                                       && typeDesc.lptdesc->vt == VT_BOOL;
            if (boolArg)
              out << "TAutoBool(";
            else if (boolRef)
              out << "TAutoBoolRef(";
            if (argIndex < nameCount)
              out << argNames[argIndex];
            else
              out << "arg" << argIndex;
            if (boolArg || boolRef)
              out << ")";
          }
          out << ")\n  AUTOCALL_";
          if (typeInfo.FuncDesc->invkind==INVOKE_PROPERTYGET) {
            if (isObject)
              out << "PROP_REF(obj)";
            else
              out << "PROP_GET";
          } else if (typeInfo.FuncDesc->invkind==INVOKE_PROPERTYPUT) {
            out << "PROP_SET(val)";
          } else {
            out << "METHOD_";
            if (isObject)
              out << "REF(obj)";
            else if (voidRet)
              out << "VOID";
            else if (boolRet)
              out << "CONV(TAutoBool)";
            else if (boolRetRef)
              out << "CONV(TAutoBoolRef)";
            else
              out << "RET";
          }
          /*{*/ out << "\n}\n";  //(for editor brace check)
        } else {
          out << " // ";
          FormatDispId(typeInfo.FuncDesc->memid,
                       typeInfo.FuncDesc->invkind,
                       typeInfo.FuncDesc->wFuncFlags, out);
        }
        out << '\n';
      }
      if (!(mode & tfDispImpl))
        /*{*/ out << "};\n";
      break;
    }
    case TKIND_COCLASS: {
      for (unsigned int cindex=0; cindex<typeInfo.Attr->cImplTypes; cindex++) {
        HREFTYPE hrefType;
        OLECALL(typeInfo->GetRefTypeOfImplType(cindex, &hrefType), "GetRefTypeofImplType");
        int typeFlags;
        OLECALL(typeInfo->GetImplTypeFlags(cindex, &typeFlags), "GetImplTypeFlags");
        TComRef<ITypeInfo> refTypeInfo;
        OLECALL(typeInfo->GetRefTypeInfo(hrefType, refTypeInfo),"TKIND_COCLASS GetRefTypeInfo"); 
        refTypeInfo.GetDocumentation();
        out << "\n//  " << refTypeInfo.Name;
        char* delim = "  [";
        if (typeFlags) {
          for (int iflag = 0; iflag < implFlagCount; iflag++, typeFlags >>= 1)
            if (typeFlags & 1) {
              out << delim << implFlagText[iflag];
              delim = ", ";
            }
          out << ']';
        }
      }
      out << "\n\n";
      break;
    }
  }
  delete ClassName;
  ClassName = 0;
}

//____________________________________________________________________________
//
// Local class to hold selection and iterator information for type library
//____________________________________________________________________________

class TLogTypeInfo {
  public:
    typedef bool (*TCall)(TLogTypeInfo&);

    TLogTypeInfo(HWND hWnd);
   ~TLogTypeInfo()        {delete SelectList;}
    bool  Report();
    HWND  GetWindow()      {return Window;}
    int   GetSelectCount() {return SelectCount;}
    int*  GetSelectList()  {return SelectList;}
    void  SetSelectList(int count, int* list);
    int   GetRequestCount() {return ReqCount;}
    void  SetRequestList(int count, int* list, char** names);
    void  SetCallback(TLogTypeInfo::TCall proc) {Proc = proc;}
    bool  MatchRequest();  // return true to continue, false if all done
    char* ExtractRequest();// return unmatched type name, 0 if list empty
    void ClearLists();
    int   Index;        // returned selection index, within user select types
    int   TypeIndex;    // returned typeinfo index, within entire type library
    char* TypeKind;     // returned typeinfo kind text
    char far* TypeName; // returned typeinfo name text
  private:
    char** ReqNames;    // temp requested type names
    int    ReqCount;    // temp requested name count
    int*   SelectList;  // list of selected typeinfos in type library
    int    SelectCount; // number of selected items
    HWND   Window;      // window to receive data
    TCall  Proc;        // callback function to display data
};
inline TLogTypeInfo::TLogTypeInfo(HWND hWnd)
                    : Window(hWnd), SelectList(0), Proc(0)
{
  ClearLists();  // SelectList must be 0 to prevent delete of garbage
}
inline void TLogTypeInfo::ClearLists()
{
  if(!ReqNames)
    delete SelectList;
  ReqNames = 0;
  SelectList = 0;
  SelectCount = 0;
  ReqCount = 0;
}
inline void TLogTypeInfo::SetSelectList(int count, int* list)
{
  ClearLists();
  SelectCount = count;
  SelectList = list;
}
inline void TLogTypeInfo::SetRequestList(int count, int* list, char** names)
{
  ClearLists();
  ReqCount = count;
  ReqNames = names;
  SelectList = list;
}
inline bool TLogTypeInfo::Report()
{
  return Proc ? Proc(*this) : MatchRequest();
}
bool TLogTypeInfo::MatchRequest()
{
  if (!ReqCount)
    return false;
  for (int i = 0; i < ReqCount; i++) {
    if (stricmp(TypeName, ReqNames[i]) == 0) {
      SelectList[SelectCount++] = TypeIndex;
      if (--ReqCount != i)
        memcpy(&ReqNames[i],&ReqNames[i+1],(ReqCount-i)*sizeof(int));
      return ReqCount != 0;
    }
  }  
  return true;  // keep going
}
char* TLogTypeInfo::ExtractRequest()
{
  if (!ReqCount)
    return 0;
  char* name = ReqNames[0];
  if (--ReqCount)
    memcpy(&ReqNames[0], &ReqNames[1], ReqCount*sizeof(int));
  return name;
}

//____________________________________________________________________________
//
// ITypeLib iterator, emits file header info, calls ITypeInfo iterator
//____________________________________________________________________________

void ReadTypeLib(char* libName, char* incName, int mode, ostream& out,
                 TLogTypeInfo& log)
{
  try {       // catch OLE errors, no OLE calls are made outside of this block
    char nameBuf[50];      // large enough for basename.tlb, overflow not fatal
    TOleAllocator oleMem(0);
    TComRef<ITypeLib> typeLib;
    TComRef<ITypeInfo> coclassInfo;
    OLECALL(::LoadTypeLib(libName, typeLib),"LoadTypeLib");
    typeLib.GetAttr();
    if (mode & tfLibHeader) {
      typeLib.GetDocumentation();
      if (::GetFileTitle(libName, nameBuf, sizeof(nameBuf)) <= 0)
        out << "// Type Library: " << nameBuf;
      out << "  " << typeLib.Doc << '\n';
      out << "// " << typeLib.Name;
      FormatVers(typeLib.Attr->wMajorVerNum, typeLib.Attr->wMinorVerNum, out);
      FormatGuidLang(typeLib.Attr->guid, typeLib.Attr->lcid, out);
      out << "\n\n";
    }
    int infoCount = typeLib->GetTypeInfoCount();
    if (incName)
      out << "#include " << incName << "\n";
    if (mode & tfDispHeader) {
      for (int infoIndex = 0; infoIndex < infoCount; infoIndex++) {
        TYPEKIND infoType;
        typeLib->GetTypeInfoType(infoIndex, &infoType);
        if (infoType == TKIND_DISPATCH) {
          TComRef<ITypeInfo> typeInfo;
          OLECALL(typeLib->GetTypeInfo(infoIndex, typeInfo),"typeLib->GetTypeInfo");
          typeInfo.GetDocumentation();
          out << "\nclass " << typeInfo.Name << ';';
        }
        if (infoType == TKIND_COCLASS) {
          OLECALL(typeLib->GetTypeInfo(infoIndex, coclassInfo),"typeLib->GetTypeInfo");
        }
      }
      out << "\n";
    }
    // need to scan coclass typeinfo for [source] classes
    // and eliminate them from HXX/CXX code generation
    // eventually should emit server code tables
    //
    int  infoIndex = 0;
    int  selIndex  = 0;
    int  selCount  = log.GetSelectCount();
    int* selList   = log.GetSelectList();
    for (; infoIndex < infoCount; infoIndex++) {
      if (selList && !(mode & tfScanOnly)) {     // partial selection
        if (!selCount || infoIndex != selList[selIndex])
          continue;
        selCount--;
      }
      TYPEKIND infoType;
      typeLib->GetTypeInfoType(infoIndex, &infoType);
      if (((1<<infoType) & mode) == 0)
        continue;
      TComRef<ITypeInfo> typeInfo;
      OLECALL(typeLib->GetTypeInfo(infoIndex, typeInfo),"GetTypeInfo");
      typeInfo.GetDocumentation();
      typeInfo.GetAttr();
      log.TypeIndex = infoIndex;
      log.Index     = selIndex++;
      log.TypeName  = typeInfo.Name;
      log.TypeKind  = infoKind[infoType];
      if (!log.Report())
        break;
      if (mode & tfScanOnly)
        continue;
      FormatTypeInfo(typeInfo, mode, out);
    }
  }
  catch(TXOle& x) {  // convert OLE exception into local exception
    Error(libName, x.why().c_str());
  }
}

//____________________________________________________________________________
//
// Command line and UI processing, creates streams
//____________________________________________________________________________

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <fstream.h>
#include <strstrea.h>

// Command line token extraction class

class TCmdLine {
  public:
    enum Kind {Null, Name, Option, Value};
    TCmdLine(char far* cmdLine);
   ~TCmdLine();
    Kind  NextToken();
    int   TokenLen;
    char* Token;
    Kind  Type;
  private:
    char* Buf;
    Kind  NextType;
};

TCmdLine::TCmdLine(char far* cmdLine) : NextType(Name)
{
  Token = Buf = new char[lstrlen(cmdLine)+1];
  TokenLen = -1;         // cancels increment on next assignment
  lstrcpy(Buf, cmdLine);
}

TCmdLine::~TCmdLine()
{
  delete Buf;
}

TCmdLine::Kind TCmdLine::NextToken()
{
  Token += (TokenLen + 1);
  if (NextType == Name) {           // name or leading spaces
    Token += strspn(Token, " \t");  // skip leading white space
    switch (*Token++) {
      case 0:
        return Type = NextType = Null;
      case '=':
        Type = Value;
        break;
      case '-':
      case '/':
        Type = Option;
        break;
      default:
        Type = Name;
        Token--;
    }
  } else {   // must have stopped on a delimiter
    Type = NextType;
    if (Type == Null)
      return Type;
  }
  TokenLen = strcspn(Token, "=/- \t");
  char* nextToken = Token + TokenLen;
  switch (*nextToken) {
    case 0:
      NextType = Null;
      break;
    case '=':
      NextType = Value;
      break;
    case '-':
    case '/':
      NextType = Option;
      break;
    default:
      NextType = Name;
  }
  *nextToken = 0;  // null-terminate current token
  return Type;
}

// File name processing

enum  fileKind    { fkDispHdr, fkDispSrc, fkFullCpp,      fkCount };
char* optText[] = { "Header",  "Code",    "Definitions" };
char* fileExt[] = { "HXX",     "CXX",     "HPP" };
int   libMode[] = { tfEnum|tfAlias|tfDispatch|tfLibHeader|tfDispHeader,
                    tfDispatch|tfDispImpl, tfAllKinds|tfLibHeader };
char* stdFile[] = { ".HXX",    ".CXX",    0 };     // OC controller proxy code
char* cppFile[] = { 0,         0,         ".HPP" };// standard C++ defs       


int GenerateFiles(char* libName, char** outFiles, TLogTypeInfo& log)
{
  char outName[_MAX_PATH];
  char outDrive[_MAX_DRIVE];
  char outDir  [_MAX_DIR];
  char outFName[_MAX_FNAME];
  char outExt  [_MAX_EXT];
  char libDrive[_MAX_DRIVE];
  char libDir  [_MAX_DIR];
  char libFName[_MAX_FNAME];
  char libExt  [_MAX_EXT];
  char incFile [_MAX_FNAME+_MAX_EXT+2];
  char* incName;

  _splitpath(libName, libDrive, libDir, libFName, libExt);
  int outCount = 0;               // count of files actually output
  for (int fileIndex = 0; fileIndex < fkCount; fileIndex++) {
    if (!outFiles[fileIndex])
      continue;
    _splitpath(outFiles[fileIndex], outDrive, outDir, outFName, outExt);
    _makepath (outName,
               outDrive[0] ? outDrive : libDrive,
               outDir[0]   ? outDir   : libDir,
               outFName[0] ? outFName : libFName,
               outExt[0]   ? outExt   : fileExt[fileIndex]);
    ofstream out;
    out.open(outName);
    ErrorIf(out.bad(), outName, IDS_OUTFILEERR);
    switch(fileIndex) {
      case fkDispHdr:
        incName = "<ocf/automacr.h>";
        incFile[0] = '"';
        _splitpath(outName, 0, 0, incFile+1, outExt);
        strcat(incFile, outExt);
        strcat(incFile, "\"");
        break;
      case fkDispSrc:
        incName = incFile;
        break;
      case fkFullCpp:
        incName = 0;
        break;
    }
    if (log.GetWindow()) {
      ::SetDlgItemText(log.GetWindow(), IDC_STATUS,  (char far*)outName);
      int* selectList = log.GetSelectList();
      int  selectCount= log.GetSelectCount();
      if (!selectList) {
        ::SendDlgItemMessage(log.GetWindow(), IDC_INFOLIST, LB_SETSEL, 1, -1);
      } else if (outCount != 0) {
        for (int i = 0; i < selectCount; i++)
          ::SendDlgItemMessage(log.GetWindow(), IDC_INFOLIST, LB_SETSEL, 1,
                               (LPARAM)(unsigned)selectList[i]);
      }
    }
    ReadTypeLib(libName, incName, libMode[fileIndex], out, log);
    outCount++;
  }
  return 0;
}

#define WM_USERSTAT (WM_USER + 100)

bool CALLBACK __export
HelpProc(HWND hDlg, UINT msg, WPARAM /*wParam*/, LPARAM /*lParam*/)
{
  if (msg != WM_COMMAND)
    return (msg == WM_INITDIALOG);
  ::EndDialog(hDlg, TRUE);
  return true;
}

bool CALLBACK __export
SelectProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM /*lParam*/)
{
  if (msg == WM_INITDIALOG) {
    int tabs = IDC_INFOLIST_TAB;
    ::SendDlgItemMessage(hDlg, IDC_INFOLIST, LB_SETTABSTOPS, 1, (LPARAM)&tabs);
    ::SendDlgItemMessage(hDlg, IDC_AUTOCODE, BM_SETCHECK, 1, 0);
    return 1;
  } else if (msg == WM_COMMAND) {
    switch (wParam) {
      case IDOK:
      case IDCANCEL:    
        ::PostMessage(hDlg, WM_USERSTAT, wParam, 0);
        return 1;
      case IDC_SELECTALL:
      case IDC_SELECTNONE:
        ::SendDlgItemMessage(hDlg, IDC_INFOLIST, LB_SETSEL,
                             wParam==IDC_SELECTALL, -1);
        return 1;
    }
  } else if (msg == WM_CLOSE) {
    ::PostMessage(hDlg, WM_USERSTAT, IDABORT, 0);
  }
  return 0;
}

bool FillListBox(TLogTypeInfo& info)
{
  char buf[100];
  wsprintf(buf, "%s\t%s", (char far*)info.TypeKind, info.TypeName);
  ::SendDlgItemMessage(info.GetWindow(), IDC_INFOLIST, LB_ADDSTRING,
                       0, (LPARAM)(char far*)buf);
  MSG msg;
  while (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
    ::IsDialogMessage(info.GetWindow(), &msg);
  return true;
}

bool ShowProgress(TLogTypeInfo& info)
{
  HWND hWnd = info.GetWindow();
  ::SendDlgItemMessage(hWnd, IDC_INFOLIST, LB_SETTOPINDEX, info.Index, 0);
  ::SendDlgItemMessage(hWnd, IDC_INFOLIST, LB_SETSEL,
                       0, (LPARAM)(unsigned)info.Index);
  MSG msg;
  while (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
    ::IsDialogMessage(hWnd, &msg);
  return true;
}

bool SilentYield(TLogTypeInfo& /*info*/)
{
  MSG msg;
  while (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
    ;
//  if (msg.message == WM_QUIT)
//    return false;
  return true;
}

const int MaxReqTypes = 20;  // maximum number of type names on command line

int PASCAL
WinMain(HINSTANCE hInst, HINSTANCE/*hPrev*/, char far* cmdLine, int/*show*/)
{
  TCmdLine cmd(cmdLine);
  char* outFiles[fkCount];
  int stat = 0;

  try {
    if (cmd.NextToken() == TCmdLine::Null) {
      //
      // If command line empty, create dialog and operate in interactive mode
      //
      char libName[_MAX_PATH];
      libName[0] = 0;
      HWND hWnd = ::CreateDialogParam(hInst, MAKEINTRESOURCE(IDD_SELECT), 0,
                                      (DLGPROC)SelectProc, 0);
      OPENFILENAME ofn = {sizeof(OPENFILENAME), hWnd, hInst,
                          "TypeLib\0*.TLB;*.OLB\0",0,0,0,
                          libName, sizeof(libName), 0, 0,
                          0, "AUTOGEN - TypeLib to C++ Conversion",
                          OFN_HIDEREADONLY | OFN_FILEMUSTEXIST,
                          0,0,0,0,0,0 };
      while(::GetOpenFileName(&ofn)) {
        ::SetDlgItemText(hWnd, IDC_LIBFILE, (char far*)libName);
        ::ShowWindow(hWnd, SW_SHOW);
        TLogTypeInfo fillInfo(hWnd);
        fillInfo.SetCallback(FillListBox);
        strstream temp;
        ReadTypeLib(libName, 0, tfScanOnly | tfAllKinds, temp, fillInfo);
        MSG msg;
        int stat = 0;
        while ( !stat && ::GetMessage(&msg, 0, 0, 0)) {
          if (msg.message == WM_USERSTAT)
            stat = msg.wParam;
          else 
            ::IsDialogMessage(hWnd, &msg);
        }
        if (stat == IDABORT)
          break;
        if (stat == IDOK) {
          ::ShowWindow(::GetDlgItem(hWnd, IDC_SELECTALL),  SW_HIDE);
          ::ShowWindow(::GetDlgItem(hWnd, IDC_SELECTNONE), SW_HIDE);
          ::ShowWindow(::GetDlgItem(hWnd, IDC_STATUS),     SW_SHOW);
          int cppdefState = (int)::SendDlgItemMessage(hWnd, IDC_CPPDEF,
                                                     BM_GETCHECK, 0, 0);
          memcpy(outFiles, cppdefState ? cppFile : stdFile, sizeof(outFiles));
          fillInfo.SetCallback(ShowProgress);
          int* selectList = 0;
          int selectCount = (int)::SendDlgItemMessage(hWnd, IDC_INFOLIST,
                                                     LB_GETSELCOUNT, 0, 0);
          if (selectCount) {
            selectList = new int[selectCount];
            ::SendDlgItemMessage(hWnd, IDC_INFOLIST, LB_GETSELITEMS,
                                 selectCount, (LPARAM)(int far*)selectList);
          }
          fillInfo.SetSelectList(selectCount, selectList);
          stat = GenerateFiles(libName, outFiles, fillInfo);
          while (!::GetFocus() ||
                  ::GetWindowTask(::GetFocus())!=::GetCurrentTask())
            if (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
              ::IsDialogMessage(hWnd, &msg);
          ::ShowWindow(::GetDlgItem(hWnd, IDC_SELECTALL),  SW_SHOW);
          ::ShowWindow(::GetDlgItem(hWnd, IDC_SELECTNONE), SW_SHOW);
          ::ShowWindow(::GetDlgItem(hWnd, IDC_STATUS),     SW_HIDE);
        }
        ::ShowWindow(hWnd, SW_HIDE);
        ::SendDlgItemMessage(hWnd, IDC_INFOLIST, LB_RESETCONTENT, 0, 0);
      }
      ::DestroyWindow(hWnd);
      return stat;
    }
    if (cmd.Type == TCmdLine::Name) {
      //
      //  If type library supplied on command line, operate in non-interactive
      //
      char* libName = cmd.Token;   // first argument should be a typelib name
      int optFound = 0;
      memset(outFiles, 0, sizeof(outFiles));
      char* reqTypes[MaxReqTypes];
      int   reqInfos[MaxReqTypes];
      int   reqCount = 0;
      int   optIndex = -1;
      while (cmd.NextToken() != TCmdLine::Null) {
        if (cmd.Type == TCmdLine::Option) {
          for (optIndex = 0; optIndex < fkCount; optIndex++) {
            if (strnicmp(cmd.Token, optText[optIndex], cmd.TokenLen) == 0)
              break;
          }
          ErrorIf(optIndex == fkCount, IDS_UNKNOWNOPT, cmd.Token);
          outFiles[optIndex] = "";
          optFound++;
        } else if (cmd.Type == TCmdLine::Value) {
          ErrorIf(optIndex == -1, IDS_MISSINGOPT, cmd.Token);
          outFiles[optIndex] = cmd.Token;
          optIndex = -1;
        } else {  // TCmdLine::Name  should be a class name to select
          ErrorIf(reqCount == MaxReqTypes, cmd.Token, IDS_TOOMANYTYPES);
          reqTypes[reqCount++] = cmd.Token;
        }
      }
      if (optFound == 0)  // if no file options, default to controller files
        memcpy(outFiles, stdFile, sizeof(outFiles));
      TLogTypeInfo silentInfo(0);
      if (reqCount) {
        silentInfo.SetRequestList(reqCount, reqInfos, reqTypes);
        strstream temp;
        ReadTypeLib(libName, 0, tfScanOnly | tfAllKinds, temp, silentInfo);
        char* badName = silentInfo.ExtractRequest();
        ErrorIf(badName!=0, IDS_BADTYPENAME, badName);
      }
      silentInfo.SetCallback(SilentYield);
      stat = GenerateFiles(libName, outFiles, silentInfo);
    } else {
      //
      //  If first command line arg is an option flag, show help dialog
      //
      stat = ::DialogBox(hInst, MAKEINTRESOURCE(IDD_HELP), 0,(DLGPROC)HelpProc);
    }
    return stat;
  }
  catch (TLocalError& xcpt) {
    char msgbuf[80];
    const char ** pmsg;
    if ( *(pmsg = &xcpt.Message) <= (const char*)IDS_MAX ||
         *(pmsg = &xcpt.Title)   <= (const char*)IDS_MAX) {
      ::LoadString(hInst, *(unsigned*)pmsg, msgbuf, sizeof(msgbuf));
      *pmsg = msgbuf;
    }
    ::MessageBox(0, xcpt.Message, xcpt.Title, MB_OK);
    return 1;
  }
  catch (xmsg& xcpt) {    // should not occur, but check anyway while catching
    ::MessageBox(0, xcpt.why().c_str(), "Exception", MB_OK);
    return 2;
  }
}
