//---------------------------------------------------------------------------
#ifndef mainclntH
#define mainclntH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "autosrvr_TLB.h"
#include <Menus.hpp>
#include <ActnList.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *Run1;
        TMenuItem *Server1;
        TActionList *ActionList1;
        TAction *ServerExecuteAction;
        TPanel *Panel1;
        TButton *Button1;
        TEdit *Edit1;
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall ServerExecuteActionExecute(TObject *Sender);
private:	// User declarations
        TCOMIMyAuto MyAutoServer;
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
 