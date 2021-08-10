// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
//  stream1.cpp
//    Must link with strmpnt.cpp
// ---------------------------------------------------------------------------

#include "strmpnt.h"

const char* FileName = "stream.dat";

void WriteStream()
{
    ofpstream ofp(FileName);
    T3DPoint p3(7,9,11);
    ofp << &p3;
}

void ReadStream()
{
    ifpstream ifp(FileName);
    T3DPoint* p3 = 0;
    ifp >> p3;
    if( p3 )
        p3->Draw();
}

int main()
{
    WriteStream();
    ReadStream();
    return 0;
}
