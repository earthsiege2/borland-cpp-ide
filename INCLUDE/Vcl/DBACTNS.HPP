// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBActns.pas' rev: 6.00

#ifndef DBActnsHPP
#define DBActnsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActnList.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbactns
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDataSetAction;
class PASCALIMPLEMENTATION TDataSetAction : public Actnlist::TAction 
{
	typedef Actnlist::TAction inherited;
	
private:
	Db::TDataSource* FDataSource;
	void __fastcall SetDataSource(Db::TDataSource* Value);
	
protected:
	virtual Db::TDataSet* __fastcall GetDataSet(System::TObject* Target);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual bool __fastcall HandlesTarget(System::TObject* Target);
	__property Db::TDataSource* DataSource = {read=FDataSource, write=SetDataSource};
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetAction(Classes::TComponent* AOwner) : Actnlist::TAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetAction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetFirst;
class PASCALIMPLEMENTATION TDataSetFirst : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetFirst(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetFirst(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetPrior;
class PASCALIMPLEMENTATION TDataSetPrior : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetPrior(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetPrior(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetNext;
class PASCALIMPLEMENTATION TDataSetNext : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetNext(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetNext(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetLast;
class PASCALIMPLEMENTATION TDataSetLast : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetLast(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetLast(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetInsert;
class PASCALIMPLEMENTATION TDataSetInsert : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetInsert(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetInsert(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetDelete;
class PASCALIMPLEMENTATION TDataSetDelete : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetDelete(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetDelete(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetEdit;
class PASCALIMPLEMENTATION TDataSetEdit : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetEdit(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetPost;
class PASCALIMPLEMENTATION TDataSetPost : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetPost(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetPost(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetCancel;
class PASCALIMPLEMENTATION TDataSetCancel : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetCancel(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetCancel(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataSetRefresh;
class PASCALIMPLEMENTATION TDataSetRefresh : public TDataSetAction 
{
	typedef TDataSetAction inherited;
	
public:
	virtual void __fastcall ExecuteTarget(System::TObject* Target);
	virtual void __fastcall UpdateTarget(System::TObject* Target);
	
__published:
	__property DataSource ;
public:
	#pragma option push -w-inl
	/* TAction.Create */ inline __fastcall virtual TDataSetRefresh(Classes::TComponent* AOwner) : TDataSetAction(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCustomAction.Destroy */ inline __fastcall virtual ~TDataSetRefresh(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dbactns */
using namespace Dbactns;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBActns
