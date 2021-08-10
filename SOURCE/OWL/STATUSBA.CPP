//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TStatusBar
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/statusba.h>
#include <owl/statusba.rh>

//
// Local class to manage the mode indicator strings
//
class TModeStrings {
  public:
    // constructor
    TModeStrings() : ModeBuff(0), ModeStrings(0), NumModes(0) {}
   ~TModeStrings()
    {
      delete [] ModeBuff;
      delete [] ModeStrings;
    }

    void Init(TModule* module, uint16 resId, const char* defaultModes);
   
    // access
    int          Count() const            { return NumModes; }
    const char*  operator [](int i) const { return ModeStrings[i]; }

  private:
    int    NumModes;
    char*  ModeBuff;
    char** ModeStrings;
};

//
// Gets the mode string array from a single resource string, like:
//   "EXT|CAPS|NUM|SCRL|OVR|REC"
// using the provided default string if resource not found.
//
void
TModeStrings::Init(TModule* module, uint16 resId, const char* defaultModes)
{
  if (!ModeStrings) {
    string modeResString(module->LoadString(resId));
    ModeBuff = strnewdup(modeResString.length() > 0 ?
                         modeResString.c_str() :
                         defaultModes);
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

//
// Static mode string object, & default mode indicator strings
//
static TModeStrings ModeOnStrings;
static TModeStrings ModeOffStrings;
static char         DefOnModes[] =  "EXT|CAPS|NUM|SCRL|OVR|REC";
static char         DefOffModes[] = "   |    |   |    |   |   ";

IMPLEMENT_CASTABLE(TStatusBar);

TStatusBar::TStatusBar(TWindow*              parent,
                       TGadget::TBorderStyle borderStyle,
                       uint                  modeIndicators,
                       TFont*                font,
                       TModule*              module)
:
  TMessageBar(parent, font, module)
{
  BorderStyle = borderStyle;
  ModeIndicators = modeIndicators;
  ModeIndicatorState = 0;
  NumModeIndicators = 0;
  ModeOnStrings.Init(GetModule(), IDS_MODES, DefOnModes);
  ModeOffStrings.Init(GetModule(), IDS_MODESOFF, DefOffModes);

  if (BorderStyle == TGadget::Plain || BorderStyle == TGadget::Embossed)
    HighlightLine = false;

  else
    Spacing.Value = 2;  // Hilight line + 1/4-em margin on raised & recessed

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
  // create text gadgets for any mode indicators the user requested,
  // using provided border style.
  //
  TScreenDC   dc;

  dc.SelectObject(*Font);

  for (int i = 0; i < ModeOnStrings.Count(); i++)
    if (ModeIndicators & (1 << i)) {
      const int    SMALL_MARGIN = 1;
      int          maxLen = max(strlen(ModeOnStrings[i]), strlen(ModeOffStrings[i]));
      TTextGadget* gadget = new TTextGadget(0, BorderStyle,
                                            TTextGadget::Left, maxLen,
                                            ModeOffStrings[i]);
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
      gadget->SetShrinkWrap(false, true);
      TMessageBar::Insert(*gadget);

      TSize        onExtent;
      dc.GetTextExtent(ModeOnStrings[i], strlen(ModeOnStrings[i]), onExtent);
      TSize        offExtent;
      dc.GetTextExtent(ModeOffStrings[i], strlen(ModeOffStrings[i]), offExtent);
      TSize extent(max(onExtent.cx, offExtent.cx), onExtent.cy);

      int          left, top, right, bottom;
      gadget->GetOuterSizes(left, right, top, bottom);

      extent.cx += left + right;
      gadget->SetSize(extent);

      NumModeIndicators++;
    }
}

bool
TStatusBar::IsModeIndicator(TGadget* gadget)
{
  int      nonModeIndicators = NumGadgets - NumModeIndicators;
  TGadget* g = Gadgets;

  for (int i = 0; i < nonModeIndicators; i++) {
    if (gadget == g)
      return false;

    g = g->NextGadget();
  }

  return true;
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
TStatusBar::operator [](uint index)
{
  PRECONDITION(index < NumGadgets - NumModeIndicators);

  for (TGadget* g = Gadgets; index > 0; index--)
    g = g->NextGadget();

  return g;
}

//
// Get the text gadget & the mode string associated with a mode indicator
//
bool
TStatusBar::GetGadgetAndStrings(TModeIndicator mode, TTextGadget*& gadget,
                                const char*& strOn, const char*& strOff)
{
  if ((ModeIndicators & mode) == 0) {
    return false;  // tracing
  }
  else {
    uint  slot = NumGadgets - 1;

    for (int index = ModeOnStrings.Count() - 1; (1 << index) > mode; index--)
      if (ModeIndicators & (1 << index))
        slot--;

    strOn  = ModeOnStrings[index];
    strOff = ModeOffStrings[index];

    for (gadget = (TTextGadget*)Gadgets; slot > 0; slot--)
      gadget = (TTextGadget*)gadget->NextGadget();

    return true;
  }
}

void
TStatusBar::ToggleModeIndicator(TModeIndicator mode)
{
  SetModeIndicator(mode, !GetModeIndicator(mode));
}

void
TStatusBar::SetModeIndicator(TModeIndicator mode, bool on)
{
  TTextGadget*  gadget;
  const char*   strOn;
  const char*   strOff;

  if (GetGadgetAndStrings(mode, gadget, strOn, strOff))
    gadget->SetText(on ? strOn : strOff);

  if (on)
    ModeIndicatorState |= mode;
  else
    ModeIndicatorState &= ~mode;
}

bool
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
          //
          // Skip if CTRL+INS or SHIFT+INS
          //
          if (((::GetKeyState(VK_CONTROL) & 0x8000) == 0) &&
              ((::GetKeyState(VK_SHIFT)   & 0x8000) == 0))
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

  return false;
}

//
//  Make sure that we are in sync with the physical KB indicators
//
bool
TStatusBar::IdleAction(long idleCount)
{
  if (idleCount == 0) {
    if ((::GetKeyState(VK_SCROLL) & 0x0001) != GetModeIndicator(ScrollLock))
      ToggleModeIndicator(ScrollLock);
    if ((::GetKeyState(VK_CAPITAL) & 0x0001) != GetModeIndicator(CapsLock))
      ToggleModeIndicator(CapsLock);
    if ((::GetKeyState(VK_NUMLOCK) & 0x0001) != GetModeIndicator(NumLock))
      ToggleModeIndicator(NumLock);
  }
  return TMessageBar::IdleAction(idleCount);
}
