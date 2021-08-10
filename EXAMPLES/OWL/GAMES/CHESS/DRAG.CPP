//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/defs.h>
#include <math.h>
#include "wcdefs.h"
#include "externs.h"

#define AnimationSpeed    2

static HDC hSaveDC;
static TPoint  LastPoint;
static HANDLE  hOldBmp;
static HBITMAP hDragPiece, hDragMask;
static HCURSOR hPrevCursor;

#undef max
#undef min
#define max(a, b)  (((a) > (b)) ? (a) : (b))
#define min(a, b)  (((a) < (b)) ? (a) : (b))

static BOOL IsDragging = FALSE;
static TPoint StartPoint;
static TPoint CurPoint;

static void
SaveBackground(TPoint& p)
{
  LastPoint = p;
  HDC hDC = GetDC(hWndMain);

  HBITMAP hBitmap = PieceBmpArray[0][white]; // handle to any of the bitmaps is ok
  BITMAP bitmap;
  GetObject(hBitmap, sizeof(BITMAP), &bitmap);
  
  hSaveDC = CreateCompatibleDC(hDC);
  hOldBmp = SelectObject(hSaveDC, CreateCompatibleBitmap(hDC, bitmap.bmWidth, bitmap.bmHeight));

  BitBlt(hSaveDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight,
    hDC, p.x, p.y, SRCCOPY);

  ReleaseDC(hWndMain, hDC);
}

static void
RestoreBackground()
{
  HDC hDC = GetDC(hWndMain);
  HBITMAP hBitmap = PieceBmpArray[0][white]; // handle to any of the bitmaps is ok
  BITMAP bitmap;
  GetObject(hBitmap, sizeof(BITMAP), &bitmap);

  BitBlt(hDC, LastPoint.x, LastPoint.y, bitmap.bmWidth, bitmap.bmHeight,
    hSaveDC, 0, 0, SRCCOPY);

  DeleteObject(SelectObject(hSaveDC, hOldBmp));
  DeleteDC(hSaveDC);
  ReleaseDC(hWndMain, hDC);
}

static void
ShowPiece(TPoint& p)
{

  HDC hDC = GetDC(hWndMain);
  HDC hMemoryDC = CreateCompatibleDC(hDC);
  BITMAP bitmap;
  GetObject(hDragPiece, sizeof(BITMAP), &bitmap);

  HANDLE hOldBmp = SelectObject(hMemoryDC, hDragMask);
  BitBlt(hDC, p.x, p.y, bitmap.bmWidth, bitmap.bmHeight,
    hMemoryDC, 0, 0, SRCAND);

  SelectObject(hMemoryDC, hDragPiece);
  BitBlt(hDC, p.x, p.y, bitmap.bmWidth, bitmap.bmHeight,
    hMemoryDC, 0, 0, SRCINVERT);

  SelectObject(hMemoryDC, hOldBmp);
  DeleteDC(hMemoryDC);
  ReleaseDC(hWndMain, hDC);
}

static void
UpdateScreen(TPoint& p)
{
  BITMAP bitmap;
  GetObject(hDragPiece, sizeof(BITMAP), &bitmap);

  TRect rect1(p, TSize(bitmap.bmWidth, bitmap.bmHeight));
  TRect rect2(LastPoint, TSize(bitmap.bmWidth, bitmap.bmHeight));
  
  if (!rect1.Touches(rect2)) {
    RestoreBackground();
    SaveBackground(p);
    ShowPiece(p);
    return;
  }

  HDC hDC = GetDC(hWndMain);

  HDC hNewSaveDC = CreateCompatibleDC(hDC);
  HANDLE hNewOldBmp = SelectObject(hNewSaveDC,
	  CreateCompatibleBitmap(hDC, bitmap.bmWidth, bitmap.bmHeight));

  TRect rect = rect1 | rect2;
  HDC hUpdateDC = CreateCompatibleDC(hDC);
  HANDLE hUOldBmp = SelectObject(hUpdateDC,
	        CreateCompatibleBitmap(hDC, rect.Width(), rect.Height()));

  // get new section
  BitBlt(hUpdateDC, 0, 0, rect.Width(), rect.Height(), hDC, rect.left, rect.top, SRCCOPY);

  // restore old section
  BitBlt(hUpdateDC, abs(rect.left-rect2.left), abs(rect.top-rect2.top),
    bitmap.bmWidth, bitmap.bmHeight, hSaveDC, 0, 0, SRCCOPY);

  // save new background
  BitBlt(hNewSaveDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight,
    hUpdateDC, abs(rect.left-rect1.left), abs(rect.top-rect1.top), SRCCOPY);

  // blit the mask
  DeleteObject(SelectObject(hSaveDC, hDragMask));

  BitBlt(hUpdateDC, abs(rect.left-rect1.left), abs(rect.top-rect1.top),
    bitmap.bmWidth, bitmap.bmHeight, hSaveDC, 0, 0, SRCAND);

  // blit the piece
  SelectObject(hSaveDC, hDragPiece);
  BitBlt(hUpdateDC, abs(rect.left-rect1.left), abs(rect.top-rect1.top),
    bitmap.bmWidth, bitmap.bmHeight, hSaveDC, 0, 0, SRCINVERT);

  // put it on the screen
  BitBlt(hDC, rect.left, rect.top, rect.Width(), rect.Height(), hUpdateDC, 0, 0, SRCCOPY);

  SelectObject(hSaveDC, hOldBmp); // don't delete current bmp (hDragPiece)
  DeleteDC(hSaveDC);
  hSaveDC = hNewSaveDC;
  hOldBmp = hNewOldBmp;
  LastPoint = p;
  DeleteObject(SelectObject(hUpdateDC, hUOldBmp));
  DeleteDC(hUpdateDC);
  ReleaseDC(hWndMain, hDC);
}

void
DragStart(SQUARETYPE square, TPoint& point)
{
  point.x -= 18;
  point.y -= 18;

  StartPoint = GetSquareXY(square);

  hDragPiece = PieceBmpArray[Board[square].piece-1][Board[square].color];
  hDragMask = MaskArray[Board[square].piece-1];

  hPrevCursor = SetCursor(0);

  SetClassWindowCursor(hWndMain, 0);
  SetCapture(hWndMain);
  ClearSquare(square);
  SaveBackground(point); 
  ShowPiece(point);  
  IsDragging = TRUE;
}

void FAR PASCAL
ReturnHome(int x, int y, LPSTR)
{
  static int Count = AnimationSpeed;
  if (Count) {
    Count--;
    return;
  }
  Count = AnimationSpeed;
  UpdateScreen(TPoint(x,y));
}

void
DragEnd(BOOL ValidMove)
{
  if (!IsDragging)
    return;
  if (ValidMove)
    RestoreBackground();
  else {
    LineDDA(CurPoint.x, CurPoint.y, StartPoint.x, StartPoint.y,
	      LINEDDAPROC(ReturnHome), 0);
    RestoreBackground();
  }
  SetCursor(hPrevCursor);
  SetClassWindowCursor(hWndMain, hPrevCursor);
  ReleaseCapture();
  IsDragging = FALSE;
}

void
Drag(TPoint& p)
{
  p.x -= 18;
  p.y -= 18;
  CurPoint = p;
  UpdateScreen(p);
}

void
SlidePiece(SQUARETYPE end, SQUARETYPE start)
{
  TPoint p1 = GetSquareXY(start);
  TPoint p2;

  if (IsDragging)
    MessageBox(0, "SlidePiece called before DragEnd", "WChess", MB_OK);

  hDragPiece = PieceBmpArray[Board[start].piece-1][Board[start].color];
  hDragMask = MaskArray[Board[start].piece-1];

  hPrevCursor = SetCursor(0);
  SetClassWindowCursor(hWndMain, 0);
  ClearSquare(start);
  SaveBackground(p1);
  ShowPiece(p1);
  
  p2 = GetSquareXY(end);
  LineDDA(p1.x, p1.y, p2.x, p2.y, LINEDDAPROC(ReturnHome), 0);
  UpdateScreen(p2);
  DeleteObject(SelectObject(hSaveDC, hOldBmp));
  DeleteDC(hSaveDC);
  SetCursor(hPrevCursor);
  SetClassWindowCursor(hWndMain, hPrevCursor);
}
