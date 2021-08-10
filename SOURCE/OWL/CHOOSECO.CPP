//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\chooseco.cpp
//   Implementation of Choose Color Common Dialog class
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\chooseco.h>

UINT TChooseColorDialog::SetRGBMsgId = 0;

DEFINE_RESPONSE_TABLE1(TChooseColorDialog, TCommonDialog)
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TChooseColorDialog);

TChooseColorDialog::TChooseColorDialog(TWindow*        parent,
                                       TData&          data,
                                       TResId          templateId,
                                       const char far* title,
                                       TModule*        module)
  : TCommonDialog(parent, title, module), 
    Data(data)
{
  if (!SetRGBMsgId)
    SetRGBMsgId = ::RegisterWindowMessage(SETRGBSTRING);

  memset(&cc, 0, sizeof(CHOOSECOLOR));
  cc.lStructSize = sizeof(CHOOSECOLOR);
  cc.hwndOwner = Parent ? Parent->HWindow : 0;
  cc.hInstance = (HWND)(HINSTANCE)*GetModule();
  cc.Flags = CC_ENABLEHOOK | Data.Flags;
  if (templateId) {
    cc.lpTemplateName = templateId;
    cc.Flags |= CC_ENABLETEMPLATE;
  } else
    cc.Flags &= ~CC_ENABLETEMPLATE;
  cc.lpfnHook = 0;

  cc.rgbResult = Data.Color;
  cc.lpCustColors = (COLORREF far*)Data.CustColors;
}

BOOL
TChooseColorDialog::DialogFunction(UINT msg, WPARAM wParam, LPARAM lParam)
{
  return TCommonDialog::DialogFunction(msg, wParam, lParam);
}

int
TChooseColorDialog::DoExecute()
{
  (DLGPROC)cc.lpfnHook = (DLGPROC)(FARPROC)StdDlgProcInstance;
  int ret = ::ChooseColor(&cc);
  if (ret) {
    Data.Flags = cc.Flags;
    Data.Error = 0;
    Data.Color = cc.rgbResult;
  } else {
    Data.Error = ::CommDlgExtendedError();
  }
  return ret ? IDOK : IDCANCEL;
}
