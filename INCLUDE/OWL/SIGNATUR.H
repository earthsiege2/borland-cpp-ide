//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Message handler signature templates
//----------------------------------------------------------------------------
#if !defined(OWL_SIGNATUR_H)
#define OWL_SIGNATUR_H

#if !defined(OWL_OWLDEFS_H)
# include <owl/owldefs.h>
#endif
class _OWLCLASS TCommandEnabler;
class _OWLCLASS TDocument;
class _OWLCLASS TView;
class TDropInfo;
class TPoint;
class TSize;
class _BIDSCLASS TRect;

//----------------------------------------------------------------------------
//  LEGEND: in order to keep signature names from getting too long, the
//          following abbreviations are used for the data types passed to and
//          returned from the methods. The first code is the return type, the
//          rest are args in left to right order.
//
//  - v   (void return)
//  - i   (int)
//  - I32 (int32)
//  - U   (uint)
//  - B   (bool)
//  - H   (HANDLE)
//  - W   (HWND)
//  - S   (char far*)
//  - CS  (const char far*)
//  - other types spelled out
//

//----------------------------------------------------------------------------

template <class T>
inline bool(T::*B_Sig(bool(T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline bool(T::*B_B_Sig(bool(T::*pmf)(bool)))(bool)
{
  return pmf;
}

template <class T>
inline bool(T::*B_CREATE_Sig(bool(T::*pmf)(CREATESTRUCT far&)))(CREATESTRUCT far&)
{
  return pmf;
}

template <class T>
inline bool(T::*B_CS_Sig(bool(T::*pmf)(const char far*)))(const char far*)
{
  return pmf;
}

template <class T>
inline bool(T::*B_MSG_Sig(bool(T::*pmf)(MSG far*)))(MSG far*)
{
  return pmf;
}

template <class T>
inline bool(T::*B_RECT_Sig(bool(T::*pmf)(TRect far*)))(TRect far*)
{
  return pmf;
}

template <class T>
inline bool(T::*B_W_U_U_Sig(bool(T::*pmf)(HWND, uint, uint)))(HWND, uint, uint)
{
  return pmf;
}

template <class T>
inline bool(T::*B_HDC_Sig(bool(T::*pmf)(HDC)))(HDC)
{
  return pmf;
}

template <class T>
inline bool(T::*B_I32_Sig(bool(T::*pmf)(int32)))(int32)
{
  return pmf;
}

template <class T>
inline bool(T::*B_PPALETTE_Sig(bool(T::*pmf)(LOGPALETTE far* far*)))(LOGPALETTE far* far*)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline const char far*(T::*CS_Sig(const char far*(T::*pmf)()))()
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline HANDLE(T::*H_Sig(HANDLE(T::*pmf)()))()
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline HBRUSH(T::*HBRUSH_HDC_W_U_Sig(HBRUSH(T::*pmf)(HDC, HWND, uint)))(HDC, HWND, uint)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline HFONT(T::*HFONT_Sig(HFONT(T::*pmf)()))()
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline int(T::*i_CREATE_Sig(int(T::*pmf)(CREATESTRUCT far&)))(CREATESTRUCT far&)
{
  return pmf;
}

template <class T>
inline int(T::*i_U_Sig(int(T::*pmf)(uint)))(uint)
{
  return pmf;
}

template <class T>
inline int(T::*i_U_W_U_Sig(int(T::*pmf)(uint, HWND, uint)))(uint, HWND, uint)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline int32(T::*I32_MDICREATESTRUCT_Sig(int32(T::*pmf)(MDICREATESTRUCT far&)))
                                        (MDICREATESTRUCT far&)
{
  return pmf;
}

template <class T>
inline int32(T::*I32_U_COMPAREITEM_Sig(int32(T::*pmf)(uint, COMPAREITEMSTRUCT far&)))
                                      (uint, COMPAREITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline int32(T::*I32_U_I32_Sig(int32(T::*pmf)(uint, int32)))(uint, int32)
{
  return pmf;
}

template <class T>
inline int32(T::*I32_U_U_HMENU_Sig(int32(T::*pmf)(uint, uint, HMENU)))(uint, uint, HMENU)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline uint32(T::*U32_VOIDFP_Sig(uint32(T::*pmf)(void far*)))(void far*)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline uint(T::*U_Sig(uint(T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline uint(T::*U_B_CALCSIZE_Sig(uint(T::*pmf)(bool, NCCALCSIZE_PARAMS far&)))
                                (bool, NCCALCSIZE_PARAMS far&)
{
  return pmf;
}

template <class T>
inline uint(T::*U_MSG_Sig(uint(T::*pmf)(MSG far*)))(MSG far*)
{
  return pmf;
}

template <class T>
inline uint(T::*U_POINT_Sig(uint(T::*pmf)(TPoint&)))(TPoint&)
{
  return pmf;
}

template <class T>
inline uint(T::*U_W_U_U_Sig(uint(T::*pmf)(HWND, uint, uint)))(HWND, uint, uint)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline void(T::*v_Sig(void(T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline void(T::*v_B_Sig(void(T::*pmf)(bool)))(bool)
{
  return pmf;
}

template <class T>
inline void(T::*v_B_HTASK_Sig(void(T::*pmf)(bool, HTASK)))(bool, HTASK)
{
  return pmf;
}

template <class T>
inline void(T::*v_B_U_Sig(void(T::*pmf)(bool, uint)))(bool, uint)
{
  return pmf;
}

template <class T>
inline void(T::*v_B_W_W_Sig(void(T::*pmf)(bool, HWND, HWND)))(bool, HWND, HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_COMMANDENABLER_Sig(void(T::*pmf)(TCommandEnabler&)))(TCommandEnabler&)
{
  return pmf;
}

template <class T>
inline void(T::*v_CS_Sig(void(T::*pmf)(const char far*)))(const char far*)
{
  return pmf;
}

template <class T>
inline void(T::*v_DROP_Sig(void(T::*pmf)(TDropInfo)))(TDropInfo)
{
  return pmf;
}

template <class T>
inline void(T::*v_H_Sig(void(T::*pmf)(HANDLE)))(HANDLE)
{
  return pmf;
}

template <class T>
inline void(T::*v_H_B_Sig(void(T::*pmf)(HANDLE, bool)))(HANDLE, bool)
{
  return pmf;
}

template <class T>
inline void(T::*v_HDC_Sig(void(T::*pmf)(HDC)))(HDC)
{
  return pmf;
}

template <class T>
inline void(T::*v_HFONT_B_Sig(void(T::*pmf)(HFONT, bool)))(HFONT, bool)
{
  return pmf;
}

template <class T>
inline void(T::*v_HMENU_Sig(void(T::*pmf)(HMENU)))(HMENU)
{
  return pmf;
}

template <class T>
inline void(T::*v_HMENU_U_B_Sig(void(T::*pmf)(HMENU, uint, bool)))(HMENU, uint, bool)
{
  return pmf;
}

template <class T>
inline void(T::*v_i_Sig(void(T::*pmf)(int)))(int)
{
  return pmf;
}

template <class T>
inline void(T::*v_MINMAXINFO_Sig(void(T::*pmf)(MINMAXINFO far&)))(MINMAXINFO far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_OWLDOCUMENT_Sig(void(T::*pmf)(TDocument&)))(TDocument&)
{
  return pmf;
}

template <class T>
inline void(T::*v_OWLVIEW_Sig(void(T::*pmf)(TView&)))(TView&)
{
  return pmf;
}

template <class T>
inline void(T::*v_POINT_Sig(void(T::*pmf)(TPoint&)))(TPoint&)
{
  return pmf;
}

template <class T>
inline void(T::*v_S_Sig(void(T::*pmf)(char far*)))(char far*)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_Sig(void(T::*pmf)(uint)))(uint)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_B_W_Sig(void(T::*pmf)(uint, bool, HWND)))(uint, bool, HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_DELETEITEM_Sig(void(T::*pmf)(uint, DELETEITEMSTRUCT far&)))
                                      (uint, DELETEITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_DRAWITEM_Sig(void(T::*pmf)(uint, DRAWITEMSTRUCT far&)))
                                      (uint, DRAWITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_MEASUREITEM_Sig(void(T::*pmf)(uint, MEASUREITEMSTRUCT far&)))
                                      (uint, MEASUREITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_POINT_Sig(void(T::*pmf)(uint, TPoint&)))(uint, TPoint&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_S_Sig(void(T::*pmf)(uint, char far*)))(uint, char far*)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_SIZE_Sig(void(T::*pmf)(uint, TSize&)))(uint, TSize&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_U_Sig(void(T::*pmf)(uint, uint)))(uint, uint)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_U_HMENU_Sig(void(T::*pmf)(uint, uint, HMENU)))(uint, uint, HMENU)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_U_U_Sig(void(T::*pmf)(uint, uint, uint)))(uint, uint, uint)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_U_W_Sig(void(T::*pmf)(uint, uint, HWND)))(uint, uint, HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_W_Sig(void(T::*pmf)(uint, HWND)))(uint, HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_W_Sig(void(T::*pmf)(HWND)))(HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_W_H_Sig(void(T::*pmf)(HWND, HANDLE)))(HWND, HANDLE)
{
  return pmf;
}

template <class T>
inline void(T::*v_W_U_U_Sig(void(T::*pmf)(HWND, uint, uint)))(HWND, uint, uint)
{
  return pmf;
}

template <class T>
inline void(T::*v_W_W_Sig(void(T::*pmf)(HWND, HWND)))(HWND, HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_WINDOWPOS_Sig(void(T::*pmf)(WINDOWPOS far&)))(WINDOWPOS far&)
{
  return pmf;
}

//
// Aliases for compatibility
//
#define LRESULT_WPARAM_LPARAM_Sig   I32_U_I32_Sig
#define B_LPARAM_Sig                B_I32_Sig
#define LRESULT_U_U_HMENU_Sig       I32_U_U_HMENU_Sig
#define LRESULT_U_COMPAREITEM_Sig   I32_U_COMPAREITEM_Sig
#define LRESULT_MDICREATESTRUCT_Sig I32_MDICREATESTRUCT_Sig

#endif  // OWL_SIGNATUR_H
