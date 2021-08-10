//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
// $Revision:   10.9  $
//
// Sample illustrating the use of OCXes in dialogs - Defines TOcxDialog
//----------------------------------------------------------------------------
#if !defined(_OCXDLG_H)
#define _OCXDLG_H

#if defined(BI_PLAT_WIN16)
#error WIN32 only.
#endif

#if !defined(OWL_OLEDIALG_H)
# include <owl/oledialg.h>
#endif
#include "vcf132.hxx"
#include "vcfi32.hxx"

// OCX Dialog object
//
class TMyOcxDialog : public TOleDialog {

  public:
    TMyOcxDialog(TWindow* parent = 0);

    void                        SetupWindow();

  protected:
    void                        EvGraphMode();
    bool                EvOcCtrlCustomEvent(TCtrlCustomEvent* pev);

  private:
    TOcControl*         pWorkbook;
         TOcControl*    pChart;
         _DVCF1                         Workbook;
         _DVtChart      Chart;

  DECLARE_RESPONSE_TABLE(TMyOcxDialog);
};

#endif  // _OCXDLG_H
