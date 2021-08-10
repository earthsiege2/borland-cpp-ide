
//**************************************************************************
//
// Bhatch.cpp - An implementation of the hatched border around inplace
//              active windows. 
//
// Modifications to OLE2UI version:
//		- C++ version
//		- removed restriction that parent must be non-null in CreateHatchWindow
//		- changed window from a child to a popup to allow null parent
//		- "extra bytes" removed in favor of member data
//		- added Paint() and InitWidth() to unclutter wnd proc
//		- added hit testing and correct cursors for handles
//		- added resizing for handles
//		- added NegotiateSize() to mediate inplace size negotiations between
//		  the container and the server
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#include "BOle.h"

// #define STRICT  1
#define STRICT
#include "OLE2UI.h"
#include "BHatch.h"

// class name of hatch window
#define CLASS_HATCH OLESTR("BOle Hatch Window")

// local function prototypes
LRESULT FAR PASCAL EXPORT BOleHatchWndProc (HWND, UINT, WPARAM, LPARAM);

// static initializer
UINT BOleHatchWindow::hatchWidth = 0;

/***************************************************************************
 * BOleHatchWindow::BOleHatchWindow
 *
 * Purpose:
 *		Protected constructor called only from static Create function
 *
 */
BOleHatchWindow::BOleHatchWindow (BOleSite *p)
{
	pBack = p;
	hWndHatch = NULL;
	hatchRect.left = hatchRect.top = hatchRect.bottom = hatchRect.right = 0;
	pSite = NULL;
}

/***************************************************************************
 * BOleHatchWindow::~BOleHatchWindow
 *
 * Purpose:
 *		Public destructor to destroy the hWnd
 *
 */
BOleHatchWindow::~BOleHatchWindow ()
{
	if (hWndHatch)
		::DestroyWindow (hWndHatch);
}

/***************************************************************************
 * BOleHatchWindow::Register
 *
 * Purpose:
 *  Register the hatch window
 *
 * Parameters:
 *  hInst           Process instance
 *
 * Return Value:
 *  TRUE            if successful
 *  FALSE           if failed
 *
 */
BOOL BOleHatchWindow::Register (HINSTANCE hInst)
{
	WNDCLASS wc;

	// Register Hatch Window Class
	wc.style = CS_BYTEALIGNWINDOW;
	wc.lpfnWndProc = BOleHatchWndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = sizeof(BOleHatchWindow*);    // 'this' in extra bytes
	wc.hInstance = hInst;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = CLASS_HATCH;

	if (!::RegisterClass(&wc))
		return FALSE;
	else
		return TRUE;
}


/***************************************************************************
 * BOleHatchWindow::Create
 *
 * Purpose:
 *  Create a hatch window
 *
 * Parameters:
 *  hWndParent          parent of hatch window
 *  hInst               instance handle
 *
 * Return Value:
 *  pointer to hatch window         if successful
 *  NULL                            if failed
 *
 */
BOleHatchWindow* BOleHatchWindow::Create (HWND hWndParent, HINSTANCE hInst, BOleSite *pBack)
{
	if (!hInst)
		return NULL;

	BOleHatchWindow *pHW = new BOleHatchWindow (pBack);
	if (!pHW)
		return NULL;

	pHW->hWndHatch = ::CreateWindow(
		CLASS_HATCH,	// Class name
		OLESTR("Hatch Window"), // Window name
		WS_CHILDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		0, 0, 0, 0,
		GetDesktopWindow(),
		(HMENU)NULL,
		hInst,
		0L
	);
	if (!pHW->hWndHatch)
		return NULL;

	::SetWindowLong (pHW->hWndHatch, 0, (long) pHW);

	return pHW;
}

/***************************************************************************
 *  BOleHatchWindow::GetWidth
 *
 *  Purpose:
 *      Get width of hatch border
 *
 *  Parameters:
 *			None
 *
 *  Return Value:
 *      width of the hatch border
 */
UINT BOleHatchWindow::GetWidth ()
{
	if (!::IsWindow(hWndHatch))
		return 0;

	return hatchWidth;
}

/***************************************************************************
 *  BOleHatchWindow::GetHatchRect
 *
 *  Purpose:
 *      Get hatch rect. this is the size of the hatch window if it were
 *      not clipped by the ClipRect.
 *
 *  Parameters:
 *      lprcHatchRect   hatch rect
 *
 *  Return Value:
 *      none
 */
void BOleHatchWindow::GetHatchRect(LPRECT lprcHatchRect)
{
	if (!::IsWindow(hWndHatch)) {
		::SetRect(lprcHatchRect, 0, 0, 0, 0);
		return;
	}

	*lprcHatchRect = hatchRect;
}


/***************************************************************************
 *	 BOleHatchWindow::SetHatchRect
 *
 *  Purpose:
 *      Store hatch rect with HatchRect window.
 *      this rect is the size of the hatch window if it were
 *      not clipped by the ClipRect.
 *
 *  Parameters:
 *      lprcHatchRect   hatch rect
 *
 *  Return Value:
 *      none
 */
void BOleHatchWindow::SetHatchRect(LPRECT lprcHatchRect)
{
	if (!::IsWindow(hWndHatch))
		return;

	hatchRect = *lprcHatchRect;
}


/***************************************************************************
 *	 BOleHatchWindow::SetSize
 *
 *  Purpose:
 *      Move/size the HatchWindow correctly given the rect required by the
 *      in-place server object window and the lprcClipRect imposed by the
 *      in-place container. both rect's are expressed in the client coord.
 *      of the in-place container's window (which is the parent of the
 *      HatchWindow).
 *
 *      OLE2NOTE: the in-place server must honor the lprcClipRect specified
 *      by its in-place container. it must NOT draw outside of the ClipRect.
 *      in order to achieve this, the hatch window is sized to be
 *      exactly the size that should be visible (rcVisRect). the
 *      rcVisRect is defined as the intersection of the full size of
 *      the HatchRect window and the lprcClipRect.
 *      the ClipRect could infact clip the HatchRect on the
 *      right/bottom and/or on the top/left. if it is clipped on the
 *      right/bottom then it is sufficient to simply resize the hatch
 *      window. but if the HatchRect is clipped on the top/left then
 *      in-place server document window (child of HatchWindow) must be moved
 *      by the delta that was clipped. the window origin of the
 *      in-place server window will then have negative coordinates relative
 *      to its parent HatchWindow.
 *
 *  Parameters:
 *      lprcIPObjRect   full size of in-place server object window
 *      lprcClipRect    clipping rect imposed by in-place container
 *      lpptOffset      offset required to position in-place server object
 *                      window properly. caller should call:
 *                          OffsetRect(&rcObjRect,lpptOffset->x,lpptOffset->y)
 *
 *  Return Value:
 */
void BOleHatchWindow::SetSize(
		LPRECT      lprcIPObjRect,
		LPRECT      lprcClipRect,
		LPPOINT     lpptOffset)
{

	RECT        rcHatchRect;
	RECT        rcVisRect;
	UINT        uHatchWidth;
	POINT       ptOffset;

	if (!::IsWindow(hWndHatch))
		return;

	rcHatchRect = *lprcIPObjRect;
	uHatchWidth = GetWidth();
	::InflateRect((LPRECT)&rcHatchRect, uHatchWidth + 1, uHatchWidth + 1);

	::IntersectRect (&rcVisRect, &rcHatchRect, lprcClipRect);
	::MoveWindow(
			hWndHatch,
			rcVisRect.left,
			rcVisRect.top,
			rcVisRect.right-rcVisRect.left,
			rcVisRect.bottom-rcVisRect.top,
			TRUE    /* fRepaint */
	);
	::InvalidateRect(hWndHatch, NULL, TRUE);

	ptOffset.x = -rcHatchRect.left + (rcHatchRect.left - rcVisRect.left);
	ptOffset.y = -rcHatchRect.top + (rcHatchRect.top - rcVisRect.top);

	/* convert the rcHatchRect into the client coordinate system of the
	**    HatchWindow itself
	*/
	::OffsetRect(&rcHatchRect, ptOffset.x, ptOffset.y);

	SetHatchRect(&rcHatchRect);

	// calculate offset required to position in-place server doc window
	lpptOffset->x = ptOffset.x;
	lpptOffset->y = ptOffset.y;
	
	return;
}

/***************************************************************************
 * BOleHatchWindow::Paint
 *
 * Purpose:
 *		Draw hatched border and handles
 *
 */
void BOleHatchWindow::Paint ()
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rcHatchRect;

	hDC = ::BeginPaint(hWndHatch, &ps);
	GetHatchRect(&rcHatchRect);
	OleUIDrawShading(&rcHatchRect, hDC, OLEUI_SHADE_BORDERIN,
			hatchWidth);
	::InflateRect ((LPRECT)&rcHatchRect, -hatchWidth, -hatchWidth);
	OleUIDrawHandles (&rcHatchRect, hDC, OLEUI_HANDLES_OUTSIDE,
		hatchWidth+1, TRUE);

	::EndPaint (hWndHatch, &ps);
}

/***************************************************************************
 * BOleHatchWindow::InitWidth
 *
 * Purpose:
 *		Initialize hatch border with from WIN.INI
 *
 */
void BOleHatchWindow::InitWidth ()
{
	hatchWidth = GetProfileInt(
		OLESTR("windows"),
		OLESTR("oleinplaceborderwidth"),
		DEFAULT_HATCHBORDER_WIDTH
	);
}

void BOleHatchWindow::SetRectExt (LPRECT r, UINT x, UINT y, UINT extent)
{
	r->left = x;
	r->top = y;
	r->right = x + extent;
	r->bottom = y + extent;
}

/***************************************************************************
 * BOleHatchWindow::HitTestHandles
 *
 * Purpose:
 *		Find out which handle the cursor is over
 *
 */
UINT BOleHatchWindow::HitTestHandles (LPPOINT where)
{
	RECT rc = hatchRect;
	RECT handleRect;

	SetRectExt (&handleRect, rc.left, rc.top, hatchWidth + 1);
	if (::PtInRect(&handleRect, *where)) 	return HTTOPLEFT;

	SetRectExt (&handleRect, rc.left, rc.top+(rc.bottom-rc.top-hatchWidth + 1)/2, hatchWidth + 1);
	if (::PtInRect(&handleRect, *where))	return HTLEFT;

	SetRectExt (&handleRect, rc.left, rc.bottom - hatchWidth + 1, hatchWidth + 1);
	if (::PtInRect(&handleRect, *where))	return HTBOTTOMLEFT;

	SetRectExt (&handleRect, rc.left+(rc.right-rc.left-hatchWidth + 1)/2, rc.top, hatchWidth + 1);
	if (::PtInRect(&handleRect, *where))	return HTTOP;
	
	SetRectExt (&handleRect, rc.left+(rc.right-rc.left-hatchWidth + 1)/2, rc.bottom - hatchWidth + 1, hatchWidth + 1);
	if (::PtInRect(&handleRect, *where))	return HTBOTTOM;

	SetRectExt (&handleRect, rc.right-hatchWidth + 1, rc.top, hatchWidth + 1);
	if (::PtInRect(&handleRect, *where))	return HTTOPRIGHT;

	SetRectExt (&handleRect, rc.right-hatchWidth + 1, rc.top+(rc.bottom-rc.top-hatchWidth + 1)/2, hatchWidth + 1);
	if (::PtInRect(&handleRect, *where))	return HTRIGHT;

	SetRectExt (&handleRect, rc.right-hatchWidth + 1, rc.bottom-hatchWidth + 1, hatchWidth + 1);
	if (::PtInRect(&handleRect, *where))	return HTBOTTOMRIGHT;

	// If we've gotten this far, the cursor is not over a handle, but it
	// is over the hatch window (because we got the message). This means
	// the cursor is over the hatched border. It can't be over our client
	// area because the server object takes up the client area.
	//
	// So, by telling Windows that the cursor is over the caption bar, we
	// can piggy-back on Windows' code for dragging windows around.
	//
	return HTCAPTION;
}

/***************************************************************************
 * BOleHatchWindow::SetHandleCursor
 *
 * Purpose:
 *		Set the cursor bitmap to match the handle it's over.
 *
 */
void BOleHatchWindow::SetHandleCursor (UINT htCode)
{
	switch (htCode) {
		case HTTOPLEFT:
			::SetCursor (::LoadCursor (NULL, MAKEINTRESOURCE(IDC_SIZENWSE)));
			break;
		case HTLEFT:
			::SetCursor (::LoadCursor (NULL, MAKEINTRESOURCE(IDC_SIZEWE)));
			break;
		case HTBOTTOMLEFT:
			::SetCursor (::LoadCursor (NULL, MAKEINTRESOURCE(IDC_SIZENESW)));
			break;
		case HTTOP:
			::SetCursor (::LoadCursor (NULL, MAKEINTRESOURCE(IDC_SIZENS)));
			break;
		case HTBOTTOM:
			::SetCursor (::LoadCursor (NULL, MAKEINTRESOURCE(IDC_SIZENS)));
			break;
		case HTTOPRIGHT:
			::SetCursor (::LoadCursor (NULL, MAKEINTRESOURCE(IDC_SIZENESW)));
			break;
		case HTRIGHT:
			::SetCursor (::LoadCursor (NULL, MAKEINTRESOURCE(IDC_SIZEWE)));
			break;
		case HTBOTTOMRIGHT:
			::SetCursor (::LoadCursor (NULL, MAKEINTRESOURCE(IDC_SIZENWSE)));
			break;
		default:
			::SetCursor (::LoadCursor (NULL, MAKEINTRESOURCE(IDC_ARROW)));
			
	}
}

/***************************************************************************
 *  Show
 *
 *  Purpose:
 *		Show or hide the hatch window; provide access to the site
 *
 *  Parameters:
 *		fShow    TRUE to show the hatch window, FALSE to hide it
 *		pS       Pointer to the in place site, which is used to
 *		         negotiate new size when a handle is dragged
 *
 */
void BOleHatchWindow::Show (BOOL fShow, LPOLEINPLACESITE pS)
{
	pSite = pS;
	::ShowWindow (hWndHatch, fShow ? SW_SHOW : SW_HIDE);
}

/***************************************************************************
 * NegotiateSize
 *
 * Purpose:
 *		When the user drags a handle of the hatch window, Windows attempts
 *		to resize the window. This routine catches that attempt and validates
 *		it with the client. We don't need to validate it with the server
 *		because the client will call the server back from OnPosRectChange to
 *		BOleSite::SetObjectRects.
 *
 *	Parameters:
 *		pwp	Pointer to Windows' WINDOWPOS structure
 *
 */
void BOleHatchWindow::NegotiateSize (WINDOWPOS *pwp)
{
	RECT rcWnd; // The pre-resize size of the hatch window

	// As an optimization, get the current size of the hatch window
	// and bail out if it's the same as the new size. This saves the
	// potentially expensive renegotiation.
	//
	::GetWindowRect (hWndHatch, &rcWnd);
	HWND parent = ::GetParent (hWndHatch);
	::ScreenToClient (parent, (LPPOINT) &rcWnd.left);
	::ScreenToClient (parent, (LPPOINT) &rcWnd.right);
	if (rcWnd.left == pwp->x && rcWnd.top == pwp->y &&
		(rcWnd.bottom - rcWnd.top == pwp->cy) &&	
		(rcWnd.right - rcWnd.left == pwp->cx))
		return;


	// Ask the client to resize to the new size of the window
	//
	RECT rcNew;
	
	// The new size of the server's inplace window
	::SetRect (&rcNew, pwp->x, pwp->y, pwp->x + pwp->cx, pwp->y + pwp->cy);
	::InflateRect (&rcNew, -(hatchWidth + 1), -(hatchWidth + 1));
	if (pSite) {
		// Ask the server to show more/less of object
		//
		if (!SUCCEEDED(pBack->SetSiteRect(&rcNew))) {
			SIZE size;
			// undo resize of the server
			size.cx = rcWnd.right - rcWnd.left;
			size.cy = rcWnd.bottom - rcWnd.top;
			pBack->pPart->SetPartSize(&size);
				
			// If the client refuses the new size, give the pre-resize
			// size of the hatch window, back to Windows through the WINDOWPOS
			//
			pwp->x = rcWnd.left;
			pwp->y = rcWnd.top;
			pwp->cx = rcWnd.right - rcWnd.left;
			pwp->cy = rcWnd.bottom - rcWnd.top;
		}
	}
}

/***************************************************************************
 *  MyHatchWndProc
 *
 *  Purpose:
 *      WndProc for hatch window
 *
 *  Parameters:
 *      hWnd
 *      Message
 *      wParam
 *      lParam
 *
 *  Return Value:
 *      message dependent
 */
LRESULT FAR PASCAL EXPORT BOleHatchWndProc (HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	BOleHatchWindow *pHW  = (BOleHatchWindow*) ::GetWindowLong (hWnd, 0);
	static fInMouseDown = FALSE;

	switch (Message) {

		case WM_CREATE:
			BOleHatchWindow::InitWidth ();
			break;

		case WM_PAINT:
			if (pHW)
				pHW->Paint ();
			break;

		// The cursor setting strategy here is to catch the WM_NCHITTEST
		// first to figure out which hit-test area the cursor is over.
		// Then Windows calls us back with WM_SETCURSOR so we can make
		// the cursor the correct shape for that hit-test area.
		//
		case WM_NCHITTEST:
			if (pHW) {
				::ScreenToClient (*pHW, (LPPOINT) &lParam);
				return pHW->HitTestHandles ((LPPOINT) &lParam);
			}
			break;

		// Any window that is used during in-place activation
		// must handle the WM_SETCURSOR message or else the cursor
		// of the in-place parent will be used. if WM_SETCURSOR is
		// not handled, then DefWindowProc sends the message to the
		// window's parent.
		//
		case WM_SETCURSOR:
			if (pHW)
				pHW->SetHandleCursor (LOWORD(lParam));
			return (LRESULT)TRUE;

		case WM_MOUSEACTIVATE:
			return MA_NOACTIVATE;

		// The window move/resize strategy here is:
		// - Keep control so we can allow the OLE2 client app to refuse
		//   the new dimensions. Don't wait until the window has already
		//   been moved and then move it back.
		// - In order to keep control, we catch the WM_WINDOWPOSCHANGING
		//   and set appropriate flags in the WINDOWPOS struct.
		// - Since WM_WINDOWPOSCHANGING is sent for both user-interface
		//   initiated actions and for ::MoveWindow-initiated changes, we
		//   keep a flag which prevents changes during mousedowns
		//
		case WM_NCLBUTTONDOWN:
			fInMouseDown = TRUE;
			return ::DefWindowProc (hWnd, Message, wParam, lParam);

		case WM_GETMINMAXINFO:
			{
				MINMAXINFO *pMMI = (MINMAXINFO *) lParam;
				int minWidth = (pHW->GetWidth() * 2) + 15;
				pMMI->ptMinTrackSize.x = minWidth;
				pMMI->ptMinTrackSize.y = minWidth;
				return 0;
			}
		case WM_WINDOWPOSCHANGING:
			{
				WINDOWPOS *pWP = (WINDOWPOS*) lParam;
				if (fInMouseDown) {
					int minWidth = (pHW->GetWidth() * 2) + 15;
					if (pWP->cx < minWidth) {
						pWP->cx = minWidth;
					}
					if (pWP->cy < minWidth) {
						pWP->cy = minWidth;
					}
					fInMouseDown = FALSE;
					pHW->NegotiateSize (pWP);
					return 0;
				}
				return ::DefWindowProc (hWnd, Message, wParam, lParam);
			}
		default:
			return ::DefWindowProc (hWnd, Message, wParam, lParam);
	}

	return 0L;
}




