//--------------------------------------------------------
// DBRADIO.H generated from BDBCTL.VBX
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBRADIOGROUP_H_)
#define DBRADIOGROUP_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBRadioGroup (VB3)
//--------------------------------------------------------

class _DBAWARECLASS TDBRadioGroup : public TDBControl {
  DBPMECLASS( TDBRadioGroup );

  // constructors
  DECLARE_CONSTRUCTORS( TDBRadioGroup );

  public:
    // Properties
    DECLARE_DB_PROP_RW2( TField, DataField );
    DECLARE_DB_PROP_RW0( Bool,    DataChanged,   Prop_TDBRadioGroup_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF,ForeColor,     Prop_TDBRadioGroup_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF,BackColor,     Prop_TDBRadioGroup_BackColor );
    DECLARE_DB_PROP_RW2( string,  FontName );
    DECLARE_DB_PROP_RW0( Bool,    FontBold,      Prop_TDBRadioGroup_FontBold );
    DECLARE_DB_PROP_RW0( Bool,    FontItalic,    Prop_TDBRadioGroup_FontItalic );
    DECLARE_DB_PROP_RW0( Bool,    FontStrikethru,Prop_TDBRadioGroup_FontStrikethru );
    DECLARE_DB_PROP_RW0( Bool,    FontUnderline, Prop_TDBRadioGroup_FontUnderline );
    DECLARE_DB_PROP_RW0( float,   FontSize,      Prop_TDBRadioGroup_FontSize );
    DECLARE_DB_PROP_RW2( string,  Caption );
    DECLARE_DB_PROP_RW0( int,     Columns,       Prop_TDBRadioGroup_Columns );
    DECLARE_DB_PROP_RW0( int,     ItemIndex,     Prop_TDBRadioGroup_ItemIndex );
    DECLARE_DB_PROP_RWS( TDBRadioGroup, Items );
    DECLARE_DB_PROP_RW0( Bool,    ReadOnly,      Prop_TDBRadioGroup_ReadOnly );
    DECLARE_DB_PROP_RW2( string,  Value );
    DECLARE_DB_PROP_RWS( TDBRadioGroup, Values );


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
  public:
    // Event Source
    DECLARE_SOURCE( OnChange,   TDBRadioGroupNotify );
    DECLARE_SOURCE( OnClick,    TDBRadioGroupNotify );
    DECLARE_SOURCE( OnDblClick, TDBRadioGroupNotify );
    DECLARE_SOURCE( OnDragDrop, TDBRadioGroupDrag );
    DECLARE_SOURCE( OnDragOver, TDBRadioGroupDragOver );
    DECLARE_SOURCE( OnEndDrag,  TDBRadioGroupDrag );
    DECLARE_SOURCE( OnEnter,    TDBRadioGroupNotify );
    DECLARE_SOURCE( OnExit,     TDBRadioGroupNotify );

    // Event Handlers
    EVENT( OnClick,    TDBControl, TNotifyEvent );
    EVENT( OnDragDrop, TDBControl, TDragEvent );
    EVENT( OnDragOver, TDBControl, TDragOverEvent );
    EVENT( OnEndDrag,  TDBControl, TDragEvent );
    DECLARE_DB_EVENT( OnChange,   TNotifyEvent );
    DECLARE_DB_EVENT( OnDblClick, TNotifyEvent );
    DECLARE_DB_EVENT( OnEnter,    TNotifyEvent );
    DECLARE_DB_EVENT( OnExit,     TNotifyEvent );

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBRadioGroup );
#endif __OWL_VBXCTL_H
};

// Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBRadioGroup )
DEFINE_DB_PROP_TSTRINGS( TDBRadioGroup, Items )
DEFINE_DB_PROP_TSTRINGS( TDBRadioGroup, Values )
DEFINE_DB_PROP_STRING( TDBRadioGroup, FontName );
DEFINE_DB_PROP_STRING( TDBRadioGroup, Caption );
DEFINE_DB_PROP_STRING( TDBRadioGroup, Value );

// Methods
inline char far* TDBRadioGroup::GetClassName()
{
  return "DBRADIOGROUP";
}

#endif DBRADIOGROUP_H_
