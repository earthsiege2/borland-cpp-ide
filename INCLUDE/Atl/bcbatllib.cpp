/* This file contains various data and code extracted from the ATL 3.0 headers
   in order to allow them to be precompiled. An explanation of each extraction
   is included as appropriate. */

#ifndef __BCBATLLIB__
#define __BCBATLLIB__

#pragma option push -w-inl
#pragma option push -w-aus

#include <utilcls.h>
#include <atl\atlmod.h>
#include <atl\atlbase.h>
#include <atl\atlwin.h>
#include <atl\atlcom.h>
#include <atl\atlhost.h>
#include <atl\atlsnap.h>
#include <atl\statreg.h>


// From AtlBase.H:

/* GUIDS and other static data declared via declspec(__selectany), which is not
   supported in precompiled headers. */

const GUID LIBID_ATLLib = {0x44EC0535,0x400F,0x11D0,{0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3}};
const CLSID CLSID_Registrar = {0x44EC053A,0x400F,0x11D0,{0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3}};
const IID IID_IRegistrar = {0x44EC053B,0x400F,0x11D0,{0x9D,0xCD,0x00,0xA0,0xC9,0x03,0x91,0xD3}};
const IID IID_IAxWinHostWindow = {0xb6ea2050,0x48a,0x11d1,{0x82,0xb9,0x0,0xc0,0x4f,0xb9,0x94,0x2e}};
const IID IID_IAxWinAmbientDispatch = {0xb6ea2051,0x48a,0x11d1,{0x82,0xb9,0x0,0xc0,0x4f,0xb9,0x94,0x2e}};
const IID IID_IInternalConnection = {0x72AD0770,0x6A9F,0x11d1,{0xBC,0xEC,0x00,0x60,0x08,0x8F,0x44,0x4E}};
const IID IID_IDocHostUIHandlerDispatch = {0x425B5AF0,0x65F1,0x11d1,{0x96,0x11,0x00,0x00,0xF8,0x1E,0x0D,0x0D}};

extern "C" GUID GUID_ATLVer30 = { 0xb62f5910, 0x6528, 0x11d1, { 0x96, 0x11, 0x0, 0x0, 0xf8, 0x1e, 0xd, 0xd } };

UINT CComApartment::ATL_CREATE_OBJECT = 0;

/* Global function declared and implemented; implementation moved here. */

static HRESULT AtlSetChildSite(IUnknown* punkChild, IUnknown* punkParent)
{
	if (punkChild == NULL)
		return E_POINTER;

	HRESULT hr;
	IObjectWithSite* pChildSite = NULL;
	hr = punkChild->QueryInterface(IID_IObjectWithSite, (void**)&pChildSite);
	if (SUCCEEDED(hr) && pChildSite != NULL)
	{
		hr = pChildSite->SetSite(punkParent);
		pChildSite->Release();
	}
	return hr;
}

namespace ATL {

/* Static data initialized within the ATL namespace. */

CComModule* _pModule = NULL;
GUID CComModule::m_libid = {0x0,0x0,0x0,{0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0}};

/* Namespace-global function implemented in the header */

UINT WINAPI AtlGetDirLen(LPCOLESTR lpszPathName)
{
	ATLASSERT(lpszPathName != NULL);

	// always capture the complete file name including extension (if present)
	LPCOLESTR lpszTemp = lpszPathName;
	for (LPCOLESTR lpsz = lpszPathName; *lpsz != NULL; )
	{
		LPCOLESTR lp = CharNextO(lpsz);
		// remember last directory/drive separator
		if (*lpsz == OLESTR('\\') || *lpsz == OLESTR('/') || *lpsz == OLESTR(':'))
			lpszTemp = lp;
		lpsz = lp;
	}

	return lpszTemp-lpszPathName;
}

}
//----------------------------------------------------------------------------//
// From AtlHost.H:

/* Static data initialized in the header, inside the ATL namespace. */

namespace ATL {
UINT WM_ATLGETHOST = 0;
UINT WM_ATLGETCONTROL = 0;
}

//----------------------------------------------------------------------------//
// From AtlSnap.H

/* Static data initialized in the header. */

CLIPFORMAT CSnapInItem::m_CCF_NODETYPE = 0;
CLIPFORMAT CSnapInItem::m_CCF_SZNODETYPE = 0;
CLIPFORMAT CSnapInItem::m_CCF_DISPLAY_NAME = 0;
CLIPFORMAT CSnapInItem::m_CCF_SNAPIN_CLASSID = 0;
CLIPFORMAT CSnapInItem::m_CCF_SNAPIN_GETOBJECTDATA = 0;
CLIPFORMAT CSnapInItem::m_CCF_MMC_MULTISELECT_DATAOBJECT = 0;

//----------------------------------------------------------------------------//
// From AtlWin.H

/* Static data initialized in the header. */

RECT CWindow::rcDefault = { CW_USEDEFAULT, CW_USEDEFAULT, 0, 0 };

//----------------------------------------------------------------------------//
// From AtlCom.H

namespace ATL {

/* Methods of CComDispatchDriver which initialize static data based upon
   values passed as in parameters. The initialization prevents them from
   precompiling. */

HRESULT CComDispatchDriver::Invoke0(DISPID dispid, VARIANT* pvarRet)
	{
		DISPPARAMS dispparams = { NULL, NULL, 0, 0};
		return p->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &dispparams, pvarRet, NULL, NULL);
	}

HRESULT CComDispatchDriver::Invoke1(DISPID dispid, VARIANT* pvarParam1, VARIANT* pvarRet)
	{
		DISPPARAMS dispparams = { pvarParam1, NULL, 1, 0};
		return p->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &dispparams, pvarRet, NULL, NULL);
	}

HRESULT CComDispatchDriver::Invoke2(DISPID dispid, VARIANT* pvarParam1, VARIANT* pvarParam2, VARIANT* pvarRet)
	{
		CComVariant varArgs[2] = { *pvarParam2, *pvarParam1 };
		DISPPARAMS dispparams = { &varArgs[0], NULL, 2, 0};
		return p->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &dispparams, pvarRet, NULL, NULL);
	}

HRESULT CComDispatchDriver::InvokeN(DISPID dispid, VARIANT* pvarParams, int nParams, VARIANT* pvarRet)
	{
		DISPPARAMS dispparams = { pvarParams, NULL, nParams, 0};
		return p->Invoke(dispid, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &dispparams, pvarRet, NULL, NULL);
	}

HRESULT CComDispatchDriver::GetProperty(IDispatch* pDisp, DISPID dwDispID, VARIANT* pVar)
	{
		ATLTRACE2(atlTraceCOM, 0, _T("CPropertyHelper::GetProperty\n"));
		DISPPARAMS dispparamsNoArgs = {NULL, NULL, 0, 0};
		return pDisp->Invoke(dwDispID, IID_NULL,
				LOCALE_USER_DEFAULT, DISPATCH_PROPERTYGET,
				&dispparamsNoArgs, pVar, NULL, NULL);
	}

HRESULT CComDispatchDriver::PutProperty(IDispatch* pDisp, DISPID dwDispID, VARIANT* pVar)
	{
		ATLTRACE2(atlTraceCOM, 0, _T("CPropertyHelper::PutProperty\n"));
		DISPPARAMS dispparams = {NULL, NULL, 1, 1};
		dispparams.rgvarg = pVar;
		DISPID dispidPut = DISPID_PROPERTYPUT;
		dispparams.rgdispidNamedArgs = &dispidPut;

		if (pVar->vt == VT_UNKNOWN || pVar->vt == VT_DISPATCH ||
			(pVar->vt & VT_ARRAY) || (pVar->vt & VT_BYREF))
		{
			HRESULT hr = pDisp->Invoke(dwDispID, IID_NULL,
				LOCALE_USER_DEFAULT, DISPATCH_PROPERTYPUTREF,
				&dispparams, NULL, NULL, NULL);
			if (SUCCEEDED(hr))
				return hr;
		}

		return pDisp->Invoke(dwDispID, IID_NULL,
				LOCALE_USER_DEFAULT, DISPATCH_PROPERTYPUT,
				&dispparams, NULL, NULL, NULL);
	}

        /* Implementations of methods and some static data initialization
           are performed by BEGIN_COM_MAP and END_COM_MAP. They have been
           broken into: BEGIN_HEADER_COM_MAP and BEGIN_IMPL_COM_MAP, and
           END_HEADER_COM_MAP and END_IMPL_COM_MAP. The _HEADER_ versions
           declare methods and data, and the _IMPL_ versions implement
           the methods and initialize the data. COM_IMPL_INTERFACE_ENTRY
           is a version of COM_INTERFACE_ENTRY which does not require
           a typedef to have been declared in the enclosing scope. */

        BEGIN_IMPL_COM_MAP(CComClassFactory, CComClassFactory)
               COM_IMPL_INTERFACE_ENTRY(IClassFactory, CComClassFactory)
        END_IMPL_COM_MAP()

        BEGIN_IMPL_COM_MAP(CComClassFactoryAutoThread,CComClassFactoryAutoThread)
                COM_IMPL_INTERFACE_ENTRY(IClassFactory, CComClassFactoryAutoThread)
        END_IMPL_COM_MAP()
}
//----------------------------------------------------------------------------//
// From StatReg.H

/* Initialized data, mostly declared via declspec(__selectany) */

LPCTSTR CRegParser::rgszNeverDelete[] =
{
	_T("CLSID"), _T("TYPELIB")
}; //Component Catagories

const int CRegParser::cbNeverDelete = sizeof(rgszNeverDelete) / sizeof(LPCTSTR*);
const int CRegParser::MAX_VALUE=4096;
const int CRegParser::MAX_TYPE=MAX_VALUE;

#pragma option pop
#pragma option pop
#endif
