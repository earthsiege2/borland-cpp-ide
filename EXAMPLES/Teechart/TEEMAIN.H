//---------------------------------------------------------------------------
#ifndef TeeMainH
#define TeeMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeeFunci.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TTeeMainForm : public TForm
{
__published:	// IDE-managed Components
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TButton *Button6;
    TChart *Chart2;
    TLabel *Label10;
    TLabel *Label4;
    TFastLineSeries *FastLineSeries1;
    TFastLineSeries *FastLineSeries2;
    TChart *Chart7;
    TPieSeries *PieSeries6;
    TChart *Chart8;
    TPieSeries *PieSeries7;
    TChart *Chart10;
    TPieSeries *PieSeries9;
    TChart *Chart9;
    TPieSeries *PieSeries8;
    TAddTeeFunction *PieSeries8TAddTeeFunction;
    TChart *Chart1;
    TPieSeries *Series1;
        TLabel *Label5;
        TPanel *Panel2;
        TPanel *Panel3;
        TLabel *Label1;
        TLabel *Label9;
        TImage *Image1;
        TTimer *Timer2;
        TTimer *Timer1;
        TPanel *Panel1;
        TLabel *Label11;
        TLabel *Label13;
        TLabel *Label16;
        TLabel *Label14;
        TLabel *Label3;
        TButton *Button1;
        TLabel *Label2;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Timer2Timer(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Chart2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Chart2MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Label10Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button6Click(TObject *Sender);
    void __fastcall Label3Click(TObject *Sender);
private:	// User declarations
  int DeltaZoom;
public:		// User declarations
    __fastcall TTeeMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTeeMainForm *TeeMainForm;
//---------------------------------------------------------------------------
#endif
