// ************************************************************************ //
// SOAP Data Module: Interface [!InterfaceName]
// ************************************************************************ //
[!if=(CLX, "TRUE")]
#include <clx.h>
[!else]
#include <vcl.h>
[!endif]
#pragma hdrstop


#include <InvokeRegistry.hpp>
#include <Midas.hpp>
#include <SOAPMidas.hpp>
#include <SOAPDm.hpp>

#include "[!UnitIdent].h"

#pragma package(smart_init)
[!if=(CLX, "TRUE")]
#pragma resource "*.xfm"
[!else]
#pragma resource "*.dfm"
[!endif]


// ************************************************************************ //
// Methods of T[!InterfaceName] which implements interface I[!InterfaceName]
// ************************************************************************ //
__fastcall T[!InterfaceName]::T[!InterfaceName](TComponent* Owner) : TSoapDataModule(Owner)
{}


OleVariant __stdcall
T[!InterfaceName]::SAS_ApplyUpdates(const WideString ProviderName, const OleVariant Delta, int MaxErrors, /* out */ int &ErrorCount, OleVariant &OwnerData)
{
  return TSoapDataModule::SAS_ApplyUpdates(ProviderName, Delta, MaxErrors, ErrorCount, OwnerData);
}

OleVariant __stdcall
T[!InterfaceName]::SAS_GetRecords(const WideString ProviderName, int Count, /* out */ int &RecsOut, int Options, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData)
{
  return TSoapDataModule::SAS_GetRecords(ProviderName, Count, RecsOut, Options, CommandText, Params, OwnerData);
}

OleVariant __stdcall
T[!InterfaceName]::SAS_DataRequest(const WideString ProviderName, const OleVariant Data)
{
  return TSoapDataModule::SAS_DataRequest(ProviderName, Data);
}

TWideStringDynArray __stdcall
T[!InterfaceName]::SAS_GetProviderNames()
{
  return TSoapDataModule::SAS_GetProviderNames();
}

OleVariant __stdcall
T[!InterfaceName]::SAS_GetParams(const WideString ProviderName, OleVariant &OwnerData)
{
  return TSoapDataModule::SAS_GetParams(ProviderName, OwnerData);
}

OleVariant __stdcall
T[!InterfaceName]::SAS_RowRequest(const WideString ProviderName, const OleVariant Row, int RequestType, OleVariant &OwnerData)
{
  return TSoapDataModule::SAS_RowRequest(ProviderName, Row, RequestType, OwnerData);
}

void __stdcall
T[!InterfaceName]::SAS_Execute(const WideString ProviderName, const WideString CommandText, OleVariant &Params, OleVariant &OwnerData)
{
  TSoapDataModule::SAS_Execute(ProviderName, CommandText, Params, OwnerData);
}


// ************************************************************************ //
// This method will be called by SOAP to create objects to handle
// WebService requests.
// ************************************************************************ //
static void __fastcall [!InterfaceName]Factory(System::TObject* &obj)
{
  obj = new T[!InterfaceName](0);
}

// ***************************************************************************
// This routines registers the interface and implementation class that exposes
// the interface as a Web Service.
// ***************************************************************************
void static RegTypes()
{
  InvRegistry()->RegisterInterface(__interfaceTypeinfo(I[!InterfaceName]));
  InvRegistry()->RegisterInvokableClass(__classid(T[!InterfaceName]), [!InterfaceName]Factory);
}
#pragma startup RegTypes 32
