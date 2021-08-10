/*-----------------------------------------------------------------------*\
| OWLSock Demo For Windows v1.0                                           |
--------------------------------------------------------------------------|
| Written By:  Paul Pedriana                                              |
| Date:        May 7, 1995.                                               |
| Copyright:   Copyright (c) 1995 by Paul Pedriana.  All Rights Reserved. |
| UserID(s):   70541,3223                                                 |
|              70541.3223@compuserve.com                                  |
--------------------------------------------------------------------------|
| This OWLSock demo is an application that demonstrates some features     |
| of OWLSock.  It uses only asynchronous (non-blocking) Winsock calls,    |
| and uses OWLSock socket 'external' notification rather than internal    |
| notification.  External notification is the way most Winsock apps do    |
| FD_XXX notifications; see the OWLSock docs for more info.               |
--------------------------------------------------------------------------|
| Notes on this module:                                                   |
|    This module is a dialog box that implements the host entry (hostent) |
| getXbyY functions.  It simply accepts an address in DNS format or       |
| dotted-decimal format and converts it to an IP address and shows you    |
| that address in dotted-decimal format.  Every TCP/IP program needs to   |
| be able to do this conversion.                                          | 
\*-----------------------------------------------------------------------*/

#include <owl/pch.h>
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#include "dlgaddr.h"

//
//
//
DEFINE_RESPONSE_TABLE1(DlgConvertAddress, TDialog)
  EV_CHILD_NOTIFY(IDC_BTN_CONVERT, BN_CLICKED, CmBtnConvert),
  EV_MESSAGE(MSG_HOST_INFO_NOTIFY, DoNotification),
END_RESPONSE_TABLE;

DlgConvertAddress::DlgConvertAddress(TWindow *parent, TResId resId, TModule *module)
:
  TDialog(parent, resId, module), myPresentState(nIdle)
{
}



void DlgConvertAddress::SetupWindow()
{
  editNameCtrl    = new TEdit(this, IDC_EDIT_NAME,      255);
  editAddressCtrl = new TEdit(this, IDC_EDIT_ADDRESS,    20);
  staticStatus    = new TStatic(this, IDC_STATIC_STATUS, 32);
  btnConvert      = new TButton(this, IDC_BTN_CONVERT);

  TDialog::SetupWindow();
}


LRESULT DlgConvertAddress::DoNotification(WPARAM, LPARAM lParam)
{
  char szAddressOutput[256];
  int  nError = (int)WSAGETASYNCERROR(lParam);

  ::MessageBeep(10);
  if (nError) {
    MessageBox(TSocketError(nError).AppendError("Error looking up host address."), "Error", MB_OK);
  }
  else {
    myHostInfoManager.HostEntryToAddress(myHostInfoManager.HostEntry, szAddressOutput);
    editAddressCtrl->SetWindowText(szAddressOutput);
  }
  GoToIdleState();
  return 1;
}


void DlgConvertAddress::CmBtnConvert()
{
  short  bAddressIsDottedDecimal;
  char   szAddressInput[256];
  int    nError;
  HANDLE hHostRequest;

  if (myPresentState == nWaitingForAddress){ //If user wanted to cancel the operation...
    myHostInfoManager.CancelHostRequest(); //Cancels the most recent request made by this HostInfoManager
    GoToIdleState();
    return;
  }
  GoToWaitingForAddressState();
  editAddressCtrl->Clear(); //Clear the text.
  editNameCtrl->GetWindowText(szAddressInput, 255);
  bAddressIsDottedDecimal = TINetSocketAddress::IsAddressDottedDecimal(szAddressInput);
  if(bAddressIsDottedDecimal){
    editAddressCtrl->SetWindowText(szAddressInput);  //User intered the address directly.
    GoToIdleState();
  }
  else{
    nError = myHostInfoManager.GetHostInfoAsync(*this, hHostRequest, szAddressInput);
    if(nError == WINSOCK_ERROR){
      MessageBox(TSocketError(myHostInfoManager.GetLastError()).GetReasonString(), "Error", MB_OK);
      GoToIdleState();
    }
  }
}


void DlgConvertAddress::CmOk()
{
  if(myPresentState != nIdle){
    CmBtnConvert();  //Causes a cancellation of the request.
  }
  TDialog::CmOk(); //We are done and can close this dialog.
}


void DlgConvertAddress::GoToIdleState()
{
  btnConvert->SetWindowText("--> Convert -->");
  staticStatus->SetWindowText("Status: Idle");
  myPresentState = nIdle;
}


void DlgConvertAddress::GoToWaitingForAddressState()
{
  btnConvert->SetWindowText("Cancel");
  staticStatus->SetWindowText("Status: Waiting for address...");
  myPresentState = nWaitingForAddress;
}



