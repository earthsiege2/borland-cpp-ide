//--------------------------------------------------------
// DBRADIO.CPP
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbcontrl.h>
#pragma hdrstop
#include <vdbt/dbradio.h>

//--------------------------------------------------------
// TDBRadioGroup (VB3)
//--------------------------------------------------------
TDBRadioGroup::TDBRadioGroup( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBRadioGroup", title, x, y, w, h, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnChange )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
{
}

TDBRadioGroup::TDBRadioGroup( TWindow *parent, int resourceId, TModule *module )
  : TDBControl( parent, resourceId, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnChange )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
{
}


//--------------------------------------------------------
// OWL response table
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBRadioGroup, TDBControl )
  EV_VBXEVENT_CLICK,
  EV_VBXEVENT_DRAGOVER,
  EV_VBXEVENT_DRAGDROP,
  EV_VBXEVENT_ENDDRAG,
  EV_VBXEVENT_DBLCLICK( Event_TDBRadioGroup_DblClick ),
  EV_VBXEVENT_ENTER(    Event_TDBRadioGroup_GotFocus ),
  EV_VBXEVENT_EXIT(     Event_TDBRadioGroup_LostFocus ),
  EV_VBXEVENT_CHANGE(   Event_TDBRadioGroup_Change ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBRadioGroup, OnClick,     TNotifyEvent,   Event_TDBRadioGroup_Click );
DEFINE_DB_EVENT( TDBRadioGroup, OnDragDrop,  TDragEvent,     Event_TDBRadioGroup_DragDrop );
DEFINE_DB_EVENT( TDBRadioGroup, OnDragOver,  TDragOverEvent, Event_TDBRadioGroup_DragOver );
DEFINE_DB_EVENT( TDBRadioGroup, OnEndDrag,   TDragEvent,     Event_TDBRadioGroup_EndDrag );
DEFINE_DB_EVENT( TDBRadioGroup, OnChange,   TNotifyEvent, Event_TDBRadioGroup_Change );
DEFINE_DB_EVENT( TDBRadioGroup, OnDblClick, TNotifyEvent, Event_TDBRadioGroup_DblClick );
DEFINE_DB_EVENT( TDBRadioGroup, OnEnter,    TNotifyEvent, Event_TDBRadioGroup_GotFocus );
DEFINE_DB_EVENT( TDBRadioGroup, OnExit,     TNotifyEvent, Event_TDBRadioGroup_LostFocus );

