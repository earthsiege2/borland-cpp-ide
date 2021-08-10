//----------------------------------------------------------------------------
// RichEdit.hpp - bcbdcc32 generated hdr (DO NOT EDIT) rev: 0
// From: RichEdit.pas
//----------------------------------------------------------------------------
#ifndef RichEditHPP
#define RichEditHPP
//----------------------------------------------------------------------------
#include <Windows.hpp>
#include <Messages.hpp>
#include <System.hpp>
#ifdef WIN32_LEAN_AND_MEAN
#include <wtypes.h>
#endif
#ifdef _VCL_LEAN_AND_MEAN
#include <windows.h>
#undef _VCL_LEAN_AND_MEAN
#endif
#include <Richedit.h>

#pragma warn -par
#pragma warn -hid 
#pragma warn -inl

namespace Richedit
{
//-- type declarations -------------------------------------------------------

typedef _charformat  TCharFormat;

typedef _charrange  TCharRange;

typedef long __fastcall (*TEditStreamCallBack)(long dwCookie, Windows::PByte pbBuff, long cb, long &
	pcb);

typedef _textrange  TTextRange;

typedef _editstream  TEditStream;

typedef _findtext  TFindText;

typedef _findtextexa  TFindTextEx;

typedef _formatrange  TFormatRange;

typedef _paraformat  TParaFormat;

typedef _msgfilter *PMsgFilter;

typedef _msgfilter  TMsgFilter;

struct TReqSize;
typedef TReqSize *PReqSize;

struct TReqSize
{
	NMHDR nmhdr;
	Windows::TRect rc;
} ;

typedef _selchange *PSelChange;

typedef _selchange  TSelChange;

struct TEndDropFiles
{
	NMHDR nmhdr;
	int hDrop;
	long cp;
	DWord fProtected;
} ;

typedef _enprotected *PENProtected;

typedef _enprotected  TENProtected;

typedef _ensaveclipboard *PENSaveClipboard;

typedef _ensaveclipboard  TENSaveClipboard;

typedef _encorrecttext  TENCorrectText;

typedef _punctuation  TPunctuation;

typedef _compcolor  TCompColor;

typedef _repastespecial  TRepasteSpecial;

//-- var, const, procedure ---------------------------------------------------
#define FT_MATCHCASE (Byte)(4)
#define FT_WHOLEWORD (Byte)(2)

}	/* namespace Richedit */

#pragma warn .par
#pragma warn .hid 
#pragma warn .inl

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Richedit;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// RichEdit
