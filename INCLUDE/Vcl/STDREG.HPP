// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'StdReg.pas' rev: 5.00

#ifndef StdRegHPP
#define StdRegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <CustomModuleEditors.hpp>	// Pascal unit
#include <ParentageSupport.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <DsgnIntf.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Stdreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TPersistentImageIndexPropertyEditor;
class PASCALIMPLEMENTATION TPersistentImageIndexPropertyEditor : public Dsgnintf::TIntegerProperty 
{
	typedef Dsgnintf::TIntegerProperty inherited;
	
protected:
	AnsiString FParentImageListPropName;
	__fastcall virtual TPersistentImageIndexPropertyEditor(const Dsgnintf::_di_IFormDesigner ADesigner, 
		int APropCount);
	virtual Imglist::TCustomImageList* __fastcall GetImageListAt(int Index);
	Imglist::TCustomImageList* __fastcall GetImageList(void);
	
public:
	virtual Dsgnintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(Classes::TGetStrProc Proc);
	DYNAMIC void __fastcall ListMeasureWidth(const AnsiString Value, Graphics::TCanvas* ACanvas, int &AWidth
		);
	DYNAMIC void __fastcall ListMeasureHeight(const AnsiString Value, Graphics::TCanvas* ACanvas, int &
		AHeight);
	DYNAMIC void __fastcall ListDrawValue(const AnsiString Value, Graphics::TCanvas* ACanvas, const Windows::TRect 
		&ARect, bool ASelected);
	__property Imglist::TCustomImageList* ImageList = {read=GetImageList};
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TPersistentImageIndexPropertyEditor(void) { }
		
	#pragma option pop
	
};


class DELPHICLASS TComponentImageIndexPropertyEditor;
class PASCALIMPLEMENTATION TComponentImageIndexPropertyEditor : public TPersistentImageIndexPropertyEditor 
	
{
	typedef TPersistentImageIndexPropertyEditor inherited;
	
protected:
	virtual Imglist::TCustomImageList* __fastcall GetImageListAt(int Index);
protected:
	#pragma option push -w-inl
	/* TPersistentImageIndexPropertyEditor.Create */ inline __fastcall virtual TComponentImageIndexPropertyEditor
		(const Dsgnintf::_di_IFormDesigner ADesigner, int APropCount) : TPersistentImageIndexPropertyEditor(
		ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TComponentImageIndexPropertyEditor(void) { }
		
	#pragma option pop
	
};


class DELPHICLASS TMenuItemImageIndexPropertyEditor;
class PASCALIMPLEMENTATION TMenuItemImageIndexPropertyEditor : public TComponentImageIndexPropertyEditor 
	
{
	typedef TComponentImageIndexPropertyEditor inherited;
	
protected:
	virtual Imglist::TCustomImageList* __fastcall GetImageListAt(int Index);
protected:
	#pragma option push -w-inl
	/* TPersistentImageIndexPropertyEditor.Create */ inline __fastcall virtual TMenuItemImageIndexPropertyEditor
		(const Dsgnintf::_di_IFormDesigner ADesigner, int APropCount) : TComponentImageIndexPropertyEditor(
		ADesigner, APropCount) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TMenuItemImageIndexPropertyEditor(void) { }
		
	#pragma option pop
	
};


class DELPHICLASS TListViewColumnImageIndexPropertyEditor;
class PASCALIMPLEMENTATION TListViewColumnImageIndexPropertyEditor : public TPersistentImageIndexPropertyEditor 
	
{
	typedef TPersistentImageIndexPropertyEditor inherited;
	
protected:
	__fastcall virtual TListViewColumnImageIndexPropertyEditor(const Dsgnintf::_di_IFormDesigner ADesigner
		, int APropCount);
public:
	#pragma option push -w-inl
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TListViewColumnImageIndexPropertyEditor(void
		) { }
	#pragma option pop
	
};


class DELPHICLASS TMenuItemSprig;
class PASCALIMPLEMENTATION TMenuItemSprig : public Parentagesupport::TSprig 
{
	typedef Parentagesupport::TSprig inherited;
	
public:
	virtual bool __fastcall SortByIndex(void);
	virtual int __fastcall ItemIndex(void);
public:
	#pragma option push -w-inl
	/* TSprig.Create */ inline __fastcall virtual TMenuItemSprig(Classes::TPersistent* AItem) : Parentagesupport::TSprig(
		AItem) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TSprig.Destroy */ inline __fastcall virtual ~TMenuItemSprig(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);

}	/* namespace Stdreg */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Stdreg;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// StdReg
