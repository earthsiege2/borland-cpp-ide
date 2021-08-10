//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef DmCSDemoHPP
#define DmCSDemoHPP
//---------------------------------------------------------------------------
#include <vcl.h>
#include <Classes.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#pragma hdrstop
//---------------------------------------------------------------------------
#ifndef WindowsHPP
#include <windows.hpp>
#endif

#ifndef MessagesHPP
#include <messages.hpp>
#endif

#ifndef SysUtilsHPP
#include <sysutils.hpp>
#endif

#ifndef ClassesHPP
#include <classes.hpp>
#endif

#ifndef GraphicsHPP
#include <graphics.hpp>
#endif

#ifndef ControlsHPP
#include <controls.hpp>
#endif

#ifndef FormsHPP
#include <forms.hpp>
#endif

#ifndef DialogsHPP
#include <dialogs.hpp>
#endif

#ifndef DBHPP
#include <db.hpp>
#endif

#ifndef DBTablesHPP
#include <dbtables.hpp>
#endif
//---------------------------------------------------------------------------
class TDmEmployee : public TDataModule
{
__published:
    TDatabase *EmployeeDatabase;
    TStoredProc *ShipOrderProc;
    TStoredProc *DeleteEmployeeProc;
    TTable *EmployeeLookup;
    TSmallintField *SmallintField1;
    TStringField *StringField1;
    TStringField *StringField2;
    TStringField *StringField3;
    TDateTimeField *DateTimeField1;
    TStringField *StringField4;
    TStringField *StringField5;
    TSmallintField *SmallintField2;
    TStringField *StringField6;
    TFloatField *FloatField1;
    TStringField *StringField7;
    TTable *SalesTable;
    TStringField *SalesTablePO_NUMBER;
    TIntegerField *SalesTableCUST_NO;
    TSmallintField *SalesTableSALES_REP;
    TStringField *SalesTableORDER_STATUS;
    TDateTimeField *SalesTableORDER_DATE;
    TDateTimeField *SalesTableSHIP_DATE;
    TDateTimeField *SalesTableDATE_NEEDED;
    TStringField *SalesTablePAID;
    TIntegerField *SalesTableQTY_ORDERED;
    TIntegerField *SalesTableTOTAL_VALUE;
    TFloatField *SalesTableDISCOUNT;
    TStringField *SalesTableITEM_TYPE;
    TFloatField *SalesTableAGED;
    TTable *CustomerTable;
    TIntegerField *CustomerTableCUST_NO;
    TStringField *CustomerTableCUSTOMER;
    TStringField *CustomerTableCONTACT_FIRST;
    TStringField *CustomerTableCONTACT_LAST;
    TStringField *CustomerTablePHONE_NO;
    TStringField *CustomerTableADDRESS_LINE1;
    TStringField *CustomerTableADDRESS_LINE2;
    TStringField *CustomerTableCITY;
    TStringField *CustomerTableSTATE_PROVINCE;
    TStringField *CustomerTableCOUNTRY;
    TStringField *CustomerTablePOSTAL_CODE;
    TStringField *CustomerTableON_HOLD;
    TTable *EmployeeTable;
    TSmallintField *EmployeeTableEMP_NO;
    TStringField *EmployeeTableFIRST_NAME;
    TStringField *EmployeeTableLAST_NAME;
    TStringField *EmployeeTablePHONE_EXT;
    TDateTimeField *EmployeeTableHIRE_DATE;
    TStringField *EmployeeTableDEPT_NO;
    TStringField *EmployeeTableJOB_CODE;
    TSmallintField *EmployeeTableJOB_GRADE;
    TStringField *EmployeeTableJOB_COUNTRY;
    TFloatField *EmployeeTableSALARY;
    TStringField *EmployeeTableFULL_NAME;
    TTable *SalaryHistoryTable;
    TStringField *SalaryHistoryTableEMPLOYEE;
    TSmallintField *SalaryHistoryTableEMP_NO;
    TDateTimeField *SalaryHistoryTableCHANGE_DATE;
    TStringField *SalaryHistoryTableUPDATER_ID;
    TFloatField *SalaryHistoryTableOLD_SALARY;
    TFloatField *SalaryHistoryTablePERCENT_CHANGE;
    TFloatField *SalaryHistoryTableNEW_SALARY;
    TDataSource *SalesSource;
    TDataSource *CustomerSource;
    TDataSource *EmployeeSource;
    TDataSource *SalaryHistorySource;
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TDmEmployee(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TDmEmployee *DmEmployee;
//---------------------------------------------------------------------------
#endif
