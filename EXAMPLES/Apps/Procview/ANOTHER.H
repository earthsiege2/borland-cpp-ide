//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef AnotherH
#define AnotherH
//----------------------------------------------------------------------------
#include <ExtCtrls.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <System.hpp>
//----------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:
	TButton *Button1;
    TLabel *Title;
    TLabel *Comments;
    TLabel *Copyright;
    TLabel *Borland;
public:
    virtual __fastcall TForm2(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TForm2 *Form2;
//----------------------------------------------------------------------------
#endif	
