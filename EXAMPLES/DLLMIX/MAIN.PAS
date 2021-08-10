//----------------------------------------------------------------------------
// Mixing BC++ built 32-bit DLL's with non-BC applications.
// Copyright (c) 1996 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
unit main;

interface

uses
   Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
   ExtCtrls, StdCtrls, Menus;

type
   { Function types }
   TbcMessage = function (msg: pchar) : Longint; stdcall;
   TbcMultiply =   function (m1: Smallint; m2: Longint) : Longint; cdecl;
   TbcAverage = function (d: Double; f: Single) : Extended; stdcall;
   TCdeclVoidFunc = procedure cdecl;
   TStdCallVoidFunc = procedure stdcall;

   TDelphiToBC = class(TForm)
      BtnMessage: TButton;
      BtnMultiply: TButton;
      BtnAverage: TButton;
      BtnExceptionTest: TButton;
      BtnUnhandledException: TButton;
      Image1: TImage;
      CancelBtn: TButton;

      procedure FormCreate(Sender: TObject);
      procedure FormClose(Sender: TObject; var Action: TCloseAction);
      procedure BtnMessageClick(Sender: TObject);
      procedure BtnMultiplyClick(Sender: TObject);
      procedure BtnAverageClick(Sender: TObject);
      procedure BtnExceptionTestClick(Sender: TObject);
      procedure BtnUnhandledExceptionTestClick(Sender: TObject);
    procedure CancelBtnClick(Sender: TObject);
   private
      { Private declarations }
      hCDll           :Longint;
      bcMessage       :TbcMessage;
      bcMultiply      :TbcMultiply;
      bcAverage       :TbcAverage;
      bcExceptionTest :TCdeclVoidFunc;
      bcUnhandledTest :TStdCallVoidFunc;
      procedure NoDLL;
   public
      { Public declarations }
   end;

var
   DelphiToBC      :TDelphiToBC;

implementation

{$R *.DFM}

procedure TDelphiToBC.FormCreate(Sender: TObject);
begin
   hCDll := LoadLibrary('BCDLL');
   if hCDll <= HINSTANCE_ERROR then
      begin
         ShowMessage('LoadLibrary failure');
         hCDll := NULL;
      end
   else
      begin
         { GetProcAddress expects an exact, case-sensitive match }
         { So, we must add addornments for Cdecl and force upper case for PASCAL }
         bcMessage       := GetProcAddress(hCDll, 'Message');
         bcMultiply      := GetProcAddress(hCDll, '_Multiply');
         bcAverage       := GetProcAddress(hCDll, 'Average');
         bcExceptionTest := GetProcAddress(hCDll, '_ExceptionTest');
         bcUnhandledTest := GetProcAddress(hCDll, 'UnhandledException');
      end;
end;

procedure TDelphiToBC.FormClose(Sender: TObject; var Action: TCloseAction);
begin
   if not hCDll = NULL then
   begin
      FreeLibrary(hCDll);
      hCdll := NULL;
   end;
end;

procedure TDelphiToBC.NoDLL();
begin
   ShowMessage('Function not hooked up. DLL loaded?');
end;

procedure TDelphiToBC.BtnMessageClick(Sender: TObject);
begin
   if not Assigned (bcMessage) then
      begin
         NoDLL;
         exit;
      end;
   bcMessage('A message from Delphi');
end;

procedure TDelphiToBC.BtnMultiplyClick(Sender: TObject);
var
   si    : Smallint;
   li    : Longint;
   ans   : Longint;
   str   : string[40];
begin
   if not Assigned (bcMultiply) then
      begin
         NoDLL;
         exit;
      end;
   si := 55;
   li := -1024;
   ans := bcMultiply(si, li);
   str := IntToStr(si) + ' * ' + IntToStr(li) + ' = ' + IntToStr(ans);
   ShowMessage(str);
end;

{   TbcAverage = function (d: Double; f: Single) : Extended; stdcall; }
procedure TDelphiToBC.BtnAverageClick(Sender: TObject);
var
   dbl   : Double;
   sngl  : Single;
   ans   : Extended;
   str   : string;
begin
   if not Assigned (bcAverage) then
      begin
         NoDLL;
         exit;
      end;
   dbl := 6232.001;
   sngl := 128.327;
   ans := bcAverage(dbl, sngl);
   str := 'The average of ' + string(Variant(dbl)) + ' and ' + string(Variant(sngl))
         + ' is ' + string(Variant(ans));
   ShowMessage(str);
end;

procedure TDelphiToBC.BtnExceptionTestClick(Sender: TObject);
begin
   if not Assigned (bcExceptionTest) then
      begin
         NoDLL;
         exit;
      end;
   bcExceptionTest;
end;

procedure TDelphiToBC.BtnUnhandledExceptionTestClick(Sender: TObject);
begin
   if not Assigned (bcUnhandledTest) then
      begin
         NoDLL;
         exit;
      end;
   try
      bcUnhandledTest;
   except
      ShowMessage('Application caught exception thrown from a Borland C++ DLL');
   end;

end;

procedure TDelphiToBC.CancelBtnClick(Sender: TObject);
begin
   application.terminate();
end;

end.
