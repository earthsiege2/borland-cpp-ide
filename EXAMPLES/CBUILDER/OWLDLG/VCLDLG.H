//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1996 by Borland International, All Rights Reserved
//
// VCLDLG.H
// This file declares a VCL form class.  The code was generated entirely
// by C++Builder.  Except for these opening comments, nothing has
// been altered.
//
// The VCLDLG example invokes the form from an OWL application.  
//---------------------------------------------------------------------------
#ifndef vcldlgH
#define vcldlgH
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>

using namespace Graphics;
using namespace Forms;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:    // IDE-managed Components 
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TGroupBox *GroupBox2;
    TScrollBar *ScrollBar_Red;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TScrollBar *ScrollBar_Green;
    TScrollBar *ScrollBar_Blue;
    TButton *Button2;
    TButton *Button1;
    TLabel *Label_Selection;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ScrollBar_Change(TObject *Sender);
private:        // User declarations
public:         // User declarations
    virtual __fastcall TForm1(TComponent* Owner);
    COLORREF GetSelectedColor(void);
    void SetSelectedColor(COLORREF color);
};
//---------------------------------------------------------------------------
extern TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
