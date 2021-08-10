// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OCXReg.pas' rev: 6.00

#ifndef OCXRegHPP
#define OCXRegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <OleCtrls.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ocxreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TOleControlEditor;
class PASCALIMPLEMENTATION TOleControlEditor : public Designeditors::TDefaultEditor 
{
	typedef Designeditors::TDefaultEditor inherited;
	
private:
	Classes::TStringList* FVerbs;
	
protected:
	__property Classes::TStringList* Verbs = {read=FVerbs};
	virtual void __fastcall DoVerb(int Verb);
	
public:
	__fastcall virtual TOleControlEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner);
	__fastcall virtual ~TOleControlEditor(void);
	virtual void __fastcall Edit(void);
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
};


class DELPHICLASS TOleObjectEditor;
class PASCALIMPLEMENTATION TOleObjectEditor : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Designeditors::TPropertyEditor* FPropertyEditor;
	
public:
	__fastcall virtual TOleObjectEditor(Designeditors::TPropertyEditor* PropertyEditor);
	virtual Variant __fastcall Edit(const Variant &OleObject);
	__property Designeditors::TPropertyEditor* PropertyEditor = {read=FPropertyEditor};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOleObjectEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOleFontEditor;
class PASCALIMPLEMENTATION TOleFontEditor : public TOleObjectEditor 
{
	typedef TOleObjectEditor inherited;
	
public:
	virtual Variant __fastcall Edit(const Variant &OleObject);
public:
	#pragma option push -w-inl
	/* TOleObjectEditor.Create */ inline __fastcall virtual TOleFontEditor(Designeditors::TPropertyEditor* PropertyEditor) : TOleObjectEditor(PropertyEditor) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOleFontEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOleObjectProperty;
class PASCALIMPLEMENTATION TOleObjectProperty : public Designeditors::TVariantProperty 
{
	typedef Designeditors::TVariantProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOleObjectProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TVariantProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TOleObjectProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOleCustomProperty;
class PASCALIMPLEMENTATION TOleCustomProperty : public Designeditors::TPropertyEditor 
{
	typedef Designeditors::TPropertyEditor inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOleCustomProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TOleCustomProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOlePropPageProperty;
class PASCALIMPLEMENTATION TOlePropPageProperty : public Designeditors::TPropertyEditor 
{
	typedef Designeditors::TPropertyEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOlePropPageProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TOlePropPageProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOleEnumProperty;
class PASCALIMPLEMENTATION TOleEnumProperty : public Designeditors::TOrdinalProperty 
{
	typedef Designeditors::TOrdinalProperty inherited;
	
private:
	Olectrls::TEnumPropDesc* FEnumPropDesc;
	
protected:
	__property Olectrls::TEnumPropDesc* EnumPropDesc = {read=FEnumPropDesc};
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOleEnumProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TOleEnumProperty(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TOleObjectEditorClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RegisterOleObjectEditor(const GUID &IID, const AnsiString ClassName, TMetaClass* EditorClass);
extern PACKAGE void __fastcall Register(void);

}	/* namespace Ocxreg */
using namespace Ocxreg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OCXReg
