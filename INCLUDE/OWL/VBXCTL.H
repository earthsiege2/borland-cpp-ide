//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   include\owl\vbxctl.h
//   Defines TVbxControl and associated classes
//----------------------------------------------------------------------------
#if !defined(__OWL_VBXCTL_H)
#define __OWL_VBXCTL_H

#if !defined(__OWL_CONTROL_H)
  #include <owl\control.h>
#endif
#if !defined(__BIVBX_H)
  #include <bivbx.h>
#endif

//
//  class TBIVbxLibrary
//  ----- -------------
//
class _OWLCLASS TBIVbxLibrary : virtual public TModule {
  public:
    TBIVbxLibrary();
   ~TBIVbxLibrary();
};
  
//
//  class TVbxEventHandler
//  ----- ----------------
//
class _OWLCLASS TVbxEventHandler : virtual public TEventHandler {
  protected:
    LRESULT  EvVbxDispatch(WPARAM wp, LPARAM lp);

  DECLARE_RESPONSE_TABLE(TVbxEventHandler);
};

//
//  class TVbxControl
//  ----- -----------
//
class _OWLCLASS TVbxControl : public TControl, public TVbxEventHandler {
  public:
    TVbxControl(TWindow*        parent,
                int             id,
                const char far* vbxName,
                const char far* vbxClass,
                const char far* title,
                int             x,
                int             y,
                int             w,
                int             h,
                long            initLen = 0,
                void far*       initData = 0,
                TModule*        module = 0);

    TVbxControl(TWindow* parent, int resourceId, TModule* module = 0);
   ~TVbxControl();

    void SetupWindow();

    LRESULT EvDefaultProcessing(WPARAM, LPARAM) { return DefaultProcessing(); }

    // properties
    int GetNumProps();
    int GetPropIndex(const char far* name);
    const char far* GetPropName(int propIndex);
    int GetPropType(int propIndex);
    int GetPropType(char far* name);
    BOOL IsArrayProp(int propIndex);
    BOOL IsArrayProp(char far* name);

    // get properties by index
    BOOL GetProp(int propIndex, int& value, int arrayIndex=-1);
    BOOL GetProp(int propIndex, long& value, int arrayIndex=-1);
    BOOL GetProp(int propIndex, ENUM& value, int arrayIndex=-1);
    BOOL GetProp(int propIndex, HPIC& value, int arrayIndex=-1);
    BOOL GetProp(int propIndex, float& value, int arrayIndex=-1);
    BOOL GetProp(int propIndex, string& value, int arrayIndex=-1);
    BOOL GetProp(int propIndex, COLORREF& value, int arrayIndex=-1);

    // get properties by name
    BOOL GetProp(const char far* name, int& value, int arrayIndex=-1);
    BOOL GetProp(const char far* name, long& value, int arrayIndex=-1);
    BOOL GetProp(const char far* name, ENUM& value, int arrayIndex=-1);
    BOOL GetProp(const char far* name, HPIC& value, int arrayIndex=-1);
    BOOL GetProp(const char far* name, float& value, int arrayIndex=-1);
    BOOL GetProp(const char far* name, string& value, int arrayIndex=-1);
    BOOL GetProp(const char far* name, COLORREF& value, int arrayIndex=-1);

    // set properties by index
    BOOL SetProp(int propIndex, int value, int arrayIndex=-1);
    BOOL SetProp(int propIndex, long value, int arrayIndex=-1);
    BOOL SetProp(int propIndex, ENUM value, int arrayIndex=-1);
    BOOL SetProp(int propIndex, HPIC value, int arrayIndex=-1);
    BOOL SetProp(int propIndex, float value, int arrayIndex=-1);
    BOOL SetProp(int propIndex, const string& value, int arrayIndex=-1);
    BOOL SetProp(int propIndex, const char far* value, int arrayIndex=-1);
    BOOL SetProp(int propIndex, COLORREF value, int arrayIndex=-1);

    // set properties by name
    BOOL SetProp(const char far* name, int value, int arrayIndex=-1);
    BOOL SetProp(const char far* name, long value, int arrayIndex=-1);
    BOOL SetProp(const char far* name, ENUM value, int arrayIndex=-1);
    BOOL SetProp(const char far* name, HPIC value, int arrayIndex=-1);
    BOOL SetProp(const char far* name, float value, int arrayIndex=-1);
    BOOL SetProp(const char far* name, const string& value, int arrayIndex=-1);
    BOOL SetProp(const char far* name, const char far* value, int arrayIndex=-1);
    BOOL SetProp(const char far*, COLORREF value, int arrayIndex=-1);

    // events
    int GetNumEvents();
    int GetEventIndex(const char far* name);
    const char far* GetEventName(int eventIndex);
    
    // methods
    BOOL Method(int method, long far* args);
    BOOL AddItem(int index, const char far* item);
    BOOL Drag(int action);
    BOOL Move(long x, long y, long w, long h);
    BOOL Refresh();
    BOOL RemoveItem(int index);
    
    // control
    HCTL GetHCTL() {return HCtl;}

  protected:
    char far* GetClassName();
    void PerformCreate(int menuOrId);
    BOOL GetVBXProperty(int propIndex, void far *value, int arrayIndex=-1);
    BOOL SetVBXProperty(int propIndex, LONG value, int arrayIndex=-1);
    
  private:
    HCTL HCtl;
    char far* VbxName;
    char far* VbxClass;
    long InitLen;
    void far* InitData;

  DECLARE_RESPONSE_TABLE(TVbxControl);
  DECLARE_CASTABLE;
};


//
// Response table macros for VBX events
//
#define EV_VBXEVENTNAME(id,name,method)\
  {WM_VBXNAME,id,(TAnyDispatcher)name,(TMyPMF)VbxSig(&TMyClass::method)}

#define EV_VBXEVENTINDEX(id,event,method)\
  {WM_VBXBASE+event,id,(TAnyDispatcher)::i_LPARAM_Dispatch,\
  (TMyPMF)VbxSig(&TMyClass::method)}

//
// WM_VBXFIREEVENT signature template
//
template <class T>
inline void(T::*VbxSig(void(T::*pmf)(VBXEVENT FAR*))) (VBXEVENT FAR*)
{
  return pmf;
}

//
//  VBXDispatch - dispatch function to crack a WM_VBXFIREEVENT message and
//  pass control to a pointer to member function.
//
LRESULT
VBXDispatch(GENERIC& generic,
            void    (GENERIC::*pmf)(VBXEVENT FAR*),
            WPARAM   wParam,
            LPARAM   lParam);

          
//
// TVbxControl Inlines
//

inline int TVbxControl::GetNumProps()
{
  return ::VBXGetNumProps(HCtl);
}

inline int TVbxControl::GetPropIndex(const char far* name)
{
  return ::VBXGetPropIndex(HCtl, name);
}

inline const char far* TVbxControl::GetPropName(int propIndex)
{
  return ::VBXGetPropName(HCtl, propIndex);
}

inline int TVbxControl::GetPropType(int propIndex)
{
  return ::VBXGetPropType(HCtl, propIndex);
}

inline int TVbxControl::GetPropType(char far* name)
{
  return GetPropType(GetPropIndex(name));
}

inline BOOL TVbxControl::IsArrayProp(int propIndex)
{
  return ::VBXIsArrayProp(HCtl, propIndex);
}

inline BOOL TVbxControl::IsArrayProp(char far* name)
{
  return IsArrayProp(GetPropIndex(name));
}


// get properties by id

inline BOOL 
TVbxControl::GetProp(int propIndex, int& value, int arrayIndex)
{
  return GetVBXProperty(propIndex, &value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(int propIndex, long& value, int arrayIndex)
{
  return GetVBXProperty(propIndex, &value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(int propIndex, ENUM& value, int arrayIndex)
{
  BOOL rv;
  short temp;
  rv = GetVBXProperty(propIndex, &temp, arrayIndex);
  value = (ENUM) temp;
  return rv;
}

inline BOOL 
TVbxControl::GetProp(int propIndex, HPIC& value, int arrayIndex)
{
  return GetVBXProperty(propIndex, &value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(int propIndex, float& value, int arrayIndex)
{
  return GetVBXProperty(propIndex, &value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(int propIndex, COLORREF& value, int arrayIndex)
{
  return GetVBXProperty(propIndex, &value, arrayIndex);
}

// get properties by name

inline BOOL 
TVbxControl::GetProp(const char far* name, int& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(const char far* name, long& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(const char far* name, ENUM& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(const char far* name, HPIC& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(const char far* name, float& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(const char far* name, string& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

inline BOOL 
TVbxControl::GetProp(const char far* name, COLORREF& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

// set properties by id

inline BOOL 
TVbxControl::SetProp(int propIndex, int value, int arrayIndex)
{
  return SetVBXProperty(propIndex, value, arrayIndex);
}

inline BOOL 
TVbxControl::SetProp(int propIndex, long value, int arrayIndex)
{
  return SetVBXProperty(propIndex, value, arrayIndex);
}

inline BOOL 
TVbxControl::SetProp(int propIndex, HPIC value, int arrayIndex)
{
  return SetVBXProperty(propIndex, value, arrayIndex);
}

inline BOOL 
TVbxControl::SetProp(int propIndex, ENUM value, int arrayIndex)
{
  return SetVBXProperty(propIndex, (long)value, arrayIndex);
}

inline BOOL
TVbxControl::SetProp(int propIndex, float value, int arrayIndex)
{
  return SetVBXProperty(propIndex, *((long*)&value), arrayIndex);
}

inline BOOL
TVbxControl::SetProp(int propIndex, const string& value, int arrayIndex)
{
  return SetVBXProperty(propIndex, long(value.c_str()), arrayIndex);
}

inline BOOL
TVbxControl::SetProp(int propIndex, const char far* value, int arrayIndex)
{
  return SetVBXProperty(propIndex, (long)value, arrayIndex);
}

inline BOOL
TVbxControl::SetProp(int propIndex, COLORREF value, int arrayIndex)
{
  return SetVBXProperty(propIndex, (long)value, arrayIndex);
}

// set properties by name

inline BOOL
TVbxControl::SetProp(const char far* name, int value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

inline BOOL 
TVbxControl::SetProp(const char far* name, long value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

inline BOOL 
TVbxControl::SetProp(const char far* name, ENUM value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

inline BOOL 
TVbxControl::SetProp(const char far* name, HPIC value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

inline BOOL 
TVbxControl::SetProp(const char far* name, float value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

inline BOOL 
TVbxControl::SetProp(const char far* name, const string& value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value.c_str());
}

inline BOOL 
TVbxControl::SetProp(const char far* name, const char far* value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

inline BOOL 
TVbxControl::SetProp(const char far* name, COLORREF value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}


inline int 
TVbxControl::GetNumEvents()
{
  return ::VBXGetNumEvents(HCtl);
}

inline int 
TVbxControl::GetEventIndex(const char far* name)
{
  return ::VBXGetEventIndex(HCtl, name);
}

inline const char far*
TVbxControl::GetEventName(int eventIndex)
{
  return ::VBXGetEventName(HCtl, eventIndex);
}

inline BOOL 
TVbxControl::Method(int method, long far* args)
{
  return ::VBXMethod(HCtl, method, args);
}

inline BOOL 
TVbxControl::AddItem(int index, const char far* item)
{
  return ::VBXMethodAddItem(HCtl, index, item);
}

inline BOOL
TVbxControl::Drag(int action)
{
  return ::VBXMethodDrag(HCtl, action);
}

inline BOOL
TVbxControl::Move(long x, long y, long w, long h)
{
  return ::VBXMethodMove(HCtl, x, y, w, h);
}

inline BOOL
TVbxControl::Refresh()
{
  return ::VBXMethodRefresh(HCtl);
}

inline BOOL
TVbxControl::RemoveItem(int index)
{
  return ::VBXMethodRemoveItem(HCtl, index);
}

#endif  // __OWL_VBXCTL_H
