
//**************************************************************************
// 
// BOleCMan.h --   Declares an IBClassMgr "factory" which can create Bolero
//                 helper objects. 
//
//                 Since callers of BOleClassManager don't have the class 
//                 definition, they can't call operator new to create a
//                 helper object.
//
//                 BOleClassMgr has a pointer to the service, so you need a
//                 BOleClassMgr for every Bolero connection you maintain.
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#ifndef BOLECMAN_H
#define BOLECMAN_H

#include "BOleComp.h"
#include "BOleSvc.h"

class BOleClassManager : public BOleComponent, public IBClassMgr
{

private:
	BOleService *pSvc;
	int nServerCount;

public:

	// IUnknown methods
	//
	DEFINE_IUNKNOWN(pObjOuter);
	virtual HRESULT _IFUNC QueryInterfaceMain(REFIID iid, LPVOID FAR* pif);

	// IClassMgr methods
	//
	virtual HRESULT _IFUNC ComponentCreate(
		PIUnknown FAR* ppRet,
		PIUnknown pAggregator,
		BCID		idClass
		);
	virtual HRESULT _IFUNC ComponentInfoGet(
		PIUnknown FAR* ppInfo,
		PIUnknown pAggregator,
		BCID		idClass
		)
	{ *ppInfo = NULLP; return ResultFromScode(E_NOTIMPL); }

	int _IFUNC ServerCount (int nDelta = 0);
	BOleService * GetService()	{return pSvc;}
	
	BOleClassManager(IBUnknownMain *pObj);
	~BOleClassManager();
};

#endif
