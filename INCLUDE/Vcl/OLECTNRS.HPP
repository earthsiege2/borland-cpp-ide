// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OleCtnrs.pas' rev: 5.00

#ifndef OleCtnrsHPP
#define OleCtnrsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ComObj.hpp>	// Pascal unit
#include <Graphics.hpp>	// Pascal unit
#include <Menus.hpp>	// Pascal unit
#include <Forms.hpp>	// Pascal unit
#include <Controls.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <OleDlg.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Commctrl.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <DocObj.h>

namespace Olectnrs
{
//-- type declarations -------------------------------------------------------
__interface IVCLFrameForm;
typedef System::DelphiInterface<IVCLFrameForm> _di_IVCLFrameForm;
class DELPHICLASS TOleContainer;
__interface INTERFACE_UUID("{CD02E1C0-52DA-11D0-9EA6-0020AF3D82DA}") IVCLFrameForm  : public IOleInPlaceFrame 
	
{
	
public:
	virtual void __fastcall AddContainer(TOleContainer* Instance) = 0 ;
	virtual void __fastcall RemoveContainer(TOleContainer* Instance) = 0 ;
	virtual void __fastcall ClearBorderSpace(void) = 0 ;
	virtual Forms::TCustomForm* __fastcall Form(void) = 0 ;
};

#pragma option push -b-
enum TAutoActivate { aaManual, aaGetFocus, aaDoubleClick };
#pragma option pop

#pragma option push -b-
enum TSizeMode { smClip, smCenter, smScale, smStretch, smAutoSize };
#pragma option pop

#pragma option push -b-
enum TObjectState { osEmpty, osLoaded, osRunning, osOpen, osInPlaceActive, osUIActive };
#pragma option pop

#pragma option push -b-
enum TCreateType { ctNewObject, ctFromFile, ctLinkToFile, ctFromData, ctLinkFromData };
#pragma option pop

struct TCreateInfo
{
	TCreateType CreateType;
	bool ShowAsIcon;
	unsigned IconMetaPict;
	GUID ClassID;
	WideString FileName;
	_di_IDataObject DataObject;
} ;

#pragma pack(push, 1)
struct TVerbInfo
{
	short Verb;
	Word Flags;
} ;
#pragma pack(pop)

typedef void __fastcall (__closure *TObjectMoveEvent)(TOleContainer* OleContainer, const Windows::TRect 
	&Bounds);

class PASCALIMPLEMENTATION TOleContainer : public Controls::TCustomControl 
{
	typedef Controls::TCustomControl inherited;
	
private:
	int FRefCount;
	_di_ILockBytes FLockBytes;
	_di_IStorage FStorage;
	_di_IOleObject FOleObject;
	int FDrawAspect;
	Windows::TPoint FViewSize;
	Classes::TStringList* FObjectVerbs;
	int FDataConnection;
	_di_IVCLFrameForm FDocForm;
	_di_IVCLFrameForm FFrameForm;
	_di_IOleInPlaceObject FOleInPlaceObject;
	_di_IOleInPlaceActiveObject FOleInPlaceActiveObject;
	HACCEL FAccelTable;
	int FAccelCount;
	Menus::TPopupMenu* FPopupVerbMenu;
	bool FAllowInPlace;
	bool FAllowActiveDoc;
	TAutoActivate FAutoActivate;
	bool FAutoVerbMenu;
	Forms::TFormBorderStyle FBorderStyle;
	bool FCopyOnSave;
	bool FOldStreamFormat;
	TSizeMode FSizeMode;
	bool FObjectOpen;
	bool FUIActive;
	bool FModified;
	bool FModSinceSave;
	bool FFocused;
	bool FNewInserted;
	Classes::TNotifyEvent FOnActivate;
	Classes::TNotifyEvent FOnDeactivate;
	TObjectMoveEvent FOnObjectMove;
	Classes::TNotifyEvent FOnResize;
	_di_IOleDocumentView FDocView;
	bool FDocObj;
	HRESULT __stdcall SaveObject(void);
	HRESULT __stdcall GetMoniker(int dwAssign, int dwWhichMoniker, /* out */ _di_IMoniker &mk);
	HRESULT __stdcall GetContainer(/* out */ _di_IOleContainer &container);
	HRESULT __stdcall ShowObject(void);
	HRESULT __stdcall OnShowWindow(BOOL fShow);
	HRESULT __stdcall RequestNewObjectLayout(void);
	HRESULT __stdcall ContextSensitiveHelp(BOOL fEnterMode);
	HRESULT __stdcall GetWindow(/* out */ HWND &wnd);
	HRESULT __stdcall CanInPlaceActivate(void);
	HRESULT __stdcall OnInPlaceActivate(void);
	HRESULT __stdcall OnUIActivate(void);
	HRESULT __stdcall GetWindowContext(/* out */ _di_IOleInPlaceFrame &frame, /* out */ _di_IOleInPlaceUIWindow 
		&doc, /* out */ Windows::TRect &rcPosRect, /* out */ Windows::TRect &rcClipRect, /* out */ tagOIFI 
		&frameInfo);
	HRESULT __stdcall Scroll(const Windows::TPoint scrollExtent);
	HRESULT __stdcall OnUIDeactivate(BOOL fUndoable);
	HRESULT __stdcall OnInPlaceDeactivate(void);
	HRESULT __stdcall DiscardUndoState(void);
	HRESULT __stdcall DeactivateAndUndo(void);
	HRESULT __stdcall OnPosRectChange(const Windows::TRect &rcPosRect);
	void __stdcall OnDataChange(const tagFORMATETC &formatetc, const tagSTGMEDIUM &stgmed);
	void __stdcall OnViewChange(int dwAspect, int lindex);
	void __stdcall OnRename(const _di_IMoniker mk);
	void __stdcall OnSave(void);
	void __stdcall OnClose(void);
	HRESULT __stdcall ActivateMe(_di_IOleDocumentView View);
	HRESULT __stdcall GetObjectInfo(int dwObject, int &dwObjSize, char * &lpszLabel, char * &lpszType, 
		char * &lpszShortType, char * &lpszLocation);
	HRESULT __stdcall GetConvertInfo(int dwObject, GUID &ClassID, Word &wFormat, GUID &ConvertDefaultClassID
		, System::PGUID &lpClsidExclude, int &cClsidExclude);
	HRESULT __stdcall ConvertObject(int dwObject, const GUID &clsidNew);
	HRESULT __stdcall GetViewInfo(int dwObject, unsigned &hMetaPict, int &dvAspect, int &nCurrentScale)
		;
	HRESULT __stdcall SetViewInfo(int dwObject, unsigned hMetaPict, int dvAspect, int nCurrentScale, BOOL 
		bRelativeToOrig);
	void __fastcall AdjustBounds(void);
	void __fastcall CheckObject(void);
	void __fastcall CreateAccelTable(void);
	void __fastcall CreateStorage(void);
	void __fastcall DesignModified(void);
	void __fastcall DestroyAccelTable(void);
	void __fastcall DestroyVerbs(void);
	int __fastcall GetBorderWidth(void);
	bool __fastcall GetCanPaste(void);
	bool __fastcall GetIconic(void);
	bool __fastcall GetLinked(void);
	int __fastcall GetObjectDataSize(void);
	Classes::TStrings* __fastcall GetObjectVerbs(void);
	AnsiString __fastcall GetOleClassName();
	Variant __fastcall GetOleObject();
	int __fastcall GetPrimaryVerb(void);
	AnsiString __fastcall GetSourceDoc();
	TObjectState __fastcall GetState(void);
	void __fastcall InitObject(void);
	void __fastcall ObjectMoved(const Windows::TRect &ObjectRect);
	void __fastcall PopupVerbMenuClick(System::TObject* Sender);
	void __fastcall SetBorderStyle(Forms::TBorderStyle Value);
	void __fastcall SetDrawAspect(bool Iconic, unsigned IconMetaPict);
	void __fastcall SetFocused(bool Value);
	void __fastcall SetIconic(bool Value);
	void __fastcall SetSizeMode(TSizeMode Value);
	void __fastcall SetUIActive(bool Active);
	void __fastcall SetViewAdviseSink(bool Enable);
	void __fastcall UpdateObjectRect(void);
	void __fastcall UpdateView(void);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Messages::TMessage &Message);
	MESSAGE void __fastcall CMDocWindowActivate(Messages::TMessage &Message);
	MESSAGE void __fastcall CMUIDeactivate(Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Messages::TWMSize &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Messages::TWMWindowPosMsg &Message);
	
protected:
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	HIDESBASEDYNAMIC void __fastcall Changed(void);
	virtual void __fastcall CreateParams(Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC Menus::TPopupMenu* __fastcall GetPopupMenu(void);
	DYNAMIC void __fastcall KeyDown(Word &Key, Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(Controls::TMouseButton Button, Classes::TShiftState Shift, int X, 
		int Y);
	virtual void __fastcall Paint(void);
	
public:
	__fastcall virtual TOleContainer(Classes::TComponent* AOwner);
	__fastcall virtual ~TOleContainer(void);
	bool __fastcall ChangeIconDialog(void);
	void __fastcall Close(void);
	void __fastcall Copy(void);
	void __fastcall CreateLinkToFile(const AnsiString FileName, bool Iconic);
	void __fastcall CreateObject(const AnsiString OleClassName, bool Iconic);
	void __fastcall CreateObjectFromFile(const AnsiString FileName, bool Iconic);
	void __fastcall CreateObjectFromInfo(const TCreateInfo &CreateInfo);
	void __fastcall DestroyObject(void);
	void __fastcall DoVerb(int Verb);
	unsigned __fastcall GetIconMetaPict(void);
	bool __fastcall InsertObjectDialog(void);
	void __fastcall LoadFromFile(const AnsiString FileName);
	void __fastcall LoadFromStream(Classes::TStream* Stream);
	bool __fastcall ObjectPropertiesDialog(void);
	void __fastcall Paste(void);
	bool __fastcall PasteSpecialDialog(void);
	void __fastcall Run(void);
	void __fastcall SaveAsDocument(const AnsiString FileName);
	void __fastcall SaveToFile(const AnsiString FileName);
	void __fastcall SaveToStream(Classes::TStream* Stream);
	void __fastcall UpdateObject(void);
	void __fastcall UpdateVerbs(void);
	__property bool CanPaste = {read=GetCanPaste, nodefault};
	__property bool Linked = {read=GetLinked, nodefault};
	__property bool Modified = {read=FModified, write=FModified, nodefault};
	__property bool NewInserted = {read=FNewInserted, nodefault};
	__property Classes::TStrings* ObjectVerbs = {read=GetObjectVerbs};
	__property AnsiString OleClassName = {read=GetOleClassName};
	__property Variant OleObject = {read=GetOleObject};
	__property _di_IOleObject OleObjectInterface = {read=FOleObject};
	__property int PrimaryVerb = {read=GetPrimaryVerb, nodefault};
	__property AnsiString SourceDoc = {read=GetSourceDoc};
	__property TObjectState State = {read=GetState, nodefault};
	__property _di_IStorage StorageInterface = {read=FStorage};
	
__published:
	__property bool AllowInPlace = {read=FAllowInPlace, write=FAllowInPlace, default=1};
	__property bool AllowActiveDoc = {read=FAllowActiveDoc, write=FAllowActiveDoc, default=1};
	__property TAutoActivate AutoActivate = {read=FAutoActivate, write=FAutoActivate, default=2};
	__property bool AutoVerbMenu = {read=FAutoVerbMenu, write=FAutoVerbMenu, default=1};
	__property Align ;
	__property Anchors ;
	__property Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property Caption ;
	__property Color ;
	__property Constraints ;
	__property bool CopyOnSave = {read=FCopyOnSave, write=FCopyOnSave, default=1};
	__property Ctl3D ;
	__property DragCursor ;
	__property DragMode ;
	__property Enabled ;
	__property bool Iconic = {read=GetIconic, write=SetIconic, stored=false, nodefault};
	__property bool OldStreamFormat = {read=FOldStreamFormat, write=FOldStreamFormat, default=0};
	__property ParentColor ;
	__property ParentCtl3D ;
	__property ParentShowHint ;
	__property PopupMenu ;
	__property ShowHint ;
	__property TSizeMode SizeMode = {read=FSizeMode, write=SetSizeMode, default=0};
	__property TabOrder ;
	__property TabStop ;
	__property Visible ;
	__property Classes::TNotifyEvent OnActivate = {read=FOnActivate, write=FOnActivate};
	__property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate};
	__property OnDragDrop ;
	__property OnDragOver ;
	__property OnEndDrag ;
	__property OnEnter ;
	__property OnExit ;
	__property OnMouseDown ;
	__property OnMouseMove ;
	__property OnMouseUp ;
	__property OnKeyDown ;
	__property OnKeyPress ;
	__property OnKeyUp ;
	__property TObjectMoveEvent OnObjectMove = {read=FOnObjectMove, write=FOnObjectMove};
	__property Classes::TNotifyEvent OnResize = {read=FOnResize, write=FOnResize};
	__property OnStartDrag ;
public:
	#pragma option push -w-inl
	/* TWinControl.CreateParented */ inline __fastcall TOleContainer(HWND ParentWindow) : Controls::TCustomControl(
		ParentWindow) { }
	#pragma option pop
	
private:
	void *__IOleClientSite;	/* IOleClientSite */
	void *__IOleInPlaceSite;	/* IOleInPlaceSite */
	void *__IAdviseSink;	/* IAdviseSink */
	void *__IOleDocumentSite;	/* IOleDocumentSite */
	void *__IOleUIObjInfo;	/* IOleUIObjInfo */
	
public:
	operator IOleUIObjInfo*(void) { return (IOleUIObjInfo*)&__IOleUIObjInfo; }
	operator IOleDocumentSite*(void) { return (IOleDocumentSite*)&__IOleDocumentSite; }
	operator IAdviseSink*(void) { return (IAdviseSink*)&__IAdviseSink; }
	operator IOleInPlaceSite*(void) { return (IOleInPlaceSite*)&__IOleInPlaceSite; }
	operator IOleClientSite*(void) { return (IOleClientSite*)&__IOleClientSite; }
	operator IUnknown*(void) { return (IUnknown*)&__IOleUIObjInfo; }
	
};


class DELPHICLASS TOleForm;
class PASCALIMPLEMENTATION TOleForm : public System::TInterfacedObject 
{
	typedef System::TInterfacedObject inherited;
	
private:
	Forms::TCustomForm* FForm;
	Classes::TList* FContainers;
	_di_IOleInPlaceActiveObject FActiveObject;
	int FSaveWidth;
	int FSaveHeight;
	Classes::TList* FHiddenControls;
	Controls::TControl* FSpacers[4];
	void __fastcall OnDestroy(void);
	void __fastcall OnResize(void);
	HRESULT __stdcall GetWindow(/* out */ HWND &wnd);
	HRESULT __stdcall ContextSensitiveHelp(BOOL fEnterMode);
	HRESULT __stdcall GetBorder(/* out */ Windows::TRect &BorderRect);
	HRESULT __stdcall RequestBorderSpace(const Windows::TRect &borderwidths);
	HRESULT __stdcall SetBorderSpace(Windows::PRect pborderwidths);
	HRESULT __stdcall SetActiveObject(const _di_IOleInPlaceActiveObject ActiveObject, wchar_t * pszObjName
		);
	HRESULT __stdcall InsertMenus(HMENU hmenuShared, tagOleMenuGroupWidths &menuWidths);
	HRESULT __stdcall SetMenu(HMENU hmenuShared, HMENU holemenu, HWND hwndActiveObject);
	HRESULT __stdcall RemoveMenus(HMENU hmenuShared);
	HRESULT __stdcall SetStatusText(wchar_t * pszStatusText);
	HRESULT __stdcall EnableModeless(BOOL fEnable);
	HRESULT __stdcall TranslateAccelerator(tagMSG &msg, Word wID);
	void __fastcall AddContainer(TOleContainer* Instance);
	void __fastcall RemoveContainer(TOleContainer* Instance);
	Forms::TCustomForm* __fastcall Form(void);
	void __fastcall ClearBorderSpace(void);
	bool __fastcall IsSpacer(Controls::TControl* Control);
	bool __fastcall IsToolControl(Controls::TControl* Control);
	
public:
	__fastcall TOleForm(Forms::TCustomForm* Form);
	__fastcall virtual ~TOleForm(void);
private:
	void *__IOleForm;	/* Forms::IOleForm */
	void *__IVCLFrameForm;	/* Olectnrs::IVCLFrameForm */
	
public:
	operator IVCLFrameForm*(void) { return (IVCLFrameForm*)&__IVCLFrameForm; }
	operator IOleInPlaceFrame*(void) { return (IOleInPlaceFrame*)&__IVCLFrameForm; }
	operator IOleInPlaceUIWindow*(void) { return (IOleInPlaceUIWindow*)&__IVCLFrameForm; }
	operator IOleWindow*(void) { return (IOleWindow*)&__IVCLFrameForm; }
	operator IOleForm*(void) { return (IOleForm*)&__IOleForm; }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Shortint ovShow = 0xffffffff;
static const Shortint ovOpen = 0xfffffffe;
static const Shortint ovHide = 0xfffffffd;
static const Shortint ovUIActivate = 0xfffffffc;
static const Shortint ovInPlaceActivate = 0xfffffffb;
static const Shortint ovDiscardUndoState = 0xfffffffa;
static const int ovPrimary = 0xffff0000;
extern PACKAGE void __fastcall DestroyMetaPict(unsigned MetaPict);

}	/* namespace Olectnrs */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Olectnrs;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OleCtnrs
