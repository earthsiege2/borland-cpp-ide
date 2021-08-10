//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ReconcileProd.h"
#include <utilcls.h>  // _ASSERTE
#pragma package(smart_init)

static const char* sErrorPacketTag = "ERRORPACKET";
static const char* sDeltaPacketTag = "DELTAPACKET";
static const char* sReconcileGridTag = "RECONCILEGRID";
static const char* sQuoteXMLAttribute = "QUOTE";
static const char* sQuoteXML = "QUOTE=\"True\""; // Do not localize
static const char* sDefaultXMLBrokerName = "XMLBroker";

static const char* sErrorMessage = "Error message:";
static const char* sOn =           "on";
static const char* sCancel = "Cancel";
static const char* sCorrect = "Correct";
static const char* sMerge = "Merge";
static const char* sPrevRow = "<";
static const char* sNextRow = ">";
static const char* sPostNext = "Post/Next";
static const char* sReapply = "Reapply Updates";
static const char* sReconcileAction = "Reconcile Action";

  static const char* sDefaultHTMLDoc =
    "<HTML>\r\n"
    "<HEAD>\r\n" 
    "</HEAD>\r\n" 
    "<BODY>\r\n" 
    "<#INCLUDES><#STYLES><#WARNINGS>\r\n" 
    "<P>\r\n" 
    "<FORM name=\"FORM1\">\r\n" 
    "<TABLE>\r\n" 
    "<TR>\r\n" 
    "<TD valign=top><H3>%0:s</H3></TD>\r\n"
    "<TD valign=top><textarea name=\"ErrMessage\" rows=2 cols=58 readonly onfocus='blur();'></textarea></TD>\r\n" 
    "<TD valign=top><H3>%1:s</H3></TD>\r\n" 
    "<TD valign=top><input type=text name=\"ErrAction\" size=12 readonly onfocus='blur();'/></TD>\r\n" 
    "</TR>\r\n" 
    "</TABLE>\r\n" 
    "<P>\r\n" 
    "<#RECONCILEGRID>\r\n" 
    "</FORM>\r\n" 
    "<P>\r\n" 
    "<FORM>\r\n" 
    "<H3> %9:s </H3>\r\n" 
    "<input type=radio name=\"action\" value=\"Cancel\" onclick='if(self.grid1!=null)grid1.cancel();'/> %2:s\r\n" 
    "<input type=radio name=\"action\" value=\"Correct\" onclick='if(self.grid1!=null)grid1.correct();'/> %3:s\r\n" 
    "<input type=radio name=\"action\" value=\"Merge\" onclick='if(self.grid1!=null)grid1.merge();'/> %4:s\r\n"
    "<P>\r\n" 
    "<input type=button value=\"%5:s\" onclick='if(self.grid1!=null)grid1.up();' />\r\n" 
    "<input type=button value=\"%6:s\" onclick='if(self.grid1!=null)grid1.down();' />\r\n" 
    "<input type=button value=\"%7:s\" onclick='if(self.grid1!=null)grid1.post();'/>\r\n" 
    "<P>\r\n" 
    "<input type=button value=\"%8:s\" onclick='if(self.grid1!=null)grid1.Reapply(Submitfrm1, Submitfrm1.postdelta);'/>\r\n" 
    "</FORM>\r\n" 
    "<#FORMS><#SCRIPT>\r\n" 
    "</BODY>\r\n" 
    "</HTML>\r\n";


//---------------------------------------------------------------------------

void __fastcall TReconcileColumn::SetCaptionAttributes(const Miditems::TCaptionAttributes* Value)
{
  FCaptionAttributes->Assign(const_cast<TPersistent*>((static_cast<const TPersistent*>(Value))));
};
void __fastcall TReconcileColumn::AssignTo(Classes::TPersistent* Dest)
{

  if (Dest->InheritsFrom(__classid(TReconcileColumn)))
  {
    TReconcileColumn*Column = (TReconcileColumn*)Dest;
    Column->FCaption = FCaption;
    Column->FCustom = FCustom;
    Column->FStyle = FStyle;
    Column->FStyleRule = FStyleRule;
    Column->FCaptionAttributes->Assign(FCaptionAttributes);
    Column->FDisplayWidth = FDisplayWidth;
  }
  else
    inherited::AssignTo(Dest);
};
__fastcall TReconcileColumn::TReconcileColumn(Classes::TComponent* AOwner)
{
  FCaptionAttributes = new TCaptionAttributes(AOwner);
  FMaxWidth = -1;
};
__fastcall TReconcileColumn::~TReconcileColumn(void)
{
  if (FCaptionAttributes)
    delete FCaptionAttributes;
};
AnsiString __fastcall TReconcileColumn::ControlContent(Webcomp::TWebContentOptions* Options)
{
  AnsiString Attrs, Events;

  AddQuotedAttrib(Attrs, "NAME", GetHTMLControlName());
  AddIntAttrib(Attrs, "SIZE", DisplayWidth);
  AddIntAttrib(Attrs, "MAXLENGTH", MaxWidth);
  AddQuotedAttrib(Attrs, "STYLE", Style);
  AddQuotedAttrib(Attrs, "CLASS", StyleRule);
  AddCustomAttrib(Attrs, Custom);

  if (!(Options->Flags.Contains(coNoScript)))
    Events = FEvents;
  return AnsiString().Format("<INPUT TYPE=TEXT %s %s>",
    ARRAYOFCONST((Attrs, Events)));
};

AnsiString __fastcall TReconcileColumn::GetHTMLControlName()
{
  return FName;
};


TReconcileColumn* __fastcall TReconcileGrid::GetColumn(int I)
{
  switch(I)
  {
    case 0: return FFieldNameColumn;
    case 1: return FModifiedColumn;
    case 2: return FConflictingColumn;
    case 3: return FOriginalColumn;
    default:
      _ASSERTE(False /*, "Column out of range" */);
  }
  return NULL;
};

int __fastcall TReconcileGrid::GetColumnCount(void)
{
  return 4;
};

void __fastcall TReconcileGrid::SetConflictingColumn(const TReconcileColumn* Value)
{
  FConflictingColumn->Assign(const_cast<TPersistent*>(static_cast<const TPersistent*>(Value)));
};

void __fastcall TReconcileGrid::SetFieldNameColumn(const TReconcileColumn* Value)
{
  FFieldNameColumn->Assign(const_cast<TPersistent*>(static_cast<const TPersistent*>(Value)));
};

void __fastcall TReconcileGrid::SetModifiedColumn(const TReconcileColumn* Value)
{
  FModifiedColumn->Assign(const_cast<TPersistent*>(static_cast<const TPersistent*>(Value)));
};

void __fastcall TReconcileGrid::SetOriginalColumn(const TReconcileColumn* Value)
{
  FOriginalColumn->Assign(const_cast<TPersistent*>(static_cast<const TPersistent*>(Value)));
};

const char * sScriptTableName = "%s_Table";

AnsiString __fastcall TReconcileGrid::HTMLTableName()
{
  AnsiString Result;
  return Result.Format(sScriptTableName, ARRAYOFCONST(("Reconcile")));
};

AnsiString __fastcall TReconcileGrid::_TableHeader()
{
  AnsiString Attribs;
  AddStringAttrib(Attribs, "NAME", HTMLTableName());
  Attribs = Attribs + HTMLAlign[TableAttributes->Align];
  AddIntAttrib(Attribs, "CELLSPACING", TableAttributes->CellSpacing);
  AddIntAttrib(Attribs, "CELLPADDING", TableAttributes->CellPadding);
  AddIntAttrib(Attribs, "BORDER", TableAttributes->Border);
  AddStringAttrib(Attribs, "BGCOLOR", TableAttributes->BgColor);
  AddQuotedAttrib(Attribs, "STYLE", TableAttributes->Style);
  AddQuotedAttrib(Attribs, "CLASS", TableAttributes->StyleRule);
  AddCustomAttrib(Attribs, TableAttributes->Custom);
  return AnsiString().Format("\r\n<TABLE%s>", ARRAYOFCONST((Attribs)));
}

AnsiString __fastcall TReconcileGrid::_RowHeader(TGridRowAttributes & HeadingAttributes)
{
  AnsiString Attribs;
  Attribs = Attribs + HTMLAlign[HeadingAttributes.Align];
  Attribs = Attribs + HTMLVAlign[HeadingAttributes.VAlign];
  AddQuotedAttrib(Attribs, "BGCOLOR", HeadingAttributes.BgColor);
  AddQuotedAttrib(Attribs, "STYLE", HeadingAttributes.Style);
  AddQuotedAttrib(Attribs, "CLASS", HeadingAttributes.StyleRule);
  AddCustomAttrib(Attribs, HeadingAttributes.Custom);
  return AnsiString().Format("<TR%s>", ARRAYOFCONST((Attribs)));
}

AnsiString __fastcall TReconcileGrid::_FormatColumn(TReconcileColumn &AColumn, AnsiString &OneRow,
  Webcomp::TWebContentOptions* Options)
{
  AnsiString Attribs;
  AddQuotedAttrib(Attribs, "STYLE", AColumn.CaptionAttributes->Style);
  AddCustomAttrib(Attribs, AColumn.CaptionAttributes->Custom);
  AddQuotedAttrib(Attribs, "CLASS", AColumn.CaptionAttributes->StyleRule);
  AnsiString Result;
  Result = AnsiString().Format("<TH%s>%s</TH>\r\n",
    ARRAYOFCONST((Attribs, AColumn.Caption)));
  Attribs = "";
  AddQuotedAttrib(Attribs, "STYLE", AColumn.Style);
  AddCustomAttrib(Attribs, AColumn.Custom);
  AddQuotedAttrib(Attribs, "CLASS", AColumn.StyleRule);
  OneRow = AnsiString().Format("%s<TD%s><DIV>%s</DIV></TD>\r\n",
    ARRAYOFCONST((OneRow, Attribs,
    AColumn.ControlContent(Options))));
  return Result;
}

AnsiString __fastcall TReconcileGrid::FormatTable(Webcomp::TLayoutWebContent* Layout, Webcomp::TWebContentOptions* Options)
{
  long I;
  AnsiString OneRow;
  AnsiString RowHeaderStr;
  AnsiString Result;

  Result = _TableHeader() + _RowHeader(*HeadingAttributes) + "\r\n";
  for (I = 0; I < ColumnCount; I++)
    Result = Result + _FormatColumn(*Column[I], OneRow, Options);
  Result = Result + "</TR>";
  RowHeaderStr = _RowHeader(*RowAttributes);
  for (I = 0; I < DisplayRows; I++)
    Result = AnsiString().Format("%s%s%s</TR>\r\n",
      ARRAYOFCONST((Result, RowHeaderStr, OneRow)));
  Result = Result + "</TABLE>";
  return Result;
};

void __fastcall TReconcileGrid::SetTableAttributes(const Miditems::TGridAttributes* Value)
{
  FTableAttributes->Assign((TPersistent*)Value);
};

void __fastcall TReconcileGrid::SetHeadingAttributes(const Miditems::TGridRowAttributes* Value)
{
  FHeadingAttributes->Assign((TPersistent*)Value);
};
void __fastcall TReconcileGrid::SetRowAttributes(const Miditems::TGridRowAttributes* Value)
{
  FRowAttributes->Assign((TPersistent*)Value);
};
void __fastcall TReconcileGrid::AssignTo(Classes::TPersistent* Dest)
{
  if (Dest->InheritsFrom(__classid(TReconcileGrid)))
  {
    TReconcileGrid * Grid = (TReconcileGrid*)Dest;
    Grid->FDisplayRows = FDisplayRows;
    Grid->FTableAttributes->Assign(FTableAttributes);
    Grid->FHeadingAttributes->Assign(FHeadingAttributes);
    Grid->FRowAttributes->Assign(FRowAttributes);
    long I;
    for (I = 0; I < ColumnCount; I++)
      Grid->Column[I]->Assign(Column[I]);
  }
  else inherited::AssignTo(Dest);
};

__fastcall TReconcileGrid::TReconcileGrid(Classes::TComponent* AOwner)
{
  FDisplayRows = 4;
  FTableAttributes = new TGridAttributes(AOwner);
  FHeadingAttributes = new TGridRowAttributes(AOwner);
  FRowAttributes = new TGridRowAttributes(AOwner);

  FTableAttributes->Border = 1;
  FFieldNameColumn = new TFieldNameColumn(AOwner);
  FModifiedColumn = new TModifiedColumn(AOwner);
  FOriginalColumn = new TOriginalColumn(AOwner);
  FConflictingColumn = new TConflictingColumn(AOwner);
};

__fastcall TReconcileGrid::~TReconcileGrid(void)
{
  if (FTableAttributes)
    delete FTableAttributes;
  if (FHeadingAttributes)
    delete FHeadingAttributes;
  if (FRowAttributes)
    delete FRowAttributes;
  long I;
  for (I = 0; I < ColumnCount; I++)
    delete Column[I];
};


void __fastcall TReconcilePageProducer::SetReconcileGrid(const TReconcileGrid* Value)
{
  FReconcileGrid->Assign((TPersistent*)Value);
};

void __fastcall TReconcilePageProducer::DoTagEvent(TTag Tag, const AnsiString TagString, Classes::TStrings* TagParams, AnsiString &ReplaceText)
{
  TXMLBroker *XMLBroker;
  TXMLOptions XMLOptions;

  if (!ComponentState.Contains(csDesigning))
    if ((Tag == tgCustom) && (CompareText(TagString, sDeltaPacketTag) == 0))
    {
      if (CompareText(TagParams->Values[sQuoteXMLAttribute], "True") == 0)
      {
        XMLOptions << xoQuote;
        XMLBroker = FindXMLBroker(TagParams);
        if (XMLBroker)
          ReplaceText = FormatXML(XMLBroker->GetDelta(Dispatcher->Request()),  XMLOptions);
      }
      return;
    }
    else if ((Tag == tgCustom) && (CompareText(TagString, sErrorPacketTag) == 0))
    {
      if (CompareText(TagParams->Values[sQuoteXMLAttribute], "True") == 0)
        XMLOptions << xoQuote;
      XMLBroker = FindXMLBroker(TagParams);  
      if (XMLBroker)
        ReplaceText = FormatXML(XMLBroker->GetErrors(), XMLOptions);
      return;
    }

  if ((Tag == tgCustom) && (CompareText(TagString, sReconcileGridTag) == 0))
  {
    if (PageElements)
      ReplaceText = (static_cast<TReconcilePageElements*>(PageElements))->ReconcileGridContent;
    return;
  }
  inherited::DoTagEvent(Tag, TagString, TagParams, ReplaceText);
};

TXMLBroker* __fastcall TReconcilePageProducer::_FindXMLBroker()
{
  long  I;
  for (I = 0; I < Owner->ComponentCount; I++)
  {
    if (Owner->Components[I]->InheritsFrom(__classid(TXMLBroker)))
    {
      TXMLBroker * Result;
      Result = (TXMLBroker*)(Owner->Components[I]);
      if (Result->GetErrors() != "")
        return Result;
    }
  }
  return NULL;
}

static const char* sErrXMLVarName = "xmlErrStr";
static const char*   sDeltaXMLVarName = "xmlDeltaStr";
static const char*   sErrDocVarName = "xmlErrDoc";
static const char*   sDeltaDocVarName = "xmlDeltaDoc";

void __fastcall TReconcilePageProducer::GeneratePageElements(void)
{
  if (ComponentState.Contains(csDesigning))
    FXMLBroker = NULL;
  else
    FXMLBroker = _FindXMLBroker();

  try
  {
    inherited::GeneratePageElements();
    (static_cast<TReconcilePageElements*>(PageElements))->ReconcileGridContent =
      FReconcileGrid->FormatTable(NULL, ScriptManager->Options);
  }
  catch(...)
  {
    FXMLBroker = NULL;
    throw;
  };
  FXMLBroker = NULL;
};

Midprod::TMidasPageElements* __fastcall TReconcilePageProducer::CreatePageElements(void)
{
  return new TReconcilePageElements;     
};

void __fastcall TReconcilePageProducer::AddIncludes(void)
{
  TStdIncludes StdIncludes;
  StdIncludes << jsDB;
  StdIncludes << jsErrDisp;
  if (! GetUseXMLIslands())
    StdIncludes << jsDom;
  AddStdIncludes(StdIncludes, ScriptManager->GetAddElementsIntf());
};

AnsiString __fastcall TReconcilePageProducer::DeclareRowSets()
{
  return AnsiString().Format(
    "var rowsetErr = new xmlRowSet(%s, null, null);\r\n"
    "var rowsetDelta = new xmlRowSet(%s, null, null);\r\n"
    "var frm1 = document.forms['FORM1'];\r\n"
    "var grid1 = new ErrReconcile(rowsetDelta,rowsetErr,\r\n"
    "   new Array(frm1.col_FieldName,frm1.col_Modified,frm1.col_Conflicting,frm1.col_Original),\r\n"
    "   new Array(\"FieldName\",\"Modified\",\"Conflicting\",\"Original\"),\r\n"
    "   frm1.ErrMessage,frm1.ErrAction);\r\n"
    "   grid1.setFocus(0,1);\r\n",
    ARRAYOFCONST((sErrDocVarName, sDeltaDocVarName)));
};

static const char *
  sSubmitFormName = "Submitfrm1"; // Do not localize

void __fastcall TReconcilePageProducer::AddScriptComponents(void)
{
  inherited::AddScriptComponents();
  const char * Indent1 = "  ";
  AnsiString PathInfo;
  AnsiString Redirect;
  AnsiString  HTMLSubmitFormName(sSubmitFormName);
  AnsiString SubmitFormVarName(sSubmitFormName);
  AnsiString XMLBrokerName;
  AnsiString Forms;
  if (FXMLBroker)
  {
    PathInfo = FXMLBroker->WebDispatch->PathInfo;
    XMLBrokerName = FXMLBroker->Name;
  }
  else
  {
    PathInfo = "";
    XMLBrokerName = sDefaultXMLBrokerName;
  }
  if (PathInfo.Length() > 0 && PathInfo[1] == '/')
    PathInfo.Delete(1, 1);
  if (Dispatcher && Dispatcher->Request())
    PathInfo = Dispatcher->Request()->ScriptName + "/" + PathInfo;
  Forms = Forms +
    AnsiString().Format("<FORM NAME=%s ACTION=\"%s\" METHOD=\"POST\">\r\n",
      ARRAYOFCONST((HTMLSubmitFormName, PathInfo)));
  Forms = Forms +
    AnsiString().Format("%s<INPUT TYPE=HIDDEN NAME=\"%s\" VALUE=\"%s\">\r\n",
      ARRAYOFCONST((Indent1, sXMLBroker, XMLBrokerName)));
  Forms = Forms +
    AnsiString().Format("%s<INPUT TYPE=HIDDEN NAME=\"%s\">\r\n",
      ARRAYOFCONST((Indent1, sPostDelta)));
  Forms = Forms +
    AnsiString().Format("%s<INPUT TYPE=HIDDEN NAME=\"%s\" VALUE=\"%s\">\r\n",
      ARRAYOFCONST((Indent1, sProducer, Name)));
  if (Dispatcher && Dispatcher->Request())
  {
    Redirect = Dispatcher->Request()->ContentFields->Values[sRedirect];
    Forms = Forms +
      AnsiString().Format("%s<INPUT TYPE=HIDDEN NAME=\"%s\" VALUE=\"%s\">\r\n",
        ARRAYOFCONST((Indent1, sRedirect, Redirect)));
  }
  Forms = Forms + "</FORM>\r\n";
  ScriptManager->GetAddElementsIntf()->AddHTMLBlock(HTMLSubmitFormName, Forms);
  ScriptManager->GetAddElementsIntf()->AddVar(SubmitFormVarName,
     AnsiString().Format("var %s = document.forms['%s']\r\n",
    ARRAYOFCONST((SubmitFormVarName, HTMLSubmitFormName))));
};

AnsiString __fastcall TReconcilePageProducer::_DeclareXMLDocument(const char * XMLBrokerName, const char * XMLVarName,
  const char * DocVarName,
  const char * TagName, const char * XMLData)
{
  AnsiString Result;
  Result = AnsiString().Format("var %s = \r\n", ARRAYOFCONST((XMLVarName)));
  if (ComponentState.Contains(csDesigning) || strlen(XMLData) == 0)
    Result = AnsiString().Format("%s<#%s %s=%s %s>;\r\n",   
      ARRAYOFCONST((Result, TagName, sXMLBroker, XMLBrokerName, sQuoteXML)));
  else
    Result = AnsiString().Format("%s%s;\r\n", ARRAYOFCONST((Result, XMLData)));
  Result = AnsiString().Format("%svar %s = new Document(%s);\r\n",
   ARRAYOFCONST((Result, DocVarName, XMLVarName)));
  return Result;
};


AnsiString __fastcall TReconcilePageProducer::DeclareXMLDocuments()
{
  AnsiString XMLBrokerName;
  AnsiString XMLErrors, XMLDelta;

  TXMLOptions XMLOptions;
  XMLOptions << xoQuote;
  GetXMLInfo(XMLBrokerName, XMLErrors, XMLDelta, XMLOptions);
  AnsiString Result;
  Result = Result +
    _DeclareXMLDocument(XMLBrokerName.c_str(), sErrXMLVarName, sErrDocVarName, sErrorPacketTag,
    XMLErrors.c_str() );
  Result = Result +
    _DeclareXMLDocument(XMLBrokerName.c_str(), sDeltaXMLVarName, sDeltaDocVarName, sDeltaPacketTag,
    XMLDelta.c_str());
  return Result;
};

AnsiString __fastcall TReconcilePageProducer::_DeclareXMLIsland(const char *XMLBrokerName,
  const char *DocVarName, const char *TagName, const char *XMLData)
{
  AnsiString Result;
  Result = Result.Format("<XML ID=%s>\r\n", ARRAYOFCONST((DocVarName)));
  if (ComponentState.Contains(csDesigning) || strlen(XMLData) == 0)
    Result = Result.Format("%s<#%s %s=%s>\r\n",
      ARRAYOFCONST((Result, TagName, sXMLBroker, XMLBrokerName)));
  else
    Result = Result.Format("%s%s", ARRAYOFCONST((Result, XMLData)));
  Result = Result + "\r\n</XML>\r\n";
  return Result;
}

AnsiString __fastcall TReconcilePageProducer::DeclareXMLIslands()
{
  AnsiString XMLBrokerName;
  AnsiString XMLErrors, XMLDelta;
  TXMLOptions XMLOptions;
  GetXMLInfo(XMLBrokerName, XMLErrors, XMLDelta, XMLOptions);
  AnsiString Result;
  Result =
    _DeclareXMLIsland(XMLBrokerName.c_str(), sErrDocVarName, sErrorPacketTag,
    XMLErrors.c_str());
  Result = Result +
    _DeclareXMLIsland(XMLBrokerName.c_str(), sDeltaDocVarName, sDeltaPacketTag,
    XMLDelta.c_str());
  return Result;
};

void __fastcall TReconcilePageProducer::GetXMLInfo(AnsiString &XMLBrokerName, AnsiString &XMLErrors, AnsiString &XMLDelta, Xmlbrokr::TXMLOptions XMLOptions)
{
  XMLErrors = "";
  XMLDelta = "";
  if (FXMLBroker)
  {
    XMLErrors = FormatXML(FXMLBroker->GetErrors(), XMLOptions);
    if (Dispatcher && Dispatcher->Request())
      XMLDelta = FormatXML(FXMLBroker->GetDelta(Dispatcher->Request()),
        XMLOptions);
    XMLBrokerName = FXMLBroker->Name;
  }
  else
    XMLBrokerName = sDefaultXMLBrokerName;
};
__fastcall TReconcilePageProducer::TReconcilePageProducer(Classes::TComponent* AOwner): TCustomMidasPageProducer(AOwner)
{
  FReconcileGrid = new TReconcileGrid(this);
  HTMLDoc->Text = AnsiString().Format(sDefaultHTMLDoc,
    ARRAYOFCONST((sErrorMessage, sOn, sCancel, sCorrect, sMerge,
     sPrevRow, sNextRow, sPostNext, sReapply, sReconcileAction)));
};

__fastcall TReconcilePageProducer::~TReconcilePageProducer(void)
{
  if (FReconcileGrid)
    delete FReconcileGrid;
};

static const char* sFieldNameCaption = "Field Name";
static const char* sModifiedCaption = "Submitted Value";
static const char* sConflictingCaption = "Conflicting Value";
static const char* sOriginalCaption = "Original Value";


__fastcall TFieldNameColumn::TFieldNameColumn(Classes::TComponent* AOwner) : TReconcileColumn(AOwner)
{
  FName = "col_FieldName";
  FEvents = "onfocus = \"blur();\"";
  FDisplayWidth = 18;
  FCaption = sFieldNameCaption;
};


__fastcall TModifiedColumn::TModifiedColumn(Classes::TComponent* AOwner) : TReconcileColumn(AOwner)
{
  FName = "col_Modified";
  FEvents = "onfocus = \"grid1.xfocus(this);\"";
  FDisplayWidth = 24;
  FCaption = sModifiedCaption;
};

__fastcall TConflictingColumn::TConflictingColumn(Classes::TComponent* AOwner) : TReconcileColumn(AOwner)
{
  FName = "col_Conflicting";
  FEvents = "onfocus = \"blur();\"";
  FDisplayWidth = 24;
  FCaption = sConflictingCaption;
};

__fastcall TOriginalColumn::TOriginalColumn(Classes::TComponent* AOwner): TReconcileColumn(AOwner)
{
  FName = "col_Original";
  FEvents = "onfocus = \"blur();\"";
  FDisplayWidth = 24;
  FCaption = sOriginalCaption;
};




