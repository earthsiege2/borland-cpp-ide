//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BankUnit.h"
#include "banking_s.hh"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBankForm *BankForm;
//---------------------------------------------------------------------------
__fastcall TBankForm::TBankForm(TComponent* Owner)
   : TForm(Owner)
{
}

//---------------------------------------------------------------------------
char * const * argV;
int argC;
//---------------------------------------------------------------------------

// ///////////////////////////////////////////
// Implement CORBA object from skeleton class
// ///////////////////////////////////////////
class BankServerImpl : public _sk_BankServer
{
  public:
    BankServerImpl(const char *object_name);

    void UpCount(int i = 0){
      if (i == 1)
      {
       BankForm->StatusBox->Text = "Bank is Open";
       return;
      }
      BankForm->CountBox->Text = String(++count);
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
       BankForm->Memo1->Lines->Add("UserID " + String(Transaction.UserID));
       BankForm->Memo1->Lines->Add("Action " + String(Transaction.action));
       BankForm->Memo1->Lines->Add("Account " + String(Transaction.account));
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
  BankNumber = 900;
  count = 0;
  UserCount = 0;
  Customers[0] = new _user;
  Customers[1] = new _user;
  Customers[2] = new _user;

  Customers[0]->UserID = 0; //"John"
  Customers[0]->AccountChecking =  2000.00;
  Customers[0]->AccountSavings =   90.0;
  UserCount++;
              
  Customers[1]->UserID = 1; //Bill;
  Customers[1]->AccountChecking = 100.00;
  Customers[1]->AccountSavings =  500.00;
  UserCount++;
              
  Customers[2]->UserID = 2; // Jim;
  Customers[2]->AccountChecking = 1000.00;
  Customers[2]->AccountSavings =  5000.00;
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
         CORBA::BOA_var boa = orb->BOA_init(argC, argV);           

         // Create a new server object.
         BankServerImpl BankServer("BankOne");

         // Export the newly created object.
         boa->obj_is_ready(&BankServer);
         BankForm->StatusBox->Text = "Bank is Open";
         
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
void __fastcall TBankForm::Button1Click(TObject *Sender)
{
 ST = new ServerThread(false);    
}
//---------------------------------------------------------------------------

