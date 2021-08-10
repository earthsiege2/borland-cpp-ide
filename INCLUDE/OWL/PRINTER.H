//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(OWL_PRINTER_H)
#define OWL_PRINTER_H

#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_PRINTDIA_H)
# include <owl/printdia.h>
#endif
#include <owl/printer.rh>
class _OWLCLASS TPrintDC;

//
//  class TPrinterAbortDlg
//  ----- ----------------
//
class _OWLCLASS TPrinterAbortDlg : public TDialog {
  public:
    TPrinterAbortDlg(TWindow* parent, TResId resId, const char far* title,
                     const char far* device, const char far* port,
                     HDC prnDC = HDC(-1));

  protected:
    void     SetupWindow();
    void     CmCancel();

    HDC      PrnDC;

  DECLARE_RESPONSE_TABLE(TPrinterAbortDlg);
};

//
// TPrintout banding flags
//
enum TPrintoutFlags {
  pfGraphics = 0x01,     // Current band accepts graphics
  pfText     = 0x02,     // Current band accepts text
  pfBoth     = (pfGraphics|pfText)
};

//
//  class TPrintout
//  ----- ---------
//
// TPrintout represents the physical printed document which is to
// sent to a printer to be printed. TPrintout does the rendering of
// the document onto the printer. For every document, or document
// type, a corresponding TPrintout class should be created.
//
class _OWLCLASS TPrintout : public TStreamableBase {
  public:
    TPrintout(const char far* title);
    virtual ~TPrintout();

    virtual void SetPrintParams(TPrintDC* dc, TSize pageSize);
    virtual void GetDialogInfo(int& minPage,     int& maxPage,
                               int& selFromPage, int& selToPage);
    virtual void BeginPrinting();
    virtual void BeginDocument(int startPage, int endPage, unsigned flags);
    virtual bool HasPage(int pageNumber);
    virtual void PrintPage(int page, TRect& rect, unsigned flags);
    virtual void EndDocument();
    virtual void EndPrinting();

    const char far* GetTitle() const {return Title;}
    bool            WantBanding() const {return Banding;}
    bool            WantForceAllBands() const {return ForceAllBands;}

    TPrintDC*       GetPrintDC() {return DC;}

  protected:
    char far* Title;
    bool      Banding;
    bool      ForceAllBands;
    TPrintDC* DC;
    TSize     PageSize;

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TPrintout(const TPrintout&);
    TPrintout& operator =(const TPrintout&);

  DECLARE_STREAMABLE(_OWLCLASS, TPrintout, 1);
};

//
//  class TPrinter
//  ----- --------
//
// TPrinter represent the physical printer device.  To print a
// TPrintout, send the TPrintout to the TPrinter's Print function.
//
class _OWLCLASS TPrinter: public TStreamableBase {
  public:
    class _OWLCLASS_RTL TXPrinter : public TXOwl {
      public:
        TXPrinter(uint resId = IDS_PRINTERERROR);
    };
    TPrinter(TApplication* app = 0);
    virtual ~TPrinter();

    virtual void ClearDevice();
    virtual void Setup(TWindow* parent);
    virtual bool Print(TWindow* parent, TPrintout& printout, bool prompt);
    virtual void ReportError(TWindow* parent, TPrintout& printout);

    TPrintDialog::TData& GetSetup() {return *Data;}

    static void  SetUserAbort(HDC abortDC = HDC(-1)) {UserAbortDC = abortDC;}
    static HDC   GetUserAbort() {return UserAbortDC;}

  protected:
    int                  Error;          // < 0 if error occurred during print
    TPrintDialog::TData* Data;           // Printer setup information
    TApplication*        Application;    // The app owning this printer object

    virtual void GetDefaultPrinter();
    virtual void SetPrinter(const char* driver, const char* device,
                            const char* output);

    virtual bool     ExecPrintDialog(TWindow* parent);
    virtual TWindow* CreateAbortWindow(TWindow* parent, TPrintout& printout);

    //
    // Helper function used by Print
    //
    void         CalcBandingFlags(TPrintDC& prnDC);
    
    //
    // Variables used by CalcBandingFlags and Print
    //
    bool     UseBandInfo;
    unsigned Flags;
    bool     FirstBand;
    TRect    BandRect;
    TSize    PageSize;

  private:
    static HDC UserAbortDC;   // Set by print dialog to prntDC if user cancels
                              // Set to -1 cancels all print jobs

    //
    // hidden to prevent accidental copying or assignment
    //
    TPrinter(const TPrinter&);
    TPrinter& operator =(const TPrinter&);

  DECLARE_STREAMABLE(_OWLCLASS, TPrinter, 1);
};

#endif  // OWL_PRINTER_H
