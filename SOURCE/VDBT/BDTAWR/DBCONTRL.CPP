//--------------------------------------------------------
// DBCONTRL.CPP
// Copyrights (C) 1996 Borland International
// All rights reserved.
//--------------------------------------------------------

#include <vdbt/dbcontrl.h>


//--------------------------------------------------------
// Events Response Table
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBControl, TVbxControl )
  EV_VBXEVENT_CLICK,
  EV_VBXEVENT_DRAGOVER,
  EV_VBXEVENT_DRAGDROP,
  EV_VBXEVENT_ENDDRAG,
END_RESPONSE_TABLE;

TDBControl::TDBControl( TWindow *parent, int id, LPCSTR lpClass, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
           : TVbxControl( parent, id, "BDT50CTL.VBX", lpClass, title
                        , x, y, w, h, 0, 0, module )
{
}

TDBControl::TDBControl( TWindow *parent, int resourceId, TModule *module )
           : TVbxControl( parent, resourceId, module )
{
}


//--------------------------------------------------------
// Common Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBControl, OnClick,    TNotifyEvent,   Event_TDBControl_Click + 4 );
DEFINE_DB_EVENT( TDBControl, OnDragDrop, TDragEvent,     Event_TDBControl_DragDrop + 4 );
DEFINE_DB_EVENT( TDBControl, OnDragOver, TDragOverEvent, Event_TDBControl_DragOver + 4 );
DEFINE_DB_EVENT( TDBControl, OnEndDrag,  TDragEvent,     Event_TDBControl_EndDrag + 4 );
