//
//----------------------------------------------------------------------------
// ObjectComponents
// (C) Copyright 1994, 1996 by Borland International, All Rights Reserved
//
//   Definition of TOcPart class
//----------------------------------------------------------------------------
#if !defined(OCF_OCCTRL_H)
#define OCF_OCCTRL_H

#if !defined(OCF_OCVIEW_H)
# include <ocf/ocview.h>
#endif

#if !defined(OCF_OCPART_H)
# include <ocf/ocpart.h>
#endif

#if !defined(OCF_AUTOMACR_H)
# include <ocf/automacr.h>
#endif

//
// Special automation macro for default event handling
//
#define DISPID_DEFAULT_EVENT       -999 

#define AUTOFUNCX(name, func, ret, defs) \
  AUTOFUNC_(name, Val=(ret)This->func( (long *)Args);, defs, \
            RETARG(ret) DEFARGSX,        \
            BLDARGSX, CTRARGSX, SETARGSX)

#define DEFARGSX           TAutoStack *Args;
#define BLDARGSX          ,&args
#define CTRARGSX          ,TAutoStack *args
#define SETARGSX          ,Args(args)

class _ICLASS TOcControlEvent;
class _ICLASS ITypeInfo;

//
// class TOcControl
// ~~~~~ ~~~~~~~~~~
// OC part class represents an embeded or linked part in a document
//
class _ICLASS TOcControl : public TOcPart, protected IBControlSite {
  public:
    TOcControl(TOcDocument& document, int id=0, TOcControlEvent* pEv=NULL);
    TOcControl(TOcDocument& document, const char far* name);

    virtual bool Init(TOcInitInfo far* initInfo, TRect pos);

    IBControl* GetBControlI() {return BCtrlI;}
    TOcView*   GetActiveControlView();
    ITypeInfo* GetEventTypeInfo();

    // Flag accessor functions
    //
    void    SetDefault(bool def)
              {if (def) Flags |= OcxDefault; else Flags &= ~OcxDefault;}
    void    SetCancel(bool cancel)
              {if (cancel) Flags |= OcxCancel; else Flags &= ~OcxCancel;}
    void    SetUserName(TString& name);

  protected:
   ~TOcControl();

    virtual    bool InitObj (TOcInitInfo far* initInfo);
    TUnknown*  CreateAutoObject(const void* obj, TAutoClass& clsInfo);

    // TUnknown virtual overrides
    //
    HRESULT      QueryObject(const IID far& iid, void far* far* iface);

    IBControl       *BCtrlI;
    TString         *pUserName;
    TServedObject   *pIExtended;
    TOcControlEvent *pEvents;

  public:
    // Object reference & lifetime managment
    // For internal OCF use only
    //
    ulong   _IFUNC AddRef() {return GetOuter()->AddRef();}
    ulong   _IFUNC Release() {return GetOuter()->Release();}
    HRESULT _IFUNC QueryInterface(const GUID far& iid, void far*far* iface)
                     {return GetOuter()->QueryInterface(iid, iface);}

  protected:
    // IBControlSite implementation for BOle to use
    //
    HRESULT _IFUNC Init(UINT, IBControl*, UINT);
    HRESULT _IFUNC OnPropertyChanged(DISPID dispid);
    HRESULT _IFUNC OnPropertyRequestEdit(DISPID dispid);
    HRESULT _IFUNC OnControlFocus(BOOL fGotFocus);
    HRESULT _IFUNC TransformCoords(TPointL far* lpptlHimetric,
                            TPointF far* lpptfContainer, DWORD flags);

    // TOcPart virtual routed to correct base (don't want other Init to hide)
    //
    HRESULT _IFUNC Init(IBDataProvider far* dp, IBPart far* p, LPCOLESTR s, BOOL b)
        {return TOcPart::Init(dp, p, s, b);}

    void    SetEventDispatch();

    // Extended property support
    //
    bool       IsCancel()  const {return ToBool(Flags & OcxCancel);}
    bool       IsDefault() const {return ToBool(Flags & OcxDefault);}
    TString&   GetUserName();
    IDispatch* GetParent();
    long       GetLeft()                 { return Pos.x; }
    long       GetTop()                  { return Pos.y; }
    long       GetWidth()                { return Size.cx; }
    long       GetHeight()               { return Size.cy; }
    void       SetLeft(long Value);
    void       SetWidth(long Value);
    void       SetTop(long Value);
    void       SetHeight(long Value);

  DECLARE_AUTOCLASS(TOcControl)
    // standard extended properties
    AUTOPROP(Visible,     IsVisible,    SetVisible,     bool, )
    AUTOPROP(Cancel,      IsCancel,     SetCancel,      bool, )
    AUTOPROP(Default,     IsDefault,    SetDefault,     bool, )
    AUTOPROP(Name,        GetUserName,  SetUserName,    TString, )
    AUTOPROPRO(Parent,    GetParent,    IDispatch *, )
    AUTOPROP(Left,        GetLeft,      SetLeft,        long, )
    AUTOPROP(Top,         GetTop,       SetTop,         long, )
    AUTOPROP(Width,       GetWidth,     SetWidth,       long, )
    AUTOPROP(Height,      GetHeight,    SetHeight,      long, )

  friend TOcControlEvent;
};

//
// class TOcControlEvent
// ~~~~~ ~~~~~~~~~~~~~~~
// OC Control Event class for standard control events
//
class _ICLASS TOcControlEvent : public TUnknown {
  protected:
    TOcControl    *pCtrl;
    TServedObject *pIEvents;

  public:
    TOcControlEvent();

    TOcControl* GetControl() {return pCtrl;}

  protected:
   ~TOcControlEvent();

    virtual void InitEventDispatch();
    TUnknown*    CreateAutoObject(const void* obj, TAutoClass& clsInfo);

    // Standard events support
    //
    long       Click();
    long       DblClick();
    long       MouseDown(short Button, short Shift, long X, long Y);
    long       MouseMove(short Button, short Shift, long X, long Y);
    long       MouseUp  (short Button, short Shift, long X, long Y);
    long       KeyDown  (short far* KeyCode, short Shift);
    long       KeyUp    (short far* KeyCode, short Shift);
    long       ErrorEvent(short number, TAutoString Description,
                  SCODE SCode, TAutoString Source, TAutoString HelpFile,
                  long helpContext, bool far* CancelDisplay);

    long       ForwardClickEvent(long Msg);
    long       ForwardKeyEvent(long Msg, short *KeyCode, short Shift);
    long       ForwardMouseEvent(long Msg, short Button, short Shift,
                  long X, long Y);
    HRESULT    CustomEvent(long *args);

  DECLARE_AUTOCLASS(TOcControlEvent)
    // standard event handlers
    AUTOFUNC0(Click,     Click,     long,)
    AUTOFUNC0(DblClick,  DblClick,  long,)
    AUTOFUNC4(MouseDown, MouseDown, long,  short,  short,  long,  long, )
    AUTOFUNC4(MouseUp,   MouseUp,   long,  short,  short,  long,  long, )
    AUTOFUNC4(MouseMove, MouseMove, long,  short,  short,  long,  long, )
    AUTOFUNC7(ErrorEvent,ErrorEvent,long,
                  short /* number */,
                  TAutoString /* Description */, long /*SCode */,
                  TAutoString /* Source */, TAutoString /* HelpFile */,
                  long /* helpContext */, bool far* /* CancelDisplay */, )
    AUTOFUNC2(KeyDown,  KeyDown,  long,  short far*,  short, )
    AUTOFUNC2(KeyUp,    KeyUp,    long,  short far*,  short, )
    AUTOFUNCX(CustomEvent, CustomEvent, long, )

  friend TOcControl;
};


//
// class TOcxView
// ~~~~~ ~~~~~~~~
// The TOcxView partner is a container (viewer) of a given (server/client)
// document.
//
class _ICLASS TOcxView : public TOcView {
  protected:
    TServedObject *pIAmbients;
    TString       *pBlankString;

  public:
    TOcxView(TOcDocument& doc, TRegList* regList=0, IUnknown* outer=0);
   ~TOcxView();

    HRESULT  QueryObject(const IID far& iid, void far* far* iface);

    // Ambient property support
    //
    void  SetBackColor(long Color);
    void  SetForeColor(long Color);
    void  SetLocaleID(long LocaleId);
    void  SetMessageReflect(bool MsgRef);
    void  SetTextAlign(short Align);
    void  SetUserMode(bool Mode);
    void  SetUIDead(bool Dead);
    void  SetShowGrabHandles(bool Handles);
    void  SetSupportsMnemonics(bool Mnem);
    void  SetShowHatching(bool Hatch);
    void  SetDisplayAsDefault(bool Disp);
    void  SetDisplayName(TString& Name);
    void  SetScaleUnits(TString& ScaleUnits);
    void  SetFont(IDispatch *pFontDisp);

  protected:
    long  GetBackColor();
    long  GetForeColor();
    long  GetLocaleID();
    bool  GetMessageReflect();
    short GetTextAlign();
    bool  GetUserMode();
    bool  GetUIDead();
    bool  GetShowGrabHandles();
    bool  GetSupportsMnemonics();
    bool  GetShowHatching();
    bool  GetDisplayAsDefault();
    TString& GetDisplayName();
    TString& GetScaleUnits();
    IDispatch *GetFont();  // returns IFontDispatch

    void  SetAmbBackColor(long Color);
    void  SetAmbForeColor(long Color);
    void  SetAmbLocaleID(long LocaleId);
    void  SetAmbMessageReflect(bool MsgRef);
    void  SetAmbTextAlign(short Align);
    void  SetAmbUserMode(bool Mode);
    void  SetAmbUIDead(bool Dead);
    void  SetAmbShowGrabHandles(bool Handles);
    void  SetAmbSupportsMnemonics(bool Mnem);
    void  SetAmbShowHatching(bool Hatch);
    void  SetAmbDisplayAsDefault(bool Disp);
    void  SetAmbDisplayName(TString& Name);
    void  SetAmbScaleUnits(TString& ScaleUnits);
    void  SetAmbFont(IDispatch *pFontDisp);

    void  AmbientChanged(DISPID dispid);
    long  GetAmbientValue(long AmbientMsg, long Default);

  // Declare ambient properties
  DECLARE_AUTOCLASS(TOcxView)
    AUTOPROP(BackColor,        GetBackColor,      SetAmbBackColor,      long, )
    AUTOPROP(ForeColor,        GetForeColor,      SetAmbForeColor,      long, )
    AUTOPROP(LocaleID,         GetLocaleID,       SetAmbLocaleID,       long, )
    AUTOPROP(MessageReflect,   GetMessageReflect, SetAmbMessageReflect, bool, )
    AUTOPROP(TextAlign,        GetTextAlign,      SetAmbTextAlign,      short, )
    AUTOPROP(UserMode,         GetUserMode,       SetAmbUserMode,       bool, )
    AUTOPROP(UIDead,           GetUIDead,         SetAmbUIDead,         bool, )
    AUTOPROP(ShowGrabHandles,  GetShowGrabHandles,SetAmbShowGrabHandles,bool, )
    AUTOPROP(ShowHatching,     GetShowHatching,   SetAmbShowHatching,   bool, )
    AUTOPROP(DisplayName,      GetDisplayName,    SetAmbDisplayName,    TString, )
    AUTOPROP(ScaleUnits,       GetScaleUnits,     SetAmbScaleUnits,     TString, )
    AUTOPROP(Font,             GetFont,           SetAmbFont,           IDispatch*, )
    AUTOPROP(DisplayAsDefault, GetDisplayAsDefault, SetDisplayAsDefault,     bool, )
    AUTOPROP(SupportsMnemonics,GetSupportsMnemonics,SetAmbSupportsMnemonics, bool, )
};


//
// struct TCtrlEvent
//
// Base struct for all control event messages
//
struct TCtrlEvent {
  TOcControl* Ctrl;       // class descriptor, contains typeinfo
};

struct TCtrlMouseEvent : public TCtrlEvent {
  short Button;
  short Shift;
  long  X;
  long  Y;
};

struct TCtrlKeyEvent : public TCtrlEvent {
  short KeyCode;
  short Shift;
};

struct TCtrlFocusEvent : public TCtrlEvent {
  bool GotFocus;
};

struct TCtrlPropertyEvent : public TCtrlEvent {
  DISPID  DispId;
  bool    accept; // used for RequestEdit - accept or reject, default = TRUE
};

struct TCtrlErrorEvent : public TCtrlEvent {
  short       Number;
  TAutoString Description;
  SCODE       SCode;
  TAutoString Source;
  TAutoString HelpFile;
  long        HelpContext;
  bool        CancelDisplay;
};

struct TCtrlCustomEvent : public TCtrlEvent {
  TAutoStack *Args;
};

struct TCtrlTransformCoords : public TCtrlEvent {
  TPointL far *lpptHimetric;
  TPointF far *lpptContainer;
  DWORD   flags;
};


//
//  Registration API's
//
HRESULT OcRegisterControl (char far* LibraryName);
HRESULT OcUnregisterControl (CLSID ClassId);

#endif

