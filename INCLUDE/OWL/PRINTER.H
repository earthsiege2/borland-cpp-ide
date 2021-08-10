//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
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

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TPrintDC;

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TPrinterAbortDlg
// ~~~~~ ~~~~~~~~~~~~~~~~
class _OWLCLASS TPrinterAbortDlg : public TDialog {
  public:
    TPrinterAbortDlg(TWindow* parent, TResId resId, const char far* title,
                     const char far* device, const char far* port,
                     HDC prnDC = HDC(-1));

  protected:
    void     SetupWindow();
    void     CmCancel();

    HDC      PrnDC;              // Device context to print on

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
// class TPrintout
// ~~~~~ ~~~~~~~~~
// TPrintout represents the physical printed document which is to sent to a
// printer to be printed. TPrintout does the rendering of the document onto the
// printer. For every document, or document type, a corresponding TPrintout
// class should be created.
//
class _OWLCLASS TPrintout : public TStreamableBase {
  public:
    TPrintout(const char far* title);
    virtual ~TPrintout();

    virtual void    SetPrintParams(TPrintDC* dc, TSize pageSize);
    virtual void    GetDialogInfo(int& minPage,     int& maxPage,
                                  int& selFromPage, int& selToPage);
    virtual void    BeginPrinting();
    virtual void    BeginDocument(int startPage, int endPage, uint flags);
    virtual bool    HasPage(int pageNumber);
    virtual void    PrintPage(int page, TRect& rect, uint flags);
    virtual void    EndDocument();
    virtual void    EndPrinting();

    // Accessors to data members of printout object
    //
    TSize           GetPageSize() const;
    const char far* GetTitle() const;
    bool            WantBanding() const;
    void            SetBanding(bool banding=true);
    bool            WantForceAllBands() const;
    void            SetForceAllBands(bool force=true);
    TPrintDC*       GetPrintDC();

  protected:
    void            SetTitle(const char far* title);
    void            SetPrintDC(TPrintDC* dc);
    void            SetPageSize(const TSize& pagesize);

  protected_data:
    char far*       Title;         // The title of this printout.
    bool            Banding;       // Whether to use banding if available
    bool            ForceAllBands; // Flag to work around some printers
    TPrintDC*       DC;            // Ptr to DC create&owned by our TPrinter
    TSize           PageSize;      // Dimensions of the printout page

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TPrintout(const TPrintout&);
    TPrintout& operator =(const TPrintout&);

  DECLARE_STREAMABLE(_OWLCLASS, TPrintout, 1);
};

//
// class TPrinter
// ~~~~~ ~~~~~~~~
// TPrinter represent the physical printer device.  To print a TPrintout,
// send the TPrintout to the TPrinter's Print function.
//
class _OWLCLASS TPrinter: public TStreamableBase {
  public:
    TPrinter(TApplication* app = 0);
    virtual ~TPrinter();

    virtual void     ClearDevice();
    virtual void     Setup(TWindow* parent);
    virtual bool     Print(TWindow* parent, TPrintout& printout, bool prompt);
    virtual void     ReportError(TWindow* parent, TPrintout& printout);

    TPrintDialog::TData& GetSetup();

    static void      SetUserAbort(HDC abortDC = HDC(-1));
    static HDC       GetUserAbort();

    // Accessors to protected state data
    //
    int              GetError();
    void             SetError(int error);

    TPrintDialog::TData* GetData();
    void             SetData(TPrintDialog::TData* data);

    TApplication*    GetApplication();
    void             SetApplication(TApplication* app);

    bool             GetUseBandInfo() const;
    void             SetUseBandInfo(bool usebandinfo);

    uint             GetFlags() const;
    void             SetFlags(uint flags);

    bool             GetFirstBand() const;
    void             SetFirstBand(bool firstband);

    TRect            GetBandRect() const;
    void             SetBandRect(const TRect& bandrect);

    TSize            GetPageSize() const;
    void             SetPageSize(const TSize& pagesize);
    TSize            GetPageSizeInch() const;
    void             SetPageSizeInch(const TSize& pageSizeInch);

    virtual void     SetPageSizes(const TPrintDC& dc);

  protected:
    virtual void     GetDefaultPrinter();
    virtual void     SetPrinter(const char* driver, const char* device,
                                const char* output);

    virtual bool     ExecPrintDialog(TWindow* parent);
    virtual bool     ExecPageSetupDialog(TWindow* parent);
    virtual TWindow* CreateAbortWindow(TWindow* parent, TPrintout& printout);

    // Helper function used by Print
    //
    void             CalcBandingFlags(TPrintDC& prnDC);


  protected_data:
    int                  Error;       // < 0 if error occurred during print
    TPrintDialog::TData* Data;        // Printer setup information
    TApplication*        Application; // The app owning this printer object

    // Variables used by CalcBandingFlags and Print
    //
    bool             UseBandInfo;     // whether to use banding or not
    uint             Flags;           // type of printout
    bool             FirstBand;       // first band?
    TRect            BandRect;        // rectangle size of the band
    TSize            PageSize;        // size of the page
    TSize            PageSizeInch;    // size of an inch on the page

  private:
    static HDC UserAbortDC;   // Set by print dialog to prntDC if user cancels
                              // Set to -1 cancels all print jobs

    // Hidden to prevent accidental copying or assignment
    //
    TPrinter(const TPrinter&);
    TPrinter& operator =(const TPrinter&);

  DECLARE_STREAMABLE(_OWLCLASS, TPrinter, 2);
};

//
// class TXPrinter
// ~~~~~ ~~~~~~~~~
// Printer and printout related exceptions
//
class _OWLCLASS_RTL TXPrinter : public TXOwl {
  public:
    TXPrinter(uint resId = IDS_PRINTERERROR);

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXPrinter* Clone();
#endif
    void Throw();

    static void Raise(uint resId = IDS_PRINTERERROR);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implmentation
//

//
// Return the title of the printout.
//
inline const char far* TPrintout::GetTitle() const {
  return Title;
}

//
// Return true if banding is desired.
//
inline bool TPrintout::WantBanding() const {
  return Banding;
}

//
// Return true if the force all bands.
//
inline bool TPrintout::WantForceAllBands() const {
  return ForceAllBands;
}

//
// Return the DC associated with the printout.
//
inline TPrintDC* TPrintout::GetPrintDC() {
  return DC;
}

//
// Set the banding flag for the printout.
//
inline void TPrintout::SetBanding(bool banding) {
  Banding = banding;
}

//
// Set the force banding flag.
//
inline void TPrintout::SetForceAllBands(bool force) {
  ForceAllBands = force;
}

//
// Set the associated DC.
//
inline void TPrintout::SetPrintDC(TPrintDC* dc) {
  DC = dc;
}

//
// Retrieve the size of the page.
//
inline TSize TPrintout::GetPageSize() const {
  return PageSize;
}

//
// Set the size of the page.
//
inline void TPrintout::SetPageSize(const TSize& pagesize) {
  PageSize = pagesize;
}

//
// Return the setup data associated for the printer.
//
inline TPrintDialog::TData& TPrinter::GetSetup() {
  return *Data;
}

//
// Set the user abort DC for the printer.
//
inline void TPrinter::SetUserAbort(HDC abortDC) {
  UserAbortDC = abortDC;
}

//
// Return the abort DC.
//
inline HDC TPrinter::GetUserAbort() {
  return UserAbortDC;
}

//
// Return the error code from the printer.
//
inline int TPrinter::GetError() {
  return Error;
}

//
// Set the error code.
//
inline void TPrinter::SetError(int error) {
  Error = error;
}

//
// Return the common dialog data associated with the printer.
//
inline TPrintDialog::TData* TPrinter::GetData() {
  return Data;
}

//
// Set the common dialog data.
//
inline void TPrinter::SetData(TPrintDialog::TData* data) {
  Data = data;
}

//
// Return the application pointer.
//
inline TApplication* TPrinter::GetApplication() {
  return Application;
}

//
// Set the application pointer.
//
inline void TPrinter::SetApplication(TApplication* app) {
  Application = app;
}

//
// Return true if to use banding information.
//
inline bool TPrinter::GetUseBandInfo() const {
  return UseBandInfo;
}

//
// Set the flag indicating whether to use banding information.
//
inline void TPrinter::SetUseBandInfo(bool usebandinfo) {
  UseBandInfo = usebandinfo;
}

//
// Return the printer flags.
//
inline uint TPrinter::GetFlags() const {
  return Flags;
}

//
// Set the flags for the printer.
//
inline void TPrinter::SetFlags(uint flags) {
  Flags = flags;
}

//
// Return true if currently printing the first band.
//
inline bool TPrinter::GetFirstBand() const {
  return FirstBand;
}

//
// Set the flag for first band.
//
inline void TPrinter::SetFirstBand(bool firstband) {
  FirstBand = firstband;
}

//
// Return the rectangle for the current band.
//
inline TRect TPrinter::GetBandRect() const {
  return BandRect;
}

//
// Set the rectangle for the band.
//
inline void TPrinter::SetBandRect(const TRect& bandrect) {
  BandRect = bandrect;
}

//
// Return the size of the page.
//
inline TSize TPrinter::GetPageSize() const {
  return PageSize;
}

//
// Set the page's size.
//
inline void TPrinter::SetPageSize(const TSize& pagesize) {
  PageSize = pagesize;
}

//
// Return the size of an inch the page.
//
inline TSize TPrinter::GetPageSizeInch() const {
  return PageSizeInch;
}

//
// Set the size of an inch on the page.
//
inline void TPrinter::SetPageSizeInch(const TSize& pageSizeInch) {
  PageSizeInch = pageSizeInch;
}

#endif  // OWL_PRINTER_H
