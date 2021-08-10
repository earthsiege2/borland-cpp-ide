//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef headmainH
#define headmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:    // IDE-managed Components 
    THeaderControl *HeaderControl1;
    TShape *Shape1;
    TShape *Shape2;
    TShape *Shape3;
    TLabel *Label1;
    void __fastcall HeaderControl1SectionTrack(
      THeaderControl *HeaderControl, THeaderSection *Section,
      int Width, TSectionTrackState State);

private:        // User declarations
public:         // User declarations
    virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
