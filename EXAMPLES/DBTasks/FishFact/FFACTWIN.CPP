//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FFactWin.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormFacts *FormFacts;
//---------------------------------------------------------------------------
__fastcall TFormFacts::TFormFacts(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

// This application shows how to display Paradox style memo and graphic
// fields in a form. Table1's DatabaseName property should point to the
// Borland sample database. Table1's TableName property should be set to 
// the BIOLIFE table.
//

void __fastcall TFormFacts::SaveClick(TObject *Sender)
{
    FILE *outfile;
    char buff[100];

    sprintf(buff, "Save Info For: %s", DBLabel1->Field->AsString.c_str());
    SaveDialog1->Title = buff;

    if (SaveDialog1->Execute())
    {
        outfile = fopen(SaveDialog1->FileName.c_str(), "wt");
        if (outfile)
        {
            fprintf(outfile, "Facts on the %s\n\n", (LPSTR)DBLabel1->Field->AsString.c_str());
            for (int i=0; i < DBGrid1->FieldCount; i++)
             	fprintf(outfile, "%s: %s\n",
                	(LPSTR)DBGrid1->Fields[i]->FieldName.c_str(),
                    (LPSTR)DBGrid1->Fields[i]->AsString.c_str());
            fprintf(outfile, "\n%s\n", (LPSTR)DBMemo1->Text.c_str());
        }
        fclose(outfile);
    }
}
//---------------------------------------------------------------------
void __fastcall TFormFacts::FormShow(TObject *Sender)
{
  Table1->Open();        
}
//---------------------------------------------------------------------------

