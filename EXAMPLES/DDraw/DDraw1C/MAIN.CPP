/*
  This is a DirectDraw program. Read DirectDraw.htm before running this
  program.
  
  This example demonstrates smooth animation of multiple objects using
  DirectDraw. The program starts in normal windows mode. If you press
  F3, the program switches to exclusive mode and begins drawing a series
  of multicolored circles and squares to the screen. Each shape has its
  own trajectory, and will bounce off the walls when it hits them. The end
  result is a series of multi-colored shapes moving across the screen in
  kaleidoscopic fashion.

  There are two main classes in the program:

  TDRAWSHAPE:
    This class represents one of the shapes being drawn to the screen. Each
    instance of the class has a location, a shape, direction, and color. Each
    call to the objects Draw method will automatically move the shape further
    in its trajectory. A constructor is provided that will allow you to
    initialize all the key features of the object.

  TFormMain:
    This object controls the flow of the program. It contains a TList object
    on which each of the programs Shapes can be hung. If the user presses
    F3, the program will automatically be placed in exclusive mode, and the
    shapes will be draw to the screen.

*/

// Includes and pragmas 
#include <vcl.h>
#include <ddraw.h>
#pragma hdrstop
#include "Main.h"
#pragma resource "*.dfm"

// Global Variables
TFormMain *FormMain;

//------------------------------------------------------------------------------
// --- TDrawShape --------------------------------------------------------------
//------------------------------------------------------------------------------

///////////////////////////////////////
// Constructor
///////////////////////////////////////
__fastcall TDrawShape::TDrawShape(int ValX, int ValY, int X, int Y,
  int AType, TColor AColor)
{
  FMoveValX = ValX;
  FMoveValY = ValY;
  ShapeRect = Rect(X, Y, X+25, Y+25);
  ShapeType = AType;
  Color = AColor;
}

///////////////////////////////////////
// Move
///////////////////////////////////////
void TDrawShape::Move()
{
  FPrevRect2 = Rect(FPrevRect.left, FPrevRect.top, FPrevRect.right, FPrevRect.bottom);
  FPrevRect = Rect(FX, FY, FX1, FY1);
  FX += FMoveValX;
  FY += FMoveValY;
  FX1 += FMoveValX;
  FY1 += FMoveValY;
  if (FX1 > 637)
    FMoveValX = -2;
  if (FX < 3)
    FMoveValX = 2;
  if (FY1 > 477)
    FMoveValY = - 2;
  if (FY < 3)
    FMoveValY = 2;
}

///////////////////////////////////////
// Draw
///////////////////////////////////////
void TDrawShape::Draw(HDC &DC)
{
  HBRUSH Brush, OldBrush;

  Brush = CreateSolidBrush(RGB(0, 0, 0));
  OldBrush = (HBRUSH)SelectObject(DC, Brush);
  if (FShapeType==CIRCLETYPE)
    Ellipse(DC, FPrevRect2.left-1, FPrevRect2.top-1, FPrevRect2.right+1, FPrevRect2.bottom+1);
  else if (FShapeType == RECTTYPE)
    Rectangle(DC, FPrevRect2.left-1, FPrevRect2.top-1, FPrevRect2.right+1, FPrevRect2.bottom+1);
  SelectObject(DC, OldBrush);
  DeleteObject(Brush);

  Move();

  Brush = CreateSolidBrush(FColor);
  OldBrush = (HBRUSH)SelectObject(DC, Brush);
  if (FShapeType==CIRCLETYPE)
    Ellipse(DC, FX, FY, FX1, FY1);
  else if (FShapeType == RECTTYPE)
    Rectangle(DC, FX, FY, FX1, FY1);

  SelectObject(DC, OldBrush);
  DeleteObject(Brush);
}

//------------------------------------------------------------------------------
// --- TFormMain ------------------------------------------------------------------
//------------------------------------------------------------------------------

///////////////////////////////////////
// Constructor
///////////////////////////////////////
__fastcall TFormMain::TFormMain(TComponent* Owner)
        : TForm(Owner)
{
  lpDD = NULL;
  FPhase = 0;
  FActive = False;
  FShapeRect = Rect(25, 25, 50, 50);
  FValueAdd = 2;
  BuildList();
}

///////////////////////////////////////
// BuildList
///////////////////////////////////////
void TFormMain::BuildList()
{
  FShapeList = new TList();

  FShapeList->Add(new TDrawShape(-2, 2, 175, 175, CIRCLETYPE, clLime));
  FShapeList->Add(new TDrawShape(2, 2, 125, 125, RECTTYPE, clBlue));
  FShapeList->Add(new TDrawShape(2, -2, 200, 200, RECTTYPE, clYellow));
  FShapeList->Add(new TDrawShape(2, -2, 75, 75, CIRCLETYPE, clRed));
  FShapeList->Add(new TDrawShape(-2, 2, 325, 350, RECTTYPE, clPurple));
  FShapeList->Add(new TDrawShape(-2, -2, 275, 250, CIRCLETYPE, clFuchsia));
  FShapeList->Add(new TDrawShape(-2, 2, 125, 325, CIRCLETYPE, clTeal));
  FShapeList->Add(new TDrawShape(2, 2, 350, 175, RECTTYPE, clNavy));
  FShapeList->Add(new TDrawShape(2, -2, 150, 250, CIRCLETYPE, clOlive));
  FShapeList->Add(new TDrawShape(-2, 2, 225, 25, CIRCLETYPE, clSilver));
}

///////////////////////////////////////
// WM_DESTROY messages
///////////////////////////////////////
void __fastcall TFormMain::FormDestroy(TObject *Sender)
{
  TDrawShape *Shape;
  int i;
  
  for (i = 0; i < FShapeList->Count; i++)
  {
    Shape = (TDrawShape*)FShapeList->Items[i];
    delete Shape;
  }
  delete FShapeList;
  
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
            PostMessage(Handle, WM_RUNAPP, 0, 0);
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
       FActive = True;
       Start();
       break;

     case VK_ESCAPE:
     case VK_F12:
       FActive = False;
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
  
  if (!FActive)
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
// Run the program
///////////////////////////////////////
void TFormMain::Run(TMessage &Message)
{
  do
  {
    PerformAction();
    Application->ProcessMessages();
  }
  while (FActive);
}

///////////////////////////////////////
// PerformAction
///////////////////////////////////////
void TFormMain::PerformAction()
{
  HDC DC;

  // Don't step through code that has lock on it!
  // Getting a DC may put a lock on video memory.
  if (lpDDSBack->GetDC(&DC) == DD_OK)
  {
    DrawShape(DC);
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
    {
      FActive = False;
      Close();
    }
  }
}

void TFormMain::DrawShape(HDC &DC)
{
  TDrawShape *Shape;
  int i;

  for (i = 0; i < FShapeList->Count; i++)
  {
    Shape = (TDrawShape*)FShapeList->Items[i];
    Shape->Draw(DC);
  }
}
