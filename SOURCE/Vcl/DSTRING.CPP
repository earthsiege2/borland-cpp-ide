//  dstring.cpp - support for delphi strings in cpp
//  $Revision:   1.28.1.0.1.2  $
//  Copyright (c) 1997, 2002 Borland Software Corp

#pragma inline
#define __DSTRING_INLINE

#include <windows.hpp>
#include <sysutils.hpp>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

#include <dstring.h>

#ifdef near
#undef near
#endif

static void dummy()
{
  // extern all asm symbols used here
  asm
  {
    extrn @System@@LStrAsg$qqrpvpxv:near
    extrn @System@@LStrCat$qqrv:near
    extrn @System@@LStrCat3$qqrv:near
    extrn @System@@LStrClr$qqrpv:near
    extrn @System@@LStrCmp$qqrv:near
    extrn @System@@LStrCopy$qqrv:near
    extrn @System@@LStrDelete$qqrv:near
    extrn @System@@LStrFromArray$qqrr17System@AnsiStringpci:near
    extrn @System@@LStrFromWStr$qqrr17System@AnsiStringx17System@WideString:near
    extrn @System@@LStrInsert$qqrv:near
    extrn @System@@LStrFromPChar$qqrr17System@AnsiStringpc:near
    extrn @System@@LStrLen$qqrv:near
    extrn @System@@LStrPos$qqrv:near
    extrn @System@@LStrSetLength$qqrv:near
  }
}


namespace System
{
  void  AnsiString::ThrowIfOutOfRange(int idx) const
  {
    if (idx < 1 || idx > Length())    // NOTE: AnsiString are 1-based !!
      throw ERangeError(Sysconst_SRangeError);
  }

  __fastcall      AnsiString::AnsiString(const char*)
  {
    asm
    {
      xor     ecx,ecx
      mov     eax, this
      mov     [eax], ecx
      call    @System@@LStrFromPChar$qqrr17System@AnsiStringpc
    }
  }

  __fastcall      AnsiString::AnsiString(const AnsiString&)
  {
    asm
    {
      mov     edx,[edx]
      xor     ecx,ecx
      mov     eax, this
      mov     [eax],ecx
      call    @System@@LStrAsg$qqrpvpxv
    }
  }

  __fastcall    AnsiString::AnsiString(const WideString &)
  {
    asm
    {
      xor   ecx, ecx
      mov   eax, this
      mov   [eax], ecx    /* this->data = NULL */
      mov   edx, [edx]    /* edx = src->data */
      call  @System@@LStrFromWStr$qqrr17System@AnsiStringx17System@WideString
    }
  }



  __fastcall AnsiString::AnsiString(const char* src, unsigned int len) : Data(0)
  {
    // We only handle up to INT_MAX (the sign bit is ignored)
    SetLength(int(len & INT_MAX));
    memcpy(Data, src, int(len & INT_MAX));
  }


  __fastcall AnsiString::AnsiString(const wchar_t* src) : Data(0)
  {
    int len = WideCharToMultiByte(CP_ACP, 0, const_cast<wchar_t*>(src), -1, 0, 0, 0, 0);

    if (len > 1)
    {
      SetLength(len - 1);
      WideCharToMultiByte(CP_ACP, 0, const_cast<wchar_t*>(src), -1, Data, len, 0, 0);
    }
  }

  __fastcall      AnsiString::AnsiString(char src) : Data(0)
  {
    sprintf("%c", src);
  }

  __fastcall AnsiString::AnsiString(short src) : Data(0)
  {
    sprintf("%hd", src);
  }

  __fastcall AnsiString::AnsiString(unsigned short src) : Data(0)
  {
    sprintf("%hu", src);
  }

  __fastcall AnsiString::AnsiString(int src) : Data(0)
  {
    sprintf("%i", src);
  }

  __fastcall AnsiString::AnsiString(unsigned int src) : Data(0)
  {
    sprintf("%u", src);
  }

  __fastcall AnsiString::AnsiString(long src) : Data(0)
  {
    sprintf("%ld", src);
  }

  __fastcall AnsiString::AnsiString(unsigned long src) : Data(0)
  {
    sprintf("%lu", src);
  }

  __fastcall AnsiString::AnsiString(__int64 src) : Data(0)
  {
    sprintf("%Li", src);
  }

  __fastcall AnsiString::AnsiString(unsigned __int64 src) : Data(0)
  {
    sprintf("%Lu", src);
  }

  __fastcall AnsiString::AnsiString(double src) : Data(0)
  {
    *this = Sysutils::FloatToStr(src);
  }

  __fastcall      AnsiString::~AnsiString()
  {
    asm
    {
      mov     eax,this
      call    @System@@LStrClr$qqrpv
    }
  }

  AnsiString& __fastcall AnsiString::operator=(const AnsiString&)
  {
    asm
    {
      mov     edx,[edx]
      call    @System@@LStrAsg$qqrpvpxv
    }
    return *this;
  }

  AnsiString& __fastcall AnsiString::operator+=(const AnsiString&)
  {
    asm
    {
      mov     edx,[edx]
      call    @System@@LStrCat$qqrv
    }
    return *this;
  }

  AnsiString __fastcall AnsiString::operator+(const AnsiString& rhs) const
  {
#if 0
    //!JK Per Peter S., change to push 0 onto the stack
    //!JK and use as the first parm
    //!JK need to take out double contruction (return tmp)
#endif
    AnsiString tmp;
    AnsiString* ptmp = &tmp;
    asm
    {
      mov     edx, this
      mov     edx, [edx]
      mov     eax, ptmp
      mov     ecx, rhs
      mov     ecx, [ecx]
      call    @System@@LStrCat3$qqrv
    }
    return tmp;
  }

#pragma option push -w-rvl

  bool __fastcall AnsiString::operator==(const AnsiString&) const
  {
    asm
    {
      mov     eax, [eax]
      mov     edx, [edx]
      call    @System@@LStrCmp$qqrv
      sete    al
      and     eax, 1
    }
  }

  bool __fastcall AnsiString::operator!=(const AnsiString&) const
  {
    asm
    {
      mov     eax, [eax]
      mov     edx, [edx]
      call    @System@@LStrCmp$qqrv
      setne   al
      and     eax, 1
    }
  }

  bool __fastcall AnsiString::operator<(const AnsiString&) const
  {
    asm
    {
      mov     eax, [eax]
      mov     edx, [edx]
      call    @System@@LStrCmp$qqrv
      setb    al
      and     eax, 1
    }
  }

  bool __fastcall AnsiString::operator>(const AnsiString&) const
  {
    asm
    {
      mov     eax, [eax]
      mov     edx, [edx]
      call    @System@@LStrCmp$qqrv
      seta    al
      and     eax, 1
    }
  }
#pragma option pop

  bool __fastcall AnsiString::operator<=(const AnsiString& rhs) const
  {
    return !operator>(rhs);
  }

  bool __fastcall AnsiString::operator >=(const AnsiString& rhs) const
  {
    return !operator<(rhs);
  }

  int __fastcall AnsiString::AnsiCompare(const AnsiString& rhs) const
  {
    return Sysutils::AnsiCompareStr(*this, rhs);
  }

  int __fastcall AnsiString::AnsiCompareIC(const AnsiString& rhs) const
  {
    return Sysutils::AnsiCompareText(*this, rhs);
  }


  // Return AnsiString of count chars of value ch
  AnsiString __fastcall AnsiString::StringOfChar(char ch, int count)
  {
    AnsiString tmp;
    tmp.SetLength(count);
    memset(tmp.Data, ch, count);
    return tmp;
  }

  AnsiString __fastcall AnsiString::LoadStr(int ident)
  {
    return Sysutils::LoadStr(ident);
  }

  AnsiString __fastcall AnsiString::LoadStr(HINSTANCE hInstance, int ident)
  {
    AnsiString str;
    str.LoadString(hInstance, ident);
    return str;
  }

  AnsiString& __fastcall AnsiString::LoadString(HINSTANCE hInstance, int id)
  {
    HRSRC resHdl = ::FindResource(hInstance, MAKEINTRESOURCE(id/16+1), RT_STRING);
    if (resHdl)
    {
      HGLOBAL gblHdl = ::LoadResource(hInstance, resHdl);
      if (gblHdl)
      {
        WCHAR* resData = (WCHAR*)::LockResource(gblHdl);
        if (resData)
        {
          unsigned int len;
          for (int cnt = id % 16; len = *resData++, cnt--; resData += len)
            ;
          if (len != 0)
          {
            SetLength(len);
            len = ::WideCharToMultiByte(CP_ACP, 0, resData, len, Data, len, 0, 0);
            if (len > 0)
              Data[len] = 0;
          }
          /* Unnecessary in Win32
          ::UnlockResource(gblHdl);
          */
        }
        ::FreeResource(resHdl);
      }
    }

    return *this;
  }

  AnsiString __fastcall AnsiString::FmtLoadStr(int ident, const TVarRec* args, int size)
  {
    return Sysutils::FmtLoadStr(ident, args, size);
  }

  AnsiString __fastcall AnsiString::Format(const AnsiString& format, const TVarRec *args, int size)
  {
    return Sysutils::Format(format, args, size);
  }

  AnsiString __fastcall AnsiString::FormatFloat(const AnsiString& format, const long double& value)
  {
    return Sysutils::FormatFloat(format, value);
  }


#undef vprintf
#undef printf
#undef sprintf

  int __cdecl AnsiString::vprintf(const char* format, va_list paramList)
  {
    int size = vsnprintf(NULL, 0, format, paramList);
    SetLength(size);
    return vsnprintf(Data, size + 1, format, paramList);
  }

  int __cdecl AnsiString::cat_vprintf(const char* format, va_list paramList)
  {
    int size = vsnprintf(NULL, 0, format, paramList);
    int len = Length();
    SetLength(len + size);
    return vsnprintf(Data + len, size + 1, format, paramList);
  }


  int __cdecl AnsiString::printf(const char* format, ...)
  {
    int rc;
    va_list paramList;
    va_start(paramList, format);
    rc = vprintf(format, paramList);
    va_end(paramList);
    return rc;
  }

  AnsiString& __cdecl AnsiString::sprintf(const char* format, ...)
  {
    va_list paramList;
    va_start(paramList, format);
    vprintf(format, paramList);
    va_end(paramList);
    return *this;
  }


  int __cdecl AnsiString::cat_printf(const char* format, ...)
  {
    int rc;
    va_list paramList;
    va_start(paramList, format);
    rc = cat_vprintf(format, paramList);
    va_end(paramList);
    return rc;
  }

  AnsiString& __cdecl AnsiString::cat_sprintf(const char* format, ...)
  {
    va_list paramList;
    va_start(paramList, format);
    cat_vprintf(format, paramList);
    va_end(paramList);
    return *this;
  }


  AnsiString __fastcall AnsiString::FloatToStrF(long double value, TStringFloatFormat format, int precision, int digits)
  {
#if 0
    //!JK this code requires TStringFloatFormat and TFloatFormat to be identical
#endif
    return Sysutils::FloatToStrF(value, TFloatFormat(format), precision, digits);
  }

  AnsiString __fastcall AnsiString::IntToHex(int value, int digits)
  {
    return Sysutils::IntToHex(value, digits);
  }

  AnsiString __fastcall AnsiString::CurrToStr(Currency value)
  {
    return ::CurrToStr(value);
  }

  AnsiString __fastcall AnsiString::CurrToStrF(Currency value, TStringFloatFormat format, int digits)
  {
#if 0
    //!JK this code requires TStringFloatFormat and TFloatFormat to be identical
#endif
    return Sysutils::CurrToStrF(value, TFloatFormat(format), digits);
  }

  int __fastcall AnsiString::WideCharBufSize() const
  {
    // return size of buffer required to call WideChar()
    return MultiByteToWideChar(CP_ACP,0,(Data)? Data: (const PChar)"", -1, 0,0);
  }

  //Convert to Unicode
  wchar_t* __fastcall AnsiString::WideChar(wchar_t* dest, int destSize) const
  {
    MultiByteToWideChar(CP_ACP,0,(Data)?Data: (const PChar)"",-1,dest,destSize);
    return dest;
  }

  AnsiString& __fastcall AnsiString::Unique()
  {
    System::UniqueString(*this);
    return *this;
  }

  AnsiString& __fastcall AnsiString::Insert(const String& source, int index)
  {
    asm
    {
      // edx must be a pointer to the characters
      mov     edx, this
      // eax must be the characters themselves
      mov     eax, source
      mov     eax, [eax]
      mov     ecx, index
      call    @System@@LStrInsert$qqrv
    }
    return *this;
  }

  AnsiString& __fastcall AnsiString::Delete(int index, int count)
  {
    asm
    {
      // eax must be a pointer to the characters
      mov     eax, this
      mov     edx, index
      mov     ecx, count
      call    @System@@LStrDelete$qqrv
    }
    return *this;
  }

  AnsiString& __fastcall AnsiString::SetLength(int newLength)
  {
    asm
    {
      //  eax must be a pointer to the characters
      mov     eax, this
      mov     edx, newLength
      call    @System@@LStrSetLength$qqrv
    }
    return *this;
  }

  int __fastcall AnsiString::Pos(const AnsiString& subStr) const
  {
    asm
    {
      // edx must be the characters themselves
      mov     edx, this
      mov     edx, [edx]
      // eax must be the characters themselves!
      mov     eax, subStr
      mov     eax, [eax]
      call    @System@@LStrPos$qqrv
      //Result left in eax
    }
    return _EAX;
  }

  AnsiString __fastcall AnsiString::LowerCase() const
  {
    return Sysutils::AnsiLowerCase(*this);
  }

  AnsiString __fastcall AnsiString::UpperCase() const
  {
    return Sysutils::AnsiUpperCase(*this);
  }

  AnsiString __fastcall AnsiString::Trim() const
  {
    return Sysutils::Trim(*this);
  }

  AnsiString __fastcall AnsiString::TrimLeft() const
  {
    return Sysutils::TrimLeft(*this);
  }

  AnsiString __fastcall AnsiString::TrimRight() const
  {
    return Sysutils::TrimRight(*this);
  }

  AnsiString __fastcall AnsiString::SubString(int index, int count) const
  {
    // This method is intended to be compatible with Delphi's Copy().
    // Be careful when reordering parameter validation to maintain the
    // semantics!
    const int len = Length();
	if (index > len || count < 1)
      return AnsiString();
	if (index < 1)
      index = 1;
    int n = len - index + 1;
    if (n > count)
      n = count;
    return AnsiString(Data + index - 1, n);
  }

  int __fastcall AnsiString::ToInt() const
  {
    return Sysutils::StrToInt(*this);
  }

  int __fastcall AnsiString::ToIntDef(int defaultValue) const
  {
    return Sysutils::StrToIntDef(*this, defaultValue);
  }

  double __fastcall AnsiString::ToDouble() const
  {
#if 0
    //!JK change this to return a long double when the compiler properly
    //!JK promotes/demotes long doubles/doubles
#endif
    return Sysutils::StrToFloat(*this);
  }

  bool __fastcall AnsiString::IsDelimiter(const AnsiString& delimiters, int index) const
  {
    return Sysutils::IsDelimiter(delimiters, *this, index);
  }

  int __fastcall AnsiString::AnsiPos(const AnsiString& subStr) const
  {
    return Sysutils::AnsiPos(subStr, *this);
  }

  bool __fastcall AnsiString::IsPathDelimiter(int index) const
  {
    return Sysutils::IsPathDelimiter(*this, index);
  }

  int __fastcall AnsiString::LastDelimiter(const AnsiString& delimiters) const
  {
    return Sysutils::LastDelimiter(delimiters, *this);
  }

  AnsiString::TStringMbcsByteType __fastcall AnsiString::ByteType(int index) const
  {
    //!GCD this code requires TStringMbcsByteType and TMbcsByteType to be identical
    return TStringMbcsByteType(Sysutils::ByteType(*this, index));
  }

  bool __fastcall AnsiString::IsLeadByte(int index) const
  {
    return ByteType(index) == mbLeadByte;
  }

  bool __fastcall AnsiString::IsTrailByte(int index) const
  {
    return ByteType(index) == mbTrailByte;
  }

  char* __fastcall AnsiString::AnsiLastChar() const
  {
    return Sysutils::AnsiLastChar(*this);
  }

  AnsiString __fastcall operator+(const char* lhs, const AnsiString& rhs)
  {
    AnsiString tmp(lhs);
    AnsiString* ptmp = &tmp;
    asm
    {
      mov     eax,ptmp
      mov     edx,rhs
      mov     edx,[edx]
      call    @System@@LStrCat$qqrv
    }
    return tmp;
  }


} // System Namespace
