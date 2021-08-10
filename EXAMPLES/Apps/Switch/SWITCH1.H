//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef Switch1H
#define Switch1H
//----------------------------------------------------------------------------
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
class TFormMain : public TForm
{
__published:
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button1Click2(TObject *Sender);
private:
public:
    virtual __fastcall TFormMain(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TFormMain *FormMain;
//----------------------------------------------------------------------------
#endif	
