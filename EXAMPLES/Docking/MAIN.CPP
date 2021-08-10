//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "dockform.h"
#include "tabhost.h"
#include "conjoinhost.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TMainForm *MainForm;

const static int WindowCount = 7;

const
  TColor Colors[WindowCount] =
    { clWhite, clBlue, clGreen, clRed, clTeal,
      clPurple, clLime };

const
  AnsiString ColStr[WindowCount] =
    { "White", "Blue", "Green", "Red", "Teal",
      "Purple", "Lime" };

TDockableForm* DockWindows[WindowCount];

//---------------------------------------------------------------------------

void TMainForm::CreateDockableWindows()
{
  for (int I = 0; I < WindowCount; I++)
  {
    DockWindows[I] = new TDockableForm(Application);

    DockWindows[I]->Caption = ColStr[I];
    DockWindows[I]->Memo1->Color = Colors[I];
    DockWindows[I]->Memo1->Font->Color = (TColor)(Colors[I] ^ 0x00FFFFFF);
    DockWindows[I]->Memo1->Text = ColStr[I] + " window ";
  }
}

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
  CreateDockableWindows();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CoolBar1DockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
  Accept = (dynamic_cast<TToolBar*>(Source->Control) != NULL);
  if (Accept)
  {
    // Modify the DockRect to preview dock area (Coolbar client area)
    Windows::TPoint TopLeft = Windows::TPoint(CoolBar1->ClientRect.Left, CoolBar1->ClientRect.Top);
    TopLeft = CoolBar1->ClientToScreen(TopLeft);

    Windows::TPoint BottomRight = Windows::TPoint(CoolBar1->ClientRect.Right, CoolBar1->ClientRect.Bottom);
    BottomRight = CoolBar1->ClientToScreen(BottomRight);

    Source->DockRect = Windows::TRect(TopLeft, BottomRight);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ExitActionExecute(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ViewToolBar1Execute(TObject *Sender)
{
  // Toggles the visible state of Toolbar1, regardless of its docked state.
  ToolBar11->Checked = !ToolBar11->Checked;
  tbToolBar1->Down = ToolBar11->Checked;

  if (ToolBar1->Floating)
    ToolBar1->HostDockSite->Visible = ToolBar11->Checked;
  else
    ToolBar1->Visible = ToolBar11->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ViewToolBar2Execute(TObject *Sender)
{
  // Toggles the visible state of Toolbar2, regardless of its docked state.
  ToolBar21->Checked = !ToolBar21->Checked;
  tbToolBar2->Down = ToolBar21->Checked;
  if (ToolBar2->Floating)
  {
    TToolDockForm* ToolDockForm = dynamic_cast<TToolDockForm*>(ToolBar2->HostDockSite);
    if (ToolDockForm != NULL)
    {
      // We need to resort to a hack here, since the Visible property
      // of TToolDockForm is *protected*. Object Pascal allows access to
      // this (protected) property, C++ does not.

      // Introduce a bit of safety: check that TToolDockForm and TForm
      // both descend from TCustomForm
      if (    !InheritsFrom(__classid(TToolDockForm), __classid(TCustomForm))
           || !InheritsFrom(__classid(TForm), __classid(TCustomForm)) )
        throw("Internal error - VCL has been redesigned");

      // "Cross"-cast the dockable form to a TForm; this is safe, as
      // Visible is implemented earlier than TCustomForm, just "published"
      // later as a property
      reinterpret_cast<TForm*>(ToolDockForm)->Visible = ToolBar21->Checked;
    }
  }
  else
    ToolBar2->Visible = ToolBar21->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GenericViewWindowExecute(TObject *Sender)
{
  TDockableForm* DockWindow;

  DockWindow = DockWindows[dynamic_cast<TComponent*>(Sender)->Tag];
  if (DockWindow == NULL)
    throw EInvalidCast("");

  // If the docked window is TabDocked, it is docked to the PageControl
  // (owned by TTabDockHost) so show the host form.
  if (dynamic_cast<TPageControl*>(DockWindow->HostDockSite) != NULL)
    static_cast<TTabDockHost*>(DockWindow->HostDockSite->Owner)->Show();
  else
    // If window is conjoin-docked, host and/or form may not be visible
    // so show both.
    if ( (dynamic_cast<TConjoinDockHost*>(DockWindow->HostDockSite) != NULL) &&
         !DockWindow->HostDockSite->Visible)
    {
      DockWindow->HostDockSite->Show();
      (static_cast<TConjoinDockHost*>(DockWindow->HostDockSite))->UpdateCaption(NULL);
      DockWindow->Show();
    }
    else
    {
      // If form is docked to one of the "hidden" docking panels, resize the
      // panel and re-show the docked form.
      if ((dynamic_cast<TPanel*>(DockWindow->HostDockSite) != NULL)
         && ((DockWindow->HostDockSite->Height == 0) | (DockWindow->HostDockSite->Width == 0)))
      {
        MainForm->ShowDockPanel((static_cast<TPanel*>(DockWindow->HostDockSite)), true, DockWindow);
      }
      else
      {
        // If the window isn't docked at all, simply show it.
        DockWindow->Show();
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LeftDockPanelDockDrop(TObject *Sender,
      TDragDockObject *Source, int X, int Y)
{
  TPanel* SenderPanel = dynamic_cast<TPanel*>(Sender);
  if (SenderPanel == NULL)
    throw EInvalidCast("");

  // OnDockDrop gets called AFTER the client has actually docked,
  // so we check for DockClientCount = 1 before making the dock panel visible.
  if (SenderPanel->DockClientCount == 1)
    ShowDockPanel(SenderPanel, true, NULL);
  SenderPanel->DockManager->ResetBounds(true);
  // Make DockManager repaints it's clients.
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LeftDockPanelDockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
  Accept = (dynamic_cast<TDockableForm*>(Source->Control) != NULL);
  if (Accept)
  {
    // Modify the DockRect to preview dock area.
    Windows::TPoint TopLeft = LeftDockPanel->ClientToScreen(Point(0, 0));
    Windows::TPoint BottomRight = LeftDockPanel->ClientToScreen(
      Point(this->ClientWidth / 3, LeftDockPanel->Height));
    Source->DockRect = Windows::TRect(TopLeft, BottomRight);
  }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LeftDockPanelGetSiteInfo(TObject *Sender,
      TControl *DockClient, TRect &InfluenceRect, TPoint &MousePos,
      bool &CanDock)
{
  // If CanDock is true, the panel will not automatically draw the preview rect.
  CanDock = (dynamic_cast<TDockableForm*>(DockClient) != NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LeftDockPanelUnDock(TObject *Sender,
      TControl *Client, TWinControl *NewTarget, bool &Allow)
{
  TPanel* SenderPanel = dynamic_cast<TPanel*>(Sender);
  if (SenderPanel == NULL)
    throw EInvalidCast("");

  // OnUnDock gets called BEFORE the client is undocked, in order to optionally
  // disallow the undock. DockClientCount is never 0 when called from this event.
  if (SenderPanel->DockClientCount == 1)
    ShowDockPanel(SenderPanel, false, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BottomDockPanelDockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
  Accept = (dynamic_cast<TDockableForm*>(Source->Control) != NULL);
  if (Accept)
  {
    // Modify the DockRect to preview dock area.
    Windows::TPoint TopLeft = BottomDockPanel->ClientToScreen(
      Point(0, -this->ClientHeight / 3));
    Windows::TPoint BottomRight = BottomDockPanel->ClientToScreen(
      Point(BottomDockPanel->Width, BottomDockPanel->Height));
    Source->DockRect = Windows::TRect(TopLeft, BottomRight);
  }
}
//---------------------------------------------------------------------------

void TMainForm::ShowDockPanel(TPanel* APanel, bool MakeVisible, TControl* Client)
{
  // Client - the docked client to show if we are re-showing the panel.
  // Client is ignored if hiding the panel.

  // Since docking to a non-visible docksite isn't allowed, instead of setting
  // Visible for the panels we set the width to zero. The default InfluenceRect
  // for a control extends a few pixels beyond it's boundaries, so it is possible
  // to dock to zero width controls.

  // Don't try to hide a panel which has visible dock clients.
  if (!MakeVisible && (APanel->VisibleDockClientCount > 1))
    return;

  if (APanel == LeftDockPanel)
    VSplitter->Visible = MakeVisible;
  else
    HSplitter->Visible = MakeVisible;

    if (MakeVisible)
    {
      if (APanel == LeftDockPanel)
      {
        APanel->Width = ClientWidth / 3;
        VSplitter->Left = APanel->Width + VSplitter->Width;
      }
      else
      {
        APanel->Height = ClientHeight / 3;
        HSplitter->Top = ClientHeight - APanel->Height - HSplitter->Width;
      }
    }
    else
    {
      if (APanel == LeftDockPanel)
        APanel->Width = 0;
      else
        APanel->Height = 0;
    }

  if (MakeVisible && (Client != NULL))
    Client->Show();
}

