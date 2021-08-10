// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ImgList.pas' rev: 5.00

#ifndef ImgListHPP
#define ImgListHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Commctrl.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Imglist
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChangeLink;
class DELPHICLASS TCustomImageList;
#pragma option push -b-
enum TDrawingStyle { dsFocus, dsSelected, dsNormal, dsTransparent };
#pragma option pop

#pragma option push -b-
enum TImageType { itImage, itMask };
#pragma option pop

typedef Shortint TOverlay;

#pragma option push -b-
enum TResType { rtBitmap, rtCursor, rtIcon };
#pragma option pop

#pragma option push -b-
enum TLoadResource { lrDefaultColor, lrDefaultSize, lrFromFile, lrMap3DColors, lrTransparent, lrMonoChrome 
	};
#pragma option pop

typedef Set<TLoadResource, lrDefaultColor, lrMonoChrome>  TLoadResources;

class PASCALIMPLEMENTATION TCustomImageList : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	int FHeight;
	int FWidth;
	int FAllocBy;
	unsigned FHandle;
	TDrawingStyle FDrawingStyle;
	bool FMasked;
	bool FShareImages;
	TImageType FImageType;
	Graphics::TColor FBkColor;
	Graphics::TColor FBlendColor;
	Classes::TList* FClients;
	Graphics::TBitmap* FBitmap;
	Graphics::TBitmap* FMonoBitmap;
	bool FChanged;
	int FUpdateCount;
	Classes::TNotifyEvent FOnChange;
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall InitBitmap(void);
	void __fastcall CheckImage(Graphics::TGraphic* Image);
	void __fastcall CopyImages(unsigned Value);
	void __fastcall CreateImageList(void);
	bool __fastcall Equal(TCustomImageList* IL);
	void __fastcall FreeHandle(void);
	int __fastcall GetCount(void);
	HBITMAP __fastcall GetBitmapHandle(HBITMAP Bitmap);
	Graphics::TColor __fastcall GetBkColor(void);
	unsigned __fastcall GetHandle(void);
	HBITMAP __fastcall GetImageHandle(Graphics::TBitmap* Image, Graphics::TBitmap* ImageDDB);
	void __fastcall InsertImage(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask, Graphics::TColor 
		MaskColor);
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall SetBkColor(Graphics::TColor Value);
	void __fastcall SetDrawingStyle(TDrawingStyle Value);
	void __fastcall SetHandle(unsigned Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetNewDimensions(unsigned Value);
	void __fastcall SetWidth(int Value);
	void __fastcall WriteData(Classes::TStream* Stream);
	void __fastcall ReadD2Stream(Classes::TStream* Stream);
	void __fastcall ReadD3Stream(Classes::TStream* Stream);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	DYNAMIC void __fastcall Change(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall DoDraw(int Index, Graphics::TCanvas* Canvas, int X, int Y, unsigned Style, 
		bool Enabled);
	void __fastcall GetImages(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	void __fastcall HandleNeeded(void);
	virtual void __fastcall Initialize(void);
	
public:
	__fastcall virtual TCustomImageList(Classes::TComponent* AOwner);
	__fastcall TCustomImageList(int AWidth, int AHeight);
	__fastcall virtual ~TCustomImageList(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall Add(Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	int __fastcall AddIcon(Graphics::TIcon* Image);
	void __fastcall AddImages(TCustomImageList* Value);
	int __fastcall AddMasked(Graphics::TBitmap* Image, Graphics::TColor MaskColor);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	void __fastcall Draw(Graphics::TCanvas* Canvas, int X, int Y, int Index, bool Enabled);
	void __fastcall DrawOverlay(Graphics::TCanvas* Canvas, int X, int Y, int ImageIndex, TOverlay Overlay
		, bool Enabled);
	bool __fastcall FileLoad(TResType ResType, AnsiString Name, Graphics::TColor MaskColor);
	void __fastcall GetBitmap(int Index, Graphics::TBitmap* Image);
	virtual Windows::TPoint __fastcall GetHotSpot();
	void __fastcall GetIcon(int Index, Graphics::TIcon* Image);
	HBITMAP __fastcall GetImageBitmap(void);
	HBITMAP __fastcall GetMaskBitmap(void);
	bool __fastcall GetResource(TResType ResType, AnsiString Name, int Width, TLoadResources LoadFlags, 
		Graphics::TColor MaskColor);
	bool __fastcall GetInstRes(unsigned Instance, TResType ResType, AnsiString Name, int Width, TLoadResources 
		LoadFlags, Graphics::TColor MaskColor);
	bool __fastcall HandleAllocated(void);
	HIDESBASE void __fastcall Insert(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	void __fastcall InsertIcon(int Index, Graphics::TIcon* Image);
	void __fastcall InsertMasked(int Index, Graphics::TBitmap* Image, Graphics::TColor MaskColor);
	void __fastcall Move(int CurIndex, int NewIndex);
	bool __fastcall Overlay(int ImageIndex, TOverlay Overlay);
	void __fastcall RegisterChanges(TChangeLink* Value);
	bool __fastcall ResourceLoad(TResType ResType, AnsiString Name, Graphics::TColor MaskColor);
	bool __fastcall ResInstLoad(unsigned Instance, TResType ResType, AnsiString Name, Graphics::TColor 
		MaskColor);
	void __fastcall Replace(int Index, Graphics::TBitmap* Image, Graphics::TBitmap* Mask);
	void __fastcall ReplaceIcon(int Index, Graphics::TIcon* Image);
	void __fastcall ReplaceMasked(int Index, Graphics::TBitmap* NewImage, Graphics::TColor MaskColor);
	void __fastcall UnRegisterChanges(TChangeLink* Value);
	__property int Count = {read=GetCount, nodefault};
	__property unsigned Handle = {read=GetHandle, write=SetHandle, nodefault};
	__property int AllocBy = {read=FAllocBy, write=FAllocBy, default=4};
	__property Graphics::TColor BlendColor = {read=FBlendColor, write=FBlendColor, default=536870911};
	__property Graphics::TColor BkColor = {read=GetBkColor, write=SetBkColor, default=536870911};
	__property TDrawingStyle DrawingStyle = {read=FDrawingStyle, write=SetDrawingStyle, default=2};
	__property int Height = {read=FHeight, write=SetHeight, default=16};
	__property TImageType ImageType = {read=FImageType, write=FImageType, default=0};
	__property bool Masked = {read=FMasked, write=FMasked, default=1};
	__property bool ShareImages = {read=FShareImages, write=FShareImages, default=0};
	__property int Width = {read=FWidth, write=SetWidth, default=16};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


class PASCALIMPLEMENTATION TChangeLink : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TCustomImageList* FSender;
	Classes::TNotifyEvent FOnChange;
	
public:
	__fastcall virtual ~TChangeLink(void);
	DYNAMIC void __fastcall Change(void);
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TCustomImageList* Sender = {read=FSender, write=FSender};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TChangeLink(void) : System::TObject() { }
	#pragma option pop
	
};


typedef int TImageIndex;

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Imglist */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Imglist;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ImgList
