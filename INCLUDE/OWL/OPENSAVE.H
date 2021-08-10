//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Definition of TOpenSave- abstract, TFileOpen-, TFileSave- common Dialog 
//   classes
//----------------------------------------------------------------------------
#if !defined(OWL_OPENSAVE_H)
#define OWL_OPENSAVE_H

#if !defined(OWL_COMMDIAL_H)
# include <owl/commdial.h>
#endif

//
//  class TOpenSaveDialog
//  ----- ---------------
//
class _OWLCLASS TOpenSaveDialog : public TCommonDialog {
  public:
    class _OWLCLASS TData {
      public:
        uint32     Flags;
        uint32     Error;
        char*      FileName;
        char*      Filter;
        char*      CustomFilter;
        int        FilterIndex;
        char*      InitialDir;
        char*      DefExt;
        int        MaxPath;
      
        TData(uint32 flags=0, const char* filter=0, char* customFilter=0, 
              char* initialDir=0, char* defExt=0, int maxPath=0);
        TData(const TData& src);
        ~TData();

        TData& operator =(const TData& src);

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
           {return ::GetFileTitle((LPSTR)fileName, fileTitle,(uint16)fileTitleLen);}

  protected:
    OPENFILENAME ofn;
    TData&       Data;

    TOpenSaveDialog(TWindow* parent, TData& data, TModule*   module = 0);
    void    Init(TResId templateId);
    bool    DialogFunction(uint message, WPARAM, LPARAM);

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
    static uint ShareViMsgId;

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

#endif  // OWL_OPENSAVE_H
