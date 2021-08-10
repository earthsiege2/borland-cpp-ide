//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef Event2H
#define Event2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmEvents : public TForm
{
__published:    // IDE-managed Components 
    TGroupBox *GroupBox1;
    TButton *btnOpenDatabase;
    TButton *btnCloseDatabase;
    TGroupBox *GroupBox4;
    TLabel *Label1;
    TButton *btnGenerateEvent;
    TEdit *ebEvent;
    TGroupBox *GroupBox2;
    TButton *btnRegisterEvents;
    TMemo *moRegister;
    TGroupBox *GroupBox3;
    TButton *btnClearEvents;
    TListBox *lbReceived;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall btnOpenDatabaseClick(TObject *Sender);
    void __fastcall btnCloseDatabaseClick(TObject *Sender);
    void __fastcall btnGenerateEventClick(TObject *Sender);
    void __fastcall btnRegisterEventsClick(TObject *Sender);
    void __fastcall btnClearEventsClick(TObject *Sender);
private:        // User declarations
public:         // User declarations
    virtual __fastcall TfrmEvents(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TfrmEvents *frmEvents;
//---------------------------------------------------------------------------
#endif
