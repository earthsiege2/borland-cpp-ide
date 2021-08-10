//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <AppEvnts.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TAppEventForm : public TForm
{
__published:	// IDE-managed Components
    TApplicationEvents *ApplicationEvents;
    TActionList *ActionList;
    TAction *Action;
    TMainMenu *MainMenu;
    TMenuItem *MenuAction;
    TMenuItem *MenuException;
    TButton *HintButton;
    TListBox *lbOnMessage;
    TLabel *lblOnMessage;
    TListBox *lbOther;
    TLabel *lblOther;
    TListBox *lbIdle;
    TLabel *lblOnIdle;
    TListBox *lbActionUpdate;
    TLabel *lblOnActionUpdate;

    void __fastcall ApplicationEventsActionExecute(TBasicAction *Action,
          bool &Handled);
    void __fastcall ApplicationEventsActionUpdate(TBasicAction *Action,
          bool &Handled);
    void __fastcall ApplicationEventsActivate(TObject *Sender);
    void __fastcall ApplicationEventsDeactivate(TObject *Sender);
    void __fastcall ApplicationEventsException(TObject *Sender,
          Exception *E);
    bool __fastcall ApplicationEventsHelp(WORD Command, int Data,
          bool &CallHelp);
    void __fastcall ApplicationEventsHint(TObject *Sender);
    void __fastcall ApplicationEventsIdle(TObject *Sender, bool &Done);
    void __fastcall ApplicationEventsMessage(tagMSG &Msg, bool &Handled);
    void __fastcall ApplicationEventsMinimize(TObject *Sender);
    void __fastcall ApplicationEventsShortCut(TWMKey &Msg, bool &Handled);
    void __fastcall ApplicationEventsRestore(TObject *Sender);
    void __fastcall ApplicationEventsShowHint(AnsiString &HintStr,
          bool &CanShow, THintInfo &HintInfo);
    void __fastcall MenuActionClick(TObject *Sender);
    void __fastcall MenuExceptionClick(TObject *Sender);
    void __fastcall ActionExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TAppEventForm( TComponent *Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAppEventForm *AppEventForm;
//---------------------------------------------------------------------------
#endif
