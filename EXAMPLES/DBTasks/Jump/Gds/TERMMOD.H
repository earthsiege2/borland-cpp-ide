//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef TermModH
#define TermModH
//---------------------------------------------------------------------------
#include <Windows.hpp>
#include <Messages.hpp>
#include <Sysutils.hpp>
#include <Graphics.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Dbgrids.hpp>
#include <Grids.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>
#include "CustMod.h"
//---------------------------------------------------------------------------
class TTerm : public TCust
{
__published:
    void __fastcall FilterToggleClick(TObject *Sender);
    void __fastcall FilterTextChange(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TTerm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TTerm *Term;
//---------------------------------------------------------------------------
#endif
