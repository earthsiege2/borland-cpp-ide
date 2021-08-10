//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Definition of TOcApp application connection class
//----------------------------------------------------------------------------
#if !defined(OCF_OCAPP_H)
#define OCF_OCAPP_H

#if !defined(OCF_BOLEINTF_H)
# include <ocf/boleintf.h>
#endif
#if !defined(OCF_OCOBJECT_H)
# include <ocf/ocobject.h>
#endif
#if !defined(OCF_OCREG_H)
# include <ocf/ocreg.h>
#endif
#if !defined(OCF_AUTODEFS_H)
# include <ocf/autodefs.h>
#endif
#if !defined(CLASSLIB_VECTIMP_H)
# include <classlib/vectimp.h>
#endif
#if !defined(OCF_OCDATA_H)
# include <ocf/ocdata.h>
#endif
#include <ocf/ocapp.rh>

class _ICLASS    TOcPart;
class _BIDSCLASS TRegLink;
class            TRegList;
class _ICLASS    TOcClassMgr;
class _ICLASS    TOcApp;

//
// Clipboard format name
//
class TOcFormatName {
  public:
    TOcFormatName();
    TOcFormatName(const char far* fmtName, const char far* fmtResultName, const char far* id = 0);

    bool operator ==(const TOcFormatName& other) const {return ToBool(&other == this);}
    const char far* GetId() const {return Id.c_str();}
    const char far* GetName() const {return Name.c_str();}
    const char far* GetResultName() const {return ResultName.c_str();}

  private:
    string Id;          // internal clipboard format name
    string Name;        // external name of clipboard format (used in list box)
    string ResultName;  // string to be used in the dialog help text
};

//
// Clipboard format names
//
class TOcNameList : private TICVectorImp<TOcFormatName> {
  public:
    TOcNameList();
   ~TOcNameList();
    void operator delete(void* ptr) {TStandardAllocator::operator delete(ptr);}

    TOcFormatName*& operator [](unsigned index) {return Base::operator[](index);}
    TOcFormatName*  operator [](char far*);
    void         Clear(int del = 1) {Base::Flush(del);}
    int          Add(TOcFormatName* name) {return Base::Add(name);}
    int          IsEmpty() const {return Base::IsEmpty();}
    unsigned     Find(const TOcFormatName* name) const {return Base::Find(name);}
    virtual uint Count() const {return Base::Count();}
    int          Detach(const TOcFormatName* name, int del = 0)
                    {return Base::Detach(Find(name), del);}

  private:
    typedef TICVectorImp<TOcFormatName> Base;
};

//
// Linking & embeding version of the Registrar
//
class TOcRegistrar : public TRegistrar {
  public:
    TOcRegistrar(TRegList& regInfo, TComponentFactory callback,
                 string& cmdLine, TRegLink* linkHead = 0,
                 HINSTANCE hInst = ::_hInstance);
   ~TOcRegistrar();

    void            CreateOcApp(uint32 options, TOcApp*& ret);
    IBClassMgr*     CreateBOleClassMgr();

  protected:
    void far* GetFactory(const GUID& clsid, const GUID far& iid);
    bool      CanUnload();
    void      LoadBOle();

  private:
    HINSTANCE      BOleInstance;// BOle DLL instance
    IBClassMgr*    BCmI;        //
    TOcClassMgr*   OcClassMgr;  // our IBClassMgr implementation
    int            AppCount;    // TOcApp instance count
  friend class _ICLASS TOcApp;
};

//
// OCF OcApplication class
//
class _ICLASS TOcApp : public TUnknown,
                       private IBApplication,
                       private IBClassMgr {
  public:
    // Constructor for OcApp
    //   retOcApp is location holding unrefcounted pointer to this OcApp
    //
    TOcApp(TOcRegistrar& registrar, uint32 options, TOcApp*& retOcApp);

    // Public accessors
    //
    TOcRegistrar& GetRegistrar() {return Registrar;}
    void    SetupWindow(HWND frameWnd) {FrameWnd = frameWnd;}
    string  GetName() const {return (const char far*)Name;}
    bool    IsOptionSet(uint32 option) const;
    void    SetOption(uint32 bit, bool state);

    // Object reference & lifetime managment
    //
    virtual void   ReleaseObject();

    // Runtime class factory [un]registration
    //
    void RegisterClasses();
    void UnregisterClasses();

    // Clipboard
    //
    void         AddUserFormatName(const char far* name, const char far* resultName,
                                   const char far* id = 0);
    TOcNameList& GetNameList() {return NameList;}

    // App side exposure of selected IBService functions
    //
    bool     UnregisterClass(const string& progid);
    void     EvResize();
    void     EvActivate(bool);
    bool     EvSetFocus(bool set) {return HRSucceeded(BServiceI->OnSetFocus(set));}
    bool     RegisterClass(const string& progid, BCID classId, bool multiUse);
//  bool     OnModalDialog(bool enable)
//               {return BServiceI->OnModalDialog(enable);}
    bool     TranslateAccel(MSG far* msg)
               {return HRSucceeded(BServiceI->TranslateAccel(msg));}
//  TOcHelp HelpMode(TOcHelp newMode);
//               {return BServiceI->HelpMode(newMode);}
    bool     CanClose();

    bool     Browse(TOcInitInfo& initInfo);
    bool     BrowseClipboard(TOcInitInfo& initInfo);
    bool     Paste(TOcInitInfo& initInfo);
    bool     Copy(TOcPart* ocPart);
    bool     Copy(TOcDataProvider* ocData);
    bool     Drag(TOcDataProvider* ocData, TOcDropAction inAction, TOcDropAction& outAction);
    bool     Drag(TOcPart* ocData, TOcDropAction inAction, TOcDropAction& outAction);
    bool     Convert(TOcPart* ocPart, bool b);
    uint     EnableEditMenu(TOcMenuEnable enable, IBDataConsumer far* ocview);

    // Exposure of BOle's componentCreate for internal OCF support
    //
    HRESULT BOleComponentCreate(IUnknown far* far* retIface,
                                IUnknown far* outer, uint32 idClass);

    // Internal reference management
    //
    ulong _IFUNC   AddRef() {return GetOuter()->AddRef();}
    ulong _IFUNC   Release() {return GetOuter()->Release();}
    HRESULT _IFUNC QueryInterface(const GUID far& iid, void far*far* iface)
                     {return GetOuter()->QueryInterface(iid, iface);}
  protected:
   ~TOcApp();

    uint32 Options;
    bool   Registered;
    TOcApp*& OcAppPtr;   // pointer to this instance, must zero on destruction

    uint32 ForwardEvent(int eventId, const void far* param);
    uint32 ForwardEvent(int eventId, uint32 param = 0);

    // TUnknown virtual overrides
    //
    HRESULT      QueryObject(const IID far& iid, void far* far* iface);

  private:

    // IBWindow implementation
    //
    HWND     _IFUNC GetWindow();
    HRESULT  _IFUNC GetWindowRect(TRect far* r);
    LPCOLESTR _IFUNC GetWindowTitle();
    void     _IFUNC AppendWindowTitle(LPCOLESTR title);
    HRESULT  _IFUNC SetStatusText(LPCOLESTR text);

    HRESULT  _IFUNC RequestBorderSpace(const TRect far*);
    HRESULT  _IFUNC SetBorderSpace(const TRect far*);

    HRESULT  _IFUNC InsertContainerMenus(HMENU hMenu, TOcMenuWidths far* omw);
    HRESULT  _IFUNC SetFrameMenu(HMENU hMenu);
    void     _IFUNC RestoreUI();
    HRESULT  _IFUNC Accelerator(MSG far* msg);
    HRESULT  _IFUNC GetAccelerators(HACCEL far*, int far*);

    // IBApplication implementation
    //
    LPCOLESTR _IFUNC GetAppName();
    TOcHelp  _IFUNC HelpMode(TOcHelp newMode);
    HRESULT  _IFUNC CanLink();
    HRESULT  _IFUNC CanEmbed();
    HRESULT  _IFUNC IsMDI();
    HRESULT  _IFUNC OnModalDialog(bool svrModal);
    void     _IFUNC DialogHelpNotify(TOcDialogHelp);
    void     _IFUNC ShutdownMaybe();

    // IBClassMgr implementation
    //
    HRESULT  _IFUNC ComponentCreate(IUnknown far* far* ret,
                                    IUnknown far* outer, uint32 classId);
    HRESULT  _IFUNC ComponentInfoGet(IUnknown far* far* info,
                                     IUnknown far* outer, uint32 classId);

    void   Init();

    TOcRegistrar&  Registrar;   // Overall application description object

    // BOle side support
    //
    IBClassMgr*    BCmI;        // Our private class maneger
    IUnknown*      BService;    // BOle service object & interface
    IBService*     BServiceI;   //
    HWND           FrameWnd;    // Corresponding main window

#if defined(BI_DATA_NEAR)
    TString&       Name;        // Application name from reglist
    TOcNameList&   NameList;    // Clipboard format name list
#else
    TString        Name;
    TOcNameList    NameList;
#endif
    bool           DisableDlgs; // Server went modal--disable our dialogs

  friend class _ICLASS TOcDocument;
  friend class _ICLASS TOcPart;
  friend class _ICLASS TOcRemView;
  friend class _ICLASS TOcView;
};

inline bool TOcApp::IsOptionSet(uint32 option) const
               {return ToBool(Options & option);}
inline void TOcApp::SetOption(uint32 bit, bool state)
               {if (state) Options |= bit; else Options &= ~bit;}

inline void TOcRegistrar::CreateOcApp(uint32 options, TOcApp*& retOcApp) {
  new TOcApp(*this, options, retOcApp);
}

//
// ObjectConnections message and subdispatch IDs
//
#define WM_BCXNAME          0x7FFF-8     // (WM_VBXNAME) BCX event fire by name
#define WM_OCEVENT          WM_BCXNAME-1 // OC -> app messages

//
// Subdispatch IDs for TOcApp clients
//
#define OC_APPINSMENUS        0x0100  // Main window insert menus
#define OC_APPMENUS           0x0101  // Main window set menu
#define OC_APPPROCESSMSG      0x0102  // Process msg for accel, etc
#define OC_APPFRAMERECT       0x0103  // Get inner rect of main window
#define OC_APPBORDERSPACEREQ  0x0104  // Request/set app frame border space
#define OC_APPBORDERSPACESET  0x0105  // Request/set app frame border space
#define OC_APPSTATUSTEXT      0x0106  // Set the status text
#define OC_APPRESTOREUI       0x0107  // Have the app frame restore its UI
#define OC_APPDIALOGHELP      0x0108  // Ole dialog help button pressed
#define OC_APPSHUTDOWN        0x0109  // Shutdown app frame window

//
// OCF Mixin Class for users derived application class
//
#if !defined(_OCMCLASS)
# define _OCMCLASS
#endif

class _OCMCLASS TOcModule {
  public:
    TOcModule() : OcApp(0) {} // must call OcInit after construction
   ~TOcModule();

    void OcInit(TOcRegistrar& registrar, uint32 options);
    TRegistrar& GetRegistrar() {return OcApp->GetRegistrar();}

    TOleAllocator OleMalloc;   // default to task allocator
    TOcApp* OcApp;
    bool IsOptionSet(uint32 option) const;
  private:
    uint32 InitOptions;
};

inline TOcModule::~TOcModule() {
  if (OcApp)
    OcApp->ReleaseObject();  // don't delete, just release
}

inline bool TOcModule::IsOptionSet(uint32 option) const {
  return OcApp ? OcApp->IsOptionSet(option) : (InitOptions & option) != 0;
}

inline void TOcModule::OcInit(TOcRegistrar& registrar, uint32 options) {
  InitOptions = options;
  registrar.CreateOcApp(options, OcApp);
}

#endif  // OCF_OCAPP_H
