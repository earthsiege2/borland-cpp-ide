//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// Implementation of class TControlGadget.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_CONTROLG_H)
# include <owl/controlg.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif
#if !defined(OWL_TOOLTIP_H)
# include <owl/tooltip.h>
#endif

OWL_DIAGINFO;
DIAG_DECLARE_GROUP(OwlGadget);

//
//
//
TControlGadget::TControlGadget(TWindow& control, TBorderStyle border)
:
  TGadget(control.Attr.Id, border)
{
  Control = &control;
  Control->ModifyStyle(0, WS_CLIPSIBLINGS);  // Make sure relayout paints OK
  TRACEX(OwlGadget, OWL_CDLEVEL, "TControlGadget constructed @" << (void*)this);
}

//
//
//
TControlGadget::~TControlGadget()
{
  Control->Destroy(0);
  delete Control;
  TRACEX(OwlGadget, OWL_CDLEVEL, "TControlGadget destructed @" << (void*)this);
}

//
//
//
void
TControlGadget::SetBounds(const TRect& bounds)
{
  TRACEX(OwlGadget, 1, "TControlGadget::SetBounds() enter @" << (void*)this <<
    " bounds = " << bounds);

  // Set the gadget bounds, then move & repaint the control
  //
  TGadget::SetBounds(bounds);
  Control->SetWindowPos(0, Bounds, SWP_NOACTIVATE|SWP_NOZORDER|SWP_NOSIZE);

  TRACEX(OwlGadget, 1, "TControlGadget::SetBounds() leave @" << (void*)this <<
    " bounds = " << bounds);
}

//
// Find out how big this control gadget wants to be. Calculated using the
// base size to get the borders, etc. plus the control size.
//
void
TControlGadget::GetDesiredSize(TSize& size)
{
  TRACEX(OwlGadget, 1, "TControlGadget::GetDesiredSize() enter @" << (void*)this <<
    " size = " << size);
  TGadget::GetDesiredSize(size);

  //    TRect rect = Control->GetWindowRect();

  if (ShrinkWrapWidth)
    size.cx += Control->Attr.W;
  if (ShrinkWrapHeight)
    size.cy += Control->Attr.H;

  TRACEX(OwlGadget, 1, "TControlGadget::GetDesiredSize() leave @" << (void*)this <<
    " size = " << size);
}

//
// Virtual called after the window holding a gadget has been created
//
void
TControlGadget::Created()
{
  PRECONDITION(Window);
  PRECONDITION(Window->GetHandle());

  // Create control is necessary
  //
  Control->SetParent(Window);
  if (Window->GetHandle() && !Control->GetHandle()) {
    Control->Create();
    Control->ShowWindow(SW_SHOWNA);
  }

  // Register control with the tooltip window (if there's one)
  //
  TTooltip* tooltip = Window->GetTooltip();
  if (tooltip) {
    CHECK(tooltip->GetHandle());

    // Register the control with the tooltip
    //
    if (Control->GetHandle()) {
      TToolInfo toolInfo(Window->GetHandle(), Control->GetHandle());
      tooltip->AddTool(toolInfo);
    }
  }
}

//
// Override the Inserted() virtual to take the oportunity to make sure that the
// control window has been created and shown
//
void
TControlGadget::Inserted()
{
  TRACEX(OwlGadget, 1, "TControlGadget::Inserted @" << (void*)this);
  Control->SetParent(Window);
  if (Window->GetHandle() && !Control->GetHandle()) {
    Control->Create();
    Control->ShowWindow(SW_SHOWNA);
  }
}

//
// Override the Remove() virtual to take the oportunity to unparent the
// control window from the owning Window
//
void
TControlGadget::Removed()
{
  TRACEX(OwlGadget, 1, "TControlGadget::Removed @" << (void*)this);
  Control->SetParent(0);
  // Should we destroy the control at this point??
  // Since it's no longer in the parent's child-list, there's a potential
  // leak. However, the semantics of this function is 'Removed' - therefore
  // one could be removing the control to be reinserted in another
  // gadgetwindow.

  // Unregister ourself with the tooltip window (if there's one)
  //
  if (Window && Window->GetHandle()) {
    TTooltip* tooltip = Window->GetTooltip();
    if (tooltip) {
      CHECK(tooltip->GetHandle());

      TToolInfo toolInfo(Window->GetHandle(), Control->GetHandle());
      tooltip->DeleteTool(toolInfo);
    }
  }
}

//
// Invalidate a rectangle within this gadget by invalidating the rect in the
// control window in addition to the owning Window
//
void
TControlGadget::InvalidateRect(const TRect& rect, bool erase)
{
  TGadget::InvalidateRect(rect, erase);
  if (Control->GetHandle())
    Control->InvalidateRect(rect, erase);
}

//
// Cause our control window to paint now if possible
//
void
TControlGadget::Update()
{
  if (Control->GetHandle())
    Control->UpdateWindow();
}
