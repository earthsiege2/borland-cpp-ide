//--------------------------------------------------------
// DBMEMO.CPP
// Copyright (C) 1996 Borland International
//--------------------------------------------------------

#include <vdbt/dbcontrl.h>
#pragma hdrstop
#include <vdbt/dbmemo.h>

//--------------------------------------------------------
// TDBMemo (VB3, subclassed from EDIT)
//--------------------------------------------------------
TDBMemo::TDBMemo( TWindow *parent, int id, LPCSTR title
                      , int x, int y, int w, int h, TModule *module )
  : TDBControl( parent, id, "TDBMemo", title, x, y, w, h, module )
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

TDBMemo::TDBMemo( TWindow *parent, int resourceId, TModule *module )
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
DEFINE_DB_RESPONSE_TABLE1( TDBMemo, TDBControl )
  EV_VBXEVENT_CLICK,
  EV_VBXEVENT_DRAGOVER,
  EV_VBXEVENT_DRAGDROP,
  EV_VBXEVENT_ENDDRAG,
  EV_VBXEVENT_DBLCLICK(  Event_TDBMemo_DblClick ),
  EV_VBXEVENT_KEYDOWN(   Event_TDBMemo_KeyDown ),
  EV_VBXEVENT_KEYPRESS(  Event_TDBMemo_KeyPress ),
  EV_VBXEVENT_KEYUP(     Event_TDBMemo_KeyUp ),
  EV_VBXEVENT_ENTER(     Event_TDBMemo_GotFocus ),
  EV_VBXEVENT_EXIT(      Event_TDBMemo_LostFocus ),
  EV_VBXEVENT_MOUSEDOWN( Event_TDBMemo_MouseDown ),
  EV_VBXEVENT_MOUSEMOVE( Event_TDBMemo_MouseMove ),
  EV_VBXEVENT_MOUSEUP(   Event_TDBMemo_MouseUp ),
  EV_VBXEVENT_CHANGE(    Event_TDBMemo_Change ),
END_RESPONSE_TABLE;


//--------------------------------------------------------
// Event handlers
//--------------------------------------------------------
DEFINE_DB_EVENT( TDBMemo, OnClick,     TNotifyEvent,   Event_TDBMemo_Click );
DEFINE_DB_EVENT( TDBMemo, OnDragDrop,  TDragEvent,     Event_TDBMemo_DragDrop );
DEFINE_DB_EVENT( TDBMemo, OnDragOver,  TDragOverEvent, Event_TDBMemo_DragOver );
DEFINE_DB_EVENT( TDBMemo, OnEndDrag,   TDragEvent,     Event_TDBMemo_EndDrag );
DEFINE_DB_EVENT( TDBMemo, OnChange,    TNotifyEvent,   Event_TDBMemo_Change );
DEFINE_DB_EVENT( TDBMemo, OnDblClick,  TNotifyEvent,   Event_TDBMemo_DblClick );
DEFINE_DB_EVENT( TDBMemo, OnEnter,     TNotifyEvent,   Event_TDBMemo_GotFocus );
DEFINE_DB_EVENT( TDBMemo, OnExit,      TNotifyEvent,   Event_TDBMemo_LostFocus );
DEFINE_DB_EVENT( TDBMemo, OnKeyDown,   TKeyEvent,      Event_TDBMemo_KeyDown );
DEFINE_DB_EVENT( TDBMemo, OnKeyPress,  TKeyPressEvent, Event_TDBMemo_KeyPress );
DEFINE_DB_EVENT( TDBMemo, OnKeyUp,     TKeyEvent,      Event_TDBMemo_KeyUp );
DEFINE_DB_EVENT( TDBMemo, OnMouseDown, TMouseEvent,    Event_TDBMemo_MouseDown );
DEFINE_DB_EVENT( TDBMemo, OnMouseMove, TMouseEvent,    Event_TDBMemo_MouseMove );
DEFINE_DB_EVENT( TDBMemo, OnMouseUp,   TMouseEvent,    Event_TDBMemo_MouseUp );


//--------------------------------------------------------
// Methods
//--------------------------------------------------------
void TDBMemo::CopyToClipboard()
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

void TDBMemo::PasteFromClipboard()
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

int TDBMemo::GetSelTextBuf( LPSTR lpBuf, int nLen )
{
  int    iLen = min( nLen - 1, (int)SelLength );

  lstrcpyn( lpBuf, SelText->c_str(), iLen );
  lpBuf[ iLen ] = '\0';

  return iLen + 1;
}

