// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrLogColSettingsFrame.pas' rev: 6.00

#ifndef SvrLogColSettingsFrameHPP
#define SvrLogColSettingsFrameHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SvrLog.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <SvrLogFrame.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Svrlogcolsettingsframe
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TLogColSettingsFrame;
class PASCALIMPLEMENTATION TLogColSettingsFrame : public Forms::TFrame 
{
	typedef Forms::TFrame inherited;
	
__published:
	Comctrls::TListView* lvColumns;
	void __fastcall FrameResize(System::TObject* Sender);
	
private:
	Svrlogframe::TLogFrame* FLogFrame;
	void __fastcall SetLogFrame(const Svrlogframe::TLogFrame* Value);
	
public:
	void __fastcall UpdateColumns(void);
	__property Svrlogframe::TLogFrame* LogFrame = {read=FLogFrame, write=SetLogFrame};
public:
	#pragma option push -w-inl
	/* TCustomFrame.Create */ inline __fastcall virtual TLogColSettingsFrame(Classes::TComponent* AOwner) : Forms::TFrame(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScrollingWinControl.Destroy */ inline __fastcall virtual ~TLogColSettingsFrame(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TLogColSettingsFrame(HWND ParentWindow) : Forms::TFrame(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Svrlogcolsettingsframe */
using namespace Svrlogcolsettingsframe;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrLogColSettingsFrame
