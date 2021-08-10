//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994, 1994 by Borland International, All Rights Reserved
//
//   Implementation of TValidator, user input validator abstract base class
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/validate.h>
#include <owl/module.h>
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
bool
TValidator::IsValidInput(char far*, bool /*suppressFill*/)
{
  return true;
}

//
// Checks input against validator for completeness. Never modifies input.
//
bool
TValidator::IsValid(const char far*)
{
  return true;
}

uint
TValidator::Transfer(char far*, void*, TTransferDirection)
{
  return 0;
}

TValidator::TXValidator::TXValidator(uint resId) : TXOwl(resId)
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

