//---------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DDCP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
	: TForm(Owner)
{
	BorderStyle = bsNone;
    InitializeDirectDraw();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::InitializeDirectDraw()
{
	DirectDrawCreate(NULL, &DirectDraw, NULL);
    DirectDraw->SetCooperativeLevel(Handle, DDSCL_ALLOWREBOOT | DDSCL_EXCLUSIVE
    									| DDSCL_FULLSCREEN);
    DirectDraw->SetDisplayMode(640, 480, 8);
    SetupPrimarySurface();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SetupPrimarySurface()
{
	DDSURFACEDESC ddsd;

    ZeroMemory(&ddsd, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
    DirectDraw->CreateSurface(&ddsd, &PrimarySurface, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::ShowPalette()
{
	RECT rect;
    rect.top = 60;

    DDBLTFX ddbltfx;
    ZeroMemory(&ddbltfx, sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);

    IDirectDrawPalette *palette332;
    PALETTEENTRY pe[256];

    //General algorithm for 3-3-2 palette
    for(int i = 0; i < 256; i++)
    {
    	pe[i].peRed = (BYTE) (((i >> 5)& 7)* 255/ 7);
		pe[i].peGreen = (BYTE) (((i >> 2)& 7)* 255/ 7);
        pe[i].peBlue = (BYTE) (((i >> 0)& 3)* 255/ 3);
        pe[i].peFlags = (BYTE)0;
    }

    DirectDraw->CreatePalette(DDPCAPS_8BIT, pe, &palette332, NULL);
    PrimarySurface->SetPalette(palette332);

   	for (int i = 0; i < 255; i++)
    {
    	ddbltfx.dwFillColor = i;

        if(i % 16 == 0)
        {
         	rect.top += 20;
            rect.left = 160;
            rect.right = rect.left + 10;
		    rect.bottom = rect.top + 10;
        }
        else
        {
         	rect.left += 20;
            rect.right = rect.left + 10;
        }

        PrimarySurface->Blt(&rect, NULL, NULL, DDBLT_COLORFILL, &ddbltfx);
    }


}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormPaint(TObject *Sender)
{
	DDBLTFX ddbltfx;
    ZeroMemory(&ddbltfx, sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = RGB(0x00, 0x00, 0x00);
    PrimarySurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL, &ddbltfx);
    ShowPalette();
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   exit(1);
}
//---------------------------------------------------------------------------

