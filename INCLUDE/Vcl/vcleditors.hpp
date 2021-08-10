// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VCLEditors.pas' rev: 6.00

#ifndef VCLEditorsHPP
#define VCLEditorsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActnList.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vcleditors
{
//-- type declarations -------------------------------------------------------
__interface ICustomPropertyDrawing;
typedef System::DelphiInterface<ICustomPropertyDrawing> _di_ICustomPropertyDrawing;
__interface INTERFACE_UUID("{E1A50419-1288-4B26-9EFA-6608A35F0824}") ICustomPropertyDrawing  : public IInterface 
{
	
public:
	virtual void __fastcall PropDrawName(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected) = 0 ;
	virtual void __fastcall PropDrawValue(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected) = 0 ;
};

__interface ICustomPropertyListDrawing;
typedef System::DelphiInterface<ICustomPropertyListDrawing> _di_ICustomPropertyListDrawing;
__interface INTERFACE_UUID("{BE2B8CF7-DDCA-4D4B-BE26-2396B969F8E0}") ICustomPropertyListDrawing  : public IInterface 
{
	
public:
	virtual void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth) = 0 ;
	virtual void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AHeight) = 0 ;
	virtual void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected) = 0 ;
};

class DELPHICLASS TFontNameProperty;
class PASCALIMPLEMENTATION TFontNameProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AHeight);
	void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth);
	void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFontNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFontNameProperty(void) { }
	#pragma option pop
	
private:
	void *__ICustomPropertyListDrawing;	/* Vcleditors::ICustomPropertyListDrawing */
	
public:
	operator ICustomPropertyListDrawing*(void) { return (ICustomPropertyListDrawing*)&__ICustomPropertyListDrawing; }
	
};


class DELPHICLASS TFontCharsetProperty;
class PASCALIMPLEMENTATION TFontCharsetProperty : public Designeditors::TIntegerProperty 
{
	typedef Designeditors::TIntegerProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFontCharsetProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFontCharsetProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TImeNameProperty;
class PASCALIMPLEMENTATION TImeNameProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TImeNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TImeNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TColorProperty;
class PASCALIMPLEMENTATION TColorProperty : public Designeditors::TIntegerProperty 
{
	typedef Designeditors::TIntegerProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
	void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AHeight);
	void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth);
	void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
	void __fastcall PropDrawName(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
	void __fastcall PropDrawValue(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TColorProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TColorProperty(void) { }
	#pragma option pop
	
private:
	void *__ICustomPropertyDrawing;	/* Vcleditors::ICustomPropertyDrawing */
	void *__ICustomPropertyListDrawing;	/* Vcleditors::ICustomPropertyListDrawing */
	
public:
	operator ICustomPropertyListDrawing*(void) { return (ICustomPropertyListDrawing*)&__ICustomPropertyListDrawing; }
	operator ICustomPropertyDrawing*(void) { return (ICustomPropertyDrawing*)&__ICustomPropertyDrawing; }
	
};


class DELPHICLASS TBrushStyleProperty;
class PASCALIMPLEMENTATION TBrushStyleProperty : public Designeditors::TEnumProperty 
{
	typedef Designeditors::TEnumProperty inherited;
	
public:
	void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AHeight);
	void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth);
	void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
	void __fastcall PropDrawName(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
	void __fastcall PropDrawValue(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TBrushStyleProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TEnumProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TBrushStyleProperty(void) { }
	#pragma option pop
	
private:
	void *__ICustomPropertyDrawing;	/* Vcleditors::ICustomPropertyDrawing */
	void *__ICustomPropertyListDrawing;	/* Vcleditors::ICustomPropertyListDrawing */
	
public:
	operator ICustomPropertyListDrawing*(void) { return (ICustomPropertyListDrawing*)&__ICustomPropertyListDrawing; }
	operator ICustomPropertyDrawing*(void) { return (ICustomPropertyDrawing*)&__ICustomPropertyDrawing; }
	
};


class DELPHICLASS TPenStyleProperty;
class PASCALIMPLEMENTATION TPenStyleProperty : public Designeditors::TEnumProperty 
{
	typedef Designeditors::TEnumProperty inherited;
	
public:
	void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AHeight);
	void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth);
	void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
	void __fastcall PropDrawName(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
	void __fastcall PropDrawValue(Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TPenStyleProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TEnumProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TPenStyleProperty(void) { }
	#pragma option pop
	
private:
	void *__ICustomPropertyDrawing;	/* Vcleditors::ICustomPropertyDrawing */
	void *__ICustomPropertyListDrawing;	/* Vcleditors::ICustomPropertyListDrawing */
	
public:
	operator ICustomPropertyListDrawing*(void) { return (ICustomPropertyListDrawing*)&__ICustomPropertyListDrawing; }
	operator ICustomPropertyDrawing*(void) { return (ICustomPropertyDrawing*)&__ICustomPropertyDrawing; }
	
};


class DELPHICLASS TCursorProperty;
class PASCALIMPLEMENTATION TCursorProperty : public Designeditors::TIntegerProperty 
{
	typedef Designeditors::TIntegerProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
	void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AHeight);
	void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth);
	void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Types::TRect &ARect, bool ASelected);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TCursorProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TCursorProperty(void) { }
	#pragma option pop
	
private:
	void *__ICustomPropertyListDrawing;	/* Vcleditors::ICustomPropertyListDrawing */
	
public:
	operator ICustomPropertyListDrawing*(void) { return (ICustomPropertyListDrawing*)&__ICustomPropertyListDrawing; }
	
};


class DELPHICLASS TFontProperty;
class PASCALIMPLEMENTATION TFontProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFontProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFontProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TModalResultProperty;
class PASCALIMPLEMENTATION TModalResultProperty : public Designeditors::TIntegerProperty 
{
	typedef Designeditors::TIntegerProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TModalResultProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TModalResultProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TShortCutProperty;
class PASCALIMPLEMENTATION TShortCutProperty : public Designeditors::TOrdinalProperty 
{
	typedef Designeditors::TOrdinalProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TShortCutProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TShortCutProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMPFilenameProperty;
class PASCALIMPLEMENTATION TMPFilenameProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TMPFilenameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TMPFilenameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TTabOrderProperty;
class PASCALIMPLEMENTATION TTabOrderProperty : public Designeditors::TIntegerProperty 
{
	typedef Designeditors::TIntegerProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TTabOrderProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TTabOrderProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCaptionProperty;
class PASCALIMPLEMENTATION TCaptionProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TCaptionProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TCaptionProperty(void) { }
	#pragma option pop
	
};


__interface ISelectionMessage;
typedef System::DelphiInterface<ISelectionMessage> _di_ISelectionMessage;
__interface INTERFACE_UUID("{58274878-BB87-406A-9220-904105C9E112}") ISelectionMessage  : public IInterface 
{
	
public:
	virtual bool __fastcall IsSelectionMessage(Controls::TControl* Sender, Messages::TMessage &Message) = 0 ;
};

__interface ISelectionMessageList;
typedef System::DelphiInterface<ISelectionMessageList> _di_ISelectionMessageList;
__interface INTERFACE_UUID("{C1360368-0099-4A7C-A4A8-7650503BA0C6}") ISelectionMessageList  : public IInterface 
{
	
public:
	_di_ISelectionMessage operator[](int Index) { return Items[Index]; }
	
public:
	virtual _di_ISelectionMessage __fastcall Get(int Index) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	__property int Count = {read=GetCount};
	__property _di_ISelectionMessage Items[int Index] = {read=Get/*, default*/};
};

__interface ICustomDesignForm;
typedef System::DelphiInterface<ICustomDesignForm> _di_ICustomDesignForm;
__interface INTERFACE_UUID("{787195AF-C234-49DC-881B-221B69C0137A}") ICustomDesignForm  : public IInterface 
{
	
public:
	virtual void __fastcall CreateDesignerForm(const Designintf::_di_IDesigner Designer, Classes::TComponent* Root, /* out */ Forms::TCustomForm* &DesignForm, /* out */ Controls::TWinControl* &ComponentContainer) = 0 ;
};

typedef void __fastcall (*TNotifyActionListChange)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool FontNamePropertyDisplayFontNames;
extern PACKAGE Word CF_COMPONENTS;
extern PACKAGE AnsiString BaseRegistryKey;
extern PACKAGE TNotifyActionListChange NotifyActionListChange;
extern PACKAGE void __fastcall RegActions(const AnsiString ACategory, TMetaClass* * AClasses, const int AClasses_Size, TMetaClass* AResource);
extern PACKAGE void __fastcall UnRegActions(TMetaClass* * Classes, const int Classes_Size);
extern PACKAGE void __fastcall EnumActions(Actnlist::TEnumActionProc Proc, void * Info);
extern PACKAGE Classes::TBasicAction* __fastcall CreateAction(Classes::TComponent* AOwner, TMetaClass* ActionClass);
extern PACKAGE AnsiString __fastcall GetDisplayValue(const Designintf::_di_IProperty Prop);
extern PACKAGE void __fastcall DefaultPropertyDrawName(Designeditors::TPropertyEditor* Prop, Graphics::TCanvas* Canvas, const Types::TRect &Rect);
extern PACKAGE void __fastcall DefaultPropertyDrawValue(Designeditors::TPropertyEditor* Prop, Graphics::TCanvas* Canvas, const Types::TRect &Rect);
extern PACKAGE void __fastcall DefaultPropertyListDrawValue(const AnsiString Value, Graphics::TCanvas* Canvas, const Types::TRect &Rect, bool Selected);
extern PACKAGE void __fastcall CopyStreamToClipboard(Classes::TMemoryStream* S);
extern PACKAGE Classes::TMemoryStream* __fastcall GetClipboardStream(void);
extern PACKAGE _di_ISelectionMessageList __fastcall SelectionMessageListOf(const Designintf::_di_ISelectionEditorList SelectionEditorList);
extern PACKAGE bool __fastcall EditActionFor(Stdctrls::TCustomEdit* AEditControl, Designintf::TEditAction Action);
extern PACKAGE Designintf::TEditState __fastcall GetEditStateFor(Stdctrls::TCustomEdit* AEditControl);

}	/* namespace Vcleditors */
using namespace Vcleditors;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VCLEditors
