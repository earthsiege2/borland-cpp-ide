//---------------------------------------------------------------------------
#ifndef UPrintH
#define UPrintH
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
class TPrintForm : public TForm
{
__published:	// IDE-managed Components
  TLabel *Label1;
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TBitBtn *BitBtn1;
  TEdit *Edit1;
  TBitBtn *BitBtn2;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TPrintForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPrintForm *PrintForm;
//---------------------------------------------------------------------------
#endif
