// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QRCtrls.pas' rev: 6.00

#ifndef QRCtrlsHPP
#define QRCtrlsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QRExpr.hpp>	// Pascal unit
#include <QR3Const.hpp>	// Pascal unit
#include <QuickRpt.hpp>	// Pascal unit
#include <QRPrntr.hpp>	// Pascal unit
#include <RichEdit.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <Printers.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qrctrls
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TQRLabelOnPrintEvent)(System::TObject* sender, AnsiString &Value);

class DELPHICLASS TQRCustomLabel;
class PASCALIMPLEMENTATION TQRCustomLabel : public Quickrpt::TQRPrintable 
{
	typedef Quickrpt::TQRPrintable inherited;
	
private:
	bool FCaptionBased;
	bool DoneFormat;
	bool FAutoSize;
	bool FAutoStretch;
	AnsiString FCaption;
	int FCurrentLine;
	AnsiString FPrintCaption;
	int FFontSize;
	Classes::TStrings* FFormattedLines;
	Classes::TStrings* FLines;
	TQRLabelOnPrintEvent FOnPrint;
	bool FWordWrap;
	bool UpdatingBounds;
	AnsiString __fastcall GetCaption();
	virtual bool __fastcall GetCaptionBased(void);
	void __fastcall SetAutoStretch(bool Value);
	void __fastcall SetCaption(AnsiString Value);
	void __fastcall SetLines(Classes::TStrings* Value);
	void __fastcall SetWordWrap(bool Value);
	void __fastcall PaintToCanvas(Graphics::TCanvas* aCanvas, const Types::TRect &aRect, bool CanExpand, int LineHeight);
	void __fastcall PrintToCanvas(Graphics::TCanvas* aCanvas, Extended aLeft, Extended aTop, Extended aWidth, Extended aHeight, Extended LineHeight, bool CanExpand);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Messages::TMessage &Message);
	
protected:
	virtual void __fastcall FormatLines(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetName(const AnsiString Value);
	virtual void __fastcall SetParent(Controls::TWinControl* AParent);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall ReadFontSize(Classes::TReader* Reader);
	virtual void __fastcall WriteFontSize(Classes::TWriter* Writer);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Prepare(void);
	virtual void __fastcall Unprepare(void);
	virtual void __fastcall Print(int OfsX, int OfsY);
	virtual void __fastcall SetAlignment(Classes::TAlignment Value);
	__property TQRLabelOnPrintEvent OnPrint = {read=FOnPrint, write=FOnPrint};
	
public:
	__fastcall virtual TQRCustomLabel(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRCustomLabel(void);
	DYNAMIC Classes::TAlignment __fastcall GetControlsAlignment(void);
	__property bool CaptionBased = {read=GetCaptionBased, nodefault};
	__property Alignment ;
	__property bool AutoSize = {read=FAutoSize, write=FAutoSize, nodefault};
	__property bool AutoStretch = {read=FAutoStretch, write=SetAutoStretch, nodefault};
	__property AnsiString Caption = {read=GetCaption, write=SetCaption, stored=true};
	__property Color  = {default=-2147483643};
	__property Font ;
	__property Classes::TStrings* Lines = {read=FLines, write=SetLines};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, nodefault};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRCustomLabel(HWND ParentWindow) : Quickrpt::TQRPrintable(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRLabel;
class PASCALIMPLEMENTATION TQRLabel : public TQRCustomLabel 
{
	typedef TQRCustomLabel inherited;
	
protected:
	virtual TMetaClass* __fastcall GetEditorClass(void);
	
__published:
	__property Alignment ;
	__property AlignToBand ;
	__property AutoSize ;
	__property AutoStretch ;
	__property BiDiMode ;
	__property ParentBiDiMode  = {default=1};
	__property Caption ;
	__property Color  = {default=-2147483643};
	__property Font ;
	__property OnPrint ;
	__property ParentFont  = {default=1};
	__property Transparent ;
	__property WordWrap ;
public:
	#pragma option push -w-inl
	/* TQRCustomLabel.Create */ inline __fastcall virtual TQRLabel(Classes::TComponent* AOwner) : TQRCustomLabel(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQRCustomLabel.Destroy */ inline __fastcall virtual ~TQRLabel(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRLabel(HWND ParentWindow) : TQRCustomLabel(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRMemo;
class PASCALIMPLEMENTATION TQRMemo : public TQRCustomLabel 
{
	typedef TQRCustomLabel inherited;
	
protected:
	virtual bool __fastcall GetCaptionBased(void);
	
public:
	virtual void __fastcall Paint(void);
	virtual void __fastcall Print(int OfsX, int OfsY);
	
__published:
	__property Alignment ;
	__property AlignToBand ;
	__property AutoSize ;
	__property AutoStretch ;
	__property BiDiMode ;
	__property ParentBiDiMode  = {default=1};
	__property Color  = {default=-2147483643};
	__property Font ;
	__property Lines ;
	__property ParentFont  = {default=1};
	__property Transparent ;
	__property WordWrap ;
public:
	#pragma option push -w-inl
	/* TQRCustomLabel.Create */ inline __fastcall virtual TQRMemo(Classes::TComponent* AOwner) : TQRCustomLabel(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQRCustomLabel.Destroy */ inline __fastcall virtual ~TQRMemo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRMemo(HWND ParentWindow) : TQRCustomLabel(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRDBText;
class PASCALIMPLEMENTATION TQRDBText : public TQRCustomLabel 
{
	typedef TQRCustomLabel inherited;
	
private:
	Stdctrls::TEdit* ComboBox;
	Db::TField* Field;
	int FieldNo;
	bool FieldOK;
	System::SmallString<30>  DataSourceName;
	Db::TDataSet* FDataSet;
	AnsiString FDataField;
	AnsiString FMask;
	bool IsMemo;
	void __fastcall SetDataSet(Db::TDataSet* Value);
	void __fastcall SetDataField(AnsiString Value);
	void __fastcall SetMask(AnsiString Value);
	
protected:
	virtual bool __fastcall GetCaptionBased(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Prepare(void);
	virtual void __fastcall Print(int OfsX, int OfsY);
	virtual void __fastcall Unprepare(void);
	
public:
	__fastcall virtual TQRDBText(Classes::TComponent* AOwner);
	DYNAMIC bool __fastcall UseRightToLeftAlignment(void);
	
__published:
	__property Alignment ;
	__property AlignToBand ;
	__property AutoSize ;
	__property AutoStretch ;
	__property BiDiMode ;
	__property ParentBiDiMode  = {default=1};
	__property Color  = {default=-2147483643};
	__property Db::TDataSet* DataSet = {read=FDataSet, write=SetDataSet};
	__property AnsiString DataField = {read=FDataField, write=SetDataField};
	__property Font ;
	__property AnsiString Mask = {read=FMask, write=SetMask};
	__property OnPrint ;
	__property ParentFont  = {default=1};
	__property Transparent ;
	__property WordWrap ;
public:
	#pragma option push -w-inl
	/* TQRCustomLabel.Destroy */ inline __fastcall virtual ~TQRDBText(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRDBText(HWND ParentWindow) : TQRCustomLabel(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRExpr;
class PASCALIMPLEMENTATION TQRExpr : public TQRCustomLabel 
{
	typedef TQRCustomLabel inherited;
	
private:
	Qrexpr::TQREvaluator* Evaluator;
	AnsiString FExpression;
	AnsiString FMask;
	Classes::TComponent* FMaster;
	bool FResetAfterPrint;
	Qrexpr::TQREvResult __fastcall GetValue();
	void __fastcall SetExpression(AnsiString Value);
	void __fastcall SetMask(AnsiString Value);
	
protected:
	virtual void __fastcall Prepare(void);
	virtual void __fastcall Unprepare(void);
	virtual void __fastcall QRNotification(System::TObject* Sender, Quickrpt::TQRNotifyOperation Operation);
	virtual void __fastcall Print(int OfsX, int OfsY);
	void __fastcall SetMaster(Classes::TComponent* AComponent);
	
public:
	__fastcall virtual TQRExpr(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRExpr(void);
	void __fastcall Reset(void);
	__property Qrexpr::TQREvResult Value = {read=GetValue};
	
__published:
	__property Alignment ;
	__property AlignToBand ;
	__property AutoSize ;
	__property AutoStretch ;
	__property BiDiMode ;
	__property ParentBiDiMode  = {default=1};
	__property Font ;
	__property Color  = {default=-2147483643};
	__property Classes::TComponent* Master = {read=FMaster, write=SetMaster};
	__property OnPrint ;
	__property ParentFont  = {default=1};
	__property bool ResetAfterPrint = {read=FResetAfterPrint, write=FResetAfterPrint, nodefault};
	__property Transparent ;
	__property WordWrap ;
	__property AnsiString Expression = {read=FExpression, write=SetExpression};
	__property AnsiString Mask = {read=FMask, write=SetMask};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRExpr(HWND ParentWindow) : TQRCustomLabel(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TQRSysDataType { qrsTime, qrsDate, qrsDateTime, qrsPageNumber, qrsReportTitle, qrsDetailCount, qrsDetailNo };
#pragma option pop

class DELPHICLASS TQRSysData;
class PASCALIMPLEMENTATION TQRSysData : public TQRCustomLabel 
{
	typedef TQRCustomLabel inherited;
	
private:
	TQRSysDataType FData;
	AnsiString FText;
	void __fastcall SetData(TQRSysDataType Value);
	HIDESBASE void __fastcall SetText(AnsiString Value);
	void __fastcall CreateCaption(void);
	
protected:
	virtual void __fastcall Print(int OfsX, int OfsY);
	
public:
	__fastcall virtual TQRSysData(Classes::TComponent* AOwner);
	
__published:
	__property Alignment ;
	__property AlignToBand ;
	__property AutoSize ;
	__property BiDiMode ;
	__property ParentBiDiMode  = {default=1};
	__property Color  = {default=-2147483643};
	__property TQRSysDataType Data = {read=FData, write=SetData, nodefault};
	__property Font ;
	__property OnPrint ;
	__property ParentFont  = {default=1};
	__property AnsiString Text = {read=FText, write=SetText};
	__property Transparent ;
public:
	#pragma option push -w-inl
	/* TQRCustomLabel.Destroy */ inline __fastcall virtual ~TQRSysData(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRSysData(HWND ParentWindow) : TQRCustomLabel(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TQRShapeType { qrsRectangle, qrsCircle, qrsVertLine, qrsHorLine, qrsTopAndBottom, qrsRightAndLeft };
#pragma option pop

class DELPHICLASS TQRShape;
class PASCALIMPLEMENTATION TQRShape : public Quickrpt::TQRPrintable 
{
	typedef Quickrpt::TQRPrintable inherited;
	
private:
	TQRShapeType FShape;
	Graphics::TBrush* FBrush;
	Graphics::TPen* FPen;
	void __fastcall SetBrush(Graphics::TBrush* Value);
	void __fastcall SetPen(Graphics::TPen* Value);
	void __fastcall SetShape(TQRShapeType Value);
	
protected:
	virtual void __fastcall Paint(void);
	virtual void __fastcall Print(int OfsX, int OfsY);
	void __fastcall StyleChanged(System::TObject* sender);
	
public:
	__fastcall virtual TQRShape(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRShape(void);
	
__published:
	__property Graphics::TBrush* Brush = {read=FBrush, write=SetBrush};
	__property Height  = {default=65};
	__property Graphics::TPen* Pen = {read=FPen, write=SetPen};
	__property TQRShapeType Shape = {read=FShape, write=SetShape, nodefault};
	__property Width  = {default=65};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRShape(HWND ParentWindow) : Quickrpt::TQRPrintable(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRImage;
class PASCALIMPLEMENTATION TQRImage : public Quickrpt::TQRPrintable 
{
	typedef Quickrpt::TQRPrintable inherited;
	
private:
	Graphics::TPicture* FPicture;
	bool FAutoSize;
	bool FStretch;
	bool FCenter;
	Graphics::TCanvas* __fastcall GetCanvas(void);
	void __fastcall PictureChanged(System::TObject* Sender);
	HIDESBASE void __fastcall SetAutoSize(bool Value);
	void __fastcall SetCenter(bool Value);
	void __fastcall SetPicture(Graphics::TPicture* Value);
	void __fastcall SetStretch(bool Value);
	
protected:
	DYNAMIC HPALETTE __fastcall GetPalette(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Print(int OfsX, int OfsY);
	
public:
	__fastcall virtual TQRImage(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRImage(void);
	__property Graphics::TCanvas* Canvas = {read=GetCanvas};
	
__published:
	__property bool AutoSize = {read=FAutoSize, write=SetAutoSize, default=0};
	__property bool Center = {read=FCenter, write=SetCenter, default=0};
	__property Graphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	__property bool Stretch = {read=FStretch, write=SetStretch, default=0};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRImage(HWND ParentWindow) : Quickrpt::TQRPrintable(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRDBImage;
class PASCALIMPLEMENTATION TQRDBImage : public Quickrpt::TQRPrintable 
{
	typedef Quickrpt::TQRPrintable inherited;
	
private:
	Db::TField* FField;
	Db::TDataSet* FDataSet;
	AnsiString FDataField;
	Graphics::TPicture* FPicture;
	bool FStretch;
	bool FCenter;
	bool FPictureLoaded;
	void __fastcall PictureChanged(System::TObject* Sender);
	void __fastcall SetCenter(bool Value);
	void __fastcall SetDataField(const AnsiString Value);
	void __fastcall SetDataSet(Db::TDataSet* Value);
	void __fastcall SetPicture(Graphics::TPicture* Value);
	void __fastcall SetStretch(bool Value);
	
protected:
	DYNAMIC HPALETTE __fastcall GetPalette(void);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Prepare(void);
	virtual void __fastcall Print(int OfsX, int OfsY);
	virtual void __fastcall UnPrepare(void);
	
public:
	__fastcall virtual TQRDBImage(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRDBImage(void);
	void __fastcall LoadPicture(void);
	__property Db::TField* Field = {read=FField};
	__property Graphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	
__published:
	__property bool Center = {read=FCenter, write=SetCenter, default=1};
	__property AnsiString DataField = {read=FDataField, write=SetDataField};
	__property Db::TDataSet* DataSet = {read=FDataSet, write=SetDataSet};
	__property bool Stretch = {read=FStretch, write=SetStretch, default=0};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRDBImage(HWND ParentWindow) : Quickrpt::TQRPrintable(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRRichEdit;
class PASCALIMPLEMENTATION TQRRichEdit : public Comctrls::TCustomRichEdit 
{
	typedef Comctrls::TCustomRichEdit inherited;
	
public:
	__property BorderStyle  = {default=1};
public:
	#pragma option push -w-inl
	/* TCustomRichEdit.Create */ inline __fastcall virtual TQRRichEdit(Classes::TComponent* AOwner) : Comctrls::TCustomRichEdit(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomRichEdit.Destroy */ inline __fastcall virtual ~TQRRichEdit(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRRichEdit(HWND ParentWindow) : Comctrls::TCustomRichEdit(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRCustomRichText;
class PASCALIMPLEMENTATION TQRCustomRichText : public Quickrpt::TQRPrintable 
{
	typedef Quickrpt::TQRPrintable inherited;
	
private:
	int LastChar;
	bool FAutoStretch;
	Comctrls::TRichEdit* FParentRichEdit;
	TQRRichEdit* FRichEdit;
	Classes::TAlignment __fastcall GetAlignment(void);
	Graphics::TColor __fastcall GetColor(void);
	Graphics::TFont* __fastcall GetFont(void);
	Classes::TStrings* __fastcall GetLines(void);
	virtual void __fastcall SetAlignment(Classes::TAlignment Value);
	HIDESBASE void __fastcall SetColor(Graphics::TColor Value);
	HIDESBASE void __fastcall SetFont(Graphics::TFont* Value);
	void __fastcall SetLines(Classes::TStrings* Value);
	void __fastcall SetParentRichEdit(Comctrls::TRichEdit* Value);
	
protected:
	__property Classes::TStrings* Lines = {read=GetLines, write=SetLines};
	__property Comctrls::TRichEdit* ParentRichEdit = {read=FParentRichEdit, write=SetParentRichEdit};
	virtual void __fastcall Print(int OfsX, int OfsY);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	
public:
	__fastcall virtual TQRCustomRichText(Classes::TComponent* AOwner);
	__fastcall virtual ~TQRCustomRichText(void);
	DYNAMIC Classes::TAlignment __fastcall GetControlsAlignment(void);
	
__published:
	__property Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, nodefault};
	__property bool AutoStretch = {read=FAutoStretch, write=FAutoStretch, nodefault};
	__property Graphics::TColor Color = {read=GetColor, write=SetColor, nodefault};
	__property Graphics::TFont* Font = {read=GetFont, write=SetFont};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRCustomRichText(HWND ParentWindow) : Quickrpt::TQRPrintable(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRRichText;
class PASCALIMPLEMENTATION TQRRichText : public TQRCustomRichText 
{
	typedef TQRCustomRichText inherited;
	
__published:
	__property Lines ;
	__property ParentRichEdit ;
public:
	#pragma option push -w-inl
	/* TQRCustomRichText.Create */ inline __fastcall virtual TQRRichText(Classes::TComponent* AOwner) : TQRCustomRichText(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQRCustomRichText.Destroy */ inline __fastcall virtual ~TQRRichText(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRRichText(HWND ParentWindow) : TQRCustomRichText(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRDBRichText;
class PASCALIMPLEMENTATION TQRDBRichText : public TQRCustomRichText 
{
	typedef TQRCustomRichText inherited;
	
private:
	Db::TField* Field;
	AnsiString FDataField;
	Db::TDataSet* FDataSet;
	
protected:
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall SetDataSet(Db::TDataSet* Value);
	virtual void __fastcall Prepare(void);
	virtual void __fastcall Unprepare(void);
	virtual void __fastcall Print(int OfsX, int OfsY);
	
__published:
	__property AnsiString DataField = {read=FDataField, write=FDataField};
	__property Db::TDataSet* DataSet = {read=FDataSet, write=SetDataSet};
public:
	#pragma option push -w-inl
	/* TQRCustomRichText.Create */ inline __fastcall virtual TQRDBRichText(Classes::TComponent* AOwner) : TQRCustomRichText(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQRCustomRichText.Destroy */ inline __fastcall virtual ~TQRDBRichText(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRDBRichText(HWND ParentWindow) : TQRCustomRichText(ParentWindow) { }
	#pragma option pop
	
};


class DELPHICLASS TQRMerger;
class PASCALIMPLEMENTATION TQRMerger : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStrings* FOrgLines;
	Classes::TStrings* FStrippedLines;
	Classes::TStrings* FMergedLines;
	bool FMerged;
	bool FPrepared;
	Classes::TList* Expressions;
	Classes::TList* FDataSets;
	
protected:
	Classes::TStrings* __fastcall GetOrgLines(void);
	Classes::TStrings* __fastcall GetMergedLines(void);
	void __fastcall SetOrgLines(Classes::TStrings* Value);
	
public:
	__fastcall TQRMerger(void);
	__fastcall virtual ~TQRMerger(void);
	void __fastcall Prepare(void);
	void __fastcall Merge(void);
	void __fastcall Unprepare(void);
	__property Classes::TStrings* Lines = {read=GetOrgLines, write=SetOrgLines};
	__property Classes::TStrings* MergedLines = {read=GetMergedLines};
	__property bool Merged = {read=FMerged, nodefault};
	__property bool Prepared = {read=FPrepared, nodefault};
	__property Classes::TList* DataSets = {read=FDataSets, write=FDataSets};
};


class DELPHICLASS TQRExprMemo;
class PASCALIMPLEMENTATION TQRExprMemo : public TQRCustomLabel 
{
	typedef TQRCustomLabel inherited;
	
private:
	TQRMerger* Merger;
	bool FRemoveBlankLines;
	
protected:
	virtual bool __fastcall GetCaptionBased(void);
	virtual void __fastcall Prepare(void);
	virtual void __fastcall Unprepare(void);
	virtual void __fastcall Print(int OfsX, int OfsY);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TQRExprMemo(Classes::TComponent* AOwner);
	
__published:
	__property bool RemoveBlankLines = {read=FRemoveBlankLines, write=FRemoveBlankLines, nodefault};
	__property Alignment ;
	__property AlignToBand ;
	__property AutoSize ;
	__property AutoStretch ;
	__property Color  = {default=-2147483643};
	__property Font ;
	__property Lines ;
	__property ParentFont  = {default=1};
	__property Transparent ;
	__property WordWrap ;
public:
	#pragma option push -w-inl
	/* TQRCustomLabel.Destroy */ inline __fastcall virtual ~TQRExprMemo(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRExprMemo(HWND ParentWindow) : TQRCustomLabel(ParentWindow) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TQRCalcOperation { qrcSum, qrcCount, qrcMax, qrcMin, qrcAverage };
#pragma option pop

class DELPHICLASS TQRDBCalc;
class PASCALIMPLEMENTATION TQRDBCalc : public TQRExpr 
{
	typedef TQRExpr inherited;
	
private:
	AnsiString FDataField;
	Db::TDataSource* FDataSource;
	TQRCalcOperation FOperation;
	Quickrpt::TQRBand* FResetBand;
	
protected:
	AnsiString __fastcall GetPrintMask();
	void __fastcall SetDataField(AnsiString Value);
	void __fastcall SetOperation(TQRCalcOperation Value);
	void __fastcall SetPrintMask(AnsiString Value);
	
__published:
	__property AnsiString DataField = {read=FDataField, write=SetDataField};
	__property Db::TDataSource* DataSource = {read=FDataSource, write=FDataSource};
	__property OnPrint ;
	__property TQRCalcOperation Operation = {read=FOperation, write=SetOperation, nodefault};
	__property ParentFont  = {default=1};
	__property AnsiString PrintMask = {read=GetPrintMask, write=SetPrintMask};
	__property Quickrpt::TQRBand* ResetBand = {read=FResetBand, write=FResetBand};
public:
	#pragma option push -w-inl
	/* TQRExpr.Create */ inline __fastcall virtual TQRDBCalc(Classes::TComponent* AOwner) : TQRExpr(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TQRExpr.Destroy */ inline __fastcall virtual ~TQRDBCalc(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TQRDBCalc(HWND ParentWindow) : TQRExpr(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qrctrls */
using namespace Qrctrls;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QRCtrls
