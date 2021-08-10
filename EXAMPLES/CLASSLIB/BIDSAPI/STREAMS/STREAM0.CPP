// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// stream0.cpp
//    Must link with strmpnt.cpp 
// ---------------------------------------------------------------------------

#include "strmpnt.h"

const char* FileName = "stream.dat";

void WriteStream(void)
{
    ofpstream ofp(FileName);
    T2DPoint p2(3,5);
    ofp << &p2;
}

void ReadStream(void)
{
    ifpstream ifp(FileName);
    T2DPoint* p2 = 0;
    ifp >> p2;
    if( p2 )
        p2->Draw();
}

int main()
{
    WriteStream();
    ReadStream();
    return 0;
}
