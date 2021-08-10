// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdNetworkCalculator.pas' rev: 6.00

#ifndef IdNetworkCalculatorHPP
#define IdNetworkCalculatorHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdBaseComponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idnetworkcalculator
{
//-- type declarations -------------------------------------------------------
#pragma pack(push, 4)
struct TIpStruct
{
	
	union
	{
		struct 
		{
			unsigned FullAddr;
			
		};
		struct 
		{
			Byte Byte4;
			Byte Byte3;
			Byte Byte2;
			Byte Byte1;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma option push -b-
enum TNetworkClass { ID_NET_CLASS_A, ID_NET_CLASS_B, ID_NET_CLASS_C, ID_NET_CLASS_D, ID_NET_CLASS_E };
#pragma option pop

class DELPHICLASS TIpProperty;
class PASCALIMPLEMENTATION TIpProperty : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
protected:
	bool FReadOnly;
	Classes::TNotifyEvent FOnChange;
	bool FByteArray[32];
	unsigned FDoubleWordValue;
	AnsiString FAsString;
	AnsiString FAsBinaryString;
	Byte FByte3;
	Byte FByte4;
	Byte FByte2;
	Byte FByte1;
	void __fastcall SetReadOnly(const bool Value);
	void __fastcall SetOnChange(const Classes::TNotifyEvent Value);
	bool __fastcall GetByteArray(unsigned Index);
	void __fastcall SetAsBinaryString(const AnsiString Value);
	void __fastcall SetAsDoubleWord(const unsigned Value);
	void __fastcall SetAsString(const AnsiString Value);
	void __fastcall SetByteArray(unsigned Index, const bool Value);
	void __fastcall SetByte4(const Byte Value);
	void __fastcall SetByte1(const Byte Value);
	void __fastcall SetByte3(const Byte Value);
	void __fastcall SetByte2(const Byte Value);
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	
public:
	virtual void __fastcall SetAll(Byte One, Byte Two, Byte Tree, Byte Four);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property bool ByteArray[unsigned Index] = {read=GetByteArray, write=SetByteArray};
	
__published:
	__property Byte Byte1 = {read=FByte1, write=SetByte1, stored=false, nodefault};
	__property Byte Byte2 = {read=FByte2, write=SetByte2, stored=false, nodefault};
	__property Byte Byte3 = {read=FByte3, write=SetByte3, stored=false, nodefault};
	__property Byte Byte4 = {read=FByte4, write=SetByte4, stored=false, nodefault};
	__property unsigned AsDoubleWord = {read=FDoubleWordValue, write=SetAsDoubleWord, stored=false, nodefault};
	__property AnsiString AsBinaryString = {read=FAsBinaryString, write=SetAsBinaryString, stored=false};
	__property AnsiString AsString = {read=FAsString, write=SetAsString};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=SetOnChange};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TIpProperty(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIpProperty(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


class DELPHICLASS TIdNetworkCalculator;
class PASCALIMPLEMENTATION TIdNetworkCalculator : public Idbasecomponent::TIdBaseComponent 
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	Classes::TStrings* FListIP;
	unsigned FNetworkMaskLength;
	TIpProperty* FNetworkMask;
	TIpProperty* FNetworkAddress;
	TNetworkClass FNetworkClass;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnGenIPList;
	void __fastcall SetOnChange(const Classes::TNotifyEvent Value);
	void __fastcall SetOnGenIPList(const Classes::TNotifyEvent Value);
	Classes::TStrings* __fastcall GetListIP(void);
	void __fastcall SetNetworkAddress(const TIpProperty* Value);
	void __fastcall SetNetworkMask(const TIpProperty* Value);
	void __fastcall SetNetworkMaskLength(const unsigned Value);
	void __fastcall OnNetMaskChange(System::TObject* Sender);
	void __fastcall OnNetAddressChange(System::TObject* Sender);
	
public:
	int __fastcall NumIP(void);
	AnsiString __fastcall StartIP();
	AnsiString __fastcall EndIP();
	void __fastcall FillIPList(void);
	__fastcall virtual TIdNetworkCalculator(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdNetworkCalculator(void);
	__property Classes::TStrings* ListIP = {read=GetListIP};
	__property TNetworkClass NetworkClass = {read=FNetworkClass, nodefault};
	
__published:
	bool __fastcall IsAddressInNetwork(AnsiString Address);
	__property TIpProperty* NetworkAddress = {read=FNetworkAddress, write=SetNetworkAddress};
	__property TIpProperty* NetworkMask = {read=FNetworkMask, write=SetNetworkMask};
	__property unsigned NetworkMaskLength = {read=FNetworkMaskLength, write=SetNetworkMaskLength, default=32};
	__property Classes::TNotifyEvent OnGenIPList = {read=FOnGenIPList, write=SetOnGenIPList};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=SetOnChange};
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint ID_NC_MASK_LENGTH = 0x20;
#define ID_NETWORKCLASS (TNetworkClass)(0)

}	/* namespace Idnetworkcalculator */
using namespace Idnetworkcalculator;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdNetworkCalculator
