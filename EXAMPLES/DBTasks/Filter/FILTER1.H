//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef Filter1HPP
#define Filter1HPP
//----------------------------------------------------------------------------
#ifndef ButtonsHPP
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#endif

#ifndef StdCtrlsHPP
#include <StdCtrls.hpp>
#endif

#ifndef DialogsHPP
#include <Dialogs.hpp>
#endif

#ifndef FormsHPP
#include <Forms.hpp>
#endif

#ifndef ControlsHPP
#include <Controls.hpp>
#endif

#ifndef GraphicsHPP
#include <Graphics.hpp>
#endif

#ifndef ClassesHPP
#include <Classes.hpp>
#endif

#ifndef SysUtilsHPP
#include <SysUtils.hpp>
#endif

#ifndef MessagesHPP
#include <Messages.hpp>
#endif

#ifndef WindowsHPP
#include <Windows.hpp>
#endif

#ifndef SystemHPP
#include <System.hpp>
#endif

#ifndef ComCtrlsHPP
#include <ComCtrls.hpp>
#endif

//-- type declarations -------------------------------------------------------
class __declspec(delphiclass) TfmFilterFrm;
class TfmFilterFrm : public TForm
{
	typedef TfmFilterFrm ThisClass;
	typedef TForm inherited;
	
__published:
	TLabel *Label1;
	TLabel *Label2;
	TListBox *ListBox1;
	TListBox *ListBox2;
	TLabel *Label3;
	TGroupBox *GroupBox1;
		TCheckBox *cbCaseSensitive;
	TCheckBox *cbPartialCompare;
	TComboBox *ComboBox1;
	TLabel *Label4;
	TButton *BtnApplyFilter;
	TButton *BtnClear;
	TButton *BtnClose;
	TMemo *Memo1;
	void __fastcall AddFieldName(TObject *Sender);
	void __fastcall ListBox2DblClick(TObject *Sender);
	void __fastcall ApplyFilter(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Memo1Change(TObject *Sender);
	void __fastcall cbCaseSensitiveClick(TObject *Sender);
	void __fastcall cbPartialCompareClick(TObject *Sender);
	void __fastcall SBtnClearClick(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall SBtnCloseClick(TObject *Sender);
public:
	__fastcall virtual TfmFilterFrm(TComponent*);
};

//-- var, const, procedure ---------------------------------------------------
extern TfmFilterFrm *fmFilterFrm;
//-- end unit ----------------------------------------------------------------
#endif	// Filter1
