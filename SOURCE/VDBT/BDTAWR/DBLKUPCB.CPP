//--------------------------------------------------------
// DBLKUPCB.CPP
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dblkupcb.h>

//--------------------------------------------------------
// TDBLookupCombo (VB3, subclassed from COMBOBOX)
//--------------------------------------------------------
TDBLookupCombo::TDBLookupCombo( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBLookupCombo", title, x, y, w, h, module )
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
  , INIT_SOURCE( OnMouseDown )
  , INIT_SOURCE( OnMouseMove )
  , INIT_SOURCE( OnMouseUp )
  , INIT_SOURCE( OnChange )
  , INIT_SOURCE( OnDropDown )
{
}

TDBLookupCombo::TDBLookupCombo( TWindow *parent, int resId, TModule *module )
  : TDBControl( parent, resId, module )
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
  , INIT_SOURCE( OnMouseDown )
  , INIT_SOURCE( OnMouseMove )
  , INIT_SOURCE( OnMouseUp )
  , INIT_SOURCE( OnChange )
  , INIT_SOURCE( OnDropDown )
{
}


//--------------------------------------------------------
// OWL response table
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBLookupCombo, TDBControl )
  EV_VBXEVENT_DBLCLICK(  Event_TDBLookupCombo_DblClick ),
  EV_VBXEVENT_KEYDOWN(   Event_TDBLookupCombo_KeyDown ),
  EV_VBXEVENT_KEYPRESS(  Event_TDBLookupCombo_KeyPress ),
  EV_VBXEVENT_KEYUP(     Event_TDBLookupCombo_KeyUp ),
  EV_VBXEVENT_ENTER(     Event_TDBLookupCombo_GotFocus ),
  EV_VBXEVENT_EXIT(      Event_TDBLookupCombo_LostFocus ),
  EV_VBXEVENT_MOUSEDOWN( Event_TDBLookupCombo_MouseDown ),
  EV_VBXEVENT_MOUSEMOVE( Event_TDBLookupCombo_MouseMove ),
  EV_VBXEVENT_MOUSEUP(   Event_TDBLookupCombo_MouseUp ),
  EV_VBXEVENT_CHANGE(    Event_TDBLookupCombo_Change ),
  EV_VBXEVENT_DROPDOWN(  Event_TDBLookupCombo_DropDown ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBLookupCombo, OnDblClick,  TNotifyEvent,   Event_TDBLookupCombo_DblClick );
DEFINE_DB_EVENT( TDBLookupCombo, OnEnter,     TNotifyEvent,   Event_TDBLookupCombo_GotFocus );
DEFINE_DB_EVENT( TDBLookupCombo, OnExit,      TNotifyEvent,   Event_TDBLookupCombo_LostFocus );
DEFINE_DB_EVENT( TDBLookupCombo, OnKeyDown,   TKeyEvent,      Event_TDBLookupCombo_KeyDown );
DEFINE_DB_EVENT( TDBLookupCombo, OnKeyPress,  TKeyPressEvent, Event_TDBLookupCombo_KeyPress );
DEFINE_DB_EVENT( TDBLookupCombo, OnKeyUp,     TKeyEvent,      Event_TDBLookupCombo_KeyUp );
DEFINE_DB_EVENT( TDBLookupCombo, OnMouseDown, TMouseEvent,    Event_TDBLookupCombo_MouseDown );
DEFINE_DB_EVENT( TDBLookupCombo, OnMouseMove, TMouseEvent,    Event_TDBLookupCombo_MouseMove );
DEFINE_DB_EVENT( TDBLookupCombo, OnMouseUp,   TMouseEvent,    Event_TDBLookupCombo_MouseUp );
DEFINE_DB_EVENT( TDBLookupCombo, OnChange,    TNotifyEvent,   Event_TDBLookupCombo_Change );
DEFINE_DB_EVENT( TDBLookupCombo, OnDropDown,  TNotifyEvent,   Event_TDBLookupCombo_DropDown );

