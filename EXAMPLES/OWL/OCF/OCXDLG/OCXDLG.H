//----------------------------------------------------------------------------
//  Project OcxDlg
//  Borland International, Inc.
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    OcxDlg Application
//  FILE:         OcxDlg.h
//  AUTHOR:       Chris McConn
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TMyOcxDialog (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(_OCXDLG_H) // Sentry, use file only if it's not already included.
#define _OCXDLG_H

#include <owl\oledialg.h>

//============================================================================
// TVariantArg encapsulates a 'VARIANTARG'. It handles 'VariantInit'
// and 'VariantClear' in the constructor and destructor respectively...
class TVariantArg : public VARIANTARG {
  public:
    TVariantArg();
    TVariantArg(char* str);
    TVariantArg(IDispatch* pDispatch);
    TVariantArg(bool b);
    TVariantArg(int i);
    TVariantArg(long l);
   ~TVariantArg();

    TVariantArg& operator =(int i);
    TVariantArg& operator =(long l);

  protected:
    void  Init(char* str);
    void  Init(IDispatch* pDispatch);
    void  Init(bool b);
    void  Init(int i);
    void  Init(long l);

  private:
    TVariantArg(const TVariantArg&);
    TVariantArg& operator =(const TVariantArg&);
};

// InLines
inline
TVariantArg::TVariantArg()
{
  VariantInit(this);
}

// Frees BSTRs or arrays and releases IDispatch
inline
TVariantArg::~TVariantArg()
{
  VariantClear(this);
}

inline
TVariantArg::TVariantArg(char* str)
{
  memset((VARIANTARG*)this, 0, sizeof(VARIANTARG));
  VariantInit((VARIANTARG*)this);
  Init(str);
}

inline
TVariantArg::TVariantArg(IDispatch* pDispatch)
{
  memset((VARIANTARG*)this, 0, sizeof(VARIANTARG));
  VariantInit((VARIANTARG*)this);
  Init(pDispatch);
}

inline
TVariantArg::TVariantArg(bool b)
{
  memset((VARIANTARG*)this, 0, sizeof(VARIANTARG));
  VariantInit((VARIANTARG*)this);
  Init(b);
}

inline
TVariantArg::TVariantArg(int i)
{
  memset((VARIANTARG*)this, 0, sizeof(VARIANTARG));
  VariantInit((VARIANTARG*)this);
  Init(i);
}

inline
TVariantArg::TVariantArg(long l)
{
  memset((VARIANTARG*)this, 0, sizeof(VARIANTARG));
  VariantInit((VARIANTARG*)this);
  Init(l);
}


//============================================================================
// OCX Dialog object
class TMyOcxDialog : public TOleDialog {

  // Functions --------------------------------------------------------------
  public:// Constructors/Destructors
    TMyOcxDialog(TWindow* parent = 0);
    virtual ~TMyOcxDialog();

  public:// virtual functions of TWindow
    void SetupWindow();
    void Paint(TDC&, bool, TRect&);

  public:// Ctrl event specific messages
    bool EvOcCtrlCustomEvent(TCtrlCustomEvent* pev);

  public:// Dialog Control response functions
    void EvGraphMode();

  public:// Implement OLE functionality
    HRESULT GetDispID(IDispatch* pDispatch, char* name, DISPID& dispid);
    HRESULT InvokeMethod(IDispatch* pDispatch, char* name,TVariantArg& result);
    HRESULT InvokeMethod(IDispatch* pDispatch, char* name,TVariantArg& varg, TVariantArg& result);
    HRESULT InvokeMethod(IDispatch* pDispatch, char* name,TVariantArg* arrayVarg, int paramCount,TVariantArg& result);
    HRESULT InvokeGet(IDispatch* pDispatch, char* name, TVariantArg& result);
    HRESULT InvokePut(IDispatch* pDispatch, char* name, TVariantArg& param);

  // Data -------------------------------------------------------------------
  private:
    TOcControl* ptrTable;
    TOcControl* ptrGraph;
    IDispatch* ptrTableDisp;
    IDispatch* ptrGraphDisp;

  DECLARE_RESPONSE_TABLE(TMyOcxDialog);

};


#endif  // _OCXDLG_H sentry.
