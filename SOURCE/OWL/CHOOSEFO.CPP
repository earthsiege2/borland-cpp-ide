//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of Choose Font Common Dialog class
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/choosefo.h>
#if !defined(ctlFirst)
# include <dlgs.h>
#endif

DEFINE_RESPONSE_TABLE1(TChooseFontDialog, TCommonDialog)
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TChooseFontDialog);

TChooseFontDialog::TChooseFontDialog(TWindow*        parent,
                                     TData&          data,
                                     TResId          templateId,
                                     const char far* title,
                                     TModule*        module)
:
  TCommonDialog(parent, title, module),
  Data(data)
{
  memset(&cf, 0, sizeof(CHOOSEFONT));
  cf.lStructSize = sizeof(CHOOSEFONT);
  cf.hwndOwner = Parent ? Parent->HWindow : 0;
  cf.hInstance = *GetModule();
  cf.Flags = CF_ENABLEHOOK | Data.Flags;
  if (templateId) {
    cf.lpTemplateName = templateId;
    cf.Flags |= CF_ENABLETEMPLATE;
  }
  else
    cf.Flags &= ~CF_ENABLETEMPLATE;
  cf.lpfnHook = 0;

  cf.hDC = Data.DC;
  cf.lpLogFont = &Data.LogFont;
  cf.iPointSize = Data.PointSize;
  cf.rgbColors = Data.Color;
  cf.lpszStyle = Data.Style;
  cf.nFontType = Data.FontType;
  cf.nSizeMin = Data.SizeMin;
  cf.nSizeMax = Data.SizeMax;
}

bool
TChooseFontDialog::DialogFunction(uint msg, WPARAM wParam, LPARAM lParam)
{
  return TCommonDialog::DialogFunction(msg, wParam, lParam);
}

int
TChooseFontDialog::DoExecute()
{
  (DLGPROC)cf.lpfnHook = (DLGPROC)(FARPROC)StdDlgProcInstance;
  int ret = ::ChooseFont(&cf);
  if (ret) {
    Data.Flags = cf.Flags;
    Data.Error = 0;
    Data.PointSize = cf.iPointSize;
    Data.Color = cf.rgbColors;
    Data.Style = cf.lpszStyle;
    Data.FontType = cf.nFontType;
  }
  else {
    Data.Error = ::CommDlgExtendedError();
  }
  return ret ? IDOK : IDCANCEL;
}
