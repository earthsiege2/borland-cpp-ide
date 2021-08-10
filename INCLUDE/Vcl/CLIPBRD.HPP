// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Clipbrd.pas' rev: 6.00

#ifndef ClipbrdHPP
#define ClipbrdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clipbrd
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClipboard;
class PASCALIMPLEMENTATION TClipboard : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FOpenRefCount;
	HWND FClipboardWindow;
	bool FAllocated;
	bool FEmptied;
	void __fastcall Adding(void);
	void __fastcall AssignGraphic(Graphics::TGraphic* Source);
	void __fastcall AssignPicture(Graphics::TPicture* Source);
	void __fastcall AssignToBitmap(Graphics::TBitmap* Dest);
	void __fastcall AssignToMetafile(Graphics::TMetafile* Dest);
	void __fastcall AssignToPicture(Graphics::TPicture* Dest);
	AnsiString __fastcall GetAsText();
	HWND __fastcall GetClipboardWindow(void);
	int __fastcall GetFormatCount(void);
	Word __fastcall GetFormats(int Index);
	void __fastcall SetAsText(const AnsiString Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	void __fastcall SetBuffer(Word Format, void *Buffer, int Size);
	virtual void __fastcall WndProc(Messages::TMessage &Message);
	void __fastcall MainWndProc(Messages::TMessage &Message);
	__property HWND Handle = {read=GetClipboardWindow, nodefault};
	__property int OpenRefCount = {read=FOpenRefCount, nodefault};
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	virtual void __fastcall Close(void);
	Classes::TComponent* __fastcall GetComponent(Classes::TComponent* Owner, Classes::TComponent* Parent);
	unsigned __fastcall GetAsHandle(Word Format);
	int __fastcall GetTextBuf(char * Buffer, int BufSize);
	bool __fastcall HasFormat(Word Format);
	virtual void __fastcall Open(void);
	void __fastcall SetComponent(Classes::TComponent* Component);
	void __fastcall SetAsHandle(Word Format, unsigned Value);
	void __fastcall SetTextBuf(char * Buffer);
	__property AnsiString AsText = {read=GetAsText, write=SetAsText};
	__property int FormatCount = {read=GetFormatCount, nodefault};
	__property Word Formats[int Index] = {read=GetFormats};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TClipboard(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TClipboard(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Word CF_PICTURE;
extern PACKAGE Word CF_COMPONENT;
extern PACKAGE TClipboard* __fastcall Clipboard(void);
extern PACKAGE TClipboard* __fastcall SetClipboard(TClipboard* NewClipboard);

}	/* namespace Clipbrd */
using namespace Clipbrd;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Clipbrd
