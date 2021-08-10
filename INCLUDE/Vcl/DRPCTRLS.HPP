// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DrpCtrls.pas' rev: 5.00

#ifndef DrpCtrlsHPP
#define DrpCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DsgnIntf.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
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
	Dsgnintf::_di_IFormDesigner FDesigner;
	void __fastcall AddComponent(const AnsiString ComponentName);
	
public:
	__fastcall TCandidateList(TMetaClass* CandidateClass, const Dsgnintf::_di_IFormDesigner Designer);
public:
		
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TCandidateList(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RegisterFieldControl(TMetaClass* FieldClass, const AnsiString ControlClass
	);
extern PACKAGE void __fastcall SetClassProp(System::TObject* Instance, const AnsiString PropName, TMetaClass* 
	ClassType, void * Value);
extern PACKAGE Db::TDataSource* __fastcall GetDataSource(const Dsgnintf::_di_IFormDesigner Designer, 
	Db::TDataSet* Dataset);
extern PACKAGE TMetaClass* __fastcall CreateControlClass(Db::TDataSet* Dataset, const AnsiString FieldName
	, AnsiString ControlClassName);
extern PACKAGE Controls::TControl* __fastcall CreateFieldControl(const Dsgnintf::_di_IFormDesigner Designer
	, Db::TField* Field, AnsiString ControlClassName, Classes::TComponent* Parent, int X, int Y, bool WithLabel
	);

}	/* namespace Drpctrls */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Drpctrls;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DrpCtrls
