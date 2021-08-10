//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <typeinfo.h>
#include "main.h"
#include "Datamod.h"
#include "brcstord.h"
#include "brparts.h"
#include "edorders.h"
#include "qrycust.h"
#include "about.h"
#include "pickrep.h"
#include "pickinvc.h"
#include "custrpt.h"
#include "orderrpt.h"
#include "invcrpt.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
   ClientWidth = CloseBtn->Left + CloseBtn->Width + 1;
   ClientHeight = CloseBtn->Top + CloseBtn->Height;
   MainPanel->Align = alClient;
   // position the form at the top of display
   Left = 10;
   Top = 10;
}
//---------------------------------------------------------------------
void TMainForm::CloseAllWindows()
{
  int I;
  TForm *F;
  for (I = 0; I < Application->ComponentCount; I++)
  {
    if ( typeid(Application->Components[I]) == typeid(TForm) )
    {
      F = new TForm(Application->Components[I]);
      if (F != this && F->Visible)
       F->Close();
    }
  }
}


//---------------------------------------------------------------------------
void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
  Application->HelpCommand(HELP_QUIT,0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BrowseCustOrd(TObject *Sender)
{
  BrCustOrdForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BrowseParts(TObject *Sender)
{
  BrPartsForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ToggleStayOnTop(TObject *Sender)
{
    static_cast<TMenuItem*>(Sender)->Checked = !(static_cast<TMenuItem*>(Sender)->Checked);
    if (static_cast<TMenuItem*>(Sender)->Checked)
      MainForm->FormStyle = fsStayOnTop;
    else
      MainForm->FormStyle = fsNormal;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NewOrder(TObject *Sender)
{
   EdOrderForm->Enter();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseApp(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ViewLocalClick(TObject *Sender)
{
  CloseAllWindows();
  MastData->UseLocalData();
  ViewLocal->Checked = True;
  Caption = Application->Title + " (Paradox Data)";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ViewRemoteClick(TObject *Sender)
{
  CloseAllWindows();
  MastData->UseRemoteData();
  ViewRemote->Checked = True;
  Caption = Application->Title + " (Interbase)";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AboutClick(TObject *Sender)
{
  AboutBox->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HelpContentsClick(TObject *Sender)
{
  Application->HelpCommand(HELP_CONTENTS, 0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::HelpBtnClick(TObject *Sender)
{
  Application->HelpCommand(HELP_CONTENTS, 0);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ViewMenuClick(TObject *Sender)
{
  // Enable the Remote data menu item only if Interbase Server is running }
  ViewRemote->Enabled = ( FindWindow(NULL, "InterBase Server") != 0 );

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ReportBtnClick(TObject *Sender)
{
  if (PickRpt->ShowModal() == mrOk)
    switch(PickRpt->ReportType->ItemIndex)
    {
    	case 0: PrintCustomerReport(PickRpt->Preview);
        break;
        case 1: PrintOrderReport(PickRpt->Preview);
        break;
        case 2: PrintInvoiceReport (PickRpt->Preview);
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintCustomerReport(bool Preview)
{
	 MastData->CustByLastInvQuery->Open();
    if (Preview)
    	CustomerByInvoiceReport->CustomerByInvoiceRpt->Preview();
    else
    	CustomerByInvoiceReport->CustomerByInvoiceRpt->Print();
      
	 MastData->CustByLastInvQuery->Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintOrderReport(bool Preview)
{
	String FromToHeading("From \"%s\" To \"%s\"");

   QueryCustDlg->Msglab->Caption = "Print all orders ranging:";
   if ((int)QueryCustDlg->FromDate == (int)0) 
   	QueryCustDlg->FromDate = EncodeDate(1995, 01, 01);
   if ((int)QueryCustDlg->ToDate == (int)0)
   	QueryCustDlg->ToDate = QueryCustDlg->ToDate.CurrentDate();
   if (QueryCustDlg->ShowModal() == mrOk)
   {
   	MastData->OrdersByDateQuery->Close();
      
      MastData->OrdersByDateQuery->Params->ParamByName("FromDate")->AsDate = 
         QueryCustDlg->FromDate;
      MastData->OrdersByDateQuery->Params->ParamByName("ToDate")->AsDate = 
         QueryCustDlg->ToDate;
         
   	MastData->OrdersByDateQuery->Open();
      
      OrdersByDateReport->FromToHeading->Caption =
      	Format(FromToHeading, OPENARRAY(TVarRec,
         (DateToStr(QueryCustDlg->FromDate), DateToStr(QueryCustDlg->ToDate))));
         
      if (Preview)
      	OrdersByDateReport->OrdersByDateRpt->Preview();
      else
      	OrdersByDateReport->OrdersByDateRpt->Print();
         
   	MastData->OrdersByDateQuery->Close();
         
   }      
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PrintInvoiceReport(bool Preview)
{
	if (PickOrderNoDlg->ShowModal() == mrOk)
   	if (Preview)
      	InvoiceByOrderNoReport->InvoiceByOrderNoRpt->Preview();
      else
      	InvoiceByOrderNoReport->InvoiceByOrderNoRpt->Print();
}         
//---------------------------------------------------------------------------

void __fastcall TMainForm::FilePrinterSetupClick(TObject *Sender)
{
  PrinterSetup->Execute();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FilePrintReportClick(TObject *Sender)
{
  if (PickRpt->ShowModal() == mrOk)
    switch(PickRpt->ReportType->ItemIndex)
    {
    	case 0: PrintCustomerReport(PickRpt->Preview);
        break;
        case 1: PrintOrderReport(PickRpt->Preview);
        break;
        case 2: PrintInvoiceReport (PickRpt->Preview);
        break;
    }
}
//---------------------------------------------------------------------------

