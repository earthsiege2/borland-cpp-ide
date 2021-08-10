//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef ToolbarH
#define ToolbarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TfmToolbar : public TForm
{
__published:    // IDE-managed Components 
    TPanel *Panel1;
    TMainMenu *MainMenu1;
    TDBNavigator *DBNavigator1;
    TMenuItem *File1;
    TMenuItem *Close1;
    TMenuItem *Record1;
    TMenuItem *First1;
    TMenuItem *Next1;
    TMenuItem *Prior1;
    TMenuItem *Last1;
    TMenuItem *N1;
    TMenuItem *Delete1;
    TMenuItem *Insert1;
    TMenuItem *Cancel1;
    TMenuItem *Window1;
    TMenuItem *Tile1;
    TMenuItem *Cascade1;
    TMenuItem *Help1;
    TMenuItem *about1;
    TMenuItem *Messages1;
    void __fastcall Close1Click(TObject *Sender);
    void __fastcall about1Click(TObject *Sender);
    void __fastcall Messages1Click(TObject *Sender);
    void __fastcall Tile1Click(TObject *Sender);
    void __fastcall Cascade1Click(TObject *Sender);
    void __fastcall First1Click(TObject *Sender);
    void __fastcall Next1Click(TObject *Sender);
    void __fastcall Prior1Click(TObject *Sender);
    void __fastcall Last1Click(TObject *Sender);
    void __fastcall Delete1Click(TObject *Sender);
    void __fastcall Insert1Click(TObject *Sender);
    void __fastcall Cancel1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:        // User declarations
	void __fastcall UpdateMenu();
public:         // User declarations
    virtual __fastcall TfmToolbar(TComponent* Owner);
    void __fastcall SetNavigator(const TDataSource* ds);
};
//---------------------------------------------------------------------------
extern TfmToolbar *fmToolbar;
//---------------------------------------------------------------------------
#endif
