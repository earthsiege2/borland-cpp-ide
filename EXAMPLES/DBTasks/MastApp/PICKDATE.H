//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef pickdateH
#define pickdateH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include "CCALENDR.h"
//---------------------------------------------------------------------------
class TBrDateForm : public TForm
{
__published:	// IDE-managed Components
	TButton *OkBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
	TLabel *TitleLabel;
	TSpeedButton *PrevMonthBtn;
	TSpeedButton *NextMonthBtn;
   TCCalendar *Calendar1;
	void __fastcall PrevMonthBtnClick(TObject *Sender);
	void __fastcall NextMonthBtnClick(TObject *Sender);
	void __fastcall Calendar1Change(TObject *Sender);
        
        
private:	// User declarations
    void SetDate(TDateTime Date);
    TDateTime GetDate();
public:		// User declarations
    __property TDateTime Date={read=GetDate,write=SetDate};
	virtual __fastcall TBrDateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TBrDateForm *BrDateForm;
//---------------------------------------------------------------------------
#endif
