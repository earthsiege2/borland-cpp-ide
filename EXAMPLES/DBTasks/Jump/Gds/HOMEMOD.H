//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef HomeModH
#define HomeModH
//---------------------------------------------------------------------------
#include <Windows.hpp>
#include <Messages.hpp>
#include <Sysutils.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "BASEMOD.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class THome : public TBase
{
__published:
    TButton *Button2;
    TButton *Button3;
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall THome(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern THome *Home;
//---------------------------------------------------------------------------
#endif
