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
|    This module is a dialog box that implements a stream socket TCP      |
| connection.  It either connects to a given port and address by itself,  |
| or it can accept an already connected socket, e.g. a socket created by  |
| an accept call.                                                         |
|    Run another instance of this dialog on another computer and you can  |
| connect the two computers together and send data back and forth.        |
\*-----------------------------------------------------------------------*/
#include <owl/pch.h>
#if !defined(OWL_INPUTDIA_H)
# include <owl/inputdia.h>
#endif
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#include <stdlib.h>   //For atoi() call.
#include "dlgstrm.h"

//********************************************************************************************
DEFINE_RESPONSE_TABLE1(DlgSendStream, TDialog)
  EV_CHILD_NOTIFY(IDC_BTN_SEND, BN_CLICKED, CmBtnSend),
  EV_CHILD_NOTIFY(IDC_BTN_SEND_CLEAR, BN_CLICKED, CmBtnSendClear),
  EV_CHILD_NOTIFY(IDC_BTN_RECEIVE_CLEAR, BN_CLICKED, CmBtnReceiveClear),
  EV_CHILD_NOTIFY(IDC_BTN_CONNECT, BN_CLICKED, CmConnectDisconnect),
  EV_MESSAGE(MSG_HOST_INFO_NOTIFY, DoHostNotification),
  EV_MESSAGE(MSG_SOCKET_NOTIFY, DoSocketNotification),
END_RESPONSE_TABLE;

DlgSendStream::DlgSendStream(TWindow* parent, TResId resId, TModule* module)
:
  TDialog(parent, resId, module),
  myPresentState(nIdle),
  sAddressToConnectTo(0, INADDR_NONE),
  bDataSent(true)
{
  TINetSocketAddress ourSocketAddress; //same as INetSocketAddress(0, INADDR_ANY);

  myStreamSocket = new TStreamSocket(ourSocketAddress);
  myStreamSocket->SetNotificationWindow(this); //redirect socket FD_XXX notifications to us.
}


DlgSendStream::~DlgSendStream()
{
  delete myStreamSocket; //It should usually be already deleted.
}

void DlgSendStream::SetupWindow()
{
  editAddressSend    = new TEdit(this, IDC_EDIT_ADDRESS_SEND,   64);
  editAddressReceive  = new TEdit(this, IDC_EDIT_ADDRESS_RECEIVE, 64);
  editDataSend      = new TEdit(this, IDC_EDIT_SEND,        256);
  editDataReceive    = new TEdit(this, IDC_EDIT_RECEIVE,      256);
  editPort         = new TEdit(this, IDC_EDIT_PORT,         8);
  staticStatus      = new TStatic(this, IDC_STATIC_STATUS,    32);
  btnConnectDisconnect = new TButton(this, IDC_BTN_CONNECT);
  TDialog::SetupWindow();
}


//
// 'newConnectedSocket' is a valid and connected socket, usually connected with an Accept() call.
// This function causes this object to
// Returns true if able to take on the connected socket (with the given address).
//  Usually will be unable to take on the newConnectedSocket if already connected with
//  current socket.
//
short DlgSendStream::ConnectWithThis(TStreamSocket& newConnectedSocket)
{
  char  szPort[12];
  int  nError;

  if (myPresentState != nIdle)
    return 0; //Unable to comply, as we are busy.

  *myStreamSocket = newConnectedSocket; //StreamSocket::operator=()
  myStreamSocket->SetSaveSocketOnDelete(FALSE); //Now we own the socket descriptor.
  sAddressToConnectTo = newConnectedSocket.PeerSocketAddress;

  // The 'newConnectedSocket' may or may not be set up for Notification, so
  //  we specifically set it here to make sure it is the way we want it:
  //
  myStreamSocket->SetNotificationWindow(this);
  nError = myStreamSocket->StartRegularNotification();
  if (nError == WINSOCK_ERROR) {
    MessageBox(TSocketError(TWinSock::Dll()->WSAGetLastError()).AppendError("Error on StartRegularNotification() in ConnectWithThis()."), "Error", MB_OK);
    GoToIdleState();
    return 0;
  }

  // Equivalent Winsock code:
  //
  nError = TWinSock::Dll()->WSAAsyncSelect(*myStreamSocket, *this, MSG_SOCKET_NOTIFY, FD_READ | FD_WRITE | FD_CLOSE | FD_CONNECT | FD_OOB);
  if (nError) {
    MessageBox(TSocketError(TWinSock::Dll()->WSAGetLastError()).AppendError("Error on WSASelect()"), "Error", MB_OK);
    GoToIdleState();
    return 0;
  }

  wsprintf(szPort, "%d", TWinSock::Dll()->ntohs(sAddressToConnectTo.GetPort()));
  editPort->SetWindowText(szPort); //disable editing.

  char far* szIPAddress;
  szIPAddress = sAddressToConnectTo.ConvertAddress(sAddressToConnectTo.GetNetworkAddress());
  editAddressSend->SetWindowText(szIPAddress);

  GoToConnectedState();
  return 1;
}

short DlgSendStream::ConnectWithThis(SOCKET& /*newSocket*/, TSocketAddress& /*sNewAddress*/)
{
  //This function presently not defined.
  return 0;
}


TResult DlgSendStream::DoHostNotification(TParam1, TParam2 param2)
{
  int  nError = WSAGETASYNCERROR(param2);

  if (myPresentState != nWaitingForAddress)
    return 1;

  if (nError) {
    MessageBox(TSocketError(nError).AppendError("Error on looking up address."), "Error", MB_OK);
    GoToIdleState();
  }
  else{
    sAddressToConnectTo.SetNetworkAddress(myHostInfoManager.HostEntry->GetINetAddress());
    GoToConnectingState();
    Connect(); //Tries to connect to the given address.
  }
  return 1;
}


TResult DlgSendStream::DoSocketNotification(TParam1, TParam2 param2)
{
  int nEvent = (int)WSAGETSELECTEVENT(param2);
  int nError = (int)WSAGETSELECTERROR(param2);

  if (nEvent == FD_WRITE && !bDataSent) {
    if (nError)
      MessageBox(TSocketError(nError).AppendError("Error on receipt of FD_WRITE."), "", MB_OK);
    else
      SendData();
  }

  else if (nEvent == FD_READ) {
    if (nError)
      MessageBox(TSocketError(nError).AppendError("Error on receipt of FD_READ."), "", MB_OK);
    else
      ReadData();
  }

  else if (nEvent == FD_CONNECT && myPresentState == nConnecting) {
    if (nError) {
      MessageBox(TSocketError(nError).AppendError("Error on receipt of FD_CONNECT."), "", MB_OK);
      GoToIdleState();
    }
    else{
      GoToConnectedState();
    }
  }

  else if (nEvent == FD_CLOSE) {
    if (nError)
      MessageBox(TSocketError(nError).AppendError("Error on receipt of FD_CLOSE."), "", MB_OK);
    GoToIdleState();
  }

  return 1;
}

void DlgSendStream::Connect()
{
  //First create the socket.
  int nError = myStreamSocket->CreateSocket(); //similar to 'socket()'
  if (nError == WINSOCK_ERROR) { //could also say 'if (nError) {'
    MessageBox(TSocketError(myStreamSocket->GetLastError()).AppendError("Error on CreateSocket()"), "Error", MB_OK);
    GoToIdleState();
    return;
  }

  //The StartRegularNotification() function converts socket into non-blocking socket.
  myStreamSocket->StartRegularNotification();

  //Bind is technically not really needed, as a connect() will bind for you:
  nError = myStreamSocket->BindSocket();
  if (nError == WINSOCK_ERROR) { //could also say 'if (nError) {'
    MessageBox(TSocketError(myStreamSocket->GetLastError()).AppendError("Error on BindSocket()"), "Error", MB_OK);
    GoToIdleState();
    return;
  }

  nError = myStreamSocket->Connect(sAddressToConnectTo);
  if (nError == WINSOCK_ERROR) {
    if (myStreamSocket->GetLastError() != WSAEWOULDBLOCK) {
      MessageBox(TSocketError(myStreamSocket->GetLastError()).AppendError("Error on Connect()"), "Error", MB_OK);
      GoToIdleState();
      return;
    }
    //Else, we will soon get asynchronously notified of a completed connection with FD_CONNECT.
  }
}



void DlgSendStream::ReadData() {
  char szData[256];
  int  nLength=255;
  int  nEditLength;
  int  nError;

  nError = myStreamSocket->Read(szData, nLength);
  if (nError == WINSOCK_ERROR) {
    MessageBox(TSocketError(myStreamSocket->GetLastError()).AppendError("Error trying to read data."), "", MB_OK);
    return;
  }
  szData[nLength]=0; //Null-terminate the data to make it a C-string.

  nEditLength = editDataReceive->GetWindowTextLength();
  editDataReceive->SetSelection(nEditLength, nEditLength); //Move cursor to end of text.
  editDataReceive->Insert(szData); //Append the new text.
}



void DlgSendStream::SendData() {
  int nError;
  int nCharsToSend;

  nCharsToSend = lstrlen(szDataToSend);
  nError = myStreamSocket->Write(szDataToSend, nCharsToSend);
  if (nError == WINSOCK_ERROR) {
    if (myStreamSocket->GetLastError() != WSAEWOULDBLOCK)
      bDataSent = TRUE;
      MessageBox(TSocketError(myStreamSocket->GetLastError()).AppendError("Error trying to write data."), "", MB_OK);
    return;
  }
  bDataSent = TRUE;
  MessageBox("Send succeeded", "", MB_OK);
}



void DlgSendStream::CmConnectDisconnect() {
  short  bAddressIsDottedDecimal;
  char   szAddressInput[256];
  u_short nPortEnteredByUser;
  HANDLE  hHostRequest;
  int    nError;

  if (myPresentState == nIdle) {
    GoToWaitingForAddressState();

    //Get port entered by user.
    editPort->GetWindowText(szAddressInput, 255);
    nPortEnteredByUser = TWinSock::Dll()->htons((u_short)atoi(szAddressInput));  //need an 'atous()' function.
    sAddressToConnectTo.SetPort(nPortEnteredByUser);

    //Get actual address entered by user.
    editAddressSend->GetWindowText(szAddressInput, 255);
    bAddressIsDottedDecimal = sAddressToConnectTo.IsAddressDottedDecimal(szAddressInput);
    if (bAddressIsDottedDecimal) {
      sAddressToConnectTo.SetNetworkAddress(sAddressToConnectTo.ConvertAddress(szAddressInput));
      //We can immediately move on to the 'nConnecting' state.
      GoToConnectingState();
      Connect();
    }
    else{
      nError = myHostInfoManager.GetHostInfoAsync(*this, hHostRequest, szAddressInput);
      if (nError == WINSOCK_ERROR) {
        MessageBox(TSocketError(myHostInfoManager.GetLastError()).AppendError("Unable to convert the host name to an address."), "Error", MB_OK);
        GoToIdleState();
      }
    }
  }

  else if (myPresentState == nWaitingForAddress) {
    //cancel the lookup and go back to idle
    myHostInfoManager.CancelHostRequest();
    GoToIdleState();
  }

  else if (myPresentState == nConnecting) {
    //cancel the connection attempt and go back to idle.
      //I don't know how to cancel a connection attempt...
      //MessageBox("Busy connecting", "", MB_OK);
    //Maybe this will work (?):
    int nError;
    nError = TWinSock::Dll()->WSACancelBlockingCall();
    if (nError == SOCKET_ERROR) {
      nError = TWinSock::Dll()->WSAGetLastError();
      MessageBox(TSocketError(nError).AppendError("Can't cancel connection attempt."), "", MB_OK);
    }
    else
      GoToIdleState();
  }

  else if (myPresentState == nConnected) {
    //simply disconnect and return to idle.
    myStreamSocket->ShutDownSocket();
    GoToIdleState();
  }
}


void DlgSendStream::CmBtnSend() {
  if (myPresentState != nConnected) {
    MessageBox("This socket is not connected", "", MB_OK);
    return;
  }
  editDataSend->GetWindowText(szDataToSend, 256);
  if (szDataToSend[0]) {
    bDataSent = FALSE;
    SendData();
  }
  else
    MessageBox("There is nothing to send.", "", MB_OK);
}


void DlgSendStream::CmBtnSendClear() {
  editDataSend->Clear(); //Clear the text.
}


void DlgSendStream::CmBtnReceiveClear() {
  editDataReceive->Clear(); //Clear the text.
}


void DlgSendStream::CmOk() {
  if (myPresentState != nIdle) {
    CmConnectDisconnect(); //Disconnect/Cancel the operation and return all to idle.
  }
  TDialog::CmOk();
}


void DlgSendStream::GoToIdleState() {
  bDataSent = 1;
  myPresentState = nIdle;
  staticStatus->SetWindowText("Status: Idle");
  btnConnectDisconnect->SetWindowText("Connect");
  editPort->SetReadOnly(FALSE); //enable editing.
  editAddressSend->SetReadOnly(FALSE);
  editAddressReceive->Clear();

  //We close the socket here if it was open already.
  myStreamSocket->CloseSocket();
}


void DlgSendStream::GoToWaitingForAddressState() {
  myPresentState = nWaitingForAddress;
  staticStatus->SetWindowText("Status: Looking Up Address...");
  btnConnectDisconnect->SetWindowText("Cancel");
  editPort->SetReadOnly(TRUE); //disable editing.
  editAddressSend->SetReadOnly(TRUE);
}

void DlgSendStream::GoToConnectingState() {
  myPresentState = nConnecting;
  staticStatus->SetWindowText("Status: Connecting...");

  //Not necessary, because previous state already set this:
  //btnConnectDisconnect->SetWindowText("Cancel");
  //editPort->SetReadOnly(TRUE); //disable editing.
  //editAddressSend->SetReadOnly(TRUE);
}


void DlgSendStream::GoToConnectedState() {
  char szIPAddress[20];

  myPresentState = nConnected;
  staticStatus->SetWindowText("Status: Connected");
  btnConnectDisconnect->SetWindowText("Disconnect");

  //Actually necessary, because we could go directly from nIdle to
  //  nConnected with the ConnectWithThis() function:
  editPort->SetReadOnly(TRUE); //disable editing.
  editAddressSend->SetReadOnly(TRUE);
  editAddressSend->GetWindowText(szIPAddress, 20);
  editAddressReceive->SetWindowText(szIPAddress);
}
