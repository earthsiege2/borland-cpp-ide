#ifndef __PROPVIEW_H
#define __PROPVIEW_H

#include <ideaddon\iview.h>

/******************************************************************************
*
*
* PropertyViewFactory
*
*
******************************************************************************/
class PropertyViewFactory : public IUserViewFactory {
public:

  PropertyViewFactory(IViewType* viewType);

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


#endif // __PROPVIEW_H
