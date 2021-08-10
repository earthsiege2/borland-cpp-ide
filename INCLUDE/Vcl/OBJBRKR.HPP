// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ObjBrkr.pas' rev: 6.00

#ifndef ObjBrkrHPP
#define ObjBrkrHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Variants.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <MConnect.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Objbrkr
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EBrokerException;
class PASCALIMPLEMENTATION EBrokerException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EBrokerException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EBrokerException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EBrokerException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EBrokerException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EBrokerException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EBrokerException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EBrokerException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EBrokerException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EBrokerException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TServerItem;
class PASCALIMPLEMENTATION TServerItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	bool FEnabled;
	AnsiString FComputerName;
	bool FHasFailed;
	int FPort;
	
protected:
	virtual AnsiString __fastcall GetDisplayName();
	
public:
	__fastcall virtual TServerItem(Classes::TCollection* AOwner);
	__property bool HasFailed = {read=FHasFailed, write=FHasFailed, nodefault};
	
__published:
	__property AnsiString ComputerName = {read=FComputerName, write=FComputerName};
	__property int Port = {read=FPort, write=FPort, default=211};
	__property bool Enabled = {read=FEnabled, write=FEnabled, default=1};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TServerItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TServerCollection;
class PASCALIMPLEMENTATION TServerCollection : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TServerItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TServerItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TServerItem* Value);
	
public:
	__fastcall TServerCollection(Classes::TComponent* AOwner);
	AnsiString __fastcall GetBalancedName();
	AnsiString __fastcall GetNextName();
	TServerItem* __fastcall FindServer(const AnsiString ComputerName);
	__property TServerItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TServerCollection(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSimpleObjectBroker;
class PASCALIMPLEMENTATION TSimpleObjectBroker : public Mconnect::TCustomObjectBroker 
{
	typedef Mconnect::TCustomObjectBroker inherited;
	
private:
	TServerCollection* FServers;
	bool FLoadBalanced;
	void __fastcall SetServers(TServerCollection* Value);
	bool __fastcall IsServersStored(void);
	AnsiString __fastcall GetNextComputer();
	OleVariant __fastcall GetServerData();
	void __fastcall SetServerData(const OleVariant &Value);
	
public:
	__fastcall virtual TSimpleObjectBroker(Classes::TComponent* AOwner);
	__fastcall virtual ~TSimpleObjectBroker(void);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	__property OleVariant ServerData = {read=GetServerData, write=SetServerData};
	virtual void __fastcall SetConnectStatus(AnsiString ComputerName, bool Success);
	virtual AnsiString __fastcall GetComputerForGUID(const GUID &GUID);
	virtual AnsiString __fastcall GetComputerForProgID(const void *ProgID);
	virtual int __fastcall GetPortForComputer(const AnsiString ComputerName);
	
__published:
	__property TServerCollection* Servers = {read=FServers, write=SetServers, stored=IsServersStored};
	__property bool LoadBalanced = {read=FLoadBalanced, write=FLoadBalanced, default=0};
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Objbrkr */
using namespace Objbrkr;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ObjBrkr
