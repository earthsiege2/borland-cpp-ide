//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#if !defined(PROPSHT_H)
#define PROPSHT_H

// Menus
//
#define IDM_APPMENU     0x1000
#define CM_PROPERTY     0x1001
#define CM_PROPMODELESS 0x1002

// Icons
//
#define IDI_COLOR       0x1000
#define IDI_SIZE        0x1001

// Dialogs
//
#define IDD_WINATTR	    0x1000
#define IDD_SAMPLEPAGE  0x1001

// Dialog Control IDs
//
#define IDC_BKCOLOR             200
#define IDC_TEXTEDIT            201

#define IDC_GRP_PAGE            100
#define IDC_SIM_APPLY           101
#define IDC_SIM_XCELTOCLOSE     102
#define IDC_SIM_CHANGED         103
#define IDC_SIM_UNCHANGED       104
#define IDC_GRP_SHEET           105
#define IDC_ADDPAGE	            106
#define IDC_REMPAGE    	        107
#define IDC_SELPAGE    	        108
#define IDC_PAGEINFO   	        109


//
// Handler for child ID notifications that are handled at the child's parent
//
// Ctl's ID is passed as parameter:
//
//        void TMyWindow::BnClicks(uint btnID);
//
#define EV_CHILD_NOTIFY_AND_ID(id, notifyCode, method)\
  {notifyCode, id, (TAnyDispatcher)::v_WPARAM_Dispatch,\
   (TMyPMF)v_U_Sig(&TMyClass::method)}

#endif // PROPSHT_H
