//----------------------------------------------------------------------------
// ObjectComponents - (C) Copyright 1994, 1996 by Borland International
// OLE Automation Controller example
//----------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#pragma hdrstop
#include "autocalc.cxx"
#include "callcalc.rh"

const GUID _cdecl FAR IID_CalcApplication =
      {0x877B6200L,0x7627,0x101B,{0xB8,0x7C,0x00,0x00,0xC0,0x57,0xCE,0x4E}};

const GUID _cdecl FAR IID_CalcDebug =
      {0x877B6201L,0x7627,0x101B,{0xB8,0x7C,0x00,0x00,0xC0,0x57,0xCE,0x4E}};

const GUID _cdecl FAR IID_CalcDllServer =
      {0x877B6280L,0x7627,0x101B,{0xB8,0x7C,0x00,0x00,0xC0,0x57,0xCE,0x4E}};

#define ExeProgId   "OCCalc.Application"
#define DllProgId   "OCCalc.DllServer"
#define DebugProgId "OCCalc.Debug"

class TOutputDialog {
  public:
    TOutputDialog(HINSTANCE hInst, int resId);
   ~TOutputDialog() {::DestroyWindow(Window);}
    void Display(int id, const char far* text);
    void Display(int id, long val);
    void Press(int id, bool state);
    void Show(int id, bool state);
    void Pump();
    void Hold();
    int  Wait();
    operator HWND() {return Window;}
  private:
    void ReportResult(long value);
    void Dispatch(MSG& msg);
    HINSTANCE Instance;
    HWND Window;

  DECLARE_AUTOCLASS(TOutputDialog)
    AUTOPROPWO(ReportResult, ReportResult, long, )
};
DEFINE_AUTOCLASS(TOutputDialog)
 EXPOSE_PROPWO_ID(0, ReportResult, TAutoLong, "Value", "Result update", 0)
END_AUTOCLASS(TOutputDialog, tfNormal,"TOutputDialog", "Callback object", 0)

void TOutputDialog::ReportResult(long value)
{
  Display(IDC_ACCUM, value);
}

#define WM_USERSTAT (WM_USER + 100)

bool CALLBACK __export
DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM /*lParam*/)
{
  if (msg == WM_INITDIALOG) {
    return 1;
  } else if (msg == WM_COMMAND && wParam >= IDOK && wParam <= IDNO) {
    ::PostMessage(hDlg, WM_USERSTAT, wParam, 0);
    return 1;
  } else if (msg == WM_CLOSE) {
    ::PostMessage(hDlg, WM_USERSTAT, IDABORT, 0);
    return 1;
  }
  return 0;
}

TOutputDialog::TOutputDialog(HINSTANCE hInst, int resId)
{
  Window = ::CreateDialog(hInst, MAKEINTRESOURCE(resId), 0, (DLGPROC)DlgProc);
  Pump();
}

void TOutputDialog::Dispatch(MSG& msg)
{
  if (::IsDialogMessage(Window, &msg))
    return;
  ::TranslateMessage(&msg);
  ::DispatchMessage(&msg);
}

void TOutputDialog::Pump()
{
  MSG msg;
  while (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
    Dispatch(msg);
}

void TOutputDialog::Hold()
{
  MSG msg;
  while (!::GetFocus()
#if 0
    || ::GetWindowTask(::GetFocus())!=::GetCurrentTask())
#endif
    )
    if (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
      Dispatch(msg);
}

int TOutputDialog::Wait()
{
  MSG msg;
  int stat = 0;
  while ( !stat && ::GetMessage(&msg, 0, 0, 0)) {
    if (msg.message == WM_USERSTAT)
      stat = msg.wParam;
    else
      Dispatch(msg);
  }
  return stat;
}

void TOutputDialog::Display(int id, const char far* text)
{
  ::SetDlgItemText(Window, id, text);
}

void TOutputDialog::Display(int id, long val)
{
  char buf[20];
  wsprintf(buf, "%ld", val);
  Display(id, buf);
}

void TOutputDialog::Press(int id, bool state)
{
  ::SendDlgItemMessage(Window, id, BM_SETSTATE, state, 0);
}

void TOutputDialog::Show(int id, bool state)
{
  ::ShowWindow(::GetDlgItem(Window, id), state ? SW_SHOWNOACTIVATE : SW_HIDE);
  Pump();
}

//____________________________________________________________________________

const char* passName[] = {"GUID: AUTOCALC.EXE",      "ProgID: " ExeProgId,
                          "GUID: ACALDIPS.DLL",      "ProgID: " DllProgId,
                          "GUID: AUTOCALC.EXE-DEBUG","ProgID: " DebugProgId};

int PASCAL
WinMain(HINSTANCE hInst, HINSTANCE/*prev*/, char far* cmdLine, int/*show*/)
{
  char buf[100];
  try {
    short i;
    TOutputDialog out(hInst, 1);
    TOleAllocator oleMem(0);   // required to initialize OLE memory allocation
    if (!cmdLine || !cmdLine[0])
      cmdLine = "1234";
    char far* passList = cmdLine;
    char pass;
    while ((pass = *passList++)!=0) {

      // Initialize display dialog
      //
      if (pass < '1' || pass > '6')
        continue;
      out.Show(IDC_EXIT,   false);
      out.Show(IDC_REPEAT, false);
      for (int b = IDC_FIRSTBUTTON; b <= IDC_LASTBUTTON; b++)
        out.Show(b, false);
      for (int t = IDC_FIRSTTEXT; t <= IDC_LASTTEXT; t++)
        out.Display(t, "");
      out.Display(IDC_PASS, passName[pass-'1']);

      // Bind to server, do some arithmetic on the caclculator
      //
      TCalc calc;
      switch (pass) {
        case '1': calc.Bind(IID_CalcApplication); break;
        case '2': calc.Bind(ExeProgId);           break;
        case '3': calc.Bind(IID_CalcDllServer);   break;
        case '4': calc.Bind(DllProgId);           break;
        case '5': calc.Bind(IID_CalcDebug);       break;
        case '6': calc.Bind(DebugProgId);         break;
      }
      calc.SetUpdate(*new TDispatch(TAutoObject<TOutputDialog>(out)));
      calc.SetOperand(pass-'0');
      calc.SetOp("Add");
      calc.Evaluate();
      calc.SetOperand(1111);
      calc.Button("*");
      calc.Evaluate(); // callback will display in IDC_ACCUM
      calc.Display();

      // Iteratate over integer array collection
      //
      TCalcArray calcArray;
      calc.GetArray(calcArray);
      TAutoEnumerator<short> array;
      calcArray.Enumerate(array);
      char* bp = buf;
      while (array.Step()) {
        array.Value(i);
        bp += wsprintf(bp, "%i ", i);
      }
      out.Display(IDC_ARRAY, buf);

      // Access calculator window, read and write caption
      //
      TCalcWindow window;
      calc.GetWindow(window);
      wsprintf(buf, "Pass %c of CALLCALC", pass);
      window.SetCaption(buf);
      out.Display(IDC_CAPTION, window.GetCaption());
      window.SetColor(RGB(0,255,0));

      // Iterate over button collection, pushing and releasing buttons
      //
      TButtonList buttons;
      window.GetButtons(buttons);
      TAutoEnumerator<TCalcButton> list;
      buttons.Enumerate(list);
      TCalcButton button;
      for (i = IDC_FIRSTBUTTON; list.Step(); i++) {
        list.Object(button);
        button.SetActivate(true);
        out.Display(i, button.GetText());
        out.Press(i, true);
        out.Show(i, true);
      }
      window.SetColor(RGB(255,0,0));
      for (int bi = (int)buttons.GetCount(); --bi >= 0; ) {
        buttons.Item(button, (short)bi);
        button.SetActivate(false);
        out.Press(IDC_FIRSTBUTTON + bi, false);
        out.Display(IDC_FIRSTBUTTON + bi, button.GetText());
      }

      // Terminate calculator, wait for user response if end of run
      //
      out.Pump();
      if (*passList == 0) {
        out.Show(IDC_EXIT,   true);
        out.Show(IDC_REPEAT, true);
        if (out.Wait() == IDC_REPEAT)
          passList = cmdLine;
      }
      calc.Quit();
    }
    ::CoFreeUnusedLibraries();
  }
  catch (TXBase& x) {
    ::MessageBox(0, x.why().c_str(), "OLE Exception", MB_OK);
  }
  return 0;
}
