// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebScript_TLB.pas' rev: 6.00

#ifndef WebScript_TLBHPP
#define WebScript_TLBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webscript_tlb
{
//-- type declarations -------------------------------------------------------
__interface IAdapterErrorsWrapper;
typedef System::DelphiInterface<IAdapterErrorsWrapper> _di_IAdapterErrorsWrapper;
typedef IAdapterErrorsWrapper AdapterErrorsWrapper;
;

__interface IAdapterRecordsWrapper;
typedef System::DelphiInterface<IAdapterRecordsWrapper> _di_IAdapterRecordsWrapper;
typedef IAdapterRecordsWrapper AdapterRecordsWrapper;
;

__interface IAdapterFieldWrapper;
typedef System::DelphiInterface<IAdapterFieldWrapper> _di_IAdapterFieldWrapper;
typedef IAdapterFieldWrapper AdapterFieldWrapper;
;

__interface IAdapterActionWrapper;
typedef System::DelphiInterface<IAdapterActionWrapper> _di_IAdapterActionWrapper;
typedef IAdapterActionWrapper AdapterActionWrapper;
;

__interface IComponentsWrapper;
typedef System::DelphiInterface<IComponentsWrapper> _di_IComponentsWrapper;
typedef IComponentsWrapper ComponentsWrapper;
;

typedef IEnumVariant EnumVariantWrapper;
;

__interface IAdapterRecordWrapper;
typedef System::DelphiInterface<IAdapterRecordWrapper> _di_IAdapterRecordWrapper;
typedef IAdapterRecordWrapper AdapterRecordWrapper;
;

__interface IResponseWrapper;
typedef System::DelphiInterface<IResponseWrapper> _di_IResponseWrapper;
typedef IResponseWrapper ResponseWrapper;
;

__interface IHTMLItemsWrapper;
typedef System::DelphiInterface<IHTMLItemsWrapper> _di_IHTMLItemsWrapper;
typedef IHTMLItemsWrapper HTMLItemsWrapper;
;

__interface IPageWrapper;
typedef System::DelphiInterface<IPageWrapper> _di_IPageWrapper;
typedef IPageWrapper PageWrapper;
;

__interface IModuleWrapper;
typedef System::DelphiInterface<IModuleWrapper> _di_IModuleWrapper;
typedef IModuleWrapper ModuleWrapper;
;

__interface IModulesWrapper;
typedef System::DelphiInterface<IModulesWrapper> _di_IModulesWrapper;
typedef IModulesWrapper ModulesWrapper;
;

__interface IProducerWrapper;
typedef System::DelphiInterface<IProducerWrapper> _di_IProducerWrapper;
typedef IProducerWrapper ProducerWrapper;
;

__interface IAdapterErrorWrapper;
typedef System::DelphiInterface<IAdapterErrorWrapper> _di_IAdapterErrorWrapper;
typedef IAdapterErrorWrapper AdapterErrorWrapper;
;

__interface IPagesWrapper;
typedef System::DelphiInterface<IPagesWrapper> _di_IPagesWrapper;
typedef IPagesWrapper PagesWrapper;
;

__interface ISessionWrapper;
typedef System::DelphiInterface<ISessionWrapper> _di_ISessionWrapper;
typedef ISessionWrapper SessionWrapper;
;

__interface ISessionIDWrapper;
typedef System::DelphiInterface<ISessionIDWrapper> _di_ISessionIDWrapper;
typedef ISessionIDWrapper SessionIDWrapper;
;

__interface IEndUserWrapper;
typedef System::DelphiInterface<IEndUserWrapper> _di_IEndUserWrapper;
typedef IEndUserWrapper EndUserWrapper;
;

__interface IAdapterValuesListWrapper;
typedef System::DelphiInterface<IAdapterValuesListWrapper> _di_IAdapterValuesListWrapper;
typedef IAdapterValuesListWrapper AdapterValuesListWrapper;
;

__interface IAdapterWrapper;
typedef System::DelphiInterface<IAdapterWrapper> _di_IAdapterWrapper;
typedef IAdapterWrapper AdapterWrapper;
;

__interface IAdapterImageWrapper;
typedef System::DelphiInterface<IAdapterImageWrapper> _di_IAdapterImageWrapper;
typedef IAdapterImageWrapper AdapterImageWrapper;
;

__interface IApplicationWrapper;
typedef System::DelphiInterface<IApplicationWrapper> _di_IApplicationWrapper;
typedef IApplicationWrapper ApplicationWrapper;
;

__interface IAdapterFieldValuesWrapper;
typedef System::DelphiInterface<IAdapterFieldValuesWrapper> _di_IAdapterFieldValuesWrapper;
typedef IAdapterFieldValuesWrapper AdapterFieldValuesWrapper;
;

__interface IAdapterHiddenFieldsWrapper;
typedef System::DelphiInterface<IAdapterHiddenFieldsWrapper> _di_IAdapterHiddenFieldsWrapper;
typedef IAdapterHiddenFieldsWrapper AdapterHiddenFieldsWrapper;
;

__interface IAdapterHiddenFieldWrapper;
typedef System::DelphiInterface<IAdapterHiddenFieldWrapper> _di_IAdapterHiddenFieldWrapper;
typedef IAdapterHiddenFieldWrapper AdapterHiddenFieldWrapper;
;

__interface IAdapterActionArrayWrapper;
typedef System::DelphiInterface<IAdapterActionArrayWrapper> _di_IAdapterActionArrayWrapper;
typedef IAdapterActionArrayWrapper AdapterActionArrayWrapper;
;

__interface IRequestWrapper;
typedef System::DelphiInterface<IRequestWrapper> _di_IRequestWrapper;
typedef IRequestWrapper RequestWrapper;
;

__interface IImageProducerWrapper;
typedef System::DelphiInterface<IImageProducerWrapper> _di_IImageProducerWrapper;
typedef IImageProducerWrapper ImageProducerWrapper;
;

__interface IComponentWrapper;
typedef System::DelphiInterface<IComponentWrapper> _di_IComponentWrapper;
__interface INTERFACE_UUID("{B6A68CA7-ED7B-4983-902E-ABB3FB97416F}") IComponentWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Name_(WideString &Get_Name__result) = 0 ;
	virtual HRESULT __safecall Get_ClassName_(WideString &Get_ClassName__result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name_() { WideString r; HRESULT hr = Get_Name_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name_ = {read=_scw_Get_Name_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_ClassName_() { WideString r; HRESULT hr = Get_ClassName_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString ClassName_ = {read=_scw_Get_ClassName_};
};

__dispinterface IComponentWrapperDisp;
typedef System::DelphiInterface<IComponentWrapperDisp> _di_IComponentWrapperDisp;
__dispinterface INTERFACE_UUID("{B6A68CA7-ED7B-4983-902E-ABB3FB97416F}") IComponentWrapperDisp  : public IDispatch 
{
	
};

__interface IBaseAdapterWrapper;
typedef System::DelphiInterface<IBaseAdapterWrapper> _di_IBaseAdapterWrapper;
__interface INTERFACE_UUID("{CAC1644B-9BAD-11D4-A4F2-00C04F6BB853}") IBaseAdapterWrapper  : public IComponentWrapper 
{
	
public:
	virtual HRESULT __safecall Get_Fields(_di_IComponentsWrapper &Get_Fields_result) = 0 ;
	virtual HRESULT __safecall Get_Actions(_di_IComponentsWrapper &Get_Actions_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IComponentsWrapper _scw_Get_Fields() { _di_IComponentsWrapper r; HRESULT hr = Get_Fields(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IComponentsWrapper Fields = {read=_scw_Get_Fields};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IComponentsWrapper _scw_Get_Actions() { _di_IComponentsWrapper r; HRESULT hr = Get_Actions(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IComponentsWrapper Actions = {read=_scw_Get_Actions};
};

__dispinterface IBaseAdapterWrapperDisp;
typedef System::DelphiInterface<IBaseAdapterWrapperDisp> _di_IBaseAdapterWrapperDisp;
__dispinterface INTERFACE_UUID("{CAC1644B-9BAD-11D4-A4F2-00C04F6BB853}") IBaseAdapterWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{E08FAAAB-58DF-46F5-943B-FFCDC35076CC}") IComponentsWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result) = 0 ;
};

__dispinterface IComponentsWrapperDisp;
typedef System::DelphiInterface<IComponentsWrapperDisp> _di_IComponentsWrapperDisp;
__dispinterface INTERFACE_UUID("{E08FAAAB-58DF-46F5-943B-FFCDC35076CC}") IComponentsWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{57EAA08F-4A35-4903-B9AA-21A380F7F94B}") IAdapterErrorsWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result) = 0 ;
	virtual HRESULT __safecall DefineLabel(const System::_di_IInterface Object_, const WideString Value) = 0 ;
	virtual HRESULT __safecall FieldErrors(const System::_di_IInterface Object_, _di_IAdapterErrorsWrapper &FieldErrors_result) = 0 ;
};

__dispinterface IAdapterErrorsWrapperDisp;
typedef System::DelphiInterface<IAdapterErrorsWrapperDisp> _di_IAdapterErrorsWrapperDisp;
__dispinterface INTERFACE_UUID("{57EAA08F-4A35-4903-B9AA-21A380F7F94B}") IAdapterErrorsWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{04934843-5058-4B3F-87F6-B88C81392CF4}") IAdapterRecordsWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result) = 0 ;
};

__dispinterface IAdapterRecordsWrapperDisp;
typedef System::DelphiInterface<IAdapterRecordsWrapperDisp> _di_IAdapterRecordsWrapperDisp;
__dispinterface INTERFACE_UUID("{04934843-5058-4B3F-87F6-B88C81392CF4}") IAdapterRecordsWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{6C3ACA79-6314-11D4-A4A2-00C04F6BB853}") IAdapterFieldWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Value(OleVariant &Get_Value_result) = 0 ;
	virtual HRESULT __safecall Get_Name(OleVariant &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_DisplayText(WideString &Get_DisplayText_result) = 0 ;
	virtual HRESULT __safecall Get_EditText(WideString &Get_EditText_result) = 0 ;
	virtual HRESULT __safecall Get_InputName(WideString &Get_InputName_result) = 0 ;
	virtual HRESULT __safecall Get_DisplayWidth(int &Get_DisplayWidth_result) = 0 ;
	virtual HRESULT __safecall Get_DisplayLabel(WideString &Get_DisplayLabel_result) = 0 ;
	virtual HRESULT __safecall Get_ValuesList(_di_IAdapterValuesListWrapper &Get_ValuesList_result) = 0 ;
	virtual HRESULT __safecall Get_InputStyle(WideString &Get_InputStyle_result) = 0 ;
	virtual HRESULT __safecall Get_DisplayStyle(WideString &Get_DisplayStyle_result) = 0 ;
	virtual HRESULT __safecall Get_Image(_di_IAdapterImageWrapper &Get_Image_result) = 0 ;
	virtual HRESULT __safecall Get_CanModify(Word &Get_CanModify_result) = 0 ;
	virtual HRESULT __safecall Get_CanView(Word &Get_CanView_result) = 0 ;
	virtual HRESULT __safecall Get_Values(_di_IAdapterFieldValuesWrapper &Get_Values_result) = 0 ;
	virtual HRESULT __safecall IsEqual(const OleVariant Value, Word &IsEqual_result) = 0 ;
	virtual HRESULT __safecall Get_ViewMode(WideString &Get_ViewMode_result) = 0 ;
	virtual HRESULT __safecall Get_Required(Word &Get_Required_result) = 0 ;
	virtual HRESULT __safecall Get_Visible(Word &Get_Visible_result) = 0 ;
	virtual HRESULT __safecall Get_MaxLength(int &Get_MaxLength_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Value() { OleVariant r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Value = {read=_scw_Get_Value};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Name() { OleVariant r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayText() { WideString r; HRESULT hr = Get_DisplayText(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayText = {read=_scw_Get_DisplayText};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_EditText() { WideString r; HRESULT hr = Get_EditText(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString EditText = {read=_scw_Get_EditText};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_InputName() { WideString r; HRESULT hr = Get_InputName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString InputName = {read=_scw_Get_InputName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_DisplayWidth() { int r; HRESULT hr = Get_DisplayWidth(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int DisplayWidth = {read=_scw_Get_DisplayWidth};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayLabel() { WideString r; HRESULT hr = Get_DisplayLabel(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayLabel = {read=_scw_Get_DisplayLabel};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterValuesListWrapper _scw_Get_ValuesList() { _di_IAdapterValuesListWrapper r; HRESULT hr = Get_ValuesList(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterValuesListWrapper ValuesList = {read=_scw_Get_ValuesList};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_InputStyle() { WideString r; HRESULT hr = Get_InputStyle(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString InputStyle = {read=_scw_Get_InputStyle};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayStyle() { WideString r; HRESULT hr = Get_DisplayStyle(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayStyle = {read=_scw_Get_DisplayStyle};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterImageWrapper _scw_Get_Image() { _di_IAdapterImageWrapper r; HRESULT hr = Get_Image(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterImageWrapper Image = {read=_scw_Get_Image};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_CanModify() { Word r; HRESULT hr = Get_CanModify(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word CanModify = {read=_scw_Get_CanModify};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_CanView() { Word r; HRESULT hr = Get_CanView(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word CanView = {read=_scw_Get_CanView};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterFieldValuesWrapper _scw_Get_Values() { _di_IAdapterFieldValuesWrapper r; HRESULT hr = Get_Values(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterFieldValuesWrapper Values = {read=_scw_Get_Values};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_ViewMode() { WideString r; HRESULT hr = Get_ViewMode(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString ViewMode = {read=_scw_Get_ViewMode};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_Required() { Word r; HRESULT hr = Get_Required(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word Required = {read=_scw_Get_Required};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_Visible() { Word r; HRESULT hr = Get_Visible(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word Visible = {read=_scw_Get_Visible};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_MaxLength() { int r; HRESULT hr = Get_MaxLength(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int MaxLength = {read=_scw_Get_MaxLength};
};

__dispinterface IAdapterFieldWrapperDisp;
typedef System::DelphiInterface<IAdapterFieldWrapperDisp> _di_IAdapterFieldWrapperDisp;
__dispinterface INTERFACE_UUID("{6C3ACA79-6314-11D4-A4A2-00C04F6BB853}") IAdapterFieldWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{6C3ACA7D-6314-11D4-A4A2-00C04F6BB853}") IAdapterActionWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Name(OleVariant &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_AsFieldValue(WideString &Get_AsFieldValue_result) = 0 ;
	virtual HRESULT __safecall LinkToPage(const WideString PageSuccess, const WideString PageFail, _di_IAdapterActionWrapper &LinkToPage_result) = 0 ;
	virtual HRESULT __safecall Get_DisplayLabel(WideString &Get_DisplayLabel_result) = 0 ;
	virtual HRESULT __safecall Get_Enabled(Word &Get_Enabled_result) = 0 ;
	virtual HRESULT __safecall Get_AsHREF(WideString &Get_AsHREF_result) = 0 ;
	virtual HRESULT __safecall Get_CanExecute(Word &Get_CanExecute_result) = 0 ;
	virtual HRESULT __safecall Get_Visible(Word &Get_Visible_result) = 0 ;
	virtual HRESULT __safecall Get_Array_(_di_IAdapterActionArrayWrapper &Get_Array__result) = 0 ;
	virtual HRESULT __safecall Get_DisplayStyle(WideString &Get_DisplayStyle_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Name() { OleVariant r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_AsFieldValue() { WideString r; HRESULT hr = Get_AsFieldValue(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString AsFieldValue = {read=_scw_Get_AsFieldValue};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayLabel() { WideString r; HRESULT hr = Get_DisplayLabel(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayLabel = {read=_scw_Get_DisplayLabel};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_Enabled() { Word r; HRESULT hr = Get_Enabled(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word Enabled = {read=_scw_Get_Enabled};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_AsHREF() { WideString r; HRESULT hr = Get_AsHREF(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString AsHREF = {read=_scw_Get_AsHREF};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_CanExecute() { Word r; HRESULT hr = Get_CanExecute(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word CanExecute = {read=_scw_Get_CanExecute};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_Visible() { Word r; HRESULT hr = Get_Visible(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word Visible = {read=_scw_Get_Visible};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterActionArrayWrapper _scw_Get_Array_() { _di_IAdapterActionArrayWrapper r; HRESULT hr = Get_Array_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterActionArrayWrapper Array_ = {read=_scw_Get_Array_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayStyle() { WideString r; HRESULT hr = Get_DisplayStyle(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayStyle = {read=_scw_Get_DisplayStyle};
};

__dispinterface IAdapterActionWrapperDisp;
typedef System::DelphiInterface<IAdapterActionWrapperDisp> _di_IAdapterActionWrapperDisp;
__dispinterface INTERFACE_UUID("{6C3ACA7D-6314-11D4-A4A2-00C04F6BB853}") IAdapterActionWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{3A5B3303-6348-11D4-A4A2-00C04F6BB853}") IAdapterRecordWrapper  : public IBaseAdapterWrapper 
{
	
};

__dispinterface IAdapterRecordWrapperDisp;
typedef System::DelphiInterface<IAdapterRecordWrapperDisp> _di_IAdapterRecordWrapperDisp;
__dispinterface INTERFACE_UUID("{3A5B3303-6348-11D4-A4A2-00C04F6BB853}") IAdapterRecordWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{7E17379A-63D7-11D4-A4A3-00C04F6BB853}") IResponseWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Write(const OleVariant varText) = 0 ;
	virtual HRESULT __safecall Get_Content(WideString &Get_Content_result) = 0 ;
	virtual HRESULT __safecall Set_Content(const WideString Value) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Content() { WideString r; HRESULT hr = Get_Content(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Content = {read=_scw_Get_Content, write=Set_Content};
};

__dispinterface IResponseWrapperDisp;
typedef System::DelphiInterface<IResponseWrapperDisp> _di_IResponseWrapperDisp;
__dispinterface INTERFACE_UUID("{7E17379A-63D7-11D4-A4A3-00C04F6BB853}") IResponseWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{60409043-63F9-11D4-A4A3-00C04F6BB853}") IHTMLItemsWrapper  : public IDispatch 
{
	
public:
	OleVariant operator[](int Index) { return ControlDefault[Index]; }
	
public:
	virtual HRESULT __safecall Get_ControlDefault(int Index, OleVariant &Get_ControlDefault_result) = 0 ;
	virtual HRESULT __safecall Count(int &Count_result) = 0 ;
	virtual HRESULT __safecall Get_Item(int Index, WideString &Get_Item_result) = 0 ;
	virtual HRESULT __safecall WriteItem(int Index) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_ControlDefault(int Index) { OleVariant r; HRESULT hr = Get_ControlDefault(Index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant ControlDefault[int Index] = {read=_scw_Get_ControlDefault/*, default*/};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Item(int Index) { WideString r; HRESULT hr = Get_Item(Index, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Item[int Index] = {read=_scw_Get_Item};
};

__dispinterface IHTMLItemsWrapperDisp;
typedef System::DelphiInterface<IHTMLItemsWrapperDisp> _di_IHTMLItemsWrapperDisp;
__dispinterface INTERFACE_UUID("{60409043-63F9-11D4-A4A3-00C04F6BB853}") IHTMLItemsWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{4A5B2D80-64B3-11D4-A4A5-00C04F6BB853}") IPageWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_HREF(WideString &Get_HREF_result) = 0 ;
	virtual HRESULT __safecall Get_Title(WideString &Get_Title_result) = 0 ;
	virtual HRESULT __safecall Get_Description(WideString &Get_Description_result) = 0 ;
	virtual HRESULT __safecall Get_Published_(Word &Get_Published__result) = 0 ;
	virtual HRESULT __safecall Get_LoginRequired(Word &Get_LoginRequired_result) = 0 ;
	virtual HRESULT __safecall Get_CanView(Word &Get_CanView_result) = 0 ;
	virtual HRESULT __safecall Get_DefaultAction(_di_IAdapterActionWrapper &Get_DefaultAction_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_HREF() { WideString r; HRESULT hr = Get_HREF(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString HREF = {read=_scw_Get_HREF};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Title() { WideString r; HRESULT hr = Get_Title(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Title = {read=_scw_Get_Title};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Description() { WideString r; HRESULT hr = Get_Description(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Description = {read=_scw_Get_Description};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_Published_() { Word r; HRESULT hr = Get_Published_(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word Published_ = {read=_scw_Get_Published_};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_LoginRequired() { Word r; HRESULT hr = Get_LoginRequired(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word LoginRequired = {read=_scw_Get_LoginRequired};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_CanView() { Word r; HRESULT hr = Get_CanView(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word CanView = {read=_scw_Get_CanView};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterActionWrapper _scw_Get_DefaultAction() { _di_IAdapterActionWrapper r; HRESULT hr = Get_DefaultAction(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterActionWrapper DefaultAction = {read=_scw_Get_DefaultAction};
};

__dispinterface IPageWrapperDisp;
typedef System::DelphiInterface<IPageWrapperDisp> _di_IPageWrapperDisp;
__dispinterface INTERFACE_UUID("{4A5B2D80-64B3-11D4-A4A5-00C04F6BB853}") IPageWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{4A5B2D88-64B3-11D4-A4A5-00C04F6BB853}") IModuleWrapper  : public IComponentWrapper 
{
	
public:
	virtual HRESULT __safecall Get_Objects(_di_IComponentsWrapper &Get_Objects_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IComponentsWrapper _scw_Get_Objects() { _di_IComponentsWrapper r; HRESULT hr = Get_Objects(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IComponentsWrapper Objects = {read=_scw_Get_Objects};
};

__dispinterface IModuleWrapperDisp;
typedef System::DelphiInterface<IModuleWrapperDisp> _di_IModuleWrapperDisp;
__dispinterface INTERFACE_UUID("{4A5B2D88-64B3-11D4-A4A5-00C04F6BB853}") IModuleWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{4A5B2D92-64B3-11D4-A4A5-00C04F6BB853}") IModulesWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result) = 0 ;
};

__dispinterface IModulesWrapperDisp;
typedef System::DelphiInterface<IModulesWrapperDisp> _di_IModulesWrapperDisp;
__dispinterface INTERFACE_UUID("{4A5B2D92-64B3-11D4-A4A5-00C04F6BB853}") IModulesWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{FB0414F4-6702-11D4-A4A7-00C04F6BB853}") IProducerWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Write(const OleVariant varText) = 0 ;
	virtual HRESULT __safecall Get_Content(WideString &Get_Content_result) = 0 ;
	virtual HRESULT __safecall Set_Content(const WideString Value) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Content() { WideString r; HRESULT hr = Get_Content(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Content = {read=_scw_Get_Content, write=Set_Content};
};

__dispinterface IProducerWrapperDisp;
typedef System::DelphiInterface<IProducerWrapperDisp> _di_IProducerWrapperDisp;
__dispinterface INTERFACE_UUID("{FB0414F4-6702-11D4-A4A7-00C04F6BB853}") IProducerWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{A23C86B1-672A-11D4-A4A7-00C04F6BB853}") IAdapterErrorWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Message(WideString &Get_Message_result) = 0 ;
	virtual HRESULT __safecall Get_Field(_di_IDispatch &Get_Field_result) = 0 ;
	virtual HRESULT __safecall Get_ID(int &Get_ID_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Message() { WideString r; HRESULT hr = Get_Message(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Message = {read=_scw_Get_Message};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IDispatch _scw_Get_Field() { _di_IDispatch r; HRESULT hr = Get_Field(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IDispatch Field = {read=_scw_Get_Field};
	#pragma option push -w-inl
	/* safecall wrapper */ inline int _scw_Get_ID() { int r; HRESULT hr = Get_ID(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property int ID = {read=_scw_Get_ID};
};

__dispinterface IAdapterErrorWrapperDisp;
typedef System::DelphiInterface<IAdapterErrorWrapperDisp> _di_IAdapterErrorWrapperDisp;
__dispinterface INTERFACE_UUID("{A23C86B1-672A-11D4-A4A7-00C04F6BB853}") IAdapterErrorWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{1CFF50C8-6995-11D4-A4AA-00C04F6BB853}") IPagesWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result) = 0 ;
};

__dispinterface IPagesWrapperDisp;
typedef System::DelphiInterface<IPagesWrapperDisp> _di_IPagesWrapperDisp;
__dispinterface INTERFACE_UUID("{1CFF50C8-6995-11D4-A4AA-00C04F6BB853}") IPagesWrapperDisp  : public IDispatch 
{
	
};

__interface IBaseRecordsAdapterWrapper;
typedef System::DelphiInterface<IBaseRecordsAdapterWrapper> _di_IBaseRecordsAdapterWrapper;
__interface INTERFACE_UUID("{CAC1644F-9BAD-11D4-A4F2-00C04F6BB853}") IBaseRecordsAdapterWrapper  : public IBaseAdapterWrapper 
{
	
public:
	virtual HRESULT __safecall Get_Records(_di_IAdapterRecordsWrapper &Get_Records_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterRecordsWrapper _scw_Get_Records() { _di_IAdapterRecordsWrapper r; HRESULT hr = Get_Records(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterRecordsWrapper Records = {read=_scw_Get_Records};
};

__dispinterface IBaseRecordsAdapterWrapperDisp;
typedef System::DelphiInterface<IBaseRecordsAdapterWrapperDisp> _di_IBaseRecordsAdapterWrapperDisp;
__dispinterface INTERFACE_UUID("{CAC1644F-9BAD-11D4-A4F2-00C04F6BB853}") IBaseRecordsAdapterWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{06C1025C-0159-4AB6-B7DD-0843DDE856BE}") IAdapterWrapper  : public IBaseRecordsAdapterWrapper 
{
	
public:
	virtual HRESULT __safecall Get_Errors(_di_IAdapterErrorsWrapper &Get_Errors_result) = 0 ;
	virtual HRESULT __safecall Get_Mode(WideString &Get_Mode_result) = 0 ;
	virtual HRESULT __safecall Set_Mode(const WideString Value) = 0 ;
	virtual HRESULT __safecall Get_CanView(Word &Get_CanView_result) = 0 ;
	virtual HRESULT __safecall Get_CanModify(Word &Get_CanModify_result) = 0 ;
	virtual HRESULT __safecall Get_HiddenFields(_di_IAdapterHiddenFieldsWrapper &Get_HiddenFields_result) = 0 ;
	virtual HRESULT __safecall Get_HiddenRecordFields(_di_IAdapterHiddenFieldsWrapper &Get_HiddenRecordFields_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterErrorsWrapper _scw_Get_Errors() { _di_IAdapterErrorsWrapper r; HRESULT hr = Get_Errors(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterErrorsWrapper Errors = {read=_scw_Get_Errors};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Mode() { WideString r; HRESULT hr = Get_Mode(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Mode = {read=_scw_Get_Mode, write=Set_Mode};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_CanView() { Word r; HRESULT hr = Get_CanView(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word CanView = {read=_scw_Get_CanView};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_CanModify() { Word r; HRESULT hr = Get_CanModify(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word CanModify = {read=_scw_Get_CanModify};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterHiddenFieldsWrapper _scw_Get_HiddenFields() { _di_IAdapterHiddenFieldsWrapper r; HRESULT hr = Get_HiddenFields(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterHiddenFieldsWrapper HiddenFields = {read=_scw_Get_HiddenFields};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterHiddenFieldsWrapper _scw_Get_HiddenRecordFields() { _di_IAdapterHiddenFieldsWrapper r; HRESULT hr = Get_HiddenRecordFields(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterHiddenFieldsWrapper HiddenRecordFields = {read=_scw_Get_HiddenRecordFields};
};

__dispinterface IAdapterWrapperDisp;
typedef System::DelphiInterface<IAdapterWrapperDisp> _di_IAdapterWrapperDisp;
__dispinterface INTERFACE_UUID("{06C1025C-0159-4AB6-B7DD-0843DDE856BE}") IAdapterWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{E1773ECC-F9EB-4614-90D3-814B059678C6}") ISessionWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Values(const WideString Name, OleVariant &Get_Values_result) = 0 ;
	virtual HRESULT __safecall Get_SessionID(_di_ISessionIDWrapper &Get_SessionID_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Values(const WideString Name) { OleVariant r; HRESULT hr = Get_Values(Name, r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Values[WideString Name] = {read=_scw_Get_Values};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_ISessionIDWrapper _scw_Get_SessionID() { _di_ISessionIDWrapper r; HRESULT hr = Get_SessionID(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_ISessionIDWrapper SessionID = {read=_scw_Get_SessionID};
};

__dispinterface ISessionWrapperDisp;
typedef System::DelphiInterface<ISessionWrapperDisp> _di_ISessionWrapperDisp;
__dispinterface INTERFACE_UUID("{E1773ECC-F9EB-4614-90D3-814B059678C6}") ISessionWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{09480FAD-09F5-4425-9DFF-BD6FFB4257FE}") ISessionIDWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Value(WideString &Get_Value_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Value() { WideString r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Value = {read=_scw_Get_Value};
};

__dispinterface ISessionIDWrapperDisp;
typedef System::DelphiInterface<ISessionIDWrapperDisp> _di_ISessionIDWrapperDisp;
__dispinterface INTERFACE_UUID("{09480FAD-09F5-4425-9DFF-BD6FFB4257FE}") ISessionIDWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{845CF950-B95B-4411-9061-67FEE8E52E08}") IEndUserWrapper  : public IAdapterWrapper 
{
	
public:
	virtual HRESULT __safecall Get_DisplayName(WideString &Get_DisplayName_result) = 0 ;
	virtual HRESULT __safecall Get_LoggedIn(Word &Get_LoggedIn_result) = 0 ;
	virtual HRESULT __safecall Get_LoginFormAction(_di_IAdapterActionWrapper &Get_LoginFormAction_result) = 0 ;
	virtual HRESULT __safecall Get_LogoutAction(_di_IAdapterActionWrapper &Get_LogoutAction_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_DisplayName() { WideString r; HRESULT hr = Get_DisplayName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString DisplayName = {read=_scw_Get_DisplayName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_LoggedIn() { Word r; HRESULT hr = Get_LoggedIn(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word LoggedIn = {read=_scw_Get_LoggedIn};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterActionWrapper _scw_Get_LoginFormAction() { _di_IAdapterActionWrapper r; HRESULT hr = Get_LoginFormAction(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterActionWrapper LoginFormAction = {read=_scw_Get_LoginFormAction};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterActionWrapper _scw_Get_LogoutAction() { _di_IAdapterActionWrapper r; HRESULT hr = Get_LogoutAction(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterActionWrapper LogoutAction = {read=_scw_Get_LogoutAction};
};

__dispinterface IEndUserWrapperDisp;
typedef System::DelphiInterface<IEndUserWrapperDisp> _di_IEndUserWrapperDisp;
__dispinterface INTERFACE_UUID("{845CF950-B95B-4411-9061-67FEE8E52E08}") IEndUserWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{7895DB1B-01E5-4B6D-9017-5653A4BEA375}") IAdapterValuesListWrapper  : public IBaseRecordsAdapterWrapper 
{
	
public:
	virtual HRESULT __safecall Get_ValueName(WideString &Get_ValueName_result) = 0 ;
	virtual HRESULT __safecall Get_Value(OleVariant &Get_Value_result) = 0 ;
	virtual HRESULT __safecall NameOfValue(const OleVariant Value, WideString &NameOfValue_result) = 0 ;
	virtual HRESULT __safecall Get_Image(_di_IAdapterImageWrapper &Get_Image_result) = 0 ;
	virtual HRESULT __safecall ImageOfValue(const OleVariant Value, _di_IAdapterImageWrapper &ImageOfValue_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_ValueName() { WideString r; HRESULT hr = Get_ValueName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString ValueName = {read=_scw_Get_ValueName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Value() { OleVariant r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Value = {read=_scw_Get_Value};
	#pragma option push -w-inl
	/* safecall wrapper */ inline _di_IAdapterImageWrapper _scw_Get_Image() { _di_IAdapterImageWrapper r; HRESULT hr = Get_Image(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property _di_IAdapterImageWrapper Image = {read=_scw_Get_Image};
};

__dispinterface IAdapterValuesListWrapperDisp;
typedef System::DelphiInterface<IAdapterValuesListWrapperDisp> _di_IAdapterValuesListWrapperDisp;
__dispinterface INTERFACE_UUID("{7895DB1B-01E5-4B6D-9017-5653A4BEA375}") IAdapterValuesListWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{E086F82C-CAC2-48B1-AFCD-52022CB454C3}") IApplicationWrapper  : public IAdapterWrapper 
{
	
public:
	virtual HRESULT __safecall Get_Title(WideString &Get_Title_result) = 0 ;
	virtual HRESULT __safecall Get_Designing(Word &Get_Designing_result) = 0 ;
	virtual HRESULT __safecall QualifyFileName(const WideString FileName, WideString &QualifyFileName_result) = 0 ;
	virtual HRESULT __safecall Get_ModulePath(WideString &Get_ModulePath_result) = 0 ;
	virtual HRESULT __safecall Get_ModuleFileName(WideString &Get_ModuleFileName_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Title() { WideString r; HRESULT hr = Get_Title(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Title = {read=_scw_Get_Title};
	#pragma option push -w-inl
	/* safecall wrapper */ inline Word _scw_Get_Designing() { Word r; HRESULT hr = Get_Designing(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property Word Designing = {read=_scw_Get_Designing};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_ModulePath() { WideString r; HRESULT hr = Get_ModulePath(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString ModulePath = {read=_scw_Get_ModulePath};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_ModuleFileName() { WideString r; HRESULT hr = Get_ModuleFileName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString ModuleFileName = {read=_scw_Get_ModuleFileName};
};

__dispinterface IApplicationWrapperDisp;
typedef System::DelphiInterface<IApplicationWrapperDisp> _di_IApplicationWrapperDisp;
__dispinterface INTERFACE_UUID("{E086F82C-CAC2-48B1-AFCD-52022CB454C3}") IApplicationWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{F2AF207A-A097-11D4-A4F7-00C04F6BB853}") IAdapterImageWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_AsHREF(WideString &Get_AsHREF_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_AsHREF() { WideString r; HRESULT hr = Get_AsHREF(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString AsHREF = {read=_scw_Get_AsHREF};
};

__dispinterface IAdapterImageWrapperDisp;
typedef System::DelphiInterface<IAdapterImageWrapperDisp> _di_IAdapterImageWrapperDisp;
__dispinterface INTERFACE_UUID("{F2AF207A-A097-11D4-A4F7-00C04F6BB853}") IAdapterImageWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{7024ECA0-35B5-491B-9AB2-743DDDB0ECDC}") IAdapterFieldValuesWrapper  : public IBaseRecordsAdapterWrapper 
{
	
public:
	virtual HRESULT __safecall HasValue(const OleVariant Value, Word &HasValue_result) = 0 ;
	virtual HRESULT __safecall Get_Value(OleVariant &Get_Value_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline OleVariant _scw_Get_Value() { OleVariant r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property OleVariant Value = {read=_scw_Get_Value};
};

__dispinterface IAdapterFieldValuesWrapperDisp;
typedef System::DelphiInterface<IAdapterFieldValuesWrapperDisp> _di_IAdapterFieldValuesWrapperDisp;
__dispinterface INTERFACE_UUID("{7024ECA0-35B5-491B-9AB2-743DDDB0ECDC}") IAdapterFieldValuesWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{B015307D-D096-11D4-A530-00C04F6BB853}") IAdapterHiddenFieldsWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result) = 0 ;
	virtual HRESULT __safecall WriteFields(const _di_IDispatch Response) = 0 ;
};

__dispinterface IAdapterHiddenFieldsWrapperDisp;
typedef System::DelphiInterface<IAdapterHiddenFieldsWrapperDisp> _di_IAdapterHiddenFieldsWrapperDisp;
__dispinterface INTERFACE_UUID("{B015307D-D096-11D4-A530-00C04F6BB853}") IAdapterHiddenFieldsWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{B0153081-D096-11D4-A530-00C04F6BB853}") IAdapterHiddenFieldWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_Name(WideString &Get_Name_result) = 0 ;
	virtual HRESULT __safecall Get_Value(WideString &Get_Value_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Name() { WideString r; HRESULT hr = Get_Name(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Name = {read=_scw_Get_Name};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Value() { WideString r; HRESULT hr = Get_Value(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Value = {read=_scw_Get_Value};
};

__dispinterface IAdapterHiddenFieldWrapperDisp;
typedef System::DelphiInterface<IAdapterHiddenFieldWrapperDisp> _di_IAdapterHiddenFieldWrapperDisp;
__dispinterface INTERFACE_UUID("{B0153081-D096-11D4-A530-00C04F6BB853}") IAdapterHiddenFieldWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{77561E9B-3754-4552-88CA-13AD02C495E2}") IAdapterActionArrayWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_NewEnum(System::_di_IInterface &Get_NewEnum_result) = 0 ;
};

__dispinterface IAdapterActionArrayWrapperDisp;
typedef System::DelphiInterface<IAdapterActionArrayWrapperDisp> _di_IAdapterActionArrayWrapperDisp;
__dispinterface INTERFACE_UUID("{77561E9B-3754-4552-88CA-13AD02C495E2}") IAdapterActionArrayWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{0546F350-4388-40ED-97D7-914CB61B48BD}") IRequestWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall Get_PathInfo(WideString &Get_PathInfo_result) = 0 ;
	virtual HRESULT __safecall Get_ScriptName(WideString &Get_ScriptName_result) = 0 ;
	virtual HRESULT __safecall Get_Host(WideString &Get_Host_result) = 0 ;
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_PathInfo() { WideString r; HRESULT hr = Get_PathInfo(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString PathInfo = {read=_scw_Get_PathInfo};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_ScriptName() { WideString r; HRESULT hr = Get_ScriptName(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString ScriptName = {read=_scw_Get_ScriptName};
	#pragma option push -w-inl
	/* safecall wrapper */ inline WideString _scw_Get_Host() { WideString r; HRESULT hr = Get_Host(r); System::CheckSafecallResult(hr); return r; }
	#pragma option pop
	__property WideString Host = {read=_scw_Get_Host};
};

__dispinterface IRequestWrapperDisp;
typedef System::DelphiInterface<IRequestWrapperDisp> _di_IRequestWrapperDisp;
__dispinterface INTERFACE_UUID("{0546F350-4388-40ED-97D7-914CB61B48BD}") IRequestWrapperDisp  : public IDispatch 
{
	
};

__interface INTERFACE_UUID("{128B1043-EF0A-4D1F-A9F7-84C2B5EB96C8}") IImageProducerWrapper  : public IDispatch 
{
	
public:
	virtual HRESULT __safecall GetImage(const System::_di_IInterface Object_, const WideString Caption, _di_IAdapterImageWrapper &GetImage_result) = 0 ;
	virtual HRESULT __safecall GetEventImage(const System::_di_IInterface Object_, const WideString Event, const WideString Caption, _di_IAdapterImageWrapper &GetEventImage_result) = 0 ;
	virtual HRESULT __safecall GetDisplayStyle(const System::_di_IInterface Object_, WideString &GetDisplayStyle_result) = 0 ;
};

__dispinterface IImageProducerWrapperDisp;
typedef System::DelphiInterface<IImageProducerWrapperDisp> _di_IImageProducerWrapperDisp;
__dispinterface INTERFACE_UUID("{128B1043-EF0A-4D1F-A9F7-84C2B5EB96C8}") IImageProducerWrapperDisp  : public IDispatch 
{
	
};

class DELPHICLASS CoAdapterErrorsWrapper;
class PASCALIMPLEMENTATION CoAdapterErrorsWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterErrorsWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterErrorsWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterErrorsWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterErrorsWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterRecordsWrapper;
class PASCALIMPLEMENTATION CoAdapterRecordsWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterRecordsWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterRecordsWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterRecordsWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterRecordsWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterFieldWrapper;
class PASCALIMPLEMENTATION CoAdapterFieldWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterFieldWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterFieldWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterFieldWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterFieldWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterActionWrapper;
class PASCALIMPLEMENTATION CoAdapterActionWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterActionWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterActionWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterActionWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterActionWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoComponentsWrapper;
class PASCALIMPLEMENTATION CoComponentsWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IComponentsWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IComponentsWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoComponentsWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoComponentsWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoEnumVariantWrapper;
class PASCALIMPLEMENTATION CoEnumVariantWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IEnumVariant __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IEnumVariant __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoEnumVariantWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoEnumVariantWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterRecordWrapper;
class PASCALIMPLEMENTATION CoAdapterRecordWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterRecordWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterRecordWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterRecordWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterRecordWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoResponseWrapper;
class PASCALIMPLEMENTATION CoResponseWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IResponseWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IResponseWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoResponseWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoResponseWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoHTMLItemsWrapper;
class PASCALIMPLEMENTATION CoHTMLItemsWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IHTMLItemsWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IHTMLItemsWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoHTMLItemsWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoHTMLItemsWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoPageWrapper;
class PASCALIMPLEMENTATION CoPageWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IPageWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IPageWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoPageWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoPageWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoModuleWrapper;
class PASCALIMPLEMENTATION CoModuleWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IModuleWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IModuleWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoModuleWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoModuleWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoModulesWrapper;
class PASCALIMPLEMENTATION CoModulesWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IModulesWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IModulesWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoModulesWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoModulesWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoProducerWrapper;
class PASCALIMPLEMENTATION CoProducerWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IProducerWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IProducerWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoProducerWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoProducerWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterErrorWrapper;
class PASCALIMPLEMENTATION CoAdapterErrorWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterErrorWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterErrorWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterErrorWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterErrorWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoPagesWrapper;
class PASCALIMPLEMENTATION CoPagesWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IPagesWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IPagesWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoPagesWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoPagesWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoSessionWrapper;
class PASCALIMPLEMENTATION CoSessionWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_ISessionWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_ISessionWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoSessionWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoSessionWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoSessionIDWrapper;
class PASCALIMPLEMENTATION CoSessionIDWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_ISessionIDWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_ISessionIDWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoSessionIDWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoSessionIDWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoEndUserWrapper;
class PASCALIMPLEMENTATION CoEndUserWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IEndUserWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IEndUserWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoEndUserWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoEndUserWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterValuesListWrapper;
class PASCALIMPLEMENTATION CoAdapterValuesListWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterValuesListWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterValuesListWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterValuesListWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterValuesListWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterWrapper;
class PASCALIMPLEMENTATION CoAdapterWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterImageWrapper;
class PASCALIMPLEMENTATION CoAdapterImageWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterImageWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterImageWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterImageWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterImageWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoApplicationWrapper;
class PASCALIMPLEMENTATION CoApplicationWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IApplicationWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IApplicationWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoApplicationWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoApplicationWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterFieldValuesWrapper;
class PASCALIMPLEMENTATION CoAdapterFieldValuesWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterFieldValuesWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterFieldValuesWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterFieldValuesWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterFieldValuesWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterHiddenFieldsWrapper;
class PASCALIMPLEMENTATION CoAdapterHiddenFieldsWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterHiddenFieldsWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterHiddenFieldsWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterHiddenFieldsWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterHiddenFieldsWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterHiddenFieldWrapper;
class PASCALIMPLEMENTATION CoAdapterHiddenFieldWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterHiddenFieldWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterHiddenFieldWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterHiddenFieldWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterHiddenFieldWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoAdapterActionArrayWrapper;
class PASCALIMPLEMENTATION CoAdapterActionArrayWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IAdapterActionArrayWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IAdapterActionArrayWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoAdapterActionArrayWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoAdapterActionArrayWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoRequestWrapper;
class PASCALIMPLEMENTATION CoRequestWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IRequestWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IRequestWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoRequestWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoRequestWrapper(void) { }
	#pragma option pop
	
};


class DELPHICLASS CoImageProducerWrapper;
class PASCALIMPLEMENTATION CoImageProducerWrapper : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	/*         class method */ static _di_IImageProducerWrapper __fastcall Create(TMetaClass* vmt);
	/*         class method */ static _di_IImageProducerWrapper __fastcall CreateRemote(TMetaClass* vmt, const AnsiString MachineName);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall CoImageProducerWrapper(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~CoImageProducerWrapper(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint WebScriptMajorVersion = 0x1;
static const Shortint WebScriptMinorVersion = 0x0;
extern PACKAGE GUID LIBID_WebScript;
extern PACKAGE GUID IID_IComponentWrapper;
extern PACKAGE GUID IID_IBaseAdapterWrapper;
extern PACKAGE GUID IID_IComponentsWrapper;
extern PACKAGE GUID IID_IAdapterErrorsWrapper;
extern PACKAGE GUID CLASS_AdapterErrorsWrapper;
extern PACKAGE GUID IID_IAdapterRecordsWrapper;
extern PACKAGE GUID CLASS_AdapterRecordsWrapper;
extern PACKAGE GUID IID_IAdapterFieldWrapper;
extern PACKAGE GUID CLASS_AdapterFieldWrapper;
extern PACKAGE GUID IID_IAdapterActionWrapper;
extern PACKAGE GUID CLASS_AdapterActionWrapper;
extern PACKAGE GUID CLASS_ComponentsWrapper;
extern PACKAGE GUID CLASS_EnumVariantWrapper;
extern PACKAGE GUID IID_IAdapterRecordWrapper;
extern PACKAGE GUID CLASS_AdapterRecordWrapper;
extern PACKAGE GUID IID_IResponseWrapper;
extern PACKAGE GUID CLASS_ResponseWrapper;
extern PACKAGE GUID IID_IHTMLItemsWrapper;
extern PACKAGE GUID CLASS_HTMLItemsWrapper;
extern PACKAGE GUID IID_IPageWrapper;
extern PACKAGE GUID CLASS_PageWrapper;
extern PACKAGE GUID IID_IModuleWrapper;
extern PACKAGE GUID CLASS_ModuleWrapper;
extern PACKAGE GUID IID_IModulesWrapper;
extern PACKAGE GUID CLASS_ModulesWrapper;
extern PACKAGE GUID IID_IProducerWrapper;
extern PACKAGE GUID CLASS_ProducerWrapper;
extern PACKAGE GUID IID_IAdapterErrorWrapper;
extern PACKAGE GUID CLASS_AdapterErrorWrapper;
extern PACKAGE GUID IID_IPagesWrapper;
extern PACKAGE GUID CLASS_PagesWrapper;
extern PACKAGE GUID IID_IBaseRecordsAdapterWrapper;
extern PACKAGE GUID IID_IAdapterWrapper;
extern PACKAGE GUID IID_ISessionWrapper;
extern PACKAGE GUID CLASS_SessionWrapper;
extern PACKAGE GUID IID_ISessionIDWrapper;
extern PACKAGE GUID CLASS_SessionIDWrapper;
extern PACKAGE GUID IID_IEndUserWrapper;
extern PACKAGE GUID CLASS_EndUserWrapper;
extern PACKAGE GUID IID_IAdapterValuesListWrapper;
extern PACKAGE GUID CLASS_AdapterValuesListWrapper;
extern PACKAGE GUID CLASS_AdapterWrapper;
extern PACKAGE GUID IID_IApplicationWrapper;
extern PACKAGE GUID IID_IAdapterImageWrapper;
extern PACKAGE GUID CLASS_AdapterImageWrapper;
extern PACKAGE GUID CLASS_ApplicationWrapper;
extern PACKAGE GUID IID_IAdapterFieldValuesWrapper;
extern PACKAGE GUID CLASS_AdapterFieldValuesWrapper;
extern PACKAGE GUID IID_IAdapterHiddenFieldsWrapper;
extern PACKAGE GUID CLASS_AdapterHiddenFieldsWrapper;
extern PACKAGE GUID IID_IAdapterHiddenFieldWrapper;
extern PACKAGE GUID CLASS_AdapterHiddenFieldWrapper;
extern PACKAGE GUID IID_IAdapterActionArrayWrapper;
extern PACKAGE GUID CLASS_AdapterActionArrayWrapper;
extern PACKAGE GUID IID_IRequestWrapper;
extern PACKAGE GUID CLASS_RequestWrapper;
extern PACKAGE GUID IID_IImageProducerWrapper;
extern PACKAGE GUID CLASS_ImageProducerWrapper;

}	/* namespace Webscript_tlb */
using namespace Webscript_tlb;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebScript_TLB
