#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#define WM_RUNAPP WM_USER

class TFormMain : public TForm
{
__published:
  void __fastcall FormDestroy(TObject *Sender);
  void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
    TShiftState Shift);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall Timer1Timer(TObject *Sender);
private:
  LPDIRECTDRAW            lpDD;           // DirectDraw object
  LPDIRECTDRAWSURFACE     lpDDSPrimary;   // DirectDraw primary surface
  LPDIRECTDRAWSURFACE     lpDDSBack;      // DirectDraw back surface
  BOOL FActive;        // is application active?
  BYTE FPhase;
  RECT FShapeRect;
  int FValueAdd;
  AnsiString FrontMsg;
  AnsiString BackMsg;
  void __fastcall Start();
  MESSAGE void Run(TMessage &Message);
  void DrawShape(HDC &DC);
public:
  __fastcall TFormMain(TComponent* Owner);
BEGIN_MESSAGE_MAP
  MESSAGE_HANDLER(WM_RUNAPP, TMessage, Run);
END_MESSAGE_MAP(TForm);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
