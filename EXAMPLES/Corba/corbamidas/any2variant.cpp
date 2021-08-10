//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <windows.h>
#include <corbapch.h>
#pragma hdrstop
#include <corba.h>
#include <any.h>

#include "Any2Variant.h"

//---------------------------------------------------------------------------


// Returns Any initialized with data from a single-dim BYTE ARRAY in a SAFEARRAY of a Variant.
//
BOOL SAFEARRAYToSequence(const VARIANT &va, CORBA::Any &any)
{
  // Ensure we're dealing with an array
  //
  if (va.vt & VT_ARRAY)
  {
    // Get the Variant Type
    //
    VARTYPE varType = VARTYPE(va.vt & ~(VT_ARRAY|VT_BYREF));
    // Must be array of byte
    if (varType == VT_UI1)
    {
      // Get ref. to SAFEARRAY
      //
      SAFEARRAY &sa = (va.vt & VT_BYREF) ? (**va.pparray) : (*va.parray);

      // Retrieve information about the SAFEARRAY
      //
      UINT dim = ::SafeArrayGetDim(&sa);

      // Must dim of 1
      if (!(dim == 1))
        return 0;

      // Count of elments in single dimension
      //
      DWORD cElements = sa.rgsabound[0].cElements;

      // Allocate the memory to hold the sequence
      CORBA::ULong value_len = cElements + sizeof(CORBA::ULong);
      char *value = new char[value_len];
      void *ptr = value;

      // Copy the element count
      *(CORBA::ULong *)ptr = cElements;
      ((CORBA::ULong *)ptr)++;

      // Copy the data
      ::SafeArrayLock(&sa);
      memcpy(ptr, sa.pvData, cElements);
      ::SafeArrayUnlock(&sa);

      // Create an any with the value
      CORBA_TypeCode_var etc = new CORBA_TypeCode(CORBA::tk_octet, 0);
      CORBA_TypeCode_var tc = CORBA::ORB::create_sequence_tc(0, etc);
      CORBA_MarshalInBuffer ibuf(value, value_len);
      any.read_value(ibuf, tc);

      delete[] value;
      return TRUE;
    }
  }

  return FALSE;
}

// Create an any that represents the content of an VARIANT.
// VT_ARRAY/VT_UI1 -> tk_sequence/tk_octet
// VT_VOID -> tk_void
// all other anys -> tk_null
CORBA::Any * SAFEARRAYToAny(const VARIANT &va)
{
  // Default constructor of Any builds a tk_null instance
  CORBA::Any_var any = new CORBA::Any;
  if (va.vt == VT_VOID)
  {
    CORBA::TypeCode_var ptc = new CORBA::TypeCode(CORBA::tk_void, 0);
    any->replace(CORBA::_tc_TypeCode, ptc);
  }
  else
    SAFEARRAYToSequence(va, *any);

  return CORBA::Any::_duplicate(any);
}

// Take data from a Sequence in the 'Any' and copies the data to
// an allocated SAFEARRAY stored in the Variant.
// NOTE: The VARIANT is *NOT* cleared. So make sure that it does
//       not contain any data that will be leaked.
//
BOOL SequenceToSAFEARRAY(const CORBA::Any &any, VARIANT &var)
{
  void *ptr = (void *)any.value();

  // Extract the length of the sequence
  //
  DWORD count = *(CORBA::ULong *)ptr;
  ((CORBA::ULong *)ptr)++;

   // Setup bonds of safearray
   //
   SAFEARRAYBOUND bounds[1];
   bounds[0].lLbound = 0;
   bounds[0].cElements= count;

  // Create SafeArray
  //
  SAFEARRAY *psa = ::SafeArrayCreate(VT_UI1, 1, bounds);

  if (psa)
  {
    // Lock and load data from Any's sequence
    //
    ::SafeArrayLock(psa);
    memcpy(psa->pvData, ptr, count);
    ::SafeArrayUnlock(psa);

    // Initialize VARIANT with SAFEARRAY
    //
    var.vt = VT_ARRAY|VT_UI1;
    V_ARRAY(&var) = psa;

    // Return success
    //
    return TRUE;
  }

  // Flag failure
  //
  return FALSE;
}

BOOL InternalAnyToSAFEARRAY(const CORBA::Any& any, CORBA::TypeCode_ptr tc, VARIANT &var)
{
  VARIANT *pv = &var;

  // Copy data from Any
  switch (tc->kind())
  {
    case CORBA::tk_null:
          ::VariantClear(pv);
          pv->vt = VT_NULL;
          return TRUE;

    case CORBA::tk_void:
          ::VariantClear(pv);
          pv->vt = VT_VOID;
          return TRUE;

    case CORBA::tk_sequence:
          ::VariantClear(pv);
          return SequenceToSAFEARRAY(any, *pv);

    case CORBA::tk_alias:
    {
		CORBA_TypeCode_var ctc = tc->content_type();
		while (ctc->kind() == CORBA::tk_alias)
		    ctc = ctc->content_type();
        return InternalAnyToSAFEARRAY(any, ctc, var);
    }

    case CORBA::tk_any:
    {
        CORBA_Any_ptr a = (CORBA_Any_ptr) any.value();
        CORBA_TypeCode_var ctc = a->type();
        return InternalAnyToSAFEARRAY(*a, ctc, var);
    }
  }
  return FALSE;
}

BOOL AnyToSAFEARRAYVar(const CORBA::Any& any, VARIANT &var)
{
  CORBA::TypeCode_var tc = any.type();
  return InternalAnyToSAFEARRAY(any, tc, var);
}

// Create an any that represents the content of an any.
// tk_sequence/tk_octet -> VT_ARRAY/VT_UI1
// tk_void -> VT_VOID
// all other anys -> VT_EMPTY
VARIANT * AnyToSAFEARRAY(const CORBA::Any& any)
{
  // Create VT_EMPTY variant
  VARIANT *pv= new VARIANT;
  ::VariantInit(pv);

  // Attempt the any data to the variant
  AnyToSAFEARRAYVar(any, *pv);

  return pv;
}

