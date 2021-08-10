//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//
//
// This example demonstrates the use of MCI APIs in Windows 3.1 in an OWL
// application:
//
// You must have a sound board/Speaker and its device driver installed under
// Windows 3.1 and be certain that it works -- Use the sound applet in Windows
// Control Pannel to generate a sound.  You may copy one of the .WAV files
// from the WINDOWS subdirectory in your system to this example's
// subdirectory.
//
// Run the .EXE. Choose File:Open and select a .WAV file. Choose Control:Play
// to play the waveform. The Control menu lets you stop/play/pause and resume.
// The scrollbar allows random access through the waveform while it is
// playing.
// This example demonstrates the use of the MCI API and a callback via
// WM_MCINOTIFY.
//
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\opensave.h>
#include <owl\framewin.h>
#include <owl\dc.h>
#include <owl\menu.h>
#include <owl\button.h>
#include <owl\slider.h>
#include <owl\slider.rh>
#include <math.h>
#include <mmsystem.h>
#include "mcisound.h"

#define ID_SCROLL    150         // Scroll bar
#define TIMER_ID     264         // Unique timer ID.
#define MCI_PARM2(p) ((long)(void far*)&p)

UINT  DeviceId = 0;              // The global waveform device opened handle
BOOL  FlushNotify = FALSE;

//----------------------------------------------------------------------------

class TSoundBar : public THSlider {
  public:
    TSoundBar(TWindow* parent, int id, int x, int y, int w, int h, 
              TModule* module = 0)
         : THSlider(parent, id, x, y, w, h, IDB_HSLIDERTHUMB, module) {}

    void    SetInfo(int ratio, long length);
    void    SetName(char* name);

    //
    // Override TScrollBars virtual functions
    //
    void    SBLineUp();
    void    SBLineDown();
    void    SBPageUp();
    void    SBPageDown();
    void    SBThumbPosition(int thumbPos);
    void    SBTop();
    void    SBBottom();

  private:
    int     WaveRatio;
    long    WaveLength;
    char    ElementName[255];

    void    ReposAndPlay(long newPos);
};


void
TSoundBar::ReposAndPlay(long newPos)
{
  MCI_PLAY_PARMS    MciPlayParm;
  MCI_SEEK_PARMS    MciSeekParm;
  MCI_SET_PARMS     MciSetParm;
  MCI_OPEN_PARMS    MciOpenParm;
  MCI_GENERIC_PARMS MciGenParm;

  // Only allow SEEK if playing.
  //
  if (!DeviceId)
     return;

  // Close the currently playing wave.
  //
  FlushNotify = TRUE;
  MciGenParm.dwCallback = 0;
  mciSendCommand(DeviceId, MCI_STOP, MCI_WAIT, MCI_PARM2(MciGenParm));
  mciSendCommand(DeviceId, MCI_CLOSE, MCI_WAIT, MCI_PARM2(MciGenParm));

  // Open the wave again and seek to new position.
  //
  MciOpenParm.dwCallback = 0;
  MciOpenParm.wDeviceID = DeviceId;
  #if !defined(__WIN32__)
    MciOpenParm.wReserved0 = 0;
  #endif
  MciOpenParm.lpstrDeviceType = 0;
  MciOpenParm.lpstrElementName = ElementName;
  MciOpenParm.lpstrAlias = 0;

  if (mciSendCommand(DeviceId, MCI_OPEN, MCI_WAIT| MCI_OPEN_ELEMENT, MCI_PARM2(MciOpenParm))) {
        MessageBox("Open Error", "Sound Play", MB_OK);
        return;
     }
  DeviceId = MciOpenParm.wDeviceID;

  // Our time scale is in SAMPLES.
  //
  MciSetParm.dwTimeFormat = MCI_FORMAT_SAMPLES;
  if (mciSendCommand(DeviceId, MCI_SET, MCI_SET_TIME_FORMAT, MCI_PARM2(MciSetParm))) {
     MessageBox("Set Time Error", "Sound Play", MB_OK);
     return;
  }

  // Compute new position, remember the scrollbar range has been scaled based
  // on WaveRatio.
  //
  MciSeekParm.dwCallback = 0;
  MciSeekParm.dwTo = (newPos*WaveRatio > WaveLength) ? WaveLength :
                                                       newPos*WaveRatio;
  if (mciSendCommand(DeviceId, MCI_SEEK, MCI_TO, MCI_PARM2(MciSeekParm))) {
    MessageBox("Seek Error", "Sound Play", MB_OK);
    return;
  }

  MciPlayParm.dwCallback = (long)HWindow;
  MciPlayParm.dwFrom = 0;
  MciPlayParm.dwTo = 0;
  if (mciSendCommand(DeviceId, MCI_PLAY, MCI_NOTIFY, MCI_PARM2(MciPlayParm))) {
    MessageBox("Play Error", "Sound Play", MB_OK);
    return;
  }
}

void
TSoundBar::SetInfo(int ratio, long length)
{
  WaveRatio = ratio;
  WaveLength = length;
}

void
TSoundBar::SetName(char* name)
{
  strcpy(ElementName, name);
}

void
TSoundBar::SBLineUp()
{
  THSlider::SBLineUp();
  ReposAndPlay(GetPosition());
}

void
TSoundBar::SBLineDown()
{
  THSlider::SBLineDown();
  ReposAndPlay(GetPosition());
}

void
TSoundBar::SBPageUp()
{
  THSlider::SBPageUp();
  ReposAndPlay(GetPosition());
}

void
TSoundBar::SBPageDown()
{
  THSlider::SBPageDown();
  ReposAndPlay(GetPosition());
}

void
TSoundBar::SBThumbPosition(int thumbPos)
{
  THSlider::SBThumbPosition(thumbPos);
  ReposAndPlay(GetPosition());
}

void
TSoundBar::SBTop()
{
  THSlider::SBTop();
  ReposAndPlay(GetPosition());
}

void
TSoundBar::SBBottom()
{
  THSlider::SBBottom();
  ReposAndPlay(GetPosition());
}


//----------------------------------------------------------------------------

class TSoundWindow : public TFrameWindow {
  public:
    TSoundWindow(TWindow* parent, const char far* title);
    ~TSoundWindow();

    void        SetupWindow();

    LRESULT     MciNotify(WPARAM, LPARAM);
    void        EvPaint();
    void        CmFileOpen();
    void        CmFileExit();
    void        CmPlayWave();
    void        CmStopWave();
    void        CmHelpAbout();
    void        EvTimer(UINT id);

  private:
    char        ElementName[255];
    int         Running;
    int         Pause;
    UINT        TimeGoing;
    int         WaveRatio;
    long        WaveLength;
    TSoundBar*  SoundBar;

    MCI_GENERIC_PARMS MciGenParm;
    MCI_OPEN_PARMS    MciOpenParm;
    MCI_PLAY_PARMS    MciPlayParm;
    MCI_STATUS_PARMS  MciStatusParm;
    MCI_SET_PARMS     MciSetParm;

    void        GetDeviceInfo();
    void        StopWave();
    void        StopMCI();

  DECLARE_RESPONSE_TABLE(TSoundWindow);
};

DEFINE_RESPONSE_TABLE1(TSoundWindow, TFrameWindow)
  EV_MESSAGE(MM_MCINOTIFY, MciNotify),
  EV_WM_PAINT,
  EV_COMMAND(SM_OPEN, CmFileOpen),
  EV_COMMAND(SM_EXIT, CmFileExit),
  EV_COMMAND(SM_PLAY, CmPlayWave),
  EV_COMMAND(SM_STOP, CmStopWave),
  EV_COMMAND(SM_ABOUT, CmHelpAbout),
  EV_WM_TIMER,
END_RESPONSE_TABLE;


TSoundWindow::TSoundWindow(TWindow* parent, const char far* title)
  : TFrameWindow(parent, title)
{
  AssignMenu(ID_MENU);
  Attr.AccelTable = IDA_SOUNDPLY;
  Attr.X = 50;
  Attr.Y = 100;
  Attr.W = 400;
  Attr.H = 220;

  Running = 0;
  Pause = 0;
  WaveLength = WaveRatio = 0;
  ElementName[0] = 0;

  SoundBar = new TSoundBar(this, ID_SCROLL, 50, 67, 300, 40);
  
  new TButton(this, SM_PLAY, "&Play", 50, 120, 50, 20, TRUE);
  new TButton(this, SM_STOP, "&Stop", 120, 120, 50, 20, TRUE);
}

void
TSoundWindow::SetupWindow()
{
  TFrameWindow::SetupWindow();
  SoundBar->SetRange(0, 0);
  SoundBar->SetRuler(0);
}

TSoundWindow::~TSoundWindow()
{
  StopMCI();
}

//
// EvPaint member function responds to WM_PAINT messages
//
void
TSoundWindow::EvPaint()
{
  TPaintDC paintDC(HWindow);

  // File name.
  //
  if (strlen(ElementName))
     paintDC.TextOut(5, 5, ElementName, strlen(ElementName));
  else
     paintDC.TextOut(5, 5, "<No WAVEFORM file loaded>", 25);

  paintDC.TextOut(160, 35, "Samples:", 8);
  paintDC.TextOut(50, 48, "0", 1);     // Beginning value.

  // Ending number of samples.
  //
  char buffer[10];
  if (WaveLength)
    wsprintf(buffer, "%ld", WaveLength);
  else
    strcpy(buffer, "Unknown");
  paintDC.TextOut(315, 48, buffer, strlen(buffer));
}

void
TSoundWindow::GetDeviceInfo()
{
  WAVEOUTCAPS waveOutCaps;

  if (!waveOutGetDevCaps(DeviceId, &waveOutCaps, sizeof(waveOutCaps))) {
    MessageBox("GetDevCaps Error", "Sound Play", MB_OK);
    return;
  }
}

//
// Play the wave...
//
void
TSoundWindow::CmPlayWave()
{
  if (!Running) {
    //
    // MCI APIs to open a device and play a .WAV file, using
    // notification to close
    //
    memset(&MciOpenParm, 0, sizeof MciOpenParm);

    MciOpenParm.lpstrElementName = ElementName;

    if (mciSendCommand(0, MCI_OPEN, MCI_WAIT | MCI_OPEN_ELEMENT, 
                       MCI_PARM2(MciOpenParm))) {
      MessageBox(
         "Open Error - a waveForm output device is necessary to use this demo.",
         "Sound Play", MB_OK);
        return;
    }
    DeviceId = MciOpenParm.wDeviceID;

    // The time format in this demo is in Samples.
    //
    MciSetParm.dwCallback = 0;
    MciSetParm.dwTimeFormat = MCI_FORMAT_SAMPLES;
    if (mciSendCommand(DeviceId, MCI_SET, MCI_SET_TIME_FORMAT, MCI_PARM2(MciSetParm))) {
      MessageBox("SetTime Error", "Sound Play", MB_OK);
      return;
    }

    MciPlayParm.dwCallback = (long)HWindow;
    MciPlayParm.dwFrom = 0;
    MciPlayParm.dwTo = 0;
    mciSendCommand(DeviceId, MCI_PLAY, MCI_NOTIFY, MCI_PARM2(MciPlayParm));

    // Modify the menu to toggle PLAY to STOP, and enable PAUSE.
    //
    TMenu menu(HWindow);
    menu.ModifyMenu(SM_PLAY, MF_STRING, SM_PLAY, "P&ause\tCtrl+A");
    menu.EnableMenuItem(SM_STOP, MF_ENABLED);

    // Make sure the Play/Stop toggle menu knows we're Running.
    //
    Running = TRUE;

    // Start a timer to show our progress through the waveform file.
    //
    TimeGoing = SetTimer(TIMER_ID, 200, 0);

    // Give enough information to the scrollbar to monitor the
    // progress and issue a re-MCI_OPEN.
    //
    SoundBar->SetName(ElementName);

  } else {
    if (!Pause) {
      // Pause the playing.
      //
      MciGenParm.dwCallback = 0;
      mciSendCommand(DeviceId, MCI_PAUSE, MCI_WAIT, MCI_PARM2(MciGenParm));

      // Toggle Pause menu to Resume.
      //
      TMenu menu(HWindow);
      menu.ModifyMenu(SM_PLAY, MF_STRING, SM_PLAY, "&Play\tCtrl+P");
      Pause = TRUE;

    } else {
      // Resume the playing.
      //
      MciGenParm.dwCallback = 0;
      mciSendCommand(DeviceId, MCI_RESUME, MCI_WAIT, MCI_PARM2(MciGenParm));

      // Toggle Resume menu to Pause.
      //
      TMenu menu(HWindow);
      menu.ModifyMenu(SM_PLAY, MF_STRING, SM_PLAY, "P&ause\tCtrl+A");
      Pause = FALSE;
    }
  }
}

void
TSoundWindow::CmStopWave()
{
  StopWave();
}

void
TSoundWindow::StopMCI()
{
  if (TimeGoing)       // if Timer is Running, then kill it now.
    TimeGoing = !KillTimer(TIMER_ID);

  // Stop playing the waveform file and close the waveform device.
  //
  MciGenParm.dwCallback = 0;
  mciSendCommand(DeviceId, MCI_STOP, MCI_WAIT, MCI_PARM2(MciGenParm));
  mciSendCommand(DeviceId, MCI_CLOSE, MCI_WAIT,MCI_PARM2(MciGenParm));

  Running = FALSE;
  DeviceId = 0;
}

//
// Reset the menus to Play menu and gray the Pause menu.
//
void
TSoundWindow::StopWave()
{
  if (DeviceId) {
    StopMCI();
    TMenu menu(HWindow);
    menu.ModifyMenu(SM_PLAY, MF_STRING, SM_PLAY, "&Play\tCtrl+P");
  }
}

void
TSoundWindow::CmFileOpen()
{
  static TOpenSaveDialog::TData data (
    OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,
    "Wave Files (*.WAV)|*.wav|",
    0,
    0,
    "WAV"
  );
  if (TFileOpenDialog(this, data).Execute() == IDOK) {
    if (CanClose()) {
      strcpy(ElementName, data.FileName);  // Remember the wave file to open.

      // Turn the Play menu on.
      TMenu(HWindow).EnableMenuItem(SM_PLAY, MF_ENABLED);

      WaveLength = 0;
      WaveRatio = 0;
      SoundBar->SetPosition(0);
      Invalidate();
    }
  }
}

void
TSoundWindow::CmFileExit()
{
  CloseWindow();
}

//
// Response function MM_MCINOTIFY message when MCI_PLAY is complete.
//
LRESULT
TSoundWindow::MciNotify(WPARAM, LPARAM)
{
  if (!FlushNotify) {        // Internal STOP/CLOSE, from thumb re-pos?
    StopWave();

    // Make sure the thumb is at the end. There could be some WM_TIMER
    // messages on the queue when we kill it, thereby flushing WM_TIMER's
    // from the message queue.
    //
    int   loVal, hiVal;
    SoundBar->GetRange(loVal, hiVal);
    SoundBar->SetPosition(hiVal);

  } else
    FlushNotify = FALSE;          // Yes, so ignore the close.
  return 0;
}

void
TSoundWindow::CmHelpAbout()
{
  MessageBox("SoundPly loads and plays waveform sound "
    "files (*.WAV).  The features of this demo are Play/Pause, Stop, "
    "and random seeks through the file via the scollbar (while the sound is "
    "playing).  NOTE: SoundPly will only play sounds if the machine contains "
    "a waveForm device, e.g. SoundBlaster, etc.).",
    "About Sound Play", MB_OK);
}

void
TSoundWindow::EvTimer(UINT)
{
  if (!FlushNotify) {               // Internal STOP/CLOSE, from thumb re-pos?
    MciStatusParm.dwCallback = 0;   // No, normal close.
    MciStatusParm.dwItem = MCI_STATUS_LENGTH;
    mciSendCommand (DeviceId, MCI_STATUS, MCI_STATUS_ITEM, MCI_PARM2(MciStatusParm));

    if (WaveLength != MciStatusParm.dwReturn) {
      Invalidate();  // First time it's different update the scrollbar nums
      WaveLength = MciStatusParm.dwReturn;
    }

    // Compute the length and ratio and update SoundBar info.
    //
    WaveRatio = int((WaveLength + 32000/2) / 32000);
    if (!WaveRatio)
      WaveRatio = 1;
    SoundBar->SetInfo(WaveRatio, WaveLength);
    SoundBar->SetRange(0, int(WaveLength / WaveRatio));
    SoundBar->SetRuler(int((WaveLength / WaveRatio) / 10));

    // Update the current position.
    //
    MciStatusParm.dwCallback = 0;
    MciStatusParm.dwItem = MCI_STATUS_POSITION;
    mciSendCommand(DeviceId, MCI_STATUS, MCI_STATUS_ITEM, MCI_PARM2(MciStatusParm));

    SoundBar->SetPosition(int(MciStatusParm.dwReturn / WaveRatio));
  }

  FlushNotify = FALSE;          // Yes, ignore this close.
}

//----------------------------------------------------------------------------

class TSoundApp : public TApplication {
  public:
    TSoundApp() : TApplication() {}
    void InitMainWindow() {
      MainWindow = new TSoundWindow(0, "OWL MCI SoundPlay Demo");
      EnableCtl3d();
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TSoundApp().Run();
}
