//---------------------------------------------------------------------------
#ifndef BankUnitH
#define BankUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TBank2Form : public TForm
{
__published:	// IDE-managed Components
   TEdit *CountBox;
   TLabel *Label1;
   TButton *Button1;
   TEdit *StatusBox;
   TLabel *Label2;
   TMemo *Memo1;
   void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TBank2Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBank2Form *Bank2Form;
//---------------------------------------------------------------------------
#endif
