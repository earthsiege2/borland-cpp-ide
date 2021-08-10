// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Masks.pas' rev: 5.00

#ifndef MasksHPP
#define MasksHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Masks
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TMask;
class PASCALIMPLEMENTATION TMask : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	void *FMask;
	int FSize;
	
public:
	__fastcall TMask(const AnsiString MaskValue);
	__fastcall virtual ~TMask(void);
	bool __fastcall Matches(const AnsiString Filename);
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall MatchesMask(const AnsiString Filename, const AnsiString Mask);

}	/* namespace Masks */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Masks;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Masks
