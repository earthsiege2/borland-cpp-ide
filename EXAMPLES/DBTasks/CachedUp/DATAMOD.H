//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef datamodH
#define datamodH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBTables.hpp>
#include <Db.hpp>
//---------------------------------------------------------------------------
class TCacheData : public TDataModule
{
__published:    // IDE-managed Components 
    TDataSource *CacheDS;
    TDatabase *CacheDB;
    TQuery *CacheQuery;
    TStringField *CacheQueryPROJ_ID;
    TStringField *CacheQueryPROJ_NAME;
    TStringField *CacheQueryUpdateStatus;
    TUpdateSQL *UpdateSQL;
    void __fastcall CacheQueryCalcFields(TDataSet *DataSet);
    
    void __fastcall UpdateErrorHandler(TDataSet *DataSet,
      EDatabaseError *E, TUpdateKind UpdateKind,
      TUpdateAction &UpdateAction);
private:        // User declarations
public:         // User declarations
    virtual __fastcall TCacheData(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TCacheData *CacheData;
//---------------------------------------------------------------------------
#endif
