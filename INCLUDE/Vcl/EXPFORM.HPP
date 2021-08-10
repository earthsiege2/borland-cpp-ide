// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ExpForm.pas' rev: 5.00

#ifndef ExpFormHPP
#define ExpFormHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <FileCtrl.hpp>	// Pascal unit
#include <DsnDBCst.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <dsnconst.hpp>	// Pascal unit
#include <DBTables.hpp>	// Pascal unit
#include <Bde.hpp>	// Pascal unit
#include <DBCombo.hpp>	// Pascal unit
#include <TeeConst.hpp>	// Pascal unit
#include <TeeProcs.hpp>	// Pascal unit
#include <DBCtrls.hpp>	// Pascal unit
#include <TeeGally.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <DBChart.hpp>	// Pascal unit
#include <Chart.hpp>	// Pascal unit
#include <TeEngine.hpp>	// Pascal unit
#include <ComCtrls.hpp>	// Pascal unit
#include <ToolIntf.hpp>	// Pascal unit
#include <Buttons.hpp>	// Pascal unit
#include <StdCtrls.hpp>	// Pascal unit
#include <ExtCtrls.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Expform
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TSources { stLocal, stAlias };
#pragma option pop

class DELPHICLASS TTeeDlgWizard;
class PASCALIMPLEMENTATION TTeeDlgWizard : public Forms::TForm 
{
	typedef Forms::TForm inherited;
	
__published:
	Stdctrls::TButton* CancelBtn;
	Stdctrls::TButton* PrevButton;
	Stdctrls::TButton* NextButton;
	Comctrls::TPageControl* PageControl;
	Comctrls::TTabSheet* TabStyle;
	Stdctrls::TLabel* Label1;
	Comctrls::TTabSheet* TableName;
	Stdctrls::TLabel* Label3;
	Comctrls::TTabSheet* Buttons;
	Stdctrls::TLabel* Label2;
	Comctrls::TTabSheet* TabSheet1;
	Stdctrls::TLabel* Label4;
	Comctrls::TTabSheet* TabSheet2;
	Dbtables::TTable* Table1;
	Extctrls::TPanel* PanelGallery;
	Extctrls::TPanel* Panel1;
	Stdctrls::TListBox* LBAvailFields;
	Stdctrls::TListBox* LBSelectedFields;
	Stdctrls::TButton* Button3;
	Stdctrls::TButton* Button2;
	Stdctrls::TButton* Button4;
	Stdctrls::TButton* Button5;
	Extctrls::TPanel* Panel2;
	Stdctrls::TLabel* Label6;
	Stdctrls::TComboBox* cbLabelsFields;
	Comctrls::TPageControl* PageControl1;
	Comctrls::TTabSheet* TabPreviewChart;
	Dbchart::TDBChart* PreviewChart;
	Extctrls::TBevel* Bevel3;
	Stdctrls::TRadioButton* rbChart2D;
	Stdctrls::TRadioButton* rbChart3D;
	Extctrls::TPanel* Panel3;
	Stdctrls::TRadioButton* rbDatabase;
	Stdctrls::TRadioButton* rbNonDatabase;
	Stdctrls::TLabel* Label7;
	Stdctrls::TLabel* Label8;
	Extctrls::TPanel* Panel7;
	Stdctrls::TCheckBox* CB3DOption;
	Stdctrls::TCheckBox* CBShowLegendOption;
	Stdctrls::TCheckBox* CBShowMarksOption;
	Stdctrls::TButton* Button1;
	Extctrls::TPanel* Panel8;
	Stdctrls::TLabel* Label27;
	Stdctrls::TLabel* DirPath;
	Stdctrls::TEdit* FileEdit;
	Stdctrls::TLabel* PathText;
	Dbcombo::TAliasFileListBox* AliasFileList;
	Dbcombo::TAliasListBox* AliasPathList;
	Filectrl::TFilterComboBox* FilterList;
	Stdctrls::TLabel* Label26;
	Stdctrls::TLabel* Label25;
	Dbcombo::TAliasDrive* AliasDriveList;
	Extctrls::TPanel* Panel4;
	Extctrls::TImage* Image2;
	Stdctrls::TLabel* LabelURL;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall CancelClick(System::TObject* Sender);
	void __fastcall PrevClick(System::TObject* Sender);
	void __fastcall NextClick(System::TObject* Sender);
	void __fastcall Button5Click(System::TObject* Sender);
	void __fastcall Button4Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall LBAvailFieldsClick(System::TObject* Sender);
	void __fastcall LBSelectedFieldsClick(System::TObject* Sender);
	void __fastcall rbChart3DClick(System::TObject* Sender);
	void __fastcall rbChart2DClick(System::TObject* Sender);
	void __fastcall Image1Click(System::TObject* Sender);
	void __fastcall CB3DOptionClick(System::TObject* Sender);
	void __fastcall CBShowLegendOptionClick(System::TObject* Sender);
	void __fastcall CBShowMarksOptionClick(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, Word &Key, Classes::TShiftState Shift);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall FileEditChange(System::TObject* Sender);
	void __fastcall FileEditKeyPress(System::TObject* Sender, char &Key);
	void __fastcall AliasFileListClick(System::TObject* Sender);
	void __fastcall AliasFileListDblClick(System::TObject* Sender);
	void __fastcall AliasPathListChange(System::TObject* Sender);
	void __fastcall FilterListChange(System::TObject* Sender);
	void __fastcall AliasDriveListChange(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, Forms::TCloseAction &Action);
	void __fastcall LabelURLClick(System::TObject* Sender);
	
private:
	Teegally::TTeeGallery* tmpGallery;
	char *SourceBuffer;
	void __fastcall RefreshButtons(void);
	void __fastcall FmtWrite(Classes::TStream* Stream, const AnsiString Fmt, const System::TVarRec * Args
		, const int Args_Size);
	Forms::TForm* __fastcall DoFormCreation(const AnsiString FormIdent);
	
public:
	AnsiString BackupDir;
	AnsiString WizardAliasName;
	AnsiString WizardPath;
	bool ForceUpdate;
	AnsiString WizardTableName;
	int WizardDriveIndex;
	TSources WizardSource;
	void __fastcall CreateSeries(Classes::TComponent* AOwner, Chart::TCustomChart* AChart, Dbtables::TTable* 
		ATable, bool ShowData);
	Classes::TMemoryStream* __fastcall CreateHeader(const AnsiString UnitIdent, const AnsiString FormIdent
		);
	Classes::TMemoryStream* __fastcall CreateCppSource(const AnsiString UnitIdent, const AnsiString FormIdent
		);
	Classes::TMemoryStream* __fastcall CreateSource(const AnsiString UnitIdent, const AnsiString FormIdent
		);
	Classes::TMemoryStream* __fastcall CreateForm(const AnsiString FormIdent);
	void __fastcall SetChartOptions(void);
	void __fastcall GallerySelectedChart(System::TObject* Sender);
	AnsiString __fastcall AliasPath(const AnsiString AliasName);
	void __fastcall SetFileEditText(const AnsiString Value);
	void __fastcall SetFilter(const AnsiString AFilter);
	void __fastcall InitFilter(void);
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TTeeDlgWizard(Classes::TComponent* AOwner) : Forms::TForm(
		AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TTeeDlgWizard(Classes::TComponent* AOwner, int 
		Dummy) : Forms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TTeeDlgWizard(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TTeeDlgWizard(HWND ParentWindow) : Forms::TForm(
		ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall TeeChartWizard(Toolintf::TIToolServices* ToolServices);

}	/* namespace Expform */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Expform;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ExpForm
