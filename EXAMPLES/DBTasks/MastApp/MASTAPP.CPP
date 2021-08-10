//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEDATAMODULE("Datamod.cpp", MastData);
USEFORM("about.cpp", AboutBox);
USEFORM("brcstord.cpp", BrCustOrdForm);
USEFORM("brparts.cpp", BrPartsForm);
USEFORM("custrpt.cpp", CustomerByInvoiceReport);
USEFORM("edcust.cpp", EdCustForm);
USEFORM("edorders.cpp", EdOrderForm);
USEFORM("edparts.cpp", EdPartsForm);
USEFORM("invcrpt.cpp", InvoiceByOrderNoReport);
USEFORM("main.cpp", MainForm);
USEFORM("orderrpt.cpp", OrdersByDateReport);
USEFORM("pickdate.cpp", BrDateForm);
USEFORM("pickinvc.cpp", PickOrderNoDlg);
USEFORM("pickrep.cpp", PickRpt);
USEFORM("qrycust.cpp", QueryCustDlg);
USEFORM("splash.cpp", SplashForm);
USEFORM("srchdlg.cpp", SearchDlg);
//---------------------------------------------------------------------------
#include "splash.h"

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
     try
     {
       SplashForm = new TSplashForm(Application);
       SplashForm->Show();
       SplashForm->Update();

       Application->Initialize();
       Application->Title = "Marine Adventures Order Entry";
       Application->HelpFile = "Mastapp.hlp";
       Application->CreateForm(__classid(TMainForm), &MainForm);
       Application->CreateForm(__classid(TMastData), &MastData);
       Application->CreateForm(__classid(TAboutBox), &AboutBox);
       Application->CreateForm(__classid(TQueryCustDlg), &QueryCustDlg);
       Application->CreateForm(__classid(TBrPartsForm), &BrPartsForm);
       Application->CreateForm(__classid(TBrCustOrdForm), &BrCustOrdForm);
       Application->CreateForm(__classid(TEdCustForm), &EdCustForm);
       Application->CreateForm(__classid(TBrDateForm), &BrDateForm);
       Application->CreateForm(__classid(TSearchDlg), &SearchDlg);
       Application->CreateForm(__classid(TEdPartsForm), &EdPartsForm);
       Application->CreateForm(__classid(TEdOrderForm), &EdOrderForm);
       Application->CreateForm(__classid(TPickRpt), &PickRpt);
       Application->CreateForm(__classid(TPickOrderNoDlg), &PickOrderNoDlg);
       Application->CreateForm(__classid(TInvoiceByOrderNoReport), &InvoiceByOrderNoReport);
       Application->CreateForm(__classid(TCustomerByInvoiceReport), &CustomerByInvoiceReport);
       Application->CreateForm(__classid(TOrdersByDateReport), &OrdersByDateReport);
       SplashForm->Hide();
       SplashForm->Close();
       Application->Run();
   }
   catch (Exception &exception)
   {
       Application->ShowException(&exception);
   }
       return 0;
}
//---------------------------------------------------------------------------
