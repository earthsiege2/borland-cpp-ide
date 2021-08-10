//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ShellCtrls.h"
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *pnlMain;
        TShellListView *ShellListView1;
        TPanel *pnlLeft;
    TShellComboBox *ShellComboBox1;
    TShellTreeView *ShellTreeView1;
    TAction *actnBack;
    TSplitter *Splitter1;
    TAction *actnRefresh;
    TAction *actnIcon;
    TAction *actnList;
    TAction *actnReport;
    TAction *actnSmallIcon;
    TAction *actnSorted;
        TActionList *ActionList1;
        TCoolBar *CoolBar1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
    void __fastcall actnBackUpdate(TObject *Sender);
    void __fastcall actnBackExecute(TObject *Sender);
    void __fastcall actnRefreshExecute(TObject *Sender);
    void __fastcall actnIconUpdate(TObject *Sender);
    void __fastcall actnIconExecute(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall actnSortedUpdate(TObject *Sender);
    void __fastcall actnSortedExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
