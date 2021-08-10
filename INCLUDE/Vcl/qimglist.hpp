// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QImgList.pas' rev: 6.00

#ifndef QImgListHPP
#define QImgListHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QGraphics.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qimglist
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TChangeLink;
class DELPHICLASS TCustomImageList;
#pragma option push -b-
enum TImageType { itImage, itMask };
#pragma option pop

class PASCALIMPLEMENTATION TCustomImageList : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	Classes::TNotifyEvent FOnChange;
	Classes::TList* FClients;
	bool FChanged;
	int FHeight;
	int FWidth;
	int FUpdateCount;
	bool FMasked;
	Qgraphics::TColor FBkColor;
	Classes::TList* FPixmapList;
	Qt::QBitmapH* FTempMask;
	Qgraphics::TColor FMaskColor;
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetWidth(const int Value);
	void __fastcall CheckImage(Qgraphics::TGraphic* Image);
	void __fastcall CopyImages(TCustomImageList* Value);
	Qt::QPixmapH* __fastcall GetImageHandle(Qgraphics::TBitmap* AImage);
	Qt::QBitmapH* __fastcall GetMaskHandle(Qgraphics::TBitmap* AImage);
	bool __fastcall Equal(TCustomImageList* IL);
	void __fastcall DefaultMask(Qt::QPixmapH* AImage);
	int __fastcall AddImage(Qt::QPixmapH* AImage, Qt::QBitmapH* AMask);
	void __fastcall ReplaceImage(int Index, Qt::QPixmapH* AImage, Qt::QBitmapH* AMask);
	void __fastcall InsertImage(int Index, Qt::QPixmapH* AImage, Qt::QBitmapH* AMask);
	void __fastcall DoDelete(int Index);
	virtual void __fastcall DoDraw(int Index, Qgraphics::TCanvas* Canvas, int X, int Y, TImageType AImage, bool Enabled);
	void __fastcall HandleMultipleImages(Qt::QPixmapH* AImage, int AIndex);
	int __fastcall GetCount(void);
	void __fastcall FillImageList(Qgraphics::TBitmap* FullImage, Qgraphics::TBitmap* FullMask, int CX, int CY, int MaskOffset, int Count);
	void __fastcall ReadD2Stream(Classes::TStream* Stream);
	void __fastcall ReadD3Stream(Classes::TStream* Stream);
	void __fastcall ReadClxStream(Classes::TStream* Stream);
	
protected:
	DYNAMIC void __fastcall Change(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall Initialize(const int AWidth, const int AHeight);
	__property bool Masked = {read=FMasked, write=FMasked, default=1};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TCustomImageList(Classes::TComponent* AOwner);
	__fastcall TCustomImageList(int AWidth, int AHeight);
	__fastcall virtual ~TCustomImageList(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	int __fastcall Add(Qgraphics::TBitmap* AImage, Qgraphics::TBitmap* AMask);
	void __fastcall AddImages(TCustomImageList* Value);
	int __fastcall AddMasked(Qgraphics::TBitmap* AImage, Qgraphics::TColor MaskColor);
	void __fastcall Clear(void);
	void __fastcall Delete(int Index);
	void __fastcall Draw(Qgraphics::TCanvas* Canvas, int X, int Y, int Index, TImageType AImageType = (TImageType)(0x0), bool Enabled = true);
	void __fastcall GetBitmap(int Index, Qgraphics::TBitmap* Image);
	Qt::QPixmapH* __fastcall GetPixmap(int Index);
	Qt::QBitmapH* __fastcall GetMask(int Index);
	HIDESBASE void __fastcall Insert(int Index, Qgraphics::TBitmap* Image, Qgraphics::TBitmap* Mask);
	void __fastcall InsertMasked(int Index, Qgraphics::TBitmap* Image, Qgraphics::TColor MaskColor);
	virtual void __fastcall Move(int CurIndex, int NewIndex);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall RegisterChanges(TChangeLink* Value);
	void __fastcall Replace(int Index, Qgraphics::TBitmap* AImage, Qgraphics::TBitmap* AMask);
	void __fastcall ReplaceMasked(int Index, Qgraphics::TBitmap* NewImage, Qgraphics::TColor MaskColor);
	void __fastcall UnRegisterChanges(TChangeLink* Value);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	__property Qgraphics::TColor BkColor = {read=FBkColor, write=FBkColor, default=536870911};
	__property int Count = {read=GetCount, nodefault};
	__property int Height = {read=FHeight, write=SetHeight, default=16};
	__property int Width = {read=FWidth, write=SetWidth, default=16};
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

class DELPHICLASS TImageList;
class PASCALIMPLEMENTATION TImageList : public TCustomImageList 
{
	typedef TCustomImageList inherited;
	
__published:
	__property BkColor  = {default=536870911};
	__property Height  = {default=16};
	__property Masked  = {default=1};
	__property Width  = {default=16};
	__property OnChange ;
public:
	#pragma option push -w-inl
	/* TCustomImageList.Create */ inline __fastcall virtual TImageList(Classes::TComponent* AOwner) : TCustomImageList(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomImageList.CreateSize */ inline __fastcall TImageList(int AWidth, int AHeight) : TCustomImageList(AWidth, AHeight) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomImageList.Destroy */ inline __fastcall virtual ~TImageList(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qimglist */
using namespace Qimglist;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QImgList
