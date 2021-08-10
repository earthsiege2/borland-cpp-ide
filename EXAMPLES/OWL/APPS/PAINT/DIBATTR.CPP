//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
// Example paint program dib attribute dialog
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/button.h>
#include <owl/dialog.h>
#include "dibattr.h"
#include "paint.rh"

extern uint32 ColorCapacity(uint depth);

DEFINE_RESPONSE_TABLE1(TDibAttrDialog, TDialog)
  EV_BN_CLICKED(IDC_2COLOR,    Bn2Color),
  EV_BN_CLICKED(IDC_16COLOR,   Bn16Color),
  EV_BN_CLICKED(IDC_256COLOR,  Bn256Color),
  EV_BN_CLICKED(IDC_HICOLOR,   BnHiColor),
  EV_BN_CLICKED(IDC_TRUECOLOR, BnTrueColor),
END_RESPONSE_TABLE;

TDibAttrDialog::TDibAttrDialog(TWindow* parent, 
                               int&     width,
                               int&     height,
                               uint32&  colors,
                               TModule* module)
:
  TDialog(parent, "IDD_DIBATTR", module),
  Width(width), Height(height), Colors(colors)
{
}

void
TDibAttrDialog::SetupWindow()
{
  SetDlgItemInt(IDC_WIDTH, Width);
  SetDlgItemInt(IDC_HEIGHT, Height);

  // Check the radio button that corresponds to the color count
  // passed to the constructor.
  //
  CheckRadioButton(IDC_2COLOR, IDC_TRUECOLOR,
    Colors == 2 ? IDC_2COLOR :
      Colors == 16 ? IDC_16COLOR :
        Colors == 256 ? IDC_256COLOR :
          Colors == 65536L ? IDC_HICOLOR : IDC_TRUECOLOR);

  // Disable radio buttons for color resolutions greater than the capacity
  // of the current display driver.
  //
  TScreenDC screenDC;
  uint32 MaxColors = ColorCapacity(screenDC.GetDeviceCaps(BITSPIXEL)*screenDC.GetDeviceCaps(PLANES));
  ::EnableWindow(GetDlgItem(IDC_16COLOR),   MaxColors >= 16);
  ::EnableWindow(GetDlgItem(IDC_256COLOR),  MaxColors >= 256);
  ::EnableWindow(GetDlgItem(IDC_HICOLOR),   MaxColors >= 65536L);
  ::EnableWindow(GetDlgItem(IDC_TRUECOLOR), MaxColors >= 16777216L);
}

bool
TDibAttrDialog::CanClose()
{
  Width = GetDlgItemInt(IDC_WIDTH);
  Height = GetDlgItemInt(IDC_HEIGHT);
  return true;
}
