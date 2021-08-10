//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Implementation of TValidator, user input validator abstract base class
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_VALIDATE_H)
# include <owl/validate.h>
#endif
#if !defined(OWL_MODULE_H)
# include <owl/module.h>
#endif
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

//
//
//
TValidator::~TValidator()
{
}

//
// Validator error display. Overridden in derived classes
//
void
TValidator::Error(TWindow* /*owner*/)
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

//
//
//
uint
TValidator::Transfer(char far*, void*, TTransferDirection)
{
  return 0;
}

//
// Adjust the 'value' of the text, given a cursor position & an amount
// Return the actual amount adjusted.
//
int
TValidator::Adjust(string& /*text*/, uint& /*begPos*/, uint& /*endPos*/, int /*amount*/)
{
  return 0;
}

//----------------------------------------------------------------------------

//
//
//
TXValidator::TXValidator(uint resId)
:
  TXOwl(resId)
{
}


//
// Copies the exception so it can be rethrown at a safer time.
//
#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXValidator*
#endif
TXValidator::Clone()
{
  return new TXValidator(*this);
}

//
// Throws the exception.
//
void
TXValidator::Throw()
{
  THROW( *this );
}

//
// Creates an instance of TXValidator and throws it.
//
void
TXValidator::Raise()
{
  TXValidator().Throw();
}

#endif
#if !defined(SECTION) || SECTION == 2

#if !defined(BI_NO_OBJ_STREAMING)

IMPLEMENT_STREAMABLE(TValidator);

//
//
//
void*
TValidator::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  is >> GetObject()->Options;
  return GetObject();
}

//
//
//
void
TValidator::Streamer::Write(opstream& os) const
{
  os << GetObject()->Options;
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
