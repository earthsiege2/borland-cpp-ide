/**********************************************************************
 *          Copyright (c) 1993 by Borland International, Inc.         *
 *                                                                    *
 *                            S_PAINT.C                               *
 *                                                                    *
 *  This program demonstrates how to write a simple Windows graphics  *
 *  program. It's called Simple Paint and provides three objects the  *
 *  user can draw, a line, an ellipse, and a rectangle. Simple Paint  *
 *  also provides the user with three choices of line thicknesses     *
 *  and three choices of colors: red, green, and black.               *
 **********************************************************************/

#define STRICT

#include <windows.h>
#include "dbugdemo.h"

//   FUNCTION PROTOTYPES

int  DoWMCommand(WPARAM wParam, HWND hWnd);
void DoLButtonDown(HWND hWnd, LONG lParam);
void DoLButtonUp(HWND hWnd, LONG lParam);
void DoMouseMove(HWND hWnd, LONG lParam);
void DoPaint(HWND hWnd);
void DrawShape(HDC hdc, int x, int y, int x2, int y2, int Shape,
               int PenWidth, COLORREF PenColor, int Slope);
LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

//   GLOBAL VARIABLES

#define ShapeI 100

int ShapeNumber = -1;           // Indicates the number of shapes drawn.

int CurrentShape = LINE;        // The shape the user is drawing.

int PenWidth = 3;               // The current pen width.
                                // Default width is medium.

COLORREF PenColor = RGB(255, 0, 0);    // The current pen color.
                                       // Default is red.

typedef struct SSHAPE           // Struct which tracks the drawn shapes.
{
        RECT       Points;      // Location of shape.
        int        PenWidth;    // Pen width for the shape.
        int        Shape;       // Type of shape.
        COLORREF   PenColor;    // Color of shape.
        int        Slope;       // Used to draw lines correctly.
} SHAPE;

SHAPE Shapes[ShapeI];           // Array that stores the shapes.

/*******************************************************
 * function WinMain
 *******************************************************/
#pragma argsused
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpszCmdLine, int nCmdShow)
{
    WNDCLASS    wndClass;
    MSG         msg;
    HWND        hWnd;

    /*
     * Register window class style if first
     * instance of this program.
     */
    if (!hPrevInstance)
    {
        wndClass.style          = CS_HREDRAW | CS_VREDRAW;
        wndClass.lpfnWndProc    = WndProc;
        wndClass.cbClsExtra     = 0;
        wndClass.cbWndExtra     = 0;
        wndClass.hInstance      = hInstance;
        wndClass.hIcon          = LoadIcon(hInstance, "IDI_SIMPLEPAINT");
        wndClass.hCursor        = LoadCursor(NULL, IDC_ARROW);
        wndClass.hbrBackground  = GetStockObject(WHITE_BRUSH);
        wndClass.lpszMenuName   = szAppName;
        wndClass.lpszClassName  = szAppName;

        if (!RegisterClass(&wndClass))
            return FALSE;
    }

    /*
     * Create and display the window.
     */
    hWnd = CreateWindow(szAppName, "Simple Paint",
               WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,0,
               CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

/*******************************************************
 * function WndProc
 *    Handles all messages received by the window
 *******************************************************/
LRESULT CALLBACK WndProc (HWND hWnd, UINT Message,
                          WPARAM wParam, LPARAM lParam)
{
    switch(Message)
    {
        case WM_COMMAND:
            return DoWMCommand(wParam, hWnd);

        case WM_LBUTTONDOWN:
            DoLButtonDown(hWnd, lParam);
            break;

        case WM_LBUTTONUP:
            DoLButtonUp(hWnd, lParam);
            break;

        case WM_MOUSEMOVE:
            DoMouseMove(hWnd, lParam);
            break;

        case WM_PAINT:
            DoPaint(hWnd);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hWnd, Message, wParam, lParam);
    }
    return 0;
}

/*****************************************************************
 * function DrawShape
 *    Draws the shape given by Shape parameter using PenWidth
 *    and PenColor in the rectangle bounded by x,y,x2,y2. The
 *    Slope parameter is used with LINE shapes to determine if
 *    lines should be drawn with a negative or positive slope.
 *****************************************************************/
#pragma argsused
void DrawShape(HDC hdc, int x, int y, int x2, int y2, int Shape,
               int PenWidth, COLORREF PenColor, int Slope)
{
    HANDLE      saveObject;

    /*
     * Create the proper pen for this shape. Save the
     * previously selected object from this DC.
     */
    saveObject = SelectObject(hdc, CreatePen(PS_SOLID,
                              PenWidth, PenColor));
    switch(Shape)
    {
        case LINE:
            /* If Slope is set, then draw from LowerRight to UpperLeft. If
             * Slope is not set then draw from UpperLeft to LowerRight.
             */
            if (Slope == 1)
            {
                MoveToEx(hdc, x, y2, NULL);
                LineTo(hdc, x2, y);
            }
            else 
            {
                MoveToEx(hdc, x, y, NULL);
                LineTo(hdc, x2, y2);
            }
            break;

        case ELLIPSE:
            Ellipse(hdc, x, y, x2, y2);
            break;

        case RECTANGLE:
            Rectangle(hdc, x, y, x2, y2);
            break;
    }

    /*
     * Delete the currently selected object (the pen) and select whatever
     * object was selected when we entered this routine.
     */

    DeleteObject(SelectObject(hdc, saveObject));
}

/****************************************************************
 * function DoPaint
 *    Processes WM_PAINT messages. WM_PAINT is generated
 *    whenever UpdateWindow is called or another window is moved,
 *    revealing a portion of the window receiving this message.
 ****************************************************************/
void DoPaint(HWND hWnd)
{
    int           i;
    HDC           hdc, hMemDC;
    RECT          theRect, destRect;
    HBITMAP       theBitmap;
    PAINTSTRUCT   ps;

    hdc = BeginPaint(hWnd, &ps);

    if (ShapeNumber >= 0)
    {
        /*
         * Determine which rectangle on the window is invalid.
         * If no rectangle is marked invalid, it will be a full
         * window repaint.
         */
        GetUpdateRect(hWnd, &theRect, 0);
        if (IsRectEmpty(&theRect))
            GetClientRect(hWnd, &theRect);

        /*
         * Create a memory DC and bitmap the same
         * size as the update rectangle.
         */
        hMemDC = CreateCompatibleDC(hdc);
        theBitmap = CreateCompatibleBitmap(hdc,
                         theRect.right-theRect.left,
                         theRect.bottom-theRect.top);
        SelectObject(hMemDC, theBitmap);

        /*
         * Erase the memBitmap.
         */
        BitBlt(hMemDC, 0, 0,
               theRect.right-theRect.left,
               theRect.bottom-theRect.top,
               hdc, 0, 0, SRCCOPY);

        /*
         * Draw only those shapes that lie
         * within the update rectangle.
         */
        for (i = 0; i <= ShapeNumber; ++i)
        {
            IntersectRect(&destRect, &Shapes[i].Points, &theRect);
            if (!IsRectEmpty(&destRect))
                DrawShape(hMemDC,
                    Shapes[i].Points.left-theRect.left,
                    Shapes[i].Points.top-theRect.top,
                    Shapes[i].Points.right-theRect.left,
                    Shapes[i].Points.bottom-theRect.top,
                    Shapes[i].Shape,
                    Shapes[i].PenWidth,
                    Shapes[i].PenColor,
                    Shapes[i].Slope);
            /*
             * Note that when drawing the shape, the shape's
             * position was transformed so that the origin was
             * at the upper-left corner of the update rectangle.
             * This is the point (0,0) on the bitmap that will
             * map onto (theRect.left,theRect.top).
             */
        }

        /*
         * Finally, copy the bitmap onto the update rectangle.
         */
        BitBlt(hdc, theRect.left, theRect.top,
               theRect.right-theRect.left,
               theRect.bottom-theRect.top,
               hMemDC, 0, 0, SRCCOPY);

        DeleteDC(hMemDC);
        DeleteObject(theBitmap);
    }
    EndPaint(hWnd, &ps);
}

/**********************************************************
 * static variables oldx, oldy, mouseDown
 *    Used to maintain both the state of the mouse position
 *    and the button status between mouse messages.
 **********************************************************/

static  oldx = -1, oldy = -1, mouseDown = 0;

/******************************************************************
 * function DoLButtonDown
 *    When the left button on the mouse is pressed, this routine
 *    saves the origin of this shape, the current pen parameters,
 *    and the current shape into the shapes array. The mouse
 *    button is also marked as pressed.
 ******************************************************************/
void DoLButtonDown(HWND hWnd, LONG lParam)
{
    /*
     * Redirect all subsequent mouse movements to this
     * window until the mouse button is released.
     */
    SetCapture(hWnd);
    oldy = Shapes[++ShapeNumber].Points.top = HIWORD(lParam);
    oldx = Shapes[ShapeNumber].Points.left = LOWORD(lParam);
    Shapes[ShapeNumber].Shape = CurrentShape;
    Shapes[ShapeNumber].PenWidth = PenWidth;
    Shapes[ShapeNumber].PenColor = PenColor;

    mouseDown = 1;
}

/******************************************************************
 * function DoLButtonUp
 *    When the Left mouse button is released, this routine
 *    allows other windows to receive mouse messages and saves
 *    the position of the mouse as the other corner of a bounding
 *    rectangle for the shape.
 ******************************************************************/
void DoLButtonUp(HWND hWnd, LONG lParam)
{
    if (mouseDown == 0)
        return;

    ReleaseCapture();

    /*
     * For rectangles to work with the IntersectRect function,
     * they must be stored as left, top, right, bottom.
     */

    SetRect(&Shapes[ShapeNumber].Points,
        min(Shapes[ShapeNumber].Points.left, LOWORD(lParam)),
        min(Shapes[ShapeNumber].Points.top, HIWORD(lParam)),
        max(Shapes[ShapeNumber].Points.left, LOWORD(lParam)),
        max(Shapes[ShapeNumber].Points.top, HIWORD(lParam)));

    /*
     * If slope is decreasing, set equal to 0, then draw from UpperLeft
     * to LowerRight. If slope is increasing, set equal to 1, and draw
     * draw from LowerLeft to UpperRight.
     */

    if (CurrentShape == LINE)
        Shapes[ShapeNumber].Slope = ((Shapes[ShapeNumber].Points.left ==
            LOWORD(lParam)) ^ (Shapes[ShapeNumber].Points.top ==
            HIWORD(lParam))) ?  1 : 0;

        /*
         * This statement uses an exclusive-or because the following
         * is true for a line drawn from LowerRight to UpperLeft:
         *     ((Shapes[ShapeNumber].Points.left == LOWORD) &&
         *         (Shapes[ShapeNumber].Points.right == HIWORD)).
         */

    /*
     * Mark this region on the window as needing redrawing and force an 
     * update.
     */

    InvalidateRect(hWnd, &Shapes[ShapeNumber].Points, 0);
    UpdateWindow(hWnd);
    mouseDown = 0;
    oldx = -1;
    oldy = -1;
}

static int SaveROP;

/**********************************************************************
 * function DoMouseMove
 *    When the mouse is moved and the button is down, this function
 *    draws the current shape. It uses the Raster Operation NOTXORPEN
 *    to draw the shape. When this mode is used, drawing the
 *    same image twice returns the image to its original state.
 *    NOTXORPEN turns black on black white, black on white black
 *    and white on white white.
 **********************************************************************/
void DoMouseMove(HWND hWnd, LONG lParam)
{
    HDC hdc;

    if (mouseDown)
    {
        hdc = GetDC(hWnd);
        /*
         * Erase the old shape as the mouse is moved.
         */
        SaveROP = SetROP2(hdc, R2_NOTXORPEN);
        DrawShape(hdc, Shapes[ShapeNumber].Points.left,
                  Shapes[ShapeNumber].Points.top, oldx, oldy,
                  Shapes[ShapeNumber].Shape,
                  Shapes[ShapeNumber].PenWidth,
                  Shapes[ShapeNumber].PenColor,
                  0);
        /*
         * Draw the new shape to the new mouse position.
         */
        oldx = LOWORD(lParam);
        oldy = HIWORD(lParam);
        DrawShape(hdc, Shapes[ShapeNumber].Points.left,
                  Shapes[ShapeNumber].Points.top, oldx, oldy,
                  Shapes[ShapeNumber].Shape,
                  Shapes[ShapeNumber].PenWidth,
                  Shapes[ShapeNumber].PenColor,
                  0);
        SetROP2(hdc, SaveROP);
        ReleaseDC(hWnd, hdc);
    }
}

/*********************************************************************
 * function DoWMCommand
 *    When a menu item is selected, this function changes the current
 *    state of shape selections to match the user's menu selection.
 *******************************************************************/
int DoWMCommand(WPARAM wParam, HWND hWnd)
{
    switch(wParam)
    {
        case MID_QUIT:
            DestroyWindow(hWnd);
            break;

        case MID_LINE:
            CurrentShape = LINE;
            break;

        case MID_ELLIPSE:
            CurrentShape = ELLIPSE;
            break;

        case MID_RECTANGLE:
            CurrentShape = RECTANGLE;
            break;

        case MID_THIN:
            PenWidth = 1;
            break;

        case MID_REGULAR:
            PenWidth = 3;
            break;

        case MID_THICK:
            PenWidth = 5;
            break;

        case MID_RED:
            PenColor = RGB(255, 0, 0);
            break;

        case MID_GREEN:
            PenColor = RGB(0, 255, 0);
            break;

        case MID_BLACK:
            PenColor = RGB(0, 0, 0);
            break;

        default:
            return 0;
    }
    return 1;
}

