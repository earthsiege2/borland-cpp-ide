// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QClipbrd.pas' rev: 6.00

#ifndef QClipbrdHPP
#define QClipbrdHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QGraphics.hpp>	// Pascal unit
#include <QConsts.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qclipbrd
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TClipboard;
class PASCALIMPLEMENTATION TClipboard : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	AnsiString FCachedProvidesFormat;
	WideString FCachedText;
	Qt::QClipboardH* FHandle;
	Qt::QClipboard_hookH* FHook;
	bool FCachedProvidesResponse;
	bool FCachedTextValid;
	void __fastcall ClearCache(void);
	void __cdecl ClipboardChangedNotification(void);
	void __fastcall AssignGraphic(Qgraphics::TGraphic* Source);
	void __fastcall AssignPicture(Qgraphics::TPicture* Source);
	void __fastcall AssignMimeSource(Qtypes::TMimeSource* Source);
	void __fastcall AssignToBitmap(Qgraphics::TBitmap* Dest);
	void __fastcall AssignToPicture(Qgraphics::TPicture* Dest);
	WideString __fastcall GetAsText();
	void __fastcall SetAsText(const WideString Value);
	Qt::QClipboardH* __fastcall GetHandle(void);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	
public:
	__fastcall virtual ~TClipboard(void);
	bool __fastcall AddFormat(const AnsiString Format, Classes::TStream* Stream);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Clear(void);
	Classes::TComponent* __fastcall GetComponent(Classes::TComponent* Owner, Classes::TComponent* Parent);
	bool __fastcall GetFormat(const AnsiString Format, Classes::TStream* Stream);
	void __fastcall SetFormat(const AnsiString Format, Classes::TStream* Stream);
	bool __fastcall Provides(const AnsiString Format);
	int __fastcall RegisterClipboardFormat(const AnsiString Format);
	void __fastcall SetComponent(Classes::TComponent* Component);
	void __fastcall SupportedFormats(Classes::TStrings* List);
	__property WideString AsText = {read=GetAsText, write=SetAsText};
	__property Qt::QClipboardH* Handle = {read=GetHandle};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TClipboard(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TClipboard* __fastcall Clipboard(void);
extern PACKAGE TClipboard* __fastcall SetClipboard(TClipboard* NewClipboard);

}	/* namespace Qclipbrd */
using namespace Qclipbrd;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QClipbrd
