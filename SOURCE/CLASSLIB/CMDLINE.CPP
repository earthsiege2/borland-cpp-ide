//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.3  $
//
// class TCmdLine implementation
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/cmdline.h>
#include <services/memory.h>
#include <tchar.h>

const _TCHAR whitespace[] = " \t";
const _TCHAR terminator[] = "=/ \t";  // remove /- to dissallow separating there

TCmdLine::TCmdLine(const _TCHAR far* cmdLine)
{
  Buffer = new _TCHAR[_tcslen(cmdLine)+1];
  _tcscpy(Buffer, cmdLine);
  Reset();
}

void TCmdLine::Reset()
{
  Token = TokenStart = Buffer;
  TokenLen = 0;
  Kind = Start;
}

TCmdLine::~TCmdLine()
{
  delete [] Buffer;
}

TCmdLine::TKind TCmdLine::NextToken(bool removeCurrent)
{
  // Done parsing, no more tokens
  //
  if (Kind == Done)
    return Kind;

  // Move Token ptr to next token, by copying over current token, or by ptr
  // adjustment. TokenStart stays right past previous token
  //
  if (removeCurrent) {
    _tcscpy(TokenStart, Token+TokenLen);
    Token = TokenStart;
  }
  else {
    Token += TokenLen;
    TokenStart = Token;
  }

  // Adjust token ptr to begining of token & determine kind
  //
  Token += _tcsspn(Token, whitespace);  // skip leading whitespace
  switch (*Token) {
    case 0:
      Kind = Done;
      break;
    case '=':
      Kind = Value;
      Token++;
      break;
    case '-':
    case '/':
      Kind = Option;
      Token++;
      break;
    default:
      Kind = Name;
  }
  Token += _tcsspn(Token, whitespace);  // skip any more whitespace
  TokenLen = _tcscspn(Token, terminator);
  return Kind;
}
