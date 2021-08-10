//--------------------------------------------------------
// DBLIST.H generated from BDBCTL.VBX
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBLISTBOX_H_)
#define DBLISTBOX_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBListBox (VB3, subclassed from LISTBOX)
//--------------------------------------------------------

class _DBAWARECLASS TDBListBox : public TDBControl {
  DBPMECLASS( TDBListBox );

  // constructors
  DECLARE_CONSTRUCTORS( TDBListBox );

  public:
    // Properties
    DECLARE_DB_PROP_RW2( TField,  DataField );
    DECLARE_DB_PROP_RW0( Bool,     DataChanged,   Prop_TDBListBox_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF, ForeColor,     Prop_TDBListBox_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF, BackColor,     Prop_TDBListBox_BackColor );
    DECLARE_DB_PROP_RW2( string,   FontName );
    DECLARE_DB_PROP_RW0( Bool,     FontBold,      Prop_TDBListBox_FontBold );
    DECLARE_DB_PROP_RW0( Bool,     FontItalic,    Prop_TDBListBox_FontItalic );
    DECLARE_DB_PROP_RW0( Bool,     FontStrikethru,Prop_TDBListBox_FontStrikethru );
    DECLARE_DB_PROP_RW0( Bool,     FontUnderline, Prop_TDBListBox_FontUnderline );
    DECLARE_DB_PROP_RW0( float,    FontSize,      Prop_TDBListBox_FontSize );
    DECLARE_DB_PROP_RO1( USHORT, TOwnerDrawAction
                               ,   Action,        Prop_TDBListBox_Action );
    DECLARE_DB_PROP_RW1( ENUM, TBorderStyle
                             ,     BorderStyle,   Prop_TDBListBox_BorderStyle );
    DECLARE_DB_PROP_RO2( TDC,      Canvas );
    DECLARE_DB_PROP_RW2( string,   Caption );
    DECLARE_DB_PROP_RW0( Bool,     IntegralHeight,Prop_TDBListBox_IntegralHeight );
    DECLARE_DB_PROP_RO0( long,     ItemData,      Prop_TDBListBox_ItemData );
    DECLARE_DB_PROP_RW0( int,      ItemHeight,    Prop_TDBListBox_ItemHeight );
    DECLARE_DB_PROP_RW0( int,      ItemIndex,     Prop_TDBListBox_ItemIndex );
    DECLARE_DB_PROP_RWS( TDBListBox, Items );
    DECLARE_DB_PROP_RW0( Bool,     ReadOnly,      Prop_TDBListBox_ReadOnly );
    DECLARE_DB_PROP_RW0( Bool,     Sorted,        Prop_TDBListBox_Sorted );
    DECLARE_DB_PROP_RW1( ENUM, TListBoxStyle
                             ,     Style,         Prop_TDBListBox_Style );
    DECLARE_DB_PROP_RW0( int,      TopIndex,      Prop_TDBListBox_TopIndex );
    DECLARE_DB_PROP_RW2( string,   Value );

  public:
    // ListBox Methods
    SHORT ItemAtPos( TPoint, bool );
    TRect ItemRect( SHORT );


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
    void FireOnMeasureItem( SHORT Index, SHORT *Height )
    {
      OnMeasureItemSource( *this, Index, Height );
    }
    void FireOnDrawItem( SHORT Index, TRect rc, TOwnerDrawState State )
    {
      OnDrawItemSource( *this, Index, rc, State );
    }

  public:
    // Event Source
    DECLARE_SOURCE( OnClick,       TDBListBoxNotify );
    DECLARE_SOURCE( OnDblClick,    TDBListBoxNotify );
    DECLARE_SOURCE( OnDragDrop,    TDBListBoxDrag );
    DECLARE_SOURCE( OnDragOver,    TDBListBoxDragOver );
    DECLARE_SOURCE( OnDrawItem,    TDBListBoxDrawItem );
    DECLARE_SOURCE( OnEndDrag,     TDBListBoxDrag );
    DECLARE_SOURCE( OnEnter,       TDBListBoxNotify );
    DECLARE_SOURCE( OnExit,        TDBListBoxNotify );
    DECLARE_SOURCE( OnKeyDown,     TDBListBoxKey );
    DECLARE_SOURCE( OnKeyPress,    TDBListBoxKeyPress );
    DECLARE_SOURCE( OnKeyUp,       TDBListBoxKey );
    DECLARE_SOURCE( OnMeasureItem, TDBListBoxMeasureItem );
    DECLARE_SOURCE( OnMouseDown,   TDBListBoxMouse );
    DECLARE_SOURCE( OnMouseMove,   TDBListBoxMouse );
    DECLARE_SOURCE( OnMouseUp,     TDBListBoxMouse );

    // Event Handlers
    DECLARE_DB_EVENT( OnClick,       TNotifyEvent );
    DECLARE_DB_EVENT( OnDragDrop,    TDragEvent );
    DECLARE_DB_EVENT( OnDragOver,    TDragOverEvent );
    DECLARE_DB_EVENT( OnEndDrag,     TDragEvent );
    DECLARE_DB_EVENT( OnDblClick,    TNotifyEvent );
    DECLARE_DB_EVENT( OnDrawItem,    TDrawItemEvent );
    DECLARE_DB_EVENT( OnEnter,       TNotifyEvent );
    DECLARE_DB_EVENT( OnExit,        TNotifyEvent );
    DECLARE_DB_EVENT( OnKeyDown,     TKeyEvent );
    DECLARE_DB_EVENT( OnKeyPress,    TKeyPressEvent );
    DECLARE_DB_EVENT( OnKeyUp,       TKeyEvent );
    DECLARE_DB_EVENT( OnMeasureItem, TMeasureItemEvent );
    DECLARE_DB_EVENT( OnMouseDown,   TMouseEvent );
    DECLARE_DB_EVENT( OnMouseMove,   TMouseEvent );
    DECLARE_DB_EVENT( OnMouseUp,     TMouseEvent );

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBListBox );
#endif __OWL_VBXCTL_H

  protected:
    void SetupWindow();
  public:
    bool Create();
};

// Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBListBox, _TDBListBox )
DEFINE_DB_PROP_TSTRINGS( TDBListBox, _TDBListBox, Items )
DEFINE_DB_PROP_STRING( TDBListBox, _TDBListBox, FontName );
DEFINE_DB_PROP_STRING( TDBListBox, _TDBListBox, Caption );
DEFINE_DB_PROP_STRING( TDBListBox, _TDBListBox, Value );

// Methods
inline char far* TDBListBox::GetClassName()
{
  return "DBLISTBOX";
}

#endif DBLISTBOX_H_
