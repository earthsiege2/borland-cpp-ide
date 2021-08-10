//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include <comobj.hpp>
#include <stdio.h>

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TOleWordForm *OleWordForm;
//---------------------------------------------------------------------------
__fastcall TOleWordForm::TOleWordForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
Variant V;

void __fastcall TOleWordForm::bTalkWordClick(TObject *Sender)
{
        IDispatch *A;
        unsigned int I;

        try
        {
                Screen->Cursor = TCursor(crHourGlass);
                V = CreateOleObject("Word.Basic");
        }
        catch (...)
        {
                Screen->Cursor = TCursor(crDefault);
                ShowMessage("This example requires Microsoft Word.");
                Application->Terminate();
        }

        A = V;

        Screen->Cursor = TCursor(crDefault);
        try{
                char TempMsg[200];
                sprintf(TempMsg, "AddRef returns: %d", A->AddRef());
                ShowMessage(TempMsg);
                A->GetTypeInfoCount(&I);
                sprintf(TempMsg, "TypeInfoCount: %d", I);
                ShowMessage(TempMsg);
        }
        catch(...){
                   A->Release();
                   throw;
        }
        A->Release();

        if (VarType(V) == varDispatch){
                ShowMessage("VarType(V) = varDispatch: True");
        }
        else{
                ShowMessage("VarType(V) = varDispatch: False");
        }

        V.Exec(Procedure("FileNew")<< "Normal");
        V.Exec(Procedure("Insert") << "The are no mistakes in life some people say\n");
        V.Exec(Procedure("Insert") << "And it's true, sometimes, you can see it that way.\n");
        V.Exec(Procedure("Insert") << "People don't live or die people just float;\n");
        V.Exec(Procedure("Insert") << "She's gone with the man in the long back coat.");
        V.Exec(Procedure("FileSaveAs") << "C:/ZIMMY.DOC");
}
//---------------------------------------------------------------------

