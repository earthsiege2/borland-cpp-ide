//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef BaseModH
#define BaseModH
//---------------------------------------------------------------------------
#include <Windows.hpp>
#include <Messages.hpp>
#include <Sysutils.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class TBase : public TForm
{
__published:
    TPanel *Panel1;
    TPanel *Panel2;
    TLabel *Label1;
    TButton *Button1;
    void __fastcall Button1Click(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TBase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TBase *Base;
//---------------------------------------------------------------------------
#endif
