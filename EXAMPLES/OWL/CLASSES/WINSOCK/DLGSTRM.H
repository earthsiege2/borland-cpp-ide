#if !defined(DLGSTRM_H)
#define DLGSTRM_H

#include <owl/defs.h>
#include <owl/dialog.h>
#include <owl/edit.h>
#include <owl/button.h>
#include <owl/winsock.h>
#include "sockdemo.rh"

class DlgSendStream : public TDialog {
public:
   enum              nState{nIdle, nWaitingForAddress, nConnecting, nConnected} myPresentState;

   TEdit*            editAddressSend;
   TEdit*            editAddressReceive;
   TEdit*            editDataSend;
   TEdit*            editDataReceive;
   TEdit*            editPort;
   TStatic*          staticStatus;
   TButton*          btnConnectDisconnect;

   TStreamSocket*     myStreamSocket;
   char               szDataToSend[256];
   bool               bDataSent;
   TINetSocketAddress sAddressToConnectTo;
   THostInfoManager   myHostInfoManager;

   DlgSendStream(TWindow* parent, TResId resId = IDD_STREAM,
                 TModule* module = 0);
  ~DlgSendStream();
   void SetupWindow();
   short ConnectWithThis(TStreamSocket& newConnectedSocket);
   short ConnectWithThis(SOCKET& newSocket, TSocketAddress& sNewAddress);
   void CmBtnSend();
   void CmBtnSendClear();
   void CmBtnReceiveClear();
   void CmConnectDisconnect();
   void CmOk();
   void Connect();
   void SendData();
   void ReadData();
   void GoToIdleState();
   void GoToWaitingForAddressState();
   void GoToConnectingState();
   void GoToConnectedState();
   LRESULT DoHostNotification(WPARAM, LPARAM lParam);
   LRESULT DoSocketNotification(WPARAM, LPARAM lParam);
   DECLARE_RESPONSE_TABLE(DlgSendStream);
};

#endif  // DLGSTRM_H
