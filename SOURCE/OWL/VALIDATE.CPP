//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\validate.cpp
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\validate.h>
#include <owl\module.h>
#include <classlib\objstrm.h>
#include <stdlib.h>
#include <ctype.h>

#if !defined(SECTION) || SECTION == 1

//
// Construct a validator
//
TValidator::TValidator()
{
  Options = 0;
}

TValidator::~TValidator()
{
}

//
// Validator error display. Overridden in derived classes
//
void
TValidator::Error()
{
}

//
// Checks current input against validator. May adjust input if suppressFill
// isn't set & validator has the voFill option set.
//
BOOL
TValidator::IsValidInput(char far*, BOOL /*suppressFill*/)
{
  return TRUE;
}

//
// Checks input against validator for completeness. Never modifies input.
//
BOOL
TValidator::IsValid(const char far*)
{
  return TRUE;
}

UINT
TValidator::Transfer(char far*, void*, TTransferDirection)
{
  return 0;
}

TValidator::TXValidator::TXValidator(UINT resId) : TXOwl(resId)
{
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE(TValidator);

void*
TValidator::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  is >> GetObject()->Options;
  return GetObject();
}

void
TValidator::Streamer::Write(opstream& os) const
{
  os << GetObject()->Options;
}

#endif

