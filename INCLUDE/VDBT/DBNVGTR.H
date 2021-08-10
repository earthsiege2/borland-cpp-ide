//--------------------------------------------------------
// DBNVGTR.H generated from BDBCTL.VBX
// Copyright (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBNAVIGATOR_H_)
#define  DBNAVIGATOR_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBNavigator (VB3)
//--------------------------------------------------------

class _DBAWARECLASS TDBNavigator : public TDBControl {
  DBPMECLASS( TDBNavigator );

  // constructors
  DECLARE_CONSTRUCTORS( TDBNavigator );


  public:
    // Properties
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnFirst,       Prop_TDBNavigator_BtnFirst );
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnPrevious,    Prop_TDBNavigator_BtnPrevious );
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnNext,        Prop_TDBNavigator_BtnNext );
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnLast,        Prop_TDBNavigator_BtnLast );
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnInsert,      Prop_TDBNavigator_BtnInsert );
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnDelete,      Prop_TDBNavigator_BtnDelete );
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnEdit,        Prop_TDBNavigator_BtnEdit );
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnPost,        Prop_TDBNavigator_BtnPost );
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnCancel,      Prop_TDBNavigator_BtnCancel );
    DECLARE_DB_PROP_RW1( ENUM, TBtnState
                             , BtnRefresh,     Prop_TDBNavigator_BtnRefresh );
    DECLARE_DB_PROP_RW0( Bool,  ConfirmDelete, Prop_TDBNavigator_ConfirmDelete );
  private:
    DECLARE_DB_PROP_RW1( ENUM, TNavigateBtn
                             , ClickButton,    Prop_TDBNavigator_ClickButton );

  public:
    // Methods
    void BtnClick( TNavigateBtn );


  private:
    void FireOnClick( TNavigateBtn Btn )
    {
      OnClickSource( *this, Btn );
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
    void FireOnReSize()
    {
      OnReSizeSource( *this );
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
    DECLARE_SOURCE( OnClick,    TDBNavigatorClick );
    DECLARE_SOURCE( OnDblClick, TDBNavigatorNotify );
    DECLARE_SOURCE( OnDragDrop, TDBNavigatorDrag );
    DECLARE_SOURCE( OnDragOver, TDBNavigatorDragOver );
    DECLARE_SOURCE( OnEndDrag,  TDBNavigatorDrag );
    DECLARE_SOURCE( OnEnter,    TDBNavigatorNotify );
    DECLARE_SOURCE( OnExit,     TDBNavigatorNotify );
    DECLARE_SOURCE( OnReSize,   TDBNavigatorNotify );

    // Event Handlers
    DECLARE_DB_EVENT( OnClick,    TNavClick );
    EVENT( OnDragDrop, TDBControl, TDragEvent );
    EVENT( OnDragOver, TDBControl, TDragOverEvent );
    EVENT( OnEndDrag,  TDBControl, TDragEvent );
    DECLARE_DB_EVENT( OnDblClick, TNotifyEvent );
    DECLARE_DB_EVENT( OnEnter,    TNotifyEvent );
    DECLARE_DB_EVENT( OnExit,     TNotifyEvent );
    DECLARE_DB_EVENT( OnReSize,   TNotifyEvent );

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBNavigator );
#endif __OWL_VBXCTL_H
};

// Inlines
// Methods
inline void TDBNavigator::BtnClick( TNavigateBtn Btn )
{
  ClickButton = Btn;
}

inline char far* TDBNavigator::GetClassName()
{
  return "DBNAVIGATOR";
}

#endif  DBNAVIGATOR_H_
