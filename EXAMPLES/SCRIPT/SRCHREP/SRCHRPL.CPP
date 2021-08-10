//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/dialog.h>
#include <stdlib.h>
#pragma hdrstop
#include "search.h"

#define IDD_SEARCHEDITBOX  109
#define IDD_REPLACEEDITBOX 110
#define IDD_MASKEDITBOX	   111

extern "C"{
int WINAPI _export searchReplaceDialog(HWND ParentHWnd, char *search,
                                       char *replace, char *mask);
}

int WINAPI _export
searchReplaceDialog(HWND parentHwnd, char *search, char *replace, char *mask)
{
  const int maxLength = 1024;
  int retVal;

  // Create/Initialize a structure to set and retrieve data;
  //
  struct {
     char  srchText[maxLength];
     char  rplcText[maxLength];
     char  maskText[maxLength];
  } dlgData = {"", ""};

  try {
    if (parentHwnd == 0) {
      parentHwnd = GetActiveWindow();
    }

    TWindow *windowPtr = new TWindow(parentHwnd);

    TDialog *optDlg = new TDialog(windowPtr, "SEARCHDLG");
    new TEdit(optDlg, IDD_SEARCHEDITBOX, maxLength);
    new TEdit(optDlg, IDD_REPLACEEDITBOX, maxLength);
    new TEdit(optDlg, IDD_MASKEDITBOX, maxLength);

    // Set default value
    if (mask != NULL) {
      strcpy(dlgData.maskText, mask);
    }
  
    optDlg->SetTransferBuffer(&dlgData);
    if ((retVal = (optDlg->Execute())) == IDOK) {
      if (search != NULL) {
        strcpy(search, dlgData.srchText);
      }
      if (replace != NULL) {
        strcpy(replace, dlgData.rplcText);
      }
      if (mask != NULL) {
        strcpy(mask, dlgData.maskText);
      }
    }

    delete optDlg;
    delete windowPtr;
  }
  catch(...) {
    MessageBox(NULL, "Problem detected", "Error Initializing Dialog", MB_OK);
  }

  return retVal;
}

