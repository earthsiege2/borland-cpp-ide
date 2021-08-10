//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\opensave.cpp
//   Definition of TOpenSave- abstract, TFileOpen-, TFileSave- common Dialog 
//   classes
//----------------------------------------------------------------------------
#if !defined(__OWL_OPENSAVE_H)
#define __OWL_OPENSAVE_H

#if !defined(__COMMDIAL_H)
  #include <owl\commdial.h>
#endif

//
//  class TOpenSaveDialog
//  ----- ---------------
//
class _OWLCLASS TOpenSaveDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        DWORD      Flags;
        DWORD      Error;
        char*      FileName;
        char*      Filter;
        char*      CustomFilter;
        int        FilterIndex;
        char*      InitialDir;
        char*      DefExt;
      
        TData(DWORD flags=0, char* filter=0, char* customFilter=0, 
              char* initialDir=0, char* defExt=0);
        ~TData();

        void     SetFilter(const char* filter = 0);

        void     Write(opstream& os);
        void     Read(ipstream& is);
    };

    TOpenSaveDialog(TWindow*        parent,
                    TData&          data,
                    TResId          templateId = 0,
                    const char far* title = 0,
                    TModule*        module = 0);

    static int GetFileTitleLen(const char far* fileName)
           {return ::GetFileTitle((LPSTR)fileName, 0, 0);} //Win32 cast

    static int GetFileTitle(const char far* fileName, char far* fileTitle, 
                            int fileTitleLen) //Win32 casts
           {return ::GetFileTitle((LPSTR)fileName, fileTitle,(WORD)fileTitleLen);}

  protected:
    OPENFILENAME ofn;
    TData&       Data;

    TOpenSaveDialog(TWindow* parent, TData& data, TModule*   module = 0);
    void    Init(TResId templateId);
    BOOL    DialogFunction(UINT message, WPARAM, LPARAM);

    //
    // override TWindow & TDialog virtuals
    //
    int     DoExecute() = 0;

    //
    // Virtual function called when a share violation occurs in dlg
    //
    virtual int ShareViolation();

    //
    // Messages registered by the common dialog DLL
    //
    static UINT ShareViMsgId;

    //
    // Default behavior inline for message response functions
    //
    void    CmOk() {DefaultProcessing();}           //EV_COMMAND(IDOK,
    void    CmLbSelChanged() {DefaultProcessing();} //EV_COMMAND(lst1 or lst2
  
  private:
    TOpenSaveDialog(const TOpenSaveDialog&);
    TOpenSaveDialog& operator =(const TOpenSaveDialog&);

  DECLARE_RESPONSE_TABLE(TOpenSaveDialog);
};


//
//  class TFileOpenDialog
//  ----- ---------------
//
class _OWLCLASS TFileOpenDialog : public TOpenSaveDialog {
  public:
    TFileOpenDialog(TWindow*        parent,
                    TData&          data,
                    TResId          templateId = 0,
                    const char far* title = 0,
                    TModule*        module = 0);

    //
    // override TDialog virtual functions
    //
    int  DoExecute();

  private:
    TFileOpenDialog(const TOpenSaveDialog&);
    TFileOpenDialog& operator=(const TOpenSaveDialog&);
};


//
//  class TFileSaveDialog
//  ----- ---------------
//
class _OWLCLASS TFileSaveDialog : public TOpenSaveDialog {
  public:
    TFileSaveDialog(TWindow*        parent,
                    TData&          data,
                    TResId          templateId = 0,
                    const char far* title = 0,
                    TModule*        module = 0);

    //
    // override TDialog virtual functions
    //
    int  DoExecute();

  private:
    TFileSaveDialog(const TFileSaveDialog&);
    TFileSaveDialog& operator=(const TFileSaveDialog&);
};

#endif  // __OWL_OPENSAVE_H
