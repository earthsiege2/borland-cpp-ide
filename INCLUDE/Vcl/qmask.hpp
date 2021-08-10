// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'QMask.pas' rev: 6.00

#ifndef QMaskHPP
#define QMaskHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QMenus.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <MaskUtils.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QTypes.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Qmask
{
//-- type declarations -------------------------------------------------------
typedef AnsiString TEditMask;

class DELPHICLASS EDBEditError;
class PASCALIMPLEMENTATION EDBEditError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDBEditError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDBEditError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDBEditError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDBEditError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDBEditError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDBEditError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDBEditError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDBEditError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDBEditError(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum QMask__2 { msMasked, msReEnter, msDBSetText };
#pragma option pop

typedef Set<QMask__2, msMasked, msDBSetText>  TMaskedState;

class DELPHICLASS TCustomMaskEdit;
class PASCALIMPLEMENTATION TCustomMaskEdit : public Qstdctrls::TCustomEdit 
{
	typedef Qstdctrls::TCustomEdit inherited;
	
private:
	AnsiString FEditMask;
	char FMaskBlank;
	int FMaxChars;
	int FWMaxChars;
	bool FMaskSave;
	TMaskedState FMaskState;
	int FCaretPos;
	int FBtnDownX;
	AnsiString FOldValue;
	bool FSettingCursor;
	bool FBeepOnError;
	bool __fastcall DoInputChar(char &NewChar, int MaskOffset);
	bool __fastcall InputChar(char &NewChar, int Offset);
	bool __fastcall DeleteSelection(AnsiString &Value, int Offset, int Len);
	int __fastcall InputString(AnsiString &Value, const AnsiString NewValue, int Offset);
	AnsiString __fastcall AddEditFormat(const AnsiString Value, bool Active);
	AnsiString __fastcall RemoveEditFormat(const AnsiString Value);
	int __fastcall FindLiteralChar(int MaskOffset, char InChar);
	AnsiString __fastcall GetEditText();
	bool __fastcall GetMasked(void);
	AnsiString __fastcall GetMaskedText();
	int __fastcall GetMaxLength(void);
	bool __fastcall CharKeys(char &CharCode);
	void __fastcall SetEditText(const AnsiString Value);
	void __fastcall SetEditMask(const AnsiString Value);
	HIDESBASE void __fastcall SetMaxLength(int Value);
	void __fastcall SetMaskedText(const AnsiString Value);
	void __fastcall DeleteKeys(Word CharCode);
	void __fastcall HomeEndKeys(Word CharCode, Classes::TShiftState Shift);
	void __fastcall CursorInc(int CursorPos, int Incr);
	void __fastcall CursorDec(int CursorPos);
	void __fastcall ArrowKeys(Word CharCode, Classes::TShiftState Shift);
	
protected:
	void __fastcall ReformatText(const AnsiString NewMask);
	void __fastcall GetSel(int &SelStart, int &SelStop);
	void __fastcall SetSel(int SelStart, int SelStop);
	HIDESBASE void __fastcall SetCursor(int Pos);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyUp(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(char &Key);
	DYNAMIC void __fastcall KeyString(WideString &S, bool &Handled);
	virtual bool __fastcall EditCanModify(void);
	virtual void __fastcall Reset(void);
	int __fastcall GetFirstEditChar(void);
	int __fastcall GetLastEditChar(void);
	int __fastcall GetNextEditChar(int Offset);
	int __fastcall GetPriorEditChar(int Offset);
	int __fastcall GetMaxChars(void);
	DYNAMIC void __fastcall MouseDown(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall TextChanged(void);
	virtual bool __fastcall Validate(const AnsiString Value, int &Pos);
	virtual void __fastcall ValidateError(void);
	void __fastcall CheckCursor(void);
	virtual void __fastcall SetText(const WideString Value);
	virtual void __fastcall SetSelText(const WideString Value);
	__property bool BeepOnError = {read=FBeepOnError, write=FBeepOnError, default=1};
	__property AnsiString EditMask = {read=FEditMask, write=SetEditMask};
	__property TMaskedState MaskState = {read=FMaskState, write=FMaskState, nodefault};
	__property int MaxLength = {read=GetMaxLength, write=SetMaxLength, default=-1};
	
public:
	__fastcall virtual TCustomMaskEdit(Classes::TComponent* AOwner);
	virtual void __fastcall CutToClipboard(void);
	virtual void __fastcall PasteFromClipboard(void);
	virtual void __fastcall ValidateEdit(void);
	virtual void __fastcall Clear(void);
	int __fastcall GetTextLen(void);
	__property bool IsMasked = {read=GetMasked, nodefault};
	__property AnsiString EditText = {read=GetEditText, write=SetEditText};
	__property AnsiString Text = {read=GetMaskedText, write=SetMaskedText};
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TCustomMaskEdit(Qt::QWidgetH* ParentWidget) : Qstdctrls::TCustomEdit(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TCustomMaskEdit(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMaskEdit;
class PASCALIMPLEMENTATION TMaskEdit : public TCustomMaskEdit 
{
	typedef TCustomMaskEdit inherited;
	
__published:
	__property Anchors  = {default=3};
	__property AutoSelect  = {default=1};
	__property AutoSize  = {default=1};
	__property BeepOnError  = {default=1};
	__property BorderStyle  = {default=1};
	__property CharCase  = {default=0};
	__property Color  = {default=-10};
	__property Constraints ;
	__property DragMode  = {default=0};
	__property Enabled  = {default=1};
	__property EditMask ;
	__property Font ;
	__property MaxLength  = {default=-1};
	__property ParentColor  = {default=0};
	__property ParentFont  = {default=1};
	__property ParentShowHint  = {default=1};
	__property PopupMenu ;
	__property ReadOnly  = {default=0};
	__property ShowHint  = {default=0};
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property Text ;
	__property Visible  = {default=1};
	__property OnChange ;
	__property OnClick ;
	__property OnContextPopup ;
	__property OnDblClick ;
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyString ;
	__property OnKeyUp ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TCustomMaskEdit.Create */ inline __fastcall virtual TMaskEdit(Classes::TComponent* AOwner) : TCustomMaskEdit(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TMaskEdit(Qt::QWidgetH* ParentWidget) : TCustomMaskEdit(ParentWidget) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TWidgetControl.Destroy */ inline __fastcall virtual ~TMaskEdit(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Qmask */
using namespace Qmask;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// QMask
