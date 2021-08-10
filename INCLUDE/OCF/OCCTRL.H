//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1997 by Borland International, All Rights Reserved
//
// $Revision:   2.27  $
//
//  Definition of TOcControl class - Proxy object representing a control in
//                                   an OCF container.
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

// Check build target!
//
#if !defined(BI_PLAT_WIN32)
# error OCCTRL.H can only be used when building WIN32 targets
#endif

class _ICLASS ITypeInfo;

#if defined(BI_NAMESPACE)
namespace OCF {
#endif

class _ICLASS TOcControlEvent;
class TAutoStack;

//
//
//
class _OCFCLASS TEventEntry {
  public:
    TEventEntry();
   ~TEventEntry();

    void      Init(int index, ITypeInfo* typeInfo);
    void      Cleanup();

  protected:
    DISPID    IDOfEvent;
    uint      ParamCount;
    BSTR*     NameAndParams;
};

//
//
//
class _OCFCLASS TEventList {
  public:
    TEventList(ITypeInfo* typeInfo);
   ~TEventList();
    TEventEntry&  operator[](int index);

    uint          GetCount() const    { return Count;    }
    const GUID&   GetEventIID() const { return EventIID; }
  protected:
    TEventEntry*  EventList;
    uint          Count;
    GUID          EventIID;
};


//
// class TOcControl
// ~~~~~ ~~~~~~~~~~
//
// Class representing an embedded control within a document
//
class _ICLASS TOcControl : public TOcPart, protected IBControlSite {
  public:
    TOcControl(TOcDocument& document, int id=0, TOcControlEvent* pEv=NULL);
    TOcControl(TOcDocument& document, const char far* name);

    // Overriden virtual of TOcPart
    //
    bool        Init(TOcInitInfo far* initInfo, TRect pos);

    // Define AddRef/Release/QI to avoid ambiguity
    //
    TUNKNOWN_STANDARD_IUNKNOWN_METHODS;

    // Retrieve interface/object
    //
    IBControl*  GetBControlI() {return BCtrlI;}
    TOcView*    GetActiveControlView();

    ITypeInfo*  GetEventTypeInfo();
    IDispatch*  GetCtlDispatch();

    // Flag accessor functions
    //
    void        SetDefault(bool def)
                {if (def) Flags |= OcxDefault; else Flags &= ~OcxDefault;}
    void        SetCancel(bool cancel)
                {if (cancel) Flags |= OcxCancel; else Flags &= ~OcxCancel;}
    void        SetUserName(TString& name);
    uint        GetId() const { return CtlId; }
    void        SetId(uint id){ CtlId = id;   }

    // Support for caching/looking of control's events
    //
    bool        FillEventList();
    TEventList* GetEventList() const;

    // Access to Extended property support
    //
    bool       IsCancel()  const        {return (Flags & OcxCancel) != 0;}
    bool       IsDefault() const        {return (Flags & OcxDefault)!= 0;}
    long       GetLeft()                { return Pos.x; }
    long       GetTop()                 { return Pos.y; }
    long       GetWidth()               { return Size.cx; }
    long       GetHeight()              { return Size.cy; }
    void       SetLeft(long Value);
    void       SetWidth(long Value);
    void       SetTop(long Value);
    void       SetHeight(long Value);
    TString&   GetUserName();
    IDispatch* GetParent();

    // Standard methods
    //
    HRESULT     Refresh()               { return GetBControlI()->Refresh(); };
    HRESULT     DoClick()               { return GetBControlI()->DoClick(); };
    HRESULT     AboutBox()              { return GetBControlI()->AboutBox(); };

  protected:
   ~TOcControl();

    // Overriden virtual of TOcPart
    //
    bool InitObj (TOcInitInfo far* initInfo);

    // Helper to create served object (IDispatch*) of a class
    //
    TUnknown*   CreateAutoObject(const void* obj, TAutoClass& clsInfo);

    // TUnknown virtual overrides
    //
    HRESULT     QueryObject(const IID far& iid, void far* far* iface);

    IBControl         *BCtrlI;
    TString           *pUserName;
    TServedObject     *pIExtended;
    TOcControlEvent   *pEvents;
    uint               CtlId;
    TEventList*        EventList;

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

    // Initialize the event IDispatch [Assumes pEvents is initialized]
    //
    void       SetEventDispatch();

  DECLARE_AUTOCLASS(TOcControl)
    //
    // Standard extended properties
    //
    AUTOPROP(Visible,     IsVisible,    SetVisible,     bool, )
    AUTOPROP(Cancel,      IsCancel,     SetCancel,      bool, )
    AUTOPROP(Default,     IsDefault,    SetDefault,     bool, )
    AUTOPROP(Name,        GetUserName,  SetUserName,    TString, )
    AUTOPROPRO(Parent,    GetParent,    IDispatch*,           )
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
  public:
    TOcControlEvent();

    // Accessor to associated control object
    //
    TOcControl*   GetControl() {return pCtrl;}

  protected:
   ~TOcControlEvent();

    virtual void  InitEventDispatch();
    TUnknown*     CreateAutoObject(const void* obj, TAutoClass& clsInfo);

    // Standard events support
    //
    long          Click();
    long          DblClick();
    long          MouseDown(short Button, short Shift, long X, long Y);
    long          MouseMove(short Button, short Shift, long X, long Y);
    long          MouseUp  (short Button, short Shift, long X, long Y);
    long          KeyDown  (short* KeyCode, short Shift);
    long          KeyUp    (short* KeyCode, short Shift);
    long          ErrorEvent(short number, TAutoString Description,
                             SCODE SCode, TAutoString Source,
                             TAutoString HelpFile,
                             long helpContext, bool far* CancelDisplay);

    HRESULT       ForwardClickEvent(uint msg, DISPID id);
    HRESULT       ForwardKeyEvent  (uint msg, DISPID id, short *KeyCode, short Shift);
    HRESULT       ForwardMouseEvent(uint msg, DISPID id, short Button, short Shift,
                                    long X, long Y);
    HRESULT       CustomEvent(long *args);

  protected:
    TOcControl    *pCtrl;
    TServedObject *pIEvents;

  DECLARE_AUTOCLASS(TOcControlEvent)

    // Automation symbol table declaring methods handling standard events
    //
    AUTOFUNC0(Click,      Click,      long,)
    AUTOFUNC0(DblClick,   DblClick,   long,)
    AUTOFUNC4(MouseDown,  MouseDown,  long,  short,  short,  long,  long, )
    AUTOFUNC4(MouseUp,    MouseUp,    long,  short,  short,  long,  long, )
    AUTOFUNC4(MouseMove,  MouseMove,  long,  short,  short,  long,  long, )
    AUTOFUNC2(KeyDown,    KeyDown,    long,  short*, short, )
    AUTOFUNC2(KeyUp,      KeyUp,      long,  short*, short, )
    AUTOFUNC7(ErrorEvent, ErrorEvent, long,
                                      short         /* number       */,
                                      TAutoString   /* Description  */,
                                      long          /* SCode        */,
                                      TAutoString   /* Source       */,
                                      TAutoString   /* HelpFile     */,
                                      long          /* helpContext  */,
                                      bool*         /* CancelDisplay */, )
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
  public:
    TOcxView(TOcDocument& doc, TRegList* regList=0, IUnknown* outer=0);
   ~TOcxView();

    HRESULT     QueryObject(const IID far& iid, void far* far* iface);

    // Ambient property support
    //
    void        SetBackColor(long Color);
    void        SetForeColor(long Color);
    void        SetLocaleID(long LocaleId);
    void        SetMessageReflect(bool MsgRef);
    void        SetTextAlign(short Align);
    void        SetUserMode(bool Mode);
    void        SetUIDead(bool Dead);
    void        SetShowGrabHandles(bool Handles);
    void        SetSupportsMnemonics(bool Mnem);
    void        SetShowHatching(bool Hatch);
    void        SetDisplayAsDefault(bool Disp);
    void        SetDisplayName(TString& Name);
    void        SetScaleUnits(TString& ScaleUnits);
    void        SetFont(IDispatch *pFontDisp);

  protected:
    long        GetBackColor();
    long        GetForeColor();
    long        GetLocaleID();
    bool        GetMessageReflect();
    short       GetTextAlign();
    bool        GetUserMode();
    bool        GetUIDead();
    bool        GetShowGrabHandles();
    bool        GetSupportsMnemonics();
    bool        GetShowHatching();
    bool        GetDisplayAsDefault();
    TString&    GetDisplayName();
    TString&    GetScaleUnits();
    IDispatch*  GetFont();  // returns IFontDispatch

    void        SetAmbBackColor(long Color);
    void        SetAmbForeColor(long Color);
    void        SetAmbLocaleID(long LocaleId);
    void        SetAmbMessageReflect(bool MsgRef);
    void        SetAmbTextAlign(short Align);
    void        SetAmbUserMode(bool Mode);
    void        SetAmbUIDead(bool Dead);
    void        SetAmbShowGrabHandles(bool Handles);
    void        SetAmbSupportsMnemonics(bool Mnem);
    void        SetAmbShowHatching(bool Hatch);
    void        SetAmbDisplayAsDefault(bool Disp);
    void        SetAmbDisplayName(TString& Name);
    void        SetAmbScaleUnits(TString& ScaleUnits);
    void        SetAmbFont(IDispatch *pFontDisp);

    void        AmbientChanged(DISPID dispid);
    long        GetAmbientValue(long AmbientMsg, long Default);

  protected:
    TServedObject *pIAmbients;
    TString       *pBlankString;

  // Ambient properties
  //
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
  TCtrlEvent(TOcControl* ctl, DISPID id) : Ctrl(ctl), DispId(id) {}

  TOcControl* Ctrl;       // Proxy object representing control
  DISPID      DispId;
};

struct TCtrlMouseEvent : public TCtrlEvent {
  TCtrlMouseEvent(TOcControl* ctl, DISPID id, short butt, short shft, long x, long y) :
                  TCtrlEvent(ctl, id), Button(butt), Shift(shft), X(x), Y(y)
                  {}

  short Button;
  short Shift;
  long  X;
  long  Y;
};

struct TCtrlKeyEvent : public TCtrlEvent {
  TCtrlKeyEvent(TOcControl* ctl, DISPID id, short kcode, short shft) : TCtrlEvent(ctl, id),
                KeyCode(kcode), Shift(shft)
                {}

  short KeyCode;
  short Shift;
};

struct TCtrlFocusEvent : public TCtrlEvent {
  TCtrlFocusEvent(TOcControl* ctl, bool gotFocus)
                : TCtrlEvent(ctl, 0/*IId of Focus Event??*/),
                  GotFocus(gotFocus){}

  bool GotFocus;
};

struct TCtrlPropertyEvent : public TCtrlEvent {
  TCtrlPropertyEvent(TOcControl* ctl, DISPID dispid, bool acpt = true) :
          TCtrlEvent(ctl, dispid), accept(acpt)
          {}

  bool    accept;
};

struct TCtrlErrorEvent : public TCtrlEvent {

  TCtrlErrorEvent(TOcControl* ctl, short num, TAutoString desc,
                  SCODE scode, TAutoString src, TAutoString hlpfile,
                  long hlpCtx, bool xceldisplay) :
                  TCtrlEvent(ctl, DISPID_ERROREVENT),
                  Number(num), Description(desc), SCode(scode), Source(src),
                  HelpFile(hlpfile), HelpContext(hlpCtx),
                  CancelDisplay(xceldisplay)
                  {}

  short       Number;
  TAutoString Description;
  SCODE       SCode;
  TAutoString Source;
  TAutoString HelpFile;
  long        HelpContext;
  bool        CancelDisplay;
};

struct TCtrlCustomEvent : public TCtrlEvent {
  TCtrlCustomEvent(TOcControl* ctl, DISPID id, TAutoStack* args) : TCtrlEvent(ctl, id),
                    Args(args)
                    {}
  TAutoStack *Args;
};

struct TCtrlTransformCoords : public TCtrlEvent {

  TCtrlTransformCoords(TOcControl* ctl, TPointL* him, TPointF* pcont,
                       DWORD flgs) :
                       TCtrlEvent(ctl, 0/*IID for this event??*/),
                       lpptHimetric(him), lpptContainer(pcont), flags(flgs)
                       {}

  TPointL    *lpptHimetric;
  TPointF    *lpptContainer;
  DWORD       flags;
};


//
// Global functions to allow easy registration/unregistration of OCXes
//
HRESULT     OcRegisterControl(char* ocxPath);
HRESULT     OcUnregisterControl(CLSID ClassId);

#if defined(BI_NAMESPACE)
} // namespace OCF
#endif

#endif

