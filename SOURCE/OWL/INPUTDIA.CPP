//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Implementation of TInputDialog.  User string input dialog box
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_INPUTDIA_H)
# include <owl/inputdia.h>
#endif
#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_VALIDATE_H)
# include <owl/validate.h>
#endif
#include <string.h>

OWL_DIAGINFO;

#if !defined(SECTION) || SECTION == 1

//
//
//
TInputDialog::TInputDialog(TWindow*        parent,
                           const char far* title,
                           const char far* prompt,
                           char far*       buffer,
                           int             bufferSize,
                           TModule*        module,
                           TValidator*     validator)
:
  TWindow(parent, title, module),
  TDialog(parent, IDD_INPUTDIALOG, module)
{
  PRECONDITION(buffer);
  SetCaption(title);
  Prompt = strnewdup(prompt);
  Buffer = buffer;
  BufferSize = bufferSize;
  if (validator)
    (new TEdit(this,ID_INPUT))->SetValidator(validator);
}

//
//
//
TInputDialog::~TInputDialog()
{
  delete[] Prompt;
}

//
// sets and gets the values of the items (controls) of the input dialog
//
void
TInputDialog::TransferData(TTransferDirection direction)
{
  if (direction == tdSetData) {
    SetDlgItemText(ID_PROMPT, Prompt);
    SetDlgItemText(ID_INPUT, Buffer);
  }
  else if (direction == tdGetData) {
    GetDlgItemText(ID_INPUT, Buffer, BufferSize);
  }
}

//
// sets the values of the items(controls) of the input dialog
//
void
TInputDialog::SetupWindow()
{
  TDialog::SetupWindow();
  SendDlgItemMessage(ID_INPUT, EM_LIMITTEXT, BufferSize - 1, 0);
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE2(TInputDialog, TDialog, TWindow);

#if !defined(BI_NO_OBJ_STREAMING)

//
// reads an instance of TInputDialog from the passed ipstream
//
void*
TInputDialog::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TDialog*)GetObject(), is);
  GetObject()->Prompt = is.freadString();
  return GetObject();
}

//
// writes the TInputDialog to the passed opstream
//
void
TInputDialog::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TDialog*)GetObject(), os);
  os.fwriteString(GetObject()->Prompt);
}


#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
