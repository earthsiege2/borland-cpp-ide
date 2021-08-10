//--------------------------------------------------------
// DBCONTRL.H
// Copyrights (C) 1996 Borland International
// All Rights Reserved
//--------------------------------------------------------

#if !defined(DBCONTROL_H_)
#define DBCONTROL_H_


#include <owl/vbxctl.h>
#include <vdbt/dbdefs.h>
#include <vdbt/dbtype.h>
#include <vdbt/dbpme.h>
#include <vdbt/dbevent.h>

//----------------------------------------------------------------------
// TDBControl Class Declaration
//----------------------------------------------------------------------
#ifdef __OWL_VBXCTL_H
class _DBAWARECLASS TDBControl : public TVbxControl {
#else                  // None Owl class
class TDBControl {
#endif __OWL_VBXCTL_H
  DBPMECLASS( TDBControl );

  public:
    // constructors
    TDBControl( TWindow*, int, LPCSTR, LPCSTR, int, int, int, int, TModule*x=0 );
    TDBControl( TWindow*, int, TModule*x=0 );


  public:
    // Common Properties
    DECLARE_DB_PROP_RW2( string, Name );
    DECLARE_DB_PROP_RW0( int,    ComponentIndex, Prop_TDBControl_Index );
    DECLARE_DB_PROP_RW0( long,   Left,           Prop_TDBControl_Left );
    DECLARE_DB_PROP_RW0( long,   Top,            Prop_TDBControl_Top );
    DECLARE_DB_PROP_RW0( long,   Width,          Prop_TDBControl_Width );
    DECLARE_DB_PROP_RW0( long,   Height,         Prop_TDBControl_Height );
    DECLARE_DB_PROP_RW0( Bool,   Visible,        Prop_TDBControl_Visible );
    DECLARE_DB_PROP_RW2( string, Tag );
    DECLARE_DB_PROP_RW1( ENUM, TDragMode
                             ,   DragMode,       Prop_TDBControl_DragMode );
    DECLARE_DB_PROP_RW0( HPIC,   DragIcon,       Prop_TDBControl_DragIcon );
    DECLARE_DB_PROP_RW1( ENUM, TMousePointer
                             ,   Cursor,         Prop_TDBControl_MousePointer );
    DECLARE_DB_PROP_RW0( Bool,   Enabled,        Prop_TDBControl_Enabled );
    DECLARE_DB_PROP_RW0( long,   HelpContext,    Prop_TDBControl_HelpContextID );
    DECLARE_DB_PROP_RO0( int,    TabOrder,       Prop_TDBControl_TabIndex );
    DECLARE_DB_PROP_RW0( Bool,   TabStop,        Prop_TDBControl_TabStop );
    DECLARE_DB_PROP_RW1( ENUM, TAlign
                             ,   Align,          Prop_TDBControl_Align );
    DECLARE_DB_PROP_RW2( TDataSource, DataSource );

#ifdef __OWL_VBXCTL_H
    DECLARE_DB_PROP_RW( TWindow*, Parent );
    DECLARE_DB_PROP_RW( TWindow*, Owner );
    DECLARE_DB_PROP_RW( TRect,    BoundsRect );
#endif __OWL_VBXCTL_H


  public:
    // Common Methods
    void   BeginDrag( bool /* Imediate */ );
    void   BringToFront();
    bool   CanFocus();
    TPoint ClientToScreen( TPoint pt );
    bool   Dragging();
    void   EndDrag( bool Drop );
    bool   Focused();
    int    GetTextBuf( LPSTR Buff, int Len );
    int    GetTextLen();
    void   Hide();
    void   Invalidate();
    void   Refresh();
    void   Repaint();
    void   ScaleBy( int M, int D );
    TPoint ScreenToClient( TPoint pt );
    void   ScrollBy( int DeltaX, int DeltaY );
    void   SendToBack();
    void   SetBounds( int l, int t, int w, int h );
    void   SetTextBuf( LPCSTR lpsz );
    void   Show();
    void   Update();

  protected:
    char far* GetClassName();

#ifdef __OWL_VBXCTL_H
  DECLARE_RESPONSE_TABLE( TDBControl );
#endif __OWL_VBXCTL_H
};

//Inlines
DEFINE_DB_PROP_DATASOURCE( TDBControl )
DEFINE_DB_PROP_STRING( TDBControl, _TDBControl, Name );
DEFINE_DB_PROP_STRING( TDBControl, _TDBControl, Tag );

// Properties Getters() and Setters()
inline TDBControl::prParent::operator TWindow*()
{
  TDBControl *pCtl = DBOUTER( Parent );
  return pCtl->GetApplication()->GetWindowPtr( pCtl->GetParent() );
}

inline TWindow*& TDBControl::prParent::operator=( TWindow*& Prnt )
{
  DBOUTER( Parent )->SetParent( Prnt );
  return Prnt;
}

#ifdef __OWL_VBXCTL_H
inline TDBControl::prOwner::operator TWindow*()
{
  return DBOUTER( Owner )->TWindow::Parent;
}

inline TWindow*& TDBControl::prOwner::operator=( TWindow*& Owner )
{
  TDBControl *pCtl = DBOUTER( Owner );
  HWND hSaved = pCtl->HWindow;

  pCtl->HWindow = 0;
  pCtl->SetParent( Owner );
  pCtl->HWindow = hSaved;
  return Owner;
}

inline TDBControl::prBoundsRect::operator TRect()
{
  TRect Rect;

  DBOUTER( Name )->GetWindowRect( Rect );
  return Rect;
}

inline TRect& TDBControl::prBoundsRect::operator=( TRect& Rect )
{
  DBOUTER( Name )->SetBounds( Rect.left, Rect.top, Rect.right, Rect.bottom );
  return Rect;
}

// Methods
inline void TDBControl::BeginDrag( bool /* Imediate */ )
{
  // Note: Immediate is currently not implemented
  Drag( 1 );
}

inline void TDBControl::BringToFront()
{
  BringWindowToTop();
}

inline bool TDBControl::CanFocus()
{
  return IsWindowVisible() && IsWindowEnabled();
}

inline TPoint TDBControl::ClientToScreen( TPoint pt )
{
  TWindow::ClientToScreen( pt );
  return pt;
}

inline bool TDBControl::Dragging()
{
  return bool( SendMessage( ::RegisterWindowMessage( "BDBCtl::Dragging" ), 0, 0L ) );
}

inline void TDBControl::EndDrag( bool Drop )
{
  Drag( Drop ? 2 : 0 );
}

inline bool TDBControl::Focused()
{
  return GetFocus() == HWindow;
}

inline int TDBControl::GetTextBuf( LPSTR Buff, int Len )
{
  return GetWindowText( Buff, Len );
}

inline int TDBControl::GetTextLen()
{
  return GetWindowTextLength();
}

inline void TDBControl::Hide()
{
  TWindow::Show( SW_HIDE );
}

inline void TDBControl::Invalidate()
{
  TWindow::Invalidate( true );
}

inline void TDBControl::Refresh()
{
  TWindow::Invalidate( true ); UpdateWindow();
}

inline void TDBControl::ScaleBy( int M, int D )
{
  TRect rc;

  GetWindowRect( rc );
  SetWindowPos( NULL, 0, 0, rc.Width() * M / D
                          , rc.Height() * M / D, SWP_NOMOVE | SWP_NOZORDER );
}

inline void TDBControl::ScrollBy( int DeltaX, int DeltaY )
{
  ScrollWindow( DeltaX, DeltaY );
}

inline void TDBControl::Repaint()
{
  TWindow::Invalidate( false );
}

inline TPoint TDBControl::ScreenToClient( TPoint pt )
{
  TWindow::ScreenToClient( pt );
  return pt;
}

inline void TDBControl::SendToBack()
{
  SetWindowPos( HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
}

inline void TDBControl::SetBounds( int l, int t, int w, int h )
{
  SetWindowPos( NULL, l, t, w, h, SWP_NOZORDER );
}

inline void TDBControl::SetTextBuf( LPCSTR lpsz )
{
  SetWindowText( lpsz );
}

inline void TDBControl::Show()
{
  TWindow::Show( SW_SHOW );
}

inline void TDBControl::Update()
{
  UpdateWindow();
}

inline char far* TDBControl::GetClassName()
{
  return "DBCONTROL";
}

#endif __OWL_VBXCTL_H

#endif DBCONTROL_H_
