//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef DataModH
#define DataModH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include "customdm.h"
//---------------------------------------------------------------------------
class TData : public TCustomerData
{
__published:
    void __fastcall OrdersFilterRecord(TDataSet *DataSet, bool &Accept);
    void __fastcall CustomersFilterRecord(TDataSet *DataSet,
      bool &Accept);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TData(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TData *Data;
//---------------------------------------------------------------------------
#endif
