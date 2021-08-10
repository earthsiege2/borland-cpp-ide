// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
//  strmpnt.cpp
//    Helper file for streaming examples.
// ---------------------------------------------------------------------------

#include "strmpnt.h"

// 
// T2DPoint
// 
T2DPoint::T2DPoint(int i, int j)
    : X(i), Y(j)
{
}

void T2DPoint::Draw()
{
    cout << "Drawing 2D point at " << X << ", " << Y << endl;
}

IMPLEMENT_CASTABLE(T2DPoint);
IMPLEMENT_STREAMABLE(T2DPoint);

void T2DPoint::Streamer::Write(opstream& os) const
{
    os << GetObject()->X << GetObject()->Y;
}

void *T2DPoint::Streamer::Read(ipstream& in, uint32) const
{
    in >> GetObject()->X >> GetObject()->Y;
    return GetObject();
}

// 
// T3DPoint
// 
T3DPoint::T3DPoint(int i, int j, int k)
    : T2DPoint(i, j), Z(k)
{
}

void T3DPoint::Draw()
{
    cout << "Drawing 3D point at " << X << ", " << Y << ", " << Z << endl;
}

IMPLEMENT_CASTABLE1(T3DPoint, T2DPoint);
IMPLEMENT_STREAMABLE1(T3DPoint, T2DPoint);

void T3DPoint::Streamer::Write(opstream& os) const
{
    WriteBaseObject((T2DPoint*)GetObject(), os);
    os << GetObject()->Z;
}

void *T3DPoint::Streamer::Read(ipstream& in, uint32) const
{
    ReadBaseObject((T2DPoint*)GetObject(), in);
    in >> GetObject()->Z;
    return GetObject();
}

// 
// Color
// 
TColor::TColor(int i, int j, int k)
    : R(i), G(j), B(k)
{
}

void TColor::DisplayColor()
{
    cout << "Color (" << R << ", " << G << ", " << B << ")" << endl;
}


// 
// T2DPointColor
// 
T2DPointColor::T2DPointColor(int x, int y, int r, int g, int b)
    : T2DPoint(x, y), TColor(r, g, b)
{
}

void T2DPointColor::Draw()
{
    DisplayColor();
    T2DPoint::Draw();
}

IMPLEMENT_CASTABLE2(T2DPointColor, T2DPoint, TColor);
IMPLEMENT_STREAMABLE2(T2DPointColor, T2DPoint, TColor);

void T2DPointColor::Streamer::Write(opstream& os) const
{
    WriteBaseObject((T2DPoint*)GetObject(), os);

    // Since TColor is not streamable (i.e. not derived from TStreamableBase
    // we'll write out the data members of it only.
    // Similarly for T2DPointColor::Streamer::Read().
    os << GetObject()->R << GetObject()->G << GetObject()->B;
}

void *T2DPointColor::Streamer::Read(ipstream& in, uint32) const
{
    ReadBaseObject((T2DPoint*)GetObject(), in);
    in >> GetObject()->R >> GetObject()->G >> GetObject()->B;
    return GetObject();
}

