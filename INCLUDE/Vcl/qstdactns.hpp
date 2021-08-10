// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QStdActns.pas' rev: 6.00

#ifndef QStdActnsHPP
#define QStdActnsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QClipbrd.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QActnList.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qstdactns
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THintAction;
class PASCALIMPLEMENTATION THintAction : public Qactnlist::TCustomAction 
{
	typedef Qactnlist::TCustomAction inherited;
	
public:
	__fastcall virtual THintAction(Classes::TComponent* AOwner);
	
__published:
	__property Hint ;
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THintAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditAction;
class PASCALIMPLEMENTATION TEditAction : public Qactnlist::TAction 
{
	typedef Qactnlist::TAction inherited;
	
private:
	Qstdctrls::TCustomEdit* FEditControl;
	Qstdctrls::TCustomMemo* FMemoControl;
	void __fastcall SetEditControl(Qstdctrls::TCustomEdit* Value);
	void __fastcall SetMemoControl(Qstdctrls::TCustomMemo* Value);
	
protected:
	virtual Qstdctrls::TCustomEdit* __fastcall GetEditControl(System::TObject* Target);
	virtual Qstdctrls::TCustomMemo* __fastcall GetMemoControl(System::TObject* Target);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	__property Qstdctrls::TCustomEdit* EditControl = {read=FEditControl, write=SetEditControl};
	__property Qstdctrls::TCustomMemo* MemoControl = {read=FMemoControl, write=SetMemoControl};
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TEditAction(Classes::TComponent* AOwner) : Qactnlist::TAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditCut;
class PASCALIMPLEMENTATION TEditCut : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TEditCut(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditCut(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditCopy;
class PASCALIMPLEMENTATION TEditCopy : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TEditCopy(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditCopy(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditPaste;
class PASCALIMPLEMENTATION TEditPaste : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TEditPaste(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditPaste(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditSelectAll;
class PASCALIMPLEMENTATION TEditSelectAll : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TEditSelectAll(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditSelectAll(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditDelete;
class PASCALIMPLEMENTATION TEditDelete : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TEditDelete(Classes::TComponent* AOwner) : TEditAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditDelete(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowAction;
class PASCALIMPLEMENTATION TWindowAction : public Qactnlist::TAction 
{
	typedef Qactnlist::TAction inherited;
	
private:
	Qforms::TForm* FForm;
	void __fastcall SetForm(Qforms::TForm* Value);
	
protected:
	virtual Qforms::TForm* __fastcall GetForm(System::TObject* Target);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	__property Qforms::TForm* Form = {read=FForm, write=SetForm};
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TWindowAction(Classes::TComponent* AOwner) : Qactnlist::TAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowClose;
class PASCALIMPLEMENTATION TWindowClose : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TWindowClose(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowClose(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowCascade;
class PASCALIMPLEMENTATION TWindowCascade : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TWindowCascade(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowCascade(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowTile;
class PASCALIMPLEMENTATION TWindowTile : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TWindowTile(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowTile(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowMinimizeAll;
class PASCALIMPLEMENTATION TWindowMinimizeAll : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TWindowMinimizeAll(Classes::TComponent* AOwner) : TWindowAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowMinimizeAll(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpAction;
class PASCALIMPLEMENTATION THelpAction : public Qactnlist::TAction 
{
	typedef Qactnlist::TAction inherited;
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual THelpAction(Classes::TComponent* AOwner) : Qactnlist::TAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpContents;
class PASCALIMPLEMENTATION THelpContents : public THelpAction 
{
	typedef THelpAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual THelpContents(Classes::TComponent* AOwner) : THelpAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpContents(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpTopicSearch;
class PASCALIMPLEMENTATION THelpTopicSearch : public THelpAction 
{
	typedef THelpAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual THelpTopicSearch(Classes::TComponent* AOwner) : THelpAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpTopicSearch(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qstdactns */
using namespace Qstdactns;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QStdActns
