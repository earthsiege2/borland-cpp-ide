//---------------------------------------------------------------------------
#ifndef LastValuH
#define LastValuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TDigitalForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TLineSeries *LineSeries2;
  TLineSeries *LineSeries3;
  TLineSeries *LineSeries4;
  TPanel *Panel1;
  TCheckBox *CheckBox1;
  TCheckBox *CheckBox2;
  TCheckBox *CheckBox3;
  TBitBtn *BitBtn3;
  TCheckBox *CheckBox4;
  TMemo *Memo1;
  TTimer *Timer1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall CheckBox2Click(TObject *Sender);
  void __fastcall CheckBox3Click(TObject *Sender);
  void __fastcall Chart1GetLegendText(TCustomAxisPanel *Sender,
          TLegendStyle LegendStyle, int Index, AnsiString &LegendText);
  void __fastcall CheckBox4Click(TObject *Sender);
    
private:	// User declarations
public:		// User declarations
  __fastcall TDigitalForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDigitalForm *DigitalForm;
//---------------------------------------------------------------------------
#endif
