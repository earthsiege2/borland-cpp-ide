//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Dispatch functions (crackers) to crack a Windows message and pass control
//   to a member function via a pointer (pmf).
//----------------------------------------------------------------------------
#if !defined(OWL_DISPATCH_H)
#define OWL_DISPATCH_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif

//
// class GENERIC
// ----- -------
// generic class for casting pointer to objects and pointer to member functions
//
class _OWLFASTTHIS GENERIC;   // conditionally define to correct calling model

//
// typedef TAnyPMF
// ------- -------
// generic pointer to member function
//
typedef void (GENERIC::*TAnyPMF)();

//
// typedef TAnyDispatcher
// ------- --------------
// all message dispatcher functions take four parameters:
// - reference to an object
// - pointer to member function (signature varies according to the cracking
//   that the function performs)
// - wParam
// - lParam
//
typedef int32 _OWLFUNC (*TAnyDispatcher)(GENERIC&, TAnyPMF, uint, int32);

//
// LEGEND: in order to keep dispatcher names from getting too long, the
//         following abbreviations are used. The names are based on the data
//         sizes passed & returned, & which param they come from.
//
// - v   (void return)
// - i   (int)
// - U   (uint)
// - H   (HANDLE) (requires special cracking, uint size)
// - I32 (int32)
// - POINT (TPoint&) (TPoint object constructed)
// - POINTER (void*) (model ambient size)
//
// Possible future cracker encoding
//  Which param:
//  - 1  wParam
//  - 2  lParam
//    How cracked (default to no processing, size of param):
//    - U Ambient size uint (squashed lParam in 16bit land)
//    - L Low 16bit word
//    - H high 16bit word
//
// Custom message crackers are named based on the message they crack
//

//----------------------------------------------------------------------------

//
// passes lParam as an int32 and returns an int result
//
int32 _OWLFUNC
i_LPARAM_Dispatch(GENERIC& generic,
                  int     (GENERIC::*pmf)(int32),
                  uint     wParam,
                  int32    lParam);

//
// passes wParam as a uint and returns an int result
//
int32 _OWLFUNC
i_WPARAM_Dispatch(GENERIC& generic,
                  int     (GENERIC::*pmf)(uint),
                  uint     wParam,
                  int32    lParam);

//----------------------------------------------------------------------------

//
// passes nothing and returns an int32 result
//
int32 _OWLFUNC
I32_Dispatch(GENERIC& generic,
             uint32  (GENERIC::*pmf)(),
             uint,
             int32);

//
// passes lParam as an int32 and returns an int32 result
//
int32 _OWLFUNC
I32_LPARAM_Dispatch(GENERIC& generic,
                    int32   (GENERIC::*pmf)(int32),
                    uint,
                    int32    lParam);

//
// passes lParam as a uint and returns an int32 result
//
int32 _OWLFUNC
I32_U_Dispatch(GENERIC& generic,
               int32   (GENERIC::*pmf)(uint),
               uint,
               int32    lParam);

//
// passes wParam as a uint and lParam as an int32 and returns an int32 result
//
int32 _OWLFUNC
I32_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                           int32   (GENERIC::*pmf)(uint, int32),
                           uint     wParam,
                           int32    lParam);

//----------------------------------------------------------------------------

//
// passes no arguments and returns a uint result
//
int32 _OWLFUNC
U_Dispatch(GENERIC& generic,
           uint    (GENERIC::*pmf)(),
           uint     wParam,
           int32    lParam);

//
// passes lParam as an int32 and returns a uint result
//
int32 _OWLFUNC
U_LPARAM_Dispatch(GENERIC& generic,
                  uint    (GENERIC::*pmf)(int32),
                  uint     wParam,
                  int32    lParam);

//
// passes lParam as a TPoint& and returns a uint result
//
int32 _OWLFUNC
U_POINT_Dispatch(GENERIC& generic,
                 uint    (GENERIC::*pmf)(TPoint&),
                 uint,
                 int32    lParam);

//
// passes lParam as a void* and returns a uint result 
//
int32 _OWLFUNC
U_POINTER_Dispatch(GENERIC& generic,
                   uint    (GENERIC::*pmf)(void*),
                   uint,
                   int32    lParam);

//
// passes lParam as a uint and returns a uint result
//
int32 _OWLFUNC
U_U_Dispatch(GENERIC& generic,
             uint    (GENERIC::*pmf)(uint),
             uint,
             int32    lParam);

//
// passes wParam as a uint, lParam.lo as a uint, and lParam.hi as a uint
//
int32 _OWLFUNC
U_U_U_U_Dispatch(GENERIC& generic,
                 uint    (GENERIC::*pmf)(uint, uint, uint),
                 uint     wParam,
                 int32    lParam);

//
// passes wParam as a uint and lParam as an int32 and returns a uint result
//
int32 _OWLFUNC
U_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         uint    (GENERIC::*pmf)(uint, int32),
                         uint     wParam,
                         int32    lParam);

//----------------------------------------------------------------------------

//
// passes nothing and always returns 0
//
int32 _OWLFUNC
v_Dispatch(GENERIC& generic,
           void    (GENERIC::*pmf)(),
           uint,
           int32);

//
// passes lParam as an int32 and always returns 0
//
int32 _OWLFUNC
v_LPARAM_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(int32),
                  uint,
                  int32    lParam);

//
// passes lParam as a TPoint& and always returns 0
//
int32 _OWLFUNC
v_POINT_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(TPoint&),
                 uint,
                 int32    lParam);

//
// passes lParam as a void* and always returns 0
//
int32 _OWLFUNC
v_POINTER_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(void*),
                   uint,
                   int32    lParam);

//
// passes lParam as a uint and always returns 0
//
int32 _OWLFUNC
v_U_Dispatch(GENERIC& generic,
             void    (GENERIC::*pmf)(uint),
             uint,
             int32    lParam);

//
// passes wParam as a uint and lParam as a TPoint& and always returns 0
//
int32 _OWLFUNC
v_U_POINT_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(uint, TPoint&),
                   uint     wParam,
                   int32    lParam);

//
// passes wParam as a uint and lParam as a uint and always returns 0
//
int32 _OWLFUNC
v_U_U_Dispatch(GENERIC& generic,
               void    (GENERIC::*pmf)(uint, uint),
               uint     wParam,
               int32    lParam);

//
// passes wParam as a uint, lParam.lo as a uint, and lParam.hi as a uint and
// always returns 0
//
int32 _OWLFUNC
v_U_U_U_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(uint, uint, uint),
                 uint     wParam,
                 int32    lParam);

//
// passes wParam as a uint and always returns 0
//
int32 _OWLFUNC
v_WPARAM_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(uint),
                  uint     wParam,
                  int32    lParam);

//
// passes wParam as a uint and lParam as an int32 and always returns 0
//
int32 _OWLFUNC
v_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         void    (GENERIC::*pmf)(uint, int32),
                         uint     wParam,
                         int32    lParam);


//----------------------------------------------------------------------------
// Semi-custom crackers

//
// passes a uint, Handle, and uint and returns an int result
// 32-bit: wParam.lo, lParam,    wParam.hi
// 16-bit: wParam,    lParam.lo, lParam.hi
//
int32 _OWLFUNC
i_U_W_U_Dispatch(GENERIC& generic,
                 int     (GENERIC::*pmf)(uint, uint, uint),
                 uint     wParam,
                 int32    lParam);

//
// passes two uints and a HANDLE and always returns 0
// 32-bit passes: wParam.lo, wParam.hi, lParam
// 16-bit passes: wParam,    lParam.lo, lParam.hi (same as v_U_U_U)
//
int32 _OWLFUNC
v_U_U_W_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(uint, uint, uint),
                 uint     wParam,
                 int32    lParam);

//----------------------------------------------------------------------------
// message-specific crackers

//
// cracker for WM_ACTIVATE
// passes a uint, a bool, and an HWND and always returns 0
//
int32 _OWLFUNC
v_Activate_Dispatch(GENERIC& generic,
                    void    (GENERIC::*pmf)(uint, uint, uint),
                    uint     wParam,
                    int32    lParam);

//
// cracker for WM_MDIACTIVATE
// passes two HWNDs and always returns 0
//
int32 _OWLFUNC
v_MdiActivate_Dispatch(GENERIC& generic,
                       void    (GENERIC::*pmf)(uint, uint),
                       uint     wParam,
                       int32    lParam);


//
// cracker for WM_PARENTNOTIFY
// passes two uints and an HWND and returns a 32bit result
//
int32 _OWLFUNC
I32_MenuChar_Dispatch(GENERIC& generic,
                      int32   (GENERIC::*pmf)(uint, uint, uint),
                      uint     wParam,
                      int32    lParam);

//
// cracker for WM_PARENTNOTIFY
// passes three uints and always returns 0
//
int32 _OWLFUNC
v_ParentNotify_Dispatch(GENERIC& generic,
                        void    (GENERIC::*pmf)(uint, uint, uint),
                        uint     wParam,
                        int32    lParam);


//----------------------------------------------------------------------------
// Aliases for compatibility

#define HBRUSH_HDC_W_U_Dispatch  U_U_U_U_Dispatch
#define LRESULT_U_U_W_Dispatch   I32_MenuChar_Dispatch
#define LRESULT_WPARAM_LPARAM_Dispatch I32_WPARAM_LPARAM_Dispatch
#define v_U_B_W_Dispatch         v_Activate_Dispatch
#define v_W_W_Dispatch           v_MdiActivate_Dispatch

#endif  // OWL_DISPATCH_H
