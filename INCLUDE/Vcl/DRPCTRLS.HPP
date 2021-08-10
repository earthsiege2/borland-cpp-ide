// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DrpCtrls.pas' rev: 6.00

#ifndef DrpCtrlsHPP
#define DrpCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DesignIntf.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Drpctrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCandidateList;
class PASCALIMPLEMENTATION TCandidateList : public Classes::TList 
{
	typedef Classes::TList inherited;
	
private:
	Designintf::_di_IDesigner FDesigner;
	void __fastcall AddComponent(const AnsiString ComponentName);
	
public:
	__fastcall TCandidateList(TMetaClass* CandidateClass, const Designintf::_di_IDesigner Designer);
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TCandidateList(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RegisterFieldControl(TMetaClass* FieldClass, const AnsiString ControlClass);
extern PACKAGE void __fastcall SetClassProp(System::TObject* Instance, const AnsiString PropName, TMetaClass* ClassType, void * Value);
extern PACKAGE Db::TDataSource* __fastcall GetDataSource(const Designintf::_di_IDesigner Designer, Db::TDataSet* Dataset);
extern PACKAGE TMetaClass* __fastcall CreateControlClass(Db::TDataSet* Dataset, const AnsiString FieldName, AnsiString ControlClassName);
extern PACKAGE Controls::TControl* __fastcall CreateFieldControl(const Designintf::_di_IDesigner Designer, Db::TField* Field, AnsiString ControlClassName, Classes::TComponent* Parent, int X, int Y, bool WithLabel);

}	/* namespace Drpctrls */
using namespace Drpctrls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DrpCtrls
