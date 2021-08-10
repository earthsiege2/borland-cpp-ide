// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'VCLSprigs.pas' rev: 6.00

#ifndef VCLSprigsHPP
#define VCLSprigsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <TreeIntf.hpp>	// Pascal unit
#include <Contnrs.hpp>	// Pascal unit
#include <TypInfo.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Vclsprigs
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TControlSprig;
class PASCALIMPLEMENTATION TControlSprig : public Treeintf::TComponentSprig 
{
	typedef Treeintf::TComponentSprig inherited;
	
public:
	__fastcall virtual TControlSprig(Classes::TPersistent* AItem)/* overload */;
	/* virtual class method */ virtual bool __fastcall PaletteOverTo(TMetaClass* vmt, Treeintf::TSprig* AParent, TMetaClass* AClass);
	virtual bool __fastcall DragOverTo(Treeintf::TSprig* AParent);
	virtual bool __fastcall DragDropTo(Treeintf::TSprig* AParent);
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TControlSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWinControlSprig;
class PASCALIMPLEMENTATION TWinControlSprig : public TControlSprig 
{
	typedef TControlSprig inherited;
	
public:
	__fastcall virtual TWinControlSprig(Classes::TPersistent* AItem)/* overload */;
	virtual bool __fastcall DragOver(Treeintf::TSprig* AItem);
	virtual bool __fastcall DragDrop(Treeintf::TSprig* AItem);
	virtual bool __fastcall PaletteOver(TMetaClass* ASprigClass, TMetaClass* AClass);
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TWinControlSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TFrameSprig;
class PASCALIMPLEMENTATION TFrameSprig : public TWinControlSprig 
{
	typedef TWinControlSprig inherited;
	
public:
	__fastcall virtual TFrameSprig(Classes::TPersistent* AItem)/* overload */;
	virtual void __fastcall FigureChildren(void);
public:
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TFrameSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TWinControlRootSprig;
class PASCALIMPLEMENTATION TWinControlRootSprig : public Treeintf::TRootSprig 
{
	typedef Treeintf::TRootSprig inherited;
	
public:
	__fastcall virtual TWinControlRootSprig(Classes::TPersistent* AItem)/* overload */;
	virtual bool __fastcall DragOver(Treeintf::TSprig* AItem);
	virtual bool __fastcall DragDrop(Treeintf::TSprig* AItem);
	virtual bool __fastcall PaletteOver(TMetaClass* ASprigClass, TMetaClass* AClass);
public:
	#pragma option push -w-inl
	/* TRootSprig.Destroy */ inline __fastcall virtual ~TWinControlRootSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TCustomFormRootSprig;
class PASCALIMPLEMENTATION TCustomFormRootSprig : public TWinControlRootSprig 
{
	typedef TWinControlRootSprig inherited;
	
public:
	__fastcall virtual TCustomFormRootSprig(Classes::TPersistent* AItem)/* overload */;
public:
	#pragma option push -w-inl
	/* TRootSprig.Destroy */ inline __fastcall virtual ~TCustomFormRootSprig(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDataModuleRootSprig;
class PASCALIMPLEMENTATION TDataModuleRootSprig : public Treeintf::TRootSprig 
{
	typedef Treeintf::TRootSprig inherited;
	
public:
	__fastcall virtual TDataModuleRootSprig(Classes::TPersistent* AItem)/* overload */;
	virtual bool __fastcall DragOver(Treeintf::TSprig* AItem);
	virtual bool __fastcall PaletteOver(TMetaClass* ASprigClass, TMetaClass* AClass);
	virtual bool __fastcall AcceptsClass(TMetaClass* AClass);
public:
	#pragma option push -w-inl
	/* TRootSprig.Destroy */ inline __fastcall virtual ~TDataModuleRootSprig(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Vclsprigs */
using namespace Vclsprigs;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// VCLSprigs
