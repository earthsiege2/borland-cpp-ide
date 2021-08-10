// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdAbout.pas' rev: 6.00

#ifndef IdAboutHPP
#define IdAboutHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idabout
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TformAbout;
class DELPHICLASS TScrollCredits;
class DELPHICLASS TCreditStrings;
class DELPHICLASS TCreditString;
class PASCALIMPLEMENTATION TCreditStrings : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TCreditString* operator[](int Index) { return Items[Index]; }
	
private:
	TScrollCredits* FOwner;
	Graphics::TFont* FHeaderFont;
	Graphics::TFont* FBodyFont;
	int FColSpace;
	TCreditString* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, const TCreditString* Value);
	void __fastcall SetBodyFont(const Graphics::TFont* Value);
	void __fastcall SetHeaderFont(const Graphics::TFont* Value);
	void __fastcall FontChange(System::TObject* Sender);
	void __fastcall SetColSpace(const int Value);
	
protected:
	virtual void __fastcall Update(Classes::TCollectionItem* Item);
	
public:
	HIDESBASE TCreditString* __fastcall Add(void);
	__fastcall TCreditStrings(TScrollCredits* AnOwner);
	__fastcall virtual ~TCreditStrings(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	tagSIZE __fastcall TextExtent(Graphics::TCanvas* Canvas);
	void __fastcall RenderText(const int ATop, const int AWidth, Graphics::TCanvas* Canvas);
	__property int ColSpace = {read=FColSpace, write=SetColSpace, nodefault};
	__property TCreditString* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
	__property Graphics::TFont* HeaderFont = {read=FHeaderFont, write=SetHeaderFont};
	__property Graphics::TFont* BodyFont = {read=FBodyFont, write=SetBodyFont};
};


class PASCALIMPLEMENTATION TScrollCredits : public Controls::TGraphicControl 
{
	typedef Controls::TGraphicControl inherited;
	
private:
	Graphics::TBitmap* bmpCredits;
	Graphics::TBitmap* bmpBack;
	Graphics::TBitmap* bmpBuffer;
	TCreditStrings* FCredits;
	int FCurrentLine;
	Graphics::TPicture* FBackground;
	void __fastcall SetCredits(const TCreditStrings* Value);
	void __fastcall BackgroundChange(System::TObject* Sender);
	void __fastcall CreditsChange(void);
	void __fastcall SetCurrentLine(const int Value);
	void __fastcall SetBackground(const Graphics::TPicture* Value);
	void __fastcall TransposeCredits(void);
	
protected:
	virtual void __fastcall Paint(void);
	HIDESBASE MESSAGE void __fastcall CMFontchanged(Messages::TMessage &Message);
	void __fastcall InvalidateBitmap(void);
	
public:
	__fastcall virtual TScrollCredits(Classes::TComponent* AOwner);
	__fastcall virtual ~TScrollCredits(void);
	
__published:
	__property Graphics::TPicture* Background = {read=FBackground, write=SetBackground};
	__property TCreditStrings* Credits = {read=FCredits, write=SetCredits};
	__property int CurrentLine = {read=FCurrentLine, write=SetCurrentLine, nodefault};
	__property OnClick ;
};


class PASCALIMPLEMENTATION TformAbout : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TPanel* Panel1;
	Extctrls::TPanel* Panel2;
	Extctrls::TBevel* bvlDialogBorder;
	Stdctrls::TLabel* lblCopyright;
	Stdctrls::TLabel* lblVersion;
	Stdctrls::TLabel* lblName;
	Stdctrls::TLabel* lblPleaseVisitUs;
	Stdctrls::TLabel* lblURL;
	Stdctrls::TButton* btnOk;
	Extctrls::TTimer* tmrScroll;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall lblURLClick(System::TObject* Sender);
	void __fastcall tmrScrollTimer(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	
protected:
	TScrollCredits* scrCredits;
	void __fastcall ScrollClick(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Messages::TWMEraseBkgnd &Message);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TformAbout(Classes::TComponent* AOwner) : Forms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TformAbout(Classes::TComponent* AOwner, int Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TformAbout(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TformAbout(HWND ParentWindow) : Forms::TForm(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TCreditString : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
public:
	AnsiString operator[](int Index) { return BodyItems[Index]; }
	
private:
	AnsiString FHeader;
	Classes::TStrings* FBody;
	int FColCount;
	#pragma pack(push, 1)
	tagSIZE FTextExtent;
	#pragma pack(pop)
	
	void __fastcall SetBody(const Classes::TStrings* Value);
	void __fastcall SetHeader(const AnsiString Value);
	void __fastcall BodyChanged(System::TObject* sender);
	void __fastcall SetColCount(const int Value);
	AnsiString __fastcall GetBodyItems(int Index);
	void __fastcall SetBodyItems(int Index, const AnsiString Value);
	__property AnsiString BodyItems[int Index] = {read=GetBodyItems, write=SetBodyItems/*, default*/};
	
protected:
	tagSIZE __fastcall TextExtent(Graphics::TCanvas* Canvas);
	void __fastcall RenderText(const int ATop, const int AWidth, Graphics::TCanvas* Canvas);
	
public:
	__fastcall virtual TCreditString(Classes::TCollection* Collection);
	__fastcall virtual ~TCreditString(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property AnsiString Header = {read=FHeader, write=SetHeader};
	__property Classes::TStrings* Body = {read=FBody, write=SetBody};
	__property int ColCount = {read=FColCount, write=SetColCount, default=1};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowAboutBox(const AnsiString AProductName, const AnsiString AProductVersion);

}	/* namespace Idabout */
using namespace Idabout;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdAbout
