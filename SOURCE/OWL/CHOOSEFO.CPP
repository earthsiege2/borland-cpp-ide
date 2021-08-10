//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implementation of TChooseFontDialog, a Choose Font Common Dialog class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_CHOOSEFO_H)
# include <owl/choosefo.h>
#endif
#if !defined(ctlFirst)
# include <dlgs.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlCommDialog);  // diagnostic group for common dialogs

DEFINE_RESPONSE_TABLE1(TChooseFontDialog, TCommonDialog)
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TChooseFontDialog);

//
// Initialize the ChooseFont data members.
//
TChooseFontDialog::TChooseFontDialog(TWindow*        parent,
                                     TData&          data,
                                     TResId          templateId,
                                     const char far* title,
                                     TModule*        module)
:
  TCommonDialog(parent, title, module),
  Data(data)
{
  memset(&Cf, 0, sizeof(CHOOSEFONT));
  Cf.lStructSize = sizeof(CHOOSEFONT);
  Cf.hwndOwner = Parent ? Parent->GetHandle() : 0;
  Cf.hInstance = *GetModule();
  Cf.Flags = CF_ENABLEHOOK | Data.Flags;
  if (templateId) {
    Cf.lpTemplateName = templateId;
    Cf.Flags |= CF_ENABLETEMPLATE;
  }
  else
    Cf.Flags &= ~CF_ENABLETEMPLATE;
  Cf.lpfnHook = 0;

  Cf.hDC = Data.DC;
  Cf.lpLogFont = &Data.LogFont;
  Cf.iPointSize = Data.PointSize;
  Cf.rgbColors = Data.Color;
  Cf.lpszStyle = Data.Style;
  Cf.nFontType = Data.FontType;
  Cf.nSizeMin = Data.SizeMin;
  Cf.nSizeMax = Data.SizeMax;

  TRACEX(OwlCommDialog, OWL_CDLEVEL, "TChooseFontDialog constructed @" << (void*)this);
}


//
// Destructor for this object does nothing in the non-diagnostic versions
// of the library.
// In the diagnostic version, it produces a trace message.
//
TChooseFontDialog::~TChooseFontDialog()
{
  TRACEX(OwlCommDialog, OWL_CDLEVEL, "TChooseFontDialog destructed @" << (void*)this);
}


//
// Override the virtual DialogFunction.
// It does no additional processing.
//
bool
TChooseFontDialog::DialogFunction(uint msg, TParam1 param1, TParam2 param2)
{
  return TCommonDialog::DialogFunction(msg, param1, param2);
}

//
// Execute the dialog to retrieve the font selected by the user.
//
int
TChooseFontDialog::DoExecute()
{
  Cf.lpfnHook = LPCFHOOKPROC(StdDlgProc);
  int ret = ::ChooseFont(&Cf);
  if (ret) {
    Data.Flags = Cf.Flags;
    Data.Error = 0;
    Data.PointSize = Cf.iPointSize;
    Data.Color = Cf.rgbColors;
    Data.Style = Cf.lpszStyle;
    Data.FontType = Cf.nFontType;
  }
  else {
    Data.Error = ::CommDlgExtendedError();
  }
  return ret ? IDOK : IDCANCEL;
}
