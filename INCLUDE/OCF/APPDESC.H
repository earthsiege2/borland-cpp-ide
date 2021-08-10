//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//   TAppDescriptor - OLE application descriptor definitions
//----------------------------------------------------------------------------
#if !defined(OCF_APPDESC_H)
#define OCF_APPDESC_H

#if !defined(OCF_AUTODEFS_H)
# include <ocf/autodefs.h>
#endif

//----------------------------------------------------------------------------
// TAppDescriptor - application registration and browsing facilities
//

class         TServedObjectCreator;
class _ICLASS TServedObject;
class _ICLASS TTypeLibrary;
class _ICLASS TCoClassInfo;
class _WSYSCLASS TRegLink;

typedef IUnknown*
(*TComponentFactory)(IUnknown* outer, uint32 options, uint32 id = 0);

class _ICLASS TAppDescriptor : public IClassFactory {
  public:
    TAppDescriptor(TRegList& regInfo, TComponentFactory callback,
                   string& cmdLine, HINSTANCE hInst = _hInstance,
                   const TRegLink* regLink = 0);
   ~TAppDescriptor();

    operator IUnknown*() {return this;}
    bool IsAutomated() const {return ClassCount > 0;}
    TComponentFactory GetFactory() const {return FactoryCallback;}
    const TRegLink* GetRegLinkHead() const {return LinkHead;}

    // Command line options accessors
    //
    bool IsOptionSet(uint32 option) const {return ToBool(Options&option);}
    uint32 GetOptions() const {return Options;}
    void SetOption(uint32 bit, bool state) {if (state) Options |= bit; else Options &= ~bit;}
    void ProcessCmdLine(string& cmdLine);
    void SetLangId(TLangId prevLang, const char* langIdStr);

    // Registration management functions
    //
    void RegisterClass();
    void UnregisterClass();
    bool RegisterObject(TObjectDescriptor app);
    void UnregisterObject();
    TClassId GetLinkGuid(int index);
    void RegisterServer(TLangId lang, const char* regFile = 0);
    void UnregisterServer(TLangId lang = 0, const char* = 0);
    void MakeTypeLib(TLangId lang, const char* = 0);

    // TAutoClass management functions
    //
    void MergeAutoClasses();

    // TypeLibrary management functions
    //
    ITypeLib*   GetTypeLibrary();  // caller MUST do a Release()
    ITypeInfo*  CreateITypeInfo(TAutoClass& cls);  // caller must release
    int         GetClassCount() {return ClassCount;}
    TLangId     GetAppLang() {return AppLang;}
    int         GetClassIndex(TAutoClass* cls);  // returns -1 if not found
    bool        GetClassId(TAutoClass* cls, GUID& retId);
    TAutoClass* GetAutoClass(unsigned index);
    TAutoClass* GetAutoClass(const GUID far& clsid);
    TRegLink*   GetRegLink(const GUID far& clsid);
    uint16      GetVersionField(uint field);
    const char* GetAppName(TLangId lang) {return AppName->Translate(lang);}
    const char* GetAppDoc(TLangId lang)  {return AppDoc->Translate(lang);}
    const char* GetHelpFile(TLangId lang){return HelpFile->Translate(lang);}
    void        WriteTypeLibrary(TLangId lang, const char far* file);

    // TServedObject management functions
    //
    TUnknown*      CreateAutoApp(TObjectDescriptor app, uint32 options,
                                 IUnknown* outer=0);
    void           ReleaseAutoApp(TObjectDescriptor app);
    TUnknown*      CreateAutoObject(TObjectDescriptor obj, TServedObject& app,
                                    IUnknown* outer=0);
    TUnknown*      CreateAutoObject(const void* obj, const typeinfo& objInfo,
                                    const void* app, const typeinfo& appInfo,
                                    IUnknown* outer=0);
    TServedObject* FindServed(const void far* mostDerivedObj);
    TServedObject* FindServed(TObjectDescriptor& objDesc);
    void AddServed(TServedObject& obj);
    void RemoveServed(TServedObject& obj);
    void InvalidateObject(const void far* obj);
    void ReleaseObject(const void far* obj);
    bool IsBound() {return static_cast<bool>(ServedList != 0 || LockCount != 0);}
    bool IsActiveObject(TServedObject* obj) {return ActiveObject == obj;}
    void FlushServed();

    TBaseClassId  AppClassId;

  private:
    void           Init(IMalloc* alloc = 0);  // called only from constructor
    TServedObject* ServedList;   // list of outstanding IDispatch/ITypeInfo objs
    TServedObject* ActiveObject;   // currently registered active object
    TServedObjectCreator* Creator; // Served Object creator class
    TRegList&      RegInfo;        // registration list for application
    const char*    Version;        // library version, stored as text string
    TLocaleString* AppProgId;      // progid of application
    TLocaleString* AppName;        // name of application, localizable
    TLocaleString* AppDoc;         // description of application, localizable
    TLocaleString* HelpFile;       // name of help file, localizable
    TAutoClass::TAutoClassRef*
                   ClassList;      // array of automated class references
    int            ClassCount;     // count of classes, set when first scanned
    int            DebugGuidOffset;// GUID offset for /Debug registration
    int            LibGuidOffset;  // GUID offset for the app library
    int            LinkGuidOffset; // GUID offset for the first doc template
    int            LinkGuidCount;  // count of GUIDs assigned to doc templates
    TLangId        AppLang;        // language Id for this running instance
    TTypeLibrary*  TypeLib;        // type library, only while referenced
    const TRegLink* LinkHead;      // reglink list of reglists to register
    TComponentFactory FactoryCallback;  // callback to create/destroy instance
    HINSTANCE      AppInstance;
    unsigned long  RefCnt;
    unsigned       LockCount;
    unsigned long  RegClassHdl;    // for unregistration
    unsigned long  RegObjectHdl;   // for unregistration
    uint32         Options;        // Command line option bit flags

    // For EXE or DLL component main, provide direct access for destructors
    // For auxilliary DLLs, a table must be maintained of AppDesc vs. task Id
    //
    static TAppDescriptor* This; // set by constructor to component instance

    // IUnknown interface
    //
    HRESULT _IFUNC QueryInterface(const IID far& iid, void far* far* retIface);
    unsigned long _IFUNC AddRef();
    unsigned long _IFUNC Release();

  public:

    // IClassFactory interface
    //
    HRESULT _IFUNC CreateInstance(IUnknown* outer, const IID FAR& iid,
                                  void far* far* retObject);
    HRESULT _IFUNC LockServer(int lock);

  friend class _ICLASS TTypeLibrary;
  friend class _ICLASS TCoClassInfo;
  friend TAppDescriptor* GetAppDescriptor();
};

//
// For EXE and DLL component main module, provide direct access to descriptor
// For auxilliary DLLs, must use table of app descriptor vs. task Id
//
inline TAppDescriptor* GetAppDescriptor() {return TAppDescriptor::This;}

class _ICLASS TTypeLibrary : public ITypeLib {
  public:
    TTypeLibrary(TAppDescriptor& appDesc, TLangId lang);
   ~TTypeLibrary();

//    operator IUnknown&() {return *this;}  

    ITypeInfo*  CreateCoClassInfo();// component typeinfo, caller must release

  private:
    TAppDescriptor& AppDesc;
    unsigned long   RefCnt;
    TLangId         Lang;
    uint16          CoClassFlags;      // type flags combined from autoclasses
    int             CoClassImplCount;  // number of interfaces in coclass

    // IUnknown interface
    //
    HRESULT _IFUNC QueryInterface(const IID far& iid, void far* far* retIface);
    unsigned long _IFUNC AddRef();
    unsigned long _IFUNC Release();

    // ITypeLib interface
    //
    unsigned int _IFUNC GetTypeInfoCount();
    HRESULT _IFUNC GetTypeInfo(unsigned index, ITypeInfo* far* retInfo);
    HRESULT _IFUNC GetTypeInfoType(unsigned index, TYPEKIND far* retKind);
    HRESULT _IFUNC GetTypeInfoOfGuid(const GUID far& guid,
                                     ITypeInfo* far* retInfo);
    HRESULT _IFUNC GetLibAttr(TLIBATTR far* far* retAttr);
    HRESULT _IFUNC GetTypeComp(ITypeComp* far* retComp);
    HRESULT _IFUNC GetDocumentation(int index, BSTR far* retName,
                                    BSTR far* retDoc,
                                    unsigned long far* retHelpContext,
                                    BSTR far* retHelpFile);
    HRESULT _IFUNC IsName(OLECHAR far* nameBuf, unsigned long hashVal,
                          int far* retFound);
    HRESULT _IFUNC FindName(OLECHAR far* nameBuf, unsigned long lHashVal,
                            ITypeInfo* far* retInfo, MEMBERID far* retId,
                            unsigned short far* inoutCount);
    void    _IFUNC ReleaseTLibAttr(TLIBATTR far* attr);
};

class _ICLASS TCoClassInfo : public ITypeInfo {
  public:
    TCoClassInfo(TAppDescriptor& appDesc, uint16 typeFlags, int implCount);
   ~TCoClassInfo();

//    operator IUnknown&() {return *this;}  

  private:
    TAppDescriptor& AppDesc;
    unsigned long   RefCnt;
    uint16          TypeFlags;   // type flags combined from autoclasses
    int             ImplCount;   // number of interfaces in coclass
    unsigned*       ImplList;    // array of indices to autoclasses
    int             Default;     // interface marked as default
    int             DefaultEvent;// event interface marked as default,source

    // IUnknown interface
    //
    HRESULT _IFUNC QueryInterface(const IID far& iid, void far* far* retIface);
    unsigned long _IFUNC AddRef();
    unsigned long _IFUNC Release();

    // ITypeInfo implementation
    //
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
};

//
// external entry points for DLL servers
//
typedef HRESULT STDAPICALLTYPE (*TDllCanUnloadNow)();
typedef HRESULT STDAPICALLTYPE (*TDllGetClassObject)(const GUID far& clsid,
                                                     const GUID far& iid,
                                                     void far* far* retObj);
typedef HRESULT STDAPICALLTYPE (*TDllRegisterServer)();
typedef HRESULT STDAPICALLTYPE (*TDllUnregisterServer)();
typedef HRESULT STDAPICALLTYPE (*TDllRegisterCommand)(const char far* cmdLine);

#endif // OCF_APPDESC_H


