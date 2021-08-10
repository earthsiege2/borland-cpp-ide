
//**************************************************************************
//
// BOleDoc.h -- Declares the document-level helper object for containers
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#ifndef _BOLEDOC_H
#define _BOLEDOC_H 1

#include "BOleComp.h"
#include "BOlePart.h"

class _ICLASS BOleService;


class _ICLASS BOleDocument : public BOleComponent, public IBDocument,
	public IDropTarget, public IOleUILinkContainer,	public IOleInPlaceFrame,
	public IBOverrideBrowseLinks
{
public:
	static CLIPFORMAT oleEmbdObjClipFmt;
	static CLIPFORMAT oleEmbSrcClipFmt;
	static CLIPFORMAT oleLinkSrcClipFmt;
							
	static CLIPFORMAT oleLinkClipFmt;
	static CLIPFORMAT oleNativeClipFmt;
	static CLIPFORMAT oleOwnerLinkClipFmt;
	static CLIPFORMAT	oleObjectDescFmt;
	static CLIPFORMAT	oleLinkSrcDescFmt;

	static UINT dragScrollInset;
	static UINT dragScrollDelay;
	static UINT dragScrollInterval;

protected:

	friend BOlePart;
	friend BOleService;

	IBContainer    * pContainer;
	IBApplication  * pApplication;
	BOleService    * pService;

	IOleInPlaceActiveObject	
						* pActivePart;	// For keeping object's active state in sync with window's

	BOlePart 		* pFirstPart;	// For enumerating objects

	// For drawing XOR'ed outline rect during drag/drop
	//
	RECT     dndObjPos;		 
	SIZE     dndSize;
	POINT    dndLastPos;  
	BOOL     dndInfoAvailable;
	POINT    dndOffset;
	PIBDropDest pDropDest;
	BOOL fDrawn;

	BOOL dndLastFeedbackFailed; // so we know what to do when mouse doesn't move

	// For scrolling during drag/drop
	//
	RECT rcScrollTop, rcScrollLeft, rcScrollRight, rcScrollBottom;
	DWORD scrollEnterTime;
	DWORD scrollLastTime;
	BOOL fScrollDelay;
	
	// For format negotiation during drag/drop
	//
	OLEUIPASTEENTRY *dndFormatList;
	UINT dndFormatCount;
	UINT dndFormat;
	BOOL fCantLink;

	// For registering drag/drop
	BOOL fRegistered;
	
	// To prevent BrowseLinks from being re-entrant
	BOOL fInBrowseLinks;
	
	// Private implementation functions 
	//
	short _IFUNC ValidateDrag(DWORD keyState, POINTL *where, DWORD *effect, IDataObject *dataObj = NULL);
	BOleScroll _IFUNC DragScrollReqd (POINTL *where);
	void _IFUNC CacheDragRects (LPRECT);
	void _IFUNC CalculateDndObjPos ();

public:
	BOleDocument (BOleClassManager *, IBUnknownMain *, BOleService *);
	~BOleDocument ();

	IBContainer *GetContainer () { return pContainer; }

	BOlePart *GetFirstPart () { return pFirstPart; }
	void      SetFirstPart (BOlePart*pPart) { pFirstPart = pPart; }
	void     OnRemovePart (BOlePart *pPart);
	BOOL _IFUNC EnableBrowseLinks();

	HRESULT		OnModalDialog (BOOL);
	HRESULT		TranslateAccel (LPMSG);

	// IDocument functions 
	//
	virtual HRESULT _IFUNC Init(PIBContainer);
	virtual void _IFUNC OnResize ();
	virtual void _IFUNC OnActivate (BOOL fActivate);
	virtual void _IFUNC OnClose ();
	virtual HRESULT _IFUNC OnSetFocus(BOOL);
	virtual HRESULT _IFUNC EnumLinks (PIBLinkInfo FAR*);
	virtual HRESULT _IFUNC BrowseLinks ();
	virtual HRESULT _IFUNC UpdateLinks ();

public:
	
	// IUnknown Methods
	//								delegate aggregator's IUnknownMain
	DEFINE_IUNKNOWN(pObjOuter)
	
	// IUnknownMain methods
	//								
	virtual HRESULT _IFUNC QueryInterfaceMain(REFIID iid, LPVOID FAR* pif);

private:

	// IOleWindow methods, base of IOleInPlaceUIWindow and IOleInPlaceSite
	//
	HRESULT _IFUNC GetWindow(HWND FAR* lphwnd);
	HRESULT _IFUNC ContextSensitiveHelp(BOOL fEnterMode);

	// IOleInPlaceUIWindow methods
	//
	HRESULT _IFUNC GetBorder(LPRECT lprectBorder);
	HRESULT _IFUNC RequestBorderSpace(LPCRECT lprectWidths);
	HRESULT _IFUNC SetBorderSpace(LPCBORDERWIDTHS lpborderwidths);
	HRESULT _IFUNC SetActiveObject(IOleInPlaceActiveObject* lpActiveObject,
	                    LPCOLESTR lpszObjName); 

	// IDropTarget functions
	//
	HRESULT _IFUNC DragEnter(IDataObject *dataObj, DWORD keyState, POINTL where, LPDWORD effect);
	HRESULT _IFUNC DragOver(DWORD keyState, POINTL where, LPDWORD effect);
	HRESULT _IFUNC DragLeave();
	HRESULT _IFUNC Drop(IDataObject *dataObj, DWORD keyState, POINTL where, LPDWORD effect);

	// IOleUILinkContainer functions
	//
	DWORD _IFUNC GetNextLink (DWORD dwLink);
	HRESULT _IFUNC SetLinkUpdateOptions (DWORD dwLink, DWORD dwUpdateOpt);
	HRESULT _IFUNC GetLinkUpdateOptions (DWORD dwLink, DWORD FAR* lpdwUpdateOpt);
	HRESULT _IFUNC SetLinkSource(
		DWORD       dwLink,
		LPOLESTR    lpszDisplayName,
		ULONG       lenFileName,
		ULONG FAR*  pchEaten,
		BOOL        fValidateSource);
	HRESULT _IFUNC GetLinkSource(
		DWORD       dwLink,
		LPOLESTR FAR*  lplpszDisplayName,
		ULONG FAR*  lplenFileName,
		LPOLESTR FAR*  lplpszFullLinkType,
		LPOLESTR FAR*  lplpszShortLinkType, 
		BOOL FAR*   lpfSourceAvailable, 
		BOOL FAR*   lpfIsSelected);
	HRESULT _IFUNC OpenLinkSource (DWORD dwLink);
	HRESULT _IFUNC UpdateLink(DWORD dwLink, BOOL fErrorMessage,BOOL fErrorAction);
	HRESULT _IFUNC CancelLink (DWORD dwLink);

	// IOleInPlaceFrame methods
	//
	HRESULT _IFUNC InsertMenus(HMENU hmenuShared, LPOLEMENUGROUPWIDTHS lpMenuWidts);
	HRESULT _IFUNC SetMenu(HMENU hmenuShared, HOLEMENU holemenu, HWND hwndActiveObject);
	HRESULT _IFUNC RemoveMenus(HMENU hmenuShared);
	HRESULT _IFUNC SetStatusText(LPCOLESTR lpszStatusText);    
	HRESULT _IFUNC EnableModeless(BOOL fEnable);
	HRESULT _IFUNC TranslateAccelerator(LPMSG lpmsg, WORD wID);
};

#endif _BOLEDOC_H

