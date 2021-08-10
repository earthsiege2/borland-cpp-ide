//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "showxml.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

const char *sShowXML = "Show XML";
const char *sShowDelta = "Show Delta";

void __fastcall TCustomShowXMLButton::ImplAddElements(_di_IAddScriptElements AddIntf)
{
  inherited::ImplAddElements(AddIntf);
  AddIntf->AddIncludeFile("xmlshow.js");
}

AnsiString __fastcall TCustomShowXMLButton::ImplContent(
  Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout)
{
  AnsiString Attrs;
  _di_ILayoutWebContent Intf;
  AnsiString FormVarName;
  AnsiString RowSetVarName;
  _di_IDataSetComponent DataSetComponent;

  AddQuotedAttrib(Attrs, "NAME", Name);
  AddQuotedAttrib(Attrs, "STYLE", Style);
  AddQuotedAttrib(Attrs, "CLASS", StyleRule);
  AddQuotedAttrib(Attrs, "VALUE", Caption);
  AddCustomAttrib(Attrs, Custom);
  TXMLBroker *XMLBroker = NULL;
  if (XMLComponent)
    if (XMLComponent->GetInterface(__uuidof(IDataSetComponent), &DataSetComponent))
      XMLBroker = DataSetComponent->XMLBroker;
  if (XMLBroker)
  {
    FormVarName = XMLBroker->SubmitFormVarName();
    RowSetVarName = XMLBroker->RowSetVarName(NULL);  // Row row set var name
  }
  AnsiString Result;
  if (!(Options->Flags.Contains(coNoScript)))
    Result =
      AnsiString().Format("<INPUT TYPE=BUTTON %0:s onclick='if(%3:s)ShowXML(%1:s.%2:s);'>\r\n",
        ARRAYOFCONST((Attrs, RowSetVarName, XMLMethodName, sXMLReadyVar)));
  else
    Result =
      AnsiString().Format("<INPUT TYPE=BUTTON %0:s>\r\n",
        ARRAYOFCONST((Attrs)));
  if (ParentLayout && ParentLayout->GetInterface(__uuidof(ILayoutWebContent), &Intf))
    Result = Intf->LayoutButton(Result, GetLayoutAttributes());
  return Result;
}


__fastcall TShowXMLButton::TShowXMLButton(TComponent* AOwner): TCustomShowXMLButton(AOwner)
{
  DefaultCaption = sShowXML;
  XMLMethodName = "root";
};

__fastcall TShowDeltaButton::TShowDeltaButton(TComponent *AOwner): TCustomShowXMLButton(AOwner)
{
  DefaultCaption = sShowDelta;
  XMLMethodName = "getDelta()";
};

//---------------------------------------------------------------------------
