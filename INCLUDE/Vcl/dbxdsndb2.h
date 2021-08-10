extern "C" int _export _stdcall getSQLDriverDB2(
             char* pszVendorLib,
             char* pszResFile,
             void** ppDrv );


extern "C" HRESULT _export _stdcall DllGetDataSnapClassObject(REFCLSID rclsid, REFIID riid,
     void **ppv);

#pragma link "dbxdsndb2.lib"
