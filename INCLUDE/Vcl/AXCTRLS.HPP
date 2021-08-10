// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'AxCtrls.pas' rev: 5.00

#ifndef AxCtrlsHPP
#define AxCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <StdVCL.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

#include <objsafe.h>
#include <ocidl.h>


namespace Axctrls
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TOleStream;
class PASCALIMPLEMENTATION TOleStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	_di_IStream FStream;
	
protected:
	_di_IStream __fastcall GetIStream();
	
public:
	__fastcall TOleStream(const _di_IStream Stream);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOleStream(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TDefinePropertyPage)(const GUID &GUID);

__dispinterface IAmbientDispatch;
typedef System::DelphiInterface<IAmbientDispatch> _di_IAmbientDispatch;
__dispinterface INTERFACE_UUID("{00020400-0000-0000-C000-000000000046}") IAmbientDispatch  : public IDispatch 
	
{
	
};

class DELPHICLASS TPropertyPage;
class DELPHICLASS TPropertyPageImpl;
class PASCALIMPLEMENTATION TPropertyPageImpl : public Comobj::TAggregatedObject 
{
	typedef Comobj::TAggregatedObject inherited;
	
private:
	TPropertyPage* FPropertyPage;
	_di_IPropertyPageSite FPageSite;
	bool FActive;
	bool FModified;
	void __fastcall Modified(void);
	
protected:
	HRESULT __stdcall SetPageSite(const _di_IPropertyPageSite pageSite);
	HRESULT __stdcall Activate(HWND hwndParent, const Windows::TRect &rc, BOOL bModal);
	HRESULT __stdcall Deactivate(void);
	HRESULT __stdcall GetPageInfo(/* out */ tagPROPPAGEINFO &pageInfo);
	HRESULT __stdcall SetObjects(int cObjects, Activex::PUnknownList pUnkList);
	HRESULT __stdcall Show(int nCmdShow);
	HRESULT __stdcall Move(const Windows::TRect &rect);
	HRESULT __stdcall IsPageDirty(void);
	HRESULT __stdcall Apply(void);
	HRESULT __stdcall Help(wchar_t * pszHelpDir);
	HRESULT __stdcall TranslateAccelerator(Windows::PMsg msg);
	HRESULT __stdcall EditProperty(int dispid);
	
public:
	virtual void __fastcall InitPropertyPage(void);
	__property TPropertyPage* PropertyPage = {read=FPropertyPage, write=FPropertyPage};
public:
	#pragma option push -w-inl
	/* TAggregatedObject.Create */ inline __fastcall TPropertyPageImpl(_di_IUnknown Controller) : Comobj::TAggregatedObject(
		Controller) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TPropertyPageImpl(void) { }
	#pragma option pop
	
private:
	void *__IPropertyPage2;	/* IPropertyPage2 */
	
public:
	operator IPropertyPage2*(void) { return (IPropertyPage2*)&__IPropertyPage2; }
	operator IPropertyPage*(void) { return (IPropertyPage*)&__IPropertyPage2; }
	operator IUnknown*(void) { return (IUnknown*)&__IPropertyPage2; }
	
};


class PASCALIMPLEMENTATION TPropertyPage : public Forms::TCustomForm 
{
	typedef Forms::TCustomForm inherited;
	
private:
	TPropertyPageImpl* FActiveXPropertyPage;
	OleVariant FOleObject;
	Classes::TInterfaceList* FOleObjects;
	HIDESBASE MESSAGE void __fastcall CMChanged(Controls::TCMChanged &Msg);
	
public:
	__fastcall virtual TPropertyPage(Classes::TComponent* AOwner);
	__fastcall virtual ~TPropertyPage(void);
	void __fastcall Modified(void);
	virtual void __fastcall UpdateObject(void);
	virtual void __fastcall UpdatePropertyPage(void);
	__property OleVariant OleObject = {read=FOleObject};
	__property Classes::TInterfaceList* OleObjects = {read=FOleObjects, write=FOleObjects};
	void __fastcall EnumCtlProps(const GUID &PropType, Classes::TStrings* PropNames);
	
__published:
	__property ActiveControl ;
	__property AutoScroll ;
	__property Caption ;
	__property ClientHeight ;
	__property ClientWidth ;
	__property Ctl3D ;
	__property Color ;
	__property Enabled ;
	__property Font ;
	__property Height ;
	__property HorzScrollBar ;
	__property OldCreateOrder ;
	__property KeyPreview ;
	__property PixelsPerInch ;
	__property ParentFont ;
	__property PopupMenu ;
	__property PrintScale ;
	__property Scaled ;
	__property ShowHint ;
	__property VertScrollBar ;
	__property Visible ;
	__property Width ;
	__property OnActivate ;
	__property OnClick ;
	__property OnClose ;
	__property OnContextPopup ;
	__property OnCreate ;
	__property OnDblClick ;
	__property OnDestroy ;
	__property OnDeactivate ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnHide ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnPaint ;
	__property OnResize ;
	__property OnShow ;
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPropertyPage(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TCustomForm(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPropertyPage(HWND ParentWindow) : Forms::TCustomForm(
		ParentWindow) { }
	#pragma option pop
	
};


typedef TMetaClass*TPropertyPageClass;

class DELPHICLASS TCustomAdapter;
class PASCALIMPLEMENTATION TCustomAdapter : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_IUnknown FOleObject;
	int FConnection;
	_di_IUnknown FNotifier;
	
protected:
	bool Updating;
	virtual void __fastcall Changed(void);
	void __fastcall ConnectOleObject(_di_IUnknown OleObject);
	void __fastcall ReleaseOleObject(void);
	virtual void __fastcall Update(void) = 0 ;
	
public:
	__fastcall TCustomAdapter(void);
	__fastcall virtual ~TCustomAdapter(void);
};


class DELPHICLASS TAdapterNotifier;
class PASCALIMPLEMENTATION TAdapterNotifier : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	TCustomAdapter* FAdapter;
	
protected:
	HRESULT __stdcall OnChanged(int dispid);
	HRESULT __stdcall OnRequestEdit(int dispid);
	
public:
	__fastcall TAdapterNotifier(TCustomAdapter* Adapter);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TAdapterNotifier(void) { }
	#pragma option pop
	
private:
	void *__IPropertyNotifySink;	/* IPropertyNotifySink */
	
public:
	operator IPropertyNotifySink*(void) { return (IPropertyNotifySink*)&__IPropertyNotifySink; }
	
};


__interface IFontAccess;
typedef System::DelphiInterface<IFontAccess> _di_IFontAccess;
__interface INTERFACE_UUID("{CBA55CA0-0E57-11D0-BD2F-0020AF0E5B81}") IFontAccess  : public IUnknown 
	
{
	
public:
	virtual void __fastcall GetOleFont(_di_IFontDisp &OleFont) = 0 ;
	virtual void __fastcall SetOleFont(const _di_IFontDisp OleFont) = 0 ;
};

class DELPHICLASS TFontAdapter;
class PASCALIMPLEMENTATION TFontAdapter : public TCustomAdapter 
{
	typedef TCustomAdapter inherited;
	
private:
	Graphics::TFont* FFont;
	
protected:
	void __fastcall GetOleFont(_di_IFontDisp &OleFont);
	void __fastcall SetOleFont(const _di_IFontDisp OleFont);
	virtual void __fastcall Changed(void);
	virtual void __fastcall Update(void);
	
public:
	__fastcall TFontAdapter(Graphics::TFont* Font);
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TFontAdapter(void) { }
	#pragma option pop
	
private:
	void *__IChangeNotifier;	/* Graphics::IChangeNotifier */
	void *__IFontAccess;	/* Axctrls::IFontAccess */
	
public:
	operator IFontAccess*(void) { return (IFontAccess*)&__IFontAccess; }
	operator IChangeNotifier*(void) { return (IChangeNotifier*)&__IChangeNotifier; }
	
};


__interface IPictureAccess;
typedef System::DelphiInterface<IPictureAccess> _di_IPictureAccess;
__interface INTERFACE_UUID("{795D4D31-43D7-11D0-9E92-0020AF3D82DA}") IPictureAccess  : public IUnknown 
	
{
	
public:
	virtual void __fastcall GetOlePicture(_di_IPictureDisp &OlePicture) = 0 ;
	virtual void __fastcall SetOlePicture(const _di_IPictureDisp OlePicture) = 0 ;
};

class DELPHICLASS TPictureAdapter;
class PASCALIMPLEMENTATION TPictureAdapter : public TCustomAdapter 
{
	typedef TCustomAdapter inherited;
	
private:
	Graphics::TPicture* FPicture;
	
protected:
	void __fastcall GetOlePicture(_di_IPictureDisp &OlePicture);
	void __fastcall SetOlePicture(const _di_IPictureDisp OlePicture);
	virtual void __fastcall Update(void);
	
public:
	__fastcall TPictureAdapter(Graphics::TPicture* Picture);
public:
	#pragma option push -w-inl
	/* TCustomAdapter.Destroy */ inline __fastcall virtual ~TPictureAdapter(void) { }
	#pragma option pop
	
private:
	void *__IChangeNotifier;	/* Graphics::IChangeNotifier */
	void *__IPictureAccess;	/* Axctrls::IPictureAccess */
	
public:
	operator IPictureAccess*(void) { return (IPictureAccess*)&__IPictureAccess; }
	operator IChangeNotifier*(void) { return (IChangeNotifier*)&__IChangeNotifier; }
	
};


class DELPHICLASS TOleGraphic;
class PASCALIMPLEMENTATION TOleGraphic : public Graphics::TGraphic 
{
	typedef Graphics::TGraphic inherited;
	
private:
	_di_IPicture FPicture;
	int __fastcall GetMMHeight(void);
	int __fastcall GetMMWidth(void);
	
protected:
	virtual void __fastcall Changed(System::TObject* Sender);
	virtual void __fastcall Draw(Graphics::TCanvas* ACanvas, const Windows::TRect &Rect);
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual HPALETTE __fastcall GetPalette(void);
	virtual bool __fastcall GetTransparent(void);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetPalette(HPALETTE Value);
	virtual void __fastcall SetWidth(int Value);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall LoadFromFile(const AnsiString Filename);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette);
	virtual void __fastcall SaveToClipboardFormat(Word &AFormat, unsigned &AData, HPALETTE &APalette);
	__property int MMHeight = {read=GetMMHeight, nodefault};
	__property int MMWidth = {read=GetMMWidth, nodefault};
	__property _di_IPicture Picture = {read=FPicture, write=FPicture};
protected:
	#pragma option push -w-inl
	/* TGraphic.Create */ inline __fastcall virtual TOleGraphic(void) : Graphics::TGraphic() { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TOleGraphic(void) { }
	#pragma option pop
	
};


class DELPHICLASS TStringsAdapter;
class PASCALIMPLEMENTATION TStringsAdapter : public Comobj::TAutoIntfObject 
{
	typedef Comobj::TAutoIntfObject inherited;
	
private:
	Classes::TStrings* FStrings;
	
protected:
	void __fastcall ReferenceStrings(Classes::TStrings* S);
	void __fastcall ReleaseStrings(void);
	HRESULT __safecall Get_ControlDefault(int Index, OleVariant &Get_ControlDefault_result);
	HRESULT __safecall Set_ControlDefault(int Index, const OleVariant Value);
	HRESULT __safecall Count(int &Count_result);
	HRESULT __safecall Get_Item(int Index, OleVariant &Get_Item_result);
	HRESULT __safecall Set_Item(int Index, const OleVariant Value);
	HRESULT __safecall Remove(int Index);
	HRESULT __safecall Clear(void);
	HRESULT __safecall Add(const OleVariant Item, int &Add_result);
	HRESULT __safecall _NewEnum(_di_IUnknown &_NewEnum_result);
	
public:
	__fastcall TStringsAdapter(Classes::TStrings* Strings);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TStringsAdapter(void) { }
	#pragma option pop
	
private:
	void *__IStrings;	/* Stdvcl::IStrings */
	void *__IStringsAdapter;	/* Classes::IStringsAdapter */
	
public:
	operator IStringsAdapter*(void) { return (IStringsAdapter*)&__IStringsAdapter; }
	operator IStrings*(void) { return (IStrings*)&__IStrings; }
	
};


class DELPHICLASS TReflectorWindow;
class PASCALIMPLEMENTATION TReflectorWindow : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	Controls::TControl* FControl;
	bool FInSize;
	MESSAGE void __fastcall WMGetDlgCode(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	
public:
	__fastcall TReflectorWindow(HWND ParentWindow, Controls::TControl* Control);
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TReflectorWindow(HWND ParentWindow) : Controls::TWinControl(
		ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TReflectorWindow(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID Class_DColorPropPage;
extern PACKAGE GUID Class_DFontPropPage;
extern PACKAGE GUID Class_DPicturePropPage;
extern PACKAGE GUID Class_DStringPropPage;
extern PACKAGE HWND __fastcall ParkingWindow(void);
extern PACKAGE OleVariant __fastcall GetDispatchPropValue(_di_IDispatch Disp, int DispID);
extern PACKAGE void __fastcall SetDispatchPropValue(_di_IDispatch Disp, int DispID, const OleVariant 
	&Value);
extern PACKAGE void __fastcall EnumDispatchProperties(_di_IDispatch Dispatch, const GUID &PropType, 
	int VTCode, Classes::TStrings* PropList);
extern PACKAGE void __fastcall GetOleFont(Graphics::TFont* Font, _di_IFontDisp &OleFont);
extern PACKAGE void __fastcall SetOleFont(Graphics::TFont* Font, _di_IFontDisp OleFont);
extern PACKAGE void __fastcall GetOlePicture(Graphics::TPicture* Picture, _di_IPictureDisp &OlePicture
	);
extern PACKAGE void __fastcall SetOlePicture(Graphics::TPicture* Picture, _di_IPictureDisp OlePicture
	);
extern PACKAGE void __fastcall GetOleStrings(Classes::TStrings* Strings, Stdvcl::_di_IStrings &OleStrings
	);
extern PACKAGE void __fastcall SetOleStrings(Classes::TStrings* Strings, Stdvcl::_di_IStrings OleStrings
	);

}	/* namespace Axctrls */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Axctrls;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// AxCtrls
