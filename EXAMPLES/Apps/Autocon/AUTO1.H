//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef Auto1H
#define Auto1H
//----------------------------------------------------------------------------
#include <ComObj.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:
    TEdit *Edit1;
    TButton *setvalB;
    TButton *getvalB;
    TButton *clearB;
    TLabel *Label1;
    TButton *functionB;
    TButton *setvalA;
    TButton *getvalA;
    TButton *clearA;
    TButton *functionA;
    TLabel *Label2;
    TLabel *Label3;
    void __fastcall setvalDClick(TObject *Sender);
    void __fastcall getvalDClick(TObject *Sender);
    void __fastcall clearDClick(TObject *Sender);
	
    void __fastcall functionDClick(TObject *Sender);
    void __fastcall setvalVClick(TObject *Sender);
    void __fastcall functionVClick(TObject *Sender);
    void __fastcall clearVClick(TObject *Sender);
    void __fastcall getvalVClick(TObject *Sender);
private: 
    IEditServerDisp AutoServer; //IDispatch method of binding
    TCOMIEditServer EditServer; //VTable method of binding
public:
    virtual __fastcall TFormMain(TComponent *Owner);
};
//----------------------------------------------------------------------------
extern TFormMain *FormMain;
//----------------------------------------------------------------------------
#endif	
