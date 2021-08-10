//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\inputdia.cpp
//   Defines type TInputDialog.  This defines the basic
//   behavior of all input dialogs.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\inputdia.h>
#include <string.h>
#include <owl\edit.h>
#include <owl\validate.h>

#if !defined(SECTION) || SECTION == 1

TInputDialog::TInputDialog(TWindow*        parent,
                           const char far* title,
                           const char far* prompt,
                           char far*       buffer,
                           int             bufferSize,
                           TModule*        module,
                           TValidator*     valid)
  : TWindow(parent, title, module),
    TDialog(parent, IDD_INPUTDIALOG, module)
{
  PRECONDITION(buffer);
  SetCaption(title);
  Prompt = strnewdup(prompt);
  Buffer = buffer;
  BufferSize = bufferSize;
  if (valid)
    new TEdit(this,ID_INPUT)->SetValidator(valid);
}

TInputDialog::~TInputDialog()
{
  delete Prompt;
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

  } else if (direction == tdGetData) {
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


#endif
