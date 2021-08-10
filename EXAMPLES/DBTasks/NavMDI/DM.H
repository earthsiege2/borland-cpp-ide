//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef DMH
#define DMH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TDM1 : public TDataModule
{
__published:    // IDE-managed Components 
    TTable *Customers;
    TTable *Orders;
    TDataSource *CustomersSource;
    TDataSource *OrdersSource;
private:        // User declarations
public:         // User declarations
    virtual __fastcall TDM1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TDM1 *DM1;
//---------------------------------------------------------------------------
#endif
