//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\checkbox.cpp
//   Implemenation ofclass TCheckBox.  This defines the basic behavior
//   for all check boxes.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\checkbox.h>
#include <owl\groupbox.h>
#include <owl\applicat.h>
#include <bwcc.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TCheckBox, TButton)
  EV_WM_GETDLGCODE,
  EV_NOTIFY_AT_CHILD(BN_CLICKED, BNClicked),
END_RESPONSE_TABLE;

//
// constructor for a TCheckBox object
//
TCheckBox::TCheckBox(TWindow*        parent,
                     int             id,
                     const char far* title,
                     int x, int y, int w, int h,
                     TGroupBox*      group,
                     TModule*        module)
  : TButton(parent, id, title, x, y, w, h, FALSE, module)
{
  Group = group;
  //
  // Don't use TButton's inherited style - it conflicts with BS_AUTOCHECKBOX
  //
  Attr.Style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTOCHECKBOX;
}

//
// constructor for a TCheckBox to be associated with a MS-Windows interface
// element created by MS-Windows from a resource definition
//
// data transfer is enabled for the TCheckBox
//
TCheckBox::TCheckBox(TWindow*   parent,
                     int        resourceId,
                     TGroupBox* group,
                     TModule*   module)
  : TButton(parent, resourceId, module)
{
  Group = group;
  EnableTransfer();
}

//
// Return name of predefined BWCC or Windows check box class
//
char far*
TCheckBox::GetClassName()
{
  if (GetApplication()->BWCCEnabled())
    return CHECK_CLASS;
  else
    return "BUTTON";
}

//
// transfers state information for the TCheckBox
//
// the direction passed specifies whether data is to be read from or
// written to the passed buffer, or whether the data element size is simply
// to be returned
//
// the return value is the size (in bytes) of the transfer data
//
UINT
TCheckBox::Transfer(void* buffer, TTransferDirection direction)
{
  if (direction == tdGetData)
    *(UINT*)buffer = GetCheck();

  else if (direction == tdSetData)
    SetCheck(*(UINT*)buffer);

  return sizeof(UINT);
}

//
// sets the check state
//
// unchecks, checks, or grays the checkbox (if 3-state) according to the
// CheckFlag passed (pass BF_UNCHECKED(0), BF_CHECKED(1), or BF_GRAYED(2))
//
// if a Group has been specified for the TCheckBox, notifies the Group that
// the state of the check box has changed
//
void
TCheckBox::SetCheck(UINT check)
{
  HandleMessage(BM_SETCHECK, check);

  if (Group)
    Group->SelectionChanged(Attr.Id);
}

//
// toggles the check state of the check box
//
void
TCheckBox::Toggle()
{
  if ((GetWindowLong(GWL_STYLE) & BS_AUTO3STATE) == BS_AUTO3STATE)
    SetCheck((GetCheck() + 1) % 3);

  else
    SetCheck((GetCheck() + 1) % 2);
}

//
// responds to an incoming BN_CLICKED message
//
// if a Group has been specified for the TCheckBox, notifies the Group that
// the state of this TCheckBox has changed
//
void
TCheckBox::BNClicked()
{
  if (Group)
    Group->SelectionChanged(Attr.Id);

  DefaultProcessing();  // give parent an opportunity to handle...
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TCheckBox, TButton);

//
// reads an instance of TCheckBox from the passed ipstream
//
void*
TCheckBox::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TButton*)GetObject(), is);
  is >> GetObject()->Group;
  return GetObject();
}

//
// writes the TCheckBox to the passed opstream
//
void
TCheckBox::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TButton*)GetObject(), os);
  os << GetObject()->Group;
}
#endif
