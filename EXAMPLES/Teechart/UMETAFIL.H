//---------------------------------------------------------------------------
#ifndef UMetafilH
#define UMetafilH
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
//---------------------------------------------------------------------------
class TMetafileForm : public TForm
{
__published:	// IDE-managed Components
  TImage *Image1;
  TChart *Chart1;
  TBarSeries *BarSeries1;
  TPanel *Panel1;
  TBitBtn *BitBtn2;
  TBitBtn *BitBtn3;
  TBitBtn *BitBtn4;
  TPanel *Panel2;
  TSaveDialog *SaveDialog1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall BitBtn3Click(TObject *Sender);
  void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TMetafileForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMetafileForm *MetafileForm;
//---------------------------------------------------------------------------
#endif
