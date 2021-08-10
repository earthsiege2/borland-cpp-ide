//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\dialog.h>
#include <owl\framewin.h>
#include <owl\vbxctl.h>
#include "vbxctlx.h"

//#define USE_RESOURCE_DLL

class TTestDialog : public TDialog, public TVbxEventHandler {
  public:
    TTestDialog(TWindow* parent, const char* name, TModule* module=0);

  protected:
    void SetupWindow();

    // OWL Aliases for VBX controls in dialog
    //
    TVbxControl* Switch1;
    TVbxControl* Switch2;
    TVbxControl* Switch3;
    TVbxControl* Switch4;
    TVbxControl* Gauge1;
    TVbxControl* Gauge2;
    TVbxControl* Gauge3;
    TVbxControl* Gauge4;

    void EvTimer(UINT timerId);
    void EvDropSrc(VBXEVENT far* event);
    void EvDropDest(VBXEVENT far* event);
    void UpdateGauge(TVbxControl* sw, TVbxControl* ga);

  DECLARE_RESPONSE_TABLE(TTestDialog);
};

DEFINE_RESPONSE_TABLE2(TTestDialog, TDialog, TVbxEventHandler)
  EV_WM_TIMER,
  EV_VBXEVENTNAME(IDC_BIPICT1,"DragDrop",EvDropSrc),
  EV_VBXEVENTNAME(IDC_BIPICT2,"DragDrop",EvDropSrc),
  EV_VBXEVENTNAME(IDC_BIPICT3,"DragDrop",EvDropDest),
END_RESPONSE_TABLE;

TTestDialog::TTestDialog(TWindow* parent, const char* name, TModule* module)
  : TDialog(parent, name, module)
{
  Switch1 = new TVbxControl(this, IDC_BISWITCH1);
  Switch2 = new TVbxControl(this, IDC_BISWITCH2);
  Switch3 = new TVbxControl(this, IDC_BISWITCH3);
  Switch4 = new TVbxControl(this, IDC_BISWITCH4);
  Gauge1  = new TVbxControl(this, IDC_BIGAUGE1);
  Gauge2  = new TVbxControl(this, IDC_BIGAUGE2);
  Gauge3  = new TVbxControl(this, IDC_BIGAUGE3);
  Gauge4  = new TVbxControl(this, IDC_BIGAUGE4);
}

void
TTestDialog::SetupWindow()
{
  TDialog::SetupWindow();
  SetTimer(1, 1);  // As fast as possible
}

void
TTestDialog::EvTimer(UINT /*timerId*/)
{
  UpdateGauge(Switch1, Gauge1);
  UpdateGauge(Switch2, Gauge2);
  UpdateGauge(Switch3, Gauge3);
  UpdateGauge(Switch4, Gauge4);
}

void
TTestDialog::UpdateGauge(TVbxControl *sw, TVbxControl* ga)
{
  BOOL on=FALSE;
  int val=0;
  if( sw->GetProp("On", on) && on )
    if( ga->GetProp("Value", val) )
      ga->SetProp("Value",  (val + 5)  % 100);
}

void
TTestDialog::EvDropSrc(VBXEVENT far * /*event*/)
{
  MessageBeep(0);
}

void
TTestDialog::EvDropDest(VBXEVENT far * event)
{
  long pic;
  if (VBXGetPropByName(VBX_EVENTARGNUM(event,HCTL,0), "Picture", &pic))
    VBXSetPropByName(event->Control, "Picture", pic);
}

//----------------------------------------------------------------------------

class TTestApp : public TApplication {
  public:
    TTestApp() : TApplication() {}
   ~TTestApp() {delete ResModule;}

  protected:
    void InitMainWindow() {
      MainWindow = new TFrameWindow(0, "Dialog Tester", 0);
      MainWindow->AssignMenu("COMMANDS");
#if defined(USE_RESOURCE_DLL)
      ResModule = new TModule("resource.dll");
# if 1
      VBXEnableDLL(*this, *ResModule);
# else
      WNDCLASS wc;
      GetClassInfo("VBCONTROL", &wc);
      wc.hInstance = *ResModule;
      RegisterClass(&wc);
# endif
#else
      ResModule = 0;
#endif
    }
    void CmTest() {TTestDialog(MainWindow, "SAMPLES", ResModule).Execute();}

  private:
    TModule* ResModule;

  DECLARE_RESPONSE_TABLE(TTestApp);
};

DEFINE_RESPONSE_TABLE(TTestApp)
  EV_COMMAND(CM_TEST, CmTest),
END_RESPONSE_TABLE;

int
OwlMain(int, char**)
{
  try {
    TBIVbxLibrary vbxLib;     // constructing this loads & inits the library
    return TTestApp().Run();
  }
  catch (xmsg& x) {
    ::MessageBox(0, x.why().c_str(), "OWL Examples", MB_OK);
    return -1;
  }
}
