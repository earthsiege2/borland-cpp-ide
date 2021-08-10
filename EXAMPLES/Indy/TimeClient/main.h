//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTime.hpp>
//---------------------------------------------------------------------------
class TfrmTimeDemo : public TForm
{
__published:	// IDE-managed Components
        TLabel *lblTimeServer;
        TLabel *Label1;
        TEdit *edtTimeResult;
        TButton *btnGetTime;
        TComboBox *cmboTimeServer;
        TIdTime *IdDemoTime;
        void __fastcall btnGetTimeClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmTimeDemo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmTimeDemo *frmTimeDemo;
//---------------------------------------------------------------------------
#endif
