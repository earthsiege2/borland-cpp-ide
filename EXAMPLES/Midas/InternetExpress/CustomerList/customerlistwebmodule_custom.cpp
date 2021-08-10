/*
  InternetExpress Example.      

  This example started with the CustomerList example and
  has been modified to use the InternetExpress custom components
  in the inetxcustom directory.

  See CustomerList.cpp for a description of the customerlist
  example.

  You will need to build and install the custom components before
  viewing CustomerListWebModule_Custom.  See inetxcustom\readme.txt.

  The CustomerList example has been modified as follows:

    Changes to the Data TMidasPageProducer:

      Remove both TDataNavigator and insert TImgDataNavigator
      components in their place.   Set the XMLComponent properties.

      Insert a new TDataNavigator.  Set XMLComponent property.

      Insert TShowXMLButton and TShowDelta button as children
      of the new TDataNavigator.

    Remove the ReconcileError TMidasPageProducer.  Add a
    TReconcilePageProducer in its place.  Set the
    XMLBroker.ReconcileProducer property to reference this
    new component.

  The behavior of this web application differs from
  CustomerList as follows:

    The navigator buttons are images rather than standard
    text buttons.  Note that you will need to copy the
    .gif file from the inetxcustom directory to your web
    directory so that they image files can be found.  Also
    see the notes in inetxcustom\readme.txt about how to
    see the images as design time.

    The ShowXML and ShowDelta buttons can be clicked to
    open a window displaying the content of the XML data
    and delta packets managed by JavaScript on the web
    page.

    If an error occurs while the MIDAS server is reconciling
    a delta packet, an HTML page is generated to allow the user to
    reconcile the error.  For example, if OrderNo is edited and
    the Apply button pressed, the message
    "Master has detail records. Cannot delete or modify." is
    displayed on the ReconcilePage.  To reconcile the error,
    select the "Correct" radio button, change the OrderNo back
    to the original value, choose the Post/Next Button then
    the Reapply Updates Button.

*/

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#include "CustomerListWebModule_Custom.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "ReconcileProd"
#pragma link "ImgButtons"
#pragma link "showxml"
#pragma resource "*.dfm"
TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWebModule1::DataHTMLTag(TObject *Sender, TTag Tag,
      const AnsiString TagString, TStrings *TagParams,
      AnsiString &ReplaceText)
{
  long CustNo;

  // See the HTMDoc property for location of tags.
  if (TagString == "HREFCUSTLIST")
  {
    // provide value for <A HREF= to return to customer list
    ReplaceText = Request->ScriptName;
    // Note that the HTMLDoc property has an onclick handler
    // to prevent this HREF from being followed if there are
    // pending updates.
  }
  else if (TagString == "CUSTOMER")
  {
    // HTML describing customer
    if (XMLBroker1->Params->Count == 0)
      XMLBroker1->FetchParams();
    CustNo = XMLBroker1->Params->Items[0]->AsInteger;
    CustNames->Active = true;
    TLocateOptions LocateOptions;
    Variant V(CustNo);
    CustNames->Locate("CustNo", VarArrayOf(&V, 1), LocateOptions);
    ReplaceText =
      AnsiString().Format("<H1>Customer Number: %s</H1>"
              "<H1>Customer Name: %s</H1>",
        ARRAYOFCONST((AnsiString(CustNo),
         CustNames->FieldByName("Company")->AsString)));
  }
}
//---------------------------------------------------------------------------
void __fastcall TWebModule1::CustListHTMLTag(TObject *Sender, TTag Tag,
      const AnsiString TagString, TStrings *TagParams,
      AnsiString &ReplaceText)
{
  TField*CompanyField;  
  TField*CustNoField;
  // See the HTMDoc property for location of tags

  // Generate list of customer HREFS.  XMLBroker1 will
  // use the Name/Value pairs to set Params.
  if (TagString == "CUSTOMERLIST")
  {
    CustNames->Open();
    CompanyField = CustNames->FieldByName("Company");
    CustNoField = CustNames->FieldByName("CustNo");
    while (! CustNames->Eof)
    {
      ReplaceText = AnsiString().Format("%s<A HREF='%s/Data?CustNo=%d'>%s</A><BR>\r\n",
        ARRAYOFCONST((ReplaceText, Request->ScriptName, CustNoField->AsInteger, CompanyField->AsString)));
      CustNames->Next();
    }
  }
        
}
//---------------------------------------------------------------------------
void __fastcall TWebModule1::XMLBroker1RequestRecords(TObject *Sender,
      TWebRequest *Request, int RecCount, OleVariant &OwnerData,
      AnsiString &Records)
{
  // Set params using name/value pairs in URL
  XMLBroker1->Params->AssignStrings(Request->QueryFields);

}

// Add a JavaScript method to check for pending updates.
void __fastcall TWebModule1::AddScript(void * Data, _di_IAddScriptElements AddScriptElements)
{
  _di_IXMLDocument XMLDocument;
  _di_IXMLRowSet RowSet;
  if (AddScriptElements->ScriptManager->XMLDocuments->Count > 0)
  {
    XMLDocument = AddScriptElements->ScriptManager->XMLDocuments->Items[0];
    if (XMLDocument->RowSets->Count > 0)
    {
      RowSet = XMLDocument->RowSets->Items[0];
      AddScriptElements->AddFunction("CheckData",
        AnsiString().Format(
       "function CheckData()\r\n"
       "{\r\n"
       "  if ((%0:s.forcepost() != 0) ||\r\n"
       "    (%0:s.DeltaChanges.row.length >0))\r\n"
       "  {\r\n"
       "     return confirm('Data has been changed.  Discard changes?');\r\n"
       "  };\r\n"
       "};\r\n", ARRAYOFCONST((RowSet->RowSetVarName))));
    }
  }
}

//---------------------------------------------------------------------------
void __fastcall TWebModule1::DataBeforeGetContent(TObject *Sender)
{
  Midcomp::_di_IScriptProducer ScriptProducer;
  if (Data->GetInterface(__uuidof(Midcomp::IScriptProducer), &ScriptProducer))
    ScriptProducer->ScriptManager->AddElementsIntf->AddPass(AddScript, NULL);
        
}
//---------------------------------------------------------------------------
void __fastcall TWebModule1::ReconcileErrorHTMLTag(TObject *Sender,
      TTag Tag, const AnsiString TagString, TStrings *TagParams,
      AnsiString &ReplaceText)
{
  // See the HTMDoc property for location of tags.
  if (TagString == "HREFCUSTLIST")
  {
    // provide value for <A HREF= to return to customer list
    ReplaceText = Request->ScriptName;
  }
  else if (TagString == "REDIRECT")
  {
    // Get redirect value send with delta packet.
    ReplaceText = Request->ContentFields->Values[sRedirect];
  }


}
//---------------------------------------------------------------------------
