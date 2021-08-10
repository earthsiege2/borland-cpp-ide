// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdCoder.pas' rev: 6.00

#ifndef IdCoderHPP
#define IdCoderHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdGlobal.hpp>	// Pascal unit
#include <IdBaseComponent.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idcoder
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TStringEvent)(Classes::TComponent* ASender, const AnsiString AOut);

typedef void __fastcall (__closure *TIntStringEvent)(Classes::TComponent* ASender, int AVal, const AnsiString AOut);

#pragma pack(push, 1)
struct TQWord
{
	unsigned L;
	unsigned H;
} ;
#pragma pack(pop)

class DELPHICLASS TIdCoder;
typedef TIdCoder* *PIdCoder;

class PASCALIMPLEMENTATION TIdCoder : public Idbasecomponent::TIdBaseComponent 
{
	typedef Idbasecomponent::TIdBaseComponent inherited;
	
protected:
	bool FAddCRLF;
	bool FAutoCompleteInput;
	#pragma pack(push, 1)
	TQWord FByteCount;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	TQWord FBytesIn;
	#pragma pack(pop)
	
	#pragma pack(push, 1)
	TQWord FBytesOut;
	#pragma pack(pop)
	
	unsigned FCBufferSize;
	unsigned FCBufferedData;
	AnsiString FCBuffer;
	AnsiString FFileName;
	bool FIgnoreCodedData;
	bool FIgnoreNotification;
	bool FInCompletion;
	AnsiString FKey;
	Byte FPriority;
	TStringEvent FOnCodedData;
	TIntStringEvent FOnNotification;
	Classes::TStringList* FOutputStrings;
	bool FTakesFileName;
	bool FTakesKey;
	bool FUseEvent;
	virtual void __fastcall Coder(void);
	virtual void __fastcall CompleteCoding(void);
	void __fastcall IncByteCount(unsigned bytes);
	void __fastcall InternSetBufferSize(int BufferSize);
	void __fastcall OutputNotification(int AVal, AnsiString AStr);
	void __fastcall OutputString(AnsiString s);
	
public:
	__fastcall virtual TIdCoder(Classes::TComponent* AOwner);
	__fastcall virtual ~TIdCoder(void);
	AnsiString __fastcall CodeString(AnsiString AStr);
	void __fastcall CodeStringFromCoder(Classes::TComponent* Sender, const AnsiString sOut);
	virtual AnsiString __fastcall CompletedInput();
	virtual AnsiString __fastcall GetCodedData();
	virtual AnsiString __fastcall GetNotification();
	virtual void __fastcall Reset(void);
	virtual void __fastcall SetKey(const AnsiString key);
	virtual void __fastcall SetBufferSize(unsigned ASize);
	__property bool AddCRLF = {read=FAddCRLF, write=FAddCRLF, nodefault};
	__property bool AutoCompleteInput = {read=FAutoCompleteInput, write=FAutoCompleteInput, nodefault};
	__property unsigned BufferSize = {read=FCBufferSize, write=SetBufferSize, nodefault};
	__property TQWord ByteCount = {read=FByteCount};
	__property TQWord BytesIn = {read=FBytesIn};
	__property TQWord BytesOut = {read=FBytesOut};
	__property AnsiString FileName = {read=FFileName, write=FFileName};
	__property bool IgnoreCodedData = {read=FIgnoreCodedData, write=FIgnoreCodedData, nodefault};
	__property bool IgnoreNotification = {read=FIgnoreNotification, write=FIgnoreNotification, nodefault};
	__property AnsiString Key = {read=FKey, write=SetKey};
	__property TStringEvent OnCodedData = {read=FOnCodedData, write=FOnCodedData};
	__property TIntStringEvent OnNotification = {read=FOnNotification, write=FOnNotification};
	__property Byte Priority = {read=FPriority, nodefault};
	__property bool TakesFileName = {read=FTakesFileName, nodefault};
	__property bool TakesKey = {read=FTakesKey, nodefault};
	__property bool UseEvent = {read=FUseEvent, write=FUseEvent, nodefault};
};


typedef TMetaClass*CIdCoder;

class DELPHICLASS TIdCoderItem;
typedef TIdCoderItem* *PIdCoderItem;

class PASCALIMPLEMENTATION TIdCoderItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	Byte FCoderType;
	Byte FCoderPriority;
	AnsiString FContentType;
	AnsiString FContentTransferEncoding;
	TMetaClass*FIdCoderClass;
	
public:
	__property Byte CoderType = {read=FCoderType, nodefault};
	__property Byte CoderPriority = {read=FCoderPriority, nodefault};
	__property AnsiString ContentType = {read=FContentType};
	__property AnsiString ContentTransferEncoding = {read=FContentTransferEncoding};
	__property TMetaClass* IdCoderClass = {read=FIdCoderClass, write=FIdCoderClass};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TIdCoderItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdCoderItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdCoderCollection;
class PASCALIMPLEMENTATION TIdCoderCollection : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
protected:
	unsigned FCount;
	TIdCoderItem* __fastcall GetCoder(unsigned Index);
	HIDESBASE TIdCoderItem* __fastcall Add(void);
	
public:
	__fastcall TIdCoderCollection(TMetaClass* ItemClass);
	TIdCoderItem* __fastcall AddCoder(void);
	TIdCoderItem* __fastcall GetCoderType(AnsiString ContentType, AnsiString ContentTransferEncoding, Byte CoderType);
	TIdCoderItem* __fastcall GetExactCoderType(AnsiString ContentType, AnsiString ContentTransferEncoding, Byte CoderType);
	__property TIdCoderItem* Items[unsigned Index] = {read=GetCoder};
	__property unsigned ItemCount = {read=FCount, nodefault};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdCoderCollection(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint CT_Creation = 0x0;
static const Byte CT_Realisation = 0x80;
static const Shortint CP_FALLBACK = 0x0;
static const Shortint CP_IMF = 0x1;
static const Shortint CP_STANDARD = 0x8;
static const Shortint CN_CODED_DATA = 0x0;
static const Shortint CN_DATA_START_FOUND = 0x1;
static const Shortint CN_DATA_END_FOUND = 0x2;
static const Shortint CN_CODING_STARTED = 0x3;
static const Shortint CN_CODING_ENDED = 0x4;
static const Shortint CN_NEW_FILENAME = 0x5;
static const Shortint CN_IMF_CODER_START = 0x14;
static const Shortint CN_IMF_BODY_START = 0x15;
static const Shortint CN_IMF_BODY_PART_END = 0x16;
static const Shortint CN_IMF_HEAD_VALUE = 0x17;
static const Shortint CN_IMF_NEW_MULTIPART = 0x18;
static const Shortint CN_IMF_END_MULTIPART = 0x19;
static const Shortint CN_IMF_DATA_END = 0x1a;
static const Shortint CN_IMF_NEW_FILENAME = 0x5;
static const Shortint CN_UU_CODER_START = 0x28;
static const Shortint CN_UU_TABLE_FOUND = 0x29;
static const Shortint CN_UU_BEGIN_FOUND = 0x2a;
static const Shortint CN_UU_TABLE_BEGIN_ABORT = 0x2b;
static const Shortint CN_UU_LAST_CHAR_FOUND = 0x2c;
static const Shortint CN_UU_END_FOUND = 0x2d;
static const Shortint CN_UU_TABLE_CHANGED = 0x2e;
static const Shortint CN_UU_PRIVILEGE_FOUND = 0x2f;
static const Shortint CN_UU_PRIVILEGE_ERROR = 0x30;
static const Shortint CN_UU_NEW_FILENAME = 0x5;
extern PACKAGE TIdCoderCollection* CoderCollective;
extern PACKAGE void __fastcall RegisterCoderClass(TMetaClass* ClassType, Byte CoderType, Byte CoderPriority, AnsiString ContentType, AnsiString ContentTransferEncoding);
extern PACKAGE void __fastcall IncQWord(TQWord &QWord, unsigned IncVal);

}	/* namespace Idcoder */
using namespace Idcoder;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdCoder
