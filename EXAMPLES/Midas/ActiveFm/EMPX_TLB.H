// ************************************************************************ //
// WARNING                                                                  //
// -------                                                                  //
// The types declared in this file were generated from data read from a     //
// Type Library. If this type library is explicitly or indirectly (via      //
// another type library referring to this type library) re-imported, or the //
// 'Refresh' command of the Type Library Editor activated while editing the //
// Type Library, the contents of this file will be regenerated and all      //
// manual modifications will be lost.                                       //
// ************************************************************************ //

// C++ TLBWRTR : $Revision:   1.0.1.0  $
// File generated on 12/8/98 4:06:46 PM from Type Library described below.

// ************************************************************************ //
// Type Lib: D:\bcb4\Examples\Midas\ActiveFm\empx.tlb
// IID\LCID: {E70AC8ED-9EE8-11D1-94A8-0020AF06242C}\0
// Helpfile: 
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINDOWS\System32\STDOLE2.TLB)
//   (2) v4.0 StdVCL, (C:\WINDOWS\System32\STDVCL40.DLL)
// ************************************************************************ //
#ifndef   EmpX_TLBH
#define   EmpX_TLBH

#pragma option push -b


#include <vcl\utilcls.h>
#if !defined(__UTILCLS_H_VERSION) || (__UTILCLS_H_VERSION < 0x0101)
#error "This file requires an newer version of the header file UTILCLS.H"
#endif
#include <ocidl.h>
#if !defined(__TLB_NO_EVENT_WRAPPERS) && defined(USING_ATLVCL)
#include <atl/atlmod.h>
#endif

namespace Empx_tlb
{

// *********************************************************************//
// HelpString: EmpX Library
// Version:    1.0
// *********************************************************************//


// *********************************************************************//
// Forward reference of some VCL types (to avoid including STDVCL.HPP)  //
// *********************************************************************//
class IStrings; class IStringsDisp;

// *********************************************************************//
// GUIDS declared in the TypeLibrary. Following prefixes are used:      //
//   Type Libraries     : LIBID_xxxx                                    //
//   CoClasses          : CLSID_xxxx                                    //
//   DISPInterfaces     : DIID_xxxx                                     //
//   Non-DISP interfaces: IID_xxxx                                      //
// *********************************************************************//
DEFINE_GUID(LIBID_EmpX, 0xE70AC8ED, 0x9EE8, 0x11D1, 0x94, 0xA8, 0x00, 0x20, 0xAF, 0x06, 0x24, 0x2C);
DEFINE_GUID(IID_IEmpEditX, 0xE70AC8EE, 0x9EE8, 0x11D1, 0x94, 0xA8, 0x00, 0x20, 0xAF, 0x06, 0x24, 0x2C);
DEFINE_GUID(DIID_IEmpEditXEvents, 0xE70AC8F0, 0x9EE8, 0x11D1, 0x94, 0xA8, 0x00, 0x20, 0xAF, 0x06, 0x24, 0x2C);
DEFINE_GUID(CLSID_EmpEditX, 0xE70AC8F2, 0x9EE8, 0x11D1, 0x94, 0xA8, 0x00, 0x20, 0xAF, 0x06, 0x24, 0x2C);

// *********************************************************************//
// Forward declaration of types defined in TypeLibrary                  //
// *********************************************************************//
enum      TxActiveFormBorderStyle;
enum      TxPrintScale;
enum      TxMouseButton;
enum      TxWindowState;
interface DECLSPEC_UUID("{E70AC8EE-9EE8-11D1-94A8-0020AF06242C}") IEmpEditX;
interface DECLSPEC_UUID("{E70AC8F0-9EE8-11D1-94A8-0020AF06242C}") IEmpEditXEvents;

// *********************************************************************//
// Declaration of CoClasses defined in Type Library                     //
// (NOTE: Here we map each CoClass to its Default Interface)            //
//                                                                      //
// The LIBID_OF_ macro(s) map a LIBID_OF_CoClassName to the GUID of this//
// TypeLibrary. It simplifies the updating of macros when CoClass name  //
// change.                                                              //
// *********************************************************************//
typedef IEmpEditX EmpEditX;

#define LIBID_OF_EmpEditX (&LIBID_EmpX)

// *********************************************************************//
// Declaration of Enumerations defined in Type Library                  //
// *********************************************************************//
typedef enum TxActiveFormBorderStyle
{
  afbNone = 0, 
  afbSingle = 1, 
  afbSunken = 2, 
  afbRaised = 3
} TxActiveFormBorderStyle;

typedef enum TxPrintScale
{
  poNone = 0, 
  poProportional = 1, 
  poPrintToFit = 2
} TxPrintScale;

typedef enum TxMouseButton
{
  mbLeft = 0, 
  mbRight = 1, 
  mbMiddle = 2
} TxMouseButton;

typedef enum TxWindowState
{
  wsNormal = 0, 
  wsMinimized = 1, 
  wsMaximized = 2
} TxWindowState;

// *********************************************************************//
// Interface: IEmpEditX
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E70AC8EE-9EE8-11D1-94A8-0020AF06242C}
// *********************************************************************//
interface IEmpEditX : public IDispatch
{
public:
  virtual HRESULT STDMETHODCALLTYPE get_Visible(TOLEBOOL* Value/*[out,retval]*/) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE set_Visible(TOLEBOOL Value/*[in]*/) = 0; // [1]
  virtual HRESULT STDMETHODCALLTYPE get_AutoScroll(TOLEBOOL* Value/*[out,retval]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE set_AutoScroll(TOLEBOOL Value/*[in]*/) = 0; // [2]
  virtual HRESULT STDMETHODCALLTYPE get_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle* Value/*[out,retval]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE set_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle Value/*[in]*/) = 0; // [3]
  virtual HRESULT STDMETHODCALLTYPE get_Caption(BSTR* Value/*[out,retval]*/) = 0; // [-518]
  virtual HRESULT STDMETHODCALLTYPE set_Caption(BSTR Value/*[in]*/) = 0; // [-518]
  virtual HRESULT STDMETHODCALLTYPE get_Color(OLE_COLOR* Value/*[out,retval]*/) = 0; // [-501]
  virtual HRESULT STDMETHODCALLTYPE set_Color(OLE_COLOR Value/*[in]*/) = 0; // [-501]
  virtual HRESULT STDMETHODCALLTYPE get_Font(IFontDisp** Value/*[out,retval]*/) = 0; // [-512]
  virtual HRESULT STDMETHODCALLTYPE set_Font(IFontDisp* Value/*[in]*/) = 0; // [-512]
  virtual HRESULT STDMETHODCALLTYPE _set_Font(IFontDisp* Value/*[in]*/) = 0; // [-512]
  virtual HRESULT STDMETHODCALLTYPE get_KeyPreview(TOLEBOOL* Value/*[out,retval]*/) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE set_KeyPreview(TOLEBOOL Value/*[in]*/) = 0; // [4]
  virtual HRESULT STDMETHODCALLTYPE get_PixelsPerInch(long* Value/*[out,retval]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE set_PixelsPerInch(long Value/*[in]*/) = 0; // [5]
  virtual HRESULT STDMETHODCALLTYPE get_PrintScale(Empx_tlb::TxPrintScale* Value/*[out,retval]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE set_PrintScale(Empx_tlb::TxPrintScale Value/*[in]*/) = 0; // [6]
  virtual HRESULT STDMETHODCALLTYPE get_Scaled(TOLEBOOL* Value/*[out,retval]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE set_Scaled(TOLEBOOL Value/*[in]*/) = 0; // [7]
  virtual HRESULT STDMETHODCALLTYPE get_Active(TOLEBOOL* Value/*[out,retval]*/) = 0; // [8]
  virtual HRESULT STDMETHODCALLTYPE get_DropTarget(TOLEBOOL* Value/*[out,retval]*/) = 0; // [9]
  virtual HRESULT STDMETHODCALLTYPE set_DropTarget(TOLEBOOL Value/*[in]*/) = 0; // [9]
  virtual HRESULT STDMETHODCALLTYPE get_HelpFile(BSTR* Value/*[out,retval]*/) = 0; // [10]
  virtual HRESULT STDMETHODCALLTYPE set_HelpFile(BSTR Value/*[in]*/) = 0; // [10]
  virtual HRESULT STDMETHODCALLTYPE get_WindowState(Empx_tlb::TxWindowState* Value/*[out,retval]*/) = 0; // [11]
  virtual HRESULT STDMETHODCALLTYPE set_WindowState(Empx_tlb::TxWindowState Value/*[in]*/) = 0; // [11]
  virtual HRESULT STDMETHODCALLTYPE get_Enabled(TOLEBOOL* Value/*[out,retval]*/) = 0; // [-514]
  virtual HRESULT STDMETHODCALLTYPE set_Enabled(TOLEBOOL Value/*[in]*/) = 0; // [-514]
  virtual HRESULT STDMETHODCALLTYPE get_Cursor(short* Value/*[out,retval]*/) = 0; // [12]
  virtual HRESULT STDMETHODCALLTYPE set_Cursor(short Value/*[in]*/) = 0; // [12]
};

// *********************************************************************//
// Interface: IEmpEditXEvents
// Flags:     (4096) Dispatchable
// GUID:      {E70AC8F0-9EE8-11D1-94A8-0020AF06242C}
// *********************************************************************//
interface IEmpEditXEvents : public IDispatch
{
// DispInterfaces have no methods. Their methods and properties are
// accessed via IDispatch::Invoke. See the class IEmpEditXEventsDisp provided
// below for an easy way to access the methods/properties of this
// interface.
};

#if !defined(__TLB_NO_INTERFACE_WRAPPERS)
// *********************************************************************//
// SmartIntf: TCOMIEmpEditX
// Interface: IEmpEditX
// *********************************************************************//
template <class T /* IEmpEditX */ >
class TCOMIEmpEditXT : public TComInterface<IEmpEditX>, public TComInterfaceBase<IUnknown>
{
public:
  TCOMIEmpEditXT() {}
  TCOMIEmpEditXT(IEmpEditX *intf, bool addRef = false) : TComInterface<IEmpEditX>(intf, addRef) {}
  TCOMIEmpEditXT(const TCOMIEmpEditXT& src) : TComInterface<IEmpEditX>(src) {}
  TCOMIEmpEditXT& operator=(const TCOMIEmpEditXT& src) { Bind(src, true); return *this;}

  HRESULT         __fastcall get_Visible(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_Visible(void);
  HRESULT         __fastcall set_Visible(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_AutoScroll(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_AutoScroll(void);
  HRESULT         __fastcall set_AutoScroll(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle* Value/*[out,retval]*/);
  Empx_tlb::TxActiveFormBorderStyle __fastcall get_AxBorderStyle(void);
  HRESULT         __fastcall set_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle Value/*[in]*/);
  HRESULT         __fastcall get_Caption(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Caption(void);
  HRESULT         __fastcall set_Caption(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Color(OLE_COLOR* Value/*[out,retval]*/);
  OLE_COLOR       __fastcall get_Color(void);
  HRESULT         __fastcall set_Color(OLE_COLOR Value/*[in]*/);
  HRESULT         __fastcall get_Font(IFontDisp** Value/*[out,retval]*/);
  IFontDisp*      __fastcall get_Font(void);
  HRESULT         __fastcall set_Font(IFontDisp* Value/*[in]*/);
  HRESULT         __fastcall _set_Font(IFontDisp* Value/*[in]*/);
  HRESULT         __fastcall get_KeyPreview(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_KeyPreview(void);
  HRESULT         __fastcall set_KeyPreview(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_PixelsPerInch(long* Value/*[out,retval]*/);
  long            __fastcall get_PixelsPerInch(void);
  HRESULT         __fastcall set_PixelsPerInch(long Value/*[in]*/);
  HRESULT         __fastcall get_PrintScale(Empx_tlb::TxPrintScale* Value/*[out,retval]*/);
  Empx_tlb::TxPrintScale __fastcall get_PrintScale(void);
  HRESULT         __fastcall set_PrintScale(Empx_tlb::TxPrintScale Value/*[in]*/);
  HRESULT         __fastcall get_Scaled(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_Scaled(void);
  HRESULT         __fastcall set_Scaled(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_Active(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_Active(void);
  HRESULT         __fastcall get_DropTarget(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_DropTarget(void);
  HRESULT         __fastcall set_DropTarget(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_HelpFile(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_HelpFile(void);
  HRESULT         __fastcall set_HelpFile(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_WindowState(Empx_tlb::TxWindowState* Value/*[out,retval]*/);
  Empx_tlb::TxWindowState __fastcall get_WindowState(void);
  HRESULT         __fastcall set_WindowState(Empx_tlb::TxWindowState Value/*[in]*/);
  HRESULT         __fastcall get_Enabled(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_Enabled(void);
  HRESULT         __fastcall set_Enabled(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_Cursor(short* Value/*[out,retval]*/);
  short           __fastcall get_Cursor(void);
  HRESULT         __fastcall set_Cursor(short Value/*[in]*/);

  __property   TOLEBOOL        Visible = {read = get_Visible, write = set_Visible};
  __property   TOLEBOOL        AutoScroll = {read = get_AutoScroll, write = set_AutoScroll};
  __property   Empx_tlb::TxActiveFormBorderStyle AxBorderStyle = {read = get_AxBorderStyle, write = set_AxBorderStyle};
  __property   BSTR            Caption = {read = get_Caption, write = set_Caption};
  __property   OLE_COLOR       Color = {read = get_Color, write = set_Color};
  __property   IFontDisp*      Font = {read = get_Font, write = set_Font};
  __property   TOLEBOOL        KeyPreview = {read = get_KeyPreview, write = set_KeyPreview};
  __property   long            PixelsPerInch = {read = get_PixelsPerInch, write = set_PixelsPerInch};
  __property   Empx_tlb::TxPrintScale PrintScale = {read = get_PrintScale, write = set_PrintScale};
  __property   TOLEBOOL        Scaled = {read = get_Scaled, write = set_Scaled};
  __property   TOLEBOOL        Active = {read = get_Active};
  __property   TOLEBOOL        DropTarget = {read = get_DropTarget, write = set_DropTarget};
  __property   BSTR            HelpFile = {read = get_HelpFile, write = set_HelpFile};
  __property   Empx_tlb::TxWindowState WindowState = {read = get_WindowState, write = set_WindowState};
  __property   TOLEBOOL        Enabled = {read = get_Enabled, write = set_Enabled};
  __property   short           Cursor = {read = get_Cursor, write = set_Cursor};
};
typedef TCOMIEmpEditXT<IEmpEditX> TCOMIEmpEditX;

// *********************************************************************//
// DispIntf:  IEmpEditX
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E70AC8EE-9EE8-11D1-94A8-0020AF06242C}
// *********************************************************************//
template<class T>
class IEmpEditXDispT : public TAutoDriver<IEmpEditX>
{
public:
  IEmpEditXDispT(){}

  IEmpEditXDispT(IEmpEditX *pintf)
  {
    TAutoDriver<IEmpEditX>::Bind(pintf);
  }

  IEmpEditXDispT& operator=(IEmpEditX *pintf)
  {
    TAutoDriver<IEmpEditX>::Bind(pintf);
    return *this;
  }

  HRESULT BindDefault(/*Binds to new instance of CoClass EmpEditX*/)
  {
    return OLECHECK(Bind(CLSID_EmpEditX));
  }

  HRESULT BindRunning(/*Binds to a running instance of CoClass EmpEditX*/)
  {
    return BindToActive(CLSID_EmpEditX);
  }

  HRESULT         __fastcall get_Visible(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_Visible(void);
  HRESULT         __fastcall set_Visible(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_AutoScroll(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_AutoScroll(void);
  HRESULT         __fastcall set_AutoScroll(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle* Value/*[out,retval]*/);
  Empx_tlb::TxActiveFormBorderStyle __fastcall get_AxBorderStyle(void);
  HRESULT         __fastcall set_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle Value/*[in]*/);
  HRESULT         __fastcall get_Caption(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_Caption(void);
  HRESULT         __fastcall set_Caption(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_Color(OLE_COLOR* Value/*[out,retval]*/);
  OLE_COLOR       __fastcall get_Color(void);
  HRESULT         __fastcall set_Color(OLE_COLOR Value/*[in]*/);
  HRESULT         __fastcall get_Font(IFontDisp** Value/*[out,retval]*/);
  IFontDisp*      __fastcall get_Font(void);
  HRESULT         __fastcall set_Font(IFontDisp* Value/*[in]*/);
  HRESULT         __fastcall _set_Font(IFontDisp* Value/*[in]*/);
  HRESULT         __fastcall get_KeyPreview(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_KeyPreview(void);
  HRESULT         __fastcall set_KeyPreview(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_PixelsPerInch(long* Value/*[out,retval]*/);
  long            __fastcall get_PixelsPerInch(void);
  HRESULT         __fastcall set_PixelsPerInch(long Value/*[in]*/);
  HRESULT         __fastcall get_PrintScale(Empx_tlb::TxPrintScale* Value/*[out,retval]*/);
  Empx_tlb::TxPrintScale __fastcall get_PrintScale(void);
  HRESULT         __fastcall set_PrintScale(Empx_tlb::TxPrintScale Value/*[in]*/);
  HRESULT         __fastcall get_Scaled(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_Scaled(void);
  HRESULT         __fastcall set_Scaled(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_Active(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_Active(void);
  HRESULT         __fastcall get_DropTarget(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_DropTarget(void);
  HRESULT         __fastcall set_DropTarget(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_HelpFile(BSTR* Value/*[out,retval]*/);
  BSTR            __fastcall get_HelpFile(void);
  HRESULT         __fastcall set_HelpFile(BSTR Value/*[in]*/);
  HRESULT         __fastcall get_WindowState(Empx_tlb::TxWindowState* Value/*[out,retval]*/);
  Empx_tlb::TxWindowState __fastcall get_WindowState(void);
  HRESULT         __fastcall set_WindowState(Empx_tlb::TxWindowState Value/*[in]*/);
  HRESULT         __fastcall get_Enabled(TOLEBOOL* Value/*[out,retval]*/);
  TOLEBOOL        __fastcall get_Enabled(void);
  HRESULT         __fastcall set_Enabled(TOLEBOOL Value/*[in]*/);
  HRESULT         __fastcall get_Cursor(short* Value/*[out,retval]*/);
  short           __fastcall get_Cursor(void);
  HRESULT         __fastcall set_Cursor(short Value/*[in]*/);

  __property   TOLEBOOL        Visible = {read = get_Visible, write = set_Visible};
  __property   TOLEBOOL        AutoScroll = {read = get_AutoScroll, write = set_AutoScroll};
  __property   Empx_tlb::TxActiveFormBorderStyle AxBorderStyle = {read = get_AxBorderStyle, write = set_AxBorderStyle};
  __property   BSTR            Caption = {read = get_Caption, write = set_Caption};
  __property   OLE_COLOR       Color = {read = get_Color, write = set_Color};
  __property   IFontDisp*      Font = {read = get_Font, write = set_Font};
  __property   TOLEBOOL        KeyPreview = {read = get_KeyPreview, write = set_KeyPreview};
  __property   long            PixelsPerInch = {read = get_PixelsPerInch, write = set_PixelsPerInch};
  __property   Empx_tlb::TxPrintScale PrintScale = {read = get_PrintScale, write = set_PrintScale};
  __property   TOLEBOOL        Scaled = {read = get_Scaled, write = set_Scaled};
  __property   TOLEBOOL        Active = {read = get_Active};
  __property   TOLEBOOL        DropTarget = {read = get_DropTarget, write = set_DropTarget};
  __property   BSTR            HelpFile = {read = get_HelpFile, write = set_HelpFile};
  __property   Empx_tlb::TxWindowState WindowState = {read = get_WindowState, write = set_WindowState};
  __property   TOLEBOOL        Enabled = {read = get_Enabled, write = set_Enabled};
  __property   short           Cursor = {read = get_Cursor, write = set_Cursor};
};
typedef IEmpEditXDispT<IEmpEditX> IEmpEditXDisp;

// *********************************************************************//
// DispIntf:  IEmpEditXEvents
// Flags:     (4096) Dispatchable
// GUID:      {E70AC8F0-9EE8-11D1-94A8-0020AF06242C}
// *********************************************************************//
template <class T>
class IEmpEditXEventsDispT : public TAutoDriver<IEmpEditXEvents>
{
public:
  IEmpEditXEventsDispT(){}

  void Attach(LPUNKNOWN punk)
  { m_Dispatch = static_cast<T*>(punk); }

  void            __fastcall OnActivate();
  void            __fastcall OnClick();
  void            __fastcall OnCreate();
  void            __fastcall OnDblClick();
  void            __fastcall OnDestroy();
  void            __fastcall OnDeactivate();
  void            __fastcall OnPaint();

};
typedef IEmpEditXEventsDispT<IEmpEditXEvents> IEmpEditXEventsDisp;

// *********************************************************************//
// SmartIntf: TCOMIEmpEditX
// Interface: IEmpEditX
// *********************************************************************//
template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_Visible(TOLEBOOL* Value/*[out,retval]*/)
{
  return (*this)->get_Visible(Value);
}

template <class T> TOLEBOOL __fastcall
TCOMIEmpEditXT<T>::get_Visible(void)
{
  TOLEBOOL Value;
  OLECHECK(get_Visible(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_Visible(TOLEBOOL Value/*[in]*/)
{
  return (*this)->set_Visible(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_AutoScroll(TOLEBOOL* Value/*[out,retval]*/)
{
  return (*this)->get_AutoScroll(Value);
}

template <class T> TOLEBOOL __fastcall
TCOMIEmpEditXT<T>::get_AutoScroll(void)
{
  TOLEBOOL Value;
  OLECHECK(get_AutoScroll(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_AutoScroll(TOLEBOOL Value/*[in]*/)
{
  return (*this)->set_AutoScroll(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle* Value/*[out,retval]*/)
{
  return (*this)->get_AxBorderStyle(Value);
}

template <class T> Empx_tlb::TxActiveFormBorderStyle __fastcall
TCOMIEmpEditXT<T>::get_AxBorderStyle(void)
{
  Empx_tlb::TxActiveFormBorderStyle Value;
  OLECHECK(get_AxBorderStyle(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle Value/*[in]*/)
{
  return (*this)->set_AxBorderStyle(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_Caption(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_Caption(Value);
}

template <class T> BSTR __fastcall
TCOMIEmpEditXT<T>::get_Caption(void)
{
  BSTR Value;
  OLECHECK(get_Caption(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_Caption(BSTR Value/*[in]*/)
{
  return (*this)->set_Caption(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_Color(OLE_COLOR* Value/*[out,retval]*/)
{
  return (*this)->get_Color(Value);
}

template <class T> OLE_COLOR __fastcall
TCOMIEmpEditXT<T>::get_Color(void)
{
  OLE_COLOR Value;
  OLECHECK(get_Color(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_Color(OLE_COLOR Value/*[in]*/)
{
  return (*this)->set_Color(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_Font(IFontDisp** Value/*[out,retval]*/)
{
  return (*this)->get_Font(Value);
}

template <class T> IFontDisp* __fastcall
TCOMIEmpEditXT<T>::get_Font(void)
{
  IFontDisp* Value= 0;
  OLECHECK(get_Font(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_Font(IFontDisp* Value/*[in]*/)
{
  return (*this)->set_Font(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::_set_Font(IFontDisp* Value/*[in]*/)
{
  return (*this)->_set_Font(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_KeyPreview(TOLEBOOL* Value/*[out,retval]*/)
{
  return (*this)->get_KeyPreview(Value);
}

template <class T> TOLEBOOL __fastcall
TCOMIEmpEditXT<T>::get_KeyPreview(void)
{
  TOLEBOOL Value;
  OLECHECK(get_KeyPreview(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_KeyPreview(TOLEBOOL Value/*[in]*/)
{
  return (*this)->set_KeyPreview(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_PixelsPerInch(long* Value/*[out,retval]*/)
{
  return (*this)->get_PixelsPerInch(Value);
}

template <class T> long __fastcall
TCOMIEmpEditXT<T>::get_PixelsPerInch(void)
{
  long Value;
  OLECHECK(get_PixelsPerInch(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_PixelsPerInch(long Value/*[in]*/)
{
  return (*this)->set_PixelsPerInch(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_PrintScale(Empx_tlb::TxPrintScale* Value/*[out,retval]*/)
{
  return (*this)->get_PrintScale(Value);
}

template <class T> Empx_tlb::TxPrintScale __fastcall
TCOMIEmpEditXT<T>::get_PrintScale(void)
{
  Empx_tlb::TxPrintScale Value;
  OLECHECK(get_PrintScale(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_PrintScale(Empx_tlb::TxPrintScale Value/*[in]*/)
{
  return (*this)->set_PrintScale(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_Scaled(TOLEBOOL* Value/*[out,retval]*/)
{
  return (*this)->get_Scaled(Value);
}

template <class T> TOLEBOOL __fastcall
TCOMIEmpEditXT<T>::get_Scaled(void)
{
  TOLEBOOL Value;
  OLECHECK(get_Scaled(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_Scaled(TOLEBOOL Value/*[in]*/)
{
  return (*this)->set_Scaled(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_Active(TOLEBOOL* Value/*[out,retval]*/)
{
  return (*this)->get_Active(Value);
}

template <class T> TOLEBOOL __fastcall
TCOMIEmpEditXT<T>::get_Active(void)
{
  TOLEBOOL Value;
  OLECHECK(get_Active(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_DropTarget(TOLEBOOL* Value/*[out,retval]*/)
{
  return (*this)->get_DropTarget(Value);
}

template <class T> TOLEBOOL __fastcall
TCOMIEmpEditXT<T>::get_DropTarget(void)
{
  TOLEBOOL Value;
  OLECHECK(get_DropTarget(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_DropTarget(TOLEBOOL Value/*[in]*/)
{
  return (*this)->set_DropTarget(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_HelpFile(BSTR* Value/*[out,retval]*/)
{
  return (*this)->get_HelpFile(Value);
}

template <class T> BSTR __fastcall
TCOMIEmpEditXT<T>::get_HelpFile(void)
{
  BSTR Value;
  OLECHECK(get_HelpFile(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_HelpFile(BSTR Value/*[in]*/)
{
  return (*this)->set_HelpFile(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_WindowState(Empx_tlb::TxWindowState* Value/*[out,retval]*/)
{
  return (*this)->get_WindowState(Value);
}

template <class T> Empx_tlb::TxWindowState __fastcall
TCOMIEmpEditXT<T>::get_WindowState(void)
{
  Empx_tlb::TxWindowState Value;
  OLECHECK(get_WindowState(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_WindowState(Empx_tlb::TxWindowState Value/*[in]*/)
{
  return (*this)->set_WindowState(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_Enabled(TOLEBOOL* Value/*[out,retval]*/)
{
  return (*this)->get_Enabled(Value);
}

template <class T> TOLEBOOL __fastcall
TCOMIEmpEditXT<T>::get_Enabled(void)
{
  TOLEBOOL Value;
  OLECHECK(get_Enabled(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_Enabled(TOLEBOOL Value/*[in]*/)
{
  return (*this)->set_Enabled(Value);
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::get_Cursor(short* Value/*[out,retval]*/)
{
  return (*this)->get_Cursor(Value);
}

template <class T> short __fastcall
TCOMIEmpEditXT<T>::get_Cursor(void)
{
  short Value;
  OLECHECK(get_Cursor(&Value));
  return Value;
}

template <class T> HRESULT __fastcall
TCOMIEmpEditXT<T>::set_Cursor(short Value/*[in]*/)
{
  return (*this)->set_Cursor(Value);
}

// *********************************************************************//
// DispIntf:  IEmpEditX
// Flags:     (4416) Dual OleAutomation Dispatchable
// GUID:      {E70AC8EE-9EE8-11D1-94A8-0020AF06242C}
// *********************************************************************//
template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_Visible(TOLEBOOL* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Visible"), DISPID(1));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BOOL:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> TOLEBOOL __fastcall
IEmpEditXDispT<T>::get_Visible(void)
{
  TOLEBOOL Value;
  this->get_Visible(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_Visible(TOLEBOOL Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Visible"), DISPID(1));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BOOL:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_AutoScroll(TOLEBOOL* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("AutoScroll"), DISPID(2));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BOOL:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> TOLEBOOL __fastcall
IEmpEditXDispT<T>::get_AutoScroll(void)
{
  TOLEBOOL Value;
  this->get_AutoScroll(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_AutoScroll(TOLEBOOL Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("AutoScroll"), DISPID(2));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BOOL:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("AxBorderStyle"), DISPID(3));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((int*)Value /*[VT_USERDEFINED:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Empx_tlb::TxActiveFormBorderStyle __fastcall
IEmpEditXDispT<T>::get_AxBorderStyle(void)
{
  Empx_tlb::TxActiveFormBorderStyle Value;
  this->get_AxBorderStyle(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_AxBorderStyle(Empx_tlb::TxActiveFormBorderStyle Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("AxBorderStyle"), DISPID(3));
  TAutoArgs<1> _args;
  _args[1] = (int)Value /*[VT_USERDEFINED:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_Caption(BSTR* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Caption"), DISPID(-518));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IEmpEditXDispT<T>::get_Caption(void)
{
  BSTR Value;
  this->get_Caption(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_Caption(BSTR Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Caption"), DISPID(-518));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BSTR:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_Color(OLE_COLOR* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Color"), DISPID(-501));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_UI4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> OLE_COLOR __fastcall
IEmpEditXDispT<T>::get_Color(void)
{
  OLE_COLOR Value;
  this->get_Color(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_Color(OLE_COLOR Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Color"), DISPID(-501));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_UI4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_Font(IFontDisp** Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Font"), DISPID(-512));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((LPDISPATCH*)Value /*[VT_USERDEFINED:2]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> IFontDisp* __fastcall
IEmpEditXDispT<T>::get_Font(void)
{
  IFontDisp* Value;
  this->get_Font(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_Font(IFontDisp* Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Font"), DISPID(-512));
  TAutoArgs<1> _args;
  _args[1] = (LPDISPATCH)Value /*[VT_USERDEFINED:1]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::_set_Font(IFontDisp* Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Font"), DISPID(-512));
  TAutoArgs<1> _args;
  _args[1] = (LPDISPATCH)Value /*[VT_USERDEFINED:1]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_KeyPreview(TOLEBOOL* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("KeyPreview"), DISPID(4));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BOOL:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> TOLEBOOL __fastcall
IEmpEditXDispT<T>::get_KeyPreview(void)
{
  TOLEBOOL Value;
  this->get_KeyPreview(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_KeyPreview(TOLEBOOL Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("KeyPreview"), DISPID(4));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BOOL:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_PixelsPerInch(long* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("PixelsPerInch"), DISPID(5));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I4:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> long __fastcall
IEmpEditXDispT<T>::get_PixelsPerInch(void)
{
  long Value;
  this->get_PixelsPerInch(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_PixelsPerInch(long Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("PixelsPerInch"), DISPID(5));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I4:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_PrintScale(Empx_tlb::TxPrintScale* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("PrintScale"), DISPID(6));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((int*)Value /*[VT_USERDEFINED:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Empx_tlb::TxPrintScale __fastcall
IEmpEditXDispT<T>::get_PrintScale(void)
{
  Empx_tlb::TxPrintScale Value;
  this->get_PrintScale(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_PrintScale(Empx_tlb::TxPrintScale Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("PrintScale"), DISPID(6));
  TAutoArgs<1> _args;
  _args[1] = (int)Value /*[VT_USERDEFINED:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_Scaled(TOLEBOOL* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Scaled"), DISPID(7));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BOOL:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> TOLEBOOL __fastcall
IEmpEditXDispT<T>::get_Scaled(void)
{
  TOLEBOOL Value;
  this->get_Scaled(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_Scaled(TOLEBOOL Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Scaled"), DISPID(7));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BOOL:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_Active(TOLEBOOL* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Active"), DISPID(8));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BOOL:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> TOLEBOOL __fastcall
IEmpEditXDispT<T>::get_Active(void)
{
  TOLEBOOL Value;
  this->get_Active(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_DropTarget(TOLEBOOL* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("DropTarget"), DISPID(9));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BOOL:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> TOLEBOOL __fastcall
IEmpEditXDispT<T>::get_DropTarget(void)
{
  TOLEBOOL Value;
  this->get_DropTarget(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_DropTarget(TOLEBOOL Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("DropTarget"), DISPID(9));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BOOL:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_HelpFile(BSTR* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("HelpFile"), DISPID(10));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BSTR:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> BSTR __fastcall
IEmpEditXDispT<T>::get_HelpFile(void)
{
  BSTR Value;
  this->get_HelpFile(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_HelpFile(BSTR Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("HelpFile"), DISPID(10));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BSTR:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_WindowState(Empx_tlb::TxWindowState* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("WindowState"), DISPID(11));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr((int*)Value /*[VT_USERDEFINED:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> Empx_tlb::TxWindowState __fastcall
IEmpEditXDispT<T>::get_WindowState(void)
{
  Empx_tlb::TxWindowState Value;
  this->get_WindowState(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_WindowState(Empx_tlb::TxWindowState Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("WindowState"), DISPID(11));
  TAutoArgs<1> _args;
  _args[1] = (int)Value /*[VT_USERDEFINED:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_Enabled(TOLEBOOL* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Enabled"), DISPID(-514));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_BOOL:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> TOLEBOOL __fastcall
IEmpEditXDispT<T>::get_Enabled(void)
{
  TOLEBOOL Value;
  this->get_Enabled(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_Enabled(TOLEBOOL Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Enabled"), DISPID(-514));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_BOOL:0]*/;
  return OlePropertyPut(_dispid, _args);
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::get_Cursor(short* Value/*[out,retval]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Cursor"), DISPID(12));
  TAutoArgs<0> _args;
  return OutRetValSetterPtr(Value /*[VT_I2:1]*/, _args, OlePropertyGet(_dispid, _args));
}

template <class T> short __fastcall
IEmpEditXDispT<T>::get_Cursor(void)
{
  short Value;
  this->get_Cursor(&Value);
  return Value;
}

template <class T> HRESULT __fastcall
IEmpEditXDispT<T>::set_Cursor(short Value/*[in]*/)
{
  static _TDispID _dispid(*this, OLETEXT("Cursor"), DISPID(12));
  TAutoArgs<1> _args;
  _args[1] = Value /*[VT_I2:0]*/;
  return OlePropertyPut(_dispid, _args);
}

// *********************************************************************//
// DispIntf:  IEmpEditXEvents
// Flags:     (4096) Dispatchable
// GUID:      {E70AC8F0-9EE8-11D1-94A8-0020AF06242C}
// *********************************************************************//
template <class T> void __fastcall
IEmpEditXEventsDispT<T>::OnActivate()
{
  static _TDispID _dispid(/* OnActivate */ DISPID(1));
  OleProcedure(_dispid);
}

template <class T> void __fastcall
IEmpEditXEventsDispT<T>::OnClick()
{
  static _TDispID _dispid(/* OnClick */ DISPID(2));
  OleProcedure(_dispid);
}

template <class T> void __fastcall
IEmpEditXEventsDispT<T>::OnCreate()
{
  static _TDispID _dispid(/* OnCreate */ DISPID(3));
  OleProcedure(_dispid);
}

template <class T> void __fastcall
IEmpEditXEventsDispT<T>::OnDblClick()
{
  static _TDispID _dispid(/* OnDblClick */ DISPID(4));
  OleProcedure(_dispid);
}

template <class T> void __fastcall
IEmpEditXEventsDispT<T>::OnDestroy()
{
  static _TDispID _dispid(/* OnDestroy */ DISPID(5));
  OleProcedure(_dispid);
}

template <class T> void __fastcall
IEmpEditXEventsDispT<T>::OnDeactivate()
{
  static _TDispID _dispid(/* OnDeactivate */ DISPID(6));
  OleProcedure(_dispid);
}

template <class T> void __fastcall
IEmpEditXEventsDispT<T>::OnPaint()
{
  static _TDispID _dispid(/* OnPaint */ DISPID(15));
  OleProcedure(_dispid);
}

#endif  //   __TLB_NO_INTERFACE_WRAPPERS


#if !defined(__TLB_NO_EVENT_WRAPPERS) && defined(USING_ATLVCL)
// *********************************************************************//
// CONNECTIONPOINT/EVENT PROXY
// CoClass         : EmpEditX
// Event Interface : IEmpEditXEvents
// *********************************************************************//
template <class T>
class TEvents_EmpEditX : public IConnectionPointImpl<T,
                                                 &DIID_IEmpEditXEvents,
                                                 CComUnkArray<CONNECTIONPOINT_ARRAY_SIZE> >
{
public:
  void            Fire_OnActivate(void);
  void            Fire_OnClick(void);
  void            Fire_OnCreate(void);
  void            Fire_OnDblClick(void);
  void            Fire_OnDestroy(void);
  void            Fire_OnDeactivate(void);
  void            Fire_OnPaint(void);
protected:
  IEmpEditXEventsDisp m_EventIntfObj;
};

template <class T> void
TEvents_EmpEditX<T>::Fire_OnActivate(void)
{
  T * pT = (T*)this;
  pT->Lock();
  IUnknown ** pp = m_vec.begin();
  while (pp < m_vec.end())
  {
    if (*pp != NULL)
    {
      m_EventIntfObj.Attach(*pp);
      m_EventIntfObj.OnActivate();
    }
    pp++;
  }
  pT->Unlock();
}

template <class T> void
TEvents_EmpEditX<T>::Fire_OnClick(void)
{
  T * pT = (T*)this;
  pT->Lock();
  IUnknown ** pp = m_vec.begin();
  while (pp < m_vec.end())
  {
    if (*pp != NULL)
    {
      m_EventIntfObj.Attach(*pp);
      m_EventIntfObj.OnClick();
    }
    pp++;
  }
  pT->Unlock();
}

template <class T> void
TEvents_EmpEditX<T>::Fire_OnCreate(void)
{
  T * pT = (T*)this;
  pT->Lock();
  IUnknown ** pp = m_vec.begin();
  while (pp < m_vec.end())
  {
    if (*pp != NULL)
    {
      m_EventIntfObj.Attach(*pp);
      m_EventIntfObj.OnCreate();
    }
    pp++;
  }
  pT->Unlock();
}

template <class T> void
TEvents_EmpEditX<T>::Fire_OnDblClick(void)
{
  T * pT = (T*)this;
  pT->Lock();
  IUnknown ** pp = m_vec.begin();
  while (pp < m_vec.end())
  {
    if (*pp != NULL)
    {
      m_EventIntfObj.Attach(*pp);
      m_EventIntfObj.OnDblClick();
    }
    pp++;
  }
  pT->Unlock();
}

template <class T> void
TEvents_EmpEditX<T>::Fire_OnDestroy(void)
{
  T * pT = (T*)this;
  pT->Lock();
  IUnknown ** pp = m_vec.begin();
  while (pp < m_vec.end())
  {
    if (*pp != NULL)
    {
      m_EventIntfObj.Attach(*pp);
      m_EventIntfObj.OnDestroy();
    }
    pp++;
  }
  pT->Unlock();
}

template <class T> void
TEvents_EmpEditX<T>::Fire_OnDeactivate(void)
{
  T * pT = (T*)this;
  pT->Lock();
  IUnknown ** pp = m_vec.begin();
  while (pp < m_vec.end())
  {
    if (*pp != NULL)
    {
      m_EventIntfObj.Attach(*pp);
      m_EventIntfObj.OnDeactivate();
    }
    pp++;
  }
  pT->Unlock();
}

template <class T> void
TEvents_EmpEditX<T>::Fire_OnPaint(void)
{
  T * pT = (T*)this;
  pT->Lock();
  IUnknown ** pp = m_vec.begin();
  while (pp < m_vec.end())
  {
    if (*pp != NULL)
    {
      m_EventIntfObj.Attach(*pp);
      m_EventIntfObj.OnPaint();
    }
    pp++;
  }
  pT->Unlock();
}

#endif  //   __TLB_NO_EVENT_WRAPPERS

};     // namespace Empx_tlb

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Empx_tlb;
#endif

#pragma option pop

#endif // EmpX_TLBH
