//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "atmserverunit.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
char * const * argV;
int argC;
//---------------------------------------------------------------------------

// /////////////////////////////////////
// Implement CORBA object from skeleton class
// /////////////////////////////////////
class ATMServerImpl : public _sk_Server
{
  public:
    ATMServerImpl(const char *object_name);

    void UpCount(int i = 0){
      if (i == 1)
      {
       Form2->Memo1->Lines->Add("**Server Started**");
       return;
      }
      Form2->Count->Text = String(count++);
    }

    virtual xaction HandleTransaction(xaction& Transaction)
    {
       UpCount();

//       Form2->Memo1->Lines->Add("**Found a Bank.");
       
       Transaction.status = invalid;
       for (int i = 0; i < UserCount; i++)
       {
         if(Transaction.UserID == CardHolders[i]->UserID)
         {
          if (Transaction.PIN == CardHolders[i]->PIN)
          {
             Transaction.status = OK;
             try {
             BankServer_var BankServer = BankServer::_bind((*Banks[CardHolders[i]->Bank]).c_str());
             BankServer->HandleTransaction(Transaction);
             Form2->Memo1->Lines->Add("Transaction to " + *Banks[CardHolders[i]->Bank]);
             }
             catch(CORBA::Exception &e){
             Form2->Memo1->Lines->Add("**Bank Server Not Available**");
             return Transaction;
             }
          }
         }
       }
 //      Transaction.status = complete;
      return Transaction;
    }  

    virtual CORBA::Long Balance(){UpCount(); return CORBA::Long(count);}

    class NoServer: public CORBA::UserException
    {
    public:
       NoServer(){}
       static ATMServerImpl::NoServer* _narrow() throw (CORBA::SystemException);

    };

  private:
    int count;
    struct _user{
        long UserID;
        long Bank;
        long PIN;
    };

   _user * CardHolders[10]; 
   long BankOne;
   long FirstBank;
   int UserCount;
   String * Banks[10];
};

ATMServerImpl::ATMServerImpl(const char *object_name=NULL) :
      _sk_Server(object_name) 
{
  count = 0;
  UserCount = 0;
  UpCount(1);
  
  Banks[0] = new String("BankOne");
  Banks[1] = new String("First Bank");
  TStrings *SL = new TStringList();
  SL->Add(*Banks[0]);
  SL->Add(*Banks[1]);
  Form2->BankBox->Items->Assign(SL);
 Form2->BankBox->ItemIndex = 0;

  BankOne = 0;
  FirstBank = 1;
  
  CardHolders[0] = new _user;
  CardHolders[1] = new _user;
  CardHolders[2] = new _user;
  CardHolders[3] = new _user;
  CardHolders[4] = new _user;
  CardHolders[5] = new _user;

  //user 1
  CardHolders[0]->UserID = 0; //"John";
  CardHolders[0]->PIN = 123;
  CardHolders[0]->Bank = BankOne;
  UserCount++;
  CardHolders[1]->UserID = 1;// "Bill";
  CardHolders[1]->PIN = 456;
  CardHolders[1]->Bank = BankOne;
  UserCount++;
  CardHolders[2]->UserID = 2; //"Jim";
  CardHolders[2]->PIN = 789;
  CardHolders[2]->Bank = BankOne;
  UserCount++;
              
  CardHolders[3]->UserID = 3; //"John";
  CardHolders[3]->PIN = 123;
  CardHolders[3]->Bank = FirstBank;
  UserCount++;
  CardHolders[4]->UserID = 4;// "Bill";
  CardHolders[4]->PIN = 456;
  CardHolders[4]->Bank = FirstBank;
  UserCount++;
  CardHolders[5]->UserID = 5; //"Jim";
  CardHolders[5]->PIN = 789;
  CardHolders[5]->Bank = FirstBank;
  UserCount++;
              
  
}
ATMServerImpl * ATMServer;
void TForm2::StartServer()
{
      try {
         // Initialize the ORB and BOA
         orb = CORBA::ORB_init(argC, argV);
         boa = orb->BOA_init(argC, argV);           

         if (obj)
         {
            Form2->Memo1->Lines->Add("**Server already started**");
            ServerNameEdit->Text = CurrentServerName;
         }else{
            // Create a new server object.
            obj = new ATMServerImpl(ServerNameEdit->Text.c_str()); //"Wells Fargo");
            CurrentServerName = ServerNameEdit->Text;
            // Export the newly created object.
            boa->obj_is_ready(obj);

            // Wait for incoming requests
            //boa->impl_is_ready();
            }
         }
      catch(const CORBA::Exception& e) {
          ShowMessage("exception caught");
         } 

}
void TForm2::DownServer()
{
 try{
  if (obj){
    boa->deactivate_obj(obj);
    obj->_release();
    obj = obj->_nil();
  }
  Form2->Memo1->Lines->Add("**The Server is Down!**");
  }
  catch(CORBA::Exception &e){
  ShowMessage("Problem Downing the Server!");
  }
  
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
         ATMServerImpl ATMServer("Wells Fargo");

         // Export the newly created object.
         boa->obj_is_ready(&ATMServer);

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
void __fastcall TForm2::Button1Click(TObject *Sender)
{
// ST = new ServerThread(false);   
 StartServer();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
   DownServer();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
 DownServer();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject/* */ *Sender)
{
  try{
  BankServer_ptr BankServer = BankServer::_bind(Form2->BankBox->Items->Strings[BankBox->ItemIndex].c_str());
  long ID = BankServer->BankID();

  Form2->Memo1->Lines->Add(String(ID));
  }
  catch(CORBA::Exception &e){ShowMessage(e._name());}
}
//---------------------------------------------------------------------------

