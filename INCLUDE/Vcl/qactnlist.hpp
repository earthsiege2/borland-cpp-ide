// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QActnList.pas' rev: 6.00

#ifndef QActnListHPP
#define QActnListHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QImgList.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qactnlist
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ERegisterActionsException;
class PASCALIMPLEMENTATION ERegisterActionsException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ERegisterActionsException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ERegisterActionsException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ERegisterActionsException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ERegisterActionsException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ERegisterActionsException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ERegisterActionsException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ERegisterActionsException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ERegisterActionsException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ERegisterActionsException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TContainedAction;
class DELPHICLASS TCustomActionList;
typedef void __fastcall (__closure *TActionEvent)(Classes::TBasicAction* Action, bool &Handled);

#pragma option push -b-
enum TActionListState { asNormal, asSuspended, asSuspendedEnabled };
#pragma option pop

class PASCALIMPLEMENTATION TCustomActionList : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
public:
	TContainedAction* operator[](int Index) { return Actions[Index]; }
	
private:
	Classes::TList* FActions;
	Qimglist::TChangeLink* FImageChangeLink;
	Qimglist::TCustomImageList* FImages;
	Classes::TNotifyEvent FOnChange;
	TActionEvent FOnExecute;
	TActionEvent FOnUpdate;
	TActionListState FState;
	TContainedAction* __fastcall GetAction(int Index);
	int __fastcall GetActionCount(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetAction(int Index, TContainedAction* Value);
	void __fastcall SetImages(Qimglist::TCustomImageList* Value);
	void __fastcall SetState(const TActionListState Value);
	
protected:
	void __fastcall AddAction(TContainedAction* Action);
	void __fastcall RemoveAction(TContainedAction* Action);
	virtual void __fastcall Change(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TActionEvent OnExecute = {read=FOnExecute, write=FOnExecute};
	__property TActionEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
	
public:
	__fastcall virtual TCustomActionList(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomActionList(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	bool __fastcall IsShortCut(int Key, Classes::TShiftState Shift, const WideString KeyText);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property TContainedAction* Actions[int Index] = {read=GetAction, write=SetAction/*, default*/};
	__property int ActionCount = {read=GetActionCount, nodefault};
	__property Qimglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TActionListState State = {read=FState, write=SetState, nodefault};
};


class PASCALIMPLEMENTATION TContainedAction : public Classes::TBasicAction 
{
	typedef Classes::TBasicAction inherited;
	
private:
	AnsiString FCategory;
	TCustomActionList* FActionList;
	int __fastcall GetIndex(void);
	bool __fastcall IsCategoryStored(void);
	void __fastcall SetCategory(const AnsiString Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetActionList(TCustomActionList* AActionList);
	
protected:
	virtual void __fastcall ReadState(Classes::TReader* Reader);
	DYNAMIC void __fastcall SetParentComponent(Classes::TComponent* AParent);
	
public:
	__fastcall virtual ~TContainedAction(void);
	DYNAMIC bool __fastcall Execute(void);
	DYNAMIC Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual bool __fastcall Update(void);
	__property TCustomActionList* ActionList = {read=FActionList, write=SetActionList};
	__property int Index = {read=GetIndex, write=SetIndex, stored=false, nodefault};
	
__published:
	__property AnsiString Category = {read=FCategory, write=SetCategory, stored=IsCategoryStored};
public:
	#pragma option push -w-inl
	/* TBasicAction.Create */ inline __fastcall virtual TContainedAction(Classes::TComponent* AOwner) : Classes::TBasicAction(AOwner) { }
	#pragma option pop
	
};


typedef TMetaClass*TContainedActionClass;

class DELPHICLASS TActionList;
class PASCALIMPLEMENTATION TActionList : public TCustomActionList 
{
	typedef TCustomActionList inherited;
	
__published:
	__property Images ;
	__property OnChange ;
	__property OnExecute ;
	__property OnUpdate ;
public:
	#pragma option push -w-inl
	/* TCustomActionList.Create */ inline __fastcall virtual TActionList(Classes::TComponent* AOwner) : TCustomActionList(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomActionList.Destroy */ inline __fastcall virtual ~TActionList(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *THintEvent)(WideString &HintStr, bool &CanShow);

class DELPHICLASS TCustomAction;
class PASCALIMPLEMENTATION TCustomAction : public TContainedAction 
{
	typedef TContainedAction inherited;
	
private:
	bool FDisableIfNoHandler;
	WideString FCaption;
	bool FChecked;
	bool FEnabled;
	Classes::THelpType FHelpType;
	Classes::THelpContext FHelpContext;
	AnsiString FHelpKeyword;
	WideString FHint;
	Qimglist::TImageIndex FImageIndex;
	Classes::TShortCut FShortCut;
	bool FVisible;
	THintEvent FOnHint;
	void __fastcall SetCaption(const WideString Value);
	void __fastcall SetChecked(bool Value);
	void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHelpContext(Classes::THelpContext Value);
	virtual void __fastcall SetHelpKeyword(const AnsiString Value);
	void __fastcall SetHelpType(Classes::THelpType Value);
	void __fastcall SetHint(const WideString Value);
	void __fastcall SetImageIndex(Qimglist::TImageIndex Value);
	void __fastcall SetShortCut(Classes::TShortCut Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	System::TObject* FImage;
	System::TObject* FMask;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall SetName(const AnsiString Value);
	
public:
	__fastcall virtual TCustomAction(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAction(void);
	DYNAMIC bool __fastcall DoHint(WideString &HintStr);
	DYNAMIC bool __fastcall Execute(void);
	__property WideString Caption = {read=FCaption, write=SetCaption};
	__property bool Checked = {read=FChecked, write=SetChecked, default=0};
	__property bool DisableIfNoHandler = {read=FDisableIfNoHandler, write=FDisableIfNoHandler, default=1};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=SetHelpContext, default=0};
	__property AnsiString HelpKeyword = {read=FHelpKeyword, write=SetHelpKeyword};
	__property Classes::THelpType HelpType = {read=FHelpType, write=SetHelpType, default=0};
	__property WideString Hint = {read=FHint, write=SetHint};
	__property Qimglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property Classes::TShortCut ShortCut = {read=FShortCut, write=SetShortCut, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property THintEvent OnHint = {read=FOnHint, write=FOnHint};
};


class DELPHICLASS TAction;
class PASCALIMPLEMENTATION TAction : public TCustomAction 
{
	typedef TCustomAction inherited;
	
__published:
	__property Caption ;
	__property Checked  = {default=0};
	__property Enabled  = {default=1};
	__property HelpContext  = {default=0};
	__property HelpKeyword ;
	__property HelpType  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property Visible  = {default=1};
	__property OnExecute ;
	__property OnHint ;
	__property OnUpdate ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TAction(Classes::TComponent* AOwner) : TCustomAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TActionLink;
class PASCALIMPLEMENTATION TActionLink : public Classes::TBasicActionLink 
{
	typedef Classes::TBasicActionLink inherited;
	
protected:
	virtual bool __fastcall IsCaptionLinked(void);
	virtual bool __fastcall IsCheckedLinked(void);
	virtual bool __fastcall IsEnabledLinked(void);
	virtual bool __fastcall IsHelpLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual bool __fastcall IsShortCutLinked(void);
	virtual bool __fastcall IsVisibleLinked(void);
	virtual void __fastcall SetCaption(const WideString Value);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetHelpContext(Classes::THelpContext Value);
	virtual void __fastcall SetHelpKeyword(const AnsiString Value);
	virtual void __fastcall SetHelpType(Classes::THelpType Value);
	virtual void __fastcall SetHint(const WideString Value);
	virtual void __fastcall SetImageIndex(int Value);
	virtual void __fastcall SetShortCut(Classes::TShortCut Value);
	virtual void __fastcall SetVisible(bool Value);
public:
	#pragma option push -w-inl
	/* TBasicActionLink.Create */ inline __fastcall virtual TActionLink(System::TObject* AClient) : Classes::TBasicActionLink(AClient) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TBasicActionLink.Destroy */ inline __fastcall virtual ~TActionLink(void) { }
	#pragma option pop
	
};


typedef TMetaClass*TActionLinkClass;

typedef void __fastcall (__closure *TEnumActionProc)(const AnsiString Category, TMetaClass* ActionClass, void * Info);

//-- var, const, procedure ---------------------------------------------------
#define QEventType_CMActionExecute (Qt::QEventType)(1005)
#define QEventType_CMActionUpdate (Qt::QEventType)(1006)
extern PACKAGE void __fastcall (*RegisterActionsProc)(const AnsiString CategoryName, TMetaClass* * AClasses, const int AClasses_Size, TMetaClass* Resource);
extern PACKAGE void __fastcall (*UnRegisterActionsProc)(TMetaClass* * AClasses, const int AClasses_Size);
extern PACKAGE void __fastcall (*EnumRegisteredActionsProc)(TEnumActionProc Proc, void * Info);
extern PACKAGE Classes::TBasicAction* __fastcall (*CreateActionProc)(Classes::TComponent* AOwner, TMetaClass* ActionClass);
extern PACKAGE void __fastcall RegisterActions(const AnsiString CategoryName, TMetaClass* * AClasses, const int AClasses_Size, TMetaClass* Resource);
extern PACKAGE void __fastcall UnRegisterActions(TMetaClass* * AClasses, const int AClasses_Size);
extern PACKAGE void __fastcall EnumRegisteredActions(TEnumActionProc Proc, void * Info);
extern PACKAGE Classes::TBasicAction* __fastcall CreateAction(Classes::TComponent* AOwner, TMetaClass* ActionClass);

}	/* namespace Qactnlist */
using namespace Qactnlist;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QActnList
