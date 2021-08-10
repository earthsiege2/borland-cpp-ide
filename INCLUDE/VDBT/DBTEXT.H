//--------------------------------------------------------
// DBTEXT.H generated from BDBCTL.VBX
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBTEXT_H_)
#define DBTEXT_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBText (VB3, subclassed from STATIC)
//--------------------------------------------------------

class _DBAWARECLASS TDBText : public TDBControl {
  DBPMECLASS( TDBText );

  // constructors
  DECLARE_CONSTRUCTORS( TDBText );

  public:
    // Properties
    DECLARE_DB_PROP_RW2( TField, DataField );
    DECLARE_DB_PROP_RW0( Bool,    DataChanged,    Prop_TDBText_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF,ForeColor,      Prop_TDBText_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF,BackColor,      Prop_TDBText_BackColor );
    DECLARE_DB_PROP_RW2( string,  FontName );
    DECLARE_DB_PROP_RW0( Bool,    FontBold,       Prop_TDBText_FontBold );
    DECLARE_DB_PROP_RW0( Bool,    FontItalic,     Prop_TDBText_FontItalic );
    DECLARE_DB_PROP_RW0( Bool,    FontStrikethru, Prop_TDBText_FontStrikethru );
    DECLARE_DB_PROP_RW0( Bool,    FontUnderline,  Prop_TDBText_FontUnderline );
    DECLARE_DB_PROP_RW0( float,   FontSize,       Prop_TDBText_FontSize );
    DECLARE_DB_PROP_RW1( ENUM, TBorderStyle
                             ,   BorderStyle,     Prop_TDBText_BorderStyle );
    DECLARE_DB_PROP_RW1( ENUM, TAlignment
                             ,    Alignment,      Prop_TDBText_Alignment );
    DECLARE_DB_PROP_RW0( Bool,    AutoSize,       Prop_TDBText_AutoSize );
    DECLARE_DB_PROP_RW2( string,  Caption );
    DECLARE_DB_PROP_RW0( Bool,    Transparent,    Prop_TDBText_Transparent );
    DECLARE_DB_PROP_RW1( ENUM, TTextWordWrap
                             ,    WordWrap,       Prop_TDBText_WordWrap );

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
    DECLARE_SOURCE( OnClick,     TDBTextNotify );
    DECLARE_SOURCE( OnDblClick,  TDBTextNotify );
    DECLARE_SOURCE( OnDragDrop,  TDBTextDrag );
    DECLARE_SOURCE( OnDragOver,  TDBTextDragOver );
    DECLARE_SOURCE( OnEndDrag,   TDBTextDrag );
    DECLARE_SOURCE( OnMouseDown, TDBTextMouse );
    DECLARE_SOURCE( OnMouseMove, TDBTextMouse );
    DECLARE_SOURCE( OnMouseUp,   TDBTextMouse );

    // Event Handlers
    DECLARE_DB_EVENT( OnClick,     TNotifyEvent );
    DECLARE_DB_EVENT( OnDragDrop,  TDragEvent );
    DECLARE_DB_EVENT( OnDragOver,  TDragOverEvent );
    DECLARE_DB_EVENT( OnEndDrag,   TDragEvent );
    DECLARE_DB_EVENT( OnDblClick,  TNotifyEvent );
    DECLARE_DB_EVENT( OnMouseDown, TMouseEvent );
    DECLARE_DB_EVENT( OnMouseMove, TMouseEvent );
    DECLARE_DB_EVENT( OnMouseUp,   TMouseEvent );

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBText );
#endif __OWL_VBXCTL_H
};

// Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBText, _TDBText )
DEFINE_DB_PROP_STRING( TDBText, _TDBText, FontName );
DEFINE_DB_PROP_STRING( TDBText, _TDBText, Caption );

// Methods
inline char far* TDBText::GetClassName()
{
  return "DBTEXT";
}

#endif DBTEXT_H_
