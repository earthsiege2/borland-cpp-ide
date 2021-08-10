//----------------------------------------------------------------------------
// ObjectComponents
// (c) Copyright 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.17  $
//
//   Implementation of TOcControl Class
//----------------------------------------------------------------------------
#include <ocf/pch.h>
#include <olectl.h>
#if !defined(OCF_OCSTORAG_H)
# include <ocf/ocstorag.h>
#endif
#if !defined(OCF_OCDOC_H)
# include <ocf/ocdoc.h>
#endif
#if !defined(OCF_OCAPP_H)
# include <ocf/ocapp.h>
#endif
#if !defined(OCF_OCVIEW_H)
# include <ocf/ocview.h>
#endif
#if !defined(OCF_OCCTRL_H)
# include <ocf/occtrl.h>
#endif

#include <stdio.h>  // sprintf


//
//
//
ObjectPtr GetControlView(ObjectPtr ctl);

//
// Control container ambient property support
//
DEFINE_AUTOCLASS(TOcxView)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_BACKCOLOR,        BackColor,        TAutoLong,   "!BackColor",        "@BackColor_", 0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_FORECOLOR,        ForeColor,        TAutoLong,   "!ForeColor",        "@ForeColor_", 0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_LOCALEID,         LocaleID,         TAutoLong,   "!LocaleID",         "@LocaleID_",  0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_TEXTALIGN,        TextAlign,        TAutoShort,  "!TextAlign",        "@TextAlign_", 0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_MESSAGEREFLECT,   MessageReflect,   TAutoBool,   "!MessageReflect",   "@MsgReflect_",  0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_USERMODE,         UserMode,         TAutoBool,   "!UserMode",         "@UserMode_",  0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_UIDEAD,           UIDead,           TAutoBool,   "!UIDead",           "@UIDead_",    0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_SHOWGRABHANDLES,  ShowGrabHandles,  TAutoBool,   "!ShowGrabHandles",  "@GrabHdl_",   0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_SHOWHATCHING,     ShowHatching,     TAutoBool,   "!ShowHatching",     "@ShowHat_", 0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_DISPLAYASDEFAULT, DisplayAsDefault, TAutoBool,   "!DisplayAsDefault", "@DispDef_",  0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_SUPPORTSMNEMONICS,SupportsMnemonics,TAutoBool,   "!SupportsMnemonics","@Mnemonics_", 0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_DISPLAYNAME,      DisplayName,      TAutoString, "!DisplayName",      "@DispName_",  0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_SCALEUNITS,       ScaleUnits,       TAutoString, "!ScaleUnits",       "@ScaleUnits_",0)
  EXPOSE_PROPRW_ID(DISPID_AMBIENT_FONT,             Font,             TAutoDispatch,"!Font",            "@Font_",      0)
END_AUTOCLASS(TOcxView, tfNormal, "TOcxView",   "@TOcxView_", 0)

//
// Control standard extended properties and standard events
//
DEFINE_AUTOCLASS(TOcControl)
  // standard extended properties
  EXPOSE_PROPRO_ID(0x80010008L,   Parent,  TAutoDispatch,"!Parent",     "!Parent",          0)
  EXPOSE_PROPRW_ID(0x80010007L,   Visible, TAutoBool,    "!Visible",    "!Visible",         0)
  EXPOSE_PROPRW_ID(0x80010037L,   Cancel,  TAutoBool,    "!Cancel",     "@Cancel_",         0)
  EXPOSE_PROPRW_ID(0x80010038L,   Default, TAutoBool,    "!Default",    "@Default_",        0)
  EXPOSE_PROPRW_ID(0x80010000L,   Name,    TAutoString,  "!Name",       "@ObjName_",        0)
  EXPOSE_PROPRW_ID(0x80010100L,   Left,     TAutoLong,   "!Left",       "!Left",            0)
  EXPOSE_PROPRW_ID(0x80010101L,   Top,      TAutoLong,   "!Top",        "!Top",             0)
  EXPOSE_PROPRW_ID(0x80010102L,   Width,    TAutoLong,   "!Width",      "!Width",           0)
  EXPOSE_PROPRW_ID(0x80010103L,   Height,   TAutoLong,   "!Height",     "!Height",          0)

  EXPOSE_DELEGATE(TOcxView, "TOcxView",  GetControlView)  // expose ambients

END_AUTOCLASS(TOcControl, tfNormal, "TOcControl",   "@TOcControl_", 0)


//
// Control standard extended properties and standard events
//
DEFINE_AUTOCLASS(TOcControlEvent)
  // standard events
  EXPOSE_METHOD_ID(DISPID_CLICK,     Click,    TAutoLong,  "!Click",     "@Click_",     0)
  EXPOSE_METHOD_ID(DISPID_DBLCLICK,  DblClick, TAutoLong,  "!DblClick",  "@DblClick_",  0)
  EXPOSE_METHOD_ID(DISPID_MOUSEDOWN, MouseDown,TAutoLong,  "!MouseDown", "@MouseDown_", 0)
    REQUIRED_ARG(TAutoShort, "!Button")
    REQUIRED_ARG(TAutoShort, "!Shift")
    REQUIRED_ARG(TAutoLong,  "!X")
    REQUIRED_ARG(TAutoLong,  "!Y")
  EXPOSE_METHOD_ID(DISPID_MOUSEUP,   MouseUp,  TAutoLong,  "!MouseUp",  "@MouseUp_",  0)
    REQUIRED_ARG(TAutoShort, "!Button")
    REQUIRED_ARG(TAutoShort, "!Shift")
    REQUIRED_ARG(TAutoLong,  "!X")
    REQUIRED_ARG(TAutoLong,  "!Y")
  EXPOSE_METHOD_ID(DISPID_MOUSEMOVE, MouseMove,TAutoLong,  "!MouseMove", "@MouseMove_", 0)
    REQUIRED_ARG(TAutoShort, "!Button")
    REQUIRED_ARG(TAutoShort, "!Shift")
    REQUIRED_ARG(TAutoLong,  "!X")
    REQUIRED_ARG(TAutoLong,  "!Y")
  EXPOSE_METHOD_ID(DISPID_KEYDOWN, KeyDown, TAutoLong,  "!KeyDown", "@KeyDown_", 0)
    REQUIRED_ARG(TAutoShortRef, "!KeyCode")
    REQUIRED_ARG(TAutoShort, "!Shift")
  EXPOSE_METHOD_ID(DISPID_KEYUP, KeyUp, TAutoLong,  "!KeyUp", "@KeyUp_", 0)
    REQUIRED_ARG(TAutoShortRef, "!KeyCode")
    REQUIRED_ARG(TAutoShort, "!Shift")
  EXPOSE_METHOD_ID(DISPID_ERROREVENT, ErrorEvent, TAutoLong, "!ErrorEvent","&ErrorEvent_",0)
    REQUIRED_ARG(TAutoShort, "!Number")
    REQUIRED_ARG(TAutoString,"!Description")
    REQUIRED_ARG(TAutoLong,  "!SCode")
    REQUIRED_ARG(TAutoString,"!Source")
    REQUIRED_ARG(TAutoString,"!HelpFile")
    REQUIRED_ARG(TAutoLong,  "!HelpContext")
    REQUIRED_ARG(TAutoBoolRef,"!CancelDisplay")
  EXPOSE_METHOD_ID(DISPID_DEFAULT_EVENT, CustomEvent,  TAutoLong, "!CustomEvent", "@CustomEvent_",0)
    REQUIRED_ARG(TAutoLongRef, "!Number")

END_AUTOCLASS(TOcControlEvent, tfNormal, "TOcControlEvent",   "@TOcCtrlEvent_", 0)

ObjectPtr GetControlView(ObjectPtr ctl)
{
  return (ObjectPtr)((TOcControl*)ctl)->GetActiveControlView();
}

//
// Construct a new part with a given temp id
//
TOcControl::TOcControl(TOcDocument& document, int id, TOcControlEvent* pEv)
:
  TOcPart(document, id),
  pUserName(new TString), BCtrlI(0), pIExtended(0), pEvents(pEv)
{
  *pUserName = GetName();
}

//
// Construct a part from a named stream in an oc doc's storage
//
TOcControl::TOcControl(TOcDocument& document, const char far* name)
:
  TOcPart(document, name),
  pUserName(0), BCtrlI(0), pIExtended(0)
{
}

TOcControl::~TOcControl()
{
  if (pIExtended)
    pIExtended->Release();
  if (pUserName)
    delete pUserName;
}


bool
TOcControl::Init (TOcInitInfo far* initInfo, TRect objPos)
{
  return TOcPart::Init (initInfo, objPos);
}


//
// Perform common ctor initialization
//
bool
TOcControl::InitObj (TOcInitInfo far* initInfo)
{
  if (TOcPart::InitObj ((TOcInitInfo far *)NULL) == false)
    return false;

  if (initInfo) {
    if (!pIExtended)
      (TUnknown far*)pIExtended = CreateAutoObject(this, ClassInfo);

    if (!pEvents)
      pEvents = new TOcControlEvent();

    // There must be an IStorage associated with each part, make sure the
    // ctor got it OK
    //
    initInfo->Storage = Storage->GetIStorage();

    // Create part helper
    //
    TXObjComp::Check(
      OcDocument.OcApp.BOleComponentCreate(&BPart, GetOuter(), cidBOleControl),
      TXObjComp::xInternalPartError);

    // Get the interfaces we need & then release the object itself
    //
    if (HRSucceeded(BPart->QueryInterface(IID_IBPart, &(LPVOID)BPartI)))
      BPartI->Release();
    if (HRSucceeded(BPart->QueryInterface(IID_IBLinkable, &(LPVOID)BLPartI)))
      BLPartI->Release();
    if (HRSucceeded(BPart->QueryInterface(IID_IBControl, &(LPVOID)BCtrlI)))
      BCtrlI->Release();

    // Initialize the Extended/Ambient IDispatch
    //
    HRESULT hr;
    IBSite* BSiteI;
    hr = QueryInterface(IID_IBSite, &(LPVOID)BSiteI);
    if (HRSucceeded(hr))
    {
      IDispatch* pID = 0;
      TOcView*   activeView = OcDocument.GetActiveView();
      CHECK(activeView);
      if ((pIExtended) &&(SUCCEEDED(pIExtended->QueryObject(IID_IDispatch,
                                     &(VOID FAR*)pID)))) {
        BCtrlI->SetAmbientDispatch(pID);
        pID->Release();
      }

      // Init the part
      //
      if (!BPartI || !HRSucceeded(hr = BPartI->Init(BSiteI, initInfo))) {
        BSiteI->Release();
        BPart->Release();
        BPart = 0;
        TXObjComp::Throw(TXObjComp::xPartInitError, hr);
      }
      BSiteI->Release();

      Rename();
      if (initInfo->How == ihLink)  // Remember that we are a link
        Flags |= Link;

      // Initialize the Events IDispatch
      //
      SetEventDispatch();

      // New parts become active when they are init'd above. Make sure that
      // our view knows that we are active too.
      //
      if (initInfo->Where == iwNew) {
        Flags |= Active;
        activeView->ActivatePart(this);
      }
    }
    else
      TXObjComp::Throw(TXObjComp::xPartInitError, hr);

  }
  return true;
}


//
//
//
ITypeInfo *
TOcControl::GetEventTypeInfo()
{
  ITypeInfo* pRet = NULL;
  if (BCtrlI)
    BCtrlI->GetEventTypeInfo (&pRet);
  return pRet;
}

//
//
//
void
TOcControl::SetEventDispatch()
{
  if (!pEvents)
    return;
  pEvents->pCtrl = this;
  pEvents->InitEventDispatch();

  IDispatch*     pID = 0;
  TServedObject* pS = pEvents->pIEvents;
  if (SUCCEEDED(pS->QueryObject(IID_IDispatch, &(VOID FAR*)pID))) {
    IID iidEv;

    BCtrlI->GetEventIID(&iidEv);
    pS->iidEvent = iidEv;

    ITypeInfo* pITypeInfo;
    LPTYPEATTR pTA;
    UINT       i;
    UINT       cEvents;

    BCtrlI->GetEventTypeInfo(&pITypeInfo);
    if (pITypeInfo)  {
      pITypeInfo->GetTypeAttr(&pTA);
      if (pTA) {
        cEvents = pTA->cFuncs;
        pITypeInfo->ReleaseTypeAttr(pTA);
        for (i = 0; i < cEvents; i++) {
          LPFUNCDESC    pFD;

          if (SUCCEEDED(pITypeInfo->GetFuncDesc(i, &pFD))) {
            ObjectPtr object = this;  // copy in case of ptr adjustment

            // see if we have a method associated with this DISPID
            // if not, find one with the same name and see if the
            // number of parameters matches
            //
            TAutoSymbol* sym = pS->Class->FindId(pFD->memid, object);
            if (!sym) {
              UINT       cNames;
              BSTR       bstrName;       //Event name(function only)
              DISPID     dispid;       //Event name(function only)
              if (SUCCEEDED(pITypeInfo->GetNames(pFD->memid, &bstrName,
                  1, &cNames))) {
                sym = pS->Class->Lookup(OleStr(bstrName),
                             LANGIDFROMLCID(LOCALE_USER_DEFAULT),
                             asAnyCommand, dispid);
                if (sym &&
                    (sym->DispId == -1 || sym->DispId == 0) &&
                    sym->TestFlag(DISPATCH_METHOD) && // check type
                    pS->Class->GetArgCount(*sym) == pFD->cParams) {
                  sym->DispId = pFD->memid;
                }

                SysFreeString(bstrName);
              }
            }
            pITypeInfo->ReleaseFuncDesc(pFD);
          }
        }
      }
      pITypeInfo->Release();
    }
    BCtrlI->SetEventDispatch(pID);
    pID->Release();
  }
}

//
//
//
TOcView*
TOcControl::GetActiveControlView()
{
  return (TOcView*)OcDocument.GetActiveView();
}

//
//
//
TUnknown*
TOcControl::CreateAutoObject(const void* obj, TAutoClass& clsInfo)
{
  TAppDescriptor* appDesc;
  TUnknown* result = 0;
  appDesc = &(OcDocument.OcApp.GetRegistrar().GetAppDescriptor());
  if (appDesc) {
    result = appDesc->CreateAutoObject(
         obj, clsInfo.GetTypeInfo(),
         obj, clsInfo.GetTypeInfo(),
         0);
    if (result)
      ((TServedObject*)result)->AddRef();
  }
  return result;
}

//
// Callback from TUnknown's implementation of QueryInterface
//
HRESULT
TOcControl::QueryObject(const IID far& iid, void far* far* iface)
{
  PRECONDITION(iface);
  HRESULT hr;

  // interfaces
  //
  HRSucceeded(hr = IBControlSite_QueryInterface(this, iid, iface))

  // helpers
  //
  || HRSucceeded(hr = TOcPart::QueryObject(iid, iface))
  || (pIExtended &&(HRSucceeded(hr = pIExtended->QueryObject(iid, iface))))
  ;
  return hr;
}


// Extended property support
//
void
TOcControl::SetUserName(TString& name)
{
  *pUserName = name;
}

//
//
//
TString&
TOcControl::GetUserName()
{
  return *pUserName;
}

//
//
//
IDispatch*
TOcControl::GetParent()
{
  IDispatch* pID = 0;
  TOcView* view = OcDocument.GetActiveView();
  if (view) {
    if (HRSucceeded(view->QueryInterface(IID_IDispatch, &(LPVOID)pID)))
      pID->Release();
  }
  return pID;
}

//
//
//
void
TOcControl::SetLeft(long value)
{
  TPoint nuPos(int(value), Pos.y);
  SetPos(nuPos);
  UpdateRect();
}

//
//
//
void
TOcControl::SetWidth(long value)
{
  TSize nuSize(int(value), Size.cy);
  SetSize(nuSize);
  UpdateRect();
}

//
//
//
void
TOcControl::SetTop(long value)
{
  TPoint nuPos(Pos.x, int(value));
  SetPos(nuPos);
  UpdateRect();
}

//
//
//
void
TOcControl::SetHeight(long Value)
{
  TSize nuSize(Size.cx, int(Value));
  SetSize(nuSize);
  UpdateRect();
}

//
//  Event support
//
HRESULT _IFUNC
TOcControl::OnControlFocus(BOOL fGotFocus)
{
  TCtrlFocusEvent ev;
  TOcView* view = OcDocument.GetActiveView();
  if (!view)
    return HR_FAIL;

  if (fGotFocus && (view->GetActivePart()) &&
     (view->GetActivePart() != this))
    view->GetActivePart()->Activate (FALSE);

  ev.Ctrl = this;
  ev.GotFocus = fGotFocus;
  view->ForwardEvent(OC_CTRLEVENT_FOCUS, &ev);
  return HR_NOERROR;
}

//
//
//
HRESULT _IFUNC
TOcControl::OnPropertyChanged(DISPID dispid)
{
  TCtrlPropertyEvent ev;
  TOcView* view = OcDocument.GetActiveView();
  if (!view)
    return HR_FAIL;

  ev.Ctrl = this;
  ev.DispId = dispid;
  ev.accept = true;
  view->ForwardEvent(OC_CTRLEVENT_PROPERTYCHANGE, &ev);
  return HR_NOERROR;
}

//
//
//
HRESULT _IFUNC
TOcControl::OnPropertyRequestEdit(DISPID dispid)
{
  TCtrlPropertyEvent ev;
  TOcView* view = OcDocument.GetActiveView();
  if (!view)
    return HR_FAIL;

  ev.Ctrl = this;
  ev.DispId = dispid;
  ev.accept = true;
  view->ForwardEvent(OC_CTRLEVENT_PROPERTYREQUESTEDIT, &ev);
  return ev.accept ? HR_OK : HR_FALSE;
}

//
//
//
HRESULT _IFUNC
TOcControl::TransformCoords(TPointL far* lpptlHimetric,
                            TPointF far* lpptfContainer, DWORD flags)
{
  TCtrlTransformCoords ev;
  TOcView* view = OcDocument.GetActiveView();
  if (!view)
    return HR_FAIL;

  ev.Ctrl = this;
  ev.lpptHimetric = lpptlHimetric;
  ev.lpptContainer = lpptfContainer;
  ev.flags = flags;
  if (!view->ForwardEvent(OC_VIEWTRANSFORMCOORDS, &ev)) {

    // default if not handled is to go from himetric to pixels and back again
    // if you want otherwise, you should override this, or answer the
    // message differently.

    HDC  dc = ::GetDC(0);
    int  xPixPerInch = ::GetDeviceCaps(dc, LOGPIXELSX);
    int  yPixPerInch = ::GetDeviceCaps(dc, LOGPIXELSY);
    ReleaseDC(0, dc);
    if (flags & XFORMCOORDS_HIMETRICTOCONTAINER) {
      lpptfContainer->x =   MAP_LOGHIM_TO_PIX(lpptlHimetric->x, xPixPerInch);
      lpptfContainer->y =   MAP_LOGHIM_TO_PIX(lpptlHimetric->y, yPixPerInch);
    }
    else if (flags & XFORMCOORDS_CONTAINERTOHIMETRIC) {
      lpptlHimetric->x =   MAP_PIX_TO_LOGHIM((ULONG)lpptfContainer->x, xPixPerInch);
      lpptlHimetric->y =   MAP_PIX_TO_LOGHIM((ULONG)lpptfContainer->y, yPixPerInch);
    }
  }
  return S_OK;
}

//
//
//
HRESULT _IFUNC TOcControl::Init(UINT, IBControl*, UINT)
{
  return ResultFromScode(E_NOTIMPL);
}

//
// TOcxView Class Implementation
//
TOcxView::TOcxView(TOcDocument& doc, TRegList* regList, IUnknown* outer)
:
  TOcView(doc, regList, outer),
  pBlankString(new TString(" "))
  //pDisplayName(new TString("Control")),
  //pScaleUnits(new TString("Control"))
{
  TAppDescriptor* appDesc;

  appDesc = &(OcApp.GetRegistrar().GetAppDescriptor());
  if (appDesc) {
    (TUnknown*)pIAmbients = appDesc->CreateAutoObject(
         (VOID*)this, ClassInfo.GetTypeInfo(),
         (VOID*)this, ClassInfo.GetTypeInfo(),
         0);
    if (pIAmbients)
      pIAmbients->AddRef();
  }
}

//
//
//
TOcxView::~TOcxView()
{
  if (pIAmbients)
    pIAmbients->Release();
  delete pBlankString;
}

//
//
//
HRESULT
TOcxView::QueryObject(const IID far& iid, void far* far* iface)
{
  PRECONDITION(iface);
  HRESULT hr;

  // interfaces
  //

  if (pIAmbients &&(HRSucceeded(hr = pIAmbients->QueryObject(iid, iface)))) {
  }
  // helpers
  //
  else if (HRSucceeded(hr = TOcView::QueryObject(iid, iface)))
  ;
  return hr;
}

//
//
//
void
TOcxView::SetBackColor(long)
{
  AmbientChanged(DISPID_AMBIENT_BACKCOLOR);
}

void
TOcxView::SetForeColor(long)
{
  AmbientChanged(DISPID_AMBIENT_FORECOLOR);
}

void
TOcxView::SetLocaleID(long)
{
  AmbientChanged(DISPID_AMBIENT_LOCALEID);
}

void
TOcxView::SetMessageReflect(bool)
{
  AmbientChanged(DISPID_AMBIENT_MESSAGEREFLECT);
}

void
TOcxView::SetTextAlign(short)
{
  AmbientChanged(DISPID_AMBIENT_TEXTALIGN);
}

void
TOcxView::SetUserMode(bool)
{
  AmbientChanged(DISPID_AMBIENT_USERMODE);
}

void
TOcxView::SetUIDead(bool)
{
  AmbientChanged(DISPID_AMBIENT_UIDEAD);
}

void
TOcxView::SetShowGrabHandles(bool)
{
  AmbientChanged(DISPID_AMBIENT_SHOWGRABHANDLES);
}

void
TOcxView::SetSupportsMnemonics(bool)
{
  AmbientChanged(DISPID_AMBIENT_SUPPORTSMNEMONICS);
}

void
TOcxView::SetShowHatching(bool)
{
  AmbientChanged(DISPID_AMBIENT_SHOWHATCHING);
}

void
TOcxView::SetDisplayAsDefault(bool)
{
  AmbientChanged(DISPID_AMBIENT_DISPLAYASDEFAULT);
}

void
TOcxView::SetDisplayName(TString& /*name*/)
{
        //pDisplayName = &name;
  AmbientChanged(DISPID_AMBIENT_DISPLAYNAME);
}

void
TOcxView::SetScaleUnits(TString& /*unit*/)
{
        //pScaleUnits = &unit;
  AmbientChanged(DISPID_AMBIENT_SCALEUNITS);
}

void
TOcxView::SetFont(IDispatch*)
{
  AmbientChanged(DISPID_AMBIENT_FONT);
}


void
TOcxView::SetAmbBackColor(long color)
{
  ForwardEvent(OC_AMBIENT_SETBACKCOLOR, color);
}

void
TOcxView::SetAmbForeColor(long color)
{
  ForwardEvent(OC_AMBIENT_SETFORECOLOR, color);
}

void
TOcxView::SetAmbLocaleID(long localeId)
{
  ForwardEvent(OC_AMBIENT_SETLOCALEID, localeId);
}

void
TOcxView::SetAmbMessageReflect(bool msgRef)
{
  ForwardEvent(OC_AMBIENT_SETMESSAGEREFLECT, msgRef);
}

void
TOcxView::SetAmbTextAlign(short align)
{
  ForwardEvent(OC_AMBIENT_SETTEXTALIGN, align);
}

void
TOcxView::SetAmbUserMode(bool mode)
{
  ForwardEvent(OC_AMBIENT_SETUSERMODE, mode);
}

void
TOcxView::SetAmbUIDead(bool dead)
{
  ForwardEvent(OC_AMBIENT_SETUIDEAD, dead);
}

void
TOcxView::SetAmbShowGrabHandles(bool handles)
{
  ForwardEvent(OC_AMBIENT_SETSHOWGRABHANDLES, handles);
}

void
TOcxView::SetAmbSupportsMnemonics(bool mnem)
{
  ForwardEvent(OC_AMBIENT_SETSUPPORTSMNEMONICS, mnem);
}

void
TOcxView::SetAmbShowHatching(bool hatch)
{
  ForwardEvent(OC_AMBIENT_SETSHOWHATCHING, hatch);
}

void
TOcxView::SetAmbDisplayAsDefault(bool Disp)
{
  ForwardEvent(OC_AMBIENT_SETDISPLAYASDEFAULT, Disp);
}

void
TOcxView::SetAmbDisplayName(TString& name)
{
  ForwardEvent(OC_AMBIENT_SETDISPLAYNAME, &name);
}

void
TOcxView::SetAmbScaleUnits(TString& scaleUnits)
{
  ForwardEvent(OC_AMBIENT_SETSCALEUNITS, &scaleUnits);
}

void
TOcxView::SetAmbFont(IDispatch* fontDisp)
{
  ForwardEvent(OC_AMBIENT_SETFONT, fontDisp);
}

long
TOcxView::GetBackColor()
{
  return GetAmbientValue(OC_AMBIENT_GETBACKCOLOR, RGB(0x80, 0x80, 0x80));
}


long
TOcxView::GetForeColor()
{
  return GetAmbientValue(OC_AMBIENT_GETFORECOLOR, RGB(0x00, 0x00, 0x00));
}


long
TOcxView::GetLocaleID()
{
  return GetAmbientValue(OC_AMBIENT_GETLOCALEID, LOCALE_USER_DEFAULT);
}


bool
TOcxView::GetMessageReflect()
{
  return (bool)(GetAmbientValue(OC_AMBIENT_GETMESSAGEREFLECT, false) & 0xf);
}


short
TOcxView::GetTextAlign()
{
  return (short)(GetAmbientValue(OC_AMBIENT_GETTEXTALIGN, 0) & 0xffff);
}


bool
TOcxView::GetUserMode()
{
  return (bool)(GetAmbientValue(OC_AMBIENT_GETUSERMODE, true) & 0xf);
}


bool
TOcxView::GetUIDead()
{
  return (bool)(GetAmbientValue(OC_AMBIENT_GETUIDEAD, false) & 0xf);
}


bool
TOcxView::GetShowGrabHandles()
{
  return (bool)(GetAmbientValue(OC_AMBIENT_GETSHOWGRABHANDLES, false) & 0xf);
}


bool
TOcxView::GetShowHatching()
{
  return (bool)(GetAmbientValue(OC_AMBIENT_GETSHOWHATCHING, false) & 0xf);
}


bool
TOcxView::GetDisplayAsDefault()
{
  return (bool)(GetAmbientValue(OC_AMBIENT_GETDISPLAYASDEFAULT, false) & 0xf);
}


bool
TOcxView::GetSupportsMnemonics()
{
  return (bool)(GetAmbientValue(OC_AMBIENT_GETSUPPORTSMNEMONICS, false) & 0xf);
}


TString&
TOcxView::GetDisplayName()
{
  TString* value;
  return ForwardEvent(OC_AMBIENT_GETDISPLAYNAME, &value) ? *value: *pBlankString;
}


TString&
TOcxView::GetScaleUnits()
{
  TString* value;
  return ForwardEvent(OC_AMBIENT_GETSCALEUNITS, &value) ? *value: *pBlankString;
}


IDispatch*
TOcxView::GetFont()
{
  IDispatch* value;
  // note that if view handles the message, it should AddRef the font
  return ForwardEvent(OC_AMBIENT_GETFONT, &value) ? value: 0;
}


void
TOcxView::AmbientChanged(DISPID dispid)
{
  // Will loop through all known controls and let them
  // know when an ambient property changes
  //
  for (TOcPartCollectionIter i(OcDocument.GetParts()); i; i++) {
    TOcPart* ocPart = (TOcPart*)i.Current();
    IBControl* CtrlI;
    if (SUCCEEDED(ocPart->QueryInterface(IID_IBControl, &(LPVOID)CtrlI))) {
      CtrlI->Release();
      CtrlI->AmbientChanged(dispid);
    }
  }
}

long
TOcxView::GetAmbientValue(long ambientMsg, long def)
{
  uint32 value;
  return ForwardEvent(int(ambientMsg), &value) ? value : def;
}

//
// TOcControlEvent Class Implementation
//    Support for standard events and generic custom event
//
TOcControlEvent::TOcControlEvent()
:
  pCtrl(0), pIEvents(0)
{
}

TOcControlEvent::~TOcControlEvent()
{
  if (pIEvents)
    pIEvents->Release();
}

void
TOcControlEvent::InitEventDispatch()
{
  if (!pIEvents)
    (TUnknown far*)pIEvents = CreateAutoObject(this, ClassInfo);
}

TUnknown*
TOcControlEvent::CreateAutoObject(const void* obj, TAutoClass& clsInfo)
{
  if (pCtrl) {
    clsInfo.AutoIds = false;
    return (TUnknown*)pIEvents = pCtrl->CreateAutoObject(obj, clsInfo);
  }
  else
    return 0;
}

long
TOcControlEvent::ForwardClickEvent(long msg)
{
  TOcView* view = pCtrl->GetActiveControlView();
  if (!view)
    return E_FAIL;

  TCtrlEvent ev;
  ev.Ctrl = pCtrl;
  view->ForwardEvent(int(msg), &ev);
  return S_OK;
}

long
TOcControlEvent::ForwardMouseEvent(long msg, short button, short shift,
    long x, long y)
{
  TOcView* view = pCtrl->GetActiveControlView();
  if (!view)
    return E_FAIL;

  TCtrlMouseEvent ev;
  ev.Ctrl = pCtrl;
  ev.Button = button;
  ev.Shift = shift;
  ev.X = x;
  ev.Y = y;
  view->ForwardEvent(int(msg), &ev);
  return S_OK;
}

long
TOcControlEvent::ForwardKeyEvent(long msg, short* keyCode, short shift)
{
  TOcView* view = pCtrl->GetActiveControlView();
  if (!view)
    return E_FAIL;

  TCtrlKeyEvent ev;
  ev.Ctrl = pCtrl;
  ev.KeyCode = *keyCode;
  ev.Shift = shift;
  view->ForwardEvent(int(msg), &ev);
  *keyCode = ev.KeyCode;
  return S_OK;
}

long
TOcControlEvent::ErrorEvent(short Number, TAutoString Description,
                  SCODE SCode, TAutoString Source, TAutoString HelpFile,
                  long HelpContext, bool far* CancelDisplay)
{
  TOcView* view = pCtrl->GetActiveControlView();
  if (!view)
    return E_FAIL;

  TCtrlErrorEvent ev;
  ev.Ctrl = pCtrl;
  ev.Number = Number;
  ev.SCode = SCode;
  ev.HelpContext = HelpContext;
  ev.CancelDisplay = *CancelDisplay;
  ev.Description = Description;
  ev.Source = Source;
  ev.HelpFile = HelpFile;

  view->ForwardEvent(OC_CTRLEVENT_ERROREVENT, &ev);
  *CancelDisplay = ev.CancelDisplay;
  return S_OK;
}

HRESULT
TOcControlEvent::CustomEvent(long* args)
{
  TCtrlCustomEvent ev;
  TAutoStack* Args = (TAutoStack*)args;
  TOcView* view = pCtrl->GetActiveControlView();
  if (!view)
    return HR_FAIL;

  ev.Ctrl = pCtrl;
  ev.Args = Args;
  view->ForwardEvent(OC_CTRLEVENT_CUSTOMEVENT, &ev);
  return HR_NOERROR;
}

long
TOcControlEvent::Click()
{
  return ForwardClickEvent(OC_CTRLEVENT_CLICK);
}

long
TOcControlEvent::DblClick()
{
  return ForwardClickEvent(OC_CTRLEVENT_DBLCLICK);
}

long
TOcControlEvent::MouseDown(short button, short shift, long x, long y)
{
  return ForwardMouseEvent(OC_CTRLEVENT_MOUSEDOWN, button, shift, x, y);
}

long
TOcControlEvent::MouseMove(short button, short shift, long x, long y)
{
  return ForwardMouseEvent(OC_CTRLEVENT_MOUSEMOVE, button, shift, x, y);
}

long
TOcControlEvent::MouseUp(short button, short shift, long x, long y)
{
  return ForwardMouseEvent(OC_CTRLEVENT_MOUSEUP, button, shift, x, y);
}

long
TOcControlEvent::KeyDown(short far* keyCode, short shift)
{
  return ForwardKeyEvent(OC_CTRLEVENT_KEYDOWN, keyCode, shift);
}

long
TOcControlEvent::KeyUp(short far* keyCode, short shift)
{
  return ForwardKeyEvent(OC_CTRLEVENT_KEYDOWN, keyCode, shift);
}

//-------------------------------------------
//  OCX Registration and Unregistration
//     may want to move these into bocole
//-------------------------------------------

HRESULT OcRegisterProc (char far* LibraryName, char far* ProcName)
{
  HINSTANCE LibHandle;
  HRESULT   hr = ResultFromScode (E_FAIL);

  LibHandle = LoadLibrary(LibraryName);
  if (!LibHandle)
    return hr;

  HRESULT PASCAL FAR _export (*DllRegisterServer)();
  (FARPROC)DllRegisterServer = ::GetProcAddress (LibHandle, ProcName);
  if (!DllRegisterServer)
    return hr;

  hr = DllRegisterServer ();
  FreeLibrary(LibHandle);
  return hr;
}


HRESULT OcRegisterControl (char far* LibraryName)
{
  return OcRegisterProc (LibraryName, "DllRegisterServer");
}


HRESULT OcUnregisterControl (CLSID ClassId)
{
  LPOLESTR str;
  char     buf[255];
  char     temp[64];
  char     LibraryName[512];
  LONG     len;
  HRESULT  hr;

  StringFromCLSID (ClassId, &str);
  strcpy (temp, OleStr (str));
  wsprintf (buf, "CLSID\\%s\\InprocServer32", temp);
  IMalloc *pMalloc;
  if (SUCCEEDED(CoGetMalloc (MEMCTX_TASK, &pMalloc))) {
    pMalloc->Free (str);
    pMalloc->Release ();
  }
  len = 512;
  hr = (HRESULT)RegQueryValue (TRegKey::ClassesRoot,
                              (LPCSTR)buf, (LPSTR)LibraryName,
                              (LONG FAR*)&len);
  if (SUCCEEDED (hr))
    hr = OcRegisterProc(LibraryName, "DllUnregisterServer");
  return hr;
}


