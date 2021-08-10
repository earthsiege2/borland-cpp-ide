//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
// Example paint program dib attribute dialog
//----------------------------------------------------------------------------
#if !defined(DIBATTR_H)
#define DIBATTR_H

#include <owl/dialog.h>

class TDibAttrDialog : public TDialog {
  public:
    TDibAttrDialog(TWindow* parent, int& width, int& height, int& colors,
                   TModule* module = 0);

  private:
    void SetupWindow();
    bool CanClose();

    void Bn2Color() {Colors = 2;}
    void Bn16Color() {Colors = 16;}
    void Bn256Color() {Colors = 256;}

    int& Width;
    int& Height;
    int& Colors;

  DECLARE_RESPONSE_TABLE(TDibAttrDialog);
};
  
#endif
