//
//**************************************************************************
// 
// BOleComp.cpp -- Provides a default IUnknownMain implementation for all
//                 Bolero components (helper objects and some private
//                 objects.
//
//                 IUnknownMain is a way to create aggregatable components
//                 which support IUnknown-based interfaces via multiple-
//                 inheritance. 
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#include "BOleComp.h"

ULONG _IFUNC BOleComponent::AddRefMain()
{
	return ++nReferences;
}

ULONG _IFUNC BOleComponent::ReleaseMain()
{
	return --nReferences ? nReferences : (delete this, 0);
}

HRESULT _IFUNC BOleComponent::QueryInterfaceMain(REFIID iid, LPVOID *ppv)
{
	*ppv = NULL;
	return  IBUnknownMain::QueryInterfaceMain(iid, ppv);
}

BOleComponent::BOleComponent(BOleClassManager *pF, IBUnknownMain *pO)
{
	pFactory = pF;
	if (pO)
		pObjOuter = pO;
	else
		pObjOuter = this;
	nReferences = 1;
}

BOleComponent::~BOleComponent()
{
}


