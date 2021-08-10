//---------------------------------------------------------------------------
#ifndef UCrossHH
#define UCrossHH
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
class TCrossHairForm : public TForm
{
__published:	// IDE-managed Components
  TChart *Chart1;
  TLineSeries *LineSeries1;
  TPanel *Panel1;
  TLabel *Label1;
  TLabel *Label2;
  TBitBtn *BitBtn1;
  TCheckBox *CheckBox1;
  TBitBtn *BitBtn2;
  TMemo *Memo1;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall Chart1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
  void __fastcall LineSeries1AfterDrawValues(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
  void __fastcall BitBtn2Click(TObject *Sender);
    
private:	// User declarations
  int OldX;
  int OldY;
  TColor CrossHairColor;
  TPenStyle CrossHairStyle;
  void DrawCross(int AX, int AY);
public:		// User declarations
  __fastcall TCrossHairForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCrossHairForm *CrossHairForm;
//---------------------------------------------------------------------------
#endif
 