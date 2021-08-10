// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Outline.pas' rev: 6.00

#ifndef OutlineHPP
#define OutlineHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Outline
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS OutlineError;
class PASCALIMPLEMENTATION OutlineError : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall OutlineError(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~OutlineError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EOutlineError;
class PASCALIMPLEMENTATION EOutlineError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EOutlineError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EOutlineError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EOutlineError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EOutlineError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EOutlineError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EOutlineError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EOutlineError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EOutlineError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EOutlineError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TOutlineNodeCompare { ocLess, ocSame, ocGreater, ocInvalid };
#pragma option pop

#pragma option push -b-
enum TAttachMode { oaAdd, oaAddChild, oaInsert };
#pragma option pop

typedef Shortint TChangeRange;

class DELPHICLASS TOutlineNode;
class DELPHICLASS TCustomOutline;
#pragma option push -b-
enum TOutlineBitmap { obPlus, obMinus, obOpen, obClose, obLeaf };
#pragma option pop

typedef Set<TOutlineBitmap, obPlus, obLeaf>  TOutlineBitmaps;

typedef Graphics::TBitmap* TBitmapArray[5];

typedef void __fastcall (__closure *EOutlineChange)(System::TObject* Sender, int Index);

#pragma option push -b-
enum TOutlineStyle { osText, osPlusMinusText, osPictureText, osPlusMinusPictureText, osTreeText, osTreePictureText };
#pragma option pop

#pragma option push -b-
enum TOutlineType { otStandard, otOwnerDraw };
#pragma option pop

#pragma option push -b-
enum TOutlineOption { ooDrawTreeRoot, ooDrawFocusRect, ooStretchBitmaps };
#pragma option pop

typedef Set<TOutlineOption, ooDrawTreeRoot, ooStretchBitmaps>  TOutlineOptions;

class PASCALIMPLEMENTATION TCustomOutline : public Grids::TCustomGrid 
{
	typedef Grids::TCustomGrid inherited;
	
public:
	TOutlineNode* operator[](int Index) { return Items[Index]; }
	
private:
	bool FBlockInsert;
	TOutlineNode* FRootNode;
	TOutlineNode* FGoodNode;
	int UpdateCount;
	TOutlineNode* FCurItem;
	AnsiString FSeparator;
	int FFontSize;
	Classes::TStrings* FStrings;
	TOutlineBitmaps FUserBitmaps;
	TOutlineBitmaps FOldBitmaps;
	Graphics::TBitmap* FPictures[5];
	EOutlineChange FOnExpand;
	EOutlineChange FOnCollapse;
	TOutlineStyle FOutlineStyle;
	int FItemHeight;
	TOutlineType FStyle;
	TOutlineOptions FOptions;
	bool FIgnoreScrollResize;
	TOutlineNode* FSelectedItem;
	Stdctrls::TDrawItemEvent FOnDrawItem;
	bool FSettingWidth;
	bool FSettingHeight;
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	int __fastcall GetItemCount(void);
	int __fastcall AttachNode(int Index, AnsiString Str, void * Ptr, TAttachMode AttachMode);
	TOutlineNode* __fastcall Get(int Index);
	int __fastcall GetSelectedItem(void);
	void __fastcall SetSelectedItem(int Value);
	TOutlineNodeCompare __fastcall CompareNodes(TOutlineNode* Value1, TOutlineNode* Value2);
	void __fastcall Error(const AnsiString ErrorString);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	bool __fastcall ResizeGrid(void);
	void __fastcall DoExpand(TOutlineNode* Node);
	void __fastcall Init(void);
	void __fastcall MoveNode(int Destination, int Source, TAttachMode AttachMode);
	void __fastcall ClearBitmap(Graphics::TBitmap* &Bitmap, TOutlineBitmap Kind);
	void __fastcall ChangeBitmap(Graphics::TBitmap* Value, TOutlineBitmap Kind);
	void __fastcall SetRowHeight(void);
	void __fastcall SetCurItem(int Value);
	void __fastcall CreateGlyph(void);
	void __fastcall SetStrings(Classes::TStrings* Value);
	Classes::TStrings* __fastcall GetStrings(void);
	bool __fastcall IsCurItem(int Value);
	void __fastcall SetPicture(int Index, Graphics::TBitmap* Value);
	Graphics::TBitmap* __fastcall GetPicture(int Index);
	void __fastcall DrawPictures(const Graphics::TBitmap* const * BitMaps, const int BitMaps_Size, const Types::TRect &ARect);
	void __fastcall DrawText(TOutlineNode* Node, const Types::TRect &Rect);
	void __fastcall SetOutlineStyle(TOutlineStyle Value);
	void __fastcall DrawTree(const Types::TRect &ARect, TOutlineNode* Node);
	void __fastcall SetItemHeight(int Value);
	void __fastcall SetStyle(TOutlineType Value);
	void __fastcall SetOutlineOptions(TOutlineOptions Value);
	bool __fastcall StoreBitmap(int Index);
	void __fastcall ReadBinaryData(Classes::TStream* Stream);
	void __fastcall WriteBinaryData(Classes::TStream* Stream);
	void __fastcall SetHorzScrollBar(void);
	void __fastcall ResetSelectedItem(void);
	void __fastcall SetRowFromNode(TOutlineNode* Node);
	
protected:
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	TOutlineNode* __fastcall SetGoodIndex(TOutlineNode* Value);
	virtual void __fastcall DrawCell(int ACol, int ARow, const Types::TRect &ARect, Grids::TGridDrawState AState);
	DYNAMIC void __fastcall DblClick(void);
	void __fastcall SetLevel(TOutlineNode* Node, unsigned CurLevel, unsigned NewLevel);
	bool __fastcall BadIndex(TOutlineNode* Value);
	void __fastcall DeleteNode(TOutlineNode* Node, int CurIndex);
	DYNAMIC void __fastcall Expand(int Index);
	DYNAMIC void __fastcall Collapse(int Index);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall Move(int Destination, int Source, TAttachMode AttachMode);
	void __fastcall SetDisplayWidth(int Value);
	__property Classes::TStrings* Lines = {read=GetStrings, write=SetStrings};
	__property TOutlineStyle OutlineStyle = {read=FOutlineStyle, write=SetOutlineStyle, default=5};
	__property EOutlineChange OnExpand = {read=FOnExpand, write=FOnExpand};
	__property EOutlineChange OnCollapse = {read=FOnCollapse, write=FOnCollapse};
	__property TOutlineOptions Options = {read=FOptions, write=SetOutlineOptions, default=3};
	__property TOutlineType Style = {read=FStyle, write=SetStyle, default=0};
	__property int ItemHeight = {read=FItemHeight, write=SetItemHeight, nodefault};
	__property Stdctrls::TDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property AnsiString ItemSeparator = {read=FSeparator, write=FSeparator};
	__property Graphics::TBitmap* PicturePlus = {read=GetPicture, write=SetPicture, stored=StoreBitmap, index=0};
	__property Graphics::TBitmap* PictureMinus = {read=GetPicture, write=SetPicture, stored=StoreBitmap, index=1};
	__property Graphics::TBitmap* PictureOpen = {read=GetPicture, write=SetPicture, stored=StoreBitmap, index=2};
	__property Graphics::TBitmap* PictureClosed = {read=GetPicture, write=SetPicture, stored=StoreBitmap, index=3};
	__property Graphics::TBitmap* PictureLeaf = {read=GetPicture, write=SetPicture, stored=StoreBitmap, index=4};
	
public:
	__fastcall virtual TCustomOutline(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomOutline(void);
	int __fastcall Add(int Index, const AnsiString Text);
	int __fastcall AddChild(int Index, const AnsiString Text);
	int __fastcall AddChildObject(int Index, const AnsiString Text, const void * Data);
	int __fastcall AddObject(int Index, const AnsiString Text, const void * Data);
	HIDESBASE int __fastcall Insert(int Index, const AnsiString Text);
	int __fastcall InsertObject(int Index, const AnsiString Text, const void * Data);
	void __fastcall Delete(int Index);
	int __fastcall GetDataItem(void * Value);
	int __fastcall GetItem(int X, int Y);
	int __fastcall GetNodeDisplayWidth(TOutlineNode* Node);
	int __fastcall GetTextItem(const AnsiString Value);
	TOutlineNode* __fastcall GetVisibleNode(int Index);
	void __fastcall FullExpand(void);
	void __fastcall FullCollapse(void);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall SaveToFile(const AnsiString FileName);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall SetUpdateState(bool Value);
	void __fastcall Clear(void);
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TOutlineNode* Items[int Index] = {read=Get/*, default*/};
	__property int SelectedItem = {read=GetSelectedItem, write=SetSelectedItem, nodefault};
	__property Row ;
	__property Canvas ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TCustomOutline(HWND ParentWindow) : Grids::TCustomGrid(ParentWindow) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TOutlineNode : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
public:
	TOutlineNode* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TList* FList;
	AnsiString FText;
	void *FData;
	TOutlineNode* FParent;
	int FIndex;
	bool FState;
	TCustomOutline* FOutline;
	int FExpandCount;
	void __fastcall ChangeExpandedCount(int Value);
	void __fastcall CloseNode(void);
	void __fastcall Clear(void);
	void __fastcall Error(const AnsiString ErrorString);
	int __fastcall GetExpandedNodeCount(void);
	AnsiString __fastcall GetFullPath();
	int __fastcall GetIndex(void);
	int __fastcall GetLastIndex(void);
	unsigned __fastcall GetLevel(void);
	Classes::TList* __fastcall GetList(void);
	unsigned __fastcall GetMaxDisplayWidth(unsigned Value);
	TOutlineNode* __fastcall GetNode(int Index);
	int __fastcall GetTopItem(void);
	TOutlineNode* __fastcall GetVisibleParent(void);
	bool __fastcall HasChildren(void);
	bool __fastcall HasVisibleParent(void);
	bool __fastcall IsEqual(TOutlineNode* Value);
	void __fastcall ReIndex(TOutlineNode* StartNode, TOutlineNode* EndNode, int NewIndex, bool IncludeStart);
	void __fastcall Repaint(void);
	bool __fastcall Resync(int &NewIndex, TOutlineNode* EndNode);
	void __fastcall SetExpandedState(bool Value);
	void __fastcall SetGoodIndex(void);
	void __fastcall SetHorzScrollBar(void);
	void __fastcall SetLevel(unsigned Level);
	void __fastcall SetText(const AnsiString Value);
	
protected:
	TOutlineNode* __fastcall GetVisibleNode(int TargetCount);
	int __fastcall AddNode(TOutlineNode* Value);
	int __fastcall InsertNode(int Index, TOutlineNode* Value);
	TOutlineNode* __fastcall GetNodeAtIndex(int TargetIndex);
	int __fastcall GetDataItem(void * Value);
	int __fastcall GetTextItem(const AnsiString Value);
	bool __fastcall HasAsParent(TOutlineNode* Value);
	bool __fastcall GetRowOfNode(TOutlineNode* TargetNode, int &RowCount);
	void __fastcall InternalRemove(TOutlineNode* Value, int Index);
	void __fastcall Remove(TOutlineNode* Value);
	void __fastcall WriteNode(char * Buffer, Classes::TStream* Stream);
	__property TCustomOutline* Outline = {read=FOutline};
	__property Classes::TList* List = {read=GetList};
	__property int ExpandCount = {read=FExpandCount, nodefault};
	__property TOutlineNode* Items[int Index] = {read=GetNode/*, default*/};
	
public:
	__fastcall TOutlineNode(TCustomOutline* AOwner);
	__fastcall virtual ~TOutlineNode(void);
	void __fastcall ChangeLevelBy(TChangeRange Value);
	void __fastcall Collapse(void);
	void __fastcall Expand(void);
	void __fastcall FullExpand(void);
	int __fastcall GetDisplayWidth(void);
	int __fastcall getFirstChild(void);
	int __fastcall GetLastChild(void);
	int __fastcall GetNextChild(int Value);
	int __fastcall GetPrevChild(int Value);
	void __fastcall MoveTo(int Destination, TAttachMode AttachMode);
	__property TOutlineNode* Parent = {read=FParent};
	__property bool Expanded = {read=FState, write=SetExpandedState, nodefault};
	__property AnsiString Text = {read=FText, write=SetText};
	__property void * Data = {read=FData, write=FData};
	__property int Index = {read=GetIndex, nodefault};
	__property unsigned Level = {read=GetLevel, write=SetLevel, nodefault};
	__property bool HasItems = {read=HasChildren, nodefault};
	__property bool IsVisible = {read=HasVisibleParent, nodefault};
	__property int TopItem = {read=GetTopItem, nodefault};
	__property AnsiString FullPath = {read=GetFullPath};
};


typedef Shortint TBitmapArrayRange;

class DELPHICLASS TOutline;
class PASCALIMPLEMENTATION TOutline : public TCustomOutline 
{
	typedef TCustomOutline inherited;
	
__published:
	__property Lines ;
	__property OutlineStyle  = {default=5};
	__property OnExpand ;
	__property OnCollapse ;
	__property Options  = {default=3};
	__property Style  = {default=0};
	__property ItemHeight ;
	__property OnDrawItem ;
	__property Align  = {default=0};
	__property Enabled  = {default=1};
	__property Font ;
	__property Color  = {default=-2147483643};
	__property ParentColor  = {default=0};
	__property ParentCtl3D  = {default=1};
	__property Ctl3D ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Visible  = {default=1};
	__property OnClick ;
	__property DragMode  = {default=0};
	__property DragKind  = {default=0};
	__property DragCursor  = {default=-12};
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDock ;
	__property OnEndDrag ;
	__property OnStartDock ;
	__property OnStartDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnDblClick ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property BorderStyle  = {default=1};
	__property ItemSeparator ;
	__property PicturePlus ;
	__property PictureMinus ;
	__property PictureOpen ;
	__property PictureClosed ;
	__property PictureLeaf ;
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property ShowHint ;
	__property PopupMenu ;
	__property ScrollBars  = {default=3};
	__property OnContextPopup ;
public:
	#pragma option push -w-inl
	/* TCustomOutline.Create */ inline __fastcall virtual TOutline(Classes::TComponent* AOwner) : TCustomOutline(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomOutline.Destroy */ inline __fastcall virtual ~TOutline(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TOutline(HWND ParentWindow) : TCustomOutline(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Outline */
using namespace Outline;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Outline
