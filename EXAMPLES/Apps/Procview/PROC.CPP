//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <stdlib.h>
#include "proc.h"
#include "another.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
#pragma resource "procv2.res"
TFormMain *FormMain;
//---------------------------------------------------------------------
static int stat=1;
int i=0;
//---------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent *Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------
bool __stdcall EnumProc(HWND hWnd,/*LPARAM*/long/*lp*/)
{
   unsigned long* pPid;   //LPDWORD
   unsigned long result;      //DWORD
   void *hg;                  //HGLOBAL
   unsigned long id;

   if(hWnd==NULL)
      return false;

   hg = GlobalAlloc(GMEM_SHARE,sizeof(unsigned long));
   pPid = (unsigned long *)GlobalLock(hg);

   result = GetWindowThreadProcessId(hWnd,pPid);

   if(result){
      char title[110];
      char className[95];
      char totalStr[256];
      GetClassName(hWnd,className,95);
      GetWindowText(hWnd,title,110);
      id=*pPid;
      ultoa(id,totalStr,10);
      strcat(totalStr,"\t");
      if(title){
         strcat(totalStr,title);
         strcat(totalStr,"\t");
      }
      strcat(totalStr,className);
      FormMain->ListBox1->Items->Add((AnsiString)totalStr);
   }
   else{
      GlobalUnlock(hg);
      GlobalFree(hg);
      return false;
   }
   GlobalUnlock(hg);
   GlobalFree(hg);
   return true;
}

//---------------------------------------------------------------------
void __fastcall TFormMain::Exit1Click(TObject* /*Sender*/)
{
   PostQuitMessage(0);
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::About1Click(TObject* /*Sender*/)
{
   Form2->ShowModal();
}
//----------------------------------------------------------------------------
 void __fastcall TFormMain::SpeedButton4Click(TObject* /*Sender*/)
{
   long lp=0;
   ListBox1->Enabled=true;
   ListBox1->Clear();
   EnumWindows((WNDENUMPROC)EnumProc,lp);
   SpeedButton2->Enabled=true;
   SpeedButton3->Enabled=true;
}
//----------------------------------------------------------------------------
void __fastcall TFormMain::RadioButton1Click(TObject* Sender)
{
   TRadioButton *rbp =(TRadioButton*) Sender;
   ListBox1->Font->Color=rbp->Font->Color;
}
//----------------------------------------------------------------------------
 void __fastcall TFormMain::New1Click(TObject* /*Sender*/)
{
   SpeedButton4Click(0);
}
//----------------------------------------------------------------------------
 void __fastcall TFormMain::Refresh1Click(TObject* /*Sender*/)
{
      SpeedButton4Click(0);
}
//----------------------------------------------------------------------------
 void __fastcall TFormMain::SpeedButton3Click(TObject* /*Sender*/)
{
      ListBox1->Clear();
      SpeedButton3->Enabled=false;
      SpeedButton1->Enabled=false;
}
//----------------------------------------------------------------------------
 void __fastcall TFormMain::ListBox1Click(TObject* /*Sender*/)
{
   SpeedButton1->Enabled=true;
   StatusBar1->SimpleText="Select 'Kill Selected PID' to terminate the process";
}
//----------------------------------------------------------------------------

void __fastcall TFormMain::FormShow(TObject */*Sender*/)
{
   if(stat){
      stat= 0;
      ListBox1->Items->Add((AnsiString)"Click on 'pid' Tool button above");
   }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Timer1Timer(TObject */*Sender*/)
{
   switch(i){
      case 0:{
         Image1->Picture->Bitmap->LoadFromResourceName(0,(AnsiString)"BITMAP_5");
         Image1->Refresh();
         i=1;
         return;
      }
      case 1:{
         Image1->Picture->Bitmap->LoadFromResourceName(0,(AnsiString)"BITMAP_2");
         Image1->Refresh();
         i=2;
         return;
      }
      case 2:{
         Image1->Picture->Bitmap->LoadFromResourceName(0,(AnsiString)"BITMAP_3");
         Image1->Refresh();
         i=3;
         return;
      }
      case 3:{
         Image1->Picture->Bitmap->LoadFromResourceName(0,(AnsiString)"BITMAP_4");
         Image1->Refresh();
         i=4;
         return;
      }
      case 4:{
         Image1->Picture->Bitmap->LoadFromResourceName(0,(AnsiString)"BITMAP_1");
         Image1->Refresh();
         i=0;
         return;
      }
   }//end switch
}

void __fastcall TFormMain::SpeedButton2Click(TObject *Sender)
{
   SpeedButton4Click(0);
   SpeedButton1->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::SpeedButton1Click(TObject *Sender)
{
   try {
   AnsiString str;
   char *tmp;
   int i;
   i= ListBox1->ItemIndex;
   if( i != -1){
      AnsiString s;
      tmp = new char[100];
      s=ListBox1->Items->Strings[i];
      strcpy(tmp,(char*)s.c_str());
      tmp=strtok(tmp,"\t");
   }
   int id=atoi(tmp);
   delete[] tmp;
   HANDLE ps = OpenProcess(1,false,id);
   if(ps){
      if(!TerminateProcess(ps,-9)){
         ShowMessage((AnsiString)"Could not end process specified!");
      }
      else{
         ShowMessage((AnsiString)"Process successfully terminated!");
      }
   }
   else{
      ShowMessage((AnsiString)"Could not open process requested!");
   }
   }
   catch(Exception &e)
   {
    ShowMessage("Please select a PID");
   }
}
//---------------------------------------------------------------------------
