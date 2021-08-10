//--------------------------------------------------------
// DBCONTRL.CPP
// Copyrights (C) 1996 Borland International
// All rights reserved.
//--------------------------------------------------------

#include <owl/vbxctl.h>
#include <vdbt/dbevent.h>


//--------------------------------------------------------
// Dispatchaers
//--------------------------------------------------------
int32 _OWLFUNC
NotifyEvent_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(), uint, int32)
{
  (generic.*pmf)();
  return 0;
}

int32 _OWLFUNC
DragEvent_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(TVbxControl&, SHORT, SHORT), uint, int32 lParam)
{
  VBXEVENT FAR* e = (VBXEVENT FAR *) lParam;
  HWND hWnd = ::VBXGetHwnd( VBX_EVENTARGNUM( e, HCTL, 0 ) );
  TVbxControl *lpCtl
     = TYPESAFE_DOWNCAST( TWindow( e->Window ).GetApplication()->GetWindowPtr( hWnd )
                        , TVbxControl );

  (generic.*pmf)( *lpCtl
	        , VBX_EVENTARGNUM( e, SHORT, 1 )
	        , VBX_EVENTARGNUM( e, SHORT, 2 ) );
  return 0;
}

int32 _OWLFUNC
DragOver_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(TVbxControl&, SHORT, SHORT, TDragState), uint, int32 lParam)
{
  VBXEVENT FAR* e = (VBXEVENT FAR *) lParam;
  HWND hWnd = ::VBXGetHwnd( VBX_EVENTARGNUM( e, HCTL, 0 ) );
  TVbxControl *lpCtl
     = TYPESAFE_DOWNCAST( TWindow( e->Window ).GetApplication()->GetWindowPtr( hWnd )
                        , TVbxControl );

  (generic.*pmf)( *lpCtl
	        , VBX_EVENTARGNUM( e, SHORT, 1 )
	        , VBX_EVENTARGNUM( e, SHORT, 2 )
	        , TDragState( VBX_EVENTARGNUM( e, SHORT, 3 ) ) );
  return 0;
}

int32 _OWLFUNC
KeyEvent_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(SHORT*, TShiftState), uint, int32 lParam)
{
  VBXEVENT FAR* e = (VBXEVENT FAR *) lParam;

  (generic.*pmf)( &VBX_EVENTARGNUM( e, SHORT, 0 )
                , TShiftState( VBX_EVENTARGNUM( e, USHORT, 1 ) ) );
  return 0;
}

int32 _OWLFUNC
KeyPress_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(SHORT), uint, int32 lParam)
{
  VBXEVENT FAR* e = (VBXEVENT FAR *) lParam;

  (generic.*pmf)( VBX_EVENTARGNUM( e, SHORT, 0 ) );
  return 0;
}

int32 _OWLFUNC
MouseEvent_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(TMouseButton, TShiftState, SHORT, SHORT), uint, int32 lParam)
{
  VBXEVENT FAR* e = (VBXEVENT FAR *) lParam;

  (generic.*pmf)( TMouseButton( VBX_EVENTARGNUM( e, USHORT, 0 ) )
                , TShiftState( VBX_EVENTARGNUM( e, USHORT, 1 ) )
                , VBX_EVENTARGNUM( e, SHORT, 2 )
                , VBX_EVENTARGNUM( e, SHORT, 3 ) );
  return 0;
}

int32 _OWLFUNC
DrawItem_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(SHORT, TRect, TOwnerDrawState), uint, int32 lParam)
{
  VBXEVENT FAR* e = (VBXEVENT FAR *) lParam;

  (generic.*pmf)( VBX_EVENTARGNUM( e, SHORT, 0 )
                , TRect( VBX_EVENTARGNUM( e, SHORT, 1 )
                       , VBX_EVENTARGNUM( e, SHORT, 2 )
                       , VBX_EVENTARGNUM( e, SHORT, 3 )
                       , VBX_EVENTARGNUM( e, SHORT, 4 ) )
                , TOwnerDrawState( VBX_EVENTARGNUM( e, USHORT, 5 ) ) );
  return 0;
}

int32 _OWLFUNC
MeasureItem_Dispatch(GENERIC& generic, void (GENERIC::*pmf)(SHORT, SHORT*), uint, int32 lParam)
{
  VBXEVENT FAR* e = (VBXEVENT FAR *) lParam;

  (generic.*pmf)( VBX_EVENTARGNUM( e, SHORT, 0 )
                , &VBX_EVENTARGNUM( e, SHORT, 1 ) );
  return 0;
}

