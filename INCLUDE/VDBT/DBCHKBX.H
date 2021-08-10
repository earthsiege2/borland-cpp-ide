//--------------------------------------------------------
// DBCHKBX.H generated from BDBCTL.VBX
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBCHECKBOX_H_)
#define DBCHECKBOX_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBCheckBox (VB3, subclassed from BUTTON)
//--------------------------------------------------------

class _DBAWARECLASS TDBCheckBox : public TDBControl {

  DBPMECLASS( TDBCheckBox );

  // constructors
  DECLARE_CONSTRUCTORS( TDBCheckBox );

  public:
    // Properties
    DECLARE_DB_PROP_RW2( TField,DataField );
    DECLARE_DB_PROP_RW0( Bool,  DataChanged,   Prop_TDBCheckBox_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF,ForeColor,   Prop_TDBCheckBox_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF,BackColor,   Prop_TDBCheckBox_BackColor );
    DECLARE_DB_PROP_RW2( string,FontName );
    DECLARE_DB_PROP_RW0( Bool,  FontBold,      Prop_TDBCheckBox_FontBold );
    DECLARE_DB_PROP_RW0( Bool,  FontItalic,    Prop_TDBCheckBox_FontItalic );
    DECLARE_DB_PROP_RW0( Bool,  FontStrikethru,Prop_TDBCheckBox_FontStrikethru );
    DECLARE_DB_PROP_RW0( Bool,  FontUnderline, Prop_TDBCheckBox_FontUnderline );
    DECLARE_DB_PROP_RW0( float, FontSize,      Prop_TDBCheckBox_FontSize );
    DECLARE_DB_PROP_RW1( ENUM, TLeftRight
                             ,  Alignment,     Prop_TDBCheckBox_Alignment );
    DECLARE_DB_PROP_RW0( Bool,  AllowGrayed,   Prop_TDBCheckBox_AllowGrayed );
    DECLARE_DB_PROP_RW2( string,Caption );
    DECLARE_DB_PROP_RW0( Bool,  Checked,       Prop_TDBCheckBox_Checked );
    DECLARE_DB_PROP_RW0( Bool,  ReadOnly,      Prop_TDBCheckBox_ReadOnly );
    DECLARE_DB_PROP_RW1( ENUM,  TCheckBoxState, State, Prop_TDBCheckBox_State );
    DECLARE_DB_PROP_RW2( string,ValueChecked );
    DECLARE_DB_PROP_RW2( string,ValueUnChecked );

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
    DECLARE_SOURCE( OnClick,     TDBCheckBoxNotify );
    DECLARE_SOURCE( OnDragDrop,  TDBCheckBoxDrag );
    DECLARE_SOURCE( OnDragOver,  TDBCheckBoxDragOver );
    DECLARE_SOURCE( OnEndDrag,   TDBCheckBoxDrag );
    DECLARE_SOURCE( OnEnter,     TDBCheckBoxNotify );
    DECLARE_SOURCE( OnExit,      TDBCheckBoxNotify );
    DECLARE_SOURCE( OnKeyDown,   TDBCheckBoxKey );
    DECLARE_SOURCE( OnKeyPress,  TDBCheckBoxKeyPress );
    DECLARE_SOURCE( OnKeyUp,     TDBCheckBoxKey );
    DECLARE_SOURCE( OnMouseDown, TDBCheckBoxMouse );
    DECLARE_SOURCE( OnMouseMove, TDBCheckBoxMouse );
    DECLARE_SOURCE( OnMouseUp,   TDBCheckBoxMouse );

    // Event Handlers
    EVENT( OnClick,    TDBControl,  TNotifyEvent );
    EVENT( OnDragDrop, TDBControl,  TDragEvent );
    EVENT( OnDragOver, TDBControl,  TDragOverEvent );
    EVENT( OnEndDrag,  TDBControl,  TDragEvent );
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
  DECLARE_RESPONSE_TABLE( TDBCheckBox );
#endif __OWL_VBXCTL_H
};

// Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBCheckBox )
DEFINE_DB_PROP_STRING( TDBCheckBox, FontName );
DEFINE_DB_PROP_STRING( TDBCheckBox, Caption );
DEFINE_DB_PROP_STRING( TDBCheckBox, ValueChecked );
DEFINE_DB_PROP_STRING( TDBCheckBox, ValueUnChecked );

// Methods
inline char far* TDBCheckBox::GetClassName()
{
  return "DBCHECKBOX";
}

#endif DBCHECKBOX_H_
