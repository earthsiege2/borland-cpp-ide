//---------------------------------------------------------------------------
#ifndef PoolingH
#define PoolingH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <registry.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
  TEdit *Count;
  TDatabase *Database1;
  TEdit *ElpTimeEdt;
  TEdit *EndTimeEdt;
  TLabel *Label1;
  TLabel *Label2;
  TLabel *Label3;
  TLabel *Label4;
  TCheckBox *MTSPooling;
  TQuery *Query1;
  TEdit *StartTimeEdt;
  TButton *TestBtn;
  void __fastcall TestBtnClick(TObject *Sender);
  void __fastcall DoTest(void);
  void __fastcall MTSPoolingClick(TObject *Sender);
  void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
  TDateTime dtStart, dtEnd, dtElp;

public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};

const AnsiString MTSRegistryKey = "SOFTWARE\\Borland\\Database Engine\\Settings\\SYSTEM\\INIT";

//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
