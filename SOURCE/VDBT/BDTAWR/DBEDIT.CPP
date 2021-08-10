//--------------------------------------------------------
// DBEDIT.CPP
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbedit.h>

//--------------------------------------------------------
// TDBEdit (VB3, subclassed from EDIT)
//--------------------------------------------------------
TDBEdit::TDBEdit( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBEdit", title, x, y, w, h, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnChange )
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

TDBEdit::TDBEdit( TWindow *parent, int resourceId, TModule *module )
  : TDBControl( parent, resourceId, module )
  , INIT_SOURCE( OnClick )
  , INIT_SOURCE( OnDragDrop )
  , INIT_SOURCE( OnDragOver )
  , INIT_SOURCE( OnEndDrag )
  , INIT_SOURCE( OnDblClick )
  , INIT_SOURCE( OnChange )
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
// OWL response table.
//--------------------------------------------------------
DEFINE_DB_RESPONSE_TABLE1( TDBEdit, TDBControl )
  EV_VBXEVENT_DBLCLICK(  Event_TDBEdit_DblClick ),
  EV_VBXEVENT_KEYDOWN(   Event_TDBEdit_KeyDown ),
  EV_VBXEVENT_KEYPRESS(  Event_TDBEdit_KeyPress ),
  EV_VBXEVENT_KEYUP(     Event_TDBEdit_KeyUp ),
  EV_VBXEVENT_ENTER(     Event_TDBEdit_GotFocus ),
  EV_VBXEVENT_EXIT(      Event_TDBEdit_LostFocus ),
  EV_VBXEVENT_MOUSEDOWN( Event_TDBEdit_MouseDown ),
  EV_VBXEVENT_MOUSEMOVE( Event_TDBEdit_MouseMove ),
  EV_VBXEVENT_MOUSEUP(   Event_TDBEdit_MouseUp ),
  EV_VBXEVENT_CHANGE(    Event_TDBEdit_Change ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event Handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBEdit, OnChange,    TNotifyEvent,   Event_TDBEdit_Change );
DEFINE_DB_EVENT( TDBEdit, OnDblClick,  TNotifyEvent,   Event_TDBEdit_DblClick );
DEFINE_DB_EVENT( TDBEdit, OnEnter,     TNotifyEvent,   Event_TDBEdit_GotFocus );
DEFINE_DB_EVENT( TDBEdit, OnExit,      TNotifyEvent,   Event_TDBEdit_LostFocus );
DEFINE_DB_EVENT( TDBEdit, OnKeyDown,   TKeyEvent,      Event_TDBEdit_KeyDown );
DEFINE_DB_EVENT( TDBEdit, OnKeyPress,  TKeyPressEvent, Event_TDBEdit_KeyPress );
DEFINE_DB_EVENT( TDBEdit, OnKeyUp,     TKeyEvent,      Event_TDBEdit_KeyUp );
DEFINE_DB_EVENT( TDBEdit, OnMouseDown, TMouseEvent,    Event_TDBEdit_MouseDown );
DEFINE_DB_EVENT( TDBEdit, OnMouseMove, TMouseEvent,    Event_TDBEdit_MouseMove );
DEFINE_DB_EVENT( TDBEdit, OnMouseUp,   TMouseEvent,    Event_TDBEdit_MouseUp );


//--------------------------------------------------------
// Methods
//--------------------------------------------------------
void TDBEdit::CopyToClipboard()
{
  TClipboard& cb = OpenClipboard();

  if( cb )
  {
    cb.EmptyClipboard();

    if( SelLength )
    {
      HGLOBAL  hText = GlobalAlloc( GHND, SelLength + 1 );

      if( hText )
      {
        LPSTR lpText = LPSTR( GlobalLock( hText ) );

        if( lpText )
        {
          lstrcpyn( lpText, SelText->c_str(), SelLength + 1 );
          GlobalUnlock( hText );
        }
        cb.SetClipboardData( CF_TEXT, hText );
      }
    }

    cb.CloseClipboard();
  }
}

void TDBEdit::PasteFromClipboard()
{
  TClipboard& cb = OpenClipboard();

  if( cb && cb.IsClipboardFormatAvailable( CF_TEXT ) )
  {
    HGLOBAL  hText = cb.GetClipboardData( CF_TEXT );

    if( hText )
    {
      LPSTR lpText = LPSTR( GlobalLock( hText ) );

      if( lpText )
      {
        SelText = &string( lpText );
        GlobalUnlock( hText );
      }
    }

    cb.CloseClipboard();
  }
}

int TDBEdit::GetSelTextBuf( LPSTR lpBuf, int nLen )
{
  int    iLen = min( nLen - 1, (int)SelLength );
  lstrcpyn( lpBuf, SelText->c_str(), iLen );
  lpBuf[ iLen ] = '\0';

  return iLen + 1;
}

