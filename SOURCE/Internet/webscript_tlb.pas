unit WebScript_TLB;

// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// PASTLWTR : $Revision:   1.32  $
// File generated on 5/16/2001 7:00:58 AM from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\tp\internet\WebBrokerScript.tlb (1)
// LIBID: {7E17379F-63D7-11D4-A4A3-00C04F6BB853}
// LCID: 0
// Helpfile: 
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v4.0 StdVCL, (C:\WINNT\System32\STDVCL40.DLL)
// ************************************************************************ //
{$TYPEDADDRESS OFF} // Unit must be compiled without type-checked pointers. 
{$WARN SYMBOL_PLATFORM OFF}
{$WRITEABLECONST ON}

interface

uses ActiveX, Classes, Graphics, StdVCL, Variants, Windows;
  

// *********************************************************************//
// GUIDS declared in the TypeLibrary. Following prefixes are used:        
//   Type Libraries     : LIBID_xxxx                                      
//   CoClasses          : CLASS_xxxx                                      
//   DISPInterfaces     : DIID_xxxx                                       
//   Non-DISP interfaces: IID_xxxx                                        
// *********************************************************************//
const
  // TypeLibrary Major and minor versions
  WebScriptMajorVersion = 1;
  WebScriptMinorVersion = 0;

  LIBID_WebScript: TGUID = '{7E17379F-63D7-11D4-A4A3-00C04F6BB853}';

  IID_IComponentWrapper: TGUID = '{B6A68CA7-ED7B-4983-902E-ABB3FB97416F}';
  IID_IBaseAdapterWrapper: TGUID = '{CAC1644B-9BAD-11D4-A4F2-00C04F6BB853}';
  IID_IComponentsWrapper: TGUID = '{E08FAAAB-58DF-46F5-943B-FFCDC35076CC}';
  IID_IAdapterErrorsWrapper: TGUID = '{57EAA08F-4A35-4903-B9AA-21A380F7F94B}';
  CLASS_AdapterErrorsWrapper: TGUID = '{9C977F89-1BF9-4AB5-A061-AE8B5EEE664E}';
  IID_IAdapterRecordsWrapper: TGUID = '{04934843-5058-4B3F-87F6-B88C81392CF4}';
  CLASS_AdapterRecordsWrapper: TGUID = '{4956B129-90EC-469B-8341-549EA7E019EC}';
  IID_IAdapterFieldWrapper: TGUID = '{6C3ACA79-6314-11D4-A4A2-00C04F6BB853}';
  CLASS_AdapterFieldWrapper: TGUID = '{6C3ACA7B-6314-11D4-A4A2-00C04F6BB853}';
  IID_IAdapterActionWrapper: TGUID = '{6C3ACA7D-6314-11D4-A4A2-00C04F6BB853}';
  CLASS_AdapterActionWrapper: TGUID = '{6C3ACA81-6314-11D4-A4A2-00C04F6BB853}';
  CLASS_ComponentsWrapper: TGUID = '{6C3ACA86-6314-11D4-A4A2-00C04F6BB853}';
  CLASS_EnumVariantWrapper: TGUID = '{3A5B32FD-6348-11D4-A4A2-00C04F6BB853}';
  IID_IAdapterRecordWrapper: TGUID = '{3A5B3303-6348-11D4-A4A2-00C04F6BB853}';
  CLASS_AdapterRecordWrapper: TGUID = '{3A5B3305-6348-11D4-A4A2-00C04F6BB853}';
  IID_IResponseWrapper: TGUID = '{7E17379A-63D7-11D4-A4A3-00C04F6BB853}';
  CLASS_ResponseWrapper: TGUID = '{7E17379C-63D7-11D4-A4A3-00C04F6BB853}';
  IID_IHTMLItemsWrapper: TGUID = '{60409043-63F9-11D4-A4A3-00C04F6BB853}';
  CLASS_HTMLItemsWrapper: TGUID = '{60409045-63F9-11D4-A4A3-00C04F6BB853}';
  IID_IPageWrapper: TGUID = '{4A5B2D80-64B3-11D4-A4A5-00C04F6BB853}';
  CLASS_PageWrapper: TGUID = '{4A5B2D82-64B3-11D4-A4A5-00C04F6BB853}';
  IID_IModuleWrapper: TGUID = '{4A5B2D88-64B3-11D4-A4A5-00C04F6BB853}';
  CLASS_ModuleWrapper: TGUID = '{4A5B2D8B-64B3-11D4-A4A5-00C04F6BB853}';
  IID_IModulesWrapper: TGUID = '{4A5B2D92-64B3-11D4-A4A5-00C04F6BB853}';
  CLASS_ModulesWrapper: TGUID = '{4A5B2D94-64B3-11D4-A4A5-00C04F6BB853}';
  IID_IProducerWrapper: TGUID = '{FB0414F4-6702-11D4-A4A7-00C04F6BB853}';
  CLASS_ProducerWrapper: TGUID = '{FB0414F6-6702-11D4-A4A7-00C04F6BB853}';
  IID_IAdapterErrorWrapper: TGUID = '{A23C86B1-672A-11D4-A4A7-00C04F6BB853}';
  CLASS_AdapterErrorWrapper: TGUID = '{A23C86B3-672A-11D4-A4A7-00C04F6BB853}';
  IID_IPagesWrapper: TGUID = '{1CFF50C8-6995-11D4-A4AA-00C04F6BB853}';
  CLASS_PagesWrapper: TGUID = '{1CFF50CA-6995-11D4-A4AA-00C04F6BB853}';
  IID_IBaseRecordsAdapterWrapper: TGUID = '{CAC1644F-9BAD-11D4-A4F2-00C04F6BB853}';
  IID_IAdapterWrapper: TGUID = '{06C1025C-0159-4AB6-B7DD-0843DDE856BE}';
  IID_ISessionWrapper: TGUID = '{E1773ECC-F9EB-4614-90D3-814B059678C6}';
  CLASS_SessionWrapper: TGUID = '{1A4699C5-8451-4C7E-BE2C-D75C9C4D826C}';
  IID_ISessionIDWrapper: TGUID = '{09480FAD-09F5-4425-9DFF-BD6FFB4257FE}';
  CLASS_SessionIDWrapper: TGUID = '{F639BDA0-FBB9-4FFA-8306-C9C0367BFA67}';
  IID_IEndUserWrapper: TGUID = '{845CF950-B95B-4411-9061-67FEE8E52E08}';
  CLASS_EndUserWrapper: TGUID = '{97841636-78F7-4D10-A80B-A62D59B535B8}';
  IID_IAdapterValuesListWrapper: TGUID = '{7895DB1B-01E5-4B6D-9017-5653A4BEA375}';
  CLASS_AdapterValuesListWrapper: TGUID = '{0B2A1052-CD4C-4CFA-87DB-19D6DC10ECB2}';
  CLASS_AdapterWrapper: TGUID = '{290EE171-C8DB-41AE-A2D7-8629AA517921}';
  IID_IApplicationWrapper: TGUID = '{E086F82C-CAC2-48B1-AFCD-52022CB454C3}';
  IID_IAdapterImageWrapper: TGUID = '{F2AF207A-A097-11D4-A4F7-00C04F6BB853}';
  CLASS_AdapterImageWrapper: TGUID = '{F2AF207C-A097-11D4-A4F7-00C04F6BB853}';
  CLASS_ApplicationWrapper: TGUID = '{CCDF6D70-AF4C-4B8D-A4DD-656C6CF2BB6A}';
  IID_IAdapterFieldValuesWrapper: TGUID = '{7024ECA0-35B5-491B-9AB2-743DDDB0ECDC}';
  CLASS_AdapterFieldValuesWrapper: TGUID = '{FCC3A5AC-378A-4CD3-BF6C-A0773988011A}';
  IID_IAdapterHiddenFieldsWrapper: TGUID = '{B015307D-D096-11D4-A530-00C04F6BB853}';
  CLASS_AdapterHiddenFieldsWrapper: TGUID = '{B015307F-D096-11D4-A530-00C04F6BB853}';
  IID_IAdapterHiddenFieldWrapper: TGUID = '{B0153081-D096-11D4-A530-00C04F6BB853}';
  CLASS_AdapterHiddenFieldWrapper: TGUID = '{B0153083-D096-11D4-A530-00C04F6BB853}';
  IID_IAdapterActionArrayWrapper: TGUID = '{77561E9B-3754-4552-88CA-13AD02C495E2}';
  CLASS_AdapterActionArrayWrapper: TGUID = '{2C279C01-3616-4501-A38F-3969C6D895FE}';
  IID_IRequestWrapper: TGUID = '{0546F350-4388-40ED-97D7-914CB61B48BD}';
  CLASS_RequestWrapper: TGUID = '{CA3A3B64-3D3C-4B75-8035-D234A3203416}';
  IID_IImageProducerWrapper: TGUID = '{128B1043-EF0A-4D1F-A9F7-84C2B5EB96C8}';
  CLASS_ImageProducerWrapper: TGUID = '{359EAC2B-F21F-40EE-AB99-3D99F31F21E0}';
type

// *********************************************************************//
// Forward declaration of types defined in TypeLibrary                    
// *********************************************************************//
  IComponentWrapper = interface;
  IComponentWrapperDisp = dispinterface;
  IBaseAdapterWrapper = interface;
  IBaseAdapterWrapperDisp = dispinterface;
  IComponentsWrapper = interface;
  IComponentsWrapperDisp = dispinterface;
  IAdapterErrorsWrapper = interface;
  IAdapterErrorsWrapperDisp = dispinterface;
  IAdapterRecordsWrapper = interface;
  IAdapterRecordsWrapperDisp = dispinterface;
  IAdapterFieldWrapper = interface;
  IAdapterFieldWrapperDisp = dispinterface;
  IAdapterActionWrapper = interface;
  IAdapterActionWrapperDisp = dispinterface;
  IAdapterRecordWrapper = interface;
  IAdapterRecordWrapperDisp = dispinterface;
  IResponseWrapper = interface;
  IResponseWrapperDisp = dispinterface;
  IHTMLItemsWrapper = interface;
  IHTMLItemsWrapperDisp = dispinterface;
  IPageWrapper = interface;
  IPageWrapperDisp = dispinterface;
  IModuleWrapper = interface;
  IModuleWrapperDisp = dispinterface;
  IModulesWrapper = interface;
  IModulesWrapperDisp = dispinterface;
  IProducerWrapper = interface;
  IProducerWrapperDisp = dispinterface;
  IAdapterErrorWrapper = interface;
  IAdapterErrorWrapperDisp = dispinterface;
  IPagesWrapper = interface;
  IPagesWrapperDisp = dispinterface;
  IBaseRecordsAdapterWrapper = interface;
  IBaseRecordsAdapterWrapperDisp = dispinterface;
  IAdapterWrapper = interface;
  IAdapterWrapperDisp = dispinterface;
  ISessionWrapper = interface;
  ISessionWrapperDisp = dispinterface;
  ISessionIDWrapper = interface;
  ISessionIDWrapperDisp = dispinterface;
  IEndUserWrapper = interface;
  IEndUserWrapperDisp = dispinterface;
  IAdapterValuesListWrapper = interface;
  IAdapterValuesListWrapperDisp = dispinterface;
  IApplicationWrapper = interface;
  IApplicationWrapperDisp = dispinterface;
  IAdapterImageWrapper = interface;
  IAdapterImageWrapperDisp = dispinterface;
  IAdapterFieldValuesWrapper = interface;
  IAdapterFieldValuesWrapperDisp = dispinterface;
  IAdapterHiddenFieldsWrapper = interface;
  IAdapterHiddenFieldsWrapperDisp = dispinterface;
  IAdapterHiddenFieldWrapper = interface;
  IAdapterHiddenFieldWrapperDisp = dispinterface;
  IAdapterActionArrayWrapper = interface;
  IAdapterActionArrayWrapperDisp = dispinterface;
  IRequestWrapper = interface;
  IRequestWrapperDisp = dispinterface;
  IImageProducerWrapper = interface;
  IImageProducerWrapperDisp = dispinterface;

// *********************************************************************//
// Declaration of CoClasses defined in Type Library                       
// (NOTE: Here we map each CoClass to its Default Interface)              
// *********************************************************************//
  AdapterErrorsWrapper = IAdapterErrorsWrapper;
  AdapterRecordsWrapper = IAdapterRecordsWrapper;
  AdapterFieldWrapper = IAdapterFieldWrapper;
  AdapterActionWrapper = IAdapterActionWrapper;
  ComponentsWrapper = IComponentsWrapper;
  EnumVariantWrapper = IEnumVARIANT;
  AdapterRecordWrapper = IAdapterRecordWrapper;
  ResponseWrapper = IResponseWrapper;
  HTMLItemsWrapper = IHTMLItemsWrapper;
  PageWrapper = IPageWrapper;
  ModuleWrapper = IModuleWrapper;
  ModulesWrapper = IModulesWrapper;
  ProducerWrapper = IProducerWrapper;
  AdapterErrorWrapper = IAdapterErrorWrapper;
  PagesWrapper = IPagesWrapper;
  SessionWrapper = ISessionWrapper;
  SessionIDWrapper = ISessionIDWrapper;
  EndUserWrapper = IEndUserWrapper;
  AdapterValuesListWrapper = IAdapterValuesListWrapper;
  AdapterWrapper = IAdapterWrapper;
  AdapterImageWrapper = IAdapterImageWrapper;
  ApplicationWrapper = IApplicationWrapper;
  AdapterFieldValuesWrapper = IAdapterFieldValuesWrapper;
  AdapterHiddenFieldsWrapper = IAdapterHiddenFieldsWrapper;
  AdapterHiddenFieldWrapper = IAdapterHiddenFieldWrapper;
  AdapterActionArrayWrapper = IAdapterActionArrayWrapper;
  RequestWrapper = IRequestWrapper;
  ImageProducerWrapper = IImageProducerWrapper;


// *********************************************************************//
// Interface: IComponentWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {B6A68CA7-ED7B-4983-902E-ABB3FB97416F}
// *********************************************************************//
  IComponentWrapper = interface(IDispatch)
    ['{B6A68CA7-ED7B-4983-902E-ABB3FB97416F}']
    function  Get_Name_ {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_ClassName_ {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    property Name_: WideString read Get_Name_;
    property ClassName_: WideString read Get_ClassName_;
  end;

// *********************************************************************//
// DispIntf:  IComponentWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {B6A68CA7-ED7B-4983-902E-ABB3FB97416F}
// *********************************************************************//
  IComponentWrapperDisp = dispinterface
    ['{B6A68CA7-ED7B-4983-902E-ABB3FB97416F}']
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: IBaseAdapterWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {CAC1644B-9BAD-11D4-A4F2-00C04F6BB853}
// *********************************************************************//
  IBaseAdapterWrapper = interface(IComponentWrapper)
    ['{CAC1644B-9BAD-11D4-A4F2-00C04F6BB853}']
    function  Get_Fields {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper; safecall;
    function  Get_Actions {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper; safecall;
    property Fields: IComponentsWrapper read Get_Fields;
    property Actions: IComponentsWrapper read Get_Actions;
  end;

// *********************************************************************//
// DispIntf:  IBaseAdapterWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {CAC1644B-9BAD-11D4-A4F2-00C04F6BB853}
// *********************************************************************//
  IBaseAdapterWrapperDisp = dispinterface
    ['{CAC1644B-9BAD-11D4-A4F2-00C04F6BB853}']
    property Fields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 1;
    property Actions {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 2;
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: IComponentsWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E08FAAAB-58DF-46F5-943B-FFCDC35076CC}
// *********************************************************************//
  IComponentsWrapper = interface(IDispatch)
    ['{E08FAAAB-58DF-46F5-943B-FFCDC35076CC}']
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
  end;

// *********************************************************************//
// DispIntf:  IComponentsWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E08FAAAB-58DF-46F5-943B-FFCDC35076CC}
// *********************************************************************//
  IComponentsWrapperDisp = dispinterface
    ['{E08FAAAB-58DF-46F5-943B-FFCDC35076CC}']
    function  Get_NewEnum {Flags(2), (1/0) CC:0, INV:1, DBG:4}: IUnknown; dispid -4;
  end;

// *********************************************************************//
// Interface: IAdapterErrorsWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {57EAA08F-4A35-4903-B9AA-21A380F7F94B}
// *********************************************************************//
  IAdapterErrorsWrapper = interface(IDispatch)
    ['{57EAA08F-4A35-4903-B9AA-21A380F7F94B}']
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
    procedure DefineLabel {Flags(1), (2/2) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown; 
                                                               {VT_8:0}const Value: WideString); safecall;
    function  FieldErrors {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown): IAdapterErrorsWrapper; safecall;
  end;

// *********************************************************************//
// DispIntf:  IAdapterErrorsWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {57EAA08F-4A35-4903-B9AA-21A380F7F94B}
// *********************************************************************//
  IAdapterErrorsWrapperDisp = dispinterface
    ['{57EAA08F-4A35-4903-B9AA-21A380F7F94B}']
    function  Get_NewEnum {Flags(2), (1/0) CC:0, INV:1, DBG:4}: IUnknown; dispid -4;
    procedure DefineLabel {Flags(2), (2/2) CC:0, INV:1, DBG:4}({VT_13:0}const Object_: IUnknown; 
                                                               {VT_8:0}const Value: WideString); dispid 1;
    function  FieldErrors {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_13:0}const Object_: IUnknown): IAdapterErrorsWrapper; dispid 2;
  end;

// *********************************************************************//
// Interface: IAdapterRecordsWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {04934843-5058-4B3F-87F6-B88C81392CF4}
// *********************************************************************//
  IAdapterRecordsWrapper = interface(IDispatch)
    ['{04934843-5058-4B3F-87F6-B88C81392CF4}']
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
  end;

// *********************************************************************//
// DispIntf:  IAdapterRecordsWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {04934843-5058-4B3F-87F6-B88C81392CF4}
// *********************************************************************//
  IAdapterRecordsWrapperDisp = dispinterface
    ['{04934843-5058-4B3F-87F6-B88C81392CF4}']
    function  Get_NewEnum {Flags(2), (1/0) CC:0, INV:1, DBG:4}: IUnknown; dispid -4;
  end;

// *********************************************************************//
// Interface: IAdapterFieldWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {6C3ACA79-6314-11D4-A4A2-00C04F6BB853}
// *********************************************************************//
  IAdapterFieldWrapper = interface(IDispatch)
    ['{6C3ACA79-6314-11D4-A4A2-00C04F6BB853}']
    function  Get_Value {Flags(1), (1/0) CC:0, INV:2, DBG:6}: OleVariant; safecall;
    function  Get_Name {Flags(1), (1/0) CC:0, INV:2, DBG:6}: OleVariant; safecall;
    function  Get_DisplayText {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_EditText {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_InputName {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_DisplayWidth {Flags(1), (1/0) CC:0, INV:2, DBG:6}: Integer; safecall;
    function  Get_DisplayLabel {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_ValuesList {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterValuesListWrapper; safecall;
    function  Get_InputStyle {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_DisplayStyle {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Image {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterImageWrapper; safecall;
    function  Get_CanModify {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_CanView {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_Values {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterFieldValuesWrapper; safecall;
    function  IsEqual {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_12:0}Value: OleVariant): WordBool; safecall;
    function  Get_ViewMode {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Required {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_Visible {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_MaxLength {Flags(1), (1/0) CC:0, INV:2, DBG:6}: Integer; safecall;
    property Value: OleVariant read Get_Value;
    property Name: OleVariant read Get_Name;
    property DisplayText: WideString read Get_DisplayText;
    property EditText: WideString read Get_EditText;
    property InputName: WideString read Get_InputName;
    property DisplayWidth: Integer read Get_DisplayWidth;
    property DisplayLabel: WideString read Get_DisplayLabel;
    property ValuesList: IAdapterValuesListWrapper read Get_ValuesList;
    property InputStyle: WideString read Get_InputStyle;
    property DisplayStyle: WideString read Get_DisplayStyle;
    property Image: IAdapterImageWrapper read Get_Image;
    property CanModify: WordBool read Get_CanModify;
    property CanView: WordBool read Get_CanView;
    property Values: IAdapterFieldValuesWrapper read Get_Values;
    property ViewMode: WideString read Get_ViewMode;
    property Required: WordBool read Get_Required;
    property Visible: WordBool read Get_Visible;
    property MaxLength: Integer read Get_MaxLength;
  end;

// *********************************************************************//
// DispIntf:  IAdapterFieldWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {6C3ACA79-6314-11D4-A4A2-00C04F6BB853}
// *********************************************************************//
  IAdapterFieldWrapperDisp = dispinterface
    ['{6C3ACA79-6314-11D4-A4A2-00C04F6BB853}']
    property Value {Flags(2), (1/0) CC:0, INV:2, DBG:6}: OleVariant readonly dispid 1;
    property Name {Flags(2), (1/0) CC:0, INV:2, DBG:6}: OleVariant readonly dispid 2;
    property DisplayText {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 3;
    property EditText {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 6;
    property InputName {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 4;
    property DisplayWidth {Flags(2), (1/0) CC:0, INV:2, DBG:6}: Integer readonly dispid 7;
    property DisplayLabel {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 8;
    property ValuesList {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterValuesListWrapper readonly dispid 11;
    property InputStyle {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 12;
    property DisplayStyle {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 13;
    property Image {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterImageWrapper readonly dispid 14;
    property CanModify {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 15;
    property CanView {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 16;
    property Values {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterFieldValuesWrapper readonly dispid 17;
    function  IsEqual {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_12:0}Value: OleVariant): WordBool; dispid 18;
    property ViewMode {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 19;
    property Required {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 20;
    property Visible {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 21;
    property MaxLength {Flags(2), (1/0) CC:0, INV:2, DBG:6}: Integer readonly dispid 5;
  end;

// *********************************************************************//
// Interface: IAdapterActionWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {6C3ACA7D-6314-11D4-A4A2-00C04F6BB853}
// *********************************************************************//
  IAdapterActionWrapper = interface(IDispatch)
    ['{6C3ACA7D-6314-11D4-A4A2-00C04F6BB853}']
    function  Get_Name {Flags(1), (1/0) CC:0, INV:2, DBG:6}: OleVariant; safecall;
    function  Get_AsFieldValue {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  LinkToPage {Flags(1), (3/2) CC:0, INV:1, DBG:6}({VT_8:0}const PageSuccess: WideString; 
                                                              {VT_8:0}const PageFail: WideString): IAdapterActionWrapper; safecall;
    function  Get_DisplayLabel {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Enabled {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_AsHREF {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_CanExecute {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_Visible {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_Array_ {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterActionArrayWrapper; safecall;
    function  Get_DisplayStyle {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    property Name: OleVariant read Get_Name;
    property AsFieldValue: WideString read Get_AsFieldValue;
    property DisplayLabel: WideString read Get_DisplayLabel;
    property Enabled: WordBool read Get_Enabled;
    property AsHREF: WideString read Get_AsHREF;
    property CanExecute: WordBool read Get_CanExecute;
    property Visible: WordBool read Get_Visible;
    property Array_: IAdapterActionArrayWrapper read Get_Array_;
    property DisplayStyle: WideString read Get_DisplayStyle;
  end;

// *********************************************************************//
// DispIntf:  IAdapterActionWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {6C3ACA7D-6314-11D4-A4A2-00C04F6BB853}
// *********************************************************************//
  IAdapterActionWrapperDisp = dispinterface
    ['{6C3ACA7D-6314-11D4-A4A2-00C04F6BB853}']
    property Name {Flags(2), (1/0) CC:0, INV:2, DBG:6}: OleVariant readonly dispid 2;
    property AsFieldValue {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 3;
    function  LinkToPage {Flags(2), (3/2) CC:0, INV:1, DBG:4}({VT_8:0}const PageSuccess: WideString; 
                                                              {VT_8:0}const PageFail: WideString): IAdapterActionWrapper; dispid 5;
    property DisplayLabel {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 4;
    property Enabled {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 6;
    property AsHREF {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 7;
    property CanExecute {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 8;
    property Visible {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 10;
    property Array_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterActionArrayWrapper readonly dispid 11;
    property DisplayStyle {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 13;
  end;

// *********************************************************************//
// Interface: IAdapterRecordWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {3A5B3303-6348-11D4-A4A2-00C04F6BB853}
// *********************************************************************//
  IAdapterRecordWrapper = interface(IBaseAdapterWrapper)
    ['{3A5B3303-6348-11D4-A4A2-00C04F6BB853}']
  end;

// *********************************************************************//
// DispIntf:  IAdapterRecordWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {3A5B3303-6348-11D4-A4A2-00C04F6BB853}
// *********************************************************************//
  IAdapterRecordWrapperDisp = dispinterface
    ['{3A5B3303-6348-11D4-A4A2-00C04F6BB853}']
    property Fields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 1;
    property Actions {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 2;
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: IResponseWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {7E17379A-63D7-11D4-A4A3-00C04F6BB853}
// *********************************************************************//
  IResponseWrapper = interface(IDispatch)
    ['{7E17379A-63D7-11D4-A4A3-00C04F6BB853}']
    procedure Write {Flags(1), (1/1) CC:0, INV:1, DBG:6}({VT_12:0}varText: OleVariant); safecall;
    function  Get_Content {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    procedure Set_Content {Flags(1), (1/1) CC:0, INV:4, DBG:6}({VT_8:0}const Value: WideString); safecall;
    property Content: WideString read Get_Content write Set_Content;
  end;

// *********************************************************************//
// DispIntf:  IResponseWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {7E17379A-63D7-11D4-A4A3-00C04F6BB853}
// *********************************************************************//
  IResponseWrapperDisp = dispinterface
    ['{7E17379A-63D7-11D4-A4A3-00C04F6BB853}']
    procedure Write {Flags(2), (1/1) CC:0, INV:1, DBG:4}({VT_12:0}varText: OleVariant); dispid 1;
    property Content {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString dispid 2;
  end;

// *********************************************************************//
// Interface: IHTMLItemsWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {60409043-63F9-11D4-A4A3-00C04F6BB853}
// *********************************************************************//
  IHTMLItemsWrapper = interface(IDispatch)
    ['{60409043-63F9-11D4-A4A3-00C04F6BB853}']
    function  Get_ControlDefault {Flags(1), (2/1) CC:0, INV:2, DBG:6}({VT_3:0}Index: Integer): OleVariant; safecall;
    function  Count {Flags(1), (1/0) CC:0, INV:1, DBG:6}: Integer; safecall;
    function  Get_Item {Flags(1), (2/1) CC:0, INV:2, DBG:6}({VT_3:0}Index: Integer): WideString; safecall;
    procedure WriteItem {Flags(1), (1/1) CC:0, INV:1, DBG:6}({VT_3:0}Index: Integer); safecall;
    property ControlDefault {Flags(2), (2/1) CC:0, INV:2, DBG:5}[{VT_3:0}Index: Integer]: OleVariant read Get_ControlDefault; default;
    property Item {Flags(2), (2/1) CC:0, INV:2, DBG:5}[{VT_3:0}Index: Integer]: WideString read Get_Item;
  end;

// *********************************************************************//
// DispIntf:  IHTMLItemsWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {60409043-63F9-11D4-A4A3-00C04F6BB853}
// *********************************************************************//
  IHTMLItemsWrapperDisp = dispinterface
    ['{60409043-63F9-11D4-A4A3-00C04F6BB853}']
    property ControlDefault {Flags(2), (2/1) CC:0, INV:2, DBG:6}[{VT_3:0}Index: Integer]: OleVariant readonly dispid 0; default;
    function  Count {Flags(2), (1/0) CC:0, INV:1, DBG:4}: Integer; dispid 1;
    property Item {Flags(2), (2/1) CC:0, INV:2, DBG:6}[{VT_3:0}Index: Integer]: WideString readonly dispid 2;
    procedure WriteItem {Flags(2), (1/1) CC:0, INV:1, DBG:4}({VT_3:0}Index: Integer); dispid 3;
  end;

// *********************************************************************//
// Interface: IPageWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4A5B2D80-64B3-11D4-A4A5-00C04F6BB853}
// *********************************************************************//
  IPageWrapper = interface(IDispatch)
    ['{4A5B2D80-64B3-11D4-A4A5-00C04F6BB853}']
    function  Get_Name {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_HREF {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Title {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Description {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Published_ {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_LoginRequired {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_CanView {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_DefaultAction {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterActionWrapper; safecall;
    property Name: WideString read Get_Name;
    property HREF: WideString read Get_HREF;
    property Title: WideString read Get_Title;
    property Description: WideString read Get_Description;
    property Published_: WordBool read Get_Published_;
    property LoginRequired: WordBool read Get_LoginRequired;
    property CanView: WordBool read Get_CanView;
    property DefaultAction: IAdapterActionWrapper read Get_DefaultAction;
  end;

// *********************************************************************//
// DispIntf:  IPageWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4A5B2D80-64B3-11D4-A4A5-00C04F6BB853}
// *********************************************************************//
  IPageWrapperDisp = dispinterface
    ['{4A5B2D80-64B3-11D4-A4A5-00C04F6BB853}']
    property Name {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 1;
    property HREF {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 2;
    property Title {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 3;
    property Description {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 4;
    property Published_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 5;
    property LoginRequired {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 6;
    property CanView {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 7;
    property DefaultAction {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterActionWrapper readonly dispid 8;
  end;

// *********************************************************************//
// Interface: IModuleWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4A5B2D88-64B3-11D4-A4A5-00C04F6BB853}
// *********************************************************************//
  IModuleWrapper = interface(IComponentWrapper)
    ['{4A5B2D88-64B3-11D4-A4A5-00C04F6BB853}']
    function  Get_Objects {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper; safecall;
    property Objects: IComponentsWrapper read Get_Objects;
  end;

// *********************************************************************//
// DispIntf:  IModuleWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4A5B2D88-64B3-11D4-A4A5-00C04F6BB853}
// *********************************************************************//
  IModuleWrapperDisp = dispinterface
    ['{4A5B2D88-64B3-11D4-A4A5-00C04F6BB853}']
    property Objects {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 2;
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: IModulesWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4A5B2D92-64B3-11D4-A4A5-00C04F6BB853}
// *********************************************************************//
  IModulesWrapper = interface(IDispatch)
    ['{4A5B2D92-64B3-11D4-A4A5-00C04F6BB853}']
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
  end;

// *********************************************************************//
// DispIntf:  IModulesWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {4A5B2D92-64B3-11D4-A4A5-00C04F6BB853}
// *********************************************************************//
  IModulesWrapperDisp = dispinterface
    ['{4A5B2D92-64B3-11D4-A4A5-00C04F6BB853}']
    function  Get_NewEnum {Flags(2), (1/0) CC:0, INV:1, DBG:4}: IUnknown; dispid -4;
  end;

// *********************************************************************//
// Interface: IProducerWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {FB0414F4-6702-11D4-A4A7-00C04F6BB853}
// *********************************************************************//
  IProducerWrapper = interface(IDispatch)
    ['{FB0414F4-6702-11D4-A4A7-00C04F6BB853}']
    procedure Write {Flags(1), (1/1) CC:0, INV:1, DBG:6}({VT_12:0}varText: OleVariant); safecall;
    function  Get_Content {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    procedure Set_Content {Flags(1), (1/1) CC:0, INV:4, DBG:6}({VT_8:0}const Value: WideString); safecall;
    property Content: WideString read Get_Content write Set_Content;
  end;

// *********************************************************************//
// DispIntf:  IProducerWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {FB0414F4-6702-11D4-A4A7-00C04F6BB853}
// *********************************************************************//
  IProducerWrapperDisp = dispinterface
    ['{FB0414F4-6702-11D4-A4A7-00C04F6BB853}']
    procedure Write {Flags(2), (1/1) CC:0, INV:1, DBG:4}({VT_12:0}varText: OleVariant); dispid 1;
    property Content {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString dispid 2;
  end;

// *********************************************************************//
// Interface: IAdapterErrorWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {A23C86B1-672A-11D4-A4A7-00C04F6BB853}
// *********************************************************************//
  IAdapterErrorWrapper = interface(IDispatch)
    ['{A23C86B1-672A-11D4-A4A7-00C04F6BB853}']
    function  Get_Message {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Field {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IDispatch; safecall;
    function  Get_ID {Flags(1), (1/0) CC:0, INV:2, DBG:6}: Integer; safecall;
    property Message: WideString read Get_Message;
    property Field: IDispatch read Get_Field;
    property ID: Integer read Get_ID;
  end;

// *********************************************************************//
// DispIntf:  IAdapterErrorWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {A23C86B1-672A-11D4-A4A7-00C04F6BB853}
// *********************************************************************//
  IAdapterErrorWrapperDisp = dispinterface
    ['{A23C86B1-672A-11D4-A4A7-00C04F6BB853}']
    property Message {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 1;
    property Field {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IDispatch readonly dispid 2;
    property ID {Flags(2), (1/0) CC:0, INV:2, DBG:6}: Integer readonly dispid 4;
  end;

// *********************************************************************//
// Interface: IPagesWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {1CFF50C8-6995-11D4-A4AA-00C04F6BB853}
// *********************************************************************//
  IPagesWrapper = interface(IDispatch)
    ['{1CFF50C8-6995-11D4-A4AA-00C04F6BB853}']
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
  end;

// *********************************************************************//
// DispIntf:  IPagesWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {1CFF50C8-6995-11D4-A4AA-00C04F6BB853}
// *********************************************************************//
  IPagesWrapperDisp = dispinterface
    ['{1CFF50C8-6995-11D4-A4AA-00C04F6BB853}']
    function  Get_NewEnum {Flags(2), (1/0) CC:0, INV:1, DBG:4}: IUnknown; dispid -4;
  end;

// *********************************************************************//
// Interface: IBaseRecordsAdapterWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {CAC1644F-9BAD-11D4-A4F2-00C04F6BB853}
// *********************************************************************//
  IBaseRecordsAdapterWrapper = interface(IBaseAdapterWrapper)
    ['{CAC1644F-9BAD-11D4-A4F2-00C04F6BB853}']
    function  Get_Records {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterRecordsWrapper; safecall;
    property Records: IAdapterRecordsWrapper read Get_Records;
  end;

// *********************************************************************//
// DispIntf:  IBaseRecordsAdapterWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {CAC1644F-9BAD-11D4-A4F2-00C04F6BB853}
// *********************************************************************//
  IBaseRecordsAdapterWrapperDisp = dispinterface
    ['{CAC1644F-9BAD-11D4-A4F2-00C04F6BB853}']
    property Records {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterRecordsWrapper readonly dispid 7;
    property Fields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 1;
    property Actions {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 2;
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: IAdapterWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {06C1025C-0159-4AB6-B7DD-0843DDE856BE}
// *********************************************************************//
  IAdapterWrapper = interface(IBaseRecordsAdapterWrapper)
    ['{06C1025C-0159-4AB6-B7DD-0843DDE856BE}']
    function  Get_Errors {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterErrorsWrapper; safecall;
    function  Get_Mode {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    procedure Set_Mode {Flags(1), (1/1) CC:0, INV:4, DBG:6}({VT_8:0}const Value: WideString); safecall;
    function  Get_CanView {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_CanModify {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_HiddenFields {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterHiddenFieldsWrapper; safecall;
    function  Get_HiddenRecordFields {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterHiddenFieldsWrapper; safecall;
    property Errors: IAdapterErrorsWrapper read Get_Errors;
    property Mode: WideString read Get_Mode write Set_Mode;
    property CanView: WordBool read Get_CanView;
    property CanModify: WordBool read Get_CanModify;
    property HiddenFields: IAdapterHiddenFieldsWrapper read Get_HiddenFields;
    property HiddenRecordFields: IAdapterHiddenFieldsWrapper read Get_HiddenRecordFields;
  end;

// *********************************************************************//
// DispIntf:  IAdapterWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {06C1025C-0159-4AB6-B7DD-0843DDE856BE}
// *********************************************************************//
  IAdapterWrapperDisp = dispinterface
    ['{06C1025C-0159-4AB6-B7DD-0843DDE856BE}']
    property Errors {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterErrorsWrapper readonly dispid 14;
    property Mode {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString dispid 17;
    property CanView {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 3;
    property CanModify {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 4;
    property HiddenFields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterHiddenFieldsWrapper readonly dispid 6;
    property HiddenRecordFields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterHiddenFieldsWrapper readonly dispid 5;
    property Records {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterRecordsWrapper readonly dispid 7;
    property Fields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 1;
    property Actions {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 2;
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: ISessionWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E1773ECC-F9EB-4614-90D3-814B059678C6}
// *********************************************************************//
  ISessionWrapper = interface(IDispatch)
    ['{E1773ECC-F9EB-4614-90D3-814B059678C6}']
    function  Get_Values {Flags(1), (2/1) CC:0, INV:2, DBG:6}({VT_8:0}const Name: WideString): OleVariant; safecall;
    function  Get_SessionID {Flags(1), (1/0) CC:0, INV:2, DBG:6}: ISessionIDWrapper; safecall;
    property Values {Flags(2), (2/1) CC:0, INV:2, DBG:5}[{VT_8:0}const Name: WideString]: OleVariant read Get_Values;
    property SessionID: ISessionIDWrapper read Get_SessionID;
  end;

// *********************************************************************//
// DispIntf:  ISessionWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E1773ECC-F9EB-4614-90D3-814B059678C6}
// *********************************************************************//
  ISessionWrapperDisp = dispinterface
    ['{E1773ECC-F9EB-4614-90D3-814B059678C6}']
    property Values {Flags(2), (2/1) CC:0, INV:2, DBG:6}[{VT_8:0}const Name: WideString]: OleVariant readonly dispid 2;
    property SessionID {Flags(2), (1/0) CC:0, INV:2, DBG:6}: ISessionIDWrapper readonly dispid 1;
  end;

// *********************************************************************//
// Interface: ISessionIDWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {09480FAD-09F5-4425-9DFF-BD6FFB4257FE}
// *********************************************************************//
  ISessionIDWrapper = interface(IDispatch)
    ['{09480FAD-09F5-4425-9DFF-BD6FFB4257FE}']
    function  Get_Value {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    property Value: WideString read Get_Value;
  end;

// *********************************************************************//
// DispIntf:  ISessionIDWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {09480FAD-09F5-4425-9DFF-BD6FFB4257FE}
// *********************************************************************//
  ISessionIDWrapperDisp = dispinterface
    ['{09480FAD-09F5-4425-9DFF-BD6FFB4257FE}']
    property Value {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 1;
  end;

// *********************************************************************//
// Interface: IEndUserWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {845CF950-B95B-4411-9061-67FEE8E52E08}
// *********************************************************************//
  IEndUserWrapper = interface(IAdapterWrapper)
    ['{845CF950-B95B-4411-9061-67FEE8E52E08}']
    function  Get_DisplayName {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_LoggedIn {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  Get_LoginFormAction {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterActionWrapper; safecall;
    function  Get_LogoutAction {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterActionWrapper; safecall;
    property DisplayName: WideString read Get_DisplayName;
    property LoggedIn: WordBool read Get_LoggedIn;
    property LoginFormAction: IAdapterActionWrapper read Get_LoginFormAction;
    property LogoutAction: IAdapterActionWrapper read Get_LogoutAction;
  end;

// *********************************************************************//
// DispIntf:  IEndUserWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {845CF950-B95B-4411-9061-67FEE8E52E08}
// *********************************************************************//
  IEndUserWrapperDisp = dispinterface
    ['{845CF950-B95B-4411-9061-67FEE8E52E08}']
    property DisplayName {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 21;
    property LoggedIn {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 22;
    property LoginFormAction {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterActionWrapper readonly dispid 23;
    property LogoutAction {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterActionWrapper readonly dispid 24;
    property Errors {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterErrorsWrapper readonly dispid 14;
    property Mode {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString dispid 17;
    property CanView {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 3;
    property CanModify {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 4;
    property HiddenFields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterHiddenFieldsWrapper readonly dispid 6;
    property HiddenRecordFields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterHiddenFieldsWrapper readonly dispid 5;
    property Records {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterRecordsWrapper readonly dispid 7;
    property Fields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 1;
    property Actions {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 2;
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: IAdapterValuesListWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {7895DB1B-01E5-4B6D-9017-5653A4BEA375}
// *********************************************************************//
  IAdapterValuesListWrapper = interface(IBaseRecordsAdapterWrapper)
    ['{7895DB1B-01E5-4B6D-9017-5653A4BEA375}']
    function  Get_ValueName {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Value {Flags(1), (1/0) CC:0, INV:2, DBG:6}: OleVariant; safecall;
    function  NameOfValue {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_12:0}Value: OleVariant): WideString; safecall;
    function  Get_Image {Flags(1), (1/0) CC:0, INV:2, DBG:6}: IAdapterImageWrapper; safecall;
    function  ImageOfValue {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_12:0}Value: OleVariant): IAdapterImageWrapper; safecall;
    property ValueName: WideString read Get_ValueName;
    property Value: OleVariant read Get_Value;
    property Image: IAdapterImageWrapper read Get_Image;
  end;

// *********************************************************************//
// DispIntf:  IAdapterValuesListWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {7895DB1B-01E5-4B6D-9017-5653A4BEA375}
// *********************************************************************//
  IAdapterValuesListWrapperDisp = dispinterface
    ['{7895DB1B-01E5-4B6D-9017-5653A4BEA375}']
    property ValueName {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 17;
    property Value {Flags(2), (1/0) CC:0, INV:2, DBG:6}: OleVariant readonly dispid 19;
    function  NameOfValue {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_12:0}Value: OleVariant): WideString; dispid 3;
    property Image {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterImageWrapper readonly dispid 5;
    function  ImageOfValue {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_12:0}Value: OleVariant): IAdapterImageWrapper; dispid 22;
    property Records {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterRecordsWrapper readonly dispid 7;
    property Fields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 1;
    property Actions {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 2;
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: IApplicationWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E086F82C-CAC2-48B1-AFCD-52022CB454C3}
// *********************************************************************//
  IApplicationWrapper = interface(IAdapterWrapper)
    ['{E086F82C-CAC2-48B1-AFCD-52022CB454C3}']
    function  Get_Title {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Designing {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WordBool; safecall;
    function  QualifyFileName {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_8:0}const FileName: WideString): WideString; safecall;
    function  Get_ModulePath {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_ModuleFileName {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    property Title: WideString read Get_Title;
    property Designing: WordBool read Get_Designing;
    property ModulePath: WideString read Get_ModulePath;
    property ModuleFileName: WideString read Get_ModuleFileName;
  end;

// *********************************************************************//
// DispIntf:  IApplicationWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E086F82C-CAC2-48B1-AFCD-52022CB454C3}
// *********************************************************************//
  IApplicationWrapperDisp = dispinterface
    ['{E086F82C-CAC2-48B1-AFCD-52022CB454C3}']
    property Title {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 21;
    property Designing {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 22;
    function  QualifyFileName {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_8:0}const FileName: WideString): WideString; dispid 8;
    property ModulePath {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 10;
    property ModuleFileName {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 9;
    property Errors {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterErrorsWrapper readonly dispid 14;
    property Mode {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString dispid 17;
    property CanView {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 3;
    property CanModify {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WordBool readonly dispid 4;
    property HiddenFields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterHiddenFieldsWrapper readonly dispid 6;
    property HiddenRecordFields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterHiddenFieldsWrapper readonly dispid 5;
    property Records {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterRecordsWrapper readonly dispid 7;
    property Fields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 1;
    property Actions {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 2;
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: IAdapterImageWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {F2AF207A-A097-11D4-A4F7-00C04F6BB853}
// *********************************************************************//
  IAdapterImageWrapper = interface(IDispatch)
    ['{F2AF207A-A097-11D4-A4F7-00C04F6BB853}']
    function  Get_AsHREF {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    property AsHREF: WideString read Get_AsHREF;
  end;

// *********************************************************************//
// DispIntf:  IAdapterImageWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {F2AF207A-A097-11D4-A4F7-00C04F6BB853}
// *********************************************************************//
  IAdapterImageWrapperDisp = dispinterface
    ['{F2AF207A-A097-11D4-A4F7-00C04F6BB853}']
    property AsHREF {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 7;
  end;

// *********************************************************************//
// Interface: IAdapterFieldValuesWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {7024ECA0-35B5-491B-9AB2-743DDDB0ECDC}
// *********************************************************************//
  IAdapterFieldValuesWrapper = interface(IBaseRecordsAdapterWrapper)
    ['{7024ECA0-35B5-491B-9AB2-743DDDB0ECDC}']
    function  HasValue {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_12:0}Value: OleVariant): WordBool; safecall;
    function  Get_Value {Flags(1), (1/0) CC:0, INV:2, DBG:6}: OleVariant; safecall;
    property Value: OleVariant read Get_Value;
  end;

// *********************************************************************//
// DispIntf:  IAdapterFieldValuesWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {7024ECA0-35B5-491B-9AB2-743DDDB0ECDC}
// *********************************************************************//
  IAdapterFieldValuesWrapperDisp = dispinterface
    ['{7024ECA0-35B5-491B-9AB2-743DDDB0ECDC}']
    function  HasValue {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_12:0}Value: OleVariant): WordBool; dispid 19;
    property Value {Flags(2), (1/0) CC:0, INV:2, DBG:6}: OleVariant readonly dispid 20;
    property Records {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IAdapterRecordsWrapper readonly dispid 7;
    property Fields {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 1;
    property Actions {Flags(2), (1/0) CC:0, INV:2, DBG:6}: IComponentsWrapper readonly dispid 2;
    property Name_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 40;
    property ClassName_ {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 41;
  end;

// *********************************************************************//
// Interface: IAdapterHiddenFieldsWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {B015307D-D096-11D4-A530-00C04F6BB853}
// *********************************************************************//
  IAdapterHiddenFieldsWrapper = interface(IDispatch)
    ['{B015307D-D096-11D4-A530-00C04F6BB853}']
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
    procedure WriteFields {Flags(1), (1/1) CC:0, INV:1, DBG:6}({VT_9:0}const Response: IDispatch); safecall;
  end;

// *********************************************************************//
// DispIntf:  IAdapterHiddenFieldsWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {B015307D-D096-11D4-A530-00C04F6BB853}
// *********************************************************************//
  IAdapterHiddenFieldsWrapperDisp = dispinterface
    ['{B015307D-D096-11D4-A530-00C04F6BB853}']
    function  Get_NewEnum {Flags(2), (1/0) CC:0, INV:1, DBG:4}: IUnknown; dispid -4;
    procedure WriteFields {Flags(2), (1/1) CC:0, INV:1, DBG:4}({VT_9:0}const Response: IDispatch); dispid 1;
  end;

// *********************************************************************//
// Interface: IAdapterHiddenFieldWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {B0153081-D096-11D4-A530-00C04F6BB853}
// *********************************************************************//
  IAdapterHiddenFieldWrapper = interface(IDispatch)
    ['{B0153081-D096-11D4-A530-00C04F6BB853}']
    function  Get_Name {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Value {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    property Name: WideString read Get_Name;
    property Value: WideString read Get_Value;
  end;

// *********************************************************************//
// DispIntf:  IAdapterHiddenFieldWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {B0153081-D096-11D4-A530-00C04F6BB853}
// *********************************************************************//
  IAdapterHiddenFieldWrapperDisp = dispinterface
    ['{B0153081-D096-11D4-A530-00C04F6BB853}']
    property Name {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 1;
    property Value {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 2;
  end;

// *********************************************************************//
// Interface: IAdapterActionArrayWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {77561E9B-3754-4552-88CA-13AD02C495E2}
// *********************************************************************//
  IAdapterActionArrayWrapper = interface(IDispatch)
    ['{77561E9B-3754-4552-88CA-13AD02C495E2}']
    function  Get_NewEnum {Flags(1), (1/0) CC:0, INV:1, DBG:6}: IUnknown; safecall;
  end;

// *********************************************************************//
// DispIntf:  IAdapterActionArrayWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {77561E9B-3754-4552-88CA-13AD02C495E2}
// *********************************************************************//
  IAdapterActionArrayWrapperDisp = dispinterface
    ['{77561E9B-3754-4552-88CA-13AD02C495E2}']
    function  Get_NewEnum {Flags(2), (1/0) CC:0, INV:1, DBG:4}: IUnknown; dispid -4;
  end;

// *********************************************************************//
// Interface: IRequestWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {0546F350-4388-40ED-97D7-914CB61B48BD}
// *********************************************************************//
  IRequestWrapper = interface(IDispatch)
    ['{0546F350-4388-40ED-97D7-914CB61B48BD}']
    function  Get_PathInfo {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_ScriptName {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    function  Get_Host {Flags(1), (1/0) CC:0, INV:2, DBG:6}: WideString; safecall;
    property PathInfo: WideString read Get_PathInfo;
    property ScriptName: WideString read Get_ScriptName;
    property Host: WideString read Get_Host;
  end;

// *********************************************************************//
// DispIntf:  IRequestWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {0546F350-4388-40ED-97D7-914CB61B48BD}
// *********************************************************************//
  IRequestWrapperDisp = dispinterface
    ['{0546F350-4388-40ED-97D7-914CB61B48BD}']
    property PathInfo {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 2;
    property ScriptName {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 3;
    property Host {Flags(2), (1/0) CC:0, INV:2, DBG:6}: WideString readonly dispid 1;
  end;

// *********************************************************************//
// Interface: IImageProducerWrapper
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {128B1043-EF0A-4D1F-A9F7-84C2B5EB96C8}
// *********************************************************************//
  IImageProducerWrapper = interface(IDispatch)
    ['{128B1043-EF0A-4D1F-A9F7-84C2B5EB96C8}']
    function  GetImage {Flags(1), (3/2) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown; 
                                                            {VT_8:0}const Caption: WideString): IAdapterImageWrapper; safecall;
    function  GetEventImage {Flags(1), (4/3) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown; 
                                                                 {VT_8:0}const Event: WideString; 
                                                                 {VT_8:0}const Caption: WideString): IAdapterImageWrapper; safecall;
    function  GetDisplayStyle {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_13:0}const Object_: IUnknown): WideString; safecall;
  end;

// *********************************************************************//
// DispIntf:  IImageProducerWrapperDisp
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {128B1043-EF0A-4D1F-A9F7-84C2B5EB96C8}
// *********************************************************************//
  IImageProducerWrapperDisp = dispinterface
    ['{128B1043-EF0A-4D1F-A9F7-84C2B5EB96C8}']
    function  GetImage {Flags(2), (3/2) CC:0, INV:1, DBG:4}({VT_13:0}const Object_: IUnknown; 
                                                            {VT_8:0}const Caption: WideString): IAdapterImageWrapper; dispid 1;
    function  GetEventImage {Flags(2), (4/3) CC:0, INV:1, DBG:4}({VT_13:0}const Object_: IUnknown; 
                                                                 {VT_8:0}const Event: WideString; 
                                                                 {VT_8:0}const Caption: WideString): IAdapterImageWrapper; dispid 3;
    function  GetDisplayStyle {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_13:0}const Object_: IUnknown): WideString; dispid 4;
  end;

// *********************************************************************//
// The Class CoAdapterErrorsWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterErrorsWrapper exposed by              
// the CoClass AdapterErrorsWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterErrorsWrapper = class
    class function Create: IAdapterErrorsWrapper;
    class function CreateRemote(const MachineName: string): IAdapterErrorsWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterRecordsWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterRecordsWrapper exposed by              
// the CoClass AdapterRecordsWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterRecordsWrapper = class
    class function Create: IAdapterRecordsWrapper;
    class function CreateRemote(const MachineName: string): IAdapterRecordsWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterFieldWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterFieldWrapper exposed by              
// the CoClass AdapterFieldWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterFieldWrapper = class
    class function Create: IAdapterFieldWrapper;
    class function CreateRemote(const MachineName: string): IAdapterFieldWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterActionWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterActionWrapper exposed by              
// the CoClass AdapterActionWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterActionWrapper = class
    class function Create: IAdapterActionWrapper;
    class function CreateRemote(const MachineName: string): IAdapterActionWrapper;
  end;

// *********************************************************************//
// The Class CoComponentsWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IComponentsWrapper exposed by              
// the CoClass ComponentsWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoComponentsWrapper = class
    class function Create: IComponentsWrapper;
    class function CreateRemote(const MachineName: string): IComponentsWrapper;
  end;

// *********************************************************************//
// The Class CoEnumVariantWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IEnumVARIANT exposed by              
// the CoClass EnumVariantWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoEnumVariantWrapper = class
    class function Create: IEnumVARIANT;
    class function CreateRemote(const MachineName: string): IEnumVARIANT;
  end;

// *********************************************************************//
// The Class CoAdapterRecordWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterRecordWrapper exposed by              
// the CoClass AdapterRecordWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterRecordWrapper = class
    class function Create: IAdapterRecordWrapper;
    class function CreateRemote(const MachineName: string): IAdapterRecordWrapper;
  end;

// *********************************************************************//
// The Class CoResponseWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IResponseWrapper exposed by              
// the CoClass ResponseWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoResponseWrapper = class
    class function Create: IResponseWrapper;
    class function CreateRemote(const MachineName: string): IResponseWrapper;
  end;

// *********************************************************************//
// The Class CoHTMLItemsWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IHTMLItemsWrapper exposed by              
// the CoClass HTMLItemsWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoHTMLItemsWrapper = class
    class function Create: IHTMLItemsWrapper;
    class function CreateRemote(const MachineName: string): IHTMLItemsWrapper;
  end;

// *********************************************************************//
// The Class CoPageWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IPageWrapper exposed by              
// the CoClass PageWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoPageWrapper = class
    class function Create: IPageWrapper;
    class function CreateRemote(const MachineName: string): IPageWrapper;
  end;

// *********************************************************************//
// The Class CoModuleWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IModuleWrapper exposed by              
// the CoClass ModuleWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoModuleWrapper = class
    class function Create: IModuleWrapper;
    class function CreateRemote(const MachineName: string): IModuleWrapper;
  end;

// *********************************************************************//
// The Class CoModulesWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IModulesWrapper exposed by              
// the CoClass ModulesWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoModulesWrapper = class
    class function Create: IModulesWrapper;
    class function CreateRemote(const MachineName: string): IModulesWrapper;
  end;

// *********************************************************************//
// The Class CoProducerWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IProducerWrapper exposed by              
// the CoClass ProducerWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoProducerWrapper = class
    class function Create: IProducerWrapper;
    class function CreateRemote(const MachineName: string): IProducerWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterErrorWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterErrorWrapper exposed by              
// the CoClass AdapterErrorWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterErrorWrapper = class
    class function Create: IAdapterErrorWrapper;
    class function CreateRemote(const MachineName: string): IAdapterErrorWrapper;
  end;

// *********************************************************************//
// The Class CoPagesWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IPagesWrapper exposed by              
// the CoClass PagesWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoPagesWrapper = class
    class function Create: IPagesWrapper;
    class function CreateRemote(const MachineName: string): IPagesWrapper;
  end;

// *********************************************************************//
// The Class CoSessionWrapper provides a Create and CreateRemote method to          
// create instances of the default interface ISessionWrapper exposed by              
// the CoClass SessionWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoSessionWrapper = class
    class function Create: ISessionWrapper;
    class function CreateRemote(const MachineName: string): ISessionWrapper;
  end;

// *********************************************************************//
// The Class CoSessionIDWrapper provides a Create and CreateRemote method to          
// create instances of the default interface ISessionIDWrapper exposed by              
// the CoClass SessionIDWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoSessionIDWrapper = class
    class function Create: ISessionIDWrapper;
    class function CreateRemote(const MachineName: string): ISessionIDWrapper;
  end;

// *********************************************************************//
// The Class CoEndUserWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IEndUserWrapper exposed by              
// the CoClass EndUserWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoEndUserWrapper = class
    class function Create: IEndUserWrapper;
    class function CreateRemote(const MachineName: string): IEndUserWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterValuesListWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterValuesListWrapper exposed by              
// the CoClass AdapterValuesListWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterValuesListWrapper = class
    class function Create: IAdapterValuesListWrapper;
    class function CreateRemote(const MachineName: string): IAdapterValuesListWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterWrapper exposed by              
// the CoClass AdapterWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterWrapper = class
    class function Create: IAdapterWrapper;
    class function CreateRemote(const MachineName: string): IAdapterWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterImageWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterImageWrapper exposed by              
// the CoClass AdapterImageWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterImageWrapper = class
    class function Create: IAdapterImageWrapper;
    class function CreateRemote(const MachineName: string): IAdapterImageWrapper;
  end;

// *********************************************************************//
// The Class CoApplicationWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IApplicationWrapper exposed by              
// the CoClass ApplicationWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoApplicationWrapper = class
    class function Create: IApplicationWrapper;
    class function CreateRemote(const MachineName: string): IApplicationWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterFieldValuesWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterFieldValuesWrapper exposed by              
// the CoClass AdapterFieldValuesWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterFieldValuesWrapper = class
    class function Create: IAdapterFieldValuesWrapper;
    class function CreateRemote(const MachineName: string): IAdapterFieldValuesWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterHiddenFieldsWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterHiddenFieldsWrapper exposed by              
// the CoClass AdapterHiddenFieldsWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterHiddenFieldsWrapper = class
    class function Create: IAdapterHiddenFieldsWrapper;
    class function CreateRemote(const MachineName: string): IAdapterHiddenFieldsWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterHiddenFieldWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterHiddenFieldWrapper exposed by              
// the CoClass AdapterHiddenFieldWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterHiddenFieldWrapper = class
    class function Create: IAdapterHiddenFieldWrapper;
    class function CreateRemote(const MachineName: string): IAdapterHiddenFieldWrapper;
  end;

// *********************************************************************//
// The Class CoAdapterActionArrayWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IAdapterActionArrayWrapper exposed by              
// the CoClass AdapterActionArrayWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoAdapterActionArrayWrapper = class
    class function Create: IAdapterActionArrayWrapper;
    class function CreateRemote(const MachineName: string): IAdapterActionArrayWrapper;
  end;

// *********************************************************************//
// The Class CoRequestWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IRequestWrapper exposed by              
// the CoClass RequestWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoRequestWrapper = class
    class function Create: IRequestWrapper;
    class function CreateRemote(const MachineName: string): IRequestWrapper;
  end;

// *********************************************************************//
// The Class CoImageProducerWrapper provides a Create and CreateRemote method to          
// create instances of the default interface IImageProducerWrapper exposed by              
// the CoClass ImageProducerWrapper. The functions are intended to be used by             
// clients wishing to automate the CoClass objects exposed by the         
// server of this typelibrary.                                            
// *********************************************************************//
  CoImageProducerWrapper = class
    class function Create: IImageProducerWrapper;
    class function CreateRemote(const MachineName: string): IImageProducerWrapper;
  end;

implementation

uses ComObj;

class function CoAdapterErrorsWrapper.Create: IAdapterErrorsWrapper;
begin
  Result := CreateComObject(CLASS_AdapterErrorsWrapper) as IAdapterErrorsWrapper;
end;

class function CoAdapterErrorsWrapper.CreateRemote(const MachineName: string): IAdapterErrorsWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterErrorsWrapper) as IAdapterErrorsWrapper;
end;

class function CoAdapterRecordsWrapper.Create: IAdapterRecordsWrapper;
begin
  Result := CreateComObject(CLASS_AdapterRecordsWrapper) as IAdapterRecordsWrapper;
end;

class function CoAdapterRecordsWrapper.CreateRemote(const MachineName: string): IAdapterRecordsWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterRecordsWrapper) as IAdapterRecordsWrapper;
end;

class function CoAdapterFieldWrapper.Create: IAdapterFieldWrapper;
begin
  Result := CreateComObject(CLASS_AdapterFieldWrapper) as IAdapterFieldWrapper;
end;

class function CoAdapterFieldWrapper.CreateRemote(const MachineName: string): IAdapterFieldWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterFieldWrapper) as IAdapterFieldWrapper;
end;

class function CoAdapterActionWrapper.Create: IAdapterActionWrapper;
begin
  Result := CreateComObject(CLASS_AdapterActionWrapper) as IAdapterActionWrapper;
end;

class function CoAdapterActionWrapper.CreateRemote(const MachineName: string): IAdapterActionWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterActionWrapper) as IAdapterActionWrapper;
end;

class function CoComponentsWrapper.Create: IComponentsWrapper;
begin
  Result := CreateComObject(CLASS_ComponentsWrapper) as IComponentsWrapper;
end;

class function CoComponentsWrapper.CreateRemote(const MachineName: string): IComponentsWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_ComponentsWrapper) as IComponentsWrapper;
end;

class function CoEnumVariantWrapper.Create: IEnumVARIANT;
begin
  Result := CreateComObject(CLASS_EnumVariantWrapper) as IEnumVARIANT;
end;

class function CoEnumVariantWrapper.CreateRemote(const MachineName: string): IEnumVARIANT;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_EnumVariantWrapper) as IEnumVARIANT;
end;

class function CoAdapterRecordWrapper.Create: IAdapterRecordWrapper;
begin
  Result := CreateComObject(CLASS_AdapterRecordWrapper) as IAdapterRecordWrapper;
end;

class function CoAdapterRecordWrapper.CreateRemote(const MachineName: string): IAdapterRecordWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterRecordWrapper) as IAdapterRecordWrapper;
end;

class function CoResponseWrapper.Create: IResponseWrapper;
begin
  Result := CreateComObject(CLASS_ResponseWrapper) as IResponseWrapper;
end;

class function CoResponseWrapper.CreateRemote(const MachineName: string): IResponseWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_ResponseWrapper) as IResponseWrapper;
end;

class function CoHTMLItemsWrapper.Create: IHTMLItemsWrapper;
begin
  Result := CreateComObject(CLASS_HTMLItemsWrapper) as IHTMLItemsWrapper;
end;

class function CoHTMLItemsWrapper.CreateRemote(const MachineName: string): IHTMLItemsWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_HTMLItemsWrapper) as IHTMLItemsWrapper;
end;

class function CoPageWrapper.Create: IPageWrapper;
begin
  Result := CreateComObject(CLASS_PageWrapper) as IPageWrapper;
end;

class function CoPageWrapper.CreateRemote(const MachineName: string): IPageWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_PageWrapper) as IPageWrapper;
end;

class function CoModuleWrapper.Create: IModuleWrapper;
begin
  Result := CreateComObject(CLASS_ModuleWrapper) as IModuleWrapper;
end;

class function CoModuleWrapper.CreateRemote(const MachineName: string): IModuleWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_ModuleWrapper) as IModuleWrapper;
end;

class function CoModulesWrapper.Create: IModulesWrapper;
begin
  Result := CreateComObject(CLASS_ModulesWrapper) as IModulesWrapper;
end;

class function CoModulesWrapper.CreateRemote(const MachineName: string): IModulesWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_ModulesWrapper) as IModulesWrapper;
end;

class function CoProducerWrapper.Create: IProducerWrapper;
begin
  Result := CreateComObject(CLASS_ProducerWrapper) as IProducerWrapper;
end;

class function CoProducerWrapper.CreateRemote(const MachineName: string): IProducerWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_ProducerWrapper) as IProducerWrapper;
end;

class function CoAdapterErrorWrapper.Create: IAdapterErrorWrapper;
begin
  Result := CreateComObject(CLASS_AdapterErrorWrapper) as IAdapterErrorWrapper;
end;

class function CoAdapterErrorWrapper.CreateRemote(const MachineName: string): IAdapterErrorWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterErrorWrapper) as IAdapterErrorWrapper;
end;

class function CoPagesWrapper.Create: IPagesWrapper;
begin
  Result := CreateComObject(CLASS_PagesWrapper) as IPagesWrapper;
end;

class function CoPagesWrapper.CreateRemote(const MachineName: string): IPagesWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_PagesWrapper) as IPagesWrapper;
end;

class function CoSessionWrapper.Create: ISessionWrapper;
begin
  Result := CreateComObject(CLASS_SessionWrapper) as ISessionWrapper;
end;

class function CoSessionWrapper.CreateRemote(const MachineName: string): ISessionWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_SessionWrapper) as ISessionWrapper;
end;

class function CoSessionIDWrapper.Create: ISessionIDWrapper;
begin
  Result := CreateComObject(CLASS_SessionIDWrapper) as ISessionIDWrapper;
end;

class function CoSessionIDWrapper.CreateRemote(const MachineName: string): ISessionIDWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_SessionIDWrapper) as ISessionIDWrapper;
end;

class function CoEndUserWrapper.Create: IEndUserWrapper;
begin
  Result := CreateComObject(CLASS_EndUserWrapper) as IEndUserWrapper;
end;

class function CoEndUserWrapper.CreateRemote(const MachineName: string): IEndUserWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_EndUserWrapper) as IEndUserWrapper;
end;

class function CoAdapterValuesListWrapper.Create: IAdapterValuesListWrapper;
begin
  Result := CreateComObject(CLASS_AdapterValuesListWrapper) as IAdapterValuesListWrapper;
end;

class function CoAdapterValuesListWrapper.CreateRemote(const MachineName: string): IAdapterValuesListWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterValuesListWrapper) as IAdapterValuesListWrapper;
end;

class function CoAdapterWrapper.Create: IAdapterWrapper;
begin
  Result := CreateComObject(CLASS_AdapterWrapper) as IAdapterWrapper;
end;

class function CoAdapterWrapper.CreateRemote(const MachineName: string): IAdapterWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterWrapper) as IAdapterWrapper;
end;

class function CoAdapterImageWrapper.Create: IAdapterImageWrapper;
begin
  Result := CreateComObject(CLASS_AdapterImageWrapper) as IAdapterImageWrapper;
end;

class function CoAdapterImageWrapper.CreateRemote(const MachineName: string): IAdapterImageWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterImageWrapper) as IAdapterImageWrapper;
end;

class function CoApplicationWrapper.Create: IApplicationWrapper;
begin
  Result := CreateComObject(CLASS_ApplicationWrapper) as IApplicationWrapper;
end;

class function CoApplicationWrapper.CreateRemote(const MachineName: string): IApplicationWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_ApplicationWrapper) as IApplicationWrapper;
end;

class function CoAdapterFieldValuesWrapper.Create: IAdapterFieldValuesWrapper;
begin
  Result := CreateComObject(CLASS_AdapterFieldValuesWrapper) as IAdapterFieldValuesWrapper;
end;

class function CoAdapterFieldValuesWrapper.CreateRemote(const MachineName: string): IAdapterFieldValuesWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterFieldValuesWrapper) as IAdapterFieldValuesWrapper;
end;

class function CoAdapterHiddenFieldsWrapper.Create: IAdapterHiddenFieldsWrapper;
begin
  Result := CreateComObject(CLASS_AdapterHiddenFieldsWrapper) as IAdapterHiddenFieldsWrapper;
end;

class function CoAdapterHiddenFieldsWrapper.CreateRemote(const MachineName: string): IAdapterHiddenFieldsWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterHiddenFieldsWrapper) as IAdapterHiddenFieldsWrapper;
end;

class function CoAdapterHiddenFieldWrapper.Create: IAdapterHiddenFieldWrapper;
begin
  Result := CreateComObject(CLASS_AdapterHiddenFieldWrapper) as IAdapterHiddenFieldWrapper;
end;

class function CoAdapterHiddenFieldWrapper.CreateRemote(const MachineName: string): IAdapterHiddenFieldWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterHiddenFieldWrapper) as IAdapterHiddenFieldWrapper;
end;

class function CoAdapterActionArrayWrapper.Create: IAdapterActionArrayWrapper;
begin
  Result := CreateComObject(CLASS_AdapterActionArrayWrapper) as IAdapterActionArrayWrapper;
end;

class function CoAdapterActionArrayWrapper.CreateRemote(const MachineName: string): IAdapterActionArrayWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_AdapterActionArrayWrapper) as IAdapterActionArrayWrapper;
end;

class function CoRequestWrapper.Create: IRequestWrapper;
begin
  Result := CreateComObject(CLASS_RequestWrapper) as IRequestWrapper;
end;

class function CoRequestWrapper.CreateRemote(const MachineName: string): IRequestWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_RequestWrapper) as IRequestWrapper;
end;

class function CoImageProducerWrapper.Create: IImageProducerWrapper;
begin
  Result := CreateComObject(CLASS_ImageProducerWrapper) as IImageProducerWrapper;
end;

class function CoImageProducerWrapper.CreateRemote(const MachineName: string): IImageProducerWrapper;
begin
  Result := CreateRemoteComObject(MachineName, CLASS_ImageProducerWrapper) as IImageProducerWrapper;
end;

end.
