// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'NMS_Stream.pas' rev: 5.00

#ifndef NMS_StreamHPP
#define NMS_StreamHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Nms_stream
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TS_BufferState { bsUnknown, bsRead, bsWrite };
#pragma option pop

class DELPHICLASS TS_BufferStream;
class PASCALIMPLEMENTATION TS_BufferStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	Classes::TStream* fStream;
	char *fBuffer;
	char *fBufPtr;
	char *fBufEnd;
	unsigned fBufSize;
	TS_BufferState fState;
	Classes::TNotifyEvent fOnFillBuffer;
	Classes::TNotifyEvent fOnFlushBuffer;
	int __fastcall GetBufPosition(void);
	
protected:
	virtual bool __fastcall FillBuffer(void);
	virtual void __fastcall PutBack(char Ch);
	virtual void __fastcall AfterFillBuffer(void);
	virtual void __fastcall AfterFlushBuffer(void);
	__property char * Buffer = {read=fBuffer};
	__property char * BufPtr = {read=fBufPtr};
	__property unsigned BufSize = {read=fBufSize, nodefault};
	__property char * BufEnd = {read=fBufEnd};
	__property int BufPosition = {read=GetBufPosition, nodefault};
	__property TS_BufferState State = {read=fState, nodefault};
	__property Classes::TStream* Stream = {read=fStream};
	
public:
	__fastcall virtual TS_BufferStream(Classes::TStream* Stream);
	__fastcall virtual ~TS_BufferStream(void);
	virtual bool __fastcall FlushBuffer(void);
	virtual int __fastcall Read(void *Buffer, int Count);
	virtual int __fastcall Write(const void *Buffer, int Count);
	virtual int __fastcall Seek(int Offset, Word Origin);
	bool __fastcall IsEof(void);
	__property Classes::TNotifyEvent OnFillBuffer = {read=fOnFillBuffer, write=fOnFillBuffer};
	__property Classes::TNotifyEvent OnFlushBuffer = {read=fOnFlushBuffer, write=fOnFlushBuffer};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int BufferSize;

}	/* namespace Nms_stream */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Nms_stream;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// NMS_Stream
