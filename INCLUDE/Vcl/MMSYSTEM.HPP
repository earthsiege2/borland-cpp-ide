// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MMSystem.pas' rev: 5.00

#ifndef MMSystemHPP
#define MMSystemHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

#include <mmsystem.h>


namespace Mmsystem
{
//-- type declarations -------------------------------------------------------
typedef mmtime_tag *PMMTime;

typedef mmtime_tag  TMMTime;

typedef DRVCONFIGINFOEX *PDrvConfigInfoEx;

typedef DRVCONFIGINFOEX  TDrvConfigInfoEx;

typedef tagDRVCONFIGINFO *PDrvConfigInfo;

typedef tagDRVCONFIGINFO  TDrvConfigInfo;

typedef int __stdcall (*TFNDriverProc)(unsigned dwDriverId, int hdrvr, unsigned msg, int lparam1, int 
	lparam2);

typedef void __stdcall (*TFNDrvCallBack)(int hdrvr, unsigned uMsg, unsigned dwUser, unsigned dw1, unsigned 
	dw2);

typedef int *PHWAVE;

typedef int *PHWAVEIN;

typedef int *PHWAVEOUT;

typedef void __stdcall (*TFNWaveCallBack)(int hdrvr, unsigned uMsg, unsigned dwUser, unsigned dw1, unsigned 
	dw2);

typedef wavehdr_tag *PWaveHdr;

typedef wavehdr_tag  TWaveHdr;

typedef tagWAVEOUTCAPSA *PWaveOutCapsA;

typedef tagWAVEOUTCAPSW *PWaveOutCapsW;

typedef tagWAVEOUTCAPSA *PWaveOutCaps;

typedef tagWAVEOUTCAPSA  TWaveOutCapsA;

typedef tagWAVEOUTCAPSW  TWaveOutCapsW;

typedef tagWAVEOUTCAPSA  TWaveOutCaps;

typedef tagWAVEINCAPSA *PWaveInCapsA;

typedef tagWAVEINCAPSW *PWaveInCapsW;

typedef tagWAVEINCAPSA *PWaveInCaps;

typedef tagWAVEINCAPSA  TWaveInCapsA;

typedef tagWAVEINCAPSW  TWaveInCapsW;

typedef tagWAVEINCAPSA  TWaveInCaps;

typedef waveformat_tag *PWaveFormat;

typedef waveformat_tag  TWaveFormat;

typedef pcmwaveformat_tag *PPCMWaveFormat;

typedef pcmwaveformat_tag  TPCMWaveFormat;

typedef tWAVEFORMATEX *PWaveFormatEx;

typedef int *PHMIDI;

typedef int *PHMIDIIN;

typedef int *PHMIDIOUT;

typedef int *PHMIDISTRM;

typedef void __stdcall (*TFNMidiCallBack)(int hdrvr, unsigned uMsg, unsigned dwUser, unsigned dw1, unsigned 
	dw2);

typedef Word TPatchArray[128];

typedef Word *PPatchArray;

typedef Word TKeyArray[128];

typedef Word *PKeyArray;

typedef tagMIDIOUTCAPSA *PMidiOutCapsA;

typedef tagMIDIOUTCAPSW *PMidiOutCapsW;

typedef tagMIDIOUTCAPSA *PMidiOutCaps;

typedef tagMIDIOUTCAPSA  TMidiOutCapsA;

typedef tagMIDIOUTCAPSW  TMidiOutCapsW;

typedef tagMIDIOUTCAPSA  TMidiOutCaps;

typedef tagMIDIINCAPSA *PMidiInCapsA;

typedef tagMIDIINCAPSW *PMidiInCapsW;

typedef tagMIDIINCAPSA *PMidiInCaps;

typedef tagMIDIINCAPSA  TMidiInCapsA;

typedef tagMIDIINCAPSW  TMidiInCapsW;

typedef tagMIDIINCAPSA  TMidiInCaps;

typedef midihdr_tag *PMidiHdr;

typedef midihdr_tag  TMidiHdr;

typedef midievent_tag *PMidiEvent;

typedef midievent_tag  TMidiEvent;

typedef midistrmbuffver_tag *PMidiStrmBuffVer;

typedef midistrmbuffver_tag  TMidiStrmBuffVer;

typedef midiproptimediv_tag *PMidiPropTimeDiv;

typedef midiproptimediv_tag  TMidiPropTimeDiv;

typedef midiproptempo_tag *PMidiPropTempo;

typedef midiproptempo_tag  TMidiPropTempo;

typedef tagAUXCAPSA *PAuxCapsA;

typedef tagAUXCAPSW *PAuxCapsW;

typedef tagAUXCAPSA *PAuxCaps;

typedef tagAUXCAPSA  TAuxCapsA;

typedef tagAUXCAPSW  TAuxCapsW;

typedef tagAUXCAPSA  TAuxCaps;

typedef int *PHMIXEROBJ;

typedef int *PHMIXER;

typedef tagMIXERCAPSA *PMixerCapsA;

typedef tagMIXERCAPSW *PMixerCapsW;

typedef tagMIXERCAPSA *PMixerCaps;

typedef tagMIXERCAPSA  TMixerCapsA;

typedef tagMIXERCAPSW  TMixerCapsW;

typedef tagMIXERCAPSA  TMixerCaps;

typedef tagMIXERLINEA *PMixerLineA;

typedef tagMIXERLINEW *PMixerLineW;

typedef tagMIXERLINEA *PMixerLine;

struct MMSystem__1
{
	unsigned dwType;
	unsigned dwDeviceID;
	Word wMid;
	Word wPid;
	unsigned vDriverVersion;
	char szPname[32];
} ;

struct MMSystem__2
{
	unsigned dwType;
	unsigned dwDeviceID;
	Word wMid;
	Word wPid;
	unsigned vDriverVersion;
	wchar_t szPname[32];
} ;

typedef tagMIXERLINEA  TMixerLineA;

typedef tagMIXERLINEW  TMixerLineW;

typedef tagMIXERLINEA  TMixerLine;

typedef tagMIXERCONTROLA *PMixerControlA;

typedef tagMIXERCONTROLW *PMixerControlW;

typedef tagMIXERCONTROLA *PMixerControl;

struct MMSystem__3
{
	
	union
	{
		struct 
		{
			unsigned dwReserved[6];
			
		};
		struct 
		{
			unsigned dwMinimum;
			unsigned dwMaximum;
			
		};
		struct 
		{
			int lMinimum;
			int lMaximum;
			
		};
		
	};
} ;

struct MMSystem__4
{
	
	union
	{
		struct 
		{
			unsigned dwReserved[6];
			
		};
		struct 
		{
			unsigned cbCustomData;
			
		};
		struct 
		{
			unsigned cSteps;
			
		};
		
	};
} ;

struct MMSystem__5
{
	
	union
	{
		struct 
		{
			unsigned dwReserved[6];
			
		};
		struct 
		{
			unsigned dwMinimum;
			unsigned dwMaximum;
			
		};
		struct 
		{
			int lMinimum;
			int lMaximum;
			
		};
		
	};
} ;

struct MMSystem__6
{
	
	union
	{
		struct 
		{
			unsigned dwReserved[6];
			
		};
		struct 
		{
			unsigned cbCustomData;
			
		};
		struct 
		{
			unsigned cSteps;
			
		};
		
	};
} ;

typedef tagMIXERCONTROLA  TMixerControlA;

typedef tagMIXERCONTROLW  TMixerControlW;

typedef tagMIXERCONTROLA  TMixerControl;

typedef tagMIXERLINECONTROLSA *PMixerLineControlsA;

typedef tagMIXERLINECONTROLSW *PMixerLineControlsW;

typedef tagMIXERLINECONTROLSA *PMixerLineControls;

typedef tagMIXERLINECONTROLSA  TMixerLineControlsA;

typedef tagMIXERLINECONTROLSW  TMixerLineControlsW;

typedef tagMIXERLINECONTROLSA  TMixerLineControls;

typedef tMIXERCONTROLDETAILS *PMixerControlDetails;

typedef tagMIXERCONTROLDETAILS_LISTTEXTA *PMixerControlDetailsListTextA;

typedef tagMIXERCONTROLDETAILS_LISTTEXTW *PMixerControlDetailsListTextW;

typedef tagMIXERCONTROLDETAILS_LISTTEXTA *PMixerControlDetailsListText;

typedef tagMIXERCONTROLDETAILS_LISTTEXTA  TMixerControlDetailsListTextA;

typedef tagMIXERCONTROLDETAILS_LISTTEXTW  TMixerControlDetailsListTextW;

typedef tagMIXERCONTROLDETAILS_LISTTEXTA  TMixerControlDetailsListText;

typedef tMIXERCONTROLDETAILS_BOOLEAN *PMixerControlDetailsBoolean;

typedef tMIXERCONTROLDETAILS_BOOLEAN  TMixerControlDetailsBoolean;

typedef tMIXERCONTROLDETAILS_SIGNED *PMixerControlDetailsSigned;

typedef tMIXERCONTROLDETAILS_SIGNED  TMixerControlDetailsSigned;

typedef tMIXERCONTROLDETAILS_UNSIGNED *PMixerControlDetailsUnsigned;

typedef tMIXERCONTROLDETAILS_UNSIGNED  TMixerControlDetailsUnsigned;

typedef void __stdcall (*TFNTimeCallBack)(unsigned uTimerID, unsigned uMessage, unsigned dwUser, unsigned 
	dw1, unsigned dw2);

typedef timecaps_tag *PTimeCaps;

typedef timecaps_tag  TTimeCaps;

typedef tagJOYCAPSA *PJoyCapsA;

typedef tagJOYCAPSW *PJoyCapsW;

typedef tagJOYCAPSA *PJoyCaps;

typedef tagJOYCAPSA  TJoyCapsA;

typedef tagJOYCAPSW  TJoyCapsW;

typedef tagJOYCAPSA  TJoyCaps;

typedef joyinfo_tag *PJoyInfo;

typedef joyinfo_tag  TJoyInfo;

typedef joyinfoex_tag *PJoyInfoEx;

typedef joyinfoex_tag  TJoyInfoEx;

typedef int *PHMMIO;

typedef int __stdcall (*TFNMMIOProc)(char * lpmmioinfo, unsigned uMessage, int lParam1, int lParam2)
	;

typedef _MMIOINFO *PMMIOInfo;

typedef _MMIOINFO  TMMIOInfo;

typedef _MMCKINFO *PMMCKInfo;

typedef _MMCKINFO  TMMCKInfo;

typedef unsigned __stdcall (*TFNYieldProc)(unsigned mciId, unsigned dwYieldData);

typedef tagMCI_GENERIC_PARMS *PMCI_Generic_Parms;

typedef tagMCI_GENERIC_PARMS  TMCI_Generic_Parms;

typedef tagMCI_OPEN_PARMSA *PMCI_Open_ParmsA;

typedef tagMCI_OPEN_PARMSW *PMCI_Open_ParmsW;

typedef tagMCI_OPEN_PARMSA *PMCI_Open_Parms;

typedef tagMCI_OPEN_PARMSA  TMCI_Open_ParmsA;

typedef tagMCI_OPEN_PARMSW  TMCI_Open_ParmsW;

typedef tagMCI_OPEN_PARMSA  TMCI_Open_Parms;

typedef tagMCI_PLAY_PARMS *PMCI_Play_Parms;

typedef tagMCI_PLAY_PARMS  TMCI_Play_Parms;

typedef tagMCI_SEEK_PARMS *PMCI_Seek_Parms;

typedef tagMCI_SEEK_PARMS  TMCI_Seek_Parms;

typedef tagMCI_STATUS_PARMS *PMCI_Status_Parms;

typedef tagMCI_STATUS_PARMS  TMCI_Status_Parms;

typedef tagMCI_INFO_PARMSA *PMCI_Info_ParmsA;

typedef tagMCI_INFO_PARMSW *PMCI_Info_ParmsW;

typedef tagMCI_INFO_PARMSA *PMCI_Info_Parms;

typedef tagMCI_INFO_PARMSA  TMCI_Info_ParmsA;

typedef tagMCI_INFO_PARMSW  TMCI_Info_ParmsW;

typedef tagMCI_INFO_PARMSA  TMCI_Info_Parms;

typedef tagMCI_GETDEVCAPS_PARMS *PMCI_GetDevCaps_Parms;

typedef tagMCI_GETDEVCAPS_PARMS  TMCI_GetDevCaps_Parms;

typedef tagMCI_SYSINFO_PARMSA *PMCI_SysInfo_ParmsA;

typedef tagMCI_SYSINFO_PARMSW *PMCI_SysInfo_ParmsW;

typedef tagMCI_SYSINFO_PARMSA *PMCI_SysInfo_Parms;

typedef tagMCI_SYSINFO_PARMSA  TMCI_SysInfo_ParmsA;

typedef tagMCI_SYSINFO_PARMSW  TMCI_SysInfo_ParmsW;

typedef tagMCI_SYSINFO_PARMSA  TMCI_SysInfo_Parms;

typedef tagMCI_SET_PARMS *PMCI_Set_Parms;

typedef tagMCI_SET_PARMS  TMCI_Set_Parms;

typedef tagMCI_BREAK_PARMS *PMCI_Break_Parms;

typedef tagMCI_BREAK_PARMS  TMCI_BReak_Parms;

struct TMCI_Sound_Parms;
typedef TMCI_Sound_Parms *PMCI_Sound_Parms;

struct TMCI_Sound_Parms
{
	int dwCallback;
	char *lpstrSoundName;
} ;

typedef MCI_SAVE_PARMSA *PMCI_Save_ParmsA;

typedef MCI_SAVE_PARMSW *PMCI_Save_ParmsW;

typedef MCI_SAVE_PARMSA *PMCI_Save_Parms;

typedef MCI_SAVE_PARMSA  TMCI_SaveParmsA;

typedef MCI_SAVE_PARMSW  TMCI_SaveParmsW;

typedef MCI_SAVE_PARMSA  TMCI_SaveParms;

typedef tagMCI_LOAD_PARMSA *PMCI_Load_ParmsA;

typedef tagMCI_LOAD_PARMSW *PMCI_Load_ParmsW;

typedef tagMCI_LOAD_PARMSA *PMCI_Load_Parms;

typedef tagMCI_LOAD_PARMSA  TMCI_Load_ParmsA;

typedef tagMCI_LOAD_PARMSW  TMCI_Load_ParmsW;

typedef tagMCI_LOAD_PARMSA  TMCI_Load_Parms;

typedef tagMCI_RECORD_PARMS *PMCI_Record_Parms;

typedef tagMCI_RECORD_PARMS  TMCI_Record_Parms;

typedef tagMCI_VD_PLAY_PARMS *PMCI_VD_Play_Parms;

typedef tagMCI_VD_PLAY_PARMS  TMCI_VD_Play_Parms;

typedef tagMCI_VD_STEP_PARMS *PMCI_VD_Step_Parms;

typedef tagMCI_VD_STEP_PARMS  TMCI_VD_Step_Parms;

typedef tagMCI_VD_ESCAPE_PARMSA *PMCI_VD_Escape_ParmsA;

typedef tagMCI_VD_ESCAPE_PARMSW *PMCI_VD_Escape_ParmsW;

typedef tagMCI_VD_ESCAPE_PARMSA *PMCI_VD_Escape_Parms;

typedef tagMCI_VD_ESCAPE_PARMSA  TMCI_VD_Escape_ParmsA;

typedef tagMCI_VD_ESCAPE_PARMSW  TMCI_VD_Escape_ParmsW;

typedef tagMCI_VD_ESCAPE_PARMSA  TMCI_VD_Escape_Parms;

typedef tagMCI_WAVE_OPEN_PARMSA *PMCI_Wave_Open_ParmsA;

typedef tagMCI_WAVE_OPEN_PARMSW *PMCI_Wave_Open_ParmsW;

typedef tagMCI_WAVE_OPEN_PARMSA *PMCI_Wave_Open_Parms;

typedef tagMCI_WAVE_OPEN_PARMSA  TMCI_Wave_Open_ParmsA;

typedef tagMCI_WAVE_OPEN_PARMSW  TMCI_Wave_Open_ParmsW;

typedef tagMCI_WAVE_OPEN_PARMSA  TMCI_Wave_Open_Parms;

typedef tagMCI_WAVE_DELETE_PARMS *PMCI_Wave_Delete_Parms;

typedef tagMCI_WAVE_DELETE_PARMS  TMCI_Wave_Delete_Parms;

typedef tagMCI_WAVE_SET_PARMS *PMCI_Wave_Set_Parms;

typedef tagMCI_WAVE_SET_PARMS  TMCI_Wave_Set_Parms;

typedef tagMCI_SEQ_SET_PARMS *PMCI_Seq_Set_Parms;

typedef tagMCI_SEQ_SET_PARMS  TMCI_Seq_Set_Parms;

typedef tagMCI_ANIM_OPEN_PARMSA *PMCI_Anim_Open_ParmsA;

typedef tagMCI_ANIM_OPEN_PARMSW *PMCI_Anim_Open_ParmsW;

typedef tagMCI_ANIM_OPEN_PARMSA *PMCI_Anim_Open_Parms;

typedef tagMCI_ANIM_OPEN_PARMSA  TMCI_Anim_Open_ParmsA;

typedef tagMCI_ANIM_OPEN_PARMSW  TMCI_Anim_Open_ParmsW;

typedef tagMCI_ANIM_OPEN_PARMSA  TMCI_Anim_Open_Parms;

typedef tagMCI_ANIM_PLAY_PARMS *PMCI_Anim_Play_Parms;

typedef tagMCI_ANIM_PLAY_PARMS  TMCI_Anim_Play_Parms;

typedef tagMCI_ANIM_STEP_PARMS *PMCI_Anim_Step_Parms;

typedef tagMCI_ANIM_STEP_PARMS  TMCI_Anim_Step_Parms;

typedef tagMCI_ANIM_WINDOW_PARMSA *PMCI_Anim_Window_ParmsA;

typedef tagMCI_ANIM_WINDOW_PARMSW *PMCI_Anim_Window_ParmsW;

typedef tagMCI_ANIM_WINDOW_PARMSA *PMCI_Anim_Window_Parms;

typedef tagMCI_ANIM_WINDOW_PARMSA  TMCI_Anim_Window_ParmsA;

typedef tagMCI_ANIM_WINDOW_PARMSW  TMCI_Anim_Window_ParmsW;

typedef tagMCI_ANIM_WINDOW_PARMSA  TMCI_Anim_Window_Parms;

typedef tagMCI_ANIM_RECT_PARMS *PMCI_Anim_Rect_Parms;

typedef tagMCI_ANIM_RECT_PARMS  TMCI_Anim_Rect_Parms;

typedef tagMCI_ANIM_UPDATE_PARMS *PMCI_Anim_Update_Parms;

typedef tagMCI_ANIM_UPDATE_PARMS  TMCI_Anim_Update_Parms;

typedef tagMCI_OVLY_OPEN_PARMSA *PMCI_Ovly_Open_ParmsA;

typedef tagMCI_OVLY_OPEN_PARMSW *PMCI_Ovly_Open_ParmsW;

typedef tagMCI_OVLY_OPEN_PARMSA *PMCI_Ovly_Open_Parms;

typedef tagMCI_OVLY_OPEN_PARMSA  TMCI_Ovly_Open_ParmsA;

typedef tagMCI_OVLY_OPEN_PARMSW  TMCI_Ovly_Open_ParmsW;

typedef tagMCI_OVLY_OPEN_PARMSA  TMCI_Ovly_Open_Parms;

typedef tagMCI_OVLY_WINDOW_PARMSA *PMCI_Ovly_Window_ParmsA;

typedef tagMCI_OVLY_WINDOW_PARMSW *PMCI_Ovly_Window_ParmsW;

typedef tagMCI_OVLY_WINDOW_PARMSA *PMCI_Ovly_Window_Parms;

typedef tagMCI_OVLY_WINDOW_PARMSA  TMCI_Ovly_Window_ParmsA;

typedef tagMCI_OVLY_WINDOW_PARMSW  TMCI_Ovly_Window_ParmsW;

typedef tagMCI_OVLY_WINDOW_PARMSA  TMCI_Ovly_Window_Parms;

typedef tagMCI_OVLY_RECT_PARMS *PMCI_Ovly_Rect_Parms;

typedef tagMCI_OVLY_RECT_PARMS  TMCI_Ovly_Rect_Parms;

typedef tagMCI_OVLY_SAVE_PARMSA *PMCI_Ovly_Save_ParmsA;

typedef tagMCI_OVLY_SAVE_PARMSW *PMCI_Ovly_Save_ParmsW;

typedef tagMCI_OVLY_SAVE_PARMSA *PMCI_Ovly_Save_Parms;

typedef tagMCI_OVLY_SAVE_PARMSA  TMCI_Ovly_Save_ParmsA;

typedef tagMCI_OVLY_SAVE_PARMSW  TMCI_Ovly_Save_ParmsW;

typedef tagMCI_OVLY_SAVE_PARMSA  TMCI_Ovly_Save_Parms;

typedef tagMCI_OVLY_LOAD_PARMSA *PMCI_Ovly_Load_ParmsA;

typedef tagMCI_OVLY_LOAD_PARMSW *PMCI_Ovly_Load_ParmsW;

typedef tagMCI_OVLY_LOAD_PARMSA *PMCI_Ovly_Load_Parms;

typedef tagMCI_OVLY_LOAD_PARMSA  TMCI_Ovly_Load_ParmsA;

typedef tagMCI_OVLY_LOAD_PARMSW  TMCI_Ovly_Load_ParmsW;

typedef tagMCI_OVLY_LOAD_PARMSA  TMCI_Ovly_Load_Parms;

//-- var, const, procedure ---------------------------------------------------
static const Word MCI_SOUND = 0x812;
static const Word MCI_SOUND_NAME = 0x100;
#define mmsyst "winmm.dll"
extern PACKAGE int __fastcall DIBIndex(int N);

}	/* namespace Mmsystem */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Mmsystem;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MMSystem
