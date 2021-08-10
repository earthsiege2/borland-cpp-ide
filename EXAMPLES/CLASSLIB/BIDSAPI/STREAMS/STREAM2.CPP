// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
//  stream2.cpp
//    Must link with strmpnt.cpp
// ---------------------------------------------------------------------------

#include "strmpnt.h"

const char* FileName = "stream.dat";

void WriteStream()
{
    ofpstream ofp(FileName);
    T2DPointColor p2c(7,9,0,1,2);
    ofp << &p2c;
}

void ReadStream()
{
    ifpstream ifp(FileName);
    T2DPointColor* p2c = 0;
    ifp >> p2c;
    if( p2c )
        p2c->Draw();
}

int main()
{
    WriteStream();
    ReadStream();
    return 0;
}
