//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef Any2VARIANTH
#define Any2VARIANTH
#include <windows.h>
#include <corba.h>
#include <any.h>

// Create an any that represents the content of an VARIANT.
// VT_ARRAY/VT_UI1 -> tk_sequence/tk_octet
// VT_VOID -> tk_void
// all other anys -> tk_null
//CORBA::Any * SAFEARRAYToAny(const VARIANT &va);
CORBA::Any * SAFEARRAYToAny(VARIANT va);

// Create an any that represents the content of an any.
// tk_sequence/tk_octet -> VT_ARRAY/VT_UI1
// tk_void -> VT_VOID
// all other anys -> VT_EMPTY
VARIANT * AnyToSAFEARRAY(const CORBA::Any& any);
BOOL AnyToSAFEARRAYVar(const CORBA::Any& any, VARIANT &var);

#endif
