//---------------------------------------------------------------------------
#ifndef ULegendH
#define ULegendH
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
class TLegendForm : public TForm
{
__published:	// IDE-managed Components
  TPaintBox *PaintBox1;
  TLabel *Label1;
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TLineSeries *LineSeries2;
  TPanel *Panel1;
  TBitBtn *BitBtn3;
  TMemo *Memo1;
  void __fastcall LineSeries2AfterDrawValues(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TLegendForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLegendForm *LegendForm;
//---------------------------------------------------------------------------
#endif
