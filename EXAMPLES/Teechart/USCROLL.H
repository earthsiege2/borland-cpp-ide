//---------------------------------------------------------------------------
#ifndef UScrollH
#define UScrollH
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
class TScrollForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TPanel *Panel1;
  TButton *Button1;
  TBitBtn *BitBtn3;
  TCheckBox *CBVertical;
  void __fastcall LineSeries1AfterAdd(TChartSeries *Sender,
          int ValueIndex);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall CBVerticalClick(TObject *Sender);
private:	// User declarations
  void AddPoint(const double x, const double y, TColor AColor);
  void FillDemoPoints();
public:		// User declarations
  __fastcall TScrollForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TScrollForm *ScrollForm;
//---------------------------------------------------------------------------
#endif
