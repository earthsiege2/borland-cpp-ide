//---------------------------------------------------------------------------
#ifndef specsH
#define specsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TChartSpecs : public TForm
{
__published:	// IDE-managed Components
  TMemo *Memo1;
  TPanel *Panel2;
  TLabel *Label1;
  TImage *Image2;
  TBitBtn *BitBtn1;
  TPanel *Panel1;
  TMemo *Memo2;
  TBitBtn *BitBtn2;
  void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TChartSpecs(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TChartSpecs *ChartSpecs;
//---------------------------------------------------------------------------
#endif
