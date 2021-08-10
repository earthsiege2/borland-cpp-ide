// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Graphics.pas' rev: 5.00

#ifndef GraphicsHPP
#define GraphicsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Graphics
{
  enum TColor {clMin=-0x7fffffff-1, clMax=0x7fffffff};
}
namespace Graphics
{
  enum TFontStyle { fsBold, fsItalic, fsUnderline, fsStrikeOut };
  typedef SmallStringBase<31> TFontDataName;
  typedef SetBase<TFontStyle, fsBold, fsStrikeOut> TFontStylesBase;
}

namespace Graphics
{
//-- type declarations -------------------------------------------------------
typedef TColor *PColor;

class DELPHICLASS EInvalidGraphic;
class PASCALIMPLEMENTATION EInvalidGraphic : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidGraphic(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidGraphic(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidGraphic(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidGraphic(int Ident, const System::TVarRec * Args
		, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidGraphic(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidGraphic(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidGraphic(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidGraphic(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidGraphic(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidGraphicOperation;
class PASCALIMPLEMENTATION EInvalidGraphicOperation : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidGraphicOperation(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidGraphicOperation(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidGraphicOperation(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidGraphicOperation(int Ident, const System::TVarRec 
		* Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidGraphicOperation(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidGraphicOperation(const AnsiString Msg, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size
		, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidGraphicOperation(int Ident, int AHelpContext
		)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidGraphicOperation(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidGraphicOperation(void) { }
	#pragma option pop
	
};


struct TResData
{
	unsigned Handle;
} ;

#pragma option push -b-
enum TFontPitch { fpDefault, fpVariable, fpFixed };
#pragma option pop

typedef AnsiString TFontName;

typedef Byte TFontCharset;

typedef Set<TFontStyle, fsBold, fsStrikeOut>  TFontStyles;

struct TFontData
{
	HFONT Handle;
	int Height;
	TFontPitch Pitch;
	TFontStylesBase Style;
	TFontCharset Charset;
	TFontDataName Name;
} ;

#pragma option push -b-
enum TPenStyle { psSolid, psDash, psDot, psDashDot, psDashDotDot, psClear, psInsideFrame };
#pragma option pop

#pragma option push -b-
enum TPenMode { pmBlack, pmWhite, pmNop, pmNot, pmCopy, pmNotCopy, pmMergePenNot, pmMaskPenNot, pmMergeNotPen, 
	pmMaskNotPen, pmMerge, pmNotMerge, pmMask, pmNotMask, pmXor, pmNotXor };
#pragma option pop

struct TPenData
{
	HPEN Handle;
	TColor Color;
	int Width;
	TPenStyle Style;
} ;

#pragma option push -b-
enum TBrushStyle { bsSolid, bsClear, bsHorizontal, bsVertical, bsFDiagonal, bsBDiagonal, bsCross, bsDiagCross 
	};
#pragma option pop

class DELPHICLASS TBitmap;
class DELPHICLASS TGraphic;
#pragma option push -b-
enum TProgressStage { psStarting, psRunning, psEnding };
#pragma option pop

typedef void __fastcall (__closure *TProgressEvent)(System::TObject* Sender, TProgressStage Stage, Byte 
	PercentDone, bool RedrawNow, const Windows::TRect &R, const AnsiString Msg);

class DELPHICLASS TCanvas;
class PASCALIMPLEMENTATION TGraphic : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TNotifyEvent FOnChange;
	TProgressEvent FOnProgress;
	bool FModified;
	bool FTransparent;
	bool FPaletteModified;
	void __fastcall SetModified(bool Value);
	
protected:
	__fastcall virtual TGraphic(void);
	virtual void __fastcall Changed(System::TObject* Sender);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall Draw(TCanvas* ACanvas, const Windows::TRect &Rect) = 0 ;
	virtual bool __fastcall Equals(TGraphic* Graphic);
	virtual bool __fastcall GetEmpty(void) = 0 ;
	virtual int __fastcall GetHeight(void) = 0 ;
	virtual HPALETTE __fastcall GetPalette(void);
	virtual bool __fastcall GetTransparent(void);
	virtual int __fastcall GetWidth(void) = 0 ;
	DYNAMIC void __fastcall Progress(System::TObject* Sender, TProgressStage Stage, Byte PercentDone, bool 
		RedrawNow, const Windows::TRect &R, const AnsiString Msg);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	virtual void __fastcall SetHeight(int Value) = 0 ;
	virtual void __fastcall SetPalette(HPALETTE Value);
	virtual void __fastcall SetTransparent(bool Value);
	virtual void __fastcall SetWidth(int Value) = 0 ;
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	
public:
	virtual void __fastcall LoadFromFile(const AnsiString Filename);
	virtual void __fastcall SaveToFile(const AnsiString Filename);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream) = 0 ;
	virtual void __fastcall SaveToStream(Classes::TStream* Stream) = 0 ;
	virtual void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette) = 0 
		;
	virtual void __fastcall SaveToClipboardFormat(Word &AFormat, unsigned &AData, HPALETTE &APalette) = 0 
		;
	__property bool Empty = {read=GetEmpty, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property bool Modified = {read=FModified, write=SetModified, nodefault};
	__property HPALETTE Palette = {read=GetPalette, write=SetPalette, nodefault};
	__property bool PaletteModified = {read=FPaletteModified, write=FPaletteModified, nodefault};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGraphic(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBitmapImage;
class DELPHICLASS TSharedImage;
class PASCALIMPLEMENTATION TSharedImage : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	int FRefCount;
	
protected:
	void __fastcall Reference(void);
	void __fastcall Release(void);
	virtual void __fastcall FreeHandle(void) = 0 ;
	__property int RefCount = {read=FRefCount, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TSharedImage(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TSharedImage(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TBitmapImage : public TSharedImage 
{
	typedef TSharedImage inherited;
	
private:
	HBITMAP FHandle;
	HBITMAP FMaskHandle;
	HPALETTE FPalette;
	HBITMAP FDIBHandle;
	#pragma pack(push, 1)
	tagDIBSECTION FDIB;
	#pragma pack(pop)
	
	Classes::TMemoryStream* FSaveStream;
	bool FOS2Format;
	bool FHalftone;
	
protected:
	virtual void __fastcall FreeHandle(void);
	
public:
	__fastcall virtual ~TBitmapImage(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TBitmapImage(void) : TSharedImage() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TTransparentMode { tmAuto, tmFixed };
#pragma option pop

#pragma option push -b-
enum TBitmapHandleType { bmDIB, bmDDB };
#pragma option pop

#pragma option push -b-
enum TPixelFormat { pfDevice, pf1bit, pf4bit, pf8bit, pf15bit, pf16bit, pf24bit, pf32bit, pfCustom }
	;
#pragma option pop

class PASCALIMPLEMENTATION TBitmap : public TGraphic 
{
	typedef TGraphic inherited;
	
private:
	TBitmapImage* FImage;
	TCanvas* FCanvas;
	bool FIgnorePalette;
	bool FMaskBitsValid;
	bool FMaskValid;
	TColor FTransparentColor;
	TTransparentMode FTransparentMode;
	void __fastcall Changing(System::TObject* Sender);
	void __fastcall CopyImage(HBITMAP AHandle, HPALETTE APalette, const tagDIBSECTION &DIB);
	void __fastcall DIBNeeded(void);
	void __fastcall FreeContext(void);
	TCanvas* __fastcall GetCanvas(void);
	virtual HBITMAP __fastcall GetHandle(void);
	TBitmapHandleType __fastcall GetHandleType(void);
	virtual HBITMAP __fastcall GetMaskHandle(void);
	bool __fastcall GetMonochrome(void);
	TPixelFormat __fastcall GetPixelFormat(void);
	void * __fastcall GetScanline(int Row);
	TColor __fastcall GetTransparentColor(void);
	void __fastcall NewImage(HBITMAP NewHandle, HPALETTE NewPalette, const tagDIBSECTION &NewDIB, bool 
		OS2Format, Classes::TStream* RLEStream);
	void __fastcall ReadStream(Classes::TStream* Stream, int Size);
	void __fastcall ReadDIB(Classes::TStream* Stream, unsigned ImageSize);
	void __fastcall SetHandle(HBITMAP Value);
	virtual void __fastcall SetHandleType(TBitmapHandleType Value);
	void __fastcall SetMaskHandle(HBITMAP Value);
	void __fastcall SetMonochrome(bool Value);
	void __fastcall SetPixelFormat(TPixelFormat Value);
	void __fastcall SetTransparentColor(TColor Value);
	void __fastcall SetTransparentMode(TTransparentMode Value);
	bool __fastcall TransparentColorStored(void);
	void __fastcall WriteStream(Classes::TStream* Stream, bool WriteSize);
	
protected:
	virtual void __fastcall Changed(System::TObject* Sender);
	virtual void __fastcall Draw(TCanvas* ACanvas, const Windows::TRect &Rect);
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual HPALETTE __fastcall GetPalette(void);
	virtual int __fastcall GetWidth(void);
	void __fastcall HandleNeeded(void);
	void __fastcall MaskHandleNeeded(void);
	void __fastcall PaletteNeeded(void);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetPalette(HPALETTE Value);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	
public:
	__fastcall virtual TBitmap(void);
	__fastcall virtual ~TBitmap(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall Dormant(void);
	void __fastcall FreeImage(void);
	virtual void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall LoadFromResourceName(unsigned Instance, const AnsiString ResName);
	void __fastcall LoadFromResourceID(unsigned Instance, int ResID);
	void __fastcall Mask(TColor TransparentColor);
	HBITMAP __fastcall ReleaseHandle(void);
	HBITMAP __fastcall ReleaseMaskHandle(void);
	HPALETTE __fastcall ReleasePalette(void);
	virtual void __fastcall SaveToClipboardFormat(Word &Format, unsigned &Data, HPALETTE &APalette);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	__property TCanvas* Canvas = {read=GetCanvas};
	__property HBITMAP Handle = {read=GetHandle, write=SetHandle, nodefault};
	__property TBitmapHandleType HandleType = {read=GetHandleType, write=SetHandleType, nodefault};
	__property bool IgnorePalette = {read=FIgnorePalette, write=FIgnorePalette, nodefault};
	__property HBITMAP MaskHandle = {read=GetMaskHandle, write=SetMaskHandle, nodefault};
	__property bool Monochrome = {read=GetMonochrome, write=SetMonochrome, nodefault};
	__property TPixelFormat PixelFormat = {read=GetPixelFormat, write=SetPixelFormat, nodefault};
	__property void * ScanLine[int Row] = {read=GetScanline};
	__property TColor TransparentColor = {read=GetTransparentColor, write=SetTransparentColor, stored=TransparentColorStored
		, nodefault};
	__property TTransparentMode TransparentMode = {read=FTransparentMode, write=SetTransparentMode, default=0
		};
};


struct TBrushData
{
	HBRUSH Handle;
	TColor Color;
	TBitmap* Bitmap;
	TBrushStyle Style;
} ;

struct TResource;
typedef TResource *PResource;

struct TResource
{
	TResource *Next;
	int RefCount;
	unsigned Handle;
	Word HashCode;
	union
	{
		struct 
		{
			TBrushData Brush;
			
		};
		struct 
		{
			TPenData Pen;
			
		};
		struct 
		{
			TFontData Font;
			
		};
		struct 
		{
			TResData Data;
			
		};
		
	};
} ;

class DELPHICLASS TGraphicsObject;
class PASCALIMPLEMENTATION TGraphicsObject : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TNotifyEvent FOnChange;
	TResource *FResource;
	_RTL_CRITICAL_SECTION *FOwnerLock;
	
protected:
	DYNAMIC void __fastcall Changed(void);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	
public:
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Windows::PRTLCriticalSection OwnerCriticalSection = {read=FOwnerLock, write=FOwnerLock};
		
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGraphicsObject(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TGraphicsObject(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


__interface IChangeNotifier;
typedef System::DelphiInterface<IChangeNotifier> _di_IChangeNotifier;
__interface INTERFACE_UUID("{1FB62321-44A7-11D0-9E93-0020AF3D82DA}") IChangeNotifier  : public IUnknown 
	
{
	
public:
	virtual void __fastcall Changed(void) = 0 ;
};

class DELPHICLASS TFont;
class PASCALIMPLEMENTATION TFont : public TGraphicsObject 
{
	typedef TGraphicsObject inherited;
	
private:
	TColor FColor;
	int FPixelsPerInch;
	_di_IChangeNotifier FNotify;
	void __fastcall GetData(TFontData &FontData);
	void __fastcall SetData(const TFontData &FontData);
	
protected:
	DYNAMIC void __fastcall Changed(void);
	HFONT __fastcall GetHandle(void);
	int __fastcall GetHeight(void);
	AnsiString __fastcall GetName();
	TFontPitch __fastcall GetPitch(void);
	int __fastcall GetSize(void);
	TFontStyles __fastcall GetStyle(void);
	TFontCharset __fastcall GetCharset(void);
	void __fastcall SetColor(TColor Value);
	void __fastcall SetHandle(HFONT Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetName(const AnsiString Value);
	void __fastcall SetPitch(TFontPitch Value);
	void __fastcall SetSize(int Value);
	void __fastcall SetStyle(TFontStyles Value);
	void __fastcall SetCharset(TFontCharset Value);
	
public:
	__fastcall TFont(void);
	__fastcall virtual ~TFont(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property _di_IChangeNotifier FontAdapter = {read=FNotify, write=FNotify};
	__property HFONT Handle = {read=GetHandle, write=SetHandle, nodefault};
	__property int PixelsPerInch = {read=FPixelsPerInch, write=FPixelsPerInch, nodefault};
	
__published:
	__property TFontCharset Charset = {read=GetCharset, write=SetCharset, nodefault};
	__property TColor Color = {read=FColor, write=SetColor, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property AnsiString Name = {read=GetName, write=SetName};
	__property TFontPitch Pitch = {read=GetPitch, write=SetPitch, default=0};
	__property int Size = {read=GetSize, write=SetSize, stored=false, nodefault};
	__property TFontStyles Style = {read=GetStyle, write=SetStyle, nodefault};
};


class DELPHICLASS TPen;
class PASCALIMPLEMENTATION TPen : public TGraphicsObject 
{
	typedef TGraphicsObject inherited;
	
private:
	TPenMode FMode;
	void __fastcall GetData(TPenData &PenData);
	void __fastcall SetData(const TPenData &PenData);
	
protected:
	TColor __fastcall GetColor(void);
	void __fastcall SetColor(TColor Value);
	HPEN __fastcall GetHandle(void);
	void __fastcall SetHandle(HPEN Value);
	void __fastcall SetMode(TPenMode Value);
	TPenStyle __fastcall GetStyle(void);
	void __fastcall SetStyle(TPenStyle Value);
	int __fastcall GetWidth(void);
	void __fastcall SetWidth(int Value);
	
public:
	__fastcall TPen(void);
	__fastcall virtual ~TPen(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property HPEN Handle = {read=GetHandle, write=SetHandle, nodefault};
	
__published:
	__property TColor Color = {read=GetColor, write=SetColor, default=0};
	__property TPenMode Mode = {read=FMode, write=SetMode, default=4};
	__property TPenStyle Style = {read=GetStyle, write=SetStyle, default=0};
	__property int Width = {read=GetWidth, write=SetWidth, default=1};
};


class DELPHICLASS TBrush;
class PASCALIMPLEMENTATION TBrush : public TGraphicsObject 
{
	typedef TGraphicsObject inherited;
	
private:
	void __fastcall GetData(TBrushData &BrushData);
	void __fastcall SetData(const TBrushData &BrushData);
	
protected:
	TBitmap* __fastcall GetBitmap(void);
	void __fastcall SetBitmap(TBitmap* Value);
	TColor __fastcall GetColor(void);
	void __fastcall SetColor(TColor Value);
	HBRUSH __fastcall GetHandle(void);
	void __fastcall SetHandle(HBRUSH Value);
	TBrushStyle __fastcall GetStyle(void);
	void __fastcall SetStyle(TBrushStyle Value);
	
public:
	__fastcall TBrush(void);
	__fastcall virtual ~TBrush(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property HBRUSH Handle = {read=GetHandle, write=SetHandle, nodefault};
	
__published:
	__property TColor Color = {read=GetColor, write=SetColor, default=16777215};
	__property TBrushStyle Style = {read=GetStyle, write=SetStyle, default=0};
};


#pragma option push -b-
enum TFillStyle { fsSurface, fsBorder };
#pragma option pop

#pragma option push -b-
enum TFillMode { fmAlternate, fmWinding };
#pragma option pop

typedef int TCopyMode;

#pragma option push -b-
enum TCanvasStates { csHandleValid, csFontValid, csPenValid, csBrushValid };
#pragma option pop

typedef Set<TCanvasStates, csHandleValid, csBrushValid>  TCanvasState;

#pragma option push -b-
enum TCanvasOrientation { coLeftToRight, coRightToLeft };
#pragma option pop

class PASCALIMPLEMENTATION TCanvas : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	HDC FHandle;
	TCanvasState State;
	TFont* FFont;
	TPen* FPen;
	TBrush* FBrush;
	Windows::TPoint FPenPos;
	int FCopyMode;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnChanging;
	_RTL_CRITICAL_SECTION FLock;
	int FLockCount;
	int FTextFlags;
	void __fastcall CreateBrush(void);
	void __fastcall CreateFont(void);
	void __fastcall CreatePen(void);
	void __fastcall BrushChanged(System::TObject* ABrush);
	void __fastcall DeselectHandles(void);
	TCanvasOrientation __fastcall GetCanvasOrientation(void);
	Windows::TRect __fastcall GetClipRect();
	HDC __fastcall GetHandle(void);
	Windows::TPoint __fastcall GetPenPos();
	TColor __fastcall GetPixel(int X, int Y);
	void __fastcall FontChanged(System::TObject* AFont);
	void __fastcall PenChanged(System::TObject* APen);
	void __fastcall SetBrush(TBrush* Value);
	void __fastcall SetFont(TFont* Value);
	void __fastcall SetHandle(HDC Value);
	void __fastcall SetPen(TPen* Value);
	void __fastcall SetPenPos(const Windows::TPoint &Value);
	void __fastcall SetPixel(int X, int Y, TColor Value);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall Changing(void);
	virtual void __fastcall CreateHandle(void);
	void __fastcall RequiredState(TCanvasState ReqState);
	
public:
	__fastcall TCanvas(void);
	__fastcall virtual ~TCanvas(void);
	void __fastcall Arc(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void __fastcall BrushCopy(const Windows::TRect &Dest, TBitmap* Bitmap, const Windows::TRect &Source
		, TColor Color);
	void __fastcall Chord(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void __fastcall CopyRect(const Windows::TRect &Dest, TCanvas* Canvas, const Windows::TRect &Source)
		;
	void __fastcall Draw(int X, int Y, TGraphic* Graphic);
	void __fastcall DrawFocusRect(const Windows::TRect &Rect);
	void __fastcall Ellipse(int X1, int Y1, int X2, int Y2)/* overload */;
	void __fastcall Ellipse(const Windows::TRect &Rect)/* overload */;
	void __fastcall FillRect(const Windows::TRect &Rect);
	void __fastcall FloodFill(int X, int Y, TColor Color, TFillStyle FillStyle);
	void __fastcall FrameRect(const Windows::TRect &Rect);
	void __fastcall LineTo(int X, int Y);
	void __fastcall Lock(void);
	void __fastcall MoveTo(int X, int Y);
	void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void __fastcall Polygon(const Windows::TPoint * Points, const int Points_Size);
	void __fastcall Polyline(const Windows::TPoint * Points, const int Points_Size);
	void __fastcall PolyBezier(const Windows::TPoint * Points, const int Points_Size);
	void __fastcall PolyBezierTo(const Windows::TPoint * Points, const int Points_Size);
	void __fastcall Rectangle(int X1, int Y1, int X2, int Y2)/* overload */;
	void __fastcall Rectangle(const Windows::TRect &Rect)/* overload */;
	void __fastcall Refresh(void);
	void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3);
	void __fastcall StretchDraw(const Windows::TRect &Rect, TGraphic* Graphic);
	tagSIZE __fastcall TextExtent(const AnsiString Text);
	int __fastcall TextHeight(const AnsiString Text);
	void __fastcall TextOut(int X, int Y, const AnsiString Text);
	void __fastcall TextRect(const Windows::TRect &Rect, int X, int Y, const AnsiString Text);
	int __fastcall TextWidth(const AnsiString Text);
	bool __fastcall TryLock(void);
	void __fastcall Unlock(void);
	__property Windows::TRect ClipRect = {read=GetClipRect};
	__property HDC Handle = {read=GetHandle, write=SetHandle, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	__property TCanvasOrientation CanvasOrientation = {read=GetCanvasOrientation, nodefault};
	__property Windows::TPoint PenPos = {read=GetPenPos, write=SetPenPos};
	__property TColor Pixels[int X][int Y] = {read=GetPixel, write=SetPixel};
	__property int TextFlags = {read=FTextFlags, write=FTextFlags, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	
__published:
	__property TBrush* Brush = {read=FBrush, write=SetBrush};
	__property int CopyMode = {read=FCopyMode, write=FCopyMode, default=13369376};
	__property TFont* Font = {read=FFont, write=SetFont};
	__property TPen* Pen = {read=FPen, write=SetPen};
};


typedef TMetaClass*TGraphicClass;

class DELPHICLASS TPicture;
class DELPHICLASS TIcon;
class DELPHICLASS TMetafile;
class PASCALIMPLEMENTATION TPicture : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	TGraphic* FGraphic;
	Classes::TNotifyEvent FOnChange;
	_di_IChangeNotifier FNotify;
	TProgressEvent FOnProgress;
	void __fastcall ForceType(TMetaClass* GraphicType);
	TBitmap* __fastcall GetBitmap(void);
	int __fastcall GetHeight(void);
	TIcon* __fastcall GetIcon(void);
	TMetafile* __fastcall GetMetafile(void);
	int __fastcall GetWidth(void);
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall SetBitmap(TBitmap* Value);
	void __fastcall SetGraphic(TGraphic* Value);
	void __fastcall SetIcon(TIcon* Value);
	void __fastcall SetMetafile(TMetafile* Value);
	void __fastcall WriteData(Classes::TStream* Stream);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	DYNAMIC void __fastcall Changed(System::TObject* Sender);
	DYNAMIC void __fastcall Progress(System::TObject* Sender, TProgressStage Stage, Byte PercentDone, bool 
		RedrawNow, const Windows::TRect &R, const AnsiString Msg);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	
public:
	__fastcall TPicture(void);
	__fastcall virtual ~TPicture(void);
	void __fastcall LoadFromFile(const AnsiString Filename);
	void __fastcall SaveToFile(const AnsiString Filename);
	void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette);
	void __fastcall SaveToClipboardFormat(Word &AFormat, unsigned &AData, HPALETTE &APalette);
	/*         class method */ static bool __fastcall SupportsClipboardFormat(TMetaClass* vmt, Word AFormat
		);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/*         class method */ static void __fastcall RegisterFileFormat(TMetaClass* vmt, const AnsiString 
		AExtension, const AnsiString ADescription, TMetaClass* AGraphicClass);
	/*         class method */ static void __fastcall RegisterFileFormatRes(TMetaClass* vmt, const AnsiString 
		AExtension, int ADescriptionResID, TMetaClass* AGraphicClass);
	/*         class method */ static void __fastcall RegisterClipboardFormat(TMetaClass* vmt, Word AFormat
		, TMetaClass* AGraphicClass);
	/*         class method */ static void __fastcall UnregisterGraphicClass(TMetaClass* vmt, TMetaClass* 
		AClass);
	__property TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property TGraphic* Graphic = {read=FGraphic, write=SetGraphic};
	__property _di_IChangeNotifier PictureAdapter = {read=FNotify, write=FNotify};
	__property int Height = {read=GetHeight, nodefault};
	__property TIcon* Icon = {read=GetIcon, write=SetIcon};
	__property TMetafile* Metafile = {read=GetMetafile, write=SetMetafile};
	__property int Width = {read=GetWidth, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
};


class DELPHICLASS TMetafileCanvas;
class PASCALIMPLEMENTATION TMetafileCanvas : public TCanvas 
{
	typedef TCanvas inherited;
	
private:
	TMetafile* FMetafile;
	
public:
	__fastcall TMetafileCanvas(TMetafile* AMetafile, HDC ReferenceDevice);
	__fastcall TMetafileCanvas(TMetafile* AMetafile, HDC ReferenceDevice, const AnsiString CreatedBy, const 
		AnsiString Description);
	__fastcall virtual ~TMetafileCanvas(void);
};


class DELPHICLASS TMetafileImage;
class PASCALIMPLEMENTATION TMetafileImage : public TSharedImage 
{
	typedef TSharedImage inherited;
	
private:
	unsigned FHandle;
	int FWidth;
	int FHeight;
	HPALETTE FPalette;
	Word FInch;
	int FTempWidth;
	int FTempHeight;
	
protected:
	virtual void __fastcall FreeHandle(void);
	
public:
	__fastcall virtual ~TMetafileImage(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TMetafileImage(void) : TSharedImage() { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TMetafile : public TGraphic 
{
	typedef TGraphic inherited;
	
private:
	TMetafileImage* FImage;
	bool FEnhanced;
	AnsiString __fastcall GetAuthor();
	AnsiString __fastcall GetDesc();
	unsigned __fastcall GetHandle(void);
	Word __fastcall GetInch(void);
	int __fastcall GetMMHeight(void);
	int __fastcall GetMMWidth(void);
	void __fastcall NewImage(void);
	void __fastcall SetHandle(unsigned Value);
	void __fastcall SetInch(Word Value);
	void __fastcall SetMMHeight(int Value);
	void __fastcall SetMMWidth(int Value);
	void __fastcall UniqueImage(void);
	
protected:
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual HPALETTE __fastcall GetPalette(void);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall Draw(TCanvas* ACanvas, const Windows::TRect &Rect);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall ReadEMFStream(Classes::TStream* Stream);
	void __fastcall ReadWMFStream(Classes::TStream* Stream, int Length);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetTransparent(bool Value);
	virtual void __fastcall SetWidth(int Value);
	bool __fastcall TestEMF(Classes::TStream* Stream);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	void __fastcall WriteEMFStream(Classes::TStream* Stream);
	void __fastcall WriteWMFStream(Classes::TStream* Stream);
	
public:
	__fastcall virtual TMetafile(void);
	__fastcall virtual ~TMetafile(void);
	void __fastcall Clear(void);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall SaveToFile(const AnsiString Filename);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette);
	virtual void __fastcall SaveToClipboardFormat(Word &AFormat, unsigned &AData, HPALETTE &APalette);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	unsigned __fastcall ReleaseHandle(void);
	__property AnsiString CreatedBy = {read=GetAuthor};
	__property AnsiString Description = {read=GetDesc};
	__property bool Enhanced = {read=FEnhanced, write=FEnhanced, default=1};
	__property unsigned Handle = {read=GetHandle, write=SetHandle, nodefault};
	__property int MMWidth = {read=GetMMWidth, write=SetMMWidth, nodefault};
	__property int MMHeight = {read=GetMMHeight, write=SetMMHeight, nodefault};
	__property Word Inch = {read=GetInch, write=SetInch, nodefault};
};


class DELPHICLASS TIconImage;
class PASCALIMPLEMENTATION TIconImage : public TSharedImage 
{
	typedef TSharedImage inherited;
	
private:
	HICON FHandle;
	Classes::TCustomMemoryStream* FMemoryImage;
	Windows::TPoint FSize;
	
protected:
	virtual void __fastcall FreeHandle(void);
	
public:
	__fastcall virtual ~TIconImage(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TIconImage(void) : TSharedImage() { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TIcon : public TGraphic 
{
	typedef TGraphic inherited;
	
private:
	TIconImage* FImage;
	Windows::TPoint FRequestedSize;
	HICON __fastcall GetHandle(void);
	void __fastcall HandleNeeded(void);
	void __fastcall ImageNeeded(void);
	void __fastcall NewImage(HICON NewHandle, Classes::TMemoryStream* NewImage);
	void __fastcall SetHandle(HICON Value);
	
protected:
	virtual void __fastcall Draw(TCanvas* ACanvas, const Windows::TRect &Rect);
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetTransparent(bool Value);
	virtual void __fastcall SetWidth(int Value);
	
public:
	__fastcall virtual TIcon(void);
	__fastcall virtual ~TIcon(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	HICON __fastcall ReleaseHandle(void);
	virtual void __fastcall SaveToClipboardFormat(Word &Format, unsigned &Data, HPALETTE &APalette);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	__property HICON Handle = {read=GetHandle, write=SetHandle, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
static const TColor clScrollBar = 0x80000000;
static const TColor clBackground = 0x80000001;
static const TColor clActiveCaption = 0x80000002;
static const TColor clInactiveCaption = 0x80000003;
static const TColor clMenu = 0x80000004;
static const TColor clWindow = 0x80000005;
static const TColor clWindowFrame = 0x80000006;
static const TColor clMenuText = 0x80000007;
static const TColor clWindowText = 0x80000008;
static const TColor clCaptionText = 0x80000009;
static const TColor clActiveBorder = 0x8000000a;
static const TColor clInactiveBorder = 0x8000000b;
static const TColor clAppWorkSpace = 0x8000000c;
static const TColor clHighlight = 0x8000000d;
static const TColor clHighlightText = 0x8000000e;
static const TColor clBtnFace = 0x8000000f;
static const TColor clBtnShadow = 0x80000010;
static const TColor clGrayText = 0x80000011;
static const TColor clBtnText = 0x80000012;
static const TColor clInactiveCaptionText = 0x80000013;
static const TColor clBtnHighlight = 0x80000014;
static const TColor cl3DDkShadow = 0x80000015;
static const TColor cl3DLight = 0x80000016;
static const TColor clInfoText = 0x80000017;
static const TColor clInfoBk = 0x80000018;
static const TColor clBlack = 0x0;
static const TColor clMaroon = 0x80;
static const TColor clGreen = 0x8000;
static const TColor clOlive = 0x8080;
static const TColor clNavy = 0x800000;
static const TColor clPurple = 0x800080;
static const TColor clTeal = 0x808000;
static const TColor clGray = 0x808080;
static const TColor clSilver = 0xc0c0c0;
static const TColor clRed = 0xff;
static const TColor clLime = 0xff00;
static const TColor clYellow = 0xffff;
static const TColor clBlue = 0xff0000;
static const TColor clFuchsia = 0xff00ff;
static const TColor clAqua = 0xffff00;
static const TColor clLtGray = 0xc0c0c0;
static const TColor clDkGray = 0x808080;
static const TColor clWhite = 0xffffff;
static const TColor clNone = 0x1fffffff;
static const TColor clDefault = 0x20000000;
static const Shortint cmBlackness = 0x42;
static const int cmDstInvert = 0x550009;
static const int cmMergeCopy = 0xc000ca;
static const int cmMergePaint = 0xbb0226;
static const int cmNotSrcCopy = 0x330008;
static const int cmNotSrcErase = 0x1100a6;
static const int cmPatCopy = 0xf00021;
static const int cmPatInvert = 0x5a0049;
static const int cmPatPaint = 0xfb0a09;
static const int cmSrcAnd = 0x8800c6;
static const int cmSrcCopy = 0xcc0020;
static const int cmSrcErase = 0x440328;
static const int cmSrcInvert = 0x660046;
static const int cmSrcPaint = 0xee0086;
static const int cmWhiteness = 0xff0062;
extern PACKAGE TFontData DefFontData;
extern PACKAGE HPALETTE SystemPalette16;
extern PACKAGE bool DDBsOnly;
extern PACKAGE void __fastcall PaletteChanged(void);
extern PACKAGE int __fastcall ColorToRGB(TColor Color);
extern PACKAGE AnsiString __fastcall ColorToString(TColor Color);
extern PACKAGE TColor __fastcall StringToColor(const AnsiString S);
extern PACKAGE void __fastcall GetColorValues(Classes::TGetStrProc Proc);
extern PACKAGE bool __fastcall ColorToIdent(int Color, AnsiString &Ident);
extern PACKAGE bool __fastcall IdentToColor(const AnsiString Ident, int &Color);
extern PACKAGE void __fastcall GetCharsetValues(Classes::TGetStrProc Proc);
extern PACKAGE bool __fastcall CharsetToIdent(int Charset, AnsiString &Ident);
extern PACKAGE bool __fastcall IdentToCharset(const AnsiString Ident, int &Charset);
extern PACKAGE int __fastcall BytesPerScanline(int PixelsPerScanline, int BitsPerPixel, int Alignment
	);
extern PACKAGE bool __fastcall TransparentStretchBlt(HDC DstDC, int DstX, int DstY, int DstW, int DstH
	, HDC SrcDC, int SrcX, int SrcY, int SrcW, int SrcH, HDC MaskDC, int MaskX, int MaskY);
extern PACKAGE void __fastcall GetDIBSizes(HBITMAP Bitmap, unsigned &InfoHeaderSize, unsigned &ImageSize
	);
extern PACKAGE bool __fastcall GetDIB(HBITMAP Bitmap, HPALETTE Palette, void *BitmapInfo, void *Bits
	);
extern PACKAGE void __fastcall FreeMemoryContexts(void);
extern PACKAGE HBITMAP __fastcall CreateMappedBmp(HBITMAP Handle, const TColor * OldColors, const int 
	OldColors_Size, const TColor * NewColors, const int NewColors_Size);
extern PACKAGE HBITMAP __fastcall CreateMappedRes(unsigned Instance, char * ResName, const TColor * 
	OldColors, const int OldColors_Size, const TColor * NewColors, const int NewColors_Size);
extern PACKAGE HBITMAP __fastcall CreateGrayMappedBmp(HBITMAP Handle);
extern PACKAGE HBITMAP __fastcall CreateGrayMappedRes(unsigned Instance, char * ResName);
extern PACKAGE HPALETTE __fastcall CopyPalette(HPALETTE Palette);
extern PACKAGE AnsiString __fastcall GraphicFilter(TMetaClass* GraphicClass);
extern PACKAGE AnsiString __fastcall GraphicExtension(TMetaClass* GraphicClass);
extern PACKAGE AnsiString __fastcall GraphicFileMask(TMetaClass* GraphicClass);
extern PACKAGE TFontCharset __fastcall GetDefFontCharSet(void);
extern PACKAGE TBitmap* __fastcall AllocPatternBitmap(TColor BkColor, TColor FgColor);

}	/* namespace Graphics */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Graphics;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Graphics
