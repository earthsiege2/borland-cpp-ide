// ************************************************************************ //
// SOAP Data Module: Interface BiolifeService
// ************************************************************************ //
#include <vcl.h>
#pragma hdrstop

#include <InvokeRegistry.hpp>
#include <Midas.hpp>
#include <SOAPMidas.hpp>
#include <SOAPDm.hpp>

#include "Unit2.h"

#pragma package(smart_init)
#pragma resource "*.dfm"


// ************************************************************************ //
// Methods of TBiolifeService which implements interface IBiolifeService
// ************************************************************************ //
__fastcall TBiolifeService::TBiolifeService(TComponent* Owner) : TSoapDataModule(Owner)
{}


OleVariant __stdcall
TBiolifeService::SAS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData)
{
  return TSoapDataModule::SAS_ApplyUpdates(ProviderName, Delta, MaxErrors, ErrorCount, OwnerData);
}

OleVariant __stdcall
TBiolifeService::SAS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData)
{
  return TSoapDataModule::SAS_GetRecords(ProviderName, Count, RecsOut, Options, CommandText, Params, OwnerData);
}

OleVariant __stdcall
TBiolifeService::SAS_DataRequest(const WideString ProviderName, const OleVariant Data)
{
  return TSoapDataModule::SAS_DataRequest(ProviderName, Data);
}

TWideStringDynArray __stdcall
TBiolifeService::SAS_GetProviderNames()
{
  return TSoapDataModule::SAS_GetProviderNames();
}

OleVariant __stdcall
TBiolifeService::SAS_GetParams(const WideString ProviderName, OleVariant &OwnerData)
{
  return TSoapDataModule::SAS_GetParams(ProviderName, OwnerData);
}

OleVariant __stdcall
TBiolifeService::SAS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType, OleVariant &OwnerData)
{
  return TSoapDataModule::SAS_RowRequest(ProviderName, Row, RequestType, OwnerData);
}

void __stdcall
TBiolifeService::SAS_Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData)
{
  TSoapDataModule::SAS_Execute(ProviderName, CommandText, Params, OwnerData);
}


// ************************************************************************ //
// This method will be called by SOAP to create objects to handle
// WebService requests.
// ************************************************************************ //
static void __fastcall BiolifeServiceFactory(System::TObject* &obj)
{
  obj = new TBiolifeService(0);
}

// ***************************************************************************
// This routines registers the interface and implementation class that exposes
// the interface as a Web Service.
// ***************************************************************************
void static RegTypes()
{
  InvRegistry()->RegisterInterface(__interfaceTypeinfo(IBiolifeService));
  InvRegistry()->RegisterInvokableClass(__classid(TBiolifeService), BiolifeServiceFactory);
  RegDefIAppServerInvClass();
}
#pragma startup RegTypes 32


