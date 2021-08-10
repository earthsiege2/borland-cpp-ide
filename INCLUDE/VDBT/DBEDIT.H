//--------------------------------------------------------
// DBEDIT.H generated from BDBCTL.VBX
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBEDIT_H_)
#define DBEDIT_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBEdit (VB3, subclassed from EDIT)
//--------------------------------------------------------

class _DBAWARECLASS TDBEdit : public TDBControl {
  DBPMECLASS( TDBEdit );

  // constructors
  DECLARE_CONSTRUCTORS( TDBEdit );

  public:
    // Edit specific Properties
    DECLARE_DB_PROP_RW2( TField, DataField );
    DECLARE_DB_PROP_RW0( Bool,    DataChanged,    Prop_TDBEdit_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF,ForeColor,      Prop_TDBEdit_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF,BackColor,      Prop_TDBEdit_BackColor );
    DECLARE_DB_PROP_RW2( string,  FontName );
    DECLARE_DB_PROP_RW0( Bool,    FontBold,       Prop_TDBEdit_FontBold );
    DECLARE_DB_PROP_RW0( Bool,    FontItalic,     Prop_TDBEdit_FontItalic );
    DECLARE_DB_PROP_RW0( Bool,    FontStrikethru, Prop_TDBEdit_FontStrikethru );
    DECLARE_DB_PROP_RW0( Bool,    FontUnderline,  Prop_TDBEdit_FontUnderline );
    DECLARE_DB_PROP_RW0( float,   FontSize,       Prop_TDBEdit_FontSize );
    DECLARE_DB_PROP_RW0( Bool,    AutoSelect,     Prop_TDBEdit_AutoSelect );
    DECLARE_DB_PROP_RW0( Bool,    AutoSize,       Prop_TDBEdit_AutoSize );
    DECLARE_DB_PROP_RW1( ENUM, TBorderStyle
                            ,     BorderStyle,    Prop_TDBEdit_BorderStyle );
    DECLARE_DB_PROP_RW2( string,Caption );
    DECLARE_DB_PROP_RW1( ENUM, TEditCharCase
                            ,     CharCase,       Prop_TDBEdit_CharCase );
    DECLARE_DB_PROP_RW0( int,     MaxLength,      Prop_TDBEdit_MaxLength );
    DECLARE_DB_PROP_RW0( Bool,    Modified,       Prop_TDBEdit_Modified );
    DECLARE_DB_PROP_RW2( string,  PasswordChar );
    DECLARE_DB_PROP_RW0( Bool,    ReadOnly,       Prop_TDBEdit_ReadOnly );
    DECLARE_DB_PROP_RW0( int,     SelLength,      Prop_TDBEdit_SelLength );
    DECLARE_DB_PROP_RW0( int,     SelStart,       Prop_TDBEdit_SelStart );
    DECLARE_DB_PROP_RW2( string,  SelText );


  public:
    // Methods
    void Clear();
    void ClearSelection();
    void CopyToClipboard();
    void CutToClipboard();
    int  GetSelTextBuf( LPSTR, int );
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
    DECLARE_SOURCE( OnChange,    TDBEditNotify );
    DECLARE_SOURCE( OnClick,     TDBEditNotify );
    DECLARE_SOURCE( OnDblClick,  TDBEditNotify );
    DECLARE_SOURCE( OnDragDrop,  TDBEditDrag );
    DECLARE_SOURCE( OnDragOver,  TDBEditDragOver );
    DECLARE_SOURCE( OnEndDrag,   TDBEditDrag );
    DECLARE_SOURCE( OnEnter,     TDBEditNotify );
    DECLARE_SOURCE( OnExit,      TDBEditNotify );
    DECLARE_SOURCE( OnKeyDown,   TDBEditKey );
    DECLARE_SOURCE( OnKeyPress,  TDBEditKeyPress );
    DECLARE_SOURCE( OnKeyUp,     TDBEditKey );
    DECLARE_SOURCE( OnMouseDown, TDBEditMouse );
    DECLARE_SOURCE( OnMouseMove, TDBEditMouse );
    DECLARE_SOURCE( OnMouseUp,   TDBEditMouse );

    // Event Handlers
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
  DECLARE_RESPONSE_TABLE( TDBEdit );
#endif __OWL_VBXCTL_H
};

// Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBEdit, _TDBEdit )
DEFINE_DB_PROP_STRING( TDBEdit, _TDBEdit, FontName );
DEFINE_DB_PROP_STRING( TDBEdit, _TDBEdit, Caption );
DEFINE_DB_PROP_STRING( TDBEdit, _TDBEdit, PasswordChar );
DEFINE_DB_PROP_STRING( TDBEdit, _TDBEdit, SelText );

// Methods
inline void TDBEdit::Clear()
{
  ::VBXMethodClear( GetHCTL() );
}

inline void TDBEdit::ClearSelection()
{
  SelText = &string();
}

inline void TDBEdit::CutToClipboard()
{
  CopyToClipboard();
  ClearSelection();
}

inline char far* TDBEdit::GetClassName()
{
  return "DBEDIT";
}

inline void TDBEdit::SelectAll()
{
  int i = 0;

  SelStart  = i;
  i = 0xFFFF;
  SelLength = i;
}

#endif DBEDIT_H_
