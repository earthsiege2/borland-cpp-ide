//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.10  $
//
// TAppDescriptor - OLE application descriptor definitions
//----------------------------------------------------------------------------
#if !defined(OCF_APPDESC_H)
#define OCF_APPDESC_H

#if !defined(OCF_AUTODEFS_H)
# include <ocf/autodefs.h>
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

class _WSYSCLASS  TRegLink;

#if defined(BI_NAMESPACE)
} // namespace ClassLib
#endif

#if defined(BI_NAMESPACE)
namespace OCF {
#endif

//----------------------------------------------------------------------------
// TAppDescriptor - application registration and browsing facilities
//

class             TServedObjectCreator;
class _ICLASS     TServedObject;
class _ICLASS     TTypeLibrary;
class _ICLASS     TCoClassInfo;

// Factory routine which creates OLE object
//
typedef IUnknown*
(*TComponentFactory)(IUnknown* outer, uint32 options, uint32 id = 0);

//
//
class _ICLASS TAppDescriptor : public IClassFactory {
  public:
    TAppDescriptor(TRegList& regInfo, TComponentFactory callback,
                   string& cmdLine, HINSTANCE hInst = _hInstance,
                   const TRegLink* regLink = 0);
   ~TAppDescriptor();

    operator          IUnknown*()            {return this;}
    bool              IsAutomated() const    {return ClassCount > 0;}
    TComponentFactory GetFactory() const     {return FactoryCallback;}
    const TRegLink*   GetRegLinkHead() const {return LinkHead;}

    // Command line options accessors
    //
    void          ProcessCmdLine(string& cmdLine);
    void          SetLangId(TLangId prevLang, const char* langIdStr);
    bool          IsOptionSet(uint32 option) const  {return (Options & option) != 0;}
    uint32        GetOptions() const                {return Options;}
    void          SetOption(uint32 bit, bool state) {
      if (state)
        Options |= bit;
      else
        Options &= ~bit;
    }

    // Registration management functions
    //
    void          RegisterClass();
    void          UnregisterClass();
    bool          RegisterObject(TObjectDescriptor app);
    void          UnregisterObject();
    TClassId      GetLinkGuid(int index);
    void          RegisterServer(TLangId lang, const char* regFile = 0);
    void          UnregisterServer(TLangId lang = 0, const char* = 0);
    void          MakeTypeLib(TLangId lang, const char* = 0);

    // TAutoClass management functions
    //
    void          MergeAutoClasses();

    // TypeLibrary management functions
    //
    ITypeLib*     GetTypeLibrary();                  //NOTE: Caller MUST do a Release()
    ITypeInfo*    CreateITypeInfo(TAutoClass& cls);  //NOTE: Caller MUST do a Release()
    int           GetClassCount()      {return ClassCount;}
    TLangId       GetAppLang()         {return AppLang;}
    int           GetClassIndex(TAutoClass* cls);  // returns -1 if not found
    bool          GetClassId(TAutoClass* cls, GUID& retId);
    TAutoClass*   GetAutoClass(unsigned index);
    TAutoClass*   GetAutoClass(const GUID& clsid);
    TRegLink*     GetRegLink(const GUID& clsid);
    uint16        GetVersionField(uint field);
    const char*   GetAppName(TLangId lang) {return AppName->Translate(lang);}
    const char*   GetAppDoc(TLangId lang)  {return AppDoc->Translate(lang);}
    const char*   GetHelpFile(TLangId lang){return HelpFile->Translate(lang);}
    void          WriteTypeLibrary(TLangId lang, const char* file);

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
    void           AddServed(TServedObject& obj);
    void           RemoveServed(TServedObject& obj);
    void           InvalidateObject(const void* obj);
    void           ReleaseObject(const void far* obj);
    bool           IsBound() {return static_cast<bool>(ServedList != 0 || LockCount != 0);}
    bool           IsActiveObject(TServedObject* obj) {return ActiveObject == obj;}
    void           FlushServed();

    TBaseClassId  AppClassId;

  private:
    void           Init(IMalloc* alloc = 0);  // called only from constructor
    TServedObject* ServedList;     // List of outstanding IDispatch/ITypeInfo objs
    TServedObject* ActiveObject;   // Currently registered active object
    TServedObjectCreator* Creator; // Served Object creator class
    TRegList&      RegInfo;        // Registration list for application
    const char*    Version;        // Library version, stored as text string
    TLocaleString* AppProgId;      // Progid of application
    TLocaleString* AppName;        // Name of application, localizable
    TLocaleString* AppDoc;         // Description of application, localizable
    TLocaleString* HelpFile;       // Name of help file, localizable
    TAutoClass::TAutoClassRef*
                   ClassList;      // Array of automated class references
    int            ClassCount;     // Count of classes, set when first scanned
    int            DebugGuidOffset;// GUID offset for /Debug registration
    int            LibGuidOffset;  // GUID offset for the app library
    int            LinkGuidOffset; // GUID offset for the first doc template
    int            LinkGuidCount;  // count of GUIDs assigned to doc templates
    TLangId        AppLang;        // Language Id for this running instance
    TTypeLibrary*  TypeLib;        // Type library, only while referenced
    const TRegLink* LinkHead;      // Reglink list of reglists to register
    TComponentFactory FactoryCallback;  // callback to create/destroy instance
    HINSTANCE      AppInstance;
    unsigned long  RefCnt;
    unsigned       LockCount;
    unsigned long  RegClassHdl;    // For unregistration
    unsigned long  RegObjectHdl;   // For unregistration
    uint32         Options;        // Command line option bit flags

    // For EXE or DLL component main, provide direct access for destructors
    // For auxilliary DLLs, a table must be maintained of AppDesc vs. task Id
    //
    static TAppDescriptor* This;   // set by constructor to component instance

    // IUnknown interface
    //
    HRESULT       _IFUNC QueryInterface(const IID far& iid, void** retIface);
    unsigned long _IFUNC AddRef();
    unsigned long _IFUNC Release();

  public:

    // IClassFactory interface
    //
    HRESULT _IFUNC CreateInstance(IUnknown* outer, const IID FAR& iid, void** retObject);
    HRESULT _IFUNC LockServer(int lock);

  friend class _ICLASS TTypeLibrary;
  friend class _ICLASS TCoClassInfo;
  friend TAppDescriptor* GetAppDescriptor();
};

//
// For EXE and DLL component main module, provide direct access to descriptor
// For auxilliary DLLs, must use table of app descriptor vs. task Id
//
inline TAppDescriptor* GetAppDescriptor() {
  return TAppDescriptor::This;
}

class _ICLASS TTypeLibrary : public ITypeLib {
  public:
    TTypeLibrary(TAppDescriptor& appDesc, TLangId lang);
   ~TTypeLibrary();


    // Component typeinfo - NOTE: Caller MUST Release()
    //
    ITypeInfo*      CreateCoClassInfo();

  private:
    TAppDescriptor& AppDesc;
    unsigned long   RefCnt;
    TLangId         Lang;
    uint16          CoClassFlags;      // Type flags combined from autoclasses
    int             CoClassImplCount;  // Number of interfaces in coclass

    // IUnknown interface
    //
    HRESULT       _IFUNC QueryInterface(const IID far& iid, void** retIface);
    unsigned long _IFUNC AddRef();
    unsigned long _IFUNC Release();

    // ITypeLib interface
    //
    unsigned int _IFUNC GetTypeInfoCount();
    HRESULT      _IFUNC GetTypeInfo(unsigned index, ITypeInfo** retInfo);
    HRESULT      _IFUNC GetTypeInfoType(unsigned index, TYPEKIND far* retKind);
    HRESULT      _IFUNC GetTypeInfoOfGuid(const GUID& guid, ITypeInfo** retInfo);
    HRESULT      _IFUNC GetLibAttr(TLIBATTR** retAttr);
    HRESULT      _IFUNC GetTypeComp(ITypeComp** retComp);
    HRESULT      _IFUNC GetDocumentation(int index, BSTR* retName,
                                         BSTR* retDoc,
                                         unsigned long* retHelpContext,
                                         BSTR* retHelpFile);
    HRESULT      _IFUNC IsName(OLECHAR* nameBuf, unsigned long hashVal,
                               int* retFound);
    HRESULT      _IFUNC FindName(OLECHAR* nameBuf, unsigned long lHashVal,
                                 ITypeInfo** retInfo, MEMBERID* retId,
                                 unsigned short far* inoutCount);
    void         _IFUNC ReleaseTLibAttr(TLIBATTR* attr);
};


class _ICLASS TCoClassInfo : public ITypeInfo {
  public:
    TCoClassInfo(TAppDescriptor& appDesc, uint16 typeFlags, int implCount);
   ~TCoClassInfo();


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
    HRESULT       _IFUNC QueryInterface(const IID far& iid, void** retIface);
    unsigned long _IFUNC AddRef();
    unsigned long _IFUNC Release();

    // ITypeInfo implementation
    //
    HRESULT _IFUNC GetTypeAttr(TYPEATTR** pptypeattr);
    HRESULT _IFUNC GetTypeComp(ITypeComp** pptcomp);
    HRESULT _IFUNC GetFuncDesc(unsigned int index, FUNCDESC** ppfuncdesc);
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
typedef HRESULT STDAPICALLTYPE (*TDllGetClassObject)(const GUID& clsid, const GUID& iid, void** retObj);
typedef HRESULT STDAPICALLTYPE (*TDllRegisterServer)();
typedef HRESULT STDAPICALLTYPE (*TDllUnregisterServer)();
typedef HRESULT STDAPICALLTYPE (*TDllRegisterCommand)(const char* cmdLine);

#if defined(BI_NAMESPACE)
} // namespace OCF
#endif

#endif // OCF_APPDESC_H
