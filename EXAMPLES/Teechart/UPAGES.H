//---------------------------------------------------------------------------
#ifndef UPagesH
#define UPagesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <BubbleCh.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TPagesForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TBubbleSeries *BubbleSeries1;
  TPanel *Panel1;
  TLabel *Label2;
  TLabel *Label1;
  TBitBtn *ButtonPrevious;
  TBitBtn *ButtonNext;
  TBitBtn *BLastPage;
  TBitBtn *BFirstPage;
  TCheckBox *CheckBox1;
  TBitBtn *BitBtn3;
  TMemo *Memo1;
        TScrollBar *ScrollBar1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall Chart1PageChange(TObject *Sender);
  void __fastcall ButtonPreviousClick(TObject *Sender);
  void __fastcall ButtonNextClick(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
  void __fastcall BFirstPageClick(TObject *Sender);
  void __fastcall BLastPageClick(TObject *Sender);
        void __fastcall ScrollBar1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TPagesForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPagesForm *PagesForm;
//---------------------------------------------------------------------------
#endif
