//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Definition of class TUpDown.
//----------------------------------------------------------------------------
#if !defined(OWL_UPDOWN_H)
#define OWL_UPDOWN_H

#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(OWL_BITSET_H)
# include <owl/bitset.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TUDAccel
// ~~~~~ ~~~~~~~~
//  Thin (real thin) wrapper for the UDACCEL structure which contains
//  information about updown accelarators. The main purpose of this
//  class is to have a place-holder for future abstraction/encapsulation.
//
class TUDAccel : public UDACCEL {
};

//
// class TUpDown
// ~~~~~ ~~~~~~~
// TUpDown encapsulates an up-down control, a window with a pair of arrow
// buttons that the user can click to increment or decrement a value.
//
class _OWLCLASS TUpDown : public TControl, public TBitFlags<uint> {
  public:
    TUpDown(TWindow* parent,
            int      id,
            int x, int y, int w, int h,
            TWindow* buddy = 0,
            TModule* module = 0);

    TUpDown(TWindow* parent, int resourceId, TWindow* buddy = 0, TModule* module = 0);

    int           GetAccel(int count, TUDAccel far* accels) const;
    int           GetBase() const;
    HWND          GetBuddy() const;
    int32         GetPos() const;
    uint32        GetRange() const;
    void          GetRange(int& lower, int& upper) const;

    bool          SetAccel(int count, const TUDAccel far* accels);
    int           SetBase(int base);
    HWND          SetBuddy(HWND hBuddy);
    int32         SetPos(int pos);
    void          SetRange(int lower, int upper);

  protected:
    // Override TWindow virtual member functions
    //
    char far*     GetClassName();
    void          PerformCreate(int);
    void          EvVScroll(uint, uint, HWND);
    void          EvHScroll(uint, uint, HWND);

#if !defined(OWL_NATIVECTRL_ALWAYS)

    // Helper routines/members used when ObjectWindows provides the
    // underlying implementation of the UpDown control...

    // Overriden virtual(s) from TWindow
    //
    void          Paint(TDC& dc, bool erase, TRect& rect);
    void          SetupWindow();

    // Message Handlers
    //
    void          EvEnable(bool enabled);
    void          EvShowWindow(bool show, uint status);
    void          EvCancelMode();
    void          EvTimer(uint timerId);
    void          EvLButtonDown(uint modKeys, TPoint& point);
    void          EvLButtonDblClk(uint modKeys, TPoint& point);
    void          EvLButtonUp(uint modKeys, TPoint& point);
    void          EvMouseMove(uint modKeys, TPoint& point);

/*  
    // Maintains internal state of the control
    //
    uint          CtlState;

    void          Set(uint flg);
    void          Clear(uint flg);
    bool          IsSet(uint flg);
*/

    // Enumeration describing the state and attributes of the updown control
    //
    enum TCtlState {
      csGrayed    = 0x0001,         // Control is grayed
      csHidden    = 0x0002,         // Control is hidden
      csMouseOut  = 0x0004,         // Mouse is outside client are
      csIncrement = 0x0008,         // Control's currently incrementing
      csDecrement = 0x0010,         // Control's currently decrementing
      csTimer1On  = 0x0020,         // Initial/delayed timer is enabled
      csTimer2On  = 0x0040          // Repeat/hold timer is enabled
    };

    // Helper routines used by ObjectWindows' implementation
    //
    void          Action();
    void          GetSpinRect(TRect& rect, bool incRect);
    void          GetSpinRectFromState(TRect& rect);
    uint          GetSpinRectFromPoint(TRect& rect, const TPoint& pt);
    void          SetBuddyInt() const;
    void          GetBuddyInt();

  private:
    // Variables used by ObjectWindows' implementaion
    //
    HWND          BuddyHandle;
    int           Base;

#endif  // !OWL_NATIVECTRL_ALWAYS

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TUpDown(const TUpDown&);
    TUpDown& operator =(const TUpDown&);

    // Data members used to hold creation attributes of control
    // NOTE: These variables are not kept in sync with the actual
    //       state of the control when the class makes use of the
    //       CommonControl implementation of 'UPDOWN'
    //
    TWindow*      Buddy;                    // Pointer to buddy window
    int           Lower;                    // Low end of range
    int           Upper;                    // High end of range
    int           Pos;                      // Current/Staring posotion

  DECLARE_RESPONSE_TABLE(TUpDown);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inlines
//

#if defined(OWL_NATIVECTRL_ALWAYS)

// When building OWL to always use the system's implementation of 
// CommonControls, the following methods are mere wrappers around
// the predefined UpDown messages (i.e. UDM_xxxx)
//

// Retrieves acceleration information for the underlying up-down control
//
inline int TUpDown::GetAccel(int count, TUDAccel far* accels) const {
  return (int)CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETACCEL, count, TParam2(accels));
}

// Retrieves the current radix base of the underlying up-down control.
// Return value is either 10 or 16.
//
inline int TUpDown::GetBase() const {
  return (int)CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETBASE);
}

// Retrieves handle if buddy window of underlying up-down control
//
inline HWND TUpDown::GetBuddy() const {
  return (HWND)CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETBUDDY);
}

// Returns current position of underlying up-down control. The high-order
// word in non-zero in case of an error. The current position is in the
// low-order word.
//
inline int32 TUpDown::GetPos() const {
  return (int32)LoUint16(CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETPOS));
}

// Retrieves the minimum and maximum range of the underlying up-down control.
// The low-order word contains the maximum position while the high-order
// word contains the minimum position.
//
inline uint32 TUpDown::GetRange() const {
  return (uint32)CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETRANGE);
}

// Retrieves the minimum and maximum range of the underlying up-down control
// into the specified 'lower' and 'upper' variables respectively.
//
inline void TUpDown::GetRange(int& lower, int& upper) const {
  uint32 ret = CONST_CAST(TUpDown*,this)->SendMessage(UDM_GETRANGE);
  lower = HiUint16(ret);
  upper = LoUint16(ret);
}

// Set the acceleration of the underlying up-down control. 'count' 
// specifies the number of structures specified in 'accels' while the
// latter is the address of an array of TUDAccel structures.
//
inline bool TUpDown::SetAccel(int count, const TUDAccel far* accels) {
  return ToBool(SendMessage(UDM_SETACCEL, count, TParam2(accels)));
}

// Sets the radix of the underlying up-down control. The 'base' parameter
// should be either '10' or '16' for decimal and hexadecimal respectively.
//
inline int TUpDown::SetBase(int base) {
  return int(SendMessage(UDM_SETBASE, base));
}

// Sets the buddy window of the underlying up-down control.
//
inline TWindow::THandle TUpDown::SetBuddy(HWND hBuddy) {
  return TWindow::THandle(SendMessage(UDM_SETBUDDY, TParam1(hBuddy)));
}

// Sets the current position of the underlying up-down control. The
// return value is the previous position.
//
inline int32 TUpDown::SetPos(int pos) {
  return SendMessage(UDM_SETPOS, 0, MkParam2(pos, 0));
}

// Sets the minimum and maximum positions of the up-down control. 
// NOTE: Neither 'lower' nor 'upper' can be greater than UD_MAXVAL or
// less than UD_MINVAL. Futhermore, the difference between the two
// positions must not exceed UD_MAXVAL;
//
inline void TUpDown::SetRange(int lower, int upper) {
  PRECONDITION(lower >= UD_MINVAL);
  PRECONDITION(lower <= UD_MAXVAL);
  PRECONDITION(upper >= UD_MINVAL);
  PRECONDITION(upper <= UD_MAXVAL);
  PRECONDITION(abs(upper-lower) <= UD_MAXVAL);
  SendMessage(UDM_SETRANGE, 0, MkParam2(upper, lower));
}

#endif  // OWL_NATIVECTRL_ALWAYS

/* 
#if !defined(OWL_NATIVECTRL_ALWAYS)
//
inline void TUpDown::Set(uint flg) {
  CtlState |= flg;
}

//
inline void TUpDown::Clear(uint flg) {
  CtlState &= ~flg;
}

//
inline bool TUpDown::IsSet(uint flg) {
  return (CtlState & flg) != 0;
}

#endif  // !OWL_NATIVECTRL_ALWAYS
*/


#endif  // OWL_UPDOWN_H
