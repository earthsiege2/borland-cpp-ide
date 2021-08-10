//--------------------------------------------------------
// DBIMAGE.H generated from BDBCTL.VBX
// Copyrights (C) 1996 Borland International
//--------------------------------------------------------

#if !defined(DBIMAGE_H_)
#define DBIMAGE_H_

#include <vdbt/dbcontrl.h>

//--------------------------------------------------------
// TDBImage (VB3)
//--------------------------------------------------------

class _DBAWARECLASS TDBImage : public TDBControl {
  DBPMECLASS( TDBImage );

  // constructors
  DECLARE_CONSTRUCTORS( TDBImage );

  public:
    // Properties
    DECLARE_DB_PROP_RW2( TField,  DataField );
    DECLARE_DB_PROP_RW0( Bool,     DataChanged, Prop_TDBImage_DataChanged );
    DECLARE_DB_PROP_RW0( COLORREF, ForeColor,   Prop_TDBImage_ForeColor );
    DECLARE_DB_PROP_RW0( COLORREF, BackColor,   Prop_TDBImage_BackColor );
    DECLARE_DB_PROP_RW0( Bool,     AutoDisplay, Prop_TDBImage_AutoDisplay );
    DECLARE_DB_PROP_RW0( Bool,     AutoSize,    Prop_TDBImage_AutoSize );
    DECLARE_DB_PROP_RW1( ENUM, TBorderStyle
                             ,     BorderStyle, Prop_TDBImage_BorderStyle );
    DECLARE_DB_PROP_RW2( string,   Caption );
    DECLARE_DB_PROP_RW0( Bool,     Center,      Prop_TDBImage_Center );
    DECLARE_DB_PROP_RW0( HPIC,     Picture,     Prop_TDBImage_Picture );
    DECLARE_DB_PROP_RW0( Bool,     ReadOnly,    Prop_TDBImage_ReadOnly );
    DECLARE_DB_PROP_RW0( Bool,     Stretch,     Prop_TDBImage_Stretch );


  public:
    // Methods
    void CopyToClipboard();
    void CutToClipboard();
    void LoadPicture();
    void PasteFromClipboard();

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

  public:
    // Event Source
    DECLARE_SOURCE( OnClick,     TDBImageNotify );
    DECLARE_SOURCE( OnDblClick,  TDBImageNotify );
    DECLARE_SOURCE( OnDragDrop,  TDBImageDrag );
    DECLARE_SOURCE( OnDragOver,  TDBImageDragOver );
    DECLARE_SOURCE( OnEndDrag,   TDBImageDrag );
    DECLARE_SOURCE( OnEnter,     TDBImageNotify );
    DECLARE_SOURCE( OnExit,      TDBImageNotify );
    DECLARE_SOURCE( OnKeyDown,   TDBImageKey );
    DECLARE_SOURCE( OnKeyPress,  TDBImageKeyPress );
    DECLARE_SOURCE( OnKeyUp,     TDBImageKey );
    DECLARE_SOURCE( OnMouseDown, TDBImageMouse );
    DECLARE_SOURCE( OnMouseMove, TDBImageMouse );
    DECLARE_SOURCE( OnMouseUp,   TDBImageMouse );

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

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBImage );
#endif __OWL_VBXCTL_H
};

//Inlines
// Properties
DEFINE_DB_PROP_DATAFIELD( TDBImage, _TDBImage )
DEFINE_DB_PROP_STRING( TDBImage, _TDBImage, Caption );

// Methods
inline void TDBImage::CopyToClipboard()
{
  ::VBXCopy( GetHCTL() );
}

void TDBImage::CutToClipboard()
{
  HPIC h = NULL;

  CopyToClipboard();
  Picture = h;
}

inline void TDBImage::PasteFromClipboard()
{
  ::VBXPaste( GetHCTL() );
}

inline void TDBImage::LoadPicture()
{
  ::VBXMethodRefresh( GetHCTL() );
}

inline char far* TDBImage::GetClassName()
{
  return "DBIMAGE";
}

#endif DBIMAGE_H_
