//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   source\owl\point.cpp
//   Implementation of mathematical TPoint, TSize, TRect classes.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\point.h>

#if !defined(SECTION) || SECTION == 1

//
// Calculate the integer square root of a 32bit signed long. return a 16bit
// signed. Is fairly fast, esp. compared to FP versions
//
int _OWLFUNC
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
// make a duplicate of a C string using new
//
char* _OWLFUNC
strnewdup(const char* s)
{
  if (!s)
    s = "";
  return strcpy(new char[strlen(s)+1], s);
}

//
// make a far duplicate of a C string using new far
//
#if defined(__SMALL__) || defined(__MEDIUM__)
char far*  _OWLFUNC
strnewdup(const char far* s)
{
  if (!s)
    s = "";
  return strcpy(new far char[strlen(s)+1], s);
}

long
atol(const char far* s)
{
  for (long val = 0; *s && isdigit(*s); s++)
    val = val*10 + *s - '0';
  return val;
}

#endif


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

#endif
#if !defined(SECTION) || SECTION == 2

ostream& _OWLFUNC
operator <<(ostream& os, const TRect& r)
{
  return os << '(' << r.left << ',' << r.top << '-'
            << r.right << ',' << r.bottom << ')';
}

//
// streaming operators for resource Ids
//
ostream& _OWLFUNC
operator <<(ostream& os, const TResId& id)
{
  BOOL  isNumeric = !id.IsString();

  if (isNumeric)
    os << (long)id.Id;

  else
    #if defined(__SMALL__) || defined(__MEDIUM__)
      os << string(id.Id);
    #else
      os << id.Id;
    #endif
  return os;
}

#endif
#if !defined(SECTION) || SECTION == 3

ipstream& _OWLFUNC
operator >>(ipstream& is, TRect& r)
{
  return is >> r.left >> r.top >> r.right >> r.bottom;
}

opstream& _OWLFUNC
operator <<(opstream& os, const TRect& r)
{
  return os << r.left << r.top << r.right << r.bottom;
}

//
// streaming operators for resource Ids
//
ipstream& _OWLFUNC
operator >>(ipstream& is, TResId& id)
{
  BOOL  isNumeric;
  is >> isNumeric;

  if (isNumeric) {
    long  nid;
    is >> nid;
    id = int(nid);

  } else
    id = is.freadString();
  return is;
}

opstream& _OWLFUNC
operator <<(opstream& os, const TResId& id)
{
  BOOL  isNumeric = !id.IsString();
  os << isNumeric;

  if (isNumeric)
    os << (long)id.Id;

  else
    os.fwriteString(id.Id);
  return os;
}
#endif

