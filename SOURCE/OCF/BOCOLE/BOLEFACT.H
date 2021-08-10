
//**************************************************************************
//
// BOleFact.h --   Declares the server-side helper for allowing OLE2 to
//                 create objects made available by Bolero server apps.
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#ifndef _BOLEFACT_H
#define _BOLEFACT_H

#include "BOleComp.h"

class _ICLASS BOleSite;
class _ICLASS BOleInProcFactory;

// class BOleFact -- OLE 2.0 Factory helper
//
class _ICLASS BOleFact : public BOleComponent, public IBClass
{
protected:
	unsigned RefCnt;
	BCID regId;
	IBClassMgr * pObjCM;
	DWORD hReg;
	DWORD dwRegisterActiveObject;
	CLSID id;
	BOleInProcFactory FAR* pIPEFact;

public:

	BOleFact(BOleClassManager * pFact, IBUnknownMain *pOuter);
	~BOleFact();

	virtual HRESULT _IFUNC Init(BOOL fSelfEmbed, LPCOLESTR pszProgId, 
                                   IBClassMgr * pCM, BCID rid);
	virtual HRESULT _IFUNC Register(BOOL fSingleUse);
	virtual HRESULT _IFUNC Revoke();
	virtual HRESULT _IFUNC GetClassID(LPCLSID pClass);
	virtual BOOL _IFUNC IsA(REFCLSID);
	virtual BOOL _IFUNC AllowEmbedFromSelf ();
	virtual HRESULT _IFUNC GetEmbeddingHelperFactory (LPUNKNOWN *ppF);
	
	IBClassMgr * ClassMgrGet() { return pObjCM; }
	

	operator const CLSID &() const {return id;}
	
	// IUnknown Methods
	//
	DEFINE_IUNKNOWN(pObjOuter);

	virtual HRESULT _IFUNC QueryInterfaceMain(REFIID iid, LPVOID FAR* pif);

	// IClassFactory methods
	//
	HRESULT _IFUNC CreateInstance(IUnknown FAR* pUnk, REFIID iid, LPVOID FAR* ppv);
	HRESULT _IFUNC LockServer(BOOL fLock);
};


// 
// BOleInProcFactory -- Private factory used when a server object is
//                      registered to be instantiated in its own container
//
class _ICLASS BOleInProcFactory : public BOleComponent, public IClassFactory
{
	public:

		BOleInProcFactory (BOleClassManager *,BOleFact FAR*, REFIID);
		~BOleInProcFactory ();

		HRESULT _IFUNC Register (BOOL);
		HRESULT _IFUNC Revoke ();

		// IUnknown methods
		//
		virtual HRESULT _IFUNC QueryInterfaceMain (REFIID iid, LPVOID FAR* pif);
		DEFINE_IUNKNOWN(pObjOuter);

	protected:

		ULONG nRef;
		DWORD regCookie;
		BOleFact *pRealFactory;
		REFIID iidServer;

		// IClassFactory methods
		//
		virtual HRESULT _IFUNC CreateInstance (LPUNKNOWN pUnk, REFIID iid, 
                                                      LPVOID FAR* ppv);
		virtual HRESULT _IFUNC LockServer (BOOL fLock);

};

#endif
