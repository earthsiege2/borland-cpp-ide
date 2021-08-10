//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\printdia.cpp
//   Implementation of Print and PrintSetup common Dialogs
//   classes
//----------------------------------------------------------------------------
#if !defined(__OWL_PRINTDIA_H)
#define __OWL_PRINTDIA_H

#if !defined(__COMMDIAL_H)
  #include <owl\commdial.h>
#endif
#if !defined(__DC_H)
  #include <owl\dc.h>
#endif

class _OWLCLASS TPrintDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        DWORD           Flags;
        DWORD           Error;
        int             FromPage;
        int             ToPage;
        int             MinPage;
        int             MaxPage;
        int             Copies;

        TData();
       ~TData();
        void                Lock();
        void                Unlock();
        void                ClearDevMode();
        const DEVMODE far*  GetDevMode() const {return DevMode;}
        void                SetDevMode(const DEVMODE far* devMode);
        void                ClearDevNames();
        const DEVNAMES far* GetDevNames() const {return DevNames;}
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
        HGLOBAL       hDevMode;
        HGLOBAL       hDevNames;
        HDC           hDC;

        DEVMODE far*  DevMode;
        DEVNAMES far* DevNames;

      friend class TPrintDialog;
    };

    TPrintDialog(TWindow*        parent,
                 TData&          data,
                 const char far* printTemplateName = 0,
                 const char far* setupTemplateName = 0,
                 const char far* title = 0,
                 TModule*        module = 0);
               
    BOOL       GetDefaultPrinter();

    int        DoExecute();

  protected:
    PRINTDLG   pd;
    TData&     Data;

    BOOL    DialogFunction(UINT message, WPARAM, LPARAM);

    // Default behavior inline for message response functions
    //
    void       CmSetup() {DefaultProcessing();} //EV_COMMAND(psh1, 

  private:
    TPrintDialog(const TPrintDialog&);
    TPrintDialog& operator=(const TPrintDialog&);

  DECLARE_RESPONSE_TABLE(TPrintDialog);
  DECLARE_CASTABLE;
};

#endif  // __OWL_PRINTDIA_H
