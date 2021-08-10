//--------------------------------------------------------
// DBLKUPLB.CPP
// Copyright (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbcontrl.h>
#pragma hdrstop
#include <vdbt/dblkuplb.h>

//--------------------------------------------------------
// TDBLookupList (VB3, subclassed from LISTBOX)
//--------------------------------------------------------
TDBLookupList::TDBLookupList( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBLookupList", title, x, y, w, h, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnKeyDown )
  , INIT_SOURCE( OnKeyPress )
  , INIT_SOURCE( OnKeyUp )
{
}

TDBLookupList::TDBLookupList( TWindow *parent, int resourceId, TModule *module )
  : TDBControl( parent, resourceId, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnKeyDown )
  , INIT_SOURCE( OnKeyPress )
  , INIT_SOURCE( OnKeyUp )
{
}


//--------------------------------------------------------
// OWL response table
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBLookupList, TDBControl )
  EV_VBXEVENT_CLICK,
  EV_VBXEVENT_DRAGOVER,
  EV_VBXEVENT_DRAGDROP,
  EV_VBXEVENT_ENDDRAG,
  EV_VBXEVENT_DBLCLICK( Event_TDBLookupList_DblClick ),
  EV_VBXEVENT_KEYDOWN(  Event_TDBLookupList_KeyDown ),
  EV_VBXEVENT_KEYPRESS( Event_TDBLookupList_KeyPress ),
  EV_VBXEVENT_KEYUP(    Event_TDBLookupList_KeyUp ),
  EV_VBXEVENT_ENTER(    Event_TDBLookupList_GotFocus ),
  EV_VBXEVENT_EXIT(     Event_TDBLookupList_LostFocus ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBLookupList, OnClick,     TNotifyEvent,   Event_TDBLookupList_Click );
DEFINE_DB_EVENT( TDBLookupList, OnDragDrop,  TDragEvent,     Event_TDBLookupList_DragDrop );
DEFINE_DB_EVENT( TDBLookupList, OnDragOver,  TDragOverEvent, Event_TDBLookupList_DragOver );
DEFINE_DB_EVENT( TDBLookupList, OnEndDrag,   TDragEvent,     Event_TDBLookupList_EndDrag );
DEFINE_DB_EVENT( TDBLookupList, OnDblClick, TNotifyEvent,   Event_TDBLookupList_DblClick );
DEFINE_DB_EVENT( TDBLookupList, OnEnter,    TNotifyEvent,   Event_TDBLookupList_GotFocus );
DEFINE_DB_EVENT( TDBLookupList, OnExit,     TNotifyEvent,   Event_TDBLookupList_LostFocus );
DEFINE_DB_EVENT( TDBLookupList, OnKeyDown,  TKeyEvent,      Event_TDBLookupList_KeyDown );
DEFINE_DB_EVENT( TDBLookupList, OnKeyPress, TKeyPressEvent, Event_TDBLookupList_KeyPress );
DEFINE_DB_EVENT( TDBLookupList, OnKeyUp,    TKeyEvent,      Event_TDBLookupList_KeyUp );

