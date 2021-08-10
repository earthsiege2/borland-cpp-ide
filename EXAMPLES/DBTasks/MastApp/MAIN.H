//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Buttons.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
#ifndef __MAIN_H
#define __MAIN_H
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#ifndef WindowsHPP
#include <windows.hpp>
#endif

#ifndef MessagesHPP
#include <messages.hpp>
#endif

#ifndef SysUtilsHPP
#include <sysutils.hpp>
#endif

#ifndef ClassesHPP
#include <classes.hpp>
#endif

#ifndef GraphicsHPP
#include <graphics.hpp>
#endif

#ifndef ControlsHPP
#include <controls.hpp>
#endif

#ifndef FormsHPP
#include <forms.hpp>
#endif

#ifndef DialogsHPP
#include <dialogs.hpp>
#endif

#ifndef MenusHPP
#include <menus.hpp>
#endif

#ifndef ExtCtrlsHPP
#include <extctrls.hpp>
#endif

#ifndef ButtonsHPP
#include <buttons.hpp>
#endif

#include <bde.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:
    TMainMenu *MainMenu;
    TMenuItem *FileMenu;
    TMenuItem *FileNewOrder;
    TMenuItem *N5;
    TMenuItem *FilePrintReport;
    TMenuItem *FilePrinterSetup;
    TMenuItem *N4;
    TMenuItem *FileExit;
    TMenuItem *ViewMenu;
    TMenuItem *ViewOrders;
    TMenuItem *ViewPartsInventory;
    TMenuItem *N7;
    TMenuItem *ViewStayOnTop;
    TMenuItem *N1;
    TMenuItem *ViewLocal;
    TMenuItem *ViewRemote;
    TMenuItem *HelpMenu;
    TMenuItem *HelpContents;
    TMenuItem *N6;
    TMenuItem *HelpAbout;
    TPrinterSetupDialog *PrinterSetup;
    TPanel *MainPanel;
    TSpeedButton *CloseBtn;
    TSpeedButton *HelpBtn;
    TSpeedButton *ReportBtn;
    TSpeedButton *PartsBtn;
    TSpeedButton *BrowseBtn;
    TSpeedButton *OrderBtn;
    void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall BrowseCustOrd(TObject *Sender);
	void __fastcall BrowseParts(TObject *Sender);
	void __fastcall ToggleStayOnTop(TObject *Sender);
	void __fastcall NewOrder(TObject *Sender);
	void __fastcall CloseApp(TObject *Sender);
	void __fastcall ViewLocalClick(TObject *Sender);
	void __fastcall ViewRemoteClick(TObject *Sender);
	void __fastcall AboutClick(TObject *Sender);
	void __fastcall HelpContentsClick(TObject *Sender);
	void __fastcall HelpBtnClick(TObject *Sender);
	void __fastcall ViewMenuClick(TObject *Sender);
	void __fastcall ReportBtnClick(TObject *Sender);
        void __fastcall FilePrinterSetupClick(TObject *Sender);
        void __fastcall FilePrintReportClick(TObject *Sender);
private:        // private user declarations
     void CloseAllWindows();
public:         // public user declarations
    virtual __fastcall TMainForm(TComponent* Owner);
    void __fastcall PrintInvoiceReport(bool Preview);
    void __fastcall PrintOrderReport(bool Preview);
    void __fastcall PrintCustomerReport(bool Preview);
};                           
//---------------------------------------------------------------------------
extern TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
