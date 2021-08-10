//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Empty replacement for exception functions
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <stdlib.h>

void _ThrowException(void __far*,void __far*,void __far*,void __far*,unsigned int,unsigned int,unsigned int,unsigned char near*)
{
  abort();
}

extern "C" void __InitExceptBlock() {}
