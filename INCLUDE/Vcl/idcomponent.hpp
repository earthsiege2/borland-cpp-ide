// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdComponent.pas' rev: 6.00

#ifndef IdComponentHPP
#define IdComponentHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <IdResourceStrings.hpp>	// Pascal unit
#include <IdStack.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <IdBaseComponent.hpp>	// Pascal unit
#include <IdAntiFreezeBase.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcomponent
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TIdStatus { hsResolving, hsConnecting, hsConnected, hsDisconnecting, hsDisconnected, hsText };
#pragma option pop

typedef AnsiString IdComponent__1[6];

typedef void __fastcall (__closure *TIdStatusEvent)(System::TObject* axSender, const TIdStatus axStatus, const AnsiString asStatusText);

#pragma option push -b-
enum TWorkMode { wmRead, wmWrite };
#pragma option pop

#pragma pack(push, 4)
struct TWorkInfo
{
	int Current;
	int Max;
	int Level;
} ;
#pragma pack(pop)

typedef void __fastcall (__closure *TWorkBeginEvent)(System::TObject* Sender, TWorkMode AWorkMode, const int AWorkCountMax);

typedef void __fastcall (__closure *TWorkEndEvent)(System::TObject* Sender, TWorkMode AWorkMode);

typedef void __fastcall (__closure *TWorkEvent)(System::TObject* Sender, TWorkMode AWorkMode, const int AWorkCount);

class DELPHICLASS TIdComponent;
class PASCALIMPLEMENTATION TIdComponent : public Idbasecomponent::TIdBaseComponent 
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	TIdStatusEvent FOnStatus;
	TWorkEvent FOnWork;
	TWorkBeginEvent FOnWorkBegin;
	TWorkEndEvent FOnWorkEnd;
	TWorkInfo FWorkInfos[2];
	void __fastcall DoStatus(TIdStatus axStatus)/* overload */;
	void __fastcall DoStatus(TIdStatus axStatus, const System::TVarRec * aaArgs, const int aaArgs_Size)/* overload */;
	AnsiString __fastcall GetLocalName();
	__property TWorkEvent OnWork = {read=FOnWork, write=FOnWork};
	__property TWorkBeginEvent OnWorkBegin = {read=FOnWorkBegin, write=FOnWorkBegin};
	__property TWorkEndEvent OnWorkEnd = {read=FOnWorkEnd, write=FOnWorkEnd};
	
public:
	virtual void __fastcall BeginWork(TWorkMode AWorkMode, const int ASize = 0x0);
	__fastcall virtual TIdComponent(Classes::TComponent* axOwner);
	__fastcall virtual ~TIdComponent(void);
	virtual void __fastcall DoWork(TWorkMode AWorkMode, const int ACount);
	virtual void __fastcall EndWork(TWorkMode AWorkMode);
	__property AnsiString LocalName = {read=GetLocalName};
	
__published:
	__property TIdStatusEvent OnStatus = {read=FOnStatus, write=FOnStatus};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE AnsiString IdStati[6];

}	/* namespace Idcomponent */
using namespace Idcomponent;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdComponent
