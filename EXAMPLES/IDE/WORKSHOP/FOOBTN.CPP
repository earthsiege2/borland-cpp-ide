// Borland C++ - (C) Copyright 1991, 1992 by Borland International
//
//  Resource Workshop 32-bit Custom Control Example

// headers
#include <windows.h>
#include <windowsx.h>
#include <custcntl.h>

#include <except.h>

#include <winsys\geometry.h>

#include "foobtn.h"
#include "foobtn.rh"

// types
enum ButtonState { bsUp, bsDown, bsFocused };

struct FooBtnData
{

  ButtonState State;
  bool Capture;
  HFONT Font;

};

struct FooBtnStyleDlgData
{

  HWND Parent;
  CCSTYLEA *InitData;

};

// constants
const char * const FooBtnClass = "FOOBTN";
const int GWL_FOOBTNDATA = 0;
const COLORREF LtGray = RGB( 192, 192, 192 );
const COLORREF DkGray = RGB( 128, 128, 128 );
const COLORREF Black = RGB( 0, 0, 0 );

static COLORREF Colors[4] =
  {
    RGB(255, 0, 0),   // Red
    RGB(0, 255, 0),   // Green
    RGB(0, 0, 255),   // Blue
    RGB(255, 255, 0)  // Yellow
  };

// globals
HINSTANCE FBInstance;

// Function prototypes:
//
BOOL WINAPI            DllEntryPoint( HINSTANCE hInst, DWORD fdwReason, LPVOID lpvReserved );
bool                   InitWindowClasses( HINSTANCE hInst );

extern "C"
{
  UINT CALLBACK __export CustomControlInfoA( LPCCINFOA acci );
  BOOL CALLBACK __export FooBtnStyleA( HWND parent, LPCCSTYLEA pccs );
  INT  CALLBACK __export FooBtnSizeToTextA( DWORD flStyle, DWORD flExtStyle, HFONT hFont, LPSTR pszText );
}


// Dialog procedure and message handlers for Control Style Dialog.
//
BOOL CALLBACK __export
FooButtonStyleDlgProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

BOOL EvFBStyleInitDialog( HWND hwnd, HWND hwndFocus, LPARAM lParam );
void EvFBStyleCommand( HWND hwnd, int id, HWND hwndCtl, UINT codeNotify );

static unsigned long StyleFromId( HWND parent, int baseCtrl, int numCtrls );


// Window message handlers
//
LRESULT CALLBACK __export
FooButtonWndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

BOOL  EvFooBtnCreate( HWND hwnd, LPCREATESTRUCT lpCreateStruct );
void  EvFooBtnDestroy( HWND hwnd );
void  EvFooBtnLButtonDown( HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags );
void  EvFooBtnLButtonUp( HWND hwnd, int x, int y, UINT keyFlags );
void  EvFooBtnMouseMove( HWND hwnd, int x, int y, UINT keyFlags );
void  EvFooBtnSetFocus( HWND hwnd, HWND hwndOldFocus );
void  EvFooBtnKillFocus( HWND hwnd, HWND hwndOldFocus );
BOOL  EvFooBtnEraseBkgnd( HWND hwnd, HDC hdc );
void  EvFooBtnPaint(HWND hwnd);
void  EvFooBtnSetFont( HWND hwnd, HFONT hfont, BOOL fRedraw );
HFONT EvFooBtnGetFont( HWND hwnd );


// Inlines for retrieving state information about particular window instance.
//
inline FooBtnData *
GetFooButtonData( HWND hwnd )
{
  return (FooBtnData *) GetWindowLong( hwnd, GWL_FOOBTNDATA );
}


// ----------------------------------------------------------------------------
//
//   Initialization
//
// ----------------------------------------------------------------------------
BOOL WINAPI
DllEntryPoint( HINSTANCE hInst, DWORD fdwReason, LPVOID /*lpvReserved*/ )
{
  bool result = true;

  switch( fdwReason )
  {
  case DLL_PROCESS_ATTACH:
    FBInstance = hInst;
    result = InitWindowClasses( hInst );
    break;
  }

  return result;
}

bool
InitWindowClasses( HINSTANCE hInst )
{
  WNDCLASS fooBtnClass;
  bool result;

  // Use WinNT STATIC control class as a guideline...
  //
  GetClassInfo( 0, "STATIC", &fooBtnClass );

  fooBtnClass.style = CS_GLOBALCLASS | CS_PARENTDC;
  fooBtnClass.lpfnWndProc = FooButtonWndProc;
  fooBtnClass.cbClsExtra = 0;
  fooBtnClass.cbWndExtra = 4;
  fooBtnClass.hInstance = hInst;
  fooBtnClass.hIcon = 0;
  fooBtnClass.hbrBackground = 0;
  fooBtnClass.lpszMenuName = 0;
  fooBtnClass.lpszClassName = FooBtnClass;

  result = (RegisterClass( &fooBtnClass ) != 0) ? true : false;

  return result;
}

// ----------------------------------------------------------------------------
//
//   Foo Button Custom Control Registration and Dialog Editor Support
//
// ----------------------------------------------------------------------------

CCINFOA FooBtnInfo =
  {
    { 'F', 'O', 'O', 'B', 'T', 'N', '\0' },
                          // Class name for control
    0,                    // CCF_ flags
    { 'F', 'o', 'o', ' ', 'B', 'u', 't', 't', 'o', 'n', '\0' },
                          // Short descriptive text
    50, 14,               // Default width & height
    FBS_FGYELLOW | FBS_BGBLUE | WS_CHILD | WS_VISIBLE | WS_TABSTOP,
                          // Default style
    0,
                          // Default ex-style
    0xF,                  // Control type mask, e.g. SS_TYPEMASK
    { 'P', 'u', 's', 'h', ' ', 'M', 'e', '\0' },
                          // Default text (CAPTION field?)
    0,                    // Number of entries in style table
    0,                    // Style table.
    FooBtnStyleA,         // Style editing function - brings up edit style dialog.
    FooBtnSizeToTextA,    // Size to Text function - allows control to size to caption.
    0, 0                  // Two reserved DWORD fields.
  };

//
// Usage of CustomControlInfo() - call first w/ NULL to find out how many
// controls are in the DLL, then call again w/ appropriately sized array
// of CCINFO structs to retrieve the data.
//
UINT CALLBACK __export
CustomControlInfoA( LPCCINFOA acci )
{
  if( acci )
  {
    memcpy( acci, &FooBtnInfo, sizeof( FooBtnInfo ) );
  }

  return 1;
}

BOOL CALLBACK __export
FooBtnStyleA( HWND parent, LPCCSTYLEA pccs )
{
  bool result = false;

  if( pccs )
  {
    FooBtnStyleDlgData FBData;
    FBData.Parent = parent;
    FBData.InitData = pccs;

    result = DialogBoxParam( FBInstance, MAKEINTRESOURCE( IDD_EDITSTYLES ),
                             parent, FooButtonStyleDlgProc, (LPARAM) &FBData
                           );
  }

  return result;
}

INT CALLBACK __export
FooBtnSizeToTextA( DWORD /*flStyle*/, DWORD /*flExtStyle*/, HFONT hFont, LPSTR pszText )
{
  // !PW Not implemented yet.
  return -1;
}

BOOL CALLBACK __export
FooButtonStyleDlgProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
  switch( msg )
  {
    HANDLE_MSG( hwnd, WM_INITDIALOG, EvFBStyleInitDialog );
    HANDLE_MSG( hwnd, WM_COMMAND, EvFBStyleCommand );
  }

  return FALSE;
}

BOOL
EvFBStyleInitDialog( HWND hwnd, HWND /*hwndFocus*/, LPARAM lParam )
{
  bool result = true;
  FooBtnStyleDlgData *FBData = (FooBtnStyleDlgData *) lParam;

  if( FBData && SetProp( hwnd, "FBData", (HANDLE) FBData ) )
  {
    // Center the dialog above the parent window.
    //
    TRect p, c;
    TPoint r;

    GetWindowRect( FBData->Parent, &p );
    GetWindowRect( hwnd, &c );

    r.x = p.left + (p.Width() - c.Width()) / 2;
    r.y = p.top + (p.Height() - c.Height()) / 2;

    MoveWindow( hwnd, r.x, r.y, c.Width(), c.Height(), false );

    // Initialize the radio button controls
    //
    int id = ((FBData->InitData->flStyle & FBS_FTEXTMASK) >> FBS_FTEXTSHIFT) + IDC_FTEXTRED - 1;
    HWND focusCtrl = GetDlgItem( hwnd, id );
    Button_SetCheck( focusCtrl, true );

    id = ((FBData->InitData->flStyle & FBS_BTEXTMASK) >> FBS_BTEXTSHIFT) + IDC_BTEXTRED - 1;
    Button_SetCheck( GetDlgItem( hwnd, id ), true );
    SetFocus( focusCtrl );
    result = false;
  }
  else
  {
    EndDialog( hwnd, false );
  }

  return result;
}

void
EvFBStyleCommand( HWND hwnd, int id, HWND /*hwndCtl*/, UINT codeNotify )
{
  switch( id )
  {

  case IDOK:
    if( codeNotify == BN_CLICKED )
    {
      FooBtnStyleDlgData *FBData = (FooBtnStyleDlgData *) GetProp( hwnd, "FBData" );
      if( FBData )
      {
        FBData->InitData->flStyle &= ~(FBS_FTEXTMASK | FBS_BTEXTMASK);
        FBData->InitData->flStyle |= StyleFromId( hwnd, IDC_FTEXTRED, 4 );
        FBData->InitData->flStyle |= StyleFromId( hwnd, IDC_BTEXTRED, 4 );
      }

      RemoveProp( hwnd, "FBData" );
      EndDialog( hwnd, TRUE );
    }
    break;

  case IDCANCEL:
    if( codeNotify == BN_CLICKED )
    {
      RemoveProp( hwnd, "FBData" );
      EndDialog( hwnd, FALSE );
    }
    break;

  }
}

static unsigned long StyleFromId( HWND parent, int baseCtrl, int numCtrls )
{
  unsigned long style;
  int ctrlId;

  for( ctrlId = baseCtrl; ctrlId <= baseCtrl+numCtrls; ctrlId++ )
  {
    if( Button_GetCheck( GetDlgItem( parent, ctrlId ) ) == BST_CHECKED )
      break;
  }

  if( ctrlId > baseCtrl+numCtrls )
    ctrlId = baseCtrl;

   if( baseCtrl == IDC_FTEXTRED )
     style = (ctrlId - IDC_FTEXTRED + 1) << FBS_FTEXTSHIFT;
   else
     style = (ctrlId - IDC_BTEXTRED + 1) << FBS_BTEXTSHIFT;

   return style;
}

// ----------------------------------------------------------------------------
//
//   Foo Button Custom Control Implementation:
//
// ----------------------------------------------------------------------------
//
//   Window procedure and message handlers.
//
// ----------------------------------------------------------------------------

LRESULT CALLBACK __export
FooButtonWndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
  switch( msg )
  {
    HANDLE_MSG( hwnd, WM_CREATE, EvFooBtnCreate );
    HANDLE_MSG( hwnd, WM_DESTROY, EvFooBtnDestroy );
    HANDLE_MSG( hwnd, WM_LBUTTONDOWN, EvFooBtnLButtonDown );
    HANDLE_MSG( hwnd, WM_LBUTTONUP, EvFooBtnLButtonUp );
    HANDLE_MSG( hwnd, WM_MOUSEMOVE, EvFooBtnMouseMove );
    HANDLE_MSG( hwnd, WM_SETFOCUS, EvFooBtnSetFocus );
    HANDLE_MSG( hwnd, WM_KILLFOCUS, EvFooBtnKillFocus );
    HANDLE_MSG( hwnd, WM_ERASEBKGND, EvFooBtnEraseBkgnd );
    HANDLE_MSG( hwnd, WM_PAINT, EvFooBtnPaint );
    HANDLE_MSG( hwnd, WM_SETFONT, EvFooBtnSetFont );
    HANDLE_MSG( hwnd, WM_GETFONT, EvFooBtnGetFont );
  }

  return DefWindowProc( hwnd, msg, wParam, lParam );
}

BOOL EvFooBtnCreate( HWND hwnd, LPCREATESTRUCT /*lpCreateStruct*/ )
{
  bool result = false;
  FooBtnData *fooData = (FooBtnData *) HeapAlloc( GetProcessHeap(), 0, sizeof( FooBtnData ) );

  if( fooData )
  {
    fooData->State = bsUp;
    fooData->Capture = false;
    fooData->Font = 0;

    SetWindowLong( hwnd, GWL_FOOBTNDATA, (LONG) fooData );
    result = true;
  }

  return result;
}

void EvFooBtnDestroy( HWND hwnd )
{
  FooBtnData *fooData = GetFooButtonData( hwnd );

  if( fooData )
  {
    HeapFree( GetProcessHeap(), 0, fooData );
    SetWindowLong( hwnd, GWL_FOOBTNDATA, 0L );
  }
}

void EvFooBtnLButtonDown( HWND hwnd, BOOL /*fDoubleClick*/, int /*x*/, int /*y*/, UINT /*keyFlags*/ )
{
  FooBtnData *fooData = GetFooButtonData( hwnd );

  if( fooData )
  {
    if( fooData->State == bsUp )
    {
      fooData->State = bsFocused;
      SetFocus( hwnd );
    }

    if( !fooData->Capture )
    {
      SetCapture( hwnd );
      fooData->Capture = true;
      fooData->State = bsDown;
      InvalidateRect( hwnd, 0, FALSE );
    }
  }
}

void EvFooBtnLButtonUp( HWND hwnd, int /*x*/, int /*y*/, UINT /*keyFlags*/ )
{
  FooBtnData *fooData = GetFooButtonData( hwnd );

  if( fooData && fooData->Capture )
  {
    fooData->Capture = false;
    fooData->State = bsFocused;
    ReleaseCapture();
    InvalidateRect( hwnd, 0, FALSE );

    // Generate <Click> event here.
  }
}

void EvFooBtnMouseMove( HWND hwnd, int x, int y, UINT /*keyFlags*/ )
{
  FooBtnData *fooData = GetFooButtonData( hwnd );

  if( fooData && fooData->Capture )
  {
    TRect rect;
    TPoint p( x, y );
    ButtonState oldState;

    GetClientRect( hwnd, &rect );

    oldState = fooData->State;

    if( rect.Contains( p ) )
      fooData->State = bsDown;
    else
      fooData->State = bsFocused;

    if( oldState != fooData->State )
      InvalidateRect( hwnd, 0, FALSE );
  }
}

void EvFooBtnSetFocus( HWND hwnd, HWND /*hwndOldFocus*/ )
{
  FooBtnData *fooData = GetFooButtonData( hwnd );

  if( fooData && fooData->State != bsFocused )
  {
    fooData->State = bsFocused;
    InvalidateRect( hwnd, 0, FALSE );
  }
}

void EvFooBtnKillFocus( HWND hwnd, HWND /*hwndOldFocus*/ )
{
  FooBtnData *fooData = GetFooButtonData( hwnd );

  if( fooData && fooData->State != bsUp )
  {
    fooData->State = bsUp;
    InvalidateRect( hwnd, 0, FALSE );
  }
}

BOOL EvFooBtnEraseBkgnd( HWND /*hwnd*/, HDC /*hdc*/ )
{
  return TRUE;
}

void EvFooBtnPaint( HWND hwnd )
{
  FooBtnData *fooData = GetFooButtonData( hwnd );

  if( fooData )
  {
    TRect fr, r, cr;
    HBITMAP bitmap;
    HPEN blackPen, whitePen, dkGrayPen, ltGrayPen, dkGrayDashPen;
    HBRUSH nullBrush, ltGrayBrush;
    HDC hdc, memdc;
    PAINTSTRUCT ps;
    int save;

    GetClientRect( hwnd, &cr );
    r = fr = cr;

    nullBrush = GetStockBrush( NULL_BRUSH );
    ltGrayBrush = GetStockBrush( LTGRAY_BRUSH );

    blackPen = GetStockPen( BLACK_PEN );
    whitePen = GetStockPen( WHITE_PEN );
    dkGrayPen = CreatePen( PS_SOLID, 1, DkGray );
    ltGrayPen = CreatePen( PS_SOLID, 1, LtGray );
    dkGrayDashPen = CreatePen( PS_DOT, 1, DkGray );

    hdc = BeginPaint( hwnd, &ps );
    memdc = CreateCompatibleDC( hdc );
    bitmap = CreateCompatibleBitmap( hdc, cr.right, cr.bottom );

    save = SaveDC( memdc );

    SelectBitmap( memdc, bitmap );
    SelectPen( memdc, blackPen );
    SelectBrush( memdc, nullBrush );

    Rectangle( memdc, r.left, r.top, r.right, r.bottom );
    r.Inflate( -1, -1 );

    if( fooData->State != bsDown )
    {
      SelectPen( memdc, whitePen );
      MoveToEx( memdc, r.left, r.bottom-2, 0 );
      LineTo( memdc, r.left, r.top );
      LineTo( memdc, r.right-1, r.top );
      MoveToEx( memdc, r.right-3, r.top+1, 0 );
      LineTo( memdc, r.left+1, r.top+1 );
      LineTo( memdc, r.left+1, r.bottom-2 );

      SelectPen( memdc, dkGrayPen );
      MoveToEx( memdc, r.left, r.bottom-1, 0 );
      LineTo( memdc, r.right-1, r.bottom-1 );
      LineTo( memdc, r.right-1, r.top-1 );
      MoveToEx( memdc, r.right-2, r.top+1, 0 );
      LineTo( memdc, r.right-2, r.bottom-2 );
      LineTo( memdc, r.left, r.bottom-2 );

      r.Inflate( -2, -2 );
    }
    else
    {
      SelectPen( memdc, dkGrayPen );
      MoveToEx( memdc, r.left, r.bottom-1, 0 );
      LineTo( memdc, r.left, r.top );
      LineTo( memdc, r.right, r.top );

      r.left++;
      r.top++;
    }

    SelectBrush( memdc, ltGrayBrush );
    PatBlt( memdc, r.left, r.top, r.Width(), r.Height(), PATCOPY );

    if( fooData->State != bsDown )
    {
      fr.left += 4;
      fr.top += 4;
      fr.right -= 6;
      fr.bottom -= 6;
    }
    else
    {
      fr.left += 6;
      fr.top += 6;
      fr.right -= 4;
      fr.bottom -= 4;
    }

    {
      TRect tr;
      char caption[64];
      int len;

      if( fooData->Font )
        SelectFont( memdc, fooData->Font );

      len  = GetWindowText( hwnd, caption, sizeof( caption )-1 );
      caption[len] = 0;

      unsigned long style = GetWindowLong( hwnd, GWL_STYLE );
      if( style & WS_DISABLED )
      {
        SetTextColor( memdc, DkGray );
        SetBkColor( memdc, LtGray );
      }
      else
      {
        SetTextColor( memdc, Colors[ ((style & FBS_FTEXTMASK) >> FBS_FTEXTSHIFT) - 1 ] );

        COLORREF bkcolor = Colors[ ((style & FBS_BTEXTMASK) >> FBS_BTEXTSHIFT) - 1 ];
        SetBkColor( memdc, bkcolor );

        HBRUSH bkbrush = CreateSolidBrush( bkcolor );
        SelectBrush( memdc, bkbrush );
        PatBlt( memdc, r.left, r.top, r.Width(), r.Height(), PATCOPY );
        SelectBrush( memdc, nullBrush );
        DeleteObject( bkbrush );
      }

      tr.SetNull();
      DrawText( memdc, caption, -1, &tr, DT_CALCRECT | DT_SINGLELINE );

      if( tr.Width() < fr.Width() )
      {
        fr.left += (fr.Width() - tr.Width()) / 2;
        fr.right = fr.left + tr.Width();
      }

      if( tr.Height() < fr.Height() )
      {
        fr.top += (fr.Height() - tr.Height()) / 2;
        fr.bottom = fr.top + tr.Height();
      }

      DrawText( memdc, caption, -1, &fr, DT_CENTER | DT_SINGLELINE | DT_VCENTER );

      fr.Inflate( 2, 2 );

      if( fooData->State != bsUp )
      {
        SelectBrush( memdc, nullBrush );
        SelectPen( memdc, dkGrayDashPen );
        Rectangle( memdc, fr.left, fr.top, fr.right, fr.bottom );
      }
    }

    BitBlt( hdc, 0, 0, cr.right, cr.bottom, memdc, 0, 0, SRCCOPY );

    RestoreDC( memdc, save );

    DeletePen( dkGrayPen );
    DeletePen( ltGrayPen );
    DeletePen( dkGrayDashPen );
    DeleteBitmap( bitmap );

    DeleteDC( memdc );
    EndPaint( hwnd, &ps );
  }
}

void EvFooBtnSetFont( HWND hwnd, HFONT hfont, BOOL fRedraw )
{
  FooBtnData *fooData = GetFooButtonData( hwnd );

  if( fooData )
  {
    fooData->Font = hfont;
    if( fRedraw )
      InvalidateRect( hwnd, 0, FALSE );
  }
}

HFONT EvFooBtnGetFont( HWND hwnd )
{
  FooBtnData *fooData = GetFooButtonData( hwnd );
  HFONT result = 0;

  if( fooData )
    result = fooData->Font;

  return result;
}
