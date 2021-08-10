// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DirSel.pas' rev: 6.00

#ifndef DirSelHPP
#define DirSelHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <QImgList.hpp>	// Pascal unit
#include <QExtCtrls.hpp>	// Pascal unit
#include <QComCtrls.hpp>	// Pascal unit
#include <QStdCtrls.hpp>	// Pascal unit
#include <QDialogs.hpp>	// Pascal unit
#include <QForms.hpp>	// Pascal unit
#include <QControls.hpp>	// Pascal unit
#include <QGraphics.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Types.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dirsel
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TDirSelDlg;
class PASCALIMPLEMENTATION TDirSelDlg : public Qforms::TForm 
{
	typedef Qforms::TForm inherited;
	
__published:
	Qextctrls::TPanel* Panel1;
	Qstdctrls::TButton* Button1;
	Qstdctrls::TButton* Button2;
	Qcomctrls::TTreeView* TV;
	Qimglist::TImageList* ImageList1;
	Qextctrls::TPanel* Panel2;
	Qextctrls::TPanel* Panel3;
	Qstdctrls::TLabel* Label1;
	Qextctrls::TPanel* Panel4;
	void __fastcall TVItemDoubleClick(System::TObject* Sender, Qcomctrls::TTreeNode* Node);
	void __fastcall TVExpanded(System::TObject* Sender, Qcomctrls::TTreeNode* Node);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall TVCustomDrawItem(Qcomctrls::TCustomViewControl* Sender, Qcomctrls::TCustomViewItem* Item, Qgraphics::TCanvas* Canvas, const Types::TRect &Rect, Qcomctrls::TCustomDrawState State, Qcomctrls::TCustomDrawStage Stage, bool &DefaultDraw);
	
private:
	AnsiString FRootDir;
	AnsiString FDir;
	void __fastcall AddDirectories(Qcomctrls::TTreeNode* Node, AnsiString Dir);
	AnsiString __fastcall GetAbsolutePath(Qcomctrls::TTreeNode* Node);
	void __fastcall SetDir(const AnsiString Value);
	void __fastcall SetRootDir(const AnsiString Value);
	
public:
	AnsiString __fastcall SelectedDir();
	__property AnsiString Directory = {read=FDir, write=SetDir};
	__property AnsiString RootDirectory = {read=FRootDir, write=SetRootDir};
public:
	#pragma option push -w-inl
	/* TCustomForm.Create */ inline __fastcall virtual TDirSelDlg(Classes::TComponent* AOwner) : Qforms::TForm(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.CreateNew */ inline __fastcall virtual TDirSelDlg(Classes::TComponent* AOwner, int Dummy) : Qforms::TForm(AOwner, Dummy) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TDirSelDlg(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWidgetControl.CreateParented */ inline __fastcall TDirSelDlg(Qt::QWidgetH* ParentWidget) : Qforms::TForm(ParentWidget) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dirsel */
using namespace Dirsel;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DirSel
