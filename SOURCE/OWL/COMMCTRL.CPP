//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// Implementation of TCommCtrlDll, a wrapper for the common control dll
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif

//
// Common Controls diagnostic group
//
DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlCommCtrl, 1, 0);

#if defined(BI_PLAT_WIN16)
  static char CommCtrlDllName[] = "COMMCTRL.DLL";
#else
  static char CommCtrlDllName[] = "COMCTL32.DLL";
#endif

//
//
//
TCommCtrlDll::TCommCtrlDll()
:
  TModule(CommCtrlDllName, true, true),

#if defined(BI_PLAT_WIN32)
  ImageList_AddMasked(*this, "ImageList_AddMasked"),
  ImageList_BeginDrag(*this, "ImageList_BeginDrag"),
  ImageList_DragEnter(*this, "ImageList_DragEnter"),
  ImageList_DragLeave(*this, "ImageList_DragLeave"),
  ImageList_DragMove(*this, "ImageList_DragMove"),
  ImageList_DrawEx(*this, "ImageList_DrawEx"),
  ImageList_GetDragImage(*this, "ImageList_GetDragImage"),
  ImageList_GetIcon(*this, "ImageList_GetIcon"),
  ImageList_GetIconSize(*this, "ImageList_GetIconSize"),
  ImageList_GetImageInfo(*this, "ImageList_GetImageInfo"),
  ImageList_LoadImage(*this, "ImageList_LoadImage"),
  ImageList_Merge(*this, "ImageList_Merge"),
  ImageList_Remove(*this, "ImageList_Remove"),
  ImageList_Replace(*this, "ImageList_Replace"),
  ImageList_SetDragCursorImage(*this, "ImageList_SetDragCursorImage"),
  ImageList_SetIconSize(*this, "ImageList_SetIconSize"),
  ImageList_DragShowNolock(*this, "ImageList_DragShowNolock"),
  ImageList_EndDrag(*this, "ImageList_EndDrag"),
#endif
  CreateMappedBitmap(*this, "CreateMappedBitmap"),
  CreatePropertySheetPage(*this, "CreatePropertySheetPage"),
  CreateStatusWindow(*this, "CreateStatusWindow"),
  CreateToolbarEx(*this, "CreateToolbarEx"),
  CreateUpDownControl(*this, "CreateUpDownControl"),
  DestroyPropertySheetPage(*this, "DestroyPropertySheetPage"),
  DrawInsert(*this, "DrawInsert"),
  DrawStatusText(*this, "DrawStatusText"),
  GetEffectiveClientRect(*this, "GetEffectiveClientRect"),
  ImageList_Add(*this, "ImageList_Add"),
  ImageList_Create(*this, "ImageList_Create"),
  ImageList_Destroy(*this, "ImageList_Destroy"),
  ImageList_Draw(*this, "ImageList_Draw"),
  ImageList_GetBkColor(*this, "ImageList_GetBkColor"),
  ImageList_GetImageCount(*this, "ImageList_GetImageCount"),
  ImageList_ReplaceIcon(*this, "ImageList_ReplaceIcon"),
  ImageList_SetBkColor(*this, "ImageList_SetBkColor"),
  ImageList_SetOverlayImage(*this, "ImageList_SetOverlayImage"),
  InitCommonControls(*this, "InitCommonControls"),
  LBItemFromPt(*this, "LBItemFromPt"),
  MakeDragList(*this, "MakeDragList"),
  MenuHelp(*this, "MenuHelp"),
  PropertySheet(*this, "PropertySheet"),
  ShowHideMenuCtl(*this, "ShowHideMenuCtl")
{
  // Do the initialization now that the Dll is loaded
  //
  InitCommonControls();
}



//
//
//
TCommCtrlDll* 
TCommCtrl::Dll()
{
  static TDllLoader<TCommCtrlDll> ccDll;
  return ccDll.Dll();
}

//
//
//
bool          
TCommCtrl::IsAvailable()
{
#if defined(BI_PLAT_WIN16)

  // For debugging purposes only
  //
# if defined(__OWL_NO_COMMCTRL)
    return false;
# endif

  // Some versions of Win 3.1x (eg. Windows for Workgroups) contain a 
  // COMMCTRL.DLL file. However, that module does not provide the API
  // documented as available from the Win95 and NT 3.51 versions of
  // the Common Control Library.
  //
  if (TSystem::IsWoW() || !TSystem::IsWin95())
    return false;
  return Dll() != 0;
#elif defined(BI_PLAT_WIN32)
  return Dll() != 0;
#endif
}

//----------------------------------------------------------------------------

//
// Constructor of the Object thrown by the CommonControl wrappers of
// ObjectWindows
//
TXCommCtrl::TXCommCtrl()
:
  TXOwl(IDS_COMMCTRL)
{
}

//
// Route to copy an exception object. The 'Clone' method is invoked when
// an exception must be suspended. The cloned copy can latter be used to 
// resume the exception.
//
#if defined(BI_NO_COVAR_RET)
TXBase*
#else
TXCommCtrl*
#endif
TXCommCtrl::Clone()
{
  return new TXCommCtrl(*this);
}

//
// Method to localize the actual call to 'throw' an TXCommCtrl object.
// NOTE: Localizing the call to 'throw' is a size optimization: the
//       overhead of a 'throw' statement is generated only once.
//
void
TXCommCtrl::Throw()
{
  THROW( *this );
}

//
// Construct a TXCommCtrl exception from scratch, and throw it
//
void
TXCommCtrl::Raise()
{
  TXCommCtrl().Throw();
}

//----------------------------------------------------------------------------
// DISPATCH.CPP
//
int32 _OWLFUNC
v_NMHDRCode_Dispatch(GENERIC& generic,
                     void    (GENERIC::*pmf)(uint),
                     uint     /*param1*/,
                     int32    param2)
{
  (generic.*pmf)((LPNMHDR(param2))->code);
  return 0;
}
