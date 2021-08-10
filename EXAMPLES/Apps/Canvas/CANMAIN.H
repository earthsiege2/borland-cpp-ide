//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef canmainH
#define canmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
const int  MaxPoints    = 15;  // Number of points to be drawn 

struct TRPoint {
  float X, Y;
};
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:    // IDE-managed Components 
    TTimer *Timer1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormPaint(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
private:        // User declarations
    TRPoint     Points[MaxPoints];
    float       Rotation;     // in radians
    int         PointCount;
    void __fastcall RotatePoints();
public:         // User declarations
    virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
