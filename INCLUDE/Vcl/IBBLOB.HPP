// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBBlob.pas' rev: 6.00

#ifndef IBBlobHPP
#define IBBlobHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBUtils.hpp>	// Pascal unit
#include <IBDatabase.hpp>	// Pascal unit
#include <IB.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <IBExternals.hpp>	// Pascal unit
#include <IBErrorCodes.hpp>	// Pascal unit
#include <IBHeader.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibblob
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIBBlobStream;
class PASCALIMPLEMENTATION TIBBlobStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	Ibdatabase::TIBBase* FBase;
	Ibheader::TGDS_QUAD FBlobID;
	int FBlobMaxSegmentSize;
	int FBlobNumSegments;
	int FBlobSize;
	short FBlobType;
	char *FBuffer;
	bool FBlobInitialized;
	void * *FHandle;
	Db::TBlobStreamMode FMode;
	bool FModified;
	int FPosition;
	
protected:
	void __fastcall CloseBlob(void);
	void __fastcall CreateBlob(void);
	void __fastcall EnsureBlobInitialized(void);
	void __fastcall GetBlobInfo(void);
	Ibdatabase::TIBDatabase* __fastcall GetDatabase(void);
	Ibheader::PISC_DB_HANDLE __fastcall GetDBHandle(void);
	Ibdatabase::TIBTransaction* __fastcall GetTransaction(void);
	Ibheader::PISC_TR_HANDLE __fastcall GetTRHandle(void);
	void __fastcall OpenBlob(void);
	void __fastcall SetBlobID(const Ibheader::TGDS_QUAD &Value);
	void __fastcall SetDatabase(Ibdatabase::TIBDatabase* Value);
	void __fastcall SetMode(Db::TBlobStreamMode Value);
	void __fastcall SetTransaction(Ibdatabase::TIBTransaction* Value);
	
public:
	__fastcall TIBBlobStream(void);
	__fastcall virtual ~TIBBlobStream(void);
	int __fastcall Call(int ErrCode, bool RaiseError);
	void __fastcall Cancel(void);
	void __fastcall CheckReadable(void);
	void __fastcall CheckWritable(void);
	void __fastcall Finalize(void);
	void __fastcall LoadFromFile(AnsiString Filename);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual int __fastcall Read(void *Buffer, int Count);
	void __fastcall SaveToFile(AnsiString Filename);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual int __fastcall Seek(int Offset, Word Origin)/* overload */;
	virtual void __fastcall SetSize(int NewSize)/* overload */;
	void __fastcall Truncate(void);
	virtual int __fastcall Write(const void *Buffer, int Count);
	__property Ibexternals::PVoid Handle = {read=FHandle};
	__property Ibheader::TGDS_QUAD BlobID = {read=FBlobID, write=SetBlobID};
	__property int BlobMaxSegmentSize = {read=FBlobMaxSegmentSize, nodefault};
	__property int BlobNumSegments = {read=FBlobNumSegments, nodefault};
	__property int BlobSize = {read=FBlobSize, nodefault};
	__property short BlobType = {read=FBlobType, nodefault};
	__property Ibdatabase::TIBDatabase* Database = {read=GetDatabase, write=SetDatabase};
	__property Ibheader::PISC_DB_HANDLE DBHandle = {read=GetDBHandle};
	__property Db::TBlobStreamMode Mode = {read=FMode, write=SetMode, nodefault};
	__property bool Modified = {read=FModified, nodefault};
	__property Ibdatabase::TIBTransaction* Transaction = {read=GetTransaction, write=SetTransaction};
	__property Ibheader::PISC_TR_HANDLE TRHandle = {read=GetTRHandle};
	
/* Hoisted overloads: */
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, Classes::TSeekOrigin Origin){ return TStream::Seek(Offset, Origin); }
	
protected:
	inline void __fastcall  SetSize(const __int64 NewSize){ TStream::SetSize(NewSize); }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Word DefaultBlobSegmentSize = 0x4000;
extern PACKAGE void __fastcall GetBlobInfo(Ibheader::PISC_BLOB_HANDLE hBlobHandle, int &NumSegments, int &MaxSegmentSize, int &TotalSize, short &BlobType);
extern PACKAGE void __fastcall ReadBlob(Ibheader::PISC_BLOB_HANDLE hBlobHandle, char * Buffer, int BlobSize);
extern PACKAGE void __fastcall WriteBlob(Ibheader::PISC_BLOB_HANDLE hBlobHandle, char * Buffer, int BlobSize);

}	/* namespace Ibblob */
using namespace Ibblob;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBBlob
