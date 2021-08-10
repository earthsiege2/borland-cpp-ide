//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
#ifndef PieRegHPP
#define PieRegHPP
//----------------------------------------------------------------------------
#include <ComCtrls.hpp>
#include <StdCtrls.hpp>
#include <DsgnIntf.hpp>
#include <Buttons.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include  "pies.h"

//-- type declarations -------------------------------------------------------
class  PACKAGE TAngleEditorDlg : public TForm
{
__published:
	TLabel *EAngleLabel;
	TLabel *SAngleLabel;
	TButton *OKButton;
	TButton *CancelButton;
	TTrackBar *STrackBar;
	TTrackBar *ETrackBar;
	void __fastcall CancelClick(TObject* Sender);
	void __fastcall STrackBarChange(TObject* Sender);
	void __fastcall ETrackBarChange(TObject* Sender);
private:
	int FOrigStart;
	int FOrigEnd;
	TAngles* FAngles;
	void __fastcall SetStartAngle(int Value);
	void __fastcall SetEndAngle(int Value);
	void __fastcall SetAngles(TAngles* Value);
public:
              __property TAngles* EditorAngles = {read=FAngles, write=SetAngles, nodefault};
              __fastcall virtual TAngleEditorDlg(TComponent* AOwner);
              __fastcall TAngleEditorDlg(TComponent* AOwner, int Dummy);
              __fastcall TAngleEditorDlg(HWND ParentWindow);
              __fastcall virtual ~TAngleEditorDlg(void);
};

class PACKAGE TAnglesProperty : public TClassProperty
{
public:
	virtual void __fastcall Edit();
	virtual TPropertyAttributes __fastcall GetAttributes(void);
	__fastcall virtual ~TAnglesProperty(void);
	__fastcall TAnglesProperty(const _di_IFormDesigner ADesigner, int APropCount);
};

class PACKAGE TPieEditor : public TDefaultEditor
{
protected:
	virtual void __fastcall EditProperty(TPropertyEditor* PropertyEditor,
                                         bool& Continue, bool& FreeEditor);
public:
  //      virtual void __fastcall Edit();
	virtual void __fastcall ExecuteVerb(int Index);
	virtual AnsiString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	__fastcall virtual TPieEditor(TComponent* AComponent, _di_IFormDesigner ADesigner);
	__fastcall virtual ~TPieEditor(void);
};

//-- var, const, procedure ---------------------------------------------------
//-- end unit ----------------------------------------------------------------
#endif	// PieReg
