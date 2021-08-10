//---------------------------------------------------------------------------

#ifndef ClntMainH
#define ClntMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *Events1;
        TMenuItem *Retrieve1;
        TToolBar *ToolBar1;
        TToolButton *tlbtnExit;
        TToolButton *ToolButton2;
        TToolButton *tlbtnRetrieve;
        TActionList *ActionList1;
        TAction *ExitAction;
        TAction *RetrieveAction;
        TImageList *Images;
        TStatusBar *StatusBar;
        TPanel *Panel1;
        TLabel *Label1;
        TPanel *Panel2;
        TSplitter *Splitter1;
        TPanel *Panel3;
        TDBImage *DBImage1;
        TDBMemo *DBMemo1;
        TLabel *Label2;
        TPanel *Panel4;
        TDBGrid *DBGrid1;
        TDateTimePicker *dtStartDate;
        TDateTimePicker *dtEndDate;
        TLabel *Label3;
        TLabel *Label4;
        void __fastcall ExitActionExecute(TObject *Sender);
        void __fastcall RetrieveActionExecute(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
