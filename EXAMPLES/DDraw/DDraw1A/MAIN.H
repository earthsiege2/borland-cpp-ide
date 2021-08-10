//---------------------------------------------------------------------------
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
class TFormMain : public TForm
{
__published:
        TTimer *Timer1;
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
        TShiftState Shift);
        void __fastcall FormPaint(TObject *Sender);
        
        void __fastcall Timer1Timer(TObject *Sender);
private:
  LPDIRECTDRAW            lpDD;           // DirectDraw object
  LPDIRECTDRAWSURFACE     lpDDSPrimary;   // DirectDraw primary surface
  LPDIRECTDRAWSURFACE     lpDDSBack;      // DirectDraw back surface
  BOOL                    bActive;        // is application active?
  BYTE phase;
  AnsiString FrontMsg;
  AnsiString BackMsg;
  void __fastcall Start();
public:
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
