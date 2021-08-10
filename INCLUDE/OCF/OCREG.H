//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// OLE Registration definitions
//----------------------------------------------------------------------------
#if !defined(OCF_OCREG_H)
#define OCF_OCREG_H

#if !defined(OCF_AUTODEFS_H)
# include <ocf/autodefs.h>
#endif
#if !defined(WINSYS_REGISTRY_H)
# include <winsys/registry.h>
#endif
#if !defined(CLASSLIB_POINTER_H)
# include <classlib/pointer.h>
#endif

//
// Global registration functions for OLE. Most are wrappers for winsys's
// TRegistry functions
//

long                                   // returns numeric value of <docflags>
OcRegisterClass(TRegList& regInfo,     // obj holding array of reg parameters
                HINSTANCE hInst,       // 0 defaults to current task
                ostream& out,          // open ostream to stream reg entries
                TLangId lang,          // language for registration
                char* filter = 0,      // internal use to restrict entries
                TRegItem* defaults = 0,// optional registration default list
                TRegItem* overrides= 0);// optional registration override list

int                                   // returns error count, 0 if success
OcUnregisterClass(TRegList& regInfo,  // registration table used for register
                  TRegItem* overrides=0); // optional additional regitration item

inline int OcRegistryValidate(istream& in) {
  return TRegistry::Validate(TRegKey::ClassesRoot, in);
}

inline void OcRegistryUpdate(istream& in) {
  TRegistry::Update(TRegKey::ClassesRoot, in);
}

int                   // return: 0=no debug reg, -1=user clsid, 1=default used
OcSetupDebugReg(TRegList& regInfo,    // original registration list
                TRegItem* regDebug,   // temp override list[DebugReplaceCount]
                TLangId lang,         // language for registration
                char* clsid);         // default temp debug clsid string buf

//
const int DebugRegCount = 4+1;        // replacements + room for terminator

extern char AppDebugFilter[];         // templates needed for debug app reg
extern char DocDebugFilter[];         // templates needed for debug doc reg
extern TRegItem OcRegNoDebug[];       // override list to shut off "debugger"
extern TRegItem OcRegNotDll[];        // override to shut off EXE-only items

//----------------------------------------------------------------------------
// TRegistrar class
//

//
// Application running mode and registration flags
// these are initialized when processing command line or registration requests
// the application's copy of the initial option flags is dynamically updated
//
enum TOcAppMode {
  amRegServer    = 0x0001, // complete registration database update requested
  amUnregServer  = 0x0002, // registration database unregistration requested
  amAutomation   = 0x0004, // set from cmdline when EXE lauched for automation
  amEmbedding    = 0x0008, // cmdline, overridden per Instance if embedded DLL
  amLangId       = 0x0010, // user registration requested a particular LangId
  amTypeLib      = 0x0020, // requested typelib to be generated and registered
  amDebug        = 0x0040, // user requested launching for debugging
  amNoRegValidate= 0x0080, // user request to suppress registry validation
  amExeModule    = 0x0100, // set for EXE components, 0 if DLL inproc server
  amExeMode      = 0x0200, // may be overridden per instance if running DLL
  amServedApp    = 0x0400, // per instance flag, app refcnt held by container
  amSingleUse    = 0x0800, // set from app reg, may be forced on per instance
  amQuietReg     = 0x1000, // suppress error UI during registration processing
  amRun          = 0x2000, // set in factory call to run application msg loop
  amShutdown     = 0x4000, // set in factory call to shutdown/delete app
  amAnyRegOption = amRegServer | amUnregServer | amTypeLib,
};

typedef IUnknown*
(*TComponentFactory)(IUnknown* outer, uint32 options, uint32 id = 0);

class _ICLASS TAppDescriptor;

//
// class TRegistrar
// ~~~~~ ~~~~~~~~~~
// Application registration manager interface class
//
class _ICLASS TRegistrar {
  public:
    TRegistrar(TRegList& regInfo, TComponentFactory callback,
               string& cmdLine, HINSTANCE hInst = ::_hInstance);
    virtual ~TRegistrar();
    TUnknown* CreateAutoApp(TObjectDescriptor app, uint32 options,
                            IUnknown* outer=0);
    void      ReleaseAutoApp(TObjectDescriptor app);
    TUnknown* CreateAutoObject(TObjectDescriptor doc, TServedObject& app,
                               IUnknown* outer=0);
    TUnknown* CreateAutoObject(const void* obj, const typeinfo& objInfo,
                               const void* app, const typeinfo& appInfo,
                               IUnknown* outer=0);
    virtual void far* GetFactory(const GUID& clsid, const GUID far& iid);
    virtual int       Run();   // run an instance of an app if it is an EXE
    virtual void      Shutdown(IUnknown* releasedObj, uint32 options);
    virtual bool      CanUnload();

    static TRegistrar* GetNext(TRegistrar* reg);// walk linked list of registrars

    // Registration management functions
    void RegisterAppClass();
    void UnregisterAppClass();

    // Command line options accessors
    bool IsOptionSet(uint32 option) const;
    uint32 GetOptions() const;
    void SetOption(uint32 bit, bool state);
    void ProcessCmdLine(string& cmdLine);

    TAppDescriptor& GetAppDescriptor() {return AppDesc;}  // internal use

  protected:
    TRegistrar(TAppDescriptor& appDesc);
    TAppDescriptor& AppDesc;

  private:
    static TRegistrar* RegistrarList;  // linked list of registrar objects
    TRegistrar* Next;                  // next link in registrar list
};

//----------------------------------------------------------------------------
//  Factory for automated OLE components, no linking/embedding support
//

template <class T> class TOcAutoFactory {
  public:
    operator TComponentFactory() {return Create;}

    // Callouts to allow replacement of individual creation steps
    //
    static T*        CreateApp(HINSTANCE hInst, uint32 options);
    static int       RunApp(T* app);
    static void      DestroyApp(T* app);

    // Main Create callback function called to create app and/or object
    //
    static IUnknown* Create(IUnknown* outer, uint32 options, uint32 id);
};

//
// Called when the app is not found and needs to be created
//
template <class T> T*
TOcAutoFactory<T>::CreateApp(HINSTANCE hInst, uint32 options)
{
  T* app = new T(hInst, options);
  return app;
}

//
// Called to run the application message loop if an EXE, or DLL in amExeMode
//
template <class T> int
TOcAutoFactory<T>::RunApp(T* /*app*/)
{
  MSG msg;
  while(GetMessage(&msg, 0, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return 0;
}

//
// Called to destroy the application previously created
//
template <class T> void
TOcAutoFactory<T>::DestroyApp(T* app)
{
  delete app;
}

//
// Main Create callback function called to create app
//
template <class T> IUnknown*
TOcAutoFactory<T>::Create(IUnknown* outer, uint32 options, uint32 /*id*/)
{
  static T* exeApp;     // used to hold EXE object until OLE factory call
  T* app;
  IUnknown* ifc = 0;
  if (options & amShutdown)
    return (options & amServedApp) ? 0 : outer;
  if ((options & amAutomation) && (options & amServedApp)) {
    app = exeApp;    // if EXE, retrieve app created on initial call from main
  } else {
    app = CreateApp(_hInstance, options);
  }
  if ((options & amAutomation) && !(options & amServedApp)) {
    exeApp = app;    // if EXE, hold app until factory call when outer known
  } else {
    ifc = *::Registrar->CreateAutoApp(TAutoObjectDelete<T>(app),options,outer);
  }
  if (options & amRun) {
    RunApp(app);
    DestroyApp(app);
  } // else DLL server, ifc will be released by controller, which deletes app
  return ifc;
}

//----------------------------------------------------------------------------

#if !defined(OCF_APPDESC_H)
# include <ocf/appdesc.h>  // private for inline implementation only
#endif

inline TUnknown*
TRegistrar::CreateAutoApp(TObjectDescriptor app, uint32 opts, IUnknown* outer)
                             {return AppDesc.CreateAutoApp(app, opts, outer);}
inline void
TRegistrar::ReleaseAutoApp(TObjectDescriptor app)
                                {AppDesc.ReleaseAutoApp(app);}
inline TUnknown*
TRegistrar::CreateAutoObject(TObjectDescriptor doc, TServedObject& app,
                             IUnknown* outer)
                           {return AppDesc.CreateAutoObject(doc, app, outer);}
inline TUnknown*
TRegistrar::CreateAutoObject(const void* obj, const typeinfo& objInfo,
                             const void* app, const typeinfo& appInfo,
                             IUnknown* outer)
         {return AppDesc.CreateAutoObject(obj, objInfo, app, appInfo, outer);}
inline void TRegistrar::RegisterAppClass()    {AppDesc.RegisterClass();}
inline void TRegistrar::UnregisterAppClass()  {AppDesc.UnregisterClass();}
inline bool TRegistrar::IsOptionSet(uint32 option) const
                                         {return AppDesc.IsOptionSet(option);}
inline uint32 TRegistrar::GetOptions() const {return AppDesc.GetOptions();}
inline void TRegistrar::SetOption(uint32 bit, bool state)
                                              {AppDesc.SetOption(bit,state);}
inline void TRegistrar::ProcessCmdLine(string& cmdLine)
                                            {AppDesc.ProcessCmdLine(cmdLine);}
#endif  // OCF_OCREG_H
