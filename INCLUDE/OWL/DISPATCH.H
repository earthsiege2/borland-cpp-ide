//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   include\owl\dispatch.h
//   Dispatch functions to crack a Windows message and pass control to a
//   pointer to member function.
//----------------------------------------------------------------------------
#if !defined(__OWL_DISPATCH_H)
#define __OWL_DISPATCH_H

#if !defined(__OWL_POINT_H)
  #include <owl\point.h>
#endif

//
//  class GENERIC
//  ----- -------
//  generic class for casting pointer to objects and pointer to member functions
//
class _OWLFASTTHIS GENERIC;   // conditionally define to correct calling model

//
//  typedef TAnyPMF
//  ------- -------
//  generic pointer to member function
//
typedef void (GENERIC::*TAnyPMF)();

//
//  typedef TAnyDispatcher
//  ------- --------------
//  all message dispatcher functions take four parameters:
//  - reference to an object
//  - pointer to member function (signature varies according to the cracking
//    that the function performs)
//  - WPARAM
//  - LPARAM
//
typedef LRESULT _OWLFUNC (*TAnyDispatcher)(GENERIC&, TAnyPMF, WPARAM, LPARAM);

//
//  LEGEND: in order to keep signature names from getting too long, the
//          following abbreviations are used:
//
//  - v (void return)
//  - i (int)
//  - U (UINT)
//  - B (BOOL)
//  - H (HANDLE)
//  - W (HWND)
//  - S (LPSTR)
//

//
//  LRESULT_WPARAM_LPARAM_Dispatch
//  ------------------------------
//  does no message cracking (passes wParam and lParam) and returns result
//  of pointer to member function
//
LRESULT _OWLFUNC
LRESULT_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                               LRESULT (GENERIC::*pmf)(WPARAM, LPARAM),
                               WPARAM   wParam,
                               LPARAM   lParam);

//
//  v_Dispatch
//  ------------
//  passes no arguments and always returns 0
//
LRESULT _OWLFUNC
v_Dispatch(GENERIC& generic,
           void    (GENERIC::*pmf)(),
           WPARAM   wParam,
           LPARAM   lParam);

//
//  v_WPARAM_LPARAM_Dispatch
//  ------------------------
//  does no message cracking (passes wParam and lParam) and always returns 0
//
LRESULT _OWLFUNC
v_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         void    (GENERIC::*pmf)(WPARAM, LPARAM),
                         WPARAM   wParam,
                         LPARAM   lParam);

//
//  v_U_U_Dispatch
//  --------------
//  passes two UINTs and always returns 0
//
//  first UINT is wParam and second one is lParam for 32-bit int and
//  LOWORD(lParam) for 16-bit int
//
LRESULT _OWLFUNC
v_U_U_Dispatch(GENERIC& generic,
               void    (GENERIC::*pmf)(UINT, UINT),
               WPARAM   wParam,
               LPARAM   lParam);

//
//  v_U_U_U_Dispatch
//  ----------------
//  passes three UINTs and always returns 0
//
//  first UINT is wParam, second UINT is LOWORD(lParam), and third UINT
//  is HIWORD(lParam)
//
LRESULT _OWLFUNC
v_U_U_U_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(UINT, UINT, UINT),
                 WPARAM   wParam,
                 LPARAM   lParam);

//
//  U_U_U_U_Dispatch
//  ----------------
//  passes three UINTs and returns result of pointer to member function
//
//  first UINT is wParam, second UINT is LOWORD(lParam), and third UINT
//  is HIWORD(lParam)
//
LRESULT _OWLFUNC
U_U_U_U_Dispatch(GENERIC& generic,
                 UINT    (GENERIC::*pmf)(UINT, UINT, UINT),
                 WPARAM   wParam,
                 LPARAM   lParam);

//
//  v_LPARAM_Dispatch
//  -----------------
//  passes LPARAM as the only parameter and always returns 0
//
LRESULT _OWLFUNC
v_LPARAM_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(LPARAM),
                  WPARAM   wParam,
                  LPARAM   lParam);

//
//  i_LPARAM_Dispatch
//  -----------------
//  passes LPARAM as the only parameter and returns result of pointer to
//  member function
//
LRESULT _OWLFUNC
i_LPARAM_Dispatch(GENERIC& generic,
                  int     (GENERIC::*pmf)(LPARAM),
                  WPARAM   wParam,
                  LPARAM   lParam);

//
//  v_WPARAM_Dispatch
//  -----------------
//  passes WPARAM as the only parameter and always returns 0
//
LRESULT _OWLFUNC
v_WPARAM_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(WPARAM),
                  WPARAM   wParam,
                  LPARAM   lParam);

//
//  i_WPARAM_Dispatch
//  -----------------
//  passes WPARAM as the only parameter and returns result of pointer to
//  member function
//
LRESULT _OWLFUNC
i_WPARAM_Dispatch(GENERIC& generic,
                  BOOL    (GENERIC::*pmf)(WPARAM),
                  WPARAM   wParam,
                  LPARAM   lParam);

//
//  v_U_U_W_Dispatch
//  ----------------
//  passes two UINTs and an HWND and always returns 0
//
LRESULT _OWLFUNC
v_U_U_W_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(UINT, UINT, HWND),
                 WPARAM   wParam,
                 LPARAM   lParam);

//
//  LRESULT_U_U_W_Dispatch
//  ----------------
//  passes two UINTs and an HWND and returns the result of pointer to member
//  function
//
LRESULT _OWLFUNC
LRESULT_U_U_W_Dispatch(GENERIC& generic,
                       LRESULT (GENERIC::*pmf)(UINT, UINT, HWND),
                       WPARAM   wParam,
                       LPARAM   lParam);

//
//  v_U_POINT_Dispatch
//  ------------------
//  passes a UINT and a reference to a POINT and always returns 0
//
LRESULT _OWLFUNC
v_U_POINT_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(UINT, TPoint&),
                   WPARAM   wParam,
                   LPARAM   lParam);

//
//  v_POINT_Dispatch
//  ----------------
//  passes a reference to a POINT and always returns 0
//
LRESULT _OWLFUNC
v_POINT_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(TPoint&),
                 WPARAM   wParam,
                 LPARAM   lParam);

//
//  U_LPARAM_Dispatch
//  ------------------------
//  passes lParam and returns the result of pointer to member
//  function
//
LRESULT _OWLFUNC
U_LPARAM_Dispatch(GENERIC& generic,
                  UINT    (GENERIC::*pmf)(LPARAM),
                  WPARAM   wParam,
                  LPARAM   lParam);

//
//  U_WPARAM_LPARAM_Dispatch
//  ------------------------
//  passes wParam and lParam and returns the result of pointer to member
//  function
//
LRESULT _OWLFUNC
U_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         UINT    (GENERIC::*pmf)(WPARAM, LPARAM),
                         WPARAM   wParam,
                         LPARAM   lParam);

//
//  U_POINT_Dispatch
//  ----------------
//  passes a reference to POINT and returns the result of pointer to member
//  function
//
LRESULT _OWLFUNC
U_POINT_Dispatch(GENERIC& generic,
                 UINT    (GENERIC::*pmf)(TPoint&),
                 WPARAM   wParam,
                 LPARAM   lParam);

//
//  U_Dispatch
//  ------------
//  passes no arguments and returns the result of pointer to member function
//
LRESULT _OWLFUNC
U_Dispatch(GENERIC& generic,
           UINT    (GENERIC::*pmf)(),
           WPARAM   wParam,
           LPARAM   lParam);

//
//  i_U_W_U_Dispatch
//  ----------------
//  passes a UINT, HWND, and UINT and returns the result of pointer to member
//  function
//
LRESULT _OWLFUNC
i_U_W_U_Dispatch(GENERIC& generic,
                 int     (GENERIC::*pmf)(UINT, HWND, UINT),
                 WPARAM   wParam,
                 LPARAM   lParam);

//
//  v_W_W_Dispatch - EvMDIActivate-specific
//  --------------
//  passes two HWNDs and always returns 0
//
LRESULT _OWLFUNC
v_W_W_Dispatch(GENERIC& generic,
               void    (GENERIC::*pmf)(HWND, HWND),
               WPARAM   wParam,
               LPARAM   lParam);

//
//  v_U_B_W_Dispatch
//  ----------------
//  passes a UINT, a BOOL, and an HWND and always returns 0
//
LRESULT _OWLFUNC
v_U_B_W_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(UINT, BOOL, HWND),
                 WPARAM   wParam,
                 LPARAM   lParam);

//
//  HBRUSH_HDC_W_U_Dispatch
//  -----------------------
//  passes an HDC, an HWND, and a UINT and returns a HBRUSH
//
LRESULT _OWLFUNC
HBRUSH_HDC_W_U_Dispatch(GENERIC& generic,
                        HBRUSH  (GENERIC::*pmf)(HDC, HWND, UINT),
                        WPARAM   wParam,
                        LPARAM   lParam);

//
//  v_POINTER_Dispatch
//  ------------------
//  passes a LPARAM as a void* pointer and always returns 0
//
LRESULT _OWLFUNC
v_POINTER_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(void*),
                   WPARAM   wParam,
                   LPARAM   lParam);

//
//  v_ParentNotify_Dispatch
//  -----------------------
//  message-specific cracking for WM_PARENTNOTIFY
//
LRESULT _OWLFUNC
v_ParentNotify_Dispatch(GENERIC& generic,
                 int     (GENERIC::*pmf)(UINT, UINT, UINT),
                 WPARAM   wParam,
                 LPARAM   lParam);

#endif  // __OWL_DISPATCH_H
