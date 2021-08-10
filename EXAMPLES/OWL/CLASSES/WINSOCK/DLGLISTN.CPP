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
|    This module acts like a server and listens for stream socket         |
| connections on the specified port.  If a connection is made, this       |
| dialog spawns a stream dialog box just like the one used to make        |
| connections.                                                            |
\*-----------------------------------------------------------------------*/

#include <owl/pch.h>
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#include <stdlib.h>   //For atoi() call.
#include "dlglstn.h"
#include "dlgstrm.h"

//********************************************************************************************
DEFINE_RESPONSE_TABLE1(DlgListen, TDialog)
  EV_CHILD_NOTIFY(IDC_BTN_LISTEN, BN_CLICKED, CmBtnListen),
  EV_MESSAGE(MSG_SOCKET_NOTIFY, DoSocketNotification),
END_RESPONSE_TABLE;

DlgListen::DlgListen(TWindow *parent, TResId resId, TModule *module)
:
  TDialog(parent, resId, module)
{
  TINetSocketAddress ourSocketAddress(0, INADDR_ANY);  //same as 'ourSocketAddress()'

  myPresentState = nIdle;
  myStreamSocket = new TStreamSocket(ourSocketAddress);
  myStreamSocket->SetNotificationWindow(this); //redirect socket FD_XXX notifications to us.
}

DlgListen::~DlgListen()
{
  delete myStreamSocket;
}

void DlgListen::SetupWindow()
{
   editPort        = new TEdit(this, IDC_EDIT_PORT,      8);
   staticStatus     = new TStatic(this, IDC_STATIC_STATUS, 32);
   buttonListen     = new TButton(this, IDC_BTN_LISTEN);
   TDialog::SetupWindow();
}

short DlgListen::SpawnChildConnection()
{
  TStreamSocket newStreamSocket;  //construct an empty StreamSocket object.
  newStreamSocket.SetSaveSocketOnDelete();  //Don't close the socket on deletion, b/c we're giving it to someone else.

  int nError = myStreamSocket->Accept(newStreamSocket); //Accept() will completely fix up nStreamSocket.
  if (nError == WINSOCK_ERROR){ //could also say: 'if (nError){'
    MessageBox(TSocketError(myStreamSocket->GetLastError()).AppendError("Error on Accept()."), "Error", MB_OK);
    return 0;
  }
  DlgSendStream* demoDlgSendStream = new DlgSendStream(GetApplication()->GetMainWindow());
  demoDlgSendStream->Create();
  demoDlgSendStream->ConnectWithThis(newStreamSocket);
  return 1;
}


LRESULT DlgListen::DoSocketNotification(WPARAM, LPARAM lParam)
{
  int  nEvent = (int)WSAGETSELECTEVENT(lParam);
  int  nError = (int)WSAGETSELECTERROR(lParam);

  if (nEvent == FD_ACCEPT){
    if (nError)
      MessageBox(TSocketError(nError).AppendError("Error on receipt of FD_ACCEPT."), "Error", MB_OK);
    else
      SpawnChildConnection();
  }
  else{
    MessageBox("Listening socket received a non-FD_ACCEPT FD_ notification", "Suspicious...", MB_OK);
  }
  return 1;
}



void DlgListen::CmBtnListen()
{
  ushort nPort;
  char   szPort[8];
  int    nError;

  if (myPresentState == nIdle){
    nError = myStreamSocket->CreateSocket(); //similar to 'socket()'
    if (nError == WINSOCK_ERROR){ //could also say 'if (nError){'
      MessageBox(TSocketError(myStreamSocket->GetLastError()).AppendError("Error on CreateSocket()"), "Error", MB_OK);
      GoToIdleState();
      return;
    }
    myStreamSocket->StartAcceptNotification();  //similar to 'WSAAsyncSelect()'
    myStreamSocket->SetNotificationWindow(this); //redirect socket FD_XXX notifications to us.

    editPort->GetWindowText(szPort, 7);
    nPort = TWinSock::Dll()->htons((u_short)atoi(szPort));
    nError = myStreamSocket->BindSocket(TINetSocketAddress(nPort, INADDR_ANY)); //similar to 'bind()'
    if (nError == WINSOCK_ERROR){ //could also say 'if (nError){'
      MessageBox(TSocketError(myStreamSocket->GetLastError()).AppendError("Error on BindSocket()"), "Error", MB_OK);
      GoToIdleState();
      return;
    }
    nError = myStreamSocket->Listen();
    if (nError == WINSOCK_ERROR){ //could also say 'if (nError){'
      MessageBox(TSocketError(myStreamSocket->GetLastError()).AppendError("Error on Listen()"), "Error", MB_OK);
      GoToIdleState();
      return;
    }
    GoToListeningState();
  }

  else { //myPresentState == nListening
    // I don't know of any way to stop listening other than simply closing the socket and
    //  then recreating it so we can re-listen on it later.
    // On the other hand, it is very uncommon for an application to do what this demo
    //  application is doing--allowing you to randomly listen to any port you want to
    //  and stop and go at any time.
    GoToIdleState();
  }
}

void DlgListen::CmOk()
{
  if (myPresentState != nIdle)
    CmBtnListen();  //This will return everything to normal and idle.
  TDialog::CmOk();
}


void DlgListen::GoToIdleState()
{
  staticStatus->SetWindowText("Status: Idle");
  buttonListen->SetWindowText("Listen");
  editPort->SetReadOnly(FALSE); //Make the port editable.
  myPresentState = nIdle;
  myStreamSocket->CloseSocket();
}


void DlgListen::GoToListeningState()
{
  staticStatus->SetWindowText("Status: Listening");
  buttonListen->SetWindowText("Stop");
  editPort->SetReadOnly(TRUE); //Make the port un-editable.
  myPresentState = nListening;
}
