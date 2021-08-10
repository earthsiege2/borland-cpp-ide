// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OCXReg.pas' rev: 5.00

#ifndef OCXRegHPP
#define OCXRegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <OleCtrls.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <ComObj.hpp>	// Pascal unit
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
class PASCALIMPLEMENTATION TOleControlEditor : public Dsgnintf::TDefaultEditor 
{
	typedef Dsgnintf::TDefaultEditor inherited;
	
private:
	Classes::TStringList* FVerbs;
	
protected:
	__property Classes::TStringList* Verbs = {read=FVerbs};
	virtual void __fastcall DoVerb(int Verb);
	
public:
	__fastcall virtual TOleControlEditor(Classes::TComponent* AComponent, Dsgnintf::_di_IFormDesigner ADesigner
		);
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
	Dsgnintf::TPropertyEditor* FPropertyEditor;
	
public:
	__fastcall virtual TOleObjectEditor(Dsgnintf::TPropertyEditor* PropertyEditor);
	virtual Variant __fastcall Edit(const Variant &OleObject);
	__property Dsgnintf::TPropertyEditor* PropertyEditor = {read=FPropertyEditor};
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
	/* TOleObjectEditor.Create */ inline __fastcall virtual TOleFontEditor(Dsgnintf::TPropertyEditor* PropertyEditor
		) : TOleObjectEditor(PropertyEditor) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOleFontEditor(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOleObjectProperty;
class PASCALIMPLEMENTATION TOleObjectProperty : public Dsgnintf::TPropertyEditor 
{
	typedef Dsgnintf::TPropertyEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
	virtual void __fastcall GetProperties(Dsgnintf::TGetPropEditProc Proc);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOleObjectProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TOleObjectProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOleCustomProperty;
class PASCALIMPLEMENTATION TOleCustomProperty : public Dsgnintf::TPropertyEditor 
{
	typedef Dsgnintf::TPropertyEditor inherited;
	
public:
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOleCustomProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TOleCustomProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOlePropPageProperty;
class PASCALIMPLEMENTATION TOlePropPageProperty : public Dsgnintf::TPropertyEditor 
{
	typedef Dsgnintf::TPropertyEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOlePropPageProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TOlePropPageProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TOleEnumProperty;
class PASCALIMPLEMENTATION TOleEnumProperty : public Dsgnintf::TOrdinalProperty 
{
	typedef Dsgnintf::TOrdinalProperty inherited;
	
private:
	Olectrls::TEnumPropDesc* FEnumPropDesc;
	
protected:
	__property Olectrls::TEnumPropDesc* EnumPropDesc = {read=FEnumPropDesc};
	
public:
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall SetValue(const AnsiString Value);
protected:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TOleEnumProperty(const Dsgnintf::_di_IFormDesigner 
		ADesigner, int APropCount) : Dsgnintf::TOrdinalProperty(ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TOleEnumProperty(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TOleObjectEditorClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RegisterOleObjectEditor(const GUID &IID, const AnsiString ClassName, 
	TMetaClass* EditorClass);
extern PACKAGE void __fastcall Register(void);

}	/* namespace Ocxreg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ocxreg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OCXReg
