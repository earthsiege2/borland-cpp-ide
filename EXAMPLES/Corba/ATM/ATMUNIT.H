//---------------------------------------------------------------------------
#ifndef atmunitH
#define atmunitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class ATMObject
{
 private:
   long _ID;
   String _serverName;
 public:
   ATMObject(){_serverName = "Wells Fargo"; _ID = 100;};
   ATMObject(String name){_serverName = name; _ID = 100;};
   String serverName(){return _serverName;}
   void serverName(String name){_serverName = name;}
   long ID(){return _ID;}
   void ID(long id){_ID = id;}
};
class TFormATM : public TForm
{
__published:	// IDE-managed Components
   TEdit *NameBox;
   TEdit *PINBox;
   TEdit *AmountBox;
   TButton *OKButton;
   TLabel *Label1;
   TLabel *Label2;
   TLabel *Label3;
   TRadioGroup *Action;
   TMemo *Memo1;
   TRadioGroup *AccountType;
   TButton *ListButton;
   TStatusBar *StatusBar1;
        TButton *Button1;
   void __fastcall OKButtonClick(TObject *Sender);
   void __fastcall ListButtonClick(TObject *Sender);
   
        void __fastcall Button1Click(TObject/* */ *Sender);
        void __fastcall FormCreate(TObject/* */ *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TFormATM(TComponent* Owner);
   ATMObject * ATM;
   long __fastcall TestConnection();
};
//---------------------------------------------------------------------------
extern PACKAGE TFormATM *FormATM;
//---------------------------------------------------------------------------
#endif
