///////////////////////////////////////////////////////////////////////////////
// ATLVCL.CPP - Provides the connective tissue between
//              the ATL framework and VCL components.
//
// $Revision:   1.29.2.6  $
//
// Copyright (c) 1997, 2000 Borland International
///////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#if !defined(__ATLVCL_H_)
#include <atl\atlvcl.h>
#endif
#include <comconst.hpp>
#include <axctrls.hpp>
#include <tchar.h>

namespace TInternalRegistrationHelpers {
// Contains functions needed internally to this module for the purpose
// of manipulating data into more pleasant forms and/or talking to the
// Registry. These functions are not available externally.

HRESULT CreateRegKey(const TCHAR* Key, const TCHAR* ValueName, const TCHAR* Value)
{
   HKEY tempKey;
   HRESULT Status = RegCreateKeyEx(HKEY_CLASSES_ROOT, Key, 0, _T(""),
                    REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, 0, &tempKey, 0);
   if SUCCEEDED(Status)
   {
     Status = RegSetValueEx(tempKey, ValueName, 0, REG_SZ, (BYTE*)Value,
                            _tcslen(Value) + 1);
     RegCloseKey(tempKey);
   }
   return Status;
}

HRESULT DeleteRegValue(TCHAR* Key, TCHAR* ValueName)
{
  HKEY tempKey;
  HRESULT Status = RegOpenKey(HKEY_CLASSES_ROOT, Key, &tempKey);
  if SUCCEEDED(Status)
  {
    Status = RegDeleteValue(tempKey, ValueName);
    RegCloseKey(tempKey);
  }
  return Status;
}

/* must be freed by caller. */
TCHAR* CreateKeyOfClass(TCHAR* CLSID)
{
   TCHAR* retval = new TCHAR[_tcslen(CLSID)+_tcslen(_T("CLSID\\"))+1]; // length of "CLSID\"+ null terminator
   _tcscpy(retval, _T("CLSID\\"));
   _tcscat(retval, CLSID);
   return retval;
}

/* must be freed by caller */
TCHAR* CreateAppIDOfClass(TCHAR* CLSID)
{
   TCHAR* retval = new TCHAR[_tcslen(CLSID)+_tcslen(_T("AppID\\"))+1]; // length of "AppID\" + null terminator
   _tcscpy(retval, _T("AppID\\"));
   _tcscat(retval, CLSID);
   return retval;
}

/* must be freed by caller */
TCHAR* CreateImplementedCategoriesOfClass(TCHAR* CLSID)
{
 TCHAR* retval = new TCHAR[_tcslen(_T("CLSID\\"))+_tcslen(CLSID)+_tcslen(_T("\\Implemented Categories\\"))+1];
  _tcscpy(retval, _T("CLSID\\"));
  _tcscat(retval, CLSID);
  _tcscat(retval, _T("\\Implemented Categories\\"));
  return retval;
}

/* must be freed by caller */
TCHAR* CreateImplementedMIDASOfClass(TCHAR* CLSID)
{
  TCHAR* retval = new TCHAR[_tcslen(CLSID)+_tcslen(_T("CLSID\\"))+
                            _tcslen(_T("\\Implemented Categories\\"))+
                            _tcslen(_T("{13E85B3C-9508-11D2-AB63-00C04FA35CFA}\\"))+1];
  _tcscpy(retval, _T("CLSID\\"));
  _tcscat(retval, CLSID);
  _tcscat(retval, _T("\\Implemented Categories\\"));
  _tcscat(retval, _T("{13E85B3C-9508-11D2-AB63-00C04FA35CFA}\\"));
  return retval;
}

/* must be freed by caller. Since the caller won't have a clue how
   to free it if it's not of type REG_SZ, free it manually and return
   an error in that case. */
char* GetRegStringValue(const TCHAR* Key, const TCHAR* ValueName)
{
   char* retval = new char[256];
   DWORD Length = 256*sizeof(char);
   HKEY tempKey;
   DWORD TypeCode;
   HRESULT hr = RegOpenKey(HKEY_CLASSES_ROOT, Key, &tempKey);
   if SUCCEEDED(hr)
   {
      hr = RegQueryValueEx(tempKey, ValueName, 0, &TypeCode, (Byte*)retval, &Length);
   }
   if (TypeCode != REG_SZ)
   {
      delete[] retval;
      retval = NULL;
   }
   return retval;
}

}   // END namespace
//-----------------------------------------------------------------------------//

// Externs
// Pointer to save Initialization Procedure when using VCL
// (CBuilder3 backward compatibility)
//
void* SaveInitProc = 0;

// Helper used by IPersistStreamInit implementation to save component
//
void __fastcall SaveVCLComponentToStream(TComponent *vclInstance, LPSTREAM pStrm)
{
  TPtr<TStream> pStream = new TOleStream(_di_IStream(pStrm));
  TPtr<TWriter> pWriter = new TWriter(pStream, 4096);
  pWriter->IgnoreChildren = true;
  pWriter->WriteDescendent(vclInstance, 0);
}


// Helper used by IPersistStreamInit implementation to load component
//
void __fastcall LoadVCLComponentFromStream(TComponent *vclInstance, LPSTREAM pStrm)
{
  TPtr<TStream> pStream = new TOleStream(_di_IStream(pStrm));
  TPtr<TReader> pReader = new TReader(pStream, 4096);
  pReader->ReadRootComponent(vclInstance);
}


// Helper used by framework to create a reflector object
//
TWinControl* CreateReflectorWindow(HWND parent, Controls::TControl* Control)
{
  return new TReflectorWindow(parent, Control);
}

//----------------------------------------------------------------------------//

// Register (or unregisters) Remote data module
//
HRESULT TRemoteDataModuleRegistrar::UpdateRegistry(bool bRegister)
{
   HRESULT hr = TTypedComServerRegistrar::UpdateRegistry(bRegister);
#if!defined UNICODE && !defined(_UNICODE)
   LPCSTR pClassID = m_ClassIDstr;
   LPCSTR pProgID  = m_ProgID;
#else
   TAPtr<CHAR> pClassID = WideToAnsi(m_ClassIDstr);
   TAPtr<CHAR> pProgID  = WideToAnsi(m_ProgID);
#endif
   if (bRegister ) hr = doRegister();
   else hr=doUnRegister();

   return hr;
}

/* Unregister the keys added if the data module supported pooling. */
HRESULT TRemoteDataModuleRegistrar::doUnRegisterPooled()
{
  TCHAR* pClassID = m_ClassIDstr;
  TCHAR* tempKey = TInternalRegistrationHelpers::CreateKeyOfClass(pClassID);
  try
  {
    OLECHECK(TInternalRegistrationHelpers::DeleteRegValue(tempKey, _T("Pooled")));
    OLECHECK(TInternalRegistrationHelpers::DeleteRegValue(tempKey, _T("MaxObjects")));
    OLECHECK(TInternalRegistrationHelpers::DeleteRegValue(tempKey, _T("Timeout")));
    OLECHECK(TInternalRegistrationHelpers::DeleteRegValue(tempKey, _T("Singleton")));
    delete[] tempKey;
  }
  catch (...)
  {
    if (tempKey) delete[] tempKey;
    return E_FAIL;
  }
  return S_OK;
}

/* Register the data module to support pooling */
HRESULT TRemoteDataModuleRegistrar::doRegisterPooled()
{
  TCHAR* pClassID = m_ClassIDstr;
  TCHAR* tempKey = TInternalRegistrationHelpers::CreateKeyOfClass(pClassID);
  char* tempNumber = 0;
 try
  {
    OLECHECK(TInternalRegistrationHelpers::CreateRegKey(tempKey, _T("Pooled"), _T("1")));
    tempNumber = new char[33];
    itoa(MaxObjects, tempNumber, 10);
#if !defined(UNICODE) && !defined(_UNICODE)
    OLECHECK(TInternalRegistrationHelpers::CreateRegKey(tempKey, "MaxObjects", tempNumber));
#else
    OLECHECK(TInternalRegistrationHelpers::CreateRegKey(tempKey, TStringConverter<char>::AnsiToWide("MaxObjects"),
                                                        TStringConverter<char>::AnsiToWide(tempNumber)));
#endif
    memset(tempNumber, '\0', 33);
    itoa(Timeout, tempNumber, 10);
#if !defined(UNICODE) && !defined(_UNICODE)
    OLECHECK(TInternalRegistrationHelpers::CreateRegKey(tempKey, "Timeout", tempNumber));
#else
    OLECHECK(TInternalRegistrationHelpers::CreateRegKey(tempKey, TStringConverter<char>::AnsiToWide("Timeout"),
                                                        TStringConverter<char>::AnsiToWide(tempNumber)));
#endif
    if (Singleton) OLECHECK(TInternalRegistrationHelpers::CreateRegKey(tempKey, _T("Singleton"), _T("1")));
    else OLECHECK(TInternalRegistrationHelpers::CreateRegKey(tempKey, _T("Singleton"), _T("0")));
    delete[] tempKey;
    delete[] tempNumber;
  }
  catch (...)
  {
    if (tempKey) delete[] tempKey;
    if (tempNumber) delete[] tempNumber;
    return E_FAIL;
  }
  return S_OK;
}

HRESULT TRemoteDataModuleRegistrar::doUnRegister()
{
  TCHAR* pClassID = m_ClassIDstr;
  ICatRegister* CatReg = 0;
  TCHAR* RegKeyTemp = 0;
  CLSID MIDASTemp;
  GUID RemovalTemp;

  // Get a component category manager. */
  HRESULT hr = CoCreateInstance(CLSID_StdComponentCategoryMgr, 0,
                                CLSCTX_INPROC_SERVER, IID_ICatRegister,
                                (void**)&CatReg);

  try {
    if SUCCEEDED(hr)
    {
#if !defined(UNICODE) && !defined(_UNICODE)
      MIDASTemp = TStringConverter<char>::AnsiToGUID("{13E85B3C-9508-11D2-AB63-00C04FA35CFA}");
      RemovalTemp = TStringConverter<char>::AnsiToGUID(pClassID);
#else
      MIDASTemp = TStringConverter<char>::WideToGUID(_T("{13E85B3C-9508-11D2-AB63-00C04FA35CFA}"));
      RemovalTemp = TStringConverter<char>::WideToGUID(pClassID);
#endif
      hr  = CatReg->UnRegisterClassImplCategories(MIDASTemp, 1, &RemovalTemp);

      RegKeyTemp = TInternalRegistrationHelpers::CreateImplementedCategoriesOfClass(pClassID);
      RegDeleteKey(HKEY_CLASSES_ROOT, RegKeyTemp);
      delete[] RegKeyTemp;
    }
    else
    {
      RegKeyTemp = TInternalRegistrationHelpers::CreateImplementedMIDASOfClass(pClassID);
      RegDeleteKey(HKEY_CLASSES_ROOT, RegKeyTemp);
      delete[] RegKeyTemp;
    }
    RegKeyTemp = TInternalRegistrationHelpers::CreateAppIDOfClass(pClassID);
    RegDeleteKey(HKEY_CLASSES_ROOT, RegKeyTemp);
    delete[] RegKeyTemp;
    if (EnableSocket)
    {
      RegKeyTemp = TInternalRegistrationHelpers::CreateKeyOfClass(pClassID);
      TInternalRegistrationHelpers::DeleteRegValue(RegKeyTemp, _T("Sockets"));
      delete[] RegKeyTemp;
    }
    if (EnableWeb)
    {
      RegKeyTemp = TInternalRegistrationHelpers::CreateKeyOfClass(pClassID);
      TInternalRegistrationHelpers::DeleteRegValue(RegKeyTemp, _T("Web"));
      delete[] RegKeyTemp;
    }
  }
  catch (...) {
    // OLECHECK throws on failure
    if (CatReg)  CatReg->Release();
    if (RegKeyTemp)  delete[] RegKeyTemp;
    return E_FAIL;
  }
  if (RegisterPooled)
  {
    hr = doUnRegisterPooled();
    return hr;
  }
  else return S_OK;
}

HRESULT TRemoteDataModuleRegistrar::doRegister()
{
 TCHAR* pClassID = m_ClassIDstr;

  // Initialize these so they can be checked for deletion if someone throws
  ICatRegister* CatReg = 0;
  TCHAR* RegKeyTemp = 0;
  TCHAR* DescriptTemp = 0;
  TCHAR* AppTemp = 0;
  LPWSTR MidasStrTemp = 0;
  GUID tempGUID;

  // Get a component category manager. */
  HRESULT hr = CoCreateInstance(CLSID_StdComponentCategoryMgr, 0,
                                CLSCTX_INPROC_SERVER, IID_ICatRegister,
                                (void**)&CatReg);
  try {
    if SUCCEEDED(hr)
    {
      /* Build a Category Information structure for the MIDAS category */
      CATEGORYINFO CatInfo;
#if !defined(UNICODE) && !defined(_UNICODE)
      CatInfo.catid = TStringConverter<char>::AnsiToGUID("{13E85B3C-9508-11D2-AB63-00C04FA35CFA}"); /* do not localize */
#else
      CatInfo.catid = TStringConverter<char>::WideToGUID(_T("{13E85B3C-9508-11D2-AB63-00C04FA35CFA}")); /* do not localize */
#endif
      MidasStrTemp = TStringConverter<char>::AnsiToWide("Borland MIDAS Application Servers"); /* Do not localize */
      CatInfo.lcid = 0x409;

      wcscpy((wchar_t*)&CatInfo.szDescription, MidasStrTemp);
      delete[] MidasStrTemp;
      MidasStrTemp - 0;

      /* Register the category */
      OLECHECK(CatReg->RegisterCategories(1, &CatInfo));
#if !defined(UNICODE) && !defined(_UNICODE)
      tempGUID =TStringConverter<char>::AnsiToGUID("{13E85B3C-9508-11D2-AB63-00C04FA35CFA}");
      OLECHECK(CatReg->RegisterClassImplCategories( TStringConverter<char>::AnsiToGUID(pClassID), 1, &tempGUID));
#else
      tempGUID =TStringConverter<char>::WideToGUID(_T("{13E85B3C-9508-11D2-AB63-00C04FA35CFA}"));
      OLECHECK(CatReg->RegisterClassImplCategories( TStringConverter<char>::WideToGUID(pClassID), 1, &tempGUID));
#endif
      CatReg->Release();
    } else {
      /* For some reason there's no component categories manager available. oops,
         we'll have to do the equivalent */
      OLECHECK(TInternalRegistrationHelpers::CreateRegKey(_T("Component Categories\\{13E85B3C-9508-11D2-AB63-00C04FA35CFA}"), /* do not localize */
                            _T("409"), _T("Borland MIDAS Application Servers"))); /* do not localize */
      RegKeyTemp = TInternalRegistrationHelpers::CreateImplementedMIDASOfClass(pClassID);
      OLECHECK(TInternalRegistrationHelpers::CreateRegKey(RegKeyTemp, _T(""), _T("")));
      delete[] RegKeyTemp;
    }

    // Register the AppID and the ClassID
    RegKeyTemp = TInternalRegistrationHelpers::CreateKeyOfClass(pClassID);
#if !defined(UNICODE) && !defined(_UNICODE)
    DescriptTemp = TInternalRegistrationHelpers::GetRegStringValue(RegKeyTemp, _T(""));
#else
    DescriptTemp = TStringConverter<char>::AnsiToWide(TInternalRegistrationHelpers::GetRegStringValue(RegKeyTemp, _T("")));
#endif
    TInternalRegistrationHelpers::CreateRegKey(RegKeyTemp, _T("AppID"), pClassID);
    AppTemp = TInternalRegistrationHelpers::CreateAppIDOfClass(pClassID);
    TInternalRegistrationHelpers::CreateRegKey(AppTemp, _T(""), DescriptTemp);
    delete[] AppTemp;
    delete[] DescriptTemp;

    if (EnableSocket)
    {
      /* Add a special key just for sockets. */
      OLECHECK(TInternalRegistrationHelpers::CreateRegKey(RegKeyTemp, _T("Sockets"), _T("1")));
    }
    if (EnableWeb)
    {
      /* Add a special key just for web support. */
      OLECHECK(TInternalRegistrationHelpers::CreateRegKey(RegKeyTemp, _T("Web"), _T("1")));
    }
    delete[] RegKeyTemp;
  }
  catch (...)
  {
    /* OLECHECK throws on failure. */
    if (CatReg) CatReg->Release();
    if (RegKeyTemp) delete[] RegKeyTemp;
    if (DescriptTemp) delete[] DescriptTemp;
    if (AppTemp) delete[] AppTemp;
    if (MidasStrTemp) delete[] MidasStrTemp;
    return E_FAIL;
  }
  if (RegisterPooled)
  {
    hr = doRegisterPooled();
    return hr;
  }
  else return S_OK;
}

//----------------------------------------------------------------------------//
// Registers (or Unregisters) ActiveX Control
//
HRESULT TAxControlRegistrar::UpdateRegistry(bool Register)
{
  HRESULT hres;
  if (Register)
  {
    // Call base first when registering
    //
    hres = TTypedComServerRegistrar::UpdateRegistry(Register);
   
    // Make registry entries
    //
    TCHAR key[_MAX_PATH];
    lstrcpy(key, m_ClassKey);
    LPTSTR pinsert = key + lstrlen(key);

    lstrcpy(pinsert, _T("\\MiscStatus"));
    CreateRegKey(key, _T(""), _T("0"));

    TCHAR misc[16];
    wsprintf(misc, _T("%d"), m_MiscFlags);
    lstrcpy(pinsert, _T("\\MiscStatus\\1"));
    CreateRegKey(key, _T(""), misc);

    lstrcpy(pinsert, _T("\\ToolboxBitmap32"));
    TCHAR mod[_MAX_PATH + 8];
    wsprintf(mod, _T("%s,%d"), LPCTSTR(m_ModuleName), m_BitmapID);
    CreateRegKey(key, _T(""),  mod);

    lstrcpy(pinsert, _T("\\Control"));
    CreateRegKey(key,   _T(""), _T(""));

    lstrcpy(pinsert, _T("\\Verb"));
    CreateRegKey(key,   _T(""), _T(""));
   
    // Register Verbs
    //
    const OLEVERB *pVerb = m_Verbs;
    while (pVerb->lpszVerbName && *pVerb->lpszVerbName)
    {
      TCHAR szKey[_MAX_PATH];
      wsprintf(szKey, _T("%s\\Verb\\%d"), LPCTSTR(m_ClassKey), pVerb->lVerb);

      TCHAR szVerb[_MAX_PATH];
      wsprintf(szVerb, _T("%ls,%d,%d"), pVerb->lpszVerbName, pVerb->fuFlags, pVerb->grfAttribs);
    
      CreateRegKey(szKey, _T(""), szVerb);

      pVerb++;
    }
  }
  else
  {
    // Call base class to unregister
    // NOTE: Base class removes everything underneath \\CLSID\\<clsid> && \\<progid>\\
    //
    hres = TTypedComServerRegistrar::UpdateRegistry(Register);
  }
  return hres;
}

//-----------------------------------------------------------------------------//
#if defined(USING_VCL)
// AutomationTerminateProc (Backward compatiblity)
//
bool __fastcall AutomationTerminateProc()
{
  return TComModule::AutomationTerminateProc();
}
#endif

