
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

class BOleHatchWindow {

public:

	static Register (HINSTANCE hInst);
	static BOleHatchWindow* Create (HWND hWndParent, HINSTANCE hInst, BOleSite *pBack);

	void SetSize (LPRECT lprcIPObjRect, LPRECT lprcClipRect, LPPOINT lpptOffset);
	~BOleHatchWindow();

	void Paint ();
	static void InitWidth ();
	UINT HitTestHandles (LPPOINT);
	void SetHandleCursor (UINT);
	void Show (BOOL, LPOLEINPLACESITE pS = NULL);
	void NegotiateSize (WINDOWPOS*);
 	UINT GetWidth ();
	
	operator HWND () {return hWndHatch;}

protected:

	HWND hWndHatch;
	RECT hatchRect;
	static UINT hatchWidth;
	LPOLEINPLACESITE pSite;
	BOleSite *pBack;
	
	BOleHatchWindow (BOleSite *pB);

	void GetHatchRect (LPRECT lpHatchRect);
	void SetHatchRect (LPRECT lpHatchRect);

	void SetRectExt (RECT FAR *, UINT, UINT, UINT);
};

#endif
