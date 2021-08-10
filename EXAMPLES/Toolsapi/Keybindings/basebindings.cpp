//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <assert.h>

#include "basebindings.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
/* utility functions */
IOTAEditBlock * __fastcall TBaseBindings::MarkWord(const _di_IOTAKeyContext Context)
{
  _di_IOTAEditPosition EP;
  _di_IOTAEditBlock EB;

  EP = Context->EditBuffer->EditPosition;
  EB = Context->EditBuffer->EditBlock;
  
  if (EP->IsWordCharacter)
    EP->MoveCursor(mmSkipLeft | mmSkipWord);
  if (EP->IsWhiteSpace)
    EP->MoveCursor(mmSkipRight | mmSkipWhite);
  if (!(EP->IsWhiteSpace))
  {
    if (!(EP->IsWordCharacter))
      EP->MoveCursor(mmSkipRight | mmSkipNonWord);
    if (EP->IsWordCharacter)
    {
      EB->Reset();
      EB->Style = btNonInclusive;
      EB->BeginBlock();
      EP->MoveCursor(mmSkipRight | mmSkipWord);
      EB->EndBlock();
    }
  }
  return Context->EditBuffer->EditBlock;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::SlideBlock(const _di_IOTAKeyContext Context, bool Backward)
{
  _di_IOTAEditBlock EB;
  int IndentAmount;

  EB = Context->EditBuffer->EditBlock;
  if (EB->Size != 0)
  {
    IndentAmount = Context->KeyboardServices->EditorServices->EditOptions->BlockIndent;
    if (Backward)
      IndentAmount = IndentAmount * -1;
    EB->Indent(IndentAmount);
  }
  else
    Context->EditBuffer->TopView->SetTempMsg(sNoBlockMarked);
};
//---------------------------------------------------------------------------
/* Default binding implementations */
void __fastcall TBaseBindings::AddWatchAtCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  HRESULT hr;
  _di_IOTAEditActions Temp;

  hr = Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &Temp);
  if (SUCCEEDED(hr))
  {
    Temp->AddWatchAtCursor();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::AutoCodeInsight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditPosition EP;
  _di_IOTAEditActions EA;
  HRESULT hr;
  Char AChar;

  EP = Context->EditBuffer->EditPosition;
  hr = Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    AChar = char(Context->Context);
    EP->InsertCharacter(AChar);
    switch (AChar)
    {
      case '.':
      case '>':
      {
        EA->CodeCompletion(csCodelist);
        break;
      }
      case '(':
      {
        EA->CodeCompletion(csParamList);
        break;
      }
    }
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::BrowseSymbolAtCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->BrowseSymbolAtCursor();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::BlockSave(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->EditBlock->SaveToFile("");
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::ClassNavigate(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->ClassNavigate(0);
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::ClassComplete(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->ClassComplete();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::ClipClear(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->EditBlock->Delete();
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::ClipCopy(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->EditBlock->Copy(false);
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::ClipCut(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->EditBlock->Cut(false);
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::ClipPaste(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->EditPosition->Paste();
  BindingResult = krHandled;

};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::CodeTemplate(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->CodeTemplate();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::CodeCompletion(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->CodeCompletion((unsigned char)Context->Context);
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::DebugInspect(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->InspectAtCursor();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::GotoLine(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->EditPosition->GotoLine(0);
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::HelpKeyword(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->HelpKeyword();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::IncrementalSearch(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->IncrementalSearch();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::InsertCompilerOptions(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->InsertCompilerOptions();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::InsertNewGUID(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->InsertNewGUID();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::NullCmd(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::OpenFileAtCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->OpenFileAtCursor();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::OpenLine(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditPosition EP;

  EP = Context->EditBuffer->EditPosition;
  EP->Save();
  __try
  {
    EP->InsertCharacter(10);
  }
  __finally
  {
    EP->Restore();
  }
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::Print(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->Print();
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::SetBlockStyle(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  TOTABlockType Style;

  Style = TOTABlockType(Context->Context);
  assert((Style >= btInclusive) && (Style < btUnknown)); /* do not localize */
  Context->EditBuffer->EditBlock->Style = Style;
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::SearchAgain(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->EditPosition->RepeatLastSearchOrReplace();
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::SearchFind(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->EditPosition->Search();
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::SearchReplace(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  Context->EditBuffer->EditPosition->Replace();
  BindingResult = krHandled;
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::SwapCPPHeader(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->SwapCPPHeader();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------
void __fastcall TBaseBindings::ViewExplorer(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                           TKeyBindingResult &BindingResult)
{
  _di_IOTAEditActions EA;
  HRESULT hr;

  Context->EditBuffer->TopView->QueryInterface(__uuidof(IOTAEditActions), (void **) &EA);
  if (SUCCEEDED(hr))
  {
    EA->ViewExplorer();
    BindingResult = krHandled;
  }
};
//---------------------------------------------------------------------------

