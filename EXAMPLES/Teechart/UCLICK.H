//---------------------------------------------------------------------------
#ifndef UClickH
#define UClickH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TClickingForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TPointSeries *Series1;
    TPanel *Panel1;
    TButton *Button1;
    TLabel *Label1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall Chart1ClickSeries(TCustomChart *Sender,
          TChartSeries *Series, int ValueIndex, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall Chart1ClickLegend(TCustomChart *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
  void __fastcall Chart1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
private:	// User declarations
public:		// User declarations
  __fastcall TClickingForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TClickingForm *ClickingForm;
//---------------------------------------------------------------------------
#endif
 