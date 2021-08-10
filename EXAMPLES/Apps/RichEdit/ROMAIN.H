//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef RomainH
#define RomainH
//----------------------------------------------------------------------------
#include <Outline.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
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
class TMainForm : public TForm
{
__published:
	TPanel *SpeedBar;
	TSpeedButton *OpenButton;
	TSpeedButton *SaveButton;
	TSpeedButton *PrintButton;
	TSpeedButton *UndoButton;
	TSpeedButton *CutButton;
	TSpeedButton *CopyButton;
	TSpeedButton *PasteButton;
	TBevel *Bevel1;
	TSpeedButton *BoldButton;
	TSpeedButton *ItalicButton;
	TSpeedButton *LeftAlign;
	TSpeedButton *CenterAlign;
	TSpeedButton *RightAlign;
	TSpeedButton *UnderlineButton;
	TSpeedButton *BulletsButton;
	TComboBox *FontName;
	TEdit *FontSize;
	TUpDown *UpDown1;
	TPanel *Ruler;
	TLabel *FirstInd;
	TLabel *LeftInd;
	TBevel *RulerLine;
	TLabel *RightInd;
	TStatusBar *StatusBar;
	TMainMenu *MainMenu;
	TMenuItem *FileMenu;
	TMenuItem *FileNew;
	TMenuItem *FileOpen;
	TMenuItem *FileSave;
	TMenuItem *FileSaveAs;
	TMenuItem *N1;
	TMenuItem *FilePrint;
	TMenuItem *N4;
	TMenuItem *FileExit;
	TMenuItem *EditMenu;
	TMenuItem *EditUndo;
	TMenuItem *N2;
	TMenuItem *EditCut;
	TMenuItem *EditCopy;
	TMenuItem *EditPaste;
	TMenuItem *N5;
	TMenuItem *EditFont;
	TMenuItem *HelpMenu;
	TMenuItem *HelpAbout;
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
	TPrintDialog *PrintDialog;
	TFontDialog *FontDialog1;
	TRichEdit *RichEdit1;
        TMenuItem *Language1;
        TMenuItem *US1;
        TMenuItem *German1;
        TMenuItem *French1;
	void __fastcall SelectionChange(TObject *Sender);
	void __fastcall AlignClick(TObject *Sender);
	void __fastcall FilePrintClick(TObject *Sender);
	void __fastcall FileExitClick(TObject *Sender);
	void __fastcall EditUndoClick(TObject *Sender);
	void __fastcall EditCutClick(TObject *Sender);
	void __fastcall EditCopyClick(TObject *Sender);
	void __fastcall EditPasteClick(TObject *Sender);
	void __fastcall HelpContentsClick(TObject *Sender);
	void __fastcall HelpSearchClick(TObject *Sender);
	void __fastcall HelpHowToClick(TObject *Sender);
	void __fastcall HelpAboutClick(TObject *Sender);
	void __fastcall RulerResize(TObject *Sender);
	void __fastcall SelectFont(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FileNewClick(TObject *Sender);
	void __fastcall FileOpenClick(TObject *Sender);
	void __fastcall FileSaveClick(TObject *Sender);
	void __fastcall FileSaveAsClick(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall BoldButtonClick(TObject *Sender);
	void __fastcall FontSizeChange(TObject *Sender);
	void __fastcall FontNameChange(TObject *Sender);
	void __fastcall UnderlineButtonClick(TObject *Sender);
	void __fastcall ItalicButtonClick(TObject *Sender);
	void __fastcall BulletsButtonClick(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall RulerItemMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall RulerItemMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall FirstIndMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall LeftIndMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall RightIndMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall US1Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:
	AnsiString FFileName;
	bool FUpdating;
	int FDragOfs;
	bool FDragging;
	TTextAttributes *__fastcall CurrText(void);
	void __fastcall GetFontNames(void);
	void __fastcall SetFileName(const AnsiString FileName);
	void __fastcall CheckFileSave(void);
	void __fastcall SetupRuler(void);
	void __fastcall SetEditRect(void);
	void __fastcall ShowHint(TObject *Sender);
public:
    virtual __fastcall TMainForm(TComponent *Owner);
};
//----------------------------------------------------------------------------
class TCharsetObject : public TObject
{
public:
    int Charset;
    __fastcall TCharsetObject(int FCharset);
};
//----------------------------------------------------------------------------
extern TMainForm *MainForm;
//----------------------------------------------------------------------------
#endif	
