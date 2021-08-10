// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SvrStatsFrame.pas' rev: 6.00

#ifndef SvrStatsFrameHPP
#define SvrStatsFrameHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SvrLog.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
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

namespace Svrstatsframe
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStatsFrame;
class PASCALIMPLEMENTATION TStatsFrame : public Forms::TFrame 
{
	typedef Forms::TFrame inherited;
	
__published:
	Stdctrls::TButton* Button1;
	Actnlist::TActionList* ActionList1;
	Actnlist::TAction* ResetCountsAction;
	Stdctrls::TLabel* lblTotalResponseTime;
	Stdctrls::TLabel* lblAvgResponseTime;
	Stdctrls::TLabel* lblLastResponseTime;
	Stdctrls::TLabel* lblRequestCount;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label7;
	Stdctrls::TLabel* Label8;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TLabel* lblMinResponseTime;
	Stdctrls::TLabel* lblMaxResponseTime;
	Stdctrls::TGroupBox* GroupBox1;
	void __fastcall ResetCountsActionExecute(System::TObject* Sender);
	void __fastcall ResetCountsActionUpdate(System::TObject* Sender);
	
private:
	unsigned FResponseCount;
	unsigned FRequestCount;
	System::TDateTime FTotalResponseTime;
	System::TDateTime FLastResponseTime;
	System::TDateTime FMaxResponseTime;
	System::TDateTime FMinResponseTime;
	System::TDateTime __fastcall GetAvgResponseTime(void);
	void __fastcall UpdateUI(void);
	
public:
	void __fastcall LogStatistics(Svrlog::TTransactionLogEntry* ATransaction);
	__property unsigned RequestCount = {read=FRequestCount, nodefault};
	__property unsigned ResponseCount = {read=FResponseCount, nodefault};
	__property System::TDateTime TotalResponseTime = {read=FTotalResponseTime};
	__property System::TDateTime AvgResponseTime = {read=GetAvgResponseTime};
	__property System::TDateTime LastResponseTime = {read=FLastResponseTime};
	__property System::TDateTime MaxResponseTime = {read=FMaxResponseTime};
	__property System::TDateTime MinResponseTime = {read=FMinResponseTime};
public:
	#pragma option push -w-inl
	/* TCustomFrame.Create */ inline __fastcall virtual TStatsFrame(Classes::TComponent* AOwner) : Forms::TFrame(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TScrollingWinControl.Destroy */ inline __fastcall virtual ~TStatsFrame(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TStatsFrame(HWND ParentWindow) : Forms::TFrame(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Svrstatsframe */
using namespace Svrstatsframe;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SvrStatsFrame
