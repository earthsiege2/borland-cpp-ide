// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ToolUtils.pas' rev: 6.00

#ifndef ToolUtilsHPP
#define ToolUtilsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DesignIntf.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Toolutils
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TIUnknownEvent)(System::_di_IInterface Unk, System::_di_IInterface UnkParam);

class DELPHICLASS TOTAClass;
class PASCALIMPLEMENTATION TOTAClass : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
protected:
	Classes::_di_IInterfaceList FNotifyList;
	void __fastcall NotifyDestroyed(System::_di_IInterface Unk, System::_di_IInterface UnkParam);
	System::TObject* __fastcall GetInstance(void);
	
public:
	__fastcall TOTAClass(void);
	virtual void __fastcall BeforeDestruction(void);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TOTAClass(void) { }
	#pragma option pop
	
private:
	void *__IImplementation;	/* Designintf::IImplementation */
	
public:
	operator IImplementation*(void) { return (IImplementation*)&__IImplementation; }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int __fastcall AddToList(const Classes::_di_IInterfaceList List, System::_di_IInterface Item);
extern PACKAGE void __fastcall ForEach(const Classes::_di_IInterfaceList InterfaceList, TIUnknownEvent Event, const System::_di_IInterface UnkParam);

}	/* namespace Toolutils */
using namespace Toolutils;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ToolUtils
