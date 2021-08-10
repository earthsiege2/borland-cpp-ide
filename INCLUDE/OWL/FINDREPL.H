//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.3  $
//
// Definition of FindReplace- abstract, Find-, Replace- common Dialog classes
//----------------------------------------------------------------------------
#if !defined(OWL_FINDREPL_H)
#define OWL_FINDREPL_H

#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TFindReplaceDialog
// ~~~~~ ~~~~~~~~~~~~~~~~~~
class _OWLCLASS TFindReplaceDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        uint32   Flags;
        uint32   Error;
        char*    FindWhat;
        char*    ReplaceWith;
        int      BuffSize;

        TData(uint32 flags = 0, int buffSize = 81);
        TData(const TData& src);
       ~TData();

        TData& operator =(const TData& src);

        void     Write(opstream& os);
        void     Read(ipstream& is);
    };

    TFindReplaceDialog(TWindow*        parent,
                       TData&          data,
                       TResId          templateId = 0,
                       const char far* title = 0,
                       TModule*        module = 0);

    void         UpdateData(TParam2 param = 0);

  protected:
    HWND         DoCreate() = 0;

    TFindReplaceDialog(TWindow*        parent,
                       TResId          templateId = 0,
                       const char far* title = 0,
                       TModule*        module = 0);

    void     Init(TResId templateId);
    bool     DialogFunction(uint message, TParam1, TParam2);

    TData&   GetData();
    void     SetData(TData& data);

    FINDREPLACE&  GetFR();
    void   SetFR(const FINDREPLACE& _fr);

    // Default behavior inline for message response functions
    //
    void     CmFindNext();   //EV_COMMAND(IDOK,
    void     CmReplace();    //EV_COMMAND(psh1,
    void     CmReplaceAll(); //EV_COMMAND(psh2,
    void     CmCancel();     //EV_COMMAND(IDCANCEL,

    void     EvNCDestroy();

  protected_data:
    FINDREPLACE  fr;
    TData&       Data;

  DECLARE_RESPONSE_TABLE(TFindReplaceDialog);
  DECLARE_CASTABLE;
};

//
// class TFindDialog
// ~~~~~ ~~~~~~~~~~~
class _OWLCLASS TFindDialog : public TFindReplaceDialog {
  public:
    TFindDialog(TWindow*        parent,
                TData&          data,
                TResId          templateId = 0,
                const char far* title = 0,
                TModule*        module = 0);

  protected:
    HWND     DoCreate();

  private:
    TFindDialog();
    TFindDialog(const TFindDialog&);

  DECLARE_CASTABLE;
};

//
// class TReplaceDialog
// ~~~~~ ~~~~~~~~~~~~~~
class _OWLCLASS TReplaceDialog : public TFindReplaceDialog {
  public:
    TReplaceDialog(TWindow*        parent,
                   TData&          data,
                   TResId          templateId = 0,
                   const char far* title = 0,
                   TModule*        module = 0);

  protected:
    HWND     DoCreate();

  private:
    TReplaceDialog(const TReplaceDialog&);
    TReplaceDialog& operator=(const TReplaceDialog&);

  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the transfer data for the find and replace dialog.
//
inline TFindReplaceDialog::TData& TFindReplaceDialog::GetData() {
  return Data;
}

//
// Set the transfer data for the dialog.
//
inline void  TFindReplaceDialog::SetData(TData& data) {
  Data = data;
}

//
// Return the underlying system structure for the find and replace dialog.
//
inline FINDREPLACE& TFindReplaceDialog::GetFR() {
  return fr;
}

//
// Set the underlying system structure for the dialog.
//
inline void TFindReplaceDialog::SetFR(const FINDREPLACE& _fr) {
  fr = _fr;
}

//
// Default behavior inline for message response functions
//
inline void TFindReplaceDialog::CmFindNext() {
  DefaultProcessing();
}

//
// Default behavior inline for message response functions
//
inline void TFindReplaceDialog::CmReplace() {
  DefaultProcessing();
}

//
// Default behavior inline for message response functions
//
inline void TFindReplaceDialog::CmReplaceAll() {
  DefaultProcessing();
}

//
// Default behavior inline for message response functions
//
inline void TFindReplaceDialog::CmCancel() {
  DefaultProcessing();
}



#endif  // OWL_FINDREPL_H
