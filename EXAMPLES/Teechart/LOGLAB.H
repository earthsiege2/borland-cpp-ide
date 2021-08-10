//---------------------------------------------------------------------------
#ifndef LogLabH
#define LogLabH
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
class TCustomLabelsForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TFastLineSeries *Series1;
  TPanel *Panel1;
  TBitBtn *BitBtn2;
  TMemo *Memo1;
  void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TCustomLabelsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCustomLabelsForm *CustomLabelsForm;
//---------------------------------------------------------------------------
#endif
