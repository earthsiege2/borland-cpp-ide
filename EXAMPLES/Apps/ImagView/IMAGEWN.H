//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef ImageWnH
#define ImageWnH
//----------------------------------------------------------------------------
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <FileCtrl.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
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
class TImageForm : public TForm
{
__published:
	TBevel *Bevel1;
	TBevel *Bevel2;
	TLabel *Label2;
	TDirectoryListBox *DirectoryListBox1;
	TDriveComboBox *DriveComboBox1;
	TEdit *FileEdit;
	TGroupBox *UpDownGroup;
	TSpeedButton *SpeedButton1;
	TBitBtn *BitBtn1;
	TGroupBox *DisabledGrp;
	TSpeedButton *SpeedButton2;
	TBitBtn *BitBtn2;
	TPanel *Panel1;
	TImage *Image1;
	TBitBtn *ViewBtn;
	TFilterComboBox *FilterComboBox1;
	TCheckBox *GlyphCheck;
	TCheckBox *StretchCheck;
	TEdit *UpDownEdit;
	TUpDown *UpDown1;
	TFileListBox *FileListBox1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ViewBtnClick(TObject *Sender);
	void __fastcall UpDownEditChange(TObject *Sender);
	void __fastcall StretchCheckClick(TObject *Sender);
	void __fastcall FileEditKeyPress(TObject *Sender, Char &Key);
	void __fastcall GlyphCheckClick(TObject *Sender);
	void __fastcall FileListBox1Click(TObject *Sender);
	
public:
	AnsiString FormCaption;
    AnsiString FileExt;
	void __fastcall ViewAsGlyph(const AnsiString FileExt);
    virtual __fastcall TImageForm(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TImageForm *ImageForm;
//----------------------------------------------------------------------------
#endif	
