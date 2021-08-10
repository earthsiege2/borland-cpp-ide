//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\eventhan.h
//   TEventHandler and related classes & macros
//----------------------------------------------------------------------------
#if !defined(__OWL_EVENTHAN_H)
#define __OWL_EVENTHAN_H

#include <limits.h>
#include <owl\signatur.h>
#include <owl\dispatch.h>

#if defined(__TRACE) || defined(__WARN)
  //
  // class/operator which converts a Windows message to its string equivalent
  //
  class _EXPCLASS ostream;
  class _OWLCLASS MsgName {
    public:
      friend ostream& operator <<(ostream& os, const MsgName& msg);
      MsgName(UINT msg) : Message(msg) {}
    private:
      UINT Message;
  };
#endif

#if defined(OWLRTFAR)
  #define __RTFAR  far
#else
  #define __RTFAR
#endif

//
// messages defined for OWL use - the top of the user range of ids is reserved
//
#define WM_OWLLAST        0x7FFF
#define WM_OWLFIRST       (WM_OWLLAST - 0x03FF)

#define WM_COMMAND_ENABLE (WM_OWLLAST - 0)
#define WM_CHILDINVALID   (WM_OWLLAST - 1)
#define WM_OWLDOCUMENT    (WM_OWLLAST - 2)
#define WM_OWLVIEW        (WM_OWLLAST - 3)
#define WM_OWLNOTIFY      (WM_OWLLAST - 4)
#define WM_OWLPREPROCMENU (WM_OWLLAST - 5)
#define WM_OWLCANCLOSE    (WM_OWLLAST - 6)
#define WM_VBXNAME        (WM_OWLLAST - 7)
#define WM_VBXBASE        (WM_OWLLAST - 7 - 256)

template <class T> class TResponseTableEntry;  // forward declaration
typedef TResponseTableEntry<GENERIC>  TGenericTableEntry;

//
//  class TEventHandler
//  ----- -------------
//  base class from which to derive classes that can handle events
//
class _OWLCLASS __rtti TEventHandler {
  public:
    class TEventInfo {
      public:
        const UINT                  Msg;
        const UINT                  Id;
        GENERIC*                    Object;
        TGenericTableEntry __RTFAR* Entry;

        TEventInfo(UINT msg, UINT id = 0) : Msg(msg), Id(id) {Entry = 0;}
    };
    typedef BOOL(*TEqualOperator)(TGenericTableEntry __RTFAR&, TEventInfo&);

    //
    // searches the list of response table entries looking for a match
    //
    // since class TEventHandler doesn't have any entries, this routine just
    // returns FALSE
    //
    virtual BOOL     Find(TEventInfo& info, TEqualOperator op = 0);

    virtual LRESULT  Dispatch(TEventInfo& info, WPARAM wp, LPARAM lp = 0);

  protected:
    BOOL             SearchEntries(TGenericTableEntry __RTFAR* entries,
                                   TEventInfo& info,
                                   TEqualOperator op);
};

//
//  template class TResponseTableEntry
//  -------- ----- -------------------
//  entries into a response table
//
template <class T> class TResponseTableEntry {
  public:
    typedef void (T::*PMF)();

    union {
      UINT          Msg;
      UINT          NotifyCode;
    };
    UINT            Id;
    TAnyDispatcher  Dispatcher;
    PMF             Pmf;
};

//
// macros to declare a response table
//
#define DECLARE_RESPONSE_TABLE(cls)\
  private:\
    static TResponseTableEntry< cls > __RTFAR __entries[];\
    typedef TResponseTableEntry< cls >::PMF   TMyPMF;\
    typedef cls                               TMyClass;\
  public:\
    BOOL  Find(TEventInfo&, TEqualOperator = 0)

#define END_RESPONSE_TABLE\
  {0, 0, 0, 0}}

#define DEFINE_RESPONSE_TABLE_ENTRIES(cls)\
  TResponseTableEntry< cls > __RTFAR  cls::__entries[] = {

//
// macro to define a response table for a class with no base response tables
//
// you use it like this:
//    DEFINE_RESPONSE_TABLE(cls)
//      EV_WM_PAINT,
//      EV_WM_LBUTTONDOWN,
//    END_RESPONSE_TABLE;
//
#define DEFINE_RESPONSE_TABLE(cls)\
  BOOL  cls::Find(TEventInfo& eventInfo, TEqualOperator equal)\
      {eventInfo.Object = (GENERIC*)this;\
       return SearchEntries((TGenericTableEntry __RTFAR*)__entries, eventInfo, equal);}\
  DEFINE_RESPONSE_TABLE_ENTRIES(cls)

//
// macro to define a response table for a class with one base. use this macro
// exactly like macro DEFINE_RESPONSE_TABLE
//
#define DEFINE_RESPONSE_TABLE1(cls, base)\
  BOOL  cls::Find(TEventInfo& eventInfo, TEqualOperator equal)\
      {eventInfo.Object = (GENERIC*)this;\
       return SearchEntries((TGenericTableEntry __RTFAR*)__entries, eventInfo, equal) ||\
              base::Find(eventInfo, equal);}\
  DEFINE_RESPONSE_TABLE_ENTRIES(cls)

//
// macro to define a response table for a class with two bases. use this macro
// exactly like macro DEFINE_RESPONSE_TABLE
//
#define DEFINE_RESPONSE_TABLE2(cls, base1, base2)\
  BOOL  cls::Find(TEventInfo& eventInfo, TEqualOperator equal)\
      {eventInfo.Object = (GENERIC*)this;\
       return SearchEntries((TGenericTableEntry __RTFAR*)__entries, eventInfo, equal) ||\
              base1::Find(eventInfo, equal) ||\
              base2::Find(eventInfo, equal);}\
  DEFINE_RESPONSE_TABLE_ENTRIES(cls)

//
// macro to define a response table for a class with three bases. use this macro
// exactly like macro DEFINE_RESPONSE_TABLE
//
#define DEFINE_RESPONSE_TABLE3(cls, base1, base2, base3)\
  BOOL  cls::Find(TEventInfo& eventInfo, TEqualOperator equal)\
      {eventInfo.Object = (GENERIC*)this;\
       return SearchEntries((TGenericTableEntry __RTFAR*)__entries, eventInfo, equal) ||\
              base1::Find(eventInfo, equal) ||\
              base2::Find(eventInfo, equal) ||\
              base3::Find(eventInfo, equal);}\
  DEFINE_RESPONSE_TABLE_ENTRIES(cls)

#endif  // __OWL_EVENTHAN_H
