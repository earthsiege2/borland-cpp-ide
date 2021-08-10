//---------------------------------------------------------------------------
#ifndef UBitmapH
#define UBitmapH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TBitmapForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TBarSeries *Series1;
  TPanel *Panel1;
  TRadioGroup *RadioGroup1;
  TBitBtn *BitBtn1;
  TBitBtn *BitBtn3;
  TCheckBox *CheckBox1;
  TButton *Button1;
  TMemo *Memo1;
  TOpenDialog *OpenDialog1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall RadioGroup1Click(TObject *Sender);
  void __fastcall BitBtn1Click(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
  void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TBitmapForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBitmapForm *BitmapForm;
//---------------------------------------------------------------------------
#endif
