//--------------------------------------------------------
// DBGRID.CPP
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbgrid.h>

//--------------------------------------------------------
// DBGrid (VB3)
//--------------------------------------------------------
TDBGrid::TDBGrid( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TVbxControl(parent, id, "VTSSONLY.VBX", "SSView"
               , title, x, y, w, h, 0, 0, module)
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnKeyDown )
  , INIT_SOURCE( OnKeyPress )
  , INIT_SOURCE( OnKeyUp )
{
}

TDBGrid::TDBGrid( TWindow *parent, int resourceId, TModule *module )
  : TVbxControl( parent, resourceId, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
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
DEFINE_DB_RESPONSE_TABLE1( TDBGrid, TVbxControl )
  EV_VBXEVENT_CLICK,
  EV_VBXEVENT_DBLCLICK( Event_TDBGrid_DblClick ),
  EV_VBXEVENT_GRID_DRAGDROP,
  EV_VBXEVENT_GRID_DRAGOVER,
  EV_VBXEVENT_ENTER( Event_TDBGrid_GotFocus ),
  EV_VBXEVENT_KEYDOWN( Event_TDBGrid_KeyDown ),
  EV_VBXEVENT_KEYPRESS( Event_TDBGrid_KeyPress ),
  EV_VBXEVENT_KEYUP( Event_TDBGrid_KeyUp ),
  EV_VBXEVENT_EXIT( Event_TDBGrid_LostFocus ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBGrid, OnClick,    TNotifyEvent,    Event_TDBGrid_Click + 4 );
DEFINE_DB_EVENT( TDBGrid, OnDblClick, TNotifyEvent,    Event_TDBGrid_DblClick + 4 );
DEFINE_DB_EVENT( TDBGrid, OnDragOver, TDragOverEvent, Event_TDBGrid_DragOver + 4 );
DEFINE_DB_EVENT( TDBGrid, OnDragDrop, TDragEvent,     Event_TDBGrid_DragDrop + 4 );
DEFINE_DB_EVENT( TDBGrid, OnEnter,    TNotifyEvent,    Event_TDBGrid_GotFocus + 4 );
DEFINE_DB_EVENT( TDBGrid, OnExit,     TNotifyEvent,    Event_TDBGrid_LostFocus + 4 );
DEFINE_DB_EVENT( TDBGrid, OnKeyDown,  TKeyEvent,       Event_TDBGrid_KeyDown + 4 );
DEFINE_DB_EVENT( TDBGrid, OnKeyPress, TKeyPressEvent,  Event_TDBGrid_KeyPress + 4 );
DEFINE_DB_EVENT( TDBGrid, OnKeyUp,    TKeyEvent,       Event_TDBGrid_KeyUp + 4 );
