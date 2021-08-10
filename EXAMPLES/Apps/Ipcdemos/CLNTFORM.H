//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//Converting header file...
//----------------------------------------------------------------------------
#ifndef ClntFormHPP
#define ClntFormHPP
//----------------------------------------------------------------------------
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Dialogs.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <StdCtrls.hpp>
#include <SysUtils.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <Forms.hpp>
#include <System.hpp>
#include "IPCThrd.h"

#define WM_UPDATESTATUS WM_USER + 2

//-- type declarations -------------------------------------------------------
class TClientForm : public TForm
{

__published:
	TStatusBar *StatusBar;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormMouseMove(TObject *Sender,  TShiftState Shift, int X, int Y);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,  TShiftState Shift, int X,
		int Y);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormClick(TObject *Sender);

	
	
private:
	AnsiString FStatusText;
	void __fastcall OnConnect(TIPCThread *Sender, bool Connecting);
	void __fastcall OnSignal(TIPCThread *Sender, const TEventData &Data);
	void __fastcall UpdateStatusBar(TMessage* Msg);
	TIPCClient *IPCClient;
	TClientFlags Flags;
   
public:
	__fastcall  virtual TClientForm(TComponent *Owner) ;
        virtual void __fastcall Dispatch(void *Message)
        {
          switch(((PMessage)Message)->Msg)
            {

              case    WM_UPDATESTATUS:
                 UpdateStatusBar((TMessage*)Message);
              break;
              default:
                 TForm::Dispatch(Message);
              break;
            }
        }
};

//-- var, const, procedure ---------------------------------------------------
extern TClientForm *ClientForm;
//-- end unit ----------------------------------------------------------------
#endif	// ClntForm

