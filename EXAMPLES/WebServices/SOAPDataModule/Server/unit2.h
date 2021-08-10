// ************************************************************************ //
// SOAP Data Module: Interface BiolifeService
// ************************************************************************ //
#if !defined(__Unit2_H)
#define __Unit2_H

#include <InvokeRegistry.hpp>
#include <Midas.hpp>
#include <SOAPMidas.hpp>
#include <SOAPDm.hpp>
#include <Classes.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <Provider.hpp>


// ************************************************************************ //
// This Interface will be exposed as a Web Service.
// As a DataModule, it inherits all of its signature from IAppServerSOAP.
// You don't need to add any methods to this interface to expose Data via
// SOAP. You can add methods if you want to expose this interface
// as a generic SOAP Service.
// ************************************************************************ //
__interface IBiolifeService : public IAppServerSOAP
{
};
typedef DelphiInterface<IBiolifeService> _di_IBiolifeService;


// ************************************************************************ //
// This class implements interface BiolifeService
// ************************************************************************ //
class TBiolifeService : public TSoapDataModule //, public IBiolifeService, public IAppServerSOAP
{
__published:
        TDataSetProvider *DataSetProvider1;
        TClientDataSet *ClientDataSet1;
private:
public:
  __fastcall TBiolifeService(TComponent* Owner);

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
  void checkValidClassImplementation() { delete new TBiolifeService(0); }
};

#endif  //  __Unit2_H

