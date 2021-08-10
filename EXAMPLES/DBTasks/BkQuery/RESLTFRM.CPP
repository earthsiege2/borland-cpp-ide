//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ResltFrm.h"
#pragma resource "*.dfm"
#include <stdio.h>
//---------------------------------------------------------------------------

__fastcall TQueryForm::TQueryForm(TComponent* AOwner) : TForm(AOwner)
{
}
__fastcall TQueryForm::TQueryForm(TComponent* AOwner, int Dummy) : TForm(AOwner, Dummy)
{
}
__fastcall TQueryForm::TQueryForm(HWND ParentWindow) : TForm(ParentWindow)
{
}
__fastcall TQueryForm::~TQueryForm(void)
{
}
//---------------------------------------------------------------------------

__fastcall TQueryThread::TQueryThread(TQueryForm* AQueryForm)
                        :TThread(false)
{
  QueryForm = AQueryForm;
  FreeOnTerminate = true;
}

__fastcall TQueryThread::~TQueryThread(void)
{
  //delete QueryForm;
}
//---------------------------------------------------------------------------

void __fastcall TQueryThread::Execute(void)
{
  static long UniqueNumber;

  try{
    // Ensure the Query has a unique session and database.  A unique session
    // is required for each thread.  Since databases are session specific
    // it must be unique as well
    InterlockedIncrement(&UniqueNumber);

    String buf = QueryForm->BKSession->Name + UniqueNumber;
    QueryForm->BKSession->SessionName = buf;
    QueryForm->BKDatabase->SessionName = QueryForm->BKSession->SessionName;

    buf = QueryForm->BKDatabase->Name + UniqueNumber;
    QueryForm->BKDatabase->DatabaseName = buf;

    QueryForm->Query->SessionName = QueryForm->BKDatabase->SessionName;
    QueryForm->Query->DatabaseName = QueryForm->BKDatabase->DatabaseName;

    // Open the query
    QueryForm->Query->Open();

    // Connect the query to the grid.
    ConnectQuery();

    // Update the status line. 
    MessageText = "Query opened";
    DisplayMessage();
  }

  catch(EDatabaseError& e){
    String buf =
          e.Message
          + "\n\n"
          + "1. Be sure Interbase and SQL Links are installed.\n"
          + "2. Run the BDE Configuration utility, BDEADMIN.EXE.\n"
          + "3. Create a new Alias by the name 'IBLOCAL' of type INTRBASE.\n"
          + "4. Set the Server Name to <Interbase path>\\EXAMPLES\\EMPLOYEE.GDB.\n";

    MessageText = buf;

    // Display error on the status line
    DisplayMessage();
  }

  catch(Exception& e){
    String buf = String(e.ClassName()) + " " + e.Message.c_str();
    MessageText = buf;

    // Display error on the status line
    DisplayMessage();
  }
}
//---------------------------------------------------------------------------

void __fastcall TQueryThread::ConnectQuery(void)
{
  QueryForm->DataSource->DataSet = QueryForm->Query;
}
//---------------------------------------------------------------------------

void __fastcall TQueryThread::DisplayMessage(void)
{
  QueryForm->StatusLine->Caption = MessageText;
}
//---------------------------------------------------------------------------

void __fastcall BackgroundQuery(const AnsiString QueryName,
                                const AnsiString Alias,
                                const AnsiString User,
                                const AnsiString Password,
                                const AnsiString QueryText)
{
  //The QueryForm object is deleted in TQueryThread's destructor
  TQueryForm* QueryForm = new TQueryForm(Application);

  QueryForm->Caption = QueryName;
  QueryForm->QueryLabel->Caption = QueryText;
  QueryForm->Show();
  QueryForm->BKDatabase->AliasName = Alias;
  QueryForm->BKDatabase->Params->Values["USER"] = User;
  QueryForm->BKDatabase->Params->Values["PASSWORD"] = Password;
  QueryForm->Query->SQL->Text = QueryText;

  // Create the background thread to execute the query. Since the thread
  // will free itself on termination we do not need to maintain a reference
  // to it.  Creating it is enough
  new TQueryThread(QueryForm);
}

