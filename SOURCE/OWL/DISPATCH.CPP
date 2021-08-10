//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of dispatcher functions
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/point.h>
#include <owl/dispatch.h>

//----------------------------------------------------------------------------

int32 _OWLFUNC
i_LPARAM_Dispatch(GENERIC& generic,
                  int     (GENERIC::*pmf)(int32),
                  uint,
                  int32    lParam)
{
  return (generic.*pmf)(lParam);
}

int32 _OWLFUNC
i_WPARAM_Dispatch(GENERIC& generic,
                  int     (GENERIC::*pmf)(uint),
                  uint     wParam,
                  int32)
{
  return (generic.*pmf)(wParam);
}

//----------------------------------------------------------------------------

int32 _OWLFUNC
I32_Dispatch(GENERIC& generic,
             uint32  (GENERIC::*pmf)(),
             uint,
             int32)
{
  return (generic.*pmf)();
}

int32 _OWLFUNC
I32_LPARAM_Dispatch(GENERIC& generic,
                    int32  (GENERIC::*pmf)(int32),
                    uint,
                    int32    lParam)
{
  return (generic.*pmf)(lParam);
}

//
// passes lParam as a uint and returns an int32 result
//
int32 _OWLFUNC
I32_U_Dispatch(GENERIC& generic,
               int32   (GENERIC::*pmf)(uint),
               uint,
               int32    lParam)
{
  return (generic.*pmf)((uint)lParam);
}


int32 _OWLFUNC
I32_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                           int32   (GENERIC::*pmf)(uint, int32),
                           uint     wParam,
                           int32    lParam)
{
  return (generic.*pmf)(wParam, lParam);
}

//----------------------------------------------------------------------------

int32 _OWLFUNC
U_Dispatch(GENERIC& generic,
           uint(GENERIC::*pmf)(),
           uint,
           int32)
{
  return (generic.*pmf)();
}

int32 _OWLFUNC
U_LPARAM_Dispatch(GENERIC& generic,
                  uint    (GENERIC::*pmf)(int32),
                  uint,
                  int32    lParam)
{
  return (generic.*pmf)(lParam);
}

int32 _OWLFUNC
U_POINT_Dispatch(GENERIC& generic,
                 uint    (GENERIC::*pmf)(TPoint&),
                 uint,
                 int32    lParam)
{
#if defined(BI_PLAT_WIN32)
  return (generic.*pmf)(TPoint(lParam));
#else
  return (generic.*pmf)(*(TPoint*)&lParam);  // 16-bit cast trick
#endif
}

int32 _OWLFUNC
U_POINTER_Dispatch(GENERIC& generic,
                   uint    (GENERIC::*pmf)(void*),
                   uint,
                   int32    lParam)
{
  return (generic.*pmf)((void*)lParam);
}

int32 _OWLFUNC
U_U_Dispatch(GENERIC& generic,
             uint    (GENERIC::*pmf)(uint),
             uint,
             int32    lParam)
{
  return (generic.*pmf)((uint)lParam);
}

int32 _OWLFUNC
U_U_U_U_Dispatch(GENERIC& generic,
                 uint    (GENERIC::*pmf)(uint, uint, uint),
                 uint     wParam,
                 int32    lParam)
{
  return (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
}

int32 _OWLFUNC
U_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         uint    (GENERIC::*pmf)(uint, int32),
                         uint     wParam,
                         int32    lParam)
{
  return (generic.*pmf)(wParam, lParam);
}

//----------------------------------------------------------------------------

int32 _OWLFUNC
v_Dispatch(GENERIC& generic,
           void    (GENERIC::*pmf)(),
           uint,
           int32)
{
  (generic.*pmf)();
  return 0;
}

int32 _OWLFUNC
v_LPARAM_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(int32),
                  uint,
                  int32    lParam)
{
  (generic.*pmf)(lParam);
  return 0;
}

int32 _OWLFUNC
v_POINT_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(TPoint&),
                 uint,
                 int32    lParam)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(TPoint(lParam));
#else
  (generic.*pmf)(*(TPoint*)&lParam);  // 16-bit cast trick
#endif
  return 0;
}

int32 _OWLFUNC
v_POINTER_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(void*),
                   uint,
                   int32    lParam)
{
  (generic.*pmf)((void*)lParam);
  return 0;
}

int32 _OWLFUNC
v_U_Dispatch(GENERIC& generic,
             void    (GENERIC::*pmf)(uint),
             uint,
             int32    lParam)
{
  (generic.*pmf)((uint)lParam);
  return 0;
}

int32 _OWLFUNC
v_U_POINT_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(uint, TPoint&),
                   uint     wParam,
                   int32    lParam)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(wParam, TPoint(lParam));
#else
  (generic.*pmf)(wParam, *(TPoint*)&lParam);  // 16-bit cast trick
#endif
  return 0;
}

int32 _OWLFUNC
v_U_U_Dispatch(GENERIC& generic,
               void    (GENERIC::*pmf)(uint, uint),
               uint     wParam,
               int32    lParam)
{
  (generic.*pmf)(wParam, (uint)lParam);
  return 0;
}

int32 _OWLFUNC
v_U_U_U_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(uint, uint, uint),
                 uint     wParam,
                 int32    lParam)
{
  (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
  return 0;
}

int32 _OWLFUNC
v_WPARAM_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(uint),
                  uint     wParam,
                  int32)
{
  (generic.*pmf)(wParam);
  return 0;
}

int32 _OWLFUNC
v_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         void    (GENERIC::*pmf)(uint, int32),
                         uint     wParam,
                         int32    lParam)
{
  (generic.*pmf)(wParam, lParam);
  return 0;
}

//----------------------------------------------------------------------------
//
// Semi-custom message crackers
//
int32 _OWLFUNC
i_U_W_U_Dispatch(GENERIC& generic,
                 int     (GENERIC::*pmf)(uint, uint, uint),
                 uint     wParam,
                 int32    lParam)
{
#if defined(BI_PLAT_WIN32)
  return (generic.*pmf)(LOWORD(wParam), lParam, HIWORD(wParam));
#else
  return (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
#endif
}

int32 _OWLFUNC
v_U_U_W_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(uint, uint, uint),
                 uint     wParam,
                 int32    lParam)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(LOWORD(wParam), HIWORD(wParam), lParam);
#else
  (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
#endif
  return 0;
}

//----------------------------------------------------------------------------
//
// Custom message crackers
//

int32 _OWLFUNC
v_Activate_Dispatch(GENERIC& generic,
                    void    (GENERIC::*pmf)(uint, uint, uint),
                    uint     wParam,
                    int32    lParam)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(LOWORD(wParam), HIWORD(wParam), lParam);
#else
  (generic.*pmf)(wParam, HIWORD(lParam), LOWORD(lParam));
#endif
  return 0;
}

int32 _OWLFUNC
v_MdiActivate_Dispatch(GENERIC& generic,
                       void    (GENERIC::*pmf)(uint, uint),
                       uint     wParam,
                       int32    lParam)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(lParam, wParam);
#else
  (generic.*pmf)(LOWORD(lParam), lParam ? HIWORD(lParam) : wParam);
#endif
  return 0;
}

int32 _OWLFUNC
I32_MenuChar_Dispatch(GENERIC& generic,
                      int32   (GENERIC::*pmf)(uint, uint, uint),
                      uint     wParam,
                      int32    lParam)
{
#if defined(BI_PLAT_WIN32)
  return (generic.*pmf)(LOWORD(wParam), HIWORD(wParam), lParam);
#else
  return (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
#endif
}

int32 _OWLFUNC
v_ParentNotify_Dispatch(GENERIC& generic,
                        void    (GENERIC::*pmf)(uint, uint, uint),
                        uint     wParam,
                        int32    lParam)
{
#if defined(BI_PLAT_WIN32)
  if (LOWORD(wParam) >= WM_MOUSEFIRST && LOWORD(wParam) <= WM_MOUSELAST)
    (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
  else
    (generic.*pmf)(LOWORD(wParam), lParam, HIWORD(wParam));
#else
  (generic.*pmf)(wParam, LOWORD(lParam), HIWORD(lParam));
#endif
  return 0;
}
