// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'jpeg.pas' rev: 6.00

#ifndef jpegHPP
#define jpegHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#pragma link "jpeg.obj"

namespace Jpeg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TJPEGData;
class PASCALIMPLEMENTATION TJPEGData : public Graphics::TSharedImage 
{
	typedef Graphics::TSharedImage inherited;
	
private:
	Classes::TCustomMemoryStream* FData;
	int FHeight;
	int FWidth;
	bool FGrayscale;
	
protected:
	virtual void __fastcall FreeHandle(void);
	
public:
	__fastcall virtual ~TJPEGData(void);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TJPEGData(void) : Graphics::TSharedImage() { }
	#pragma option pop
	
};


typedef Shortint TJPEGQualityRange;

#pragma option push -b-
enum TJPEGPerformance { jpBestQuality, jpBestSpeed };
#pragma option pop

#pragma option push -b-
enum TJPEGScale { jsFullSize, jsHalf, jsQuarter, jsEighth };
#pragma option pop

#pragma option push -b-
enum TJPEGPixelFormat { jf24Bit, jf8Bit };
#pragma option pop

class DELPHICLASS TJPEGImage;
class PASCALIMPLEMENTATION TJPEGImage : public Graphics::TGraphic 
{
	typedef Graphics::TGraphic inherited;
	
private:
	TJPEGData* FImage;
	Graphics::TBitmap* FBitmap;
	int FScaledWidth;
	int FScaledHeight;
	HPALETTE FTempPal;
	bool FSmoothing;
	bool FGrayScale;
	TJPEGPixelFormat FPixelFormat;
	TJPEGQualityRange FQuality;
	bool FProgressiveDisplay;
	bool FProgressiveEncoding;
	TJPEGPerformance FPerformance;
	TJPEGScale FScale;
	bool FNeedRecalc;
	void __fastcall CalcOutputDimensions(void);
	Graphics::TBitmap* __fastcall GetBitmap(void);
	bool __fastcall GetGrayscale(void);
	void __fastcall SetGrayscale(bool Value);
	void __fastcall SetPerformance(TJPEGPerformance Value);
	void __fastcall SetPixelFormat(TJPEGPixelFormat Value);
	void __fastcall SetScale(TJPEGScale Value);
	void __fastcall SetSmoothing(bool Value);
	
protected:
	virtual void __fastcall AssignTo(Classes::TPersistent* Dest);
	virtual void __fastcall Changed(System::TObject* Sender);
	virtual void __fastcall Draw(Graphics::TCanvas* ACanvas, const Types::TRect &Rect);
	virtual bool __fastcall Equals(Graphics::TGraphic* Graphic);
	void __fastcall FreeBitmap(void);
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual HPALETTE __fastcall GetPalette(void);
	virtual int __fastcall GetWidth(void);
	void __fastcall NewBitmap(void);
	void __fastcall NewImage(void);
	virtual void __fastcall ReadData(Classes::TStream* Stream);
	void __fastcall ReadStream(int Size, Classes::TStream* Stream);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetPalette(HPALETTE Value);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall WriteData(Classes::TStream* Stream);
	__property Graphics::TBitmap* Bitmap = {read=GetBitmap};
	
public:
	__fastcall virtual TJPEGImage(void);
	__fastcall virtual ~TJPEGImage(void);
	void __fastcall Compress(void);
	void __fastcall DIBNeeded(void);
	void __fastcall JPEGNeeded(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	virtual void __fastcall LoadFromStream(Classes::TStream* Stream);
	virtual void __fastcall SaveToStream(Classes::TStream* Stream);
	virtual void __fastcall LoadFromClipboardFormat(Word AFormat, unsigned AData, HPALETTE APalette);
	virtual void __fastcall SaveToClipboardFormat(Word &AFormat, unsigned &AData, HPALETTE &APalette);
	__property bool Grayscale = {read=GetGrayscale, write=SetGrayscale, nodefault};
	__property bool ProgressiveEncoding = {read=FProgressiveEncoding, write=FProgressiveEncoding, nodefault};
	__property TJPEGQualityRange CompressionQuality = {read=FQuality, write=FQuality, nodefault};
	__property TJPEGPixelFormat PixelFormat = {read=FPixelFormat, write=SetPixelFormat, nodefault};
	__property bool ProgressiveDisplay = {read=FProgressiveDisplay, write=FProgressiveDisplay, nodefault};
	__property TJPEGPerformance Performance = {read=FPerformance, write=SetPerformance, nodefault};
	__property TJPEGScale Scale = {read=FScale, write=SetScale, nodefault};
	__property bool Smoothing = {read=FSmoothing, write=SetSmoothing, nodefault};
};


#pragma pack(push, 1)
struct TJPEGDefaults
{
	TJPEGQualityRange CompressionQuality;
	bool Grayscale;
	TJPEGPerformance Performance;
	TJPEGPixelFormat PixelFormat;
	bool ProgressiveDisplay;
	bool ProgressiveEncoding;
	TJPEGScale Scale;
	bool Smoothing;
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TJPEGDefaults JPEGDefaults;

}	/* namespace Jpeg */
using namespace Jpeg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// jpeg
