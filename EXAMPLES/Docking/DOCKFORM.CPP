//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "dockform.h"
#include "conjoinhost.h"
#include "main.h"
#include "tabhost.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

//---------------------------------------------------------------------------
__fastcall TDockableForm::TDockableForm(TComponent* Owner)
  : TForm(Owner)
{
}

TAlign TDockableForm::ComputeDockingRect(TRect & DockRect, const TPoint & MousePos)
{
  Types::TRect  DockTopRect,
                  DockLeftRect,
                  DockBottomRect,
                  DockRightRect,
                  DockCenterRect;

  Types::TPoint TopLeft,
                  BottomRight;

  TAlign Result = alNone;

  // Divide form up into docking "Zones"
  TopLeft = Types::TPoint(0, 0);
  BottomRight = Types::TPoint(ClientWidth / 5, ClientHeight);
  DockLeftRect = Types::TRect(TopLeft, BottomRight);

  TopLeft = Types::TPoint(ClientWidth / 5, 0);
  BottomRight = Types::TPoint(ClientWidth / 5 * 4, ClientHeight / 5);
  DockTopRect = Types::TRect(TopLeft, BottomRight);

  TopLeft = Types::TPoint(ClientWidth / 5 * 4, 0);
  BottomRight = Types::TPoint(ClientWidth, ClientHeight);
  DockRightRect = Types::TRect(TopLeft, BottomRight);

  TopLeft = Types::TPoint(ClientWidth / 5, ClientHeight / 5 * 4);
  BottomRight = Types::TPoint(ClientWidth / 5 * 4, ClientHeight);
  DockBottomRect = Types::TRect(TopLeft, BottomRight);

  TopLeft = Types::TPoint(ClientWidth / 5, ClientHeight / 5);
  BottomRight = Types::TPoint(ClientWidth / 5 * 4, ClientHeight / 5 * 4);
  DockCenterRect = Types::TRect(TopLeft, BottomRight);

  // Find out where the mouse cursor is,
  // to decide where to draw dock preview.
  if (PtInRect(&DockLeftRect, MousePos))
  {
    Result = alLeft;
    DockRect = DockLeftRect;
    DockRect.Right = ClientWidth / 2;
  }
  else
    if (PtInRect(&DockTopRect, MousePos))
    {
      Result = alTop;
      DockRect = DockTopRect;
      DockRect.Left = 0;
      DockRect.Right = ClientWidth;
      DockRect.Bottom = ClientHeight / 2;
    }
    else
      if (PtInRect(&DockRightRect, MousePos))
      {
        Result = alRight;
        DockRect = DockRightRect;
        DockRect.Left = ClientWidth / 2;
      }
      else
        if (PtInRect(&DockBottomRect, MousePos))
        {
          Result = alBottom;
          DockRect = DockBottomRect;
          DockRect.Left = 0;
          DockRect.Right = ClientWidth;
          DockRect.Top = ClientHeight / 2;
        }
        else
          if (PtInRect(&DockCenterRect, MousePos))
          {
            Result = alClient;
            DockRect = DockCenterRect;
          }

  if (Result != alNone)
  {
    // DockRect is in screen coordinates.
    TopLeft = ClientToScreen(Types::TPoint(DockRect.Left, DockRect.Top));
    BottomRight = ClientToScreen(Types::TPoint(DockRect.Right, DockRect.Bottom));

    DockRect = TRect(TopLeft, BottomRight);
  }

  return Result;
}

//---------------------------------------------------------------------------
void __fastcall TDockableForm::FormClose(TObject *Sender, TCloseAction &Action)
{
  // The action taken depends on how the form is docked.

  if (dynamic_cast<TConjoinDockHost*>(HostDockSite) != NULL)
  {
    // Remove the form's caption from the conjoin dock host's caption list
    (static_cast<TConjoinDockHost*>(HostDockSite))->UpdateCaption(this);

    // If we're the last visible form on a conjoined form, hide the form
    if (HostDockSite->VisibleDockClientCount <= 1)
      HostDockSite->Hide();
  }

  // If docked to a panel, tell the panel to hide itself. If there are other
  // visible dock clients on the panel, it ShowDockPanel won't allow it to
  // be hidden
  if (dynamic_cast<TPanel*>(HostDockSite) != NULL)
    MainForm->ShowDockPanel(static_cast<TPanel*>(HostDockSite), false, NULL);

  Action = caHide;
}
//---------------------------------------------------------------------------

void __fastcall TDockableForm::FormDockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
  TRect ARect;

  Accept = (dynamic_cast<TDockableForm*>(Source->Control) != NULL);

  // Draw dock preview depending on where the cursor is relative to our client area
  if (Accept && (ComputeDockingRect(ARect, Point(X, Y)) != alNone))
    Source->DockRect = ARect;
}
//---------------------------------------------------------------------------

void __fastcall TDockableForm::CMDockClient(TCMDockClient& Message)
{
  TRect ARect;
  TAlign DockType;
  TForm* Host;
  Types::TPoint Pt;

  // Overriding this message allows the dock form to create host forms
  // depending on the mouse position when docking occurs. If we don't override
  // this message, the form will use VCL's default DockManager.

  // NOTE: the only time ManualDock can be safely called during a drag
  //       operation is we override processing of CM_DOCKCLIENT.

  if (dynamic_cast<TDockableForm*>(Message.DockSource->Control) != NULL)
  {

    // Find out how to dock (using a TAlign as the result of ComputeDockingRect)
    Pt.x = Message.MousePos.x;
    Pt.y = Message.MousePos.y;
    DockType = ComputeDockingRect(ARect, Pt);

    // If we are over a dockable form docked to a panel in the
    // main window, manually dock the dragged form to the panel with
    // the correct orientation.
    if (dynamic_cast<TPanel*>(HostDockSite) != NULL)
    {
      Message.DockSource->Control->ManualDock(HostDockSite, NULL, DockType);
      return;
    }

    // alClient => Create a TabDockHost and manually dock both forms
    // to the PageControl owned by the TabDockHost.
    if (DockType == alClient)
    {
      Host = new TTabDockHost(Application);
      Host->BoundsRect = this->BoundsRect;

      TPageControl* PageControl = dynamic_cast<TTabDockHost*>(Host)->PageControl1;

      if (PageControl == NULL)
        throw EInvalidCast("");

      this->ManualDock(PageControl, NULL, alClient);
      Message.DockSource->Control->ManualDock(PageControl, NULL, alClient);
      Host->Visible = true;
    }
    // If DockType <> alClient, create the ConjoinDockHost and manually dock both
    // forms to it. Be sure to make dockable forms non-dockable when hosted by
    // ConjoinDockForm, since it is using the VCL default DockManager.
    else {
      Host = new TConjoinDockHost(Application);
      Host->BoundsRect = this->BoundsRect;
      this->ManualDock(Host, NULL, alNone);
      this->DockSite = false;
      Message.DockSource->Control->ManualDock(Host, NULL, DockType);
      dynamic_cast<TDockableForm*>(Message.DockSource->Control)->DockSite = false;
      Host->Visible = true;
    }
  }
}

void __fastcall TDockableForm::FormShow(TObject *Sender)
{
  if (dynamic_cast<TConjoinDockHost*>(HostDockSite) != NULL)
    (static_cast<TConjoinDockHost*>(HostDockSite))->UpdateCaption(NULL);
}
//---------------------------------------------------------------------------

