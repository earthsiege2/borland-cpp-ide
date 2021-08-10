//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "canmain.h"
#include "math.h"
#include <stdlib.h>
#include <algorithm>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain *FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::FormCreate(TObject *Sender)
{
	Canvas->Pen->Color = clTeal;
	Rotation = 0;
	PointCount = MaxPoints;
	RotatePoints();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FormPaint(TObject *Sender)
{
	int centerX = ClientWidth / 2;
	int centerY = ClientHeight / 2;
	int radius = std::min(centerY, centerX);

	Canvas->Ellipse(0, 0, radius*2, radius*2);
	int i,j;
	for (i = 0; i < PointCount; i++) {
		for (j = i + 1; j < PointCount; j++) {
			Canvas->MoveTo(radius + floor(Points[i].X * radius),
				radius + floor(Points[i].Y * radius));
			Canvas->LineTo(radius + floor(Points[j].X * radius),
				radius + floor(Points[j].Y * radius));
		}
	}

	// A challenge:  Turn the rotating figure into a ball that bounces off the
	// walls of the window.  Don't forget the english (spin) on the ball should
	// pick up when bouncing off the wall...
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FormResize(TObject *Sender)
{
	Invalidate();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Timer1Timer(TObject *Sender)
{
	RotatePoints();
	Invalidate();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::RotatePoints()
{
	// NOTE: all figures are in radians
	const float M_2PI = 2 * M_PI;           // 2 pi radians in a circle
	float StepAngle = M_2PI / PointCount;   // angular distance between points

	Rotation += M_PI / 32;   // Increment the angle of rotation of figure
	if (Rotation > StepAngle)
		Rotation -= StepAngle;   // Keep rotation less than distance between points

	// The loop below has i walking through the Points array, while j walks
	// simultaneously through the angles to each point on the circle.
	// Incrementing j by StepAngle moves j to the next point on the circle with
	// no complicated arithmetic (everything has been set up in advance of the
	// loop).  Initializing j with Rotation causes the entire figure to shift
	// clockwise a small amount.
	//
	int i;
	float j;
	for (i = 0, j = Rotation; i < PointCount; i++, j += StepAngle) {
		Points[i].X = cos(j);   // These values will be multiplied by the
		Points[i].Y = sin(j);   // current radius at display time.
	}
}
//---------------------------------------------------------------------
