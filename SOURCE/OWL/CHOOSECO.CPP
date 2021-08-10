//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implementation of TChooseColorDialog, a Choose Color Common Dialog class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_CHOOSECO_H)
# include <owl/chooseco.h>
#endif

DIAG_DECLARE_GROUP(OwlCommDialog);  // diagnostic group for common dialogs

uint TChooseColorDialog::SetRGBMsgId = 0;

DEFINE_RESPONSE_TABLE1(TChooseColorDialog, TCommonDialog)
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TChooseColorDialog);

//
// Initialize the choose color common dialog data members.
//
TChooseColorDialog::TChooseColorDialog(TWindow*        parent,
                                       TData&          data,
                                       TResId          templateId,
                                       const char far* title,
                                       TModule*        module)
:
  TCommonDialog(parent, title, module),
  Data(data)
{
  if (!SetRGBMsgId)
    SetRGBMsgId = ::RegisterWindowMessage(SETRGBSTRING);

  memset(&Cc, 0, sizeof Cc);
  Cc.lStructSize = sizeof Cc;
  Cc.hwndOwner = Parent ? Parent->GetHandle() : 0;
  Cc.hInstance = HWND(GetModule()->GetHandle());  // hInstance is badly typed
  Cc.Flags = CC_ENABLEHOOK | Data.Flags;
  if (templateId) {
    Cc.lpTemplateName = templateId;
    Cc.Flags |= CC_ENABLETEMPLATE;
  }
  else
    Cc.Flags &= ~CC_ENABLETEMPLATE;
  Cc.lpfnHook = 0;

  Cc.rgbResult = Data.Color;
  Cc.lpCustColors = (COLORREF far*)Data.CustColors;

  TRACEX(OwlCommDialog, OWL_CDLEVEL, "TChooseColorDialog constructed @" << (void*)this);
}

//
// Destructor does nothing in non diagnostic versions of the library.
// In the diagnostic version, it displays a trace message.
//
TChooseColorDialog::~TChooseColorDialog()
{
  TRACEX(OwlCommDialog, OWL_CDLEVEL, "TChooseColorDialog destructed @" << (void*)this);
}

//
// Override the virtual DialogFunction.
// Does no additional processing.
//
bool
TChooseColorDialog::DialogFunction(uint msg, TParam1 param1, TParam2 param2)
{
  return TCommonDialog::DialogFunction(msg, param1, param2);
}

//
// Execute the dialog to retrieve user's choice of color.
//
int
TChooseColorDialog::DoExecute()
{
  Cc.lpfnHook = LPCCHOOKPROC(StdDlgProc);
  int ret = ::ChooseColor(&Cc);
  if (ret) {
    Data.Flags = Cc.Flags;
    Data.Error = 0;
    Data.Color = Cc.rgbResult;
  }
  else {
    Data.Error = ::CommDlgExtendedError();
  }
  return ret ? IDOK : IDCANCEL;
}
