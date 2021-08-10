//---------------------------------------------------------------------------
#ifndef basebindingsH
#define basebindingsH
//---------------------------------------------------------------------------

#include <toolsapi.hpp>
#include "baseclss.h"
#include "strindx.rh"

const kfImplicit = kfImplicitShift | kfImplicitModifier | kfImplicitKeypad;

class TBaseBindings
{
  public:
    virtual ~TBaseBindings(void){}
    /* utility functions */
    IOTAEditBlock * __fastcall MarkWord(const _di_IOTAKeyContext Context);
    void __fastcall SlideBlock(const _di_IOTAKeyContext Context, bool Backward);
    /* Default binding implementations */
    void __fastcall AddWatchAtCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall AutoCodeInsight(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall BrowseSymbolAtCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall BlockSave(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall ClassNavigate(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall ClassComplete(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall ClipClear(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall ClipCopy(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall ClipCut(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall ClipPaste(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall CodeTemplate(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall CodeCompletion(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall DebugInspect(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall GotoLine(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall HelpKeyword(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall IncrementalSearch(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall InsertCompilerOptions(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall InsertNewGUID(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall NullCmd(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall OpenFileAtCursor(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall OpenLine(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall Print(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall SetBlockStyle(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall SearchAgain(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall SearchFind(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall SearchReplace(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall SwapCPPHeader(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
    void __fastcall ViewExplorer(const _di_IOTAKeyContext Context, TShortCut KeyCode,
                               TKeyBindingResult &BindingResult);
};

#endif
