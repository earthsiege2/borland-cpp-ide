//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef ProcH
#define ProcH
//----------------------------------------------------------------------------
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <System.hpp>
//----------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *New1;
	TMenuItem *Exit1;
	TMenuItem *N1;
	TMenuItem *Help1;
	TMenuItem *About1;
	TPanel *Panel1;
	TSpeedButton *SpeedButton3;
	TSpeedButton *SpeedButton4;
	TStatusBar *StatusBar1;
	TListBox *ListBox1;
	TMenuItem *Refresh1;
	TRadioButton *RadioButton4;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TTimer *Timer1;
	TImage *Image1;
	TBevel *Bevel1;
    TSpeedButton *SpeedButton2;
    TSpeedButton *SpeedButton1;
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	
	
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall RadioButton1Click(TObject *Sender);
	
	
	void __fastcall New1Click(TObject *Sender);
	void __fastcall Refresh1Click(TObject *Sender);
	
	
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall SpeedButton2Click(TObject *Sender);
    void __fastcall SpeedButton1Click(TObject *Sender);
public:
    virtual __fastcall TFormMain(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TFormMain *FormMain;
//----------------------------------------------------------------------------
#endif	
