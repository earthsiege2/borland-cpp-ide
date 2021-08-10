#ifndef MainH
#define MainH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#define WM_INFOSTART WM_USER

//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:
  void __fastcall FormDestroy(TObject *Sender);
  void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
    TShiftState Shift);
  void __fastcall FormPaint(TObject *Sender);
private:
  LPDIRECTDRAW  lpDD;
  LPDIRECTDRAWSURFACE  lpDDSPrimary;
  LPDIRECTDRAWSURFACE  lpDDSBack;
  LPDIRECTDRAWSURFACE  lpDDSOne;
  LPDIRECTDRAWPALETTE  lpDDPal;
  BOOL FActive;
  BOOL FRunApp;
  void UpdateFrame(void);
  void Start();
  void InitFail();
  HRESULT RestoreAll(void);
  MESSAGE void MyMove(TMessage &Message);
public:
  __fastcall TFormMain(TComponent* Owner);
BEGIN_MESSAGE_MAP
  MESSAGE_HANDLER(WM_INFOSTART, TMessage, MyMove);
END_MESSAGE_MAP(TForm);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
