//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000 Inprise Corporation. All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "atmunit.h"
#include "servname.h"
#include "xaction_c.hh"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
USE_STD_NS
TFormATM *FormATM;
//---------------------------------------------------------------------------
__fastcall TFormATM::TFormATM(TComponent* Owner)
   : TForm(Owner)
{
}
char * const * argV;
int argC;
//---------------------------------------------------------------------------

// /////////////////////////////////////
// Mimic streaming to VCL Memo Window
// /////////////////////////////////////
class catchit: public streambuf
{
	TMemo * M;
    int ct;
    String S;
    char * cbuff;

    public:
    catchit(TMemo *Memo){M = Memo; ct = 1;};
    int sync();
    int overflow(int ch);

};
int catchit::overflow(int ch)
{
  S += (char)ch;
  return 0;
}
int catchit::sync()
{
//   M->Lines->Strings[ct++] = S;
   M->Lines->Add(S);
   S = "";

   return ct;
}

// ////////////////////////////////////////////
// class _update
// Instantiate this object to interface with the view
// Usage: new _update(FormATM);
// ////////////////////////////////////////////
class _update
{
  private:
    TFormATM * theForm;

  public:
  __fastcall _update(TFormATM* ATMForm){theForm = ATMForm;}
  long AccountType() {return (long)theForm->AccountType->ItemIndex + 1;}
  EnumAction ActionType() {return (EnumAction)theForm->Action->ItemIndex;}
  long UserID()
  {
    if (theForm->NameBox->Text == "John")
     return 0;
    if (theForm->NameBox->Text == "Bill")
     return 1;
    if (theForm->NameBox->Text == "Jim")
     return 2;
    if (theForm->NameBox->Text == "Gene")
     return 3;
    if (theForm->NameBox->Text == "Wally")
     return 4;
    if (theForm->NameBox->Text == "Frank")
     return 5;
    return -1; //Don't know User
  }
  long PIN()
  { try {
    return (long)theForm->PINBox->Text.ToInt();
    }
    catch (Exception &e){return (long)0;}
  }
  double Amount(){return theForm->AmountBox->Text.ToDouble();}
  void UpdateList()
  { 
    theForm->Memo1->Lines->Add("User: John, PIN:123,  Bank 1");
    theForm->Memo1->Lines->Add("User: Bill, PIN:456,  Bank 1");
    theForm->Memo1->Lines->Add("User: Jim, PIN:789,  Bank 1");
    theForm->Memo1->Lines->Add("User: Gene, PIN:123,  Bank 2");
    theForm->Memo1->Lines->Add("User: Wally, PIN:456,  Bank 2");
    theForm->Memo1->Lines->Add("User: Frank, PIN:789,  Bank 2");
  }
  void UpdateMemo(String str){theForm->Memo1->Lines->Add(str);}
  void UpdateStatus(String str){theForm->StatusBar1->SimpleText = str;}
  void Clear(){theForm->Memo1->Clear();}
};                              

void __fastcall TFormATM::OKButtonClick(TObject *Sender)
{
   catchit cbuf(Memo1);
   ostream CCout(&cbuf);  //Visibroker has defined Cout

   //Create ATM view interface object
   _update* Input = new _update(FormATM);

   //Create a new transaction object
   xaction_var X = new xaction;
   
   //Poplulate transaction object
    X->UserID  = Input->UserID(); 
    try{
    X->PIN     = Input->PIN(); 
    }catch(Exception &e){ X->PIN = 0;}
    X->amount  = Input->Amount(); 
    X->action  = Input->ActionType(); 
    X->account = Input->AccountType();
    X->balance = 0.00;
    X->status = incomplete;

    try{
 
    // Start the ORB
    CORBA::ORB_ptr orb = CORBA::ORB_init();
    Input->UpdateStatus("**ORB Initialized.");

    // Bind to a ATM server.
    Server_ptr ATMServer = Server::_bind(ATM->serverName().c_str());
    Input->UpdateStatus("**ATMServer connect complete.");
    Input->UpdateStatus("**ATM is open.");
     

      //Send ATM the tranaction
      ATMServer->HandleTransaction(X);
  
    
      if (X->status == complete)
      {
        Input->UpdateMemo("Your account balance: $" + CurrToStr(X->balance));
        Input->UpdateMemo("Transaction Complete");
      }
      if (X->status == incomplete)
      {
        Input->UpdateMemo("Transaction not processed.");
        Input->UpdateMemo("Your account balance: $" + CurrToStr(X->balance));
      }  
      
      if (X->status == invalid)
      {
        Input->Clear();
        Input->UpdateMemo("User ID and PIN did not match.");
      }
  
    }
    catch(const CORBA::Exception& e) {
    CCout << e._name() << endl;
    Input->UpdateStatus("**ATM is closed.");
    }              

    
}
//---------------------------------------------------------------------------
void __fastcall TFormATM::ListButtonClick(TObject *Sender)
{
  _update * U = new _update(FormATM);
  U->UpdateList();
  delete U; 
}
//---------------------------------------------------------------------------

#define mrOK 1

void __fastcall TFormATM::Button1Click(TObject/* */ *Sender)
{
  if (ServerNameDlg->ShowModal() == mrOK)
  {
   ATM->serverName(ServerNameDlg->ServerNameEdit->Text);
  }
}

long __fastcall TFormATM::TestConnection()
{    
   try {
     CORBA::ORB_ptr orb = CORBA::ORB_init();
     Server_ptr S = Server::_bind(ServerNameDlg->ServerNameEdit->Text.c_str());
     return S->Balance();
     }
     catch(CORBA::Exception &e){

       return 0;
     }
}
//---------------------------------------------------------------------------

void __fastcall TFormATM::FormCreate(TObject/* */ *Sender)
{
 ATM = new ATMObject();        
}
//---------------------------------------------------------------------------

