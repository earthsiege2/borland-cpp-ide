/////////////////////////////////////////////////////////////////////////////
// ATLMOD.H - Helper classes (based on ATL) used by CBuilder ActiveX Servers
//
// $Revision:   1.28.1.0.1.0  $
// $Date:   22 Jan 2002 11:37:50  $
//
// Copyright (c) 1999, 2000 Borland International
/////////////////////////////////////////////////////////////////////////////

#if !defined(_ATLMOD_H)
#define _ATLMOD_H

#pragma option push -VF

// These are required due to RTL differences between VC++ and BCB
//
#define _ATL_NO_FORCE_LIBS
#define _ATL_NO_DEBUG_CRT

// Defines _ASSERTE et al.
//
#include <utilcls.h>

// ATL's Base header
//
#if !defined(__ATLBASE_H)
  #include <atl\atlbase.h>
#endif

#include <objbase.h>
#include <cguid.h>
#include <dir.h>

// Local Servers are assumed to be VCL-based
//
#if !defined(__DLL__)
#define USING_VCL
#endif

#if defined(USING_VCL)
#include <comconst.hpp>
#include <sysutils.hpp>
#endif

// Enumerations for Instancing, ThreadingModel etc...
//
enum ObjectInstancing
{
  ioInternalInstance,       // Object is *NOT* exposed to Clients via CoCreateInstance
  ioSingleInstance,         //
  ioMultiInstance,          //
  oiAmbientInstancing       // Determine based on definition of _ATL_xxxx_THREADED macro
};

enum ObjectThreadingModel
{
  otSingle,                 //
  otApartment,
  otFree,
  otBoth,
  otNeutral,
  otAmbientThreadModel      // Use global settings based on _ATL_xxxx_INSTANCING
};

// Default MiscStatus Flags of Object
//
const DWORD dwDefaultControlMiscFlags = OLEMISC_RECOMPOSEONRESIZE | OLEMISC_CANTLINKINSIDE |
                                        OLEMISC_INSIDEOUT | OLEMISC_ACTIVATEWHENVISIBLE |
                                        OLEMISC_SETCLIENTSITEFIRST;

// Declares routine that provide static accessors to various OBJECT attributes
//
#define DECLARE_OLEMISC_FLAGS(flags)  static DWORD   _GetObjectMiscStatus(){ return flags; }
#define DECLARE_PROGID(progid)        static LPCTSTR GetProgID()           { return progid;}
#define DECLARE_DESCRIPTION(desc)     static LPCTSTR GetDescription()      { return desc;  }
#define DECLARE_THREADING_MODEL(thrd) static ObjectThreadingModel GetThreadModel() { return thrd; }

// Declares tables of Verbs (Actions) support by object
//
#define BEGIN_VERB_MAP()            \
static const OLEVERB* _GetVerbs()   \
{                                   \
  static const OLEVERB  _verbs[]=   \
  {

#define VERB_ENTRY_EX(verbId, verbString, mfFlags, verbAttrib)  \
      {verbId, verbString, mfFlags, verbAttrib },

#define VERB_ENTRY(verbId, verbString)  \
         VERB_ENTRY_EX(verbId, verbString, 0 /* No MF_xxxx Flags */, OLEVERBATTRIB_ONCONTAINERMENU)

#define END_VERB_MAP()  \
      { 0, 0, 0, 0 }    \
  };                    \
  return _verbs;        \
};



// TATLModule enhances ATL's CComModule (i.e. T is assumed to be CComModule or a
//                                       CComModule-derived class)
// It is designed to support both in-process and out-of-process servers and handle
// some VCL requirements (if USING_VCL is defined)
//
template <class T = CComModule>
class TATLModule: public T
{
public:
  TATLModule();

#if defined(USING_VCL)
  // Used by Local Servers using VCL
  //
  TATLModule(TProcedure InitProcedure);
#endif

 ~TATLModule();

  LONG        Unlock();

  // Data members of TATLModule<T>
  //
  DWORD       m_ThreadID;             // Thread identifier of module
  bool        m_bRun;                 // Flags whether to run server
  bool        m_bExe;                 // Flags Local server
  bool        m_bAutomationServer;    // Flags module's for Automation Server
  TInitOle*    m_InitOle;              // Object to initialize OLE

#if defined(USING_VCL)
  // Routine used to initialize/cleandup .EXE server using VCL
  //
  static  void __fastcall InitATLServer();
  static  bool __fastcall AutomationTerminateProc();
  static  TProcedure      SaveInitProc;   // Holds system's old InitProcedure

  void    DoFileAndObjectRegistration();
#endif
};


// Constructor used by In-Proc servers (and Out-of-proc servers not using VCL)
//
template <class T>
TATLModule<T>::TATLModule() : m_ThreadID(0), m_bRun(true), m_bExe(false), m_bAutomationServer(false)
{
  m_InitOle = new TInitOle;
  // Could ensure OLE was properly initialized
  /*
  _ASSERTE(!!m_InitOle);
  */
}


// Constructor used by Out-of-proc servers using VCL
//
#if defined(USING_VCL)

template <class T>
TATLModule<T>::TATLModule(TProcedure initProcedure): m_ThreadID(0), m_bRun(true),
                                                     m_bExe(true), m_bAutomationServer(false)
{
  // Could ensure OLE was properly initialized
  /*
  _ASSERTE(!!m_InitOle);
  */

  // Have default Initialization Procedure if none was specified
  //
  if (!initProcedure)
    initProcedure = TATLModule<T>::InitATLServer;

  // Plug in our Initialization procedure
  //
  if (m_bExe && initProcedure)
  {
    SaveInitProc = TProcedure(System::InitProc);
    System::InitProc = initProcedure;
  }
}

#endif  // USING_VCL


// If we're a running out-of-proc server, we revoke registered objects
//
template <class T>
TATLModule<T>::~TATLModule()
{
  if (m_bRun && m_bExe)
  {
    RevokeClassObjects();
  }

  if (!(m_bExe)) {
    delete m_InitOle;
  }
}

#if defined(USING_VCL)

// Performs registration based on switches passed to application
// Invoked only for local servers
//
template <class T>
void TATLModule<T>::DoFileAndObjectRegistration()
{
  TSysCharSet DelimSet;
  DelimSet << '/' << '-';

  if (FindCmdLineSwitch("REGSERVER", DelimSet, true))
  {
    RegisterServer(TRUE);
    m_bRun = false;
  }
  else if (FindCmdLineSwitch("UNREGSERVER", DelimSet, true))
  {
    UnregisterServer();
    m_bRun = false;
  }
  else if (!(FindCmdLineSwitch("AUTOMATION", DelimSet, true) ||
             FindCmdLineSwitch("EMBEDDING", DelimSet, true)))
  {
    RegisterServer(TRUE);
  }

  if (m_bRun)
  {
#ifdef _ATL_SINGLEUSE_INSTANCING
      RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_SINGLEUSE);
#else
      RegisterClassObjects(CLSCTX_LOCAL_SERVER, REGCLS_MULTIPLEUSE);
#endif
  }
  else
    exit(EXIT_SUCCESS);
}

#endif  // USING_VCL


// Override's CComModule's Unlock to post a WM_QUIT message for out-of-proc servers
//
template <class T>
LONG TATLModule<T>::Unlock()
{
  LONG result = T::Unlock();
  if ((result == 0) && m_bExe)
  {
    // If this EXE was launched by OLE (as an Automation Server), then terminate.
    //
    TSysCharSet DelimSet;
    DelimSet << '/' << '-';
    if (FindCmdLineSwitch("AUTOMATION", DelimSet, true))
      ::PostThreadMessage(m_ThreadID, WM_QUIT, 0, 0);
  }
  return result;
}


// _Module is assumed to be a reference to a TComModule
// User may define _Module to be a ref. to an instance of a class derived
// from TComModule.
//
typedef TATLModule<CComModule> TComModule;
extern TComModule &_Module;


#if defined(USING_VCL)

// Variable used to store original System's InitProc
//
template <class T>
TProcedure TATLModule<T>::SaveInitProc = 0;

// To be defined in the Project's source
//
extern _ATL_OBJMAP_ENTRY ObjectMap[];

// Routine used to initialize EXE ATL Servers that use VCL
// This routine is set as System's InitProc - allowing us to initialize a
// variables before chaining off to the original InitProcedure...
//
//
template <class T>
void __fastcall TATLModule<T>::InitATLServer()
{
  // Invoke previous InitProcedure in the chain
  //
  if (SaveInitProc)
    SaveInitProc();

  _Module.Init(ObjectMap, Sysinit::HInstance);
  _Module.m_ThreadID = ::GetCurrentThreadId();
  _Module.m_bAutomationServer = true;
  _Module.DoFileAndObjectRegistration();
  AddTerminateProc(AutomationTerminateProc);
}


// AutomationTerminateProc
//
// Verifies if a Server was launched with the /Automation switch and warns
// user of attempt to unload Server currently being automated.
//

template <class T>
bool __fastcall TATLModule<T>::AutomationTerminateProc()
{

  if (_Module.GetLockCount() > 0)
  {
    return ::MessageBoxA(0, (Comconst_SNoCloseActiveServer1 + Comconst_SNoCloseActiveServer2).c_str(),
                         Comconst_SAutomationWarning.c_str(),
                         MB_YESNO|MB_TASKMODAL|MB_ICONWARNING|MB_DEFBUTTON2) == IDYES;
  }
  else
    // if there are no outstanding lock, it's OK to terminate
    //
    return true;
}

#endif  // USING_VCL

// BCC32's paranoid about operator ambiguities
//
#if defined(__BORLANDC__)
#pragma option push -w-prc
#endif

#if !defined(__ATLCOM_H__)
  #include <atl\atlcom.h>
#endif
#include   <shellapi.h>
#if !defined(__ATLCTL_H__)
  #include <atl\atlctl.h>
#endif

#if defined(__BORLANDC__)
#pragma option pop
#endif

class TFakeRegistrarType
{
public:
  DECLARE_THREADING_MODEL(otAmbientThreadModel);
};

// Provides basic registry support (Add, delete and nuke a key)
//
template <class T>
class TRegistrarBaseT
{
public:
  // Helpers to create/delete registry keys
  //
  static HRESULT  CreateRegKey(LPCTSTR Key, LPCTSTR ValueName, LPCTSTR Value);
  static HRESULT  DeleteRegKey(LPCTSTR Key);
  static HRESULT  NukeRegKey(LPCTSTR Key);

  // Converts a GUID to string
  //
  static HRESULT GUIDToString(const GUID& guid, TAPtr<TCHAR>& gstr);
};

// Creates a Registry Key
//
template <class T>
HRESULT TRegistrarBaseT<T>::CreateRegKey(LPCTSTR keyStr, LPCTSTR ValueName, LPCTSTR Value)
{
  CRegKey key;
  HRESULT status = key.Create(HKEY_CLASSES_ROOT, keyStr);

  if ((status == ERROR_SUCCESS) && (Value != NULL))
  {
    status = key.SetValue(Value, ValueName);

#if defined(SHOW_CREATEREGKEY_VALUES)
    TCHAR dbgMsg[_MAX_PATH*3];
    wsprintf(dbgMsg, _T("%s=%s [%s]"), keyStr, ValueName, Value);
    ::MessageBox(0, dbgMsg, keyStr, MB_OK);
#endif
  }
  return status;
}

// Deletes a Registry Key
// NOTE: A quirk of Windows is that under Win95, ::RegDeleteKey also deletes all descendants
//       whereas under NT the subkey to be deleted must not have subkeys.
//
template <class T>
HRESULT TRegistrarBaseT<T>::DeleteRegKey(LPCTSTR keyStr)
{
  return ::RegDeleteKey(HKEY_CLASSES_ROOT, keyStr);
}

// Delete a Registry Key and all subkeys
//
template <class T>
HRESULT TRegistrarBaseT<T>::NukeRegKey(LPCTSTR keyStr)
{
  // Open the Key
  //
  CRegKey key;
  key.Attach(HKEY_CLASSES_ROOT);
  return key.RecurseDeleteKey(keyStr);
}

// Convert GUID to String
//
template <class T>
HRESULT TRegistrarBaseT<T>::GUIDToString(const GUID& guid, TAPtr<TCHAR>& gstr)
{
  LPOLESTR wstr;
  HRESULT hr = ::StringFromCLSID(guid, &wstr);
  if (hr != S_OK)
    return hr;
#if !defined(UNICODE) && !defined(_UNICODE)
  gstr = WideToAnsi(wstr);
#else
  gstr = strnewdup(wstr);
#endif
  ::CoTaskMemFree(wstr);
  return hr;
}



// TComServerRegistrar class performs registration for a COM server.
// An instance of this class is typically created via the
// DECLARE_COMSERVER_REGISTRY macro.
//
template <class T>
class TComServerRegistrarT : TRegistrarBaseT<T>
{
public:
  TComServerRegistrarT();
  TComServerRegistrarT(const CLSID& clsid, LPCTSTR progID, LPCTSTR description);
 ~TComServerRegistrarT();

  // Virtual method overriden by various Registrars to carry our Registration tasks
  //
  virtual HRESULT UpdateRegistry(bool Register);

protected:
  LPCTSTR                 m_ProgID;           // Programmatic Identifier
  CLSID                   m_ClassID;          // GUID of Object to be registered
  TAPtr<TCHAR>            m_Description;      // Description of CoClass
  TAPtr<TCHAR>            m_ClassIDstr;       // {xxxxxxxx-xxxx-... }
  TAPtr<TCHAR>            m_ClassKey;         // CLSID\{xxxxxxxx-xxxx}
  TAPtr<TCHAR>            m_ServerType;       // LocalServer32 or InprocServer32
  TAPtr<TCHAR>            m_ModuleName;       // Full path to server

  // Helper routine to initialize some data members of class
  //
  void                    Init();
};

// CBuilder3 compatible registrar type
//
typedef TComServerRegistrarT<TFakeRegistrarType> TComServerRegistrar;


template <class T>
TComServerRegistrarT<T>::TComServerRegistrarT() : m_ClassID(0), m_ProgID(0)
{
  Init();
}

template <class T>
TComServerRegistrarT<T>::TComServerRegistrarT(const CLSID& clsid, LPCTSTR progID, LPCTSTR description) :
                                             m_ClassID(clsid),
                                             m_ProgID(progID),
                                             m_Description((description && *description) ?
                                                           TStringConverter<TCHAR>::strnewdup(description) : 0)
{
  Init();
}

template <class T>
TComServerRegistrarT<T>::~TComServerRegistrarT()
{}


// Initialize variables required for registering server
//
template <class T> void
TComServerRegistrarT<T>::Init()
{
  // Retrieve name of this module
  //
  TAPtr<TCHAR> longModuleName = new TCHAR[_MAX_PATH];
  ::GetModuleFileName(_Module.m_hInst, longModuleName, _MAX_PATH);

  // Determine whether there are spaces in the module path/name
  //
  bool hasSpace = false;
  for (int i=0; longModuleName[i]; i++)
    if (isspace(longModuleName[i]))
    {
      hasSpace = true;
      break;
    }

  // Convert to shortpath (NT4's CreateProcess bug) if there's a space
  //
  if (hasSpace)
  {
    m_ModuleName = new TCHAR[_MAX_PATH];
    ::GetShortPathName(longModuleName, m_ModuleName, _MAX_PATH);
  }
  else
    // Transfer ownership of buffer;
    //
    m_ModuleName = longModuleName;

  // Create string of CLSID
  //
  GUIDToString(m_ClassID, m_ClassIDstr);

  // CLSID\{xxxxx-xxx-xx-xx} key
  //
  m_ClassKey = new TCHAR[_MAX_PATH];
  lstrcpy(m_ClassKey, _T("CLSID\\"));
  lstrcat(m_ClassKey, m_ClassIDstr);

  // Create string for server type
  //
  if (_Module.m_bExe)
    m_ServerType = strnewdup(_T("\\LocalServer32"));
  else
    m_ServerType = strnewdup(_T("\\InprocServer32"));
}

template <class T>
bool IsEqual(T t1, T t2)
{
  return t1 == t2;
}

// Perform actual (Un)Registration
//
template <class T> HRESULT
TComServerRegistrarT<T>::UpdateRegistry(bool bRegister)
{
  if (bRegister)
  {
    static TCHAR szAutomation[] = _T(" /Automation");

    // Create registry entries
    //
    CreateRegKey(m_ClassKey, _T(""), m_Description);

    // ClassKey\ServerType
    //
    TAPtr<TCHAR> key(new TCHAR[_MAX_PATH]);
    lstrcpy(key, m_ClassKey);
    lstrcat(key, m_ServerType);

    // Copy over module name
    //
    TAPtr<TCHAR> mod(new TCHAR[_MAX_PATH + sizeof(szAutomation)]);
    lstrcpy(mod, m_ModuleName);

    // Make sure we have /Automation on EXE Automation Servers
    //
    if (_Module.m_bExe && _Module.m_bAutomationServer)
      lstrcat(mod, szAutomation);

    // Register ClassKey\ServerType
    //
    CreateRegKey(key, _T(""), mod);

    // Store Threading Model
    // Ambient relies on defines (a la CBuilder3)
    //
    LPCTSTR szThrdMdl = _T("ThreadingModel");
    if (IsEqual(T::GetThreadModel(), otAmbientThreadModel))
    {
#if   defined(_ATL_SINGLE_THREADED)
      CreateRegKey(key, szThrdMdl, _T("Single"));
#elif defined(_ATL_BOTH_THREADED)
      CreateRegKey(key, szThrdMdl, _T("Both"));
#elif defined(_ATL_APARTMENT_THREADED)
      CreateRegKey(key, szThrdMdl, _T("Apartment"));
#elif defined(_ATL_NEUTRAL_THREADED)
      if (IsComPlusPlatform<int>()) CreateRegKey(key, szThrdMdl, _T("Neutral"))
      else CreateRegKey(key, szThrdMdl, _T("Apartment"));
#elif defined(_ATL_FREE_THREADED)           // NOTE: Check _ATL_FREE_THREADED last
                                            //       because ATLBASE.H defines it for BOTH
      CreateRegKey(key, szThrdMdl, _T("Free"));
#else
      CreateRegKey(key, _T("NoThreadingModel"), _T(""));
#endif
    }
    else if (IsEqual(T::GetThreadModel(), otSingle))
    {
      CreateRegKey(key, szThrdMdl, _T("Single"));
    }
    else if (IsEqual(T::GetThreadModel(), otFree))
    {
      CreateRegKey(key, szThrdMdl, _T("Free"));
    }
    else if (IsEqual(T::GetThreadModel(), otBoth))
    {
      CreateRegKey(key, szThrdMdl, _T("Both"));
    }
    else if (IsEqual(T::GetThreadModel(), otNeutral))
    {
      if (IsComPlusPlatform<int>()) CreateRegKey(key, szThrdMdl, _T("Neutral"));
      else CreateRegKey(key, szThrdMdl, _T("Apartment")); 
    }
    else /* if (T::GetThreadModel() == otApartment)  (Default case) */
    {
      CreateRegKey(key, szThrdMdl, _T("Apartment"));
    }

    // Register CLSID/ProgID
    //
    if (m_ProgID && *m_ProgID)
    {
      CreateRegKey(m_ProgID, _T(""), m_Description);

      TAPtr<TCHAR> buff(new TCHAR[_MAX_PATH]);
      lstrcpy(buff, m_ProgID);
      lstrcat(buff, _T("\\CLSID"));
      CreateRegKey(buff, _T(""), m_ClassIDstr);

      lstrcpy(buff, m_ClassKey);
      lstrcat(buff, _T("\\ProgID"));
      CreateRegKey(buff, _T(""), m_ProgID);
    }
  }
  else
  {
    // Remove registry entries
    //
    NukeRegKey(m_ClassKey);
    if (m_ProgID && *m_ProgID)
      NukeRegKey(m_ProgID);
  }
  return S_OK;
}


// TTypedComServerRegistrar class performs registration for a COM server
// which contains a type library (i.e., an automation server).
// An instance of this class is typically created via the
// DECLARE_TYPED_COMSERVER_REGISTRY macro.
//
template <class T>
class TTypedComServerRegistrarT : public TComServerRegistrarT<T>
{
public:
  TTypedComServerRegistrarT(): TComServerRegistrarT<T>() {}

  TTypedComServerRegistrarT(const CLSID& clsid,
                            LPCTSTR progid,
                            LPCTSTR description = 0) : TComServerRegistrarT<T>(clsid, progid, description)
  {}

  // Overriden to perform additional Registration tasks
  //
  virtual HRESULT UpdateRegistry(bool Register);
};


// CBuilder3 compatible registrar type
//
typedef TTypedComServerRegistrarT<TFakeRegistrarType> TTypedComServerRegistrar;


// Registers (or Unregisters) Server with TypeLibrary
//
template <class T>
HRESULT TTypedComServerRegistrarT<T>::UpdateRegistry(bool Register)
{
  // Load the Module's type library (assumes TypeLibrary is part of module)
  //
  TComInterface<ITypeLib> pTypeLib;
  HRESULT hres = ::LoadTypeLib(TOleString(m_ModuleName), &pTypeLib);
  if (hres != S_OK)
    return hres;

  // Retrieve ITypeInfo
  //
  TComInterface<ITypeInfo> pTypeInfo;
  hres = pTypeLib->GetTypeInfoOfGuid(m_ClassID, &pTypeInfo);
  if (!SUCCEEDED(hres))
    return hres;

  // Get description
  //
  if (!m_Description)
  {
    BSTR description;
    hres = pTypeInfo->GetDocumentation(MEMBERID_NIL, NULL,
                                       &description, NULL, NULL);
    if (SUCCEEDED(hres) && description!=NULL)
    {
#if !defined(UNICODE) && !defined(_UNICODE)
      m_Description = WideToAnsi(description);
#else
      m_Description = strnewdup(description);
#endif
      ::SysFreeString(description);
    }
  }

  // Obtain TLIBATTR for this type library
  //
  TLIBATTR *pTypeAttr = 0;
  hres = pTypeLib->GetLibAttr(&pTypeAttr);
  if (!SUCCEEDED(hres))
    return hres;

  // Get type library version number and GUID from TLIBATTR
  //
  WORD wMajor = pTypeAttr->wMajorVerNum;
  WORD wMinor = pTypeAttr->wMinorVerNum;
  GUID libID  = pTypeAttr->guid;

  pTypeLib->ReleaseTLibAttr(pTypeAttr);
  pTypeAttr = 0;

  if (Register)
  {
    // Make registry entries
    // Call base first when registering
    //
    hres = TComServerRegistrarT<T>::UpdateRegistry(Register);

    // Create TypeLibrary keys
    //
    TCHAR versionVal[128];
    wsprintf(versionVal, _T("%d.%d"), int(wMajor), int(wMinor));

    TAPtr<TCHAR> key(new TCHAR[_MAX_PATH]);
    lstrcpy(key, m_ClassKey);
    lstrcat(key, _T("\\Version"));
    CreateRegKey(key, _T(""), versionVal);

    TAPtr<TCHAR> libidstr;
    GUIDToString(libID, libidstr);

    lstrcpy(key, m_ClassKey);
    lstrcat(key, _T("\\Typelib"));
    CreateRegKey(key, _T(""), libidstr);

    hres = ::RegisterTypeLib(pTypeLib, TOleString(m_ModuleName), 0);
  }
  else
  {
    // Call base to unregister
    // NOTE: Base class nukes everything under \\CLSID\\<clsid>
    //
    hres = TComServerRegistrarT<T>::UpdateRegistry(Register);
  }
  return hres;
}


// TRemoteDataModuleRegistrar
//
class TRemoteDataModuleRegistrar : public TTypedComServerRegistrar
{
private:
  HRESULT doRegisterPooled();
  HRESULT doUnRegisterPooled();
  HRESULT doRegister();
  HRESULT doUnRegister();
public:
  bool RegisterPooled;
  bool EnableSocket;
  bool EnableWeb;
  bool Singleton;
  int Timeout;
  int MaxObjects;
  TRemoteDataModuleRegistrar() : TTypedComServerRegistrar() {}

  TRemoteDataModuleRegistrar(const CLSID& clsid, LPCTSTR progID, LPCTSTR description = 0):
  TTypedComServerRegistrar(clsid, progID, description)
  {}

  virtual HRESULT UpdateRegistry(bool);
};


// TAxControlRegistrar class performs registration for an ActiveX control.
// An instance of this class is typically created via the
// DECLARE_ACTIVEXCONTROL_FACTORY macro.
//
class TAxControlRegistrar: public TTypedComServerRegistrar
{
public:
  TAxControlRegistrar(): m_BitmapID(0), m_MiscFlags(dwDefaultControlMiscFlags), m_Verbs(0)
  {}

  TAxControlRegistrar(const CLSID& clsid,                           // CLSID of Object
                      LPCTSTR progid,                               // ProgId of Object
                      int bitmapID,                                 // Index of ToolboxBitmap32 res.
                      DWORD miscFlags = dwDefaultControlMiscFlags,  // Object MISC_xxx flags
                      const OLEVERB *verbs = 0) :                   // Array of Verbs
                                                m_BitmapID(bitmapID),
                                                m_MiscFlags(miscFlags),
                                                m_Verbs(verbs),
                                                TTypedComServerRegistrar(clsid, progid, 0)
  {}

  // Overriden to perform additional Registration tasks
  //
  virtual HRESULT UpdateRegistry(bool Register);

protected:
  int             m_BitmapID;     // Index of ToolboxBitmap32 Resource
  DWORD           m_MiscFlags;    // Inf. about Control's Designer's/behavior's aspect
  const OLEVERB*  m_Verbs;        // Array of OLEVERBs support be Control
};


// Automation Object Macros
//

// Macro to provide IAppServer support
#define  RDMOBJECT_COM_INTERFACE_ENTRIES(intf) \
      COM_INTERFACE_ENTRY(intf)                \
      COM_INTERFACE_ENTRY2(IAppServer, intf)   \
      COM_INTERFACE_ENTRY2(IDispatch, intf)     
  
//Macro for standard IDispatch Support
#define  AUTOOBJECT_COM_INTERFACE_ENTRIES(intf) \
      COM_INTERFACE_ENTRY(intf)                 \
      COM_INTERFACE_ENTRY2(IDispatch, intf)

// Entry of the default dispatch interface of a COCLASS
//
#define   COM_INTERFACE_ENTRY_OF_DEF_DISPINTF(intf) \
      COM_INTERFACE_ENTRY(intf)                     \
      COM_INTERFACE_ENTRY2(IDispatch, intf)

// Macro defining base class of an Automation Object implementation class.
// NOTE: This macro uses the ambient Threading model setting
//
#define AUTOOBJECT_IMPL(cppClass, CoClass, intf)  \
  public CComObjectRootEx<CComObjectThreadModel>, \
  public CComCoClass<cppClass, &CLSID_##CoClass>, \
  public IDispatchImpl<intf, &IID_##intf, LIBID_OF_##CoClass >


// The DUALINTERFACE macros are inserted by the CodeManager if you insert additional interfaces
// to your CoClass.
//
#define DUALINTERFACE_IMPL(coclass, intf) \
   public IDispatchImpl<intf, &IID_##intf, LIBID_OF_##coclass>

#define DUALINTERFACE_ENTRY(i) \
   COM_INTERFACE_ENTRY(i)


#define UPDATE_REGISTRY_METHOD(code) \
static HRESULT WINAPI UpdateRegistry(BOOL bRegister)  \
{ \
  HRESULT hres; \
  try \
  { \
   code \
  } \
  catch (Exception& e) \
  { \
   hres = Error(e.Message.c_str()); \
  } \
  return hres; \
}

#define DECLARE_COMSERVER_REGISTRY(progid, desc)                \
   UPDATE_REGISTRY_METHOD(                                      \
      TComServerRegistrar CSR(GetObjectCLSID(), progid, desc);  \
      hres = CSR.UpdateRegistry(bRegister);)

#define DECLARE_TYPED_COMSERVER_REGISTRY(progid)                \
   UPDATE_REGISTRY_METHOD(                                      \
    TTypedComServerRegistrar TCSR(GetObjectCLSID(), progid);    \
    hres = TCSR.UpdateRegistry(bRegister);)

#define DECLARE_VCL_CONTROL_PERSISTENCE(CppClass, VclClass) \
    HRESULT IPersistStreamInit_Save(LPSTREAM pstrm, BOOL fClearDirty, ATL_PROPMAP_ENTRY* pMap) \
             { \
             HRESULT retval = S_OK; \
             typedef TVclComControl<CppClass, VclClass> VclComBase;  \
             if (VclComBase* convert = dynamic_cast<VclComBase*>(this)) \
                retval = convert->IPersistStreamInit_SaveVCL(pstrm, fClearDirty, pMap);   \
	     else retval = S_FALSE; \
             return retval; \
             } \
    HRESULT IPersistStreamInit_Load(LPSTREAM pstrm, ATL_PROPMAP_ENTRY *pMap)  \
             { \
             HRESULT retval = S_OK; \
             typedef TVclComControl<CppClass, VclClass> VclComBase; \
             if (VclComBase* convert = dynamic_cast<VclComBase*>(this)) \
                retval = convert->IPersistStreamInit_LoadVCL(pstrm, pMap); \
	     else retval = S_FALSE; \
             return retval; \
             }

#pragma option pop
#endif // _ATL_MOD


