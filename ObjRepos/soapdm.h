// ************************************************************************ //
// SOAP Data Module: Interface [!InterfaceName]
// ************************************************************************ //

#ifndef  [!UnitIdent]H
#define  [!UnitIdent]H

#include <InvokeRegistry.hpp>
#include <Midas.hpp>
#include <SOAPMidas.hpp>
#include <SOAPDm.hpp>


// ************************************************************************ //
// This Interface will be exposed as a Web Service.
// As a DataModule, it inherits all of its signature from IAppServerSOAP.
// You don't need to add any methods to this interface to expose Data via
// SOAP. You can add methods if you want to expose this interface
// as a generic SOAP Service.
// ************************************************************************ //
__interface I[!InterfaceName] : public IAppServerSOAP
{
};
typedef DelphiInterface<I[!InterfaceName]> _di_I[!InterfaceName];


// ************************************************************************ //
// This class implements interface [!InterfaceName]
// ************************************************************************ //
class T[!InterfaceName] : public TSoapDataModule, public I[!InterfaceName], public IAppServerSOAP
{
__published:
private:
public:
  __fastcall T[!InterfaceName](TComponent* Owner);

  /* IAppServerSOAP */
  OleVariant __stdcall SAS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData);
  OleVariant __stdcall SAS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);
  OleVariant __stdcall SAS_DataRequest(const WideString ProviderName, const OleVariant Data);
  TWideStringDynArray __stdcall SAS_GetProviderNames();
  OleVariant __stdcall SAS_GetParams(const WideString ProviderName, OleVariant &OwnerData);
  OleVariant __stdcall SAS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType, OleVariant &OwnerData);
  void __stdcall SAS_Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData);


  /* IUnknown Methods */
  HRESULT       __stdcall QueryInterface(const GUID& IID, void **Obj) { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  unsigned long __stdcall AddRef()  { return TSoapDataModule::_AddRef(); }
  unsigned long __stdcall Release() { return TSoapDataModule::_Release();}

  /* To ensure that the class is not abstract */
  void checkValidClassImplementation() { delete new T[!InterfaceName](0); }
};

#endif  

