//--------------------------------------------------------
// DBLKUPCB.H generated from BDBCTL.VBX
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBLOOKUPCOMBO_H_)
#define DBLOOKUPCOMBO_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBLookupCombo (VB3, subclassed from COMBOBOX)
//--------------------------------------------------------

class _DBAWARECLASS TDBLookupCombo : public TDBControl {
  DBPMECLASS( TDBLookupCombo );

  // constructors
  DECLARE_CONSTRUCTORS( TDBLookupCombo );

  public:
    // Properties
    DECLARE_DB_PROP_RW2( TField,DataField );
    DECLARE_DB_PROP_RW0( Bool,  DataChanged,   Prop_TDBLookupCombo_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF,ForeColor,   Prop_TDBLookupCombo_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF,BackColor,   Prop_TDBLookupCombo_BackColor );
    DECLARE_DB_PROP_RW2( string,FontName );
    DECLARE_DB_PROP_RW0( Bool,  FontBold,      Prop_TDBLookupCombo_FontBold );
    DECLARE_DB_PROP_RW0( Bool,  FontItalic,    Prop_TDBLookupCombo_FontItalic );
    DECLARE_DB_PROP_RW0( Bool,  FontStrikethru,Prop_TDBLookupCombo_FontStrikethru );
    DECLARE_DB_PROP_RW0( Bool,  FontUnderline, Prop_TDBLookupCombo_FontUnderline );
    DECLARE_DB_PROP_RW0( float, FontSize,      Prop_TDBLookupCombo_FontSize );
    DECLARE_DB_PROP_RW0( Bool,  AutoSelect,    Prop_TDBLookupCombo_AutoSelect );
    DECLARE_DB_PROP_RW2( string,Caption );
    DECLARE_DB_PROP_RW2( string,DisplayValue );
    DECLARE_DB_PROP_RW0( int,   DropDownCount, Prop_TDBLookupCombo_DropDownCount );
    DECLARE_DB_PROP_RW0( int,   DropDownWidth, Prop_TDBLookupCombo_DropDownWidth );
    DECLARE_DB_PROP_RW0( int,   ItemHeight,    Prop_TDBLookupCombo_ItemHeight );
    DECLARE_DB_PROP_RW0( int,   ItemIndex,     Prop_TDBLookupCombo_ItemIndex );
    DECLARE_DB_PROP_RW2( TDataSource, LookupSource );
    DECLARE_DB_PROP_RW2( TField,      LookupField );
    DECLARE_DB_PROP_RW2( string,LookupDisplay );
    DECLARE_DB_PROP_RW0( int,   MaxLength,     Prop_TDBLookupCombo_MaxLength );
    DECLARE_DB_PROP_RW1( USHORT, TDBLookupListOptions
                              , Options,       Prop_TDBLookupCombo_Options );
    DECLARE_DB_PROP_RW0( Bool,  ReadOnly,      Prop_TDBLookupCombo_ReadOnly );
    DECLARE_DB_PROP_RW0( int,   SelLength,     Prop_TDBLookupCombo_SelLength );
    DECLARE_DB_PROP_RW0( int,   SelStart,      Prop_TDBLookupCombo_SelStart );
    DECLARE_DB_PROP_RW2( string,SelText );
    DECLARE_DB_PROP_RW0( Bool,  Sorted,        Prop_TDBLookupCombo_Sorted );
    DECLARE_DB_PROP_RW1( ENUM, TComboBoxStyle
                            ,   Style,         Prop_TDBLookupCombo_Style );
    DECLARE_DB_PROP_RW2( string,Value );
  private:
    DECLARE_DB_PROP_RO1( long, HCTL
                             ,  LookupHCTL,    Prop_TDBLookupCombo_LookupHctl );


  public:
    // Methods
    void CloseUp();
    void DropDown();


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
    void FireOnDropDown()
    {
      OnDropDownSource( *this );
    }

  public:
    // Event Sinks
    DECLARE_SOURCE( OnChange,    TDBLookupComboNotify );
    DECLARE_SOURCE( OnClick,     TDBLookupComboNotify );
    DECLARE_SOURCE( OnDblClick,  TDBLookupComboNotify );
    DECLARE_SOURCE( OnDragDrop,  TDBLookupComboDrag );
    DECLARE_SOURCE( OnDragOver,  TDBLookupComboDragOver );
    DECLARE_SOURCE( OnDropDown,  TDBLookupComboNotify );
    DECLARE_SOURCE( OnEndDrag,   TDBLookupComboDrag );
    DECLARE_SOURCE( OnEnter,     TDBLookupComboNotify );
    DECLARE_SOURCE( OnExit,      TDBLookupComboNotify );
    DECLARE_SOURCE( OnKeyDown,   TDBLookupComboKey );
    DECLARE_SOURCE( OnKeyPress,  TDBLookupComboKeyPress );
    DECLARE_SOURCE( OnKeyUp,     TDBLookupComboKey );
    DECLARE_SOURCE( OnMouseDown, TDBLookupComboMouse );
    DECLARE_SOURCE( OnMouseMove, TDBLookupComboMouse );
    DECLARE_SOURCE( OnMouseUp,   TDBLookupComboMouse );

    // Event Handlers
    DECLARE_DB_EVENT( OnClick,     TNotifyEvent );
    DECLARE_DB_EVENT( OnDragDrop,  TDragEvent );
    DECLARE_DB_EVENT( OnDragOver,  TDragOverEvent );
    DECLARE_DB_EVENT( OnEndDrag,   TDragEvent );
    DECLARE_DB_EVENT( OnDblClick,  TNotifyEvent );
    DECLARE_DB_EVENT( OnEnter,     TNotifyEvent );
    DECLARE_DB_EVENT( OnExit,      TNotifyEvent );
    DECLARE_DB_EVENT( OnKeyDown,   TKeyEvent );
    DECLARE_DB_EVENT( OnKeyPress,  TKeyPressEvent );
    DECLARE_DB_EVENT( OnKeyUp,     TKeyEvent );
    DECLARE_DB_EVENT( OnMouseDown, TMouseEvent );
    DECLARE_DB_EVENT( OnMouseMove, TMouseEvent );
    DECLARE_DB_EVENT( OnMouseUp,   TMouseEvent );
    DECLARE_DB_EVENT( OnChange,    TNotifyEvent );
    DECLARE_DB_EVENT( OnDropDown,  TNotifyEvent );

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBLookupCombo );
#endif __OWL_VBXCTL_H
};

// Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBLookupCombo, _TDBLookupCombo )
DEFINE_DB_PROP_LOOKUPFIELD( TDBLookupCombo, _TDBLookupCombo )
DEFINE_DB_PROP_LOOKUPSOURCE( TDBLookupCombo )
DEFINE_DB_PROP_STRING( TDBLookupCombo, _TDBLookupCombo, FontName );
DEFINE_DB_PROP_STRING( TDBLookupCombo, _TDBLookupCombo, Caption );
DEFINE_DB_PROP_STRING( TDBLookupCombo, _TDBLookupCombo, DisplayValue );
DEFINE_DB_PROP_STRING( TDBLookupCombo, _TDBLookupCombo, LookupDisplay );
DEFINE_DB_PROP_STRING( TDBLookupCombo, _TDBLookupCombo, SelText );
DEFINE_DB_PROP_STRING( TDBLookupCombo, _TDBLookupCombo, Value );

// Methods
inline void TDBLookupCombo::CloseUp()
{
  SendMessage( CB_SHOWDROPDOWN, true, 0L );
}

inline void TDBLookupCombo::DropDown()
{
  SendMessage( CB_SHOWDROPDOWN, false, 0L );
}

inline char far* TDBLookupCombo::GetClassName()
{
  return "DBLOOKUPCOMBO";
}

#endif DBLOOKUPCOMBO_H_

