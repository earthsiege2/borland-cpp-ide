//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "ScktComp.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TChatForm : public TForm
{
__published:	// IDE-managed Components
        TBevel *Bevel1;
        TStatusBar *StatusBar1;
        TPanel *Panel1;
        TSpeedButton *SpeedButton1;
        TMemo *Memo1;
        TMemo *Memo2;
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *FileListenItem;
        TMenuItem *FileConnectItem;
        TMenuItem *Disconnect1;
        TMenuItem *N1;
        TMenuItem *Exit1;
        TServerSocket *ServerSocket;
        TClientSocket *ClientSocket;
        void __fastcall FileListenItemClick(TObject *Sender);
   void __fastcall FileConnectItemClick(TObject *Sender);
   void __fastcall Exit1Click(TObject *Sender);
   void __fastcall Memo1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift);
   void __fastcall FormCreate(TObject *Sender);
   void __fastcall ClientSocketConnect(TObject *Sender,
      TCustomWinSocket *Socket);
   void __fastcall ClientSocketDisconnect(TObject *Sender,
      TCustomWinSocket *Socket);
   void __fastcall ClientSocketRead(TObject *Sender,
      TCustomWinSocket *Socket);
   void __fastcall ServerSocketClientRead(TObject *Sender,
      TCustomWinSocket *Socket);
   void __fastcall ServerSocketAccept(TObject *Sender,
      TCustomWinSocket *Socket);
   void __fastcall ServerSocketClientConnect(TObject *Sender,
      TCustomWinSocket *Socket);
   void __fastcall Disconnect1Click(TObject *Sender);
   void __fastcall ClientSocketError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode);
   void __fastcall ServerSocketClientDisconnect(TObject *Sender,
      TCustomWinSocket *Socket);
private:	// User declarations
public:		// User declarations
        bool IsServer;
        String Server;
        __fastcall TChatForm(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern TChatForm *ChatForm;
//---------------------------------------------------------------------------
#endif
