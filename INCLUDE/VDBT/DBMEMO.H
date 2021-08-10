//--------------------------------------------------------
// DBMEMO.H generated from BDBCTL.VBX
// Copyright (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBMEMO_H_)
#define DBMEMO_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBMemo (VB3, subclassed from EDIT)
//--------------------------------------------------------

class _DBAWARECLASS TDBMemo : public TDBControl {
  DBPMECLASS( TDBMemo );

  // constructors
  DECLARE_CONSTRUCTORS( TDBMemo );

  public:
    // Properties
    DECLARE_DB_PROP_RW2( TField, DataField );
    DECLARE_DB_PROP_RW0( Bool,    DataChanged,    Prop_TDBMemo_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF,ForeColor,      Prop_TDBMemo_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF,BackColor,      Prop_TDBMemo_BackColor );
    DECLARE_DB_PROP_RW2( string,  FontName );
    DECLARE_DB_PROP_RW0( Bool,    FontBold,       Prop_TDBMemo_FontBold );
    DECLARE_DB_PROP_RW0( Bool,    FontItalic,     Prop_TDBMemo_FontItalic );
    DECLARE_DB_PROP_RW0( Bool,    FontStrikethru, Prop_TDBMemo_FontStrikethru );
    DECLARE_DB_PROP_RW0( Bool,    FontUnderline,  Prop_TDBMemo_FontUnderline );
    DECLARE_DB_PROP_RW0( float,   FontSize,       Prop_TDBMemo_FontSize );
    DECLARE_DB_PROP_RW1( ENUM, TAlignment
                             ,    Alignment,      Prop_TDBMemo_Alignment );
    DECLARE_DB_PROP_RW0( Bool,    AutoDisplay,    Prop_TDBMemo_AutoDisplay );
    DECLARE_DB_PROP_RW1( ENUM, TBorderStyle
                             ,    BorderStyle,    Prop_TDBMemo_BorderStyle );
    DECLARE_DB_PROP_RWS( TDBMemo, Lines );
    DECLARE_DB_PROP_RW0( int,     MaxLength,      Prop_TDBMemo_MaxLength );
    DECLARE_DB_PROP_RW0( Bool,    Modified,       Prop_TDBMemo_Modified );
    DECLARE_DB_PROP_RW0( Bool,    ReadOnly,       Prop_TDBMemo_ReadOnly );
    DECLARE_DB_PROP_RW1( ENUM, TScrollBars
                             ,    ScrollBars,     Prop_TDBMemo_ScrollBars );
    DECLARE_DB_PROP_RW0( int,     SelLength,      Prop_TDBMemo_SelLength );
    DECLARE_DB_PROP_RW0( int,     SelStart,       Prop_TDBMemo_SelStart );
    DECLARE_DB_PROP_RW2( string,  SelText );
    DECLARE_DB_PROP_RW0( Bool,    WantReturns,    Prop_TDBMemo_WantReturns );
    DECLARE_DB_PROP_RW0( Bool,    WantTabs,       Prop_TDBMemo_WantTabs );
    DECLARE_DB_PROP_RW0( Bool,    WordWrap,       Prop_TDBMemo_WordWrap );

  public:
    // Methods
    void Clear();
    void ClearSelection();
    void CopyToClipboard();
    void CutToClipboard();
    int  GetSelTextBuf( LPSTR, int );
    void LoadMemo();
    void PasteFromClipboard();
    void SelectAll();
    void SetSelTextBuf( LPCSTR );


  private:
    void FireOnClick()
    {
      OnClickSource( *this );
    }
    void FireOnDragDrop( TVbxControl& Source, SHORT x, SHORT y )
    {
      OnDragDropSource( *this, Source, x, y );
    }
    void FireOnDragOver( TVbxControl& Source, SHORT x, SHORT y, TDragState State )
    {
      OnDragOverSource( *this, Source, x, y, State );
    }
    void FireOnEndDrag( TVbxControl& Source, SHORT x, SHORT y )
    {
      OnEndDragSource( *this, Source, x, y );
    }
    void FireOnChange()
    {
      OnChangeSource( *this );
    }
    void FireOnDblClick()
    {
      OnDblClickSource( *this );
    }
    void FireOnEnter()
    {
      OnEnterSource( *this );
    }
    void FireOnExit()
    {
      OnExitSource( *this );
    }
    void FireOnKeyDown( SHORT *Key, TShiftState State )
    {
      OnKeyDownSource( *this, Key, State );
    }
    void FireOnKeyPress( SHORT Key )
    {
      OnKeyPressSource( *this, Key );
    }
    void FireOnKeyUp( SHORT *Key, TShiftState State )
    {
      OnKeyUpSource( *this, Key, State );
    }
    void FireOnMouseDown( TMouseButton Button, TShiftState State, SHORT x, SHORT y )
    {
      OnMouseDownSource( *this, Button, State, x, y );
    }
    void FireOnMouseMove( TMouseButton Button, TShiftState State, SHORT x, SHORT y )
    {
      OnMouseMoveSource( *this, Button, State, x, y );
    }
    void FireOnMouseUp( TMouseButton Button, TShiftState State, SHORT x, SHORT y )
    {
      OnMouseUpSource( *this, Button, State, x, y );
    }

  public:
    // Event Source
    DECLARE_SOURCE( OnClick,     TDBMemoNotify );
    DECLARE_SOURCE( OnDragDrop,  TDBMemoDrag );
    DECLARE_SOURCE( OnDragOver,  TDBMemoDragOver );
    DECLARE_SOURCE( OnEndDrag,   TDBMemoDrag );
    DECLARE_SOURCE( OnDblClick,  TDBMemoNotify );
    DECLARE_SOURCE( OnChange,    TDBMemoNotify );
    DECLARE_SOURCE( OnEnter,     TDBMemoNotify );
    DECLARE_SOURCE( OnExit,      TDBMemoNotify );
    DECLARE_SOURCE( OnKeyDown,   TDBMemoKey );
    DECLARE_SOURCE( OnKeyPress,  TDBMemoKeyPress );
    DECLARE_SOURCE( OnKeyUp,     TDBMemoKey );
    DECLARE_SOURCE( OnMouseDown, TDBMemoMouse );
    DECLARE_SOURCE( OnMouseMove, TDBMemoMouse );
    DECLARE_SOURCE( OnMouseUp,   TDBMemoMouse );

    // Event handlers
    DECLARE_DB_EVENT( OnClick,     TNotifyEvent );
    DECLARE_DB_EVENT( OnDragDrop,  TDragEvent );
    DECLARE_DB_EVENT( OnDragOver,  TDragOverEvent );
    DECLARE_DB_EVENT( OnEndDrag,   TDragEvent );
    DECLARE_DB_EVENT( OnChange,    TNotifyEvent );
    DECLARE_DB_EVENT( OnDblClick,  TNotifyEvent );
    DECLARE_DB_EVENT( OnEnter,     TNotifyEvent );
    DECLARE_DB_EVENT( OnExit,      TNotifyEvent );
    DECLARE_DB_EVENT( OnKeyDown,   TKeyEvent );
    DECLARE_DB_EVENT( OnKeyPress,  TKeyPressEvent );
    DECLARE_DB_EVENT( OnKeyUp,     TKeyEvent );
    DECLARE_DB_EVENT( OnMouseDown, TMouseEvent );
    DECLARE_DB_EVENT( OnMouseMove, TMouseEvent );
    DECLARE_DB_EVENT( OnMouseUp,   TMouseEvent );

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBMemo );
#endif __OWL_VBXCTL_H
};

// Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBMemo, _TDBMemo )
DEFINE_DB_PROP_TSTRINGS( TDBMemo, _TDBMemo, Lines )
DEFINE_DB_PROP_STRING( TDBMemo, _TDBMemo, FontName );
DEFINE_DB_PROP_STRING( TDBMemo, _TDBMemo, SelText );

// Methods
inline void TDBMemo::Clear()
{
  ::VBXMethodClear( GetHCTL() );
}

inline void TDBMemo::ClearSelection()
{
  SelText = &string();
}

inline void TDBMemo::CutToClipboard()
{
  CopyToClipboard();
  ClearSelection();
}

inline void TDBMemo::LoadMemo()
{
  if( ! AutoDisplay )
    ::VBXMethodRefresh( GetHCTL() );
}

inline void TDBMemo::SelectAll()
{
  int i = 0;

  SelStart  = i;
  i = 0xFFFF;
  SelLength = i;
}

inline char far* TDBMemo::GetClassName()
{
  return "DBMEMO";
}

#endif DBMEMO_H_
