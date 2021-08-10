#ifndef MainH
#define MainH
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>

#define WM_RUNAPP WM_USER
#define CIRCLETYPE 0
#define RECTTYPE 1

class TDrawShape : public TObject
{
private:
  int FX;
  int FY;
  int FX1;
  int FY1;
  int FMoveValX;
  int FMoveValY;
  int FShapeType;
  RECT FPrevRect, FPrevRect2;
  TColor FColor;
  RECT __fastcall GetRect()
  {
    return Rect(FX,FY,FX1,FY1);
  }
  void __fastcall SetRect(RECT R)
  {
    FX = R.left; FY = R.top; FX1 = R.right; FY1 = R.bottom;
  }
public:
  __fastcall TDrawShape(int ValX, int ValY) { FMoveValX = ValX; FMoveValY = ValY; }
  __fastcall TDrawShape(int ValX, int ValY, int X, int Y, int AType, TColor AColor);
  void Move();
  void Draw(HDC &DC);
  __property RECT ShapeRect={read=GetRect, write=SetRect};
  __property int ShapeType={read=FShapeType, write=FShapeType};
  __property TColor Color={read=FColor, write=FColor};
};

class TFormMain : public TForm
{
__published:
  void __fastcall FormDestroy(TObject *Sender);
  void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
    TShiftState Shift);
  void __fastcall FormPaint(TObject *Sender);
private:
  LPDIRECTDRAW            lpDD;           // DirectDraw object
  LPDIRECTDRAWSURFACE     lpDDSPrimary;   // DirectDraw primary surface
  LPDIRECTDRAWSURFACE     lpDDSBack;      // DirectDraw back surface
  BOOL FActive;        // is application active?
  BYTE FPhase;
  RECT FShapeRect;
  TList *FShapeList;
  int FValueAdd;
  void BuildList();
  void DrawShape(HDC &DC);
  void PerformAction();
  MESSAGE void Run(TMessage &Message);
  void __fastcall Start();
public:
  __fastcall TFormMain(TComponent* Owner);
BEGIN_MESSAGE_MAP
  MESSAGE_HANDLER(WM_RUNAPP, TMessage, Run);
END_MESSAGE_MAP(TForm);
};

extern TFormMain *FormMain;

#endif
