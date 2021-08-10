extern "C" int _export _stdcall getSQLDriverINTERBASE(
             char* pszVendorLib,
             char* pszResFile,
             void** ppDrv );


extern "C" HRESULT _export _stdcall DllGetDataSnapClassObject(REFCLSID rclsid, REFIID riid,
     void **ppv);

#pragma link "dbxdsnint.lib"
