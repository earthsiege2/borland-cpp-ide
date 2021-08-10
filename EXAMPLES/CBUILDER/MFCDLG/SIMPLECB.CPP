//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "SimpleCB.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
const char *adj[] = {
	"Awesome", "Fast", "Shipping", "Better than sliced bread", "Cool",
    "Nifty", "Slick", "Rockin'", "Easy to use", "Fun to use", "The Cat's meow",
    "Advanced", "Revolutionary",
    NULL
};
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	static int adjCount;
    if(adj[adjCount] == NULL)
    	adjCount = 0;

	ListBox1->Items->Add(adj[adjCount++]);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	// we are done with the form, dismiss it.
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	ListBox1->Items->Add(Edit1->Text);
}
//---------------------------------------------------------------------------