//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef FmxwinH
#define FmxwinH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Tabs.hpp>
#include <Menus.hpp>
#include <FileCtrl.hpp>
#include <Outline.hpp>
#include <Grids.hpp>
#include "CDIROUTL.h"
#include "cdiroutl.h"
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *StatusPanel;
	TPanel *DirectoryPanel;
	TPanel *FilePanel;
	TTabSet *DriveTabSet;
	TImage *Floppy;
	TImage *Fixed;
	TImage *Network;
	TMainMenu *MainMenu1;
	TFileListBox *FileList;
	TMenuItem *File1;
	TMenuItem *Open1;
	TMenuItem *Move1;
	TMenuItem *Copy1;
	TMenuItem *Delete1;
	TMenuItem *Rename1;
	TMenuItem *Properties1;
	TMenuItem *N1;
	TMenuItem *Exit1;
   TCDirectoryOutline *DirectoryOutline;
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Properties1Click(TObject *Sender);
	void __fastcall DirectoryOutlineChange(TObject *Sender);
	void __fastcall DirectoryOutlineDragDrop(TObject *Sender, TObject *Source,
	 int X, int Y);
	void __fastcall DirectoryOutlineDragOver(TObject *Sender,TObject *Source,
	int X, int Y, TDragState State,bool &Accept);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FileListChange(TObject *Sender);
	void __fastcall FileListEndDrag(TObject *Sender, TObject *Target,
	  int X, int Y);
	void __fastcall FileListMouseDown(TObject *Sender, TMouseButton Button,
	 TShiftState Shift, int X, int Y);
	void __fastcall DriveTabSetClick(TObject *Sender);
	void __fastcall DriveTabSetDrawTab(TObject *Sender, TCanvas *TabCanvas,
	 TRect &R, int Index, bool Selected);
	void __fastcall DriveTabSetMeasureTab(TObject *Sender, int Index,
	                  int &TabWidth);
    void __fastcall FileChange(TObject *Sender);
	void __fastcall File1Click(TObject *Sender);
	void __fastcall Delete1Click(TObject *Sender);
	void __fastcall Open1Click(TObject *Sender);
	
	
	
	
	void __fastcall FileListDblClick(TObject *Sender);
private:	// User declarations
  bool FileSelected;
  void __fastcall ConfirmChange(const AnsiString ACaption,AnsiString FromFile,
        AnsiString ToFile);

public:		// User declarations
	virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
