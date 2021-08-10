//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef ClientFormUH
#define ClientFormUH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <StdActns.hpp>
//---------------------------------------------------------------------------
class TClientForm : public TForm
{
__published:	// IDE-managed Components
  TPanel *Panel2;
  TDBNavigator *DBNavigator2;
  TPanel *Panel1;
  TButton *Button1;
  TDBGrid *DBGrid2;
  TImageList *ImageList1;
  TMainMenu *MainMenu1;
  TMenuItem *File1;
  TMenuItem *Exit1;
  TMenuItem *Edit1;
  TMenuItem *Cut1;
  TMenuItem *Copy1;
  TMenuItem *Paste1;
  TActionList *ActionList1;
  TEditCopy *CopyAction;
  TEditCut *CutAction;
  TEditPaste *PasteAction;
  TAction *ExitAction;
    TAction *ActionApply;
    TAction *ActionRefresh;
    TButton *btnRefresh;
    TButton *btnApply;
  void __fastcall ActionApplyExecute(TObject *Sender);
  void __fastcall ActionRefreshExecute(TObject *Sender);
  void __fastcall ExitActionExecute(TObject *Sender);
  void __fastcall ActionApplyUpdate(TObject *Sender);
  void __fastcall ActionRefreshUpdate(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TClientForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TClientForm *ClientForm;
//---------------------------------------------------------------------------
#endif
