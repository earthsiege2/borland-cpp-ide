// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QTypes.pas' rev: 6.00

#ifndef QTypesHPP
#define QTypesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qtypes
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EHandleComponentException;
class PASCALIMPLEMENTATION EHandleComponentException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EHandleComponentException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EHandleComponentException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EHandleComponentException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EHandleComponentException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EHandleComponentException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EHandleComponentException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EHandleComponentException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EHandleComponentException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EHandleComponentException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidParam;
class PASCALIMPLEMENTATION EInvalidParam : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidParam(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidParam(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidParam(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidParam(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidParam(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidParam(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidParam(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidParam(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidParam(void) { }
	#pragma option pop
	
};


typedef WideString TCaption;

class DELPHICLASS THandleComponent;
class PASCALIMPLEMENTATION THandleComponent : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Qt::QObject_hookH* FHooks;
	Qt::QWidgetH* FParentWidget;
	Classes::THelpContext FHelpContext;
	AnsiString FHelpKeyword;
	AnsiString FHelpFile;
	Classes::THelpType FHelpType;
	Qt::QObject_hookH* __fastcall GetHooks(void);
	void __cdecl DestroyedHook(void);
	Qt::QObjectH* __fastcall GetHandle(void);
	Qt::QWidgetH* __fastcall GetParentWidget(void);
	void __fastcall SetParentWidget(const Qt::QWidgetH* Value);
	bool __fastcall IsHelpContextStored(void);
	
protected:
	Qt::QObjectH* FHandle;
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateWidget(void) = 0 ;
	virtual void __fastcall DestroyWidget(void);
	virtual bool __cdecl EventFilter(Qt::QObjectH* Sender, Qt::QEventH* Event);
	virtual void __fastcall HookEvents(void);
	virtual void __fastcall InitWidget(void);
	virtual void __fastcall InvokeHelp(void);
	void __fastcall SetHelpContext(const Classes::THelpContext Value);
	void __fastcall SetHelpKeyword(const AnsiString Value);
	virtual void __fastcall WidgetDestroyed(void);
	__property AnsiString HelpFile = {read=FHelpFile, write=FHelpFile};
	__property Classes::THelpType HelpType = {read=FHelpType, write=FHelpType, default=0};
	__property AnsiString HelpKeyword = {read=FHelpKeyword, write=SetHelpKeyword};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=SetHelpContext, stored=IsHelpContextStored, default=0};
	
public:
	__fastcall virtual ~THandleComponent(void);
	void __fastcall HandleNeeded(void);
	bool __fastcall HandleAllocated(void);
	__property Qt::QObjectH* Handle = {read=GetHandle};
	__property Qt::QObject_hookH* Hooks = {read=GetHooks, write=FHooks};
	__property Qt::QWidgetH* ParentWidget = {read=GetParentWidget, write=SetParentWidget};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual THandleComponent(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	
};


class DELPHICLASS TMimeSource;
class PASCALIMPLEMENTATION TMimeSource : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	bool FOwnHandle;
	Qt::QMimeSourceH* __fastcall GetHandle(void);
	void __fastcall SetHandle(const Qt::QMimeSourceH* Value);
	void __fastcall HandleNeeded(void);
	
protected:
	Qt::QMimeSourceH* FHandle;
	virtual void __fastcall CreateHandle(void);
	bool __fastcall HandleAllocated(void);
	
public:
	__fastcall TMimeSource(Qt::QMimeSourceH* AHandle);
	__fastcall virtual ~TMimeSource(void);
	bool __fastcall SaveToStream(const AnsiString Format, Classes::TStream* Stream);
	void __fastcall SupportedFormats(Classes::TStrings* List);
	bool __fastcall Provides(const AnsiString Format);
	void __fastcall OwnHandle(void);
	void __fastcall ReleaseHandle(void);
	__property Qt::QMimeSourceH* Handle = {read=GetHandle, write=SetHandle};
};


class DELPHICLASS TClxMimeSource;
class PASCALIMPLEMENTATION TClxMimeSource : public TMimeSource 
{
	typedef TMimeSource inherited;
	
private:
	HIDESBASE Qt::QClxMimeSourceH* __fastcall GetHandle(void);
	HIDESBASE void __fastcall SetHandle(const Qt::QClxMimeSourceH* Value);
	
public:
	__fastcall TClxMimeSource(const AnsiString Format, Classes::TStream* Data)/* overload */;
	__fastcall TClxMimeSource(Qt::QClxMimeSourceH* MimeSourceH)/* overload */;
	void __fastcall LoadFromStream(Classes::TStream* Stream, const AnsiString Format);
	__property Qt::QClxMimeSourceH* Handle = {read=GetHandle, write=SetHandle};
public:
	#pragma option push -w-inl
	/* TMimeSource.Destroy */ inline __fastcall virtual ~TClxMimeSource(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall CopyQStringListToTStrings(Qt::QStringListH* Handle, Classes::TStrings* Strings);
extern PACKAGE Classes::TStringList* __fastcall QStringListToTStringList(Qt::QStringListH* Handle);
extern PACKAGE Qt::QStringListH* __fastcall TStringsToQStringList(Classes::TStrings* Strings);
extern PACKAGE Qt::QIODeviceH* __fastcall IODeviceFromStream(Classes::TStream* Stream, bool Owned = false);

}	/* namespace Qtypes */
using namespace Qtypes;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QTypes
