// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ActnList.pas' rev: 6.00

#ifndef ActnListHPP
#define ActnListHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Contnrs.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Actnlist
{
//-- type declarations -------------------------------------------------------
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
	Imglist::TChangeLink* FImageChangeLink;
	Imglist::TCustomImageList* FImages;
	Classes::TNotifyEvent FOnChange;
	TActionEvent FOnExecute;
	TActionEvent FOnUpdate;
	TActionListState FState;
	TContainedAction* __fastcall GetAction(int Index);
	int __fastcall GetActionCount(void);
	void __fastcall ImageListChange(System::TObject* Sender);
	void __fastcall SetAction(int Index, TContainedAction* Value);
	void __fastcall SetState(const TActionListState Value);
	
protected:
	void __fastcall AddAction(TContainedAction* Action);
	void __fastcall RemoveAction(TContainedAction* Action);
	virtual void __fastcall Change(void);
	DYNAMIC void __fastcall GetChildren(Classes::TGetChildProc Proc, Classes::TComponent* Root);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	DYNAMIC void __fastcall SetChildOrder(Classes::TComponent* Component, int Order);
	virtual void __fastcall SetImages(Imglist::TCustomImageList* Value);
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TActionEvent OnExecute = {read=FOnExecute, write=FOnExecute};
	__property TActionEvent OnUpdate = {read=FOnUpdate, write=FOnUpdate};
	
public:
	__fastcall virtual TCustomActionList(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomActionList(void);
	DYNAMIC bool __fastcall ExecuteAction(Classes::TBasicAction* Action);
	bool __fastcall IsShortCut(Messages::TWMKey &Message);
	DYNAMIC bool __fastcall UpdateAction(Classes::TBasicAction* Action);
	__property TContainedAction* Actions[int Index] = {read=GetAction, write=SetAction/*, default*/};
	__property int ActionCount = {read=GetActionCount, nodefault};
	__property Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TActionListState State = {read=FState, write=SetState, default=0};
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
	__property State  = {default=0};
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


class DELPHICLASS TShortCutList;
class PASCALIMPLEMENTATION TShortCutList : public Classes::TStringList 
{
	typedef Classes::TStringList inherited;
	
private:
	Classes::TShortCut __fastcall GetShortCuts(int Index);
	
public:
	virtual int __fastcall Add(const AnsiString S);
	int __fastcall IndexOfShortCut(const Classes::TShortCut Shortcut);
	__property Classes::TShortCut ShortCuts[int Index] = {read=GetShortCuts};
public:
	#pragma option push -w-inl
	/* TStringList.Destroy */ inline __fastcall virtual ~TShortCutList(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TShortCutList(void) : Classes::TStringList() { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *THintEvent)(AnsiString &HintStr, bool &CanShow);

class DELPHICLASS TCustomAction;
class PASCALIMPLEMENTATION TCustomAction : public TContainedAction 
{
	typedef TContainedAction inherited;
	
private:
	bool FDisableIfNoHandler;
	AnsiString FCaption;
	bool FChecking;
	bool FChecked;
	bool FEnabled;
	int FGroupIndex;
	Classes::THelpType FHelpType;
	Classes::THelpContext FHelpContext;
	AnsiString FHelpKeyword;
	AnsiString FHint;
	Imglist::TImageIndex FImageIndex;
	Classes::TShortCut FShortCut;
	bool FVisible;
	THintEvent FOnHint;
	TShortCutList* FSecondaryShortCuts;
	bool FSavedEnabledState;
	bool FAutoCheck;
	void __fastcall SetAutoCheck(bool Value);
	void __fastcall SetCaption(const AnsiString Value);
	void __fastcall SetChecked(bool Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetGroupIndex(const int Value);
	virtual void __fastcall SetHelpContext(Classes::THelpContext Value);
	virtual void __fastcall SetHelpKeyword(const AnsiString Value);
	void __fastcall SetHelpType(Classes::THelpType Value);
	void __fastcall SetHint(const AnsiString Value);
	void __fastcall SetImageIndex(Imglist::TImageIndex Value);
	void __fastcall SetShortCut(Classes::TShortCut Value);
	void __fastcall SetVisible(bool Value);
	TShortCutList* __fastcall GetSecondaryShortCuts(void);
	void __fastcall SetSecondaryShortCuts(const TShortCutList* Value);
	bool __fastcall IsSecondaryShortCutsStored(void);
	
protected:
	System::TObject* FImage;
	System::TObject* FMask;
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall SetName(const AnsiString Value);
	virtual bool __fastcall HandleShortCut(void);
	__property bool SavedEnabledState = {read=FSavedEnabledState, write=FSavedEnabledState, nodefault};
	
public:
	__fastcall virtual TCustomAction(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomAction(void);
	DYNAMIC bool __fastcall DoHint(AnsiString &HintStr);
	DYNAMIC bool __fastcall Execute(void);
	__property bool AutoCheck = {read=FAutoCheck, write=SetAutoCheck, default=0};
	__property AnsiString Caption = {read=FCaption, write=SetCaption};
	__property bool Checked = {read=FChecked, write=SetChecked, default=0};
	__property bool DisableIfNoHandler = {read=FDisableIfNoHandler, write=FDisableIfNoHandler, default=0};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property int GroupIndex = {read=FGroupIndex, write=SetGroupIndex, default=0};
	__property Classes::THelpContext HelpContext = {read=FHelpContext, write=SetHelpContext, default=0};
	__property AnsiString HelpKeyword = {read=FHelpKeyword, write=SetHelpKeyword};
	__property Classes::THelpType HelpType = {read=FHelpType, write=SetHelpType, default=0};
	__property AnsiString Hint = {read=FHint, write=SetHint};
	__property Imglist::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property Classes::TShortCut ShortCut = {read=FShortCut, write=SetShortCut, default=0};
	__property TShortCutList* SecondaryShortCuts = {read=GetSecondaryShortCuts, write=SetSecondaryShortCuts, stored=IsSecondaryShortCutsStored};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property THintEvent OnHint = {read=FOnHint, write=FOnHint};
};


class DELPHICLASS TAction;
class PASCALIMPLEMENTATION TAction : public TCustomAction 
{
	typedef TCustomAction inherited;
	
public:
	__fastcall virtual TAction(Classes::TComponent* AOwner);
	
__published:
	__property AutoCheck  = {default=0};
	__property Caption ;
	__property Checked  = {default=0};
	__property Enabled  = {default=1};
	__property GroupIndex  = {default=0};
	__property HelpContext  = {default=0};
	__property HelpKeyword ;
	__property HelpType  = {default=0};
	__property Hint ;
	__property ImageIndex  = {default=-1};
	__property ShortCut  = {default=0};
	__property SecondaryShortCuts ;
	__property Visible  = {default=1};
	__property OnExecute ;
	__property OnHint ;
	__property OnUpdate ;
public:
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
	virtual bool __fastcall IsGroupIndexLinked(void);
	virtual bool __fastcall IsHelpContextLinked(void);
	virtual bool __fastcall IsHelpLinked(void);
	virtual bool __fastcall IsHintLinked(void);
	virtual bool __fastcall IsImageIndexLinked(void);
	virtual bool __fastcall IsShortCutLinked(void);
	virtual bool __fastcall IsVisibleLinked(void);
	virtual void __fastcall SetAutoCheck(bool Value);
	virtual void __fastcall SetCaption(const AnsiString Value);
	virtual void __fastcall SetChecked(bool Value);
	virtual void __fastcall SetEnabled(bool Value);
	virtual void __fastcall SetGroupIndex(int Value);
	virtual void __fastcall SetHelpContext(Classes::THelpContext Value);
	virtual void __fastcall SetHelpKeyword(const AnsiString Value);
	virtual void __fastcall SetHelpType(Classes::THelpType Value);
	virtual void __fastcall SetHint(const AnsiString Value);
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
extern PACKAGE void __fastcall (*RegisterActionsProc)(const AnsiString CategoryName, TMetaClass* * AClasses, const int AClasses_Size, TMetaClass* Resource);
extern PACKAGE void __fastcall (*UnRegisterActionsProc)(TMetaClass* * AClasses, const int AClasses_Size);
extern PACKAGE void __fastcall (*EnumRegisteredActionsProc)(TEnumActionProc Proc, void * Info);
extern PACKAGE Classes::TBasicAction* __fastcall (*CreateActionProc)(Classes::TComponent* AOwner, TMetaClass* ActionClass);
extern PACKAGE void __fastcall RegisterActions(const AnsiString CategoryName, TMetaClass* * AClasses, const int AClasses_Size, TMetaClass* Resource);
extern PACKAGE void __fastcall UnRegisterActions(TMetaClass* * AClasses, const int AClasses_Size);
extern PACKAGE void __fastcall EnumRegisteredActions(TEnumActionProc Proc, void * Info);
extern PACKAGE Classes::TBasicAction* __fastcall CreateAction(Classes::TComponent* AOwner, TMetaClass* ActionClass);

}	/* namespace Actnlist */
using namespace Actnlist;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ActnList
