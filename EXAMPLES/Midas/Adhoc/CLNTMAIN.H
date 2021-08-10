//---------------------------------------------------------------------------

#ifndef clntmainH
#define clntmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <MConnect.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DataSource1;
        TClientDataSet *ClientDataSet1;
        TDCOMConnection *DCOMConnection1;
        TDBGrid *DBGrid1;
        TPanel *Panel1;
        TButton *BtnFetchData;
        TComboBox *cmbAlias;
        TLabel *lblAlias;
        TLabel *Label1;
        TComboBox *cmbTables;
        TPanel *Panel2;
        TDBNavigator *DBNavigator1;
        void __fastcall BtnFetchDataClick(TObject *Sender);
        void __fastcall cmbAliasChange(TObject *Sender);
        void __fastcall cmbTablesChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
