//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\noxx.cpp
// Empty replacement for exception functions
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <stdlib.h>

void _ThrowException(void __far*,void __far*,void __far*,void __far*,unsigned int,unsigned int,unsigned int,unsigned char near*)
{
  abort();
}

extern "C" void __InitExceptBlock() {}
