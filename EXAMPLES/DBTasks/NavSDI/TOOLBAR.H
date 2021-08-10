//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef ToolBarH
#define ToolBarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TfmToolBar : public TForm
{
__published:    // IDE-managed Components
    TDBNavigator *DBNavigator1;
    TMainMenu *MainMenu1;
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
    TMenuItem *Help1;
    TMenuItem *About1;
    TMenuItem *Messages1;
        TMenuItem *Windows1;
        TMenuItem *Customers1;
        TMenuItem *Orders1;
    void __fastcall First1Click(TObject *Sender);
    void __fastcall Next1Click(TObject *Sender);
    void __fastcall Prior1Click(TObject *Sender);
    void __fastcall Last1Click(TObject *Sender);
    void __fastcall Delete1Click(TObject *Sender);
    void __fastcall Insert1Click(TObject *Sender);
    void __fastcall Cancel1Click(TObject *Sender);
    void __fastcall Close1Click(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);
    void __fastcall Messages1Click(TObject *Sender);
        void __fastcall Customers1Click(TObject *Sender);
        void __fastcall Orders1Click(TObject *Sender);
private:        // User declarations
public:         // User declarations
    virtual __fastcall TfmToolBar(TComponent* Owner);
    void virtual __fastcall SetNavigator(const TDataSource* ds);
	void __fastcall UpdateMenu();
};
//---------------------------------------------------------------------------
extern TfmToolBar *fmToolBar;
//---------------------------------------------------------------------------
#endif
