//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------
// App.h - dcc32 generated hdr (DO NOT EDIT) rev: 0
// From: App.pas
//---------------------------------------------------------------
#ifndef AppHPP
#define AppHPP
//---------------------------------------------------------------
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
#include <ToolIntf.hpp>
#include <EditIntf.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <System.hpp>
#include <FileCtrl.hpp>

//-- type declarations ------------------------------------------
enum TMoveDirection { mdPrevious, mdNext, mdNoMove };
enum TPages { pgMenus, pgExtensions, pgSpeedbar, pgAppInfo };
enum TMainItems { mmFile, mmEdit, mmWindow, mmHelp };
enum TCodeSnipet {csMainImpl , csHdr1, csHdr2, csProgram,
                  csFormCreateProc, csShowHelpProc, csFileNewProc,
                  csFileOpenProc, csFileSaveProc, csFileSaveAsProc,
                  csFilePrintProc, csFilePrintSetupProc,
                  csFileExitProc, csEditUndoProc, csEditCutProc,
                  csEditCopyProc, csEditPasteProc, csWindowTileProc,
                  csWindowCascadeProc, csWindowArrangeProc,
                  csHelpContentsProc, csHelpSearchProc,
                  csHelpHowToUseProc, csHelpAboutProc, csForm,
                  csFormMenu, csCreateMethod, csFormMDI, csHints,
                  csMenuObject, csFileMenuObject, csEditMenuObject, 
                  csWindowMenuObject, csHelpMenuObject,
                  csOpenDialogObject,csSaveDialogObject,
                  csPrintDialogObject,csPrintSetupDialogObject,
                  csStatusLineObject, csSpeedbarObject,
                  csSpeedButtonObject, csLastObject};

/////////////////////////////////////////// TAppExpert //////////
 __declspec(delphiclass)class TAppExpert;
class TAppExpert : public TForm
{
	typedef TForm inherited;
__published:
	TPaintBox*         Sample;      // SamplePaint
	TButton*           CancelBtn;   //
	TButton*           PrevButton;  // NextPrevClick
	TButton*           NextButton;  // NextPrevClick
	TPageControl*      PageControl; //
	TTabSheet*         Menus;       //
	TLabel*            Label1;      //
	TLabel*            Label2;      //
	TLabel*            Label3;      //
	TLabel*            Label4;      //
	TLabel*            Label5;      //
	TCheckBox*         cbFileMenu;  // MenuClicked
	TCheckBox*         cbEditMenu;  // MenuClicked
	TCheckBox*         cbWindowMenu;// MenuClicked
	TCheckBox*         cbHelpMenu;  // MenuClicked
	TTabSheet*         Extensions;  //
	TLabel*            Label6;      //
	TPanel*            Panel1;      //
	THeader*           ExtHeader;   // File Extensions list header
	TListBox*          ExtListBox;  // File Extensions list box
	TButton*           AddButton;   // File Ext list Add button
	TButton*           EditButton;  // File Ext list edit button
	TButton*           DeleteButton;// File Ext list Delete button
	TButton*           UpButton;    // MoveClick
	TButton*           DownButton;  // MoveClick
	TTabSheet*         Speedbtns;   //

	TLabel*            Label7;
	TPaintBox*         Speedbar;     // SpeedMouseDown, SpeedbarPaint
	TLabel*            Label8;       //
	TLabel*            Label9;       //
	TListBox*          MenuList;     // MenuListClick
	TListBox*          MenuItemList; // DrawMenuItem
	TButton*           Button1;      // InsertClick
	TButton*           Button2;      // RemoveClick
	TButton*           Button3;      // SpaceClick
	TTabSheet*         AppInfo;      //
	TLabel*            Label13;      //
	TLabel*            Label10;      //
	TLabel*            Label15;      //
	TGroupBox*         GroupBox1;    //
	TCheckBox*         cbMDIApp;     //
	TCheckBox*         cbStatusLine; //
	TCheckBox*         cbHints;      //
	TEdit*             AppPath;      //
	TButton*           PathBrowse;   // BrowseClick
	TEdit*             AppName;      // User's application name

	void __fastcall HeaderSized(TObject* Sender, Integer ASection,
                              Integer AWidth);
	void __fastcall FormCreate(TObject* Sender);
	void __fastcall NextPrevClick(TObject* Sender);
	void __fastcall DrawExtension(TWinControl* Control, Integer Index,
                                const TRect &Rect, TOwnerDrawState State);
	void __fastcall AddClick(TObject* Sender);
	void __fastcall EditClick(TObject* Sender);
	void __fastcall DeleteClick(TObject* Sender);
	void __fastcall MoveClick(TObject* Sender);
	void __fastcall SpeedbarPaint(TObject* Sender);
	void __fastcall FormDestroy(TObject* Sender);
	void __fastcall MenuListClick(TObject* Sender);
	void __fastcall DrawMenuItem(TWinControl* Control, Integer Index,
                               const TRect &Rect, TOwnerDrawState State);
	void __fastcall InsertClick(TObject* Sender);
	void __fastcall SpaceClick(TObject* Sender);
	void __fastcall SpeedMouseDown(TObject* Sender, TMouseButton Button,
                                 TShiftState Shift, Integer X, Integer Y);
	void __fastcall RemoveClick(TObject* Sender);
	void __fastcall BrowseClick(TObject* Sender);
	void __fastcall SamplePaint(TObject* Sender);
	void __fastcall MenuClicked(TObject* Sender);

private:
	TList*             SpeedList;
	TList*             ButtonList;
	int                FSpeedIndex;
	Graphics::TBitmap* SpeedPointer;
	Graphics::TBitmap* Offscreen;
	Graphics::TBitmap* SampleBmp;
	void __fastcall RefreshButtons(void);
	int __fastcall NextPage(TMoveDirection Direction);
	TRect __fastcall SpeedButtonRect(int Index);
	int __fastcall SpeedButtonAtPos(const tagPOINT &Pos);
	int __fastcall GetSpeedButtonCount(void);
	int __fastcall GetSpeedButtonID(int Value);
	bool __fastcall ValidateInfo(void);

public:
	__fastcall TAppExpert(TComponent* AOwner);
	__fastcall TAppExpert(TComponent* AOwner, int Dummy);
	__fastcall virtual ~TAppExpert(void);

  bool __fastcall HasMenus(void);
  __property int SpeedButtonCount = {read=GetSpeedButtonCount,nodefault};
	__property int SpeedButtonID[int Value] = {read=GetSpeedButtonID};
	__fastcall TAppExpert(HWND ParentWindow) : TForm(ParentWindow) { }
};

//-- var, const, procedure --------------------------------------
extern TAppExpert* AppExpert;
extern void __fastcall ApplicationExpert(TIToolServices* ToolServices);
//-- end unit ---------------------------------------------------

void __fastcall ApplicationExpert(TIToolServices* ToolServices);

/////////////////////////////////////////// EButtonImage ////////
// EButtonImage - draws the image of a TSpeedButton
class __declspec(delphiclass) EButtonImage;
class EButtonImage : public TObject {
  private:
    long              FBitmapID;
    Graphics::TBitmap *bmFBitmap;
    int               FNumGlyphs;
    TPoint            DefButtonSize;
    void __fastcall SetBitmapID(long Value);
  public:
    __fastcall EButtonImage(void);
    __fastcall ~EButtonImage(void);
    void __fastcall Draw(TCanvas *Canvas, int X, int Y);
    __property long BitmapID = {read=FBitmapID, write=SetBitmapID};
    __property int NumGlyphs = {read=FNumGlyphs, write=FNumGlyphs};
};

// ////////// AppCreator //////////////////////////
// This class creates a new project makefile
// ////////////////////////////////////////////////
class AppCreatorEx : public TIProjectCreator
{
private:
 String UnitName;
 String ProjectName;
 TIToolServices * TS;
public:
 __fastcall AppCreatorEx(String PN, String UN, TIToolServices * T): ProjectName(PN), UnitName(UN), TS(T), TIProjectCreator(){};
 virtual _stdcall bool Existing(void);
 virtual AnsiString __stdcall GetFileName(void);
 virtual AnsiString __stdcall GetFileSystem(void);
 virtual AnsiString __stdcall NewProjectSource(const AnsiString ProjectName);
 virtual void __stdcall NewDefaultModule(void);
 virtual void __stdcall NewProjectResource(TIModuleInterface* Module);
};

// Function prototypes
void __fastcall InitCodeGeneration(void);
void __fastcall DoneCodeGeneration(void);
void __fastcall BinToHex(char *Binary, char *Text, int Count);
void __fastcall WriteBinaryAsText(TStream *Input, TStream *Output) ;
void _fastcall FmtWrite(TStream *Stream, char *Fmt,
                        const TVarRec *Args, const int Args_Size);
void __fastcall WriteSnipet(TStream *Stream, TCodeSnipet Snipet) ;
void __fastcall WriteIdent(TStream *Stream, long ResID,
                           const String VarType) ;
void __fastcall WriteMenuItems(TStream *Stream,
                               TMainItems MenuIndex) ;
void __fastcall WriteMethodDecl(TStream *Stream, long ResID);
void __fastcall WriteMenuMethodDecls(TStream *Stream,
                                     TMainItems MenuIndex);
void __fastcall WriteMethodHeader(TStream *Stream, long ResID) ;
void __fastcall WriteMenuMethods(TStream *Stream,
                                 TMainItems MenuIndex,
                                 TCodeSnipet BaseSnipet);
void __fastcall WriteGlyphData(TStream *Stream, long BitmapID);
TFileName* __fastcall GenerateProjectSource(TAppExpert *AppExpert);
void __fastcall GenerateHdrSourceFile(TAppExpert *AppExpert);
TFileName* __fastcall GenerateMainSourceFile(TAppExpert *AppExpert);
void __fastcall GenerateMainFormFile(TAppExpert *AppExpert);
bool __fastcall EditFilterInfo(String *Filter);
void __fastcall RemoveItems(TList &List, TMainItems MenuIndex);
bool __fastcall EditFilterInfo(String &Filter);

#endif	// App
