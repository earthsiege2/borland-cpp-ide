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
|    This module is a dialog box that implements the service (servent)    |
| getXbyY functions.  It simply accepts a service and protocol and tells  |
| you what port they reside on, if any.  Although Winsock is supposed to  |
| let you specify a NULL protocol parameter, some of the current Winsock  |
| implementations don't seem to allow this.                               |                                                         |
\*-----------------------------------------------------------------------*/

#include <owl/pch.h>
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#include "dlgsrvc.h"

//********************************************************************************************
DEFINE_RESPONSE_TABLE1(DlgConvertService, TDialog)
  EV_CHILD_NOTIFY(IDC_BTN_CONVERT, BN_CLICKED, CmBtnConvert),
  EV_MESSAGE(MSG_SERVICE_NOTIFY, DoNotification),
END_RESPONSE_TABLE;

DlgConvertService::DlgConvertService(TWindow* parent, TResId resId, TModule* module)
:
  TDialog(parent, resId, module),
  myPresentState(nIdle)
{
  editService  = new TEdit  (this, IDC_EDIT_SERVICE,  255);
  editProtocol = new TEdit  (this, IDC_EDIT_PROTOCOL,  20);
  editPort     = new TEdit  (this, IDC_EDIT_PORT,      20);
  staticStatus = new TStatic(this, IDC_STATIC_STATUS, 32);
  btnConvert   = new TButton(this, IDC_BTN_CONVERT);
}



void DlgConvertService::SetupWindow()
{
  TDialog::SetupWindow();
}


TResult DlgConvertService::DoNotification(WPARAM, LPARAM lParam)
{
  char szPortOutput[256];
  int  nError = (int)WSAGETASYNCERROR(lParam);

  ::MessageBeep(10);
  if (nError) {
    MessageBox(TSocketError(nError).AppendError("Error looking up service."), "Error", MB_OK);
  }
  else {
    wsprintf(szPortOutput, "%d", TWinSock::Dll()->ntohs(myServiceManager.ServiceEntry->s_port));
    editPort->SetWindowText(szPortOutput);
    editProtocol->SetWindowText(myServiceManager.ServiceEntry->s_proto);
  }
  GoToIdleState();
  return 1;
}

void DlgConvertService::CmBtnConvert()
{
  char  szServiceInput[32];
  char  szProtocolInput[32];
  char*  szProtocolInputPtr;
  int   nError;
  HANDLE hServiceRequest;

  if (myPresentState == nWaitingForService) {
    myServiceManager.CancelServiceRequest(); //Cancels the most recent request.
    GoToIdleState();
    return;
  }
  GoToWaitingForServiceState();
  editPort->Clear(); //Clear the text.
  editService->GetWindowText(szServiceInput, 32);
  editProtocol->GetWindowText(szProtocolInput, 32);
  btnConvert->SetWindowText("Cancel");

  // The follwing code isn't common in real-life applications.  Usually, the
  //  application knows what service and protocol it is looking for, and so
  //  doesn't have to do this Null-testing logic:
  //
  if (szProtocolInput[0])
    szProtocolInputPtr = szProtocolInput;
  else
    szProtocolInputPtr = 0; //Need to do this to allow user to let Winsock find ANY port for the service.

  nError = myServiceManager.GetServiceAsync(*this, hServiceRequest, szServiceInput, szProtocolInputPtr);
  if (nError == WINSOCK_ERROR) {
    MessageBox(TSocketError(myServiceManager.GetLastError()).GetReasonString(), "Error", MB_OK);
    GoToIdleState();
  }
}


void DlgConvertService::CmOk()
{
  if (myPresentState != nIdle) {
    CmBtnConvert();  //Causes a cancellation of service request.
  }
  TDialog::CmOk(); //We are done and can close this dialog.
}

void DlgConvertService::GoToIdleState()
{
  btnConvert->SetWindowText("--> Convert -->");
  staticStatus->SetWindowText("Status: Idle");
  myPresentState = nIdle;
}

void DlgConvertService::GoToWaitingForServiceState()
{
  btnConvert->SetWindowText("Cancel");
  staticStatus->SetWindowText("Status: Waiting for service...");
  myPresentState = nWaitingForService;
}
