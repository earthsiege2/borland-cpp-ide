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
|    This is the application module.  It essentially fields menu choices  |
| and makes dialogs out of them.  The dialogs all the real work.          |
\*-----------------------------------------------------------------------*/

#include <owl/pch.h>
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#include <stdio.h>
#include "sockdemo.h"
#include "sockbout.h" //Used by CmHelpAbout().  The about dialog
#include "dlgaddr.h"  //Used by CmConvertAddress(). The Name to Address conversion dialog
#include "dlgsrvc.h"  //Used by CmConvertService(). The Service to Port conversion dialog
#include "dlgdgrm.h"  //Used by CmSendDatagrams(). The Datagram sending dialog
#include "dlgstrm.h"  //Used by CmStreamConnect()/CmStreamListen. The Stream sending dialog
#include "dlglstn.h"  //Used by CmStreamListen(). The Listen dialog

//
// Our one global:  In this demo app, it doesn't need to be global,
//  but you want it that way in other apps, as there generally need be
//  only one SocketManager;
//
TSocketManager* gSocketManager;

DEFINE_RESPONSE_TABLE1(SockDemoApp, TApplication)
  EV_COMMAND(CM_GET_WSADATA, CmGetWSAData),
  EV_COMMAND(CM_GET_MY_ADDRESS, CmGetMyAddress),
  EV_COMMAND(CM_CONVERT_SERVICE, CmConvertService),
  EV_COMMAND(CM_CONVERT_ADDRESS, CmConvertAddress),
  EV_COMMAND(CM_SEND_DATAGRAMS, CmSendDatagrams),
  EV_COMMAND(CM_STREAM_LISTEN, CmStreamListen),
  EV_COMMAND(CM_STREAM_CONNECT, CmStreamConnect),
  EV_COMMAND(CM_SHOW_SOCKET_ERROR, CmShowSocketError),
  EV_COMMAND(CM_HELPABOUT, CmHelpAbout),
  EV_COMMAND(CM_HELP_HOW, CmHelpHow),
END_RESPONSE_TABLE;


SockDemoApp::SockDemoApp()
:
  TApplication("OWLSock demo")
{
  gSocketManager = new TSocketManager();
}


SockDemoApp::~SockDemoApp()
{
  delete gSocketManager;
}


void SockDemoApp::InitMainWindow()
{
  if(nCmdShow != SW_HIDE)
    nCmdShow = (nCmdShow != SW_SHOWMINNOACTIVE) ? SW_SHOWNORMAL : nCmdShow;

  TFrameWindow *frame = new TFrameWindow((TWindow*)NULL, GetName());
  frame->SetIcon(this, IDI_SDIAPPLICATION);
  frame->AssignMenu(MENU_MAIN);
  frame->Attr.AccelTable = MENU_MAIN;
  SetMainWindow(frame);
  frame->SetMenuDescr(TMenuDescr(MENU_MAIN));
}

void SockDemoApp::CmGetWSAData()
{
  char output[256];
  sprintf(output,
          "Major Version: %d\n"
          "Minor Version: %d\n"
          "Max Sockets  : %d\n"
          "Description:  \n"
          "%s\n\n"
          "SystemStatus:  \n"
          "%s",
           gSocketManager->GetMajorVersion(),
           gSocketManager->GetMinorVersion(),
           gSocketManager->GetMaxSocketsAvailable(),
           gSocketManager->GetDescription(),
           gSocketManager->GetSystemStatus());
  GetMainWindow()->MessageBox(output, "Sockets Info", MB_OK);
}

void SockDemoApp::CmGetMyAddress()
{
  char szOutput[148];
  char szName[128];
  char szAddress[20];
  THostInfoManager myHostInfoManager;

  myHostInfoManager.GetHostName(szName, 128);
  myHostInfoManager.GetHostAddress(szAddress, szName);  //Will this block if it is my address?  Doesn't seem to.
  wsprintf(szOutput, "This computer's name:\n"
               "%s\n\n"
               "This computer's address:\n"
               "%s", szName, szAddress);
  GetMainWindow()->MessageBox(szOutput, "This Computer's Info", MB_OK);
}

void SockDemoApp::CmConvertService()
{
  DlgConvertService* demoDlgConvertService = new DlgConvertService(GetMainWindow());
  demoDlgConvertService->Create();
}

void SockDemoApp::CmConvertAddress()
{
  DlgConvertAddress* demoDlgConvertAddress = new DlgConvertAddress(GetMainWindow());
  demoDlgConvertAddress->Create();
}

void SockDemoApp::CmSendDatagrams()
{
  DlgSendDatagram* demoDlgSendDatagram = new DlgSendDatagram(GetMainWindow());
  demoDlgSendDatagram->Create();
}

void SockDemoApp::CmStreamListen()
{
  DlgListen* demoDlgListen = new DlgListen(GetMainWindow());
  demoDlgListen->Create();
}


void SockDemoApp::CmStreamConnect()
{
  DlgSendStream* demoDlgSendStream = new DlgSendStream(GetMainWindow());
  demoDlgSendStream->Create();
}

void SockDemoApp::CmShowSocketError()
{
  GetMainWindow()->MessageBox(TSocketError(WSAEWOULDBLOCK).AppendError("You forgot to make the socket non-blocking."), "Error (not real)", MB_OK);
}


void SockDemoApp::CmHelpAbout()
{
  DlgSockDemoAbout(GetMainWindow()).Execute();
}


void SockDemoApp::CmHelpHow(){
  GetMainWindow()->MessageBox(
                    "You use the stream and datagram socket parts of this demo"
                    " by running a copy of this demo on multiple computers"
                    " at a time and use the stream and datagram dialog boxes"
                    " to make connections between them.",
                    "How to use this demo", MB_OK);
}

//
//
//
int OwlMain (int , char* [])
{
  if (!TWinSock::IsAvailable()) {
    ::MessageBox(0, "WinSock cannot be initialized.", "Error", MB_OK | MB_ICONSTOP);
    return -1;
  }

  SockDemoApp app;
  return app.Run();
}
