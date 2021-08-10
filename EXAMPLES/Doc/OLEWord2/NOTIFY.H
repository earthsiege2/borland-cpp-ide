//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef NOTIFYH
#define NOTIFYH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TNotifyForm : public TForm
{
__published:	// IDE-managed Components 
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
private:	// User declarations
public:		// User declarations
	virtual __fastcall TNotifyForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TNotifyForm *NotifyForm;
//---------------------------------------------------------------------------
#endif
