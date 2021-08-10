//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
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

#if defined(BI_NAMESPACE)
namespace OWL {
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

#if defined(BI_PLAT_WIN32)
    TTimeGadget(TGetTimeFunc timeFunc = &TTimeGadget::GetSystemTime,
#else
    TTimeGadget(TGetTimeFunc timeFunc = &TTimeGadget::GetTTime,
#endif
                int id = 0,
                TBorderStyle = Recessed,
                TAlign = Center,
                uint numChars = 12,
                const char* text = 0,
                TFont* font = 0 /*new TGadgetWindowFont*/);

    // Override from TGadget
    //
    void  Created();
    bool  IdleAction(long count);

    static void GetTTime(string&);
#if defined(BI_PLAT_WIN32)
    static void GetSystemTime(string&);
    static void GetLocalTime(string&);
#endif

  private:
    TGetTimeFunc TimeFunc;
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

#endif  // OWL_TIMEGADG_H
