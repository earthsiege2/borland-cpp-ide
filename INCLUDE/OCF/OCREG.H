//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   OLE Registration definitions
//----------------------------------------------------------------------------
#if !defined(OCF_OCREG_H)
#define OCF_OCREG_H

#if !defined(OCF_AUTODEFS_H)
# include <ocf/autodefs.h>
#endif
#if !defined(OSL_GEOMETRY_H)
# include <osl/geometry.h>  // defines TPointer
#endif
class _EXPCLASS istream;
class _EXPCLASS ostream;

//____________________________________________________________________________
//
// TXRegistry - Windows Registry related exception object
//____________________________________________________________________________

class TXRegistry : public TXBase {
  public:
    TXRegistry(const char* msg, const char* key);
    TXRegistry(const TXRegistry& copy);
    static void Check(long stat, const char* key);
    const char* Key;
};
inline TXRegistry::TXRegistry(const char* msg, const char* key)
            : TXBase(msg), Key(key) {}
inline TXRegistry::TXRegistry(const TXRegistry& src)
            : TXBase(src), Key(src.Key) {}

//____________________________________________________________________________
//
// Clipboard and registry data transfer format definitions
//____________________________________________________________________________

const int ocrVerbLimit   = 8;  // maximum number of verbs registered per class
const int ocrFormatLimit = 8;  // maximum number of data formats per class

// format: standard clipboard numeric format, or name of custom format
//
enum ocrClipFormat {
  ocrText           =  1,  // CF_TEXT          
  ocrBitmap         =  2,  // CF_BITMAP       
  ocrMetafilePict   =  3,  // CF_METAFILEPICT 
  ocrSylk           =  4,  // CF_SYLK         
  ocrDif            =  5,  // CF_DIF          
  ocrTiff           =  6,  // CF_TIFF         
  ocrOemText        =  7,  // CF_OEMTEXT      
  ocrDib            =  8,  // CF_DIB          
  ocrPalette        =  9,  // CF_PALETTE      
  ocrPenData        = 10,  // CF_PENDATA      
  ocrRiff           = 11,  // CF_RIFF         
  ocrWave           = 12,  // CF_WAVE         
  ocrUnicodeText    = 13,  // CF_UNICODETEXT  Win32 only
  ocrEnhMetafile    = 14,  // CF_ENHMETAFILE  Win32 only
};
#define ocrRichText          "Rich Text Format"
#define ocrEmbedSource       "Embed Source"
#define ocrEmbeddedObject    "Embedded Object"
#define ocrLinkSource        "Link Source"
#define ocrObjectDescriptor  "Object Descriptor"
#define ocrLinkSrcDescriptor "Link Source Descriptor"

// aspect: view types supported by transfer
//
enum ocrAspect {
  ocrContent   = 1,  // DVASPECT_CONTENT    normal display representation
  ocrThumbnail = 2,  // DVASPECT_THUMBNAIL  picture appropriate for browser
  ocrIcon      = 4,  // DVASPECT_ICON       iconized representation of object
  ocrDocPrint  = 8,  // DVASPECT_DOCPRINT   print preview representation
};

// medium: means of data transfer
//
enum ocrMedium {
  ocrHGlobal    = 1,  // TYMED_HGLOBAL  global memory handle
  ocrFile       = 2,  // TYMED_FILE     data as contents of file
  ocrIStream    = 4,  // TYMED_ISTREAM  instance of an IStream object
  ocrIStorage   = 8,  // TYMED_ISTORAGE streams within an instance of IStorage
  ocrGDI        = 16, // TYMED_GDI      GDI object in global handle
  ocrMfPict     = 32, // TYMED_MFPICT   CF_METAFILEPICT containing global handle
  ocrStaticMed  = 1024 // OLE 2 static object
};

// direction: transfer directions supported
//
enum ocrDirection {
  ocrGet    = 1,
  ocrSet    = 2,
  ocrGetSet = 3,
};

//____________________________________________________________________________
//
// Miscellaneous registry definitions
//____________________________________________________________________________

// IOleObject miscellaneous status flags, defined for each or all aspects
//
enum ocrObjectStatus {
  ocrRecomposeOnResize           = 1,   // request redraw on container resize
  ocrOnlyIconic                  = 2,   // only useful context view is Icon
  ocrInsertNotReplace            = 4,   // should not replace current select.
  ocrStatic                      = 8,   // object is an OLE static object
  ocrCantLinkInside              = 16,  // should not be the link source
  ocrCanLinkByOle1               = 32,  // only used in OBJECTDESCRIPTOR
  ocrIsLinkObject                = 64,  // set by OLE2 link for OLE1 compat.
  ocrInsideOut                   = 128, // can be activated concurrently
  ocrActivateWhenVisible         = 256, // hint to cntnr when ocrInsideOut set
  ocrRenderingIsDeviceIndependent= 512, // no decisions made based on target
  ocrNoSpecialRendering          = 512, // older enum for previous entry
};

// IOleObject verb menu flags
//
enum ocrVerbMenuFlags {
  ocrGrayed      = 1,   // MF_GRAYED
  ocrDisabled    = 2,   // MF_DISABLED
  ocrChecked     = 8,   // MF_CHECKED
  ocrMenuBarBreak= 32,  // MF_MENUBARBREAK
  ocrMenuBreak   = 64,  // MF_MENUBAR
};

// IOleObject verb attribute flags
//
enum ocrVerbAttributes {
  ocrNeverDirties      = 1,   // verb can never cause object to become dirty
  ocrOnContainerMenu   = 2,   // only useful context view is Icon
};

// Entries for <usage> registration parameter, class factory registration mode
//
#define ocrSingleUse     "1"  // single client per instance
#define ocrMultipleUse   "2"  // multiple clients per instance
#define ocrMultipleLocal "3"  // multiple clients, separate inproc server


long                                   // returns numeric value of <docflags>
OcRegisterClass(TRegList& regInfo,     // obj holding array of reg parameters
                HINSTANCE hInst,       // 0 defaults to current task
                ostream& out,          // open ostream to stream reg entries
                TLangId lang,          // language for registration
                char* filter = 0,      // internal use to restrict entries
                TRegItem* defaults = 0,// optional registration default list
                TRegItem* extra = 0);  // optional registration override list

int                                   // returns error count, 0 if success
OcUnregisterClass(TRegList& regInfo,  // registration table used for register
                  TRegItem* extra=0); // optional additional regitration item

int OcRegistryValidate(istream& in);   // returns number of mismatched entires

void OcRegistryUpdate(istream& in);

int                   // return: 0=no debug reg, -1=user clsid, 1=default used
OcSetupDebugReg(TRegList& regInfo,    // original registration list
                TRegItem* regDebug,   // temp override list[DebugReplaceCount]
                TLangId lang,         // language for registration
                char* clsid);         // default temp debug clsid string buf
const int DebugRegCount = 4+1;        // replacements + room for terminator
extern char AppDebugFilter[];         // templates needed for debug app reg
extern char DocDebugFilter[];         // templates needed for debug doc reg
extern TRegItem OcRegNoDebug[];       // override list to shut off "debugger"
extern TRegItem OcRegNotDll[];        // override to shut off EXE-only items

//____________________________________________________________________________
//
// TRegistrar - Application registration manager interface class
//____________________________________________________________________________

// application running mode and registration flags
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

//____________________________________________________________________________
//
//  Factory for automated OLE components, no linking/embedding support
//____________________________________________________________________________

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

//____________________________________________________________________________

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
