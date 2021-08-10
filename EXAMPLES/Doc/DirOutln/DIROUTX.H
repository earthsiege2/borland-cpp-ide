//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef diroutxH
#define diroutxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Outline.hpp>
#include <Grids.hpp>
#include <FileCtrl.hpp>
#include "cdiroutl.h"
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:    // IDE-managed Components 
    TLabel *Label2;
    TDriveComboBox *DriveComboBox1;
    TLabel *Label1;
    TLabel *Label3;
    TEdit *Edit1;
    TFileListBox *FileListBox1;
    TLabel *Label5;
    TMemo *Memo1;
    TLabel *Label4;
   TCDirectoryOutline *DirectoryOutline1;
    void __fastcall DirectoryOutline1Change(TObject *Sender);
    void __fastcall DriveComboBox1Change(TObject *Sender);
    void __fastcall Edit1Change(TObject *Sender);
    void __fastcall FileListBox1Change(TObject *Sender);
    void __fastcall FileListBox1Enter(TObject *Sender);
   
private:        // User declarations
public:         // User declarations
    virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
