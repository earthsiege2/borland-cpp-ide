//--------------------------------------------------------
// DBLIST.CPP
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dblist.h>
#include <stdio.h>

//--------------------------------------------------------
// TDBListBox (VB3, subclassed from LISTBOX)
//--------------------------------------------------------
TDBListBox::TDBListBox( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBListBox", title, x, y, w, h, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnDrawItem )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnKeyDown )
  , INIT_SOURCE( OnKeyPress )
  , INIT_SOURCE( OnKeyUp )
  , INIT_SOURCE( OnMeasureItem )
  , INIT_SOURCE( OnMouseDown )
  , INIT_SOURCE( OnMouseMove )
  , INIT_SOURCE( OnMouseUp )
{
}

TDBListBox::TDBListBox( TWindow *parent, int resourceId, TModule *module )
  : TDBControl( parent, resourceId, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnDrawItem )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnKeyDown )
  , INIT_SOURCE( OnKeyPress )
  , INIT_SOURCE( OnKeyUp )
  , INIT_SOURCE( OnMeasureItem )
  , INIT_SOURCE( OnMouseDown )
  , INIT_SOURCE( OnMouseMove )
  , INIT_SOURCE( OnMouseUp )
{
}

bool TDBListBox::Create()
{
  return TDBControl::Create();
}

void TDBListBox::SetupWindow()
{
  TDBControl::SetupWindow();
}

//--------------------------------------------------------
// OWL response table.
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBListBox, TDBControl )
  EV_VBXEVENT_DBLCLICK(    Event_TDBListBox_DblClick ),
  EV_VBXEVENT_KEYDOWN(     Event_TDBListBox_KeyDown ),
  EV_VBXEVENT_KEYPRESS(    Event_TDBListBox_KeyPress ),
  EV_VBXEVENT_KEYUP(       Event_TDBListBox_KeyUp ),
  EV_VBXEVENT_ENTER(       Event_TDBListBox_GotFocus ),
  EV_VBXEVENT_EXIT(        Event_TDBListBox_LostFocus ),
  EV_VBXEVENT_MOUSEDOWN(   Event_TDBListBox_MouseDown ),
  EV_VBXEVENT_MOUSEMOVE(   Event_TDBListBox_MouseMove ),
  EV_VBXEVENT_MOUSEUP(     Event_TDBListBox_MouseUp ),
  EV_VBXEVENT_MEASUREITEM( Event_TDBListBox_MeasureItem ),
  EV_VBXEVENT_DRAWITEM(    Event_TDBListBox_DrawItem ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBListBox, OnDblClick,    TNotifyEvent,      Event_TDBListBox_DblClick );
DEFINE_DB_EVENT( TDBListBox, OnDrawItem,    TDrawItemEvent,    Event_TDBListBox_DrawItem );
DEFINE_DB_EVENT( TDBListBox, OnEnter,       TNotifyEvent,      Event_TDBListBox_GotFocus );
DEFINE_DB_EVENT( TDBListBox, OnExit,        TNotifyEvent,      Event_TDBListBox_LostFocus );
DEFINE_DB_EVENT( TDBListBox, OnKeyDown,     TKeyEvent,         Event_TDBListBox_KeyDown );
DEFINE_DB_EVENT( TDBListBox, OnKeyPress,    TKeyPressEvent,    Event_TDBListBox_KeyPress );
DEFINE_DB_EVENT( TDBListBox, OnKeyUp,       TKeyEvent,         Event_TDBListBox_KeyUp );
DEFINE_DB_EVENT( TDBListBox, OnMeasureItem, TMeasureItemEvent, Event_TDBListBox_MeasureItem );
DEFINE_DB_EVENT( TDBListBox, OnMouseDown,   TMouseEvent,       Event_TDBListBox_MouseDown );
DEFINE_DB_EVENT( TDBListBox, OnMouseMove,   TMouseEvent,       Event_TDBListBox_MouseMove );
DEFINE_DB_EVENT( TDBListBox, OnMouseUp,     TMouseEvent,       Event_TDBListBox_MouseUp );


//--------------------------------------------------------
// Getters & Setters
//--------------------------------------------------------
TDC *TDBListBox::prCanvas::Get()
{
  HDC Canvas = NULL;

  if( ! DBOUTER( Canvas )->GetVBXProperty( Prop_TDBComboBox_Canvas, &Canvas, -1 ) )
    ThrowException( "Getting Canvas Failed!" );

  if( p )
    delete p;

  if( (p = new TDC( Canvas )) == NULL )
    ThrowException( "Memory Allocation Failed in TDBListBox::Canvas::Get()!" );

  return p;
}


// Methods
SHORT TDBListBox::ItemAtPos( TPoint pt, bool Existing )
{
  if( Existing && ! GetClientRect().Contains( pt ) )
    return -1;

  SHORT Index = SHORT( SendMessage( LB_GETTOPINDEX, 0, 0L ) );
  try {
  for( ; ! ItemRect( Index ).Contains( pt ) ; Index++ )
    ;
  } catch( TXOwl )
  {
    // Ignore the exeption throwen by ItemRect()
  }

  return Index;
}

TRect TDBListBox::ItemRect( SHORT Indx )
{
  TRect rc;

  if( LB_ERR == SendMessage( LB_GETITEMRECT, Indx, LPARAM( (TRect FAR*)&rc ) ) )
  {
    char Error[ 48 ];

    sprintf( Error, "TDBListBox::ItemRect(%d): Invalid Index", Indx );
    TXOwl( Error ).Throw();
  }

  return rc;
}

