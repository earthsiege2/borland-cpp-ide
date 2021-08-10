//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.2  $
//
// Definition of class TTimeGadget
//----------------------------------------------------------------------------
#if !defined(OWL_TIMEGADG_H)
#define OWL_TIMEGADG_H

#if !defined(OWL_TEXTGADG_H)
# include <owl/textgadg.h>
#endif
#if !defined(CLASSLIB_TIME_H)
# include <classlib/time.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TTimeGadget
// ~~~~~ ~~~~~~~~~~~
// A gadget for displaying a time and/or date message.
//
class _OWLCLASS TTimeGadget : public TTextGadget {
  public:
    typedef void _CALLCNVN (*TGetTimeFunc)(string&);
    TTimeGadget(TGetTimeFunc timeFunc = &TTimeGadget::GetTTime, int id = 0,
                TBorderStyle = Recessed, TAlign = Center,
                uint numChars = 12, const char* text = 0,
                TFont* font = new TGadgetWindowFont);

    // Override from TGadget
    //
    bool  IdleAction(long count);

    static void GetTTime(string&);
#if defined(BI_PLAT_WIN32)
    static void GetSystemTime(string&);
#endif

  private:
    TGetTimeFunc TimeFunc;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#endif  // OWL_TIMEGADG_H
