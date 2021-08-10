#if !defined(DLGDGRM_H)
#define DLGDGRM_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#include "sockdemo.rh"

class DlgSendDatagram : public TDialog {
  public:
    enum nState { nIdle, nWaitingForAddress, nSendingData } myPresentState;

    TEdit*             editAddressSend;
    TEdit*             editAddressReceive;
    TEdit*             editDataSend;
    TEdit*             editDataReceive;
    TEdit*             editPort;
    TStatic*           staticStatus;

    TDatagramSocket*   myDatagramSocket;
    char               szDataToSend[256];
    bool               bDataSent;
    TINetSocketAddress sAddressToSendTo;
    THostInfoManager   myHostInfoManager;

    DlgSendDatagram(TWindow* parent, TResId resId = IDD_DATAGRAM,
                    TModule* module = 0);
   ~DlgSendDatagram();
    void SetupWindow();
    void CmBtnSend();
    void CmBtnSendClear();
    void CmBtnReceiveClear();
    void CmOk();
    void SendData();
    void ReadData();
    void GoToIdleState();
    void GoToWaitingForAddressState();
    void GoToSendingDataState();
    LRESULT DoHostNotification(WPARAM, LPARAM lParam);
    LRESULT DoSocketNotification(WPARAM, LPARAM lParam);

  DECLARE_RESPONSE_TABLE(DlgSendDatagram);
};

#endif  // DLGDGRM_H
