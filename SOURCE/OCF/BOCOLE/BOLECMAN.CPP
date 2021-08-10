//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.10  $
//
//  Declares an IBClassMgr "factory" which can create Bolero helper objects.
//
//    Since callers of BOleClassManager don't have the class
//    definition, they can't call operator new to create a
//    helper object.
//
//    BOleClassMgr has a pointer to the service, so you need a
//    BOleClassMgr for every Bolero connection you maintain.
//----------------------------------------------------------------------------
#include "BOleCMan.h"
#include "BOleSvc.h"
#include "BOleDoc.h"
#include "BOleIPS.h"
#include "BOleSite.h"
#include "BOleCtrl.h"
#include "BOleFont.h"
#include "BOlePict.h"
#include "BOleCont.h"
#include "BOleData.h"
#include "BOleFact.h"
#include "BOcxCtrl.h"

HRESULT _IFUNC BOleClassManager::QueryInterfaceMain(REFIID iid, LPVOID FAR *ppv)
{
	HRESULT hr = ResultFromScode(E_NOINTERFACE);
	*ppv = NULL;
	
	// interfaces
	SUCCEEDED(hr = IBClassMgr_QueryInterface(this, iid, ppv))

	// base classes	
	|| SUCCEEDED(hr = BOleComponent::QueryInterfaceMain(iid, ppv))

	// helpers
	;
		
	return hr;
}


BOleClassManager::BOleClassManager(IBUnknownMain *pObj) :
	pSvc (NULLP), pFont (NULLP), BOleComponent(this, pObj)
{
	nServerCount = 0;
}


BOleClassManager::~BOleClassManager()
{
	if (pSvc != NULLP) {
		pSvc->ReleaseMain();
		pSvc = NULLP;
	}

	if (pFont != NULLP) {
		pFont->ReleaseMain();
		pFont = NULLP;
	}

	OLE::OleUninitialize (); // Req'd to free OLE2's clipboard window
}

int _IFUNC BOleClassManager::ServerCount (int nDelta)
{
	nServerCount += nDelta;
	if (nServerCount == 0) {
		if (pSvc && (nDelta != 0))
			// call ShutdownMaybe on TRANSITION to 0
			(pSvc->GetApplication())->ShutdownMaybe();
	}
	return nServerCount;
}

HRESULT _IFUNC BOleClassManager::ComponentCreate( PIUnknown FAR * ppObj, PIUnknown pO, BCID cid)
{
	*ppObj = NULL;
	PIBUnknownMain pOuter = AsPIUnknownMain(pO);
	
	switch (cid) {
		case cidBOleService:
			{
				if (pSvc != NULLP)
					pSvc->ReleaseMain();	// ref count on helper (not aggregator)
				pSvc = new BOleService(this, pOuter);
				*ppObj = AsPIUnknown(pSvc);
				if (pSvc != NULLP)
					pSvc->AddRefMain();
				break;
			}
		case cidBOleDocument:
			{
				if (pSvc != NULLP)
					*ppObj = AsPIUnknown(new BOleDocument(this, pOuter, pSvc));
				break;
			}
		case cidBOleContainer:
			{
				*ppObj = AsPIUnknown(new BOleContainer(this, pOuter));
				break;
			}
		case cidBOlePart:
			{
				if (pSvc != NULLP)
					*ppObj = AsPIUnknown(new BOlePart(this, pOuter, pSvc->pActiveDoc));
				break;
			}
		case cidBOleControl:
			{
				if (pSvc != NULLP)
					*ppObj = AsPIUnknown(new BOleControl(this, pOuter, pSvc->pActiveDoc));
				break;
			}
		case cidBOleSite:
			{
				*ppObj = AsPIUnknown(new BOleSite(this, pOuter, pSvc));
				break;
			}
		case cidBOleInProcSite:
			{
				*ppObj = AsPIUnknown(new BOleInProcServer(this, pOuter, pSvc));
				break;
			}
		case cidBOleInProcHandler:
			{
				*ppObj = AsPIUnknown(new BOleInProcHandler(this, pOuter, pSvc));
				break;
			}

		case cidBOleControlSite:
			{
				*ppObj = AsPIUnknown(new BOleControlSite(this, pOuter));
				break;
			}
		case cidBOleData:
			*ppObj = AsPIUnknown (new BOleData(this, pOuter));
			break;

		case cidBOleFactory:
			// not aggregated directly by clients
			// we create one on the clients behalf in IService::RegisterClass
			// and release it in IService::UnregisterClass
			{
				*ppObj = AsPIUnknown (new BOleFact(this, pOuter));
				break;
			}
		case cidBOleControlFactory:
			// not aggregated directly by clients
			// we create one on the clients behalf in IService::RegisterControlClass
			// and release it in IService::UnregisterControlClass
			{
				*ppObj = AsPIUnknown (new BOleControlFact(this, pOuter));
				break;
			}
		case cidBOleFont:
			{
   			*ppObj = AsPIUnknown(new BOleFont (this, pOuter));
				break;
			}
		case cidBOlePicture:
			{
   			*ppObj = AsPIUnknown(new BOlePicture (this, pOuter));
				break;
			}
	}
	return (*ppObj) ? NOERROR : ResultFromScode (E_FAIL);
}


void BOleClassManager::SetFontCache(BOleFontObj *pFontObj)
{
  if (!pFontObj || (pFontObj == pFont)) {
    if (pFont) {
      pFont = pFont->GetNext ();
      if (pFont)
        pFont->SetPrev (NULL);
    }
  } else if (pFontObj) {
    if (pFont) 
      pFont->SetPrev (pFontObj);
    pFontObj->SetNext (pFont);
    pFontObj->SetPrev (NULL);
    pFont = pFontObj;
  }
}



// CreateClassMgr -- This is the way to initiate a connection with Bolero.
//                   To help us be version-resilient, it's the only exported
//                   function which is visible to Bolero customers
//
extern "C"

HRESULT PASCAL FAR _export _loadds CreateClassMgr (
	PIUnknown FAR *pCM,
	PIUnknown pOuter,
	IMalloc FAR *pMalloc)
{
	OLE::OleInitialize(pMalloc);
	*pCM = new BOleClassManager (AsPIUnknownMain(pOuter));
	return (*pCM) ?NOERROR:ResultFromScode(E_OUTOFMEMORY);
}
