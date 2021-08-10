// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Proxies.pas' rev: 6.00

#ifndef ProxiesHPP
#define ProxiesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Proxies
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall CreateSubClass(System::TObject* Instance, const AnsiString ClassName, const AnsiString UnitName, TMetaClass* Ancestor)/* overload */;
extern PACKAGE void __fastcall CreateSubClass(System::TObject* Instance, const AnsiString ClassName, TMetaClass* Ancestor)/* overload */;
extern PACKAGE void __fastcall ChangeToProxyClass(System::TObject* Instance, TMetaClass* Proxy);
extern PACKAGE void __fastcall DestroySubClass(System::TObject* Instance);
extern PACKAGE void __fastcall RenameSubClass(System::TObject* Instance, const AnsiString ClassName, const AnsiString UnitName = "");
extern PACKAGE void * __fastcall CreateSubClassMethod(System::TObject* Instance, const AnsiString MethodName);
extern PACKAGE void __fastcall RenameSubClassMethod(System::TObject* Instance, void * Method, const AnsiString MethodName);
extern PACKAGE void __fastcall DestroySubClassMethod(System::TObject* Instance, void * Method);
extern PACKAGE bool __fastcall IsProxyClass(TMetaClass* ClassType);

}	/* namespace Proxies */
using namespace Proxies;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Proxies
