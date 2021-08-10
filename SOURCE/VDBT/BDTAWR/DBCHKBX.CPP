//--------------------------------------------------------
// DBCHKBX.CPP
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbchkbx.h>

//--------------------------------------------------------
// TDBCheckBox (VB3, subclassed from BUTTON)
//--------------------------------------------------------
TDBCheckBox::TDBCheckBox( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBCheckBox", title, x, y, w, h, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnKeyDown )
  , INIT_SOURCE( OnKeyPress )
  , INIT_SOURCE( OnKeyUp )
  , INIT_SOURCE( OnMouseDown )
  , INIT_SOURCE( OnMouseMove )
  , INIT_SOURCE( OnMouseUp )
{
}

TDBCheckBox::TDBCheckBox( TWindow *parent, int resourceId, TModule *module )
  : TDBControl( parent, resourceId, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnKeyDown )
  , INIT_SOURCE( OnKeyPress )
  , INIT_SOURCE( OnKeyUp )
  , INIT_SOURCE( OnMouseDown )
  , INIT_SOURCE( OnMouseMove )
  , INIT_SOURCE( OnMouseUp )
{
}


//--------------------------------------------------------
// OWL response table
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBCheckBox, TDBControl )
  EV_VBXEVENT_KEYDOWN(   Event_TDBCheckBox_KeyDown ),
  EV_VBXEVENT_KEYPRESS(  Event_TDBCheckBox_KeyPress ),
  EV_VBXEVENT_KEYUP(     Event_TDBCheckBox_KeyUp ),
  EV_VBXEVENT_ENTER(     Event_TDBCheckBox_GotFocus ),
  EV_VBXEVENT_EXIT(      Event_TDBCheckBox_LostFocus ),
  EV_VBXEVENT_MOUSEDOWN( Event_TDBCheckBox_MouseDown ),
  EV_VBXEVENT_MOUSEMOVE( Event_TDBCheckBox_MouseMove ),
  EV_VBXEVENT_MOUSEUP(   Event_TDBCheckBox_MouseUp ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Events
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBCheckBox, OnEnter,     TNotifyEvent,   Event_TDBCheckBox_GotFocus );
DEFINE_DB_EVENT( TDBCheckBox, OnExit,      TNotifyEvent,   Event_TDBCheckBox_LostFocus );
DEFINE_DB_EVENT( TDBCheckBox, OnKeyDown,   TKeyEvent,      Event_TDBCheckBox_KeyDown );
DEFINE_DB_EVENT( TDBCheckBox, OnKeyPress,  TKeyPressEvent, Event_TDBCheckBox_KeyPress );
DEFINE_DB_EVENT( TDBCheckBox, OnKeyUp,     TKeyEvent,      Event_TDBCheckBox_KeyUp );
DEFINE_DB_EVENT( TDBCheckBox, OnMouseDown, TMouseEvent,    Event_TDBCheckBox_MouseDown );
DEFINE_DB_EVENT( TDBCheckBox, OnMouseMove, TMouseEvent,    Event_TDBCheckBox_MouseMove );
DEFINE_DB_EVENT( TDBCheckBox, OnMouseUp,   TMouseEvent,    Event_TDBCheckBox_MouseMove );

