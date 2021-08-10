// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ToolWin.pas' rev: 6.00

#ifndef ToolWinHPP
#define ToolWinHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Toolwin
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TEdgeBorder { ebLeft, ebTop, ebRight, ebBottom };
#pragma option pop

typedef Set<TEdgeBorder, ebLeft, ebBottom>  TEdgeBorders;

#pragma option push -b-
enum TEdgeStyle { esNone, esRaised, esLowered };
#pragma option pop

class DELPHICLASS TToolWindow;
class PASCALIMPLEMENTATION TToolWindow : public Controls::TWinControl 
{
	typedef Controls::TWinControl inherited;
	
private:
	TEdgeBorders FEdgeBorders;
	TEdgeStyle FEdgeInner;
	TEdgeStyle FEdgeOuter;
	void __fastcall SetEdgeBorders(TEdgeBorders Value);
	void __fastcall SetEdgeInner(TEdgeStyle Value);
	void __fastcall SetEdgeOuter(TEdgeStyle Value);
	
protected:
	virtual void __fastcall NCPaint(HDC DC);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMBorderChanged(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	
public:
	__fastcall virtual TToolWindow(Classes::TComponent* AOwner);
	__property TEdgeBorders EdgeBorders = {read=FEdgeBorders, write=SetEdgeBorders, default=15};
	__property TEdgeStyle EdgeInner = {read=FEdgeInner, write=SetEdgeInner, default=1};
	__property TEdgeStyle EdgeOuter = {read=FEdgeOuter, write=SetEdgeOuter, default=2};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TToolWindow(HWND ParentWindow) : Controls::TWinControl(ParentWindow) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWinControl.Destroy */ inline __fastcall virtual ~TToolWindow(void) { }
	#pragma option pop
	
};


class DELPHICLASS TToolDockObject;
class PASCALIMPLEMENTATION TToolDockObject : public Controls::TDragDockObject 
{
	typedef Controls::TDragDockObject inherited;
	
protected:
	virtual void __fastcall AdjustDockRect(const Types::TRect &ARect);
	virtual void __fastcall DrawDragDockImage(void);
	virtual void __fastcall EraseDragDockImage(void);
	
public:
	__fastcall virtual TToolDockObject(Controls::TControl* AControl);
public:
	#pragma option push -w-inl
	/* TDragDockObject.Destroy */ inline __fastcall virtual ~TToolDockObject(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TSizingOrientation { soNone, soHorizontal, soVertical };
#pragma option pop

class DELPHICLASS TToolDockForm;
class PASCALIMPLEMENTATION TToolDockForm : public Forms::TCustomDockForm 
{
	typedef Forms::TCustomDockForm inherited;
	
private:
	int FPrevWidth;
	int FPrevHeight;
	int FSizingAdjustH;
	int FSizingAdjustW;
	TSizingOrientation FSizingOrientation;
	bool FUpdatingSize;
	
protected:
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoAddDockClient(Controls::TControl* Client, const Types::TRect &ARect);
	HIDESBASE MESSAGE void __fastcall WMNCCreate(Messages::TWMNCCreate &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonDown(Messages::TWMNCHitMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMSysCommand(Messages::TWMSysCommand &Message);
	
public:
	__fastcall virtual TToolDockForm(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TToolDockForm(Classes::TComponent* AOwner, int Dummy) : Forms::TCustomDockForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TToolDockForm(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TToolDockForm(HWND ParentWindow) : Forms::TCustomDockForm(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Toolwin */
using namespace Toolwin;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ToolWin
