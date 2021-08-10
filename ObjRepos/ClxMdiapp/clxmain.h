//----------------------------------------------------------------------------
#ifndef MainH
#define MainH
//----------------------------------------------------------------------------
#include "ClxChildWin.h"
#include <QComCtrls.hpp>
#include <QExtCtrls.hpp>
#include <QButtons.hpp>
#include <QDialogs.hpp>
#include <QStdCtrls.hpp>
#include <QMenus.hpp>
#include <QControls.hpp>
#include <QForms.hpp>
#include <QGraphics.hpp>
#include <SysUtils.hpp>
#include <QActnList.hpp>
#include <QImgList.hpp>
#include <QStdActns.hpp>
#include <QTypes.hpp>
#include <Messages.hpp>
#include <System.hpp>
#include <Classes.hpp>
//----------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:
/*
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *FileNewItem;
	TMenuItem *FileOpenItem;
	TMenuItem *FileCloseItem;
	TMenuItem *Window1;
	TMenuItem *Help1;
	TMenuItem *N1;
	TMenuItem *FileExitItem;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	//TMenuItem *WindowArrangeItem;
	TMenuItem *HelpAboutItem;
	TOpenDialog *OpenDialog;
	TMenuItem *FileSaveItem;
	TMenuItem *FileSaveAsItem;
	TMenuItem *Edit1;
	TMenuItem *CutItem;
	TMenuItem *CopyItem;
	TMenuItem *PasteItem;
	TMenuItem *WindowMinimizeItem;
        TStatusBar *StatusBar;
        TActionList *ActionList1;
        TEditCut *EditCut1;
        TEditCopy *EditCopy1;
        TEditPaste *EditPaste1;
        TAction *FileNew1;
        TAction *FileSave1;
        TAction *FileExit1;
        TAction *FileOpen1;
        TAction *FileSaveAs1;
        TWindowCascade *WindowCascade1;
        //TWindowTileHorizontal *WindowTileHorizontal1;
        //TWindowArrange *WindowArrangeAll1;
        TWindowMinimizeAll *WindowMinimizeAll1;
        TAction *HelpAbout1;
        TWindowClose *FileClose1;
        //TWindowTileVertical *WindowTileVertical1;
        TMenuItem *WindowTileItem2;
        TToolBar *ToolBar2;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TImageList *ImageList1;
*/
        TMainMenu *MainMenu1;
	TMenuItem* File1;
        TMenuItem *FileNewItem;
        TMenuItem *FileOpenItem;
	TMenuItem* FileCloseItem;
	TMenuItem* Window1;
	TMenuItem* Help1;
	TMenuItem* N1;
	TMenuItem* FileExitItem;
	TMenuItem* WindowCascadeItem;
	TMenuItem* WindowTileItem;
	TMenuItem* HelpAboutItem;
	TOpenDialog* OpenDialog;
	TMenuItem* FileSaveItem;
        TMenuItem *FileSaveAsItem;
	TMenuItem* Edit1;
	TMenuItem* CutItem;
	TMenuItem* CopyItem;
	TMenuItem* PasteItem;
	TMenuItem* WindowMinimizeItem;
	TStatusBar* StatusBar;
	TActionList* ActionList1;
	TEditCut* EditCut1;
	TEditCopy* EditCopy1;
	TEditPaste* EditPaste1;
	TAction* FileNew1;
	TAction* FileSave1;
	TAction* FileExit1;
	TAction* FileOpen1;
	TAction* FileSaveAs1;
	TWindowCascade* WindowCascade1;
	TWindowMinimizeAll* WindowMinimizeAll1;
	TAction* HelpAbout1;
	TWindowClose* FileClose1;
	TMenuItem* WindowTileItem2;
	TToolBar* ToolBar2;
	TToolButton* ToolButton1;
	TToolButton* ToolButton2;
	TToolButton* ToolButton3;
	TToolButton* ToolButton4;
	TToolButton* ToolButton5;
	TToolButton* ToolButton6;
        TToolButton *ToolButton9;
	TToolButton* ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
	TWindowClose* WindowClose1;
	TWindowTile* WindowTile1;
        TToolButton *ToolButton12;
        TImageList *ImageList1;

        void __fastcall FileNew1Execute(TObject *Sender);
        void __fastcall FileOpen1Execute(TObject *Sender);
        void __fastcall HelpAbout1Execute(TObject *Sender);
        void __fastcall FileExit1Execute(TObject *Sender);
private:
	void __fastcall CreateMDIChild(const String Name);
public:
	virtual __fastcall TMainForm(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TMainForm *MainForm;
extern TMDIChild *__fastcall MDIChildCreate(void);
//----------------------------------------------------------------------------
#endif    
