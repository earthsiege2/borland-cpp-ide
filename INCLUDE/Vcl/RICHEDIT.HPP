// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'RichEdit.pas' rev: 5.00

#ifndef RichEditHPP
#define RichEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <RichEdit.h>

namespace Richedit
{
//-- type declarations -------------------------------------------------------
struct TCharFormatA
{
	unsigned cbSize;
	int dwMask;
	int dwEffects;
	int yHeight;
	int yOffset;
	unsigned crTextColor;
	Byte bCharSet;
	Byte bPitchAndFamily;
	char szFaceName[32];
} ;

struct TCharFormatW
{
	unsigned cbSize;
	int dwMask;
	int dwEffects;
	int yHeight;
	int yOffset;
	unsigned crTextColor;
	Byte bCharSet;
	Byte bPitchAndFamily;
	wchar_t szFaceName[32];
} ;

typedef TCharFormatA  TCharFormat;

typedef _charrange  TCharRange;

typedef TEXTRANGEA  TTextRangeA;

typedef TEXTRANGEW  TTextRangeW;

typedef TEXTRANGEA  TEXTRANGE;

typedef int __stdcall (*TEditStreamCallBack)(int dwCookie, Windows::PByte pbBuff, int cb, int &pcb);
	

typedef _editstream  TEditStream;

typedef FINDTEXTA  FINDTEXT;

typedef FINDTEXTA  TFindTextA;

typedef FINDTEXTW  TFindTextW;

typedef FINDTEXTA  TFindText;

typedef FINDTEXTEXA  FINDTEXTEX;

typedef FINDTEXTEXA  TFindTextExA;

typedef FINDTEXTEXW  TFindTextExW;

typedef FINDTEXTEXA  TFindTextEx;

typedef _formatrange  TFormatRange;

typedef _paraformat  TParaFormat;

typedef CHARFORMAT2A  CHARFORMAT2;

typedef CHARFORMAT2A  TCharFormat2A;

typedef CHARFORMAT2W  TCharFormat2W;

typedef PARAFORMAT2  TParaFormat2;

typedef _msgfilter *PMsgFilter;

typedef _msgfilter  TMsgFilter;

struct TReqSize;
typedef TReqSize *PReqSize;

struct TReqSize
{
	tagNMHDR nmhdr;
	Windows::TRect rc;
} ;

typedef _selchange *PSelChange;

typedef _selchange  TSelChange;

struct TEndDropFiles
{
	tagNMHDR nmhdr;
	unsigned hDrop;
	int cp;
	BOOL fProtected;
} ;

typedef _enprotected *PENProtected;

typedef _enprotected  TENProtected;

typedef _ensaveclipboard *PENSaveClipboard;

typedef _ensaveclipboard  TENSaveClipboard;

typedef ENOLEOPFAILED  TENOleOpFailed;

typedef OBJECTPOSITIONS  TObjectPositions;

typedef ENLINK  TENLink;

typedef _encorrecttext  TENCorrectText;

typedef _punctuation  TPunctuation;

typedef _compcolor  TCompColor;

typedef _repastespecial  TRepasteSpecial;

typedef GETTEXTEX  TGetTextEx;

typedef GETTEXTLENGTHEX  TGetTextLengthEx;

//-- var, const, procedure ---------------------------------------------------
#define RICHEDIT_CLASS10A "RICHEDIT"
static const Shortint FT_MATCHCASE = 0x4;
static const Shortint FT_WHOLEWORD = 0x2;

}	/* namespace Richedit */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Richedit;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// RichEdit
