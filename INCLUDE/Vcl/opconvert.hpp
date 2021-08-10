// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OPConvert.pas' rev: 6.00

#ifndef OPConvertHPP
#define OPConvertHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <XMLIntf.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <InvokeRegistry.hpp>	// Pascal unit
#include <IntfInfo.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Opconvert
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSOAPConvertOption { soSendUntyped, soSendMultiRefObj, soSendMultiRefArray, soTryAllSchema, soRootRefNodesToBody, soDocument, soReturnSuccessForFault, soUTF8InHeader, soDontSendEmptyNodes };
#pragma option pop

typedef Set<TSOAPConvertOption, soSendUntyped, soDontSendEmptyNodes>  TSOAPConvertOptions;

__interface IOPConvert;
typedef System::DelphiInterface<IOPConvert> _di_IOPConvert;
__interface INTERFACE_UUID("{918CDE63-20E4-427D-8455-24489FF959D8}") IOPConvert  : public IInterface 
{
	
public:
	virtual TSOAPConvertOptions __fastcall GetOptions(void) = 0 ;
	virtual void __fastcall SetOptions(TSOAPConvertOptions Value) = 0 ;
	virtual WideString __fastcall InvContextToMsg(const Intfinfo::TIntfMetaData &IntfMD, int MethNum, Invokeregistry::TInvContext* Con) = 0 ;
	virtual void __fastcall ProcessResponse(const Classes::TStream* Resp, const Intfinfo::TIntfMetaData &IntfMD, const Intfinfo::TIntfMethEntry &MD, Invokeregistry::TInvContext* Context) = 0 /* overload */;
	virtual void __fastcall ProcessResponse(const WideString Resp, const Intfinfo::TIntfMetaData &IntfMD, const Intfinfo::TIntfMethEntry &MD, Invokeregistry::TInvContext* Context) = 0 /* overload */;
	virtual void __fastcall MsgToInvContext(const WideString Request, const Intfinfo::TIntfMetaData &IntfMD, int &MethNum, Invokeregistry::TInvContext* Context) = 0 /* overload */;
	virtual void __fastcall MsgToInvContext(const Classes::TStream* Request, const Intfinfo::TIntfMetaData &IntfMD, int &MethNum, Invokeregistry::TInvContext* Context) = 0 /* overload */;
	virtual void __fastcall MakeResponse(const Intfinfo::TIntfMetaData &IntfMD, const int MethNum, Invokeregistry::TInvContext* Context, Classes::TStream* Response) = 0 ;
	virtual WideString __fastcall MakeFault(const Sysutils::Exception* Ex) = 0 ;
	__property TSOAPConvertOptions Options = {read=GetOptions, write=SetOptions};
};

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Opconvert */
using namespace Opconvert;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OPConvert
