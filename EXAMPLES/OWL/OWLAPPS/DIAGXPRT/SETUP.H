//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------

#include  <owl\scrollba.h>
#include  <owl\button.h>
#include  <owl\listbox.h>
#include  <owl\checkbox.h>
#include  <owl\radiobut.h>
#include  <owl\edit.h>
#include  <owl\static.h>
#include  <classlib\arrays.h>

class TDiagEnable;
class TSizableDialog;
class TSetupDialog;

class TSetupItem;
class TSysItem;
class TUsrItem;

class TBaseSetupWindow;
class TSysWindow;
class TUsrWindow;

class TGroup;
class TSysGroup;
class TUsrGroup;
class TGroupScroll;

#define SYS_INI "owl.ini"
#define SYS_CLS "Diagnostics"
#define SYS_DSC "Diagnostics Descriptions"
#define USR_INI "owl.ini"
#define USR_CLS "Diagnostics"
#define USR_DSC "Users Diagnostics Descriptions"


class TDiagEnable : public TCheckBox {
  public:
    TDiagEnable(TWindow* parent, int id, TWindow* w0, TWindow* w1)
      : W0(w0), W1(w1), S0(0), S1(0), TCheckBox(parent, id) {}
    TDiagEnable(TWindow* parent, int id, TGroup* s0, TGroup* s1)
      : W0(0), W1(0), S0(s0), S1(s1), TCheckBox(parent, id) {}
    void  BNClicked();
    BOOL  EnableWindow(BOOL enable);

  protected:
    TGroup*  S0;
    TGroup*  S1;
    TWindow* W0;
    TWindow* W1;

  DECLARE_RESPONSE_TABLE(TDiagEnable);
};


class TUsrEnable : public TDiagEnable {
  public:
    TUsrEnable(TWindow *w, int nID, TWindow *w0, TWindow *w1, TWindow *B) :
      Ntf(B), TDiagEnable(w, nID, w0, w1) {}

    void  EvSetFocus(HWND h) {
      if (Ntf && !Ntf->IsWindowEnabled()) Ntf->EnableWindow(TRUE);
      TDiagEnable::EvSetFocus(h);
    }
    void  EvKillFocus(HWND h) {
      if (Ntf && Ntf->IsWindowEnabled()) Ntf->EnableWindow(FALSE);
      TDiagEnable::EvKillFocus(h);
    }

  private:
    TWindow* Ntf;

    DECLARE_RESPONSE_TABLE(TUsrEnable);
};


class TMainEnable : public TDiagEnable {
  public:
    TMainEnable(TWindow* parent, int id, TGroup* g0, TGroup* g1);
    void Load();
    void Save();

  private:
    static char* Class;
};

class TSetupItem {
  public:
    TSetupItem(char *Class, char *Descr);
    virtual ~TSetupItem() { delete Enable; }

    virtual char*  GetIniFile() = 0;
    virtual char*  GetSection() = 0;
    virtual char*  GetSectionDesc() = 0;
    const char*    GetDescr() { return Descr.c_str(); }
    const char*    GetClass() { return Class.c_str(); }
    void           SetClass(char* c) { Class = c; }
    void           SetDescr(char* d) { Descr = d; }
    virtual void operator =(TBaseSetupWindow& w);
    virtual void   Load();
    virtual void   Save();
    BOOL           GetEnable() { return bEnable; }
    int            GetLevel()  { return level; }
    void           SetEnable(BOOL bS) { bEnable = bS; }
    void           SetLevel(int n) { level = n; }

  protected:
    TDiagEnable*   Enable;
    string         Class, Descr;

  private:
    BOOL    bEnable;
    int     level;
};

class TSysItem : public TSetupItem {
  public:
    TSysItem(char* Class, char* Descr = 0) : TSetupItem(Class, Descr) {}
    virtual char*  GetIniFile() { return SYS_INI; }
    virtual char*  GetSection() { return SYS_CLS; }
    virtual char*  GetSectionDesc() { return SYS_DSC; }
};

class TUsrItem : public TSetupItem {
  public:
    TUsrItem(char* Class, char* Descr = 0) : TSetupItem(Class, Descr) {}
    virtual char*  GetIniFile() { return USR_INI; }
    virtual char*  GetSection() { return USR_CLS; }
    virtual char*  GetSectionDesc() { return USR_DSC; }
};

class TBaseSetupWindow {
  public:
    TBaseSetupWindow() : Enable(0) {}
    virtual BOOL  GetEnable() { CHECK(Enable!=0); return Enable->GetCheck(); }
    virtual void  SetEnable(BOOL bE) { CHECK(Enable!=0); Enable->SetCheck(bE); }
    virtual void  EnableWindow(BOOL bE) = 0;
    virtual int   GetLevel() = 0;
    virtual void  SetLevel(int level) = 0;
    virtual void  operator = (TSetupItem &it) = 0;
    virtual void  operator = (int) = 0;
  protected:
    TDiagEnable* Enable;
};

template <class C1,class C2>
class TSetupWindow : public TBaseSetupWindow {
  public:
    virtual int   GetLevel() = 0;
    virtual void  SetLevel(int level) = 0;
  
    virtual void  EnableWindow(BOOL e) {
              Enable->EnableWindow(e);
              if (e) e = Enable->GetCheck();
              Child1->EnableWindow(e);
              Child2->EnableWindow(e);
            }
    virtual void operator = (TSetupItem &it) {
              SetEnable(it.GetEnable());
              SetLevel(it.GetLevel());
              Enable->SetWindowText(it.GetDescr());
              Enable->ShowWindow(SW_SHOW);
              Child1->ShowWindow(SW_SHOW);
              Child2->ShowWindow(SW_SHOW);
            }
    virtual void  operator = (int) {
              Enable->ShowWindow(SW_HIDE);
              Child1->ShowWindow(SW_HIDE);
              Child2->ShowWindow(SW_HIDE);
            }

  protected:
    C1* Child1;
    C2* Child2;
};

class TSysWindow : public TSetupWindow<TRadioButton,TRadioButton> {
  public:
    TSysWindow(TWindow* w, int i) {
              Child1 = new TRadioButton(w, i + 1, 0);
              Child1->Create();
              Child2 = new TRadioButton(w, i + 2, 0);
              Child2->Create();
              Enable = new TDiagEnable(w, i, Child1, Child2);
              Enable->Create();
            }
    virtual int   GetLevel() { return Child1->GetCheck() ? 1 : 0; }
    virtual void  SetLevel(int level) {
              if (level)
                Child1->SetCheck(1);
              else
                Child2->SetCheck(1);
            }
};

class TUsrWindow : public TSetupWindow<TStatic, TEdit> {
  public:
    TUsrWindow(TWindow* w, int i) {
      Child1 = new TStatic(w, i + 1, 20); Child1->Create();
      Child2 = new TEdit(w, i + 2); Child2->Create();
      Enable = new TDiagEnable(w, i, Child1, Child2); Enable->Create();
    }
    virtual int GetLevel() {
      char b[6];
      Child2->GetWindowText(b, sizeof(b));
      return atoi(b);
    }
    virtual void  SetLevel(int level) {
      char b[6];
      wsprintf(b, "%d", level);
      Child2->SetWindowText(b);
    }
};

class TItemsArray : public TArrayAsVector<TSetupItem *> {
  public:
    TItemsArray() : TArrayAsVector<TSetupItem *>(10, 0, 4) {}
};

class TWindowArray : public TArrayAsVector<TBaseSetupWindow *> {
  public:
    TWindowArray() : TArrayAsVector<TBaseSetupWindow *>(10, 0, 4) {}
};

class TGroup {
  public:
    enum { MapToTop = 0, MapToBottom = 0x7fff, MapAsBefore = 0x7ffe };

    TWindowArray Windows;
    TItemsArray Items;

    virtual void  SetMainSwitch(TCheckBox* c) { Switch = c; }
    virtual BOOL  IsEnable() { return Switch ? Switch->GetCheck() : 1; }
    virtual void  EnableWindow(BOOL enable);
    virtual void  Load();
    virtual void  Save();
    virtual void  Cleanup() = 0;
    virtual int   Map(int x);
    virtual int   UnMap();
    virtual ~TGroup() { Windows.Flush(); Items.Flush(); }

  private:
    int        scrollPos;
    TCheckBox* Switch;
};

class TSysGroup : public TGroup {
  public:
    TSysGroup(TWindow* dialog, int firstID);
    void  Cleanup();
};

class TUsrGroup : public TGroup {
  public:
    TUsrGroup(TWindow* dialog, int firstID);
    void  Cleanup();
};

class TSizableDialog : public TDialog {
  public:
    TSizableDialog(TWindow* parent, int dlgID, int boxID) : nBoxID(boxID),
                   TDialog(parent, dlgID) {}
    enum { t_minmax, t_min, t_max };
    virtual void  Toggle(int type = t_minmax);
    BOOL    IsMaximized() { return bMaximized; }

  protected:
    virtual void  SetupWindow();
    virtual void  EnableControls();
    void  Center();
    void  AdjustPos();

  private:
    int   nBoxID;
    TSize small;
    TSize large;
    BOOL  bMaximized;
    int   tSize;
};

class TSetupDialog : public TSizableDialog {
  public:
    TSetupDialog(TWindow* p):TSizableDialog(p, DG_OPTIONS, ID_BOX) {}
    void  SetupWindow();
    void  CleanupWindow();
    void  UpdateButtons();
    void  CmOk();
    void  CmAddUsr();
    void  CmDelUsr();
    void  CmEdtUsr();
    void  CmZoom();

  private:
    TSysGroup*    SysGroup;
    TUsrGroup*    UsrGroup;
    TMainEnable*  MainEnable;
    TGroupScroll* SysScroll;
    TGroupScroll* UsrScroll;
    TButton*      pDel;
    TButton*      pEdt;

  DECLARE_RESPONSE_TABLE(TSetupDialog);
};

class TGroupScroll : public TScrollBar {
  public:
    TGroupScroll(TWindow *W, int id, TGroup *group);
    void  Initialize(int pos);
    void  EvVScroll(UINT code, UINT pos, HWND hCtl);
    void  SetPosition(int pos);
    void  EndScroll();

  private:
    int     x;
    int     min;
    int     max;
    TGroup* group;

  DECLARE_RESPONSE_TABLE(TGroupScroll);
};

//
//  class TAddUsrDialog
//
class TAddUsrDialog : public TDialog {
  public:
    char Class[80], Descr[80];
    TAddUsrDialog(TWindow* p): TDialog(p, DG_ADD_CUSTOM) {}
    void CmOk();

  DECLARE_RESPONSE_TABLE(TAddUsrDialog);
};

//
//  class TItemsDialog
//
class TItemsDialog : public TDialog {
  public:
    TItemsDialog(TWindow* p, int id, TItemsArray* it): items(it), TDialog(p, id) {}
    ~TItemsDialog();

    virtual BOOL  IsValid() { return TRUE; }
    virtual void  SetupWindow();
    virtual void  CmOk() { if (IsValid()) TDialog::CmOk(); }
    virtual void  LBDblClk() {}
    virtual void  LBSelChange() {}

    TItemsArray* items;
    int          nSel;

  protected:
    TListBox*  pList;

  DECLARE_RESPONSE_TABLE(TItemsDialog);
};

//
//  class TDelUsrDialog
//
class TDelUsrDialog : public TItemsDialog {
  public:
    TDelUsrDialog(TWindow* p, TItemsArray* it): TItemsDialog(p, DG_DEL_CUSTOM, it) {}
    virtual void  CmOk();
    virtual void  LBDblClk() { CmOk(); }
};

//
//  class TEdtUsrDialog
//
class TEdtUsrDialog : public TItemsDialog {
  public:
    TEdtUsrDialog(TWindow* p, TItemsArray* it)
        : nPrevSel(LB_ERR), TItemsDialog(p, DG_EDT_CUSTOM, it) {}
    virtual void  LBSelChange();
    virtual void  CmOk();

  private:
    int   nPrevSel;
    static  char*  Template;

  DECLARE_RESPONSE_TABLE(TEdtUsrDialog);
};
