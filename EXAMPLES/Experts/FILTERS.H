//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef filterH
#define filterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFilterDlg : public TForm
{
__published:	// IDE-managed Components 
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Description;
        TEdit *Extension;
        TButton *Button1;
        TButton *Button2;
private:	// User declarations
private:
	void __fastcall SetFilter(const String Value);
	String __fastcall GetFilter(void);

public:		// User declarations
        virtual __fastcall TFilterDlg(TComponent* Owner);
        __property String Filter = {read=GetFilter, write=SetFilter};
};
//---------------------------------------------------------------------------
extern TFilterDlg *FilterDlg;
//---------------------------------------------------------------------------
#endif
