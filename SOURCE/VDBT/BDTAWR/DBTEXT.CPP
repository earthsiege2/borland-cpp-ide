//--------------------------------------------------------
// DBTEXT.CPP
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbtext.h>

//--------------------------------------------------------
// TDBText (VB3, subclassed from STATIC)
//--------------------------------------------------------
TDBText::TDBText( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBText", title, x, y, w, h, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnMouseDown )
  , INIT_SOURCE( OnMouseMove )
  , INIT_SOURCE( OnMouseUp )
{
}

TDBText::TDBText( TWindow *parent, int resourceId, TModule *module )
  : TDBControl( parent, resourceId, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnMouseDown )
  , INIT_SOURCE( OnMouseMove )
  , INIT_SOURCE( OnMouseUp )
{
}


//--------------------------------------------------------
// OWL response table.
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBText, TDBControl )
  EV_VBXEVENT_DBLCLICK(  Event_TDBText_DblClick ),
  EV_VBXEVENT_MOUSEDOWN( Event_TDBText_MouseDown ),
  EV_VBXEVENT_MOUSEMOVE( Event_TDBText_MouseMove ),
  EV_VBXEVENT_MOUSEUP(   Event_TDBText_MouseUp ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBText, OnDblClick,  TNotifyEvent,Event_TDBText_DblClick );
DEFINE_DB_EVENT( TDBText, OnMouseDown, TMouseEvent, Event_TDBText_MouseDown );
DEFINE_DB_EVENT( TDBText, OnMouseMove, TMouseEvent, Event_TDBText_MouseMove );
DEFINE_DB_EVENT( TDBText, OnMouseUp,   TMouseEvent, Event_TDBText_MouseUp );

