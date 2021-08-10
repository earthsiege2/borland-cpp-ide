// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxEditors.pas' rev: 6.00

#ifndef ClxEditorsHPP
#define ClxEditorsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QDialogs.hpp>	// Pascal unit
#include <QActnList.hpp>	// Pascal unit
#include <QImgList.hpp>	// Pascal unit
#include <ClxImgEdit.hpp>	// Pascal unit
#include <QMenus.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <DsnConst.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clxeditors
{
//-- type declarations -------------------------------------------------------
__interface ICustomDesignForm;
typedef System::DelphiInterface<ICustomDesignForm> _di_ICustomDesignForm;
__interface INTERFACE_UUID("{833D4D25-3E3D-44DB-82CC-117C02C778B1}") ICustomDesignForm  : public IInterface 
{
	
public:
	virtual void __fastcall CreateDesignerForm(const Designintf::_di_IDesigner Designer, Classes::TComponent* Root, /* out */ Qforms::TCustomForm* &DesignForm, /* out */ Qcontrols::TWidgetControl* &ComponentContainer) = 0 ;
};

class DELPHICLASS TAlignProperty;
class PASCALIMPLEMENTATION TAlignProperty : public Designeditors::TEnumProperty 
{
	typedef Designeditors::TEnumProperty inherited;
	
public:
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TAlignProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TEnumProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TAlignProperty(void) { }
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
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TColorProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TColorProperty(void) { }
	#pragma option pop
	
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
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TCursorProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TIntegerProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TCursorProperty(void) { }
	#pragma option pop
	
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


class DELPHICLASS TFontNameProperty;
class PASCALIMPLEMENTATION TFontNameProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFontNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFontNameProperty(void) { }
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


class DELPHICLASS TImageListEditor;
class PASCALIMPLEMENTATION TImageListEditor : public Designeditors::TComponentEditor 
{
	typedef Designeditors::TComponentEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TImageListEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TComponentEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TImageListEditor(void) { }
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


class DELPHICLASS TFileNameProperty;
class PASCALIMPLEMENTATION TFileNameProperty : public Designeditors::TStringProperty 
{
	typedef Designeditors::TStringProperty inherited;
	
protected:
	virtual void __fastcall GetDialogOptions(Qdialogs::TOpenDialog* Dialog);
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TFileNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TFileNameProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS THTMLFileNameProperty;
class PASCALIMPLEMENTATION THTMLFileNameProperty : public TFileNameProperty 
{
	typedef TFileNameProperty inherited;
	
protected:
	virtual void __fastcall GetDialogOptions(Qdialogs::TOpenDialog* Dialog);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual THTMLFileNameProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TFileNameProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~THTMLFileNameProperty(void) { }
	#pragma option pop
	
};


typedef void __fastcall (*TNotifyActionListChange)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TNotifyActionListChange NotifyActionListChange;
extern PACKAGE void __fastcall CopyStreamToClipboard(Classes::TStream* S);
extern PACKAGE Classes::TMemoryStream* __fastcall GetClipboardStream(void);
extern PACKAGE void __fastcall RegActions(const AnsiString ACategory, TMetaClass* * AClasses, const int AClasses_Size, TMetaClass* AResource);
extern PACKAGE void __fastcall UnRegActions(TMetaClass* * Classes, const int Classes_Size);
extern PACKAGE void __fastcall EnumActions(Qactnlist::TEnumActionProc Proc, void * Info);
extern PACKAGE Classes::TBasicAction* __fastcall CreateAction(Classes::TComponent* AOwner, TMetaClass* ActionClass);

}	/* namespace Clxeditors */
using namespace Clxeditors;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxEditors
