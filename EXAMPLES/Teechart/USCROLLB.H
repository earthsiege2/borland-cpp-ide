//---------------------------------------------------------------------------
#ifndef UScrollBH
#define UScrollBH
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
class TScrollBarForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TScrollBar *ScrollBar2;
  TScrollBar *ScrollBar1;
  TLineSeries *LineSeries1;
  void __fastcall ScrollBar1Change(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall ScrollBar2Change(TObject *Sender);
  void __fastcall Chart1Scroll(TObject *Sender);
  void __fastcall Chart1UndoZoom(TObject *Sender);
  void __fastcall Chart1Zoom(TObject *Sender);
  void __fastcall Chart1Resize(TObject *Sender);
private:	// User declarations
  bool ChangingBars;
  void CalcScrollBarPos();
public:		// User declarations
  __fastcall TScrollBarForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TScrollBarForm *ScrollBarForm;
//---------------------------------------------------------------------------
#endif
