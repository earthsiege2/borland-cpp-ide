//---------------------------------------------------------------------------

#ifndef ClntMainH
#define ClntMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *Database1;
        TMenuItem *Retrieve1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TActionList *ActionList1;
        TAction *ExitAction;
        TAction *ApplyAction;
        TImageList *Images;
        TPanel *Panel1;
        TSplitter *Splitter1;
        TPanel *Panel2;
        TDBNavigator *DBNavigator1;
        TPanel *Panel3;
        TDBMemo *DBMemo1;
        TLabel *Label1;
        TLabel *Label2;
        TDBComboBox *DBComboBox1;
        TStatusBar *StatusBar1;
        TToolBar *ToolBar1;
        TToolButton *tlbtnExit;
        TToolButton *ToolButton2;
        TToolButton *tlbtnApply;
        TDBGrid *DBGrid2;
        TDBGrid *DBGrid1;
        TDBNavigator *DBNavigator2;
        void __fastcall ExitActionExecute(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall ApplyActionExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
