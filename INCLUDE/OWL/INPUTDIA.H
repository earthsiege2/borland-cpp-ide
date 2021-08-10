//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of TInputDialog class
//----------------------------------------------------------------------------
#if !defined(OWL_INPUTDIA_H)
#define OWL_INPUTDIA_H

#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#include <owl/inputdia.rh>

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TValidator;

//
// class TInputDialog
// ~~~~~ ~~~~~~~~~~~~
class _OWLCLASS TInputDialog : public TDialog {
  public:
    TInputDialog(TWindow*        parent,
                 const char far* title,
                 const char far* prompt,
                 char far*       buffer,
                 int             bufferSize,
                 TModule*        module = 0,
                 TValidator*     valid = 0);  // Optional validator

   ~TInputDialog();

    // Override TWindow virtual member functions
    //
    void TransferData(TTransferDirection);

    const char far* GetPrompt() const;
    const char far* GetBuffer() const;
    int             GetBufferSize() const;

  protected:
    // Override TWindow virtual member functions
    //
    void SetupWindow();

  public_data:
    char far* Prompt;
    char far* Buffer;
    int       BufferSize;

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TInputDialog(const TInputDialog&);
    TInputDialog& operator=(const TInputDialog&);

  DECLARE_STREAMABLE(_OWLCLASS, TInputDialog, 1);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the prompt for the dialog.
//
inline const char far* TInputDialog::GetPrompt() const
{
  return Prompt;
}

//
// Return the buffer.
//
inline const char far* TInputDialog::GetBuffer() const
{
  return Buffer;
}

//
// Return the size of the buffer.
//
inline int TInputDialog::GetBufferSize() const
{
  return BufferSize;
}


#endif  // OWL_INPUTDIA_H
