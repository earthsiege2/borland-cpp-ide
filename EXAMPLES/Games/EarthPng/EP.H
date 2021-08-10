//---------------------------------------------------------------------------
#ifndef VCLEarthPongH
#define VCLEarthPongH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <mmsystem.h>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormPaint(TObject *Sender);
	
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	
private:	// User declarations
    bool GameOver;
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
    void __fastcall IdleLoop(TObject*, bool&);
    TImage *backgroundImage;
    TImage *spriteImage;
    TImage *paddle;
    TCanvas	*backgroundCanvas;
    TCanvas *workCanvas;
    TRect	backgroundRect, spriteRect, changeRect, paddleRect, changePaddleRect;
    int x, y, xDir, yDir, paddleX, paddleY, paddleCenter, Angle;
    void __fastcall virtual SetCursor(TMessage &);
    BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(WM_SETCURSOR, TMessage, SetCursor)
    END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
