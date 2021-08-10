// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MPlayer.pas' rev: 6.00

#ifndef MPlayerHPP
#define MPlayerHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Menus.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Dialogs.hpp>	// Pascal unit
#include <MMSystem.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Mplayer
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TMPBtnType { btPlay, btPause, btStop, btNext, btPrev, btStep, btBack, btRecord, btEject };
#pragma option pop

typedef Set<TMPBtnType, btPlay, btEject>  TButtonSet;

#pragma option push -b-
enum TMPGlyph { mgEnabled, mgDisabled, mgColored };
#pragma option pop

#pragma pack(push, 4)
struct TMPButton
{
	bool Visible;
	bool Enabled;
	bool Colored;
	bool Auto;
	Graphics::TBitmap* Bitmaps[3];
} ;
#pragma pack(pop)

#pragma option push -b-
enum TMPDeviceTypes { dtAutoSelect, dtAVIVideo, dtCDAudio, dtDAT, dtDigitalVideo, dtMMMovie, dtOther, dtOverlay, dtScanner, dtSequencer, dtVCR, dtVideodisc, dtWaveAudio };
#pragma option pop

#pragma option push -b-
enum TMPTimeFormats { tfMilliseconds, tfHMS, tfMSF, tfFrames, tfSMPTE24, tfSMPTE25, tfSMPTE30, tfSMPTE30Drop, tfBytes, tfSamples, tfTMSF };
#pragma option pop

#pragma option push -b-
enum TMPModes { mpNotReady, mpStopped, mpPlaying, mpRecording, mpSeeking, mpPaused, mpOpen };
#pragma option pop

#pragma option push -b-
enum TMPNotifyValues { nvSuccessful, nvSuperseded, nvAborted, nvFailure };
#pragma option pop

#pragma option push -b-
enum TMPDevCaps { mpCanStep, mpCanEject, mpCanPlay, mpCanRecord, mpUsesWindow };
#pragma option pop

typedef Set<TMPDevCaps, mpCanStep, mpUsesWindow>  TMPDevCapsSet;

typedef void __fastcall (__closure *EMPNotify)(System::TObject* Sender, TMPBtnType Button, bool &DoDefault);

typedef void __fastcall (__closure *EMPPostNotify)(System::TObject* Sender, TMPBtnType Button);

class DELPHICLASS EMCIDeviceError;
class PASCALIMPLEMENTATION EMCIDeviceError : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EMCIDeviceError(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EMCIDeviceError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EMCIDeviceError(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EMCIDeviceError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EMCIDeviceError(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EMCIDeviceError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EMCIDeviceError(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EMCIDeviceError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EMCIDeviceError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TMediaPlayer;
class PASCALIMPLEMENTATION TMediaPlayer : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	TMPButton Buttons[9];
	TButtonSet FVisibleButtons;
	TButtonSet FEnabledButtons;
	TButtonSet FColoredButtons;
	TButtonSet FAutoButtons;
	bool Pressed;
	bool Down;
	TMPBtnType CurrentButton;
	#pragma pack(push, 1)
	Types::TRect CurrentRect;
	#pragma pack(pop)
	
	int ButtonWidth;
	#pragma pack(push, 1)
	Types::TPoint MinBtnSize;
	#pragma pack(pop)
	
	EMPNotify FOnClick;
	EMPPostNotify FOnPostClick;
	Classes::TNotifyEvent FOnNotify;
	TMPBtnType FocusedButton;
	bool MCIOpened;
	TMPDevCapsSet FCapabilities;
	bool FCanPlay;
	bool FCanStep;
	bool FCanEject;
	bool FCanRecord;
	bool FHasVideo;
	int FFlags;
	bool FWait;
	bool FNotify;
	bool FUseWait;
	bool FUseNotify;
	bool FUseFrom;
	bool FUseTo;
	Word FDeviceID;
	TMPDeviceTypes FDeviceType;
	int FTo;
	int FFrom;
	int FFrames;
	int FError;
	TMPNotifyValues FNotifyValue;
	Controls::TWinControl* FDisplay;
	int FDWidth;
	int FDHeight;
	AnsiString FElementName;
	bool FAutoEnable;
	bool FAutoOpen;
	bool FAutoRewind;
	bool FShareable;
	void __fastcall LoadBitmaps(void);
	void __fastcall DestroyBitmaps(void);
	void __fastcall SetEnabledButtons(TButtonSet Value);
	void __fastcall SetColored(TButtonSet Value);
	HIDESBASE void __fastcall SetVisible(TButtonSet Value);
	void __fastcall SetAutoEnable(bool Value);
	void __fastcall DrawAutoButtons(void);
	HIDESBASE void __fastcall DoMouseDown(int XPos, int YPos);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseMove(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMKillFocus &Message);
	MESSAGE void __fastcall WMGetDlgCode(Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	int __fastcall VisibleButtonCount(void);
	void __fastcall Adjust(void);
	void __fastcall DoClick(TMPBtnType Button);
	void __fastcall DoPostClick(TMPBtnType Button);
	void __fastcall DrawButton(TMPBtnType Btn, int X);
	void __fastcall CheckIfOpen(void);
	void __fastcall SetPosition(int Value);
	void __fastcall SetDeviceType(TMPDeviceTypes Value);
	void __fastcall SetWait(bool Flag);
	void __fastcall SetNotify(bool Flag);
	void __fastcall SetFrom(int Value);
	void __fastcall SetTo(int Value);
	void __fastcall SetTimeFormat(TMPTimeFormats Value);
	void __fastcall SetDisplay(Controls::TWinControl* Value);
	void __fastcall SetOrigDisplay(void);
	void __fastcall SetDisplayRect(const Types::TRect &Value);
	Types::TRect __fastcall GetDisplayRect();
	void __fastcall GetDeviceCaps(void);
	int __fastcall GetStart(void);
	int __fastcall GetLength(void);
	TMPModes __fastcall GetMode(void);
	int __fastcall GetTracks(void);
	int __fastcall GetPosition(void);
	AnsiString __fastcall GetErrorMessage();
	TMPTimeFormats __fastcall GetTimeFormat(void);
	int __fastcall GetTrackLength(int TrackNum);
	int __fastcall GetTrackPosition(int TrackNum);
	
protected:
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall AutoButtonSet(TMPBtnType Btn);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	MESSAGE void __fastcall MMNotify(Messages::TMessage &Message);
	HIDESBASEDYNAMIC void __fastcall Click(TMPBtnType Button, bool &DoDefault);
	DYNAMIC void __fastcall PostClick(TMPBtnType Button);
	DYNAMIC void __fastcall DoNotify(void);
	DYNAMIC void __fastcall Updated(void);
	
public:
	__fastcall virtual TMediaPlayer(Classes::TComponent* AOwner);
	__fastcall virtual ~TMediaPlayer(void);
	void __fastcall Open(void);
	void __fastcall Close(void);
	void __fastcall Play(void);
	void __fastcall Stop(void);
	void __fastcall Pause(void);
	void __fastcall Step(void);
	void __fastcall Back(void);
	void __fastcall Previous(void);
	void __fastcall Next(void);
	void __fastcall StartRecording(void);
	void __fastcall Eject(void);
	void __fastcall Save(void);
	void __fastcall PauseOnly(void);
	void __fastcall Resume(void);
	void __fastcall Rewind(void);
	__property int TrackLength[int TrackNum] = {read=GetTrackLength};
	__property int TrackPosition[int TrackNum] = {read=GetTrackPosition};
	__property TMPDevCapsSet Capabilities = {read=FCapabilities, nodefault};
	__property int Error = {read=FError, nodefault};
	__property AnsiString ErrorMessage = {read=GetErrorMessage};
	__property int Start = {read=GetStart, nodefault};
	__property int Length = {read=GetLength, nodefault};
	__property int Tracks = {read=GetTracks, nodefault};
	__property int Frames = {read=FFrames, write=FFrames, nodefault};
	__property TMPModes Mode = {read=GetMode, nodefault};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property bool Wait = {read=FWait, write=SetWait, nodefault};
	__property bool Notify = {read=FNotify, write=SetNotify, nodefault};
	__property TMPNotifyValues NotifyValue = {read=FNotifyValue, nodefault};
	__property int StartPos = {read=FFrom, write=SetFrom, nodefault};
	__property int EndPos = {read=FTo, write=SetTo, nodefault};
	__property Word DeviceID = {read=FDeviceID, nodefault};
	__property TMPTimeFormats TimeFormat = {read=GetTimeFormat, write=SetTimeFormat, nodefault};
	__property Types::TRect DisplayRect = {read=GetDisplayRect, write=SetDisplayRect};
	
__published:
	__property TButtonSet ColoredButtons = {read=FColoredButtons, write=SetColored, default=511};
	__property Enabled  = {default=1};
	__property TButtonSet EnabledButtons = {read=FEnabledButtons, write=SetEnabledButtons, default=511};
	__property TButtonSet VisibleButtons = {read=FVisibleButtons, write=SetVisible, default=511};
	__property Anchors  = {default=3};
	__property bool AutoEnable = {read=FAutoEnable, write=SetAutoEnable, default=1};
	__property bool AutoOpen = {read=FAutoOpen, write=FAutoOpen, default=0};
	__property bool AutoRewind = {read=FAutoRewind, write=FAutoRewind, default=1};
	__property Constraints ;
	__property TMPDeviceTypes DeviceType = {read=FDeviceType, write=SetDeviceType, default=0};
	__property Controls::TWinControl* Display = {read=FDisplay, write=SetDisplay};
	__property AnsiString FileName = {read=FElementName, write=FElementName};
	__property bool Shareable = {read=FShareable, write=FShareable, default=0};
	__property Visible  = {default=1};
	__property ParentShowHint  = {default=1};
	__property ShowHint ;
	__property PopupMenu ;
	__property TabOrder  = {default=-1};
	__property TabStop  = {default=1};
	__property EMPNotify OnClick = {read=FOnClick, write=FOnClick};
	__property OnContextPopup ;
	__property OnEnter ;
	__property OnExit ;
	__property EMPPostNotify OnPostClick = {read=FOnPostClick, write=FOnPostClick};
	__property Classes::TNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TMediaPlayer(HWND ParentWindow) : Controls::TCustomControl(ParentWindow) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Mplayer */
using namespace Mplayer;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MPlayer
