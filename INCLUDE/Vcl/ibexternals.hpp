// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IBExternals.pas' rev: 6.00

#ifndef IBExternalsHPP
#define IBExternalsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IBUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ibexternals
{
//-- type declarations -------------------------------------------------------
typedef int Int;

typedef unsigned UInt;

typedef int Long;

typedef unsigned ULong;

typedef short Short;

typedef Word UShort;

typedef float Float;

typedef Byte UChar;

typedef int ISC_LONG;

typedef unsigned UISC_LONG;

typedef __int64 ISC_INT64;

typedef int ISC_STATUS;

typedef unsigned UISC_STATUS;

typedef void *Void;

typedef char * *PPChar;

typedef short *PSmallInt;

typedef int *PInt;

typedef int *PInteger;

typedef short *PShort;

typedef Word *PUShort;

typedef int *PLong;

typedef unsigned *PULong;

typedef float *PFloat;

typedef Byte *PUChar;

typedef void * *PVoid;

typedef double *PDouble;

typedef int *PISC_LONG;

typedef unsigned *PUISC_LONG;

typedef int *PISC_STATUS;

typedef PISC_STATUS *PPISC_STATUS;

typedef unsigned *PUISC_STATUS;

#pragma pack(push, 4)
struct TCTimeStructure
{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
} ;
#pragma pack(pop)

typedef TCTimeStructure *PCTimeStructure;

typedef TCTimeStructure  TM;

typedef TCTimeStructure *PTM;

#pragma pack(push, 2)
struct TISC_VARYING
{
	short strlen;
	char str[1];
} ;
#pragma pack(pop)

typedef short __cdecl (*TISC_BlobGetSegment)(PInt BlobHandle, char * Buffer, int BufferSize, int &ResultLength);

typedef void __cdecl (*TISC_BlobPutSegment)(PInt BlobHandle, char * Buffer, short BufferLength);

#pragma pack(push, 4)
struct TBlob
{
	TISC_BlobGetSegment GetSegment;
	int *BlobHandle;
	int SegmentCount;
	int MaxSegmentLength;
	int TotalSize;
	TISC_BlobPutSegment PutSegment;
} ;
#pragma pack(pop)

typedef TBlob *PBlob;

//-- var, const, procedure ---------------------------------------------------
static const Shortint dSun = 0x1;
static const Shortint dMon = 0x2;
static const Shortint dTue = 0x3;
static const Shortint dWed = 0x4;
static const Shortint dThu = 0x5;
static const Shortint dFri = 0x6;
static const Shortint dSat = 0x7;
static const Shortint dJan = 0x1;
static const Shortint dFeb = 0x2;
static const Shortint dMar = 0x3;
static const Shortint dApr = 0x4;
static const Shortint dMay = 0x5;
static const Shortint dJun = 0x6;
static const Shortint dJul = 0x7;
static const Shortint dAug = 0x8;
static const Shortint dSep = 0x9;
static const Shortint dOct = 0xa;
static const Shortint dNov = 0xb;
static const Shortint dDec = 0xc;
static const Word cYearOffset = 0x76c;
static const Shortint cSun = 0x0;
static const Shortint cMon = 0x1;
static const Shortint cTue = 0x2;
static const Shortint cWed = 0x3;
static const Shortint cThu = 0x4;
static const Shortint cFri = 0x5;
static const Shortint cSat = 0x6;
static const Shortint cJan = 0x0;
static const Shortint cFeb = 0x1;
static const Shortint cMar = 0x2;
static const Shortint cApr = 0x3;
static const Shortint cMay = 0x4;
static const Shortint cJun = 0x5;
static const Shortint cJul = 0x6;
static const Shortint cAug = 0x7;
static const Shortint cSep = 0x8;
static const Shortint cOct = 0x9;
static const Shortint cNov = 0xa;
static const Shortint cDec = 0xb;
extern PACKAGE void __fastcall InitializeTCTimeStructure(TCTimeStructure &tm_record);

}	/* namespace Ibexternals */
using namespace Ibexternals;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IBExternals
