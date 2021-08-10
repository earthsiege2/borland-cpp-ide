// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Messages.pas' rev: 6.00

#ifndef MessagesHPP
#define MessagesHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Messages
{
//-- type declarations -------------------------------------------------------
struct TMessage;
typedef TMessage *PMessage;

#pragma pack(push, 1)
struct TMessage
{
	unsigned Msg;
	union
	{
		struct 
		{
			Word WParamLo;
			Word WParamHi;
			Word LParamLo;
			Word LParamHi;
			Word ResultLo;
			Word ResultHi;
			
		};
		struct 
		{
			int WParam;
			int LParam;
			int Result;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMNoParams
{
	unsigned Msg;
	Word Unused[4];
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMKey
{
	unsigned Msg;
	Word CharCode;
	Word Unused;
	int KeyData;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMouse
{
	unsigned Msg;
	int Keys;
	union
	{
		struct 
		{
			Types::TSmallPoint Pos;
			int Result;
			
		};
		struct 
		{
			short XPos;
			short YPos;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMouseWheel
{
	unsigned Msg;
	short Keys;
	short WheelDelta;
	union
	{
		struct 
		{
			Types::TSmallPoint Pos;
			int Result;
			
		};
		struct 
		{
			short XPos;
			short YPos;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TMSHMouseWheel
{
	unsigned Msg;
	int WheelDelta;
	union
	{
		struct 
		{
			Types::TSmallPoint Pos;
			int Result;
			
		};
		struct 
		{
			short XPos;
			short YPos;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMWindowPosMsg
{
	unsigned Msg;
	int Unused;
	tagWINDOWPOS *WindowPos;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMScroll
{
	unsigned Msg;
	short ScrollCode;
	short Pos;
	HWND ScrollBar;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMActivate
{
	unsigned Msg;
	Word Active;
	Word Minimized;
	HWND ActiveWindow;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMActivateApp
{
	unsigned Msg;
	BOOL Active;
	int ThreadId;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMAskCBFormatName
{
	unsigned Msg;
	Word NameLen;
	Word Unused;
	char *FormatName;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMCancelMode;

#pragma pack(push, 1)
struct TWMChangeCBChain
{
	unsigned Msg;
	HWND Remove;
	HWND Next;
	int Result;
} ;
#pragma pack(pop)

typedef TWMKey  TWMChar;

#pragma pack(push, 1)
struct TWMCharToItem
{
	unsigned Msg;
	Word Key;
	Word CaretPos;
	HWND ListBox;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMChildActivate;

#pragma pack(push, 1)
struct TWMChooseFont_GetLogFont
{
	unsigned Msg;
	int Unused;
	tagLOGFONTA *LogFont;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMClear;

typedef TWMNoParams  TWMClose;

#pragma pack(push, 1)
struct TWMCommand
{
	unsigned Msg;
	Word ItemID;
	Word NotifyCode;
	HWND Ctl;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMCompacting
{
	unsigned Msg;
	int CompactRatio;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMCompareItem
{
	unsigned Msg;
	HWND Ctl;
	tagCOMPAREITEMSTRUCT *CompareItemStruct;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMCopy;

#pragma pack(push, 1)
struct TWMCopyData
{
	unsigned Msg;
	HWND From;
	tagCOPYDATASTRUCT *CopyDataStruct;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMCreate
{
	unsigned Msg;
	int Unused;
	tagCREATESTRUCTA *CreateStruct;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMCtlColor
{
	unsigned Msg;
	HDC ChildDC;
	HWND ChildWnd;
	int Result;
} ;
#pragma pack(pop)

typedef TWMCtlColor  TWMCtlColorBtn;

typedef TWMCtlColor  TWMCtlColorDlg;

typedef TWMCtlColor  TWMCtlColorEdit;

typedef TWMCtlColor  TWMCtlColorListbox;

typedef TWMCtlColor  TWMCtlColorMsgbox;

typedef TWMCtlColor  TWMCtlColorScrollbar;

typedef TWMCtlColor  TWMCtlColorStatic;

typedef TWMNoParams  TWMCut;

#pragma pack(push, 1)
struct TWMDDE_Ack
{
	unsigned Msg;
	HWND PostingApp;
	union
	{
		struct 
		{
			int PackedVal;
			
		};
		struct 
		{
			Word App;
			Word Topic;
			int Result;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDDE_Advise
{
	unsigned Msg;
	HWND PostingApp;
	int PackedVal;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDDE_Data
{
	unsigned Msg;
	HWND PostingApp;
	int PackedVal;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDDE_Execute
{
	unsigned Msg;
	HWND PostingApp;
	unsigned Commands;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDDE_Initiate
{
	unsigned Msg;
	HWND PostingApp;
	Word App;
	Word Topic;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDDE_Poke
{
	unsigned Msg;
	HWND PostingApp;
	int PackedVal;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDDE_Request
{
	unsigned Msg;
	HWND PostingApp;
	Word Format;
	Word Item;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDDE_Terminate
{
	unsigned Msg;
	HWND PostingApp;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDDE_Unadvise
{
	unsigned Msg;
	HWND PostingApp;
	Word Format;
	Word Item;
	int Result;
} ;
#pragma pack(pop)

typedef TWMKey  TWMDeadChar;

#pragma pack(push, 1)
struct TWMDeleteItem
{
	unsigned Msg;
	HWND Ctl;
	tagDELETEITEMSTRUCT *DeleteItemStruct;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMDestroy;

typedef TWMNoParams  TWMDestroyClipboard;

#pragma pack(push, 1)
struct TWMDevModeChange
{
	unsigned Msg;
	int Unused;
	char *Device;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMDrawClipboard;

#pragma pack(push, 1)
struct TWMDrawItem
{
	unsigned Msg;
	HWND Ctl;
	tagDRAWITEMSTRUCT *DrawItemStruct;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDropFiles
{
	unsigned Msg;
	unsigned Drop;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMEnable
{
	unsigned Msg;
	BOOL Enabled;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMEndSession
{
	unsigned Msg;
	BOOL EndSession;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMEnterIdle
{
	unsigned Msg;
	int Source;
	HWND IdleWnd;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMEnterMenuLoop
{
	unsigned Msg;
	BOOL IsTrackPopupMenu;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMEnterMenuLoop  TWMExitMenuLoop;

#pragma pack(push, 1)
struct TWMEraseBkgnd
{
	unsigned Msg;
	HDC DC;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMFontChange;

typedef TWMNoParams  TWMGetDlgCode;

typedef TWMNoParams  TWMGetFont;

#pragma pack(push, 1)
struct TWMGetIcon
{
	unsigned Msg;
	BOOL BigIcon;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMGetHotKey;

#pragma pack(push, 1)
struct TWMGetMinMaxInfo
{
	unsigned Msg;
	int Unused;
	tagMINMAXINFO *MinMaxInfo;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMGetText
{
	unsigned Msg;
	int TextMax;
	char *Text;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMGetTextLength;

#pragma pack(push, 1)
struct TWMHotKey
{
	unsigned Msg;
	int HotKey;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMScroll  TWMHScroll;

#pragma pack(push, 1)
struct TWMHScrollClipboard
{
	unsigned Msg;
	HWND Viewer;
	Word ScrollCode;
	Word Pos;
	int Result;
} ;
#pragma pack(pop)

typedef TWMEraseBkgnd  TWMIconEraseBkgnd;

#pragma pack(push, 1)
struct TWMInitDialog
{
	unsigned Msg;
	HWND Focus;
	int InitParam;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMInitMenu
{
	unsigned Msg;
	HMENU Menu;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMInitMenuPopup
{
	unsigned Msg;
	HMENU MenuPopup;
	short Pos;
	Word SystemMenu;
	int Result;
} ;
#pragma pack(pop)

typedef TWMKey  TWMKeyDown;

typedef TWMKey  TWMKeyUp;

#pragma pack(push, 1)
struct TWMKillFocus
{
	unsigned Msg;
	HWND FocusedWnd;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMMouse  TWMLButtonDblClk;

typedef TWMMouse  TWMLButtonDown;

typedef TWMMouse  TWMLButtonUp;

typedef TWMMouse  TWMMButtonDblClk;

typedef TWMMouse  TWMMButtonDown;

typedef TWMMouse  TWMMButtonUp;

#pragma pack(push, 1)
struct TWMMDIActivate
{
	unsigned Msg;
	union
	{
		struct 
		{
			HWND DeactiveWnd;
			HWND ActiveWnd;
			int Result;
			
		};
		struct 
		{
			HWND ChildWnd;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMDICascade
{
	unsigned Msg;
	int Cascade;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMDICreate
{
	unsigned Msg;
	int Unused;
	tagMDICREATESTRUCTA *MDICreateStruct;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMDIDestroy
{
	unsigned Msg;
	HWND Child;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMMDIGetActive;

typedef TWMNoParams  TWMMDIIconArrange;

#pragma pack(push, 1)
struct TWMMDIMaximize
{
	unsigned Msg;
	HWND Maximize;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMDINext
{
	unsigned Msg;
	HWND Child;
	int Next;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMMDIRefreshMenu;

#pragma pack(push, 1)
struct TWMMDIRestore
{
	unsigned Msg;
	HWND IDChild;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMDISetMenu
{
	unsigned Msg;
	HMENU MenuFrame;
	HMENU MenuWindow;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMDITile
{
	unsigned Msg;
	int Tile;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMeasureItem
{
	unsigned Msg;
	HWND IDCtl;
	tagMEASUREITEMSTRUCT *MeasureItemStruct;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMenuChar
{
	unsigned Msg;
	char User;
	Byte Unused;
	Word MenuFlag;
	HMENU Menu;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMenuSelect
{
	unsigned Msg;
	Word IDItem;
	Word MenuFlag;
	HMENU Menu;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMMouseActivate
{
	unsigned Msg;
	HWND TopLevel;
	Word HitTestCode;
	Word MouseMsg;
	int Result;
} ;
#pragma pack(pop)

typedef TWMMouse  TWMMouseMove;

#pragma pack(push, 1)
struct TWMMove
{
	unsigned Msg;
	int Unused;
	union
	{
		struct 
		{
			Types::TSmallPoint Pos;
			int Result;
			
		};
		struct 
		{
			short XPos;
			short YPos;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMNCActivate
{
	unsigned Msg;
	BOOL Active;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMNCCalcSize
{
	unsigned Msg;
	BOOL CalcValidRects;
	tagNCCALCSIZE_PARAMS *CalcSize_Params;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMNCCreate
{
	unsigned Msg;
	int Unused;
	tagCREATESTRUCTA *CreateStruct;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMNCDestroy;

#pragma pack(push, 1)
struct TWMNCHitTest
{
	unsigned Msg;
	int Unused;
	union
	{
		struct 
		{
			Types::TSmallPoint Pos;
			int Result;
			
		};
		struct 
		{
			short XPos;
			short YPos;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMNCHitMessage
{
	unsigned Msg;
	int HitTest;
	short XCursor;
	short YCursor;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNCHitMessage  TWMNCLButtonDblClk;

typedef TWMNCHitMessage  TWMNCLButtonDown;

typedef TWMNCHitMessage  TWMNCLButtonUp;

typedef TWMNCHitMessage  TWMNCMButtonDblClk;

typedef TWMNCHitMessage  TWMNCMButtonDown;

typedef TWMNCHitMessage  TWMNCMButtonUp;

typedef TWMNCHitMessage  TWMNCMouseMove;

#pragma pack(push, 1)
struct TWMNCPaint
{
	unsigned Msg;
	HRGN RGN;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNCHitMessage  TWMNCRButtonDblClk;

typedef TWMNCHitMessage  TWMNCRButtonDown;

typedef TWMNCHitMessage  TWMNCRButtonUp;

#pragma pack(push, 1)
struct TWMNextDlgCtl
{
	unsigned Msg;
	int CtlFocus;
	Word Handle;
	Word Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMNotify
{
	unsigned Msg;
	int IDCtrl;
	tagNMHDR *NMHdr;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMNotifyFormat
{
	unsigned Msg;
	HWND From;
	int Command;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMPaint
{
	unsigned Msg;
	HDC DC;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMPaintClipboard
{
	unsigned Msg;
	HWND Viewer;
	unsigned PaintStruct;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMPaintIcon;

#pragma pack(push, 1)
struct TWMPaletteChanged
{
	unsigned Msg;
	HWND PalChg;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMPaletteIsChanging
{
	unsigned Msg;
	HWND Realize;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMParentNotify
{
	unsigned Msg;
	Word Event;
	union
	{
		struct 
		{
			Word Value1;
			int Value2;
			int Result;
			
		};
		struct 
		{
			Word Value;
			short XPos;
			short YPos;
			
		};
		struct 
		{
			Word ChildID;
			HWND ChildWnd;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMPaste;

#pragma pack(push, 1)
struct TWMPower
{
	unsigned Msg;
	int PowerEvt;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMQueryDragIcon;

#pragma pack(push, 1)
struct TWMQueryEndSession
{
	unsigned Msg;
	int Source;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMQueryNewPalette;

typedef TWMNoParams  TWMQueryOpen;

typedef TWMNoParams  TWMQueueSync;

#pragma pack(push, 1)
struct TWMQuit
{
	unsigned Msg;
	int ExitCode;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMMouse  TWMRButtonDblClk;

typedef TWMMouse  TWMRButtonDown;

typedef TWMMouse  TWMRButtonUp;

typedef TWMNoParams  TWMRenderAllFormats;

#pragma pack(push, 1)
struct TWMRenderFormat
{
	unsigned Msg;
	int Format;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSetCursor
{
	unsigned Msg;
	HWND CursorWnd;
	Word HitTest;
	Word MouseMsg;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSetFocus
{
	unsigned Msg;
	HWND FocusedWnd;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSetFont
{
	unsigned Msg;
	HFONT Font;
	Word Redraw;
	Word Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSetHotKey
{
	unsigned Msg;
	int Key;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSetIcon
{
	unsigned Msg;
	BOOL BigIcon;
	HICON Icon;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSetRedraw
{
	unsigned Msg;
	int Redraw;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSetText
{
	unsigned Msg;
	int Unused;
	char *Text;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMShowWindow
{
	unsigned Msg;
	BOOL Show;
	int Status;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSize
{
	unsigned Msg;
	int SizeType;
	Word Width;
	Word Height;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSizeClipboard
{
	unsigned Msg;
	HWND Viewer;
	unsigned RC;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSpoolerStatus
{
	unsigned Msg;
	int JobStatus;
	Word JobsLeft;
	Word Unused;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMStyleChange
{
	unsigned Msg;
	int StyleType;
	tagSTYLESTRUCT *StyleStruct;
	int Result;
} ;
#pragma pack(pop)

typedef TWMStyleChange  TWMStyleChanged;

typedef TWMStyleChange  TWMStyleChanging;

typedef TWMKey  TWMSysChar;

typedef TWMNoParams  TWMSysColorChange;

#pragma pack(push, 1)
struct TWMSysCommand
{
	unsigned Msg;
	int CmdType;
	union
	{
		struct 
		{
			short XPos;
			short YPos;
			int Result;
			
		};
		struct 
		{
			Word Key;
			
		};
		struct 
		{
			HWND ActivateWnd;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSysDeadChar
{
	unsigned Msg;
	Word CharCode;
	Word Unused;
	int KeyData;
	int Result;
} ;
#pragma pack(pop)

typedef TWMKey  TWMSysKeyDown;

typedef TWMKey  TWMSysKeyUp;

#pragma pack(push, 1)
struct TWMSystemError
{
	unsigned Msg;
	Word ErrSpec;
	int Unused;
	int Result;
} ;
#pragma pack(pop)

typedef TWMNoParams  TWMTimeChange;

#pragma pack(push, 1)
struct TWMTimer
{
	unsigned Msg;
	int TimerID;
	void *TimerProc;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMUIState
{
	unsigned Msg;
	Word Action;
	Word Flags;
	int Unused;
} ;
#pragma pack(pop)

typedef TWMUIState  TWMChangeUIState;

typedef TWMUIState  TWMUpdateUIState;

typedef TWMNoParams  TWMQueryUIState;

typedef TWMNoParams  TWMUndo;

typedef TWMCharToItem  TWMVKeyToItem;

typedef TWMScroll  TWMVScroll;

#pragma pack(push, 1)
struct TWMVScrollClipboard
{
	unsigned Msg;
	HWND Viewer;
	Word ScollCode;
	Word ThumbPos;
	int Result;
} ;
#pragma pack(pop)

typedef TWMWindowPosMsg  TWMWindowPosChanged;

typedef TWMWindowPosMsg  TWMWindowPosChanging;

#pragma pack(push, 1)
struct TWMWinIniChange
{
	unsigned Msg;
	int Unused;
	char *Section;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMSettingChange
{
	unsigned Msg;
	int Flag;
	char *Section;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMHelp
{
	unsigned Msg;
	int Unused;
	tagHELPINFO *HelpInfo;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMDisplayChange
{
	unsigned Msg;
	int BitsPerPixel;
	Word Width;
	Word Height;
	int Result;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TWMContextMenu
{
	unsigned Msg;
	HWND hWnd;
	union
	{
		struct 
		{
			Types::TSmallPoint Pos;
			int Result;
			
		};
		struct 
		{
			short XPos;
			short YPos;
			
		};
		
	};
} ;
#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------

}	/* namespace Messages */
using namespace Messages;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Messages
