// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DirOutln.pas' rev: 6.00

#ifndef DirOutlnHPP
#define DirOutlnHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Outline.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Diroutln
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TTextCase { tcLowerCase, tcUpperCase, tcAsIs };
#pragma option pop

typedef AnsiString __fastcall (*TCaseFunction)(const AnsiString AString);

class DELPHICLASS TDirectoryOutline;
class PASCALIMPLEMENTATION TDirectoryOutline : public Outline::TCustomOutline 
{
	typedef Outline::TCustomOutline inherited;
	
private:
	char FDrive;
	AnsiString FDirectory;
	Classes::TNotifyEvent FOnChange;
	TTextCase FTextCase;
	TCaseFunction FCaseFunction;
	
protected:
	void __fastcall SetDrive(char NewDrive);
	void __fastcall SetDirectory(const AnsiString NewDirectory);
	void __fastcall SetTextCase(TTextCase NewTextCase);
	void __fastcall AssignCaseProc(void);
	virtual void __fastcall BuildOneLevel(int RootItem);
	virtual void __fastcall BuildTree(void);
	virtual void __fastcall BuildSubTree(int RootItem);
	virtual void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall Expand(int Index);
	int __fastcall FindIndex(Outline::TOutlineNode* RootNode, AnsiString SearchName);
	virtual void __fastcall Loaded(void);
	void __fastcall WalkTree(const AnsiString Dest);
	
public:
	__fastcall virtual TDirectoryOutline(Classes::TComponent* AOwner);
	AnsiString __fastcall ForceCase(const AnsiString AString);
	__property char Drive = {read=FDrive, write=SetDrive, nodefault};
	__property AnsiString Directory = {read=FDirectory, write=SetDirectory};
	__property Lines  = {stored=false};
	
__published:
	__property Align  = {default=0};
	__property Anchors  = {default=3};
	__property BorderStyle  = {default=1};
	__property Color  = {default=-2147483643};
	__property Constraints ;
	__property Ctl3D ;
	__property DragCursor  = {default=-12};
	__property DragKind  = {default=0};
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property ItemHeight ;
	__property Options  = {default=6};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PictureClosed ;
	__property PictureLeaf ;
	__property PictureOpen ;
	__property PopupMenu ;
	__property ScrollBars  = {default=3};
	__property Style  = {default=0};
	__property ShowHint ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property TTextCase TextCase = {read=FTextCase, write=SetTextCase, default=0};
	__property Visible  = {default=1};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnClick ;
	__property OnCollapse ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnDrawItem ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnExpand ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDock ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomOutline.Destroy */ inline __fastcall virtual ~TDirectoryOutline(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDirectoryOutline(HWND ParentWindow) : Outline::TCustomOutline(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall SameLetter(char Letter1, char Letter2);

}	/* namespace Diroutln */
using namespace Diroutln;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DirOutln
