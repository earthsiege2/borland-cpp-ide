//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Declares THelpContext and THelpFileManager.
//----------------------------------------------------------------------------
#if !defined(OWL_HLPMANAG_H)
#define OWL_HLPMANAG_H

#if defined(BI_PLAT_WIN16)
# error Help manager is defined only in Win32
#else

#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif

#if !defined(CLASSLIB_DLISTIMP_H)
# include <classlib/dlistimp.h>
#endif

class _OWLCLASS THelpContext;
class _OWLCLASS TWindow;

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// class THelpContext
// ~~~~~ ~~~~~~~~~~~~
// THelpContext is a class that maintains information about a menu item id and
// a child control id with a help context id.
// As particular windows get and lose focus, their context tables are removed
// from a global context table.
//
class _OWLCLASS THelpContext {
  public:
    THelpContext();
    THelpContext(TWindow* window, int helpId, int menuId, int controlId);
    THelpContext(const THelpContext&);
   ~THelpContext();

    THelpContext& operator =(const THelpContext&);
    int operator ==(const THelpContext&) const;

    int GetHelpFileContextId() const;
    int GetMenuContextId() const;
    int GetControlContextId() const;
    TWindow* GetWindow() const;
    void SetWindow(TWindow* window);

  private:
    int HelpFileContextId;
    int MenuContextId;
    int ControlContextId;
    TWindow* Window;
};

//
// class THelpFileManager
// ~~~~~ ~~~~~~~~~~~~~~~~
// The global context table is used by THelpFileManager, which is designed to
// be a mixin for TApplication.
// THelpFileManager looks for the WM_HELP message and calls the help file
// with the associated context id.
//
class _OWLCLASS THelpFileManager : virtual public TEventHandler {
  public:
    THelpFileManager(const string& helpFileName);
    virtual ~THelpFileManager();

    virtual void ActivateHelp(TWindow*, int helpFileContextId);
    virtual void DeactivateHelp();

    void   SetHelpFile(const string& helpFileName);
    string GetHelpFile() const;

    bool GetHelpContextFromControl(THelpContext&, int controlId, HWND ctrl) const;
    bool GetHelpContextFromMenu(THelpContext&, int menuId) const;

    void AddContextInfo(TWindow*, int helpId, int menuId, int controlId);
    void RemoveContextInfo(TWindow*);

  protected:
    void EvHelp(HELPINFO*);

  private:
    typedef TDoubleListImp<THelpContext> TContextList;
    typedef TDoubleListIteratorImp<THelpContext> TContextListIterator;
    TContextList* ContextTable;

    string HelpFileName;

  DECLARE_RESPONSE_TABLE(THelpFileManager);
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Macros to simplify usage of THelpContext
//

#if defined(OWLHCFAR)
# define __HCFAR __far
#else
# define __HCFAR
#endif

#define DECLARE_HELPCONTEXT(cls)               \
    static THelpContext __HCFAR __hcEntries[]

#define DEFINE_HELPCONTEXT(cls)\
  THelpContext __HCFAR cls::__hcEntries[] = {

#define END_HELPCONTEXT        \
    {THelpContext(0, 0, 0, 0)} \
  }

#define HCENTRY_MENU(hcId, menuId)                    \
  {THelpContext(0, hcId, menuId, 0)}

#define HCENTRY_CONTROL(hcId, ctlId)                  \
  {THelpContext(0, hcId, 0, ctlId)}

#define HCENTRY_MENU_AND_CONTROL(hcId, menuId, ctlId) \
  {THelpContext(0, hcId, menuId, ctlId)}

#define SETUP_HELPCONTEXT(appCls, cls)                                  \
  {                                                                     \
    appCls* app = TYPESAFE_DOWNCAST(GetApplication(), appCls);          \
    if (app) {                                                          \
      for (THelpContext* hc = &__hcEntries[0]; !IsLastIndirectContext(*hc); hc++) { \
        app->AddContextInfo(this,                                       \
                            hc->GetHelpFileContextId(),                 \
                            hc->GetMenuContextId(),                     \
                            hc->GetControlContextId());                 \
      }                                                                 \
    }                                                                   \
  }

#define CLEANUP_HELPCONTEXT(appCls, cls)                          \
  {                                                               \
    appCls* app = TYPESAFE_DOWNCAST(GetApplication(), appCls);    \
    if (app)                                                      \
      app->RemoveContextInfo(this);                               \
  }

const int TablePtr = -1;

//----------------------------------------------------------------------------
// Inline implementations
//

//
// Return true if the context entry is a pointer to another table.
//
inline bool
IsIndirectHelpContext(const THelpContext& context)
{
  if (context.GetMenuContextId() == TablePtr &&
      context.GetHelpFileContextId() == TablePtr &&
      context.GetControlContextId() == TablePtr)
    return true;
  return false;
}

//
// Return true if this entry is the last entry.
//
inline bool
IsLastIndirectContext(const THelpContext& context)
{
  if (context.GetMenuContextId() == 0 &&
      context.GetHelpFileContextId() == 0 &&
      context.GetControlContextId() == 0)
    return true;
  return false;
}

//
// Return the name of the help file.
//
inline string
THelpFileManager::GetHelpFile() const
{
  return HelpFileName;
}

//
// Return the help file context id for the context entry.
//
inline int
THelpContext::GetHelpFileContextId() const
{
  return HelpFileContextId;
}

//
// Return the menu id for this context entry.
//
inline int
THelpContext::GetMenuContextId() const
{
  return MenuContextId;
}

//
// Return the child control id for this context entry.
//
inline int
THelpContext::GetControlContextId() const
{
  return ControlContextId;
}

//
// Return the window this entry is associated with.
//
inline TWindow*
THelpContext::GetWindow() const
{
  return Window;
}

//
// Sets the window for this context entry.
//
inline void
THelpContext::SetWindow(TWindow* window)
{
  Window = window;
}

#endif  // Win32

#endif  // OWL_HLPMANAG_H
