//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
#ifndef ServMainH
#define ServMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *QueryCount;
    TLabel *ClientCount;
private:	// User declarations
    int FQueryCount;
    int FClientCount;
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
    void __fastcall UpdateClientCount(int Incr);
    void __fastcall IncQueryCount(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
