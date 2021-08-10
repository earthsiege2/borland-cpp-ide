/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  comhelp.h
  Created: 10/20/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef __COMHELP_H
#define __COMHELP_H

#include <windows.h>
#include <objbase.h>
#include <ideaddon\iide.h>
#include <ideaddon\ivfile.h>
#include <ideaddon\iview.h>
#include <ideaddon\ipolystr.h>

//
// helper functions in comhelp.cpp
//

// Manage the IdeServer instance pointer and get various interfaces from it
extern void SetIdeServer( IIdeServer * pIdeServer );
extern IIdeServer * GetIdeServer( void );  // does an addref
extern void ReleaseIdeServer( void );
extern IUnknown * GetInterface ( REFCLSID rclsid );

// These 3 call the IdeServer to make unique instances
extern IPolyString  * CreatePolyString();
extern IVirtualFile * CreateVirtualFile();
extern IViewType   * CreateViewType();

// Poly string helpers
extern IPolyString  * MakePolyString( const char * cstr );
extern char *PolyCstrDup ( IPolyString *polystr );

//.............................................................................
// 
// IUnknownImp template
//   Derive from this, passing in an IUnknown-derived type to inherit default
//   IUnknown implementation. For an example see examples\project.h
// 
//.............................................................................
template <class T> 
class IUnknownImp : public T {
 public:
  IUnknownImp( REFIID riid, LPUNKNOWN outerUnk = 0) {
          _iid = riid; _refCount = 1;
          d_outerUnk = outerUnk;
  }

  // IUnknown
  virtual STDMETHODIMP QueryInterface( REFIID riid, LPVOID * ppvObj);
  virtual STDMETHODIMP_(ULONG) AddRef  (THIS);
  virtual STDMETHODIMP_(ULONG) Release (THIS);

 protected:
  IID _iid; 
  ULONG _refCount;
  LPUNKNOWN d_outerUnk;
};


//.............................................................................
//
// Define various helper macros so you can do things such as:
//
//   IToolServer *pToolSrvr = GET_INTERFACE(IToolServer);  // ret NULL if err
//
// instead of the usual:
//
//   IToolServer *pToolSrvr;
//   IIdeServer  *pIdeServer;
//   HRESULT hRes = ::CoCreateInstance ( IID_Addon_IIdeAddon, NULL, 
//                          CLSCTX_INPROC_SERVER, 
//                          IID_IUnknown, (void **) &pIdeServer);
//   hRes = pIdeServer->QueryInterface( IID_Addon_IToolServer, (void **) &pToolSrvr );
//
// SetIdeServer must be called with the IdeServer pointer passed in to 
// BcwAddonEntry() at startup before the first GET_INTERFACE is called. 
// Addon clients should then call ReleaseIdeServer() in the shutdown call
// to BcwAddonEntry() ro release the IdeServer pointer. 
//   
// IUNKNOWNIMPL_INIT( Type )
//   When deriving from IUnknownImpl, use this macro to pass the 
//   the IID reference to the IUnknownImpl constructor.
//
// These macros rely on the IID consisting of "IID_Addon_" + "ClassName"
//
// For example, the poly string class is IPolyString and the IID is
// IID_Addon_IPolyString
//

#define MAKE_IID_NAME(Type) \
      IID_Addon_##Type

#define GET_INTERFACE(Type) \
     (Type *) ::GetInterface( MAKE_IID_NAME(Type) )

#define IUNKNOWNIMPL_INIT( Type ) \
    IUnknownImp< Type > ( MAKE_IID_NAME( Type ) )

#define IUNKNOWNIMPL_INIT2( Type, outerUnk ) \
    IUnknownImp< Type > ( MAKE_IID_NAME( Type ) , outerUnk)

//.............................................................................
template <class T> 
STDMETHODIMP IUnknownImp<T>::QueryInterface( REFIID riid, LPVOID * ppobj ) {
  HRESULT hRes = ResultFromScode( E_NOINTERFACE );
  *ppobj = NULL;

  if ( ( riid == IID_IUnknown ) || ( riid == _iid ) )  {
    *ppobj = (LPVOID) this;
  }

  if ( *ppobj != NULL ) {
    ( (LPUNKNOWN) *ppobj )->AddRef();
    hRes = NOERROR;
  } else if (d_outerUnk) {
   return d_outerUnk->QueryInterface(riid, ppobj);
  }
  return hRes;
}


template <class T> 
STDMETHODIMP_(ULONG) IUnknownImp<T>::AddRef() {
  if (d_outerUnk) {
   d_outerUnk->AddRef();
  }
  return _refCount++;
}

template <class T> 
STDMETHODIMP_(ULONG) IUnknownImp<T>::Release (THIS)  {
  if (d_outerUnk) {
   d_outerUnk->Release();
  }               // mjw - lifetime controlled by shutdown
  return --_refCount == 0 ? (/*delete this,*/ 0) : _refCount;
}



#endif    //  __COMHELP_H
