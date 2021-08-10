//----------------------------------------------------------------------------
//  Project OcxDlg
//  Borland International, Inc.
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    OcxDlg Application
//  FILE:         OcxDlg.cpp
//  AUTHOR:       Chris McConn
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TMyOcxDialog (TDialog).
//
//  In order to run this example you MUST first install the Visual Components
//  OCX controls Formula One Spread Sheet and First Impression Chart.
//----------------------------------------------------------------------------

#include <owl/pch.h>
#include <stdio.h>

#include "OcxDlg.h"

#include "OcxDlgAp.rh"     // Definition of all resources.


#define ROWS 5
#define COLUMNS 4

// LOCALE ID
static LCID lcid = LOCALE_SYSTEM_DEFAULT;

//============================================================================
// TVariantArg.  There are many types of Variant arguments possible, see
// class TAutoVal in \bc5\include\ocf\autodefs.h
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void
TVariantArg::Init(char* str)
{
  // NOTE: VariantClear will free the BSTR
  V_VT(this) = VT_BSTR;
  V_BSTR(this) = SysAllocString(str);
}

void
TVariantArg::Init(IDispatch* pDispatch)
{
  V_VT(this) = VT_DISPATCH;
  V_DISPATCH(this) = pDispatch;
}

void
TVariantArg::Init(bool b)
{
  V_VT(this) = VT_BOOL;
  V_BOOL(this) = b;
}

void
TVariantArg::Init(int i)
{
  V_VT(this) = VT_I2;
  V_I2(this) = i;
}

void
TVariantArg::Init(long l)
{
  V_VT(this) = VT_I4;
  V_I4(this) = l;
}

TVariantArg&
TVariantArg::operator = (int i)
{
  V_I2(this) = i;
}

TVariantArg&
TVariantArg::operator = (long l)
{
  V_I4(this) = l;
}

//============================================================================
//{{TMyOcxDialog Implementation}}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//============================================================================
// Build a response table for all messages/commands handled
// by the application.
DEFINE_RESPONSE_TABLE1(TMyOcxDialog, TOleDialog)
  EV_CHILD_NOTIFY( IDC_PIE_RAD,   BN_CLICKED, EvGraphMode),
  EV_CHILD_NOTIFY( IDC_GRAPH_RAD, BN_CLICKED, EvGraphMode),
END_RESPONSE_TABLE;


//############################################################################
// TMyOcxDialog Constructors/Destructors

//============================================================================
TMyOcxDialog::TMyOcxDialog(TWindow* parent)
:
  TOleDialog(parent, IDD_CLIENT)
{
}

//============================================================================
TMyOcxDialog::~TMyOcxDialog()
{
}


//############################################################################
// virtual functions of TWindow

//============================================================================
void
TMyOcxDialog::SetupWindow()
{
  TOleDialog::SetupWindow();

  //------------------------------------------
  // Get an IDispatch for each OCX
  TOcDocument* ocdoc = GetOcDoc();
  TOcPartCollection& parts = ocdoc->GetParts();
  int count = parts.Count();
  if (count == 2) {
    TOcPartCollectionIter part_itr(parts);
    TOcPart* part1 = part_itr++;
    TOcPart* part2 = part_itr++;

    #if 0
      // This code can be used to get a short description 
      // for each control.
      TString desc(part1->GetServerName(pnShort));
      char* buf = desc;
      MessageBox(buf,"Control 1",MB_OK);

      desc = part2->GetServerName(pnShort);
      buf = desc;
      MessageBox(buf,"Control 2",MB_OK);
    #endif

    // Since the SpreadSheet was inserted into the dialog
    // box 1st, we know it is the 1st control
    ptrTable = TYPESAFE_DOWNCAST(part1, TOcControl);
    ptrGraph = TYPESAFE_DOWNCAST(part2, TOcControl);
  }

  IBControl* tableface = ptrTable->GetBControlI();
  IBControl* graphface = ptrGraph->GetBControlI();

  tableface->GetCtrlDispatch(&ptrTableDisp);
  graphface->GetCtrlDispatch(&ptrGraphDisp);

  //-------------------------------------
  // Initialize the Spread Sheet Control

  // Get the ShowTabs Property value
  TVariantArg result;
  HRESULT hrStat = InvokeGet(ptrTableDisp, "ShowTabs", result);

  // Turn off Sheet tabs
  TVariantArg ivalue(0);
  hrStat = InvokePut(ptrTableDisp, "ShowTabs", ivalue);

  // Specify rows and columns for viewing
  ivalue=1;
  hrStat = InvokePut(ptrTableDisp, "MinRow", ivalue);
  ivalue=ROWS;
  hrStat = InvokePut(ptrTableDisp, "MaxRow",   ivalue);
  hrStat = InvokePut(ptrGraphDisp, "RowCount", ivalue);
  ivalue=1;
  hrStat = InvokePut(ptrTableDisp, "MinCol", ivalue);
  ivalue=COLUMNS;
  hrStat = InvokePut(ptrTableDisp, "MaxCol", ivalue);
  hrStat = InvokePut(ptrGraphDisp, "ColumnCount", ivalue);

  // Specify formulas for each cell
  for (int row = 1; row <= ROWS; row++) {
    ivalue=row;
    hrStat = InvokePut(ptrTableDisp, "Row", ivalue);
    hrStat = InvokePut(ptrGraphDisp, "Row", ivalue);
    for (int col = 1; col <= COLUMNS; col++) {
      ivalue=col;
      hrStat = InvokePut(ptrTableDisp, "Col",    ivalue);
      hrStat = InvokePut(ptrGraphDisp, "Column", ivalue);
      TVariantArg svalue("RAND()*100");
      hrStat = InvokePut(ptrTableDisp, "Formula", svalue);
      hrStat = InvokeMethod(ptrTableDisp, "Recalc", result);
      hrStat = InvokeGet(ptrTableDisp, "Number",  result);
      hrStat = InvokePut(ptrGraphDisp, "Data",    result);
    }
  }

  //-------------------------------------
  // Initialize the Graph Control

  // Force Chart to Redraw after any change
  TVariantArg bvalue(true);
  hrStat = InvokePut(ptrGraphDisp, "Repaint", bvalue);

  //-------------------
  // Adjust Main Window 
  TRect drect;
  TRect srect;
  GetWindowRect(drect);
  AdjustWindowRectEx(drect, Parent->GetStyle(), false, Parent->GetExStyle());
  Parent->SetWindowPos(0, drect, SWP_NOMOVE|SWP_NOZORDER|SWP_SHOWWINDOW);
}

//============================================================================
void
TMyOcxDialog::Paint(TDC& dc, bool repaint, TRect&)
{
  EvGraphMode();
}

//############################################################################
// Ctrl event specific messages

//============================================================================
// Catch custom events from the OCX controls
bool
TMyOcxDialog::EvOcCtrlCustomEvent(TCtrlCustomEvent* pev)
{
  if (pev->Ctrl == ptrTable) {
    if (pev->Args->DispId == 0x4 /*SelChange()*/) {
      // Write to graph
      TVariantArg result;
      HRESULT hrStat;

      // Update Graph
      for (int row = 1; row <= ROWS; row++) {
        hrStat = InvokeGet(ptrTableDisp, "Row",    result);
        hrStat = InvokePut(ptrGraphDisp, "Row",    result);
        for (int col = 1; col <= COLUMNS; col++) {
          hrStat = InvokeGet(ptrTableDisp, "Col",    result);
          hrStat = InvokePut(ptrGraphDisp, "Column", result);
          hrStat = InvokeMethod(ptrTableDisp, "Recalc", result);
          hrStat = InvokeGet(ptrTableDisp, "Number", result);
          hrStat = InvokePut(ptrGraphDisp, "Data",   result);
        }
      }
    }
  }
  return true;
}

//############################################################################
// Dialog Control response functions

//============================================================================
// Toggle between 3D Pie chart and 3D Graph Mode
void
TMyOcxDialog::EvGraphMode()
{
  if (IsDlgButtonChecked(IDC_PIE_RAD)) {
    TVariantArg ivalue(13);
    HRESULT hrStat = InvokePut(ptrGraphDisp, "ChartType", ivalue);
  }
  else {
    TVariantArg ivalue(0);
    HRESULT hrStat = InvokePut(ptrGraphDisp, "ChartType", ivalue);
  }
}

//============================================================================
// Get the Dispatch ID of the Property or Method
HRESULT
TMyOcxDialog::GetDispID(IDispatch* pDispatch, char* name, DISPID& dispid)
{
  OLECHAR wname[128];
  OLECHAR* names[1];

  MultiByteToWideChar(CP_ACP, 0, name, -1, wname, 128);
  names[0] = wname;

  return pDispatch->GetIDsOfNames(IID_NULL, names, 1, lcid, &dispid);
}

//============================================================================
// Invokes a method with no parameters
HRESULT
TMyOcxDialog::InvokeMethod(IDispatch* pDispatch, char* name, TVariantArg& result)
{
  HRESULT hResult;
  UINT nErr = 0;

  // Initialize Dispatch ID
  //
  DISPID dispid;
  hResult = GetDispID(pDispatch, name, dispid);
  if (FAILED(hResult))
    return hResult;

  // Initialize params & Invoke the method
  //
  DISPPARAMS dispParams = { 0, 0, 0, 0};
  return pDispatch->Invoke(dispid, IID_NULL, lcid, DISPATCH_METHOD,
                          &dispParams, &result, 0, &nErr);
}

//============================================================================
// Invokes a method with a single parameter...
HRESULT
TMyOcxDialog::InvokeMethod(IDispatch* pDispatch, char* name,
             TVariantArg& varg, TVariantArg& result)
{
  HRESULT hResult;
  UINT nErr = 0;

  // Initialize params
  //
  DISPPARAMS dispParams;
  dispParams.rgvarg = &varg;
  dispParams.rgdispidNamedArgs = 0;
  dispParams.cArgs = 1;
  dispParams.cNamedArgs = 0;

  // Init Dispatch ID
  //
  DISPID dispid;
  hResult = GetDispID(pDispatch, name, dispid);
  if (FAILED(hResult))
    return hResult;

  return pDispatch->Invoke(dispid, IID_NULL, lcid, DISPATCH_METHOD,
                          &dispParams, &result, 0, &nErr);
}

//============================================================================
// Invokes a method with a multiple parameters
HRESULT
TMyOcxDialog::InvokeMethod(IDispatch* pDispatch, char* name,
             TVariantArg* arrayVarg, int paramCount, TVariantArg& result)
{
  HRESULT hResult;
  UINT nErr = 0;

  // Initialize params
  //
  DISPPARAMS dispParams;
  dispParams.rgvarg = arrayVarg;
  dispParams.rgdispidNamedArgs = 0;
  dispParams.cArgs = paramCount;
  dispParams.cNamedArgs = 0;

  // Init Dispatch ID
  //
  DISPID dispid;
  hResult = GetDispID(pDispatch, name, dispid);
  if (FAILED(hResult))
    return hResult;

  return pDispatch->Invoke(dispid, IID_NULL, lcid, DISPATCH_METHOD,
                          &dispParams, &result, 0, &nErr);
}

//============================================================================
// Invokes a Property/Get
HRESULT
TMyOcxDialog::InvokeGet(IDispatch* pDispatch, char* name, TVariantArg& result)
{
  HRESULT hResult;
  UINT nErr = 0;

  // Initialize Dispatch ID
  //
  DISPID dispid;
  hResult = GetDispID(pDispatch, name, dispid);
  if (FAILED(hResult))
    return hResult;

  // Initialize params & Invoke the method
  //
  DISPPARAMS dispParams = { 0, 0, 0, 0};
  return pDispatch->Invoke(dispid, IID_NULL, lcid, DISPATCH_PROPERTYGET,
                           &dispParams, &result, 0, &nErr);
}

//============================================================================
// Invokes a Property/Put
HRESULT
TMyOcxDialog::InvokePut(IDispatch* pDispatch, char* name, TVariantArg& param)
{
  HRESULT hResult;
  UINT nErr = 0;

  // Initialize Dispatch ID
  //
  DISPID dispid;
  DISPID dispidPropertyPut = DISPID_PROPERTYPUT;

  // Initialize params & Invoke the method
  //
  DISPPARAMS dispParams;
  dispParams.rgvarg = &param;
  dispParams.rgdispidNamedArgs = &dispidPropertyPut;
  dispParams.cArgs = 1;
  dispParams.cNamedArgs = 1;

  hResult = GetDispID(pDispatch, name, dispid);

  if (FAILED(hResult))
    return hResult;

  return pDispatch->Invoke(dispid, IID_NULL, lcid, DISPATCH_PROPERTYPUT,
                           &dispParams, 0, 0, &nErr);
}

