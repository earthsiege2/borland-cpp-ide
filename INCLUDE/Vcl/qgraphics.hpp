// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QGraphics.pas' rev: 6.00

#ifndef QGraphicsHPP
#define QGraphicsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Qt.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
namespace Qgraphics
{
  enum TColor {clMin=-0x7fffffff-1, clMax=0x7fffffff};
}
enum TFontCharSet { fcsLatin1, fcsAnyCharSet, fcsLatin2, fcsLatin3, fcsLatin4, fcsISO_8859_5,
fcsISO_8859_6, fcsISO_8859_7, fcsISO_8859_8, fcsLatin5, fcsLatin6, fcsISO_8859_11, fcsISO_8859_12,
fcsLatin7, fcsLatin8, fcsLatin9, fcsKOI8R, fcsSet_Ja, fcsSet_Ko, fcsSet_Th_TH, fcsSet_Zh, fcsSet_Zh_TW,
fcsUnicode, fcsDefaultCharSet, fcsANSI_CHARSET, fcsDEFAULT_CHARSET, fcsSYMBOL_CHARSET, fcsMAC_CHARSET,
fcsSHIFTJIS_CHARSET, fcsHANGEUL_CHARSET, fcsJOHAB_CHARSET, fcsGB2312_CHARSET, fcsCHINESEBIG5_CHARSET,
fcsGREEK_CHARSET, fcsTURKISH_CHARSET, fcsHEBREW_CHARSET, fcsARABIC_CHARSET, fcsBALTIC_CHARSET,
fcsRUSSIAN_CHARSET, fcsTHAI_CHARSET, fcsEASTEUROPE_CHARSET, fcsOEM_CHARSET };

namespace Qgraphics
{
//-- type declarations -------------------------------------------------------
typedef TColor *PColor;

typedef unsigned TColorRef;

typedef Shortint TMappedColor;

class DELPHICLASS EInvalidGraphic;
class PASCALIMPLEMENTATION EInvalidGraphic : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidGraphic(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidGraphic(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidGraphic(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidGraphic(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidGraphic(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidGraphic(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidGraphic(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidGraphic(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
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
	/* Exception.Create */ inline __fastcall EInvalidGraphicOperation(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidGraphicOperation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidGraphicOperation(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidGraphicOperation(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidGraphicOperation(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidGraphicOperation(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidGraphicOperation(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidGraphicOperation(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidGraphicOperation(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalidHandleException;
class PASCALIMPLEMENTATION EInvalidHandleException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalidHandleException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalidHandleException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalidHandleException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalidHandleException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalidHandleException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalidHandleException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalidHandleException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalidHandleException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalidHandleException(void) { }
	#pragma option pop
	
};


class DELPHICLASS TGraphicsObject;
class PASCALIMPLEMENTATION TGraphicsObject : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TNotifyEvent FOnChange;
	int FChangeDisabled;
	bool FChangePending;
	
protected:
	virtual void __fastcall Changed(void);
	void __fastcall Lock(void);
	void __fastcall Unlock(void);
	void __fastcall DisableChanged(void);
	void __fastcall EnableChanged(void);
	
public:
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGraphicsObject(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TGraphicsObject(void) : Classes::TPersistent() { }
	#pragma option pop
	
};


#pragma option push -b-
enum TFontPitch { fpDefault, fpVariable, fpFixed };
#pragma option pop

typedef AnsiString TFontName;

#pragma option push -b-
enum TFontStyle { fsBold, fsItalic, fsUnderline, fsStrikeOut };
#pragma option pop

typedef Set<TFontStyle, fsBold, fsStrikeOut>  TFontStyles;

#pragma option push -b-
enum TFontHint { fhHelvetica, fhTimes, fhCourier, fhOldEnglish, fhSystem, fhAny };
#pragma option pop

class DELPHICLASS TFont;
class PASCALIMPLEMENTATION TFont : public TGraphicsObject 
{
	typedef TGraphicsObject inherited;
	
private:
	int FPixelsPerInch;
	TColor FColor;
	Qt::QFontH* FHandle;
	Qt::QPenH* FFontPen;
	int FOriginalWeight;
	bool FOwned;
	TFontCharSet FCharSet;
	void __fastcall FreeHandle(void);
	int __fastcall GetHeight(void);
	AnsiString __fastcall GetName();
	TFontPitch __fastcall GetPitch(void);
	int __fastcall GetSize(void);
	TFontStyles __fastcall GetStyle(void);
	int __fastcall GetWeight(void);
	bool __fastcall IsWeightStored(void);
	void __fastcall SetCharSet(TFontCharSet Value);
	void __fastcall SetColor(const TColor Value);
	void __fastcall SetHandle(const Qt::QFontH* Value);
	void __fastcall SetHeight(const int Value);
	void __fastcall SetName(const AnsiString Value);
	void __fastcall SetPitch(const TFontPitch Value);
	void __fastcall SetSize(const int Value);
	void __fastcall SetStyle(const TFontStyles Value);
	void __fastcall SetWeight(const int Value);
	
public:
	__fastcall TFont(void)/* overload */;
	__fastcall TFont(Qt::QFontH* AHandle)/* overload */;
	__fastcall virtual ~TFont(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall OwnHandle(void);
	Qt::QFontH* __fastcall ReleaseHandle(void);
	__property Qt::QFontH* Handle = {read=FHandle, write=SetHandle};
	__property Qt::QPenH* FontPen = {read=FFontPen};
	__property int PixelsPerInch = {read=FPixelsPerInch, write=FPixelsPerInch, nodefault};
	
__published:
	__property TFontCharSet CharSet = {read=FCharSet, write=SetCharSet, default=23};
	__property TColor Color = {read=FColor, write=SetColor, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property AnsiString Name = {read=GetName, write=SetName};
	__property TFontPitch Pitch = {read=GetPitch, write=SetPitch, default=0};
	__property int Size = {read=GetSize, write=SetSize, stored=false, nodefault};
	__property TFontStyles Style = {read=GetStyle, write=SetStyle, nodefault};
	__property int Weight = {read=GetWeight, write=SetWeight, stored=IsWeightStored, nodefault};
};


#pragma option push -b-
enum TPenStyle { psSolid, psDash, psDot, psDashDot, psDashDotDot, psClear };
#pragma option pop

#pragma option push -b-
enum TPenMode { pmBlack, pmWhite, pmNop, pmNot, pmCopy, pmNotCopy, pmMergePenNot, pmMaskPenNot, pmMergeNotPen, pmMaskNotPen, pmMerge, pmNotMerge, pmMask, pmNotMask, pmXor, pmNotXor };
#pragma option pop

class DELPHICLASS TPen;
class PASCALIMPLEMENTATION TPen : public TGraphicsObject 
{
	typedef TGraphicsObject inherited;
	
private:
	Qt::QPenH* FHandle;
	TColor FColor;
	TPenMode FMode;
	bool FOwned;
	TPenStyle __fastcall GetStyle(void);
	int __fastcall GetWidth(void);
	void __fastcall SetColor(const TColor Value);
	void __fastcall SetHandle(const Qt::QPenH* Value);
	void __fastcall SetMode(const TPenMode Value);
	void __fastcall SetStyle(const TPenStyle Value);
	void __fastcall SetWidth(const int Value);
	void __fastcall FreeHandle(void);
	
public:
	__fastcall TPen(void)/* overload */;
	__fastcall TPen(Qt::QPenH* AHandle)/* overload */;
	__fastcall virtual ~TPen(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall OwnHandle(void);
	Qt::QPenH* __fastcall ReleaseHandle(void);
	__property Qt::QPenH* Handle = {read=FHandle, write=SetHandle};
	
__published:
	__property TColor Color = {read=FColor, write=SetColor, default=0};
	__property TPenMode Mode = {read=FMode, write=SetMode, default=4};
	__property TPenStyle Style = {read=GetStyle, write=SetStyle, default=0};
	__property int Width = {read=GetWidth, write=SetWidth, default=1};
};


#pragma option push -b-
enum TBrushStyle { bsSolid, bsClear, bsHorizontal, bsVertical, bsFDiagonal, bsBDiagonal, bsCross, bsDiagCross, bsDense1, bsDense2, bsDense3, bsDense4, bsDense5, bsDense6, bsDense7 };
#pragma option pop

class DELPHICLASS TBrush;
class DELPHICLASS TBitmap;
class DELPHICLASS TGraphic;
#pragma option push -b-
enum TProgressStage { psStarting, psRunning, psEnding };
#pragma option pop

typedef void __fastcall (__closure *TProgressEvent)(System::TObject* Sender, TProgressStage Stage, Byte PercentDone, bool RedrawNow, const Types::TRect &R, const WideString Msg);

class DELPHICLASS TCanvas;
typedef TMetaClass*TGraphicClass;

class PASCALIMPLEMENTATION TGraphic : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	Classes::TNotifyEvent FOnChange;
	TProgressEvent FOnProgress;
	bool FModified;
	bool FTransparent;
	void __fastcall SetModified(bool Value);
	
protected:
	__fastcall virtual TGraphic(void);
	virtual void __fastcall Changed(System::TObject* Sender);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall Draw(TCanvas* ACanvas, const Types::TRect &Rect) = 0 ;
	virtual bool __fastcall Equals(TGraphic* Graphic);
	virtual bool __fastcall GetEmpty(void) = 0 ;
	virtual int __fastcall GetHeight(void) = 0 ;
	virtual bool __fastcall GetTransparent(void);
	virtual int __fastcall GetWidth(void) = 0 ;
	DYNAMIC void __fastcall Progress(System::TObject* Sender, TProgressStage Stage, Byte PercentDone, bool RedrawNow, const Types::TRect &R, const WideString Msg);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	virtual void __fastcall SetHeight(int Value) = 0 ;
	virtual void __fastcall SetTransparent(bool Value);
	virtual void __fastcall SetWidth(int Value) = 0 ;
	virtual void __fastcall TiledDraw(TCanvas* ACanvas, const Types::TRect &Rect);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	
public:
	/* virtual class method */ virtual bool __fastcall Assigns(TMetaClass* vmt, TMetaClass* Source);
	/* virtual class method */ virtual bool __fastcall AssignsTo(TMetaClass* vmt, TMetaClass* Dest);
	virtual void __fastcall LoadFromMimeSource(Qtypes::TMimeSource* MimeSource) = 0 ;
	virtual void __fastcall SaveToMimeSource(Qtypes::TClxMimeSource* MimeSource) = 0 ;
	virtual void __fastcall LoadFromFile(const AnsiString Filename);
	virtual void __fastcall SaveToFile(const AnsiString Filename);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream) = 0 ;
	virtual void __fastcall SaveToStream(Classes::TStream* Stream) = 0 ;
	void __fastcall LoadFrom(const AnsiString Filename)/* overload */;
	void __fastcall LoadFrom(Classes::TStream* Stream)/* overload */;
	void __fastcall SaveTo(const AnsiString Filename)/* overload */;
	void __fastcall SaveTo(Classes::TStream* Stream)/* overload */;
	__property bool Empty = {read=GetEmpty, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property bool Modified = {read=FModified, write=SetModified, nodefault};
	__property bool Transparent = {read=GetTransparent, write=SetTransparent, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
public:
	#pragma option push -w-inl
	/* TPersistent.Destroy */ inline __fastcall virtual ~TGraphic(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TPixelFormat { pf1bit, pf8bit, pf16bit, pf32bit, pfCustom };
#pragma option pop

#pragma option push -b-
enum TTransparentMode { tmAuto, tmFixed };
#pragma option pop

class PASCALIMPLEMENTATION TBitmap : public TGraphic 
{
	typedef TGraphic inherited;
	
private:
	Qt::QImageH* FImage;
	Qt::QPixmapH* FPixmap;
	TCanvas* FCanvas;
	Classes::TStream* FStream;
	int FHeight;
	int FWidth;
	TPixelFormat FPixelFormat;
	AnsiString FFormat;
	TColor FTransparentColor;
	TTransparentMode FTransparentMode;
	void __fastcall Changing(System::TObject* Sender);
	TCanvas* __fastcall GetCanvas(void);
	Qt::QPixmapH* __fastcall GetHandle(void);
	bool __fastcall GetMonochrome(void);
	void __fastcall ResizeImage(int NewWidth, int NewHeight);
	void __fastcall SetMonochrome(const bool Value);
	void __fastcall SetHandle(const Qt::QPixmapH* Value);
	TColor __fastcall GetTransparentColor(void);
	void __fastcall SetTransparentColor(const TColor Value);
	void __fastcall SetTransparentMode(const TTransparentMode Value);
	bool __fastcall TransparentColorStored(void);
	void * __fastcall GetScanLine(int Row);
	TPixelFormat __fastcall GetPixelFormat(void);
	void __fastcall SetPixelFormat(const TPixelFormat Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall Draw(TCanvas* ACanvas, const Types::TRect &Rect);
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual bool __fastcall GetTransparent(void);
	virtual int __fastcall GetWidth(void);
	void __fastcall ImageNeeded(void);
	void __fastcall HandleNeeded(void);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetTransparent(bool Value);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall TiledDraw(TCanvas* ACanvas, const Types::TRect &Rect);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	
public:
	__fastcall virtual TBitmap(void);
	__fastcall virtual ~TBitmap(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/* virtual class method */ virtual bool __fastcall AssignsTo(TMetaClass* vmt, TMetaClass* Dest);
	void * __fastcall ColorTable(void);
	void __fastcall Dormant(void);
	void __fastcall FreeImage(void);
	void __fastcall FreePixmap(void);
	Qt::QPixmapH* __fastcall ReleasePixmap(void);
	virtual void __fastcall LoadFromMimeSource(Qtypes::TMimeSource* MimeSource);
	virtual void __fastcall SaveToMimeSource(Qtypes::TClxMimeSource* MimeSource);
	void __fastcall LoadFromResourceName(unsigned Instance, const AnsiString ResName);
	void __fastcall LoadFromResourceID(unsigned Instance, int ResID);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall Mask(TColor TransparentColor);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	__property TCanvas* Canvas = {read=GetCanvas};
	__property AnsiString Format = {read=FFormat, write=FFormat};
	__property Qt::QPixmapH* Handle = {read=GetHandle, write=SetHandle};
	__property bool Monochrome = {read=GetMonochrome, write=SetMonochrome, nodefault};
	__property TPixelFormat PixelFormat = {read=GetPixelFormat, write=SetPixelFormat, nodefault};
	__property void * ScanLine[int Row] = {read=GetScanLine};
	__property TColor TransparentColor = {read=GetTransparentColor, write=SetTransparentColor, stored=TransparentColorStored, nodefault};
	__property TTransparentMode TransparentMode = {read=FTransparentMode, write=SetTransparentMode, default=0};
};


class PASCALIMPLEMENTATION TBrush : public TGraphicsObject 
{
	typedef TGraphicsObject inherited;
	
private:
	Qt::QBrushH* FHandle;
	bool FOwned;
	TBitmap* FBitmap;
	TColor FColor;
	void __fastcall FreeHandle(void);
	TBrushStyle __fastcall GetStyle(void);
	void __fastcall SetBitmap(const TBitmap* Value);
	TBitmap* __fastcall GetBitmap(void);
	void __fastcall SetColor(const TColor Value);
	void __fastcall SetHandle(const Qt::QBrushH* Value);
	void __fastcall SetStyle(const TBrushStyle Value);
	
protected:
	virtual void __fastcall BitmapChanged(System::TObject* Sender);
	
public:
	__fastcall TBrush(void)/* overload */;
	__fastcall TBrush(Qt::QBrushH* AHandle)/* overload */;
	__fastcall virtual ~TBrush(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	void __fastcall OwnHandle(void);
	Qt::QBrushH* __fastcall ReleaseHandle(void);
	__property TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property Qt::QBrushH* Handle = {read=FHandle, write=SetHandle};
	
__published:
	__property TColor Color = {read=FColor, write=SetColor, default=16777215};
	__property TBrushStyle Style = {read=GetStyle, write=SetStyle, default=0};
};


class DELPHICLASS TFontRecall;
class PASCALIMPLEMENTATION TFontRecall : public Classes::TRecall 
{
	typedef Classes::TRecall inherited;
	
public:
	__fastcall TFontRecall(TFont* AFont);
public:
	#pragma option push -w-inl
	/* TRecall.Destroy */ inline __fastcall virtual ~TFontRecall(void) { }
	#pragma option pop
	
};


class DELPHICLASS TPenRecall;
class PASCALIMPLEMENTATION TPenRecall : public Classes::TRecall 
{
	typedef Classes::TRecall inherited;
	
public:
	__fastcall TPenRecall(TPen* APen);
public:
	#pragma option push -w-inl
	/* TRecall.Destroy */ inline __fastcall virtual ~TPenRecall(void) { }
	#pragma option pop
	
};


class DELPHICLASS TBrushRecall;
class PASCALIMPLEMENTATION TBrushRecall : public Classes::TRecall 
{
	typedef Classes::TRecall inherited;
	
public:
	__fastcall TBrushRecall(TBrush* ABrush);
public:
	#pragma option push -w-inl
	/* TRecall.Destroy */ inline __fastcall virtual ~TBrushRecall(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TCopyMode { cmBlackness, cmDstInvert, cmMergeCopy, cmMergePaint, cmNotSrcCopy, cmNotSrcErase, cmPatCopy, cmPatInvert, cmPatPaint, cmSrcAnd, cmSrcCopy, cmSrcErase, cmSrcInvert, cmSrcPaint, cmWhiteness, cmCreateMask };
#pragma option pop

#pragma option push -b-
enum TCanvasStates { csHandleValid, csFontValid, csPenValid, csBrushValid };
#pragma option pop

typedef Set<TCanvasStates, csHandleValid, csBrushValid>  TCanvasState;

#pragma option push -b-
enum TTextAlign { taTop, taBottom };
#pragma option pop

class PASCALIMPLEMENTATION TCanvas : public Classes::TPersistent 
{
	typedef Classes::TPersistent inherited;
	
private:
	int FLockCount;
	int FStartCount;
	TFont* FFont;
	TPen* FPen;
	TBrush* FBrush;
	TCanvasState State;
	TTextAlign FTextAlign;
	#pragma pack(push, 1)
	Types::TPoint FPenPos;
	#pragma pack(pop)
	
	_RTL_CRITICAL_SECTION FLock;
	TCopyMode FCopyMode;
	Classes::TNotifyEvent FOnChange;
	Classes::TNotifyEvent FOnChanging;
	Qt::QRegionH* FClipRegion;
	bool FNeedsEnd;
	void __fastcall BrushChanged(System::TObject* Sender);
	void __fastcall CreateBrush(void);
	void __fastcall CreateFont(void);
	void __fastcall CreatePen(void);
	void __fastcall FontChanged(System::TObject* Sender);
	Types::TRect __fastcall GetClipRect();
	Qt::QPainterH* __fastcall GetHandle(void);
	Types::TPoint __fastcall GetPenPos();
	void __fastcall PenChanged(System::TObject* Sender);
	void __fastcall SetBrush(const TBrush* Value);
	void __fastcall SetFont(const TFont* Value);
	void __fastcall SetHandle(const Qt::QPainterH* Value);
	void __fastcall SetPen(const TPen* Value);
	void __fastcall SetPenPos(const Types::TPoint &Value);
	
protected:
	Qt::QPainterH* FHandle;
	virtual void __fastcall BeginPainting(void);
	virtual void __fastcall Changing(void);
	virtual void __fastcall Changed(void);
	virtual void __fastcall CreateHandle(void);
	void __fastcall RequiredState(TCanvasState ReqState);
	
public:
	__fastcall TCanvas(void);
	__fastcall virtual ~TCanvas(void);
	void __fastcall Arc(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)/* overload */;
	void __fastcall Arc(int X, int Y, int W, int H, int Angle, int AngleLength)/* overload */;
	void __fastcall Chord(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)/* overload */;
	void __fastcall Chord(int X, int Y, int W, int H, int Angle, int AngleLength)/* overload */;
	void __fastcall CopyRect(const Types::TRect &Dest, TCanvas* Canvas, const Types::TRect &Source);
	void __fastcall Draw(int X, int Y, TGraphic* Graphic);
	void __fastcall DrawFocusRect(const Types::TRect &Rect);
	void __fastcall DrawPoint(int X, int Y)/* overload */;
	void __fastcall DrawPoint(const Types::TPoint &Point)/* overload */;
	void __fastcall DrawPoints(const Types::TPoint * Points, const int Points_Size);
	void __fastcall Ellipse(int X1, int Y1, int X2, int Y2)/* overload */;
	void __fastcall Ellipse(const Types::TRect &Rect)/* overload */;
	void __fastcall FillRect(const Types::TRect &Rect);
	Qt::QRegionH* __fastcall GetClipRegion(void);
	void __fastcall LineTo(int X, int Y);
	void __fastcall Lock(void);
	void __fastcall MoveTo(int X, int Y);
	void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)/* overload */;
	void __fastcall Pie(int X, int Y, int W, int H, int Angle, int AngleLength)/* overload */;
	void __fastcall Polygon(const Types::TPoint * Points, const int Points_Size, bool Winding = false, int StartIndex = 0x0, int NumPts = 0xffffffff);
	void __fastcall Polyline(const Types::TPoint * Points, const int Points_Size, int StartIndex = 0x0, int NumPts = 0xffffffff);
	void __fastcall PolyBezier(const Types::TPoint * Points, const int Points_Size, int StartIndex = 0x0);
	void __fastcall PolyBezierTo(const Types::TPoint * Points, const int Points_Size, int StartIndex = 0x0);
	void __fastcall Rectangle(int X1, int Y1, int X2, int Y2)/* overload */;
	void __fastcall Rectangle(const Types::TRect &Rect)/* overload */;
	void __fastcall Refresh(void);
	Qt::QPainterH* __fastcall ReleaseHandle(void);
	void __fastcall ResetClipRegion(void);
	void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3);
	void __fastcall SetClipRect(const Types::TRect &ARect);
	void __fastcall Start(bool FreshState = true);
	void __fastcall Stop(void);
	void __fastcall StretchDraw(const Types::TRect &Rect, TGraphic* Graphic);
	void __fastcall TextExtent(const WideString Text, Types::TRect &Rect, const int Flags = 0x0)/* overload */;
	tagSIZE __fastcall TextExtent(const WideString Text, const int Flags = 0x0)/* overload */;
	int __fastcall TextHeight(const WideString Text);
	void __fastcall TextOut(int X, int Y, const WideString Text);
	void __fastcall TextRect(const Types::TRect &Rect, int X, int Y, const WideString Text, int TextFlags = 0x0);
	int __fastcall TextWidth(const WideString Text);
	void __fastcall TiledDraw(const Types::TRect &Rect, TGraphic* Graphic);
	bool __fastcall TryLock(void);
	void __fastcall Unlock(void);
	__property Types::TRect ClipRect = {read=GetClipRect};
	__property Qt::QPainterH* Handle = {read=GetHandle, write=SetHandle};
	__property int LockCount = {read=FLockCount, nodefault};
	__property Types::TPoint PenPos = {read=GetPenPos, write=SetPenPos};
	__property int StartCount = {read=FStartCount, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Classes::TNotifyEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	
__published:
	__property TBrush* Brush = {read=FBrush, write=SetBrush};
	__property TCopyMode CopyMode = {read=FCopyMode, write=FCopyMode, default=10};
	__property TFont* Font = {read=FFont, write=SetFont};
	__property TPen* Pen = {read=FPen, write=SetPen};
	__property TTextAlign TextAlign = {read=FTextAlign, write=FTextAlign, default=0};
};


class DELPHICLASS TPicture;
class DELPHICLASS TIcon;
class PASCALIMPLEMENTATION TPicture : public Classes::TInterfacedPersistent 
{
	typedef Classes::TInterfacedPersistent inherited;
	
private:
	TGraphic* FGraphic;
	Classes::TNotifyEvent FOnChange;
	TProgressEvent FOnProgress;
	void __fastcall ForceType(TMetaClass* GraphicType);
	TBitmap* __fastcall GetBitmap(void);
	int __fastcall GetHeight(void);
	TIcon* __fastcall GetIcon(void);
	int __fastcall GetWidth(void);
	void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall SetBitmap(TBitmap* Value);
	void __fastcall SetGraphic(TGraphic* Value);
	void __fastcall SetIcon(TIcon* Value);
	void __fastcall WriteData(Classes::TStream* Stream);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	DYNAMIC void __fastcall Changed(System::TObject* Sender);
	DYNAMIC void __fastcall Progress(System::TObject* Sender, TProgressStage Stage, Byte PercentDone, bool RedrawNow, const Types::TRect &R, const WideString Msg);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	
public:
	__fastcall TPicture(void);
	__fastcall virtual ~TPicture(void);
	void __fastcall LoadFromMimeSource(Qtypes::TMimeSource* MimeSource);
	void __fastcall SaveToMimeSource(Qtypes::TClxMimeSource* MimeSource);
	void __fastcall LoadFromFile(const AnsiString Filename);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall SaveToFile(const AnsiString Filename);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	/*         class method */ static void __fastcall RegisterFileFormat(TMetaClass* vmt, const AnsiString AExtension, const AnsiString ADescription, TMetaClass* AGraphicClass);
	/*         class method */ static void __fastcall RegisterFileFormatRes(TMetaClass* vmt, const AnsiString AExtension, int ADescriptionResID, TMetaClass* AGraphicClass);
	/*         class method */ static void __fastcall UnregisterGraphicClass(TMetaClass* vmt, TMetaClass* AClass);
	__property TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property TGraphic* Graphic = {read=FGraphic, write=SetGraphic};
	__property int Height = {read=GetHeight, nodefault};
	__property TIcon* Icon = {read=GetIcon, write=SetIcon};
	__property int Width = {read=GetWidth, nodefault};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property TProgressEvent OnProgress = {read=FOnProgress, write=FOnProgress};
private:
	void *__IStreamPersist;	/* Classes::IStreamPersist */
	
public:
	operator IStreamPersist*(void) { return (IStreamPersist*)&__IStreamPersist; }
	
};


#pragma pack(push, 1)
struct TBitmapFileHeader
{
	Word bfType;
	unsigned bfSize;
	Word bfReserved1;
	Word bfReserved2;
	unsigned bfOffBits;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TBitmapInfoHeader
{
	unsigned biSize;
	int biWidth;
	int biHeight;
	Word biPlanes;
	Word biBitCount;
	unsigned biCompression;
	unsigned biSizeImage;
	int biXPelsPerMeter;
	int biYPelsPerMeter;
	unsigned biClrUsed;
	unsigned biClrImportant;
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct TIconDirEntry
{
	Byte bWidth;
	Byte bHeight;
	Byte bColorCount;
	Byte bReserved;
	Word wPlanes;
	Word wBitCount;
	unsigned dwBytesInRes;
	unsigned dwImageOffset;
} ;
#pragma pack(pop)

class DELPHICLASS TBitmapCanvas;
class PASCALIMPLEMENTATION TBitmapCanvas : public TCanvas 
{
	typedef TCanvas inherited;
	
private:
	TBitmap* FBitmap;
	
protected:
	virtual void __fastcall BeginPainting(void);
	virtual void __fastcall CreateHandle(void);
	
public:
	__fastcall TBitmapCanvas(TBitmap* Bitmap);
public:
	#pragma option push -w-inl
	/* TCanvas.Destroy */ inline __fastcall virtual ~TBitmapCanvas(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TIcon : public TGraphic 
{
	typedef TGraphic inherited;
	
private:
	TBitmap* FBitmap;
	Classes::TMemoryStream* FMemoryImage;
	#pragma pack(push, 1)
	Types::TPoint FRequestedSize;
	#pragma pack(pop)
	
	void __fastcall NewImage(void);
	Qt::QPixmapH* __fastcall GetHandle(void);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall Draw(TCanvas* ACanvas, const Types::TRect &Rect);
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
	/* virtual class method */ virtual bool __fastcall AssignsTo(TMetaClass* vmt, TMetaClass* Dest);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromMimeSource(Qtypes::TMimeSource* MimeSource);
	void __fastcall LoadFromResourceName(unsigned Instance, const AnsiString ResName);
	virtual void __fastcall SaveToMimeSource(Qtypes::TClxMimeSource* MimeSource);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	__property Qt::QPixmapH* Handle = {read=GetHandle};
};


class DELPHICLASS TDrawing;
class PASCALIMPLEMENTATION TDrawing : public TGraphic 
{
	typedef TGraphic inherited;
	
private:
	Qt::QPictureH* FHandle;
	int FWidth;
	int FHeight;
	TCanvas* FCanvas;
	TCanvas* __fastcall GetCanvas(void);
	
protected:
	virtual void __fastcall Draw(TCanvas* ACanvas, const Types::TRect &Rect);
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual int __fastcall GetWidth(void);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	
public:
	__fastcall virtual TDrawing(void);
	__fastcall virtual ~TDrawing(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall LoadFromMimeSource(Qtypes::TMimeSource* MimeSource);
	virtual void __fastcall SaveToMimeSource(Qtypes::TClxMimeSource* MimeSource);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	__property Qt::QPictureH* Handle = {read=FHandle};
	__property TCanvas* Canvas = {read=GetCanvas};
};


class DELPHICLASS TDrawingCanvas;
class PASCALIMPLEMENTATION TDrawingCanvas : public TCanvas 
{
	typedef TCanvas inherited;
	
private:
	TDrawing* FDrawing;
	
protected:
	virtual void __fastcall BeginPainting(void);
	virtual void __fastcall CreateHandle(void);
	
public:
	__fastcall TDrawingCanvas(TDrawing* Drawing);
public:
	#pragma option push -w-inl
	/* TCanvas.Destroy */ inline __fastcall virtual ~TDrawingCanvas(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TColorGroup { cgInactive, cgDisabled, cgActive };
#pragma option pop

#pragma option push -b-
enum TColorRole { crForeground, crButton, crLight, crMidlight, crDark, crMid, crText, crBrightText, crButtonText, crBase, crBackground, crShadow, crHighlight, crHighlightText, crNoRole };
#pragma option pop

class DELPHICLASS TPalette;
class PASCALIMPLEMENTATION TPalette : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Qt::QPaletteH* FHandle;
	TColor FBaseColor;
	Qt::QColorGroupH* FInactiveColors;
	Qt::QColorGroupH* FActiveColors;
	Qt::QColorGroupH* FDisabledColors;
	Classes::TNotifyEvent FOnChange;
	bool FOwned;
	int FUpdateCount;
	void __fastcall SetBaseColor(const TColor Value);
	Qt::QPaletteH* __fastcall GetHandle(void);
	void __fastcall SetBrush(TColorGroup Group, TColorRole Role, TColor Color, Qt::QPixmapH* Pixmap);
	void __fastcall SetOwned(const bool Value);
	void __fastcall SetHandle(const Qt::QPaletteH* Value);
	
protected:
	virtual void __fastcall Changed(void);
	void __fastcall CreatePalette(void);
	
public:
	__fastcall virtual TPalette(void);
	__fastcall virtual ~TPalette(void);
	void __fastcall BeginUpdate(void);
	Qt::QPixmapH* __fastcall GetBrushPixmap(TColorGroup Group, TColorRole Role);
	TColor __fastcall GetColor(TColorGroup Group, TColorRole Role)/* overload */;
	TColor __fastcall GetColor(TMappedColor MappedColor)/* overload */;
	Qt::QColorGroupH* __fastcall ColorGroup(TColorGroup Group);
	void __fastcall EndUpdate(void);
	void __fastcall SetBitmap(TColorGroup Group, TColorRole Role, TBitmap* Bitmap);
	void __fastcall SetColor(TColorGroup Group, TColorRole Role, TColor Color);
	__property TColor BaseColor = {read=FBaseColor, write=SetBaseColor, nodefault};
	__property bool Owned = {read=FOwned, write=SetOwned, nodefault};
	__property Qt::QPaletteH* Handle = {read=GetHandle, write=SetHandle};
	__property Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
};


class DELPHICLASS TWidgetPalette;
class PASCALIMPLEMENTATION TWidgetPalette : public TPalette 
{
	typedef TPalette inherited;
	
private:
	TColorRole FColorRole;
	TColorRole FTextColorRole;
	TBitmap* FBitmap;
	TColor __fastcall GetWidgetColor(void);
	TColor __fastcall GetWidgetTextColor(void);
	void __fastcall SetWidgetBitmap(const TBitmap* Value);
	void __fastcall SetWidgetColor(const TColor Value);
	void __fastcall SetWidgetTextColor(const TColor Value);
	TBitmap* __fastcall GetWidgetBitmap(void);
	
protected:
	virtual void __fastcall BitmapChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TWidgetPalette(void);
	__fastcall virtual ~TWidgetPalette(void);
	bool __fastcall IsBitmapEmpty(void);
	__property TColorRole ColorRole = {read=FColorRole, write=FColorRole, nodefault};
	__property TColorRole TextColorRole = {read=FTextColorRole, write=FTextColorRole, nodefault};
	__property TBitmap* Bitmap = {read=GetWidgetBitmap, write=SetWidgetBitmap};
	__property TColor Color = {read=GetWidgetColor, write=SetWidgetColor, nodefault};
	__property TColor TextColor = {read=GetWidgetTextColor, write=SetWidgetTextColor, nodefault};
};


#pragma option push -b-
enum TEdgeBorder { ebLeft, ebTop, ebRight, ebBottom };
#pragma option pop

typedef Set<TEdgeBorder, ebLeft, ebBottom>  TEdgeBorders;

#pragma option push -b-
enum TEdgeStyle { esNone, esRaised, esLowered };
#pragma option pop

//-- var, const, procedure ---------------------------------------------------
static const Shortint Version = 0x1;
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
static const TColor clForeground = 0xffffffff;
static const TColor clButton = 0xfffffffe;
static const TColor clLight = 0xfffffffd;
static const TColor clMidlight = 0xfffffffc;
static const TColor clDark = 0xfffffffb;
static const TColor clMid = 0xfffffffa;
static const TColor clText = 0xfffffff9;
static const TColor clBrightText = 0xfffffff8;
static const TColor clButtonText = 0xfffffff7;
static const TColor clBase = 0xfffffff6;
static const TColor clBackground = 0xfffffff5;
static const TColor clShadow = 0xfffffff4;
static const TColor clHighlight = 0xfffffff3;
static const TColor clHighlightedText = 0xfffffff2;
static const Shortint cloNormal = 0x20;
static const Shortint cloDisabled = 0x40;
static const Shortint cloActive = 0x60;
static const TColor clNormalForeground = 0xffffffdf;
static const TColor clNormalButton = 0xffffffde;
static const TColor clNormalLight = 0xffffffdd;
static const TColor clNormalMidlight = 0xffffffdc;
static const TColor clNormalDark = 0xffffffdb;
static const TColor clNormalMid = 0xffffffda;
static const TColor clNormalText = 0xffffffd9;
static const TColor clNormalBrightText = 0xffffffd8;
static const TColor clNormalButtonText = 0xffffffd7;
static const TColor clNormalBase = 0xffffffd6;
static const TColor clNormalBackground = 0xffffffd5;
static const TColor clNormalShadow = 0xffffffd4;
static const TColor clNormalHighlight = 0xffffffd3;
static const TColor clNormalHighlightedText = 0xffffffd2;
static const TColor clDisabledForeground = 0xffffffbf;
static const TColor clDisabledButton = 0xffffffbe;
static const TColor clDisabledLight = 0xffffffbd;
static const TColor clDisabledMidlight = 0xffffffbc;
static const TColor clDisabledDark = 0xffffffbb;
static const TColor clDisabledMid = 0xffffffba;
static const TColor clDisabledText = 0xffffffb9;
static const TColor clDisabledBrightText = 0xffffffb8;
static const TColor clDisabledButtonText = 0xffffffb7;
static const TColor clDisabledBase = 0xffffffb6;
static const TColor clDisabledBackground = 0xffffffb5;
static const TColor clDisabledShadow = 0xffffffb4;
static const TColor clDisabledHighlight = 0xffffffb3;
static const TColor clDisabledHighlightedText = 0xffffffb2;
static const TColor clActiveForeground = 0xffffff9f;
static const TColor clActiveButton = 0xffffff9e;
static const TColor clActiveLight = 0xffffff9d;
static const TColor clActiveMidlight = 0xffffff9c;
static const TColor clActiveDark = 0xffffff9b;
static const TColor clActiveMid = 0xffffff9a;
static const TColor clActiveText = 0xffffff99;
static const TColor clActiveBrightText = 0xffffff98;
static const TColor clActiveButtonText = 0xffffff97;
static const TColor clActiveBase = 0xffffff96;
static const TColor clActiveBackground = 0xffffff95;
static const TColor clActiveShadow = 0xffffff94;
static const TColor clActiveHighlight = 0xffffff93;
static const TColor clActiveHighlightedText = 0xffffff92;
static const TColor clFirstSpecialColor = 0xffffff92;
static const TColor clScrollBar = 0xfffffffe;
static const TColor clActiveCaption = 0xffffff92;
static const TColor clInactiveCaption = 0xffffffb2;
static const TColor clMenu = 0xfffffffa;
static const TColor clWindow = 0xfffffff6;
static const TColor clWindowFrame = 0xfffffff3;
static const TColor clMenuText = 0xfffffff7;
static const TColor clWindowText = 0xfffffff9;
static const TColor clCaptionText = 0xfffffff2;
static const TColor clActiveBorder = 0xffffff93;
static const TColor clInactiveBorder = 0xffffffb3;
static const TColor clAppWorkSpace = 0xfffffffa;
static const TColor clBtnFace = 0xfffffffe;
static const TColor clBtnShadow = 0xfffffffb;
static const TColor clGrayText = 0xfffffffd;
static const TColor clBtnText = 0xfffffff7;
static const TColor clInactiveCaptionText = 0xffffffb2;
static const TColor clBtnHighlight = 0xffffff9d;
static const TColor cl3DDkShadow = 0xfffffffa;
static const TColor cl3DLight = 0xfffffffc;
static const TColor clInfoText = 0xfffffff9;
static const TColor clInfoBk = 0xe1ffff;
static const TColor clHighlightText = 0xfffffff2;
static const TColor clMask = 0xffffff;
static const TColor clDontMask = 0x0;
static const Shortint DrawStage_Pre = 0x0;
static const Shortint DrawStage_Post = 0x1;
static const Shortint DrawStage_DefaultDraw = 0x2;
#define fcsISO_8859_1 (TFontCharSet)(0)
#define fcsISO_8859_2 (TFontCharSet)(2)
#define fcsISO_8859_3 (TFontCharSet)(3)
#define fcsISO_8859_4 (TFontCharSet)(4)
#define fcsISO_8859_9 (TFontCharSet)(9)
#define fcsISO_8859_10 (TFontCharSet)(10)
#define fcsISO_8859_13 (TFontCharSet)(13)
#define fcsISO_8859_14 (TFontCharSet)(14)
#define fcsISO_8859_15 (TFontCharSet)(15)
#define fcsSet_1 (TFontCharSet)(17)
#define fcsSet_N (TFontCharSet)(21)
static const Shortint fwLight = 0x19;
static const Shortint fwNormal = 0x32;
static const Shortint fwDemiBold = 0x3f;
static const Shortint fwBold = 0x4b;
static const Shortint fwBlack = 0x57;
#define fhSanSerif (TFontHint)(0)
#define fhSerif (TFontHint)(1)
#define fhTypeWriter (TFontHint)(2)
#define fhDecorative (TFontHint)(3)
#define ebRect (System::Set<TEdgeBorder, ebLeft, ebBottom> () << TEdgeBorder(0) << TEdgeBorder(1) << TEdgeBorder(2) << TEdgeBorder(3) )
extern PACKAGE bool ExactBitmaps;
extern PACKAGE int __fastcall ColorToRGB(TColor Color);
extern PACKAGE Qt::QColorGroupColorRole __fastcall ColorRole(TColor Color);
extern PACKAGE Qt::QPaletteColorGroup __fastcall ColorGroup(TColor Color);
extern PACKAGE Qt::QBrushH* __fastcall GetEmptyQBrush(void);
extern PACKAGE Qt::QPenH* __fastcall GetEmptyQPen(void);
extern PACKAGE Qt::QFontH* __fastcall GetEmptyQFont(void);
extern PACKAGE Qt::QColorH* __fastcall QColor(TColor Color, Qt::QWidgetH* Widget = (Qt::QWidgetH*)(0x0));
extern PACKAGE TColor __fastcall QColorColor(Qt::QColorH* Color);
extern PACKAGE void __fastcall GetColorValues(Classes::TGetStrProc Proc);
extern PACKAGE bool __fastcall ColorToIdent(int Color, AnsiString &Ident);
extern PACKAGE bool __fastcall IdentToColor(const AnsiString Ident, int &Color);
extern PACKAGE AnsiString __fastcall ColorToString(TColor Color);
extern PACKAGE TColor __fastcall StringToColor(const AnsiString S);
extern PACKAGE void __fastcall InflateRect(Types::TRect &ARect, int X, int Y);
extern PACKAGE void __fastcall OffsetRect(Types::TRect &ARect, int X, int Y);
extern PACKAGE void __fastcall DrawEdge(TCanvas* Canvas, const Types::TRect &R, TEdgeStyle EdgeInner, TEdgeStyle EdgeOuter, TEdgeBorders EdgeBorders);
extern PACKAGE void __fastcall DrawItem(TCanvas* Canvas, int x, int y, int w, int h, int Flags, bool Enabled, const WideString Text, int Length = 0xffffffff, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0), TBitmap* Bitmap = (TBitmap*)(0x0));
extern PACKAGE void __fastcall DrawShadeLine(TCanvas* Canvas, int x1, int y1, int x2, int y2, bool Sunken, int LineWidth, int MidLineWidth, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawShadeRect(TCanvas* Canvas, int x, int y, int w, int h, bool Sunken, int LineWidth, int MidLineWidth, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawShadeRect(TCanvas* Canvas, const Types::TRect &Rect, bool Sunken, int LineWidth, int MidLineWidth, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawShadePanel(TCanvas* Canvas, int x, int y, int w, int h, bool Sunken, int LineWidth, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawShadePanel(TCanvas* Canvas, const Types::TRect &Rect, bool Sunken, int LineWidth, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawWinButton(TCanvas* Canvas, int x, int y, int w, int h, bool Sunken, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawWinButton(TCanvas* Canvas, const Types::TRect &Rect, bool Sunken, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawWinPanel(TCanvas* Canvas, int x, int y, int w, int h, bool Sunken, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawWinPanel(TCanvas* Canvas, const Types::TRect &Rect, bool Sunken, Qt::QColorGroupH* ColorGroup = (Qt::QColorGroupH*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawPlainRect(TCanvas* Canvas, int x, int y, int w, int h, TColor Color, int LineWidth)/* overload */;
extern PACKAGE void __fastcall DrawPlainRect(TCanvas* Canvas, const Types::TRect &Rect, TColor Color, int LineWidth)/* overload */;
extern PACKAGE AnsiString __fastcall GraphicFilter(TMetaClass* GraphicClass, bool AllFilter = true);
extern PACKAGE AnsiString __fastcall GraphicExtension(TMetaClass* GraphicClass);
extern PACKAGE AnsiString __fastcall GraphicFileMask(TMetaClass* GraphicClass);
extern PACKAGE TBitmap* __fastcall AllocPatternBitmap(TColor BkColor, TColor FgColor);

}	/* namespace Qgraphics */
using namespace Qgraphics;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QGraphics
