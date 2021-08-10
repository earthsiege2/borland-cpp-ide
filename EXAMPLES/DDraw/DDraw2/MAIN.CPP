/*
  This program introduces the concept of loading a bitmap into a DirectDraw
  scene. The program flips back and forth between two surfaces, one of
  which contains a bitmap, while the second is black. Therefore the
  picture should appear to blink on and off.
*/

// Includes 
#include <vcl.h>
#include <ddraw.h>
#pragma hdrstop
#include "Main.h"
#include "ddutil.h"
#pragma resource "*.dfm"

//Const
#define TIMER_ID        1
#define TIMER_RATE      500

// Global Variables
TFormMain *FormMain;
char szBackground[] = "BACK";

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
    if(lpDDPal != NULL )
    {
      lpDDPal->Release();
      lpDDPal = NULL;
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
  char buf[256];

  ddrval = DirectDrawCreate(NULL, &lpDD, NULL);
  if(ddrval == DD_OK)
  {
    // Enter exclusive mode
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
          // Retrieve pointer to back buffer
          ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
          ddrval = lpDDSPrimary->GetAttachedSurface(&ddscaps,
                                                &lpDDSBack);

          if(ddrval == DD_OK)
          {
            lpDDPal = DDLoadPalette(lpDD, szBackground);
            if (lpDDPal == NULL)
              goto error;

            ddrval = lpDDSPrimary->SetPalette(lpDDPal);

            if( ddrval != DD_OK )
              goto error;

            // load a bitmap into the back buffer.
            ddrval = DDReLoadBitmap(lpDDSBack, szBackground);

            if( ddrval != DD_OK )
              goto error;

            // Create a timer to flip the pages
            Timer1->Enabled = True;
            bActive = True;
            return;
          }
        }
      }
    }
  }
error:
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
    ddrval = lpDDSPrimary->Flip( NULL, 0 );
    if( ddrval == DD_OK )
      break;
    if( ddrval == DDERR_SURFACELOST )
    {
      ddrval = lpDDSPrimary->Restore();
      if( ddrval != DD_OK )
        break;
      ddrval = DDReLoadBitmap(lpDDSBack, szBackground);
      if( ddrval != DD_OK )
        break;
    }
    if( ddrval != DDERR_WASSTILLDRAWING )
      break;
  }
}

