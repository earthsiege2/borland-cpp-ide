// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BandActn.pas' rev: 6.00

#ifndef BandActnHPP
#define BandActnHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <CustomizeDlg.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <ActnMan.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "dclact.lib"

namespace Bandactn
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomizeActionBars;
class PASCALIMPLEMENTATION TCustomizeActionBars : public Actnlist::TAction 
{
	typedef Actnlist::TAction inherited;
	
private:
	Customizedlg::TCustomizeDlg* FCustomizeDlg;
	Actnman::TCustomActionManager* FActionManager;
	
public:
	__fastcall virtual TCustomizeActionBars(Classes::TComponent* AOwner);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	
__published:
	__property Actnman::TCustomActionManager* ActionManager = {read=FActionManager, write=FActionManager};
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TCustomizeActionBars(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Bandactn */
using namespace Bandactn;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BandActn
