//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "main.h"
#include "string.h";
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TCInfoModule *CInfoModule;
String ScriptName;

//---------------------------------------------------------------------------
__fastcall TCInfoModule::TCInfoModule(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCInfoModule::RootHTMLTag(TObject *Sender, TTag Tag,
      const AnsiString TagString, TStrings *TagParams,
      AnsiString &ReplaceText)
{
  if ( TagString==AnsiString("MODULENAME") )
    ReplaceText = ScriptName;

}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustInfoModCreate(
      TObject *Sender)
{
  char* filename = new char[MAX_PATH- 1];
  Customer->Open();
  BioLife->Open();
  GetModuleFileName(HInstance, filename,MAX_PATH-1);
  ScriptName = ExtractFileName(filename);
  delete[] filename;
}
//---------------------------------------------------------------------------
void __fastcall TCInfoModule::CustomerListHTMLTag(TObject *Sender,
      TTag Tag, const AnsiString TagString, TStrings *TagParams,
      AnsiString &ReplaceText)
{
  String Customers = "";
  if (CompareText(TagString, AnsiString("CUSTLIST")) == 0)
  {
    Customers = "";
    Customer->First();
    while ( !( Customer->Eof ) )
    {
      Customers = Customers + "<A HREF=/scripts/" + ScriptName + "/runquery?CustNo=" +
                  CustomerCustNo->AsInteger + ">" + CustomerCompany->AsString.c_str() +
                  "</A><BR>";
      Customer->Next();
    }
  }
  ReplaceText = Customers;
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleCustomerlistAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  Response->Content = CustomerList->Content();
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleQueryActionAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  TLocateOptions SearchOptions = SearchOptions<<(TLocateOption)NULL;
  if (Customer->Locate( AnsiString("CustNo"),
                        Request->QueryFields->Values[AnsiString("CustNo")],
                        SearchOptions))
  {
    CustomerOrders->Header->Clear();
    CustomerOrders->Header->Add(AnsiString("The following table was produced using a TDatasetTableProducer.<P>"));
    CustomerOrders->Header->Add(AnsiString("Orders for: " +
                    Customer->Fields->FieldByName("Company")->Value));
    Response->Content = CustomerOrders->Content();
  }
  else
  {
    Response->Content = "<html><body><b>Customer: "
                        + Request->QueryFields->Values[AnsiString("CustNo")]
                        + " not found</b></body></html>";
  }
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleRedirectAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  Response->SendRedirect(AnsiString("http://www.inprise.com"));
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleGetImageAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  TJPEGImage *Jpg = new TJPEGImage();
  TMemoryStream *S = new TMemoryStream();
  TPicture *P = new TPicture();

  try
  {
    P->Assign(BioLifeGraphic);
    Jpg->Assign(P->Graphic);
    try
    {
      Jpg->SaveToStream(S);
      S->Position = 0;
      Response->ContentType = AnsiString("image/jpeg");
      Response->ContentStream = S;
      Response->SendResponse();
    }
    __finally
    {
      &P->Free;
      &S->Free;
    }
  }
  __finally
  {
    &Jpg->Free;
  }

}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleBioLifeAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  Response->Content = BioLifeProducer->Content();

}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleRootAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  Response->Content = Root->Content();

}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::BioLifeNotesGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
   Text = Sender->Value;

}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::BioLifeGraphicGetText(TField *Sender,
      AnsiString &Text, bool DisplayText)
{
  Text = "<IMG SRC=/scripts/" + ScriptName + "/getimage alt= ["
          + BioLifeCommon_Name->AsString + "] border=0>" ;
}
//---------------------------------------------------------------------------



