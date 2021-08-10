//----------------------------------------------------------------------------
// ObjectComponents - (C) Copyright 1994, 1996 by Borland International
//----------------------------------------------------------------------------
#include <ocf/automacr.h>
#include "autocalc.rh"

class TUpdate : public TAutoProxy {
  public:
    TUpdate() : TAutoProxy(0x409) {}
    void SetResult(long);
};

class TCalcButton : public TAutoBase {
  public:
    TCalcButton(HWND hWnd) : HWnd(hWnd) {}
    HWND HWnd;
    bool GetPush() {return (::SendMessage(HWnd, BM_GETSTATE, 0, 0) & 4) != 0;}
    void SetPush(bool state) {::SendMessage(HWnd, BM_SETSTATE, state, 0);}
    void  SetText(char* text) {::SetWindowText(HWnd, text);}
    char* GetText(){static char b[21]; return ::GetWindowText(HWnd,b,20)? b:0;}

  DECLARE_AUTOCLASS(TCalcButton)
    AUTOPROP  (Push, GetPush, SetPush, bool,)
    AUTOPROP  (Text, GetText, SetText, TAutoString,)
};

class TCalcWindow;

class TCalcButtons {    // class used only to temporarily expose collection
  public:
    TCalcButtons(HWND window) : HWnd(window) {}
    short GetCount() { return IDC_LASTID - IDC_FIRSTID; }
    HWND GetButton(short i) {return ::GetDlgItem(HWnd, i + IDC_FIRSTID+1);}
    HWND HWnd;

  DECLARE_AUTOCLASS(TCalcButtons)
    AUTOFUNC0 (Count, GetCount, short,)
    AUTOFUNC1 (Item,  GetButton, TAutoObjectByVal<TCalcButton>, short,
                          AUTOVALIDATE(Arg1 >= 0 && Arg1 < This->GetCount()) )
    AUTOITERATOR(int Id, Id = IDC_FIRSTID+1, Id <= IDC_LASTID, Id++,
                 TAutoObjectByVal<TCalcButton>(::GetDlgItem(This->HWnd,Id)))
};

class TCalcWindow : public TAutoBase {
  public:
    TCalcWindow() : hWnd(0), Background(0) {}
   ~TCalcWindow() { if (hWnd) ::DestroyWindow(hWnd); }
    operator bool() {return hWnd != 0;}
    operator HWND() {return hWnd;}

    void  SetCaption(const char far* text);
    const char* GetCaption();
    int GetWidth();
    void SetWidth(int);
    int GetHeight();
    void SetHeight(int);
    unsigned long GetBackground() { return Background; }
    void SetBackground(long color);

    long Background;
    HWND  hWnd;

  DECLARE_AUTOCLASS(TCalcWindow)
    AUTOPROP  (Caption,    GetCaption,SetCaption, TAutoString,)
    AUTOPROP  (Height,     GetHeight,SetHeight,   int,)
    AUTOPROP  (Width,      GetWidth,SetWidth,     int,)
    AUTOPROP  (Background, GetBackground,SetBackground, unsigned long,)
    AUTODATARO(Buttons,    hWnd,   TAutoObjectByVal<TCalcButtons>,)
};

enum operators {
  OP_NONE = 0,
  OP_PLUS,
  OP_MINUS,
  OP_MULT,
  OP_DIV,
  OP_EQUALS,
  OP_CLEAR,
};

#define COUNT 10

class TMyArray {    // class used only to temporarily expose collection
  public:
    TMyArray(short* array) : Array(array) {}
    short* Array;
    long GetCount() {return COUNT;}
    short GetItem(short index) {return Array[index];}

  DECLARE_AUTOCLASS(TMyArray)
    AUTOFUNC0 (Count, GetCount, long,)
    AUTOFUNC1 (Item,  GetItem,  short, short,AUTOVALIDATE(Arg1>=0 && Arg1<COUNT))
    AUTOITERATOR(int Index, Index=0, Index<COUNT, Index++, (This->Array)[Index])
};

class TCalc : public TAutoBase {
  public:
    TCalc(HINSTANCE hInst, uint32 options);
    void Closed() {Window.hWnd = 0;}

    // automated methods and properties
    bool  GetVisible();
    void  SetVisible(bool show);
    bool  Eval();
    void  Clear();
    void  Display();
    bool  Button(const char far* button);
    TCalcWindow& GetWindow() { return Window; }
    long  LookAtWindow(const TCalcWindow& wnd) {return wnd.Background;}

    int ButtonPush(int button);  // not exposed via automation
    uint32 Options;

  private:
    TUpdate Update;  // callback to controller
    TCalcWindow Window;
    bool  Entry;

    // automated data members
    short Op;
    long  Opnd;
    long  Accum;
    short Elem[COUNT];

  DECLARE_AUTOCLASS(TCalc)
    AUTODATA  (Accum,   Accum,     long,  )
    AUTODATA  (Opnd,    Opnd,      long,  )
    AUTODATA  (Op,      Op, short, AUTOVALIDATE(Val>=OP_NONE && Val<=OP_CLEAR))
    AUTOFUNC0 (Eval,    Eval,      bool, )
    AUTOFUNC0V(Clear,   Clear,            )
    AUTOFUNC0V(Display, Display,          )
    AUTOFUNC1 (Button,  Button,    bool, TAutoString,)
    AUTOPROPRO(Window,  GetWindow, TAutoObject<TCalcWindow>,  )
    AUTOFUNC1 (LookAt,  LookAtWindow, long, TAutoObject<const TCalcWindow>,)
    AUTODATARO(MyArray, Elem,      TAutoObjectByVal<TMyArray>,)
    AUTOPROXY (Update,  Update, )
    AUTOPROP  (Visible, GetVisible, SetVisible, bool,)
};
