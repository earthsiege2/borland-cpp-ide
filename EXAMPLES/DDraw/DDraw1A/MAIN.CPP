/*
  This is a DirectDraw example program. DirectDraw programs require that you
  have the DirectDraw runtime on your system. The runtime files are available
  from Microsoft's web site, though many machines will have them on them
  already, as they ship with a wide variety of products, including games, the
  future operating systems Windows 98 and Windows NT 5.0. If you are using NT 4,
  you should upgrade to at least Service Pack 3, so that you can have access
  to DirectDraw 3.0, which is part of that Service Pack. Don't
  try to install the DirectDraw runtime on a Windows NT system, instead, get
  the latest Service Pack. The runtime install is meant only for Windows 95 or
  98. One way to tell if you have DirectDraw on your system is to look in the
  Windows/System directory or Winnt/System32 directory for the files DDRAW.DLL
  and DSOUND.DLL.

  The purpose of DirectDraw is to allow you to perform very fast graphics
  operations inside the Windows environment. In particular, DirectDraw can
  give you direct access to the video buffers on a video card. For best
  results, you should have at least 2 MB of memory on your video card.
  DirectDraw allows you to create a backbuffer, draw to it, and then
  flip it to the visible area in your video memory. Assuming that you are
  in exclusive mode, and have enough video memory to keep both your primary
  surface and back surface in video RAM, then the flip operation is
  not a copy procedure, but simply changes the address of the block of
  memory referenced by the visible area of your video card's memory. In short
  the operation is very fast, and is guarenteed to happen in sync with
  the refresh operations on your monitor. As a result, you can use DirectDraw
  to perform very smooth animations. For a complete explanation, go to the
  DirectDraw area on Microsoft's web site, or visit my web site at
  http://users.aol.com/charliecal.

  The code shown here is the simplest possible DirectDraw program. It is
  modeled closely after the DDX1 example that ships with the Microsoft's
  DirectDraw SDK. I've simply taken their program, and rewritten it to
  compile under a form based environment. In particular, the code uses a
  TTimer object rather than calling SetTimer, and it responds to events
  such as OnKeyDown rather than directly handling WM_KEYDOWN messages.
  The conversion to a form based paradigm makes the code easier to read,
  but doesn't change its underlying structure.

  If you do not want to use forms, the DDX1 program will compile unchanged
  under CBuilder. Simply start a standard CBuilder project, remove the main
  form, then replace the code in the Project Source with the code from
  DDX1.cpp, which file ships with Microsoft's SDK. Press compile, and the
  program will run fine.

  The code in this project has five methods:

  CONSTRUCTOR:
    Perform trivial initialization of variables.

  FORMDESTROY:
    Destroy the direct draw surfaces created in the Start method.

  START:
    Call DirectDrawCreate, which initializes DirectDraw, and returns a pointer
      to a DirectDraw object.
    Call SetCooperativeLevel to switch into exclusive mode.
    Call SetDisplayMode to switch to 640X480 8 bit resolution.
    Call CreateSurface to create a primary surface
    Call GetAttachedSurface to get a pointer to the back surface
    Paint the front and back surface to black, and paint text to each
      so you can recognize them when they are flipped to the screen.
    Enable the timer.

  FORMKEYDOWN:
    Respond to key presses designating the user's desire to switch into
      exclusive mode and begin the demo.
    Respond to the F12 or Esc keys by shutting down the application.

  FORMPAINT:
    Paint some simple instructions for the user in the middle of the screen.
    This method is not called while the program is in Exclusive mode.

  TIMER1TIMER:
    Flip between the primary and back surfaces. This is the key method in this
    demo as it shows how to swap two different surfaces, which is what you
    want to do in an animated graphics program. This method is somewhat
    misleading, though, because most of the time you will want to swap at
    the fastest rate possible, rather than waiting for the timer to call
    your program and ask you to swap. For instance, a smooth animation
    should have a frame rate of at least 25 frames per second, a rate which
    is not practical to achieve using a timer.

*/

// Includes 
#include <vcl.h>
#include <ddraw.h>
#pragma hdrstop
#include "Main.h"
#pragma resource "*.dfm"

//Const
#define TIMER_ID        1
#define TIMER_RATE      500

// Global Variables
TFormMain *FormMain;

///////////////////////////////////////
// Constructor
///////////////////////////////////////
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
  lpDD = NULL;
  phase = 0;
  bActive = False;
  FrontMsg = "Front buffer (F12 or Esc to quit)";
  BackMsg = "Back buffer (F12 or Esc to quit)";
}

///////////////////////////////////////
// WM_DESTROY messages
///////////////////////////////////////
void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
  if(lpDD != NULL)
  {
    if(lpDDSPrimary != NULL)
    {
      lpDDSPrimary->Release();
      lpDDSPrimary = NULL;
    }
    lpDD->Release();
    lpDD = NULL;
  }
}

///////////////////////////////////////
// Initialize DirectDraw
///////////////////////////////////////
void __fastcall TFormMain::Start()
{
  HRESULT ddrval;
  DDSURFACEDESC ddsd;
  DDSCAPS ddscaps;
  HDC DC;
  char buf[256];

  ddrval = DirectDrawCreate(NULL, &lpDD, NULL);
  if(ddrval == DD_OK)
  {
    // Get exclusive mode
    ddrval = lpDD->SetCooperativeLevel(Handle,
      DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN);
    if(ddrval == DD_OK)
    {
      ddrval = lpDD->SetDisplayMode(640, 480, 8);
      if(ddrval == DD_OK)
      {
        // Create the primary surface with 1 back buffer
        ddsd.dwSize = sizeof(ddsd);
        ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
                              DDSCAPS_FLIP |
                              DDSCAPS_COMPLEX;
        ddsd.dwBackBufferCount = 1;
        ddrval = lpDD->CreateSurface(&ddsd, &lpDDSPrimary, NULL);
        if(ddrval == DD_OK)
        {
          // Get a pointer to the back buffer
          ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
          ddrval = lpDDSPrimary->GetAttachedSurface(&ddscaps,
                                                &lpDDSBack);
          if(ddrval == DD_OK)
          {
            // draw some text.
            if (lpDDSPrimary->GetDC(&DC) == DD_OK)
            {
                SetBkColor(DC, RGB(0, 0, 255));
                SetTextColor(DC, RGB(255, 255, 0));
                TextOut(DC, 0, 0, FrontMsg.c_str(), FrontMsg.Length());
                lpDDSPrimary->ReleaseDC(DC);
            }

            if (lpDDSBack->GetDC(&DC) == DD_OK)
            {
                SetBkColor(DC, RGB(0, 0, 255));
                SetTextColor(DC, RGB(255, 255, 0));
                TextOut(DC, 0, 0, BackMsg.c_str(), BackMsg.Length());
                lpDDSBack->ReleaseDC(DC);
            }

            // Create a timer to flip the pages
            Timer1->Enabled = True;
            bActive = True;
            return;
          }
        }
      }
    }
  }
  wsprintf(buf, "Direct Draw Init Failed (%08lx)\n", ddrval);
  MessageBox(Handle, buf, "ERROR", MB_OK);
  Close();
}

///////////////////////////////////////
// WM_KEYDOWN messages
///////////////////////////////////////
void __fastcall TFormMain::FormKeyDown(TObject *Sender, WORD &Key,
        TShiftState Shift)
{

   switch (Key)
   {
     case VK_F3:
       Start();
       break;

     case VK_ESCAPE:
     case VK_F12:
       Close();
       break;
   }
}

///////////////////////////////////////
// WM_PAINT messages
///////////////////////////////////////
void __fastcall TFormMain::FormPaint(TObject *Sender)
{
  RECT rc;
  SIZE size;
  char szMsg[] = "Page Flipping Test: Press F3 to start, F12 or Esc to exit";
  
  if (!bActive)
  {
    HDC DC = GetDC(Handle);
    rc = GetClientRect();
    GetTextExtentPoint(DC, szMsg, lstrlen(szMsg), &size);
    SetBkColor(DC, RGB(0, 0, 0));
    SetTextColor(DC, RGB(255, 255, 0));
    TextOut(DC, (rc.right - size.cx)/2, (rc.bottom - size.cy)/2,
      szMsg, sizeof(szMsg)-1);
    ReleaseDC(Handle, DC);
  }
}

///////////////////////////////////////
// WM_TIMER messages
///////////////////////////////////////
void __fastcall TFormMain::Timer1Timer(TObject *Sender)
{
  HDC DC;

  if (lpDDSBack->GetDC(&DC) == DD_OK)
  {
    if(phase)
    {
      SetBkColor(DC, RGB(0, 0, 255));
      SetTextColor(DC, RGB(255, 255, 0));
      TextOut(DC, 0, 0, FrontMsg.c_str(), FrontMsg.Length());
      phase = 0;
    }
    else
    {
      SetBkColor(DC, RGB(0, 0, 255));
      SetTextColor(DC, RGB(0, 255, 255));
      TextOut(DC, 0, 0, BackMsg.c_str(), BackMsg.Length());
      phase = 1;
    }
    lpDDSBack->ReleaseDC(DC);
  }

  while(1)
  {
    HRESULT ddrval;
    ddrval = lpDDSPrimary->Flip(NULL, 0);
    
    if(ddrval == DD_OK)
      break;

    if(ddrval == DDERR_SURFACELOST)
    {
      ddrval = lpDDSPrimary->Restore();
      if(ddrval != DD_OK)
        break;
    }

    if(ddrval != DDERR_WASSTILLDRAWING)
      break;
  }
}

