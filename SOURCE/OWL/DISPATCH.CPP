//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\dispatch.cpp
//   Implementation of dispatcher classes
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\point.h>
#include <owl\dispatch.h>

LRESULT _OWLFUNC
LRESULT_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                               LRESULT (GENERIC::*pmf)(WPARAM, LPARAM),
                               WPARAM   wParam,
                               LPARAM   lParam)
{
  return (generic.*pmf)(wParam, lParam);
}

LRESULT _OWLFUNC
v_Dispatch(GENERIC& generic,
           void    (GENERIC::*pmf)(),
           WPARAM,
           LPARAM)
{
  (generic.*pmf)();
  return 0;
}

LRESULT _OWLFUNC
v_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         void    (GENERIC::*pmf)(WPARAM, LPARAM),
                         WPARAM   wParam,
                         LPARAM   lParam)
{
  (generic.*pmf)(wParam, lParam);
  return 0;
}

LRESULT _OWLFUNC
v_U_U_Dispatch(GENERIC& generic,
               void    (GENERIC::*pmf)(UINT, UINT),
               WPARAM   wParam,
               LPARAM   lParam)
{
#if defined(__WIN32__)
  (generic.*pmf)(wParam, lParam);
#else
  (generic.*pmf)(wParam, LOWORD(lParam));
#endif
  return 0;
}

LRESULT _OWLFUNC
v_U_U_U_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(UINT, UINT, UINT),
                 WPARAM   wParam,
                 LPARAM   lParam)
{
  (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
  return 0;
}

LRESULT _OWLFUNC
U_U_U_U_Dispatch(GENERIC& generic,
                 UINT    (GENERIC::*pmf)(UINT, UINT, UINT),
                 WPARAM   wParam,
                 LPARAM   lParam)
{
  return (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
}

LRESULT _OWLFUNC
v_LPARAM_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(LPARAM),
                  WPARAM,
                  LPARAM   lParam)
{
  (generic.*pmf)(lParam);
  return 0;
}

LRESULT _OWLFUNC
i_LPARAM_Dispatch(GENERIC& generic,
                  int     (GENERIC::*pmf)(LPARAM),
                  WPARAM,
                  LPARAM   lParam)
{
  return (generic.*pmf)(lParam);
}

LRESULT _OWLFUNC
v_WPARAM_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(WPARAM),
                  WPARAM   wParam,
                  LPARAM)
{
  (generic.*pmf)(wParam);
  return 0;
}

LRESULT _OWLFUNC
i_WPARAM_Dispatch(GENERIC& generic,
                  int     (GENERIC::*pmf)(WPARAM),
                  WPARAM   wParam,
                  LPARAM)
{
  return (generic.*pmf)(wParam);
}

LRESULT _OWLFUNC
v_U_U_W_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(UINT, UINT, HWND),
                 WPARAM   wParam,
                 LPARAM   lParam)
{
#if defined(__WIN32__)
  (generic.*pmf)(LOWORD(wParam), HIWORD(wParam), (HWND)lParam);
#else
  (generic.*pmf)(wParam, LOWORD(lParam), (HWND)HIWORD(lParam));
#endif
  return 0;
}

LRESULT _OWLFUNC
LRESULT_U_U_W_Dispatch(GENERIC& generic,
                       LRESULT (GENERIC::*pmf)(UINT, UINT, HWND),
                       WPARAM   wParam,
                       LPARAM   lParam)
{
#if defined(__WIN32__)
  return (generic.*pmf)(LOWORD(wParam), HIWORD(wParam), (HWND)lParam);
#else
  return (generic.*pmf)(wParam, LOWORD(lParam), (HWND)HIWORD(lParam));
#endif
}

LRESULT _OWLFUNC
v_U_POINT_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(UINT, TPoint&),
                   WPARAM   wParam,
                   LPARAM   lParam)
{
#if defined(__WIN32__)
  (generic.*pmf)(wParam, TPoint(lParam));
#else
  (generic.*pmf)(wParam, *(TPoint*)&lParam);
#endif
  return 0;
}

LRESULT _OWLFUNC
v_POINT_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(TPoint&),
                 WPARAM,
                 LPARAM   lParam)
{
#if defined(__WIN32__)
  (generic.*pmf)(TPoint(lParam));
#else
  (generic.*pmf)(*(TPoint*)&lParam);
#endif
  return 0;
}

LRESULT _OWLFUNC
U_LPARAM_Dispatch(GENERIC& generic,
                  UINT    (GENERIC::*pmf)(LPARAM),
                  WPARAM,
                  LPARAM   lParam)
{
  return (generic.*pmf)(lParam);
}

LRESULT _OWLFUNC
U_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         UINT    (GENERIC::*pmf)(WPARAM, LPARAM),
                         WPARAM   wParam,
                         LPARAM   lParam)
{
  return (generic.*pmf)(wParam, lParam);
}

LRESULT _OWLFUNC
U_POINT_Dispatch(GENERIC& generic,
                 UINT    (GENERIC::*pmf)(TPoint&),
                 WPARAM,
                 LPARAM   lParam)
{
#if defined(__WIN32__)
  return (generic.*pmf)(TPoint(lParam));
#else
  return (generic.*pmf)(*(TPoint*)&lParam);
#endif
}

LRESULT _OWLFUNC
U_Dispatch(GENERIC& generic,
           UINT(GENERIC::*pmf)(),
           WPARAM,
           LPARAM)
{
  return (generic.*pmf)();
}

LRESULT _OWLFUNC
i_U_W_U_Dispatch(GENERIC& generic,
                 int     (GENERIC::*pmf)(UINT, HWND, UINT),
                 WPARAM   wParam,
                 LPARAM   lParam)
{
#if defined(__WIN32__)
  return (generic.*pmf)(LOWORD(wParam), (HWND)lParam, HIWORD(wParam));
#else
  return (generic.*pmf)(wParam, (HWND)LOWORD(lParam), HIWORD(lParam));
#endif
}

LRESULT _OWLFUNC
v_W_W_Dispatch(GENERIC& generic,
               void    (GENERIC::*pmf)(HWND, HWND),
               WPARAM   wParam,
               LPARAM   lParam)
{
#if defined(__WIN32__)
  (generic.*pmf)((HWND)lParam, (HWND)wParam);
#else
  (generic.*pmf)((HWND)LOWORD(lParam), (HWND)(lParam ? HIWORD(lParam) : wParam));
#endif
  return 0;
}

LRESULT _OWLFUNC
v_U_B_W_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(UINT, BOOL, HWND),
                 WPARAM   wParam,
                 LPARAM   lParam)
{
#if defined(__WIN32__)
  (generic.*pmf)(LOWORD(wParam), HIWORD(wParam), (HWND)lParam);
#else
  (generic.*pmf)(wParam, HIWORD(lParam), (HWND)LOWORD(lParam));
#endif
  return 0;
}

LRESULT _OWLFUNC
HBRUSH_HDC_W_U_Dispatch(GENERIC& generic,
                        HBRUSH  (GENERIC::*pmf)(HDC, HWND, UINT),
                        WPARAM   wParam,
                        LPARAM   lParam)
{
  return (LRESULT)(generic.*pmf)((HDC)wParam,
                                 (HWND)LOWORD(lParam),
                                 HIWORD(lParam));
}

LRESULT _OWLFUNC
v_POINTER_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(void*),
                   WPARAM,
                   LPARAM   lParam)
{
  (generic.*pmf)((void*)lParam);
  return 0;
}

LRESULT _OWLFUNC
v_ParentNotify_Dispatch(GENERIC& generic,
                 int     (GENERIC::*pmf)(UINT, UINT, UINT),
                 WPARAM   wParam,
                 LPARAM   lParam)
{
#if defined(__WIN32__)
  if (LOWORD(wParam) >= WM_MOUSEFIRST && LOWORD(wParam) <= WM_MOUSELAST)
    (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
  else
    (generic.*pmf)(LOWORD(wParam), lParam, HIWORD(wParam));
#else
  (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
#endif
  return 0;
}

