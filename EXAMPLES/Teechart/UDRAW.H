//---------------------------------------------------------------------------
#ifndef UDrawH
#define UDrawH
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
class TDrawForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TPanel *Panel1;
  TBitBtn *BitBtn3;
  TCheckBox *CheckBox1;
  TCheckBox *CheckBox2;
  TMemo *Memo1;
  TTimer *Timer1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall LineSeries1BeforeDrawValues(TObject *Sender);
  void __fastcall LineSeries1AfterDrawValues(TObject *Sender);
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
    void __fastcall CheckBox2Click(TObject *Sender);
private:	// User declarations
  double Percent;
  int DeltaPercent;
public:		// User declarations
  __fastcall TDrawForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDrawForm *DrawForm;
//---------------------------------------------------------------------------
#endif
