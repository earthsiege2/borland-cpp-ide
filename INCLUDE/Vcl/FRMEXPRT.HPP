// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Frmexprt.pas' rev: 5.00

#ifndef FrmexprtHPP
#define FrmexprtHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBCombo.hpp>	// Pascal unit
#include <FileCtrl.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Frmexprt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS FormExcept;
class PASCALIMPLEMENTATION FormExcept : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall FormExcept(const AnsiString Msg) : Sysutils::Exception(Msg
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall FormExcept(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall FormExcept(int Ident)/* overload */ : Sysutils::Exception(
		Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall FormExcept(int Ident, const System::TVarRec * Args, 
		const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall FormExcept(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(
		Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall FormExcept(const AnsiString Msg, const System::TVarRec 
		* Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext
		) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall FormExcept(int Ident, int AHelpContext)/* overload */
		 : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall FormExcept(System::PResStringRec ResStringRec, const 
		System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(
		ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~FormExcept(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TLayouts { ctHorz, ctVert, ctGrid };
#pragma option pop

#pragma option push -b-
enum TSources { stLocal, stAlias };
#pragma option pop

#pragma option push -b-
enum TLabelPos { lLeft, lTop };
#pragma option pop

struct TExpertChoice;
typedef TExpertChoice *PExpertChoice;

struct TExpertChoice
{
	TLayouts Layout;
	TSources Source;
	TLabelPos Labels;
	Classes::TStringList* QueryText;
	AnsiString TableName;
	Classes::TStringList* FieldList;
	int DriveIndex;
	AnsiString Path;
	AnsiString AliasName;
	int TypeIndex;
} ;

struct TFieldInfo;
typedef TFieldInfo *PFieldInfo;

struct TFieldInfo
{
	Db::TFieldType DataType;
	Word ControlWidth;
	TMetaClass*FieldClass;
	TMetaClass*ControlClass;
} ;

class DELPHICLASS TFormExpert;
class PASCALIMPLEMENTATION TFormExpert : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Extctrls::TNotebook* Notebook1;
	Stdctrls::TGroupBox* GroupBox2;
	Stdctrls::TRadioButton* CreateSingle;
	Stdctrls::TRadioButton* CreateMulti;
	Stdctrls::TLabel* Label1;
	Stdctrls::TLabel* LayoutLine1;
	Stdctrls::TRadioButton* HorzButton;
	Stdctrls::TRadioButton* VertButton;
	Stdctrls::TRadioButton* GridButton;
	Stdctrls::TLabel* Label8;
	Stdctrls::TLabel* Label9;
	Stdctrls::TLabel* Label10;
	Stdctrls::TLabel* Label11;
	Stdctrls::TLabel* Label12;
	Stdctrls::TLabel* Label13;
	Stdctrls::TLabel* Label6;
	Filectrl::TFilterComboBox* FilterList;
	Stdctrls::TLabel* Label25;
	Stdctrls::TLabel* Label26;
	Stdctrls::TLabel* Label27;
	Stdctrls::TLabel* DirPath;
	Stdctrls::TEdit* FileEdit;
	Stdctrls::TLabel* PathText;
	Dbcombo::TAliasDrive* AliasDriveList;
	Dbcombo::TAliasListBox* AliasPathList;
	Dbcombo::TAliasFileListBox* AliasFileList;
	Stdctrls::TLabel* Label22;
	Stdctrls::TLabel* Label24;
	Stdctrls::TLabel* TableLine;
	Stdctrls::TLabel* Label5;
	Stdctrls::TRadioButton* LeftButton;
	Stdctrls::TRadioButton* TopButton;
	Stdctrls::TLabel* Label28;
	Stdctrls::TLabel* Label29;
	Stdctrls::TListBox* DetailList;
	Stdctrls::TListBox* MasterList;
	Stdctrls::TLabel* Label30;
	Stdctrls::TLabel* Label31;
	Stdctrls::TButton* AddButton;
	Stdctrls::TLabel* Label32;
	Stdctrls::TLabel* Label33;
	Stdctrls::TButton* DeleteButton;
	Stdctrls::TButton* ClearButton;
	Stdctrls::TListBox* BindList;
	Stdctrls::TLabel* Label4;
	Extctrls::TImage* Image1;
	Stdctrls::TListBox* ChosenList;
	Buttons::TBitBtn* UpButton;
	Buttons::TBitBtn* DownButton;
	Stdctrls::TListBox* AvailableList;
	Stdctrls::TGroupBox* GroupBox1;
	Stdctrls::TRadioButton* CreateTable;
	Stdctrls::TRadioButton* CreateQuery;
	Stdctrls::TLabel* IndexLabel;
	Extctrls::TBevel* Bevel1;
	Stdctrls::TComboBox* IndexList;
	Stdctrls::TLabel* Label17;
	Stdctrls::TLabel* Label18;
	Dbtables::TTable* Table1;
	Buttons::TBitBtn* BitBtn3;
	Buttons::TBitBtn* BitBtn4;
	Buttons::TBitBtn* BitBtn5;
	Buttons::TBitBtn* BitBtn6;
	Stdctrls::TCheckBox* GenMainForm;
	Dbtables::TTable* Table2;
	Stdctrls::TButton* CancelButton;
	Stdctrls::TButton* HelpButton;
	Stdctrls::TButton* PrevButton;
	Stdctrls::TButton* NextButton;
	Stdctrls::TButton* CreateButton;
	Stdctrls::TGroupBox* FormChoices;
	Stdctrls::TRadioButton* FormAndModule;
	Stdctrls::TRadioButton* Form;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall NextButtonClick(System::TObject* Sender);
	void __fastcall PrevButtonClick(System::TObject* Sender);
	void __fastcall CreateOptionClick(System::TObject* Sender);
	void __fastcall DataSourceListClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall LayoutButtonClick(System::TObject* Sender);
	void __fastcall AliasDriveListChange(System::TObject* Sender);
	void __fastcall AliasPathListChange(System::TObject* Sender);
	void __fastcall FilterListChange(System::TObject* Sender);
	void __fastcall AliasFileListClick(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall Button4Click(System::TObject* Sender);
	void __fastcall FileEditChange(System::TObject* Sender);
	void __fastcall ListDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, Controls::TDragState 
		State, bool &Accept);
	void __fastcall ListDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall UpButtonClick(System::TObject* Sender);
	void __fastcall DownButtonClick(System::TObject* Sender);
	void __fastcall PosButtonClick(System::TObject* Sender);
	void __fastcall BindingListClick(System::TObject* Sender);
	void __fastcall AddButtonClick(System::TObject* Sender);
	void __fastcall ClearButtonClick(System::TObject* Sender);
	void __fastcall ListDblClick(System::TObject* Sender);
	void __fastcall DeleteButtonClick(System::TObject* Sender);
	void __fastcall BindListClick(System::TObject* Sender);
	void __fastcall AliasFileListDblClick(System::TObject* Sender);
	void __fastcall FormPaint(System::TObject* Sender);
	void __fastcall FileEditKeyPress(System::TObject* Sender, char &Key);
	void __fastcall CreateTableClick(System::TObject* Sender);
	void __fastcall CreateQueryClick(System::TObject* Sender);
	void __fastcall IndexListChange(System::TObject* Sender);
	void __fastcall FormClick(System::TObject* Sender);
	void __fastcall FormAndModuleClick(System::TObject* Sender);
	void __fastcall HelpButtonClick(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	
private:
	Classes::TStringList* FAliasList;
	int FCurPage;
	bool FSimpleQuery;
	bool FProcessedMaster;
	TExpertChoice FChoice1;
	TExpertChoice FChoice2;
	TExpertChoice *FCurChoice;
	int FInitialDriveIndex;
	AnsiString FInitialDir;
	int FChosenItem;
	Controls::TImageList* FImageList;
	bool FDataModule;
	bool FClearDetails;
	Classes::TStringList* FOrderedDetailList;
	Classes::TStringList* FOrderedMasterList;
	Classes::TStringList* FMasterDescList;
	Classes::TStringList* FDetailDescList;
	bool FCreateTable;
	bool SyncChoices;
	bool ForceUpdate;
	AnsiString FFullIndexName;
	void __fastcall AddToBindList(const AnsiString Str1, const AnsiString Str2);
	void __fastcall ChangePages(int Value);
	void __fastcall CheckBind(void);
	TMetaClass* __fastcall CreateField(Classes::TComponent* AOwner, Db::TDataSet* DataSet, TMetaClass* 
		FieldClass, const AnsiString DatabaseName, const AnsiString TableName, const AnsiString FieldName)
		;
	bool __fastcall DoDragOver(Stdctrls::TListBox* List, const Windows::TPoint &Point, int &Index, Controls::TDragState 
		State, bool DropOnSelected);
	void __fastcall FillFieldList(Classes::TStrings* List, PExpertChoice Choice, bool StoreDesc);
	AnsiString __fastcall AliasPath(const AnsiString AliasName);
	void __fastcall FreeChoice(TExpertChoice &Choice);
	void __fastcall GenSelect(const AnsiString TableName, Classes::TStrings* Fields, Classes::TStrings* 
		SQLText, const AnsiString AliasName, const AnsiString Delimiter, bool QuoteTableName, const AnsiString 
		Owner);
	void __fastcall GenBindVar(const AnsiString TableName, Classes::TStrings* List, Classes::TStrings* 
		Query, const AnsiString Delimiter);
	int __fastcall GetFirstSelection(Stdctrls::TCustomListBox* List);
	void __fastcall SetFileEditText(const AnsiString Value);
	void __fastcall Init(void);
	void __fastcall InitChoice(TExpertChoice &Choice);
	void __fastcall InitFilter(void);
	void __fastcall InitQuery(Classes::TComponent* AOwner, Dbtables::TQuery* Query, const TExpertChoice 
		&Choice, bool Bind);
	void __fastcall InitTable(Classes::TComponent* AOwner, Dbtables::TTable* Table, const TExpertChoice 
		&Choice, bool Bind);
	void __fastcall MoveDragList(Stdctrls::TListBox* List1, Stdctrls::TListBox* List2, const Windows::TPoint 
		&Point, int Index);
	void __fastcall MoveItems(Stdctrls::TListBox* List, const Windows::TPoint &Point, int Index);
	void __fastcall OrderFieldList(Classes::TStrings* OrderedList, Classes::TStrings* List);
	void __fastcall ProcessPage0(void);
	void __fastcall ProcessPage1(void);
	void __fastcall ProcessPage2(void);
	void __fastcall ProcessPage3(void);
	void __fastcall ProcessPage4(void);
	void __fastcall ProcessPage5(void);
	void __fastcall RemoveMatch(Classes::TStrings* List1, Classes::TStrings* List2);
	void __fastcall MoveSelected(Stdctrls::TCustomListBox* List, Classes::TStrings* Items);
	void __fastcall InsertSelected(Stdctrls::TCustomListBox* List, Classes::TStrings* Items, int Index)
		;
	void __fastcall SetButtons(void);
	void __fastcall SetFilter(const AnsiString AFilter);
	void __fastcall SetItem(Stdctrls::TListBox* List, int Index);
	void __fastcall SetLayOut(void);
	__property Classes::TStringList* AliasList = {read=FAliasList};
	__property int CurPage = {read=FCurPage, write=FCurPage, nodefault};
	__property bool SimpleQuery = {read=FSimpleQuery, write=FSimpleQuery, nodefault};
	__property bool ProcessedMaster = {read=FProcessedMaster, write=FProcessedMaster, nodefault};
	__property TExpertChoice Choice1 = {read=FChoice1, write=FChoice1};
	__property TExpertChoice Choice2 = {read=FChoice2, write=FChoice2};
	__property int ChosenItem = {read=FChosenItem, write=FChosenItem, nodefault};
	__property Controls::TImageList* ImageList = {read=FImageList};
	__property Classes::TStringList* OrderedDetailList = {read=FOrderedDetailList};
	__property Classes::TStringList* OrderedMasterList = {read=FOrderedMasterList};
	
public:
	__fastcall virtual TFormExpert(Classes::TComponent* AOwner);
	bool __fastcall CreateForm(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFormExpert(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFormExpert(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TFormExpert(HWND ParentWindow) : Forms::TForm(ParentWindow
		) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Frmexprt */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Frmexprt;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Frmexprt
