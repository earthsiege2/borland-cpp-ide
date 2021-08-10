//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.8  $
//$Revision:   10.8  $
//
// Definition of TVbxControl and associated classes
//----------------------------------------------------------------------------
#if !defined(OWL_VBXCTL_H)
#define OWL_VBXCTL_H
#define __OWL_VBXCTL_H   // Old-style define for VbxGen compatibility

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(__BIVBX_H)
# if defined(BI_PLAT_WIN32) && defined(_INC_DDEMLH)
#   define _HSZ_DEFINED
# endif
# include <bivbx.h>
#endif
#if !defined(BI_PLAT_MSW)
# error VBX supported only under MS Windows
#endif
class _OWLCLASS_RTL TXVbxLibrary;

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// class TBIVbxLibrary
// ~~~~~ ~~~~~~~~~~~~~
class _USERCLASS TBIVbxLibrary {
  public:
    TBIVbxLibrary();
   ~TBIVbxLibrary();

#if defined(OWL2_COMPAT)
    typedef ::TXVbxLibrary TXVbxLibrary;  // Exceptions moved to global scope
#endif
};

//
// class TXVbxLibrary
// ~~~~~ ~~~~~~~~~~~~
class _OWLCLASS_RTL TXVbxLibrary : public TXOwl {
  public:
    TXVbxLibrary();

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXVbxLibrary* Clone();
#endif
    void Throw();

    static void Raise();
};

//
// class TVbxEventHandler
// ~~~~~ ~~~~~~~~~~~~~~~~
class _USERCLASS TVbxEventHandler : virtual public TEventHandler {
  protected:
    TResult  EvVbxDispatch(TParam1 p1, TParam2 p2);
    TResult  EvVbxInitForm(TParam1 p1, TParam2 p2);

  DECLARE_RESPONSE_TABLE(TVbxEventHandler);
};

//
// class TVbxControl
// ~~~~~ ~~~~~~~~~~~
class _USERCLASS TVbxControl : public TControl, public TVbxEventHandler {
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

    // Properties
    //
    int GetNumProps();
    int GetPropIndex(const char far* name);
#if defined(BI_PLAT_WIN16)
    const char far* GetPropName(int propIndex);
#endif
    void GetPropName(int propIndex, string& str);
    int GetPropType(int propIndex);
    int GetPropType(char far* name);
    bool IsArrayProp(int propIndex);
    bool IsArrayProp(char far* name);

    // Get properties by index
    //
    bool GetProp(int propIndex, int& value, int arrayIndex=-1);
    bool GetProp(int propIndex, long& value, int arrayIndex=-1);
#if defined(BI_UNIQUE_BOOL)
    bool GetProp(int propIndex, bool& value, int arrayIndex=-1);
#endif
    bool GetProp(int propIndex, ENUM& value, int arrayIndex=-1);
    bool GetProp(int propIndex, HPIC& value, int arrayIndex=-1);
    bool GetProp(int propIndex, float& value, int arrayIndex=-1);
    bool GetProp(int propIndex, string& value, int arrayIndex=-1);
    bool GetProp(int propIndex, COLORREF& value, int arrayIndex=-1);

    // Get properties by name
    //
    bool GetProp(const char far* name, int& value, int arrayIndex=-1);
    bool GetProp(const char far* name, long& value, int arrayIndex=-1);
#if defined(BI_UNIQUE_BOOL)
    bool GetProp(const char far* name, bool& value, int arrayIndex=-1);
#endif
    bool GetProp(const char far* name, ENUM& value, int arrayIndex=-1);
    bool GetProp(const char far* name, HPIC& value, int arrayIndex=-1);
    bool GetProp(const char far* name, float& value, int arrayIndex=-1);
    bool GetProp(const char far* name, string& value, int arrayIndex=-1);
    bool GetProp(const char far* name, COLORREF& value, int arrayIndex=-1);

    // Set properties by index
    //
    bool SetProp(int propIndex, int value, int arrayIndex=-1);
    bool SetProp(int propIndex, long value, int arrayIndex=-1);
    bool SetProp(int propIndex, ENUM value, int arrayIndex=-1);
    bool SetProp(int propIndex, HPIC value, int arrayIndex=-1);
    bool SetProp(int propIndex, float value, int arrayIndex=-1);
    bool SetProp(int propIndex, const string& value, int arrayIndex=-1);
    bool SetProp(int propIndex, const char far* value, int arrayIndex=-1);
    bool SetProp(int propIndex, COLORREF value, int arrayIndex=-1);

    // Set properties by name
    //
    bool SetProp(const char far* name, int value, int arrayIndex=-1);
    bool SetProp(const char far* name, long value, int arrayIndex=-1);
    bool SetProp(const char far* name, ENUM value, int arrayIndex=-1);
    bool SetProp(const char far* name, HPIC value, int arrayIndex=-1);
    bool SetProp(const char far* name, float value, int arrayIndex=-1);
    bool SetProp(const char far* name, const string& value, int arrayIndex=-1);
    bool SetProp(const char far* name, const char far* value, int arrayIndex=-1);
    bool SetProp(const char far*, COLORREF value, int arrayIndex=-1);

    // Events
    //
    int GetNumEvents();
    int GetEventIndex(const char far* name);
#if defined(BI_PLAT_WIN16)
    const char far* GetEventName(int eventIndex);
#endif
    void GetEventName(int eventIndex, string& str);

    // Methods
    //
    bool AddItem(int index, const char far* item);
    bool Drag(int action);
    bool Move(long x, long y, long w, long h);
    bool Refresh();
    bool RemoveItem(int index);

    // Control
    //
    HCTL GetHCTL();

  protected:
    char far* GetClassName();
    void PerformCreate(int menuOrId);
    bool GetVBXProperty(int propIndex, void far *value, int arrayIndex=-1);
    bool SetVBXProperty(int propIndex, int32 value, int arrayIndex=-1);

  private:
    HCTL      HCtl;
    char far* VbxName;
    char far* VbxClass;
    long      InitLen;
    void far* InitData;

    TResult EvDefaultProcessing(TParam1, TParam2);

  DECLARE_RESPONSE_TABLE(TVbxControl);
  DECLARE_CASTABLE;
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------

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
// VBXDispatch - dispatch function to crack a WM_VBXFIREEVENT message and
// pass control to a pointer to member function.
//
TResult
VBXDispatch(GENERIC& generic,
            void    (GENERIC::*pmf)(VBXEVENT FAR*),
            TParam1  param1,
            TParam2  param2);

//----------------------------------------------------------------------------
// TVbxControl Inlines
//

//
// Retrieve the number of properties in the VBX.
//
inline int TVbxControl::GetNumProps()
{
  return ::VBXGetNumProps(HCtl);
}

//
// Convert the name of the property into an index.
//
inline int TVbxControl::GetPropIndex(const char far* name)
{
  return ::VBXGetPropIndex(HCtl, name);
}

#if defined(BI_PLAT_WIN16)
//
// Retrieve the name of the property at a particular index.
// For portability between 16-bits and 32-bits use the other form of
// GetPropName().
//
inline const char far* TVbxControl::GetPropName(int propIndex)
{
  return ::VBXGetPropName(HCtl, propIndex);
}
#endif

//
// Retrieve the name of the property at a particular index.
//
inline void TVbxControl::GetPropName(int propIndex, string& str)
{
  char buff[64];
  ::VBXGetPropNameBuf(HCtl, propIndex, buff, sizeof buff);
  str = buff;
}

//
// Retrieve the type of the property.
// See PTYPE_XXXX in BIVBX.H.
//
inline int TVbxControl::GetPropType(int propIndex)
{
  return ::VBXGetPropType(HCtl, propIndex);
}

//
// Retrieve the type of the property.
// See PTYPE_XXXX in BIVBX.H.
//
inline int TVbxControl::GetPropType(char far* name)
{
  return GetPropType(GetPropIndex(name));
}

//
// Return true if the property is an array.
//
inline bool TVbxControl::IsArrayProp(int propIndex)
{
  return ::VBXIsArrayProp(HCtl, propIndex);
}

//
// Return true if the property is an array.
//
inline bool TVbxControl::IsArrayProp(char far* name)
{
  return IsArrayProp(GetPropIndex(name));
}


//----------------------------------------------------------------------------
// Get properties by id
//

//
inline bool
TVbxControl::GetProp(int propIndex, int& value, int arrayIndex)
{
#if defined(BI_PLAT_WIN32)
  int16 temp;
  if (GetVBXProperty(propIndex, &temp, arrayIndex)) {
         value = temp;
         return true;
  }
  return false;
#else
  return GetVBXProperty(propIndex, &value, arrayIndex);
#endif
}

//
inline bool
TVbxControl::GetProp(int propIndex, long& value, int arrayIndex)
{
  return GetVBXProperty(propIndex, &value, arrayIndex);
}

#if defined(BI_UNIQUE_BOOL)
//
// Retrieve the boolean property at a particular index.
//
inline bool
TVbxControl::GetProp(int propIndex, bool& value, int arrayIndex)
{
#if defined(BI_PLAT_WIN32)
  int16 temp;
  if (GetVBXProperty(propIndex, &temp, arrayIndex)) {
    value = temp;
    return true;
  }
  return false;
#else
  return GetVBXProperty(propIndex, &value, arrayIndex);
#endif
}
#endif

//
inline bool
TVbxControl::GetProp(int propIndex, ENUM& value, int arrayIndex)
{
  int16 temp;
  bool rv = GetVBXProperty(propIndex, &temp, arrayIndex);
  value = (ENUM)temp;
  return rv;
}

//
inline bool
TVbxControl::GetProp(int propIndex, HPIC& value, int arrayIndex)
{
  return GetVBXProperty(propIndex, &value, arrayIndex);
}

//
inline bool
TVbxControl::GetProp(int propIndex, float& value, int arrayIndex)
{
  return GetVBXProperty(propIndex, &value, arrayIndex);
}

//
inline bool
TVbxControl::GetProp(int propIndex, COLORREF& value, int arrayIndex)
{
  return GetVBXProperty(propIndex, &value, arrayIndex);
}

//----------------------------------------------------------------------------
// Get properties by name
//

#if defined(BI_UNIQUE_BOOL)
//
inline bool
TVbxControl::GetProp(const char far* name, int& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}
#endif

//
inline bool
TVbxControl::GetProp(const char far* name, long& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

//
// Retrieve the boolean property at a particular index.
//
inline bool
TVbxControl::GetProp(const char far* name, bool& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

//
inline bool
TVbxControl::GetProp(const char far* name, ENUM& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

//
inline bool
TVbxControl::GetProp(const char far* name, HPIC& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

//
inline bool
TVbxControl::GetProp(const char far* name, float& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

//
inline bool
TVbxControl::GetProp(const char far* name, string& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

//
inline bool
TVbxControl::GetProp(const char far* name, COLORREF& value, int arrayIndex)
{
  return GetProp(GetPropIndex(name), value, arrayIndex);
}

//----------------------------------------------------------------------------
// Set properties by id
//

//
inline bool
TVbxControl::SetProp(int propIndex, int value, int arrayIndex)
{
  return SetVBXProperty(propIndex, value, arrayIndex);
}

//
inline bool
TVbxControl::SetProp(int propIndex, long value, int arrayIndex)
{
  return SetVBXProperty(propIndex, value, arrayIndex);
}

//
inline bool
TVbxControl::SetProp(int propIndex, HPIC value, int arrayIndex)
{
  return SetVBXProperty(propIndex, value, arrayIndex);
}

//
inline bool
TVbxControl::SetProp(int propIndex, ENUM value, int arrayIndex)
{
  return SetVBXProperty(propIndex, (long)value, arrayIndex);
}

//
inline bool
TVbxControl::SetProp(int propIndex, float value, int arrayIndex)
{
  return SetVBXProperty(propIndex, *((long*)&value), arrayIndex);
}

//
inline bool
TVbxControl::SetProp(int propIndex, const string& value, int arrayIndex)
{
  return SetVBXProperty(propIndex, long(value.c_str()), arrayIndex);
}

//
inline bool
TVbxControl::SetProp(int propIndex, const char far* value, int arrayIndex)
{
  return SetVBXProperty(propIndex, (long)value, arrayIndex);
}

//
inline bool
TVbxControl::SetProp(int propIndex, COLORREF value, int arrayIndex)
{
  return SetVBXProperty(propIndex, (long)value, arrayIndex);
}

//----------------------------------------------------------------------------
// Set properties by name
//

//
inline bool
TVbxControl::SetProp(const char far* name, int value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

//
inline bool
TVbxControl::SetProp(const char far* name, long value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

//
inline bool
TVbxControl::SetProp(const char far* name, ENUM value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

//
inline bool
TVbxControl::SetProp(const char far* name, HPIC value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

//
inline bool
TVbxControl::SetProp(const char far* name, float value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

//
inline bool
TVbxControl::SetProp(const char far* name, const string& value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value.c_str());
}

//
inline bool
TVbxControl::SetProp(const char far* name, const char far* value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

//
inline bool
TVbxControl::SetProp(const char far* name, COLORREF value, int arrayIndex)
{
  return SetProp(GetPropIndex(name), value);
}

//----------------------------------------------------------------------------
//

//
// Return the number of events.
//
inline int
TVbxControl::GetNumEvents()
{
  return ::VBXGetNumEvents(HCtl);
}

//
// Return the index of the event given its name.
//
inline int
TVbxControl::GetEventIndex(const char far* name)
{
  return ::VBXGetEventIndex(HCtl, name);
}

#if defined(BI_PLAT_WIN16)
//
// Retrieve the name of the event at a particular index.
// For portability between 16-bits and 32-bits use the other form of
// GetEventName().
//
inline const char far*
TVbxControl::GetEventName(int eventIndex)
{
  return ::VBXGetEventName(HCtl, eventIndex);
}
#endif

//
// Retrieve the name of the event at a particular index.
//
inline void
TVbxControl::GetEventName(int eventIndex, string& str)
{
  char buff[64];
  ::VBXGetEventNameBuf(HCtl, eventIndex, buff, sizeof buff);
  str = buff;
}

//
inline bool
TVbxControl::AddItem(int index, const char far* item)
{
  return ::VBXMethodAddItem(HCtl, index, item);
}

//
inline bool
TVbxControl::Drag(int action)
{
  return ::VBXMethodDrag(HCtl, action);
}

//
inline bool
TVbxControl::Move(long x, long y, long w, long h)
{
  return ::VBXMethodMove(HCtl, x, y, w, h);
}

//
inline bool
TVbxControl::Refresh()
{
  return ::VBXMethodRefresh(HCtl);
}

//
inline bool
TVbxControl::RemoveItem(int index)
{
  return ::VBXMethodRemoveItem(HCtl, index);
}

//
inline HCTL
TVbxControl::GetHCTL()
{
  return HCtl;
}

#endif  // OWL_VBXCTL_H
