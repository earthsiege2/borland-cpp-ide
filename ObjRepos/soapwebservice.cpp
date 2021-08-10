[!outputon]
[!if=(Comments, "TRUE")]
// ************************************************************************ //
// Implementation class for interface I[!InterfaceName]
// ************************************************************************ //
[!endif]
[!if=(CLX, "TRUE")]
#include <clx.h>
[!else]
#include <vcl.h>
[!endif]
#pragma hdrstop

#if !defined([!IntfFileName]H)
#include "[!IntfFileName].h"
#endif

// ************************************************************************ //
//  [!ImplClassName] implements interface I[!InterfaceName]
// ************************************************************************ //
class [!ImplClassName] : public TInvokableClass, public I[!InterfaceName]
{
public:
[!if=(Samples, "TRUE")]
[!if=(Comments, "TRUE")]
    /* Sample methods of I[!InterfaceName] */
[!endif]
  SampleEnum     echoEnum(SampleEnum eValue);
  TDoubleArray   echoDoubleArray(const TDoubleArray daValue);
  TSampleStruct* echoStruct(const TSampleStruct* pStruct);
  double         echoDouble(double dValue);
[!endif]
[!if=(Comments, "TRUE")]

  /* IUnknown */
[!endif]
  HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& IID, void **Obj)
                        { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  ULONG STDMETHODCALLTYPE AddRef() { return TInterfacedObject::_AddRef();  }
  ULONG STDMETHODCALLTYPE Release(){ return TInterfacedObject::_Release(); }

[!if=(Comments, "TRUE")]
  /* Ensures that the class is not abstract */
[!endif]
  void checkValid() { delete new [!ImplClassName](); }
};

[!if=(Samples, "TRUE")]

SampleEnum [!ImplClassName]::echoEnum(SampleEnum eValue)
{
[!if=(Comments, "TRUE")]
  /* TODO : Implement method echoEnum */
[!endif]
  return eValue;
}

TDoubleArray [!ImplClassName]::echoDoubleArray(TDoubleArray daValue)
{
[!if=(Comments, "TRUE")]
  /* TODO : Implement method echoDoubleArray */
[!endif]
  return daValue;
}

TSampleStruct* [!ImplClassName]::echoStruct(const TSampleStruct* pEmployee)
{
[!if=(Comments, "TRUE")]
  /* TODO : Implement method echoMyEmployee */
[!endif]
  return new TSampleStruct();
}

double [!ImplClassName]::echoDouble(const double dValue)
{
[!if=(Comments, "TRUE")]
  /* TODO : Implement method echoDouble */
[!endif]
  return dValue;
}

[!endif]

[!if=(Activation, "GLOBAL")]
static void __fastcall [!InterfaceName]Factory(System::TObject* &obj)
{
  static _di_I[!InterfaceName] iInstance;
  static [!ImplClassName] *instance = 0;
  if (!instance)
  {
    instance = new [!ImplClassName]();
    instance->GetInterface(iInstance);
  }
  obj = instance;
}
[!endif]

[!if=(Comments, "TRUE")]
// ************************************************************************ //
//  The following routine registers the interface and implementation class.
// ************************************************************************ //
[!endif]
static void RegTypes()
{
  InvRegistry()->RegisterInterface(__interfaceTypeinfo(I[!InterfaceName]));
[!if=(Activation, "GLOBAL")]
  InvRegistry()->RegisterInvokableClass(__classid([!ImplClassName]), [!InterfaceName]Factory);
[!else]
  InvRegistry()->RegisterInvokableClass(__classid([!ImplClassName]));
[!endif]
}
#pragma startup RegTypes 32

