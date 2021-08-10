//--------------------------------------------------------
// DBCOMBO.CPP
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbcombo.h>

//--------------------------------------------------------
// TDBComboBox (VB3, subclassed from COMBOBOX)
//--------------------------------------------------------
TDBComboBox::TDBComboBox( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBComboBox", title, x, y, w, h, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnChange )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnDrawItem )
  , INIT_SOURCE( OnDropDown )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnKeyDown )
  , INIT_SOURCE( OnKeyPress )
  , INIT_SOURCE( OnKeyUp )
  , INIT_SOURCE( OnMeasureItem )
{
}

TDBComboBox::TDBComboBox( TWindow *parent, int resourceId, TModule *module )
  : TDBControl( parent, resourceId, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnChange )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnDrawItem )
  , INIT_SOURCE( OnDropDown )
  , INIT_SOURCE( OnEnter )
  , INIT_SOURCE( OnExit )
  , INIT_SOURCE( OnKeyDown )
  , INIT_SOURCE( OnKeyPress )
  , INIT_SOURCE( OnKeyUp )
  , INIT_SOURCE( OnMeasureItem )
{
}


//--------------------------------------------------------
// OWL response table
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBComboBox, TDBControl )
  EV_VBXEVENT_KEYDOWN(     Event_TDBComboBox_KeyDown ),
  EV_VBXEVENT_KEYPRESS(    Event_TDBComboBox_KeyPress ),
  EV_VBXEVENT_KEYUP(       Event_TDBComboBox_KeyUp ),
  EV_VBXEVENT_ENTER(       Event_TDBComboBox_GotFocus ),
  EV_VBXEVENT_EXIT(        Event_TDBComboBox_LostFocus ),
  EV_VBXEVENT_CHANGE(      Event_TDBComboBox_Change ),
  EV_VBXEVENT_MEASUREITEM( Event_TDBComboBox_MeasureItem ),
  EV_VBXEVENT_DRAWITEM(    Event_TDBComboBox_DrawItem ),
  EV_VBXEVENT_DROPDOWN(    Event_TDBComboBox_DropDown ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBComboBox, OnChange,      TNotifyEvent,      Event_TDBComboBox_Change );
DEFINE_DB_EVENT( TDBComboBox, OnDblClick,    TNotifyEvent,      Event_TDBComboBox_DblClick );
DEFINE_DB_EVENT( TDBComboBox, OnDrawItem,    TDrawItemEvent,    Event_TDBComboBox_DrawItem );
DEFINE_DB_EVENT( TDBComboBox, OnDropDown,    TNotifyEvent,      Event_TDBComboBox_DropDown );
DEFINE_DB_EVENT( TDBComboBox, OnEnter,       TNotifyEvent,      Event_TDBComboBox_GotFocus );
DEFINE_DB_EVENT( TDBComboBox, OnExit,        TNotifyEvent,      Event_TDBComboBox_LostFocus );
DEFINE_DB_EVENT( TDBComboBox, OnKeyDown,     TKeyEvent,         Event_TDBComboBox_KeyDown );
DEFINE_DB_EVENT( TDBComboBox, OnKeyPress,    TKeyPressEvent,    Event_TDBComboBox_KeyPress );
DEFINE_DB_EVENT( TDBComboBox, OnKeyUp,       TKeyEvent,         Event_TDBComboBox_KeyUp );
DEFINE_DB_EVENT( TDBComboBox, OnMeasureItem, TMeasureItemEvent, Event_TDBComboBox_MeasureItem );


//--------------------------------------------------------
// Getter & Setters
//--------------------------------------------------------
TDC *TDBComboBox::prCanvas::Get()
{
  HDC Canvas = NULL;

  if( ! DBOUTER( Canvas )->GetVBXProperty( Prop_TDBComboBox_Canvas, &Canvas, -1 ) )
    ThrowException( "Getting Canvas Failed!" );

  if( p )
    delete p;

  if( (p = new TDC( Canvas )) == NULL )
    ThrowException( "Memory Allocation Failed in TDBComboBox::Canvas::Get()!" );

  return p;
}
