//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <SOAPConn.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TSoapConnection *SoapConnection1;
        TClientDataSet *ClientDataSet1;
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TDBNavigator *DBNavigator1;
        TDBImage *DBImage1;
  TCheckBox *CheckBox1;
  TMemo *Memo1;
  TMemo *Memo2;
  TPageControl *PageControl1;
  TTabSheet *TabSheet1;
  TTabSheet *TabSheet2;
  TPanel *Panel1;
  void __fastcall SoapConnection1BeforeExecute(const AnsiString MethodName,
          WideString &SOAPRequest);
  void __fastcall CheckBox1Click(TObject *Sender);
  void __fastcall SoapConnection1AfterExecute(const AnsiString MethodName,
          TStream *SOAPResponse);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
