//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <menus.hpp>

#include "bufferlist.h"
#include "bufferlistform.h"
#include "savekeymacro.h"
#include "strindx.rh"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace Bufferlist
{
  const BOOKMARK_ID_SYSTEM_ONE   = 19;
  const BOOKMARK_ID_SYSTEM_TWO   = 18;
  const BOOKMARK_ID_SYSTEM_THREE = 17;

  void __fastcall PACKAGE Register()
  {
    _di_IOTAKeyboardServices Temp;
    HRESULT hr;

    Temp = BorlandIDEServices;
    if (Temp)
    {
      Temp->AddKeyboardBinding(new TBufferList);
      Temp->AddKeyboardBinding(new TClassicBinding);
    }
  }
  //---------------------------------------------------------------------------
  void __fastcall TBufferList::BufferListProc(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult)
  {
    int i;
    _di_IInterfaceList InterfaceList;
    _di_IOTAEditBufferIterator Iter;
    _di_IOTAEditBuffer Buffer;
    _di_IOTAEditBuffer Temp;
    TBufferListFrm *Form = new TBufferListFrm(Application);
    HRESULT hr;

    __try
    {
      InterfaceList = *(new TInterfaceList());
      Context->KeyboardServices->EditorServices->GetEditBufferIterator(Iter);
      for(i = 0; i < Iter->Count; i++)
      {
        Buffer = Iter->EditBuffers[i];
        InterfaceList->Add(Buffer);
        Form->BufferListBox->Items->Add(Buffer->FileName);
      }
      if (Form->BufferListBox->Items->Count > 1)
        Form->BufferListBox->ItemIndex = 1;
      else
        Form->BufferListBox->ItemIndex = 0;
      Iter = NULL;                  
      if (Form->ShowModal() == mrOk)
      {
        hr = InterfaceList->Items[Form->BufferListBox->ItemIndex]->QueryInterface(__uuidof(IOTAEditBuffer), (void **) &Temp);
        if (SUCCEEDED(hr))
          Temp->Show();
      }
    }
    __finally
    {
      delete Form;
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  /* IOTAKeyBoardBinding */
  TBindingType __fastcall TBufferList::GetBindingType(void)
  {
    return btPartial;
  };
  //---------------------------------------------------------------------------
  AnsiString __fastcall TBufferList::GetDisplayName(void)
  {
    return LoadStr(sBufferList);
  };
  //---------------------------------------------------------------------------
  AnsiString __fastcall TBufferList::GetName(void)
  {
    return "Borland.BufferList";  //do not localize
  };
  //---------------------------------------------------------------------------
  void __fastcall TBufferList::BindKeyboard(const _di_IOTAKeyBindingServices BindingServices)
  {
    Classes::TShortCut Shortcuts[1];
    TShiftState sState;

    sState << ssCtrl;                                 
    Shortcuts[0] = Menus::ShortCut('B', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, BufferListProc, NULL, kfImplicit, "", "");
  };
  //---------------------------------------------------------------------------
  
  /* TClassicBinding */

  void __fastcall TClassicBinding::AdjustBlockCase(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;

    EB = Context->EditBuffer->EditBlock;
    if (EB->Size != 0)
    {
      if (Context->Context != NULL)
        EB->LowerCase();
      else
        EB->UpperCase();
    }
    else
      Context->EditBuffer->TopView->SetTempMsg(sNoBlockMarked);
    BindingResult = krHandled;    
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::AdjustWordCase(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;
    _di_IOTAEditView EV;
    bool Blocked;

    EV = Context->EditBuffer->TopView;
    EB = EV->Block;
    if (EB->Size != 0)
    {
      EB->Save();
      Blocked = true;
    }
    else
      Blocked = false;
    __try
    {
      EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_ONE);
      __try
      {
        if (reinterpret_cast<LongBool>(Context->Context))
          MarkWord(Context)->LowerCase();
        else
          MarkWord(Context)->UpperCase();
        EB->Reset();
      }
      __finally
      {
        EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_ONE);
      }
    }
    __finally
    {
      if (Blocked)
        EB->Restore();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::BackspaceDelete(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->BackspaceDelete(1);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicBlockDelete(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;
    _di_IOTAEditView EV;
  
    EV = Context->EditBuffer->TopView;
    EB = EV->Block;
    if (EB->Size != 0)
    {
      EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_ONE);
      EB->Delete();
      EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_ONE);
      EV->SetTempMsg(LoadStr(sBlockDeleted));
    }
    else
      EV->SetTempMsg(sNoBlockMarked);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicDeleteLine(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditView EV;
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;
    bool Blocked;
    TOTABlockType Style;

    EV = Context->EditBuffer->TopView;
    EP = EV->Position;
    EB = EV->Block;
    if (EB->Size != 0)
    {
      EB->Save();
      __try
      {
        EP->Save();
        __try
        {
          EP->Move(EB->StartingRow, EB->StartingColumn);
          EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_ONE);
          EP->Move(EB->EndingRow, EB->EndingColumn);
          EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_TWO);
          Blocked = true;
        }
        __finally
        {
          EP->Restore();
        }
      }
      __finally
      {
        EB->Restore();
      }
    }
    else
      Blocked = false;
    __try
    {
      Style = EB->Style;
      __try
      {
        EP->MoveBOL();
        EP->Save();
        __try
        {
          EB->Reset();
          EB->Style = btLine;
          EB->BeginBlock();
          EB->Delete();
        }
        __finally
        {
          EP->Restore();
        }
      }
      __finally
      {
        EB->Style = Style;
      }
    }
    __finally
    {
      if (Blocked)
      {
        EP->Save();
        __try
        {
          EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_ONE);
          EB->BeginBlock();
          EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_TWO);
          EB->EndBlock();
        }
        __finally
        {
          EP->Restore();
        }
      }
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicMarkWord(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;

    EP = Context->EditBuffer->EditPosition;
    if (!(EP->IsWordCharacter))
      WordLeft(Context, KeyCode, BindingResult);
    MarkWord(Context);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicMarkToViewBottom(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditView EV;
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;

    EV = Context->EditBuffer->TopView;
    EP = EV->Position;
    EB = EV->Block;
    if ((EB->EndingRow == EP->Row) && (EB->EndingColumn == EP->Column))
    {
  //    EB->Style = btNonInclusive;
      EP->Move(EB->StartingRow, EB->StartingColumn);
      EB->BeginBlock();
      EB->Extend(EV->BottomRow - 1, EP->Column);
      EB->EndBlock();
    }
    else
    {
      EB->Reset();
  //    EB->Style = btNonInclusive;
      EB->BeginBlock();
      EB->Extend(EV->BottomRow - 1, EP->Column);
      EB->EndBlock();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicMarkToViewTop(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditView EV;
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;

    EV = Context->EditBuffer->TopView;
    EP = EV->Position;
    EB = EV->Block;
    if ((EB->StartingRow == EP->Row) && (EB->StartingColumn == EP->Column))
    {
  //    EB->Style = btNonInclusive;
      EP->Move(EB->EndingRow, EB->EndingColumn);
      EB->EndBlock();
      EB->Extend(EV->TopRow, EP->Column);
      EB->BeginBlock();
    }
    else
    {
      EB->Reset();
  //    EB->Style = btNonInclusive;
      EB->EndBlock();
      EB->Extend(EV->TopRow, EP->Column);
      EB->BeginBlock();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicMarkToBOF(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditView EV;
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;

    EV = Context->EditBuffer->TopView;
    EP = EV->Position;
    EB = EV->Block;
    if ((EB->StartingRow == EP->Row) && (EB->StartingColumn == EP->Column))
    {
  //    EB->Style = btNonInclusive;
      EP->Move(EB->EndingRow, EB->EndingColumn);
      EB->EndBlock();
      EP->Move(1, 1);
      EB->BeginBlock();
    }
    else
    {
      EB->Reset();
  //    EB->Style = btNonInclusive;
      EB->EndBlock();
      EP->Move(1, 1);
      EB->BeginBlock();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicMarkToBOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditView EV;
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;
    int EndRow, EndCol;

    EV = Context->EditBuffer->TopView;
    EP = EV->Position;
    EB = EV->Block;
    EB->Save();
    __try
    {
      EP->Save();
      __try
      {
        EP->MoveBOL();
        EndRow = EP->Row;
        EndCol = EP->Column;
      }
      __finally
      {
        EP->Restore();
      }
    }
    __finally
    {
      EB->Restore();
    }
    EB->Extend(EndRow, EndCol);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicMarkToEOF(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditView EV;
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;

    EV = Context->EditBuffer->TopView;
    EP = EV->Position;
    EB = EV->Block;
    if ((EB->StartingRow == EP->Row) && (EB->StartingColumn == EP->Column))
    {
  //    EB->Style = btNonInclusive;
      EP->Move(EB->StartingRow, EB->StartingColumn);
      EB->EndBlock();
      EP->MoveEOF();
      EB->BeginBlock();
    }
    else
    {
      EB->Reset();
  //    EB->Style = btNonInclusive;
      EB->EndBlock();
      EP->MoveEOF();
      EB->BeginBlock();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicMarkToEOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditView EV;
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;
    int EndRow, EndCol;

    EV = Context->EditBuffer->TopView;
    EP = EV->Position;
    EB = EV->Block;
    EB->Save();
    __try
    {
      EP->Save();
      __try
      {
        EP->MoveEOL();
        EndRow = EP->Row;
        EndCol = EP->Column;
      }
      __finally
      {
        EP->Restore();
      }
    }
    __finally
    {
      EB->Restore();
    }
    EB->Extend(EndRow, EndCol);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicMoveBlock(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;
    _di_IOTAEditView EV;
    int NewRow, NewColumn;

    EP = Context->EditBuffer->EditPosition;
    EB = Context->EditBuffer->EditBlock;
    EV = Context->EditBuffer->TopView;
    if (EB->Size != 0)
    {
      EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_ONE);
      EB->Save();
      __try
      {
        EP->Move(EB->StartingRow, EB->StartingColumn);
      }
      __finally
      {
        EB->Restore();
      }
      EB->Cut(false);
      EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_ONE);
      NewRow = EP->Row;
      NewColumn = EP->Column;
      EP->Paste();
      EP->Move(NewRow, NewColumn);
      EB->BeginBlock();
      EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_ONE);
      EB->Extend(EP->Row, EP->Column);
      EB->Save();
      __try
      {
        EP->Move(NewRow, NewColumn);
      }
      __finally
      {
        EB->Restore();
      }
      EV->SetTempMsg(LoadStr(sBlockMoved));
    }
    else
      EV->SetTempMsg(LoadStr(sNoBlockMarked));
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ClassicToggleCase(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;
    bool Blocked;

    EB = Context->EditBuffer->EditBlock;
    EP = Context->EditBuffer->EditPosition;
    if (EB->Size != 0)
    {
      EB->Save();
      Blocked = true;
    }
    else
      Blocked = false;
    __try
    {
      if (((EP->Column <= EB->EndingColumn) && (EP->Row <= EB->EndingRow)) &&
        ((EP->Column >= EB->StartingColumn) && (EP->Row >= EB->StartingRow)))
        EB->ToggleCase();
      else
      {
        EB->BeginBlock();
        EP->MoveRelative(0, 1);
        EB->EndBlock();
        EB->ToggleCase();
        EB->Reset();
      }
    }
    __finally
    {
      if (Blocked)
        EB->Restore();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::CopyBlock(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;

    EB = Context->EditBuffer->EditBlock;
    if (EB->Size != 0)
    {
      EB->Copy(false);
      Context->EditBuffer->EditPosition->Paste();
      Context->EditBuffer->TopView->SetTempMsg(LoadStr(sBlockCopied));
    }
    else
      Context->EditBuffer->TopView->SetTempMsg(LoadStr(sNoBlockMarked));
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::CursorLeft(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveRelative(0, -1);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::CursorRight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveRelative(0, 1);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::DeleteChar(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->Delete(1);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::DeleteToEOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
      _di_IOTAEditPosition Pos;
      _di_IOTAEditBlock Block;

      Pos = Context->EditBuffer->EditPosition;
      Block = Context->EditBuffer->EditBlock;
      Block->Visible = False;
      Block->Save();
      __try
      {
        Block->Style = btNonInclusive;
        Block->BeginBlock();
        Pos->MoveEOL();
        Block->EndBlock();
        Block->Delete();
      }
      __finally
      {
        Block->Restore();
      }
      BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::DeleteWordLeft(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;
    _di_IOTAEditView EV;
    bool Blocked;

    EV = Context->EditBuffer->TopView;
    EB = EV->Block;
    EP = EV->Position;
    if ((EB->Style != btNonInclusive) || (EB->Size != 0))
    {
      EB->Save();
      __try
      {
        EP->Save();
        __try
        {
          EP->Move(EB->StartingRow, EB->StartingColumn);
          EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_ONE);
          EP->Move(EB->EndingRow, EB->EndingColumn);
          EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_TWO);
        }
        __finally
        {
          EP->Restore();
        }
      }
      __finally
      {
        EB->Restore();
      }
      Blocked = true;
    }
    else
      Blocked = false;
    EB->Style = btNonInclusive;
    EB->Reset();
    EB->EndBlock();
    EP->MoveCursor(mmSkipLeft | mmSkipNonWord);
    EP->MoveCursor(mmSkipLeft | mmSkipWord);
    EB->BeginBlock();
    EB->Delete();
    if (Blocked)
    {
      EB->Style = btNonInclusive;
      EP->Save();
      __try
      {
        EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_ONE);
        EB->BeginBlock();
        EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_TWO);
        EB->EndBlock();
      }
      __finally
      {
        EP->Restore();
      }
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::DeleteWordRight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;
    _di_IOTAEditView EV;
    bool Blocked;
    int C, SpaceAdjust;
    
    EV = Context->EditBuffer->TopView;
    EB = EV->Block;
    EP = EV->Position;
    if ((EB->Style != btNonInclusive) || (EB->Size != 0))
    {
      EB->Save();
      __try
      {
        EP->Save();
        __try
        {
          EP->Move(EB->StartingRow, EB->StartingColumn);
          EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_ONE);
          EP->Move(EB->EndingRow, EB->EndingColumn);
          EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_TWO);
        }
        __finally
        {
          EP->Restore();
        }
      }
      __finally
      {
        EB->Restore();
      }
      Blocked = true;
    }
    else
      Blocked = false;

    EB->Style = btNonInclusive;
    EB->Reset();
    EB->BeginBlock();
    SpaceAdjust = 0;
    EV->BookmarkRecord(BOOKMARK_ID_SYSTEM_THREE);

    if (EP->IsWhiteSpace)
    {
      if (EP->Character == 0x9)
      {
        C = EP->Column;
        EP->Delete(1);
        if (C != EP->Column)
          SpaceAdjust = C - EP->Column;
      }
      EP->MoveCursor(mmSkipRight | mmSkipWhite);
    }
    else if (EP->IsWordCharacter)
    {
      EP->MoveCursor(mmSkipRight | mmSkipWord);
      EP->MoveCursor(mmSkipRight | mmSkipWhite);
    }
    else if (EP->IsSpecialCharacter)
    {
      EP->Delete(1);
      EP->MoveCursor(mmSkipRight | mmSkipWhite);
    }
    else
      EP->Delete(1);
    EB->EndBlock();
    EB->Delete();
    while (SpaceAdjust > 0)
    {
      EP->InsertCharacter(' ');
      --SpaceAdjust;
    }
    if (Blocked)
    { 
      EB->Style = btNonInclusive;
      EP->Save();
      __try
      {
        EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_ONE);
        EB->BeginBlock();
        EV->BookmarkGoto(BOOKMARK_ID_SYSTEM_TWO);
        EB->EndBlock();
      }
      __finally
      {
        EP->Restore();
      }
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::EndCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->Move(Context->EditBuffer->TopView->BottomRow, 0);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::GotoBookmark(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->TopView->BookmarkGoto(reinterpret_cast<int>(Context->Context));
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::HomeCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->Move(Context->EditBuffer->TopView->TopRow, 0);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::IndentBlock(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    SlideBlock(Context, reinterpret_cast<LongBool>(Context->Context));
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::InsertCharacter(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->InsertCharacter(reinterpret_cast<int>(Context->Context));
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::InsertFile(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;

    EP = Context->EditBuffer->EditPosition;
    EP->Save();
    __try
    {
      EP->InsertFile("");
    }
    __finally
    {
      EP->Restore();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::InsertLiteralKey(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->KeyboardServices->PushKeyboard("LiteralKeyTable"); /* do not localize */
    Context->EditBuffer->TopView->SetTempMsg(LoadStr(sInsertLiteralChar));
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::InsertTab(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;
    _di_IOTABufferOptions EO;

    EP = Context->EditBuffer->EditPosition;
    EO = Context->EditBuffer->BufferOptions;
    if (!(EO->InsertMode))
      EP->Tab(1);
    else if (EO->SmartTab)
      EP->Align(1);
    else
      EP->InsertCharacter(0x9);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::LineDown(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveRelative(1, 0);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::LineUp(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveRelative(-1, 0);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::LiteralKeyProc(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Word Key;
    TShiftState Shift;
    TShiftState TestSet;
    char InsertChar;

    ShortCutToKey(KeyCode, Key, Shift);
    TestSet << ssCtrl;
    if (Shift == TestSet)
    {
      if ((Key >= 0x40) && (Key < 0x5F))
      {
        Key = Key - 0x40;
        Shift.Clear();
      }
      else if ((Key >= 0x60) && (Key < 0x7F))
      {
        Key = Key - 0x60;
        Shift.Clear();
      }
    }
    TestSet.Clear();
    if (Shift == TestSet)
    {
      InsertChar = Key & 0x00FF; 
      Context->EditBuffer->EditPosition->InsertCharacter(InsertChar);
    }
    Context->EditBuffer->TopView->SetTempMsg(LoadStr(sLiteralKeyInserted));
    Context->KeyboardServices->PopKeyboard("LiteralKeyTable"); /* do not localize */
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::LoadKeyMacro(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAKeyboardServices KS;
    _di_IStream Stream;
    TSaveKeyMacroDlg *MacroDlg;

    KS = Context->KeyboardServices;
    if ((!(KS->CurrentPlayback->IsPlaying)) && (!(KS->CurrentRecord->IsRecording)))
    {
      MacroDlg = new TSaveKeyMacroDlg(Application);
      __try
      {
        if (MacroDlg->OpenDialog1->Execute())
        {
          try
          {
            Stream = *(new TStreamAdapter(new TFileStream(MacroDlg->OpenDialog1->FileName,
                                                        fmOpenRead | fmShareDenyWrite), soOwned));
            KS->CurrentPlayback->Clear();
            KS->CurrentPlayback->ReadFromStream(Stream);
          }
          catch(...)
          {
            Application->HandleException(dynamic_cast<TObject *>(this));
          }
        }
      }
      __finally
      {
        delete MacroDlg;
      }
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MarkBlockBegin(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;
    _di_IOTAEditPosition EP;
    _di_IOTAEditView EV;
    int EndCol, EndRow;
    int TopRow, LeftCol;

    EB = Context->EditBuffer->EditBlock;
    EP = Context->EditBuffer->EditPosition;
    EV = Context->EditBuffer->TopView;
    if ((EB->Style != btNonInclusive) || (EB->Size != 0))
    {
      TopRow = EV->TopRow;
      LeftCol = EV->LeftColumn;
      EndCol = EB->EndingColumn;
      EndRow = EB->EndingRow;
      if (EP->Row == EndRow)
        if (EP->Column >= EndCol)
          EndCol = EP->Column;
      if (EP->Row > EndRow)
        EndRow = EP->Row;
      EP->Save();
      __try
      {
        EB->Reset();
        EB->BeginBlock();
        EB->Style = btNonInclusive;
        EP->Move(EndRow, EndCol);
        EB->EndBlock();
      }
      __finally
      {
        EP->Restore();
      }
      EV->SetTopLeft(TopRow, LeftCol);
    }
    else
    {
      EB->Reset();
      EB->BeginBlock();
      EB->Style = btNonInclusive;
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MarkBlockEnd(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;
    _di_IOTAEditPosition EP;
    int StartRow, StartCol;

    EB = Context->EditBuffer->EditBlock;
    EP = Context->EditBuffer->EditPosition;
    if ((EB->Style != btNonInclusive) || (EB->Size != 0))
    {
      StartCol = EB->StartingColumn;
      StartRow = EB->StartingRow;
      if (EP->Row == StartRow)
        if (EP->Column <= StartCol)
          StartCol = EP->Column;
      if (EP->Row < StartRow)
        StartRow = EP->Row;
      EP->Save();
      __try
      {
        EP->Move(StartRow, StartCol);
        EB->Reset();
        EB->BeginBlock();
        EB->Style = btNonInclusive;
      }
      __finally
      {
        EP->Restore();
      }
    }
    EB->EndBlock();
    EB->Style = btNonInclusive;
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MarkLine(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;
    _di_IOTAEditBlock EB;

    EP = Context->EditBuffer->EditPosition;
    EB = Context->EditBuffer->EditBlock;
    EP->Save();
    __try
    {
      EP->Move(0, 1);
      EB->Style = btNonInclusive;
      EB->BeginBlock();
      EP->MoveRelative(1, 0);
      EB->EndBlock();
    }
    __finally
    {
      EP->Restore();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MarkToPageDown(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditBlock->ExtendPageDown();
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MarkToPageUp(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditBlock->ExtendPageUp();
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MarkToRelativeHoriz(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditBlock->ExtendRelative(0, reinterpret_cast<int>(Context->Context));
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MarkToRelativeVert(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditBlock->ExtendRelative(reinterpret_cast<int>(Context->Context), 0);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MarkToWordLeft(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;
    _di_IOTAEditPosition EP;
    int NewRow, NewColumn;

    EB = Context->EditBuffer->EditBlock;
    EP = Context->EditBuffer->EditPosition;
    EP->Save();
    __try
    {
      EB->Save();
      __try
      {
        WordLeft(Context, KeyCode, BindingResult);
        NewRow = EP->Row;
        NewColumn = EP->Column;
      }
      __finally
      {
        EB->Restore();
      }
    }
    __finally
    {
      EP->Restore();
    }
    EB->Extend(NewRow, NewColumn);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MarkToWordRight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;
    _di_IOTAEditPosition EP;
    int NewRow, NewColumn;

    EB = Context->EditBuffer->EditBlock;
    EP = Context->EditBuffer->EditPosition;
    EP->Save();
    __try
    {
      EB->Save();
      __try
      {
        WordRight(Context, KeyCode, BindingResult);
        NewRow = EP->Row;
        NewColumn = EP->Column;
      }
      __finally
      {
        EB->Restore();
      }
    }
    __finally
    {
      EP->Restore();
    }
    EB->Extend(NewRow, NewColumn);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveCursorHorizontal(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveRelative(0, reinterpret_cast<int>(Context->Context));
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveCursorToBOF(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveCursorToBOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveBOL();
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveCursorToEOF(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveEOF();
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveCursorToEOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveEOL();
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveCursorToLastEdit(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;
    _di_IOTAEditView EV;

    EP = Context->EditBuffer->EditPosition;
    EV = Context->EditBuffer->TopView;
    EP->Move(EV->GetLastEditRow(), EV->GetLastEditColumn());
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveCursorToMarkBegin(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;

    EB = Context->EditBuffer->EditBlock;
    if (EB->Visible && (EB->Size != 0))
    {
      EB->Save();
      __try
      {
        Context->EditBuffer->EditPosition->Move(EB->StartingRow, EB->StartingColumn);
      }
      __finally
      {
        EB->Restore();
      }
    }
    else
      Context->EditBuffer->TopView->SetTempMsg(sNoBlockMarked);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveCursorToMarkEnd(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditBlock EB;

    EB = Context->EditBuffer->EditBlock;
    if (EB->Visible && (EB->Size != 0))
    {
      EB->Save();
      __try
      {
        Context->EditBuffer->EditPosition->Move(EB->EndingRow, EB->EndingColumn);
      }
      __finally
      {
        EB->Restore();
      }
    }
    else
      Context->EditBuffer->TopView->SetTempMsg(sNoBlockMarked);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveCursorVertical(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveRelative(reinterpret_cast<int>(Context->Context), 0);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveLineViewBottom(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditView EV;
    int Row, TopRow, BottomRow, Height;

    EV = Context->EditBuffer->TopView;
    Row = EV->Position->GetRow();
    TopRow = EV->TopRow;
    BottomRow = EV->BottomRow;
    Height = BottomRow - TopRow;
    if (Row > Height)
      EV->SetTopLeft(Row - (Height - 1), 0);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::MoveLineViewTop(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditView EV;

    EV = Context->EditBuffer->TopView;
    EV->SetTopLeft(EV->Position->Row, 0);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::PageDown(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->TopView->PageDown();
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::PageUp(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->TopView->PageUp();
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::SetBookmark(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->TopView->BookmarkToggle(reinterpret_cast<int>(Context->Context));
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::Scroll(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAEditPosition EP;
    _di_IOTAEditView EV;
    int Delta;
    
    EV = Context->EditBuffer->TopView;
    EP = EV->Position;
    Delta = reinterpret_cast<int>(Context->Context);
    EV->Scroll(Delta, 0);
    if (EP->Row >= EV->GetBottomRow())
    {
      EP->Move(EP->Row - 1, EP->Column);
      EV->MoveViewToCursor();
    }
    if (EP->Row < EV->GetTopRow())
    {
      EP->Move(EP->Row + 1, EP->Column);
      EV->MoveViewToCursor();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ToggleBlock(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditBlock->Visible = !(Context->EditBuffer->EditBlock->Visible);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ToggleInsertMode(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTABufferOptions EO;

    EO = Context->KeyboardServices->EditorServices->EditOptions->BufferOptions;
    EO->InsertMode = !EO->InsertMode;
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::ToggleMacroRecord(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    _di_IOTAKeyboardServices KS;
    _di_IStream Stream;
    TSaveKeyMacroDlg *MacroDlg; 

    KS = Context->KeyboardServices;
    if (!(KS->CurrentPlayback->IsPlaying))
    {
      if (KS->CurrentRecord->IsRecording)
      {
        KS->ResumeRecord();
        MacroDlg = new TSaveKeyMacroDlg(Application);
        try
        {
          if (MacroDlg->ShowModal() == mrOk)
          try
          {
            Stream = *(new TStreamAdapter(new TFileStream(MacroDlg->Edit1->Text, fmCreate), soOwned));
            KS->CurrentRecord->WriteToStream(Stream);
          }
          catch (...)
          {
            Application->HandleException(dynamic_cast<TObject *>(this));
          }
        }
        __finally
        {
          delete MacroDlg;
        }
      }
      else
        KS->ResumeRecord();
    }
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::WordLeft(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveCursor(mmSkipLeft | mmSkipNonWord);
    Context->EditBuffer->EditPosition->MoveCursor(mmSkipLeft | mmSkipWord | mmSkipStream);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::WordRight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                  TKeyBindingResult &BindingResult)
  {
    Context->EditBuffer->EditPosition->MoveCursor(mmSkipRight | mmSkipWord | mmSkipStream);
    Context->EditBuffer->EditPosition->MoveCursor(mmSkipRight | mmSkipNonWord);
    BindingResult = krHandled;
  };
  //---------------------------------------------------------------------------
  TBindingType __fastcall TClassicBinding::GetBindingType(void)
  {
    return btComplete;
  };
  //---------------------------------------------------------------------------
  AnsiString __fastcall TClassicBinding::GetDisplayName(void)
  {
    return LoadStr(sNewIDEClassic);
  };
  //---------------------------------------------------------------------------
  AnsiString __fastcall TClassicBinding::GetName(void)
  {
    return "Borland.NewClassic"; /* do not localize */
  };
  //---------------------------------------------------------------------------
  void __fastcall TClassicBinding::BindKeyboard(const _di_IOTAKeyBindingServices BindingServices)
  {
    Classes::TShortCut Shortcuts[2];
    TShiftState sState;

    using Menus::ShortCut;

    sState << ssAlt;
    Shortcuts[0] = ShortCut(VK_F5, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, DebugInspect, NULL, kfImplicit, "", "");
    sState.Clear();

    sState << ssCtrl;
    Shortcuts[0] = ShortCut(VK_F1, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, HelpKeyword, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_F7, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, AddWatchAtCursor, NULL, kfImplicit, "", "");

    BindingServices->AddMenuCommand(mcAddWatchAtCursor, AddWatchAtCursor, NULL);
    BindingServices->AddMenuCommand(mcInspectAtCursor, DebugInspect, NULL);

    Shortcuts[0] = ShortCut('A', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, WordLeft, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('C', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, PageDown, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('D', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, CursorRight, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('E', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, LineUp, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('F', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, WordRight, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('G', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, DeleteChar, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('H', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, BackspaceDelete, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('I', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, InsertTab, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('J', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, CodeTemplate, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('L', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, SearchAgain, NULL, kfImplicit, "", "SearchAgainItem");
    Shortcuts[0] = ShortCut('R', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, PageUp, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('S', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, CursorLeft, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('T', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, DeleteWordRight, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('V', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ToggleInsertMode, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('W', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, Scroll, Pointer(-1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('X', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, LineDown, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Y', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassicDeleteLine, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Z', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, Scroll, Pointer(1), kfImplicit, "", "");
    BindingServices->AddMenuCommand(mcRepeatSearch, SearchAgain, NULL);

    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('B', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MarkBlockBegin, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('C', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, CopyBlock, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('E', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, AdjustWordCase, Pointer(1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('F', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, AdjustWordCase, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('H', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, ToggleBlock, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('I', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, IndentBlock, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('K', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MarkBlockEnd, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('L', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MarkLine, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('N', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, AdjustBlockCase, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('O', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, AdjustBlockCase, Pointer(1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('P', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, Print, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('R', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, InsertFile, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('T', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, ClassicMarkWord, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('U', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, IndentBlock, Pointer(1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('V', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, ClassicMoveBlock, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('W', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, BlockSave, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('Y', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, ClassicBlockDelete, NULL, kfImplicit, "", "");

    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    /* sState should be [ssCtrl] up to here */
    sState.Clear();
    Shortcuts[1] = ShortCut('O', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, NULL, kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('1', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(1), kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('2', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(2), kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('3', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(3), kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('4', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(4), kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('5', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(5), kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('6', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(6), kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('7', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(7), kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('8', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(8), kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('9', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(9), kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('0', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, NULL, kfImplicit, "", "");

    sState << ssCtrl;
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('1', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('2', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(2), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('3', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(3), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('4', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(4), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('5', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(5), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('6', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(6), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('7', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(7), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('8', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(8), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('K', sState);
    Shortcuts[1] = ShortCut('9', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBookmark, Pointer(9), kfImplicit, "", "");

    Shortcuts[0] = ShortCut('N', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, OpenLine, NULL, kfImplicit, "", "");

    Shortcuts[0] = ShortCut('O', sState);
    Shortcuts[1] = ShortCut('A', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, OpenFileAtCursor, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('O', sState);
    Shortcuts[1] = ShortCut('B', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, BrowseSymbolAtCursor, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('O', sState);
    Shortcuts[1] = ShortCut('C', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBlockStyle, Pointer(btColumn), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('O', sState);
    Shortcuts[1] = ShortCut('G', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoLine, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('O', sState);
    Shortcuts[1] = ShortCut('I', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBlockStyle, Pointer(btInclusive), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('O', sState);
    Shortcuts[1] = ShortCut('K', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBlockStyle, Pointer(btNonInclusive), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('O', sState);
    Shortcuts[1] = ShortCut('L', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SetBlockStyle, Pointer(btLine), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('O', sState);
    Shortcuts[1] = ShortCut('O', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, InsertCompilerOptions, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('O', sState);
    Shortcuts[1] = ShortCut('U', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, ClassicToggleCase, NULL, kfImplicit, "", "");
    BindingServices->AddMenuCommand(mcGotoLine, GotoLine, NULL);

    Shortcuts[0] = ShortCut('P', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, InsertLiteralKey, NULL, kfImplicit, "", "");

    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('A', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SearchReplace, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('B', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MoveCursorToMarkBegin, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('C', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MoveCursorToEOF, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('D', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MoveCursorToEOL, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('E', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, HomeCursor, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('F', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, SearchFind, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('G', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, NullCmd, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('H', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, NullCmd, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('I', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, NullCmd, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('J', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, NullCmd, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('K', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MoveCursorToMarkEnd, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('P', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MoveCursorToLastEdit, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('R', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MoveCursorToBOF, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('S', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MoveCursorToBOL, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('T', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MoveLineViewTop, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('U', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, MoveLineViewBottom, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('X', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, EndCursor, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('Y', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, DeleteToEOL, NULL, kfImplicit, "", "");

    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('O', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, NULL, kfImplicit, "", "");

    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('1', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(1), kfImplicit, "", "");
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('2', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(2), kfImplicit, "", "");
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('3', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(3), kfImplicit, "", "");
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('4', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(4), kfImplicit, "", "");
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('5', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(5), kfImplicit, "", "");
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('6', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(6), kfImplicit, "", "");
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('7', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(7), kfImplicit, "", "");
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('8', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(8), kfImplicit, "", "");
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    sState.Clear();
    Shortcuts[1] = ShortCut('9', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(9), kfImplicit, "", "");
    sState << ssCtrl;
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('0', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('1', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('2', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(2), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('3', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(3), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('4', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(4), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('5', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(5), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('6', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(6), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('7', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(7), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('8', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(8), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('Q', sState);
    Shortcuts[1] = ShortCut('9', sState);
    BindingServices->AddKeyBinding(Shortcuts, 1, GotoBookmark, Pointer(9), kfImplicit, "", "");

    BindingServices->AddMenuCommand(mcReplace, SearchReplace, NULL);
    BindingServices->AddMenuCommand(mcGetFindString, SearchFind, NULL);
    BindingServices->AddMenuCommand(mcMoveToMark0, GotoBookmark, NULL);
    BindingServices->AddMenuCommand(mcMoveToMark1, GotoBookmark, Pointer(1));
    BindingServices->AddMenuCommand(mcMoveToMark2, GotoBookmark, Pointer(2));
    BindingServices->AddMenuCommand(mcMoveToMark3, GotoBookmark, Pointer(3));
    BindingServices->AddMenuCommand(mcMoveToMark4, GotoBookmark, Pointer(4));
    BindingServices->AddMenuCommand(mcMoveToMark5, GotoBookmark, Pointer(5));
    BindingServices->AddMenuCommand(mcMoveToMark6, GotoBookmark, Pointer(6));
    BindingServices->AddMenuCommand(mcMoveToMark7, GotoBookmark, Pointer(7));
    BindingServices->AddMenuCommand(mcMoveToMark8, GotoBookmark, Pointer(8));
    BindingServices->AddMenuCommand(mcMoveToMark9, GotoBookmark, Pointer(9));
    BindingServices->AddMenuCommand(mcSetMark0, SetBookmark, NULL);
    BindingServices->AddMenuCommand(mcSetMark1, SetBookmark, Pointer(1));
    BindingServices->AddMenuCommand(mcSetMark2, SetBookmark, Pointer(2));
    BindingServices->AddMenuCommand(mcSetMark3, SetBookmark, Pointer(3));
    BindingServices->AddMenuCommand(mcSetMark4, SetBookmark, Pointer(4));
    BindingServices->AddMenuCommand(mcSetMark5, SetBookmark, Pointer(5));
    BindingServices->AddMenuCommand(mcSetMark6, SetBookmark, Pointer(6));
    BindingServices->AddMenuCommand(mcSetMark7, SetBookmark, Pointer(7));
    BindingServices->AddMenuCommand(mcSetMark8, SetBookmark, Pointer(8));
    BindingServices->AddMenuCommand(mcSetMark9, SetBookmark, Pointer(9));

    Shortcuts[0] = ShortCut(VK_RETURN, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, OpenFileAtCursor, NULL, kfImplicit, "", "ecOpenFileAtCursor");
    Shortcuts[0] = ShortCut(VK_SPACE, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, CodeCompletion, Pointer(csCodelist | csManual), kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_PRIOR, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MoveCursorToBOF, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_NEXT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MoveCursorToEOF, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_RIGHT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, WordRight, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_LEFT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, WordLeft, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_HOME, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, HomeCursor, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_END, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, EndCursor, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_BACK, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, DeleteWordLeft, NULL, kfImplicit, "", "");

    sState.Clear();
    Shortcuts[0] = ShortCut(VK_TAB, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, InsertTab, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_BACK, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, BackspaceDelete, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_HOME, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MoveCursorToBOL, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_END, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MoveCursorToEOL, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_DELETE, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, DeleteChar, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_INSERT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ToggleInsertMode, NULL, kfImplicit, "", "");

    Shortcuts[0] = ShortCut(VK_DOWN, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MoveCursorVertical, Pointer(1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_UP, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MoveCursorVertical, Pointer(-1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_RIGHT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MoveCursorHorizontal, Pointer(1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_LEFT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MoveCursorHorizontal, Pointer(-1), kfImplicit, "", "");

    Shortcuts[0] = ShortCut(VK_PRIOR, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, PageUp, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_NEXT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, PageDown, NULL, kfImplicit, "", "");

    Shortcuts[0] = ShortCut(VK_RETURN, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, InsertCharacter, Pointer(0x0D), kfImplicit, "", "");

    Shortcuts[0] = ShortCut(VK_UP, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MoveCursorVertical, Pointer(-1), kfImplicit, "", "");

    sState << ssShift;
    Shortcuts[0] = ShortCut(VK_BACK, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, BackspaceDelete, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_LEFT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MarkToRelativeHoriz, Pointer(-1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_RIGHT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MarkToRelativeHoriz, Pointer(1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_UP, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MarkToRelativeVert, Pointer(-1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_DOWN, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MarkToRelativeVert, Pointer(1), kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_END, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassicMarkToEOL, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_HOME, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassicMarkToBOL, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_PRIOR, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MarkToPageUp, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_NEXT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MarkToPageDown, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_RETURN, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, InsertCharacter, Pointer(0x0D), kfImplicit, "", "");

    Shortcuts[0] = ShortCut(VK_INSERT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClipPaste, NULL, kfImplicit, "", "EditPasteItem");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut(VK_INSERT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClipCopy, NULL, kfImplicit, "", "EditCopyItem");
    sState.Clear();
    sState << ssShift;
    Shortcuts[0] = ShortCut(VK_DELETE, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClipCut, NULL, kfImplicit, "", "EditCutItem");
    sState.Clear();
    sState << ssCtrl;
    Shortcuts[0] = ShortCut(VK_DELETE, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClipClear, NULL, kfImplicit, "", "EditDeleteItem");
    sState.Clear();
    BindingServices->AddMenuCommand(mcClipPaste, ClipPaste, NULL);
    BindingServices->AddMenuCommand(mcClipCopy, ClipCopy, NULL);
    BindingServices->AddMenuCommand(mcClipCut, ClipCut, NULL);
    BindingServices->AddMenuCommand(mcClipClear, ClipClear, NULL);

    sState << ssCtrl << ssShift;
    Shortcuts[0] = ShortCut(VK_LEFT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MarkToWordLeft, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_RIGHT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, MarkToWordRight, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('C', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassComplete, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('G', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, InsertNewGUID, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('S', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, IncrementalSearch, NULL, kfImplicit, "", "SearchIncrementalItem");
    Shortcuts[0] = ShortCut(VK_SPACE, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, CodeCompletion, Pointer(csParamList | csManual), kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_END, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassicMarkToViewBottom, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_HOME, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassicMarkToViewTop, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_PRIOR, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassicMarkToBOF, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_NEXT, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassicMarkToEOF, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_UP, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassNavigate, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut(VK_DOWN, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ClassNavigate, NULL, kfImplicit, "", "");
    Shortcuts[0] = ShortCut('R', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, ToggleMacroRecord, NULL, kfImplicit, "", "");
    sState.Clear();
    sState << ssCtrl << ssShift << ssAlt;
    Shortcuts[0] = ShortCut('P', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, LoadKeyMacro, NULL, kfImplicit, "", "");
    BindingServices->AddMenuCommand(mcIncrementalSearch, IncrementalSearch, NULL);

    sState.Clear();

    Shortcuts[0] = Menus::TextToShortCut("->");
    BindingServices->AddKeyBinding(Shortcuts, 0, AutoCodeInsight, Pointer("->"), kfImplicit, "", "");
    Shortcuts[0] = ShortCut('>', sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, AutoCodeInsight, Pointer('>'), kfImplicit, "", "");
    Shortcuts[0] = Menus::TextToShortCut('(');
    BindingServices->AddKeyBinding(Shortcuts, 0, AutoCodeInsight, Pointer('('), kfImplicit, "", "");

  /*
    BindingServices->AddKeyBinding([ShortCut(Ord('Q'), [ssCtrl]), ShortCut(Ord('y'), [])], DeleteToEOL, NULL);
    BindingServices->AddKeyBinding([ShortCut(Ord('Q'), [ssCtrl]), ShortCut(Ord('Y'), [])], DeleteToEOL, NULL);
  */
    // Create the literal key table->-> Note: needs at least one keybinding in order to be created
    Shortcuts[0] = ShortCut(0, sState);
    BindingServices->AddKeyBinding(Shortcuts, 0, NullCmd, NULL, 7, "LiteralKeyTable", "");
    BindingServices->SetDefaultKeyProc(LiteralKeyProc, NULL, "LiteralKeyTable");
  };
  //---------------------------------------------------------------------------
} /* namespace BufferList */

