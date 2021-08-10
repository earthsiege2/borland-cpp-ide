#if !defined(DLGADDR_H)
#define DLGADDR_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
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

class DlgConvertAddress : public TDialog {
  public:
   enum    nState {nIdle, nWaitingForAddress} myPresentState;

   TEdit   *editNameCtrl;
   TEdit   *editAddressCtrl;
   TStatic *staticStatus;
   TButton *btnConvert;
   bool    bBusyDoingLookup;
   THostInfoManager myHostInfoManager;

   DlgConvertAddress(TWindow *parent, TResId resId = IDD_CONVERT_ADDRESS, TModule *module = 0);
   void SetupWindow();
   void CmBtnConvert();
   void CmOk();
   void GoToIdleState();
   void GoToWaitingForAddressState();
   LRESULT DoNotification(WPARAM, LPARAM lParam);
   DECLARE_RESPONSE_TABLE(DlgConvertAddress);
};

#endif  // DLGADDR_H
