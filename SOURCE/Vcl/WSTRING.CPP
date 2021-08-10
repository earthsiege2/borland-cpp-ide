//  wstring.cpp - support for delphi WideString
//  $Revision:   1.7.1.0.1.1  $
//  Copyright (c) 1997, 2002 Borland Software Corporation

#pragma inline

#include <windows.hpp>
#include <sysutils.hpp>
#include <string.h>
#include <stdlib.h>
#include <wstring.h>
#include <utilcls.h>
#include <stdio.h>

#undef near
#undef printf
#undef vprintf

namespace System
{
  __fastcall WideString::WideString(const char*)
  {
    asm
    {
      extrn @System@@WStrFromPChar$qqrr17System@WideStringpc:near
      mov     eax, this
      xor     ecx,ecx
      mov     [eax], ecx    /* this->data = NULL */
      call    @System@@WStrFromPChar$qqrr17System@WideStringpc
    }
  }

  __fastcall WideString::WideString(const WideString&)
  {
    asm
    {
      extrn @System@@WStrAsg$qqrr17System@WideStringx17System@WideString:near
      mov     eax, this
      mov     edx,[edx]   /* src->data */
      xor     ecx,ecx
      mov     [eax],ecx   /* this->data = NULL */
      call    @System@@WStrAsg$qqrr17System@WideStringx17System@WideString
    }
  }

  __fastcall WideString::WideString(const AnsiString&)
  {
    asm
    {
      extrn @System@@WStrFromLStr$qqrr17System@WideStringx17System@AnsiString:near
      mov   eax, this
      xor   ecx, ecx
      mov   edx, [edx]    /* src->data */
      mov   [eax], ecx    /* this->data = NULL */
      call  @System@@WStrFromLStr$qqrr17System@WideStringx17System@AnsiString
    }
  }

  __fastcall WideString::WideString(const wchar_t*, int len)
  {
    asm
    {
      extrn @System@@WStrFromPWCharLen$qqrr17System@WideStringpbi:near
      mov   eax, this
      xor   ecx, ecx
      mov   [eax], ecx
      mov   ecx, len
      call  @System@@WStrFromPWCharLen$qqrr17System@WideStringpbi
    }
  }

  __fastcall WideString::WideString(const wchar_t*)
  {
    asm
    {
      extrn @System@@WStrFromPWChar$qqrr17System@WideStringpb:near
      mov   eax, this
      xor   ecx, ecx
      mov   [eax], ecx
      call  @System@@WStrFromPWChar$qqrr17System@WideStringpb
    }
  }

  __fastcall WideString::WideString(const wchar_t)
  {
    asm
    {
      extrn @System@@WStrFromWChar$qqrr17System@WideStringb:near
      mov   eax, this
      xor   ecx, ecx
      mov   [eax], ecx
      call  @System@@WStrFromWChar$qqrr17System@WideStringb
    }
  }


  __fastcall WideString::WideString(char src)
    : Data(0)
  {
    printf(L"%c", src);
  }

  __fastcall WideString::WideString(short src)
    : Data(0)
  {
    printf(L"%hd", src);
  }

  __fastcall WideString::WideString(unsigned short src)
    : Data(0)
  {
    printf(L"%hu", src);
  }

  __fastcall WideString::WideString(int src)
    : Data(0)
  {
    printf(L"%d", src);
  }

  __fastcall WideString::WideString(unsigned int src)
    : Data(0)
  {
    printf(L"%u", src);
  }

  __fastcall WideString::WideString(long src)
    : Data(0)
  {
    printf(L"%ld", src);
  }

  __fastcall WideString::WideString(unsigned long src)
    : Data(0)
  {
    printf(L"%lu", src);
  }

  __fastcall WideString::WideString(__int64 src)
    : Data(0)
  {
    printf(L"%Ld", src);
  }

  __fastcall WideString::WideString(unsigned __int64 src)
    : Data(0)
  {
    printf(L"%Lu", src);
  }

  __fastcall WideString::WideString(float src)
    : Data(0)
  {
    printf(L"%g", src);
  }

  __fastcall WideString::WideString(double src)
    : Data(0)
  {
    printf(L"%g", src);
  }

  __fastcall WideString::WideString(long double src)
    : Data(0)
  {
    printf(L"%Lg", src);
  }
  
  __fastcall WideString::~WideString()
  {
    asm
    {
      extrn @System@@WStrClr$qqrpv:near
      mov   eax, this
      call  @System@@WStrClr$qqrpv
    }
  }


  WideString& __fastcall WideString::operator=(const WideString&)
  {
    asm
    {
      extrn @System@@WStrAsg$qqrr17System@WideStringx17System@WideString:near
      mov   edx, [edx]
      call  @System@@WStrAsg$qqrr17System@WideStringx17System@WideString
    }
    return *this;
  }

  WideString& __fastcall WideString::operator=(BSTR src)
  {
    Empty();
    Data = src;
    return *this;
  }

  WideString& __fastcall WideString::operator=(const char* src)
  {
    *this = WideString(src).Detach();
    return *this;
  }

  WideString& __fastcall WideString::operator=(const AnsiString& src)
  {
    *this = src.c_str();
    return *this;
  }

  void __fastcall WideString::Attach(BSTR src)
  {
    // Must Detach what there before Attaching new BSTR
    //
    _ASSERTE(Data == 0);
    Data = src;
  }

  BSTR __fastcall WideString::Detach()
  {
    BSTR bstr = Data;
    Data = 0;
    return bstr;
  }

  void __fastcall WideString::Empty()
  {
    if (Data)
    {
      ::SysFreeString(Data);
      Data = 0;
    }
  }

  WideString& __fastcall WideString::operator+=(const WideString&)
  {
    asm
    {
      extrn   @System@@WStrCat$qqrr17System@WideStringx17System@WideString:near
      mov     edx,[edx]
      call    @System@@WStrCat$qqrr17System@WideStringx17System@WideString
    }
    return *this;
  }

#pragma option push -w-rvl 

  bool __fastcall WideString::operator==(const WideString& rhs) const
  {
    /* 42464
    asm
    {
      extrn @System@@WStrCmp$qqrv:near
      mov   eax, [eax]
      mov   edx, [edx]
      call  @System@@WStrCmp$qqrv
      sete  al
      movzx eax, al
    }
    */
    if (Data == rhs.Data)
      return true;
    if (!Data || !rhs.Data)
      return false;

    const wchar_t *p1 = Data, *p2 = rhs.Data;
    while ((*p1 == *p2) && *p1) {
      p1++; p2++;
    }

    return *p1 == *p2;
  }

  bool __fastcall WideString::operator!=(const WideString&) const
  {
    asm
    {
      extrn @System@@WStrCmp$qqrv:near
      mov   eax, [eax]
      mov   edx, [edx]
      call  @System@@WStrCmp$qqrv
      setne al
      movzx eax, al
    }
  }

  bool __fastcall WideString::operator<(const WideString&) const
  {
    asm
    {
      extrn @System@@WStrCmp$qqrv:near
      mov   eax, [eax]
      mov   edx, [edx]
      call  @System@@WStrCmp$qqrv
      setb  al
      movzx eax, al
    }
  }

  bool __fastcall WideString::operator>(const WideString&) const
  {
    asm
    {
      extrn @System@@WStrCmp$qqrv:near
      mov   eax, [eax]
      mov   edx, [edx]
      call  @System@@WStrCmp$qqrv
      seta  al
      movzx eax, al
    }
  }

#pragma option pop

  bool __fastcall WideString::operator<=(const WideString& rhs) const
  {
    return !operator>(rhs);
  }

  bool __fastcall WideString::operator>=(const WideString& rhs) const
  {
    return !operator<(rhs);
  }

  WideString __fastcall WideString::operator+(const WideString& rhs) const
  {
    WideString  *tmp = new WideString;
    TPtr<WideString> _t(tmp);

    asm
    {
      extrn @System@@WStrCat3$qqrr17System@WideStringx17System@WideStringt2:near
      mov   edx, this
      mov   edx, [edx]
      mov   eax, tmp
      mov   ecx, rhs
      mov   ecx, [ecx]
      call  @System@@WStrCat3$qqrr17System@WideStringx17System@WideStringt2
    }
    return *tmp;
  }

  int __fastcall WideString::Length() const
  {
    asm
    {
      extrn @System@@WStrLen$qqrx17System@WideString:near
      mov   eax, [eax]  /* this->data */
      call  @System@@WStrLen$qqrx17System@WideString
    }
    return _EAX;
  }

  bool __fastcall WideString::IsEmpty() const
  {
    return Data == 0;
  }

  void __fastcall WideString::Insert(const WideString& strn, int index)
  {
    asm
    {
      extrn @System@@WStrInsert$qqrx17System@WideStringr17System@WideStringi:near
      mov   edx, this
      mov   eax, strn
      mov   eax, [eax]
      mov   ecx, index
      call  @System@@WStrInsert$qqrx17System@WideStringr17System@WideStringi
    }
  }

  void __fastcall WideString::Delete(int index, int count)
  {
    asm
    {
      extrn @System@@WStrDelete$qqrr17System@WideStringii:near
      mov   eax, this
      mov   edx, index
      mov   ecx, count
      call  @System@@WStrDelete$qqrr17System@WideStringii
    }
  }

  void __fastcall WideString::SetLength(int newLength) // newLength: wchar_t count
  {
    asm
    {
      extrn @System@@WStrSetLength$qqrr17System@WideStringi:near
      mov   eax, this
      mov   edx, newLength
      call  @System@@WStrSetLength$qqrr17System@WideStringi
    }
  }

  int __fastcall WideString::Pos(const WideString& subStr) const
  {
    asm
    {
      extrn @System@@WStrPos$qqrv:near
      mov   edx, this
      mov   edx, [edx]
      mov   eax, subStr
      mov   eax, [eax]
      call  @System@@WStrPos$qqrv
    }
    return _EAX;
  }

  WideString __fastcall WideString::SubString(int index, int count) const
  {
    WideString *tmp = new WideString;
    TPtr<WideString> _t(tmp);
    asm
    {
      extrn   @System@@WStrCopy$qqrx17System@WideStringii:near
      mov     eax, tmp
      push    eax
      mov     ecx, count
      mov     edx, index
      mov     eax, this
      mov     eax, [eax]
      call    @System@@WStrCopy$qqrx17System@WideStringii
    }
    return *tmp;
  }

  BSTR __fastcall WideString::Copy(BSTR src)
  {
    return ::SysAllocStringLen(src, ::SysStringLen(src));
  }
  
  int __cdecl WideString::vprintf(const wchar_t* fmt, va_list ap)
  {
    int n = vsnwprintf(NULL, 0, fmt, ap);
    SetLength(n);
    return vsnwprintf(Data, n + 1, fmt, ap);
  }

  int __cdecl WideString::printf(const wchar_t *fmt, ...)
  {
    va_list ap;
    va_start(ap, fmt);
    int rc = vprintf(fmt, ap);
    va_end(ap);
    return rc;
  }


}

