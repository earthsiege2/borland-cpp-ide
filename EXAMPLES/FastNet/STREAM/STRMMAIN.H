//---------------------------------------------------------------------------
#ifndef strmmainH
#define strmmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <NMSTRM.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button1;
        TButton *Button2;
        TEdit *Edit1;
        TEdit *Edit2;
        TStatusBar *StatusBar1;
        TNMStrm *NMStrm1;
        TNMStrmServ *NMStrmServ1;
        TOpenPictureDialog *OpenPictureDialog1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall NMStrm1Connect(TObject *Sender);
        void __fastcall NMStrm1ConnectionFailed(TObject *Sender);
        void __fastcall NMStrm1Disconnect(TObject *Sender);
        void __fastcall NMStrm1HostResolved(TComponent *Sender);
        void __fastcall NMStrm1MessageSent(TObject *Sender);
        void __fastcall NMStrm1PacketSent(TObject *Sender);
        void __fastcall NMStrm1Status(TComponent *Sender,
      AnsiString Status);
        void __fastcall NMStrm1InvalidHost(bool &handled);
        void __fastcall NMStrmServ1ClientContact(TObject *Sender);
        void __fastcall NMStrmServ1MSG(TComponent *Sender,
      const AnsiString sFrom, TStream *strm);
        void __fastcall NMStrmServ1Status(TComponent *Sender,
      AnsiString Status);
private:	// User declarations
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
