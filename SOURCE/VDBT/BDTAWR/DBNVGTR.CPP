//--------------------------------------------------------
// DBNVGTR.CPP
// Copyright (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbcontrl.h>
#pragma hdrstop
#include <vdbt/dbnvgtr.h>

//--------------------------------------------------------
// TDBNavigator (VB3)
//--------------------------------------------------------
TDBNavigator::TDBNavigator( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBNavigator", title, x, y, w, h, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnReSize )
{
}

TDBNavigator::TDBNavigator( TWindow *parent, int resourceId, TModule *module )
  : TDBControl( parent, resourceId, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnReSize )
{
}


//--------------------------------------------------------
// OWL response table
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBNavigator, TDBControl )
  EV_VBXEVENT_NAVCLICK,
  EV_VBXEVENT_DRAGOVER,
  EV_VBXEVENT_DRAGDROP,
  EV_VBXEVENT_ENDDRAG,
  EV_VBXEVENT_DBLCLICK( Event_TDBNavigator_DblClick ),
  EV_VBXEVENT_ENTER(    Event_TDBNavigator_GotFocus ),
  EV_VBXEVENT_EXIT(     Event_TDBNavigator_LostFocus ),
  EV_VBXEVENT_NAVRESIZE,
  EV_VBXEVENT_NAVCLICK,
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBNavigator, OnClick,    TNavClick,      Event_TDBNavigator_ReSize + 1 );
DEFINE_DB_EVENT( TDBNavigator, OnDragDrop, TDragEvent,     Event_TDBNavigator_DragDrop );
DEFINE_DB_EVENT( TDBNavigator, OnDragOver, TDragOverEvent, Event_TDBNavigator_DragOver );
DEFINE_DB_EVENT( TDBNavigator, OnEndDrag,  TDragEvent,     Event_TDBNavigator_EndDrag );
DEFINE_DB_EVENT( TDBNavigator, OnDblClick, TNotifyEvent,   Event_TDBNavigator_DblClick );
DEFINE_DB_EVENT( TDBNavigator, OnEnter,    TNotifyEvent,   Event_TDBNavigator_GotFocus );
DEFINE_DB_EVENT( TDBNavigator, OnExit,     TNotifyEvent,   Event_TDBNavigator_LostFocus );
DEFINE_DB_EVENT( TDBNavigator, OnReSize,   TNotifyEvent,   Event_TDBNavigator_ReSize );


//--------------------------------------------------------
// Dispatchaers
//--------------------------------------------------------
int32 _OWLFUNC
NavClick_Dispatch(GENERIC& gnrc, void (GENERIC::*pmf)(TNavigateBtn), uint, int32)
{
  (gnrc.*pmf)( ((TDBNavigator&)gnrc).ClickButton );
  return 0;
}

