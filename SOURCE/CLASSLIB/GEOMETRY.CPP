//----------------------------------------------------------------------------
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//   Implementation of geometry (TPoint, TSize, TRect) classes.
//----------------------------------------------------------------------------
#if !defined(_Windows)
# define _Windows      // pretend we are in windows to get the headers we need
#endif
#include <osl/defs.h>
#include <osl/geometry.h>

//
// Calculate the integer square root of a 32bit signed long. return a 16bit
// signed. Is fairly fast, esp. compared to FP versions
//
int _BIDSFUNC
Sqrt(long val)
{
  if (val <= 0)
    return 0;     // Throw a math exception?

  unsigned mask = 1;  // Bit mask to shift left
  int best = 0;       // Best estimate so far

  for (; !(mask&0x8000); mask <<= 1)
    if (((long)best+mask)*(best+mask) <= val)
      best |= mask;
  return best;
}

//
// Make a duplicate of a C string using new char[]
//
char* _BIDSFUNC
strnewdup(const char* s, size_t allocSize)
{
  if (!s)
    s = "";
  int alloc = max(strlen(s)+1, allocSize);
  return strcpy(new char[alloc], s);
}

//
// Make a far duplicate of a C string using new char[] far
//
#if defined(BI_DATA_NEAR)

char far*  _BIDSFUNC
strnewdup(const char far* s, size_t allocSize)
{
  if (!s)
    s = "";
  int alloc = max(strlen(s)+1, allocSize);
  return strcpy(new far char[alloc], s);
}

long
atol(const char far* s)
{
  for (long val = 0; *s && isdigit(*s); s++)
    val = val*10 + *s - '0';
  return val;
}

#endif

#if !defined(BI_PLAT_WIN16)
//
// Make a duplicate of a wide C string using new wchar_t[]
//
wchar_t* _BIDSFUNC
strnewdup(const wchar_t* s, size_t allocSize)
{
  if (!s)
    s = L"";
  int alloc = max((size_t)lstrlenW(s)+1, allocSize);
  return lstrcpyW(new wchar_t[alloc], s);
}
#endif

//----------------------------------------------------------------------------

TRect&
TRect::Normalize()
{
  if (left > right)
    Swap(left, right);
  if (top > bottom)
    Swap(top, bottom);
  return *this;
}

TRect&
TRect::Offset(int dx, int dy)
{
  left += dx;
  top += dy;
  right += dx;
  bottom += dy;
  return *this;
}

TRect&
TRect::Inflate(int dx, int dy)
{
  left -= dx;
  top -= dy;
  right += dx;
  bottom += dy;
  return *this;
}

TRect&
TRect::operator &=(const TRect& other)
{
  if (!IsNull()) {
    if (other.IsNull())
      SetNull();
    else {
      left = Max(left, other.left);
      top = Max(top, other.top);
      right = Min(right, other.right);
      bottom = Min(bottom, other.bottom);
    }
  }
  return *this;
}

TRect&
TRect::operator |=(const TRect& other)
{
  if (!other.IsNull()) {
    if (IsNull())
      *this = other;
    else {
      left = Min(left, other.left);
      top = Min(top, other.top);
      right = Max(right, other.right);
      bottom = Max(bottom, other.bottom);
    }
  }
  return *this;
}

//----------------------------------------------------------------------------
// class TCmdLine implementation

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
