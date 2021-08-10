//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\statusba.cpp
//   Defines class TStatusBar.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\statusba.h>
#include <owl\statusba.rc>

static char   DefModes[] = "EXT|CAPS|NUM|SCRL|OVR|REC";
static char*  ModeBuff;
static char** ModeStrings;
static int    NumModes = 0;

//
// Gets the mode string array from a single resource string, like:
//   "EXT|CAPS|NUM|SCRL|OVR|REC"
//
static void
GetModes(HINSTANCE hInstance)
{
  if (!ModeStrings) {
    string modeResString(hInstance, IDS_MODES);
    ModeBuff = strnewdup(modeResString.length() > 0 ?
                         modeResString.c_str() :
                         DefModes);
    NumModes = 1;
    for (char* p = ModeBuff; *p; p++)
      if (*p == '|') {
        *p = 0;
        NumModes++;
      }

    typedef char* pchar;
    ModeStrings = new pchar[NumModes];
    p = ModeBuff;
    for (int i = 0; i < NumModes; i++) {
      ModeStrings[i] = p;
      p += strlen(p) + 1;
    }
  }
}

IMPLEMENT_CASTABLE(TStatusBar);

TStatusBar::TStatusBar(TWindow*              parent,
                       TGadget::TBorderStyle borderStyle,
                       UINT                  modeIndicators,
                       TFont*                font,
                       TModule*              module)
  : TMessageBar(parent, font, module)
{
  BorderStyle = borderStyle;
  ModeIndicators = modeIndicators;
  ModeIndicatorState = 0;
  NumModeIndicators = 0;
  ::GetModes(*GetModule());

  if (BorderStyle == TGadget::Plain || BorderStyle == TGadget::Embossed)
    HighlightLine = FALSE;

  else
    Spacing.Value = 2;  // 1/4 em quad

  switch (BorderStyle) {
    case TGadget::Raised:
    case TGadget::Recessed:
      //
      // we want one border height along the top and bottom and 1/2 an em quad
      // along the left and right so we will set pixels and compute the lengths
      // ourselves
      //
      Margins.Units = TMargins::Pixels;
      Margins.Left = Margins.Right = LayoutUnitsToPixels(4);
      Margins.Top = Margins.Bottom = GetSystemMetrics(SM_CYBORDER);
      break;

    case TGadget::Plain:
      Margins.Units = TMargins::BorderUnits;
      Margins.Left = Margins.Top = Margins.Right = Margins.Bottom = -1;
      break;
  }

  Gadgets->SetBorderStyle(BorderStyle); // Set border style for first gadget

  //
  // create text gadgets for any mode indicators the user requested
  //
  TScreenDC   dc;

  dc.SelectObject(*Font);

  for (int i = 0; i < NumModes; i++)
    if (ModeIndicators & (1 << i)) {
      const int    SMALL_MARGIN = 1;
      TSize        extent;
      int          left, top, right, bottom;
      TTextGadget* gadget = new TTextGadget(0, BorderStyle,
                                            TTextGadget::Left,
                                            strlen(ModeStrings[i]));
      TMargins     margins = gadget->GetMargins();

      //
      // use small left and right margins
      //
      margins.Left = margins.Right = SMALL_MARGIN;
      gadget->SetMargins(margins);

      //
      // turn off shrink wrapping for the width and choose a width that is
      // custom fit for the string
      //
      dc.GetTextExtent(ModeStrings[i], strlen(ModeStrings[i]), extent);
      gadget->SetShrinkWrap(FALSE, TRUE);
      TMessageBar::Insert(*gadget);
      gadget->GetOuterSizes(left, right, top, bottom);
      extent.cx += left + right;
      gadget->SetSize(extent);

      NumModeIndicators++;
    }
}

BOOL
TStatusBar::IsModeIndicator(TGadget* gadget)
{
  int      nonModeIndicators = NumGadgets - NumModeIndicators;
  TGadget* g = Gadgets;

  for (int i = 0; i < nonModeIndicators; i++) {
    if (gadget == g)
      return FALSE;

    g = g->NextGadget();
  }

  return TRUE;
}

//
//
//
void
TStatusBar::PositionGadget(TGadget*, TGadget* next, TPoint& origin)
{
  int  cxBorder = GetSystemMetrics(SM_CXBORDER);

  if (BorderStyle == TGadget::Plain)
    origin.x -= cxBorder;  // overlap the borders

  //
  // leave extra spacing between the mode indicators
  //
  if (IsModeIndicator(next))
    switch (Spacing.Units) {
      case TMargins::Pixels:
        origin.x += Spacing.Value;
        break;

      case TMargins::LayoutUnits:
        origin.x += LayoutUnitsToPixels(Spacing.Value);
        break;

      case TMargins::BorderUnits:
        origin.x += Spacing.Value * cxBorder;
        break;
    }
}

//
// insert a gadget. default placement is just after the gadget to the left of
// the status mode indicators
//
void
TStatusBar::Insert(TGadget& gadget, TPlacement placement, TGadget* sibling)
{
  gadget.SetBorderStyle(BorderStyle);
  if (!sibling)
    sibling = operator[](NumGadgets - NumModeIndicators - 1);
  TMessageBar::Insert(gadget, placement, sibling);
}

//
// return gadget at a given index, except mode indicator gadgets
//
TGadget*
TStatusBar::operator [](UINT index)
{
  PRECONDITION(index < NumGadgets - NumModeIndicators);

  for (TGadget* g = Gadgets; index > 0; index--)
    g = g->NextGadget();

  return g;
}

//
// Get the text gadget & the mode string associated with a mode indicator 
//
BOOL
TStatusBar::GetGadgetAndString(TModeIndicator mode, TTextGadget*& gadget, char*& str)
{
  if ((ModeIndicators & mode) == 0) {
    return FALSE;  // tracing

  } else {
    UINT  slot = NumGadgets - 1;

    for (int index = NumModes - 1; (1 << index) > mode; index--)
      if (ModeIndicators & (1 << index))
        slot--;

    str = ModeStrings[index];

    for (gadget = (TTextGadget*)Gadgets; slot > 0; slot--)
      gadget = (TTextGadget*)gadget->NextGadget();

    return TRUE;
  }
}

void
TStatusBar::ToggleModeIndicator(TModeIndicator mode)
{
  SetModeIndicator(mode, !GetModeIndicator(mode));
}

void
TStatusBar::SetModeIndicator(TModeIndicator mode, BOOL on)
{
  TTextGadget*  gadget;
  char*         str;

  if (GetGadgetAndString(mode, gadget, str))
    gadget->SetText(on ? str : 0);
  
  if (on)
    ModeIndicatorState |= mode;
  else
    ModeIndicatorState &= ~mode;
}

BOOL
TStatusBar::PreProcessMsg(MSG& msg)
{
  if (msg.message == WM_KEYDOWN) {  

    switch (msg.wParam) {
      case VK_SCROLL:
        
        if (ModeIndicators & ScrollLock) {
          //ScrollLockModeChange();
          ToggleModeIndicator(ScrollLock);
        }
        break;

      case VK_INSERT:
        if (ModeIndicators & Overtype) {
          //OvertypeModeChange();
          ToggleModeIndicator(Overtype);
        }
        break;

      case VK_CAPITAL:
        if (ModeIndicators & CapsLock)
          ToggleModeIndicator(CapsLock);
        break;

      case VK_NUMLOCK:
        if (ModeIndicators & NumLock)
          ToggleModeIndicator(NumLock);
        break;
    }
  }
  
  return FALSE;
}

//
//  Make sure that we are in sync with the physical KB indicators
//
BOOL
TStatusBar::IdleAction(long idleCount)
{
  if (idleCount == 0) {
    if ((::GetKeyState(VK_SCROLL) & 0x0001) != GetModeIndicator(ScrollLock))
      ToggleModeIndicator(ScrollLock);
    if ((::GetKeyState(VK_INSERT) & 0x0001) != !GetModeIndicator(Overtype))
      ToggleModeIndicator(Overtype);
    if ((::GetKeyState(VK_CAPITAL) & 0x0001) != GetModeIndicator(CapsLock))
      ToggleModeIndicator(CapsLock);
    if ((::GetKeyState(VK_NUMLOCK) & 0x0001) != GetModeIndicator(NumLock))
      ToggleModeIndicator(NumLock);
  }
  return TMessageBar::IdleAction(idleCount);
}
