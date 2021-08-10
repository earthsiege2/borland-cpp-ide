// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StdActns.pas' rev: 5.00

#ifndef StdActnsHPP
#define StdActnsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stdactns
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS THintAction;
class PASCALIMPLEMENTATION THintAction : public Actnlist::TCustomAction 
{
	typedef Actnlist::TCustomAction inherited;
	
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
class PASCALIMPLEMENTATION TEditAction : public Actnlist::TAction 
{
	typedef Actnlist::TAction inherited;
	
private:
	Stdctrls::TCustomEdit* FControl;
	void __fastcall SetControl(Stdctrls::TCustomEdit* Value);
	
protected:
	virtual Stdctrls::TCustomEdit* __fastcall GetControl(System::TObject* Target);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	__property Stdctrls::TCustomEdit* Control = {read=FControl, write=SetControl};
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TEditAction(Classes::TComponent* AOwner) : Actnlist::TAction(
		AOwner) { }
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
	/* TCustomAction.Create */ inline __fastcall virtual TEditCut(Classes::TComponent* AOwner) : TEditAction(
		AOwner) { }
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
	/* TCustomAction.Create */ inline __fastcall virtual TEditCopy(Classes::TComponent* AOwner) : TEditAction(
		AOwner) { }
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
	/* TCustomAction.Create */ inline __fastcall virtual TEditPaste(Classes::TComponent* AOwner) : TEditAction(
		AOwner) { }
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
	/* TCustomAction.Create */ inline __fastcall virtual TEditSelectAll(Classes::TComponent* AOwner) : 
		TEditAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditSelectAll(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditUndo;
class PASCALIMPLEMENTATION TEditUndo : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TEditUndo(Classes::TComponent* AOwner) : TEditAction(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditUndo(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditDelete;
class PASCALIMPLEMENTATION TEditDelete : public TEditAction 
{
	typedef TEditAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TEditDelete(Classes::TComponent* AOwner) : TEditAction(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TEditDelete(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowAction;
class PASCALIMPLEMENTATION TWindowAction : public Actnlist::TAction 
{
	typedef Actnlist::TAction inherited;
	
private:
	Forms::TForm* FForm;
	void __fastcall SetForm(Forms::TForm* Value);
	
protected:
	virtual Forms::TForm* __fastcall GetForm(System::TObject* Target);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation
		);
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	__property Forms::TForm* Form = {read=FForm, write=SetForm};
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TWindowAction(Classes::TComponent* AOwner) : Actnlist::TAction(
		AOwner) { }
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
	/* TCustomAction.Create */ inline __fastcall virtual TWindowClose(Classes::TComponent* AOwner) : TWindowAction(
		AOwner) { }
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
	/* TCustomAction.Create */ inline __fastcall virtual TWindowCascade(Classes::TComponent* AOwner) : 
		TWindowAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowCascade(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowTileHorizontal;
class PASCALIMPLEMENTATION TWindowTileHorizontal : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TWindowTileHorizontal(Classes::TComponent* AOwner
		) : TWindowAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowTileHorizontal(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowTileVertical;
class PASCALIMPLEMENTATION TWindowTileVertical : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TWindowTileVertical(Classes::TComponent* AOwner
		) : TWindowAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowTileVertical(void) { }
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
	/* TCustomAction.Create */ inline __fastcall virtual TWindowMinimizeAll(Classes::TComponent* AOwner
		) : TWindowAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowMinimizeAll(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWindowArrange;
class PASCALIMPLEMENTATION TWindowArrange : public TWindowAction 
{
	typedef TWindowAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual TWindowArrange(Classes::TComponent* AOwner) : 
		TWindowAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TWindowArrange(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpAction;
class PASCALIMPLEMENTATION THelpAction : public Actnlist::TAction 
{
	typedef Actnlist::TAction inherited;
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual THelpAction(Classes::TComponent* AOwner) : Actnlist::TAction(
		AOwner) { }
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
	/* TCustomAction.Create */ inline __fastcall virtual THelpContents(Classes::TComponent* AOwner) : THelpAction(
		AOwner) { }
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
	/* TCustomAction.Create */ inline __fastcall virtual THelpTopicSearch(Classes::TComponent* AOwner) : 
		THelpAction(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpTopicSearch(void) { }
	#pragma option pop
	
};


class DELPHICLASS THelpOnHelp;
class PASCALIMPLEMENTATION THelpOnHelp : public THelpAction 
{
	typedef THelpAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
public:
	#pragma option push -w-inl
	/* TCustomAction.Create */ inline __fastcall virtual THelpOnHelp(Classes::TComponent* AOwner) : THelpAction(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~THelpOnHelp(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Stdactns */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Stdactns;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StdActns
