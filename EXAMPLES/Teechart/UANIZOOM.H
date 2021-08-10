//---------------------------------------------------------------------------
#ifndef UAniZoomH
#define UAniZoomH
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
class TFormAnimatedZoom : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TLineSeries *LineSeries2;
  TLineSeries *LineSeries3;
  TLineSeries *LineSeries4;
  TLineSeries *LineSeries5;
  TPointSeries *PointSeries1;
  TPanel *Panel1;
  TLabel *Label1;
  TCheckBox *CheckBox1;
  TCheckBox *CheckBox2;
  TBitBtn *BitBtn2;
  TBitBtn *BitBtn1;
  TBitBtn *BitBtn3;
  TMemo *Memo1;
        TScrollBar *ScrollBar1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
  void __fastcall CheckBox2Click(TObject *Sender);
  void __fastcall BitBtn1Click(TObject *Sender);
  void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall ScrollBar1Change(TObject *Sender);
private:	// User declarations
  void RandomValues(TChartSeries* ASeries);
public:		// User declarations
  __fastcall TFormAnimatedZoom(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAnimatedZoom *FormAnimatedZoom;
//---------------------------------------------------------------------------
#endif
