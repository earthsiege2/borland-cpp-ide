//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//----------------------------------------------------------------------------

//
// This is an example of how to use TRACE macros in a program without 
// requiring an OWL diagnostic build.  
// Just define __TRACE (and/or __WARN) before any OWL headers
// Then you can use TRACE() or WARN() directly
//
#define __TRACE

#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\layoutwi.h>
#include <owl\layoutco.h>
#include <owl\dialog.h>
#include <owl\combobox.h>
#include <owl\edit.h>
#include <string.h>
#include "layout.rh"
#include "laydia.h"


DEFINE_RESPONSE_TABLE1(TLayoutDialog, TDialog)
  EV_COMMAND(ID_LAYOUT, HandleLayout),
  EV_LBN_SELCHANGE(ID_WINDOWLIST, HandleWindowChange),
END_RESPONSE_TABLE;

TLayoutDialog::TLayoutDialog(TLayoutWindow* parent,
                             TResId         resId,
                             TChildInfo*    childInfo)
  : TDialog(parent, resId),
    LayoutWindow(parent),
    ChildInfo(childInfo)
{
  WindowList     = new TListBox(this, ID_WINDOWLIST);
  
  X1EdgeCombo = new TComboBox(this,ID_X1_MYEDGE);
  X2EdgeCombo = new TComboBox(this,ID_X2_MYEDGE);
  Y1EdgeCombo = new TComboBox(this,ID_Y1_MYEDGE);
  Y2EdgeCombo = new TComboBox(this,ID_Y2_MYEDGE);

  X1OtherEdgeCombo = new TComboBox(this,ID_X1_OTHEREDGE);
  X2OtherEdgeCombo = new TComboBox(this,ID_X2_OTHEREDGE);
  Y1OtherEdgeCombo = new TComboBox(this,ID_Y1_OTHEREDGE);
  Y2OtherEdgeCombo = new TComboBox(this,ID_Y2_OTHEREDGE);

  X1UnitsCombo     = new TComboBox(this, ID_X1_UNITS);
  X2UnitsCombo     = new TComboBox(this, ID_X2_UNITS);
  Y1UnitsCombo     = new TComboBox(this, ID_Y1_UNITS);
  Y2UnitsCombo     = new TComboBox(this, ID_Y2_UNITS);

  X1ValueEdit = new TEdit(this,ID_X1_VALUE);
  X2ValueEdit = new TEdit(this,ID_X2_VALUE);
  Y1ValueEdit = new TEdit(this,ID_Y1_VALUE);
  Y2ValueEdit = new TEdit(this,ID_Y2_VALUE);
  
  X1RelationCombo  = new TComboBox(this, ID_X1_RELATIONSHIP);
  X2RelationCombo  = new TComboBox(this, ID_X2_RELATIONSHIP);
  Y1RelationCombo  = new TComboBox(this, ID_Y1_RELATIONSHIP);
  Y2RelationCombo  = new TComboBox(this, ID_Y2_RELATIONSHIP);

  X1RelWinCombo    = new TComboBox(this, ID_X1_RELWIN);
  X2RelWinCombo    = new TComboBox(this, ID_X2_RELWIN);
  Y1RelWinCombo    = new TComboBox(this, ID_Y1_RELWIN);
  Y2RelWinCombo    = new TComboBox(this, ID_Y2_RELWIN);
}


struct TEnumPair {
  char far* Name;
  DWORD     Value;
};
#define ENUMPAIR(enum)   {#enum, enum}


//
// For a valid constraint....
// X2Edge must not be the same as X1 edge
// Y2Edge must not be the same as Y1 edge
// If X2Edge == lmWidth then lmLeft and lmRight relations don't make sense
// if Y2Edge == lmHeight then lmAbove and lmBelow relations don't make sense
//

TEnumPair X1EdgePairs[] = {
  ENUMPAIR(lmLeft),
  ENUMPAIR(lmCenter),
  ENUMPAIR(lmRight),
};

TEnumPair X2EdgePairs[] = {
  ENUMPAIR(lmCenter),
  ENUMPAIR(lmRight),
  ENUMPAIR(lmWidth),
};

TEnumPair Y1EdgePairs[] = {
  ENUMPAIR(lmTop),
  ENUMPAIR(lmCenter),
  ENUMPAIR(lmBottom),
};

TEnumPair Y2EdgePairs[] = {
  ENUMPAIR(lmCenter),
  ENUMPAIR(lmBottom),
  ENUMPAIR(lmHeight),
};

TEnumPair AllEdgePairs[] = {
  ENUMPAIR(lmLeft),
  ENUMPAIR(lmCenter),
  ENUMPAIR(lmRight),
  ENUMPAIR(lmTop),
  ENUMPAIR(lmBottom),
  ENUMPAIR(lmWidth),
  ENUMPAIR(lmHeight),
};


// Relations for all X edges
TEnumPair XRelationPairs[] = {
  ENUMPAIR(lmAsIs),
  ENUMPAIR(lmAbsolute),
  ENUMPAIR(lmPercentOf),
  ENUMPAIR(lmSameAs),
  ENUMPAIR(lmLeftOf),     //These should be disabled for lmWidth
  ENUMPAIR(lmRightOf),
};

TEnumPair YRelationPairs[] = {
  ENUMPAIR(lmAsIs),
  ENUMPAIR(lmAbsolute),
  ENUMPAIR(lmPercentOf),
  ENUMPAIR(lmSameAs),
  ENUMPAIR(lmAbove),      //These should be disabled for lmHeight
  ENUMPAIR(lmBelow),
};

TEnumPair RelWinPairs[MaxWindows] = {
  ENUMPAIR(lmParent),
};

TEnumPair UnitsPairs[] = {
  ENUMPAIR(lmPixels),
  ENUMPAIR(lmLayoutUnits),
};

static void FillCombo(TComboBox* combo, TEnumPair* pairs, int count)
{
  while (combo->DeleteString(0) > 0)
    ;
  for (int i = 0; i < count; i++) {
    int index = combo->AddString(pairs[i].Name);
    combo->SetItemData(index, pairs[i].Value);
  }
}

void TLayoutDialog::SetupWindow()
{
  TDialog::SetupWindow();


  // Fill the window list
  for (int i = 0; ChildInfo[i].Child && i < MaxWindows-1; i++) {
    WindowList->AddString(ChildInfo[i].Child->Title);
    RelWinPairs[i+1].Name = ChildInfo[i].Child->Title;
    RelWinPairs[i+1].Value = DWORD(ChildInfo[i].Child);
  }

  WindowList->SetSelIndex(0);

  FillCombo(X1EdgeCombo,X1EdgePairs,COUNTOF(X1EdgePairs));
  FillCombo(X2EdgeCombo,X2EdgePairs,COUNTOF(X2EdgePairs));
  FillCombo(Y1EdgeCombo,Y1EdgePairs,COUNTOF(Y1EdgePairs));
  FillCombo(Y2EdgeCombo,Y2EdgePairs,COUNTOF(Y2EdgePairs));

  FillCombo(X1OtherEdgeCombo,AllEdgePairs,COUNTOF(AllEdgePairs));
  FillCombo(X2OtherEdgeCombo,AllEdgePairs,COUNTOF(AllEdgePairs));
  FillCombo(Y1OtherEdgeCombo,AllEdgePairs,COUNTOF(AllEdgePairs));
  FillCombo(Y2OtherEdgeCombo,AllEdgePairs,COUNTOF(AllEdgePairs));

  FillCombo(X1UnitsCombo, UnitsPairs, COUNTOF(UnitsPairs));
  FillCombo(X2UnitsCombo, UnitsPairs, COUNTOF(UnitsPairs));
  FillCombo(Y1UnitsCombo, UnitsPairs, COUNTOF(UnitsPairs));
  FillCombo(Y2UnitsCombo, UnitsPairs, COUNTOF(UnitsPairs));
  
  X1ValueEdit->SetText("");
  X2ValueEdit->SetText("");
  Y1ValueEdit->SetText("");
  Y2ValueEdit->SetText("");

  FillCombo(X1RelationCombo, XRelationPairs, COUNTOF(XRelationPairs));
  FillCombo(X2RelationCombo, XRelationPairs, COUNTOF(XRelationPairs));
  FillCombo(Y1RelationCombo, YRelationPairs, COUNTOF(YRelationPairs));
  FillCombo(Y2RelationCombo, YRelationPairs, COUNTOF(YRelationPairs));

  FillCombo(X1RelWinCombo, RelWinPairs, i+1);
  FillCombo(X2RelWinCombo, RelWinPairs, i+1);
  FillCombo(Y1RelWinCombo, RelWinPairs, i+1);
  FillCombo(Y2RelWinCombo, RelWinPairs, i+1);

  ChildNum = -1;  //Flag to signal initial call to HandleWindowChange
  HandleWindowChange();
}

static void SelectItemData(TComboBox* combo, DWORD itemData)
{
  int count = combo->GetCount();
  combo->SetSelIndex(-1); //Clear the selection
  for (int i = 0; i < count; i++)
    if (combo->GetItemData(i) == itemData) {
      combo->SetSelIndex(i);
      return;
    }
  TRACE("Couldn't find lmXxx (" << itemData <<") in list");
}

//
// Take a given layout constraint & shove it into the dialog
//
void TLayoutDialog::SetLayoutConstraint(TLayoutConstraint& lc, Constraint which)
{
  char buff[20];

  switch (which) {
    case X1:
      SelectItemData(X1EdgeCombo, lc.MyEdge);
      SelectItemData(X1RelationCombo, lc.Relationship);
      SelectItemData(X1RelWinCombo, DWORD(lc.RelWin));
      SelectItemData(X1OtherEdgeCombo, lc.OtherEdge);
      SelectItemData(X1UnitsCombo, lc.Units);
      wsprintf(buff, "%d", lc.Value);
      X1ValueEdit->SetText(buff);
      break;

    case X2:
      SelectItemData(X2EdgeCombo, lc.MyEdge);
      SelectItemData(X2RelationCombo, lc.Relationship);
      SelectItemData(X2RelWinCombo, DWORD(lc.RelWin));
      SelectItemData(X2OtherEdgeCombo, lc.OtherEdge);
      SelectItemData(X2UnitsCombo, lc.Units);
      wsprintf(buff, "%d", lc.Value);
      X2ValueEdit->SetText(buff);
      break;

    case Y1:
      SelectItemData(Y1EdgeCombo, lc.MyEdge);
      SelectItemData(Y1RelationCombo, lc.Relationship);
      SelectItemData(Y1RelWinCombo, DWORD(lc.RelWin));
      SelectItemData(Y1OtherEdgeCombo, lc.OtherEdge);
      SelectItemData(Y1UnitsCombo, lc.Units);
      wsprintf(buff, "%d", lc.Value);
      Y1ValueEdit->SetText(buff);
      break;

    case Y2:
      SelectItemData(Y2EdgeCombo, lc.MyEdge);
      SelectItemData(Y2RelationCombo, lc.Relationship);
      SelectItemData(Y2RelWinCombo, DWORD(lc.RelWin));
      SelectItemData(Y2OtherEdgeCombo, lc.OtherEdge);
      SelectItemData(Y2UnitsCombo, lc.Units);
      wsprintf(buff, "%d", lc.Value);
      Y2ValueEdit->SetText(buff);
      break;
  }
}

//
// Retrieve a layout constraint from the dialog
//
void TLayoutDialog::GetLayoutConstraint(TLayoutConstraint& lc, Constraint which)
{
  char buff[20];
  switch (which) {
    case X1:
      lc.MyEdge = (TEdge)X1EdgeCombo->GetItemData(X1EdgeCombo->GetSelIndex());
      lc.Relationship = (TRelationship)X1RelationCombo->GetItemData(X1RelationCombo->GetSelIndex());
      lc.RelWin = (TWindow*)X1RelWinCombo->GetItemData(X1RelWinCombo->GetSelIndex());
      lc.OtherEdge = (TEdge)X1OtherEdgeCombo->GetItemData(X1OtherEdgeCombo->GetSelIndex());
      lc.Units = (TMeasurementUnits)X1UnitsCombo->GetItemData(X1UnitsCombo->GetSelIndex());
      X1ValueEdit->GetText(buff, sizeof buff);
      lc.Value = atoi(buff);
      break;

    case X2:
      lc.MyEdge = (TEdge)X2EdgeCombo->GetItemData(X2EdgeCombo->GetSelIndex());
      lc.Relationship = (TRelationship)X2RelationCombo->GetItemData(X2RelationCombo->GetSelIndex());
      lc.RelWin = (TWindow*)X2RelWinCombo->GetItemData(X2RelWinCombo->GetSelIndex());
      lc.OtherEdge = (TEdge)X2OtherEdgeCombo->GetItemData(X2OtherEdgeCombo->GetSelIndex());
      lc.Units = (TMeasurementUnits)X2UnitsCombo->GetItemData(X2UnitsCombo->GetSelIndex());
      X2ValueEdit->GetText(buff, sizeof buff);
      lc.Value = atoi(buff);
      break;

    case Y1:
      lc.MyEdge = (TEdge)Y1EdgeCombo->GetItemData(Y1EdgeCombo->GetSelIndex());
      lc.Relationship = (TRelationship)Y1RelationCombo->GetItemData(Y1RelationCombo->GetSelIndex());
      lc.RelWin = (TWindow*)Y1RelWinCombo->GetItemData(Y1RelWinCombo->GetSelIndex());
      lc.OtherEdge = (TEdge)Y1OtherEdgeCombo->GetItemData(Y1OtherEdgeCombo->GetSelIndex());
      lc.Units = (TMeasurementUnits)Y1UnitsCombo->GetItemData(Y1UnitsCombo->GetSelIndex());
      Y1ValueEdit->GetText(buff, sizeof buff);
      lc.Value = atoi(buff);
      break;

    case Y2:
      lc.MyEdge = (TEdge)Y2EdgeCombo->GetItemData(Y2EdgeCombo->GetSelIndex());
      lc.Relationship = (TRelationship)Y2RelationCombo->GetItemData(Y2RelationCombo->GetSelIndex());
      lc.RelWin = (TWindow*)Y2RelWinCombo->GetItemData(Y2RelWinCombo->GetSelIndex());
      lc.OtherEdge = (TEdge)Y2OtherEdgeCombo->GetItemData(Y2OtherEdgeCombo->GetSelIndex());
      lc.Units = (TMeasurementUnits)Y2UnitsCombo->GetItemData(Y2UnitsCombo->GetSelIndex());
      Y2ValueEdit->GetText(buff, sizeof buff);
      lc.Value = atoi(buff);
      break;

  }
}

// Window changed
// Ask user to save current layout constraints?

void TLayoutDialog::HandleWindowChange()
{
  if (ChildNum>=0) {
    // Save all of the current settings, unless this is the first call
    GetLayoutConstraint(ChildInfo[ChildNum].LayoutMetrics.X,X1);
    GetLayoutConstraint(ChildInfo[ChildNum].LayoutMetrics.Width,X2);
    GetLayoutConstraint(ChildInfo[ChildNum].LayoutMetrics.Y,Y1);
    GetLayoutConstraint(ChildInfo[ChildNum].LayoutMetrics.Height,Y2);
  }
  // Switch to new window
  ChildNum = WindowList->GetSelIndex();
  SetLayoutConstraint(ChildInfo[ChildNum].LayoutMetrics.X,X1);
  SetLayoutConstraint(ChildInfo[ChildNum].LayoutMetrics.Width,X2);
  SetLayoutConstraint(ChildInfo[ChildNum].LayoutMetrics.Y,Y1);
  SetLayoutConstraint(ChildInfo[ChildNum].LayoutMetrics.Height,Y2);
}

// Get the constraints from each window, update child window
void TLayoutDialog::HandleLayout()
{
  TLayoutMetrics& lm = ChildInfo[ChildNum].LayoutMetrics;

  GetLayoutConstraint(lm.X,X1);
  GetLayoutConstraint(lm.Width,X2);
  GetLayoutConstraint(lm.Y,Y1);
  GetLayoutConstraint(lm.Height,Y2);

  // Check some basic restrictions
  if (lm.X.MyEdge == lm.Width.MyEdge) {
      MessageBox("X1.MyEdge can not be the same as X2.MyEdge");
      return;
      }
  if (lm.Y.MyEdge == lm.Height.MyEdge) {
      MessageBox("Y1.MyEdge can not be the same as Y2.MyEdge");
      return;
      }

  Parent->PostMessage(WM_COMMAND, CM_RELAYOUT);
}
