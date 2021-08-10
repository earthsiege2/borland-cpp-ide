//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Filename:    gadgfact.cpp
//
// Date:        27-Sep-95
//
// Description:
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include "TBExpert.h"

int CountOfGadgetFactories = 0;
TGadgetFactory** GadgetFactories;

void
TGadgetFactory::Init(int id, TGadget::TBorderStyle border, const char* resId)
{
  Id = id;
  BorderStyle = border;
  if (resId)
    ResId = strnewdup(resId);
  else
    ResId = 0;
}

TGadgetFactory::TGadgetFactory(int id, TGadget::TBorderStyle border) // time gadget
:
  Type(Time)
{
  Init(id, border, 0);
}

TGadgetFactory::TGadgetFactory(int id, TGadget::TBorderStyle border, int data)
:
  Type(Separator)
{
  Init(id, border, 0);
  Width = data;
}

TGadgetFactory::TGadgetFactory(int id, TGadget::TBorderStyle border, int key, const char* text)
:
  Type(Mode),
  Key(key)
{
  Init(id, border, 0);
  GadgetText = strnewdup(text);
}

TGadgetFactory::TGadgetFactory(int id, TGadget::TBorderStyle border,
                               TTextGadget::TAlign align, uint chars,
                               const char* text)
:
  Type(Text),
  Align(align),
  NumChars(chars)
{
  Init(id, border, 0);
  GadgetText = strnewdup(text);
}

TGadgetFactory::TGadgetFactory(int id, TGadget::TBorderStyle border,
                               TButtonGadget::TType type,
                               TButtonGadget::TState state, const char* bmp)
:
  Type(Button),
  ButtonType(type),
  ButtonState(state)
{
  Init(id, border, 0);
  PathToBmp = strnewdup(bmp);
}

TGadgetFactory::~TGadgetFactory()
{
  delete[] ResId;
  if (Type == Text || Type == Mode)
    delete[] GadgetText;
  else if (Type == Button)
    delete[] PathToBmp;
}


TGadget*
TGadgetFactory::CreateGadget(int index)
{
  TGadget* gadget = 0;

  switch (Type) {
    case Separator: {
      gadget = new TSeparatorGadget(Width, DummyGadgetIdBase);
      break;
    }
    case Mode: {
      gadget = new TModeGadget(Key, GadgetText, DummyGadgetIdBase + index);
      break;
    }
    case Time: {
      gadget = new TTimeGadget(&TTimeGadget::GetTTime, DummyGadgetIdBase + index);
      break;
    }
    case Text: {
      gadget = new TTextGadget(DummyGadgetIdBase + index, BorderStyle, Align, NumChars, GadgetText);
      break;
    }
    case Button: {
      gadget = new TDynamicButtonGadget(PathToBmp, DummyGadgetIdBase + index,
                   ButtonType, false, ButtonState);
      break;
    }
  }

  if (gadget != 0)
    if (!(Type == Separator || Type == Button))
      gadget->SetBorderStyle(BorderStyle);

  return gadget;
}

void
TGadgetFactory::GenerateDefine(ofstream& f)
{
  if (ResId && strlen(ResId) > 0)
    f << "#define " << ResId << " " << Id << endl;
}

void
TGadgetFactory::GenerateProperId(ofstream& f)
{
  if (ResId && strlen(ResId) > 0) {
    f << ResId;
  }
  else {
    f << Id;
  }
}

static void
GenerateBorderStyle(TGadget::TBorderStyle bs, ofstream& f)
{
  struct {
    TGadget::TBorderStyle BorderStyle;
    char*                 Name;
  } mapping[] = {
    { TGadget::None, "TGadget::None" },
    { TGadget::Plain, "TGadget::Plain" },
    { TGadget::Raised, "TGadget::Raised" },
    { TGadget::Recessed, "TGadget::Recessed" },
    { TGadget::Embossed, "TGadget::Embossed" },
    { TGadget::Grooved, "TGadget::Grooved" },
    { TGadget::ButtonUp, "TGadget::ButtonUp" },
    { TGadget::ButtonDn, "TGadget::ButtonDn" },
    { TGadget::WndRaised, "TGadget::WndRaised" },
    { TGadget::WndRecessed, "TGadget::WndRecessed" },
    { TGadget::WellSet, "TGadget::WellSet" }
  };

  for (int i = 0; i < sizeof mapping/sizeof mapping[0]; i++) {
    if (mapping[i].BorderStyle == bs) {
      f << mapping[i].Name;
      return;
    }
  }
}

static void
GenerateAlign(TTextGadget::TAlign align, ofstream& f)
{
  struct {
    TTextGadget::TAlign Align;
    char*               Name;
  } mapping[] = {
    { TTextGadget::Left,   "TGadget::Left" },
    { TTextGadget::Center, "TGadget::Center" },
    { TTextGadget::Right,  "TGadget::Right" }
  };

  for (int i = 0; i < sizeof mapping/sizeof mapping[0]; i++) {
    if (mapping[i].Align == align) {
      f << mapping[i].Name;
      return;
    }
  }
}

void
TGadgetFactory::GenerateCode(ofstream& f)
{
  switch (Type) {
    case Separator: {
      f << "*new TSeparatorGadget(" << Width << ", ";
      GenerateProperId(f);
      f << ")";
      break;
    }
    case Mode: {
      f << "*new TModeGadget( 0x" << hex << Key << dec << ", " << '\"' << GadgetText << '\"' << ", ";
      GenerateProperId(f);
      f << ", ";
      GenerateBorderStyle(BorderStyle, f);
      f << ")";
      break;
    }
    case Time: {
      f << "*new TTimeGadget(&TTimeGadget::GetTTime, ";
      GenerateProperId(f);
      f << ")";
      break;
    }
    case Text: {
      f << "*new TTextGadget(";
      GenerateProperId(f);
      f << ", ";
      GenerateBorderStyle(BorderStyle, f);
      f << ", ";
      GenerateAlign(Align, f);
      f << ", " << NumChars << ", " << '\"' << GadgetText << '\"';
      f << ")";
      break;
    }
    case Button: {
      f << "*new TButtonGadget(";
      GenerateProperId(f);
      f << ", ";
      GenerateProperId(f);
      f << ")";
      break;
    }
  }
}


void
TGadgetFactory::SetId(int id)
{
  Id = id;
}

void
TGadgetFactory::SetBorderStyle(int style)
{
  struct {
    TGadget::TBorderStyle BorderStyle;
  } mapping[] = {
    { TGadget::None },
    { TGadget::Plain },
    { TGadget::Raised },
    { TGadget::Recessed },
    { TGadget::Embossed },
    { TGadget::Grooved },
    { TGadget::ButtonUp },
    { TGadget::ButtonDn },
    { TGadget::WndRaised },
    { TGadget::WndRecessed },
    { TGadget::WellSet }
  };

  BorderStyle = mapping[style].BorderStyle;
}

void
TGadgetFactory::SetResId(const char* resId)
{
  delete ResId;
  ResId = strnewdup(resId);
}

void
TGadgetFactory::SetAlign(int align)
{
  struct {
    TTextGadget::TAlign Align;
  } mapping[] = {
    { TTextGadget::Left },
    { TTextGadget::Center },
    { TTextGadget::Right }
  };

  Align = mapping[align].Align;
}

void
TGadgetFactory::SetNumChars(uint numChars)
{
  NumChars = numChars;
}

void
TGadgetFactory::SetGadgetText(const char* text)
{
  delete[] GadgetText;
  GadgetText = strnewdup(text);
}

void
TGadgetFactory::SetKey(int key)
{
  Key = key;
}

void
TGadgetFactory::SetButtonType(int type)
{
  struct {
    TButtonGadget::TType Type;
  } mapping[] = {
    { TButtonGadget::Command },
    { TButtonGadget::Exclusive },
    { TButtonGadget::NonExclusive },
    { TButtonGadget::SemiExclusive },
    { TButtonGadget::RepeatCmd }
  };

  ButtonType = mapping[type].Type;
}

void
TGadgetFactory::SetButtonState(int state)
{
  struct {
    TButtonGadget::TState State;
  } mapping[] = {
    { TButtonGadget::Up },
    { TButtonGadget::Down },
    { TButtonGadget::Indeterminate }
  };

  ButtonState = mapping[state].State;
}
