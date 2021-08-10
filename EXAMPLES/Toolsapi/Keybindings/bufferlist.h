//---------------------------------------------------------------------------
#ifndef bufferlistH
#define bufferlistH
//---------------------------------------------------------------------------

#include <toolsapi.hpp>
#include "basebindings.h"
#include "baseclss.h"

namespace Bufferlist
{
  class TBufferList : public OTAClasses::TOTAKeyboardBinding
  {
    public:
      void __fastcall BufferListProc(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                                     TKeyBindingResult &BindingResult);
      virtual TBindingType __fastcall GetBindingType(void);
      virtual AnsiString __fastcall GetDisplayName(void);
      virtual AnsiString __fastcall GetName(void);
      virtual void __fastcall BindKeyboard(const _di_IOTAKeyBindingServices BindingServices);
  };

  class TClassicBinding : public TBaseBindings,
                          public OTAClasses::TOTAKeyboardBinding 
  {
  protected:
    void __fastcall AdjustBlockCase(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall AdjustWordCase(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall BackspaceDelete(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicBlockDelete(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicDeleteLine(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicMarkWord(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicMarkToViewBottom(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicMarkToViewTop(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicMarkToBOF(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicMarkToBOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicMarkToEOF(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicMarkToEOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicMoveBlock(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ClassicToggleCase(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall CopyBlock(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall CursorLeft(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall CursorRight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall DeleteChar(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall DeleteToEOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall DeleteWordLeft(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall DeleteWordRight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall EndCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall GotoBookmark(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall HomeCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall IndentBlock(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall InsertCharacter(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall InsertFile(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall InsertLiteralKey(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall InsertTab(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall LineDown(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall LineUp(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall LiteralKeyProc(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall LoadKeyMacro(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MarkBlockBegin(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MarkBlockEnd(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MarkLine(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MarkToPageDown(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MarkToPageUp(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MarkToRelativeHoriz(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MarkToRelativeVert(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MarkToWordLeft(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MarkToWordRight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveCursorHorizontal(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveCursorToBOF(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveCursorToBOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveCursorToEOF(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveCursorToEOL(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveCursorToLastEdit(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveCursorToMarkBegin(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveCursorToMarkEnd(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveCursorVertical(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveLineViewBottom(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall MoveLineViewTop(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall PageDown(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall PageUp(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall SetBookmark(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall Scroll(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ToggleBlock(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ToggleInsertMode(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall ToggleMacroRecord(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall WordLeft(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
    void __fastcall WordRight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                    TKeyBindingResult &BindingResult);
  public:
    /* IOTAKeyboardBinding */
    virtual TBindingType __fastcall GetBindingType(void);
    virtual AnsiString __fastcall GetDisplayName(void);
    virtual AnsiString __fastcall GetName(void);
    virtual void __fastcall BindKeyboard(const _di_IOTAKeyBindingServices BindingServices);
  };

} /* namespace BufferList */
#endif
