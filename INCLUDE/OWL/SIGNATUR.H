//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\signatur.h
//   Message cracking signature templates
//----------------------------------------------------------------------------
#if !defined(__OWL_SIGNATUR_H)
#define __OWL_SIGNATUR_H

#if !defined(__OWL_OWLDEFS_H)
  #include <owl\owldefs.h>
#endif

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

class _OWLCLASS TCommandEnabler;
class _OWLCLASS TDocument;
class _OWLCLASS TView;
class TDropInfo;
class TPoint;
class TSize;

template <class T>
inline LRESULT(T::*LRESULT_WPARAM_LPARAM_Sig(LRESULT(T::*pmf)(WPARAM, LPARAM)))
                                                 (WPARAM, LPARAM)
{
  return pmf;
}

template <class T>
inline void(T::*v_Sig(void(T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline void(T::*v_U_S_Sig(void(T::*pmf)(UINT, LPSTR)))(UINT, LPSTR)
{
  return pmf;
}

template <class T>
inline void(T::*v_W_W_Sig(void(T::*pmf)(HWND, HWND)))(HWND, HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_U_U_Sig(void(T::*pmf)(UINT, UINT, UINT)))(UINT, UINT, UINT)
{
  return pmf;
}

template <class T>
inline int(T::*i_CREATE_Sig(int(T::*pmf)(CREATESTRUCT far&)))(CREATESTRUCT far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_B_Sig(void(T::*pmf)(BOOL)))(BOOL)
{
  return pmf;
}

template <class T>
inline BOOL(T::*B_HDC_Sig(BOOL(T::*pmf)(HDC)))(HDC)
{
  return pmf;
}

template <class T>
inline BOOL(T::*B_LPARAM_Sig(BOOL(T::*pmf)(LPARAM)))(LPARAM)
{
  return pmf;
}

template <class T>
inline void(T::*v_MINMAXINFO_Sig(void(T::*pmf)(MINMAXINFO far&)))(MINMAXINFO far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_U_W_Sig(void(T::*pmf)(UINT, UINT, HWND)))(UINT, UINT, HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_U_HMENU_Sig(void(T::*pmf)(UINT, UINT, HMENU)))(UINT, UINT, HMENU)
{
  return pmf;
}

template <class T>
inline void(T::*v_W_U_U_Sig(void(T::*pmf)(HWND, UINT, UINT)))(HWND, UINT, UINT)
{
  return pmf;
}

template <class T>
inline void(T::*v_H_Sig(void(T::*pmf)(HANDLE)))(HANDLE)
{
  return pmf;
}

template <class T>
inline void(T::*v_H_B_Sig(void(T::*pmf)(HANDLE, BOOL)))(HANDLE, BOOL)
{
  return pmf;
}

template <class T>
inline void(T::*v_HDC_Sig(void(T::*pmf)(HDC)))(HDC)
{
  return pmf;
}

template <class T>
inline void(T::*v_DROP_Sig(void(T::*pmf)(TDropInfo)))(TDropInfo)
{
  return pmf;
}

template <class T>
inline void(T::*v_W_Sig(void(T::*pmf)(HWND)))(HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_POINT_Sig(void(T::*pmf)(UINT, TPoint&)))(UINT, TPoint&)
{
  return pmf;
}

template <class T>
inline LRESULT(T::*LRESULT_U_U_HMENU_Sig(LRESULT(T::*pmf)(UINT, UINT, HMENU)))(UINT, UINT, HMENU)
{
  return pmf;
}

template <class T>
inline UINT(T::*U_W_U_U_Sig(UINT(T::*pmf)(HWND, UINT, UINT)))(HWND, UINT, UINT)
{
  return pmf;
}

template <class T>
inline void(T::*v_POINT_Sig(void(T::*pmf)(TPoint&)))(TPoint&)
{
  return pmf;
}

template <class T>
inline BOOL(T::*B_B_Sig(BOOL(T::*pmf)(BOOL)))(BOOL)
{
  return pmf;
}

template <class T>
inline UINT(T::*U_B_CALCSIZE_Sig(UINT(T::*pmf)(BOOL, NCCALCSIZE_PARAMS far&)))
                                     (BOOL, NCCALCSIZE_PARAMS far&)
{
  return pmf;
}

template <class T>
inline BOOL(T::*B_CREATE_Sig(BOOL(T::*pmf)(CREATESTRUCT far&)))(CREATESTRUCT far&)
{
  return pmf;
}

template <class T>
inline UINT(T::*U_MSG_Sig(UINT(T::*pmf)(MSG far*)))(MSG far*)
{
  return pmf;
}

template <class T>
inline UINT(T::*U_POINT_Sig(UINT(T::*pmf)(TPoint&)))(TPoint&)
{
  return pmf;
}

template <class T>
inline void(T::*v_W_H_Sig(void(T::*pmf)(HWND, HANDLE)))(HWND, HANDLE)
{
  return pmf;
}

template <class T>
inline UINT(T::*U_Sig(UINT(T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline HANDLE(T::*H_Sig(HANDLE(T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline BOOL(T::*B_Sig(BOOL(T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline BOOL(T::*B_W_U_U_Sig(BOOL(T::*pmf)(HWND, UINT, UINT)))(HWND, UINT, UINT)
{
  return pmf;
}

template <class T>
inline void(T::*v_B_U_Sig(void(T::*pmf)(BOOL, UINT)))(BOOL, UINT)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_Sig(void(T::*pmf)(UINT)))(UINT)
{
  return pmf;
}

template <class T>
inline void(T::*v_i_Sig(void(T::*pmf)(int)))(int)
{
  return pmf;
}

template <class T>
inline void(T::*v_WINDOWPOS_Sig(void(T::*pmf)(WINDOWPOS far&)))(WINDOWPOS far&)
{
  return pmf;
}

template <class T>
inline int(T::*i_U_W_U_Sig(int(T::*pmf)(UINT, HWND, UINT)))(UINT, HWND, UINT)
{
  return pmf;
}

template <class T>
inline void(T::*v_S_Sig(void(T::*pmf)(LPSTR)))(LPSTR)
{
  return pmf;
}

template <class T>
inline LRESULT(T::*LRESULT_U_COMPAREITEM_Sig(LRESULT(T::*pmf)(UINT, COMPAREITEMSTRUCT far&)))
                                      (UINT, COMPAREITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_DELETEITEM_Sig(void(T::*pmf)(UINT, DELETEITEMSTRUCT far&)))
                                      (UINT, DELETEITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_DRAWITEM_Sig(void(T::*pmf)(UINT, DRAWITEMSTRUCT far&)))
                                      (UINT, DRAWITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_MEASUREITEM_Sig(void(T::*pmf)(UINT, MEASUREITEMSTRUCT far&)))
                                      (UINT, MEASUREITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_U_Sig(void(T::*pmf)(UINT, UINT)))(UINT, UINT)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_SIZE_Sig(void(T::*pmf)(UINT, TSize&)))(UINT, TSize&)
{
  return pmf;
}

template <class T>
inline void(T::*v_B_HTASK_Sig(void(T::*pmf)(BOOL, HTASK)))(BOOL, HTASK)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_B_W_Sig(void(T::*pmf)(UINT, BOOL, HWND)))(UINT, BOOL, HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_U_W_Sig(void(T::*pmf)(UINT, HWND)))(UINT, HWND)
{
  return pmf;
}

template <class T>
inline void(T::*v_HMENU_Sig(void(T::*pmf)(HMENU)))(HMENU)
{
  return pmf;
}

template <class T>
inline void(T::*v_HMENU_U_B_Sig(void(T::*pmf)(HMENU, UINT, BOOL)))(HMENU, UINT, BOOL)
{
  return pmf;
}

template <class T>
inline void(T::*v_B_W_W_Sig(void(T::*pmf)(BOOL, HWND, HWND)))(BOOL, HWND, HWND)
{
  return pmf;
}

template <class T>
inline int(T::*i_U_Sig(int(T::*pmf)(UINT)))(UINT)
{
  return pmf;
}

template <class T>
inline HBRUSH(T::*HBRUSH_HDC_W_U_Sig(HBRUSH(T::*pmf)(HDC, HWND, UINT)))(HDC, HWND, UINT)
{
  return pmf;
}

template <class T>
inline LRESULT(T::*LRESULT_MDICREATESTRUCT_Sig(LRESULT(T::*pmf)(MDICREATESTRUCT far&)))(MDICREATESTRUCT far&)
{
  return pmf;
}

template <class T>
inline void(T::*v_COMMANDENABLER_Sig(void(T::*pmf)(TCommandEnabler&)))(TCommandEnabler&)
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

#endif  // __OWL_SIGNATUR_H
