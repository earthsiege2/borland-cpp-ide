/*
  This program is based heavily on an example from the
  DirectX SDK. It demonstrates one way to animate a bitmap. 
*/

#include <vcl.h>
#include <ddraw.h>
#pragma hdrstop
#include "ddutil.h"
#include "Main.h"
#pragma resource "*.dfm"
#define NAME "DDExample4"
#define TITLE "Direct Draw Example 4"

char szBitmap[] = "ALL";
TFormMain *FormMain;

__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
  FRunApp = True;
  FActive = False;  
}

MESSAGE void TFormMain::MyMove(TMessage &Message)
{
  do
  {
    UpdateFrame();
    Application->ProcessMessages();
  }
  while(FRunApp == True);
}

void TFormMain::InitFail()
{
    MessageBox(Handle, "DirectDraw Init FAILED", TITLE, MB_OK );
    Close();
} /* initFail */

void TFormMain::Start()
{
  HRESULT ddrval;
  DDSURFACEDESC	ddsd;
  DDSCAPS ddscaps;

  ddrval = DirectDrawCreate( NULL, &lpDD, NULL );
  if( ddrval != DD_OK )
  {
     InitFail();
     return;
  }

  // Get exclusive mode
  ddrval = lpDD->SetCooperativeLevel(Handle, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN );
  if( ddrval != DD_OK )
  {
    InitFail();
    return;
  }

  // Set the video mode to 640x480x8
  ddrval = lpDD->SetDisplayMode( 640, 480, 8);
  if( ddrval != DD_OK )
  {
    InitFail();
    return;
  }

  // Create the primary surface with 1 back buffer
  ddsd.dwSize = sizeof( ddsd );
  ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
  ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE |
                        DDSCAPS_FLIP |
                        DDSCAPS_COMPLEX;
  ddsd.dwBackBufferCount = 1;
  ddrval = lpDD->CreateSurface( &ddsd, &lpDDSPrimary, NULL );
  if( ddrval != DD_OK )
  {
    InitFail();
    return;
  }

  ddscaps.dwCaps = DDSCAPS_BACKBUFFER;
  ddrval = lpDDSPrimary->GetAttachedSurface(&ddscaps, &lpDDSBack);
  if( ddrval != DD_OK )
  {
    InitFail();
    return;
  }

  // create and set the palette
  lpDDPal = DDLoadPalette(lpDD, szBitmap);

  if (lpDDPal)
      lpDDSPrimary->SetPalette(lpDDPal);

  // Create the offscreen surface, by loading our bitmap.
  lpDDSOne = DDLoadBitmap(lpDD, szBitmap, 0, 0);

  if( lpDDSOne == NULL )
  {
    InitFail();
    return;
  }
  // Set the color key for this bitmap (black)
  DDSetColorKey(lpDDSOne, RGB(0,0,0));
}

void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
  if( lpDD != NULL )
  {
    if( lpDDSPrimary != NULL )
    {
      lpDDSPrimary->Release();
      lpDDSPrimary = NULL;
    }
    if( lpDDSOne != NULL )
    {
      lpDDSOne->Release();
      lpDDSOne = NULL;
    }
    if( lpDDPal != NULL )
    {
      lpDDPal->Release();
      lpDDPal = NULL;
    }
    lpDD->Release();
    lpDD = NULL;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormKeyDown(TObject *Sender, WORD &Key,
        TShiftState Shift)
{
  switch (Key)
  {
    case VK_F3:
      FActive = True;
      Start();
      PostMessage(Handle, WM_INFOSTART, 0, 0);
      break;
      
    case VK_ESCAPE:
    case VK_F12:
      FRunApp = False;
      FActive = False;
      Close();
      break;
  }
}

HRESULT TFormMain::RestoreAll( void )
{
  HRESULT	ddrval;

  ddrval = lpDDSPrimary->Restore();
  if( ddrval == DD_OK )
  {
	  ddrval = lpDDSOne->Restore();
  	if( ddrval == DD_OK )
	  {
      DDReLoadBitmap(lpDDSOne, szBitmap);
    }
  }
  return ddrval;
} /* restoreAll */

void TFormMain::UpdateFrame( void )
{
  static DWORD	lastTickCount[3] = {0,0,0};
  static int		currentFrame[3] = {0,0,0};
  DWORD		thisTickCount;
  RECT		rcRect;
  DWORD		delay[3] = {50, 78, 13};
  int			i;
  int			xpos[3] = {288, 190, 416};
  int			ypos[3] = {128, 300, 256};
  HRESULT		ddrval;

  // Decide which frame will be blitted next
  thisTickCount = GetTickCount();
  for(i=0; i<3; i++)
  {
    if((thisTickCount - lastTickCount[i]) > delay[i])
    {
      // Move to next frame;
      lastTickCount[i] = thisTickCount;
      currentFrame[i]++;
      if(currentFrame[i] > 59)
        currentFrame[i] = 0;
    }
  }

  // Blit the stuff for the next frame
  rcRect.left = 0;
  rcRect.top = 0;
  rcRect.right = 640;
  rcRect.bottom = 480;
  while(1)
  {
    ddrval = lpDDSBack->BltFast( 0, 0, lpDDSOne,
    &rcRect, DDBLTFAST_NOCOLORKEY );
    if( ddrval == DD_OK )
      break;

    if( ddrval == DDERR_SURFACELOST )
    {
      ddrval = RestoreAll();
      if( ddrval != DD_OK )
      {
        return;
      }
    }
    if( ddrval != DDERR_WASSTILLDRAWING )
    {
      return;
    }
  }

  if(ddrval != DD_OK)
    return;

  for(i=0; i<3; i++)
  {
    rcRect.left   = currentFrame[i]%10*64;
    rcRect.top    = currentFrame[i]/10*64 + 480;
    rcRect.right  = currentFrame[i]%10*64 + 64;
    rcRect.bottom = currentFrame[i]/10*64 + 64 + 480;

    while( 1 )
    {
      ddrval = lpDDSBack->BltFast( xpos[i], ypos[i], lpDDSOne,
        &rcRect, DDBLTFAST_SRCCOLORKEY );
      if( ddrval == DD_OK )
       break;

      if( ddrval == DDERR_SURFACELOST )
      {
        ddrval = RestoreAll();
        if( ddrval != DD_OK )
          return;
      }
      if( ddrval != DDERR_WASSTILLDRAWING )
        return;
    }
  }
  // Flip the surfaces
  while( 1 )
  {
    ddrval = lpDDSPrimary->Flip( NULL, 0 );
    if( ddrval == DD_OK )
      break;

    if( ddrval == DDERR_SURFACELOST )
    {
      ddrval = RestoreAll();
      if( ddrval != DD_OK )
        break;
    }
    if( ddrval != DDERR_WASSTILLDRAWING )
      break;
  }
}

void __fastcall TFormMain::FormPaint(TObject *Sender)
{
  AnsiString S = "F3 to Start, Esc to Exit";
  HDC DC = GetDC(Handle);
  if (!FActive)
  {
    SetBkMode(DC, TRANSPARENT);
    TextOut(DC, 25, 100, S.c_str(), S.Length());
  }
  ReleaseDC(Handle, DC);
}

