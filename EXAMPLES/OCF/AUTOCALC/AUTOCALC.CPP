//----------------------------------------------------------------------------
// ObjectComponents - (C) Copyright 1994, 1996 by Borland International
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#include <ocf/ocreg.h>
#include "autocalc.h"
#include "autocalc.hh"  // help constants (HC_???)

TLangId TLocaleString::NativeLangId=MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US);

  DEFINE_AUTOENUM(CalcOps, TAutoShort)
  AUTOENUM("!Add",      OP_PLUS)
  AUTOENUM("!Subtract", OP_MINUS)
  AUTOENUM("!Multiply", OP_MULT)
  AUTOENUM("!Divide",   OP_DIV)
  AUTOENUM("!Equals",   OP_EQUALS)
  AUTOENUM("!Clear",    OP_CLEAR)
  END_AUTOENUM(CalcOps, TAutoShort)

DEFINE_AUTOCLASS(TCalc)
  EXPOSE_PROPRW(Opnd,      TAutoLong,  "Operand",      "@Operand_", HC_TCALC_OPERAND)
  EXPOSE_PROPRW_ID(0,Accum,TAutoLong,  "!Accumulator", "@Accumulator_", HC_TCALC_ACCUMULATOR)
  EXPOSE_PROPRW(Op,        CalcOps,    "Op",           "@Op_", HC_TCALC_OPERATOR)
  EXPOSE_METHOD(Eval,      TAutoBool,  "!Evaluate",    "@Evaluate_", HC_TCALC_EVALUATE)
  EXPOSE_METHOD(Clear,     TAutoVoid,  "!Clear",       "@Clear_", HC_TCALC_CLEAR)
  EXPOSE_METHOD(Display,   TAutoVoid,  "!Display",     "@Display_", HC_TCALC_DISPLAY)
  EXPOSE_QUIT(                         "!Quit",        "@Quit_", HC_TCALC_QUIT)
  EXPOSE_METHOD(Button,    TAutoBool,  "!Button",      "@Button_", HC_TCALC_BUTTON)
	REQUIRED_ARG(           TAutoString,"!Key")
  EXPOSE_PROPRO(Window,    TCalcWindow,"!Window",      "@Window_", HC_TCALC_WINDOW)
  EXPOSE_METHOD(LookAt,    TAutoLong,  "!LookAtWindow","@LookAtWindow_", HC_TCALC_LOOKATWINDOW)
	REQUIRED_ARG(           TCalcWindow,"!Window")
  EXPOSE_PROPRO(MyArray,   TMyArray,   "!Array",       "@Array_", HC_TCALC_ARRAY)
  EXPOSE_PROPRW(Update,    TAutoDispatch, "!Update",   "@Update_", HC_TCALC_UPDATE)
  EXPOSE_PROPRW(Visible,   TAutoBool,  "!Visible",     "@Visible_", HC_TCALC_VISIBLE)
  EXPOSE_APPLICATION(      TCalc,      "!Application", "@Application_", HC_TCALC_APPLICATION)
END_AUTOCLASS(TCalc, tfAppObject|tfCanCreate, "TCalc", "@TCalc", HC_TCALC)

DEFINE_AUTOCLASS(TCalcWindow)
  EXPOSE_PROPRW(Caption,    TAutoString, "!Caption",    "@Caption_",HC_TCALCWINDOW_TITLE)
  EXPOSE_PROPRW(Background, TAutoLong,   "!Color",      "@Color_",  HC_TCALCWINDOW_BKGNDCOLOR)
  EXPOSE_PROPRW(Height,     TAutoLong,   "!Height",     "@Height_", HC_TCALCWINDOW_HEIGHT)
  EXPOSE_PROPRW(Width,      TAutoLong,   "!Width",      "@Width_",  HC_TCALCWINDOW_WIDTH)
  EXPOSE_PROPRO(Buttons,    TCalcButtons,"!Buttons",    "@Buttons_",HC_TCALCWINDOW_BUTTONS)
  EXPOSE_APPLICATION(       TCalc,       "!Application","@Application_", HC_TCALC_APPLICATION)
END_AUTOCLASS(TCalcWindow,  tfNormal,    "TCalcWindow", "@TCalcWindow", HC_TCALCWINDOW)

DEFINE_AUTOCLASS(TMyArray)
  EXPOSE_PROPRO(Count,      TAutoLong,  "!Count", "@CountAr_", HC_TMYARRAY_COUNT)
  EXPOSE_ITERATOR(          TAutoShort,           "Array Iterator", HC_TMYARRAY_ITERATOR)
  EXPOSE_METHOD_ID(0, Item, TAutoShort, "!Item",  "@ItemAr_", 0)
	REQUIRED_ARG(            TAutoShort, "!Index")
END_AUTOCLASS(TMyArray,     tfNormal,   "TCalcArray", "@TMyArray", HC_TMYARRAY)

DEFINE_AUTOCLASS(TCalcButtons)
  EXPOSE_PROPRO(Count,      TAutoLong,  "!Count",      "@CountBu_", HC_TCALCBUTTONS_COUNT)
  EXPOSE_ITERATOR(          TCalcButton,          "Button Iterator", HC_TCALCBUTTONS_ITERATOR)
  EXPOSE_METHOD_ID(0, Item, TCalcButton,"!Item",  "@ItemBu_", 0)
	REQUIRED_ARG(            TAutoShort, "!Index")
END_AUTOCLASS(TCalcButtons, tfNormal,   "TButtonList", "@TCalcButtons", HC_TCALCBUTTONS)

DEFINE_AUTOCLASS(TCalcButton)
  EXPOSE_PROPRW(Text,    TAutoString, "!Text",    "@Text_", HC_TCALCBUTTON_TEXT)
  EXPOSE_PROPRW(Push,    TAutoBool,   "!Activate","@Activate_", HC_TCALCBUTTON_STATE)
  EXPOSE_APPLICATION(    TCalc,       "!Application", "@Application_", HC_TCALC_APPLICATION)
END_AUTOCLASS(TCalcButton,tfNormal,   "TCalcButton", "@TCalcButton", HC_TCALCBUTTON)

DEFINE_AUTOEVENTCLASS(TCalcEvents)
  EXPOSE_PROPWO_ID(0, , TAutoLong, "Value", "Result update", 0)
END_AUTOEVENTCLASS(TCalcEvents,tfDefault,"TCalcEvents", "Calculator Events", 0)

void TUpdate::SetResult(long val)
{
  AUTONAMES0("Value")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

TCalc::TCalc(HINSTANCE hInst, uint32 options) : Options(options)
{
  Window.hWnd = ::CreateDialog(hInst, MAKEINTRESOURCE(IDD_CALC), 0, 0);
  ::SetWindowLong(Window, DLGWINDOWEXTRA, (long)this);
  ::ShowWindow(Window, SW_SHOW);
  Clear();
  Display();
  for (int i = 0; i < COUNT; i++)
    Elem[i] = short((i+1)*10);
}

void TCalc::Clear()
{
  Op = OP_CLEAR;
  Eval();
}

bool TCalc::Eval()
{
  switch(Op) {
  case OP_PLUS:   Accum += Opnd; break;
  case OP_MINUS:  Accum -= Opnd; break;
  case OP_MULT:   Accum *= Opnd; break;
  case OP_DIV:    if (!Opnd) return false; Accum /= Opnd; break;
  case OP_EQUALS: Accum = Opnd;  break;
  case OP_CLEAR:  Accum = 0;     break;
  case OP_NONE:   break;
  default:        return false;
  }
  Op = OP_EQUALS; // in case clear or if Eval called again with no op
  Opnd = 0;
  Entry = false;
  if (Update.IsBound())
    Update.SetResult(Accum);
  return true;
}

void TCalc::Display()
{
  long val = Entry ? Opnd : Accum;
  char buf[20];
  wsprintf(buf, "%ld", val);
  SetDlgItemText(Window, IDC_DISPLAY, buf);
}

bool TCalc::Button(const char far* txt)
{
  short ret = true;
  const char* list = BUTTON_CHARS;
  while (*txt) {
	 const char far* s = strchr(list, *txt++);
	 if (s)
		ButtonPush(int(s-list) + IDC_FIRSTID);
	 else
		ret = false;
  }
  return ret;
}

int TCalc::ButtonPush(int button)  // internal call, not automated
{
  if(button >= IDC_FIRSTDIGIT && button <= IDC_LASTDIGIT) {
	 Opnd  = (Opnd * 10) + long(button - IDC_FIRSTDIGIT);
	 Entry = true;
  } else if(button >= IDC_FIRSTOP && button <= IDC_LASTOP) {
	 if (button == IDC_CLEAR) {
		Clear();
	 } else {
		if (Entry)
		  Eval();
		Op = short(button-IDC_FIRSTOP);
	 }
  }else{
	 return 0; // unknown button
  }
  Display();
  return 1;
}

bool TCalc::GetVisible()
{
  return (bool)Window && ::IsWindowVisible(Window);
}

void TCalc::SetVisible(bool show)
{
  ::ShowWindow(Window, show);
}

void TCalcWindow::SetCaption(const char far* text)
{
  ::SetWindowText(hWnd, text);
}

const char* TCalcWindow::GetCaption()
{
  static char buf[256];
  return ::GetWindowText(hWnd, buf, sizeof(buf)-1) ? buf : 0;
}

int TCalcWindow::GetWidth()
{
  RECT rect;
  ::GetWindowRect(hWnd, &rect);
  return rect.right - rect.left;
}

void TCalcWindow::SetWidth(int width)
{
  RECT rect;
  ::GetWindowRect(hWnd, &rect);
  ::MoveWindow(hWnd, rect.left, rect.top, width, rect.bottom-rect.top, TRUE);
}

int TCalcWindow::GetHeight()
{
  RECT rect;
  ::GetWindowRect(hWnd, &rect);
  return rect.bottom - rect.top;
}

void TCalcWindow::SetHeight(int height)
{
  RECT rect;
  ::GetWindowRect(hWnd, &rect);
  ::MoveWindow(hWnd, rect.left, rect.top, rect.right-rect.left, height,TRUE);
}

void TCalcWindow::SetBackground(long color)
{
  Background = color;
  ::InvalidateRect(hWnd, 0, TRUE);
}
