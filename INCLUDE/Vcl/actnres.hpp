// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ActnRes.pas' rev: 6.00

#ifndef ActnResHPP
#define ActnResHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ExtActns.hpp>	// Pascal unit
#include <ActnList.hpp>	// Pascal unit
#include <StdActns.hpp>	// Pascal unit
#include <ImgList.hpp>	// Pascal unit
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
#pragma link "dclact.lib"

namespace Actnres
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TStandardActions;
class PASCALIMPLEMENTATION TStandardActions : public Classes::TDataModule 
{
	typedef Classes::TDataModule inherited;
	
__published:
	Actnlist::TActionList* ActionList1;
	Stdactns::TEditCut* EditCut1;
	Stdactns::TEditCopy* EditCopy1;
	Stdactns::TEditPaste* EditPaste1;
	Stdactns::TWindowArrange* WindowArrange1;
	Stdactns::TWindowCascade* WindowCascade1;
	Stdactns::TWindowClose* WindowClose1;
	Stdactns::TWindowMinimizeAll* WindowMinimizeAll1;
	Stdactns::TWindowTileHorizontal* WindowTileHorizontal1;
	Stdactns::TWindowTileVertical* WindowTileVertical1;
	Controls::TImageList* ImageList1;
	Stdactns::TEditDelete* EditDelete1;
	Stdactns::TEditSelectAll* EditSelectAll1;
	Stdactns::TEditUndo* EditUndo1;
	Stdactns::THelpContents* HelpContents1;
	Stdactns::THelpOnHelp* HelpOnHelp1;
	Stdactns::THelpTopicSearch* HelpTopicSearch1;
	Stdactns::TFileExit* FileExit1;
	Stdactns::TFileOpen* FileOpen1;
	Stdactns::TFilePrintSetup* FilePrintSetup1;
	Stdactns::TFileSaveAs* FileSaveAs1;
	Extactns::TRichEditBold* RichEditBold1;
	Extactns::TRichEditItalic* RichEditItalic1;
	Extactns::TRichEditUnderline* RichEditUnderline1;
	Stdactns::TSearchFind* SearchFind1;
	Stdactns::TSearchFindNext* SearchFindNext1;
	Stdactns::TSearchReplace* SearchReplace1;
	Extactns::TRichEditAlignCenter* RichEditAlignCenter1;
	Extactns::TRichEditAlignLeft* RichEditAlignLeft1;
	Extactns::TRichEditAlignRight* RichEditAlignRight1;
	Extactns::TRichEditBullets* RichEditBullets1;
	Extactns::TRichEditStrikeOut* RichEditStrikeOut1;
	Stdactns::TColorSelect* ColorSelect1;
	Stdactns::TFontEdit* FontEdit1;
	Extactns::TOpenPicture* OpenPicture1;
	Extactns::TSavePicture* SavePicture1;
	Extactns::TFileRun* FileRun1;
	Extactns::TPreviousTab* PreviousTab1;
	Extactns::TNextTab* NextTab1;
	Stdactns::TSearchFindFirst* SearchFindFirst1;
	Stdactns::THelpContextAction* HelpContextAction1;
	Extactns::TBrowseURL* BrowseURL1;
	Extactns::TDownLoadURL* DownLoadURL1;
	Extactns::TListControlCopySelection* ListControlCopySelection1;
	Extactns::TListControlDeleteSelection* ListControlDeleteSelection1;
	Extactns::TListControlSelectAll* ListControlSelectAll1;
	Extactns::TListControlClearSelection* ListControlClearSelection1;
	Extactns::TListControlMoveSelection* ListControlMoveSelection1;
	Extactns::TSendMail* SendMail1;
	Stdactns::TPrintDlg* PrintDlg1;
public:
	#pragma option push -w-inl
	/* TDataModule.Create */ inline __fastcall virtual TStandardActions(Classes::TComponent* AOwner) : Classes::TDataModule(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataModule.CreateNew */ inline __fastcall virtual TStandardActions(Classes::TComponent* AOwner, int Dummy) : Classes::TDataModule(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TDataModule.Destroy */ inline __fastcall virtual ~TStandardActions(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TStandardActions* StandardActions;

}	/* namespace Actnres */
using namespace Actnres;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ActnRes
