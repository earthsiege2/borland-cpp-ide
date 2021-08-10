//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "palette.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
#pragma resource "extrares.res"
TDoodleForm *DoodleForm;
//---------------------------------------------------------------------------
__fastcall TDoodleForm::TDoodleForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDoodleForm::FormCreate(TObject *Sender)
{
    HINSTANCE HInst;
    HInst = reinterpret_cast<HINSTANCE>(HInstance);
    // Load custom cursors for tools from extrares.res
    Screen->Cursors[crFill] = LoadCursor(HInst, "FILL");
    Screen->Cursors[crPlus] = LoadCursor(HInst, "PLUS");
    Screen->Cursors[crDraw] = LoadCursor(HInst, "DRAW");
    Screen->Cursors[crErase] = LoadCursor(HInst, "ERASE");
    Cursor = TCursor(crDraw);
}
//---------------------------------------------------------------------------
void __fastcall TDoodleForm::Image1MouseDown(TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y)
{
    // The Doodle form contains an Image control on which all of the painting
    // will occur.  Another option would have been to draw directly on the
    // form's canvas.  The benefit of drawing on the Image control is that
    // it knows how to repaint itself.

    if (ToolPalette->FillButton->Down)
    {
        // The fill tool is the only one that makes use of the right mouse
        // button.  The right mouse button is used to fill with the BG color.
        if (Button == mbLeft)
            Image1->Canvas->Brush->Color = ToolPalette->FGShape->Brush->Color;
        else
            Image1->Canvas->Brush->Color = ToolPalette->BGShape->Brush->Color;
        Image1->Canvas->FloodFill(X, Y, Image1->Canvas->Pixels[X][Y], fsSurface);
        return;
    }

    // Otherwise, only the left mouse button is of interest.
    if (Button != mbLeft)
        return;

    if (ToolPalette->EraseButton->Down)
    {
        Image1->Canvas->Pen->Color = ToolPalette->BGShape->Brush->Color;
        Image1->Canvas->Brush->Color = ToolPalette->BGShape->Brush->Color;
        Image1->Canvas->Pen->Width = 13;
        Image1->Canvas->Rectangle(X-1, Y-1, X, Y);
        Image1->Canvas->MoveTo(X,Y);
        return;
    }

    if (ToolPalette->PencilButton->Down)
    {
        Image1->Canvas->Pen->Color = ToolPalette->FGShape->Brush->Color;
        Image1->Canvas->Brush->Color = ToolPalette->BGShape->Brush->Color;
        Image1->Canvas->MoveTo(X,Y);
        return;
    }

    // At this point, we know we are dealing with a circle, solid circle,
    // square, or solid square

    InitialX = X;
    InitialY = Y;

    // TmpImage will hold the image as it existed when the mouse went down.
    // This will be retained until the mouse is released.  This image will be
    // used to restore the image during sizing of squares and circles.
    TmpImage = new TImage(this);
    TmpImage->Picture = Image1->Picture;
}
//---------------------------------------------------------------------------
void __fastcall TDoodleForm::Image1MouseMove(TObject *Sender, TShiftState Shift,
    int X, int Y)
{
    // Only the left mouse button is of interest
    if (!Shift.Contains(ssLeft))
        return;

    if (ToolPalette->FillButton->Down)
        return;

    if (ToolPalette->PencilButton->Down)
    {
        Image1->Canvas->LineTo(X,Y);
        return;
    }

    if (ToolPalette->EraseButton->Down)
    {
        Image1->Canvas->LineTo(X,Y);
        return;
    }

    // At this point, we know we are dealing with an ellipse or rectangle,
    // filled or not filled.
    DrawShape(X, Y);
}
//---------------------------------------------------------------------------
void __fastcall TDoodleForm::Image1MouseUp(TObject *Sender, TMouseButton Button,
    TShiftState Shift, int X, int Y)
{
    // Only the left mouse button is of interest
    if (Button != mbLeft)
        return;

    if ((ToolPalette->FillButton->Down) || (ToolPalette->PencilButton->Down))
        return;

    if (ToolPalette->EraseButton->Down)
    {
        Image1->Canvas->Pen->Width = 1;
        return;
    }

    // At this point, we know we are dealing with an ellipse or rectangle,
    // filled or not filled.
    DrawShape(X, Y);

    delete TmpImage;
}
//---------------------------------------------------------------------------
void __fastcall TDoodleForm::FormActivate(TObject *Sender)
{
    // Contains the code for positioning and showing the tool palette.
    // The call to ToolPalette->Show() could have gone in DoodleForm's
    // Show method if not for the desire to position the window.

    if (ToolPalette->Visible)
        return;

    // Initial position of the palette relative to the main form
    ToolPalette->Top = DoodleForm->Top + (DoodleForm->Height / 6);
    ToolPalette->Left = DoodleForm->Left - ((DoodleForm->Width / 5));
    ToolPalette->Show();
}
//---------------------------------------------------------------------------
void __fastcall TDoodleForm::DrawShape(int X, int Y)
{
    TRect bounds;  // for graphics functions which require a rect

    // Start with the original image that we saved when the button
    // first went down.  This blows away any previous rectangles or ellipses
    // that were drawn while the user dragged.
    Image1->Picture = TmpImage->Picture;

    // The above line blew away the brush.  The line below restores it.
    Image1->Canvas->Brush->Color = ToolPalette->FGShape->Brush->Color;
    Image1->Canvas->Pen->Color = ToolPalette->FGShape->Brush->Color;

    // Some graphics functions do not allow a rectangle with its bottom above
    // its top, or right to the left of its left side.  This code is to deal
    // with the case that the user started dragging from the bottom or right.
    if (X < InitialX)
    {
        bounds.Left = X;
        bounds.Right = InitialX;
    }
    else
    {
        bounds.Right = X;
        bounds.Left = InitialX;
    }

    if (Y < InitialY)
    {
        bounds.Top = Y;
        bounds.Bottom = InitialY;
    }
    else
    {
        bounds.Bottom = Y;
        bounds.Top = InitialY;
    }

    // Draw the circle or square using the corresponding function.
    if (ToolPalette->CircleButton->Down)
        Image1->Canvas->Arc(InitialX, InitialY, X, Y, X, Y, X, Y);
    else if (ToolPalette->SolidCirButton->Down)
        Image1->Canvas->Ellipse(InitialX, InitialY, X, Y);
    else if (ToolPalette->SquareButton->Down)
        Image1->Canvas->FrameRect(bounds);
    else if (ToolPalette->SolidSqButton->Down)
        Image1->Canvas->FillRect(bounds);
}
//---------------------------------------------------------------------------
void __fastcall TDoodleForm::FormShow(TObject *Sender)
{
 SetFocus();   
}
//---------------------------------------------------------------------------

void __fastcall TDoodleForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 Application->Terminate();   
}
//---------------------------------------------------------------------------

 