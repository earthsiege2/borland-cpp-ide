//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\dialog.h>
#include <owl\dc.h>
#include <stdio.h>
#include "tscrnsav.h"
#include "owlscrn.h"

//#define USE_BWCC

#if defined(USE_BWCC)
  #define IDD_CONFIGURE "IDD_CONFIGURE_BWCC"
#else
  #define IDD_CONFIGURE "IDD_CONFIGURE"
#endif

const char OwlScrnSectionStr[] = "OwlScreenSaver";
const char ObjectsStr[] = "Objects";
const char SpeedStr[] = "Speed";
char  AppName[]  = "ScreenSaver.OWLSample";
const int NumThings = 900;
const int MaxBuilders = 8;

class TScreenThing {
  public:
    TScreenThing(TSize& scrnSize);
    
    virtual void Draw(TDC& dc) = 0;

  protected:
    const TPoint& Position() {return Pos;}
    const TColor& Color() {return C;}

  private:
    TPoint  Pos;
    TColor  C;
};

typedef TScreenThing* (*TScreenThingBuilder)(TSize&);

TScreenThing::TScreenThing(TSize& scrnSize)
{
  Pos.x = random(scrnSize.cx + 1);
  Pos.y = random(scrnSize.cy + 1);
  C = TColor(random(0x100), random(0x100), random(0x100));
}


class TDot : public TScreenThing {
  public:
    TDot(TSize& scrnSize) : TScreenThing(scrnSize) {}
    
    virtual void Draw(TDC& dc);

    static TScreenThing* Build(TSize& scrnSize) {return new TDot(scrnSize);}
};

void
TDot::Draw(TDC& dc)
{
  dc.SetPixel(Position(), Color());
}

class TLine : public TScreenThing  {
  public:
    TLine(TSize& scrnSize) : TScreenThing(scrnSize) {
      End.x = random(scrnSize.cx + 1);
      End.y = random(scrnSize.cy + 1);
    }
    
    virtual void Draw(TDC& dc);

    static TScreenThing* Build(TSize& scrnSize) {return new TLine(scrnSize);}
    
  private:
    TPoint  End;
};

void
TLine::Draw(TDC& dc)
{
  dc.SelectObject(TPen(Color()));
  dc.MoveTo(Position());
  dc.LineTo(End);
  dc.RestorePen();
}

class TBlob : public TScreenThing  {
  public:
    TBlob(TSize& scrnSize) : TScreenThing(scrnSize) {
      Rad.cx = random(scrnSize.cx/20);
      Rad.cy = random(scrnSize.cy/20);
    }
    
    virtual void Draw(TDC& dc);
    static TScreenThing* Build(TSize& scrnSize) {return new TBlob(scrnSize);}
    
  private:
    TSize  Rad;
};

void
TBlob::Draw(TDC& dc)
{
  dc.SelectObject(TBrush(Color()));
  dc.Ellipse(Position().x-Rad.cx, Position().y-Rad.cy, 
             Position().x+Rad.cx, Position().y+Rad.cy);
  dc.RestoreBrush();
}

//----------------------------------------------------------------------------

class TMyScrnSavWindow : public TScrnSavWindow {
  public:
    TMyScrnSavWindow(TWindow* parent, const char* title, TModule* = 0);

  protected:
    char far* GetClassName() {return(AppName);}
    void  GetWindowClass(WNDCLASS& wndClass);

    virtual void  AnimateScreen();

  private:
    TScreenThing*  Thing[NumThings];
    TScreenThingBuilder Builder[MaxBuilders];
    TSize          ScreenSize;
    int            DrawIndex, EraseIndex;
    int            NumBuilders;
    BOOL           DoDots;
    BOOL           DoLines;
    BOOL           DoBlobs;
};

TMyScrnSavWindow::TMyScrnSavWindow(TWindow* parent, const char* title,
                                   TModule* module)
  : TWindow(parent, title, module),
    TScrnSavWindow(parent, title, module)
{
  DrawIndex  = 0;
  EraseIndex = -2*(NumThings/3);
  ScreenSize.cx = GetSystemMetrics(SM_CXSCREEN);
  ScreenSize.cy = GetSystemMetrics(SM_CYSCREEN);

  char settings[32];

  GetProfileString(OwlScrnSectionStr, ObjectsStr, "1 0 0", settings, sizeof(settings));
  sscanf(settings, "%d %d %d", &DoDots, &DoLines, &DoBlobs);
  
  NumBuilders = 0;
  if (DoDots)
    Builder[NumBuilders++] = TDot::Build;
  if (DoLines)
    Builder[NumBuilders++] = TLine::Build;
  if (DoBlobs)
    Builder[NumBuilders++] = TBlob::Build;

  int speed;
  GetProfileString(OwlScrnSectionStr, SpeedStr, "2", settings, sizeof(settings));
  sscanf(settings, "%d", &speed);
  
  ((TScrnSavApp*)GetApplication())->SetSpeed(speed);
}

void
TMyScrnSavWindow::GetWindowClass(WNDCLASS& wndClass)
{
  TScrnSavWindow::GetWindowClass(wndClass);
  wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
}

void
TMyScrnSavWindow::AnimateScreen()
{
  if (!DoDots && !DoLines && !DoBlobs)
    return;

  TClientDC  dc(*this);
  if (dc) {
    dc.SetROP2(R2_XORPEN);

    Thing[DrawIndex] = Builder[random(NumBuilders)](ScreenSize);
    Thing[DrawIndex]->Draw(dc);

    DrawIndex++;
    DrawIndex %= NumThings;

    if (EraseIndex >= 0) {
      Thing[EraseIndex]->Draw(dc);
      delete Thing[EraseIndex];
      EraseIndex++;
      EraseIndex %= NumThings;

    } else
      EraseIndex++;
  }
}

//----------------------------------------------------------------------------

class TScrnSavDlg : public TDialog {
  public:
    TScrnSavDlg(TWindow* parent, const char* name, TModule* module)
      : TDialog(parent, name, module) {}
      
    void SetupWindow();
    void CloseWindow(int retValue);
   
  DECLARE_RESPONSE_TABLE(TScrnSavDlg);
};

DEFINE_RESPONSE_TABLE1(TScrnSavDlg, TDialog)
  EV_COMMAND(IDCANCEL, CmCancel),
END_RESPONSE_TABLE;

void
TScrnSavDlg::SetupWindow()
{
  char settings[32];
  
  int doDots, doLines, doBlobs;
  ::GetProfileString(OwlScrnSectionStr, ObjectsStr, "1 0 0", 
                     settings, sizeof(settings));
  sscanf(settings, "%d %d %d", &doDots, &doLines, &doBlobs);
  CheckDlgButton(ID_DOTS, doDots);
  CheckDlgButton(ID_LINES, doLines);
  CheckDlgButton(ID_BLOBS, doBlobs);

  int speed;
  ::GetProfileString(OwlScrnSectionStr, SpeedStr, "2", 
                     settings, sizeof(settings));
  sscanf(settings, "%d", &speed);
  CheckRadioButton(ID_SLOW, ID_FAST, ID_SLOW+speed);
}

void
TScrnSavDlg::CloseWindow(int retValue)
{
  char settings[32];

  wsprintf(settings, "%d %d %d", IsDlgButtonChecked(ID_DOTS), 
                                 IsDlgButtonChecked(ID_LINES), 
                                 IsDlgButtonChecked(ID_BLOBS));
  WriteProfileString(OwlScrnSectionStr, ObjectsStr, settings);
  
  wsprintf(settings, "%d", IsDlgButtonChecked(ID_SLOW) ? 0 : 
                           (IsDlgButtonChecked(ID_MED) ? 1 : 2));
  WriteProfileString(OwlScrnSectionStr, SpeedStr, settings);

  TDialog::CloseWindow(retValue);
}

//----------------------------------------------------------------------------

class TMyScrnSavApp : public TScrnSavApp {
  public:
    TMyScrnSavApp(char far* name) : TScrnSavApp(name) {
      #if defined(USE_BWCC)
        EnableBWCC();
      #endif
    }

    // Override TScrnSavApp's virtual functions
    //
    void  InitScrnSavWindow();
    void  InitConfigDialog();
};

void
TMyScrnSavApp::InitScrnSavWindow()
{
  ScrnSavWnd = new TMyScrnSavWindow(0, AppName);
}

void
TMyScrnSavApp::InitConfigDialog()
{
  ConfigureDialog = new TScrnSavDlg(0, IDD_CONFIGURE, this);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TMyScrnSavApp(AppName).Run();
}
