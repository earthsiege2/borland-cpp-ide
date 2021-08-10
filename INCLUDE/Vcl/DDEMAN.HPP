// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DdeMan.pas' rev: 5.00

#ifndef DdeManHPP
#define DdeManHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <StdCtrls.hpp>	// Pascal unit
#include <Ddeml.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Ddeman
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TDataMode { ddeAutomatic, ddeManual };
#pragma option pop

typedef void __fastcall (__closure *TMacroEvent)(System::TObject* Sender, Classes::TStrings* Msg);

class DELPHICLASS TDdeClientConv;
class DELPHICLASS TDdeClientItem;
class PASCALIMPLEMENTATION TDdeClientConv : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	AnsiString FDdeService;
	AnsiString FDdeTopic;
	int FConv;
	tagCONVINFO FCnvInfo;
	Classes::TList* FItems;
	int FHszApp;
	int FHszTopic;
	int FDdeFmt;
	Classes::TNotifyEvent FOnClose;
	Classes::TNotifyEvent FOnOpen;
	AnsiString FAppName;
	TDataMode FDataMode;
	TDataMode FConnectMode;
	bool FWaitStat;
	bool FFormatChars;
	void __fastcall SetDdeService(const AnsiString Value);
	void __fastcall SetDdeTopic(const AnsiString Value);
	void __fastcall SetService(const AnsiString Value);
	void __fastcall SetTopic(const AnsiString Value);
	void __fastcall SetConnectMode(TDataMode NewMode);
	void __fastcall SetFormatChars(bool NewFmt);
	void __fastcall XactComplete(void);
	void __fastcall SrvrDisconnect(void);
	void __fastcall DataChange(int DdeDat, int hszIt);
	
protected:
	bool __fastcall CreateDdeConv(int FHszApp, int FHszTopic);
	Classes::TPersistent* __fastcall GetCliItemByName(const AnsiString ItemName);
	Classes::TPersistent* __fastcall GetCliItemByCtrl(TDdeClientItem* ACtrl);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	void __fastcall ReadLinkInfo(Classes::TReader* Reader);
	void __fastcall WriteLinkInfo(Classes::TWriter* Writer);
	bool __fastcall OnSetItem(TDdeClientItem* aCtrl, const AnsiString S);
	void __fastcall OnAttach(TDdeClientItem* aCtrl);
	void __fastcall OnDetach(TDdeClientItem* aCtrl);
	DYNAMIC void __fastcall Close(void);
	DYNAMIC void __fastcall Open(void);
	bool __fastcall ChangeLink(const AnsiString App, const AnsiString Topic, const AnsiString Item);
	void __fastcall ClearItems(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TDdeClientConv(Classes::TComponent* AOwner);
	__fastcall virtual ~TDdeClientConv(void);
	bool __fastcall PasteLink(void);
	bool __fastcall OpenLink(void);
	bool __fastcall SetLink(const AnsiString Service, const AnsiString Topic);
	void __fastcall CloseLink(void);
	bool __fastcall StartAdvise(void);
	bool __fastcall PokeDataLines(const AnsiString Item, Classes::TStrings* Data);
	bool __fastcall PokeData(const AnsiString Item, char * Data);
	bool __fastcall ExecuteMacroLines(Classes::TStrings* Cmd, bool waitFlg);
	bool __fastcall ExecuteMacro(char * Cmd, bool waitFlg);
	char * __fastcall RequestData(const AnsiString Item);
	__property int DdeFmt = {read=FDdeFmt, nodefault};
	__property bool WaitStat = {read=FWaitStat, nodefault};
	__property int Conv = {read=FConv, nodefault};
	__property TDataMode DataMode = {read=FDataMode, write=FDataMode, nodefault};
	
__published:
	__property AnsiString ServiceApplication = {read=FAppName, write=FAppName};
	__property AnsiString DdeService = {read=FDdeService, write=SetDdeService};
	__property AnsiString DdeTopic = {read=FDdeTopic, write=SetDdeTopic};
	__property TDataMode ConnectMode = {read=FConnectMode, write=SetConnectMode, default=0};
	__property bool FormatChars = {read=FFormatChars, write=SetFormatChars, default=0};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property Classes::TNotifyEvent OnOpen = {read=FOnOpen, write=FOnOpen};
};


class PASCALIMPLEMENTATION TDdeClientItem : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TStrings* FLines;
	TDdeClientConv* FDdeClientConv;
	AnsiString FDdeClientItem;
	Classes::TNotifyEvent FOnChange;
	AnsiString __fastcall GetText();
	void __fastcall SetDdeClientItem(const AnsiString Val);
	void __fastcall SetDdeClientConv(TDdeClientConv* Val);
	void __fastcall SetText(const AnsiString S);
	void __fastcall SetLines(Classes::TStrings* L);
	void __fastcall OnAdvise(void);
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TDdeClientItem(Classes::TComponent* AOwner);
	__fastcall virtual ~TDdeClientItem(void);
	
__published:
	__property AnsiString Text = {read=GetText, write=SetText};
	__property Classes::TStrings* Lines = {read=FLines, write=SetLines};
	__property TDdeClientConv* DdeConv = {read=FDdeClientConv, write=SetDdeClientConv};
	__property AnsiString DdeItem = {read=FDdeClientItem, write=SetDdeClientItem};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


class DELPHICLASS TDdeServerConv;
class PASCALIMPLEMENTATION TDdeServerConv : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TNotifyEvent FOnOpen;
	Classes::TNotifyEvent FOnClose;
	TMacroEvent FOnExecuteMacro;
	
protected:
	DYNAMIC void __fastcall Connect(void);
	DYNAMIC void __fastcall Disconnect(void);
	
public:
	__fastcall virtual TDdeServerConv(Classes::TComponent* AOwner);
	__fastcall virtual ~TDdeServerConv(void);
	int __fastcall ExecuteMacro(int Data);
	
__published:
	__property Classes::TNotifyEvent OnOpen = {read=FOnOpen, write=FOnOpen};
	__property Classes::TNotifyEvent OnClose = {read=FOnClose, write=FOnClose};
	__property TMacroEvent OnExecuteMacro = {read=FOnExecuteMacro, write=FOnExecuteMacro};
};


class DELPHICLASS TDdeServerItem;
class PASCALIMPLEMENTATION TDdeServerItem : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TStrings* FLines;
	TDdeServerConv* FServerConv;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnPokeData;
	int FFmt;
	void __fastcall ValueChanged(void);
	
protected:
	AnsiString __fastcall GetText();
	void __fastcall SetText(const AnsiString Item);
	void __fastcall SetLines(Classes::TStrings* Value);
	void __fastcall SetServerConv(TDdeServerConv* SConv);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	__fastcall virtual TDdeServerItem(Classes::TComponent* AOwner);
	__fastcall virtual ~TDdeServerItem(void);
	int __fastcall PokeData(int Data);
	void __fastcall CopyToClipboard(void);
	DYNAMIC void __fastcall Change(void);
	__property int Fmt = {read=FFmt, nodefault};
	
__published:
	__property TDdeServerConv* ServerConv = {read=FServerConv, write=SetServerConv};
	__property AnsiString Text = {read=GetText, write=SetText};
	__property Classes::TStrings* Lines = {read=FLines, write=SetLines};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnPokeData = {read=FOnPokeData, write=FOnPokeData};
};


class DELPHICLASS TDdeMgr;
class PASCALIMPLEMENTATION TDdeMgr : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	AnsiString FAppName;
	int FHszApp;
	Classes::TList* FConvs;
	Classes::TList* FCliConvs;
	Classes::TList* FConvCtrls;
	int FDdeInstId;
	Word FLinkClipFmt;
	void __fastcall Disconnect(Classes::TComponent* DdeSrvrConv);
	Classes::TComponent* __fastcall GetSrvrConv(const AnsiString Topic);
	bool __fastcall AllowConnect(int hszApp, int hszTopic);
	int __fastcall AllowWildConnect(int hszApp, int hszTopic);
	bool __fastcall Connect(int Conv, int hszTopic, bool SameInst);
	void __fastcall PostDataChange(const AnsiString Topic, AnsiString Item);
	void __fastcall SetAppName(const AnsiString Name);
	void __fastcall ResetAppName(void);
	TDdeServerConv* __fastcall GetServerConv(const AnsiString Topic);
	void __fastcall InsertServerConv(TDdeServerConv* SConv);
	void __fastcall RemoveServerConv(TDdeServerConv* SConv);
	Forms::TForm* __fastcall GetForm(const AnsiString Topic);
	
public:
	__fastcall virtual TDdeMgr(Classes::TComponent* AOwner);
	__fastcall virtual ~TDdeMgr(void);
	AnsiString __fastcall GetExeName();
	__property int DdeInstId = {read=FDdeInstId, write=FDdeInstId, nodefault};
	__property AnsiString AppName = {read=FAppName, write=SetAppName};
	__property Word LinkClipFmt = {read=FLinkClipFmt, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TDdeMgr* ddeMgr;
extern PACKAGE bool __fastcall GetPasteLinkInfo(AnsiString &Service, AnsiString &Topic, AnsiString &
	Item);

}	/* namespace Ddeman */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Ddeman;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DdeMan
