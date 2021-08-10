//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of Print and PrintSetup common Dialogs classes
//----------------------------------------------------------------------------
#if !defined(OWL_PRINTDIA_H)
#define OWL_PRINTDIA_H

#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TPrintDialog
// ~~~~~ ~~~~~~~~~~~~
class _OWLCLASS TPrintDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        uint32          Flags;
        uint32          Error;
        int             FromPage;
        int             ToPage;
        int             MinPage;
        int             MaxPage;
        int             Copies;

#if defined(BI_PLAT_WIN32)  
        uint32          PageSetupFlags;    // Additional page setup dialog flags
        TPoint          PaperSize;         // Size of the paper user has chosen
        TRect           MinMargin;         // Minimum allowable margins of the paper
        TRect           Margin;            // Initial margins for the paper
        bool            DoPageSetup;       // Flag to do page setup?
#endif

        TData();
       ~TData();
        void                Lock();
        void                Unlock();
        void                ClearDevMode();
        const DEVMODE far*  GetDevMode() const;
        void                SetDevMode(const DEVMODE far* devMode);
        void                ClearDevNames();
        const DEVNAMES far* GetDevNames() const;
        const char far*     GetDriverName() const;
        const char far*     GetDeviceName() const;
        const char far*     GetOutputName() const;
        void                SetDevNames(const char far* driver,
                                        const char far* device,
                                        const char far* output);
        TPrintDC*           TransferDC();

        void*               Read(ipstream& is, uint32 version);
        void                Write(opstream& os);

      private:
        HGLOBAL       HDevMode;
        HGLOBAL       HDevNames;
        HDC           HDc;

        DEVMODE far*  DevMode;
        DEVNAMES far* DevNames;

        TData(const TData&);         // hidden to prevent copying & assignment
        TData& operator =(const TData&);

      friend class TPrintDialog;
    };

    TPrintDialog(TWindow*        parent,
                 TData&          data,
                 const char far* printTemplateName = 0,
                 const char far* setupTemplateName = 0,
                 const char far* title = 0,
                 TModule*        module = 0);

    bool       GetDefaultPrinter();

    int        DoExecute();

  protected:
    bool    DialogFunction(uint message, TParam1, TParam2);

    // Default behavior inline for message response functions
    //
    void       CmSetup(); //EV_COMMAND(psh1,

    PRINTDLG&  GetPD();
    void       SetPD(const PRINTDLG& _pd);

    TData&     GetData();
    void       SetData(const TData& data);

  protected_data:
    union {
      PRINTDLG     pd;  // old name
      PRINTDLG     Pd;  // new name
    };
#if defined(BI_PLAT_WIN32)
    PAGESETUPDLG   Psd;
#endif
    TData&         Data;

  private:
    TPrintDialog(const TPrintDialog&);
    TPrintDialog& operator=(const TPrintDialog&);

  DECLARE_RESPONSE_TABLE(TPrintDialog);
  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

// ---------------------------------------------------------------------------
// Inline implementation
//
//

//
// Return the DEVMODE structure used by the dialog.
//
inline const DEVMODE far*  TPrintDialog::TData::GetDevMode() const {
  return DevMode;
}

//
// Return the DEVNAMES structure used by the dialog.
//
inline const DEVNAMES far* TPrintDialog::TData::GetDevNames() const {
  return DevNames;
}

//
// Default processing.
//
inline void TPrintDialog::CmSetup() {
  DefaultProcessing();
}

//
// Return the PRINTDLG structure used by the dialog.
//
inline PRINTDLG& TPrintDialog::GetPD() {
  return pd;
}

//
// Set the PRINTDLG structure used by the dialog.
//
inline void TPrintDialog::SetPD(const PRINTDLG& _pd) {
  pd = _pd;
}

//
// Return the transfer data of the dialog.
//
inline TPrintDialog::TData& TPrintDialog::GetData() {
  return Data;
}

//
// Set the transfer data of the dialog.
//
inline void TPrintDialog::SetData(const TData& data) {
  Data = data;
}

#endif  // OWL_PRINTDIA_H
