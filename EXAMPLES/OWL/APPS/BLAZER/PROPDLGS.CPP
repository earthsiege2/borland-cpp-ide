//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Implementation of the property pages TSpeedPage and TBitBltPage
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "blazer.h"
#include "propdlgs.h"

//
// Declare some constant ranges for the random factor, delta, and delay values.
//
const int RandomFactorLower = 2;
const int RandomFactorUpper = 12;
const int DeltaLower = 5;
const int DeltaUpper = 15;
const int DelayLower = 1;
const int DelayUpper = 20;

DEFINE_RESPONSE_TABLE1(TSpeedPage, TPropertyPage)
  EV_WM_HELP,
END_RESPONSE_TABLE;

DEFINE_HELPCONTEXT(TSpeedPage)
  HCENTRY_CONTROL(IDH_RANDOM,  IDC_RANDOM),
  HCENTRY_CONTROL(IDH_DELTA,   IDC_DELTA),
  HCENTRY_CONTROL(IDH_DELAY,   IDC_DELAY),
END_HELPCONTEXT;

//
// Constructor to initialize values.
//
TSpeedPage::TSpeedPage(int factor, int delta, int delay, TPropertySheet* parent,
  TResId resId, const char far* title, TResId iconRes, TModule* module)
:
  FactorValue(factor),
  DeltaValue(delta),
  DelayValue(delay),
  TPropertyPage(parent, resId, title, iconRes, module)
{
  // These are place holders for where the real gauge controls are to
  // be positioned since TGauges are not real custom controls.
  //
  DeltaPlace        = new TStatic(this, IDC_DELTAPLACE);
  RandomFactorPlace = new TStatic(this, IDC_RANDOMPLACE);
  DelayPlace        = new TStatic(this, IDC_DELAYPLACE);
}


//
// SetupWindow().
// Now that the static place-holder controls are created, we can determine
// their locations using GetWindowRect and create TGauges at those locations.
// Since the place-holder controls are not visible, the gauges will appear to
// have been created along with the dialog.
//
void
TSpeedPage::SetupWindow()
{
  // Ensure child static controls are created.
  //
  TPropertyPage::SetupWindow();


  SETUP_HELPCONTEXT(TBlazerApp, TSpeedPage);

  TRect windowRect;
  TPoint p;

  // Create the random factor gauge and set its range and position.
  //
  windowRect = RandomFactorPlace->GetWindowRect();
  p = windowRect.TopLeft();
  ScreenToClient(p);
  RandomFactor = new THSlider(this, IDC_RANDOM,
    p.x, p.y, windowRect.Width(), windowRect.Height());
  RandomFactor->Create();
  RandomFactor->SetRange(RandomFactorLower, RandomFactorUpper);
  RandomFactor->SetPosition(FactorValue);

  // Create the delta gauge and set its range and position.
  //
  windowRect = DeltaPlace->GetWindowRect();
  p = windowRect.TopLeft();
  ScreenToClient(p);
  Delta = new THSlider(this, IDC_DELTA,
    p.x, p.y, windowRect.Width(), windowRect.Height());
  Delta->Create();
  Delta->SetRange(DeltaLower, DeltaUpper);
  Delta->SetPosition(DeltaValue);

  // Create the delay gauge and set its range and position.
  //
  windowRect = DelayPlace->GetWindowRect();
  p = windowRect.TopLeft();
  ScreenToClient(p);
  Delay = new THSlider(this, IDC_DELAY,
    p.x, p.y, windowRect.Width(), windowRect.Height());
  Delay->Create();
  Delay->SetRange(DelayLower, DelayUpper);
  Delay->SetPosition(DelayValue);
}

//
// CleanupWindow()
//
void
TSpeedPage::CleanupWindow()
{
  // Save the position of the gauges
  //
  FactorValue = RandomFactor->GetPosition();
  DeltaValue  = Delta->GetPosition();
  DelayValue  = Delay->GetPosition();

  CLEANUP_HELPCONTEXT(TBlazerApp, TSpeedPage);

  TPropertyPage::CleanupWindow();
}

//
// Forward WM_HELP messages up to application.
//
void
TSpeedPage::EvHelp(HELPINFO* hi)
{
  ::Application->GetMainWindow()->SendMessage(WM_HELP, 0, TParam2(hi));
}


//
// Constructor to initialize values.
//
TBitBltPage::TBitBltPage(bool blitterBlocks, bool sound,
  TPropertySheet* parent, TResId resId,
  const char far* title, TResId iconRes, TModule* module)
:
  BlitterBlocks(blitterBlocks),
  EnableSound(sound),
  TPropertyPage(parent, resId, title, iconRes, module)
{
  Destructive = new TRadioButton(this, IDC_DESTRUCTIVE);
  Sprite      = new TRadioButton(this, IDC_SPRITE);
  Sound       = new TCheckBox(this, IDC_SOUND);
}


//
// SetupWindow().
//
void
TBitBltPage::SetupWindow()
{
  TPropertyPage::SetupWindow();
  SETUP_HELPCONTEXT(TBlazerApp, TBitBltPage);

  if (BlitterBlocks)
    Destructive->Check();
  else
    Sprite->Check();

  if (EnableSound)
    Sound->Check();
  else
    Sound->Uncheck();
}

//
// CleanupWindow().
//
void
TBitBltPage::CleanupWindow()
{
  EnableSound = Sound->GetCheck() == BF_CHECKED ? true : false;
  CLEANUP_HELPCONTEXT(TBlazerApp, TBitBltPage);
  TPropertyPage::CleanupWindow();
}

DEFINE_RESPONSE_TABLE1(TBitBltPage, TPropertyPage)
  EV_WM_HELP,
  EV_BN_CLICKED(IDC_DESTRUCTIVE, BnDestructiveClicked),
  EV_BN_CLICKED(IDC_SPRITE     , BnSpriteClicked),
END_RESPONSE_TABLE;

DEFINE_HELPCONTEXT(TBitBltPage)
  HCENTRY_CONTROL(IDH_DESTRUCTIVE, IDC_DESTRUCTIVE),
  HCENTRY_CONTROL(IDH_SPRITE,      IDC_SPRITE),
  HCENTRY_CONTROL(IDH_SOUND,       IDC_SOUND),
END_HELPCONTEXT;

//
//
//
void
TBitBltPage::BnDestructiveClicked()
{
  BlitterBlocks = true;
}

//
//
//
void
TBitBltPage::BnSpriteClicked()
{
  BlitterBlocks = false;
}

//
// Forward WM_HELP messages up to application.
//
void
TBitBltPage::EvHelp(HELPINFO* hi)
{
  ::Application->GetMainWindow()->SendMessage(WM_HELP, 0, TParam2(hi));
}


