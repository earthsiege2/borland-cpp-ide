//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef DMHPP
#define DMHPP
//----------------------------------------------------------------------------
#ifndef DBTablesHPP
#include <DBTables.hpp>
#include <DB.hpp>
#include <Classes.hpp>
#include <Db.hpp>
#endif

#ifndef DBHPP
#include <DB.hpp>
#endif

#ifndef DialogsHPP
#include <Dialogs.hpp>
#endif

#ifndef FormsHPP
#include <Forms.hpp>
#endif

#ifndef ControlsHPP
#include <Controls.hpp>
#endif

#ifndef GraphicsHPP
#include <Graphics.hpp>
#endif

#ifndef ClassesHPP
#include <Classes.hpp>
#endif

#ifndef SysUtilsHPP
#include <SysUtils.hpp>
#endif

#ifndef MessagesHPP
#include <Messages.hpp>
#endif

#ifndef WindowsHPP
#include <Windows.hpp>
#endif

#ifndef SystemHPP
#include <System.hpp>
#endif

//-- type declarations -------------------------------------------------------
class __declspec(delphiclass) TDM1;
class TDM1 : public TDataModule
{
	typedef TDM1 ThisClass;
	typedef TDataModule inherited;
	
__published:
	TTable *Customer;
	TDataSource *CustomerSource;
	TQuery *SQLCustomer;
	TQuery *SQLOrders;
	TDataSource *OrdersSource;
	TFloatField *SQLOrdersOrderNo;
	TFloatField *SQLOrdersCustno;
	TDateTimeField *SQLOrdersSaleDate;
	TDateTimeField *SQLOrdersShipDate;
	TIntegerField *SQLOrdersEmpNo;
	TCurrencyField *SQLOrdersAmountPaid;
	void __fastcall DM1Create(TObject *Sender);
	void __fastcall SQLOrdersFilterRecord(TDataSet *DataSet, bool &Accept);
	
public:
	Extended OrdersFilterAmount;

	__fastcall virtual TDM1(TComponent *);
};

//-- var, const, procedure ---------------------------------------------------
extern TDM1 *DM1;
//-- end unit ----------------------------------------------------------------
#endif	// DM
