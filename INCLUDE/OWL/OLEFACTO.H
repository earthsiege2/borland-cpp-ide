//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.2  $
//
// Templatized class implementation of OLE component creation code for
// TComponentFactory callback for ObjectWindows applications
// All templates assume an AppDictionary global and a Registrar global
// User can provide alternate implementation for any or all of the functions
// The user's derived TApplication class is passed as the template parameter
//
//----------------------------------------------------------------------------
#if !defined(OWL_OLEFACTO_H)
#define OWL_OLEFACTO_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OCF_OLEUTIL_H)
# include <ocf/oleutil.h>
#endif
#if !defined(OCF_OCREG_H)
# include <ocf/ocreg.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//----------------------------------------------------------------------------
// Non-automated application automation callout stub implementation
//

template <class T> struct TOleFactoryNoAuto {
  static void      AutomateApp(T* app, uint32 options);
  static TUnknown* AutomateObject(T* app, const void* obj,const typeinfo& info);
  static void      UnregisterAutomation(T* app);
};

//
template<class T> void
TOleFactoryNoAuto<T>::AutomateApp(T* /*app*/, uint32) {

}

//
template<class T> TUnknown*
TOleFactoryNoAuto<T>::AutomateObject(T*, const void*,const typeinfo&) {
  return 0;
}

//
template<class T> void
TOleFactoryNoAuto<T>::UnregisterAutomation(T* /*app*/) {

}

//----------------------------------------------------------------------------
// Automated application default automation callout implementation
//

template <class T> struct TOleFactoryAuto {
  static void      AutomateApp(T* app, uint32 options);
  static TUnknown* AutomateObject(T* app, const void* obj,const typeinfo& info);
  static void      UnregisterAutomation(T* app);
};

//
// Default callout to aggregate an automation helper to an automated object
//
template <class T> TUnknown*
TOleFactoryAuto<T>::AutomateObject(T* app,const void* obj,const typeinfo& info)
{
  return ::Registrar->CreateAutoObject(obj, info, app, typeid(*app));
}

//
// Default callout to unregister automation active object
//
template <class T> void
TOleFactoryAuto<T>::UnregisterAutomation(T* app)
{
  ::Registrar->ReleaseAutoApp(TAutoObject<T>(app));
}

//
// Default callout to aggregate an automation helper to an automated app
//
template <class T> void
TOleFactoryAuto<T>::AutomateApp(T* app, uint32 options)
{
  ::Registrar->CreateAutoApp(TAutoObjectDelete<T>(app), options);
}

//----------------------------------------------------------------------------
// Application creation/destruction callouts shared for doc/view and non-d/v
//

template<class T, class Auto> struct TOleFactoryAppBase {
  static T*        CreateApp(uint32 options);
  static void      DestroyApp(T* app);
};

//
template<class T, class Auto> T*
TOleFactoryAppBase<T, Auto>::CreateApp(uint32 options)
{
  T* app = new T;
  if ((options & amEmbedding) || !(options & amExeMode))
    app->nCmdShow = SW_HIDE;
  app->OcInit(*::Registrar, options);
  Auto::AutomateApp(app, options);
  app->Start();
  return app;
}

//
template<class T, class Auto>
void TOleFactoryAppBase<T, Auto>::DestroyApp(T* app)
{
  Auto::UnregisterAutomation(app);
  delete app;
}

//----------------------------------------------------------------------------
// Non-docview application callout implementation, no CreateObject implemented
// User must either provide an implementation of CreateOleObject for app class
// or else reimplement this template function for the particular class
//

template<class T, class Auto> struct TOleFactoryNoDocView
                                   : TOleFactoryAppBase<T, Auto> {
  static TUnknown* CreateObject(T* app, uint32 options, TRegLink* link);
};

//
template <class T, class Auto> TUnknown*
TOleFactoryNoDocView<T, Auto>::CreateObject(T* app, uint32 options,
                                            TRegLink* link)
{
  return app->CreateOleObject(options, link);
}

//----------------------------------------------------------------------------
// Docview application callout implementation - supplies CreateObject function
//

template <class T, class Auto> struct TOleFactoryDocView
                                    : TOleFactoryAppBase<T, Auto> {
  static TUnknown* CreateObject(T* app, uint32 options, TRegLink* link);
};

//
template <class T, class Auto> TUnknown*
TOleFactoryDocView<T, Auto>::CreateObject(T* app, uint32 options, TRegLink* link)
{
  TUnknown* obj = 0;
  if (!link)      // if not coming up embedded, we don't know what to make here
    return 0;
  TDocManager* docMan = app->GetDocManager();
  if (!docMan)
    return 0;
  TDocTemplate* tpl = static_cast<TDocTemplate*>(link);
  TDocument* doc = docMan->CreateDoc(tpl, 0, 0, dtNewDoc | dtNoAutoView);
  TView* view = tpl->ConstructView(*doc);
  TOleWindow* ow = TYPESAFE_DOWNCAST(view, TOleWindow);
  if (ow) {
    obj = ow->CreateOcView(tpl, (options & amEmbedding) != 0, 0);
    TUnknown* autoObj;
    void* viewObj = dynamic_cast<void*>(view); // get address of derived most
    void* docObj = dynamic_cast<void*>(doc);
    if ((autoObj = Auto::AutomateObject(app, viewObj, typeid(*view))) != 0 ||
        (autoObj = Auto::AutomateObject(app, docObj,  typeid(*doc)))  != 0) {
      obj->SetOuter(&autoObj->Aggregate(*obj));
      obj->AdjustRefCount(-1);  // remove extra ref count
      obj = autoObj;
      obj->AdjustRefCount(+1);  // add it back to the new outer sub-object
    }
  }
  doc->InitView(view);
  return (options & amEmbedding) ? obj : 0;
}

//----------------------------------------------------------------------------
// Standard factory for OWL components, callouts supplied via template args
//
template <class T, class Obj> class TOleFactoryBase {
  public:
    operator TComponentFactory() {return Create;}
    static IUnknown* Create(IUnknown* outer, uint32 options, uint32 id);
};

/*
//
template <class T, class Obj>
TOleFactoryBase<T, Obj>::operator TComponentFactory()
{
  return Create;
}
*/

//
// Main Create callback function called to create app and/or object
//
template <class T, class Obj> IUnknown*
TOleFactoryBase<T, Obj>::Create(IUnknown* outer, uint32 options, uint32 id)
{
  TRegLink* link = reinterpret_cast<TRegLink*>(id);

  // Look for the app object for this process, creating one if necessary
  //
  TApplication* existingApp = ::AppDictionary.GetApplication();
  T* app;
  if (!existingApp) {
    if (options & amShutdown)   // app already destructed
      return 0;
    app = Obj::CreateApp(options);
    if (!link && !(options & amEmbedding)) {
      Obj::CreateObject(app, options, link);
    }
  } else {
    app = TYPESAFE_DOWNCAST(existingApp, T);
    if (options & amShutdown) {
      Obj::DestroyApp(app);
      return 0;  // any interface present when passed in has now been released
    }
  }
  TUnknown* obj = app->OcApp;   // app's COM interface, used if not doc object

  // If a component ID was passed, make that component, otherwise return app
  //
  if (link) {
    TUnknown* doc = Obj::CreateObject(app, options, link);
    if (doc)
      obj = doc;
    else if (!(options & amEmbedding))  // run DLL in ExeMode from doc factory
      app->OcApp->SetOption(amServedApp, true);
    else
      return 0;  // doc factory failed
  }
  IUnknown* ifc = obj ? obj->SetOuter(outer) : 0; // aggregate to passed outer

  // Run message look if ExeMode, either EXE server or DLL server force to run
  // EXE servers come through here twice, no Run if 2nd pass from factory call
  //
  if (options & amRun)
    app->Run();

  return ifc;
}

//----------------------------------------------------------------------------
//  Factory for OWL non-Doc/View, non-automated OLE components
//
template <class T> class TOleFactory
: public TOleFactoryBase<T, TOleFactoryNoDocView<T, TOleFactoryNoAuto<T> > >
{
};

//
//  Factory for OWL Doc/View, non-automated OLE components
//
template <class T> class TOleDocViewFactory
: public TOleFactoryBase<T, TOleFactoryDocView<T, TOleFactoryNoAuto<T> > >
{
};

//
//  Factory for OWL non-Doc/View, automated OLE components
//
template <class T> class TOleAutoFactory
: public TOleFactoryBase<T, TOleFactoryNoDocView<T, TOleFactoryAuto<T> > >
{
};

//
//  Factory for OWL Doc/View, automated OLE components
//
template <class T> class TOleDocViewAutoFactory
: public TOleFactoryBase<T, TOleFactoryDocView<T, TOleFactoryAuto<T> > >
{
};

//----------------------------------------------------------------------------
//  Factory for OWL automated OLE components, no linking/embedding support
//

template <class T> class TAutoFactory {
  public:
    operator TComponentFactory() {return Create;}

    // Callouts to allow replacement of individual creation steps
    //
    static T*        CreateApp(uint32 options);
    static void      DestroyApp(T* app);

    // Main Create callback function called to create app and/or object
    //
    static IUnknown* Create(IUnknown* outer, uint32 options, uint32 id);
};

/*
//
template <class T>
TAutoFactory<T>::operator TComponentFactory()
{
  return Create;
}
*/

//
// Called when the app is not found and needs to be created
//
template <class T> T*
TAutoFactory<T>::CreateApp(uint32 options)
{
  T* app = new T;
  if ((options & amEmbedding) || !(options & amExeMode))
    app->nCmdShow = SW_HIDE;
  app->Start();
  return app;
}

//
// Called to destroy the application previously created
//
template <class T> void
TAutoFactory<T>::DestroyApp(T* app)
{
  delete app;
}

//
// Main Create callback function called to create app
//
template <class T> IUnknown*
TAutoFactory<T>::Create(IUnknown* outer, uint32 options, uint32 /*id*/)
{
  IUnknown* ifc = 0;
  TApplication* existingApp = ::AppDictionary.GetApplication();
  T* app;
  if (!existingApp) {
    if (options & amShutdown)   // app already destructed
      return 0;
    app = CreateApp(options);
  }
  else {
    app = TYPESAFE_DOWNCAST(existingApp, T);
    if (options & amShutdown) {
      DestroyApp(app);
      return (options & amServedApp) ? 0 : outer;
    }
  }

  if (options & amServedApp) {
    TUnknown* obj = ::Registrar->CreateAutoApp(TAutoObjectDelete<T>(app),
                                               options, outer);
    ifc = *obj;  // does an AddRef, reference count owned by container
  }

  if (options & amRun) {
    app->Run();
  }
  return ifc;
}

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#endif  // OWL_OLEFACTO_H
