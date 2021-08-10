//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.7  $
//
// Message handler signature templates
//----------------------------------------------------------------------------
#if !defined(OWL_SIGNATUR_H)
#define OWL_SIGNATUR_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TCommandEnabler;
class _OWLCLASS TDocument;
class _OWLCLASS TView;
//class TDropInfo;
//class TPoint;
//class TSize;

//----------------------------------------------------------------------------
//  LEGEND: in order to keep signature names from getting too long, the
//          following abbreviations are used for the data types passed to and
//          returned from the methods. The first code is the return type, the
//          rest are args in left to right order.
//
//  - v   (void return)
//  - i,I (int)
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
inline bool _CALLCNVN (T::*B_Sig(bool _CALLCNVN (T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_B_Sig(bool _CALLCNVN (T::*pmf)(bool)))(bool)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_I_Sig(bool _CALLCNVN (T::*pmf)(int)))(int)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_CREATE_Sig(bool _CALLCNVN (T::*pmf)(CREATESTRUCT far&)))(CREATESTRUCT far&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_CS_Sig(bool _CALLCNVN (T::*pmf)(const char far*)))(const char far*)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_MSG_Sig(bool _CALLCNVN (T::*pmf)(MSG far*)))(MSG far*)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_RECT_Sig(bool _CALLCNVN (T::*pmf)(TRect far*)))(TRect far*)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_U_RECT_Sig(bool _CALLCNVN (T::*pmf)(uint,TRect&)))(uint,TRect&)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_U_U_Sig(bool _CALLCNVN (T::*pmf)(uint,uint)))(uint,uint)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_W_U_U_Sig(bool _CALLCNVN (T::*pmf)(HWND, uint, uint)))(HWND, uint, uint)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_HDC_Sig(bool _CALLCNVN (T::*pmf)(HDC)))(HDC)
{
  return pmf;
}

#if defined(BI_PLAT_WIN32)
template <class T>
inline bool _CALLCNVN (T::*B_B_HKL_Sig(bool _CALLCNVN (T::*pmf)(bool, HKL)))(bool, HKL)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_I_HKL_Sig(bool _CALLCNVN (T::*pmf)(int, HKL)))(int, HKL)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_HELPINFO_Sig(void _CALLCNVN (T::*pmf)(HELPINFO&)))(HELPINFO&)
{
  return pmf;
}

#endif  // defined(BI_PLAT_WIN32)

template <class T>
inline void _CALLCNVN (T::*v_HRGN_Sig(void _CALLCNVN (T::*pmf)(HRGN)))(HRGN)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_B_I_I_Sig(void _CALLCNVN (T::*pmf)(bool, int, int)))(bool, int, int)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_I32_Sig(bool _CALLCNVN (T::*pmf)(int32)))(int32)
{
  return pmf;
}

template <class T>
inline bool _CALLCNVN (T::*B_PPALETTE_Sig(bool _CALLCNVN (T::*pmf)(LOGPALETTE far* far*)))(LOGPALETTE far* far*)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline const char far* _CALLCNVN (T::*CS_Sig(const char far* _CALLCNVN (T::*pmf)()))()
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline HANDLE _CALLCNVN (T::*H_Sig(HANDLE _CALLCNVN (T::*pmf)()))()
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline HBRUSH _CALLCNVN (T::*HBRUSH_HDC_W_U_Sig(HBRUSH _CALLCNVN (T::*pmf)(HDC, HWND, uint)))(HDC, HWND, uint)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline HFONT _CALLCNVN (T::*HFONT_Sig(HFONT _CALLCNVN (T::*pmf)()))()
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline HICON _CALLCNVN (T::*HICON_B_Sig(HICON _CALLCNVN (T::*pmf)(bool)))(bool)
{
  return pmf;
}

template <class T>
inline HICON _CALLCNVN (T::*HICON_B_HICON_Sig(HICON _CALLCNVN (T::*pmf)(bool, HICON)))(bool, HICON)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline int _CALLCNVN (T::*i_CREATE_Sig(int _CALLCNVN (T::*pmf)(CREATESTRUCT far&)))(CREATESTRUCT far&)
{
  return pmf;
}

template <class T>
inline int _CALLCNVN (T::*i_U_Sig(int _CALLCNVN (T::*pmf)(uint)))(uint)
{
  return pmf;
}

template <class T>
inline int _CALLCNVN (T::*i_U_W_U_Sig(int _CALLCNVN (T::*pmf)(uint, HWND, uint)))(uint, HWND, uint)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline int32 _CALLCNVN (T::*I32_MDICREATESTRUCT_Sig(int32 _CALLCNVN (T::*pmf)(MDICREATESTRUCT far&)))
                                        (MDICREATESTRUCT far&)
{
  return pmf;
}

template <class T>
inline int32 _CALLCNVN (T::*I32_U_COMPAREITEM_Sig(int32 _CALLCNVN (T::*pmf)(uint, COMPAREITEMSTRUCT far&)))
                                      (uint, COMPAREITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline int32 _CALLCNVN (T::*I32_U_I32_Sig(int32 _CALLCNVN (T::*pmf)(uint, int32)))(uint, int32)
{
  return pmf;
}

template <class T>
inline int32 _CALLCNVN (T::*I32_U_U_HMENU_Sig(int32 _CALLCNVN (T::*pmf)(uint, uint, HMENU)))(uint, uint, HMENU)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline uint32 _CALLCNVN (T::*U32_VOIDFP_Sig(uint32 _CALLCNVN (T::*pmf)(void far*)))(void far*)
{
  return pmf;
}

template <class T>
inline uint32 _CALLCNVN (T::*U32_Sig(uint32 _CALLCNVN (T::*pmf)()))()
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline uint _CALLCNVN (T::*U_Sig(uint _CALLCNVN (T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline uint _CALLCNVN (T::*U_B_CALCSIZE_Sig(uint _CALLCNVN (T::*pmf)(bool, NCCALCSIZE_PARAMS far&)))
                                (bool, NCCALCSIZE_PARAMS far&)
{
  return pmf;
}

template <class T>
inline uint _CALLCNVN (T::*U_MSG_Sig(uint _CALLCNVN (T::*pmf)(MSG far*)))(MSG far*)
{
  return pmf;
}

template <class T>
inline uint _CALLCNVN (T::*U_POINT_Sig(uint _CALLCNVN (T::*pmf)(TPoint&)))(TPoint&)
{
  return pmf;
}

template <class T>
inline uint _CALLCNVN (T::*U_W_U_U_Sig(uint _CALLCNVN (T::*pmf)(HWND, uint, uint)))(HWND, uint, uint)
{
  return pmf;
}

//----------------------------------------------------------------------------

template <class T>
inline void _CALLCNVN (T::*v_Sig(void _CALLCNVN (T::*pmf)()))()
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_B_Sig(void _CALLCNVN (T::*pmf)(bool)))(bool)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_B_B_Sig(void _CALLCNVN (T::*pmf)(bool, bool)))(bool, bool)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_B_HTASK_Sig(void _CALLCNVN (T::*pmf)(bool, HTASK)))(bool, HTASK)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_B_U_Sig(void _CALLCNVN (T::*pmf)(bool, uint)))(bool, uint)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_B_W_W_Sig(void _CALLCNVN (T::*pmf)(bool, HWND, HWND)))(bool, HWND, HWND)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_COMMANDENABLER_Sig(void _CALLCNVN (T::*pmf)(TCommandEnabler&)))(TCommandEnabler&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_CS_Sig(void _CALLCNVN (T::*pmf)(const char far*)))(const char far*)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_DROP_Sig(void _CALLCNVN (T::*pmf)(TDropInfo)))(TDropInfo)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_H_Sig(void _CALLCNVN (T::*pmf)(HANDLE)))(HANDLE)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_H_B_Sig(void _CALLCNVN (T::*pmf)(HANDLE, bool)))(HANDLE, bool)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_HDC_Sig(void _CALLCNVN (T::*pmf)(HDC)))(HDC)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_HDC_U_Sig(void _CALLCNVN (T::*pmf)(HDC,uint)))(HDC,uint)
{
  return pmf;
}

#if defined(BI_PLAT_WIN32)
template <class T>
inline void _CALLCNVN (T::*v_HELPINFO_Sig(void _CALLCNVN (T::*pmf)(HELPINFO far*)))(HELPINFO far*)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_HWND_PCOPYDATASTRUCT_Sig(void _CALLCNVN (T::*pmf)(HWND,COPYDATASTRUCT*)))(HWND,COPYDATASTRUCT*)
{
  return pmf;
}
#endif

template <class T>
inline void _CALLCNVN (T::*v_HFONT_B_Sig(void _CALLCNVN (T::*pmf)(HFONT, bool)))(HFONT, bool)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_HMENU_Sig(void _CALLCNVN (T::*pmf)(HMENU)))(HMENU)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_HMENU_U_B_Sig(void _CALLCNVN (T::*pmf)(HMENU, uint, bool)))(HMENU, uint, bool)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_i_Sig(void _CALLCNVN (T::*pmf)(int)))(int)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_MINMAXINFO_Sig(void _CALLCNVN (T::*pmf)(MINMAXINFO far&)))(MINMAXINFO far&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_OWLDOCUMENT_Sig(void _CALLCNVN (T::*pmf)(TDocument&)))(TDocument&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_OWLVIEW_Sig(void _CALLCNVN (T::*pmf)(TView&)))(TView&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_POINT_Sig(void _CALLCNVN (T::*pmf)(TPoint&)))(TPoint&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_S_Sig(void _CALLCNVN (T::*pmf)(char far*)))(char far*)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_Sig(void _CALLCNVN (T::*pmf)(uint)))(uint)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_B_W_Sig(void _CALLCNVN (T::*pmf)(uint, bool, HWND)))(uint, bool, HWND)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_CS_Sig(void _CALLCNVN (T::*pmf)(uint, const char far*)))(uint, const char far*)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_DELETEITEM_Sig(void _CALLCNVN (T::*pmf)(uint, DELETEITEMSTRUCT far&)))
                                      (uint, DELETEITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_DRAWITEM_Sig(void _CALLCNVN (T::*pmf)(uint, DRAWITEMSTRUCT far&)))
                                      (uint, DRAWITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_MEASUREITEM_Sig(void _CALLCNVN (T::*pmf)(uint, MEASUREITEMSTRUCT far&)))
                                      (uint, MEASUREITEMSTRUCT far&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_POINT_Sig(void _CALLCNVN (T::*pmf)(uint, TPoint&)))(uint, TPoint&)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_S_Sig(void _CALLCNVN (T::*pmf)(uint, char far*)))(uint, char far*)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_SIZE_Sig(void _CALLCNVN (T::*pmf)(uint, TSize&)))(uint, TSize&)
{
  return pmf;
}

#if defined(BI_PLAT_WIN32)
template <class T>
inline void _CALLCNVN (T::*v_U_STYLE_Sig(void _CALLCNVN (T::*pmf)(uint, STYLESTRUCT far*)))(uint, STYLESTRUCT far*)
{
  return pmf;
}
#endif

template <class T>
inline void _CALLCNVN (T::*v_U_U_Sig(void _CALLCNVN (T::*pmf)(uint, uint)))(uint, uint)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_U_HMENU_Sig(void _CALLCNVN (T::*pmf)(uint, uint, HMENU)))(uint, uint, HMENU)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_U_U_Sig(void _CALLCNVN (T::*pmf)(uint, uint, uint)))(uint, uint, uint)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_U_W_Sig(void _CALLCNVN (T::*pmf)(uint, uint, HWND)))(uint, uint, HWND)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_U_W_Sig(void _CALLCNVN (T::*pmf)(uint, HWND)))(uint, HWND)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_W_Sig(void _CALLCNVN (T::*pmf)(HWND)))(HWND)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_W_H_Sig(void _CALLCNVN (T::*pmf)(HWND, HANDLE)))(HWND, HANDLE)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_W_I_I_Sig(void _CALLCNVN (T::*pmf)(HWND, int, int)))(HWND, int, int)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_W_U_U_Sig(void _CALLCNVN (T::*pmf)(HWND, uint, uint)))(HWND, uint, uint)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_W_W_Sig(void _CALLCNVN (T::*pmf)(HWND, HWND)))(HWND, HWND)
{
  return pmf;
}

template <class T>
inline void _CALLCNVN (T::*v_WINDOWPOS_Sig(void _CALLCNVN (T::*pmf)(WINDOWPOS far&)))(WINDOWPOS far&)
{
  return pmf;
}

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//
// Aliases for compatibility
//
#define LRESULT_WPARAM_LPARAM_Sig   I32_U_I32_Sig
#define B_LPARAM_Sig                B_I32_Sig
#define LRESULT_U_U_HMENU_Sig       I32_U_U_HMENU_Sig
#define LRESULT_U_COMPAREITEM_Sig   I32_U_COMPAREITEM_Sig
#define LRESULT_MDICREATESTRUCT_Sig I32_MDICREATESTRUCT_Sig

#endif  // OWL_SIGNATUR_H
