//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\editfile.h
//   Definition of class TEditFile, a text edit which can find/replace
//   and read/write from/to a file.
//----------------------------------------------------------------------------
#if !defined(__OWL_EDITFILE_H)
#define __OWL_EDITFILE_H

#if !defined(__OWL_EDITSEAR_H)
  #include <owl\editsear.h>
#endif
#if !defined(__OWL_OPENSAVE_H)
  #include <owl\opensave.h>
#endif
#include <owl\editfile.rh>

//
//  class TEditFile
//  ----- -----------
//
class _OWLCLASS TEditFile : public TEditSearch {
  public:
    TOpenSaveDialog::TData FileData;
    char far* FileName;

    TEditFile(TWindow*        parent = 0,
              int             id = 0,
              const char far* text = 0,
              int x = 0, int y = 0, int w = 0, int h = 0,
              const char far* fileName = 0,
              TModule*        module = 0);

   ~TEditFile();

    virtual BOOL  CanClear();
    virtual BOOL  CanClose();

    void          NewFile();
    void          Open();
    BOOL          Read(const char far* fileName=0);
    void          ReplaceWith(const char far* fileName);
    BOOL          Save();
    BOOL          SaveAs();
    void          SetFileName(const char far* fileName);
    BOOL          Write(const char far* fileName=0);

    //
    // command response functions
    //
    void          CmFileNew() {NewFile();}    // CM_FILENEW
    void          CmFileOpen() {Open();}      // CM_FILEOPEN
    void          CmFileSave() {Save();}      // CM_FILESAVE
    void          CmFileSaveAs() {SaveAs();}  // CM_FILESAVEAS

    //
    // command enabler functions
    //
    void          CmSaveEnable(TCommandEnabler& commandHandler);    

  protected:
    //
    // override virtual functions defined by TWindow
    //
    void          SetupWindow();

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TEditFile(const TEditFile&);
    TEditFile& operator =(const TEditFile&);

  DECLARE_RESPONSE_TABLE(TEditFile);
  DECLARE_STREAMABLE(_OWLCLASS, TEditFile, 1);
};

#endif  // __OWL_EDITFILE_H
