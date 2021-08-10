//---------------------------------------------------------------------------
#ifndef atmserverunitH
#define atmserverunitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "xaction_s.hh"
#include "banking_s.hh"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
   TMemo *Memo1;
   TLabel *Transactions;
   TEdit *Count;
   TButton *Button1;
        TButton *Button2;
        TEdit *ServerNameEdit;
        TLabel *Label1;
        TLabel *Label2;
        TComboBox *BankBox;
        TButton *Button3;
   void __fastcall Button1Click(TObject *Sender);
        
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button3Click(TObject/* */ *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TForm2(TComponent* Owner);
   void StartServer();
   void DownServer();
   CORBA::ORB_var orb;
   CORBA::BOA_var boa;
   CORBA::Object_ptr obj;
   String CurrentServerName;
         

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
