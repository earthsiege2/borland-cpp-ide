//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    statmgr.cpp
//
// Date:        27-Sep-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/dialog.h>
#include <owl/edit.h>
#include <owl/combobox.h>
#include <stdio.h>
#include "TBExpert.h"

static char Temp[255];

//
// class TGadgetDialog
// ~~~~~ ~~~~~~~~~~~~~
class TGadgetDialog : public TDialog {
  public:
    TGadgetDialog(int factoryIndex, TWindow* parent, TResId resId)
    :
      TDialog(parent, resId),
      FactoryIndex(factoryIndex)
    {
      Id = new TEdit(this, ID_ID);
      ResId = new TEdit(this, ID_RESID);
      BorderStyle = new TComboBox(this, ID_BORDERSTYLE);
    }

   ~TGadgetDialog() { CloseWindow(); }

    void SetupWindow();
    void CleanupWindow();

    void CmDummy() {
//      CloseWindow();
//      GetApplication()->GetMainWindow()->GetClientWindow()->PostMessage(WUM_DONEMODIFYINGGADGET);
    }

    TEdit* ResId;
    TEdit* Id;
    TComboBox* BorderStyle;
    int FactoryIndex;

  DECLARE_RESPONSE_TABLE(TGadgetDialog);
};

DEFINE_RESPONSE_TABLE1(TGadgetDialog, TDialog)
  EV_COMMAND(IDOK, CmDummy),
  EV_COMMAND(IDCANCEL, CmDummy),
END_RESPONSE_TABLE;

void
TGadgetDialog::SetupWindow()
{
  TDialog::SetupWindow();
  TGadgetFactory* factory = GadgetFactories[FactoryIndex];

  if (factory->GetResId())
    ResId->SetText(factory->GetResId());
  else
    ResId->SetText("");

  sprintf(Temp, "%d", factory->GetId());
  Id->SetText(Temp);

  struct {
    char* Name;
  } mapping[] = {
    { "None" },
    { "Plain" },
    { "Raised" },
    { "Recessed" },
    { "Embossed" },
    { "Grooved" },
    { "ButtonUp" },
    { "ButtonDn" },
    { "WndRaised" },
    { "WndRecessed" },
    { "WellSet" }
  };

  for (int i = 0; i < sizeof mapping/sizeof mapping[0]; i++)
    BorderStyle->AddString(mapping[i].Name);
  BorderStyle->SetSelIndex(factory->GetBorderStyle());
}

void
TGadgetDialog::CleanupWindow()
{
  TGadgetFactory* factory = GadgetFactories[FactoryIndex];

  Id->GetText(Temp, sizeof Temp);
  int id = 0;
  sscanf(Temp, "%d", &id);
  factory->SetId(id);

  ResId->GetText(Temp, sizeof Temp);
  factory->SetResId(Temp);

  int borderStyle = BorderStyle->GetSelIndex();
  factory->SetBorderStyle(borderStyle);

  GetApplication()->GetMainWindow()->GetClientWindow()->PostMessage(WUM_DONEMODIFYINGGADGET);
  TDialog::CleanupWindow();
}

//
// class TTextGadgetDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~
class TTextGadgetDialog : public TGadgetDialog {
  public:
    TTextGadgetDialog(int factoryIndex, TWindow* parent, TResId id)
    :
      TGadgetDialog(factoryIndex, parent, id)
    {
      Align = new TComboBox(this, ID_ALIGN);
      NumChar = new TEdit(this, ID_NUMCHARS);
      Text = new TEdit(this, ID_TEXT);
    }

   ~TTextGadgetDialog() { CloseWindow(); }

    void SetupWindow();
    void CleanupWindow();

    TComboBox* Align;
    TEdit* NumChar;
    TEdit* Text;
};

void
TTextGadgetDialog::SetupWindow()
{
  TGadgetDialog::SetupWindow();
  TGadgetFactory* factory = GadgetFactories[FactoryIndex];

  Text->SetText(factory->GetGadgetText());
  sprintf(Temp, "%d", factory->GetNumChars());
  NumChar->SetText(Temp);

  struct {
    char* Name;
  } mapping[] = {
    { "Left" },
    { "Center" },
    { "Right" }
  };

  for (int i = 0; i < sizeof mapping/sizeof mapping[0]; i++)
    Align->AddString(mapping[i].Name);
  Align->SetSelIndex(factory->GetAlign());
}

void
TTextGadgetDialog::CleanupWindow()
{
  TGadgetFactory* factory = GadgetFactories[FactoryIndex];

  NumChar->GetText(Temp, sizeof Temp);
  int numChar = 0;
  sscanf(Temp, "%d", &numChar);
  factory->SetNumChars(numChar);

  factory->SetAlign(Align->GetSelIndex());


  Text->GetText(Temp, sizeof Temp);
  factory->SetGadgetText(Temp);

  TGadgetDialog::CleanupWindow();
}

//
// class TModeGadgetDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~
class TModeGadgetDialog : public TTextGadgetDialog {
  public:
    TModeGadgetDialog(int factoryIndex, TWindow* parent, TResId id)
    :
      TTextGadgetDialog(factoryIndex, parent, id)
    {
      Key = new TEdit(this, ID_KEY);
    }

   ~TModeGadgetDialog() { CloseWindow(); }

    void SetupWindow();
    void CleanupWindow();

    TEdit* Key;
};

void
TModeGadgetDialog::SetupWindow()
{
  TTextGadgetDialog::SetupWindow();
  TGadgetFactory* factory = GadgetFactories[FactoryIndex];

  sprintf(Temp, "%d", factory->GetKey());
  Key->SetText(Temp);
}

void
TModeGadgetDialog::CleanupWindow()
{
  TGadgetFactory* factory = GadgetFactories[FactoryIndex];

  Key->GetText(Temp, sizeof Temp);
  int key = 0;
  sscanf(Temp, "%d", &key);
  factory->SetKey(key);

  TTextGadgetDialog::CleanupWindow();
}

//
// class TButtonGadgetDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~~~
class TButtonGadgetDialog : public TGadgetDialog {
  public:
    TButtonGadgetDialog(int factoryIndex, TWindow* parent, TResId id)
    :
      TGadgetDialog(factoryIndex, parent, id)
    {
      ButtonState = new TComboBox(this, ID_STATE);
      ButtonType = new TComboBox(this, ID_TYPE);
    }

   ~TButtonGadgetDialog() { CloseWindow(); }

    void SetupWindow();
    void CleanupWindow();

    TComboBox* ButtonState;
    TComboBox* ButtonType;
};

void
TButtonGadgetDialog::SetupWindow()
{
  TGadgetDialog::SetupWindow();
  TGadgetFactory* factory = GadgetFactories[FactoryIndex];

  struct {
    char* Name;
  } typeMapping[] = {
    { "Command" },
    { "Exclusive" },
    { "NonExclusive" },
    { "SemiExclusive" },
    { "Repeat" }
  };

  for (int i = 0; i < sizeof typeMapping/sizeof typeMapping[0]; i++)
    ButtonType->AddString(typeMapping[i].Name);
  ButtonType->SetSelIndex(factory->GetButtonType());

  struct {
    char* Name;
  } stateMapping[] = {
    { "Up" },
    { "Down" },
    { "Indeterminate" }
  };

  for (int i = 0; i < sizeof stateMapping/sizeof stateMapping[0]; i++)
    ButtonState->AddString(stateMapping[i].Name);
  ButtonState->SetSelIndex(factory->GetButtonState());
}

void
TButtonGadgetDialog::CleanupWindow()
{
  TGadgetFactory* factory = GadgetFactories[FactoryIndex];

  factory->SetButtonState(ButtonState->GetSelIndex());
  factory->SetButtonType(ButtonType->GetSelIndex());

  TGadgetDialog::CleanupWindow();
}


//----------------------------------------------------------------------------
//
//

TStatusManager::TStatusManager(TWindow* parent)
:
  TLayoutWindow(parent, 0),
  Window(0),
  PrevStatus(EndDrag)
{
  TBExpertWindow = TYPESAFE_DOWNCAST(Parent, TTBExpertWindow);
  Attr.Style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
  Attr.ExStyle |= WS_EX_CLIENTEDGE;
}

TStatusManager::~TStatusManager()
{
}

void
TStatusManager::SetupWindow()
{
  TLayoutWindow::SetupWindow();
  SetDragStatus(Dragging);
}

bool
TStatusManager::EvEraseBkgnd(HDC)
{
  return true;
}

DEFINE_RESPONSE_TABLE1(TStatusManager, TLayoutWindow)
  EV_WM_ERASEBKGND,
END_RESPONSE_TABLE;


void
TStatusManager::SetDragStatus(TStatus status, int factoryIndex)
{
  PrevStatus = Status;
  Status = status;
  switch (Status) {
    case BeforeDrag:
      SetBeforeDrag();
      break;
    case BeginDrag:
      SetBeginDrag();
      break;
    case Dragging:
      SetDragging();
      break;
    case EndDrag:
      SetEndDrag();
      break;
    case ModifyGadget:
      ModifyGadgetFactory(factoryIndex);
      break;
  }
}

void
TStatusManager::ModifyGadgetFactory(int factoryIndex)
{
  TGadgetFactory::TGadgetType type = GadgetFactories[factoryIndex]->GetType();

  if (type == TGadgetFactory::Separator || type == TGadgetFactory::Time)
    return;

  delete Window;

  switch (type) {
    case TGadgetFactory::Text:
      Window = new TTextGadgetDialog(factoryIndex, this, IDD_MODIFYTEXT);
      break;

    case TGadgetFactory::Mode:
      Window = new TModeGadgetDialog(factoryIndex, this, IDD_MODIFYMODE);
      break;

    case TGadgetFactory::Button:
      Window = new TButtonGadgetDialog(factoryIndex, this, IDD_MODIFYBUTTON);
      break;

    default: {
      Window = 0;
      throw TXOwl("Unknown type");
    }
  }

  Window->Create();
  SetLayoutMetrics();
}

void
TStatusManager::SetBeforeDrag()
{
  if (PrevStatus != Status) {
    delete Window;
    Window = new TStatic(this, -1, "", 0, 0, 10, 10);
    SetLayoutMetrics();
    Window->Create();
  }
  Window->SetCaption("Please drag one of the available tools on to the toolbar.");
}

void
TStatusManager::SetBeginDrag()
{
  if (PrevStatus != Status) {
    delete Window;
    Window = new TStatic(this, -1, "", 0, 0, 10, 10);
    SetLayoutMetrics();
    Window->Create();
  }
  Window->SetCaption("Begin drag");
}

void
TStatusManager::SetDragging()
{
  if (PrevStatus != Status) {
    delete Window;
    Window = new TStatic(this, -1, "", 0, 0, 10, 10);
    SetLayoutMetrics();
    Window->Create();
  }
  Window->SetCaption("Now drop it over the toolbar");
}

void
TStatusManager::SetEndDrag()
{
  if (PrevStatus != Status) {
    delete Window;
    Window = new TStatic(this, -1, "", 0, 0, 10, 10);
    SetLayoutMetrics();
    Window->Create();
  }
  Window->SetCaption("Thank you");
}

void
TStatusManager::SetLayoutMetrics()
{
  if (Window) {
    TLayoutMetrics lmWindow;
    lmWindow.X.SameAs(lmParent, lmLeft);
    lmWindow.Y.SameAs(lmParent, lmTop);
    lmWindow.Width.SameAs(lmParent, lmRight);
    lmWindow.Height.SameAs(lmParent, lmBottom);
    SetChildLayoutMetrics(*Window, lmWindow);
    if (IsWindow())
      Layout();
  }
}
