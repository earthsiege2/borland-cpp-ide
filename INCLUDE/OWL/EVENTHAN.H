//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   TEventHandler and related classes & macros
//----------------------------------------------------------------------------
#if !defined(OWL_EVENTHAN_H)
#define OWL_EVENTHAN_H

#if !defined(OWL_SIGNATUR_H)
# include <owl/signatur.h>
#endif
#if !defined(OWL_DISPATCH_H)
# include <owl/dispatch.h>
#endif

#if defined(__TRACE) || defined(__WARN)
  //
  // class/operator which converts a Windows message to its string equivalent
  //
  class _EXPCLASS ostream;
  class _OWLCLASS MsgName {
    public:
      friend ostream& operator <<(ostream& os, const MsgName& msg);
      MsgName(uint msg) : Message(msg) {}
    private:
      uint Message;
  };
#endif

#if defined(OWLRTFAR)
# define __RTFAR  far
#else
# define __RTFAR
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
#define WM_VBXINITFORM    (WM_OWLLAST - 7)
#define WM_VBXNAME        (WM_OWLLAST - 8)
#define WM_VBXBASE        (WM_OWLLAST - 8 - 256)
#define WM_OWLWAKEUP      (WM_VBXBASE - 1)

template <class T> class TResponseTableEntry;  // forward declaration
typedef TResponseTableEntry<GENERIC>  TGenericTableEntry;

//
//  class TEventHandler
//  ----- -------------
//  base class from which to derive classes that can handle events
//
class _OWLCLASS _RTTI TEventHandler {
  public:
    class TEventInfo {
      public:
        const uint                  Msg;
        const uint                  Id;
        GENERIC*                    Object;
        TGenericTableEntry __RTFAR* Entry;

        TEventInfo(uint msg, uint id = 0) : Msg(msg), Id(id) {Entry = 0;}
    };
    typedef bool(*TEqualOperator)(TGenericTableEntry __RTFAR&, TEventInfo&);

    //
    // searches the list of response table entries looking for a match
    //
    // since class TEventHandler doesn't have any entries, this routine just
    // returns false
    //
    virtual bool     Find(TEventInfo& info, TEqualOperator op = 0);

    virtual LRESULT  Dispatch(TEventInfo& info, WPARAM wp, LPARAM lp = 0);

  protected:
    bool             SearchEntries(TGenericTableEntry __RTFAR* entries,
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
      uint          Msg;
      uint          NotifyCode;
    };
    uint            Id;
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
    bool  Find(TEventInfo&, TEqualOperator = 0)

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
  bool  cls::Find(TEventInfo& eventInfo, TEqualOperator equal)\
      {eventInfo.Object = (GENERIC*)this;\
       return SearchEntries((TGenericTableEntry __RTFAR*)__entries, eventInfo, equal);}\
  DEFINE_RESPONSE_TABLE_ENTRIES(cls)

//
// macro to define a response table for a class with one base. use this macro
// exactly like macro DEFINE_RESPONSE_TABLE
//
#define DEFINE_RESPONSE_TABLE1(cls, base)\
  bool  cls::Find(TEventInfo& eventInfo, TEqualOperator equal)\
      {eventInfo.Object = (GENERIC*)this;\
       return SearchEntries((TGenericTableEntry __RTFAR*)__entries, eventInfo, equal) ||\
              base::Find(eventInfo, equal);}\
  DEFINE_RESPONSE_TABLE_ENTRIES(cls)

//
// macro to define a response table for a class with two bases. use this macro
// exactly like macro DEFINE_RESPONSE_TABLE
//
#define DEFINE_RESPONSE_TABLE2(cls, base1, base2)\
  bool  cls::Find(TEventInfo& eventInfo, TEqualOperator equal)\
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
  bool  cls::Find(TEventInfo& eventInfo, TEqualOperator equal)\
      {eventInfo.Object = (GENERIC*)this;\
       return SearchEntries((TGenericTableEntry __RTFAR*)__entries, eventInfo, equal) ||\
              base1::Find(eventInfo, equal) ||\
              base2::Find(eventInfo, equal) ||\
              base3::Find(eventInfo, equal);}\
  DEFINE_RESPONSE_TABLE_ENTRIES(cls)

#endif  // OWL_EVENTHAN_H
