//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BankUnit2.h"
#include "banking_s.hh"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBank2Form *Bank2Form;
//---------------------------------------------------------------------------
__fastcall TBank2Form::TBank2Form(TComponent* Owner)
   : TForm(Owner)
{
}

//---------------------------------------------------------------------------
char * const * argV;
int argC;
//---------------------------------------------------------------------------
class BankServerImpl : public _sk_BankServer
{
  public:
    BankServerImpl(const char *object_name);

    void UpCount(int i = 0){
      if (i == 1)
      {
       Bank2Form->StatusBox->Text = "Bank is Open";
       return;
      }
      Bank2Form->CountBox->Text = String(++count);
    }
    virtual long BankID()
            {
              return BankNumber;
            }
    
    virtual xaction HandleTransaction(xaction& Transaction)
    {
       bool PostChange = false;
       double workingBalance = 0;
       
       UpCount();
       Transaction.status = incomplete; 
       Bank2Form->Memo1->Lines->Add("UserID " + String(Transaction.UserID));
       Bank2Form->Memo1->Lines->Add("Action " + String(Transaction.action));
       Bank2Form->Memo1->Lines->Add("Account " + String(Transaction.account));
       for (int i = 0; i < UserCount; i++)
       {
         if(Transaction.UserID == Customers[i]->UserID)
         {
          if (Transaction.account == 1)
            workingBalance = Customers[i]->AccountChecking;
          else 
            workingBalance = Customers[i]->AccountSavings;
            
          switch(Transaction.action)
          {
            case balance:
            Transaction.balance = workingBalance;
            Transaction.status = complete;
            break;
            
            case withdraw:
            Transaction.balance = workingBalance;
            workingBalance -= Transaction.amount;
            if (workingBalance < 0){
              Transaction.status = incomplete;
              }
              else
              {
              Transaction.balance = workingBalance;
              Transaction.status = complete;
              PostChange = true;
              }
            
            break;
            
            case deposit:
            workingBalance += Transaction.amount;
            Transaction.balance = workingBalance;
            Transaction.status = complete;
            PostChange = true;
            break;                        
          } 
             
          if (PostChange)
          {
            if (Transaction.account == 1)
             Customers[i]->AccountChecking = workingBalance;
            else 
             Customers[i]->AccountSavings  = workingBalance;
          
          }      
         }
       }
      return Transaction;
    }  
    
   private:
   long BankNumber;
    int count;
    int UserCount;
    struct _user{
      long UserID;
      double AccountChecking;
      double AccountSavings;
    };

    _user * Customers[10];
};

BankServerImpl::BankServerImpl(const char *object_name = NULL):
_sk_BankServer(object_name)
{
  BankNumber = 800;
  count = 0;
  UserCount = 0;
  Customers[0] = new _user;
  Customers[1] = new _user;
  Customers[2] = new _user;

  Customers[0]->UserID = 3; //"Gene"
  Customers[0]->AccountChecking =  92000.00;
  Customers[0]->AccountSavings =   990.0;
  UserCount++;
              
  Customers[1]->UserID = 4; //Wally;
  Customers[1]->AccountChecking = 9100.00;
  Customers[1]->AccountSavings =  9500.00;
  UserCount++;
              
  Customers[2]->UserID = 5; //Frank;
  Customers[2]->AccountChecking = 91000.00;
  Customers[2]->AccountSavings =  95000.00;
  UserCount++;
              
}                              
//---------------------------------------------------------------------------
class ServerThread : public TThread
{
  public:
   __fastcall ServerThread(bool CS):TThread(CS){};
   
   void  __fastcall Execute()
   {
     try {

         // Initialize the ORB and BOA
         CORBA::ORB_var orb = CORBA::ORB_init(argC, argV);
//         Form2->Memo1->Lines->Add("Orb object started.");
         CORBA::BOA_var boa = orb->BOA_init(argC, argV);           
         // Create a new account object.
         BankServerImpl BankServer("First Bank");

         // Export the newly created object.
         boa->obj_is_ready(&BankServer);
         Bank2Form->StatusBox->Text = "Bank is Open";
         
         // Wait for incoming requests
         boa->impl_is_ready();
         }
      catch(const CORBA::Exception& e) {
          ShowMessage("exception caught");
         } 
    }
};
ServerThread * ST;
//---------------------------------------------------------------------------
void __fastcall TBank2Form::Button1Click(TObject *Sender)
{
 ST = new ServerThread(false);    
}
//---------------------------------------------------------------------------
