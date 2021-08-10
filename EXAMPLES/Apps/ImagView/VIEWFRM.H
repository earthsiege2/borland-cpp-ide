//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef ViewFrmH
#define ViewFrmH
//----------------------------------------------------------------------------
#include <ExtCtrls.hpp>
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
class TViewFrm : public TForm
{
__published:
	TImage *Image1;
public:
    virtual __fastcall TViewFrm(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TViewFrm *ViewFrm;
//----------------------------------------------------------------------------
#endif	
