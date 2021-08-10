#if !defined(DLGSRVC_H)
#define DLGSRVC_H

#include <owl/defs.h>
#include <owl/edit.h>
#include <owl/button.h>
#include <owl/winsock.h>
#include "sockdemo.rh"

class DlgConvertService : public TDialog {
  public:
    enum     nState{nIdle, nWaitingForService} myPresentState;

    TEdit*    editService;
    TEdit*    editProtocol;
    TEdit*    editPort;
    TStatic* staticStatus;
    TButton* btnConvert;
    bool      bBusyDoingLookup;
    TServiceManager myServiceManager;

    DlgConvertService(TWindow* parent, TResId resId = IDD_GET_SERVICE_PORT,
                      TModule* module = 0);
    void SetupWindow();
    void CmBtnConvert();
    void CmOk();
    void GoToIdleState();
    void GoToWaitingForServiceState();

    TResult DoNotification(TParam1, TParam2 param2);

  DECLARE_RESPONSE_TABLE(DlgConvertService);
};

#endif  // DLGSRVC_H
