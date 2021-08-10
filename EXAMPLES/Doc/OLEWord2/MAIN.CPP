//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <comobj.hpp>
#include <memory>     //for STL auto_ptr
#include <stdio.h>
#include <dir.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string>
#include "main.h"
#include "notify.h"

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TOleWordForm *OleWordForm;
char *current_directory(char *path);
//---------------------------------------------------------------------------
__fastcall TOleWordForm::TOleWordForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
#pragma warn -stv
void __fastcall TOleWordForm::TalkToWordClick(TObject *Sender)
{
  static HANDLE shFileMap = NULL;

  //Get the current directory and build the filename string
  char curdir[MAXPATH];
  current_directory(curdir);
  AnsiString strFullFileName(curdir);
  strFullFileName = strFullFileName + "\\CBUILDER.DOC";

  //Create the message window and proceed with automating Word
  std::auto_ptr<TNotifyForm> pfrm(new TNotifyForm(this));
  pfrm->Label1->Caption = "Starting Microsoft Word...";
  pfrm->Update();

  try{

    //check that this automation routine is not already executing.  A single
    //instance of Word seems not to like it.
    shFileMap = CreateFileMapping((HANDLE)0xffffffff,
                                  NULL,
                                  PAGE_READWRITE,
                                  0,
                                  4,
                                  "OLEWord2SharedData");
    if (shFileMap != NULL && GetLastError() == ERROR_ALREADY_EXISTS){
    throw Exception( "This automation procedure seems be running already. Aborting Automation.");
    }

    V = CreateOleObject("Word.Basic");

    pfrm->Label1->Caption = "Opening a new file..." ;
    pfrm->Update();
    V.Exec(Procedure("FileNew") << "Normal");

    pfrm->Label1->Caption = "Inserting words..." ;
    pfrm->Update();
    V.Exec(Procedure("Insert") << "Borland welcomes you to the wonderful ");
    V.Exec(Procedure("Insert") << "world of Borland C++Builder.\nWe're so ");
    V.Exec(Procedure("Insert") << "very glad you could join us!\n");

    pfrm->Label1->Caption = "Saving CBUILDER.DOC, password=cbuilder...";
    pfrm->Label3->Caption = "If MSWord starts flashing, "
                            "please right-click on the caption bar.";
    pfrm->Update();
    V.Exec(Procedure("FileSaveAs") << strFullFileName << NULL << NULL << "cbuilder");

    pfrm->Label1->Caption = "Closing the file CBUILDER.DOC. . ." ;
    pfrm->Update();
    V.Exec(Procedure("FileClose") << 1);

    pfrm->Label1->Caption = "Operation complete!";
    pfrm->Update();
  }


  catch(EOleException& e){
    char buf[256];
    pfrm->Label1->Caption = "An EOleException reference has been encountered...";
    sprintf(buf, "Result: %s.\n\n%s.",
            e.Message,
            "The password for this file is \"cbuilder\".\n"
            "The new file will not be saved.");
    V.Exec(Procedure("AppHide"));
    ShowMessage(buf);
    V.Exec(Procedure("AppShow"));
  }
  catch(EOleSysError& e){
    char buf[256];
    sprintf(buf, "Result: %s.\n\n%s", e.Message,
            "This example program requires Microsoft Word.\n");
             ShowMessage(buf);
  }

  catch(Exception& e){
    pfrm->Label1->Caption = "Word seems to have created CBUILDER.DOC already...";
    pfrm->Update();
    V.Exec(Procedure("AppHide"));
    ShowMessage(e.Message);
    V.Exec(Procedure("AppShow"));
  }

  //If none of the above exceptions, catch it so that we can close the handle
  catch(...){}
  CloseHandle(shFileMap);
}
#pragma warn .stv
//---------------------------------------------------------------------

#pragma warn -sig
char *current_directory(char *path)
{
  strcpy(path, "X:\\");      /* fill string with form of response: X:\ */
  path[0] = 'A' + getdisk();    /* replace X with current drive letter */
  getcurdir(0, path+3);  /* fill rest of string with current directory */
  return(path);
}
#pragma warn .sig

