//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (C) 1995, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#if !defined(ANIMCTL_H)
#define ANIMCTL_H

// Control style
//
#if !defined(ACS_CENTER)
  #define ACS_CENTER          0x0001
#endif

#if !defined(ACS_TRANSPARENT)
  #define ACS_TRANSPARENT     0x0002
#endif

// Dialog/Control IDs
//
#define IDD_ANIMATE           0x0500
#define IDC_ANIMATE           0x0100

#define IDC_REWIND     	      257
#define IDC_STOP       	      261
#define IDC_PLAY       	      260
#define IDC_FORWARD           258

// Menubar/menuitem IDs
//
#define IDM_APPMENU           0x1000
#define CM_ANIMATE            0x1001
#define CM_STOP               0x1002
#define CM_DIALOG             0x1003

// AVI resource IDs
//
#define SAMPLE_ONE            1000
#define SAMPLE_TWO            "Sample_Avi"

#endif // ANIMCTL_H
