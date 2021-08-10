// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxPicEdit.pas' rev: 6.00

#ifndef ClxPicEditHPP
#define ClxPicEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QExtCtrls.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <QButtons.hpp>	// Pascal unit
#include <QDialogs.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clxpicedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClxPictureEditorDlg;
class PASCALIMPLEMENTATION TClxPictureEditorDlg : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
__published:
	Qstdctrls::TButton* OKButton;
	Qstdctrls::TButton* CancelButton;
	Qstdctrls::TButton* HelpButton;
	Qstdctrls::TGroupBox* GroupBox1;
	Qextctrls::TPanel* ImagePanel;
	Qstdctrls::TButton* Load;
	Qstdctrls::TButton* Save;
	Qstdctrls::TButton* Clear;
	Qextctrls::TPaintBox* ImagePaintBox;
	Qdialogs::TOpenDialog* OpenDialog;
	Qdialogs::TSaveDialog* SaveDialog;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall LoadClick(System::TObject* Sender);
	void __fastcall SaveClick(System::TObject* Sender);
	void __fastcall ClearClick(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall ImagePaintBoxPaint(System::TObject* Sender);
	
private:
	Qgraphics::TPicture* Pic;
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TClxPictureEditorDlg(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClxPictureEditorDlg(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TClxPictureEditorDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TClxPictureEditorDlg(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
};


class DELPHICLASS TPictureEditor;
class PASCALIMPLEMENTATION TPictureEditor : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TMetaClass*FGraphicClass;
	Qgraphics::TPicture* FPicture;
	TClxPictureEditorDlg* FPicDlg;
	void __fastcall SetPicture(Qgraphics::TPicture* Value);
	
public:
	__fastcall virtual TPictureEditor(Classes::TComponent* AOwner);
	__fastcall virtual ~TPictureEditor(void);
	bool __fastcall Execute(void);
	__property TMetaClass* GraphicClass = {read=FGraphicClass, write=FGraphicClass};
	__property Qgraphics::TPicture* Picture = {read=FPicture, write=SetPicture};
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

}	/* namespace Clxpicedit */
using namespace Clxpicedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxPicEdit
