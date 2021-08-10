//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef DM1H
#define DM1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------

// Declare constants we're interested in.
//
const int eKeyViol = 9729;
const int eRequiredFieldMissing = 9732;
const int eForeignKey = 9733;
const int eDetailsExist = 9734;

class TDM : public TDataModule
{
__published:	// IDE-managed Components 
        TTable *Customer;
        TFloatField *CustomerCustNo;
        TStringField *CustomerCompany;
        TDataSource *CustomerSource;
        TTable *Orders;
        TFloatField *OrdersOrderNo;
        TFloatField *OrdersCustNo;
        TDateTimeField *OrdersSaleDate;
        TDateTimeField *OrdersShipDate;
        TIntegerField *OrdersEmpNo;
        TDataSource *OrdersSource;
        TTable *Items;
        TFloatField *ItemsOrderNo;
        TFloatField *ItemsItemNo;
        TFloatField *ItemsPartNo;
        TIntegerField *ItemsQty;
        TFloatField *ItemsDiscount;
        TDataSource *ItemsSource;
        void __fastcall CustomerPostError(TDataSet *DataSet,
           EDatabaseError *E, TDataAction &Action);
        void __fastcall CustomerDeleteError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action);
        void __fastcall CustomerCustNoChange(TField *Sender);
        void __fastcall CustomerAfterPost(TDataSet *DataSet);
        
        void __fastcall OrdersPostError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action);
        void __fastcall ItemsPostError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action);
        void __fastcall OrdersDeleteError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action);
private:	// User declarations
public:		// User declarations
        virtual __fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TDM *DM;
//---------------------------------------------------------------------------
#endif
