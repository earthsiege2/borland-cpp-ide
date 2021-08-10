//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.1  $
//
// class TCmdLine implementation
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/cmdline.h>
#include <services/memory.h>

const char whitespace[] = " \t";
const char terminator[] = "=/ \t";  // remove /- to dissallow separating there

TCmdLine::TCmdLine(const char far* cmdLine)
{
  Buffer = new char[strlen(cmdLine)+1];
  strcpy(Buffer, cmdLine);
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
    strcpy(TokenStart, Token+TokenLen);
    Token = TokenStart;
  }
  else {
    Token += TokenLen;
    TokenStart = Token;
  }

  // Adjust token ptr to begining of token & determine kind
  //
  Token += strspn(Token, whitespace);  // skip leading whitespace
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
  Token += strspn(Token, whitespace);  // skip any more whitespace
  TokenLen = strcspn(Token, terminator);
  return Kind;
}
