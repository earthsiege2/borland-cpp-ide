//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
#ifndef MonFormHPP
#define MonFormHPP
//----------------------------------------------------------------------------
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <TypInfo.hpp>
#include <StdCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <System.hpp>
#include "IPCThrd.h"

//-- message defines ---------------------------------------------------------
#define WM_SETTRACEDATA WM_USER + 1
#define WM_UPDATESTATUS WM_USER + 2
#define WM_UPDATEMENU   WM_USER + 3
//-- type declarations -------------------------------------------------------
struct TWMTraceData
{
	Cardinal Msg;
	Longint X;
	Longint Y;
	TClientFlag Flag;
	Longint Result;
} ;

struct TLabelRec
{
	TLabel *XLabel;
	TLabel *YLabel;
} ;

class TMonitorForm : public TForm
{

__published:
	TLabel *DownX;
	TLabel *DownY;
	TLabel *SizeX;
	TLabel *SizeY;
	TLabel *MoveX;
	TLabel *MoveY;
	TBevel *Bevel1;
	TPanel *Panel1;
	TSpeedButton *PauseButton;
	TStatusBar *StatusBar;
	TCheckBox *MouseMove;
	TCheckBox *MouseDown;
	TCheckBox *WindowSize;
	TMainMenu *MainMenu;
	TMenuItem *Options1;
	TMenuItem *AutoClientSwitch1;
	TMenuItem *PlaceHolder21;
	TMenuItem *File1;
	TMenuItem *miFileExit;
	TMenuItem *miClients;
	TMenuItem *PlaceHolder1;
	TMenuItem *Help1;
	TMenuItem *About1;
	TSpeedButton *ShowTraceButton;
	TSpeedButton *ClearButton;
	TSpeedButton *ExitButton;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall ClientMenuClick(TObject *Sender);
	void __fastcall miClientsClick(TObject *Sender);
	void __fastcall SetTraceFlags(TObject *Sender);
	void __fastcall AutoClientSwitch1Click(TObject *Sender);
	void __fastcall miFileExitClick(TObject *Sender);
	void __fastcall ShowTraceButtonClick(TObject *Sender);
	void __fastcall PauseButtonClick(TObject *Sender);
	void __fastcall ClearButtonClick(TObject *Sender);
	void __fastcall ExitButtonClick(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);




private:
	TWMTraceData FTraceMsg;
	TIPCMonitor *IPCMonitor;
	TLabelRec TraceLabels[5];
	TEventData FClientData;
	AnsiString FStatusText;
	void __fastcall ClearLabels(void);
	void __fastcall OnConnect(TIPCThread *Sender, Boolean Connecting);
	void __fastcall OnDirectoryUpdate(TIPCThread *Sender);
	void __fastcall OnSignal(TIPCThread *Sender, const TEventData &Data);
	void __fastcall SignalClientStatus();
        void __fastcall TMonitorForm::SetupLabelArray();
        void __fastcall UpdateTraceData(TWMTraceData* Msg);
        void __fastcall UpdateStatusBar(TMessage* Msg);
        void __fastcall UpdateClientMenu(TMessage* Msg);


public:
	virtual __fastcall  TMonitorForm::TMonitorForm(TComponent *Owner);

        virtual void __fastcall Dispatch(void *Message)
        {
          switch(((PMessage)Message)->Msg)
            {

              case    WM_SETTRACEDATA:
                 UpdateTraceData((TWMTraceData*)Message);
              break;
              case    WM_UPDATESTATUS:
                 UpdateStatusBar((TMessage*)Message);
              break;
              case    WM_UPDATEMENU:
                 UpdateClientMenu((TMessage*)Message);
              break;
              default:
                 TForm::Dispatch(Message);
              break;
            }
        }
};

//-- var, const, procedure ---------------------------------------------------
extern TMonitorForm *MonitorForm;
//-- end unit ----------------------------------------------------------------
#endif	// MonForm

