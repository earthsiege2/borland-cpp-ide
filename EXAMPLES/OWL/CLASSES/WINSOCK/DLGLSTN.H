#if !defined(DLGLSTN_H)
#define DLGLSTN_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_BUTTON_H)
# include <owl/button.h>
#endif
#if !defined(OWL_WINSOCK_H)
# include <owl/winsock.h>
#endif
#include "sockdemo.rh"

class DlgListen : public TDialog
{
  public:
    TEdit*        editPort;
    TStatic*      staticStatus;
    TButton*      buttonListen;

    enum          nState{nIdle, nListening} myPresentState;
    TStreamSocket* myStreamSocket;

    DlgListen(TWindow *parent, TResId resId = IDD_LISTEN, TModule *module = 0);
   ~DlgListen();

    void  SetupWindow();
    short SpawnChildConnection();
    void  GoToIdleState();
    void  GoToListeningState();
    void  CmBtnListen();
    void  CmOk();
    TResult DoSocketNotification(TParam1, TParam2 param2);

  DECLARE_RESPONSE_TABLE(DlgListen);
};

#endif  // DLGLSTN_H
