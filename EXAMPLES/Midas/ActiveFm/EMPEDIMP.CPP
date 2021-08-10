//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// This project demonstrates using client datasets in an ActiveForm.
// The ActiveForm in this project works just like the client in the
// EmpEdit example.  Before compiling and using this Active Library you
// should compile and run the Srvr example from the EmpEdit project group.
//
// For information on deploying ActiveForms, look for
// "ActiveX control:and .INF file, delpolying on the web" in the online
// help index.
//
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <atl\atlvcl.h>

#include "EmpEdImp.h"
#include "RECERROR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TEmpEditX *EmpEditX;
//---------------------------------------------------------------------------
__fastcall TEmpEditX::TEmpEditX(HWND ParentWindow)
    : TActiveForm(ParentWindow)
{
}
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::_set_Font(IFontDisp* Value)
{
  try
  {
     const DISPID dispid = -512;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     SetOleFont(m_VclCtl->Font, Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_Active(VARIANT_BOOL* Value)
{
  try
  {
    *Value = m_VclCtl->Active;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_AutoScroll(VARIANT_BOOL* Value)
{
  try
  {
    *Value = m_VclCtl->AutoScroll;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_AxBorderStyle(
  TxActiveFormBorderStyle* Value)
{
  try
  {
    *Value = (TxActiveFormBorderStyle)(m_VclCtl->AxBorderStyle);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_Caption(BSTR* Value)
{
  try
  {
    *Value = WideString(m_VclCtl->Caption).Copy();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_Color(::OLE_COLOR* Value)
{
  try
  {
    *Value = (OLE_COLOR)(m_VclCtl->Color);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_Cursor(short* Value)
{
  try
  {
    *Value = (short)(m_VclCtl->Cursor);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_DropTarget(VARIANT_BOOL* Value)
{
  try
  {
    *Value = m_VclCtl->DropTarget;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_Enabled(VARIANT_BOOL* Value)
{
  try
  {
    *Value = m_VclCtl->Enabled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_Font(IFontDisp** Value)
{
  try
  {
    _di_IFontDisp Temp;
    GetOleFont(m_VclCtl->Font, Temp);
    Temp->AddRef();
    *Value = Temp;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_HelpFile(BSTR* Value)
{
  try
  {
    *Value = WideString(m_VclCtl->HelpFile).Copy();
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_KeyPreview(VARIANT_BOOL* Value)
{
  try
  {
    *Value = m_VclCtl->KeyPreview;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_PixelsPerInch(long* Value)
{
  try
  {
    *Value = (long)(m_VclCtl->PixelsPerInch);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_PrintScale(TxPrintScale* Value)
{
  try
  {
    *Value = (TxPrintScale)(m_VclCtl->PrintScale);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_Scaled(VARIANT_BOOL* Value)
{
  try
  {
    *Value = m_VclCtl->Scaled;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_Visible(VARIANT_BOOL* Value)
{
  try
  {
    *Value = m_VclCtl->Visible;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::get_WindowState(TxWindowState* Value)
{
  try
  {
    *Value = (TxWindowState)(m_VclCtl->WindowState);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_AutoScroll(VARIANT_BOOL Value)
{
  try
  {
     const DISPID dispid = 2;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->AutoScroll = Value;
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_AxBorderStyle(
  TxActiveFormBorderStyle Value)
{
  try
  {
     const DISPID dispid = 3;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->AxBorderStyle = (TActiveFormBorderStyle)(Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_Caption(BSTR Value)
{
  try
  {
     const DISPID dispid = -518;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->Caption = AnsiString(Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_Color(::OLE_COLOR Value)
{
  try
  {
     const DISPID dispid = -501;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->Color = (TColor)(Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_Cursor(short Value)
{
  try
  {
     const DISPID dispid = 12;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->Cursor = (TCursor)(Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_DropTarget(VARIANT_BOOL Value)
{
  try
  {
     const DISPID dispid = 9;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->DropTarget = Value;
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_Enabled(VARIANT_BOOL Value)
{
  try
  {
     const DISPID dispid = -514;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->Enabled = Value;
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_Font(IFontDisp* Value)
{
  try
  {
     const DISPID dispid = -512;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     SetOleFont(m_VclCtl->Font, Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_HelpFile(BSTR Value)
{
  try
  {
     const DISPID dispid = 10;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->HelpFile = AnsiString(Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_KeyPreview(VARIANT_BOOL Value)
{
  try
  {
     const DISPID dispid = 4;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->KeyPreview = Value;
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_PixelsPerInch(long Value)
{
  try
  {
     const DISPID dispid = 5;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->PixelsPerInch = (int)(Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_PrintScale(TxPrintScale Value)
{
  try
  {
     const DISPID dispid = 6;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->PrintScale = (TPrintScale)(Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_Scaled(VARIANT_BOOL Value)
{
  try
  {
     const DISPID dispid = 7;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->Scaled = Value;
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_Visible(VARIANT_BOOL Value)
{
  try
  {
     const DISPID dispid = 1;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->Visible = Value;
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------

STDMETHODIMP TEmpEditXImpl::set_WindowState(TxWindowState Value)
{
  try
  {
     const DISPID dispid = 11;
     if (FireOnRequestEdit(dispid) == S_FALSE)
       return S_FALSE;
     m_VclCtl->WindowState = (TWindowState)(Value);
     FireOnChanged(dispid);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_IEmpEditX);
  }
  return S_OK;
};
//---------------------------------------------------------------------------


void __fastcall TEmpEditXImpl::ActivateEvent(TObject *Sender)
{
  Fire_OnActivate();
};
//---------------------------------------------------------------------------

void __fastcall TEmpEditXImpl::ClickEvent(TObject *Sender)
{
  Fire_OnClick();
};
//---------------------------------------------------------------------------

void __fastcall TEmpEditXImpl::CreateEvent(TObject *Sender)
{
  Fire_OnCreate();
};
//---------------------------------------------------------------------------

void __fastcall TEmpEditXImpl::DblClickEvent(TObject *Sender)
{
  Fire_OnDblClick();
};
//---------------------------------------------------------------------------

void __fastcall TEmpEditXImpl::DeactivateEvent(TObject *Sender)
{
  Fire_OnDeactivate();
};
//---------------------------------------------------------------------------

void __fastcall TEmpEditXImpl::DestroyEvent(TObject *Sender)
{
  Fire_OnDestroy();
};
//---------------------------------------------------------------------------

void __fastcall TEmpEditXImpl::PaintEvent(TObject *Sender)
{
  Fire_OnPaint();
};
//---------------------------------------------------------------------------
void __fastcall TEmpEditX::QueryButtonClick(TObject *Sender)
{
  // Get data from the server.  The number of records returned is dependent on
  // the PacketRecords property of TClientDataSet.  If PacketRecords is set
  // to -1, then all records are returned.  Otherwise, as the user scrolls
  // through the data, additional records are returned in separate data packets.
  //

  Employees->Close();
  Employees->Open();
}
//---------------------------------------------------------------------------
void __fastcall TEmpEditX::UpdateButtonClick(TObject *Sender)
{
  // Apply any edits.  The parameter indicates the number of errors which
  // are allowed before the updating is aborted.  A value of -1 indicates that
  // all successful updates be applied regardless of the number of errors.
  //

  Employees->ApplyUpdates(-1);
}
//---------------------------------------------------------------------------
void __fastcall TEmpEditX::UndoButtonClick(TObject *Sender)
{
  // Here we demonstrated a new feature in TClientDataSet, the ability to undo
  // changes in reverse order.  The parameter indicates if the cursor should
  // be repositioned to the record associated with the change.
  //

  Employees->UndoLastChange(true);
}
//---------------------------------------------------------------------------
void __fastcall TEmpEditX::EmployeesReconcileError(
      TCustomClientDataSet *DataSet, EReconcileError *E,
      TUpdateKind UpdateKind, TReconcileAction &Action)
{
  // This is the event handler which is called when there are errors during the
  // update process.  To demonstrate, you can create an error by running two
  // copies of this application and modifying the same record in each one.
  // Here we use the standard reconcile error dialog from the object repository.
  //

  Action = HandleReconcileError(Owner, DataSet, UpdateKind, E);
}
//---------------------------------------------------------------------------
void __fastcall TEmpEditX::EmpDataDataChange(TObject *Sender,
      TField *Field)
{
  // This code is used to update the status bar to show the number of records
  // that have been retrieved and our relative position with the dataset.
  //

  if(Employees->Active)
    RecInd->Caption = Format(" %d of %d ", ARRAYOFCONST((Employees->RecNo, Employees->RecordCount)) );
}
//---------------------------------------------------------------------------

