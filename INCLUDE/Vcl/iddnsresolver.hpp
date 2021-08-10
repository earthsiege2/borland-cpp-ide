// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdDNSResolver.pas' rev: 6.00

#ifndef IdDNSResolverHPP
#define IdDNSResolverHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdComponent.hpp>	// Pascal unit
#include <IdUDPBase.hpp>	// Pascal unit
#include <IdUDPClient.hpp>	// Pascal unit
#include <IdGlobal.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <IdResourceStrings.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Iddnsresolver
{
//-- type declarations -------------------------------------------------------
typedef AnsiString IdDNSResolver__1[6];

typedef Byte TWKSBits[8];

typedef Byte TRequestedRecord;

typedef Set<TRequestedRecord, 1, 255>  TRequestedRecords;

class DELPHICLASS TIdDNSHeader;
class PASCALIMPLEMENTATION TIdDNSHeader : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	Word FAnCount;
	Word FArCount;
	Word FBitCode;
	Word FId;
	Word FQdCount;
	Word FNsCount;
	bool __fastcall GetAA(void);
	Word __fastcall GetOpCode(void);
	bool __fastcall GetQr(void);
	bool __fastcall GetRA(void);
	Word __fastcall GetRCode(void);
	bool __fastcall GetRD(void);
	bool __fastcall GetTC(void);
	void __fastcall InitializefId(void);
	void __fastcall SetAA(bool AuthAnswer);
	void __fastcall SetOpCode(Word OpCode);
	void __fastcall SetQr(bool IsResponse);
	void __fastcall SetRA(bool RecursionAvailable);
	void __fastcall SetRCode(Word RCode);
	void __fastcall SetRD(bool RecursionDesired);
	void __fastcall SetTC(bool IsTruncated);
	
public:
	__fastcall TIdDNSHeader(void);
	virtual void __fastcall InitVars(void);
	__property bool AA = {read=GetAA, write=SetAA, nodefault};
	__property Word ANCount = {read=FAnCount, write=FAnCount, nodefault};
	__property Word ARCount = {read=FArCount, write=FArCount, nodefault};
	__property Word ID = {read=FId, write=FId, nodefault};
	__property Word NSCount = {read=FNsCount, write=FNsCount, nodefault};
	__property Word Opcode = {read=GetOpCode, write=SetOpCode, nodefault};
	__property Word QDCount = {read=FQdCount, write=FQdCount, nodefault};
	__property bool Qr = {read=GetQr, write=SetQr, nodefault};
	__property bool RA = {read=GetRA, write=SetRA, nodefault};
	__property Word RCode = {read=GetRCode, write=SetRCode, nodefault};
	__property bool RD = {read=GetRD, write=SetRD, nodefault};
	__property bool TC = {read=GetTC, write=SetTC, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TIdDNSHeader(void) { }
	#pragma option pop
	
};


class DELPHICLASS TQuestionItem;
class PASCALIMPLEMENTATION TQuestionItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
public:
	Word QClass;
	AnsiString QName;
	Word QType;
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TQuestionItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TQuestionItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdDNSQuestionList;
class PASCALIMPLEMENTATION TIdDNSQuestionList : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TQuestionItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TQuestionItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TQuestionItem* Value);
	
public:
	__fastcall TIdDNSQuestionList(void);
	HIDESBASE TQuestionItem* __fastcall Add(void);
	__property TQuestionItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdDNSQuestionList(void) { }
	#pragma option pop
	
};


#pragma pack(push, 1)
struct THInfo
{
	System::ShortString CPUStr;
	System::ShortString OsStr;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TMInfo
{
	System::ShortString EMailBox;
	System::ShortString RMailBox;
} ;
#pragma pack(pop)

#pragma pack(push, 2)
struct TMX
{
	System::ShortString Exchange;
	Word Preference;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TSOA
{
	unsigned Expire;
	unsigned Minimum;
	System::ShortString MName;
	unsigned Refresh;
	unsigned Retry;
	System::ShortString RName;
	unsigned Serial;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TWKS
{
	unsigned Address;
	Byte Bits[8];
	Byte Protocol;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TRdata
{
	AnsiString DomainName;
	THInfo HInfo;
	TMInfo MInfo;
	TMX MX;
	TSOA SOA;
	unsigned A;
	TWKS WKS;
	AnsiString Data;
	AnsiString HostAddrStr;
} ;
#pragma pack(pop)

class DELPHICLASS TIdDNSResourceItem;
class PASCALIMPLEMENTATION TIdDNSResourceItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
public:
	Word AType;
	Word AClass;
	AnsiString Name;
	TRdata RData;
	Word RDLength;
	unsigned TTL;
	AnsiString StarData;
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TIdDNSResourceItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdDNSResourceItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdDNSResourceList;
class PASCALIMPLEMENTATION TIdDNSResourceList : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TIdDNSResourceItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdDNSResourceItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdDNSResourceItem* Value);
	
public:
	HIDESBASE TIdDNSResourceItem* __fastcall Add(void);
	__fastcall TIdDNSResourceList(void);
	__property TIdDNSResourceItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	
__published:
	AnsiString __fastcall GetDNSMxExchangeNameEx(int Idx);
	AnsiString __fastcall GetDNSRDataDomainName(int Idx);
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdDNSResourceList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMXRecord;
class PASCALIMPLEMENTATION TMXRecord : public TIdDNSResourceItem 
{
	typedef TIdDNSResourceItem inherited;
	
protected:
	Word FPreference;
	AnsiString FExchange;
	
public:
	__property Word Preference = {read=FPreference, nodefault};
	__property AnsiString Exchange = {read=FExchange};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TMXRecord(Classes::TCollection* Collection) : TIdDNSResourceItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TMXRecord(void) { }
	#pragma option pop
	
};


class DELPHICLASS TARecord;
class PASCALIMPLEMENTATION TARecord : public TIdDNSResourceItem 
{
	typedef TIdDNSResourceItem inherited;
	
protected:
	AnsiString FDomainName;
	
public:
	__property AnsiString DomainName = {read=FDomainName};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TARecord(Classes::TCollection* Collection) : TIdDNSResourceItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TARecord(void) { }
	#pragma option pop
	
};


class DELPHICLASS TNameRecord;
class PASCALIMPLEMENTATION TNameRecord : public TIdDNSResourceItem 
{
	typedef TIdDNSResourceItem inherited;
	
protected:
	AnsiString FDomainName;
	
public:
	__property AnsiString DomainName = {read=FDomainName};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TNameRecord(Classes::TCollection* Collection) : TIdDNSResourceItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TNameRecord(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPTRRecord;
class PASCALIMPLEMENTATION TPTRRecord : public TIdDNSResourceItem 
{
	typedef TIdDNSResourceItem inherited;
	
protected:
	AnsiString FDomainName;
	
public:
	__property AnsiString DomainName = {read=FDomainName};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TPTRRecord(Classes::TCollection* Collection) : TIdDNSResourceItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TPTRRecord(void) { }
	#pragma option pop
	
};


class DELPHICLASS THInfoRecord;
class PASCALIMPLEMENTATION THInfoRecord : public TIdDNSResourceItem 
{
	typedef TIdDNSResourceItem inherited;
	
protected:
	AnsiString FCPUStr;
	AnsiString FOsStr;
	
public:
	__property AnsiString CPUStr = {read=FCPUStr};
	__property AnsiString OsStr = {read=FOsStr};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual THInfoRecord(Classes::TCollection* Collection) : TIdDNSResourceItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~THInfoRecord(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMInfoRecord;
class PASCALIMPLEMENTATION TMInfoRecord : public TIdDNSResourceItem 
{
	typedef TIdDNSResourceItem inherited;
	
protected:
	AnsiString FEMmailBox;
	AnsiString FRMailBox;
	
public:
	__property AnsiString EMmailBox = {read=FEMmailBox};
	__property AnsiString RMailBox = {read=FRMailBox};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TMInfoRecord(Classes::TCollection* Collection) : TIdDNSResourceItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TMInfoRecord(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMRecord;
class PASCALIMPLEMENTATION TMRecord : public TIdDNSResourceItem 
{
	typedef TIdDNSResourceItem inherited;
	
protected:
	AnsiString FEMailBox;
	AnsiString FRMailBox;
	
public:
	__property AnsiString EMailBox = {read=FEMailBox};
	__property AnsiString RMailBox = {read=FRMailBox};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TMRecord(Classes::TCollection* Collection) : TIdDNSResourceItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TMRecord(void) { }
	#pragma option pop
	
};


class DELPHICLASS TSOARecord;
class PASCALIMPLEMENTATION TSOARecord : public TIdDNSResourceItem 
{
	typedef TIdDNSResourceItem inherited;
	
protected:
	unsigned FExpire;
	unsigned FMinimum;
	AnsiString FMName;
	unsigned FRefresh;
	unsigned FRetry;
	AnsiString FRName;
	unsigned FSerial;
	
public:
	__property unsigned Expire = {read=FExpire, nodefault};
	__property unsigned Minimum = {read=FMinimum, nodefault};
	__property AnsiString MName = {read=FMName};
	__property unsigned Refresh = {read=FRefresh, nodefault};
	__property unsigned Retry = {read=FRetry, nodefault};
	__property AnsiString RName = {read=FRName};
	__property unsigned Serial = {read=FSerial, nodefault};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TSOARecord(Classes::TCollection* Collection) : TIdDNSResourceItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TSOARecord(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWKSRecord;
class PASCALIMPLEMENTATION TWKSRecord : public TIdDNSResourceItem 
{
	typedef TIdDNSResourceItem inherited;
	
protected:
	unsigned FAddress;
	Byte FBits[8];
	Byte FProtocol;
	Byte __fastcall GetBits(int AIndex);
	
public:
	__property unsigned Address = {read=FAddress, nodefault};
	__property Byte Bits[int AIndex] = {read=GetBits};
	__property Byte Protocol = {read=FProtocol, nodefault};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TWKSRecord(Classes::TCollection* Collection) : TIdDNSResourceItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TWKSRecord(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdDNSResolver;
class PASCALIMPLEMENTATION TIdDNSResolver : public Idudpclient::TIdUDPClient 
{
	typedef Idudpclient::TIdUDPClient inherited;
	
protected:
	TIdDNSResourceList* FDNSAnList;
	TIdDNSResourceList* FDNSArList;
	TIdDNSHeader* FDNSHeader;
	TIdDNSQuestionList* FDNSQdList;
	TIdDNSResourceList* FDNSNsList;
	AnsiString FQPacket;
	AnsiString FRPacket;
	int FQPackSize;
	TRequestedRecords FRequestedRecords;
	int FRPackSize;
	TIdDNSResourceList* FAnswers;
	AnsiString __fastcall CreateLabelStr(AnsiString QName);
	void __fastcall CreateQueryPacket(void);
	void __fastcall DecodeReplyPacket(void);
	
public:
	virtual void __fastcall ClearVars(void);
	__fastcall virtual TIdDNSResolver(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdDNSResolver(void);
	void __fastcall ResolveDNS(void);
	void __fastcall ResolveDomain(const AnsiString ADomain);
	__property TIdDNSResourceList* Answers = {read=FAnswers};
	__property TIdDNSResourceList* DNSAnList = {read=FDNSAnList, write=FDNSAnList};
	__property TIdDNSResourceList* DNSARList = {read=FDNSArList, write=FDNSArList};
	__property TIdDNSHeader* DNSHeader = {read=FDNSHeader, write=FDNSHeader};
	__property TIdDNSQuestionList* DNSQDList = {read=FDNSQdList, write=FDNSQdList};
	__property TIdDNSResourceList* DNSNSList = {read=FDNSNsList, write=FDNSNsList};
	__property Port  = {default=53};
	__property AnsiString QPacket = {read=FQPacket, write=FQPacket};
	__property TRequestedRecords RequestedRecords = {read=FRequestedRecords, write=FRequestedRecords};
	__property AnsiString RPacket = {read=FRPacket, write=FRPacket};
	__property ReceiveTimeout  = {default=4000};
};


#pragma pack(push, 1)
struct HiLoBytes
{
	Byte HiByte;
	Byte LoByte;
} ;
#pragma pack(pop)

#pragma pack(push, 2)
struct WordRec
{
	
	union
	{
		struct 
		{
			Word AWord;
			
		};
		struct 
		{
			HiLoBytes TheBytes;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 2)
struct HiLoWords
{
	Word HiWord;
	Word LowWord;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct CardinalRec
{
	
	union
	{
		struct 
		{
			HiLoWords Words;
			
		};
		struct 
		{
			unsigned aCardinal;
			
		};
		
	};
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const Word IdDNSResolver_ReceiveTimeout = 0xfa0;
static const Word cQRBit = 0x8000;
static const Word cQRMask = 0xefff;
static const Word cOpCodeBits = 0x7800;
static const Word cOpCodeMask = 0x87ff;
static const Word cAABit = 0x400;
static const Word cAAMask = 0xfbff;
static const Word cTCBit = 0x200;
static const Word cTCMask = 0xfdff;
static const Word cRDBit = 0x100;
static const Word cRDMask = 0xfeff;
static const Byte cRABit = 0x80;
static const Word cRAMask = 0xff7f;
static const Shortint cRCodeBits = 0xf;
static const Word cRCodeMask = 0xfff0;
static const Shortint cResQuery = 0x0;
static const Shortint cResIQuery = 0x1;
static const Shortint cResStatus = 0x2;
extern PACKAGE System::SmallString<7>  cOPCodeStrs[3];
static const Shortint cA = 0x1;
static const Shortint cNS = 0x2;
static const Shortint cMD = 0x3;
static const Shortint cMF = 0x4;
static const Shortint cName = 0x5;
static const Shortint cSOA = 0x6;
static const Shortint cMB = 0x7;
static const Shortint cMG = 0x8;
static const Shortint cMR = 0x9;
static const Shortint cNULL = 0xa;
static const Shortint cWKS = 0xb;
static const Shortint cPTR = 0xc;
static const Shortint cHINFO = 0xd;
static const Shortint cMINFO = 0xe;
static const Shortint cMX = 0xf;
static const Shortint cTXT = 0x10;
static const Byte cAXFR = 0xfc;
static const Byte cMAILB = 0xfd;
static const Byte cMAILA = 0xfe;
static const Byte cStar = 0xff;
static const Shortint cIN = 0x1;
static const Shortint cCS = 0x2;
static const Shortint cCH = 0x3;
static const Shortint cHS = 0x4;
extern PACKAGE System::SmallString<3>  cQClassStr[4];
static const Shortint cRCodeNoError = 0x0;
static const Shortint cRCodeFormatErr = 0x1;
static const Shortint cRCodeServerErr = 0x2;
static const Shortint cRCodeNameErr = 0x3;
static const Shortint cRCodeNotImplemented = 0x4;
static const Shortint cRCodeRefused = 0x5;
extern PACKAGE AnsiString cRCodeStrs[6];
extern PACKAGE AnsiString __fastcall GetQTypeStr(int aQType);
extern PACKAGE AnsiString __fastcall GetQClassStr(int QClass);

}	/* namespace Iddnsresolver */
using namespace Iddnsresolver;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdDNSResolver
