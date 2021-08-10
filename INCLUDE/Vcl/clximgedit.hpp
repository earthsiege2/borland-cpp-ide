// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ClxImgEdit.pas' rev: 6.00

#ifndef ClxImgEditHPP
#define ClxImgEditHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QTypes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <Qt.hpp>	// Pascal unit
#include <QImgList.hpp>	// Pascal unit
#include <QComCtrls.hpp>	// Pascal unit
#include <QDialogs.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Clximgedit
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TImageOperation { ioCrop, ioStretch, ioCenter };
#pragma option pop

class DELPHICLASS TImageInfo;
class DELPHICLASS TClxImageListEditor;
class PASCALIMPLEMENTATION TClxImageListEditor : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
__published:
	Qstdctrls::TButton* OK;
	Qstdctrls::TButton* Cancel;
	Qstdctrls::TGroupBox* ImageGroup;
	Qextctrls::TPanel* MainPanel;
	Qextctrls::TImage* MainImage;
	Qdialogs::TOpenDialog* OpenDialog;
	Qextctrls::TRadioGroup* OptionsGroup;
	Qstdctrls::TButton* Apply;
	Qstdctrls::TComboBox* TransparentColor;
	Qstdctrls::TLabel* TransparentLabel;
	Qstdctrls::TLabel* FillLabel;
	Qstdctrls::TComboBox* FillColor;
	Qstdctrls::TButton* Help;
	Qstdctrls::TGroupBox* GroupBox1;
	Qcomctrls::TIconView* ImageView;
	Qstdctrls::TButton* Add;
	Qstdctrls::TButton* Delete;
	Qstdctrls::TButton* Clear;
	Qstdctrls::TButton* ExportBtn;
	Qdialogs::TSaveDialog* SaveDialog;
	void __fastcall AddClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall ClearClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall OptionsGroupClick(System::TObject* Sender);
	void __fastcall ApplyClick(System::TObject* Sender);
	void __fastcall TransparentColorChange(System::TObject* Sender);
	void __fastcall TransparentColorExit(System::TObject* Sender);
	void __fastcall ImageViewChange(System::TObject* Sender, Qcomctrls::TIconViewItem* Item, Qcomctrls::TItemChange Change);
	void __fastcall ImageViewKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall HelpClick(System::TObject* Sender);
	void __fastcall MainImageMouseMove(System::TObject* Sender, Classes::TShiftState Shift, int X, int Y);
	void __fastcall ExportBtnClick(System::TObject* Sender);
	void __fastcall ImageViewSelectItem(System::TObject* Sender, Qcomctrls::TIconViewItem* Item, bool Selected);
	void __fastcall MainImageMouseDown(System::TObject* Sender, Qcontrols::TMouseButton Button, Classes::TShiftState Shift, int X, int Y);
	void __fastcall ImageViewEdited(System::TObject* Sender, Qcomctrls::TIconViewItem* Item, const WideString NewName);
	
private:
	bool FChanging;
	bool FSelecting;
	Qimglist::TImageList* FComponentList;
	Classes::TList* FInfoList;
	Qimglist::TImageList* FImageList;
	Qimglist::TImageList* FImageListView;
	Qgraphics::TBitmap* FImageBitmap;
	Qimglist::TImageList* FDragImageList;
	int FImageXDivOffset;
	int FImageYDivOffset;
	void __fastcall AddColor(const AnsiString S);
	void __fastcall ClearBitmap(Qgraphics::TBitmap* Value, Qgraphics::TColor Color);
	void __fastcall ClearAllImages(void);
	void __fastcall ClearWithFill(Qgraphics::TBitmap* Bitmap, int Index);
	void __fastcall DeleteSelectedImages(void);
	void __fastcall FocusImage(int Index, int Count);
	TImageInfo* __fastcall GetImageInfo(int Index);
	int __fastcall GetIndex(void);
	void __fastcall MoveImage(int FromIndex, int ToIndex);
	void __fastcall Replace(int Index, Qgraphics::TBitmap* Image, Qgraphics::TBitmap* Mask);
	void __fastcall ReplaceMasked(int Index, Qgraphics::TBitmap* NewImage, Qgraphics::TColor MaskColor);
	void __fastcall SetImageOperation(TImageOperation Operation);
	void __fastcall SetImageColor(Qgraphics::TColor Color, bool Fill);
	bool __fastcall SetStates(void);
	void __fastcall StretchImageList(Qimglist::TImageList* SrcList, Qimglist::TImageList* DstList, int Width, int Height);
	void __fastcall CenterImageList(Qimglist::TImageList* SrcList, Qimglist::TImageList* DstList, int Width, int Height);
	void __fastcall UpdateImageView(void);
	void __fastcall StretchReplace(Qimglist::TImageList* List, int Index, Qgraphics::TBitmap* Image, Qgraphics::TBitmap* Mask);
	void __fastcall StretchReplaceMasked(Qimglist::TImageList* List, int Index, Qgraphics::TBitmap* Image, Qgraphics::TColor MaskColor);
	void __fastcall CenterReplace(Qimglist::TImageList* List, int Index, Qgraphics::TBitmap* Image, Qgraphics::TBitmap* Mask);
	void __fastcall CenterReplaceMasked(Qimglist::TImageList* List, int Index, Qgraphics::TBitmap* Image, Qgraphics::TColor MaskColor);
	void __fastcall DoImageListViewChange(System::TObject* Sender);
	void __fastcall UpdatePickColor(int X, int Y);
	
public:
	__fastcall TClxImageListEditor(Classes::TComponent* AOwner, Qimglist::TImageList* AImgList);
	void __fastcall AddBitmap(void);
	void __fastcall Center(int Index);
	void __fastcall Crop(int Index);
	void __fastcall SelectImage(int Index);
	void __fastcall Stretch(int Index);
	__property Qimglist::TImageList* DragImageList = {read=FDragImageList, write=FDragImageList};
	__property Qgraphics::TBitmap* ImageBitmap = {read=FImageBitmap};
	__property int Index = {read=GetIndex, nodefault};
	__property Classes::TList* InfoList = {read=FInfoList};
	__property Qimglist::TImageList* ImageList = {read=FImageList};
	__property Qimglist::TImageList* ImageListView = {read=FImageListView};
	__property TImageInfo* Items[int Index] = {read=GetImageInfo};
	__property Qimglist::TImageList* ComponentList = {read=FComponentList};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TClxImageListEditor(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TClxImageListEditor(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TClxImageListEditor(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TClxImageListEditor(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TImageInfo : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	bool FAutoOp;
	TImageOperation FOperation;
	Classes::TList* FOwner;
	TClxImageListEditor* FOwnerForm;
	bool FCanChangeTransparent;
	bool FCanChangeFill;
	Qgraphics::TBitmap* FBitmap;
	Qgraphics::TBitmap* FMask;
	bool FNew;
	Qgraphics::TColor FTransparentColor;
	Qgraphics::TColor FFillColor;
	void __fastcall Center(void);
	void __fastcall Crop(void);
	int __fastcall GetIndex(void);
	void __fastcall SetOperation(TImageOperation Value);
	void __fastcall SetFillColor(Qgraphics::TColor Value);
	void __fastcall SetTransparentColor(Qgraphics::TColor Value);
	void __fastcall Stretch(void);
	
public:
	__fastcall TImageInfo(Classes::TList* AOwner, TClxImageListEditor* AOwnerForm);
	__fastcall virtual ~TImageInfo(void);
	void __fastcall Change(void);
	void __fastcall SelectImage(void);
	__property Qgraphics::TBitmap* Bitmap = {read=FBitmap};
	__property Qgraphics::TBitmap* Mask = {read=FMask};
	__property bool New = {read=FNew, nodefault};
	__property bool CanChangeFill = {read=FCanChangeFill, nodefault};
	__property bool CanChangeTransparent = {read=FCanChangeTransparent, nodefault};
	__property Qgraphics::TColor FillColor = {read=FFillColor, write=SetFillColor, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property TImageOperation Operation = {read=FOperation, write=SetOperation, nodefault};
	__property Classes::TList* Owner = {read=FOwner};
	__property TClxImageListEditor* OwnerForm = {read=FOwnerForm};
	__property Qgraphics::TColor TransparentColor = {read=FTransparentColor, write=SetTransparentColor, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall EditImageList(Qimglist::TImageList* AImageList);

}	/* namespace Clximgedit */
using namespace Clximgedit;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ClxImgEdit
