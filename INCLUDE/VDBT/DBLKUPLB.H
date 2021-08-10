//--------------------------------------------------------
// DBLKUPLB.H generated from BDBCTL.VBX
// Copyright (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBLOOKUPLIST_H_)
#define DBLOOKUPLIST_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBLookupList (VB3, subclassed from LISTBOX)
//--------------------------------------------------------

class _DBAWARECLASS TDBLookupList : public TDBControl {
  DBPMECLASS( TDBLookupList );

  // constructors
  DECLARE_CONSTRUCTORS( TDBLookupList );

  public:
    // Properties
    DECLARE_DB_PROP_RW2( TField, DataField );
    DECLARE_DB_PROP_RW0( Bool,  DataChanged,   Prop_TDBLookupList_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF,ForeColor,   Prop_TDBLookupList_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF,BackColor,   Prop_TDBLookupList_BackColor );
    DECLARE_DB_PROP_RW2( string,FontName );
    DECLARE_DB_PROP_RW0( Bool,  FontBold,      Prop_TDBLookupList_FontBold );
    DECLARE_DB_PROP_RW0( Bool,  FontItalic,    Prop_TDBLookupList_FontItalic );
    DECLARE_DB_PROP_RW0( Bool,  FontStrikethru,Prop_TDBLookupList_FontStrikethru );
    DECLARE_DB_PROP_RW0( Bool,  FontUnderline, Prop_TDBLookupList_FontUnderline );
    DECLARE_DB_PROP_RW0( float, FontSize,      Prop_TDBLookupList_FontSize );
    DECLARE_DB_PROP_RW1( ENUM, TBorderStyle
                             ,  BorderStyle,   Prop_TDBLookupList_BorderStyle );
    DECLARE_DB_PROP_RW2( string,Caption );
    DECLARE_DB_PROP_RW2( string,DisplayValue );
    DECLARE_DB_PROP_RW0( int,   FieldCount,    Prop_TDBLookupList_FieldCount );
    DECLARE_DB_PROP_RW0( Bool,  IntegralHeight,Prop_TDBLookupList_IntegralHeight );
    DECLARE_DB_PROP_RW0( int,   ItemHeight,    Prop_TDBLookupList_ItemHeight );
    DECLARE_DB_PROP_RW0( int,   ItemIndex,     Prop_TDBLookupList_ItemIndex );
    DECLARE_DB_PROP_RW2( TDataSource,LookupSource );
    DECLARE_DB_PROP_RW2( TField,     LookupField );
    DECLARE_DB_PROP_RW2( string,LookupDisplay );
    DECLARE_DB_PROP_RW1( int, TDBLookupListOptions
                               ,Options,      Prop_TDBLookupList_Options );
    DECLARE_DB_PROP_RW0( Bool,  ReadOnly,     Prop_TDBLookupList_ReadOnly );
    DECLARE_DB_PROP_RW2( string,SelectedField );
    DECLARE_DB_PROP_RW0( int,   SelectedIndex,Prop_TDBLookupList_SelectedIndex );
    DECLARE_DB_PROP_RW0( Bool,  Sorted,        Prop_TDBLookupList_Sorted );
    DECLARE_DB_PROP_RW1( ENUM, TListBoxStyle
                             ,  Style,         Prop_TDBLookupList_Style );
    DECLARE_DB_PROP_RW2( string,Value );
  private:
    DECLARE_DB_PROP_RO1( long, HCTL
                             ,  LookupHCTL,    Prop_TDBLookupList_LookupHctl );


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

  public:
    // Event Source
    DECLARE_SOURCE( OnClick,    TDBLookupListNotify );
    DECLARE_SOURCE( OnDblClick, TDBLookupListNotify );
    DECLARE_SOURCE( OnDragDrop, TDBLookupListDrag );
    DECLARE_SOURCE( OnDragOver, TDBLookupListDragOver );
    DECLARE_SOURCE( OnEndDrag,  TDBLookupListDrag );
    DECLARE_SOURCE( OnEnter,    TDBLookupListNotify );
    DECLARE_SOURCE( OnExit,     TDBLookupListNotify );
    DECLARE_SOURCE( OnKeyDown,  TDBLookupListKey );
    DECLARE_SOURCE( OnKeyPress, TDBLookupListKeyPress );
    DECLARE_SOURCE( OnKeyUp,    TDBLookupListKey );

    // Event Handlers
    EVENT( OnClick,    TDBControl, TNotifyEvent );
    EVENT( OnDragDrop, TDBControl, TDragEvent );
    EVENT( OnDragOver, TDBControl, TDragOverEvent );
    EVENT( OnEndDrag,  TDBControl, TDragEvent );
    DECLARE_DB_EVENT( OnDblClick, TNotifyEvent );
    DECLARE_DB_EVENT( OnEnter,    TNotifyEvent );
    DECLARE_DB_EVENT( OnExit,     TNotifyEvent );
    DECLARE_DB_EVENT( OnKeyDown,  TKeyEvent );
    DECLARE_DB_EVENT( OnKeyPress, TKeyPressEvent );
    DECLARE_DB_EVENT( OnKeyUp,    TKeyEvent );

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBLookupList );
#endif __OWL_VBXCTL_H
};

// Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBLookupList )
DEFINE_DB_PROP_LOOKUPFIELD( TDBLookupList )
DEFINE_DB_PROP_LOOKUPSOURCE( TDBLookupList )
DEFINE_DB_PROP_STRING( TDBLookupList, FontName );
DEFINE_DB_PROP_STRING( TDBLookupList, Caption );
DEFINE_DB_PROP_STRING( TDBLookupList, DisplayValue );
DEFINE_DB_PROP_STRING( TDBLookupList, LookupDisplay );
DEFINE_DB_PROP_STRING( TDBLookupList, Value );

// Methods
inline char far* TDBLookupList::GetClassName()
{
  return "DBLOOKUPLIST";
}

#endif DBLOOKUPLIST_H_
