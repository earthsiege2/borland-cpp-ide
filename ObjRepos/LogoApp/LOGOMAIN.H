//----------------------------------------------------------------------------
#ifndef LogoMainH
#define LogoMainH
//----------------------------------------------------------------------------
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
//----------------------------------------------------------------------------
class TLogoAppForm : public TForm
{
__published:
	TOpenDialog *OpenDialog;
	TSaveDialog *SaveDialog;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TActionList *ActionList1;
        TAction *FileNew1;
        TAction *FileOpen1;
        TAction *FileSave1;
        TAction *FileSaveAs1;
        TAction *FileSend1;
        TAction *FileExit1;
        TEditCut *EditCut1;
        TEditCopy *EditCopy1;
        TEditPaste *EditPaste1;
        TAction *HelpAbout1;
        TStatusBar *StatusBar;
        TImageList *ImageList1;
        TRichEdit *RichEdit1;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *FileNewItem;
        TMenuItem *FileOpenItem;
        TMenuItem *FileSaveItem;
        TMenuItem *FileSaveAsItem;
        TMenuItem *N1;
        TMenuItem *FileSendItem;
        TMenuItem *FileExitItem;
        TMenuItem *CutItem;
        TMenuItem *CopyItem;
        TMenuItem *PasteItem;
        TMenuItem *Help1;
        TMenuItem *HelpAboutItem;
	void __fastcall FileNew1Execute(TObject *Sender);
	void __fastcall FileOpen1Execute(TObject *Sender);
	void __fastcall FileSave1Execute(TObject *Sender);
	void __fastcall FileSaveAs1Execute(TObject *Sender);
	void __fastcall FileSend1Execute(TObject *Sender);
	void __fastcall FileExit1Execute(TObject *Sender);
	void __fastcall HelpAbout1Execute(TObject *Sender);
private:
	AnsiString FFileName;
public:
	virtual __fastcall TLogoAppForm(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TLogoAppForm *LogoAppForm;
//----------------------------------------------------------------------------
#endif    
