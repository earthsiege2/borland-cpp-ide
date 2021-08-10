//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// Simple EXE to load and run a DLL server
//----------------------------------------------------------------------------
#define STRICT
#include <windows.h>
#include <shellapi.h>
#include <ole2.h>
#include <winsys\registry.h>

#define _IFUNC  STDMETHODCALLTYPE
typedef HRESULT STDAPICALLTYPE (*TDllGetClassObject)(const GUID far& clsid,
                                                     const GUID far& iid,
                                                     void far* far* retObj);
class TDummy : public IUnknown {
  HRESULT _IFUNC QueryInterface(const GUID far& iid, void far* far* pif)
   {*pif = 0; return iid==IID_NULL ? NOERROR : ResultFromScode(E_NOINTERFACE);}
  unsigned long _IFUNC AddRef() {return 1;}
  unsigned long _IFUNC Release(){return 0;}
};

int PASCAL
WinMain(HINSTANCE/*hInst*/, HINSTANCE/*prev*/, char far* cmdLine, int/*show*/)
{
  char* error = 0;
  const int guidChars = 38;
  const int guidKeySize = sizeof("CLSID\\")-1;
  char guidBuf[guidKeySize + guidChars + 1] = "CLSID\\";
  const int pathSize = 260;
  char path[pathSize];
  long guidBufSize = guidChars + 1;
  long pathBufSize = pathSize;
  HKEY key;

  if (!cmdLine || !cmdLine[0]) {
    cmdLine = "Error";
    error = "Command line must have DLL ProgId";
  }
  else if (::RegOpenKey(TRegKey::ClassesRoot, cmdLine, &key) != S_OK) {
    error = "ProgId not found in Registry";
  }
  else {
    long rstat = ::RegQueryValue(key, "CLSID", guidBuf+guidKeySize, &guidBufSize);
	 ::RegCloseKey(key);
    if (rstat != S_OK ||
        ::RegOpenKey(TRegKey::ClassesRoot, guidBuf, &key) != S_OK) {
      error = "CLSID not found in Registry";
    }
    else {
      long rstat = ::RegQueryValue(key, "InprocServer", path, &pathBufSize);
    	 ::RegCloseKey(key);
      if (rstat != S_OK) {
        error = "No InprocServer specified in Registry";
      }
      else {
        ::OleInitialize(0);
        HINSTANCE hLib = ::LoadLibrary(path);
        if (hLib < HINSTANCE_ERROR) {
          error = "Could not load library";
        }
        else {
          TDllGetClassObject entry = (TDllGetClassObject)::GetProcAddress(hLib,
                                                           "DllGetClassObject");
          if (!entry) {
            error = "Could not find entry point";
          }
          else {
            IClassFactory* factory;
            GUID guid;
            ::CLSIDFromString(guidBuf+guidKeySize, &guid);
            HRESULT stat = (*entry)(guid, IID_IClassFactory,
                                    (void far*far*)&factory);
            if (stat) {
              error = "Could not obtain factory";
            }
            else {
              IUnknown* ifc;
              stat = factory->CreateInstance(&TDummy(), IID_IUnknown,
                                             (void far*far*)&ifc);
              factory->Release();
              if (stat) {
                error = "Could not create object";
              }
              else {
                long refs = ifc->Release();
                char buf[30];
                wsprintf(buf, "Reference count = %li", refs);
                if (refs != 0)
                  error = buf;
              }
            }
          }
          ::FreeLibrary(hLib);
        }
        ::OleUninitialize();
      }
    }
  }
  if (error)
    ::MessageBox(0, error, "DLLRUN - (c) Borland 1994, 1996", MB_OK);
  return error != 0;
}
