//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef GdsstdH
#define GdsstdH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TGDSStdForm : public TForm
{
__published:
    TPanel *GDSStdPanel;
    TBevel *ImageBevel;
    TLabel *GDSSloganLabel2;
    TLabel *GDSLabel2;
    TImage *GDSStdImage;
    TLabel *GDSLabel;
    TLabel *GDSSloganLabel;
private:        // private user declarations
public:         // public user declarations
    virtual __fastcall TGDSStdForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TGDSStdForm *GDSStdForm;
//---------------------------------------------------------------------------
#endif
