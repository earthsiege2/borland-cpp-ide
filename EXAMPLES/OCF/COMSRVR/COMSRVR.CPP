//----------------------------------------------------------------------------
// ObjectComponents - (c) Copyright 1994, 1996 by Borland International
//
// $Revision:   2.1  $
//----------------------------------------------------------------------------
#include <ocf/ocfpch.h>
#if !defined(OCF_OCREG_H)
# include <ocf/ocreg.h>
#endif
#if !defined(OCF_OLEUTIL_H)
# include <ocf/oleutil.h>
#endif
#include <windowsx.h>
#include <initguid.h>

#if defined(BI_COMP_BORLANDC)
# pragma hdrstop
#endif

#include "comintf.h"

// Registrar pointer to handle registration chores
//
TPointer<TRegistrar>    Registrar;

// String to hold command line
//
TPointer<string>        CmdLine;

// Class Object registration information
//
BEGIN_REGISTRATION(ObjectReg)
  REGDATA(clsid,       "{6034C8E0-C35B-101B-AFFC-00608C19FAA0}" )
  REGDATA(description, "Sample OCF Object with COM Interfaces")
  REGDATA(progid,      "CUSTOM.OBJECT.1")
END_REGISTRATION

// Declare new class derived from interface with TUnknown mixin
//
DECLARE_COMBASES2(TUtilObjectCom, IShape, ICalendar);

// Declare class derived from mixin which implements interface members
//
class _ICLASS TUtilObject : public TUtilObjectCom {

  public:
    TUtilObject();
   ~TUtilObject();

    // { C++ methods implementing interfaces }

    // IShape methods
    //
    BOOL _IFUNC Rectangle(HDC, int left, int top,
                          int right, int bottom,
                          COLORREF fill);
    BOOL _IFUNC  Ellipse(HDC, int left, int top, int right, int bottom,
                         COLORREF fill);

    // ICalendar methods
    //
    int _IFUNC   GetDayOf(int year, int month, int date);
};

// Declare ClsName##QueryInterface inline
//
DEFINE_QI_BASE(IShape,    IID_IShape.Data1);
DEFINE_QI_BASE(ICalendar, IID_ICalendar.Data1);


// Define class which inherits from our interfaces and
// TUnknown as a mixin class.
//
DEFINE_COMBASES2(TUtilObjectCom, IShape, ICalendar);

// C++ Object constructor
//
TUtilObject::TUtilObject()
{
  // Increment ref. count of DLL since we're serving an Object
  //
  Registrar->GetAppDescriptor().LockServer(TRUE);
}

// C++ Object destructor
//
TUtilObject::~TUtilObject()
{
  // Decrement ref. count of DLL
  //
  Registrar->GetAppDescriptor().LockServer(FALSE);
}

//
//
//
BOOL _IFUNC
TUtilObject::Rectangle(HDC dc, int left, int top, int right, int bottom,
                       COLORREF fill)
{
  HBRUSH oldBrush = SelectBrush(dc, CreateSolidBrush(fill));
  BOOL result = ::Rectangle(dc, left, top, right, bottom);
  DeleteBrush(SelectBrush(dc, oldBrush));
  return result;
}

//
//
//
BOOL _IFUNC
TUtilObject::Ellipse(HDC dc, int left, int top, int right, int bottom,
                     COLORREF fill)
{
  HBRUSH oldBrush = SelectBrush(dc, CreateSolidBrush(fill));
  BOOL result = ::Ellipse(dc, left, top, right, bottom);
  DeleteBrush(SelectBrush(dc, oldBrush));

  return result;
}

//
// ICalendar methods implemented
//

//
// The following function determines the day of a specified date.
// The parameters passed are the month, date and year (in 4 digits -
// eg. 1989 instead of 89).  The return value indicates the day
// the of the week with:
//     Sunday=0, Monday=1 etc. etc.
//
int _IFUNC
TUtilObject::GetDayOf(int year, int month, int date)
{
  int century, day;

  century = year/100;
  year    = year%100;
  if (month < 3) {
    month += 12;
    year > 0 ? year-- : (year = 99, century--);
  }
  day = date;
  day = day + (((month+1) * 26) / 10);
  day = day + year;
  day = day + (year / 4);
  day = day + (century / 4);
  day = day - century - century;
  day = day % 7;
  if (day == 0)
      day = 7;
  return --day;
}

#if defined(BI_PLAT_WIN16)
//
// DLL's entry point
//
int FAR PASCAL
LibMain(HINSTANCE, WORD, WORD wHeapSize, LPSTR lpszCmdLine)
{
	if (wHeapSize != 0)
		UnlockData(0);

#elif defined(BI_PLAT_WIN32)

int WINAPI
DllEntryPoint(HINSTANCE hInstance, uint32 reason, LPVOID)
{
  if (reason != DLL_PROCESS_ATTACH)
    return 1;

  LPSTR lpszCmdLine = 0;
#endif

  try {
    CmdLine   = new string(lpszCmdLine);
    Registrar = new TRegistrar(::ObjectReg, TOcComFactory<TUtilObject>(),
                              *::CmdLine);
  }
  catch(xmsg &msg) {
    MessageBox(0, msg.why().c_str(), "EXCEPTION",
               MB_OK|MB_TASKMODAL);
    return 0;
  }
  return 1;
}

#if defined(BI_PLAT_WIN16)

//
// Exit routine of DLL
//
int FAR PASCAL WEP(int bSystemExit)
{
  return 1;
}

#endif


