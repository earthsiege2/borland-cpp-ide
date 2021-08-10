//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef ClientDataModuleUH
#define ClientDataModuleUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include "Customers_c.hh"
//---------------------------------------------------------------------------
class TClientDataModule : public TDataModule
{
__published:	// IDE-managed Components
  TClientDataSet *CustomerDataSet;
  TDataSource *CustomerDataSource;
private:	// User declarations
  CBuilder::Customers_ptr __fastcall GetAppServer();
  CBuilder::Customers_var FAppServer;
  void __fastcall SetAppServer(CBuilder::Customers_ptr _ptr);
  bool __fastcall GetConnected();
public:		// User declarations
  __fastcall TClientDataModule(TComponent* Owner);
  void __fastcall ApplyCustomerChanges();
  void __fastcall DiscardCustomerChanges();
  __property CBuilder::Customers_ptr AppServer = {read=GetAppServer, write=SetAppServer};
  __property bool Connected = {read=GetConnected};
  void __fastcall RefreshCustomer();
};
//---------------------------------------------------------------------------
extern PACKAGE TClientDataModule *ClientDataModule;
//---------------------------------------------------------------------------
#endif
