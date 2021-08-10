//
//**************************************************************************
// 
// BHatch.cpp -- An implementation of the hatched border around inplace
//               active windows.
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#ifndef HATCH_H
#define HATCH_H

#include "BOleSite.h"

#define CLIPPED				0x0001
#define CLIPPED_LEFT 		0x0002
#define CLIPPED_TOP        0x0004
#define CLIPPED_TOPLEFT    CLIPPED_LEFT|CLIPPED_TOP

void SetRectExt (RECT FAR *,UINT,UINT,UINT);

class BOleHatchWindow {

public:

	BOleHatchWindow (HWND,HINSTANCE,BOleSite*);
	~BOleHatchWindow();

	static 					Register (HINSTANCE hInst); // register window
	static void 			InitWidth ();

	// window messages related member functions
#ifdef ANSI
	LRESULT 					wmCreate (LPCREATESTRUCTA);
#else
	LRESULT 					wmCreate (LPCREATESTRUCT);
#endif
	LRESULT 					wmPaint ();
	UINT 						wmNCHitTest (LPPOINT);
	LRESULT 					wmSetCursor (HWND, UINT, UINT);
	UINT 						wmMouseActivate (HWND, UINT, UINT);
	LRESULT 					wmNCLButtonDown (UINT, LPPOINT);
	LRESULT 					wmGetMinMaxInfo (MINMAXINFO*);
	LRESULT 					wmWindowPosChanging (LPWINDOWPOS);

	void 						Show (BOOL, LPOLEINPLACESITE = NULL);
	void 						SetSize (LPRECT,LPRECT,LPPOINT);
	void 						NegotiateSize (WINDOWPOS*);
	UINT 						GetWidth ();

	operator 				HWND () {return hWndHatch;}

protected:

	static UINT 			hatchWidth; // hatch border size

	HWND 						hWndHatch; // hatch window handle
	RECT 						hatchRect; // keep server window rectangle in client coordinates

	int 						nClippedFlag; // clipped status flag
	RECT 						MoveRect; // temp rect used only inside WM_WINDOWPOSCHANGING (orrible!)
	BOOL 						fInMouseDown; // used to signal when mouse left button is kept down

	LPOLEINPLACESITE 		pSite;
	BOleSite *				pBack;

};

#endif

