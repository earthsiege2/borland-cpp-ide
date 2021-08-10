//---------------------------------------------------------------------------
#ifndef UKBoarH
#define UKBoarH
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
class TKeyboardForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TPanel *Panel1;
  TBitBtn *BitBtn1;
  TCheckBox *InvertScroll;
  TCheckBox *CheckLimits;
  TMemo *Memo1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
  void __fastcall CheckLimitsClick(TObject *Sender);
  void __fastcall InvertScrollClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TKeyboardForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKeyboardForm *KeyboardForm;
//---------------------------------------------------------------------------
#endif
