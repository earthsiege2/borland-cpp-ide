//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Implementation of the TAnimateCtrl class
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_ANIMCTRL_H)
# include <owl/animctrl.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlCommCtrl);

// Constructor for a TAnimateCtrl to be associated with a new underlying
// control.
//
TAnimateCtrl::TAnimateCtrl(TWindow* parent, int id, int x, int y, int w, int h,
                           TModule* module)
:
 TControl(parent, id, "", x, y, w, h, module)
{
  if (!TCommCtrl::IsAvailable())
    throw TXCommCtrl();
  Attr.Style = WS_CHILD | WS_VISIBLE | ACS_CENTER | ACS_TRANSPARENT;
  TRACEX(OwlCommCtrl, OWL_CDLEVEL, "TAnimateCtrl constructed @" << (void*)this);
}

// Constructor to alias a control defined in a dialog resource
//
TAnimateCtrl::TAnimateCtrl(TWindow* parent, int resourceId, TModule* module)
:
 TControl(parent, resourceId, module)
{
  if (!TCommCtrl::IsAvailable())
    throw TXCommCtrl();
  TRACEX(OwlCommCtrl, OWL_CDLEVEL, "TAnimateCtrl constructed @" << (void*)this);
}

// Destructor
//
TAnimateCtrl::~TAnimateCtrl()
{
  TRACEX(OwlCommCtrl, OWL_CDLEVEL, "TAnimateCtrl deleted @" << (void*)this);
}

// Opens an .AVI file and displays the first frame.
// The 'res' parameter may be a resourceId if the .AVI is from a resource.
// It may also be a full path of an .AVI file.
// Use NULL (0) as 'res' to close any previously opened .AVI file.
//
bool
TAnimateCtrl::Open(char far* res)
{
  return SendMessage(ACM_OPEN, 0, TParam2(res)) != 0;
}

// Plays the .AVI file from frame index 'start' to frame index 'end'.
// The 'repeat' parameter is the number of times to play the frames.
// Use -1 for repeat to play indefinitely.
// NOTE: The control plays the clip in the backgroud while the 
//       current thread continues executing.
//
bool
TAnimateCtrl::Play(uint16 start, uint16 end, uint repeat)
{
  return SendMessage(ACM_PLAY, repeat, MkUint32(start, end)) != 0;
}

// Seek to frame index 'frame'. The value is zero-based and must not
// exceed 65,536.
//
bool
TAnimateCtrl::Seek(uint16 frame)
{
  return Play(frame, frame, 0);
}

// Stops playing the current AVI file.
//
void
TAnimateCtrl::Stop()
{
  SendMessage(ACM_STOP);
}

//
// Returns the predefined class registered by the Common Control library
// for the Animation control.
//
char far*
TAnimateCtrl::GetClassName()
{
  return ANIMATE_CLASS;
}

