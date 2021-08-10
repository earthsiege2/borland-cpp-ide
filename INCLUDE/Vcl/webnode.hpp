// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebNode.pas' rev: 6.00

#ifndef WebNodeHPP
#define WebNodeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IntfInfo.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webnode
{
//-- type declarations -------------------------------------------------------
__interface IWebNode;
typedef System::DelphiInterface<IWebNode> _di_IWebNode;
__interface INTERFACE_UUID("{D8AFC380-2A17-4BED-8359-81B502CE61B3}") IWebNode  : public IInterface 
{
	
public:
	virtual void __fastcall Execute(const WideString DataMsg, Classes::TStream* Response) = 0 ;
	virtual void __fastcall BeforeExecute(const Intfinfo::TIntfMetaData &IntfMD, const Intfinfo::TIntfMethEntry &MethMD) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Webnode */
using namespace Webnode;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebNode
