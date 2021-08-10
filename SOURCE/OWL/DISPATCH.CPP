//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Implementation of OWL message dispatcher functions
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_DISPATCH_H)
# include <owl/dispatch.h>
#endif

OWL_DIAGINFO;

//----------------------------------------------------------------------------

#if defined(BI_NAMESPACE)
namespace OWL {
#endif
  
int32 _OWLFUNC
i_LPARAM_Dispatch(GENERIC& generic,
                  int     (GENERIC::*pmf)(int32),
                  uint,
                  int32    param2)
{
  return (generic.*pmf)(param2);
}

int32 _OWLFUNC
i_WPARAM_Dispatch(GENERIC& generic,
                  int     (GENERIC::*pmf)(uint),
                  uint     param1,
                  int32)
{
  return (generic.*pmf)(param1);
}

int32 _OWLFUNC
B_WPARAM_Dispatch(GENERIC& generic,
                  bool     (GENERIC::*pmf)(uint),
                  uint     param1,
                  int32)
{
  return (generic.*pmf)(param1);
}

int32 _OWLFUNC
B_B_Dispatch(GENERIC& generic,
             bool     (GENERIC::*pmf)(bool),
             uint     param1,
             int32)
{
  return (generic.*pmf)((bool)param1);
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
                    int32    param2)
{
  return (generic.*pmf)(param2);
}

//
// Passes param2 as a uint and returns an int32 result
//
int32 _OWLFUNC
I32_U_Dispatch(GENERIC& generic,
               int32   (GENERIC::*pmf)(uint),
               uint,
               int32    param2)
{
  return (generic.*pmf)((uint)param2);
}

//
// Passes param2 as an int and returns bool
//
int32 _OWLFUNC
B_I2_Dispatch(GENERIC& generic,
               bool  (GENERIC::*pmf)(int),
               uint,
               int32    param2)
{
  return (generic.*pmf)((int)param2);
}

int32 _OWLFUNC
I32_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                           int32   (GENERIC::*pmf)(uint, int32),
                           uint     param1,
                           int32    param2)
{
  return (generic.*pmf)(param1, param2);
}

//----------------------------------------------------------------------------

int32 _OWLFUNC
U_Dispatch(GENERIC& generic,
           uint  (GENERIC::*pmf)(),
           uint,
           int32)
{
  return (generic.*pmf)();
}

int32 _OWLFUNC
U32_Dispatch(GENERIC& generic,
             uint32  (GENERIC::*pmf)(),
             uint,
             int32)
{
  return (generic.*pmf)();
}

int32 _OWLFUNC
B_Dispatch(GENERIC& generic,
           bool(GENERIC::*pmf)(),
           uint,
           int32)
{
  return (generic.*pmf)();
}

int32 _OWLFUNC
B_LPARAM_Dispatch(GENERIC& generic,
                  bool    (GENERIC::*pmf)(int32),
                  uint,
                  int32    param2)
{
  return (generic.*pmf)(param2) != false;
}

int32 _OWLFUNC
U_LPARAM_Dispatch(GENERIC& generic,
                  uint    (GENERIC::*pmf)(int32),
                  uint,
                  int32    param2)
{
  return (generic.*pmf)(param2);
}

int32 _OWLFUNC
U_POINT_Dispatch(GENERIC& generic,
                 uint    (GENERIC::*pmf)(TPoint&),
                 uint,
                 int32    param2)
{
#if defined(BI_PLAT_WIN32)
  return (generic.*pmf)(TPoint(param2));
#else
  return (generic.*pmf)(*(TPoint*)&param2);  // 16-bit cast trick
#endif
}

int32 _OWLFUNC
U_POINTER_Dispatch(GENERIC& generic,
                   uint    (GENERIC::*pmf)(void*),
                   uint,
                   int32    param2)
{
  return (generic.*pmf)((void*)param2);
}

int32 _OWLFUNC
B_POINTER_Dispatch(GENERIC& generic,
                   bool    (GENERIC::*pmf)(void*),
                   uint,
                   int32    param2)
{
  return (generic.*pmf)((void*)param2);
}

int32 _OWLFUNC
U_U_Dispatch(GENERIC& generic,
             uint    (GENERIC::*pmf)(uint),
             uint     param1,
             int32)
{
  return (generic.*pmf)((uint)param1);
}

int32 _OWLFUNC
U_B_Dispatch(GENERIC& generic,
             uint    (GENERIC::*pmf)(bool),
             uint     param1,
             int32)
{
  return (generic.*pmf)((bool)param1);
}

int32 _OWLFUNC
B_B_U_Dispatch(GENERIC& generic,
             bool    (GENERIC::*pmf)(bool, uint),
             uint     param1,
             int32    param2)
{
  return (generic.*pmf)((bool)param1, (uint)param2);
}

int32 _OWLFUNC
U_U_RECT_Dispatch(GENERIC& generic,
                  uint    (GENERIC::*pmf)(uint, TRect&),
                  uint     param1,
                  int32    param2)
{
#if defined(BI_DATA_NEAR)
  TRect rect(*(RECT far*)param2);
  uint i = (generic.*pmf)(param1, rect);
  *(RECT far*)param2 = rect;
  return i;
#else
  return (generic.*pmf)(param1, *(TRect*)param2);
#endif
}

int32 _OWLFUNC
B_U_RECT_Dispatch(GENERIC& generic,
                  bool    (GENERIC::*pmf)(uint, TRect&),
                  uint     param1,
                  int32    param2)
{
#if defined(BI_DATA_NEAR)
  TRect rect(*(RECT far*)param2);
  bool b = (generic.*pmf)(param1, rect);
  *(RECT far*)param2 = rect;
  return b;
#else
  return (generic.*pmf)(param1, *(TRect*)param2);
#endif
}

int32 _OWLFUNC
U_U_U_U_Dispatch(GENERIC& generic,
                 uint    (GENERIC::*pmf)(uint, uint, uint),
                 uint     param1,
                 int32    param2)
{
  return (generic.*pmf)(param1, LoUint16(param2), HiUint16(param2));
}

int32 _OWLFUNC
U_U_U_Dispatch(GENERIC& generic,
               uint    (GENERIC::*pmf)(uint, uint),
               uint     wParam,
               int32    lParam)
{
  return (generic.*pmf)(wParam, uint(lParam));
}

int32 _OWLFUNC
U_B_U_Dispatch(GENERIC& generic,
               uint    (GENERIC::*pmf)(bool, uint),
               uint     wParam,
               int32    lParam)
{
  return (generic.*pmf)((bool)wParam, uint(lParam));
}

int32 _OWLFUNC
B_U_U_Dispatch(GENERIC& generic,
               bool    (GENERIC::*pmf)(uint, uint),
               uint     wParam,
               int32    lParam)
{
  return (generic.*pmf)(wParam, (uint)lParam); //cast for 16-bit compatability
}

int32 _OWLFUNC
B_U_U_U_Dispatch(GENERIC& generic,
                 bool    (GENERIC::*pmf)(uint, uint, uint),
                 uint     param1,
                 int32    param2)
{
  return (generic.*pmf)(param1, LoUint16(param2), HiUint16(param2));
}

int32 _OWLFUNC
U_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         uint    (GENERIC::*pmf)(uint, int32),
                         uint     param1,
                         int32    param2)
{
  return (generic.*pmf)(param1, param2);
}

int32 _OWLFUNC
B_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         bool    (GENERIC::*pmf)(uint, int32),
                         uint     param1,
                         int32    param2)
{
  return (generic.*pmf)(param1, param2);
}

int32 _OWLFUNC
U_B_LPARAM_Dispatch(GENERIC& generic,
                    uint    (GENERIC::*pmf)(bool, int32),
                    uint     param1,
                    int32    param2)
{
  return (generic.*pmf)((bool)param1, param2);
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
                  int32    param2)
{
  (generic.*pmf)(param2);
  return 0;
}

int32 _OWLFUNC
v_POINT_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(TPoint&),
                 uint,
                 int32    param2)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(TPoint(param2));
#else
  (generic.*pmf)(*(TPoint*)&param2);  // 16-bit cast trick
#endif
  return 0;
}

int32 _OWLFUNC
v_POINTER_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(void*),
                   uint,
                   int32    param2)
{
  (generic.*pmf)((void*)param2);
  return 0;
}

int32 _OWLFUNC
v_U_Dispatch(GENERIC& generic,
             void    (GENERIC::*pmf)(uint),
             uint,
             int32    param2)
{
  (generic.*pmf)((uint)param2);
  return 0;
}

int32 _OWLFUNC
v_U_POINT_Dispatch(GENERIC& generic,
                   void    (GENERIC::*pmf)(uint, TPoint&),
                   uint     param1,
                   int32    param2)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(param1, TPoint(param2));
#else
  (generic.*pmf)(param1, *(TPoint*)&param2);  // 16-bit cast trick
#endif
  return 0;
}

int32 _OWLFUNC
v_U_U_Dispatch(GENERIC& generic,
               void    (GENERIC::*pmf)(uint, uint),
               uint     param1,
               int32    param2)
{
  (generic.*pmf)(param1, (uint)param2);
  return 0;
}

int32 _OWLFUNC
v_U_B_Dispatch(GENERIC& generic,
               void    (GENERIC::*pmf)(uint, bool),
               uint     param1,
               int32    param2)
{
  (generic.*pmf)(param1, (bool)param2);
  return 0;
}

int32 _OWLFUNC
v_B_U_Dispatch(GENERIC& generic,
               void    (GENERIC::*pmf)(bool, uint),
               uint     param1,
               int32    param2)
{
  (generic.*pmf)((bool)param1, (uint)param2);
  return 0;
}

int32 _OWLFUNC
v_U_U_U_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(uint, uint, uint),
                 uint     param1,
                 int32    param2)
{
  (generic.*pmf)(param1, LoUint16(param2), HiUint16(param2));
  return 0;
}

int32 _OWLFUNC
v_B_U_U_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(bool, uint, uint),
                 uint     param1,
                 int32    param2)
{
  (generic.*pmf)((bool)param1, LoUint16(param2), HiUint16(param2));
  return 0;
}

int32 _OWLFUNC
v_U_U_B_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(uint, uint, bool),
                 uint     param1,
                 int32    param2)
{
  (generic.*pmf)(param1, LoUint16(param2), (bool)HiUint16(param2));
  return 0;
}

int32 _OWLFUNC
v_WPARAM_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(uint),
                  uint     param1,
                  int32)
{
  (generic.*pmf)(param1);
  return 0;
}

int32 _OWLFUNC
v_B_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(bool),
                  uint     param1,
                  int32)
{
  (generic.*pmf)((bool)param1);
  return 0;
}

int32 _OWLFUNC
v_B_B_Dispatch(GENERIC& generic,
                  void    (GENERIC::*pmf)(bool, bool),
                  uint     param1,
                  int32    param2)
{
  (generic.*pmf)((bool)param1, (bool)param2);
  return 0;
}

#if defined(BI_PLAT_WIN32)
int32 _OWLFUNC
v_HWND_PCOPYDATASTRUCT_Dispatch(GENERIC& generic,
                         void    (GENERIC::*pmf)(HWND, COPYDATASTRUCT*),
                         uint     param1,
                         int32    param2)
{
  (generic.*pmf)((HWND)param1, (COPYDATASTRUCT*)param2);
  return true;
}
#endif

int32 _OWLFUNC
v_WPARAM_LPARAM_Dispatch(GENERIC& generic,
                         void    (GENERIC::*pmf)(uint, int32),
                         uint     param1,
                         int32    param2)
{
  (generic.*pmf)(param1, param2);
  return 0;
}

//----------------------------------------------------------------------------
//
// Semi-custom message crackers
//
int32 _OWLFUNC
i_U_W_U_Dispatch(GENERIC& generic,
                 int     (GENERIC::*pmf)(uint, uint, uint),
                 uint     param1,
                 int32    param2)
{
#if defined(BI_PLAT_WIN32)
  return (generic.*pmf)(LoUint16(param1), param2, HiUint16(param1));
#else
  return (generic.*pmf)(param1, LoUint16(param2), HiUint16(param2));
#endif
}

int32 _OWLFUNC
v_U_U_W_Dispatch(GENERIC& generic,
                 void    (GENERIC::*pmf)(uint, uint, uint),
                 uint     param1,
                 int32    param2)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(LoUint16(param1), HiUint16(param1), param2);
#else
  (generic.*pmf)(param1, LoUint16(param2), HiUint16(param2));
#endif
  return 0;
}

//----------------------------------------------------------------------------
//
// Custom message crackers
//

int32 _OWLFUNC
v_Activate_Dispatch(GENERIC& generic,
                    void    (GENERIC::*pmf)(uint, bool, uint),
                    uint     param1,
                    int32    param2)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(LoUint16(param1), (bool)HiUint16(param1), param2);
#else
  (generic.*pmf)(param1, (bool)HiUint16(param2), LoUint16(param2));
#endif
  return 0;
}

int32 _OWLFUNC
v_MdiActivate_Dispatch(GENERIC& generic,
                       void    (GENERIC::*pmf)(uint, uint),
                       uint     param1,
                       int32    param2)
{
#if defined(BI_PLAT_WIN32)
  (generic.*pmf)(param2, param1);
#else
  (generic.*pmf)(LoUint16(param2), param2 ? HiUint16(param2) : param1);
#endif
  return 0;
}

int32 _OWLFUNC
I32_MenuChar_Dispatch(GENERIC& generic,
                      int32   (GENERIC::*pmf)(uint, uint, uint),
                      uint     param1,
                      int32    param2)
{
#if defined(BI_PLAT_WIN32)
  return (generic.*pmf)(LoUint16(param1), HiUint16(param1), param2);
#else
  return (generic.*pmf)(param1, LoUint16(param2), HiUint16(param2));
#endif
}

int32 _OWLFUNC
v_ParentNotify_Dispatch(GENERIC& generic,
                        void    (GENERIC::*pmf)(uint, uint, uint),
                        uint     param1,
                        int32    param2)
{
#if defined(BI_PLAT_WIN32)
  if (LoUint16(param1) >= WM_MOUSEFIRST && LoUint16(param1) <= WM_MOUSELAST)
    (generic.*pmf)(param1, LoUint16(param2), HiUint16(param2));
  else
    (generic.*pmf)(LoUint16(param1), param2, HiUint16(param1));
#else
  (generic.*pmf)(param1, LoUint16(param2), HiUint16(param2));
#endif
  return 0;
}

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif
