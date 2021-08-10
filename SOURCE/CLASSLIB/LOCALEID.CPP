//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// TLocaleString default native language for symbols, only if not user-defined
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#include <winsys/lclstrng.h>

TLangId TLocaleString::NativeLangId = TLocaleString::GetSystemLangId();
