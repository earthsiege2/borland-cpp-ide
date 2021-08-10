//----------------------------------------------------------------------------
//  Project ApxSdi
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    ApxSdi Application
//  FILE:         apxprint.h
//  AUTHOR:
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxPrintout (TPrintout).
//
//----------------------------------------------------------------------------
#if !defined(apxprint_h)  // Sentry use file only if it's not already included.
#define apxprint_h

#include <owl/printer.h>


class TApxPrintout : public TPrintout {
  public:
    TApxPrintout(TPrinter* printer, const char far* title, TWindow* window, bool scale = true)
      : TPrintout(title)
      {
        Printer = printer;
        Window = window;
        Scale = scale;
        MapMode = MM_ANISOTROPIC;
        TotalPages = INT_MAX;
      }

    void GetDialogInfo(int& minPage, int& maxPage, int& selFromPage, int& selToPage);
    void BeginPage(TRect& clientR);
    void PrintPage(int page, TRect& rect, unsigned flags);
    void EndPage();
    void SetBanding(bool b)        { Banding = b; }
    bool HasPage(int pageNumber);

  protected:
    TWindow*  Window;
    bool      Scale;
    TPrinter* Printer;
    int       MapMode;

    int       PrevMode;
    TSize     OldVExt, OldWExt;
    TRect     OrgR;
    int       TotalPages; 
};

#endif  // apxprint_h
