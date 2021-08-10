//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef optionsH
#define optionsH
//----------------------------------------------------------------------------
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <ComCtrls.hpp>
//----------------------------------------------------------------------------
class TOptionsDlg : public TForm
{
__published:
    TButton *OKBtn;
    TButton *CancelBtn;
    TBevel *Bevel1;
    TTrackBar *SpeedSet;
    TTrackBar *PopulationSet;
    TEdit *GameTimeSet;
    TLabel *Slow;
    TLabel *Fast;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Speed;
    TLabel *Population;
    TLabel *Time;
    void __fastcall OKBtnClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:
public:
    virtual __fastcall TOptionsDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern TOptionsDlg *OptionsDlg;
//----------------------------------------------------------------------------
#endif    
