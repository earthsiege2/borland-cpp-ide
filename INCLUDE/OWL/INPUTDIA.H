//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Definition of TInputDialog class
//----------------------------------------------------------------------------
#if !defined(OWL_INPUTDIA_H)
#define OWL_INPUTDIA_H

#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#include <owl/inputdia.rh>

class _OWLCLASS TValidator;

//
//  class TInputDialog
//  ----- ------------
//
class _OWLCLASS TInputDialog : public TDialog {
  public:
    char far* Prompt;
    char far* Buffer;
    int       BufferSize;

    TInputDialog(TWindow*        parent,
                 const char far* title,
                 const char far* prompt,
                 char far*       buffer,
                 int             bufferSize,
                 TModule*        module = 0,
                 TValidator*     valid = 0);  // Optional validator

   ~TInputDialog();

    //
    // Override TWindow virtual member functions
    //
    void TransferData(TTransferDirection);


  protected:
    //
    // Override TWindow virtual member functions
    //
    void SetupWindow();

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TInputDialog(const TInputDialog&);
    TInputDialog& operator=(const TInputDialog&);

  DECLARE_STREAMABLE(_OWLCLASS, TInputDialog, 1);
};

#endif  // OWL_INPUTDIA_H
