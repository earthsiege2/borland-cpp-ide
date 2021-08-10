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
|    This module is a dialog box that implements a datagram socket UDP    |
| data sender and receiver.  You simply specify a port and address, and   |
| it makes a socket to match and sends the data you request to the given  |
| port and address.  Currently, this dialog only keeps the socket open    |
| as long as it is sending data, so it would be hard to run another       |
| instance of this dialog an another machine to receive the data.         | 
\*-----------------------------------------------------------------------*/

#include <owl/pch.h>
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#include <stdlib.h>        //For atoi() call.
#include "dlgdgrm.h"

//********************************************************************************************
DEFINE_RESPONSE_TABLE1(DlgSendDatagram, TDialog)
  EV_CHILD_NOTIFY(IDC_BTN_SEND, BN_CLICKED, CmBtnSend),
  EV_CHILD_NOTIFY(IDC_BTN_SEND_CLEAR, BN_CLICKED, CmBtnSendClear),
  EV_CHILD_NOTIFY(IDC_BTN_RECEIVE_CLEAR, BN_CLICKED, CmBtnReceiveClear),
  EV_MESSAGE(MSG_HOST_INFO_NOTIFY, DoHostNotification),
  EV_MESSAGE(MSG_SOCKET_NOTIFY, DoSocketNotification),
END_RESPONSE_TABLE;

DlgSendDatagram::DlgSendDatagram(TWindow *parent, TResId resId, TModule *module)
:
  TDialog(parent, resId, module),
  myPresentState(nIdle),
  sAddressToSendTo(0, INADDR_NONE),
  bDataSent(true)
{
  TINetSocketAddress ourSocketAddress; //same as TINetSocketAddress(0, INADDR_ANY);

  myPresentState = nIdle;
  myDatagramSocket = new TDatagramSocket(ourSocketAddress);
  myDatagramSocket->SetNotificationWindow(this); //redirect socket FD_XXX notifications to us.
}


DlgSendDatagram::~DlgSendDatagram()
{
  delete myDatagramSocket;
}


void DlgSendDatagram::SetupWindow()
{
  editAddressSend    = new TEdit(this, IDC_EDIT_ADDRESS_SEND,    64);
  editAddressReceive = new TEdit(this, IDC_EDIT_ADDRESS_RECEIVE, 64);
  editDataSend       = new TEdit(this, IDC_EDIT_SEND,            256);
  editDataReceive    = new TEdit(this, IDC_EDIT_RECEIVE,         256);
  editPort           = new TEdit(this, IDC_EDIT_PORT,            8);
  staticStatus       = new TStatic(this, IDC_STATIC_STATUS,      32);
  TDialog::SetupWindow();
}


LRESULT DlgSendDatagram::DoHostNotification(WPARAM, LPARAM lParam)
{
  int  nError = WSAGETASYNCERROR(lParam);

  if (myPresentState != nWaitingForAddress)
    return 1;

  if (nError){
    MessageBox(TSocketError(nError).AppendError("Error on looking up address."), "Error", MB_OK);
    GoToIdleState();
  }
  else {
    sAddressToSendTo.SetNetworkAddress(myHostInfoManager.HostEntry->GetINetAddress());
    GoToSendingDataState();
    SendData();
  }
  return 1;
}


LRESULT DlgSendDatagram::DoSocketNotification(WPARAM, LPARAM lParam)
{
  int nEvent = (int)WSAGETSELECTEVENT(lParam);
  int nError = (int)WSAGETSELECTERROR(lParam);

  if (nEvent == FD_WRITE  && !nError && myPresentState == nSendingData && !bDataSent)
    SendData();

  else if (nEvent == FD_READ && !nError)
    ReadData();

  return 1L;
}



void DlgSendDatagram::ReadData()
{
  char         chData[256]; //For demo purposes, we only accept small amounts of data.
  int          nLength=255;
  char far*    szAddress;
  TINetSocketAddress sAddress;

  int error = myDatagramSocket->Read(chData, nLength, sAddress);
  if (error == WINSOCK_ERROR){
    MessageBox(TSocketError(myDatagramSocket->GetLastError()).GetReasonString(),
               "FD_READ Error", MB_OK);
    return;
  }
  chData[nLength] = 0; //Null-terminate the data to make it a C-string.
  szAddress = sAddress.ConvertAddress(sAddress.GetNetworkAddress());
  editAddressReceive->SetWindowText(szAddress);
  editDataReceive->SetWindowText(chData);
}

void DlgSendDatagram::SendData()
{
  int charsToSend = strlen(szDataToSend);
  int error = myDatagramSocket->Write(szDataToSend, charsToSend, sAddressToSendTo);
  if (error == WINSOCK_ERROR) {
    if (myDatagramSocket->GetLastError() == WSAEWOULDBLOCK)
      return; //leave state at: myPresentState = nSendingData
    bDataSent = TRUE;
    MessageBox(TSocketError(myDatagramSocket->GetLastError()).GetReasonString(),
               "Send Failed", MB_OK);
    GoToIdleState();
    return;
  }
  // It is important that we set the bDataSent flag to be true here,
  //  before we call MessageBox(), because MessageBox() will let another
  //  FD_WRITE message be received, and while the MessageBox() is up, we
  //  will inadvertantly send data again.
  // Note that if we remove the MessageBox() statement and simply call
  //  GoToIdleState(), the socket will be immediately closed.  Immediately
  //  closing a socket right after sending data could lose the sent data
  //  unless the socket is set to linger.
  bDataSent = true;
  MessageBox("Send succeeded\n\nClick OK to close the socket. Closing the socket will disable"
          " the ability to receive data on the given port.  This datagram sender creates"
          " a socket on the fly when you click 'send' and closes the socket when you click"
          " on this OK box.  However, you can receive data while this message box remains open.",
          "", MB_OK);
  GoToIdleState();
}

void DlgSendDatagram::CmBtnSend()
{
  short  bAddressIsDottedDecimal;
  char   szAddressInput[256];
  HANDLE  hHostRequest;
  int    nError;
  u_short nPort;
  char   szPort[8];

  if (myPresentState != nIdle){
    MessageBox("Busy Sending Data Already", "", MB_OK);
    return;
  }

  //Set up port
  editPort->GetWindowText(szPort, 7);
  nPort = TWinSock::Dll()->htons((u_short)atoi(szPort)); //you may get a compiler warning here.
  sAddressToSendTo.SetPort(nPort);

  //Set up socket
  nError = myDatagramSocket->CreateSocket(); //similar to 'socket()'
  if (nError == WINSOCK_ERROR){ //could also say 'if (nError){'
    MessageBox(TSocketError(myDatagramSocket->GetLastError()).AppendError("Error on CreateSocket()"), "Error", MB_OK);
    GoToIdleState();
    return;
  }

  ////Turn on/off lingering, if you want.
  //myDatagramSocket->SetLingerOption(FALSE);   //Don't linger on closesocket().  Not important here.

  //Make the sock asynchronous and notify us.  
  myDatagramSocket->StartRegularNotification();  //similar to 'WSAAsyncSelect()'

  //Bind the socket to our address and port.
  //By binding to a specific port, we can receive datagrams on the same port as we send them.
  //  We thus can even send datagrams to ourselves if we want to.
  myDatagramSocket->SetMyAddress(TINetSocketAddress(nPort));
  nError = myDatagramSocket->BindSocket(); //similar to 'bind()'
  if (nError == WINSOCK_ERROR){ //could also say 'if (nError){'
    MessageBox(TSocketError(myDatagramSocket->GetLastError()).AppendError("Error on BindSocket()"), "Error", MB_OK);
    GoToIdleState();
    return;
  }

  editDataSend->GetWindowText(szDataToSend, 256);
  if (szDataToSend[0]){
    bDataSent = FALSE;
    GoToWaitingForAddressState();
    editAddressSend->GetWindowText(szAddressInput, 255);
    bAddressIsDottedDecimal = TINetSocketAddress::IsAddressDottedDecimal(szAddressInput);
    if (bAddressIsDottedDecimal) {
      sAddressToSendTo.SetNetworkAddress(sAddressToSendTo.ConvertAddress(szAddressInput));
      GoToSendingDataState();
      SendData();
    }
    else{
      nError = myHostInfoManager.GetHostInfoAsync(*this, hHostRequest, szAddressInput);
      if (nError == WINSOCK_ERROR){
        MessageBox("Unable to convert the host name to an address", "Error", MB_OK);
        GoToIdleState();
      }
    }
  }
}


void DlgSendDatagram::CmBtnSendClear(){
  editDataSend->SetWindowText(""); //Clear the text.
}


void DlgSendDatagram::CmBtnReceiveClear(){
  editDataReceive->SetWindowText(""); //Clear the text.
}


void DlgSendDatagram::CmOk(){
  if (myPresentState == nWaitingForAddress)
    myHostInfoManager.CancelHostRequest();
  if (myPresentState != nIdle)
    GoToIdleState();
  TDialog::CmOk();
}


void DlgSendDatagram::GoToIdleState(){
  bDataSent = 1;
  myPresentState = nIdle;
  staticStatus->SetWindowText("Status: Idle");
  editPort->SetReadOnly(FALSE);

  //We close the socket here if it was open already.
  myDatagramSocket->CloseSocket();
}


void DlgSendDatagram::GoToWaitingForAddressState(){
  myPresentState = nWaitingForAddress;
  staticStatus->SetWindowText("Status: Looking Up Address...");
  editPort->SetReadOnly(TRUE);
}


void DlgSendDatagram::GoToSendingDataState(){
  myPresentState = nSendingData;
  staticStatus->SetWindowText("Status: Sending Data");
  editPort->SetReadOnly(TRUE);
}



