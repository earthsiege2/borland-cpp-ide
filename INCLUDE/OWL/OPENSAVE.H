//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Definition of TOpenSave abstract, TFileOpen, TFileSave common Dialog classes
//----------------------------------------------------------------------------
#if !defined(OWL_OPENSAVE_H)
#define OWL_OPENSAVE_H

#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>


//
// class TOpenSaveDialog
// ~~~~~ ~~~~~~~~~~~~~~~
class _OWLCLASS TOpenSaveDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        uint32          Flags;
        uint32          Error;
        char*           FileName;
        char far*       Filter;
        char far*       CustomFilter;
        int             FilterIndex;
        const char far* InitialDir;
        const char far* DefExt;
        int             MaxPath;

        TData(uint32 flags=0, const char far* filter=0, char far* customFilter=0,
              const char far* initialDir=0, const char far* defExt=0,
              int maxPath=0, int filterIndex = 0);
        TData(const TData& src);
       ~TData();

        TData& operator =(const TData& src);

        void     SetFilter(const char far* filter = 0);

        void     Write(opstream& os);
        void     Read(ipstream& is);
    };

    TOpenSaveDialog(TWindow*        parent,
                    TData&          data,
                    TResId          templateId = 0,
                    const char far* title = 0,
                    TModule*        module = 0);

    static int GetFileTitleLen(const char far* fileName);
    static int GetFileTitle(const char far* fileName, char far* fileTitle,
                            int bufLen);

  protected:
    TOpenSaveDialog(TWindow* parent, TData& data, TModule*   module = 0);
    void    Init(TResId templateId);
    bool    DialogFunction(uint message, TParam1, TParam2);

    // Override TWindow & TDialog virtuals
    //
    int     DoExecute() = 0;

    // Virtual function called when a share violation occurs in dlg
    //
    virtual int ShareViolation();

    // Messages registered by the common dialog DLL
    //
    static uint GetShareViMsgId();

    // Default behavior inline for message response functions
    //
    void    CmOk();           //EV_COMMAND(IDOK,
    void    CmLbSelChanged(); //EV_COMMAND(lst1 or lst2

    OPENFILENAME& GetOFN();
    void          SetOFN(const OPENFILENAME& _ofn);

    TData&  GetData();
    void    SetData(TData& data);

  protected_data:
    OPENFILENAME ofn;
    TData&       Data;

    static uint ShareViMsgId;

  private:
    TOpenSaveDialog(const TOpenSaveDialog&);
    TOpenSaveDialog& operator =(const TOpenSaveDialog&);

  DECLARE_RESPONSE_TABLE(TOpenSaveDialog);
};

//
// class TFileOpenDialog
// ~~~~~ ~~~~~~~~~~~~~~~
class _OWLCLASS TFileOpenDialog : public TOpenSaveDialog {
  public:
    TFileOpenDialog(TWindow*        parent,
                    TData&          data,
                    TResId          templateId = 0,
                    const char far* title = 0,
                    TModule*        module = 0);

    // Override TDialog virtual functions
    //
    int  DoExecute();

  private:
    TFileOpenDialog(const TOpenSaveDialog&);
    TFileOpenDialog& operator=(const TOpenSaveDialog&);
};

//
// class TFileSaveDialog
// ~~~~~ ~~~~~~~~~~~~~~~
class _OWLCLASS TFileSaveDialog : public TOpenSaveDialog {
  public:
    TFileSaveDialog(TWindow*        parent,
                    TData&          data,
                    TResId          templateId = 0,
                    const char far* title = 0,
                    TModule*        module = 0);

    // Override TDialog virtual functions
    //
    int  DoExecute();

  private:
    TFileSaveDialog(const TFileSaveDialog&);
    TFileSaveDialog& operator=(const TFileSaveDialog&);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return the sharing violation message id.
//
inline uint TOpenSaveDialog::GetShareViMsgId()
{
  return ShareViMsgId;
}

//
// Return the title length of the dialog.
//
inline int TOpenSaveDialog::GetFileTitleLen(const char far* fileName)
{
  return ::GetFileTitle((LPSTR)fileName, 0, 0);   //Win32 cast
}

//
// Return the title of the dialog.
//
inline int TOpenSaveDialog::GetFileTitle(const char far* fileName,
                                         char far* fileTitle,
                                         int fileTitleLen)
{
  return ::GetFileTitle((LPSTR)fileName, fileTitle, (uint16)fileTitleLen);
                        //Win32 casts
}

//
inline void TOpenSaveDialog::CmOk()
{
  DefaultProcessing();
}

//
inline void TOpenSaveDialog::CmLbSelChanged()
{
  DefaultProcessing();
}

//
// Return the OPENFILENAME structure.
//
inline OPENFILENAME& TOpenSaveDialog::GetOFN()
{
  return ofn;
}

//
// Set the OPENFILENAME structure for the dialog.
//
inline void TOpenSaveDialog::SetOFN(const OPENFILENAME& _ofn)
{
  ofn = _ofn;
}

//
// Retrieve the transfer buffer for the dialog.
//
inline TOpenSaveDialog::TData& TOpenSaveDialog::GetData()
{
  return Data;
}

//
// Set the transfer buffer for the dialog.
//
inline void TOpenSaveDialog::SetData(TOpenSaveDialog::TData& data)
{
  Data = data;
}

#endif  // OWL_OPENSAVE_H
