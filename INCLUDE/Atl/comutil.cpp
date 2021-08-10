
/* ****************************************************************** *
 *                                                                    *
 * C++Builder implementation of COMUTIL support functions              *
 *                                                                    *
 * Note: these functions are not guaranteed to be implemented in the  *
 * same fashion as the MS RTL functions of the same name.             *
 *                                                                    *
 *                                                                    *
 * Copyright (c) 2001, 2002 Borland Software Corporation              *
 *                                                                    *
 * ****************************************************************** */

#include <comdef.h>
#include <windows.h>

namespace _com_util {

/* String utilities */

BSTR __stdcall ConvertStringToBSTR(const char* pSrc) throw (_com_error) 
{
  int size = ::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pSrc, -1, 0, 0);
  LPWSTR dst = ::SysAllocStringLen(0, size);
  size = ::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pSrc, -1, dst, size);
  if (size <= 0) _com_issue_error(E_OUTOFMEMORY);
  return dst;
}

char* __stdcall ConvertBSTRToString(BSTR pSrc) throw (_com_error) {

  int size = ::WideCharToMultiByte(CP_ACP, MB_PRECOMPOSED, pSrc, -1, 0, 0, 0, 0);
  char* dst = new char[size];
  size = ::WideCharToMultiByte(CP_ACP, 0, pSrc, -1, dst, size, 0 ,0);
  if (size <= 0) _com_issue_error(E_OUTOFMEMORY);
  return dst;
}

/* Exception Utilities */

void __stdcall _com_raise_error(HRESULT hr, IErrorInfo* perrinfo = 0) throw (_com_error) 
{
  throw _com_error(hr, perrinfo);
}

void __stdcall _com_issue_error(HRESULT hr) throw(_com_error)
{

  throw _com_error(hr);
}

void _stdcall _com_issue_errorex(HRESULT hr, IUnknown*, REFIID) throw(_com_error){

  /* what's the right thing to do here? probably *not* what we're doing, but
     without a test case ...  Can someone who is using this please send email
     to rwest@borland.com explaining *how* it's being used and what you want
     from it? :) */

  throw _com_error(hr);
}

}
