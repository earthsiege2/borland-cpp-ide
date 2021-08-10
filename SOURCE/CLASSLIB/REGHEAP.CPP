//----------------------------------------------------------------------------
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(_Windows)
# define _Windows      // pretend we are in windows to get the headers we need
#endif
#include <osl/locale.h>

TRegFormatHeap TRegItem::Heap = {0, 0, 0};
