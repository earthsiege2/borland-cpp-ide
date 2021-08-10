//----------------------------------------------------------------------------
##@QUERY_PRJ_NAME [[Project]]
//  Project [[Project]]
##@QUERY_PRJ_COMPANY [[CompanyName]] 2
##@QUERY_PRJ_COPYRIGHT [[Copyright]] 2
##\\Copyright Copyright 2
//  [[CompanyName]]
//  [[Copyright]]
//
##@QUERY_TARGET_NAME [[Target]]
//  SUBSYSTEM:    [[Target]] Application
//  FILE:         apxprint.h
##@QUERY_PRJ_USER [[Author]]
//  AUTHOR:       [[Author]]
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TApxPrintout (TPrintout).
//
//----------------------------------------------------------------------------
#if !defined(apxprint_h)  // Sentry use file only if it's not already included.
#define apxprint_h

#include <owl/printer.h>
#include <owl/editfile.h>


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
