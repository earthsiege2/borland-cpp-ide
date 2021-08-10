//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\printer.h
//----------------------------------------------------------------------------
#if !defined(__OWL_PRINTER_H)
#define __OWL_PRINTER_H

#if !defined(__OWL_DIALOG_H)
  #include <owl\dialog.h>
#endif
#if !defined(__OWL_PRINTDIA_H)
  #include <owl\printdia.h>
#endif
#include <owl\printer.rh>
class _OWLCLASS TPrintDC;

//
//  class TPrinterAbortDlg
//  ----- ----------------
//
class _OWLCLASS TPrinterAbortDlg : public TDialog {
  public:
    TPrinterAbortDlg(TWindow* parent, TResId resId, const char far* title,
                     const char far* device, const char far* port);

  protected:
    void     SetupWindow();
    LRESULT  EvCommand(UINT id, HWND hWndCtl, UINT notifyCode);
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
    virtual BOOL HasPage(int pageNumber);
    virtual void PrintPage(int page, TRect& rect, unsigned flags);
    virtual void EndDocument();
    virtual void EndPrinting();

    const char far* GetTitle() const {return Title;}
    BOOL            WantBanding() const {return Banding;}
    BOOL            WantForceAllBands() const {return ForceAllBands;}

  protected:
    char far* Title;
    BOOL      Banding;
    BOOL      ForceAllBands;
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
    class _OWLCLASS_RTL TXPrinter : TXOwl {
      public:
        TXPrinter(UINT resId = IDS_PRINTERERROR);
    };
    TPrinter();
    virtual ~TPrinter();

    virtual void ClearDevice();
    virtual void Setup(TWindow* parent);
    virtual BOOL Print(TWindow* parent, TPrintout& printout, BOOL prompt);
    virtual void ReportError(TWindow* parent, TPrintout& printout);

    TPrintDialog::TData& GetSetup() {return *Data;}

    static void  SetUserAbort(BOOL abort=TRUE) {UserAbort=abort;}
    static BOOL  GetUserAbort() {return UserAbort;}

  protected:
    int                  Error;          // < 0 if error occurred during print
    TPrintDialog::TData* Data;           // Printer setup information

    virtual void GetDefaultPrinter();
    virtual void SetPrinter(const char* driver, const char* device,
                            const char* output);

    virtual BOOL     ExecPrintDialog(TWindow* parent);
    virtual TWindow* CreateAbortWindow(TWindow* parent, TPrintout& printout);

    //
    // Helper function used by Print
    //
    void         CalcBandingFlags(TPrintDC& prnDC);
    
    //
    // Variables used by CalcBandingFlags and Print
    //
    BOOL     UseBandInfo;
    unsigned Flags;
    BOOL     FirstBand;
    TRect    BandRect;
    TSize    PageSize;

  private:
    static BOOL UserAbort;    // Set by printing dialog if user cancels

    //
    // hidden to prevent accidental copying or assignment
    //
    TPrinter(const TPrinter&);
    TPrinter& operator =(const TPrinter&);

  DECLARE_STREAMABLE(_OWLCLASS, TPrinter, 1);
};

#endif  // __OWL_PRINTER_H
