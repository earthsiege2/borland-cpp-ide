// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PropertyCategories.pas' rev: 6.00

#ifndef PropertyCategoriesHPP
#define PropertyCategoriesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <Masks.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Propertycategories
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPropertyFilter;
class PASCALIMPLEMENTATION TPropertyFilter : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Masks::TMask* FMask;
	TMetaClass*FComponentClass;
	Typinfo::TTypeInfo *FPropertyType;
	int FGroup;
	
public:
	__fastcall TPropertyFilter(const AnsiString APropertyName, TMetaClass* AComponentClass, Typinfo::PTypeInfo APropertyType);
	__fastcall virtual ~TPropertyFilter(void);
	bool __fastcall Match(const AnsiString APropertyName, TMetaClass* AComponentClass, Typinfo::PTypeInfo APropertyType);
	__property TMetaClass* ComponentClass = {read=FComponentClass};
	__property Typinfo::PTypeInfo PropertyType = {read=FPropertyType};
};


class DELPHICLASS TPropertyCategory;
class PASCALIMPLEMENTATION TPropertyCategory : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Contnrs::TObjectList* FList;
	int FMatchCount;
	Designeditors::TPropertyEditor* FEditor;
	bool FEnabled;
	bool FVisible;
	int FGroup;
	AnsiString FName;
	
protected:
	TPropertyFilter* __fastcall GetFilter(int Index);
	
public:
	__fastcall TPropertyCategory(const AnsiString AName);
	__fastcall virtual ~TPropertyCategory(void);
	TPropertyFilter* __fastcall Add(TPropertyFilter* AFilter);
	int __fastcall Count(void);
	bool __fastcall Match(const AnsiString APropertyName, TMetaClass* AComponentClass, Typinfo::PTypeInfo APropertyType);
	void __fastcall ClearMatches(void);
	void __fastcall FreeEditorGroup(int AGroup);
	__property TPropertyFilter* Filters[int Index] = {read=GetFilter};
	__property int MatchCount = {read=FMatchCount, nodefault};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
	__property Designeditors::TPropertyEditor* Editor = {read=FEditor, write=FEditor};
	__property AnsiString Name = {read=FName};
};


typedef TMetaClass*TPropertyCategoryClass;

#pragma option push -b-
enum TPropertyCategoryVisibleMode { pcvAll, pcvToggle, pcvNone, pcvNotListed, pcvOnlyListed };
#pragma option pop

class DELPHICLASS TPropertyCategoryList;
class PASCALIMPLEMENTATION TPropertyCategoryList : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	TPropertyCategory* operator[](int Index) { return Categories[Index]; }
	
private:
	Contnrs::TObjectList* FList;
	TPropertyCategory* FMiscCategory;
	
protected:
	TPropertyCategory* __fastcall GetCategory(int Index);
	AnsiString __fastcall GetHiddenCategories();
	void __fastcall SetHiddenCategories(const AnsiString Value);
	
public:
	__fastcall TPropertyCategoryList(void);
	__fastcall virtual ~TPropertyCategoryList(void);
	TPropertyCategory* __fastcall FindCategory(const AnsiString ACategoryName);
	int __fastcall IndexOf(const AnsiString ACategoryName);
	void __fastcall ClearMatches(void);
	void __fastcall FreeEditorGroup(int AGroup);
	TPropertyCategory* __fastcall MiscCategory(void);
	int __fastcall Count(void);
	bool __fastcall Match(const AnsiString APropertyName, TMetaClass* AComponentClass, Typinfo::PTypeInfo APropertyType = (void *)(0x0));
	bool __fastcall ChangeVisibility(TPropertyCategoryVisibleMode AMode)/* overload */;
	bool __fastcall ChangeVisibility(TPropertyCategoryVisibleMode AMode, const AnsiString * ANames, const int ANames_Size)/* overload */;
	__property AnsiString HiddenCategories = {read=GetHiddenCategories, write=SetHiddenCategories};
	__property TPropertyCategory* Categories[int Index] = {read=GetCategory/*, default*/};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IsPropertyInCategory(const AnsiString Category, TMetaClass* ComponentClass, const AnsiString PropertyName)/* overload */;
extern PACKAGE bool __fastcall IsPropertyInCategory(const AnsiString Category, const AnsiString ClassName, const AnsiString PropertyName)/* overload */;
extern PACKAGE TPropertyCategoryList* __fastcall PropertyCategoryList(void);

}	/* namespace Propertycategories */
using namespace Propertycategories;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PropertyCategories
