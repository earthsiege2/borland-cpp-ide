//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdFinger.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TfrmFingerDemo : public TForm
{
__published:	// IDE-managed Components
        TLabel *lblQuerry;
        TLabel *lblInstructions;
        TEdit *edtQuerry;
        TMemo *mmoQuerryResults;
        TCheckBox *chkVerboseQuerry;
        TBitBtn *bbtnQuerry;
        TIdFinger *IdFngFinger;
        void __fastcall bbtnQuerryClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmFingerDemo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmFingerDemo *frmFingerDemo;
//---------------------------------------------------------------------------
#endif
