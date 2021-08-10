
#define CN_BASE 0xBC00 // from CONTROLS.PAS

typedef HWND (__stdcall *TWindowFactoryFunc)(HWND hwndParent, LPUNKNOWN &pObj);

#ifdef OWL_WINDOW_H

class TDelphiFormWrapper: public TWindow
{
public:
  TDelphiFormWrapper(TWindowFactoryFunc factoryFunc,
  	TWindow* parent, const char far* title = 0, TModule* module = 0)
  	: TWindow( parent, title, module ), Factory(factoryFunc), pOleObj(0) { }

protected:
  bool PreProcessMsg( MSG &msg ) {
    // duplicates the code in FORMS.PAS for IsKeyMsg()
    if ((msg.message >= WM_KEYFIRST) && (msg.message <= WM_KEYLAST) &&
      (GetCapture() == 0)) {
      if (SendMessage(CN_BASE + msg.message, msg.wParam, msg.lParam) != 0 )
        return true;
    }
    if (IsDialogMessage( GetHandle(), &msg ))
    	return true;
    return false;
  }
  bool Register() { return true; } // don't bother, Delphi will do this
  void PerformCreate(int menuOrId) {
      LPUNKNOWN pObj;
      SetHandle(Factory(Parent->GetHandle(), pObj));
  }
public:
  LPUNKNOWN pOleObj;
private:
  TWindowFactoryFunc Factory;
};



#endif

#ifdef __AFXWIN_H__

class CDelphiFormWrapper: public CView
{
public:
  CDelphiFormWrapper(TWindowFactoryFunc factoryFunc)
  	: Factory(factoryFunc), pOleObj(0) { }

protected:
  BOOL PreTranslateMessage(LPMSG lpMsg) {
    // duplicates the code in FORMS.PAS for IsKeyMsg()
    if (m_hWnd && (lpMsg->message >= WM_KEYFIRST) && (lpMsg->message <= WM_KEYLAST) &&
      (::GetCapture() == 0)) {
      if (SendMessage(CN_BASE + lpMsg->message, lpMsg->wParam, lpMsg->lParam) != 0 )
        return true;
    }
    return CWnd::PreTranslateMessage(lpMsg);
  }
  virtual void OnDraw(CDC *)
  {
    // do nothing; we should never be called.
  }

public:
  // for child windows, views, panes etc
  BOOL Create(CWnd *pParentWnd)
  {
      Attach( Factory(pParentWnd->m_hWnd, pOleObj) );
      return m_hWnd != NULL;
  }
  afx_msg void OnPaint()
  {
    // don't do CView::OnPaint, we are a control!
    Default();
  }

public:
  LPUNKNOWN pOleObj;
private:
  TWindowFactoryFunc Factory;
};

#endif