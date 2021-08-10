//---------------------------------------------------------------------------

#ifndef SimpleEchoClient_uH
#define SimpleEchoClient_uH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Rio.hpp>
#include <SOAPHTTPClient.hpp>
#include "SimpleEcho.h"
#include <Menus.hpp>
#include <SOAPHTTPTrans.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *EditSendInteger;
        TButton *ButtonEchoInteger;
        THTTPRIO *HTTPRIO1;
        TComboBox *CBServerURL;
        TButton *ButtonSetRioURL;
        TButton *ButtonEchoString;
        TButton *ButtonEchoBoolean;
        TButton *ButtonEchoFloat;
        TButton *ButtonEchoDate;
        TButton *ButtonEchoVoid;
        TButton *ButtonEchoHexBinary;
        TEdit *EditSendString;
        TEdit *EditSendBoolean;
        TEdit *EditSendFloat;
        TEdit *EditSendDate;
        TEdit *EditSendHexBinary;
        TEdit *EditSendVoid;
        TEdit *EditRecvInteger;
        TEdit *EditRecvString;
        TEdit *EditRecvBoolean;
        TEdit *EditRecvFloat;
        TEdit *EditRecvDate;
        TEdit *EditRecvHexBinary;
        TEdit *EditRecvVoid;
        TButton *Button1;
        TLabel *Label2;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TEdit *EditSendStringArray0;
        TEdit *EditSendStringArray1;
        TEdit *Edit3;
        TEdit *EditSendStringArray2;
        TEdit *EditSendStringArray3;
        TEdit *EditSendStringArray4;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TEdit *EditRecvStringArray0;
        TEdit *EditRecvStringArray1;
        TEdit *EditRecvStringArray2;
        TEdit *EditRecvStringArray3;
        TEdit *EditRecvStringArray4;
        TButton *ButtonEchoSimpleClass;
        TLabel *Label15;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *ClearValues1;
        TMenuItem *SendData1;
        TMenuItem *RecieveData1;
        void __fastcall ButtonEchoIntegerClick(TObject *Sender);
        void __fastcall ButtonSetRioURLClick(TObject *Sender);
        void __fastcall ButtonEchoStringClick(TObject *Sender);
        void __fastcall ButtonEchoBooleanClick(TObject *Sender);
        void __fastcall ButtonEchoFloatClick(TObject *Sender);
        void __fastcall ButtonEchoDateClick(TObject *Sender);
        void __fastcall ButtonEchoHexBinaryClick(TObject *Sender);
        void __fastcall ButtonEchoVoidClick(TObject *Sender);
        void __fastcall ButtonEchoSimpleClassClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall SendData1Click(TObject *Sender);
        void __fastcall RecieveData1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        _di_InteropTestPortType FEchoService;
        _di_InteropTestPortType GetEchoService();
__property
        _di_InteropTestPortType EchoService = { read=GetEchoService };
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
