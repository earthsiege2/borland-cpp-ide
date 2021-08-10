//----------------------------------------------------------------------------
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
// TLocaleString default native language for symbols, only if not user-defined
//----------------------------------------------------------------------------
#if !defined(_Windows)
# define _Windows      // pretend we are in windows to get the headers we need
#endif
#include <osl/locale.h>

TLangId TLocaleString::NativeLangId = TLocaleString::GetSystemLangId();
