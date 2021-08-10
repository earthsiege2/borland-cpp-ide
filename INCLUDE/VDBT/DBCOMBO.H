//--------------------------------------------------------
// DBCOMBO.H generated from BDBCTL.VBX
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBCOMBOBOX_H_)
#define DBCOMBOBOX_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBComboBox (VB3, subclassed from COMBOBOX)
//--------------------------------------------------------

class _DBAWARECLASS TDBComboBox : public TDBControl {
  DBPMECLASS( TDBComboBox );

  // constructors
  DECLARE_CONSTRUCTORS( TDBComboBox );

  public:
    // Properties
    DECLARE_DB_PROP_RW2( TField,  DataField );
    DECLARE_DB_PROP_RW0( Bool,    DataChanged, Prop_TDBComboBox_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF,ForeColor,   Prop_TDBComboBox_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF,BackColor,   Prop_TDBComboBox_BackColor );
    DECLARE_DB_PROP_RW2( string,  FontName );
    DECLARE_DB_PROP_RW0( Bool,    FontBold,    Prop_TDBComboBox_FontBold );
    DECLARE_DB_PROP_RW0( Bool, FontItalic,     Prop_TDBComboBox_FontItalic );
    DECLARE_DB_PROP_RW0( Bool, FontStrikethru,Prop_TDBComboBox_FontStrikethru );
    DECLARE_DB_PROP_RW0( Bool, FontUnderline,Prop_TDBComboBox_FontUnderline );
    DECLARE_DB_PROP_RW0( float,FontSize,       Prop_TDBComboBox_FontSize );
    DECLARE_DB_PROP_RO1( USHORT, TOwnerDrawAction
                               , Action,        Prop_TDBComboBox_Action );
    DECLARE_DB_PROP_RO2( TDC,  Canvas );
    DECLARE_DB_PROP_RW2( string, Caption );
    DECLARE_DB_PROP_RW0( int,  DropDownCount,Prop_TDBComboBox_DropDownCount );
    DECLARE_DB_PROP_RW0( int,  DropDownWidth,Prop_TDBComboBox_DropDownWidth );
    DECLARE_DB_PROP_RO0( long, ItemData,     Prop_TDBComboBox_ItemData );
    DECLARE_DB_PROP_RW0( int,  ItemHeight,   Prop_TDBComboBox_ItemHeight );
    DECLARE_DB_PROP_RW0( int,  ItemIndex,    Prop_TDBComboBox_ItemIndex );
    DECLARE_DB_PROP_RWS( TDBComboBox, Items );
    DECLARE_DB_PROP_RW0( int,  MaxLength,    Prop_TDBComboBox_MaxLength );
    DECLARE_DB_PROP_RW0( Bool, ReadOnly,     Prop_TDBComboBox_ReadOnly );
    DECLARE_DB_PROP_RW0( int,  SelLength,    Prop_TDBComboBox_SelLength );
    DECLARE_DB_PROP_RW0( int,  SelStart,     Prop_TDBComboBox_SelStart );
    DECLARE_DB_PROP_RW2( string,SelText );
    DECLARE_DB_PROP_RW0( Bool,  Sorted,       Prop_TDBComboBox_Sorted );
    DECLARE_DB_PROP_RW1( ENUM, TComboBoxStyle
                             ,  Style,        Prop_TDBComboBox_Style );

  private:
    void FireOnChange()
    {
      OnChangeSource( *this );
    }
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
    void FireOnDropDown()
    {
      OnDropDownSource( *this );
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
    DECLARE_SOURCE( OnClick,       TDBComboBoxNotify );
    DECLARE_SOURCE( OnDragDrop,    TDBComboBoxDrag );
    DECLARE_SOURCE( OnDragOver,    TDBComboBoxDragOver );
    DECLARE_SOURCE( OnEndDrag,     TDBComboBoxDrag );
    DECLARE_SOURCE( OnChange,      TDBComboBoxNotify );
    DECLARE_SOURCE( OnDblClick,    TDBComboBoxNotify );
    DECLARE_SOURCE( OnDrawItem,    TDBComboBoxDrawItem );
    DECLARE_SOURCE( OnDropDown,    TDBComboBoxNotify );
    DECLARE_SOURCE( OnEnter,       TDBComboBoxNotify );
    DECLARE_SOURCE( OnExit,        TDBComboBoxNotify );
    DECLARE_SOURCE( OnKeyDown,     TDBComboBoxKey );
    DECLARE_SOURCE( OnKeyPress,    TDBComboBoxKeyPress );
    DECLARE_SOURCE( OnKeyUp,       TDBComboBoxKey );
    DECLARE_SOURCE( OnMeasureItem, TDBComboBoxMeasureItem );

    // Event Handlers
    EVENT( OnClick,    TDBControl,   TNotifyEvent );
    EVENT( OnDragDrop, TDBControl,   TDragEvent );
    EVENT( OnDragOver, TDBControl,   TDragOverEvent );
    EVENT( OnEndDrag,  TDBControl,   TDragEvent );
    DECLARE_DB_EVENT( OnChange,      TNotifyEvent );
    DECLARE_DB_EVENT( OnDblClick,    TNotifyEvent );
    DECLARE_DB_EVENT( OnDrawItem,    TDrawItemEvent );
    DECLARE_DB_EVENT( OnDropDown,    TNotifyEvent );
    DECLARE_DB_EVENT( OnEnter,       TNotifyEvent );
    DECLARE_DB_EVENT( OnExit,        TNotifyEvent );
    DECLARE_DB_EVENT( OnKeyDown,     TKeyEvent );
    DECLARE_DB_EVENT( OnKeyPress,    TKeyPressEvent );
    DECLARE_DB_EVENT( OnKeyUp,       TKeyEvent );
    DECLARE_DB_EVENT( OnMeasureItem, TMeasureItemEvent );

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBComboBox );
#endif __OWL_VBXCTL_H
};

// Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBComboBox )
DEFINE_DB_PROP_TSTRINGS( TDBComboBox, Items )
DEFINE_DB_PROP_STRING( TDBComboBox, FontName );
DEFINE_DB_PROP_STRING( TDBComboBox, Caption );
DEFINE_DB_PROP_STRING( TDBComboBox, SelText );

// Methods
inline char far* TDBComboBox::GetClassName()
{
  return "DBCOMBOBOX";
}

#endif DBCOMBOBOX_H_
