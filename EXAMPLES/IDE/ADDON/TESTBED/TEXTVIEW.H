#ifndef __TEXTVIEW_H
#define __TEXTVIEW_H

#include <ideaddon\iview.h>

/******************************************************************************
*
*
* TextViewFactory
*
*
******************************************************************************/
class TextViewFactory : public IUserViewFactory {
public:

  TextViewFactory();

  //IUnknown members
  STDMETHODIMP QueryInterface (THIS_ REFIID, LPVOID FAR *);
  STDMETHODIMP_(ULONG) AddRef (THIS) { return m_RefCount++; }
  STDMETHODIMP_(ULONG) Release (THIS) 
      {return --m_RefCount == 0 ? (delete this, 0) : m_RefCount; }

  virtual IViewClient * CreateView(IViewParentWnd* wndServer,
                                    void * restoreData);
  virtual void InitializeProperty(IViewType* viewType);

protected:
  // private variables
  ULONG    m_RefCount;
};


#endif // __TEXTVIEW_H
