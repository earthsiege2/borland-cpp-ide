//--------------------------------------------------------
// DBIMAGE.CPP
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbimage.h>

//--------------------------------------------------------
// TDBImage (VB3)
//--------------------------------------------------------
TDBImage::TDBImage( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBImage", title, x, y, w, h, module )
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
{
}

TDBImage::TDBImage( TWindow *parent, int resourceId, TModule *module )
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
  , INIT_SOURCE( OnMouseDown )
  , INIT_SOURCE( OnMouseMove )
  , INIT_SOURCE( OnMouseUp )
{
}


//--------------------------------------------------------
// OWL response table
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBImage, TDBControl )
  EV_VBXEVENT_DBLCLICK(  Event_TDBImage_DblClick ),
  EV_VBXEVENT_KEYDOWN(   Event_TDBImage_KeyDown ),
  EV_VBXEVENT_KEYPRESS(  Event_TDBImage_KeyPress ),
  EV_VBXEVENT_KEYUP(     Event_TDBImage_KeyUp ),
  EV_VBXEVENT_ENTER(     Event_TDBImage_GotFocus ),
  EV_VBXEVENT_EXIT(      Event_TDBImage_LostFocus ),
  EV_VBXEVENT_MOUSEDOWN( Event_TDBImage_MouseDown ),
  EV_VBXEVENT_MOUSEMOVE( Event_TDBImage_MouseMove ),
  EV_VBXEVENT_MOUSEUP(   Event_TDBImage_MouseUp ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Events
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBImage, OnDblClick,  TNotifyEvent,   Event_TDBImage_DblClick );
DEFINE_DB_EVENT( TDBImage, OnEnter,     TNotifyEvent,   Event_TDBImage_GotFocus );
DEFINE_DB_EVENT( TDBImage, OnExit,      TNotifyEvent,   Event_TDBImage_LostFocus );
DEFINE_DB_EVENT( TDBImage, OnKeyDown,   TKeyEvent,      Event_TDBImage_KeyDown );
DEFINE_DB_EVENT( TDBImage, OnKeyPress,  TKeyPressEvent, Event_TDBImage_KeyPress );
DEFINE_DB_EVENT( TDBImage, OnKeyUp,     TKeyEvent,      Event_TDBImage_KeyUp );
DEFINE_DB_EVENT( TDBImage, OnMouseDown, TMouseEvent,    Event_TDBImage_MouseDown );
DEFINE_DB_EVENT( TDBImage, OnMouseMove, TMouseEvent,    Event_TDBImage_MouseMove );
DEFINE_DB_EVENT( TDBImage, OnMouseUp,   TMouseEvent,    Event_TDBImage_MouseUp );

