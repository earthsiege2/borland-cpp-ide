//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ImgButtons.h"  
#pragma package(smart_init)

//---------------------------------------------------------------------------

const char * sFirstButton = "First";
const char *  sLastButton = "Last";
const char *   sPriorButton = "Prior";
const char *   sNextButton = "Next";
const char *   sPriorPageButton = "Prior Page";
const char *   sNextPageButton = "Next Page";
const char *   sDeleteButton = "Delete";
const char *   sInsertButton = "Insert";
const char *   sUndoButton = "Undo";
const char *   sPostButton = "Post";
const char *   sApplyUpdates = "Apply Updates";
const char *   sXMLComponentNotDefined = "%s.XMLComponent = nil";

  #define DefaultGridButtonsCount 11
  TComponentClass DefaultGridButtons[DefaultGridButtonsCount] =
    {__classid(TImgFirstButton),
    __classid(TImgPriorPageButton),
    __classid(TImgPriorButton),
    __classid(TImgNextButton),
    __classid(TImgNextPageButton),
    __classid(TImgLastButton),
    __classid(TImgInsertButton),
    __classid(TImgDeleteButton),
    __classid(TImgUndoButton),
    __classid(TImgPostButton),
    __classid(TImgApplyUpdatesButton)};

  #define DefaultFormButtonsCount 9
  TComponentClass DefaultFormButtons[DefaultFormButtonsCount] =
    {__classid(TImgFirstButton),
    __classid(TImgPriorButton),
    __classid(TImgNextButton),
    __classid(TImgLastButton),
    __classid(TImgInsertButton),
    __classid(TImgDeleteButton),
    __classid(TImgUndoButton),
    __classid(TImgPostButton),
    __classid(TImgApplyUpdatesButton)};


void __fastcall TImgDataNavigator::GetDefaultButtons()
{
  TComponent *XMLDisplay;
  _di_IXMLDisplay Intf;
  long Count;
  bool Grid;

  Grid = False;
  XMLDisplay = GetWebDisplayComponent();
  if (XMLDisplay)
    if (XMLDisplay->GetInterface(__uuidof(IXMLDisplay), &Intf))
      Grid = Intf->IsMultipleRecordView;
  if (Grid)
    Count = DefaultGridButtonsCount;
  else
    Count = DefaultFormButtonsCount;
  if ((DefaultWebComponents) &&
    (DefaultWebComponents->Count != Count))
  {
    delete DefaultWebComponents;
    DefaultWebComponents = NULL;
  }
  if (! DefaultWebComponents)
  {
    DefaultWebComponents = new TWebComponentList(this);
    if (Grid)
      CreateDefaultButtonClasses(DefaultGridButtons, DefaultGridButtonsCount - 1, WebFieldControls);
    else
      CreateDefaultButtonClasses(DefaultFormButtons, DefaultFormButtonsCount - 1, WebFieldControls);
  }
}

AnsiString __fastcall TImgDataNavigator::ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout)
{
  AnsiString Path;
  TComponent * Button;
  long I;
  //TCustomWebDispatcher * Dispatcher;
  _di_IWebDispatcherAccess Dispatcher;
  // Initialize image paths
  Path = ImagePathURL;
  if (! (ComponentState.Contains(csDesigning) && (Path.Length() == 0)))
  {
    if (Path.Length() == 0)
    {
      Dispatcher = FindDispatcher(this);
      if (Dispatcher && Dispatcher->Request())
         Path = PathInfoToRelativePath(Dispatcher->Request()->PathInfo);
    }
  }
  for (I = 0; I < VisibleButtons()->Count; I++)
  {
    Button = VisibleButtons()->WebComponents[I];
    if (Button->InheritsFrom(__classid(TImgDataSetButton)))
      ((TImgDataSetButton*)Button)->SetPathURL(Path);
    else if (Button->InheritsFrom(__classid(TImgApplyUpdatesButton)))
      ((TImgApplyUpdatesButton*)Button)->SetPathURL(Path);
  }
  return inherited::ImplContent(Options, ParentLayout);
}

void __fastcall TImgDataNavigator::SetImagePathURL(const AnsiString Value)
{
  AnsiString NewValue;
  if (Value.Length() != 0)
  {
    NewValue = DosPathToUnixPath(Value);
    if (!IsDelimiter("/", NewValue, NewValue.Length()))
      NewValue = NewValue + "/";
  }
  FImagePathURL = NewValue;
}


AnsiString __fastcall TImgDataSetButton::GetAlt()
{
  if (FAlt.Length() == 0)
    return DefaultAlt;
  else
    return FAlt;
}

AnsiString __fastcall TImgDataSetButton::GetMethodName()
{
  return XMLMethodName;
}

AnsiString __fastcall TImgDataSetButton::GetSrc()
{
  if (FSrc.Length() == 0)
    return DefaultSrc;
  else
    return FSrc;
}

AnsiString __fastcall TImgDataSetButton::GetSrcUrl()
{
  return FPathURL + Src;
}

void __fastcall TImgDataSetButton::AddElements(_di_IAddScriptElements AddIntf)
{
  if ((XMLComponent == NULL) && (Name.Length() != 0))
    AddIntf->AddError(AnsiString().Format(sXMLComponentNotDefined, ARRAYOFCONST((Name))));
}

AnsiString __fastcall TImgDataSetButton::ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout)
{
  AnsiString Attrs;
  _di_ILayoutWebContent Intf;
  //AddQuotedAttrib(Attrs, 'NAME', Name);
  AddQuotedAttrib(Attrs, "STYLE", Style);
  AddQuotedAttrib(Attrs, "CLASS", StyleRule);
  AddQuotedAttrib(Attrs, "ALT", Alt);
  AddQuotedAttrib(Attrs, "SRC", GetSrcUrl());
  AddCustomAttrib(Attrs, Custom);
  if (! Border)
    AddStringAttrib(Attrs, "BORDER", "0");
  AnsiString Result;
  if (! Options->Flags.Contains(coNoScript))
  {
    Result =
      AnsiString().Format("<A HREF='' onclick='if(%3:s)%1:s.%2:s();return false;'><IMG %0:s/></A>\r\n",
        ARRAYOFCONST((Attrs, GetXmlDisplayName(), GetMethodName(), sXMLReadyVar)));
  }
  else
    Result =
      AnsiString().Format("<A><IMG %0:s/></A>\r\n",
        ARRAYOFCONST((Attrs)));
  if (ParentLayout && ParentLayout->GetInterface(__uuidof(ILayoutWebContent), &Intf))
    Result = Intf->LayoutButton(Result, GetLayoutAttributes());
  return Result;
}

void __fastcall TImgDataSetButton::SetPathURL(AnsiString APath)
{
  FPathURL = APath;
}

__fastcall TImgFirstButton::TImgFirstButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sFirstButton;
  DefaultSrc = "first.gif";
  XMLMethodName = "first";
}

__fastcall TImgLastButton::TImgLastButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sLastButton;
  DefaultSrc = "last.gif";
  XMLMethodName = "last";
}

__fastcall TImgPriorButton::TImgPriorButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sPriorButton;
  DefaultSrc = "prior.gif";
  XMLMethodName = "up";
}

__fastcall TImgNextButton::TImgNextButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sNextButton;
  DefaultSrc = "next.gif";
  XMLMethodName = "down";
}

__fastcall TImgPriorPageButton::TImgPriorPageButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sPriorPageButton;
  DefaultSrc = "priorpage.gif";
  XMLMethodName = "pgup";
}

__fastcall TImgNextPageButton::TImgNextPageButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sNextPageButton;
  DefaultSrc = "nextpage.gif";
  XMLMethodName = "pgdown";
}


__fastcall TImgUndoButton::TImgUndoButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sUndoButton;
  DefaultSrc = "undo.gif";
  XMLMethodName = "undo";
}

__fastcall TImgDeleteButton::TImgDeleteButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sDeleteButton;
  DefaultSrc = "delete.gif";
  XMLMethodName = "removeRow";
}

__fastcall TImgInsertButton::TImgInsertButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sInsertButton;
  DefaultSrc = "insert.gif";
  XMLMethodName = "newRow";
}

__fastcall TImgPostButton::TImgPostButton(Classes::TComponent* AOwner): TImgDataSetButton(AOwner)
{
  DefaultAlt = sPostButton;
  DefaultSrc = "post.gif";
  XMLMethodName = "post";
}

AnsiString __fastcall TImgApplyUpdatesButton::GetAlt()
{
  if (FAlt.Length() == 0)
    return DefaultAlt;
  else
    return FAlt;
}

AnsiString __fastcall TImgApplyUpdatesButton::GetSrc()
{
  if (FSrc.Length() == 0)
    return DefaultSrc;
  else
    return FSrc;
}

AnsiString __fastcall TImgApplyUpdatesButton::GetSrcUrl()
{
  return FPathURL + Src;
}

void __fastcall TImgApplyUpdatesButton::SetPathURL(AnsiString APath)
{
  FPathURL = APath;
}

__fastcall TImgApplyUpdatesButton::TImgApplyUpdatesButton(Classes::TComponent* AOwner): TApplyUpdatesButton(AOwner)
{
  DefaultAlt = sApplyUpdates;
  DefaultSrc = "applyupdates.gif";
}

AnsiString __fastcall TImgApplyUpdatesButton::ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout)
{
  AnsiString Attrs;
  _di_ILayoutWebContent Intf;
  AnsiString FormVarName;
  AnsiString RowSetVarName;

  AddQuotedAttrib(Attrs, "NAME", Name);
  AddQuotedAttrib(Attrs, "STYLE", Style);
  AddQuotedAttrib(Attrs, "CLASS", StyleRule);
  AddQuotedAttrib(Attrs, "ALT", Alt);
  AddQuotedAttrib(Attrs, "SRC", GetSrcUrl());
  AddCustomAttrib(Attrs, Custom);
  if (! Border)
    AddStringAttrib(Attrs, "BORDER", "0");
  if (XMLData->XMLBroker)
  {
    FormVarName = XMLData->XMLBroker->SubmitFormVarName();
    RowSetVarName = XMLData->XMLBroker->RowSetVarName(NULL);
  }
  AnsiString Result;
  if ( ! Options->Flags.Contains(coNoScript))
  {
    Result =
      AnsiString().Format("<A HREF='' onclick='if(%3:s)%1:s.Apply(%2:s, %2:s.postdelta);return false;'><IMG %0:s/></A>\r\n",
        ARRAYOFCONST((Attrs, RowSetVarName, FormVarName,sXMLReadyVar)));
  }
  else
    Result =
      AnsiString().Format("<A><IMG %0:s/></A>\r\n",
        ARRAYOFCONST((Attrs)));
  if (ParentLayout && ParentLayout->GetInterface(__uuidof(ILayoutWebContent), &Intf))
    Result = Intf->LayoutButton(Result, GetLayoutAttributes());
  return Result;
}



//---------------------------------------------------------------------------
