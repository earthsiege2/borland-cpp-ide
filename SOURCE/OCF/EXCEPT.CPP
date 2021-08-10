//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.3  $
//
// OLE Exception classes
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#if !defined(OCF_DEFS_H)
# include <ocf/defs.h>
#endif
#if !defined(OCF_OLEUTIL_H)
# include <ocf/oleutil.h>
#endif
#if !defined(WINSYS_STRING_H)
# include <winsys/string.h>
#endif
#if !defined(SERVICES_MEMORY_H)
# include <services/memory.h>
#endif


// DLL which can provide a string for a give OLE error code
//
#if defined(BI_PLAT_WIN16)
const char OleErrorStringsDLL[] = "OLE_ERR.DLL";
#else
const char OleErrorStringsDLL[] = "OLE_ERRF.DLL";
#endif


//
//
//
TXOle::~TXOle()
{
}

//
//
//
TXOle*
TXOle::Clone()
{
  return new TXOle(*this);
}

//
//
//
void
TXOle::Throw()
{
  THROW( *this );
}

//
//
//
void
TXOle::Check(HRESULT hr, const char far* msg)
{
  if (FAILED(hr))
    Throw(hr, msg);
}

//
//
//
void
TXOle::Check(HRESULT hr)
{
  Check(hr, 0);
}

//
//
//
void
TXOle::Throw(HRESULT hr, const char far* msg)
{
  if (!InstanceCount) {
    char buf[128+1];
    wsprintf(buf, "%s failed, ", msg ? msg : "OLE call");

    int len = strlen(buf);
    OleErrorFromCode(hr, buf + len, sizeof(buf) - len - 2);
    strcat(buf, ".");

    WARN(hr != HR_NOERROR, buf);
    throw TXOle(buf, hr);
  }
}

//
// If OLE-Error-String DLL exists, & msg string is there, then use
// it. Otherwise just use the number.
//
void
TXOle::OleErrorFromCode(HRESULT stat, char far* buffer, int size)
{
  const   char HResultToStringIDFunc[] = "StringIDFromHResult";
  typedef int _export CALLBACK (*TStringIDFromHResult)(HRESULT hr);

  int len = 0;
  OFSTRUCT ofs;
  if (OpenFile(OleErrorStringsDLL, &ofs, OF_EXIST) != HFILE_ERROR) {
    HINSTANCE hInst = LoadLibrary(OleErrorStringsDLL);
    if (hInst > (HINSTANCE)HINSTANCE_ERROR) {
      TStringIDFromHResult func =
          (TStringIDFromHResult)GetProcAddress(hInst, HResultToStringIDFunc);
      if (func) {
        int id = func(stat);
        if (id)
          len = ::LoadString(hInst, id, buffer, size);
      }
      FreeLibrary(hInst);
    }
  }
  if (!len) {
    char numBuf[25];
    wsprintf(numBuf, "ErrorCode: %8lX", stat);
    strncat(buffer, numBuf, size - strlen(buffer) - 1);
  }
  buffer[size-1] = 0;
}

