//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//
// Implemenation of class TCheckBox.  This defines the basic behavior for all
// check boxes.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_CHECKBOX_H)
# include <owl/checkbox.h>
#endif
#if !defined(OWL_GROUPBOX_H)
# include <owl/groupbox.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif

#if defined(BI_COMP_BORLANDC)
# include <bwcc.h>
#endif

DIAG_DECLARE_GROUP(OwlControl);

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
:
  TButton(parent, id, title, x, y, w, h, false, module)
{
  Group = group;
  //
  // Don't use TButton's inherited style - it conflicts with BS_AUTOCHECKBOX
  //
  Attr.Style = WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_AUTOCHECKBOX;

  TRACEX(OwlControl, OWL_CDLEVEL, "TCheckBox constructed @" << (void*)this);
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
:
  TButton(parent, resourceId, module)
{
  Group = group;
  EnableTransfer();

  TRACEX(OwlControl, OWL_CDLEVEL, "TCheckBox constructed from resource @" << (void*)this);
}

//
// Output a trace message if using the diagnostic libraries.
//
TCheckBox::~TCheckBox()
{
  TRACEX(OwlControl, OWL_CDLEVEL, "TCheckBox destructed @" << (void*)this);
}

//
// Return name of predefined BWCC or Windows check box class
//
char far*
TCheckBox::GetClassName()
{
#if defined(BI_COMP_BORLANDC)
  if (GetApplication()->BWCCEnabled()) {
    TRACEX(OwlControl, 1, "BWCC checkbox used for classname @" << (void*)this);
    return CHECK_CLASS;
  }
#endif
  TRACEX(OwlControl, 1, "Regular checkbox used for classname @" << (void*)this);
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
uint
TCheckBox::Transfer(void* buffer, TTransferDirection direction)
{
  if (direction == tdGetData)
    *(uint*)buffer = GetCheck();

  else if (direction == tdSetData)
    SetCheck(*(uint*)buffer);

  return sizeof(uint);
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
TCheckBox::SetCheck(uint check)
{
  PRECONDITION(GetHandle());
  SendMessage(BM_SETCHECK, check);

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

#if !defined(BI_NO_OBJ_STREAMING)

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

#if !defined(BI_NO_OBJ_STREAMING)

//
// writes the TCheckBox to the passed opstream
//
void
TCheckBox::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TButton*)GetObject(), os);
  os << GetObject()->Group;
}
#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
