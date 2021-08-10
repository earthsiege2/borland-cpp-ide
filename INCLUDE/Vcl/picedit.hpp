// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'PicEdit.pas' rev: 6.00

#ifndef PicEditHPP
#define PicEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtDlgs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Picedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPictureEditorDlg;
class PASCALIMPLEMENTATION TPictureEditorDlg : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extdlgs::TOpenPictureDialog* OpenDialog;
	Extdlgs::TSavePictureDialog* SaveDialog;
	Stdctrls::TButton* OKButton;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TButton* HelpButton;
	Stdctrls::TGroupBox* GroupBox1;
	Extctrls::TPanel* ImagePanel;
	Stdctrls::TButton* Load;
	Stdctrls::TButton* Save;
	Stdctrls::TButton* Clear;
	Extctrls::TPaintBox* ImagePaintBox;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall LoadClick(System::TObject* Sender);
	void __fastcall SaveClick(System::TObject* Sender);
	void __fastcall ClearClick(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall ImagePaintBoxPaint(System::TObject* Sender);
	
private:
	Graphics::TPicture* Pic;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TPictureEditorDlg(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TPictureEditorDlg(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TPictureEditorDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TPictureEditorDlg(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TPictureEditor;
class PASCALIMPLEMENTATION TPictureEditor : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TMetaClass*FGraphicClass;
	Graphics::TPicture* FPicture;
	TPictureEditorDlg* FPicDlg;
	void __fastcall SetPicture(Graphics::TPicture* Value);
	
public:
	__fastcall virtual TPictureEditor(Classes::TComponent* AOwner);
	__fastcall virtual ~TPictureEditor(void);
	bool __fastcall Execute(void);
	__property TMetaClass* GraphicClass = {read=FGraphicClass, write=FGraphicClass};
	__property Graphics::TPicture* Picture = {read=FPicture, write=SetPicture};
};


class DELPHICLASS TPictureProperty;
class PASCALIMPLEMENTATION TPictureProperty : public Designeditors::TPropertyEditor 
{
	typedef Designeditors::TPropertyEditor inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TPictureProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TPropertyEditor(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TPictureProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGraphicProperty;
class PASCALIMPLEMENTATION TGraphicProperty : public Designeditors::TClassProperty 
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual AnsiString __fastcall GetValue();
	virtual void __fastcall SetValue(const AnsiString Value);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Create */ inline __fastcall virtual TGraphicProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TGraphicProperty(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGraphicEditor;
class PASCALIMPLEMENTATION TGraphicEditor : public Designeditors::TDefaultEditor 
{
	typedef Designeditors::TDefaultEditor inherited;
	
public:
	virtual void __fastcall EditProperty(const Designintf::_di_IProperty Prop, bool &Continue);
public:
	#pragma option push -w-inl
	/* TComponentEditor.Create */ inline __fastcall virtual TGraphicEditor(Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Designeditors::TDefaultEditor(AComponent, ADesigner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TGraphicEditor(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Picedit */
using namespace Picedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// PicEdit
