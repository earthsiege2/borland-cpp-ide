// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'mxdcube.pas' rev: 5.00

#ifndef mxdcubeHPP
#define mxdcubeHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Mask.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <mxstore.hpp>	// Pascal unit
#include <mxcommon.hpp>	// Pascal unit
#include <mxDB.hpp>	// Pascal unit
#include <mxgrid.hpp>	// Pascal unit
#include <mxConsts.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Grids.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mxdcube
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ECubeDesignError;
class PASCALIMPLEMENTATION ECubeDesignError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ECubeDesignError(const AnsiString Msg) : Sysutils::Exception(
		Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ECubeDesignError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ECubeDesignError(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ECubeDesignError(int Ident, const System::TVarRec * 
		Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ECubeDesignError(const AnsiString Msg, int AHelpContext
		) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ECubeDesignError(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ECubeDesignError(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ECubeDesignError(System::PResStringRec ResStringRec
		, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ECubeDesignError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TEditorDimensionItem;
class PASCALIMPLEMENTATION TEditorDimensionItem : public Mxcommon::TDimensionItem 
{
	typedef Mxcommon::TDimensionItem inherited;
	
public:
	#pragma option push -w-inl
	/* TDimensionItem.Create */ inline __fastcall virtual TEditorDimensionItem(Classes::TCollection* Collection
		) : Mxcommon::TDimensionItem(Collection) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TEditorDimensionItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TDssCubeEditor;
class PASCALIMPLEMENTATION TDssCubeEditor : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TListBox* FieldList;
	Stdctrls::TRadioButton* RadioMetaData;
	Stdctrls::TRadioButton* RadioDimensionData;
	Stdctrls::TRadioButton* RadioAllData;
	Stdctrls::TRadioButton* RadioNoData;
	Stdctrls::TGroupBox* Panel1;
	Stdctrls::TEdit* CaptionEdit;
	Stdctrls::TLabel* CaptionLabel;
	Stdctrls::TLabel* ActiveLabel;
	Stdctrls::TLabel* BinLabel;
	Stdctrls::TLabel* StartLabel;
	Stdctrls::TLabel* TypeLabel;
	Stdctrls::TComboBox* ActiveEdit;
	Stdctrls::TComboBox* BinEdit;
	Stdctrls::TComboBox* TypeEdit;
	Comctrls::TPageControl* Pager;
	Comctrls::TTabSheet* DimensionInfo;
	Comctrls::TTabSheet* MemoryControl;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* Label2;
	Stdctrls::TEdit* FormatEdit;
	Mask::TMaskEdit* StartEdit;
	Stdctrls::TButton* OKButton;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TButton* HelpButton;
	Stdctrls::TLabel* NActiveDims;
	Stdctrls::TLabel* nDemandDims;
	Stdctrls::TLabel* Label4;
	Stdctrls::TLabel* Label7;
	Stdctrls::TLabel* Label9;
	Stdctrls::TLabel* NActiveSums;
	Stdctrls::TLabel* NDemandSums;
	Stdctrls::TLabel* Label6;
	Stdctrls::TEdit* MaxDims;
	Stdctrls::TEdit* MaxSums;
	Stdctrls::TEdit* MaxCells;
	Stdctrls::TLabel* Label5;
	Stdctrls::TLabel* Label12;
	Stdctrls::TLabel* nDemandCells;
	Stdctrls::TButton* GetCellCounts;
	Stdctrls::TGroupBox* CubeLimits;
	Stdctrls::TLabel* ValueCount;
	Stdctrls::TLabel* Label3;
	Stdctrls::TLabel* nCurrDims;
	Stdctrls::TLabel* nCurrSums;
	Stdctrls::TLabel* nCurrCells;
	Stdctrls::TLabel* BaseNameLabel;
	Mask::TMaskEdit* BaseNameEdit;
	void __fastcall RadioDimensionDataClick(System::TObject* Sender);
	void __fastcall RadioMetaDataClick(System::TObject* Sender);
	void __fastcall RadioAllDataClick(System::TObject* Sender);
	void __fastcall RadioNoDataClick(System::TObject* Sender);
	void __fastcall FieldListClick(System::TObject* Sender);
	void __fastcall OKButtonClick(System::TObject* Sender);
	void __fastcall HandleFieldEdit(System::TObject* Sender);
	void __fastcall HandleBeginEdit(System::TObject* Sender, char &Key);
	void __fastcall ActiveEditChange(System::TObject* Sender);
	void __fastcall CancelButtonClick(System::TObject* Sender);
	void __fastcall PagerChange(System::TObject* Sender);
	void __fastcall GetCellCountsClick(System::TObject* Sender);
	void __fastcall FormKeyPress(System::TObject* Sender, char &Key);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	
private:
	Mxdb::TDecisionCube* myObject;
	Mxstore::TCubeDims* myMap;
	Db::TDataSet* myDataSet;
	Dbtables::TDatabase* myDB;
	bool bBinEdited;
	bool bEditing;
	bool bParsed;
	bool bDataSetMatch;
	int fLastSelected;
	bool bForceRefresh;
	bool bSetNameEditing;
	bool bSetValuesEditing;
	AnsiString FNameCopy;
	AnsiString FFormatCopy;
	Mxcommon::TActiveFlags FActiveCopy;
	Mxcommon::TDimFlags FTypeCopy;
	Mxcommon::TBinType FBinTypeCopy;
	AnsiString FStartValueCopy;
	void __fastcall InitEdit(void);
	void __fastcall CommitEdit(void);
	void __fastcall GetValueCounts(void);
	
public:
	void __fastcall UpdateLists(void);
	void __fastcall InitializePanel(void);
	void __fastcall InitCapacityPage(void);
	bool __fastcall SInitialize(const Forms::_di_IDesigner Designer, Classes::TComponent* AnObject);
	void __fastcall SFinalize(void);
	__fastcall virtual TDssCubeEditor(Classes::TComponent* AOwner);
	__fastcall virtual ~TDssCubeEditor(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDssCubeEditor(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TDssCubeEditor(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TDssCubeEditor* DSSCubeEditor;
extern PACKAGE void __fastcall ShowDSSCubeEditor(const Forms::_di_IDesigner Designer, Mxdb::TDecisionCube* 
	aCube);

}	/* namespace Mxdcube */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mxdcube;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// mxdcube
