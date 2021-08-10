
//**************************************************************************
// 
// BOleComp.h --   Provides a default IUnknownMain implementation for all
//                 Bolero components (helper objects and some private
//                 objects).
//
//                 IUnknownMain is a way to create aggregatable components
//                 which support IUnknown-based interfaces via multiple-
//                 inheritance. 
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#ifndef BOLECOMP_H
#define BOLECOMP_H

#include "BOle.h"
#include "OleDebug.h"

class _ICLASS BOleClassManager;

PREDECLARE_INTERFACE( BOleComponent );

class _ICLASS BOleComponent : public IBUnknownMain 
#ifdef OLEDBG
, public cDebug
#endif
{
public:
	BOleClassManager * pFactory;		

private:
	unsigned long nReferences;

protected:
	IBUnknownMain * pObjOuter;		
	BOleComponent(BOleClassManager *pF, PIBUnknownMain pObj);
	virtual ~BOleComponent();

public:

	// IUnknown methods delegate aggregator's IUnknownMain
	//
	DEFINE_IUNKNOWN(pObjOuter);
	
	// IUnknownMain methods
	//
	virtual HRESULT _IFUNC QueryInterfaceMain(REFIID iid, LPVOID FAR* pif);
	virtual ULONG _IFUNC AddRefMain();
	virtual ULONG _IFUNC ReleaseMain();
};

#endif
