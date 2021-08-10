//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   OLE Automation Class Definitions
//----------------------------------------------------------------------------
#if !defined(OCF_AUTODEFS_H)
#define OCF_AUTODEFS_H

#if !defined(OCF_OCDEFS_H)
#  include <ocf/ocdefs.h>
#endif
#if !defined(OSL_LOCALE_H)
# include <osl/locale.h>   // TLocaleString and TRegItem/TRegList
#endif
#if !defined(OSL_USTRING_H)
# include <osl/ustring.h>  // TString and TUString
#endif
#if !defined(__TYPEINFO_H)
# include <typeinfo.h>
#endif

// class modifier for inherited classes or members within user C++ classes
// if ambient class model is not used, this macro must be defined to match
//
#if !defined(_AUTOCLASS)
# define  _AUTOCLASS
#endif

// forward class references
//
class _AUTOCLASS TAutoDetach;
class _AUTOCLASS TAutoBase;
class _ICLASS TAppDescriptor;  // defined in appdesc.h
class _ICLASS TServedObject;
class _ICLASS TAutoIterator;
class TAutoCreator;
class TAutoCommand;
class TAutoSymbol;
class TAutoString;
class TAutoStack;
class far TAutoVal;
class TXAuto;
class TAutoEnum;

const void far* DynamicCast(const void far* obj, const typeinfo& src,
                                                 const typeinfo& dst);
const void far* MostDerived(const void far* obj, const typeinfo& src);

// global function to invalidate external references, class model-independent
//
void SendObituary(const void far* obj, const typeinfo& typeInfo);

//____________________________________________________________________________
//
// Automation typedefs
//____________________________________________________________________________

typedef unsigned long TLocaleId;   // locale ID - same as NT LCID

class _AUTOCLASS TAutoBase {   // default base for automatable objects
  public:
    virtual ~TAutoBase();// only member is virtual destructor for unregistration
};

class _AUTOCLASS TAutoDetach { // default base for detach notification objects
  protected:
    void Notify(int offset, const typeinfo& typeInfo);  // sends obituary
};          // the size of this object must be 0 to not affect enclosing class

typedef void* ObjectPtr;  // generic opaque object pointer

// Generic conversion function for changing between inherited classes

template <class T, class B> struct TTypeConvert {
  static ObjectPtr Cast(ObjectPtr from) { return
   reinterpret_cast<ObjectPtr>( dynamic_cast<T*>(reinterpret_cast<B*>(from)));
  }
};

typedef ObjectPtr      (*TAutoSymTypeConvert) (ObjectPtr obj);
typedef TAutoCommand*  (*TAutoCommandBuild)(ObjectPtr obj,int attr,TAutoStack&);
typedef TAutoCommand*  (*TAutoCommandBuildDtr)(ObjectPtr obj, int attr);
typedef TAutoIterator* (*TAutoIteratorBuild)(ObjectPtr obj,
                                             TAutoCreator& creator,
                                             IUnknown* owner, TLangId lang);
typedef IUnknown&      (*TAggregator)(ObjectPtr obj, TUnknown& inner);

extern "C" const GUID __cdecl IID_TServedObject;

//____________________________________________________________________________
//
// TXAuto - automation exception object
//____________________________________________________________________________

class TXAuto : public TXBase {
  public:
    enum TError {
      xNoError,
      xConversionFailure,
      xNotIDispatch,
      xForeignIDispatch,
      xTypeMismatch,
      xNoArgSymbol,
      xParameterMissing,
      xNoDefaultValue,
      xValidateFailure,
      xExecutionFailure,
      xErrorStatus,
    };
    TXAuto(TXAuto::TError err)
        : TXBase("Automation Exception"), ErrorCode(err) {}
    TError ErrorCode;
};

//____________________________________________________________________________
//
// TAutoType, TAutoClass - automation type/class descriptor
//____________________________________________________________________________

struct TAutoType {
    uint16 GetType() const {return Type;}
    uint16 Type;
};

class TAutoClass : public TAutoType {
  public:
    TAutoClass(TAutoSymbol* table, TAutoSymbol* classSymbol,
               const typeinfo& typeInfo, TAggregator aggregator=0);
   ~TAutoClass();

    short         CountCommands();    // forces counts to be set on first call
    TAutoSymbol*  Lookup(char far* name, TLangId lang, short symFlags, long far& id);
    TAutoSymbol*  LookupArg(char far* name, TLangId lang, TAutoSymbol* cmd,
                            long far& retid);
    TAutoSymbol*  FindId(short id, ObjectPtr& objptr);
    TAutoSymbol*  FindFunction(unsigned index, int& retId);
    TAutoSymbol*  FindVariable(unsigned index, int& retId);
    TXAuto::TError Dispatch(ObjectPtr obj, TAutoCreator& creator,
                            TUnknown& owner, int attr, TAutoStack& args,
                            TAutoVal far* retval);
    TAutoSymbol*  GetTable();
    TAutoSymbol*  GetClassSymbol();
    short         GetArgCount(TAutoSymbol& sym);
    TAutoCommandBuildDtr GetDestructor();
    const typeinfo&  GetTypeInfo();
    const char* GetName(TLangId lang = TLocaleString::UserDefaultLangId);
    const char* GetDoc (TLangId lang = TLocaleString::UserDefaultLangId);
    unsigned long GetHelpId();
    unsigned short GetTypeFlags();
    int            GetImplTypeFlags();
    unsigned short GetCoClassFlags();
    TAggregator GetAggregator();
    IUnknown&   Aggregate(ObjectPtr obj, TUnknown& inner);

  protected:
    TAggregator Aggregator;  // aggregator function for C++ COM classes
    short CommandCount;      // command count including bases, 0 if uncounted
    short FunctionCount;     // number of symbols exposed as typelib functions
    short VariableCount;     // number of symbols exposed as typelib variables
    TAutoSymbol* Table;      // pointer to array of symbol entries
    TAutoSymbol* ClassSymbol;// pointer to class symbol (terminator)
    const typeinfo& TypeInfo;// for validating type of data pointers
    friend class TServedObject;

  private:
    struct TAutoClassRef {   // element used for array of TAutoClass objects
      TAutoClass* Class;
      int         GuidOffset;
    };
    struct TExtLink;      // fwd declaration
    static struct TClassList { // module-static TAutoClass data
      int  CountAutoClasses();  // walks list in attatched DLLs
      TAutoClassRef* MergeAutoClasses(TAutoClassRef* array);
      TAutoClass* List;   // chain of autoclasses in THIS module
      int         Count;  // count of classes in THIS module
      TExtLink*   Link;   // chain of TAutoClass data for loaded DLLs
    } ClassList;
    struct TExtLink {      // doubly-linked list of external DLL data
      TExtLink(TClassList* list, HINSTANCE module);
     ~TExtLink();
      TClassList* Classes;
      HINSTANCE   Module; // module handle if dynmaically loaded, else 0
      TExtLink*   Next;
      TExtLink**  Prev;
    };
    TAutoClass*   NextClass;          // link to next class
    friend class TExtLink;            // access to ClassList
    friend class TClassList;          // access to TAutoClassRef
    friend class _ICLASS TTypeLibrary;// access to TAutoClassRef
    friend class _ICLASS TCoClassInfo;// access to TAutoClassRef
    friend class TAppDescriptor;      // access to linkage information
};

//____________________________________________________________________________
//
// TAuto(type) automation datatype encapsulations
//____________________________________________________________________________

struct TAutoVoid {  // purpose to implement assignent of void to TAutoVal
  static TAutoType ClassInfo;
};

struct TAutoDate {  // purpose to disambiguate type from double
  TAutoDate() : Date(0) {}
  TAutoDate(double d) : Date(d) {}
  operator double() { return Date; }
  double Date;      // same as OLE DATE
  static TAutoType ClassInfo;
};

struct TAutoCurrency : public CY {
  static TAutoType ClassInfo;
};

struct TAutoBool {  // for suppressing compiler warnings until bool is a type
  TAutoBool() : B(0) {}
  TAutoBool(bool b) : B(b) {}
  TAutoBool(TBool b) : B(static_cast<bool>(b)) {}
  operator bool() {return B;}
  operator TBool() {return static_cast<TBool>(B);}
  void operator =(bool b) {B = b;}
  void operator =(TBool b) {B = static_cast<bool>(b);}
  bool B;
  static TAutoType ClassInfo;
};

struct TAutoBoolRef {  // needed for automating bool far* until bool is a type
  TAutoBoolRef() : P(0) {}
  TAutoBoolRef(bool far* p) : P(p) {}
  TAutoBoolRef(TBool far* p) : P((bool far*)p) {}
  operator bool far*() {return P;}
  void operator =(bool far* p) {P = p;}
  void operator =(TBool far* p){P = (bool far*)p;}
  bool far* P;
  static TAutoType ClassInfo;
};

// the following types do no hold data, but only provide static type codes

struct TAutoShort      { static TAutoType ClassInfo; };
struct TAutoDouble     { static TAutoType ClassInfo; };
struct TAutoFloat      { static TAutoType ClassInfo; };
struct TAutoLong       { static TAutoType ClassInfo; };
struct TAutoByte       { static TAutoType ClassInfo; };
struct TAutoUnknown    { static TAutoType ClassInfo; };  // for raw IUnknown*
struct TAutoDispatch   { static TAutoType ClassInfo; };  // for raw IDispatch*
struct TAutoShortRef   { static TAutoType ClassInfo; };
struct TAutoLongRef    { static TAutoType ClassInfo; };
struct TAutoFloatRef   { static TAutoType ClassInfo; };
struct TAutoDoubleRef  { static TAutoType ClassInfo; };
struct TAutoCurrencyRef{ static TAutoType ClassInfo; };
struct TAutoDateRef    { static TAutoType ClassInfo; };
struct TAutoStringRef  { static TAutoType ClassInfo; };
struct TAutoVariantRef { static TAutoType ClassInfo; };
struct TAutoByteRef    { static TAutoType ClassInfo; };
#if (MAXINT==MAXSHORT)
typedef TAutoShort    TAutoInt;
typedef TAutoShortRef TAutoIntRef;
#else
typedef TAutoLong    TAutoInt;
typedef TAutoLongRef TAutoIntRef;
#endif

//____________________________________________________________________________
//
// Attribute flags for automation symbols and command objects
//____________________________________________________________________________

enum AutoSymFlag {
  asAnyCommand     = 0x0017,  // any command: method, property get/set, build
   asOleType       = 0x0007,  // method or property exposed for OLE
    asMethod       = 0x0001,  // method     (same as OLE INVOKE_FUNC)
    asGet          = 0x0002,  // returns property value (INVOKE_PROPERTYGET)
     asIterator    = 0x000A,  // iterator property (_NewEnum)
    asSet          = 0x0004,  // set property value     (INVOKE_PROPERTYSET)
    asGetSet       = 0x0006,  // can get or set property(...GET + ...SET)
   asBuild         = 0x0010,  // contructor command (unsupported by OLE 2.01)
  asFactory        = 0x0020,  // for creating objects or class determination
  asClass          = 0x0040,  // extension to another class symbol table
  asArgument       = 0x0080,  // property returning an object
  asNotTerminator  = 0x00FF,  // any symbol except terminator with class info

  asBindable       = 0x0400,  // sends OnChanged notification
  asRequestEdit    = 0x0800,  // sends OnRequest edit before change
  asDisplayBind    = 0x1000,  // user-display of bindable
  asDefaultBind    = 0x2000,  // this property only is the default (redundant)
  asHidden         = 0x4000,  // not visible to normal browsing
  asPersistent     = 0x8000,  // property is persistent
};

// Automation datatypes and flags - same as OLE 2 definitions

enum AutoDataType {
  atVoid              = 0x0000,   //  void
  atNull              = 0x0001,   //  SQL style Null
  atShort             = 0x0002,   //  2 byte signed int
  atLong              = 0x0003,   //  4 byte signed int
  atFloat             = 0x0004,   //  4 byte real
  atDouble            = 0x0005,   //  8 byte real
  atCurrency          = 0x0006,   //  currency
  atDatetime          = 0x0007,   //  datetime as double
  atString            = 0x0008,   //  BSTR, string preceeded by length
  atObject            = 0x0009,   //  IDispatch*
  atError             = 0x000A,   //  SCODE
  atBool              = 0x000B,   //  True=-1, False=0
  atVariant           = 0x000C,   //  VARIANT FAR*
  atUnknown           = 0x000D,   //  IUnknown*
  atByte              = 0x0011,	 //  byte, unsigned char
  atObjectDesc        = 0x001D,   //  object precursor state (internal use only)
  atLoanedBSTR        = 0x001A,   //  BSTR owned by TUString (internal use only)
  atTypeMask          = 0x001F,   //  base type code without bit flags
  atOLE2Mask          = 0x601F,   //  type code with bit flags
};
const uint16 atSafeArray = 0x2000;
const uint16 atByRef     = 0x4000;
const uint16 atEnum      = 0x1000;   // non-OLE, enumeration for data of a type
const uint16 atAutoClass = 0x0800;   // non-OLE, class object is a TAutoClass

//____________________________________________________________________________
//
// Automated class typeinfo flags - corresponding to OLE 2.02 definitions
//    flags set in END_AUTOCLASS, END_AUTOAGGREGATE, END_AUTOEVENTCLASS macros
//____________________________________________________________________________

// Flags set on any autoclass, but apply only to enclosing coclass typeinfo.
// Autoclasses with any of these bits set will be members of generated coclass.
// These flags from all autoclasses are combined to form the coclass type flags

const uint16 tfAppObject     =   1; // TYPEFLAG_FAPPOBJECT, set on COCLASS
const uint16 tfCanCreate     =   2; // TYPEFLAG_FCANCREATE, set on COCLASS
const uint16 tfLicensed      =   4; // TYPEFLAG_FLICENSED,  set on COCLASS
const uint16 tfPredeclared   =   8; // TYPEFLAG_FPREDECLID, set on COCLASS
const uint16 tfControl       =  32; // TYPEFLAG_FCONTROL,   set on COCLASS
const uint16 tfCoClassXfer   =  tfAppObject|tfCanCreate|tfLicensed|tfControl|tfPredeclared;

// Flags set on any autoclass, but used when class is a member of a coclass.
// Autoclasses with any of these bits set will be members of generated coclass.
// Flags from each class are set on the corresponding interfaces in the coclass

const uint16 tfDefault      = (1<<12); // IMPLTYPEFLAG_FDEFAULT << 12
const uint16 tfEventSource  = (2<<12); // IMPLTYPEFLAG_FSOURCE << 12
const uint16 tfRestricted   = (4<<12); // IMPLTYPEFLAG_FRESTRICTED << 12
const uint16 tfImplFlagXfer = (tfDefault | tfEventSource | tfRestricted);

// Flags set on individual autoclasses, transferred to corresponding typeinfos

const uint16 tfHidden        =  16;  // TYPEFLAG_FHIDDEN
const uint16 tfNonextensible = 128;  // TYPEFLAG_FNONEXTENSIBLE
const uint16 tfAutoClassMask =  tfHidden|tfNonextensible;

// Flags defined by OLE, but not applicable to dispatch interfaces

const uint16 tfDual          =  64;  // TYPEFLAG_FDUAL
const uint16 tfAutomation    = 256;  // TYPEFLAG_FOLEAUTOMATION

// Default typeflags value for autoclass not exposed as part of the coclass

const uint16 tfNormal        =   0;  // automated classes not at app level

//____________________________________________________________________________
//
//  TAutoSymbol - symbol table element
//____________________________________________________________________________

struct TAutoSymbol {
  TLocaleString Name;         // name of symbol, initially untranslated
  TLocaleString Doc;          // documentation string, initially untranslated
  uint16 Attr;                // attributes: enum AutoSymFlag, as????
  union {
    short DispId;             // reserved dispatch ID, if not 0
    short SymCount;           // asClass only: symbol count, 0 = uncounted yet
    unsigned short TypeFlags; // class symbol only (terminator)
  };
  TAutoType* Type;             // pointer to class/type/enum descriptor
  union {
    TAutoCommandBuild  Build;  // asAnyCommand only: address of command builder
    TAutoIteratorBuild BuildIter;// asIterator only: address of iterator builder
    TAutoSymTypeConvert Convert; // asFactory/asClass: function to perform cast
    TAutoCommandBuildDtr BuildDtr;// terminator only: destructor command builder
    void far*      DefaultArg; // asArgument: default value, extends to 8 bytes
  };
  ulong HelpId;              // help context ID, not for asArgument

  // inline data member accessor functions
  void SetFlag(uint16 mask);
  void ClearFlag(uint16 mask);
  bool TestFlag(uint16 mask);
  uint16 GetFlags();
  bool IsEnum();
  bool IsByRef();
  bool IsArray();
  bool IsIterator();
  bool IsTerminator();
  uint16 GetDataType();
  TAutoClass*  GetClass();
  TAutoEnum*   GetEnum();

  // inline static functions solely to provide type-safety initializing symbols
  static TAutoCommandBuild InitTypeConvert(TAutoSymTypeConvert f);
  static TAutoCommandBuild InitAutoIterator(TAutoIteratorBuild f);
  static TAutoCommandBuild InitAutoDestructor(TAutoCommandBuildDtr f);
};

//____________________________________________________________________________
//
// TObjectDescriptor - precursor to TServedObject containing object info
//____________________________________________________________________________

struct TObjectDescBase {   // ONLY for use when storing in TAutoVal union
  const void* Object;      // pointer to C++ object
  TAutoClass* Class;       // class descriptor, contains typeinfo
  const void far* MostDerived()
                         {return ::MostDerived(Object, Class->GetTypeInfo());}
};  // cannot have a constructor and must limit to 8 bytes for TAutoVal union

struct TObjectDescriptor : public TObjectDescBase {
  enum TDestruct     { // behavior when an automation helper is freed
    Quiet = 0,         // automation object quietly goes away without notice
    Delete = 1,        // automation object deletes the C++ object serviced
    PostQuit = 2       // automation object posts a quit message to application
  };
  TDestruct Destruct;
  TObjectDescriptor(const void* obj, TAutoClass& classobj,
                    TObjectDescriptor::TDestruct destruct = Quiet)
                    { Object = obj; Class = &classobj; Destruct = destruct; }
  private:
    TObjectDescriptor() {}    // uninitialized struct
  friend class TAutoClass;    // restrict access to uninitialized constructor
  friend class TAutoIterator;
};

//____________________________________________________________________________
//
// TAutoVal - automation data element (same data as OLE/BASIC VARIANT)
//____________________________________________________________________________

// This class simply duplicates and adds access methods to the system VARIANT
// Data members or virtual functions cannot be added.
// We rely on the fact that we can cast a VARIANT safely to/from a TAutoVal.

class far TAutoVal {
  public:
    operator unsigned char();
    operator signed char();
    operator char();
    operator unsigned char far*();
    operator signed char far*();
    operator char far*();
    operator int();
    operator int far*();
    operator unsigned int();
    operator short();
    operator short far*();
    operator unsigned short();
    operator unsigned short far*();// Note:VARIANT can't distinguish from short*
    operator long();
    operator long far*();
    operator unsigned long();
    operator unsigned long far*();// Note:VARIANT can't distinguish from long*
    operator float();
    operator float far*();
    operator double();
    operator double far*();
    operator TBool();
    operator TBool far*();
    operator TAutoBool();
    operator TAutoBoolRef();   
    operator TAutoCurrency();
    operator TAutoCurrency far*();
    operator TAutoDate();
    operator TAutoDate far*();
    operator string();
    operator TUString*();
    operator IDispatch*();
    operator IUnknown*();
    operator IDispatch&();
    operator IUnknown&();

    void operator =(unsigned char      i);
    void operator =(signed char        i);
    void operator =(char               i);
    void operator =(unsigned char far* p);
    void operator =(signed char far*   p);
    void operator =(char far*          p);
    void operator =(int                i);
    void operator =(int far*           p);
    void operator =(unsigned int       i);
    void operator =(unsigned int far*  p);
    void operator =(unsigned short     i);
    void operator =(unsigned short far*p);
    void operator =(long               i);
    void operator =(long far*          p);
    void operator =(unsigned long      i);
    void operator =(unsigned long far* p);
    void operator =(short              i);
    void operator =(short far*         p);
    void operator =(float              i);
    void operator =(float far*         p);
    void operator =(double             i);
    void operator =(double far*        p);
    void operator =(TBool              i);
    void operator =(TBool far*         p);
    void operator =(TAutoBool          i);
    void operator =(TAutoBoolRef       p);
    void operator =(const string&      s);
    void operator =(TAutoString        s);
    void operator =(TAutoCurrency      i);
    void operator =(TAutoCurrency far* p);
    void operator =(TAutoDate          i);
    void operator =(TAutoDate far*     i);
    void operator =(IDispatch*       ifc);
    void operator =(IUnknown*        ifc);
    void operator =(TObjectDescriptor od);
    void operator =(TAutoVoid);

    int GetDataType();
    void Clear();      // free any references, set type to atVoid
    void Restore();    // convert any non-OLE changes back to original types
    void Copy(const TAutoVal& copy);
    bool IsRef();
    TAutoVal far* DereferenceVariant();
    void SetLocale(TLocaleId);  // associate locale with appropriate pointers
    TLocaleId GetLocale() const;// retrieve locale from appropriate pointers
    TLangId   GetLanguage() const; // retrieve language from pointer types
    TString   StrVal();   // returns internal string pointer if atString
    bool GetObjDesc(TObjectDescriptor&);// return temp object info, else false
    SAFEARRAY far* GetArray();   // return array pointer, null if not array
    void far* SetByRef(AutoDataType);  // set type, return pointer to data loc

  private:
    unsigned short vt;
    unsigned short Reserved1;
    unsigned short Reserved2;
    unsigned short Reserved3;
    union {
      unsigned char bVal;             // VT_UI1
      short         iVal;             // VT_I2
      long          lVal;             // VT_I4
      float         fltVal;           // VT_R4
      double        dblVal;           // VT_R8
      VARIANT_BOOL  boolVal;          // VT_BOOL
      SCODE         scode;            // VT_ERROR
      TAutoCurrency cyVal;            // VT_CY
      DATE          date;             // VT_DATE
      BSTR          bstrVal;          // VT_BSTR
      IUnknown*     punkVal;          // VT_UNKNOWN
      IDispatch*    pdispVal;         // VT_DISPATCH
      SAFEARRAY far* parray;          // VT_ARRAY|*

      unsigned char far* pbVal;       // VT_BYREF|VT_UI1
      short         far* piVal;       // VT_BYREF|VT_I2
      long          far* plVal;       // VT_BYREF|VT_I4
      float         far* pfltVal;     // VT_BYREF|VT_R4
      double        far* pdblVal;     // VT_BYREF|VT_R8
      VARIANT_BOOL  far* pbool;       // VT_BYREF|VT_BOOL
      SCODE         far* pscode;      // VT_BYREF|VT_ERROR
      TAutoCurrency far* pcyVal;      // VT_BYREF|VT_CY
      DATE          far* pdate;       // VT_BYREF|VT_DATE
      BSTR          far* pbstrVal;    // VT_BYREF|VT_BSTR
      IUnknown*     far* ppunkVal;    // VT_BYREF|VT_UNKNOWN
      IDispatch*    far* ppdispVal;   // VT_BYREF|VT_DISPATCH
      SAFEARRAY far* far* pparray;    // VT_BYREF|VT_ARRAY|*
      VARIANT       far* pvarVal;     // VT_BYREF|VT_VARIANT
      void          far* byref;       // Generic ByRef

      struct {                       // added locale info for BSTR/IDispatch
        void far* Val;
        LCID      Locale;            // unused 4 bytes for pointer types
      } p;

      struct {                       // added info when loaned BSTR ownership
        BSTR      Val;
        TUString* Holder;            // string holder sharing current BSTR
      } s;

      TObjectDescBase ObjDesc;       // temporary space for returning object
    };
    void ConvRef(int type);
};

//____________________________________________________________________________
//
// TAutoString class - based on reference counted TString with added automation
//   functionality
//
class TAutoString : public TString {
  public:
    TAutoString(const char far* s = 0) : TString(s) {}
#if defined(BI_HAS_WCHAR)
    TAutoString(const wchar_t* s)      : TString(s) {}
#endif
    TAutoString(BSTR s, bool loan)     : TString(s) {}
    TAutoString(const string& s)       : TString(s) {}
    TAutoString(TUString* s)           : TString(s) {}
    TAutoString(TAutoVal& val)         : TString(val) {}
    TAutoString(const TAutoString& src) : TString(src.S) {++*S;}

    TAutoString& operator =(const char far* s) {S = S->Assign(s); return *this;}
    TAutoString& operator =(const TAutoString& s) {S = S->Assign(*s.S); return *this;}
    TAutoString& operator =(char* s)           {S = S->Assign(s); return *this;}
#if defined(BI_HAS_WCHAR)
    TAutoString& operator =(const wchar_t* s)  {S = S->Assign(s); return *this;}
    TAutoString& operator =(wchar_t* s)        {S = S->Assign(s); return *this;}
#endif
    TAutoString& operator =(TAutoVal& val)     {--*S; S = val; return *this;}

    static TAutoType ClassInfo;              // automation type code
};

//____________________________________________________________________________
//
// TAutoStack - automation argument stack abstraction
//____________________________________________________________________________

class TAutoStack {
  public:
    enum {SetValue = -3}; // special arg index for property set value
    TAutoStack(VARIANT far* stack, TLocaleId locale, int argcount,
               int namedcount, long far* map, TServedObject* owner);
   ~TAutoStack();
    TAutoVal& operator[](int index);
    TAutoSymbol* Symbol;      // symbol of method/prop, args follow
    int ArgSymbolCount;
    TLangId LangId;
    int CurrentArg;           // index of last arg requested by operator[]
    const int ArgCount;
    TServedObject* Owner;
    long ErrorCode;           // set if TXAuto::xErrorStatus returned
    const char* ErrorMsg;     // set if TXAuto::xErrorStatus returned
  protected:
    TAutoVal far* Stack;
    int NamedCount;
    long far* NamedIds;
    TAutoVal Default;
};

//____________________________________________________________________________
//
// Automation abstract base class for command objects
//____________________________________________________________________________

struct TAutoTransfer;              // persistence transfer parameter structure

class TAutoCommand {
  public:
    TAutoCommand(int attr);          // construtor called from derived classes
    virtual ~TAutoCommand() {}
    virtual TAutoCommand* Undo();             // generate command for undo stack
    virtual int           Record(TAutoStack& q); // record command and arguments
    virtual TAutoCommand& Invoke();           // invoke all command processing
    virtual bool          Validate();         // validate parameters
    virtual void          Execute();          // perform action on C++ object
    virtual long          Report();           // check result of execution
    virtual void          Return(TAutoVal& v);// convert return value to variant
    virtual void          Transfer(TAutoTransfer& x); // stream data in or out
            void          Fail(TXAuto::TError);// throw designated exception

    // Non-virtual hook functions
    typedef const char* (*TErrorMsgHook)(long errCode);
    static TErrorMsgHook SetErrorMsgHook(TErrorMsgHook callback);

    typedef bool (*TCommandHook)(TAutoCommand& cmdObj);
    static TCommandHook SetCommandHook(TCommandHook callback);

    // inline data member accessor functions
    static const char* LookupError(long errCode);
    void SetFlag(int mask);
    void ClearFlag(int mask);
    bool TestFlag(int mask);
    bool IsPropSet();
    TAutoSymbol* GetSymbol();
    void SetSymbol(TAutoSymbol* sym);

  protected:
    TAutoSymbol* Symbol;      // symbol entry generating this command
    int Attr;                 // attribute and state flags, asXXXXXX
};
    extern TAutoCommand::TErrorMsgHook TAutoCommand_ErrorLookup;
    extern TAutoCommand::TCommandHook  TAutoCommand_InvokeHook;

// Build function for application Quit command implementation
TAutoCommand* AutoQuitBuild(ObjectPtr obj, int attr, TAutoStack& args);

//____________________________________________________________________________
//
// TAutoEnum - automation enumeration descriptor
//____________________________________________________________________________

template <class T>
struct TAutoEnumVal {
  TLocaleString Name;         // name of symbol, enumeration text
  T Val;                      // enumeration internal value
};

class TAutoEnum : public TAutoType {
  public:
    virtual bool Convert(TAutoVal& txtVal, TAutoVal& numVal) = 0;
    virtual bool Convert(TAutoVal& numVal, TLangId langId) = 0;

  protected:
    TAutoEnum(int count, int type);
    int Count;              // length of this symbol table
};

template <class T>
class TAutoEnumT : public TAutoEnum {
  public:
    TAutoEnumT(TAutoEnumVal<T>* table, int symcount, int type);
    bool Convert(TAutoVal& txtVal, TAutoVal& numVal);
    bool Convert(TAutoVal& numVal, TLangId langId);

  protected:
    TAutoEnumVal<T>* Table; // pointer to array of symbol entries
};

//____________________________________________________________________________
//
// TAutoCreator - Object responsible for creating automation COM object
//____________________________________________________________________________

class TAutoCreator {
  public:
    TAutoCreator() {}
    virtual TUnknown*  CreateObject(TObjectDescriptor objDesc,
                                    IUnknown* outer = 0) = 0;
    virtual IDispatch* CreateDispatch(TObjectDescriptor objDesc,
                                      IUnknown* outer = 0) = 0;
    virtual void       Attach(TServedObject& obj) {}
    virtual void       Detach(TServedObject& obj) {}
};

class TServedObjectCreator : public TAutoCreator {
  public:
    TServedObjectCreator(TAppDescriptor& appDesc);
    TUnknown*  CreateObject(TObjectDescriptor objDesc, IUnknown* outer = 0);
    IDispatch* CreateDispatch(TObjectDescriptor objDesc, IUnknown* outer = 0);
    void       Attach(TServedObject& obj);
    void       Detach(TServedObject& obj);
//protected:
    TAppDescriptor& AppDesc;
    TServedObject* AppObject;
  private:
    int ObjCount;
  friend class TServedObject;
};

class _ICLASS TDispatch;

class TDispatchCreator : public TAutoCreator {
  public:
    TDispatchCreator() {}
    TUnknown*  CreateObject(TObjectDescriptor objDesc, IUnknown* outer = 0);
    IDispatch* CreateDispatch(TObjectDescriptor objDesc, IUnknown* outer = 0);
  protected:
};

//____________________________________________________________________________
//
// TServedObject - OLE object exposed for automated access of internal object
//____________________________________________________________________________

DECLARE_COMBASES2(TServedCOM, IDispatch, ITypeInfo)

class _ICLASS TServedObject : public TServedCOM {
    HRESULT QueryObject(const GUID far& iid, void far* far* pif);
  public:
    TServedObject(TObjectDescriptor& obj, TServedObjectCreator& creator,
                                          IUnknown* outer=0);
   ~TServedObject();
    TServedObject* GetAppObject() {return Creator.AppObject;}
    TServedObjectCreator& GetCreator() {return Creator;}
    void* Object;          // pointer to C++ object instance, 0 if deleted
    const void far* RootObject;  // pointer to object of most derived class
    TAutoClass*     Class;       // class of which object is an instance
    TServedObjectCreator& Creator;
    operator IDispatch*();
    TLangId ReqLang;             // language requested by caller
    TObjectDescriptor::TDestruct Destruct;  // what to do with C++ object
  private:
    TServedObject*        Next;
    TServedObject* far*   Prev;
    // need to access local LANGID for typeinfo, either as member or as global

    // IDispatch implementation
    HRESULT _IFUNC GetTypeInfoCount(unsigned int far* pctinfo);
    HRESULT _IFUNC GetTypeInfo(unsigned int itinfo, LCID lcid,
                               ITypeInfo* far* pptinfo);
    HRESULT _IFUNC GetIDsOfNames(const IID far& riid, OLECHAR far* far* rgszNames,
                                 uint cNames, LCID lcid,
                                 DISPID far* rgdispid);
    HRESULT _IFUNC Invoke(DISPID dispidMember, const IID far& riid, LCID lcid,
                                 unsigned short wFlags,
                                 DISPPARAMS far* pdispparams,
                                 VARIANT far* pvarResult,
                                 EXCEPINFO far* pexcepinfo,
                                 unsigned int far* puArgErr);

    // ITypeInfo implementation
    HRESULT _IFUNC GetTypeAttr(TYPEATTR far* far* pptypeattr);
    HRESULT _IFUNC GetTypeComp(ITypeComp* far* pptcomp);
    HRESULT _IFUNC GetFuncDesc(unsigned int index, FUNCDESC far* far* ppfuncdesc);
    HRESULT _IFUNC GetVarDesc(unsigned int index, VARDESC far* far* ppvardesc);
    HRESULT _IFUNC GetNames(MEMBERID memid, BSTR far* rgbstrNames,
                            unsigned int cMaxNames,
                            unsigned int far* pcNames);
    HRESULT _IFUNC GetRefTypeOfImplType(unsigned int index, HREFTYPE far* phreftype);
    HRESULT _IFUNC GetImplTypeFlags(unsigned int index, int far* pimpltypeflags);
    HRESULT _IFUNC GetIDsOfNames(OLECHAR far* far* rgszNames,
                                 unsigned int cNames,
                                 MEMBERID far* rgmemid);
    HRESULT _IFUNC Invoke(void far* pvInstance, MEMBERID memid,
                          unsigned short wFlags,
                          DISPPARAMS far *pdispparams,
                          VARIANT far *pvarResult,
                          EXCEPINFO far *pexcepinfo,
                          unsigned int far *puArgErr);
    HRESULT _IFUNC GetDocumentation(MEMBERID memid,
                                    BSTR far* pbstrName,
                                    BSTR far* pbstrDocString,
                                    ulong far* pdwHelpContext,
                                    BSTR far* pbstrHelpFile);
    HRESULT _IFUNC GetDllEntry(MEMBERID memid, INVOKEKIND invkind,
                               BSTR far* pbstrDllName,
                               BSTR far* pbstrName,
                               unsigned short far* pwOrdinal);
    HRESULT _IFUNC GetRefTypeInfo(HREFTYPE hreftype,
                                  ITypeInfo* far* pptinfo);
    HRESULT _IFUNC AddressOfMember(MEMBERID memid, INVOKEKIND invkind,
                                   void far* far* ppv);
    HRESULT _IFUNC CreateInstance(IUnknown* punkOuter, const IID far& riid,
                                  void far* far* ppvObj);
    HRESULT _IFUNC GetMops(MEMBERID memid, BSTR far* pbstrMops);
    HRESULT _IFUNC GetContainingTypeLib(ITypeLib* far* pptlib,
                                        uint far* pindex);
    void _IFUNC ReleaseTypeAttr(TYPEATTR far* ptypeattr);
    void _IFUNC ReleaseFuncDesc(FUNCDESC far* pfuncdesc);
    void _IFUNC ReleaseVarDesc(VARDESC far* pvardesc);
  friend class TAppDescriptor;   // access to Next,Prev
};

//____________________________________________________________________________
//
// TDispatch - lightweight IDispatch implementation for automation controllers
//____________________________________________________________________________

DECLARE_COMBASES1(TDispatchCOM, IDispatch)

class _ICLASS TDispatch : public TDispatchCOM {
  public:
    TDispatch(TObjectDescriptor& obj, IUnknown* outer = 0);
    void*        Object;      // pointer to C++ object instance, 0 if deleted
    TAutoClass*  Class;       // class of which object is an instance
    void InvalidateObject() {Object = 0;}
    operator IDispatch*();
  private:
    // IDispatch implementation
    HRESULT _IFUNC GetTypeInfoCount(unsigned int far* pctinfo);
    HRESULT _IFUNC GetTypeInfo(unsigned int itinfo, LCID lcid,
                               ITypeInfo* far* pptinfo);
    HRESULT _IFUNC GetIDsOfNames(const IID far& riid, OLECHAR far* far* rgszNames,
                                 unsigned int cNames, LCID lcid,
                                 DISPID far* rgdispid);
    HRESULT _IFUNC Invoke(DISPID dispidMember, const IID far& riid, LCID lcid,
                                 unsigned short wFlags,
                                 DISPPARAMS far* pdispparams,
                                 VARIANT far* pvarResult,
                                 EXCEPINFO far* pexcepinfo,
                                 unsigned int far* puArgErr);
};

//____________________________________________________________________________
//
// TAutoObject - holders for C++ object pointers for automation conversions
//____________________________________________________________________________

template<class T>
class TAutoObject {
  public:
    void operator=(IDispatch& dp);
    void operator=(T* p) {P=p;}
    void operator=(T& r) {P=&r;}
    T& operator*() {return *P;}
    operator TObjectDescriptor() {return TObjectDescriptor(P, T::ClassInfo);}
    TAutoObject() : P(0) {}
    TAutoObject(T* p) {P=p;}
    TAutoObject(T& r) {P=&r;}
    TAutoObject(IDispatch& dr);
    operator T*() {return P;}
    operator T&() {return *P;}
  protected:
    T* P;
    T F();// only purpose to remove const for typeid incase T is a const class
};

template<class T>
TAutoObject<T>::TAutoObject(IDispatch& ifc)
{
  TServedObject* obj;
  if (ifc.QueryInterface(IID_TServedObject, (void far* far*)&obj) != 0)
    throw TXAuto(TXAuto::xForeignIDispatch);
  P = (T*)DynamicCast(obj->Object, obj->Class->GetTypeInfo(), typeid(F()));
  if (!P)
    throw TXAuto(TXAuto::xTypeMismatch);
}

template<class T> void
TAutoObject<T>::operator=(IDispatch& ifc)
{
  TServedObject* obj;
  if (ifc.QueryInterface(IID_TServedObject, (void far* far*)&obj) != 0)
    throw TXAuto(TXAuto::xForeignIDispatch);
  P = (T*)DynamicCast(obj->Object, obj->Class->GetTypeInfo(), typeid(F()));
  if (!P)
    throw TXAuto(TXAuto::xTypeMismatch);
}

template<class T>      // for returning objects only, no IDispatch constructor
class TAutoObjectDelete : public TAutoObject<T>{
  public:
    void operator=(T* p) {P=p;}
    void operator=(T& r) {P=&r;}
    TAutoObjectDelete()     : TAutoObject<T>() {}
    TAutoObjectDelete(T* p) : TAutoObject<T>(p) {}
    TAutoObjectDelete(T& r) : TAutoObject<T>(r) {}
    operator TObjectDescriptor()
        {return TObjectDescriptor(P,T::ClassInfo, TObjectDescriptor::Delete);}
};

template<class T>      // for returning objects by value
class TAutoObjectByVal : public TAutoObjectDelete<T> {
  public:
    void operator=(T o) {P=new T(o);}
    TAutoObjectByVal() : TAutoObjectDelete<T>() {}
    TAutoObjectByVal(T o) : TAutoObjectDelete<T>(new T(o)) {}
};

//____________________________________________________________________________
//
// TAutoIterator - automation collection iterator
//____________________________________________________________________________


class TAutoIterator : public IEnumVARIANT {
  public:
    // IEnumVARIANT implementation
    HRESULT       _IFUNC QueryInterface(const GUID far& iid, void far*far* pif);
    unsigned long _IFUNC AddRef();
    unsigned long _IFUNC Release();
    HRESULT _IFUNC Next(unsigned long count, VARIANT far* retvals,
                        unsigned long far* retcount);
    HRESULT _IFUNC Skip(unsigned long count);
    HRESULT _IFUNC Reset();
    HRESULT _IFUNC Clone(IEnumVARIANT* far* retiter);

    // specific implementation required by derived classes
    virtual void           Init()=0;   // reset to first item
    virtual bool           Test()=0;   // test if item exists
    virtual void           Step()=0;   // advance to next item
    virtual void           Return(TAutoVal& v)=0;// convert item to variant
    virtual TAutoIterator* Copy()=0;   // return copy of iterator

    // inline data member accessor functions
    TAutoSymbol* GetSymbol();
    void SetSymbol(TAutoSymbol* sym);
    operator IUnknown*();     // essentially a quick QueryInterface

    virtual ~TAutoIterator();
    TAutoClass* Class;
  protected:
    TAutoSymbol* Symbol;      // symbol entry generating this command
    TAutoCreator& Creator;    // object to create returned automation objects
    IUnknown* Owner;          // Release() must be called on destruction
    unsigned RefCnt;
    TLangId Lang;
    TAutoIterator(TAutoCreator& creator, IUnknown* owner, TLangId lang); // called from derived
    TAutoIterator(TAutoIterator& copy);  // copy constructor for base class
  };

//____________________________________________________________________________
//
// TAutoProxy - client C access proxy, base class
//____________________________________________________________________________

enum AutoCallFlag {
  acMethod         = 0x0001,  // method call, same as OLE2
  acPropGet        = 0x0002,  // returns property value, same as OLE2
  acPropSet        = 0x0004,  // set property value, same as OLE2
  acVoidRet        = 0x8000,  // pass NULL for return variant, not OLE2 flag
};

class TAutoProxyArgs {
  public:
    TAutoProxyArgs(int cnt) : Count(cnt) {}
   ~TAutoProxyArgs();
    TAutoVal& operator[](int index);
    operator TAutoVal&()    {return *(TAutoVal*)(this+1);}
    operator VARIANT far*() {return (VARIANT far*)(this+1);}
    operator unsigned int() {return Count;}
  private:
    int Count;
};

template <int N>
struct TAutoArgs : public TAutoProxyArgs {
  TAutoVal Args[N+1];
  TAutoArgs() : TAutoProxyArgs(N) {}
};

class TAutoProxy {
  public:
   ~TAutoProxy();
    void Bind(IUnknown* obj);
    void Bind(IUnknown& obj);
    void Bind(const GUID& guid);
    void Bind(const char far* progid);
    void Bind(TAutoVal& val);
    void Bind(IDispatch* obj);
    void Bind(IDispatch& obj);
    void Unbind();
    void MustBeBound();
    bool IsBound()  {return ToBool(That != 0);}
    void SetLang(TLangId lang) {Lang = lang;}
    operator IDispatch*();
    operator IDispatch&();
    long      Lookup(const long id) {return id;}
    long      Lookup(const char far* name);
    void      Lookup(const char far* names, long* ids, unsigned count);
  protected:
    TAutoProxy(TLangId lang) : That(0), Lang(lang) {}
    TAutoVal& Invoke(uint16 attr, TAutoProxyArgs& args, long* ids, unsigned named=0);
    IDispatch* That;
    TLangId Lang;
};

struct TAutoDispId {
  TAutoDispId(TAutoProxy* prx, char* name) : Id(prx->Lookup(name)) {}
  TAutoDispId(TAutoProxy*, long id) : Id(id) {}
  long Id;
  operator long*()  {return &Id;}
  operator unsigned() {return 0;}
};

template <int N> struct TAutoDispIds {
  TAutoDispIds(TAutoProxy* prx, const char* names) {prx->Lookup(names, Ids);}
  long Ids[N+1];
  operator long*()  {return Ids;}
  operator unsigned() {return N;}
};

class TAutoEnumeratorBase {
  public:
    void Bind(TAutoVal& val);
    void Unbind()   { if (Iterator) Iterator->Release(); Iterator=0; Clear();}
    bool Step();
    void Clear()      { Current.Clear(); }
    bool IsValid()    { return Current.GetDataType() != atVoid; }
    void Object(TAutoProxy& prx) { prx.Bind(Current); }
    void operator =(const TAutoEnumeratorBase& copy);
   ~TAutoEnumeratorBase() { Unbind(); }
  protected:
    TAutoEnumeratorBase() : Iterator(0) {Current = TAutoVoid();}
    TAutoEnumeratorBase(const TAutoEnumeratorBase& copy);
    IEnumVARIANT* Iterator;
    TAutoVal Current;
};

template <class T>
class TAutoEnumerator : public TAutoEnumeratorBase {
  public:
    TAutoEnumerator() : TAutoEnumeratorBase() {}
    TAutoEnumerator(const TAutoEnumerator<T>& cpy) : TAutoEnumeratorBase(cpy) {}
    void Value(T& v);
    operator T();
};

//____________________________________________________________________________
//
// Inline implementations for automation controller
//____________________________________________________________________________

inline TAutoVal& TAutoProxyArgs::operator[](int index)
{
  return *((TAutoVal*)(this+1)+(index ? Count+1-index : 0));
}

inline TAutoProxy::operator IDispatch&()  // this function not used internally
{
  if (!That)   // test only needed if inline to prevent function call overhead
    MustBeBound();
  return *That;
}

inline TAutoProxy::operator IDispatch*()
{
  if (That)
    That->AddRef();
  return That;
}

inline void TAutoProxy::Unbind()
{
  if (That)
    That->Release();
  That = 0;
}

inline TAutoProxy::~TAutoProxy()
{
  Unbind();
}

inline void TAutoEnumerator<short>::Value(short& v) { v = Current; }
inline void TAutoEnumerator<long>::Value(long& v)   { v = Current; }
inline void TAutoEnumerator<bool>::Value(bool& v)   { v = Current; }
inline void TAutoEnumerator<TAutoString>::Value(TAutoString& v)
                                                    { v = Current; }

inline TAutoEnumerator<short>::operator short() { return (short)Current; }
inline TAutoEnumerator<long>::operator long()   { return (long)Current; }
inline TAutoEnumerator<bool>::operator bool()   { return (bool)Current; }
inline TAutoEnumerator<TAutoString>::operator TAutoString()
                                                { return (TAutoString)Current; }
//____________________________________________________________________________
//
// Inline implementations for automation server - part 1
//____________________________________________________________________________

// TAutoClass inlines

inline TAutoSymbol* TAutoClass::GetTable()       {return Table;}
inline TAutoSymbol* TAutoClass::GetClassSymbol() {return ClassSymbol;}
inline TAutoCommandBuildDtr TAutoClass::GetDestructor() {return ClassSymbol->BuildDtr;}
inline const typeinfo&  TAutoClass::GetTypeInfo()    {return TypeInfo;}
inline const char* TAutoClass::GetName(TLangId id) {return ClassSymbol->Name.Translate(id);}
inline const char* TAutoClass::GetDoc (TLangId id) {return ClassSymbol->Doc.Translate(id);}
inline unsigned long TAutoClass::GetHelpId() {return ClassSymbol->HelpId;}
inline unsigned short TAutoClass::GetTypeFlags()
                            {return ClassSymbol->TypeFlags & tfAutoClassMask;}
inline int TAutoClass::GetImplTypeFlags() {return ClassSymbol->TypeFlags>>12;}
inline unsigned short TAutoClass::GetCoClassFlags()
                            {return ClassSymbol->TypeFlags & tfCoClassXfer;}
inline TAggregator TAutoClass::GetAggregator() {return Aggregator;}
inline IUnknown& TAutoClass::Aggregate(ObjectPtr obj, TUnknown& inner)
        {return obj && Aggregator ? Aggregator(obj, inner) : (IUnknown&)inner;}
//____________________________________________________________________________

// TAutoSymbol inlines

inline void TAutoSymbol::SetFlag(uint16 mask) {Attr |= mask;}
inline void TAutoSymbol::ClearFlag(uint16 mask) {Attr &= uint16(~mask);}
inline bool TAutoSymbol::TestFlag(uint16 mask) {return (Attr&mask)? true:false;}
inline uint16 TAutoSymbol::GetFlags() {return (uint16)Attr;}
inline bool TAutoSymbol::IsEnum() {return (Type->GetType() & atEnum)? true:false;}
inline bool TAutoSymbol::IsByRef() {return (Type->GetType() & atByRef)? true:false;}
inline bool TAutoSymbol::IsArray() {return (Type->GetType() & atSafeArray)? true:false;}
inline bool TAutoSymbol::IsIterator() {return ToBool((Attr&asIterator)==asIterator);}
inline bool TAutoSymbol::IsTerminator() {return ToBool((Attr & asNotTerminator)== 0);}
inline uint16 TAutoSymbol::GetDataType() {return uint16(Type->GetType() & atTypeMask);}
inline TAutoClass* TAutoSymbol::GetClass(){return (Type->GetType()&atAutoClass)?
                                                      (TAutoClass*)Type : 0; }
inline TAutoEnum* TAutoSymbol::GetEnum() {return (Type->GetType()&atEnum) ?
                                                      (TAutoEnum*)Type : 0; }
inline TAutoCommandBuild TAutoSymbol::InitTypeConvert(TAutoSymTypeConvert f)
                                         { return (TAutoCommandBuild)f;}
inline TAutoCommandBuild TAutoSymbol::InitAutoIterator(TAutoIteratorBuild f)
                                         { return (TAutoCommandBuild)f;}
inline TAutoCommandBuild TAutoSymbol::InitAutoDestructor(TAutoCommandBuildDtr f)
                                         { return (TAutoCommandBuild)f;}
//____________________________________________________________________________

// TAutoVal inlines

inline TAutoVal::operator unsigned long(){return (unsigned long)operator long();}
#if (MAXINT==MAXSHORT)
inline TAutoVal::operator int()          {return operator short();}
inline TAutoVal::operator unsigned int() {return operator unsigned short();}
inline TAutoVal::operator int far*()     {return (int far*)operator short far*();}
#else
inline TAutoVal::operator int()          {return operator long(); }
inline TAutoVal::operator unsigned int() {return (unsigned long)(long)*this;}
inline TAutoVal::operator int far*()     {return (int far*)operator long far*();}
#endif

inline TAutoVal::operator TAutoBool()  {return TAutoBool(operator TBool());}
inline TAutoVal::operator TAutoBoolRef(){return TAutoBoolRef(operator TBool far*());}
inline TAutoVal::operator signed char(){return operator unsigned char();}
inline TAutoVal::operator char()       {return operator unsigned char();}
inline TAutoVal::operator char far*()  {return (char far*)operator unsigned char far*();}
inline TAutoVal::operator signed char far*(){return (signed char far*)operator unsigned char far*();}

inline void TAutoVal::operator =(IDispatch* ifc) {vt=atObject; pdispVal=ifc;}
inline void TAutoVal::operator =(IUnknown* ifc)  {vt=atUnknown; punkVal=ifc;}
inline void TAutoVal::operator =(unsigned char v){vt=atByte;   bVal  = v;}
inline void TAutoVal::operator =(signed char v)  {vt=atByte;   bVal  = v;}
inline void TAutoVal::operator =(char v)         {vt=atByte;   bVal  = v;}
inline void TAutoVal::operator =(short  v)       {vt=atShort;  iVal  = v;}
inline void TAutoVal::operator =(long   v)       {vt=atLong;   lVal  = v;}
inline void TAutoVal::operator =(float  v)       {vt=atFloat;  fltVal= v;}
inline void TAutoVal::operator =(double v)       {vt=atDouble; dblVal= v;}
inline void TAutoVal::operator =(TBool  v)   {vt=atBool; boolVal = short(v ? -1 : 0);}
inline void TAutoVal::operator =(TAutoBool v){vt=atBool; boolVal = short((bool)v ? -1 : 0);}
inline void TAutoVal::operator =(TAutoDate v)    {vt=atDatetime; date = v;}
inline void TAutoVal::operator =(TAutoCurrency v){vt=atCurrency; cyVal = v;}
inline void TAutoVal::operator =(TAutoVoid)      {vt=atVoid;}
inline void TAutoVal::operator =(unsigned char far* p){vt=atByte+atByRef; pbVal=p;}
inline void TAutoVal::operator =(signed char far* p){vt=atByte+atByRef; pbVal=(unsigned char far*) p;}
inline void TAutoVal::operator =(char far* p)       {vt=atByte+atByRef; pbVal=(unsigned char far*) p;}
inline void TAutoVal::operator =(short far* p) {vt=atShort+atByRef; piVal=p;}
inline void TAutoVal::operator =(long far* p)  {vt=atLong+atByRef;  plVal=p;}
inline void TAutoVal::operator =(TBool far* p) {vt=atBool+atByRef;  pbool=(VARIANT_BOOL far*)p;}
inline void TAutoVal::operator =(TAutoBoolRef p){vt=atBool+atByRef; pbool=(VARIANT_BOOL far*)(bool far*)p;}
inline void TAutoVal::operator =(float far* p) {vt=atFloat+atByRef; pfltVal=p;}
inline void TAutoVal::operator =(double far* p){vt=atDouble+atByRef;pdblVal=p;}
inline void TAutoVal::operator =(TAutoDate far* p){vt=atDatetime+atByRef;pdate=(double far*)p;}
inline void TAutoVal::operator =(TAutoCurrency far* p){vt=atCurrency+atByRef;pcyVal=p;}

inline void TAutoVal::operator =(unsigned short v){vt=atLong; lVal = (long)v;}
inline void TAutoVal::operator =(unsigned short far* p)
                                  {vt=atShort+atByRef; piVal = (short far*)p;}
inline void TAutoVal::operator =(unsigned long v) {vt=atLong; lVal = (long)v;}
inline void TAutoVal::operator =(unsigned long far* p)
                                    {vt=atLong+atByRef; plVal = (long far*)p;}
#if (MAXINT==MAXSHORT)
inline void TAutoVal::operator =(int v) {vt=atShort; iVal=v;}
inline void TAutoVal::operator =(int far* p) {vt=atShort+atByRef; piVal=(short far*)p;}
inline void TAutoVal::operator =(unsigned int v) {operator =((unsigned short)v);}
inline void TAutoVal::operator =(unsigned int far* p) {operator =((unsigned short far*)p);}
#else
inline void TAutoVal::operator =(int v) {vt=atLong; lVal=v;}
inline void TAutoVal::operator =(int far* p) {vt=atLong+atByRef; plVal = (long far*)p;}
inline void TAutoVal::operator =(unsigned int v) {operator =((unsigned long)v);}
inline void TAutoVal::operator =(unsigned int far* p) {operator =((unsigned long far*)p);}
#endif

inline void TAutoVal::operator =(TObjectDescriptor od)
  {vt=atObjectDesc; ObjDesc.Object=od.Object; ObjDesc.Class=od.Class;
   if (od.Destruct == TObjectDescriptor::Delete) vt |= atByRef;}

inline int TAutoVal::GetDataType() {return vt;}

inline void TAutoVal::Clear()
{
  if ((vt & ~atByRef) == atLoanedBSTR) {
    s.Holder->ReleaseBstr((vt & atByRef) ? *pbstrVal : bstrVal);
    vt = uint16(atString | (vt & atByRef));
  }
  ::VariantClear((VARIANT far*)this);
}

inline void TAutoVal::Restore()
{
  if ((vt & ~atByRef) == atLoanedBSTR) {
    s.Holder->RevokeBstr((vt & atByRef) ? *pbstrVal : bstrVal);
    vt = uint16(atString | (vt & atByRef));
  } else if (vt == uint16(atBool | atByRef) && *pbool != 0) {
    *pbool = -1;
  }
  // need to check if atObjectDesc? should never happen as it is temporary
}

inline void TAutoVal::Copy(const TAutoVal& copy)
{
  vt = copy.vt;
  p  = copy.p;
  if (vt == atUnknown || vt == atObject)
    punkVal->AddRef();
  if (vt == atString)
    bstrVal = ::SysAllocString(bstrVal);
}

inline bool TAutoVal::IsRef() {return ToBool(vt & atByRef);}

inline TAutoVal far* TAutoVal::DereferenceVariant()
               {return vt==atVariant+atByRef ? (TAutoVal far*)pvarVal : this;}

inline TString TAutoVal::StrVal() {return vt==atString ? bstrVal : 0;}

inline bool TAutoVal::GetObjDesc(TObjectDescriptor& od)
{
  if ((char)vt != atObjectDesc)
    return false;
  od.Object = ObjDesc.Object;
  od.Class = ObjDesc.Class;
  od.Destruct = IsRef() ? TObjectDescriptor::Delete : TObjectDescriptor::Quiet;
  return true;
}

inline SAFEARRAY far* TAutoVal::GetArray()
{
  if (vt == atSafeArray)
    return parray;
  if (vt == (atSafeArray|atByRef))
    return *pparray;
  return 0;
}

inline void far* TAutoVal::SetByRef(AutoDataType datatype)
{
  if (vt == atVariant)
    return this;
  vt = uint16(datatype);
  return &byref;
}

//____________________________________________________________________________

// TServedObject inlines

inline TServedObject::operator IDispatch*()
{
  AddRef();
  return (IDispatch*)this;  // essentially a quick QueryInterface on the obj
}

// TDispatch inlines

inline TDispatch::operator IDispatch*()
{
  AddRef();
  return (IDispatch*)this;  // essentially a quick QueryInterface on the obj
}

//____________________________________________________________________________

// TAutoCommand inlines

inline TAutoCommand::TAutoCommand(int attr) : Attr(attr), Symbol(0) {}
inline void TAutoCommand::SetFlag(int mask) {Attr |= mask;}
inline void TAutoCommand::ClearFlag(int mask) {Attr&=(~mask);}
inline bool TAutoCommand::TestFlag(int mask) {return ToBool((Attr&mask)==mask);}
inline bool TAutoCommand::IsPropSet() {return TestFlag(asSet);}
inline TAutoSymbol* TAutoCommand::GetSymbol() {return Symbol;}
inline void TAutoCommand::SetSymbol(TAutoSymbol* sym) {Symbol = sym;}
inline const char* TAutoCommand::LookupError(long errCode)
    {return TAutoCommand_ErrorLookup ? TAutoCommand_ErrorLookup(errCode) : 0;}
//____________________________________________________________________________

// TAutoEnum inlines and template function definitions

inline TAutoEnum::TAutoEnum(int count, int type)
                        : Count(count) { Type = short(type + atEnum); }

template <class T> inline
TAutoEnumT<T>::TAutoEnumT(TAutoEnumVal<T>* table, int symcount, int type)
: TAutoEnum(symcount, type), Table(table) {}

// incoming enumeration string localized lookup
//
template <class T> bool
TAutoEnumT<T>::Convert(TAutoVal& txtVal, TAutoVal& numVal)
{
  const char far* str = txtVal.StrVal();  // 0 if not string type
  if (str) {
    TLangId langId = txtVal.GetLanguage();
    for (int i = 0; i < Count; i++) {
      if (Table[i].Name.Compare(str, langId) == 0) {
        numVal = Table[i].Val;
        return true;
      }
    }
  }
  return false;
}

// outgoing enumeration translation to localized string
//
template <class T> bool
TAutoEnumT<T>::Convert(TAutoVal& numVal, TLangId langId)
{
  T val;
  val = numVal;  // perhaps we should put a try/catch here!!
  for (int i = 0; i < Count; i++) {
    if (Table[i].Val == val) {
      numVal = Table[i].Name.Translate(langId);
      numVal.SetLocale(langId);
      return true;
    }
  }
  return false;
}

// special case for outgoing string enumerations
//
#pragma warn -inl
inline bool
TAutoEnumT<const char*>::Convert(TAutoVal& numVal, TLangId langId)
{
  const char far* str = numVal.StrVal();  // 0 if not string type
  if (str)
    for (int i = 0; i < Count; i++) {
      if (lstrcmp(Table[i].Val, str) == 0) {
        numVal = Table[i].Name.Translate(langId);
        numVal.SetLocale(langId);
        return true;
      }
    }
  return false;
}
#pragma warn .inl

//____________________________________________________________________________

// TAutoIterator inlines

inline TAutoIterator::operator IUnknown*() {RefCnt++; return this;}
inline TAutoSymbol* TAutoIterator::GetSymbol() {return Symbol;}
inline void TAutoIterator::SetSymbol(TAutoSymbol* sym) {Symbol = sym;}

//____________________________________________________________________________
//
// Inline implementations for automation server - part 2
//   These are inline only for the purpose of allowing _AUTOCLASS
//   to be specified at compile time without rebuilding OCF library
//   This applies to classes: TAutoBase, TAutoCommand, TAutoDetach
//____________________________________________________________________________

inline TAutoBase::~TAutoBase()
{
  ::SendObituary(this, typeid(TAutoBase));
}

inline void TAutoDetach::Notify(int offset, const typeinfo& typeInfo)
{
  ::SendObituary((char*)this-offset, typeInfo);
}
//____________________________________________________________________________

// TAutoCommand implementation specified inline to avoid _AUTOCLASS link errors

inline void TAutoCommand::Fail(TXAuto::TError err) { throw TXAuto(err); }

inline bool TAutoCommand::Validate() { return true; }

inline TAutoCommand& TAutoCommand::Invoke()
{
  if (!TAutoCommand_InvokeHook || TAutoCommand_InvokeHook(*this))
    Execute();
  return *this;
}

inline void TAutoCommand::Execute()
{
}

inline long TAutoCommand::Report()
{
  return 0;
}

inline void TAutoCommand::Return(TAutoVal& v)
{
  v = TAutoVoid();
}

inline void TAutoCommand::Transfer(TAutoTransfer& x)
{
}

inline TAutoCommand* TAutoCommand::Undo() {return 0;}

inline int TAutoCommand::Record(TAutoStack&) {return 0;}

inline TAutoCommand::TErrorMsgHook
TAutoCommand::SetErrorMsgHook(TAutoCommand::TErrorMsgHook callback){
  TErrorMsgHook hook = TAutoCommand_ErrorLookup;
  TAutoCommand_ErrorLookup = callback;
  return hook;
}

inline TAutoCommand::TCommandHook
TAutoCommand::SetCommandHook(TAutoCommand::TCommandHook callback){
  TCommandHook hook = TAutoCommand_InvokeHook;
  TAutoCommand_InvokeHook = callback;
  return hook;
}

#endif  // OCF_AUTODEFS_H

