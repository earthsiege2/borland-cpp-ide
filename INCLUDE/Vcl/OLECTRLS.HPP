// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OleCtrls.pas' rev: 6.00

#ifndef OleCtrlsHPP
#define OleCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <AxCtrls.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Olectrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TEventDispatch;
class DELPHICLASS TOleControl;
struct TControlData;
typedef TControlData *PControlData;

class DELPHICLASS TEnumPropDesc;
class PASCALIMPLEMENTATION TOleControl : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	TControlData *FControlData;
	int FRefCount;
	TEventDispatch* FEventDispatch;
	unsigned FObjectData;
	_di_IOleObject FOleObject;
	_di_IPersistStreamInit FPersistStream;
	_di_IOleControl FOleControl;
	_di_IDispatch FControlDispatch;
	_di_IPerPropertyBrowsing FPropBrowsing;
	_di_IOleInPlaceObject FOleInPlaceObject;
	_di_IOleInPlaceActiveObject FOleInPlaceActiveObject;
	int FPropConnection;
	int FEventsConnection;
	int FMiscStatus;
	Classes::TList* FFonts;
	Classes::TList* FPictures;
	bool FUpdatingPictures;
	bool FUpdatingColor;
	bool FUpdatingFont;
	bool FUpdatingEnabled;
	void __fastcall CreateControl(void);
	void __fastcall CreateEnumPropDescs(void);
	void __fastcall CreateInstance(void);
	void __fastcall CreateStorage(void);
	void __fastcall DesignModified(void);
	void __fastcall DestroyControl(void);
	void __fastcall DestroyEnumPropDescs(void);
	void __fastcall DestroyStorage(void);
	void __fastcall GetEventMethod(int DispID, System::TMethod &Method);
	Menus::TMainMenu* __fastcall GetMainMenu(void);
	Variant __fastcall GetOleObject();
	_di_IDispatch __fastcall GetDefaultDispatch();
	void __fastcall HookControlWndProc(void);
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall SetUIActive(bool Active);
	void __fastcall WriteData(Classes::TStream* Stream);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Messages::TWMPaint &Message);
	MESSAGE void __fastcall CMDocWindowActivate(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDialogKey(Messages::TMessage &Message);
	MESSAGE void __fastcall CMUIActivate(Messages::TMessage &Message);
	MESSAGE void __fastcall CMUIDeactivate(Messages::TMessage &Message);
	void __fastcall D2InvokeEvent(int DispID, tagDISPPARAMS &Params);
	
protected:
	virtual void __fastcall StandardEvent(int DispID, tagDISPPARAMS &Params);
	virtual void __fastcall InvokeEvent(int DispID, tagDISPPARAMS &Params);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	HRESULT __stdcall SaveObject(void);
	HRESULT __stdcall GetMoniker(int dwAssign, int dwWhichMoniker, /* out */ _di_IMoniker &mk);
	HRESULT __stdcall GetContainer(/* out */ _di_IOleContainer &container);
	HRESULT __stdcall ShowObject(void);
	HRESULT __stdcall OnShowWindow(BOOL fShow);
	HRESULT __stdcall RequestNewObjectLayout(void);
	HRESULT __stdcall OnControlInfoChanged(void);
	HRESULT __stdcall LockInPlaceActive(BOOL fLock);
	HRESULT __stdcall GetExtendedControl(/* out */ _di_IDispatch &disp);
	HRESULT __stdcall TransformCoords(Types::TPoint &ptlHimetric, tagPOINTF &ptfContainer, int flags);
	HRESULT __stdcall OleControlSite_TranslateAccelerator(Windows::PMsg msg, int grfModifiers);
	HRESULT __stdcall OnFocus(BOOL fGotFocus);
	HRESULT __stdcall ShowPropertyFrame(void);
	HRESULT __stdcall ContextSensitiveHelp(BOOL fEnterMode);
	HRESULT __stdcall OleInPlaceSite_GetWindow(/* out */ HWND &wnd);
	HRESULT __stdcall CanInPlaceActivate(void);
	HRESULT __stdcall OnInPlaceActivate(void);
	HRESULT __stdcall OnUIActivate(void);
	HRESULT __stdcall GetWindowContext(/* out */ _di_IOleInPlaceFrame &frame, /* out */ _di_IOleInPlaceUIWindow &doc, /* out */ Types::TRect &rcPosRect, /* out */ Types::TRect &rcClipRect, /* out */ tagOIFI &frameInfo);
	HRESULT __stdcall Scroll(const Types::TPoint scrollExtent);
	HRESULT __stdcall OnUIDeactivate(BOOL fUndoable);
	HRESULT __stdcall OnInPlaceDeactivate(void);
	HRESULT __stdcall DiscardUndoState(void);
	HRESULT __stdcall DeactivateAndUndo(void);
	HRESULT __stdcall OnPosRectChange(const Types::TRect &rcPosRect);
	HRESULT __stdcall GetBorder(/* out */ Types::TRect &rectBorder);
	HRESULT __stdcall RequestBorderSpace(const Types::TRect &borderwidths);
	HRESULT __stdcall SetBorderSpace(Types::PRect pborderwidths);
	HRESULT __stdcall SetActiveObject(const _di_IOleInPlaceActiveObject activeObject, wchar_t * pszObjName);
	HRESULT __stdcall OleInPlaceFrame_GetWindow(/* out */ HWND &wnd);
	HRESULT __stdcall InsertMenus(HMENU hmenuShared, tagOleMenuGroupWidths &menuWidths);
	HRESULT __stdcall SetMenu(HMENU hmenuShared, HMENU holemenu, HWND hwndActiveObject);
	HRESULT __stdcall RemoveMenus(HMENU hmenuShared);
	HRESULT __stdcall SetStatusText(wchar_t * pszStatusText);
	HRESULT __stdcall EnableModeless(BOOL fEnable);
	HRESULT __stdcall OleInPlaceFrame_TranslateAccelerator(tagMSG &msg, Word wID);
	HIDESBASE HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HIDESBASE HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HIDESBASE HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	HIDESBASE HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	HRESULT __stdcall PreMessageFilter(HWND wnd, int msg, int wp, int lp, /* out */ int &res, /* out */ int &Cookie);
	HRESULT __stdcall PostMessageFilter(HWND wnd, int msg, int wp, int lp, /* out */ int &res, int Cookie);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DestroyWindowHandle(void);
	Byte __fastcall GetByteProp(int Index);
	Graphics::TColor __fastcall GetColorProp(int Index);
	Graphics::TColor __fastcall GetTColorProp(int Index);
	System::Comp __fastcall GetCompProp(int Index);
	System::Currency __fastcall GetCurrencyProp(int Index);
	double __fastcall GetDoubleProp(int Index);
	_di_IDispatch __fastcall GetIDispatchProp(int Index);
	int __fastcall GetIntegerProp(int Index);
	System::_di_IInterface __fastcall GetIUnknownProp(int Index);
	Word __fastcall GetWordBoolProp(int Index);
	System::TDateTime __fastcall GetTDateTimeProp(int Index);
	Graphics::TFont* __fastcall GetTFontProp(int Index);
	Word __fastcall GetOleBoolProp(int Index);
	double __fastcall GetOleDateProp(int Index);
	Activex::TOleEnum __fastcall GetOleEnumProp(int Index);
	Activex::TOleEnum __fastcall GetTOleEnumProp(int Index);
	OleVariant __fastcall GetOleVariantProp(int Index);
	Graphics::TPicture* __fastcall GetTPictureProp(int Index);
	void __fastcall GetProperty(int Index, TVarData &Value);
	Shortint __fastcall GetShortIntProp(int Index);
	float __fastcall GetSingleProp(int Index);
	short __fastcall GetSmallintProp(int Index);
	AnsiString __fastcall GetStringProp(int Index);
	Variant __fastcall GetVariantProp(int Index);
	WideString __fastcall GetWideStringProp(int Index);
	Word __fastcall GetWordProp(int Index);
	virtual void __fastcall InitControlData(void) = 0 ;
	virtual void __fastcall InitControlInterface(const System::_di_IInterface Obj);
	void __fastcall InvokeMethod(const void *DispInfo, void * Result);
	DYNAMIC bool __fastcall PaletteChanged(bool Foreground);
	void __fastcall PictureChanged(System::TObject* Sender);
	void __fastcall SetByteProp(int Index, Byte Value);
	void __fastcall SetColorProp(int Index, Graphics::TColor Value);
	void __fastcall SetTColorProp(int Index, Graphics::TColor Value);
	void __fastcall SetCompProp(int Index, const System::Comp Value);
	void __fastcall SetCurrencyProp(int Index, const System::Currency Value);
	void __fastcall SetDoubleProp(int Index, const double Value);
	void __fastcall SetIDispatchProp(int Index, const _di_IDispatch Value);
	void __fastcall SetIntegerProp(int Index, int Value);
	void __fastcall SetIUnknownProp(int Index, const System::_di_IInterface Value);
	virtual void __fastcall SetName(const AnsiString Value);
	void __fastcall SetWordBoolProp(int Index, Word Value);
	void __fastcall SetTDateTimeProp(int Index, const System::TDateTime Value);
	void __fastcall SetTFontProp(int Index, Graphics::TFont* Value);
	void __fastcall SetOleBoolProp(int Index, Word Value);
	void __fastcall SetOleDateProp(int Index, const double Value);
	void __fastcall SetOleEnumProp(int Index, Activex::TOleEnum Value);
	void __fastcall SetTOleEnumProp(int Index, Activex::TOleEnum Value);
	void __fastcall SetOleVariantProp(int Index, const OleVariant &Value);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	void __fastcall SetTPictureProp(int Index, Graphics::TPicture* Value);
	void __fastcall SetProperty(int Index, const TVarData &Value);
	void __fastcall SetShortIntProp(int Index, Shortint Value);
	void __fastcall SetSingleProp(int Index, const float Value);
	void __fastcall SetSmallintProp(int Index, short Value);
	void __fastcall SetStringProp(int Index, const AnsiString Value);
	void __fastcall SetVariantProp(int Index, const Variant &Value);
	void __fastcall SetWideStringProp(int Index, const WideString Value);
	void __fastcall SetWordProp(int Index, Word Value);
	void __fastcall _SetColorProp(int Index, Graphics::TColor Value);
	void __fastcall _SetTColorProp(int Index, Graphics::TColor Value);
	void __fastcall _SetTOleEnumProp(int Index, Activex::TOleEnum Value);
	void __fastcall _SetTFontProp(int Index, Graphics::TFont* Value);
	void __fastcall _SetTPictureProp(int Index, Graphics::TPicture* Value);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	virtual bool __fastcall SuppressException(Sysutils::Exception* E);
	__property PControlData ControlData = {read=FControlData, write=FControlData};
	virtual HRESULT __stdcall OnChanged(int dispid);
	virtual HRESULT __stdcall OnRequestEdit(int dispid);
	
public:
	__fastcall virtual TOleControl(Classes::TComponent* AOwner);
	__fastcall virtual ~TOleControl(void);
	void __fastcall BrowseProperties(void);
	virtual void __fastcall DefaultHandler(void *Message);
	void __fastcall DoObjectVerb(int Verb);
	TEnumPropDesc* __fastcall GetEnumPropDesc(int DispID);
	bool __fastcall GetHelpContext(AnsiString Member, int &HelpCtx, AnsiString &HelpFile);
	void __fastcall GetObjectVerbs(Classes::TStrings* List);
	AnsiString __fastcall GetPropDisplayString(int DispID);
	void __fastcall GetPropDisplayStrings(int DispID, Classes::TStrings* List);
	bool __fastcall IsCustomProperty(int DispID);
	bool __fastcall IsPropPageProperty(int DispID);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	void __fastcall SetPropDisplayString(int DispID, const AnsiString Value);
	void __fastcall ShowAboutBox(void);
	__property Variant OleObject = {read=GetOleObject};
	__property _di_IPerPropertyBrowsing PerPropBrowsing = {read=FPropBrowsing};
	__property _di_IDispatch DefaultDispatch = {read=GetDefaultDispatch};
	__property TabStop  = {default=1};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TOleControl(HWND ParentWindow) : Controls::TWinControl(ParentWindow) { }
	#pragma option pop
	
private:
	void *__IOleClientSite;	/* IOleClientSite */
	void *__IOleControlSite;	/* IOleControlSite [TranslateAccelerator=OleControlSite_TranslateAccelerator] */
	void *__IOleInPlaceSite;	/* IOleInPlaceSite [GetWindow=OleInPlaceSite_GetWindow] */
	void *__IOleInPlaceFrame;	/* IOleInPlaceFrame [TranslateAccelerator=OleInPlaceFrame_TranslateAccelerator, GetWindow=OleInPlaceFrame_GetWindow] */
	void *__IDispatch;	/* IDispatch */
	void *__IPropertyNotifySink;	/* IPropertyNotifySink */
	void *__ISimpleFrameSite;	/* ISimpleFrameSite */
	
public:
	operator ISimpleFrameSite*(void) { return (ISimpleFrameSite*)&__ISimpleFrameSite; }
	operator IPropertyNotifySink*(void) { return (IPropertyNotifySink*)&__IPropertyNotifySink; }
	operator IDispatch*(void) { return (IDispatch*)&__IDispatch; }
	operator IOleInPlaceFrame*(void) { return (IOleInPlaceFrame*)&__IOleInPlaceFrame; }
	operator IOleInPlaceSite*(void) { return (IOleInPlaceSite*)&__IOleInPlaceSite; }
	operator IOleControlSite*(void) { return (IOleControlSite*)&__IOleControlSite; }
	operator IOleClientSite*(void) { return (IOleClientSite*)&__IOleClientSite; }
	operator IInterface*(void) { return (IInterface*)&__ISimpleFrameSite; }
	
};


class PASCALIMPLEMENTATION TEventDispatch : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TOleControl* FControl;
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	__property TOleControl* Control = {read=FControl};
	
public:
	__fastcall TEventDispatch(TOleControl* Control);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TEventDispatch(void) { }
	#pragma option pop
	
private:
	void *__IDispatch;	/* IDispatch */
	
public:
	operator IDispatch*(void) { return (IDispatch*)&__IDispatch; }
	operator IInterface*(void) { return (IInterface*)&__IDispatch; }
	
};


#pragma pack(push, 4)
struct TEnumValue
{
	int Value;
	AnsiString Ident;
} ;
#pragma pack(pop)

typedef TEnumValue TEnumValueList[32768];

typedef TEnumValue *PEnumValueList;

class PASCALIMPLEMENTATION TEnumPropDesc : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FDispID;
	int FValueCount;
	TEnumValue *FValues;
	
public:
	__fastcall TEnumPropDesc(int DispID, int ValueCount, const _di_ITypeInfo TypeInfo);
	__fastcall virtual ~TEnumPropDesc(void);
	void __fastcall GetStrings(Classes::TGetStrProc Proc);
	int __fastcall StringToValue(const AnsiString S);
	AnsiString __fastcall ValueToString(int V);
};


#pragma pack(push, 4)
struct TControlData
{
	GUID ClassID;
	GUID EventIID;
	int EventCount;
	void *EventDispIDs;
	void *LicenseKey;
	unsigned Flags;
	int Version;
	int FontCount;
	int *FontIDs;
	int PictureCount;
	int *PictureIDs;
	int Reserved;
	int InstanceCount;
	Classes::TList* EnumPropDescs;
} ;
#pragma pack(pop)

struct TControlData2;
typedef TControlData2 *PControlData2;

#pragma pack(push, 4)
struct TControlData2
{
	GUID ClassID;
	GUID EventIID;
	int EventCount;
	void *EventDispIDs;
	void *LicenseKey;
	unsigned Flags;
	int Version;
	int FontCount;
	int *FontIDs;
	int PictureCount;
	int *PictureIDs;
	int Reserved;
	int InstanceCount;
	Classes::TList* EnumPropDescs;
	unsigned FirstEventOfs;
} ;
#pragma pack(pop)

class DELPHICLASS EOleCtrlError;
class PASCALIMPLEMENTATION EOleCtrlError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EOleCtrlError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOleCtrlError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOleCtrlError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOleCtrlError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOleCtrlError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOleCtrlError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOleCtrlError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOleCtrlError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOleCtrlError(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE OleVariant EmptyParam;
extern PACKAGE Variant __fastcall FontToOleFont(Graphics::TFont* Font);
extern PACKAGE void __fastcall OleFontToFont(const Variant &OleFont, Graphics::TFont* Font);

}	/* namespace Olectrls */
using namespace Olectrls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OleCtrls
