//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.8  $
//
// Sample illustrating the use of OCXes in dialogs - Implements TMyOcxDialog
//
// NOTE: In order to run this example you MUST first install the Visual 
//       Components OCX controls Formula One Spread Sheet and First 
//       Impression Chart.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <stdio.h>
#include "ocxdlg.h"
#include "ocxdlgap.rh"     
#include "vcf132.cxx"
#include "vcfi32.cxx"

//
//
//
const int RowCount = 5;
const int ColCount = 4;
const char progIdWorkbook[] = "VCF1.VCF1Ctrl.1";
const char progIdChart[] = "VCFI.VCFiCtrl.1";
GUID  guidWorkbook = CLSID_NULL;
GUID  guidChart = CLSID_NULL;

//
//
//
DEFINE_RESPONSE_TABLE1(TMyOcxDialog, TOleDialog)
  EV_CHILD_NOTIFY( IDC_PIE_RAD,   BN_CLICKED, EvGraphMode),
  EV_CHILD_NOTIFY( IDC_GRAPH_RAD, BN_CLICKED, EvGraphMode),
END_RESPONSE_TABLE;

//
//
//
TMyOcxDialog::TMyOcxDialog(TWindow* parent) : TOleDialog(parent, IDD_CLIENT)
{}

//
//
//
void
TMyOcxDialog::SetupWindow()
{
  TOleDialog::SetupWindow();

  // Retrieve CLSID of OCXes
  //
  ::CLSIDFromProgID(TString(progIdWorkbook), &guidWorkbook);
  ::CLSIDFromProgID(TString(progIdChart), &guidChart);

  // Retrieve TOcControl objects representing the respective OCXes
  // of our dialog..
  //
  pWorkbook = GetOcControlOfOCX(guidWorkbook);
  pChart = GetOcControlOfOCX(guidChart);

  // Bind to each OCX's primary IDispatch interface via proxy objects
  //
  Chart.Bind(pChart->GetCtlDispatch());
  Workbook.Bind(pWorkbook->GetCtlDispatch());

  // Init Workbook/Chart with some data
  //
  Workbook.SetShowTabs(F1TabsOff);
  Workbook.SetMinRow(1);
  Workbook.SetMaxRow(RowCount);
  Workbook.SetMinCol(1);
  Workbook.SetMaxCol(ColCount);
	       
  for (int row=1; row <= RowCount; row++) {
    Workbook.SetRow(row);	
    Chart.SetRow(row);
    for (int col=1; col <= ColCount; col++) {
      Workbook.SetCol(col);
      Chart.SetColumn(col);
      Workbook.SetFormula(string("RAND()*100"));
      Workbook.Recalc();
    }	
  }
  Chart.SetRepaint(true);	

  // Adjust Main Window 
  //
  TRect drect;
  TRect srect;
  GetWindowRect(drect);
  AdjustWindowRectEx(drect, Parent->GetStyle(), false, Parent->GetExStyle());
  Parent->SetWindowPos(0, drect, SWP_NOMOVE|SWP_NOZORDER|SWP_SHOWWINDOW);
}

//
//
bool
TMyOcxDialog::EvOcCtrlCustomEvent(TCtrlCustomEvent* pev)
{
  if (pev->Ctrl == pWorkbook) {
    if (pev->Args->DispId == 0x4 /*SelChange()*/) {

      // Update chart from data retrieved from workbook
      //
      for (int row = 1; row <= RowCount; row++) {
        Chart.SetColumn(Workbook.GetCol());
        for (int col = 1; col <= ColCount; col++) {
          Chart.SetColumn(Workbook.GetCol());
          Chart.SetData(TAutoVal(Workbook.GetNumber()));
        }
      }
    }
  }
  return true;
}

//
// Toggle between 3D Pie chart and 3D Graph Mode
//
void
TMyOcxDialog::EvGraphMode()
{
  if (IsDlgButtonChecked(IDC_PIE_RAD)) 
    Chart.SetChartType(VtChChartType3dPie);
  else 
    Chart.SetChartType(VtChChartType3dBar);
}
