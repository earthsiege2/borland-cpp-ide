
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0347 */
/* Compiler settings for shobjidl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __shobjidl_h__
#define __shobjidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPersistFolder_FWD_DEFINED__
#define __IPersistFolder_FWD_DEFINED__
typedef interface IPersistFolder IPersistFolder;
#endif 	/* __IPersistFolder_FWD_DEFINED__ */


#ifndef __IPersistFolder2_FWD_DEFINED__
#define __IPersistFolder2_FWD_DEFINED__
typedef interface IPersistFolder2 IPersistFolder2;
#endif 	/* __IPersistFolder2_FWD_DEFINED__ */


#ifndef __IPersistIDList_FWD_DEFINED__
#define __IPersistIDList_FWD_DEFINED__
typedef interface IPersistIDList IPersistIDList;
#endif 	/* __IPersistIDList_FWD_DEFINED__ */


#ifndef __IEnumIDList_FWD_DEFINED__
#define __IEnumIDList_FWD_DEFINED__
typedef interface IEnumIDList IEnumIDList;
#endif 	/* __IEnumIDList_FWD_DEFINED__ */


#ifndef __IShellFolder_FWD_DEFINED__
#define __IShellFolder_FWD_DEFINED__
typedef interface IShellFolder IShellFolder;
#endif 	/* __IShellFolder_FWD_DEFINED__ */


#ifndef __IEnumExtraSearch_FWD_DEFINED__
#define __IEnumExtraSearch_FWD_DEFINED__
typedef interface IEnumExtraSearch IEnumExtraSearch;
#endif 	/* __IEnumExtraSearch_FWD_DEFINED__ */


#ifndef __IShellFolder2_FWD_DEFINED__
#define __IShellFolder2_FWD_DEFINED__
typedef interface IShellFolder2 IShellFolder2;
#endif 	/* __IShellFolder2_FWD_DEFINED__ */


#ifndef __IShellView_FWD_DEFINED__
#define __IShellView_FWD_DEFINED__
typedef interface IShellView IShellView;
#endif 	/* __IShellView_FWD_DEFINED__ */


#ifndef __IShellView2_FWD_DEFINED__
#define __IShellView2_FWD_DEFINED__
typedef interface IShellView2 IShellView2;
#endif 	/* __IShellView2_FWD_DEFINED__ */


#ifndef __IFolderView_FWD_DEFINED__
#define __IFolderView_FWD_DEFINED__
typedef interface IFolderView IFolderView;
#endif 	/* __IFolderView_FWD_DEFINED__ */


#ifndef __IFolderFilterSite_FWD_DEFINED__
#define __IFolderFilterSite_FWD_DEFINED__
typedef interface IFolderFilterSite IFolderFilterSite;
#endif 	/* __IFolderFilterSite_FWD_DEFINED__ */


#ifndef __IFolderFilter_FWD_DEFINED__
#define __IFolderFilter_FWD_DEFINED__
typedef interface IFolderFilter IFolderFilter;
#endif 	/* __IFolderFilter_FWD_DEFINED__ */


#ifndef __IShellBrowser_FWD_DEFINED__
#define __IShellBrowser_FWD_DEFINED__
typedef interface IShellBrowser IShellBrowser;
#endif 	/* __IShellBrowser_FWD_DEFINED__ */


#ifndef __IProfferService_FWD_DEFINED__
#define __IProfferService_FWD_DEFINED__
typedef interface IProfferService IProfferService;
#endif 	/* __IProfferService_FWD_DEFINED__ */


#ifndef __IPropertyUI_FWD_DEFINED__
#define __IPropertyUI_FWD_DEFINED__
typedef interface IPropertyUI IPropertyUI;
#endif 	/* __IPropertyUI_FWD_DEFINED__ */


#ifndef __ICategoryProvider_FWD_DEFINED__
#define __ICategoryProvider_FWD_DEFINED__
typedef interface ICategoryProvider ICategoryProvider;
#endif 	/* __ICategoryProvider_FWD_DEFINED__ */


#ifndef __ICategorizer_FWD_DEFINED__
#define __ICategorizer_FWD_DEFINED__
typedef interface ICategorizer ICategorizer;
#endif 	/* __ICategorizer_FWD_DEFINED__ */


#ifndef __IShellLinkA_FWD_DEFINED__
#define __IShellLinkA_FWD_DEFINED__
typedef interface IShellLinkA IShellLinkA;
#endif 	/* __IShellLinkA_FWD_DEFINED__ */


#ifndef __IShellLinkW_FWD_DEFINED__
#define __IShellLinkW_FWD_DEFINED__
typedef interface IShellLinkW IShellLinkW;
#endif 	/* __IShellLinkW_FWD_DEFINED__ */


#ifndef __IActionProgressDialog_FWD_DEFINED__
#define __IActionProgressDialog_FWD_DEFINED__
typedef interface IActionProgressDialog IActionProgressDialog;
#endif 	/* __IActionProgressDialog_FWD_DEFINED__ */


#ifndef __IHWEventHandler_FWD_DEFINED__
#define __IHWEventHandler_FWD_DEFINED__
typedef interface IHWEventHandler IHWEventHandler;
#endif 	/* __IHWEventHandler_FWD_DEFINED__ */


#ifndef __IQueryCancelAutoPlay_FWD_DEFINED__
#define __IQueryCancelAutoPlay_FWD_DEFINED__
typedef interface IQueryCancelAutoPlay IQueryCancelAutoPlay;
#endif 	/* __IQueryCancelAutoPlay_FWD_DEFINED__ */


#ifndef __IActionProgress_FWD_DEFINED__
#define __IActionProgress_FWD_DEFINED__
typedef interface IActionProgress IActionProgress;
#endif 	/* __IActionProgress_FWD_DEFINED__ */


#ifndef __IShellExtInit_FWD_DEFINED__
#define __IShellExtInit_FWD_DEFINED__
typedef interface IShellExtInit IShellExtInit;
#endif 	/* __IShellExtInit_FWD_DEFINED__ */


#ifndef __IShellPropSheetExt_FWD_DEFINED__
#define __IShellPropSheetExt_FWD_DEFINED__
typedef interface IShellPropSheetExt IShellPropSheetExt;
#endif 	/* __IShellPropSheetExt_FWD_DEFINED__ */


#ifndef __IRemoteComputer_FWD_DEFINED__
#define __IRemoteComputer_FWD_DEFINED__
typedef interface IRemoteComputer IRemoteComputer;
#endif 	/* __IRemoteComputer_FWD_DEFINED__ */


#ifndef __IQueryContinue_FWD_DEFINED__
#define __IQueryContinue_FWD_DEFINED__
typedef interface IQueryContinue IQueryContinue;
#endif 	/* __IQueryContinue_FWD_DEFINED__ */


#ifndef __IUserNotification_FWD_DEFINED__
#define __IUserNotification_FWD_DEFINED__
typedef interface IUserNotification IUserNotification;
#endif 	/* __IUserNotification_FWD_DEFINED__ */


#ifndef __IItemNameLimits_FWD_DEFINED__
#define __IItemNameLimits_FWD_DEFINED__
typedef interface IItemNameLimits IItemNameLimits;
#endif 	/* __IItemNameLimits_FWD_DEFINED__ */


#ifndef __INetCrawler_FWD_DEFINED__
#define __INetCrawler_FWD_DEFINED__
typedef interface INetCrawler INetCrawler;
#endif 	/* __INetCrawler_FWD_DEFINED__ */


#ifndef __IExtractImage_FWD_DEFINED__
#define __IExtractImage_FWD_DEFINED__
typedef interface IExtractImage IExtractImage;
#endif 	/* __IExtractImage_FWD_DEFINED__ */


#ifndef __IExtractImage2_FWD_DEFINED__
#define __IExtractImage2_FWD_DEFINED__
typedef interface IExtractImage2 IExtractImage2;
#endif 	/* __IExtractImage2_FWD_DEFINED__ */


#ifndef __IUserEventTimerCallback_FWD_DEFINED__
#define __IUserEventTimerCallback_FWD_DEFINED__
typedef interface IUserEventTimerCallback IUserEventTimerCallback;
#endif 	/* __IUserEventTimerCallback_FWD_DEFINED__ */


#ifndef __IUserEventTimer_FWD_DEFINED__
#define __IUserEventTimer_FWD_DEFINED__
typedef interface IUserEventTimer IUserEventTimer;
#endif 	/* __IUserEventTimer_FWD_DEFINED__ */


#ifndef __IDockingWindow_FWD_DEFINED__
#define __IDockingWindow_FWD_DEFINED__
typedef interface IDockingWindow IDockingWindow;
#endif 	/* __IDockingWindow_FWD_DEFINED__ */


#ifndef __IDeskBand_FWD_DEFINED__
#define __IDeskBand_FWD_DEFINED__
typedef interface IDeskBand IDeskBand;
#endif 	/* __IDeskBand_FWD_DEFINED__ */


#ifndef __ITaskbarList_FWD_DEFINED__
#define __ITaskbarList_FWD_DEFINED__
typedef interface ITaskbarList ITaskbarList;
#endif 	/* __ITaskbarList_FWD_DEFINED__ */


#ifndef __ITaskbarList2_FWD_DEFINED__
#define __ITaskbarList2_FWD_DEFINED__
typedef interface ITaskbarList2 ITaskbarList2;
#endif 	/* __ITaskbarList2_FWD_DEFINED__ */


#ifndef __ICDBurn_FWD_DEFINED__
#define __ICDBurn_FWD_DEFINED__
typedef interface ICDBurn ICDBurn;
#endif 	/* __ICDBurn_FWD_DEFINED__ */


#ifndef __IAddressBarParser_FWD_DEFINED__
#define __IAddressBarParser_FWD_DEFINED__
typedef interface IAddressBarParser IAddressBarParser;
#endif 	/* __IAddressBarParser_FWD_DEFINED__ */


#ifndef __IWizardSite_FWD_DEFINED__
#define __IWizardSite_FWD_DEFINED__
typedef interface IWizardSite IWizardSite;
#endif 	/* __IWizardSite_FWD_DEFINED__ */


#ifndef __IWizardExtension_FWD_DEFINED__
#define __IWizardExtension_FWD_DEFINED__
typedef interface IWizardExtension IWizardExtension;
#endif 	/* __IWizardExtension_FWD_DEFINED__ */


#ifndef __IWebWizardExtension_FWD_DEFINED__
#define __IWebWizardExtension_FWD_DEFINED__
typedef interface IWebWizardExtension IWebWizardExtension;
#endif 	/* __IWebWizardExtension_FWD_DEFINED__ */


#ifndef __IPublishingWizard_FWD_DEFINED__
#define __IPublishingWizard_FWD_DEFINED__
typedef interface IPublishingWizard IPublishingWizard;
#endif 	/* __IPublishingWizard_FWD_DEFINED__ */


#ifndef __IFolderViewHost_FWD_DEFINED__
#define __IFolderViewHost_FWD_DEFINED__
typedef interface IFolderViewHost IFolderViewHost;
#endif 	/* __IFolderViewHost_FWD_DEFINED__ */


#ifndef __IAutoCompleteDropDown_FWD_DEFINED__
#define __IAutoCompleteDropDown_FWD_DEFINED__
typedef interface IAutoCompleteDropDown IAutoCompleteDropDown;
#endif 	/* __IAutoCompleteDropDown_FWD_DEFINED__ */


#ifndef __QueryCancelAutoPlay_FWD_DEFINED__
#define __QueryCancelAutoPlay_FWD_DEFINED__

#ifdef __cplusplus
typedef class QueryCancelAutoPlay QueryCancelAutoPlay;
#else
typedef struct QueryCancelAutoPlay QueryCancelAutoPlay;
#endif /* __cplusplus */

#endif 	/* __QueryCancelAutoPlay_FWD_DEFINED__ */


#ifndef __DriveSizeCategorizer_FWD_DEFINED__
#define __DriveSizeCategorizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class DriveSizeCategorizer DriveSizeCategorizer;
#else
typedef struct DriveSizeCategorizer DriveSizeCategorizer;
#endif /* __cplusplus */

#endif 	/* __DriveSizeCategorizer_FWD_DEFINED__ */


#ifndef __DriveTypeCategorizer_FWD_DEFINED__
#define __DriveTypeCategorizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class DriveTypeCategorizer DriveTypeCategorizer;
#else
typedef struct DriveTypeCategorizer DriveTypeCategorizer;
#endif /* __cplusplus */

#endif 	/* __DriveTypeCategorizer_FWD_DEFINED__ */


#ifndef __FreeSpaceCategorizer_FWD_DEFINED__
#define __FreeSpaceCategorizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class FreeSpaceCategorizer FreeSpaceCategorizer;
#else
typedef struct FreeSpaceCategorizer FreeSpaceCategorizer;
#endif /* __cplusplus */

#endif 	/* __FreeSpaceCategorizer_FWD_DEFINED__ */


#ifndef __TimeCategorizer_FWD_DEFINED__
#define __TimeCategorizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class TimeCategorizer TimeCategorizer;
#else
typedef struct TimeCategorizer TimeCategorizer;
#endif /* __cplusplus */

#endif 	/* __TimeCategorizer_FWD_DEFINED__ */


#ifndef __SizeCategorizer_FWD_DEFINED__
#define __SizeCategorizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class SizeCategorizer SizeCategorizer;
#else
typedef struct SizeCategorizer SizeCategorizer;
#endif /* __cplusplus */

#endif 	/* __SizeCategorizer_FWD_DEFINED__ */


#ifndef __AlphabeticalCategorizer_FWD_DEFINED__
#define __AlphabeticalCategorizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class AlphabeticalCategorizer AlphabeticalCategorizer;
#else
typedef struct AlphabeticalCategorizer AlphabeticalCategorizer;
#endif /* __cplusplus */

#endif 	/* __AlphabeticalCategorizer_FWD_DEFINED__ */


#ifndef __MergedCategorizer_FWD_DEFINED__
#define __MergedCategorizer_FWD_DEFINED__

#ifdef __cplusplus
typedef class MergedCategorizer MergedCategorizer;
#else
typedef struct MergedCategorizer MergedCategorizer;
#endif /* __cplusplus */

#endif 	/* __MergedCategorizer_FWD_DEFINED__ */


#ifndef __ImageProperties_FWD_DEFINED__
#define __ImageProperties_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImageProperties ImageProperties;
#else
typedef struct ImageProperties ImageProperties;
#endif /* __cplusplus */

#endif 	/* __ImageProperties_FWD_DEFINED__ */


#ifndef __PropertiesUI_FWD_DEFINED__
#define __PropertiesUI_FWD_DEFINED__

#ifdef __cplusplus
typedef class PropertiesUI PropertiesUI;
#else
typedef struct PropertiesUI PropertiesUI;
#endif /* __cplusplus */

#endif 	/* __PropertiesUI_FWD_DEFINED__ */


#ifndef __UserNotification_FWD_DEFINED__
#define __UserNotification_FWD_DEFINED__

#ifdef __cplusplus
typedef class UserNotification UserNotification;
#else
typedef struct UserNotification UserNotification;
#endif /* __cplusplus */

#endif 	/* __UserNotification_FWD_DEFINED__ */


#ifndef __UserEventTimerCallback_FWD_DEFINED__
#define __UserEventTimerCallback_FWD_DEFINED__

#ifdef __cplusplus
typedef class UserEventTimerCallback UserEventTimerCallback;
#else
typedef struct UserEventTimerCallback UserEventTimerCallback;
#endif /* __cplusplus */

#endif 	/* __UserEventTimerCallback_FWD_DEFINED__ */


#ifndef __UserEventTimer_FWD_DEFINED__
#define __UserEventTimer_FWD_DEFINED__

#ifdef __cplusplus
typedef class UserEventTimer UserEventTimer;
#else
typedef struct UserEventTimer UserEventTimer;
#endif /* __cplusplus */

#endif 	/* __UserEventTimer_FWD_DEFINED__ */


#ifndef __NetCrawler_FWD_DEFINED__
#define __NetCrawler_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetCrawler NetCrawler;
#else
typedef struct NetCrawler NetCrawler;
#endif /* __cplusplus */

#endif 	/* __NetCrawler_FWD_DEFINED__ */


#ifndef __CDBurn_FWD_DEFINED__
#define __CDBurn_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDBurn CDBurn;
#else
typedef struct CDBurn CDBurn;
#endif /* __cplusplus */

#endif 	/* __CDBurn_FWD_DEFINED__ */


#ifndef __AddressBarParser_FWD_DEFINED__
#define __AddressBarParser_FWD_DEFINED__

#ifdef __cplusplus
typedef class AddressBarParser AddressBarParser;
#else
typedef struct AddressBarParser AddressBarParser;
#endif /* __cplusplus */

#endif 	/* __AddressBarParser_FWD_DEFINED__ */


#ifndef __TaskbarList_FWD_DEFINED__
#define __TaskbarList_FWD_DEFINED__

#ifdef __cplusplus
typedef class TaskbarList TaskbarList;
#else
typedef struct TaskbarList TaskbarList;
#endif /* __cplusplus */

#endif 	/* __TaskbarList_FWD_DEFINED__ */


#ifndef __WebWizardHost_FWD_DEFINED__
#define __WebWizardHost_FWD_DEFINED__

#ifdef __cplusplus
typedef class WebWizardHost WebWizardHost;
#else
typedef struct WebWizardHost WebWizardHost;
#endif /* __cplusplus */

#endif 	/* __WebWizardHost_FWD_DEFINED__ */


#ifndef __PublishDropTarget_FWD_DEFINED__
#define __PublishDropTarget_FWD_DEFINED__

#ifdef __cplusplus
typedef class PublishDropTarget PublishDropTarget;
#else
typedef struct PublishDropTarget PublishDropTarget;
#endif /* __cplusplus */

#endif 	/* __PublishDropTarget_FWD_DEFINED__ */


#ifndef __PublishingWizard_FWD_DEFINED__
#define __PublishingWizard_FWD_DEFINED__

#ifdef __cplusplus
typedef class PublishingWizard PublishingWizard;
#else
typedef struct PublishingWizard PublishingWizard;
#endif /* __cplusplus */

#endif 	/* __PublishingWizard_FWD_DEFINED__ */


#ifndef __InternetPrintOrdering_FWD_DEFINED__
#define __InternetPrintOrdering_FWD_DEFINED__

#ifdef __cplusplus
typedef class InternetPrintOrdering InternetPrintOrdering;
#else
typedef struct InternetPrintOrdering InternetPrintOrdering;
#endif /* __cplusplus */

#endif 	/* __InternetPrintOrdering_FWD_DEFINED__ */


#ifndef __FolderViewHost_FWD_DEFINED__
#define __FolderViewHost_FWD_DEFINED__

#ifdef __cplusplus
typedef class FolderViewHost FolderViewHost;
#else
typedef struct FolderViewHost FolderViewHost;
#endif /* __cplusplus */

#endif 	/* __FolderViewHost_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oleidl.h"
#include "oaidl.h"
#include "shtypes.h"
#include "servprov.h"
#include "comcat.h"
#include "propidl.h"
#include "prsht.h"
#include "msxml.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_shobjidl_0000 */
/* [local] */ 

#ifndef _WINRESRC_
#ifndef _WIN32_IE
#define _WIN32_IE 0x0501
#else
#if (_WIN32_IE < 0x0400) && defined(_WIN32_WINNT) && (_WIN32_WINNT >= 0x0500)
#error _WIN32_IE setting conflicts with _WIN32_WINNT setting
#endif
#endif
#endif


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0000_v0_0_s_ifspec;

#ifndef __IPersistFolder_INTERFACE_DEFINED__
#define __IPersistFolder_INTERFACE_DEFINED__

/* interface IPersistFolder */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPersistFolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214EA-0000-0000-C000-000000000046")
    IPersistFolder : public IPersist
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ LPCITEMIDLIST pidl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistFolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPersistFolder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPersistFolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPersistFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            IPersistFolder * This,
            /* [out] */ CLSID *pClassID);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IPersistFolder * This,
            /* [in] */ LPCITEMIDLIST pidl);
        
        END_INTERFACE
    } IPersistFolderVtbl;

    interface IPersistFolder
    {
        CONST_VTBL struct IPersistFolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistFolder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistFolder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistFolder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistFolder_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPersistFolder_Initialize(This,pidl)	\
    (This)->lpVtbl -> Initialize(This,pidl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPersistFolder_Initialize_Proxy( 
    IPersistFolder * This,
    /* [in] */ LPCITEMIDLIST pidl);


void __RPC_STUB IPersistFolder_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPersistFolder_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0191 */
/* [local] */ 

typedef IPersistFolder *LPPERSISTFOLDER;

#if (_WIN32_IE >= 0x0400)


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0191_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0191_v0_0_s_ifspec;

#ifndef __IPersistFolder2_INTERFACE_DEFINED__
#define __IPersistFolder2_INTERFACE_DEFINED__

/* interface IPersistFolder2 */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPersistFolder2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1AC3D9F0-175C-11d1-95BE-00609797EA4F")
    IPersistFolder2 : public IPersistFolder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCurFolder( 
            /* [out] */ LPITEMIDLIST *ppidl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistFolder2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPersistFolder2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPersistFolder2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPersistFolder2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            IPersistFolder2 * This,
            /* [out] */ CLSID *pClassID);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IPersistFolder2 * This,
            /* [in] */ LPCITEMIDLIST pidl);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurFolder )( 
            IPersistFolder2 * This,
            /* [out] */ LPITEMIDLIST *ppidl);
        
        END_INTERFACE
    } IPersistFolder2Vtbl;

    interface IPersistFolder2
    {
        CONST_VTBL struct IPersistFolder2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistFolder2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistFolder2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistFolder2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistFolder2_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPersistFolder2_Initialize(This,pidl)	\
    (This)->lpVtbl -> Initialize(This,pidl)


#define IPersistFolder2_GetCurFolder(This,ppidl)	\
    (This)->lpVtbl -> GetCurFolder(This,ppidl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPersistFolder2_GetCurFolder_Proxy( 
    IPersistFolder2 * This,
    /* [out] */ LPITEMIDLIST *ppidl);


void __RPC_STUB IPersistFolder2_GetCurFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPersistFolder2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0192 */
/* [local] */ 

typedef IPersistFolder2 *LPPERSISTFOLDER2;

#endif


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0192_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0192_v0_0_s_ifspec;

#ifndef __IPersistIDList_INTERFACE_DEFINED__
#define __IPersistIDList_INTERFACE_DEFINED__

/* interface IPersistIDList */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IPersistIDList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1079acfc-29bd-11d3-8e0d-00c04f6837d5")
    IPersistIDList : public IPersist
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetIDList( 
            /* [in] */ LPCITEMIDLIST pidl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIDList( 
            /* [out] */ LPITEMIDLIST *ppidl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistIDListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPersistIDList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPersistIDList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPersistIDList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClassID )( 
            IPersistIDList * This,
            /* [out] */ CLSID *pClassID);
        
        HRESULT ( STDMETHODCALLTYPE *SetIDList )( 
            IPersistIDList * This,
            /* [in] */ LPCITEMIDLIST pidl);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDList )( 
            IPersistIDList * This,
            /* [out] */ LPITEMIDLIST *ppidl);
        
        END_INTERFACE
    } IPersistIDListVtbl;

    interface IPersistIDList
    {
        CONST_VTBL struct IPersistIDListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistIDList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistIDList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistIDList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistIDList_GetClassID(This,pClassID)	\
    (This)->lpVtbl -> GetClassID(This,pClassID)


#define IPersistIDList_SetIDList(This,pidl)	\
    (This)->lpVtbl -> SetIDList(This,pidl)

#define IPersistIDList_GetIDList(This,ppidl)	\
    (This)->lpVtbl -> GetIDList(This,ppidl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPersistIDList_SetIDList_Proxy( 
    IPersistIDList * This,
    /* [in] */ LPCITEMIDLIST pidl);


void __RPC_STUB IPersistIDList_SetIDList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPersistIDList_GetIDList_Proxy( 
    IPersistIDList * This,
    /* [out] */ LPITEMIDLIST *ppidl);


void __RPC_STUB IPersistIDList_GetIDList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPersistIDList_INTERFACE_DEFINED__ */


#ifndef __IEnumIDList_INTERFACE_DEFINED__
#define __IEnumIDList_INTERFACE_DEFINED__

/* interface IEnumIDList */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IEnumIDList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214F2-0000-0000-C000-000000000046")
    IEnumIDList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ LPITEMIDLIST *rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumIDList **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumIDListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumIDList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumIDList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumIDList * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumIDList * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ LPITEMIDLIST *rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumIDList * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumIDList * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumIDList * This,
            /* [out] */ IEnumIDList **ppenum);
        
        END_INTERFACE
    } IEnumIDListVtbl;

    interface IEnumIDList
    {
        CONST_VTBL struct IEnumIDListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumIDList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumIDList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumIDList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumIDList_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumIDList_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumIDList_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumIDList_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumIDList_Next_Proxy( 
    IEnumIDList * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ LPITEMIDLIST *rgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumIDList_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIDList_Skip_Proxy( 
    IEnumIDList * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumIDList_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIDList_Reset_Proxy( 
    IEnumIDList * This);


void __RPC_STUB IEnumIDList_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumIDList_Clone_Proxy( 
    IEnumIDList * This,
    /* [out] */ IEnumIDList **ppenum);


void __RPC_STUB IEnumIDList_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumIDList_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0194 */
/* [local] */ 

typedef IEnumIDList *LPENUMIDLIST;

typedef enum tagSHGDN
{
    SHGDN_NORMAL             = 0x0000,  // default (display purpose)
    SHGDN_INFOLDER           = 0x0001,  // displayed under a folder (relative)
    SHGDN_FOREDITING         = 0x1000,  // for in-place editing
    SHGDN_FORADDRESSBAR      = 0x4000,  // UI friendly parsing name (remove ugly stuff)
    SHGDN_FORPARSING         = 0x8000,  // parsing name for ParseDisplayName()
} SHGNO;
typedef DWORD SHGDNF;

typedef enum tagSHCONTF
{
    SHCONTF_FOLDERS             = 0x0020,   // only want folders enumerated (SFGAO_FOLDER)
    SHCONTF_NONFOLDERS          = 0x0040,   // include non folders
    SHCONTF_INCLUDEHIDDEN       = 0x0080,   // show items normally hidden
    SHCONTF_INIT_ON_FIRST_NEXT  = 0x0100,   // allow EnumObject() to return before validating enum
    SHCONTF_NETPRINTERSRCH      = 0x0200,   // hint that client is looking for printers
    SHCONTF_SHAREABLE           = 0x0400,   // hint that client is looking sharable resources (remote shares)
    SHCONTF_STORAGE             = 0x0800,   // include all items with accessible storage and their ancestors
#ifdef __BORLANDC__
} tagSHCONTF;
#else
};
#endif

typedef DWORD SHCONTF;

#define SHCIDS_ALLFIELDS        0x80000000L
#define SHCIDS_CANONICALONLY    0x10000000L
#define SHCIDS_BITMASK          0xFFFF0000L
#define SHCIDS_COLUMNMASK       0x0000FFFFL
#define SFGAO_CANCOPY           DROPEFFECT_COPY // Objects can be copied    (0x1)
#define SFGAO_CANMOVE           DROPEFFECT_MOVE // Objects can be moved     (0x2)
#define SFGAO_CANLINK           DROPEFFECT_LINK // Objects can be linked    (0x4)
#define SFGAO_STORAGE           0x00000008L     // supports BindToObject(IID_IStorage)
#define SFGAO_CANRENAME         0x00000010L     // Objects can be renamed
#define SFGAO_CANDELETE         0x00000020L     // Objects can be deleted
#define SFGAO_HASPROPSHEET      0x00000040L     // Objects have property sheets
#define SFGAO_DROPTARGET        0x00000100L     // Objects are drop target
#define SFGAO_CAPABILITYMASK    0x00000177L
#define SFGAO_ENCRYPTED         0x00002000L     // object is encrypted (use alt color)
#define SFGAO_ISSLOW            0x00004000L     // 'slow' object
#define SFGAO_GHOSTED           0x00008000L     // ghosted icon
#define SFGAO_LINK              0x00010000L     // Shortcut (link)
#define SFGAO_SHARE             0x00020000L     // shared
#define SFGAO_READONLY          0x00040000L     // read-only
#define SFGAO_HIDDEN            0x00080000L     // hidden object
#define SFGAO_DISPLAYATTRMASK   0x000FC000L
#define SFGAO_FILESYSANCESTOR   0x10000000L     // may contain children with SFGAO_FILESYSTEM
#define SFGAO_FOLDER            0x20000000L     // support BindToObject(IID_IShellFolder)
#define SFGAO_FILESYSTEM        0x40000000L     // is a win32 file system object (file/folder/root)
#define SFGAO_HASSUBFOLDER      0x80000000L     // may contain children with SFGAO_FOLDER
#define SFGAO_CONTENTSMASK      0x80000000L
#define SFGAO_VALIDATE          0x01000000L     // invalidate cached information
#define SFGAO_REMOVABLE         0x02000000L     // is this removeable media?
#define SFGAO_COMPRESSED        0x04000000L     // Object is compressed (use alt color)
#define SFGAO_BROWSABLE         0x08000000L     // supports IShellFolder, but only implements CreateViewObject() (non-folder view)
#define SFGAO_NONENUMERATED     0x00100000L     // is a non-enumerated object
#define SFGAO_NEWCONTENT        0x00200000L     // should show bold in explorer tree
#define SFGAO_CANMONIKER        0x00400000L     // defunct
#define SFGAO_HASSTORAGE        0x00400000L     // defunct
#define SFGAO_STREAM            0x00400000L     // supports BindToObject(IID_IStream)
#define SFGAO_STORAGEANCESTOR   0x00800000L     // may contain children with SFGAO_STORAGE or SFGAO_STREAM
#define SFGAO_STORAGECAPMASK    0x70C50008L     // for determining storage capabilities, ie for open/save semantics
typedef ULONG SFGAOF;

#define STR_SKIP_BINDING_CLSID      L"Skip Binding CLSID"
#define STR_PARSE_PREFER_FOLDER_BROWSING     L"Parse Prefer Folder Browsing"
#define STR_DONT_PARSE_RELATIVE              L"Don't Parse Relative"
#define STR_PARSE_TRANSLATE_ALIASES          L"Parse Translate Aliases"



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0194_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0194_v0_0_s_ifspec;

#ifndef __IShellFolder_INTERFACE_DEFINED__
#define __IShellFolder_INTERFACE_DEFINED__

/* interface IShellFolder */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IShellFolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214E6-0000-0000-C000-000000000046")
    IShellFolder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ParseDisplayName( 
            /* [in] */ HWND hwnd,
            /* [in] */ LPBC pbc,
            /* [string][in] */ LPOLESTR pszDisplayName,
            /* [out] */ ULONG *pchEaten,
            /* [out] */ LPITEMIDLIST *ppidl,
            /* [unique][out][in] */ ULONG *pdwAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumObjects( 
            /* [in] */ HWND hwnd,
            /* [in] */ SHCONTF grfFlags,
            /* [out] */ IEnumIDList **ppenumIDList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToObject( 
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ LPBC pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BindToStorage( 
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ LPBC pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareIDs( 
            /* [in] */ LPARAM lParam,
            /* [in] */ LPCITEMIDLIST pidl1,
            /* [in] */ LPCITEMIDLIST pidl2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateViewObject( 
            /* [in] */ HWND hwndOwner,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributesOf( 
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [out][in] */ SFGAOF *rgfInOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUIObjectOf( 
            /* [in] */ HWND hwndOwner,
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [in] */ REFIID riid,
            /* [unique][out][in] */ UINT *rgfReserved,
            /* [iid_is][out] */ void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplayNameOf( 
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ SHGDNF uFlags,
            /* [out] */ STRRET *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNameOf( 
            /* [in] */ HWND hwnd,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [string][in] */ LPCOLESTR pszName,
            /* [in] */ SHGDNF uFlags,
            /* [out] */ LPITEMIDLIST *ppidlOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellFolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellFolder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellFolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *ParseDisplayName )( 
            IShellFolder * This,
            /* [in] */ HWND hwnd,
            /* [in] */ LPBC pbc,
            /* [string][in] */ LPOLESTR pszDisplayName,
            /* [out] */ ULONG *pchEaten,
            /* [out] */ LPITEMIDLIST *ppidl,
            /* [unique][out][in] */ ULONG *pdwAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *EnumObjects )( 
            IShellFolder * This,
            /* [in] */ HWND hwnd,
            /* [in] */ SHCONTF grfFlags,
            /* [out] */ IEnumIDList **ppenumIDList);
        
        HRESULT ( STDMETHODCALLTYPE *BindToObject )( 
            IShellFolder * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ LPBC pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *BindToStorage )( 
            IShellFolder * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ LPBC pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *CompareIDs )( 
            IShellFolder * This,
            /* [in] */ LPARAM lParam,
            /* [in] */ LPCITEMIDLIST pidl1,
            /* [in] */ LPCITEMIDLIST pidl2);
        
        HRESULT ( STDMETHODCALLTYPE *CreateViewObject )( 
            IShellFolder * This,
            /* [in] */ HWND hwndOwner,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttributesOf )( 
            IShellFolder * This,
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [out][in] */ SFGAOF *rgfInOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetUIObjectOf )( 
            IShellFolder * This,
            /* [in] */ HWND hwndOwner,
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [in] */ REFIID riid,
            /* [unique][out][in] */ UINT *rgfReserved,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayNameOf )( 
            IShellFolder * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ SHGDNF uFlags,
            /* [out] */ STRRET *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetNameOf )( 
            IShellFolder * This,
            /* [in] */ HWND hwnd,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [string][in] */ LPCOLESTR pszName,
            /* [in] */ SHGDNF uFlags,
            /* [out] */ LPITEMIDLIST *ppidlOut);
        
        END_INTERFACE
    } IShellFolderVtbl;

    interface IShellFolder
    {
        CONST_VTBL struct IShellFolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellFolder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellFolder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellFolder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellFolder_ParseDisplayName(This,hwnd,pbc,pszDisplayName,pchEaten,ppidl,pdwAttributes)	\
    (This)->lpVtbl -> ParseDisplayName(This,hwnd,pbc,pszDisplayName,pchEaten,ppidl,pdwAttributes)

#define IShellFolder_EnumObjects(This,hwnd,grfFlags,ppenumIDList)	\
    (This)->lpVtbl -> EnumObjects(This,hwnd,grfFlags,ppenumIDList)

#define IShellFolder_BindToObject(This,pidl,pbc,riid,ppv)	\
    (This)->lpVtbl -> BindToObject(This,pidl,pbc,riid,ppv)

#define IShellFolder_BindToStorage(This,pidl,pbc,riid,ppv)	\
    (This)->lpVtbl -> BindToStorage(This,pidl,pbc,riid,ppv)

#define IShellFolder_CompareIDs(This,lParam,pidl1,pidl2)	\
    (This)->lpVtbl -> CompareIDs(This,lParam,pidl1,pidl2)

#define IShellFolder_CreateViewObject(This,hwndOwner,riid,ppv)	\
    (This)->lpVtbl -> CreateViewObject(This,hwndOwner,riid,ppv)

#define IShellFolder_GetAttributesOf(This,cidl,apidl,rgfInOut)	\
    (This)->lpVtbl -> GetAttributesOf(This,cidl,apidl,rgfInOut)

#define IShellFolder_GetUIObjectOf(This,hwndOwner,cidl,apidl,riid,rgfReserved,ppv)	\
    (This)->lpVtbl -> GetUIObjectOf(This,hwndOwner,cidl,apidl,riid,rgfReserved,ppv)

#define IShellFolder_GetDisplayNameOf(This,pidl,uFlags,pName)	\
    (This)->lpVtbl -> GetDisplayNameOf(This,pidl,uFlags,pName)

#define IShellFolder_SetNameOf(This,hwnd,pidl,pszName,uFlags,ppidlOut)	\
    (This)->lpVtbl -> SetNameOf(This,hwnd,pidl,pszName,uFlags,ppidlOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IShellFolder_ParseDisplayName_Proxy( 
    IShellFolder * This,
    /* [in] */ HWND hwnd,
    /* [in] */ LPBC pbc,
    /* [string][in] */ LPOLESTR pszDisplayName,
    /* [out] */ ULONG *pchEaten,
    /* [out] */ LPITEMIDLIST *ppidl,
    /* [unique][out][in] */ ULONG *pdwAttributes);


void __RPC_STUB IShellFolder_ParseDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder_EnumObjects_Proxy( 
    IShellFolder * This,
    /* [in] */ HWND hwnd,
    /* [in] */ SHCONTF grfFlags,
    /* [out] */ IEnumIDList **ppenumIDList);


void __RPC_STUB IShellFolder_EnumObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder_BindToObject_Proxy( 
    IShellFolder * This,
    /* [in] */ LPCITEMIDLIST pidl,
    /* [in] */ LPBC pbc,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppv);


void __RPC_STUB IShellFolder_BindToObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder_BindToStorage_Proxy( 
    IShellFolder * This,
    /* [in] */ LPCITEMIDLIST pidl,
    /* [in] */ LPBC pbc,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppv);


void __RPC_STUB IShellFolder_BindToStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder_CompareIDs_Proxy( 
    IShellFolder * This,
    /* [in] */ LPARAM lParam,
    /* [in] */ LPCITEMIDLIST pidl1,
    /* [in] */ LPCITEMIDLIST pidl2);


void __RPC_STUB IShellFolder_CompareIDs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder_CreateViewObject_Proxy( 
    IShellFolder * This,
    /* [in] */ HWND hwndOwner,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppv);


void __RPC_STUB IShellFolder_CreateViewObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder_GetAttributesOf_Proxy( 
    IShellFolder * This,
    /* [in] */ UINT cidl,
    /* [size_is][in] */ LPCITEMIDLIST *apidl,
    /* [out][in] */ SFGAOF *rgfInOut);


void __RPC_STUB IShellFolder_GetAttributesOf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder_GetUIObjectOf_Proxy( 
    IShellFolder * This,
    /* [in] */ HWND hwndOwner,
    /* [in] */ UINT cidl,
    /* [size_is][in] */ LPCITEMIDLIST *apidl,
    /* [in] */ REFIID riid,
    /* [unique][out][in] */ UINT *rgfReserved,
    /* [iid_is][out] */ void **ppv);


void __RPC_STUB IShellFolder_GetUIObjectOf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder_GetDisplayNameOf_Proxy( 
    IShellFolder * This,
    /* [in] */ LPCITEMIDLIST pidl,
    /* [in] */ SHGDNF uFlags,
    /* [out] */ STRRET *pName);


void __RPC_STUB IShellFolder_GetDisplayNameOf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder_SetNameOf_Proxy( 
    IShellFolder * This,
    /* [in] */ HWND hwnd,
    /* [in] */ LPCITEMIDLIST pidl,
    /* [string][in] */ LPCOLESTR pszName,
    /* [in] */ SHGDNF uFlags,
    /* [out] */ LPITEMIDLIST *ppidlOut);


void __RPC_STUB IShellFolder_SetNameOf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShellFolder_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0195 */
/* [local] */ 

typedef IShellFolder *LPSHELLFOLDER;

#if (_WIN32_IE >= 0x0500)
typedef struct tagEXTRASEARCH
    {
    GUID guidSearch;
    WCHAR wszFriendlyName[ 80 ];
    WCHAR wszUrl[ 2084 ];
    } 	EXTRASEARCH;

typedef struct tagEXTRASEARCH *LPEXTRASEARCH;

typedef struct IEnumExtraSearch *LPENUMEXTRASEARCH;




extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0195_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0195_v0_0_s_ifspec;

#ifndef __IEnumExtraSearch_INTERFACE_DEFINED__
#define __IEnumExtraSearch_INTERFACE_DEFINED__

/* interface IEnumExtraSearch */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IEnumExtraSearch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0E700BE1-9DB6-11d1-A1CE-00C04FD75D13")
    IEnumExtraSearch : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ EXTRASEARCH *rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumExtraSearch **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumExtraSearchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumExtraSearch * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumExtraSearch * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumExtraSearch * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumExtraSearch * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ EXTRASEARCH *rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumExtraSearch * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumExtraSearch * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumExtraSearch * This,
            /* [out] */ IEnumExtraSearch **ppenum);
        
        END_INTERFACE
    } IEnumExtraSearchVtbl;

    interface IEnumExtraSearch
    {
        CONST_VTBL struct IEnumExtraSearchVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumExtraSearch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumExtraSearch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumExtraSearch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumExtraSearch_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumExtraSearch_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumExtraSearch_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumExtraSearch_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumExtraSearch_Next_Proxy( 
    IEnumExtraSearch * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ EXTRASEARCH *rgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IEnumExtraSearch_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumExtraSearch_Skip_Proxy( 
    IEnumExtraSearch * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumExtraSearch_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumExtraSearch_Reset_Proxy( 
    IEnumExtraSearch * This);


void __RPC_STUB IEnumExtraSearch_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumExtraSearch_Clone_Proxy( 
    IEnumExtraSearch * This,
    /* [out] */ IEnumExtraSearch **ppenum);


void __RPC_STUB IEnumExtraSearch_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumExtraSearch_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0196 */
/* [local] */ 

typedef /* [public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0196_0001
    {	SHCOLSTATE_TYPE_STR	= 0x1,
	SHCOLSTATE_TYPE_INT	= 0x2,
	SHCOLSTATE_TYPE_DATE	= 0x3,
	SHCOLSTATE_TYPEMASK	= 0xf,
	SHCOLSTATE_ONBYDEFAULT	= 0x10,
	SHCOLSTATE_SLOW	= 0x20,
	SHCOLSTATE_EXTENDED	= 0x40,
	SHCOLSTATE_SECONDARYUI	= 0x80,
	SHCOLSTATE_HIDDEN	= 0x100,
	SHCOLSTATE_PREFER_VARCMP	= 0x200
    } 	SHCOLSTATE;

typedef DWORD SHCOLSTATEF;

typedef /* [public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_shobjidl_0196_0002
    {
    GUID fmtid;
    DWORD pid;
    } 	SHCOLUMNID;

typedef struct __MIDL___MIDL_itf_shobjidl_0196_0002 *LPSHCOLUMNID;

typedef const SHCOLUMNID *LPCSHCOLUMNID;



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0196_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0196_v0_0_s_ifspec;

#ifndef __IShellFolder2_INTERFACE_DEFINED__
#define __IShellFolder2_INTERFACE_DEFINED__

/* interface IShellFolder2 */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IShellFolder2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("93F2F68C-1D1B-11d3-A30E-00C04F79ABD1")
    IShellFolder2 : public IShellFolder
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDefaultSearchGUID( 
            /* [out] */ GUID *pguid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSearches( 
            /* [out] */ IEnumExtraSearch **ppenum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultColumn( 
            /* [in] */ DWORD dwRes,
            /* [out] */ ULONG *pSort,
            /* [out] */ ULONG *pDisplay) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultColumnState( 
            /* [in] */ UINT iColumn,
            /* [out] */ SHCOLSTATEF *pcsFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDetailsEx( 
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ const SHCOLUMNID *pscid,
            /* [out] */ VARIANT *pv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDetailsOf( 
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ UINT iColumn,
            /* [out] */ SHELLDETAILS *psd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapColumnToSCID( 
            /* [in] */ UINT iColumn,
            /* [in] */ SHCOLUMNID *pscid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellFolder2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellFolder2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellFolder2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellFolder2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ParseDisplayName )( 
            IShellFolder2 * This,
            /* [in] */ HWND hwnd,
            /* [in] */ LPBC pbc,
            /* [string][in] */ LPOLESTR pszDisplayName,
            /* [out] */ ULONG *pchEaten,
            /* [out] */ LPITEMIDLIST *ppidl,
            /* [unique][out][in] */ ULONG *pdwAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *EnumObjects )( 
            IShellFolder2 * This,
            /* [in] */ HWND hwnd,
            /* [in] */ SHCONTF grfFlags,
            /* [out] */ IEnumIDList **ppenumIDList);
        
        HRESULT ( STDMETHODCALLTYPE *BindToObject )( 
            IShellFolder2 * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ LPBC pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *BindToStorage )( 
            IShellFolder2 * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ LPBC pbc,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *CompareIDs )( 
            IShellFolder2 * This,
            /* [in] */ LPARAM lParam,
            /* [in] */ LPCITEMIDLIST pidl1,
            /* [in] */ LPCITEMIDLIST pidl2);
        
        HRESULT ( STDMETHODCALLTYPE *CreateViewObject )( 
            IShellFolder2 * This,
            /* [in] */ HWND hwndOwner,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttributesOf )( 
            IShellFolder2 * This,
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [out][in] */ SFGAOF *rgfInOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetUIObjectOf )( 
            IShellFolder2 * This,
            /* [in] */ HWND hwndOwner,
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [in] */ REFIID riid,
            /* [unique][out][in] */ UINT *rgfReserved,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayNameOf )( 
            IShellFolder2 * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ SHGDNF uFlags,
            /* [out] */ STRRET *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetNameOf )( 
            IShellFolder2 * This,
            /* [in] */ HWND hwnd,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [string][in] */ LPCOLESTR pszName,
            /* [in] */ SHGDNF uFlags,
            /* [out] */ LPITEMIDLIST *ppidlOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultSearchGUID )( 
            IShellFolder2 * This,
            /* [out] */ GUID *pguid);
        
        HRESULT ( STDMETHODCALLTYPE *EnumSearches )( 
            IShellFolder2 * This,
            /* [out] */ IEnumExtraSearch **ppenum);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultColumn )( 
            IShellFolder2 * This,
            /* [in] */ DWORD dwRes,
            /* [out] */ ULONG *pSort,
            /* [out] */ ULONG *pDisplay);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultColumnState )( 
            IShellFolder2 * This,
            /* [in] */ UINT iColumn,
            /* [out] */ SHCOLSTATEF *pcsFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetDetailsEx )( 
            IShellFolder2 * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ const SHCOLUMNID *pscid,
            /* [out] */ VARIANT *pv);
        
        HRESULT ( STDMETHODCALLTYPE *GetDetailsOf )( 
            IShellFolder2 * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ UINT iColumn,
            /* [out] */ SHELLDETAILS *psd);
        
        HRESULT ( STDMETHODCALLTYPE *MapColumnToSCID )( 
            IShellFolder2 * This,
            /* [in] */ UINT iColumn,
            /* [in] */ SHCOLUMNID *pscid);
        
        END_INTERFACE
    } IShellFolder2Vtbl;

    interface IShellFolder2
    {
        CONST_VTBL struct IShellFolder2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellFolder2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellFolder2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellFolder2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellFolder2_ParseDisplayName(This,hwnd,pbc,pszDisplayName,pchEaten,ppidl,pdwAttributes)	\
    (This)->lpVtbl -> ParseDisplayName(This,hwnd,pbc,pszDisplayName,pchEaten,ppidl,pdwAttributes)

#define IShellFolder2_EnumObjects(This,hwnd,grfFlags,ppenumIDList)	\
    (This)->lpVtbl -> EnumObjects(This,hwnd,grfFlags,ppenumIDList)

#define IShellFolder2_BindToObject(This,pidl,pbc,riid,ppv)	\
    (This)->lpVtbl -> BindToObject(This,pidl,pbc,riid,ppv)

#define IShellFolder2_BindToStorage(This,pidl,pbc,riid,ppv)	\
    (This)->lpVtbl -> BindToStorage(This,pidl,pbc,riid,ppv)

#define IShellFolder2_CompareIDs(This,lParam,pidl1,pidl2)	\
    (This)->lpVtbl -> CompareIDs(This,lParam,pidl1,pidl2)

#define IShellFolder2_CreateViewObject(This,hwndOwner,riid,ppv)	\
    (This)->lpVtbl -> CreateViewObject(This,hwndOwner,riid,ppv)

#define IShellFolder2_GetAttributesOf(This,cidl,apidl,rgfInOut)	\
    (This)->lpVtbl -> GetAttributesOf(This,cidl,apidl,rgfInOut)

#define IShellFolder2_GetUIObjectOf(This,hwndOwner,cidl,apidl,riid,rgfReserved,ppv)	\
    (This)->lpVtbl -> GetUIObjectOf(This,hwndOwner,cidl,apidl,riid,rgfReserved,ppv)

#define IShellFolder2_GetDisplayNameOf(This,pidl,uFlags,pName)	\
    (This)->lpVtbl -> GetDisplayNameOf(This,pidl,uFlags,pName)

#define IShellFolder2_SetNameOf(This,hwnd,pidl,pszName,uFlags,ppidlOut)	\
    (This)->lpVtbl -> SetNameOf(This,hwnd,pidl,pszName,uFlags,ppidlOut)


#define IShellFolder2_GetDefaultSearchGUID(This,pguid)	\
    (This)->lpVtbl -> GetDefaultSearchGUID(This,pguid)

#define IShellFolder2_EnumSearches(This,ppenum)	\
    (This)->lpVtbl -> EnumSearches(This,ppenum)

#define IShellFolder2_GetDefaultColumn(This,dwRes,pSort,pDisplay)	\
    (This)->lpVtbl -> GetDefaultColumn(This,dwRes,pSort,pDisplay)

#define IShellFolder2_GetDefaultColumnState(This,iColumn,pcsFlags)	\
    (This)->lpVtbl -> GetDefaultColumnState(This,iColumn,pcsFlags)

#define IShellFolder2_GetDetailsEx(This,pidl,pscid,pv)	\
    (This)->lpVtbl -> GetDetailsEx(This,pidl,pscid,pv)

#define IShellFolder2_GetDetailsOf(This,pidl,iColumn,psd)	\
    (This)->lpVtbl -> GetDetailsOf(This,pidl,iColumn,psd)

#define IShellFolder2_MapColumnToSCID(This,iColumn,pscid)	\
    (This)->lpVtbl -> MapColumnToSCID(This,iColumn,pscid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IShellFolder2_GetDefaultSearchGUID_Proxy( 
    IShellFolder2 * This,
    /* [out] */ GUID *pguid);


void __RPC_STUB IShellFolder2_GetDefaultSearchGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder2_EnumSearches_Proxy( 
    IShellFolder2 * This,
    /* [out] */ IEnumExtraSearch **ppenum);


void __RPC_STUB IShellFolder2_EnumSearches_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder2_GetDefaultColumn_Proxy( 
    IShellFolder2 * This,
    /* [in] */ DWORD dwRes,
    /* [out] */ ULONG *pSort,
    /* [out] */ ULONG *pDisplay);


void __RPC_STUB IShellFolder2_GetDefaultColumn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder2_GetDefaultColumnState_Proxy( 
    IShellFolder2 * This,
    /* [in] */ UINT iColumn,
    /* [out] */ SHCOLSTATEF *pcsFlags);


void __RPC_STUB IShellFolder2_GetDefaultColumnState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder2_GetDetailsEx_Proxy( 
    IShellFolder2 * This,
    /* [in] */ LPCITEMIDLIST pidl,
    /* [in] */ const SHCOLUMNID *pscid,
    /* [out] */ VARIANT *pv);


void __RPC_STUB IShellFolder2_GetDetailsEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder2_GetDetailsOf_Proxy( 
    IShellFolder2 * This,
    /* [in] */ LPCITEMIDLIST pidl,
    /* [in] */ UINT iColumn,
    /* [out] */ SHELLDETAILS *psd);


void __RPC_STUB IShellFolder2_GetDetailsOf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellFolder2_MapColumnToSCID_Proxy( 
    IShellFolder2 * This,
    /* [in] */ UINT iColumn,
    /* [in] */ SHCOLUMNID *pscid);


void __RPC_STUB IShellFolder2_MapColumnToSCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShellFolder2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0197 */
/* [local] */ 

#endif // _WIN32_IE >= 0x0500)
typedef char *LPVIEWSETTINGS;

typedef /* [public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0197_0001
    {	FWF_AUTOARRANGE	= 0x1,
	FWF_ABBREVIATEDNAMES	= 0x2,
	FWF_SNAPTOGRID	= 0x4,
	FWF_OWNERDATA	= 0x8,
	FWF_BESTFITWINDOW	= 0x10,
	FWF_DESKTOP	= 0x20,
	FWF_SINGLESEL	= 0x40,
	FWF_NOSUBFOLDERS	= 0x80,
	FWF_TRANSPARENT	= 0x100,
	FWF_NOCLIENTEDGE	= 0x200,
	FWF_NOSCROLL	= 0x400,
	FWF_ALIGNLEFT	= 0x800,
	FWF_NOICONS	= 0x1000,
	FWF_SHOWSELALWAYS	= 0x2000,
	FWF_NOVISIBLE	= 0x4000,
	FWF_SINGLECLICKACTIVATE	= 0x8000,
	FWF_NOWEBVIEW	= 0x10000,
	FWF_HIDEFILENAMES	= 0x20000,
	FWF_CHECKSELECT	= 0x40000
    } 	FOLDERFLAGS;

typedef /* [public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0197_0002
    {	FVM_FIRST	= 1,
	FVM_ICON	= 1,
	FVM_SMALLICON	= 2,
	FVM_LIST	= 3,
	FVM_DETAILS	= 4,
	FVM_THUMBNAIL	= 5,
	FVM_TILE	= 6,
	FVM_THUMBSTRIP	= 7,
	FVM_LAST	= 7
    } 	FOLDERVIEWMODE;

typedef /* [public][public][public][public][public][public][public][public][public] */ struct __MIDL___MIDL_itf_shobjidl_0197_0003
    {
    UINT ViewMode;
    UINT fFlags;
    } 	FOLDERSETTINGS;

typedef FOLDERSETTINGS *LPFOLDERSETTINGS;

typedef const FOLDERSETTINGS *LPCFOLDERSETTINGS;

typedef FOLDERSETTINGS *PFOLDERSETTINGS;

#define SVSI_DESELECT       0x00000000
#define SVSI_SELECT         0x00000001
#define SVSI_EDIT           0x00000003  // includes select
#define SVSI_DESELECTOTHERS 0x00000004
#define SVSI_ENSUREVISIBLE  0x00000008
#define SVSI_FOCUSED        0x00000010
#define SVSI_TRANSLATEPT    0x00000020
#define SVSI_SELECTIONMARK  0x00000040
#define SVSI_POSITIONITEM   0x00000080
#define SVSI_CHECK          0x00000100
#define SVSI_NOSTATECHANGE  0x80000000
typedef UINT SVSIF;

typedef /* [public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0197_0004
    {	SVGIO_BACKGROUND	= 0,
	SVGIO_SELECTION	= 0x1,
	SVGIO_ALLVIEW	= 0x2,
	SVGIO_CHECKED	= 0x3,
	SVGIO_TYPE_MASK	= 0xf,
	SVGIO_FLAG_VIEWORDER	= 0x80000000
    } 	SVGIO;

typedef /* [public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0197_0005
    {	SVUIA_DEACTIVATE	= 0,
	SVUIA_ACTIVATE_NOFOCUS	= 1,
	SVUIA_ACTIVATE_FOCUS	= 2,
	SVUIA_INPLACEACTIVATE	= 3
    } 	SVUIA_STATUS;

#ifdef _FIX_ENABLEMODELESS_CONFLICT
#define    EnableModeless EnableModelessSV
#endif
#ifdef _NEVER_
typedef LPARAM LPFNSVADDPROPSHEETPAGE;

#else //!_NEVER_
#include <prsht.h>
typedef LPFNADDPROPSHEETPAGE LPFNSVADDPROPSHEETPAGE;
#endif //_NEVER_



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0197_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0197_v0_0_s_ifspec;

#ifndef __IShellView_INTERFACE_DEFINED__
#define __IShellView_INTERFACE_DEFINED__

/* interface IShellView */
/* [unique][object][uuid][helpstring] */ 

typedef IShellView *LPSHELLVIEW;


EXTERN_C const IID IID_IShellView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214E3-0000-0000-C000-000000000046")
    IShellView : public IOleWindow
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE TranslateAccelerator( 
            /* [in] */ MSG *pmsg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableModeless( 
            /* [in] */ BOOL fEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UIActivate( 
            /* [in] */ UINT uState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateViewWindow( 
            /* [in] */ IShellView *psvPrevious,
            /* [in] */ LPCFOLDERSETTINGS pfs,
            /* [in] */ IShellBrowser *psb,
            /* [out] */ RECT *prcView,
            /* [out] */ HWND *phWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DestroyViewWindow( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentInfo( 
            /* [out] */ LPFOLDERSETTINGS pfs) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE AddPropertySheetPages( 
            /* [in] */ DWORD dwReserved,
            /* [in] */ LPFNSVADDPROPSHEETPAGE pfn,
            /* [in] */ LPARAM lparam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveViewState( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectItem( 
            /* [in] */ LPCITEMIDLIST pidlItem,
            /* [in] */ SVSIF uFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemObject( 
            /* [in] */ UINT uItem,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellView * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellView * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            IShellView * This,
            /* [out] */ HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            IShellView * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( STDMETHODCALLTYPE *TranslateAccelerator )( 
            IShellView * This,
            /* [in] */ MSG *pmsg);
        
        HRESULT ( STDMETHODCALLTYPE *EnableModeless )( 
            IShellView * This,
            /* [in] */ BOOL fEnable);
        
        HRESULT ( STDMETHODCALLTYPE *UIActivate )( 
            IShellView * This,
            /* [in] */ UINT uState);
        
        HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IShellView * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateViewWindow )( 
            IShellView * This,
            /* [in] */ IShellView *psvPrevious,
            /* [in] */ LPCFOLDERSETTINGS pfs,
            /* [in] */ IShellBrowser *psb,
            /* [out] */ RECT *prcView,
            /* [out] */ HWND *phWnd);
        
        HRESULT ( STDMETHODCALLTYPE *DestroyViewWindow )( 
            IShellView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentInfo )( 
            IShellView * This,
            /* [out] */ LPFOLDERSETTINGS pfs);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *AddPropertySheetPages )( 
            IShellView * This,
            /* [in] */ DWORD dwReserved,
            /* [in] */ LPFNSVADDPROPSHEETPAGE pfn,
            /* [in] */ LPARAM lparam);
        
        HRESULT ( STDMETHODCALLTYPE *SaveViewState )( 
            IShellView * This);
        
        HRESULT ( STDMETHODCALLTYPE *SelectItem )( 
            IShellView * This,
            /* [in] */ LPCITEMIDLIST pidlItem,
            /* [in] */ SVSIF uFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemObject )( 
            IShellView * This,
            /* [in] */ UINT uItem,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        END_INTERFACE
    } IShellViewVtbl;

    interface IShellView
    {
        CONST_VTBL struct IShellViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellView_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IShellView_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IShellView_TranslateAccelerator(This,pmsg)	\
    (This)->lpVtbl -> TranslateAccelerator(This,pmsg)

#define IShellView_EnableModeless(This,fEnable)	\
    (This)->lpVtbl -> EnableModeless(This,fEnable)

#define IShellView_UIActivate(This,uState)	\
    (This)->lpVtbl -> UIActivate(This,uState)

#define IShellView_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)

#define IShellView_CreateViewWindow(This,psvPrevious,pfs,psb,prcView,phWnd)	\
    (This)->lpVtbl -> CreateViewWindow(This,psvPrevious,pfs,psb,prcView,phWnd)

#define IShellView_DestroyViewWindow(This)	\
    (This)->lpVtbl -> DestroyViewWindow(This)

#define IShellView_GetCurrentInfo(This,pfs)	\
    (This)->lpVtbl -> GetCurrentInfo(This,pfs)

#define IShellView_AddPropertySheetPages(This,dwReserved,pfn,lparam)	\
    (This)->lpVtbl -> AddPropertySheetPages(This,dwReserved,pfn,lparam)

#define IShellView_SaveViewState(This)	\
    (This)->lpVtbl -> SaveViewState(This)

#define IShellView_SelectItem(This,pidlItem,uFlags)	\
    (This)->lpVtbl -> SelectItem(This,pidlItem,uFlags)

#define IShellView_GetItemObject(This,uItem,riid,ppv)	\
    (This)->lpVtbl -> GetItemObject(This,uItem,riid,ppv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IShellView_TranslateAccelerator_Proxy( 
    IShellView * This,
    /* [in] */ MSG *pmsg);


void __RPC_STUB IShellView_TranslateAccelerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView_EnableModeless_Proxy( 
    IShellView * This,
    /* [in] */ BOOL fEnable);


void __RPC_STUB IShellView_EnableModeless_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView_UIActivate_Proxy( 
    IShellView * This,
    /* [in] */ UINT uState);


void __RPC_STUB IShellView_UIActivate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView_Refresh_Proxy( 
    IShellView * This);


void __RPC_STUB IShellView_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView_CreateViewWindow_Proxy( 
    IShellView * This,
    /* [in] */ IShellView *psvPrevious,
    /* [in] */ LPCFOLDERSETTINGS pfs,
    /* [in] */ IShellBrowser *psb,
    /* [out] */ RECT *prcView,
    /* [out] */ HWND *phWnd);


void __RPC_STUB IShellView_CreateViewWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView_DestroyViewWindow_Proxy( 
    IShellView * This);


void __RPC_STUB IShellView_DestroyViewWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView_GetCurrentInfo_Proxy( 
    IShellView * This,
    /* [out] */ LPFOLDERSETTINGS pfs);


void __RPC_STUB IShellView_GetCurrentInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IShellView_AddPropertySheetPages_Proxy( 
    IShellView * This,
    /* [in] */ DWORD dwReserved,
    /* [in] */ LPFNSVADDPROPSHEETPAGE pfn,
    /* [in] */ LPARAM lparam);


void __RPC_STUB IShellView_AddPropertySheetPages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView_SaveViewState_Proxy( 
    IShellView * This);


void __RPC_STUB IShellView_SaveViewState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView_SelectItem_Proxy( 
    IShellView * This,
    /* [in] */ LPCITEMIDLIST pidlItem,
    /* [in] */ SVSIF uFlags);


void __RPC_STUB IShellView_SelectItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView_GetItemObject_Proxy( 
    IShellView * This,
    /* [in] */ UINT uItem,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppv);


void __RPC_STUB IShellView_GetItemObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShellView_INTERFACE_DEFINED__ */


#ifndef __IShellView2_INTERFACE_DEFINED__
#define __IShellView2_INTERFACE_DEFINED__

/* interface IShellView2 */
/* [unique][object][uuid][helpstring] */ 

typedef GUID SHELLVIEWID;

#define SV2GV_CURRENTVIEW ((UINT)-1)
#define SV2GV_DEFAULTVIEW ((UINT)-2)
#include <pshpack8.h>
typedef struct _SV2CVW2_PARAMS
    {
    DWORD cbSize;
    IShellView *psvPrev;
    LPCFOLDERSETTINGS pfs;
    IShellBrowser *psbOwner;
    RECT *prcView;
    const SHELLVIEWID *pvid;
    HWND hwndView;
    } 	SV2CVW2_PARAMS;

typedef struct _SV2CVW2_PARAMS *LPSV2CVW2_PARAMS;

#include <poppack.h>

EXTERN_C const IID IID_IShellView2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88E39E80-3578-11CF-AE69-08002B2E1262")
    IShellView2 : public IShellView
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetView( 
            /* [out][in] */ SHELLVIEWID *pvid,
            /* [in] */ ULONG uView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateViewWindow2( 
            /* [in] */ LPSV2CVW2_PARAMS lpParams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HandleRename( 
            /* [in] */ LPCITEMIDLIST pidlNew) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectAndPositionItem( 
            /* [in] */ LPCITEMIDLIST pidlItem,
            /* [in] */ UINT uFlags,
            /* [in] */ POINT *ppt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellView2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellView2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellView2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellView2 * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            IShellView2 * This,
            /* [out] */ HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            IShellView2 * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( STDMETHODCALLTYPE *TranslateAccelerator )( 
            IShellView2 * This,
            /* [in] */ MSG *pmsg);
        
        HRESULT ( STDMETHODCALLTYPE *EnableModeless )( 
            IShellView2 * This,
            /* [in] */ BOOL fEnable);
        
        HRESULT ( STDMETHODCALLTYPE *UIActivate )( 
            IShellView2 * This,
            /* [in] */ UINT uState);
        
        HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IShellView2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateViewWindow )( 
            IShellView2 * This,
            /* [in] */ IShellView *psvPrevious,
            /* [in] */ LPCFOLDERSETTINGS pfs,
            /* [in] */ IShellBrowser *psb,
            /* [out] */ RECT *prcView,
            /* [out] */ HWND *phWnd);
        
        HRESULT ( STDMETHODCALLTYPE *DestroyViewWindow )( 
            IShellView2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentInfo )( 
            IShellView2 * This,
            /* [out] */ LPFOLDERSETTINGS pfs);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *AddPropertySheetPages )( 
            IShellView2 * This,
            /* [in] */ DWORD dwReserved,
            /* [in] */ LPFNSVADDPROPSHEETPAGE pfn,
            /* [in] */ LPARAM lparam);
        
        HRESULT ( STDMETHODCALLTYPE *SaveViewState )( 
            IShellView2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SelectItem )( 
            IShellView2 * This,
            /* [in] */ LPCITEMIDLIST pidlItem,
            /* [in] */ SVSIF uFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemObject )( 
            IShellView2 * This,
            /* [in] */ UINT uItem,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetView )( 
            IShellView2 * This,
            /* [out][in] */ SHELLVIEWID *pvid,
            /* [in] */ ULONG uView);
        
        HRESULT ( STDMETHODCALLTYPE *CreateViewWindow2 )( 
            IShellView2 * This,
            /* [in] */ LPSV2CVW2_PARAMS lpParams);
        
        HRESULT ( STDMETHODCALLTYPE *HandleRename )( 
            IShellView2 * This,
            /* [in] */ LPCITEMIDLIST pidlNew);
        
        HRESULT ( STDMETHODCALLTYPE *SelectAndPositionItem )( 
            IShellView2 * This,
            /* [in] */ LPCITEMIDLIST pidlItem,
            /* [in] */ UINT uFlags,
            /* [in] */ POINT *ppt);
        
        END_INTERFACE
    } IShellView2Vtbl;

    interface IShellView2
    {
        CONST_VTBL struct IShellView2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellView2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellView2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellView2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellView2_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IShellView2_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IShellView2_TranslateAccelerator(This,pmsg)	\
    (This)->lpVtbl -> TranslateAccelerator(This,pmsg)

#define IShellView2_EnableModeless(This,fEnable)	\
    (This)->lpVtbl -> EnableModeless(This,fEnable)

#define IShellView2_UIActivate(This,uState)	\
    (This)->lpVtbl -> UIActivate(This,uState)

#define IShellView2_Refresh(This)	\
    (This)->lpVtbl -> Refresh(This)

#define IShellView2_CreateViewWindow(This,psvPrevious,pfs,psb,prcView,phWnd)	\
    (This)->lpVtbl -> CreateViewWindow(This,psvPrevious,pfs,psb,prcView,phWnd)

#define IShellView2_DestroyViewWindow(This)	\
    (This)->lpVtbl -> DestroyViewWindow(This)

#define IShellView2_GetCurrentInfo(This,pfs)	\
    (This)->lpVtbl -> GetCurrentInfo(This,pfs)

#define IShellView2_AddPropertySheetPages(This,dwReserved,pfn,lparam)	\
    (This)->lpVtbl -> AddPropertySheetPages(This,dwReserved,pfn,lparam)

#define IShellView2_SaveViewState(This)	\
    (This)->lpVtbl -> SaveViewState(This)

#define IShellView2_SelectItem(This,pidlItem,uFlags)	\
    (This)->lpVtbl -> SelectItem(This,pidlItem,uFlags)

#define IShellView2_GetItemObject(This,uItem,riid,ppv)	\
    (This)->lpVtbl -> GetItemObject(This,uItem,riid,ppv)


#define IShellView2_GetView(This,pvid,uView)	\
    (This)->lpVtbl -> GetView(This,pvid,uView)

#define IShellView2_CreateViewWindow2(This,lpParams)	\
    (This)->lpVtbl -> CreateViewWindow2(This,lpParams)

#define IShellView2_HandleRename(This,pidlNew)	\
    (This)->lpVtbl -> HandleRename(This,pidlNew)

#define IShellView2_SelectAndPositionItem(This,pidlItem,uFlags,ppt)	\
    (This)->lpVtbl -> SelectAndPositionItem(This,pidlItem,uFlags,ppt)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IShellView2_GetView_Proxy( 
    IShellView2 * This,
    /* [out][in] */ SHELLVIEWID *pvid,
    /* [in] */ ULONG uView);


void __RPC_STUB IShellView2_GetView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView2_CreateViewWindow2_Proxy( 
    IShellView2 * This,
    /* [in] */ LPSV2CVW2_PARAMS lpParams);


void __RPC_STUB IShellView2_CreateViewWindow2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView2_HandleRename_Proxy( 
    IShellView2 * This,
    /* [in] */ LPCITEMIDLIST pidlNew);


void __RPC_STUB IShellView2_HandleRename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellView2_SelectAndPositionItem_Proxy( 
    IShellView2 * This,
    /* [in] */ LPCITEMIDLIST pidlItem,
    /* [in] */ UINT uFlags,
    /* [in] */ POINT *ppt);


void __RPC_STUB IShellView2_SelectAndPositionItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShellView2_INTERFACE_DEFINED__ */


#ifndef __IFolderView_INTERFACE_DEFINED__
#define __IFolderView_INTERFACE_DEFINED__

/* interface IFolderView */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IFolderView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("cde725b0-ccc9-4519-917e-325d72fab4ce")
    IFolderView : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCurrentViewMode( 
            /* [out][in] */ UINT *pViewMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCurrentViewMode( 
            /* [in] */ UINT ViewMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFolder( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ int iItemIndex,
            /* [out] */ LPITEMIDLIST *ppidl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ItemCount( 
            /* [in] */ UINT uFlags,
            /* [out] */ int *pcItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Items( 
            /* [in] */ UINT uFlags,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSelectionMarkedItem( 
            /* [out] */ int *piItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFocusedItem( 
            /* [out] */ int *piItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemPosition( 
            /* [in] */ LPCITEMIDLIST pidl,
            /* [out] */ POINT *ppt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSpacing( 
            /* [full][out][in] */ POINT *ppt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultSpacing( 
            /* [out] */ POINT *ppt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAutoArrange( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectItem( 
            /* [in] */ int iItem,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectAndPositionItems( 
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [size_is][full][in] */ POINT *apt,
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFolderViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFolderView * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFolderView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFolderView * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentViewMode )( 
            IFolderView * This,
            /* [out][in] */ UINT *pViewMode);
        
        HRESULT ( STDMETHODCALLTYPE *SetCurrentViewMode )( 
            IFolderView * This,
            /* [in] */ UINT ViewMode);
        
        HRESULT ( STDMETHODCALLTYPE *GetFolder )( 
            IFolderView * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *Item )( 
            IFolderView * This,
            /* [in] */ int iItemIndex,
            /* [out] */ LPITEMIDLIST *ppidl);
        
        HRESULT ( STDMETHODCALLTYPE *ItemCount )( 
            IFolderView * This,
            /* [in] */ UINT uFlags,
            /* [out] */ int *pcItems);
        
        HRESULT ( STDMETHODCALLTYPE *Items )( 
            IFolderView * This,
            /* [in] */ UINT uFlags,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        HRESULT ( STDMETHODCALLTYPE *GetSelectionMarkedItem )( 
            IFolderView * This,
            /* [out] */ int *piItem);
        
        HRESULT ( STDMETHODCALLTYPE *GetFocusedItem )( 
            IFolderView * This,
            /* [out] */ int *piItem);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemPosition )( 
            IFolderView * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [out] */ POINT *ppt);
        
        HRESULT ( STDMETHODCALLTYPE *GetSpacing )( 
            IFolderView * This,
            /* [full][out][in] */ POINT *ppt);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultSpacing )( 
            IFolderView * This,
            /* [out] */ POINT *ppt);
        
        HRESULT ( STDMETHODCALLTYPE *GetAutoArrange )( 
            IFolderView * This);
        
        HRESULT ( STDMETHODCALLTYPE *SelectItem )( 
            IFolderView * This,
            /* [in] */ int iItem,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SelectAndPositionItems )( 
            IFolderView * This,
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [size_is][full][in] */ POINT *apt,
            /* [in] */ DWORD dwFlags);
        
        END_INTERFACE
    } IFolderViewVtbl;

    interface IFolderView
    {
        CONST_VTBL struct IFolderViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFolderView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFolderView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFolderView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFolderView_GetCurrentViewMode(This,pViewMode)	\
    (This)->lpVtbl -> GetCurrentViewMode(This,pViewMode)

#define IFolderView_SetCurrentViewMode(This,ViewMode)	\
    (This)->lpVtbl -> SetCurrentViewMode(This,ViewMode)

#define IFolderView_GetFolder(This,riid,ppv)	\
    (This)->lpVtbl -> GetFolder(This,riid,ppv)

#define IFolderView_Item(This,iItemIndex,ppidl)	\
    (This)->lpVtbl -> Item(This,iItemIndex,ppidl)

#define IFolderView_ItemCount(This,uFlags,pcItems)	\
    (This)->lpVtbl -> ItemCount(This,uFlags,pcItems)

#define IFolderView_Items(This,uFlags,riid,ppv)	\
    (This)->lpVtbl -> Items(This,uFlags,riid,ppv)

#define IFolderView_GetSelectionMarkedItem(This,piItem)	\
    (This)->lpVtbl -> GetSelectionMarkedItem(This,piItem)

#define IFolderView_GetFocusedItem(This,piItem)	\
    (This)->lpVtbl -> GetFocusedItem(This,piItem)

#define IFolderView_GetItemPosition(This,pidl,ppt)	\
    (This)->lpVtbl -> GetItemPosition(This,pidl,ppt)

#define IFolderView_GetSpacing(This,ppt)	\
    (This)->lpVtbl -> GetSpacing(This,ppt)

#define IFolderView_GetDefaultSpacing(This,ppt)	\
    (This)->lpVtbl -> GetDefaultSpacing(This,ppt)

#define IFolderView_GetAutoArrange(This)	\
    (This)->lpVtbl -> GetAutoArrange(This)

#define IFolderView_SelectItem(This,iItem,dwFlags)	\
    (This)->lpVtbl -> SelectItem(This,iItem,dwFlags)

#define IFolderView_SelectAndPositionItems(This,cidl,apidl,apt,dwFlags)	\
    (This)->lpVtbl -> SelectAndPositionItems(This,cidl,apidl,apt,dwFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFolderView_GetCurrentViewMode_Proxy( 
    IFolderView * This,
    /* [out][in] */ UINT *pViewMode);


void __RPC_STUB IFolderView_GetCurrentViewMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_SetCurrentViewMode_Proxy( 
    IFolderView * This,
    /* [in] */ UINT ViewMode);


void __RPC_STUB IFolderView_SetCurrentViewMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_GetFolder_Proxy( 
    IFolderView * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppv);


void __RPC_STUB IFolderView_GetFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_Item_Proxy( 
    IFolderView * This,
    /* [in] */ int iItemIndex,
    /* [out] */ LPITEMIDLIST *ppidl);


void __RPC_STUB IFolderView_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_ItemCount_Proxy( 
    IFolderView * This,
    /* [in] */ UINT uFlags,
    /* [out] */ int *pcItems);


void __RPC_STUB IFolderView_ItemCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_Items_Proxy( 
    IFolderView * This,
    /* [in] */ UINT uFlags,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppv);


void __RPC_STUB IFolderView_Items_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_GetSelectionMarkedItem_Proxy( 
    IFolderView * This,
    /* [out] */ int *piItem);


void __RPC_STUB IFolderView_GetSelectionMarkedItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_GetFocusedItem_Proxy( 
    IFolderView * This,
    /* [out] */ int *piItem);


void __RPC_STUB IFolderView_GetFocusedItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_GetItemPosition_Proxy( 
    IFolderView * This,
    /* [in] */ LPCITEMIDLIST pidl,
    /* [out] */ POINT *ppt);


void __RPC_STUB IFolderView_GetItemPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_GetSpacing_Proxy( 
    IFolderView * This,
    /* [full][out][in] */ POINT *ppt);


void __RPC_STUB IFolderView_GetSpacing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_GetDefaultSpacing_Proxy( 
    IFolderView * This,
    /* [out] */ POINT *ppt);


void __RPC_STUB IFolderView_GetDefaultSpacing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_GetAutoArrange_Proxy( 
    IFolderView * This);


void __RPC_STUB IFolderView_GetAutoArrange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_SelectItem_Proxy( 
    IFolderView * This,
    /* [in] */ int iItem,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IFolderView_SelectItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderView_SelectAndPositionItems_Proxy( 
    IFolderView * This,
    /* [in] */ UINT cidl,
    /* [size_is][in] */ LPCITEMIDLIST *apidl,
    /* [size_is][full][in] */ POINT *apt,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IFolderView_SelectAndPositionItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFolderView_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0200 */
/* [local] */ 

#define SID_SFolderView IID_IFolderView    // folder view, usuaally IFolderView
#ifdef _FIX_ENABLEMODELESS_CONFLICT
#undef    EnableModeless 
#endif


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0200_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0200_v0_0_s_ifspec;

#ifndef __IFolderFilterSite_INTERFACE_DEFINED__
#define __IFolderFilterSite_INTERFACE_DEFINED__

/* interface IFolderFilterSite */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IFolderFilterSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C0A651F5-B48B-11d2-B5ED-006097C686F6")
    IFolderFilterSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetFilter( 
            /* [in] */ IUnknown *punk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFolderFilterSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFolderFilterSite * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFolderFilterSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFolderFilterSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetFilter )( 
            IFolderFilterSite * This,
            /* [in] */ IUnknown *punk);
        
        END_INTERFACE
    } IFolderFilterSiteVtbl;

    interface IFolderFilterSite
    {
        CONST_VTBL struct IFolderFilterSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFolderFilterSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFolderFilterSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFolderFilterSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFolderFilterSite_SetFilter(This,punk)	\
    (This)->lpVtbl -> SetFilter(This,punk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFolderFilterSite_SetFilter_Proxy( 
    IFolderFilterSite * This,
    /* [in] */ IUnknown *punk);


void __RPC_STUB IFolderFilterSite_SetFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFolderFilterSite_INTERFACE_DEFINED__ */


#ifndef __IFolderFilter_INTERFACE_DEFINED__
#define __IFolderFilter_INTERFACE_DEFINED__

/* interface IFolderFilter */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IFolderFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9CC22886-DC8E-11d2-B1D0-00C04F8EEB3E")
    IFolderFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShouldShow( 
            /* [in] */ IShellFolder *psf,
            /* [in] */ LPCITEMIDLIST pidlFolder,
            /* [in] */ LPCITEMIDLIST pidlItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumFlags( 
            /* [in] */ IShellFolder *psf,
            /* [in] */ LPCITEMIDLIST pidlFolder,
            /* [in] */ HWND *phwnd,
            /* [out] */ DWORD *pgrfFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFolderFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFolderFilter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFolderFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFolderFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *ShouldShow )( 
            IFolderFilter * This,
            /* [in] */ IShellFolder *psf,
            /* [in] */ LPCITEMIDLIST pidlFolder,
            /* [in] */ LPCITEMIDLIST pidlItem);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnumFlags )( 
            IFolderFilter * This,
            /* [in] */ IShellFolder *psf,
            /* [in] */ LPCITEMIDLIST pidlFolder,
            /* [in] */ HWND *phwnd,
            /* [out] */ DWORD *pgrfFlags);
        
        END_INTERFACE
    } IFolderFilterVtbl;

    interface IFolderFilter
    {
        CONST_VTBL struct IFolderFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFolderFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFolderFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFolderFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFolderFilter_ShouldShow(This,psf,pidlFolder,pidlItem)	\
    (This)->lpVtbl -> ShouldShow(This,psf,pidlFolder,pidlItem)

#define IFolderFilter_GetEnumFlags(This,psf,pidlFolder,phwnd,pgrfFlags)	\
    (This)->lpVtbl -> GetEnumFlags(This,psf,pidlFolder,phwnd,pgrfFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFolderFilter_ShouldShow_Proxy( 
    IFolderFilter * This,
    /* [in] */ IShellFolder *psf,
    /* [in] */ LPCITEMIDLIST pidlFolder,
    /* [in] */ LPCITEMIDLIST pidlItem);


void __RPC_STUB IFolderFilter_ShouldShow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFolderFilter_GetEnumFlags_Proxy( 
    IFolderFilter * This,
    /* [in] */ IShellFolder *psf,
    /* [in] */ LPCITEMIDLIST pidlFolder,
    /* [in] */ HWND *phwnd,
    /* [out] */ DWORD *pgrfFlags);


void __RPC_STUB IFolderFilter_GetEnumFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFolderFilter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0202 */
/* [local] */ 

#define SBSP_DEFBROWSER         0x0000
#define SBSP_SAMEBROWSER        0x0001
#define SBSP_NEWBROWSER         0x0002
#define SBSP_DEFMODE            0x0000
#define SBSP_OPENMODE           0x0010
#define SBSP_EXPLOREMODE        0x0020
#define SBSP_HELPMODE           0x0040 // IEUNIX : Help window uses this.
#define SBSP_NOTRANSFERHIST     0x0080
#define SBSP_ABSOLUTE           0x0000
#define SBSP_RELATIVE           0x1000
#define SBSP_PARENT             0x2000
#define SBSP_NAVIGATEBACK       0x4000
#define SBSP_NAVIGATEFORWARD    0x8000
#define SBSP_ALLOW_AUTONAVIGATE 0x10000
#define SBSP_NOAUTOSELECT       0x04000000
#define SBSP_WRITENOHISTORY     0x08000000
#define SBSP_REDIRECT                     0x40000000
#define SBSP_INITIATEDBYHLINKFRAME        0x80000000
#define FCW_STATUS      0x0001
#define FCW_TOOLBAR     0x0002
#define FCW_TREE        0x0003
#define FCW_INTERNETBAR 0x0006
#define FCW_PROGRESS    0x0008
#define FCT_MERGE       0x0001
#define FCT_CONFIGABLE  0x0002
#define FCT_ADDTOEND    0x0004
#ifdef _NEVER_
typedef LPARAM LPTBBUTTONSB;

#else //!_NEVER_
#include <commctrl.h>
typedef LPTBBUTTON LPTBBUTTONSB;
#endif //_NEVER_


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0202_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0202_v0_0_s_ifspec;

#ifndef __IShellBrowser_INTERFACE_DEFINED__
#define __IShellBrowser_INTERFACE_DEFINED__

/* interface IShellBrowser */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IShellBrowser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214E2-0000-0000-C000-000000000046")
    IShellBrowser : public IOleWindow
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InsertMenusSB( 
            /* [in] */ HMENU hmenuShared,
            /* [out][in] */ LPOLEMENUGROUPWIDTHS lpMenuWidths) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMenuSB( 
            /* [in] */ HMENU hmenuShared,
            /* [in] */ HOLEMENU holemenuRes,
            /* [in] */ HWND hwndActiveObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveMenusSB( 
            /* [in] */ HMENU hmenuShared) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStatusTextSB( 
            /* [unique][in] */ LPCOLESTR pszStatusText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableModelessSB( 
            /* [in] */ BOOL fEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TranslateAcceleratorSB( 
            /* [in] */ MSG *pmsg,
            /* [in] */ WORD wID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BrowseObject( 
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ UINT wFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetViewStateStream( 
            /* [in] */ DWORD grfMode,
            /* [out] */ IStream **ppStrm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetControlWindow( 
            /* [in] */ UINT id,
            /* [out] */ HWND *phwnd) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SendControlMsg( 
            /* [in] */ UINT id,
            /* [in] */ UINT uMsg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [in] */ LRESULT *pret) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryActiveShellView( 
            /* [out] */ IShellView **ppshv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnViewWindowActive( 
            /* [in] */ IShellView *pshv) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetToolbarItems( 
            /* [in] */ LPTBBUTTONSB lpButtons,
            /* [in] */ UINT nButtons,
            /* [in] */ UINT uFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellBrowserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellBrowser * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellBrowser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellBrowser * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            IShellBrowser * This,
            /* [out] */ HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            IShellBrowser * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( STDMETHODCALLTYPE *InsertMenusSB )( 
            IShellBrowser * This,
            /* [in] */ HMENU hmenuShared,
            /* [out][in] */ LPOLEMENUGROUPWIDTHS lpMenuWidths);
        
        HRESULT ( STDMETHODCALLTYPE *SetMenuSB )( 
            IShellBrowser * This,
            /* [in] */ HMENU hmenuShared,
            /* [in] */ HOLEMENU holemenuRes,
            /* [in] */ HWND hwndActiveObject);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveMenusSB )( 
            IShellBrowser * This,
            /* [in] */ HMENU hmenuShared);
        
        HRESULT ( STDMETHODCALLTYPE *SetStatusTextSB )( 
            IShellBrowser * This,
            /* [unique][in] */ LPCOLESTR pszStatusText);
        
        HRESULT ( STDMETHODCALLTYPE *EnableModelessSB )( 
            IShellBrowser * This,
            /* [in] */ BOOL fEnable);
        
        HRESULT ( STDMETHODCALLTYPE *TranslateAcceleratorSB )( 
            IShellBrowser * This,
            /* [in] */ MSG *pmsg,
            /* [in] */ WORD wID);
        
        HRESULT ( STDMETHODCALLTYPE *BrowseObject )( 
            IShellBrowser * This,
            /* [in] */ LPCITEMIDLIST pidl,
            /* [in] */ UINT wFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetViewStateStream )( 
            IShellBrowser * This,
            /* [in] */ DWORD grfMode,
            /* [out] */ IStream **ppStrm);
        
        HRESULT ( STDMETHODCALLTYPE *GetControlWindow )( 
            IShellBrowser * This,
            /* [in] */ UINT id,
            /* [out] */ HWND *phwnd);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SendControlMsg )( 
            IShellBrowser * This,
            /* [in] */ UINT id,
            /* [in] */ UINT uMsg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            /* [in] */ LRESULT *pret);
        
        HRESULT ( STDMETHODCALLTYPE *QueryActiveShellView )( 
            IShellBrowser * This,
            /* [out] */ IShellView **ppshv);
        
        HRESULT ( STDMETHODCALLTYPE *OnViewWindowActive )( 
            IShellBrowser * This,
            /* [in] */ IShellView *pshv);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetToolbarItems )( 
            IShellBrowser * This,
            /* [in] */ LPTBBUTTONSB lpButtons,
            /* [in] */ UINT nButtons,
            /* [in] */ UINT uFlags);
        
        END_INTERFACE
    } IShellBrowserVtbl;

    interface IShellBrowser
    {
        CONST_VTBL struct IShellBrowserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellBrowser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellBrowser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellBrowser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellBrowser_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IShellBrowser_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IShellBrowser_InsertMenusSB(This,hmenuShared,lpMenuWidths)	\
    (This)->lpVtbl -> InsertMenusSB(This,hmenuShared,lpMenuWidths)

#define IShellBrowser_SetMenuSB(This,hmenuShared,holemenuRes,hwndActiveObject)	\
    (This)->lpVtbl -> SetMenuSB(This,hmenuShared,holemenuRes,hwndActiveObject)

#define IShellBrowser_RemoveMenusSB(This,hmenuShared)	\
    (This)->lpVtbl -> RemoveMenusSB(This,hmenuShared)

#define IShellBrowser_SetStatusTextSB(This,pszStatusText)	\
    (This)->lpVtbl -> SetStatusTextSB(This,pszStatusText)

#define IShellBrowser_EnableModelessSB(This,fEnable)	\
    (This)->lpVtbl -> EnableModelessSB(This,fEnable)

#define IShellBrowser_TranslateAcceleratorSB(This,pmsg,wID)	\
    (This)->lpVtbl -> TranslateAcceleratorSB(This,pmsg,wID)

#define IShellBrowser_BrowseObject(This,pidl,wFlags)	\
    (This)->lpVtbl -> BrowseObject(This,pidl,wFlags)

#define IShellBrowser_GetViewStateStream(This,grfMode,ppStrm)	\
    (This)->lpVtbl -> GetViewStateStream(This,grfMode,ppStrm)

#define IShellBrowser_GetControlWindow(This,id,phwnd)	\
    (This)->lpVtbl -> GetControlWindow(This,id,phwnd)

#define IShellBrowser_SendControlMsg(This,id,uMsg,wParam,lParam,pret)	\
    (This)->lpVtbl -> SendControlMsg(This,id,uMsg,wParam,lParam,pret)

#define IShellBrowser_QueryActiveShellView(This,ppshv)	\
    (This)->lpVtbl -> QueryActiveShellView(This,ppshv)

#define IShellBrowser_OnViewWindowActive(This,pshv)	\
    (This)->lpVtbl -> OnViewWindowActive(This,pshv)

#define IShellBrowser_SetToolbarItems(This,lpButtons,nButtons,uFlags)	\
    (This)->lpVtbl -> SetToolbarItems(This,lpButtons,nButtons,uFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IShellBrowser_InsertMenusSB_Proxy( 
    IShellBrowser * This,
    /* [in] */ HMENU hmenuShared,
    /* [out][in] */ LPOLEMENUGROUPWIDTHS lpMenuWidths);


void __RPC_STUB IShellBrowser_InsertMenusSB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_SetMenuSB_Proxy( 
    IShellBrowser * This,
    /* [in] */ HMENU hmenuShared,
    /* [in] */ HOLEMENU holemenuRes,
    /* [in] */ HWND hwndActiveObject);


void __RPC_STUB IShellBrowser_SetMenuSB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_RemoveMenusSB_Proxy( 
    IShellBrowser * This,
    /* [in] */ HMENU hmenuShared);


void __RPC_STUB IShellBrowser_RemoveMenusSB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_SetStatusTextSB_Proxy( 
    IShellBrowser * This,
    /* [unique][in] */ LPCOLESTR pszStatusText);


void __RPC_STUB IShellBrowser_SetStatusTextSB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_EnableModelessSB_Proxy( 
    IShellBrowser * This,
    /* [in] */ BOOL fEnable);


void __RPC_STUB IShellBrowser_EnableModelessSB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_TranslateAcceleratorSB_Proxy( 
    IShellBrowser * This,
    /* [in] */ MSG *pmsg,
    /* [in] */ WORD wID);


void __RPC_STUB IShellBrowser_TranslateAcceleratorSB_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_BrowseObject_Proxy( 
    IShellBrowser * This,
    /* [in] */ LPCITEMIDLIST pidl,
    /* [in] */ UINT wFlags);


void __RPC_STUB IShellBrowser_BrowseObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_GetViewStateStream_Proxy( 
    IShellBrowser * This,
    /* [in] */ DWORD grfMode,
    /* [out] */ IStream **ppStrm);


void __RPC_STUB IShellBrowser_GetViewStateStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_GetControlWindow_Proxy( 
    IShellBrowser * This,
    /* [in] */ UINT id,
    /* [out] */ HWND *phwnd);


void __RPC_STUB IShellBrowser_GetControlWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IShellBrowser_SendControlMsg_Proxy( 
    IShellBrowser * This,
    /* [in] */ UINT id,
    /* [in] */ UINT uMsg,
    /* [in] */ WPARAM wParam,
    /* [in] */ LPARAM lParam,
    /* [in] */ LRESULT *pret);


void __RPC_STUB IShellBrowser_SendControlMsg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_QueryActiveShellView_Proxy( 
    IShellBrowser * This,
    /* [out] */ IShellView **ppshv);


void __RPC_STUB IShellBrowser_QueryActiveShellView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellBrowser_OnViewWindowActive_Proxy( 
    IShellBrowser * This,
    /* [in] */ IShellView *pshv);


void __RPC_STUB IShellBrowser_OnViewWindowActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IShellBrowser_SetToolbarItems_Proxy( 
    IShellBrowser * This,
    /* [in] */ LPTBBUTTONSB lpButtons,
    /* [in] */ UINT nButtons,
    /* [in] */ UINT uFlags);


void __RPC_STUB IShellBrowser_SetToolbarItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShellBrowser_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0203 */
/* [local] */ 

typedef IShellBrowser *LPSHELLBROWSER;



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0203_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0203_v0_0_s_ifspec;

#ifndef __IProfferService_INTERFACE_DEFINED__
#define __IProfferService_INTERFACE_DEFINED__

/* interface IProfferService */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IProfferService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("cb728b20-f786-11ce-92ad-00aa00a74cd0")
    IProfferService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProfferService( 
            /* [in] */ REFGUID rguidService,
            /* [in] */ IServiceProvider *psp,
            /* [out] */ DWORD *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevokeService( 
            /* [in] */ DWORD dwCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProfferServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProfferService * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProfferService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProfferService * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProfferService )( 
            IProfferService * This,
            /* [in] */ REFGUID rguidService,
            /* [in] */ IServiceProvider *psp,
            /* [out] */ DWORD *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *RevokeService )( 
            IProfferService * This,
            /* [in] */ DWORD dwCookie);
        
        END_INTERFACE
    } IProfferServiceVtbl;

    interface IProfferService
    {
        CONST_VTBL struct IProfferServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProfferService_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProfferService_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProfferService_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProfferService_ProfferService(This,rguidService,psp,pdwCookie)	\
    (This)->lpVtbl -> ProfferService(This,rguidService,psp,pdwCookie)

#define IProfferService_RevokeService(This,dwCookie)	\
    (This)->lpVtbl -> RevokeService(This,dwCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IProfferService_ProfferService_Proxy( 
    IProfferService * This,
    /* [in] */ REFGUID rguidService,
    /* [in] */ IServiceProvider *psp,
    /* [out] */ DWORD *pdwCookie);


void __RPC_STUB IProfferService_ProfferService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProfferService_RevokeService_Proxy( 
    IProfferService * This,
    /* [in] */ DWORD dwCookie);


void __RPC_STUB IProfferService_RevokeService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IProfferService_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0204 */
/* [local] */ 

#define SID_SProfferService IID_IProfferService    // nearest service that you can proffer to
typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0204_0001
    {	PUIFNF_DEFAULT	= 0,
	PUIFNF_MNEMONIC	= 0x1
    } 	PROPERTYUI_NAME_FLAGS;

typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0204_0002
    {	PUIF_DEFAULT	= 0,
	PUIF_RIGHTALIGN	= 0x1,
	PUIF_NOLABELININFOTIP	= 0x2
    } 	PROPERTYUI_FLAGS;

typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0204_0003
    {	PUIFFDF_DEFAULT	= 0,
	PUIFFDF_RIGHTTOLEFT	= 0x1,
	PUIFFDF_SHORTFORMAT	= 0x2,
	PUIFFDF_NOTIME	= 0x4,
	PUIFFDF_FRIENDLYDATE	= 0x8,
	PUIFFDF_NOUNITS	= 0x10
    } 	PROPERTYUI_FORMAT_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0204_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0204_v0_0_s_ifspec;

#ifndef __IPropertyUI_INTERFACE_DEFINED__
#define __IPropertyUI_INTERFACE_DEFINED__

/* interface IPropertyUI */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IPropertyUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("757a7d9f-919a-4118-99d7-dbb208c8cc66")
    IPropertyUI : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ParsePropertyName( 
            /* [in] */ LPCWSTR pszName,
            /* [out] */ FMTID *pfmtid,
            /* [out] */ PROPID *ppid,
            /* [out][in] */ ULONG *pchEaten) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCannonicalName( 
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [size_is][out] */ LPWSTR pwszText,
            /* [in] */ DWORD cchText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplayName( 
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [in] */ PROPERTYUI_NAME_FLAGS flags,
            /* [size_is][out] */ LPWSTR pwszText,
            /* [in] */ DWORD cchText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPropertyDescription( 
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [size_is][out] */ LPWSTR pwszText,
            /* [in] */ DWORD cchText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultWidth( 
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [out] */ ULONG *pcxChars) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFlags( 
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [out] */ PROPERTYUI_FLAGS *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FormatForDisplay( 
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [in] */ const PROPVARIANT *pvar,
            /* [in] */ PROPERTYUI_FORMAT_FLAGS flags,
            /* [size_is][out] */ LPWSTR pwszText,
            /* [in] */ DWORD cchText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHelpInfo( 
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [size_is][out] */ LPWSTR pwszHelpFile,
            /* [in] */ DWORD cch,
            /* [out] */ UINT *puHelpID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPropertyUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPropertyUI * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPropertyUI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPropertyUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *ParsePropertyName )( 
            IPropertyUI * This,
            /* [in] */ LPCWSTR pszName,
            /* [out] */ FMTID *pfmtid,
            /* [out] */ PROPID *ppid,
            /* [out][in] */ ULONG *pchEaten);
        
        HRESULT ( STDMETHODCALLTYPE *GetCannonicalName )( 
            IPropertyUI * This,
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [size_is][out] */ LPWSTR pwszText,
            /* [in] */ DWORD cchText);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayName )( 
            IPropertyUI * This,
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [in] */ PROPERTYUI_NAME_FLAGS flags,
            /* [size_is][out] */ LPWSTR pwszText,
            /* [in] */ DWORD cchText);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyDescription )( 
            IPropertyUI * This,
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [size_is][out] */ LPWSTR pwszText,
            /* [in] */ DWORD cchText);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultWidth )( 
            IPropertyUI * This,
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [out] */ ULONG *pcxChars);
        
        HRESULT ( STDMETHODCALLTYPE *GetFlags )( 
            IPropertyUI * This,
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [out] */ PROPERTYUI_FLAGS *pFlags);
        
        HRESULT ( STDMETHODCALLTYPE *FormatForDisplay )( 
            IPropertyUI * This,
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [in] */ const PROPVARIANT *pvar,
            /* [in] */ PROPERTYUI_FORMAT_FLAGS flags,
            /* [size_is][out] */ LPWSTR pwszText,
            /* [in] */ DWORD cchText);
        
        HRESULT ( STDMETHODCALLTYPE *GetHelpInfo )( 
            IPropertyUI * This,
            /* [in] */ REFFMTID fmtid,
            /* [in] */ PROPID pid,
            /* [size_is][out] */ LPWSTR pwszHelpFile,
            /* [in] */ DWORD cch,
            /* [out] */ UINT *puHelpID);
        
        END_INTERFACE
    } IPropertyUIVtbl;

    interface IPropertyUI
    {
        CONST_VTBL struct IPropertyUIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPropertyUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPropertyUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPropertyUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPropertyUI_ParsePropertyName(This,pszName,pfmtid,ppid,pchEaten)	\
    (This)->lpVtbl -> ParsePropertyName(This,pszName,pfmtid,ppid,pchEaten)

#define IPropertyUI_GetCannonicalName(This,fmtid,pid,pwszText,cchText)	\
    (This)->lpVtbl -> GetCannonicalName(This,fmtid,pid,pwszText,cchText)

#define IPropertyUI_GetDisplayName(This,fmtid,pid,flags,pwszText,cchText)	\
    (This)->lpVtbl -> GetDisplayName(This,fmtid,pid,flags,pwszText,cchText)

#define IPropertyUI_GetPropertyDescription(This,fmtid,pid,pwszText,cchText)	\
    (This)->lpVtbl -> GetPropertyDescription(This,fmtid,pid,pwszText,cchText)

#define IPropertyUI_GetDefaultWidth(This,fmtid,pid,pcxChars)	\
    (This)->lpVtbl -> GetDefaultWidth(This,fmtid,pid,pcxChars)

#define IPropertyUI_GetFlags(This,fmtid,pid,pFlags)	\
    (This)->lpVtbl -> GetFlags(This,fmtid,pid,pFlags)

#define IPropertyUI_FormatForDisplay(This,fmtid,pid,pvar,flags,pwszText,cchText)	\
    (This)->lpVtbl -> FormatForDisplay(This,fmtid,pid,pvar,flags,pwszText,cchText)

#define IPropertyUI_GetHelpInfo(This,fmtid,pid,pwszHelpFile,cch,puHelpID)	\
    (This)->lpVtbl -> GetHelpInfo(This,fmtid,pid,pwszHelpFile,cch,puHelpID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPropertyUI_ParsePropertyName_Proxy( 
    IPropertyUI * This,
    /* [in] */ LPCWSTR pszName,
    /* [out] */ FMTID *pfmtid,
    /* [out] */ PROPID *ppid,
    /* [out][in] */ ULONG *pchEaten);


void __RPC_STUB IPropertyUI_ParsePropertyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPropertyUI_GetCannonicalName_Proxy( 
    IPropertyUI * This,
    /* [in] */ REFFMTID fmtid,
    /* [in] */ PROPID pid,
    /* [size_is][out] */ LPWSTR pwszText,
    /* [in] */ DWORD cchText);


void __RPC_STUB IPropertyUI_GetCannonicalName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPropertyUI_GetDisplayName_Proxy( 
    IPropertyUI * This,
    /* [in] */ REFFMTID fmtid,
    /* [in] */ PROPID pid,
    /* [in] */ PROPERTYUI_NAME_FLAGS flags,
    /* [size_is][out] */ LPWSTR pwszText,
    /* [in] */ DWORD cchText);


void __RPC_STUB IPropertyUI_GetDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPropertyUI_GetPropertyDescription_Proxy( 
    IPropertyUI * This,
    /* [in] */ REFFMTID fmtid,
    /* [in] */ PROPID pid,
    /* [size_is][out] */ LPWSTR pwszText,
    /* [in] */ DWORD cchText);


void __RPC_STUB IPropertyUI_GetPropertyDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPropertyUI_GetDefaultWidth_Proxy( 
    IPropertyUI * This,
    /* [in] */ REFFMTID fmtid,
    /* [in] */ PROPID pid,
    /* [out] */ ULONG *pcxChars);


void __RPC_STUB IPropertyUI_GetDefaultWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPropertyUI_GetFlags_Proxy( 
    IPropertyUI * This,
    /* [in] */ REFFMTID fmtid,
    /* [in] */ PROPID pid,
    /* [out] */ PROPERTYUI_FLAGS *pFlags);


void __RPC_STUB IPropertyUI_GetFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPropertyUI_FormatForDisplay_Proxy( 
    IPropertyUI * This,
    /* [in] */ REFFMTID fmtid,
    /* [in] */ PROPID pid,
    /* [in] */ const PROPVARIANT *pvar,
    /* [in] */ PROPERTYUI_FORMAT_FLAGS flags,
    /* [size_is][out] */ LPWSTR pwszText,
    /* [in] */ DWORD cchText);


void __RPC_STUB IPropertyUI_FormatForDisplay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPropertyUI_GetHelpInfo_Proxy( 
    IPropertyUI * This,
    /* [in] */ REFFMTID fmtid,
    /* [in] */ PROPID pid,
    /* [size_is][out] */ LPWSTR pwszHelpFile,
    /* [in] */ DWORD cch,
    /* [out] */ UINT *puHelpID);


void __RPC_STUB IPropertyUI_GetHelpInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPropertyUI_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0205 */
/* [local] */ 

#if (_WIN32_IE >= 0x0500)


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0205_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0205_v0_0_s_ifspec;

#ifndef __ICategoryProvider_INTERFACE_DEFINED__
#define __ICategoryProvider_INTERFACE_DEFINED__

/* interface ICategoryProvider */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_ICategoryProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9af64809-5864-4c26-a720-c1f78c086ee3")
    ICategoryProvider : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CanCategorizeOnSCID( 
            SHCOLUMNID *pscid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDefaultCategory( 
            GUID *pguid,
            SHCOLUMNID *pscid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCategoryForSCID( 
            SHCOLUMNID *pscid,
            GUID *pguid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE EnumCategories( 
            IEnumGUID **penum) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCategoryName( 
            GUID *pguid,
            LPWSTR pszName,
            UINT cch) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateCategory( 
            GUID *pguid,
            REFIID riid,
            /* [iid_is] */ void **ppv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICategoryProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICategoryProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICategoryProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICategoryProvider * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CanCategorizeOnSCID )( 
            ICategoryProvider * This,
            SHCOLUMNID *pscid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDefaultCategory )( 
            ICategoryProvider * This,
            GUID *pguid,
            SHCOLUMNID *pscid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCategoryForSCID )( 
            ICategoryProvider * This,
            SHCOLUMNID *pscid,
            GUID *pguid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *EnumCategories )( 
            ICategoryProvider * This,
            IEnumGUID **penum);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCategoryName )( 
            ICategoryProvider * This,
            GUID *pguid,
            LPWSTR pszName,
            UINT cch);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CreateCategory )( 
            ICategoryProvider * This,
            GUID *pguid,
            REFIID riid,
            /* [iid_is] */ void **ppv);
        
        END_INTERFACE
    } ICategoryProviderVtbl;

    interface ICategoryProvider
    {
        CONST_VTBL struct ICategoryProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICategoryProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICategoryProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICategoryProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICategoryProvider_CanCategorizeOnSCID(This,pscid)	\
    (This)->lpVtbl -> CanCategorizeOnSCID(This,pscid)

#define ICategoryProvider_GetDefaultCategory(This,pguid,pscid)	\
    (This)->lpVtbl -> GetDefaultCategory(This,pguid,pscid)

#define ICategoryProvider_GetCategoryForSCID(This,pscid,pguid)	\
    (This)->lpVtbl -> GetCategoryForSCID(This,pscid,pguid)

#define ICategoryProvider_EnumCategories(This,penum)	\
    (This)->lpVtbl -> EnumCategories(This,penum)

#define ICategoryProvider_GetCategoryName(This,pguid,pszName,cch)	\
    (This)->lpVtbl -> GetCategoryName(This,pguid,pszName,cch)

#define ICategoryProvider_CreateCategory(This,pguid,riid,ppv)	\
    (This)->lpVtbl -> CreateCategory(This,pguid,riid,ppv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategoryProvider_CanCategorizeOnSCID_Proxy( 
    ICategoryProvider * This,
    SHCOLUMNID *pscid);


void __RPC_STUB ICategoryProvider_CanCategorizeOnSCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategoryProvider_GetDefaultCategory_Proxy( 
    ICategoryProvider * This,
    GUID *pguid,
    SHCOLUMNID *pscid);


void __RPC_STUB ICategoryProvider_GetDefaultCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategoryProvider_GetCategoryForSCID_Proxy( 
    ICategoryProvider * This,
    SHCOLUMNID *pscid,
    GUID *pguid);


void __RPC_STUB ICategoryProvider_GetCategoryForSCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategoryProvider_EnumCategories_Proxy( 
    ICategoryProvider * This,
    IEnumGUID **penum);


void __RPC_STUB ICategoryProvider_EnumCategories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategoryProvider_GetCategoryName_Proxy( 
    ICategoryProvider * This,
    GUID *pguid,
    LPWSTR pszName,
    UINT cch);


void __RPC_STUB ICategoryProvider_GetCategoryName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategoryProvider_CreateCategory_Proxy( 
    ICategoryProvider * This,
    GUID *pguid,
    REFIID riid,
    /* [iid_is] */ void **ppv);


void __RPC_STUB ICategoryProvider_CreateCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICategoryProvider_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0206 */
/* [local] */ 

typedef /* [public][public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0206_0001
    {	CATINFO_NORMAL	= 0,
	CATINFO_COLLAPSED	= 0x1,
	CATINFO_HIDDEN	= 0x2
    } 	CATEGORYINFO_FLAGS;

typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_shobjidl_0206_0002
    {	CATSORT_DEFAULT	= 0,
	CATSORT_NAME	= 0x1
    } 	CATSORT_FLAGS;

typedef /* [public][public] */ struct __MIDL___MIDL_itf_shobjidl_0206_0003
    {
    CATEGORYINFO_FLAGS cif;
    WCHAR wszName[ 260 ];
    } 	CATEGORY_INFO;



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0206_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0206_v0_0_s_ifspec;

#ifndef __ICategorizer_INTERFACE_DEFINED__
#define __ICategorizer_INTERFACE_DEFINED__

/* interface ICategorizer */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_ICategorizer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a3b14589-9174-49a8-89a3-06a1ae2b9ba7")
    ICategorizer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetDescription( 
            LPWSTR pszDesc,
            UINT cch) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCategory( 
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [size_is][out][in] */ DWORD *rgCategoryIds) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCategoryInfo( 
            DWORD dwCategoryId,
            CATEGORY_INFO *pci) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CompareCategory( 
            CATSORT_FLAGS csfFlags,
            DWORD dwCategoryId1,
            DWORD dwCategoryId2) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICategorizerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICategorizer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICategorizer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICategorizer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            ICategorizer * This,
            LPWSTR pszDesc,
            UINT cch);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            ICategorizer * This,
            /* [in] */ UINT cidl,
            /* [size_is][in] */ LPCITEMIDLIST *apidl,
            /* [size_is][out][in] */ DWORD *rgCategoryIds);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCategoryInfo )( 
            ICategorizer * This,
            DWORD dwCategoryId,
            CATEGORY_INFO *pci);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CompareCategory )( 
            ICategorizer * This,
            CATSORT_FLAGS csfFlags,
            DWORD dwCategoryId1,
            DWORD dwCategoryId2);
        
        END_INTERFACE
    } ICategorizerVtbl;

    interface ICategorizer
    {
        CONST_VTBL struct ICategorizerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICategorizer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICategorizer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICategorizer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICategorizer_GetDescription(This,pszDesc,cch)	\
    (This)->lpVtbl -> GetDescription(This,pszDesc,cch)

#define ICategorizer_GetCategory(This,cidl,apidl,rgCategoryIds)	\
    (This)->lpVtbl -> GetCategory(This,cidl,apidl,rgCategoryIds)

#define ICategorizer_GetCategoryInfo(This,dwCategoryId,pci)	\
    (This)->lpVtbl -> GetCategoryInfo(This,dwCategoryId,pci)

#define ICategorizer_CompareCategory(This,csfFlags,dwCategoryId1,dwCategoryId2)	\
    (This)->lpVtbl -> CompareCategory(This,csfFlags,dwCategoryId1,dwCategoryId2)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategorizer_GetDescription_Proxy( 
    ICategorizer * This,
    LPWSTR pszDesc,
    UINT cch);


void __RPC_STUB ICategorizer_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategorizer_GetCategory_Proxy( 
    ICategorizer * This,
    /* [in] */ UINT cidl,
    /* [size_is][in] */ LPCITEMIDLIST *apidl,
    /* [size_is][out][in] */ DWORD *rgCategoryIds);


void __RPC_STUB ICategorizer_GetCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategorizer_GetCategoryInfo_Proxy( 
    ICategorizer * This,
    DWORD dwCategoryId,
    CATEGORY_INFO *pci);


void __RPC_STUB ICategorizer_GetCategoryInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ICategorizer_CompareCategory_Proxy( 
    ICategorizer * This,
    CATSORT_FLAGS csfFlags,
    DWORD dwCategoryId1,
    DWORD dwCategoryId2);


void __RPC_STUB ICategorizer_CompareCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICategorizer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0207 */
/* [local] */ 

#endif // (_WIN32_IE >= 0x0500)
#ifdef UNICODE
#define IShellLink      IShellLinkW
#else
#define IShellLink      IShellLinkA
#endif
typedef /* [public] */ 
enum __MIDL___MIDL_itf_shobjidl_0207_0001
    {	SLR_NO_UI	= 0x1,
	SLR_ANY_MATCH	= 0x2,
	SLR_UPDATE	= 0x4,
	SLR_NOUPDATE	= 0x8,
	SLR_NOSEARCH	= 0x10,
	SLR_NOTRACK	= 0x20,
	SLR_NOLINKINFO	= 0x40,
	SLR_INVOKE_MSI	= 0x80,
	SLR_NO_UI_WITH_MSG_PUMP	= 0x101
    } 	SLR_FLAGS;

typedef /* [public] */ 
enum __MIDL___MIDL_itf_shobjidl_0207_0002
    {	SLGP_SHORTPATH	= 0x1,
	SLGP_UNCPRIORITY	= 0x2,
	SLGP_RAWPATH	= 0x4
    } 	SLGP_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0207_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0207_v0_0_s_ifspec;

#ifndef __IShellLinkA_INTERFACE_DEFINED__
#define __IShellLinkA_INTERFACE_DEFINED__

/* interface IShellLinkA */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IShellLinkA;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214EE-0000-0000-C000-000000000046")
    IShellLinkA : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [size_is][out] */ LPSTR pszFile,
            /* [in] */ int cch,
            /* [full][out][in] */ WIN32_FIND_DATAA *pfd,
            /* [in] */ DWORD fFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIDList( 
            /* [out] */ LPITEMIDLIST *ppidl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIDList( 
            /* [in] */ LPCITEMIDLIST pidl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [size_is][out] */ LPSTR pszName,
            /* [in] */ int cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [in] */ LPCSTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWorkingDirectory( 
            /* [size_is][out] */ LPSTR pszDir,
            /* [in] */ int cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWorkingDirectory( 
            /* [in] */ LPCSTR pszDir) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetArguments( 
            /* [size_is][out] */ LPSTR pszArgs,
            /* [in] */ int cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetArguments( 
            /* [in] */ LPCSTR pszArgs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHotkey( 
            /* [out] */ WORD *pwHotkey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHotkey( 
            /* [in] */ WORD wHotkey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetShowCmd( 
            /* [out] */ int *piShowCmd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetShowCmd( 
            /* [in] */ int iShowCmd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIconLocation( 
            /* [size_is][out] */ LPSTR pszIconPath,
            /* [in] */ int cch,
            /* [out] */ int *piIcon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIconLocation( 
            /* [in] */ LPCSTR pszIconPath,
            /* [in] */ int iIcon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRelativePath( 
            /* [in] */ LPCSTR pszPathRel,
            /* [in] */ DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resolve( 
            /* [in] */ HWND hwnd,
            /* [in] */ DWORD fFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPath( 
            /* [in] */ LPCSTR pszFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellLinkAVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellLinkA * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellLinkA * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellLinkA * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IShellLinkA * This,
            /* [size_is][out] */ LPSTR pszFile,
            /* [in] */ int cch,
            /* [full][out][in] */ WIN32_FIND_DATAA *pfd,
            /* [in] */ DWORD fFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDList )( 
            IShellLinkA * This,
            /* [out] */ LPITEMIDLIST *ppidl);
        
        HRESULT ( STDMETHODCALLTYPE *SetIDList )( 
            IShellLinkA * This,
            /* [in] */ LPCITEMIDLIST pidl);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IShellLinkA * This,
            /* [size_is][out] */ LPSTR pszName,
            /* [in] */ int cch);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IShellLinkA * This,
            /* [in] */ LPCSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetWorkingDirectory )( 
            IShellLinkA * This,
            /* [size_is][out] */ LPSTR pszDir,
            /* [in] */ int cch);
        
        HRESULT ( STDMETHODCALLTYPE *SetWorkingDirectory )( 
            IShellLinkA * This,
            /* [in] */ LPCSTR pszDir);
        
        HRESULT ( STDMETHODCALLTYPE *GetArguments )( 
            IShellLinkA * This,
            /* [size_is][out] */ LPSTR pszArgs,
            /* [in] */ int cch);
        
        HRESULT ( STDMETHODCALLTYPE *SetArguments )( 
            IShellLinkA * This,
            /* [in] */ LPCSTR pszArgs);
        
        HRESULT ( STDMETHODCALLTYPE *GetHotkey )( 
            IShellLinkA * This,
            /* [out] */ WORD *pwHotkey);
        
        HRESULT ( STDMETHODCALLTYPE *SetHotkey )( 
            IShellLinkA * This,
            /* [in] */ WORD wHotkey);
        
        HRESULT ( STDMETHODCALLTYPE *GetShowCmd )( 
            IShellLinkA * This,
            /* [out] */ int *piShowCmd);
        
        HRESULT ( STDMETHODCALLTYPE *SetShowCmd )( 
            IShellLinkA * This,
            /* [in] */ int iShowCmd);
        
        HRESULT ( STDMETHODCALLTYPE *GetIconLocation )( 
            IShellLinkA * This,
            /* [size_is][out] */ LPSTR pszIconPath,
            /* [in] */ int cch,
            /* [out] */ int *piIcon);
        
        HRESULT ( STDMETHODCALLTYPE *SetIconLocation )( 
            IShellLinkA * This,
            /* [in] */ LPCSTR pszIconPath,
            /* [in] */ int iIcon);
        
        HRESULT ( STDMETHODCALLTYPE *SetRelativePath )( 
            IShellLinkA * This,
            /* [in] */ LPCSTR pszPathRel,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE *Resolve )( 
            IShellLinkA * This,
            /* [in] */ HWND hwnd,
            /* [in] */ DWORD fFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetPath )( 
            IShellLinkA * This,
            /* [in] */ LPCSTR pszFile);
        
        END_INTERFACE
    } IShellLinkAVtbl;

    interface IShellLinkA
    {
        CONST_VTBL struct IShellLinkAVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellLinkA_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellLinkA_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellLinkA_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellLinkA_GetPath(This,pszFile,cch,pfd,fFlags)	\
    (This)->lpVtbl -> GetPath(This,pszFile,cch,pfd,fFlags)

#define IShellLinkA_GetIDList(This,ppidl)	\
    (This)->lpVtbl -> GetIDList(This,ppidl)

#define IShellLinkA_SetIDList(This,pidl)	\
    (This)->lpVtbl -> SetIDList(This,pidl)

#define IShellLinkA_GetDescription(This,pszName,cch)	\
    (This)->lpVtbl -> GetDescription(This,pszName,cch)

#define IShellLinkA_SetDescription(This,pszName)	\
    (This)->lpVtbl -> SetDescription(This,pszName)

#define IShellLinkA_GetWorkingDirectory(This,pszDir,cch)	\
    (This)->lpVtbl -> GetWorkingDirectory(This,pszDir,cch)

#define IShellLinkA_SetWorkingDirectory(This,pszDir)	\
    (This)->lpVtbl -> SetWorkingDirectory(This,pszDir)

#define IShellLinkA_GetArguments(This,pszArgs,cch)	\
    (This)->lpVtbl -> GetArguments(This,pszArgs,cch)

#define IShellLinkA_SetArguments(This,pszArgs)	\
    (This)->lpVtbl -> SetArguments(This,pszArgs)

#define IShellLinkA_GetHotkey(This,pwHotkey)	\
    (This)->lpVtbl -> GetHotkey(This,pwHotkey)

#define IShellLinkA_SetHotkey(This,wHotkey)	\
    (This)->lpVtbl -> SetHotkey(This,wHotkey)

#define IShellLinkA_GetShowCmd(This,piShowCmd)	\
    (This)->lpVtbl -> GetShowCmd(This,piShowCmd)

#define IShellLinkA_SetShowCmd(This,iShowCmd)	\
    (This)->lpVtbl -> SetShowCmd(This,iShowCmd)

#define IShellLinkA_GetIconLocation(This,pszIconPath,cch,piIcon)	\
    (This)->lpVtbl -> GetIconLocation(This,pszIconPath,cch,piIcon)

#define IShellLinkA_SetIconLocation(This,pszIconPath,iIcon)	\
    (This)->lpVtbl -> SetIconLocation(This,pszIconPath,iIcon)

#define IShellLinkA_SetRelativePath(This,pszPathRel,dwReserved)	\
    (This)->lpVtbl -> SetRelativePath(This,pszPathRel,dwReserved)

#define IShellLinkA_Resolve(This,hwnd,fFlags)	\
    (This)->lpVtbl -> Resolve(This,hwnd,fFlags)

#define IShellLinkA_SetPath(This,pszFile)	\
    (This)->lpVtbl -> SetPath(This,pszFile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IShellLinkA_GetPath_Proxy( 
    IShellLinkA * This,
    /* [size_is][out] */ LPSTR pszFile,
    /* [in] */ int cch,
    /* [full][out][in] */ WIN32_FIND_DATAA *pfd,
    /* [in] */ DWORD fFlags);


void __RPC_STUB IShellLinkA_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_GetIDList_Proxy( 
    IShellLinkA * This,
    /* [out] */ LPITEMIDLIST *ppidl);


void __RPC_STUB IShellLinkA_GetIDList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_SetIDList_Proxy( 
    IShellLinkA * This,
    /* [in] */ LPCITEMIDLIST pidl);


void __RPC_STUB IShellLinkA_SetIDList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_GetDescription_Proxy( 
    IShellLinkA * This,
    /* [size_is][out] */ LPSTR pszName,
    /* [in] */ int cch);


void __RPC_STUB IShellLinkA_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_SetDescription_Proxy( 
    IShellLinkA * This,
    /* [in] */ LPCSTR pszName);


void __RPC_STUB IShellLinkA_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_GetWorkingDirectory_Proxy( 
    IShellLinkA * This,
    /* [size_is][out] */ LPSTR pszDir,
    /* [in] */ int cch);


void __RPC_STUB IShellLinkA_GetWorkingDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_SetWorkingDirectory_Proxy( 
    IShellLinkA * This,
    /* [in] */ LPCSTR pszDir);


void __RPC_STUB IShellLinkA_SetWorkingDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_GetArguments_Proxy( 
    IShellLinkA * This,
    /* [size_is][out] */ LPSTR pszArgs,
    /* [in] */ int cch);


void __RPC_STUB IShellLinkA_GetArguments_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_SetArguments_Proxy( 
    IShellLinkA * This,
    /* [in] */ LPCSTR pszArgs);


void __RPC_STUB IShellLinkA_SetArguments_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_GetHotkey_Proxy( 
    IShellLinkA * This,
    /* [out] */ WORD *pwHotkey);


void __RPC_STUB IShellLinkA_GetHotkey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_SetHotkey_Proxy( 
    IShellLinkA * This,
    /* [in] */ WORD wHotkey);


void __RPC_STUB IShellLinkA_SetHotkey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_GetShowCmd_Proxy( 
    IShellLinkA * This,
    /* [out] */ int *piShowCmd);


void __RPC_STUB IShellLinkA_GetShowCmd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_SetShowCmd_Proxy( 
    IShellLinkA * This,
    /* [in] */ int iShowCmd);


void __RPC_STUB IShellLinkA_SetShowCmd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_GetIconLocation_Proxy( 
    IShellLinkA * This,
    /* [size_is][out] */ LPSTR pszIconPath,
    /* [in] */ int cch,
    /* [out] */ int *piIcon);


void __RPC_STUB IShellLinkA_GetIconLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_SetIconLocation_Proxy( 
    IShellLinkA * This,
    /* [in] */ LPCSTR pszIconPath,
    /* [in] */ int iIcon);


void __RPC_STUB IShellLinkA_SetIconLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_SetRelativePath_Proxy( 
    IShellLinkA * This,
    /* [in] */ LPCSTR pszPathRel,
    /* [in] */ DWORD dwReserved);


void __RPC_STUB IShellLinkA_SetRelativePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_Resolve_Proxy( 
    IShellLinkA * This,
    /* [in] */ HWND hwnd,
    /* [in] */ DWORD fFlags);


void __RPC_STUB IShellLinkA_Resolve_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkA_SetPath_Proxy( 
    IShellLinkA * This,
    /* [in] */ LPCSTR pszFile);


void __RPC_STUB IShellLinkA_SetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShellLinkA_INTERFACE_DEFINED__ */


#ifndef __IShellLinkW_INTERFACE_DEFINED__
#define __IShellLinkW_INTERFACE_DEFINED__

/* interface IShellLinkW */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IShellLinkW;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214F9-0000-0000-C000-000000000046")
    IShellLinkW : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [size_is][out] */ LPWSTR pszFile,
            /* [in] */ int cch,
            /* [full][out][in] */ WIN32_FIND_DATAW *pfd,
            /* [in] */ DWORD fFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIDList( 
            /* [out] */ LPITEMIDLIST *ppidl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIDList( 
            /* [in] */ LPCITEMIDLIST pidl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [size_is][out] */ LPWSTR pszName,
            int cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [in] */ LPCWSTR pszName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWorkingDirectory( 
            /* [size_is][out] */ LPWSTR pszDir,
            int cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWorkingDirectory( 
            /* [in] */ LPCWSTR pszDir) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetArguments( 
            /* [size_is][out] */ LPWSTR pszArgs,
            int cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetArguments( 
            /* [in] */ LPCWSTR pszArgs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHotkey( 
            /* [out] */ WORD *pwHotkey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHotkey( 
            /* [in] */ WORD wHotkey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetShowCmd( 
            /* [out] */ int *piShowCmd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetShowCmd( 
            /* [in] */ int iShowCmd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIconLocation( 
            /* [size_is][out] */ LPWSTR pszIconPath,
            /* [in] */ int cch,
            /* [out] */ int *piIcon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIconLocation( 
            /* [in] */ LPCWSTR pszIconPath,
            /* [in] */ int iIcon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRelativePath( 
            /* [in] */ LPCWSTR pszPathRel,
            /* [in] */ DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resolve( 
            /* [in] */ HWND hwnd,
            /* [in] */ DWORD fFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPath( 
            /* [in] */ LPCWSTR pszFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellLinkWVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellLinkW * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellLinkW * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellLinkW * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IShellLinkW * This,
            /* [size_is][out] */ LPWSTR pszFile,
            /* [in] */ int cch,
            /* [full][out][in] */ WIN32_FIND_DATAW *pfd,
            /* [in] */ DWORD fFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDList )( 
            IShellLinkW * This,
            /* [out] */ LPITEMIDLIST *ppidl);
        
        HRESULT ( STDMETHODCALLTYPE *SetIDList )( 
            IShellLinkW * This,
            /* [in] */ LPCITEMIDLIST pidl);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IShellLinkW * This,
            /* [size_is][out] */ LPWSTR pszName,
            int cch);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IShellLinkW * This,
            /* [in] */ LPCWSTR pszName);
        
        HRESULT ( STDMETHODCALLTYPE *GetWorkingDirectory )( 
            IShellLinkW * This,
            /* [size_is][out] */ LPWSTR pszDir,
            int cch);
        
        HRESULT ( STDMETHODCALLTYPE *SetWorkingDirectory )( 
            IShellLinkW * This,
            /* [in] */ LPCWSTR pszDir);
        
        HRESULT ( STDMETHODCALLTYPE *GetArguments )( 
            IShellLinkW * This,
            /* [size_is][out] */ LPWSTR pszArgs,
            int cch);
        
        HRESULT ( STDMETHODCALLTYPE *SetArguments )( 
            IShellLinkW * This,
            /* [in] */ LPCWSTR pszArgs);
        
        HRESULT ( STDMETHODCALLTYPE *GetHotkey )( 
            IShellLinkW * This,
            /* [out] */ WORD *pwHotkey);
        
        HRESULT ( STDMETHODCALLTYPE *SetHotkey )( 
            IShellLinkW * This,
            /* [in] */ WORD wHotkey);
        
        HRESULT ( STDMETHODCALLTYPE *GetShowCmd )( 
            IShellLinkW * This,
            /* [out] */ int *piShowCmd);
        
        HRESULT ( STDMETHODCALLTYPE *SetShowCmd )( 
            IShellLinkW * This,
            /* [in] */ int iShowCmd);
        
        HRESULT ( STDMETHODCALLTYPE *GetIconLocation )( 
            IShellLinkW * This,
            /* [size_is][out] */ LPWSTR pszIconPath,
            /* [in] */ int cch,
            /* [out] */ int *piIcon);
        
        HRESULT ( STDMETHODCALLTYPE *SetIconLocation )( 
            IShellLinkW * This,
            /* [in] */ LPCWSTR pszIconPath,
            /* [in] */ int iIcon);
        
        HRESULT ( STDMETHODCALLTYPE *SetRelativePath )( 
            IShellLinkW * This,
            /* [in] */ LPCWSTR pszPathRel,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE *Resolve )( 
            IShellLinkW * This,
            /* [in] */ HWND hwnd,
            /* [in] */ DWORD fFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetPath )( 
            IShellLinkW * This,
            /* [in] */ LPCWSTR pszFile);
        
        END_INTERFACE
    } IShellLinkWVtbl;

    interface IShellLinkW
    {
        CONST_VTBL struct IShellLinkWVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellLinkW_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellLinkW_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellLinkW_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellLinkW_GetPath(This,pszFile,cch,pfd,fFlags)	\
    (This)->lpVtbl -> GetPath(This,pszFile,cch,pfd,fFlags)

#define IShellLinkW_GetIDList(This,ppidl)	\
    (This)->lpVtbl -> GetIDList(This,ppidl)

#define IShellLinkW_SetIDList(This,pidl)	\
    (This)->lpVtbl -> SetIDList(This,pidl)

#define IShellLinkW_GetDescription(This,pszName,cch)	\
    (This)->lpVtbl -> GetDescription(This,pszName,cch)

#define IShellLinkW_SetDescription(This,pszName)	\
    (This)->lpVtbl -> SetDescription(This,pszName)

#define IShellLinkW_GetWorkingDirectory(This,pszDir,cch)	\
    (This)->lpVtbl -> GetWorkingDirectory(This,pszDir,cch)

#define IShellLinkW_SetWorkingDirectory(This,pszDir)	\
    (This)->lpVtbl -> SetWorkingDirectory(This,pszDir)

#define IShellLinkW_GetArguments(This,pszArgs,cch)	\
    (This)->lpVtbl -> GetArguments(This,pszArgs,cch)

#define IShellLinkW_SetArguments(This,pszArgs)	\
    (This)->lpVtbl -> SetArguments(This,pszArgs)

#define IShellLinkW_GetHotkey(This,pwHotkey)	\
    (This)->lpVtbl -> GetHotkey(This,pwHotkey)

#define IShellLinkW_SetHotkey(This,wHotkey)	\
    (This)->lpVtbl -> SetHotkey(This,wHotkey)

#define IShellLinkW_GetShowCmd(This,piShowCmd)	\
    (This)->lpVtbl -> GetShowCmd(This,piShowCmd)

#define IShellLinkW_SetShowCmd(This,iShowCmd)	\
    (This)->lpVtbl -> SetShowCmd(This,iShowCmd)

#define IShellLinkW_GetIconLocation(This,pszIconPath,cch,piIcon)	\
    (This)->lpVtbl -> GetIconLocation(This,pszIconPath,cch,piIcon)

#define IShellLinkW_SetIconLocation(This,pszIconPath,iIcon)	\
    (This)->lpVtbl -> SetIconLocation(This,pszIconPath,iIcon)

#define IShellLinkW_SetRelativePath(This,pszPathRel,dwReserved)	\
    (This)->lpVtbl -> SetRelativePath(This,pszPathRel,dwReserved)

#define IShellLinkW_Resolve(This,hwnd,fFlags)	\
    (This)->lpVtbl -> Resolve(This,hwnd,fFlags)

#define IShellLinkW_SetPath(This,pszFile)	\
    (This)->lpVtbl -> SetPath(This,pszFile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IShellLinkW_GetPath_Proxy( 
    IShellLinkW * This,
    /* [size_is][out] */ LPWSTR pszFile,
    /* [in] */ int cch,
    /* [full][out][in] */ WIN32_FIND_DATAW *pfd,
    /* [in] */ DWORD fFlags);


void __RPC_STUB IShellLinkW_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_GetIDList_Proxy( 
    IShellLinkW * This,
    /* [out] */ LPITEMIDLIST *ppidl);


void __RPC_STUB IShellLinkW_GetIDList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_SetIDList_Proxy( 
    IShellLinkW * This,
    /* [in] */ LPCITEMIDLIST pidl);


void __RPC_STUB IShellLinkW_SetIDList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_GetDescription_Proxy( 
    IShellLinkW * This,
    /* [size_is][out] */ LPWSTR pszName,
    int cch);


void __RPC_STUB IShellLinkW_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_SetDescription_Proxy( 
    IShellLinkW * This,
    /* [in] */ LPCWSTR pszName);


void __RPC_STUB IShellLinkW_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_GetWorkingDirectory_Proxy( 
    IShellLinkW * This,
    /* [size_is][out] */ LPWSTR pszDir,
    int cch);


void __RPC_STUB IShellLinkW_GetWorkingDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_SetWorkingDirectory_Proxy( 
    IShellLinkW * This,
    /* [in] */ LPCWSTR pszDir);


void __RPC_STUB IShellLinkW_SetWorkingDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_GetArguments_Proxy( 
    IShellLinkW * This,
    /* [size_is][out] */ LPWSTR pszArgs,
    int cch);


void __RPC_STUB IShellLinkW_GetArguments_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_SetArguments_Proxy( 
    IShellLinkW * This,
    /* [in] */ LPCWSTR pszArgs);


void __RPC_STUB IShellLinkW_SetArguments_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_GetHotkey_Proxy( 
    IShellLinkW * This,
    /* [out] */ WORD *pwHotkey);


void __RPC_STUB IShellLinkW_GetHotkey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_SetHotkey_Proxy( 
    IShellLinkW * This,
    /* [in] */ WORD wHotkey);


void __RPC_STUB IShellLinkW_SetHotkey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_GetShowCmd_Proxy( 
    IShellLinkW * This,
    /* [out] */ int *piShowCmd);


void __RPC_STUB IShellLinkW_GetShowCmd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_SetShowCmd_Proxy( 
    IShellLinkW * This,
    /* [in] */ int iShowCmd);


void __RPC_STUB IShellLinkW_SetShowCmd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_GetIconLocation_Proxy( 
    IShellLinkW * This,
    /* [size_is][out] */ LPWSTR pszIconPath,
    /* [in] */ int cch,
    /* [out] */ int *piIcon);


void __RPC_STUB IShellLinkW_GetIconLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_SetIconLocation_Proxy( 
    IShellLinkW * This,
    /* [in] */ LPCWSTR pszIconPath,
    /* [in] */ int iIcon);


void __RPC_STUB IShellLinkW_SetIconLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_SetRelativePath_Proxy( 
    IShellLinkW * This,
    /* [in] */ LPCWSTR pszPathRel,
    /* [in] */ DWORD dwReserved);


void __RPC_STUB IShellLinkW_SetRelativePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_Resolve_Proxy( 
    IShellLinkW * This,
    /* [in] */ HWND hwnd,
    /* [in] */ DWORD fFlags);


void __RPC_STUB IShellLinkW_Resolve_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellLinkW_SetPath_Proxy( 
    IShellLinkW * This,
    /* [in] */ LPCWSTR pszFile);


void __RPC_STUB IShellLinkW_SetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShellLinkW_INTERFACE_DEFINED__ */


#ifndef __IActionProgressDialog_INTERFACE_DEFINED__
#define __IActionProgressDialog_INTERFACE_DEFINED__

/* interface IActionProgressDialog */
/* [unique][helpstring][uuid][object] */ 

/* [v1_enum] */ 
enum __MIDL_IActionProgressDialog_0001
    {	SPINITF_NORMAL	= 0,
	SPINITF_MODAL	= 0x1,
	SPINITF_NOMINIMIZE	= 0x8
    } ;
typedef DWORD SPINITF;


EXTERN_C const IID IID_IActionProgressDialog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49ff1172-eadc-446d-9285-156453a6431c")
    IActionProgressDialog : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ SPINITF flags,
            /* [string][in] */ LPCWSTR pszTitle,
            /* [string][in] */ LPCWSTR pszCancel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActionProgressDialogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActionProgressDialog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActionProgressDialog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActionProgressDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IActionProgressDialog * This,
            /* [in] */ SPINITF flags,
            /* [string][in] */ LPCWSTR pszTitle,
            /* [string][in] */ LPCWSTR pszCancel);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IActionProgressDialog * This);
        
        END_INTERFACE
    } IActionProgressDialogVtbl;

    interface IActionProgressDialog
    {
        CONST_VTBL struct IActionProgressDialogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActionProgressDialog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActionProgressDialog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActionProgressDialog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActionProgressDialog_Initialize(This,flags,pszTitle,pszCancel)	\
    (This)->lpVtbl -> Initialize(This,flags,pszTitle,pszCancel)

#define IActionProgressDialog_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IActionProgressDialog_Initialize_Proxy( 
    IActionProgressDialog * This,
    /* [in] */ SPINITF flags,
    /* [string][in] */ LPCWSTR pszTitle,
    /* [string][in] */ LPCWSTR pszCancel);


void __RPC_STUB IActionProgressDialog_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IActionProgressDialog_Stop_Proxy( 
    IActionProgressDialog * This);


void __RPC_STUB IActionProgressDialog_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActionProgressDialog_INTERFACE_DEFINED__ */


#ifndef __IHWEventHandler_INTERFACE_DEFINED__
#define __IHWEventHandler_INTERFACE_DEFINED__

/* interface IHWEventHandler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHWEventHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C1FB73D0-EC3A-4ba2-B512-8CDB9187B6D1")
    IHWEventHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [string][in] */ LPCWSTR pszParams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HandleEvent( 
            /* [string][in] */ LPCWSTR pszDeviceID,
            /* [string][in] */ LPCWSTR pszAltDeviceID,
            /* [string][in] */ LPCWSTR pszEventType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HandleEventWithContent( 
            /* [string][in] */ LPCWSTR pszDeviceID,
            /* [string][in] */ LPCWSTR pszAltDeviceID,
            /* [string][in] */ LPCWSTR pszEventType,
            /* [string][in] */ LPCWSTR pszContentTypeHandler,
            /* [in] */ IDataObject *pdataobject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHWEventHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHWEventHandler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHWEventHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHWEventHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IHWEventHandler * This,
            /* [string][in] */ LPCWSTR pszParams);
        
        HRESULT ( STDMETHODCALLTYPE *HandleEvent )( 
            IHWEventHandler * This,
            /* [string][in] */ LPCWSTR pszDeviceID,
            /* [string][in] */ LPCWSTR pszAltDeviceID,
            /* [string][in] */ LPCWSTR pszEventType);
        
        HRESULT ( STDMETHODCALLTYPE *HandleEventWithContent )( 
            IHWEventHandler * This,
            /* [string][in] */ LPCWSTR pszDeviceID,
            /* [string][in] */ LPCWSTR pszAltDeviceID,
            /* [string][in] */ LPCWSTR pszEventType,
            /* [string][in] */ LPCWSTR pszContentTypeHandler,
            /* [in] */ IDataObject *pdataobject);
        
        END_INTERFACE
    } IHWEventHandlerVtbl;

    interface IHWEventHandler
    {
        CONST_VTBL struct IHWEventHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHWEventHandler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHWEventHandler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHWEventHandler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHWEventHandler_Initialize(This,pszParams)	\
    (This)->lpVtbl -> Initialize(This,pszParams)

#define IHWEventHandler_HandleEvent(This,pszDeviceID,pszAltDeviceID,pszEventType)	\
    (This)->lpVtbl -> HandleEvent(This,pszDeviceID,pszAltDeviceID,pszEventType)

#define IHWEventHandler_HandleEventWithContent(This,pszDeviceID,pszAltDeviceID,pszEventType,pszContentTypeHandler,pdataobject)	\
    (This)->lpVtbl -> HandleEventWithContent(This,pszDeviceID,pszAltDeviceID,pszEventType,pszContentTypeHandler,pdataobject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHWEventHandler_Initialize_Proxy( 
    IHWEventHandler * This,
    /* [string][in] */ LPCWSTR pszParams);


void __RPC_STUB IHWEventHandler_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHWEventHandler_HandleEvent_Proxy( 
    IHWEventHandler * This,
    /* [string][in] */ LPCWSTR pszDeviceID,
    /* [string][in] */ LPCWSTR pszAltDeviceID,
    /* [string][in] */ LPCWSTR pszEventType);


void __RPC_STUB IHWEventHandler_HandleEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHWEventHandler_HandleEventWithContent_Proxy( 
    IHWEventHandler * This,
    /* [string][in] */ LPCWSTR pszDeviceID,
    /* [string][in] */ LPCWSTR pszAltDeviceID,
    /* [string][in] */ LPCWSTR pszEventType,
    /* [string][in] */ LPCWSTR pszContentTypeHandler,
    /* [in] */ IDataObject *pdataobject);


void __RPC_STUB IHWEventHandler_HandleEventWithContent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHWEventHandler_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0211 */
/* [local] */ 

#define ARCONTENT_AUTORUNINF         0x00000002
#define ARCONTENT_AUDIOCD         0x00000004
#define ARCONTENT_DVDMOVIE        0x00000008
#define ARCONTENT_BLANKCD         0x00000010
#define ARCONTENT_BLANKDVD        0x00000020
#define ARCONTENT_UNKNOWNCONTENT     0x00000040
#define ARCONTENT_AUTOPLAYPIX     0x00000080
#define ARCONTENT_AUTOPLAYMUSIC      0x00000100
#define ARCONTENT_AUTOPLAYVIDEO      0x00000200


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0211_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0211_v0_0_s_ifspec;

#ifndef __IQueryCancelAutoPlay_INTERFACE_DEFINED__
#define __IQueryCancelAutoPlay_INTERFACE_DEFINED__

/* interface IQueryCancelAutoPlay */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IQueryCancelAutoPlay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DDEFE873-6997-4e68-BE26-39B633ADBE12")
    IQueryCancelAutoPlay : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AllowAutoPlay( 
            /* [string][in] */ LPCWSTR pszPath,
            /* [in] */ DWORD dwContentType,
            /* [string][in] */ LPCWSTR pszLabel,
            /* [in] */ DWORD dwSerialNumber) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IQueryCancelAutoPlayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IQueryCancelAutoPlay * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IQueryCancelAutoPlay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IQueryCancelAutoPlay * This);
        
        HRESULT ( STDMETHODCALLTYPE *AllowAutoPlay )( 
            IQueryCancelAutoPlay * This,
            /* [string][in] */ LPCWSTR pszPath,
            /* [in] */ DWORD dwContentType,
            /* [string][in] */ LPCWSTR pszLabel,
            /* [in] */ DWORD dwSerialNumber);
        
        END_INTERFACE
    } IQueryCancelAutoPlayVtbl;

    interface IQueryCancelAutoPlay
    {
        CONST_VTBL struct IQueryCancelAutoPlayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IQueryCancelAutoPlay_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IQueryCancelAutoPlay_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IQueryCancelAutoPlay_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IQueryCancelAutoPlay_AllowAutoPlay(This,pszPath,dwContentType,pszLabel,dwSerialNumber)	\
    (This)->lpVtbl -> AllowAutoPlay(This,pszPath,dwContentType,pszLabel,dwSerialNumber)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IQueryCancelAutoPlay_AllowAutoPlay_Proxy( 
    IQueryCancelAutoPlay * This,
    /* [string][in] */ LPCWSTR pszPath,
    /* [in] */ DWORD dwContentType,
    /* [string][in] */ LPCWSTR pszLabel,
    /* [in] */ DWORD dwSerialNumber);


void __RPC_STUB IQueryCancelAutoPlay_AllowAutoPlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IQueryCancelAutoPlay_INTERFACE_DEFINED__ */


#ifndef __IActionProgress_INTERFACE_DEFINED__
#define __IActionProgress_INTERFACE_DEFINED__

/* interface IActionProgress */
/* [unique][helpstring][uuid][object] */ 

/* [v1_enum] */ 
enum __MIDL_IActionProgress_0001
    {	SPBEGINF_NORMAL	= 0,
	SPBEGINF_AUTOTIME	= 0x2,
	SPBEGINF_NOPROGRESSBAR	= 0x10,
	SPBEGINF_MARQUEEPROGRESS	= 0x20
    } ;
typedef DWORD SPBEGINF;

typedef /* [v1_enum] */ 
enum _SPACTION
    {	SPACTION_NONE	= 0,
	SPACTION_MOVING	= SPACTION_NONE + 1,
	SPACTION_COPYING	= SPACTION_MOVING + 1,
	SPACTION_RECYCLING	= SPACTION_COPYING + 1,
	SPACTION_APPLYINGATTRIBS	= SPACTION_RECYCLING + 1,
	SPACTION_DOWNLOADING	= SPACTION_APPLYINGATTRIBS + 1,
	SPACTION_SEARCHING_INTERNET	= SPACTION_DOWNLOADING + 1,
	SPACTION_CALCULATING	= SPACTION_SEARCHING_INTERNET + 1,
	SPACTION_UPLOADING	= SPACTION_CALCULATING + 1,
	SPACTION_SEARCHING_FILES	= SPACTION_UPLOADING + 1
    } 	SPACTION;

typedef /* [v1_enum] */ 
enum _SPTEXT
    {	SPTEXT_ACTIONDESCRIPTION	= 1,
	SPTEXT_ACTIONDETAIL	= SPTEXT_ACTIONDESCRIPTION + 1
    } 	SPTEXT;


EXTERN_C const IID IID_IActionProgress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49ff1173-eadc-446d-9285-156453a6431c")
    IActionProgress : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Begin( 
            /* [in] */ SPACTION action,
            /* [in] */ SPBEGINF flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateProgress( 
            /* [in] */ ULONGLONG ulCompleted,
            /* [in] */ ULONGLONG ulTotal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateText( 
            /* [in] */ SPTEXT sptext,
            /* [string][in] */ LPCWSTR pszText,
            /* [in] */ BOOL fMayCompact) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryCancel( 
            /* [out] */ BOOL *pfCancelled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetCancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE End( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IActionProgressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActionProgress * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActionProgress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActionProgress * This);
        
        HRESULT ( STDMETHODCALLTYPE *Begin )( 
            IActionProgress * This,
            /* [in] */ SPACTION action,
            /* [in] */ SPBEGINF flags);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateProgress )( 
            IActionProgress * This,
            /* [in] */ ULONGLONG ulCompleted,
            /* [in] */ ULONGLONG ulTotal);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateText )( 
            IActionProgress * This,
            /* [in] */ SPTEXT sptext,
            /* [string][in] */ LPCWSTR pszText,
            /* [in] */ BOOL fMayCompact);
        
        HRESULT ( STDMETHODCALLTYPE *QueryCancel )( 
            IActionProgress * This,
            /* [out] */ BOOL *pfCancelled);
        
        HRESULT ( STDMETHODCALLTYPE *ResetCancel )( 
            IActionProgress * This);
        
        HRESULT ( STDMETHODCALLTYPE *End )( 
            IActionProgress * This);
        
        END_INTERFACE
    } IActionProgressVtbl;

    interface IActionProgress
    {
        CONST_VTBL struct IActionProgressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActionProgress_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IActionProgress_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IActionProgress_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IActionProgress_Begin(This,action,flags)	\
    (This)->lpVtbl -> Begin(This,action,flags)

#define IActionProgress_UpdateProgress(This,ulCompleted,ulTotal)	\
    (This)->lpVtbl -> UpdateProgress(This,ulCompleted,ulTotal)

#define IActionProgress_UpdateText(This,sptext,pszText,fMayCompact)	\
    (This)->lpVtbl -> UpdateText(This,sptext,pszText,fMayCompact)

#define IActionProgress_QueryCancel(This,pfCancelled)	\
    (This)->lpVtbl -> QueryCancel(This,pfCancelled)

#define IActionProgress_ResetCancel(This)	\
    (This)->lpVtbl -> ResetCancel(This)

#define IActionProgress_End(This)	\
    (This)->lpVtbl -> End(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IActionProgress_Begin_Proxy( 
    IActionProgress * This,
    /* [in] */ SPACTION action,
    /* [in] */ SPBEGINF flags);


void __RPC_STUB IActionProgress_Begin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IActionProgress_UpdateProgress_Proxy( 
    IActionProgress * This,
    /* [in] */ ULONGLONG ulCompleted,
    /* [in] */ ULONGLONG ulTotal);


void __RPC_STUB IActionProgress_UpdateProgress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IActionProgress_UpdateText_Proxy( 
    IActionProgress * This,
    /* [in] */ SPTEXT sptext,
    /* [string][in] */ LPCWSTR pszText,
    /* [in] */ BOOL fMayCompact);


void __RPC_STUB IActionProgress_UpdateText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IActionProgress_QueryCancel_Proxy( 
    IActionProgress * This,
    /* [out] */ BOOL *pfCancelled);


void __RPC_STUB IActionProgress_QueryCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IActionProgress_ResetCancel_Proxy( 
    IActionProgress * This);


void __RPC_STUB IActionProgress_ResetCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IActionProgress_End_Proxy( 
    IActionProgress * This);


void __RPC_STUB IActionProgress_End_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IActionProgress_INTERFACE_DEFINED__ */


#ifndef __IShellExtInit_INTERFACE_DEFINED__
#define __IShellExtInit_INTERFACE_DEFINED__

/* interface IShellExtInit */
/* [unique][local][object][uuid] */ 


EXTERN_C const IID IID_IShellExtInit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214E8-0000-0000-C000-000000000046")
    IShellExtInit : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ LPCITEMIDLIST pidlFolder,
            /* [in] */ IDataObject *pdtobj,
            /* [in] */ HKEY hkeyProgID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellExtInitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellExtInit * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellExtInit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellExtInit * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IShellExtInit * This,
            /* [in] */ LPCITEMIDLIST pidlFolder,
            /* [in] */ IDataObject *pdtobj,
            /* [in] */ HKEY hkeyProgID);
        
        END_INTERFACE
    } IShellExtInitVtbl;

    interface IShellExtInit
    {
        CONST_VTBL struct IShellExtInitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellExtInit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellExtInit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellExtInit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellExtInit_Initialize(This,pidlFolder,pdtobj,hkeyProgID)	\
    (This)->lpVtbl -> Initialize(This,pidlFolder,pdtobj,hkeyProgID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IShellExtInit_Initialize_Proxy( 
    IShellExtInit * This,
    /* [in] */ LPCITEMIDLIST pidlFolder,
    /* [in] */ IDataObject *pdtobj,
    /* [in] */ HKEY hkeyProgID);


void __RPC_STUB IShellExtInit_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShellExtInit_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0214 */
/* [local] */ 

typedef IShellExtInit *LPSHELLEXTINIT;



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0214_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0214_v0_0_s_ifspec;

#ifndef __IShellPropSheetExt_INTERFACE_DEFINED__
#define __IShellPropSheetExt_INTERFACE_DEFINED__

/* interface IShellPropSheetExt */
/* [unique][local][object][uuid] */ 


enum __MIDL_IShellPropSheetExt_0001
    {	EXPPS_FILETYPES	= 0x1
    } ;
typedef UINT EXPPS;


EXTERN_C const IID IID_IShellPropSheetExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214E9-0000-0000-C000-000000000046")
    IShellPropSheetExt : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPages( 
            /* [in] */ LPFNSVADDPROPSHEETPAGE pfnAddPage,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReplacePage( 
            /* [in] */ EXPPS uPageID,
            /* [in] */ LPFNSVADDPROPSHEETPAGE pfnReplaceWith,
            /* [in] */ LPARAM lParam) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellPropSheetExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShellPropSheetExt * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShellPropSheetExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShellPropSheetExt * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPages )( 
            IShellPropSheetExt * This,
            /* [in] */ LPFNSVADDPROPSHEETPAGE pfnAddPage,
            /* [in] */ LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *ReplacePage )( 
            IShellPropSheetExt * This,
            /* [in] */ EXPPS uPageID,
            /* [in] */ LPFNSVADDPROPSHEETPAGE pfnReplaceWith,
            /* [in] */ LPARAM lParam);
        
        END_INTERFACE
    } IShellPropSheetExtVtbl;

    interface IShellPropSheetExt
    {
        CONST_VTBL struct IShellPropSheetExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShellPropSheetExt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShellPropSheetExt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShellPropSheetExt_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShellPropSheetExt_AddPages(This,pfnAddPage,lParam)	\
    (This)->lpVtbl -> AddPages(This,pfnAddPage,lParam)

#define IShellPropSheetExt_ReplacePage(This,uPageID,pfnReplaceWith,lParam)	\
    (This)->lpVtbl -> ReplacePage(This,uPageID,pfnReplaceWith,lParam)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IShellPropSheetExt_AddPages_Proxy( 
    IShellPropSheetExt * This,
    /* [in] */ LPFNSVADDPROPSHEETPAGE pfnAddPage,
    /* [in] */ LPARAM lParam);


void __RPC_STUB IShellPropSheetExt_AddPages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IShellPropSheetExt_ReplacePage_Proxy( 
    IShellPropSheetExt * This,
    /* [in] */ EXPPS uPageID,
    /* [in] */ LPFNSVADDPROPSHEETPAGE pfnReplaceWith,
    /* [in] */ LPARAM lParam);


void __RPC_STUB IShellPropSheetExt_ReplacePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShellPropSheetExt_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0215 */
/* [local] */ 

typedef IShellPropSheetExt *LPSHELLPROPSHEETEXT;



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0215_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0215_v0_0_s_ifspec;

#ifndef __IRemoteComputer_INTERFACE_DEFINED__
#define __IRemoteComputer_INTERFACE_DEFINED__

/* interface IRemoteComputer */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IRemoteComputer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("000214FE-0000-0000-C000-000000000046")
    IRemoteComputer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ LPCWSTR pszMachine,
            /* [in] */ BOOL bEnumerating) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRemoteComputerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRemoteComputer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRemoteComputer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRemoteComputer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IRemoteComputer * This,
            /* [in] */ LPCWSTR pszMachine,
            /* [in] */ BOOL bEnumerating);
        
        END_INTERFACE
    } IRemoteComputerVtbl;

    interface IRemoteComputer
    {
        CONST_VTBL struct IRemoteComputerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRemoteComputer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRemoteComputer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRemoteComputer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRemoteComputer_Initialize(This,pszMachine,bEnumerating)	\
    (This)->lpVtbl -> Initialize(This,pszMachine,bEnumerating)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRemoteComputer_Initialize_Proxy( 
    IRemoteComputer * This,
    /* [in] */ LPCWSTR pszMachine,
    /* [in] */ BOOL bEnumerating);


void __RPC_STUB IRemoteComputer_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRemoteComputer_INTERFACE_DEFINED__ */


#ifndef __IQueryContinue_INTERFACE_DEFINED__
#define __IQueryContinue_INTERFACE_DEFINED__

/* interface IQueryContinue */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IQueryContinue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7307055c-b24a-486b-9f25-163e597a28a9")
    IQueryContinue : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryContinue( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IQueryContinueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IQueryContinue * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IQueryContinue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IQueryContinue * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryContinue )( 
            IQueryContinue * This);
        
        END_INTERFACE
    } IQueryContinueVtbl;

    interface IQueryContinue
    {
        CONST_VTBL struct IQueryContinueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IQueryContinue_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IQueryContinue_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IQueryContinue_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IQueryContinue_QueryContinue(This)	\
    (This)->lpVtbl -> QueryContinue(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IQueryContinue_QueryContinue_Proxy( 
    IQueryContinue * This);


void __RPC_STUB IQueryContinue_QueryContinue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IQueryContinue_INTERFACE_DEFINED__ */


#ifndef __IUserNotification_INTERFACE_DEFINED__
#define __IUserNotification_INTERFACE_DEFINED__

/* interface IUserNotification */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IUserNotification;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ba9711ba-5893-4787-a7e1-41277151550b")
    IUserNotification : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetBalloonInfo( 
            /* [string][in] */ LPCWSTR pszTitle,
            /* [string][in] */ LPCWSTR pszText,
            /* [in] */ DWORD dwInfoFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBalloonRetry( 
            /* [in] */ DWORD dwShowTime,
            /* [in] */ DWORD dwInterval,
            /* [in] */ UINT cRetryCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIconInfo( 
            /* [in] */ HICON hIcon,
            /* [string][in] */ LPCWSTR pszToolTip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Show( 
            /* [in] */ IQueryContinue *pqc,
            /* [in] */ DWORD dwContinuePollInterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PlaySound( 
            /* [string][in] */ LPCWSTR pszSoundName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUserNotificationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUserNotification * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUserNotification * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUserNotification * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetBalloonInfo )( 
            IUserNotification * This,
            /* [string][in] */ LPCWSTR pszTitle,
            /* [string][in] */ LPCWSTR pszText,
            /* [in] */ DWORD dwInfoFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetBalloonRetry )( 
            IUserNotification * This,
            /* [in] */ DWORD dwShowTime,
            /* [in] */ DWORD dwInterval,
            /* [in] */ UINT cRetryCount);
        
        HRESULT ( STDMETHODCALLTYPE *SetIconInfo )( 
            IUserNotification * This,
            /* [in] */ HICON hIcon,
            /* [string][in] */ LPCWSTR pszToolTip);
        
        HRESULT ( STDMETHODCALLTYPE *Show )( 
            IUserNotification * This,
            /* [in] */ IQueryContinue *pqc,
            /* [in] */ DWORD dwContinuePollInterval);
        
        HRESULT ( STDMETHODCALLTYPE *PlaySound )( 
            IUserNotification * This,
            /* [string][in] */ LPCWSTR pszSoundName);
        
        END_INTERFACE
    } IUserNotificationVtbl;

    interface IUserNotification
    {
        CONST_VTBL struct IUserNotificationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUserNotification_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUserNotification_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUserNotification_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUserNotification_SetBalloonInfo(This,pszTitle,pszText,dwInfoFlags)	\
    (This)->lpVtbl -> SetBalloonInfo(This,pszTitle,pszText,dwInfoFlags)

#define IUserNotification_SetBalloonRetry(This,dwShowTime,dwInterval,cRetryCount)	\
    (This)->lpVtbl -> SetBalloonRetry(This,dwShowTime,dwInterval,cRetryCount)

#define IUserNotification_SetIconInfo(This,hIcon,pszToolTip)	\
    (This)->lpVtbl -> SetIconInfo(This,hIcon,pszToolTip)

#define IUserNotification_Show(This,pqc,dwContinuePollInterval)	\
    (This)->lpVtbl -> Show(This,pqc,dwContinuePollInterval)

#define IUserNotification_PlaySound(This,pszSoundName)	\
    (This)->lpVtbl -> PlaySound(This,pszSoundName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IUserNotification_SetBalloonInfo_Proxy( 
    IUserNotification * This,
    /* [string][in] */ LPCWSTR pszTitle,
    /* [string][in] */ LPCWSTR pszText,
    /* [in] */ DWORD dwInfoFlags);


void __RPC_STUB IUserNotification_SetBalloonInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IUserNotification_SetBalloonRetry_Proxy( 
    IUserNotification * This,
    /* [in] */ DWORD dwShowTime,
    /* [in] */ DWORD dwInterval,
    /* [in] */ UINT cRetryCount);


void __RPC_STUB IUserNotification_SetBalloonRetry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IUserNotification_SetIconInfo_Proxy( 
    IUserNotification * This,
    /* [in] */ HICON hIcon,
    /* [string][in] */ LPCWSTR pszToolTip);


void __RPC_STUB IUserNotification_SetIconInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IUserNotification_Show_Proxy( 
    IUserNotification * This,
    /* [in] */ IQueryContinue *pqc,
    /* [in] */ DWORD dwContinuePollInterval);


void __RPC_STUB IUserNotification_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IUserNotification_PlaySound_Proxy( 
    IUserNotification * This,
    /* [string][in] */ LPCWSTR pszSoundName);


void __RPC_STUB IUserNotification_PlaySound_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUserNotification_INTERFACE_DEFINED__ */


#ifndef __IItemNameLimits_INTERFACE_DEFINED__
#define __IItemNameLimits_INTERFACE_DEFINED__

/* interface IItemNameLimits */
/* [object][uuid] */ 


EXTERN_C const IID IID_IItemNameLimits;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1df0d7f1-b267-4d28-8b10-12e23202a5c4")
    IItemNameLimits : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetValidCharacters( 
            /* [out] */ LPWSTR *ppwszValidChars,
            /* [out] */ LPWSTR *ppwszInvalidChars) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxLength( 
            /* [in] */ LPCWSTR pszName,
            /* [out] */ int *piMaxNameLen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IItemNameLimitsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IItemNameLimits * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IItemNameLimits * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IItemNameLimits * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetValidCharacters )( 
            IItemNameLimits * This,
            /* [out] */ LPWSTR *ppwszValidChars,
            /* [out] */ LPWSTR *ppwszInvalidChars);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxLength )( 
            IItemNameLimits * This,
            /* [in] */ LPCWSTR pszName,
            /* [out] */ int *piMaxNameLen);
        
        END_INTERFACE
    } IItemNameLimitsVtbl;

    interface IItemNameLimits
    {
        CONST_VTBL struct IItemNameLimitsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IItemNameLimits_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IItemNameLimits_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IItemNameLimits_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IItemNameLimits_GetValidCharacters(This,ppwszValidChars,ppwszInvalidChars)	\
    (This)->lpVtbl -> GetValidCharacters(This,ppwszValidChars,ppwszInvalidChars)

#define IItemNameLimits_GetMaxLength(This,pszName,piMaxNameLen)	\
    (This)->lpVtbl -> GetMaxLength(This,pszName,piMaxNameLen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IItemNameLimits_GetValidCharacters_Proxy( 
    IItemNameLimits * This,
    /* [out] */ LPWSTR *ppwszValidChars,
    /* [out] */ LPWSTR *ppwszInvalidChars);


void __RPC_STUB IItemNameLimits_GetValidCharacters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IItemNameLimits_GetMaxLength_Proxy( 
    IItemNameLimits * This,
    /* [in] */ LPCWSTR pszName,
    /* [out] */ int *piMaxNameLen);


void __RPC_STUB IItemNameLimits_GetMaxLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IItemNameLimits_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0219 */
/* [local] */ 

#define SNCF_REFRESHLIST 0x00000001  // refresh the list (eg. from F5 or opening a folder)


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0219_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0219_v0_0_s_ifspec;

#ifndef __INetCrawler_INTERFACE_DEFINED__
#define __INetCrawler_INTERFACE_DEFINED__

/* interface INetCrawler */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_INetCrawler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49c929ee-a1b7-4c58-b539-e63be392b6f3")
    INetCrawler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Update( 
            /* [in] */ DWORD dwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetCrawlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INetCrawler * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INetCrawler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INetCrawler * This);
        
        HRESULT ( STDMETHODCALLTYPE *Update )( 
            INetCrawler * This,
            /* [in] */ DWORD dwFlags);
        
        END_INTERFACE
    } INetCrawlerVtbl;

    interface INetCrawler
    {
        CONST_VTBL struct INetCrawlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetCrawler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetCrawler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetCrawler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetCrawler_Update(This,dwFlags)	\
    (This)->lpVtbl -> Update(This,dwFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE INetCrawler_Update_Proxy( 
    INetCrawler * This,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB INetCrawler_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetCrawler_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0220 */
/* [local] */ 

#if (_WIN32_IE >= 0x0400)
#define IEI_PRIORITY_MAX        ITSAT_MAX_PRIORITY
#define IEI_PRIORITY_MIN        ITSAT_MIN_PRIORITY
#define IEIT_PRIORITY_NORMAL     ITSAT_DEFAULT_PRIORITY
#define IEIFLAG_ASYNC       0x0001      // ask the extractor if it supports ASYNC extract (free threaded)
#define IEIFLAG_CACHE       0x0002      // returned from the extractor if it does NOT cache the thumbnail
#define IEIFLAG_ASPECT      0x0004      // passed to the extractor to beg it to render to the aspect ratio of the supplied rect
#define IEIFLAG_OFFLINE     0x0008      // if the extractor shouldn't hit the net to get any content neede for the rendering
#define IEIFLAG_GLEAM       0x0010      // does the image have a gleam ? this will be returned if it does
#define IEIFLAG_SCREEN      0x0020      // render as if for the screen  (this is exlusive with IEIFLAG_ASPECT )
#define IEIFLAG_ORIGSIZE    0x0040      // render to the approx size passed, but crop if neccessary
#define IEIFLAG_NOSTAMP     0x0080      // returned from the extractor if it does NOT want an icon stamp on the thumbnail
#define IEIFLAG_NOBORDER    0x0100      // returned from the extractor if it does NOT want an a border around the thumbnail
#define IEIFLAG_QUALITY     0x0200      // passed to the Extract method to indicate that a slower, higher quality image is desired, re-compute the thumbnail


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0220_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0220_v0_0_s_ifspec;

#ifndef __IExtractImage_INTERFACE_DEFINED__
#define __IExtractImage_INTERFACE_DEFINED__

/* interface IExtractImage */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IExtractImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BB2E617C-0920-11d1-9A0B-00C04FC2D6C1")
    IExtractImage : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLocation( 
            /* [size_is][out] */ LPWSTR pszPathBuffer,
            /* [in] */ DWORD cch,
            /* [unique][out][in] */ DWORD *pdwPriority,
            /* [in] */ const SIZE *prgSize,
            /* [in] */ DWORD dwRecClrDepth,
            /* [in] */ DWORD *pdwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Extract( 
            /* [out] */ HBITMAP *phBmpThumbnail) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExtractImage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExtractImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExtractImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocation )( 
            IExtractImage * This,
            /* [size_is][out] */ LPWSTR pszPathBuffer,
            /* [in] */ DWORD cch,
            /* [unique][out][in] */ DWORD *pdwPriority,
            /* [in] */ const SIZE *prgSize,
            /* [in] */ DWORD dwRecClrDepth,
            /* [in] */ DWORD *pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Extract )( 
            IExtractImage * This,
            /* [out] */ HBITMAP *phBmpThumbnail);
        
        END_INTERFACE
    } IExtractImageVtbl;

    interface IExtractImage
    {
        CONST_VTBL struct IExtractImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractImage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractImage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractImage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractImage_GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)	\
    (This)->lpVtbl -> GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)

#define IExtractImage_Extract(This,phBmpThumbnail)	\
    (This)->lpVtbl -> Extract(This,phBmpThumbnail)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IExtractImage_GetLocation_Proxy( 
    IExtractImage * This,
    /* [size_is][out] */ LPWSTR pszPathBuffer,
    /* [in] */ DWORD cch,
    /* [unique][out][in] */ DWORD *pdwPriority,
    /* [in] */ const SIZE *prgSize,
    /* [in] */ DWORD dwRecClrDepth,
    /* [in] */ DWORD *pdwFlags);


void __RPC_STUB IExtractImage_GetLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IExtractImage_Extract_Proxy( 
    IExtractImage * This,
    /* [out] */ HBITMAP *phBmpThumbnail);


void __RPC_STUB IExtractImage_Extract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractImage_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0221 */
/* [local] */ 

typedef IExtractImage *LPEXTRACTIMAGE;

#endif
#if (_WIN32_IE >= 0x0500)


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0221_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0221_v0_0_s_ifspec;

#ifndef __IExtractImage2_INTERFACE_DEFINED__
#define __IExtractImage2_INTERFACE_DEFINED__

/* interface IExtractImage2 */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IExtractImage2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("953BB1EE-93B4-11d1-98A3-00C04FB687DA")
    IExtractImage2 : public IExtractImage
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDateStamp( 
            /* [out] */ FILETIME *pDateStamp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IExtractImage2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IExtractImage2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IExtractImage2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IExtractImage2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocation )( 
            IExtractImage2 * This,
            /* [size_is][out] */ LPWSTR pszPathBuffer,
            /* [in] */ DWORD cch,
            /* [unique][out][in] */ DWORD *pdwPriority,
            /* [in] */ const SIZE *prgSize,
            /* [in] */ DWORD dwRecClrDepth,
            /* [in] */ DWORD *pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *Extract )( 
            IExtractImage2 * This,
            /* [out] */ HBITMAP *phBmpThumbnail);
        
        HRESULT ( STDMETHODCALLTYPE *GetDateStamp )( 
            IExtractImage2 * This,
            /* [out] */ FILETIME *pDateStamp);
        
        END_INTERFACE
    } IExtractImage2Vtbl;

    interface IExtractImage2
    {
        CONST_VTBL struct IExtractImage2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IExtractImage2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IExtractImage2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IExtractImage2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IExtractImage2_GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)	\
    (This)->lpVtbl -> GetLocation(This,pszPathBuffer,cch,pdwPriority,prgSize,dwRecClrDepth,pdwFlags)

#define IExtractImage2_Extract(This,phBmpThumbnail)	\
    (This)->lpVtbl -> Extract(This,phBmpThumbnail)


#define IExtractImage2_GetDateStamp(This,pDateStamp)	\
    (This)->lpVtbl -> GetDateStamp(This,pDateStamp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IExtractImage2_GetDateStamp_Proxy( 
    IExtractImage2 * This,
    /* [out] */ FILETIME *pDateStamp);


void __RPC_STUB IExtractImage2_GetDateStamp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IExtractImage2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0222 */
/* [local] */ 

typedef IExtractImage2 *LPEXTRACTIMAGE2;

#endif



extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0222_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0222_v0_0_s_ifspec;

#ifndef __IUserEventTimerCallback_INTERFACE_DEFINED__
#define __IUserEventTimerCallback_INTERFACE_DEFINED__

/* interface IUserEventTimerCallback */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IUserEventTimerCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e9ead8e6-2a25-410e-9b58-a9fbef1dd1a2")
    IUserEventTimerCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE UserEventTimerProc( 
            /* [in] */ ULONG uUserEventTimerID,
            /* [in] */ UINT uTimerElapse) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUserEventTimerCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUserEventTimerCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUserEventTimerCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUserEventTimerCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *UserEventTimerProc )( 
            IUserEventTimerCallback * This,
            /* [in] */ ULONG uUserEventTimerID,
            /* [in] */ UINT uTimerElapse);
        
        END_INTERFACE
    } IUserEventTimerCallbackVtbl;

    interface IUserEventTimerCallback
    {
        CONST_VTBL struct IUserEventTimerCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUserEventTimerCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUserEventTimerCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUserEventTimerCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUserEventTimerCallback_UserEventTimerProc(This,uUserEventTimerID,uTimerElapse)	\
    (This)->lpVtbl -> UserEventTimerProc(This,uUserEventTimerID,uTimerElapse)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IUserEventTimerCallback_UserEventTimerProc_Proxy( 
    IUserEventTimerCallback * This,
    /* [in] */ ULONG uUserEventTimerID,
    /* [in] */ UINT uTimerElapse);


void __RPC_STUB IUserEventTimerCallback_UserEventTimerProc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUserEventTimerCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0223 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0223_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0223_v0_0_s_ifspec;

#ifndef __IUserEventTimer_INTERFACE_DEFINED__
#define __IUserEventTimer_INTERFACE_DEFINED__

/* interface IUserEventTimer */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IUserEventTimer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0F504B94-6E42-42E6-99E0-E20FAFE52AB4")
    IUserEventTimer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetUserEventTimer( 
            /* [in] */ HWND hWnd,
            /* [in] */ UINT uCallbackMessage,
            /* [in] */ UINT uTimerElapse,
            /* [in] */ IUserEventTimerCallback *pUserEventTimerCallback,
            /* [out][in] */ ULONG *puUserEventTimerID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KillUserEventTimer( 
            /* [in] */ HWND hWnd,
            /* [in] */ ULONG uUserEventTimerID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserEventTimerElapsed( 
            /* [in] */ HWND hWnd,
            /* [in] */ ULONG uUserEventTimerID,
            /* [out] */ UINT *puTimerElapsed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitTimerTickInterval( 
            /* [in] */ UINT uTimerTickIntervalMs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUserEventTimerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUserEventTimer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUserEventTimer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUserEventTimer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserEventTimer )( 
            IUserEventTimer * This,
            /* [in] */ HWND hWnd,
            /* [in] */ UINT uCallbackMessage,
            /* [in] */ UINT uTimerElapse,
            /* [in] */ IUserEventTimerCallback *pUserEventTimerCallback,
            /* [out][in] */ ULONG *puUserEventTimerID);
        
        HRESULT ( STDMETHODCALLTYPE *KillUserEventTimer )( 
            IUserEventTimer * This,
            /* [in] */ HWND hWnd,
            /* [in] */ ULONG uUserEventTimerID);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserEventTimerElapsed )( 
            IUserEventTimer * This,
            /* [in] */ HWND hWnd,
            /* [in] */ ULONG uUserEventTimerID,
            /* [out] */ UINT *puTimerElapsed);
        
        HRESULT ( STDMETHODCALLTYPE *InitTimerTickInterval )( 
            IUserEventTimer * This,
            /* [in] */ UINT uTimerTickIntervalMs);
        
        END_INTERFACE
    } IUserEventTimerVtbl;

    interface IUserEventTimer
    {
        CONST_VTBL struct IUserEventTimerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUserEventTimer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUserEventTimer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUserEventTimer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUserEventTimer_SetUserEventTimer(This,hWnd,uCallbackMessage,uTimerElapse,pUserEventTimerCallback,puUserEventTimerID)	\
    (This)->lpVtbl -> SetUserEventTimer(This,hWnd,uCallbackMessage,uTimerElapse,pUserEventTimerCallback,puUserEventTimerID)

#define IUserEventTimer_KillUserEventTimer(This,hWnd,uUserEventTimerID)	\
    (This)->lpVtbl -> KillUserEventTimer(This,hWnd,uUserEventTimerID)

#define IUserEventTimer_GetUserEventTimerElapsed(This,hWnd,uUserEventTimerID,puTimerElapsed)	\
    (This)->lpVtbl -> GetUserEventTimerElapsed(This,hWnd,uUserEventTimerID,puTimerElapsed)

#define IUserEventTimer_InitTimerTickInterval(This,uTimerTickIntervalMs)	\
    (This)->lpVtbl -> InitTimerTickInterval(This,uTimerTickIntervalMs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IUserEventTimer_SetUserEventTimer_Proxy( 
    IUserEventTimer * This,
    /* [in] */ HWND hWnd,
    /* [in] */ UINT uCallbackMessage,
    /* [in] */ UINT uTimerElapse,
    /* [in] */ IUserEventTimerCallback *pUserEventTimerCallback,
    /* [out][in] */ ULONG *puUserEventTimerID);


void __RPC_STUB IUserEventTimer_SetUserEventTimer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IUserEventTimer_KillUserEventTimer_Proxy( 
    IUserEventTimer * This,
    /* [in] */ HWND hWnd,
    /* [in] */ ULONG uUserEventTimerID);


void __RPC_STUB IUserEventTimer_KillUserEventTimer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IUserEventTimer_GetUserEventTimerElapsed_Proxy( 
    IUserEventTimer * This,
    /* [in] */ HWND hWnd,
    /* [in] */ ULONG uUserEventTimerID,
    /* [out] */ UINT *puTimerElapsed);


void __RPC_STUB IUserEventTimer_GetUserEventTimerElapsed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IUserEventTimer_InitTimerTickInterval_Proxy( 
    IUserEventTimer * This,
    /* [in] */ UINT uTimerTickIntervalMs);


void __RPC_STUB IUserEventTimer_InitTimerTickInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUserEventTimer_INTERFACE_DEFINED__ */


#ifndef __IDockingWindow_INTERFACE_DEFINED__
#define __IDockingWindow_INTERFACE_DEFINED__

/* interface IDockingWindow */
/* [object][uuid] */ 


EXTERN_C const IID IID_IDockingWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("012dd920-7b26-11d0-8ca9-00a0c92dbfe8")
    IDockingWindow : public IOleWindow
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowDW( 
            /* [in] */ BOOL fShow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseDW( 
            /* [in] */ DWORD dwReserved) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResizeBorderDW( 
            /* [in] */ LPCRECT prcBorder,
            /* [in] */ IUnknown *punkToolbarSite,
            /* [in] */ BOOL fReserved) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDockingWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDockingWindow * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDockingWindow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDockingWindow * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            IDockingWindow * This,
            /* [out] */ HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            IDockingWindow * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( STDMETHODCALLTYPE *ShowDW )( 
            IDockingWindow * This,
            /* [in] */ BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *CloseDW )( 
            IDockingWindow * This,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE *ResizeBorderDW )( 
            IDockingWindow * This,
            /* [in] */ LPCRECT prcBorder,
            /* [in] */ IUnknown *punkToolbarSite,
            /* [in] */ BOOL fReserved);
        
        END_INTERFACE
    } IDockingWindowVtbl;

    interface IDockingWindow
    {
        CONST_VTBL struct IDockingWindowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDockingWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDockingWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDockingWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDockingWindow_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IDockingWindow_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IDockingWindow_ShowDW(This,fShow)	\
    (This)->lpVtbl -> ShowDW(This,fShow)

#define IDockingWindow_CloseDW(This,dwReserved)	\
    (This)->lpVtbl -> CloseDW(This,dwReserved)

#define IDockingWindow_ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)	\
    (This)->lpVtbl -> ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDockingWindow_ShowDW_Proxy( 
    IDockingWindow * This,
    /* [in] */ BOOL fShow);


void __RPC_STUB IDockingWindow_ShowDW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDockingWindow_CloseDW_Proxy( 
    IDockingWindow * This,
    /* [in] */ DWORD dwReserved);


void __RPC_STUB IDockingWindow_CloseDW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDockingWindow_ResizeBorderDW_Proxy( 
    IDockingWindow * This,
    /* [in] */ LPCRECT prcBorder,
    /* [in] */ IUnknown *punkToolbarSite,
    /* [in] */ BOOL fReserved);


void __RPC_STUB IDockingWindow_ResizeBorderDW_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDockingWindow_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0225 */
/* [local] */ 

#define DBIM_MINSIZE    0x0001
#define DBIM_MAXSIZE    0x0002
#define DBIM_INTEGRAL   0x0004
#define DBIM_ACTUAL     0x0008
#define DBIM_TITLE      0x0010
#define DBIM_MODEFLAGS  0x0020
#define DBIM_BKCOLOR    0x0040
#include <pshpack8.h>
typedef /* [public][public] */ struct __MIDL___MIDL_itf_shobjidl_0225_0001
    {
    DWORD dwMask;
    POINTL ptMinSize;
    POINTL ptMaxSize;
    POINTL ptIntegral;
    POINTL ptActual;
    WCHAR wszTitle[ 256 ];
    DWORD dwModeFlags;
    COLORREF crBkgnd;
    } 	DESKBANDINFO;

#include <poppack.h>
#define DBIMF_NORMAL            0x0000
#define DBIMF_FIXED             0x0001
#define DBIMF_FIXEDBMP          0x0004   // a fixed background bitmap (if supported)
#define DBIMF_VARIABLEHEIGHT    0x0008
#define DBIMF_UNDELETEABLE      0x0010
#define DBIMF_DEBOSSED          0x0020
#define DBIMF_BKCOLOR           0x0040
#define DBIMF_USECHEVRON        0x0080
#define DBIMF_BREAK             0x0100
#define DBIMF_ADDTOFRONT        0x0200
#define DBIMF_TOPALIGN          0x0400
#define DBIF_VIEWMODE_NORMAL         0x0000
#define DBIF_VIEWMODE_VERTICAL       0x0001
#define DBIF_VIEWMODE_FLOATING       0x0002
#define DBIF_VIEWMODE_TRANSPARENT    0x0004

enum __MIDL___MIDL_itf_shobjidl_0225_0002
    {	DBID_BANDINFOCHANGED	= 0,
	DBID_SHOWONLY	= 1,
	DBID_MAXIMIZEBAND	= 2,
	DBID_PUSHCHEVRON	= 3,
	DBID_DELAYINIT	= 4,
	DBID_FINISHINIT	= 5,
	DBID_SETWINDOWTHEME	= 6,
	DBID_PERMITAUTOHIDE	= 7
    } ;
#define DBPC_SELECTFIRST    (DWORD)-1
#define DBPC_SELECTLAST     (DWORD)-2
#define CGID_DeskBand IID_IDeskBand


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0225_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0225_v0_0_s_ifspec;

#ifndef __IDeskBand_INTERFACE_DEFINED__
#define __IDeskBand_INTERFACE_DEFINED__

/* interface IDeskBand */
/* [object][uuid] */ 


EXTERN_C const IID IID_IDeskBand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EB0FE172-1A3A-11D0-89B3-00A0C90A90AC")
    IDeskBand : public IDockingWindow
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBandInfo( 
            /* [in] */ DWORD dwBandID,
            /* [in] */ DWORD dwViewMode,
            /* [out][in] */ DESKBANDINFO *pdbi) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDeskBandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDeskBand * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDeskBand * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDeskBand * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *GetWindow )( 
            IDeskBand * This,
            /* [out] */ HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ContextSensitiveHelp )( 
            IDeskBand * This,
            /* [in] */ BOOL fEnterMode);
        
        HRESULT ( STDMETHODCALLTYPE *ShowDW )( 
            IDeskBand * This,
            /* [in] */ BOOL fShow);
        
        HRESULT ( STDMETHODCALLTYPE *CloseDW )( 
            IDeskBand * This,
            /* [in] */ DWORD dwReserved);
        
        HRESULT ( STDMETHODCALLTYPE *ResizeBorderDW )( 
            IDeskBand * This,
            /* [in] */ LPCRECT prcBorder,
            /* [in] */ IUnknown *punkToolbarSite,
            /* [in] */ BOOL fReserved);
        
        HRESULT ( STDMETHODCALLTYPE *GetBandInfo )( 
            IDeskBand * This,
            /* [in] */ DWORD dwBandID,
            /* [in] */ DWORD dwViewMode,
            /* [out][in] */ DESKBANDINFO *pdbi);
        
        END_INTERFACE
    } IDeskBandVtbl;

    interface IDeskBand
    {
        CONST_VTBL struct IDeskBandVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDeskBand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDeskBand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDeskBand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDeskBand_GetWindow(This,phwnd)	\
    (This)->lpVtbl -> GetWindow(This,phwnd)

#define IDeskBand_ContextSensitiveHelp(This,fEnterMode)	\
    (This)->lpVtbl -> ContextSensitiveHelp(This,fEnterMode)


#define IDeskBand_ShowDW(This,fShow)	\
    (This)->lpVtbl -> ShowDW(This,fShow)

#define IDeskBand_CloseDW(This,dwReserved)	\
    (This)->lpVtbl -> CloseDW(This,dwReserved)

#define IDeskBand_ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)	\
    (This)->lpVtbl -> ResizeBorderDW(This,prcBorder,punkToolbarSite,fReserved)


#define IDeskBand_GetBandInfo(This,dwBandID,dwViewMode,pdbi)	\
    (This)->lpVtbl -> GetBandInfo(This,dwBandID,dwViewMode,pdbi)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDeskBand_GetBandInfo_Proxy( 
    IDeskBand * This,
    /* [in] */ DWORD dwBandID,
    /* [in] */ DWORD dwViewMode,
    /* [out][in] */ DESKBANDINFO *pdbi);


void __RPC_STUB IDeskBand_GetBandInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDeskBand_INTERFACE_DEFINED__ */


#ifndef __ITaskbarList_INTERFACE_DEFINED__
#define __ITaskbarList_INTERFACE_DEFINED__

/* interface ITaskbarList */
/* [object][uuid] */ 


EXTERN_C const IID IID_ITaskbarList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("56FDF342-FD6D-11d0-958A-006097C9A090")
    ITaskbarList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE HrInit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTab( 
            /* [in] */ HWND hwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteTab( 
            /* [in] */ HWND hwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ActivateTab( 
            /* [in] */ HWND hwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveAlt( 
            /* [in] */ HWND hwnd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITaskbarListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITaskbarList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITaskbarList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITaskbarList * This);
        
        HRESULT ( STDMETHODCALLTYPE *HrInit )( 
            ITaskbarList * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddTab )( 
            ITaskbarList * This,
            /* [in] */ HWND hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteTab )( 
            ITaskbarList * This,
            /* [in] */ HWND hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ActivateTab )( 
            ITaskbarList * This,
            /* [in] */ HWND hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveAlt )( 
            ITaskbarList * This,
            /* [in] */ HWND hwnd);
        
        END_INTERFACE
    } ITaskbarListVtbl;

    interface ITaskbarList
    {
        CONST_VTBL struct ITaskbarListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITaskbarList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITaskbarList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITaskbarList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITaskbarList_HrInit(This)	\
    (This)->lpVtbl -> HrInit(This)

#define ITaskbarList_AddTab(This,hwnd)	\
    (This)->lpVtbl -> AddTab(This,hwnd)

#define ITaskbarList_DeleteTab(This,hwnd)	\
    (This)->lpVtbl -> DeleteTab(This,hwnd)

#define ITaskbarList_ActivateTab(This,hwnd)	\
    (This)->lpVtbl -> ActivateTab(This,hwnd)

#define ITaskbarList_SetActiveAlt(This,hwnd)	\
    (This)->lpVtbl -> SetActiveAlt(This,hwnd)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITaskbarList_HrInit_Proxy( 
    ITaskbarList * This);


void __RPC_STUB ITaskbarList_HrInit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITaskbarList_AddTab_Proxy( 
    ITaskbarList * This,
    /* [in] */ HWND hwnd);


void __RPC_STUB ITaskbarList_AddTab_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITaskbarList_DeleteTab_Proxy( 
    ITaskbarList * This,
    /* [in] */ HWND hwnd);


void __RPC_STUB ITaskbarList_DeleteTab_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITaskbarList_ActivateTab_Proxy( 
    ITaskbarList * This,
    /* [in] */ HWND hwnd);


void __RPC_STUB ITaskbarList_ActivateTab_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ITaskbarList_SetActiveAlt_Proxy( 
    ITaskbarList * This,
    /* [in] */ HWND hwnd);


void __RPC_STUB ITaskbarList_SetActiveAlt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITaskbarList_INTERFACE_DEFINED__ */


#ifndef __ITaskbarList2_INTERFACE_DEFINED__
#define __ITaskbarList2_INTERFACE_DEFINED__

/* interface ITaskbarList2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_ITaskbarList2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("602D4995-B13A-429b-A66E-1935E44F4317")
    ITaskbarList2 : public ITaskbarList
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MarkFullscreenWindow( 
            /* [in] */ HWND hwnd,
            /* [in] */ BOOL fFullscreen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITaskbarList2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITaskbarList2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITaskbarList2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITaskbarList2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *HrInit )( 
            ITaskbarList2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddTab )( 
            ITaskbarList2 * This,
            /* [in] */ HWND hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteTab )( 
            ITaskbarList2 * This,
            /* [in] */ HWND hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *ActivateTab )( 
            ITaskbarList2 * This,
            /* [in] */ HWND hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveAlt )( 
            ITaskbarList2 * This,
            /* [in] */ HWND hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *MarkFullscreenWindow )( 
            ITaskbarList2 * This,
            /* [in] */ HWND hwnd,
            /* [in] */ BOOL fFullscreen);
        
        END_INTERFACE
    } ITaskbarList2Vtbl;

    interface ITaskbarList2
    {
        CONST_VTBL struct ITaskbarList2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITaskbarList2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ITaskbarList2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ITaskbarList2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ITaskbarList2_HrInit(This)	\
    (This)->lpVtbl -> HrInit(This)

#define ITaskbarList2_AddTab(This,hwnd)	\
    (This)->lpVtbl -> AddTab(This,hwnd)

#define ITaskbarList2_DeleteTab(This,hwnd)	\
    (This)->lpVtbl -> DeleteTab(This,hwnd)

#define ITaskbarList2_ActivateTab(This,hwnd)	\
    (This)->lpVtbl -> ActivateTab(This,hwnd)

#define ITaskbarList2_SetActiveAlt(This,hwnd)	\
    (This)->lpVtbl -> SetActiveAlt(This,hwnd)


#define ITaskbarList2_MarkFullscreenWindow(This,hwnd,fFullscreen)	\
    (This)->lpVtbl -> MarkFullscreenWindow(This,hwnd,fFullscreen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ITaskbarList2_MarkFullscreenWindow_Proxy( 
    ITaskbarList2 * This,
    /* [in] */ HWND hwnd,
    /* [in] */ BOOL fFullscreen);


void __RPC_STUB ITaskbarList2_MarkFullscreenWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ITaskbarList2_INTERFACE_DEFINED__ */


#ifndef __ICDBurn_INTERFACE_DEFINED__
#define __ICDBurn_INTERFACE_DEFINED__

/* interface ICDBurn */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ICDBurn;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3d73a659-e5d0-4d42-afc0-5121ba425c8d")
    ICDBurn : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRecorderDriveLetter( 
            /* [size_is][out] */ LPWSTR pszDrive,
            /* [in] */ UINT cch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Burn( 
            /* [in] */ HWND hwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HasRecordableDrive( 
            /* [out] */ BOOL *pfHasRecorder) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICDBurnVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICDBurn * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICDBurn * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICDBurn * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecorderDriveLetter )( 
            ICDBurn * This,
            /* [size_is][out] */ LPWSTR pszDrive,
            /* [in] */ UINT cch);
        
        HRESULT ( STDMETHODCALLTYPE *Burn )( 
            ICDBurn * This,
            /* [in] */ HWND hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *HasRecordableDrive )( 
            ICDBurn * This,
            /* [out] */ BOOL *pfHasRecorder);
        
        END_INTERFACE
    } ICDBurnVtbl;

    interface ICDBurn
    {
        CONST_VTBL struct ICDBurnVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICDBurn_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICDBurn_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICDBurn_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICDBurn_GetRecorderDriveLetter(This,pszDrive,cch)	\
    (This)->lpVtbl -> GetRecorderDriveLetter(This,pszDrive,cch)

#define ICDBurn_Burn(This,hwnd)	\
    (This)->lpVtbl -> Burn(This,hwnd)

#define ICDBurn_HasRecordableDrive(This,pfHasRecorder)	\
    (This)->lpVtbl -> HasRecordableDrive(This,pfHasRecorder)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ICDBurn_GetRecorderDriveLetter_Proxy( 
    ICDBurn * This,
    /* [size_is][out] */ LPWSTR pszDrive,
    /* [in] */ UINT cch);


void __RPC_STUB ICDBurn_GetRecorderDriveLetter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICDBurn_Burn_Proxy( 
    ICDBurn * This,
    /* [in] */ HWND hwnd);


void __RPC_STUB ICDBurn_Burn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ICDBurn_HasRecordableDrive_Proxy( 
    ICDBurn * This,
    /* [out] */ BOOL *pfHasRecorder);


void __RPC_STUB ICDBurn_HasRecordableDrive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICDBurn_INTERFACE_DEFINED__ */


#ifndef __IAddressBarParser_INTERFACE_DEFINED__
#define __IAddressBarParser_INTERFACE_DEFINED__

/* interface IAddressBarParser */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IAddressBarParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C9D81948-443A-40C7-945C-5E171B8C66B4")
    IAddressBarParser : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ParseFromOutsideSource( 
            /* [string][in] */ LPCWSTR pcszUrlIn,
            /* [in] */ DWORD dwParseFlags,
            /* [out] */ BOOL *pfWasCorrected) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUrl( 
            /* [size_is][out] */ LPWSTR pszUrlOut,
            /* [in] */ DWORD cchUrlOutSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUrl( 
            /* [string][in] */ LPCWSTR pcszUrlIn,
            /* [in] */ DWORD dwGenType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplayName( 
            /* [size_is][out] */ LPWSTR pszUrlOut,
            /* [in] */ DWORD cchUrlOutSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPidl( 
            /* [out] */ LPITEMIDLIST *ppidl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPidl( 
            /* [in] */ LPCITEMIDLIST pidl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetArgs( 
            /* [size_is][out] */ LPWSTR pszArgsOut,
            /* [in] */ DWORD cchArgsOutSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddPath( 
            /* [in] */ LPCITEMIDLIST pidl) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAddressBarParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAddressBarParser * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAddressBarParser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAddressBarParser * This);
        
        HRESULT ( STDMETHODCALLTYPE *ParseFromOutsideSource )( 
            IAddressBarParser * This,
            /* [string][in] */ LPCWSTR pcszUrlIn,
            /* [in] */ DWORD dwParseFlags,
            /* [out] */ BOOL *pfWasCorrected);
        
        HRESULT ( STDMETHODCALLTYPE *GetUrl )( 
            IAddressBarParser * This,
            /* [size_is][out] */ LPWSTR pszUrlOut,
            /* [in] */ DWORD cchUrlOutSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetUrl )( 
            IAddressBarParser * This,
            /* [string][in] */ LPCWSTR pcszUrlIn,
            /* [in] */ DWORD dwGenType);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayName )( 
            IAddressBarParser * This,
            /* [size_is][out] */ LPWSTR pszUrlOut,
            /* [in] */ DWORD cchUrlOutSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPidl )( 
            IAddressBarParser * This,
            /* [out] */ LPITEMIDLIST *ppidl);
        
        HRESULT ( STDMETHODCALLTYPE *SetPidl )( 
            IAddressBarParser * This,
            /* [in] */ LPCITEMIDLIST pidl);
        
        HRESULT ( STDMETHODCALLTYPE *GetArgs )( 
            IAddressBarParser * This,
            /* [size_is][out] */ LPWSTR pszArgsOut,
            /* [in] */ DWORD cchArgsOutSize);
        
        HRESULT ( STDMETHODCALLTYPE *AddPath )( 
            IAddressBarParser * This,
            /* [in] */ LPCITEMIDLIST pidl);
        
        END_INTERFACE
    } IAddressBarParserVtbl;

    interface IAddressBarParser
    {
        CONST_VTBL struct IAddressBarParserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAddressBarParser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAddressBarParser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAddressBarParser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAddressBarParser_ParseFromOutsideSource(This,pcszUrlIn,dwParseFlags,pfWasCorrected)	\
    (This)->lpVtbl -> ParseFromOutsideSource(This,pcszUrlIn,dwParseFlags,pfWasCorrected)

#define IAddressBarParser_GetUrl(This,pszUrlOut,cchUrlOutSize)	\
    (This)->lpVtbl -> GetUrl(This,pszUrlOut,cchUrlOutSize)

#define IAddressBarParser_SetUrl(This,pcszUrlIn,dwGenType)	\
    (This)->lpVtbl -> SetUrl(This,pcszUrlIn,dwGenType)

#define IAddressBarParser_GetDisplayName(This,pszUrlOut,cchUrlOutSize)	\
    (This)->lpVtbl -> GetDisplayName(This,pszUrlOut,cchUrlOutSize)

#define IAddressBarParser_GetPidl(This,ppidl)	\
    (This)->lpVtbl -> GetPidl(This,ppidl)

#define IAddressBarParser_SetPidl(This,pidl)	\
    (This)->lpVtbl -> SetPidl(This,pidl)

#define IAddressBarParser_GetArgs(This,pszArgsOut,cchArgsOutSize)	\
    (This)->lpVtbl -> GetArgs(This,pszArgsOut,cchArgsOutSize)

#define IAddressBarParser_AddPath(This,pidl)	\
    (This)->lpVtbl -> AddPath(This,pidl)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAddressBarParser_ParseFromOutsideSource_Proxy( 
    IAddressBarParser * This,
    /* [string][in] */ LPCWSTR pcszUrlIn,
    /* [in] */ DWORD dwParseFlags,
    /* [out] */ BOOL *pfWasCorrected);


void __RPC_STUB IAddressBarParser_ParseFromOutsideSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressBarParser_GetUrl_Proxy( 
    IAddressBarParser * This,
    /* [size_is][out] */ LPWSTR pszUrlOut,
    /* [in] */ DWORD cchUrlOutSize);


void __RPC_STUB IAddressBarParser_GetUrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressBarParser_SetUrl_Proxy( 
    IAddressBarParser * This,
    /* [string][in] */ LPCWSTR pcszUrlIn,
    /* [in] */ DWORD dwGenType);


void __RPC_STUB IAddressBarParser_SetUrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressBarParser_GetDisplayName_Proxy( 
    IAddressBarParser * This,
    /* [size_is][out] */ LPWSTR pszUrlOut,
    /* [in] */ DWORD cchUrlOutSize);


void __RPC_STUB IAddressBarParser_GetDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressBarParser_GetPidl_Proxy( 
    IAddressBarParser * This,
    /* [out] */ LPITEMIDLIST *ppidl);


void __RPC_STUB IAddressBarParser_GetPidl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressBarParser_SetPidl_Proxy( 
    IAddressBarParser * This,
    /* [in] */ LPCITEMIDLIST pidl);


void __RPC_STUB IAddressBarParser_SetPidl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressBarParser_GetArgs_Proxy( 
    IAddressBarParser * This,
    /* [size_is][out] */ LPWSTR pszArgsOut,
    /* [in] */ DWORD cchArgsOutSize);


void __RPC_STUB IAddressBarParser_GetArgs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAddressBarParser_AddPath_Proxy( 
    IAddressBarParser * This,
    /* [in] */ LPCITEMIDLIST pidl);


void __RPC_STUB IAddressBarParser_AddPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAddressBarParser_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0230 */
/* [local] */ 

#define IDD_WIZEXTN_FIRST    0x5000
#define IDD_WIZEXTN_LAST     0x5100


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0230_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0230_v0_0_s_ifspec;

#ifndef __IWizardSite_INTERFACE_DEFINED__
#define __IWizardSite_INTERFACE_DEFINED__

/* interface IWizardSite */
/* [object][local][helpstring][uuid] */ 


EXTERN_C const IID IID_IWizardSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88960f5b-422f-4e7b-8013-73415381c3c3")
    IWizardSite : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPreviousPage( 
            /* [out] */ HPROPSHEETPAGE *phpage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextPage( 
            /* [out] */ HPROPSHEETPAGE *phpage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCancelledPage( 
            /* [out] */ HPROPSHEETPAGE *phpage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWizardSiteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWizardSite * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWizardSite * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWizardSite * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPreviousPage )( 
            IWizardSite * This,
            /* [out] */ HPROPSHEETPAGE *phpage);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextPage )( 
            IWizardSite * This,
            /* [out] */ HPROPSHEETPAGE *phpage);
        
        HRESULT ( STDMETHODCALLTYPE *GetCancelledPage )( 
            IWizardSite * This,
            /* [out] */ HPROPSHEETPAGE *phpage);
        
        END_INTERFACE
    } IWizardSiteVtbl;

    interface IWizardSite
    {
        CONST_VTBL struct IWizardSiteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWizardSite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWizardSite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWizardSite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWizardSite_GetPreviousPage(This,phpage)	\
    (This)->lpVtbl -> GetPreviousPage(This,phpage)

#define IWizardSite_GetNextPage(This,phpage)	\
    (This)->lpVtbl -> GetNextPage(This,phpage)

#define IWizardSite_GetCancelledPage(This,phpage)	\
    (This)->lpVtbl -> GetCancelledPage(This,phpage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWizardSite_GetPreviousPage_Proxy( 
    IWizardSite * This,
    /* [out] */ HPROPSHEETPAGE *phpage);


void __RPC_STUB IWizardSite_GetPreviousPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWizardSite_GetNextPage_Proxy( 
    IWizardSite * This,
    /* [out] */ HPROPSHEETPAGE *phpage);


void __RPC_STUB IWizardSite_GetNextPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWizardSite_GetCancelledPage_Proxy( 
    IWizardSite * This,
    /* [out] */ HPROPSHEETPAGE *phpage);


void __RPC_STUB IWizardSite_GetCancelledPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWizardSite_INTERFACE_DEFINED__ */


#ifndef __IWizardExtension_INTERFACE_DEFINED__
#define __IWizardExtension_INTERFACE_DEFINED__

/* interface IWizardExtension */
/* [object][local][helpstring][uuid] */ 


EXTERN_C const IID IID_IWizardExtension;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c02ea696-86cc-491e-9b23-74394a0444a8")
    IWizardExtension : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPages( 
            /* [out][in] */ HPROPSHEETPAGE *aPages,
            /* [in] */ UINT cPages,
            /* [out] */ UINT *pnPagesAdded) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFirstPage( 
            /* [out] */ HPROPSHEETPAGE *phpage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastPage( 
            /* [out] */ HPROPSHEETPAGE *phpage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWizardExtensionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWizardExtension * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWizardExtension * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWizardExtension * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPages )( 
            IWizardExtension * This,
            /* [out][in] */ HPROPSHEETPAGE *aPages,
            /* [in] */ UINT cPages,
            /* [out] */ UINT *pnPagesAdded);
        
        HRESULT ( STDMETHODCALLTYPE *GetFirstPage )( 
            IWizardExtension * This,
            /* [out] */ HPROPSHEETPAGE *phpage);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastPage )( 
            IWizardExtension * This,
            /* [out] */ HPROPSHEETPAGE *phpage);
        
        END_INTERFACE
    } IWizardExtensionVtbl;

    interface IWizardExtension
    {
        CONST_VTBL struct IWizardExtensionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWizardExtension_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWizardExtension_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWizardExtension_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWizardExtension_AddPages(This,aPages,cPages,pnPagesAdded)	\
    (This)->lpVtbl -> AddPages(This,aPages,cPages,pnPagesAdded)

#define IWizardExtension_GetFirstPage(This,phpage)	\
    (This)->lpVtbl -> GetFirstPage(This,phpage)

#define IWizardExtension_GetLastPage(This,phpage)	\
    (This)->lpVtbl -> GetLastPage(This,phpage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWizardExtension_AddPages_Proxy( 
    IWizardExtension * This,
    /* [out][in] */ HPROPSHEETPAGE *aPages,
    /* [in] */ UINT cPages,
    /* [out] */ UINT *pnPagesAdded);


void __RPC_STUB IWizardExtension_AddPages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWizardExtension_GetFirstPage_Proxy( 
    IWizardExtension * This,
    /* [out] */ HPROPSHEETPAGE *phpage);


void __RPC_STUB IWizardExtension_GetFirstPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWizardExtension_GetLastPage_Proxy( 
    IWizardExtension * This,
    /* [out] */ HPROPSHEETPAGE *phpage);


void __RPC_STUB IWizardExtension_GetLastPage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWizardExtension_INTERFACE_DEFINED__ */


#ifndef __IWebWizardExtension_INTERFACE_DEFINED__
#define __IWebWizardExtension_INTERFACE_DEFINED__

/* interface IWebWizardExtension */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IWebWizardExtension;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0e6b3f66-98d1-48c0-a222-fbde74e2fbc5")
    IWebWizardExtension : public IWizardExtension
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetInitialURL( 
            /* [string][in] */ LPCWSTR pszURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetErrorURL( 
            /* [string][in] */ LPCWSTR pszErrorURL) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWebWizardExtensionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebWizardExtension * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebWizardExtension * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebWizardExtension * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPages )( 
            IWebWizardExtension * This,
            /* [out][in] */ HPROPSHEETPAGE *aPages,
            /* [in] */ UINT cPages,
            /* [out] */ UINT *pnPagesAdded);
        
        HRESULT ( STDMETHODCALLTYPE *GetFirstPage )( 
            IWebWizardExtension * This,
            /* [out] */ HPROPSHEETPAGE *phpage);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastPage )( 
            IWebWizardExtension * This,
            /* [out] */ HPROPSHEETPAGE *phpage);
        
        HRESULT ( STDMETHODCALLTYPE *SetInitialURL )( 
            IWebWizardExtension * This,
            /* [string][in] */ LPCWSTR pszURL);
        
        HRESULT ( STDMETHODCALLTYPE *SetErrorURL )( 
            IWebWizardExtension * This,
            /* [string][in] */ LPCWSTR pszErrorURL);
        
        END_INTERFACE
    } IWebWizardExtensionVtbl;

    interface IWebWizardExtension
    {
        CONST_VTBL struct IWebWizardExtensionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebWizardExtension_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWebWizardExtension_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWebWizardExtension_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWebWizardExtension_AddPages(This,aPages,cPages,pnPagesAdded)	\
    (This)->lpVtbl -> AddPages(This,aPages,cPages,pnPagesAdded)

#define IWebWizardExtension_GetFirstPage(This,phpage)	\
    (This)->lpVtbl -> GetFirstPage(This,phpage)

#define IWebWizardExtension_GetLastPage(This,phpage)	\
    (This)->lpVtbl -> GetLastPage(This,phpage)


#define IWebWizardExtension_SetInitialURL(This,pszURL)	\
    (This)->lpVtbl -> SetInitialURL(This,pszURL)

#define IWebWizardExtension_SetErrorURL(This,pszErrorURL)	\
    (This)->lpVtbl -> SetErrorURL(This,pszErrorURL)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWebWizardExtension_SetInitialURL_Proxy( 
    IWebWizardExtension * This,
    /* [string][in] */ LPCWSTR pszURL);


void __RPC_STUB IWebWizardExtension_SetInitialURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebWizardExtension_SetErrorURL_Proxy( 
    IWebWizardExtension * This,
    /* [string][in] */ LPCWSTR pszErrorURL);


void __RPC_STUB IWebWizardExtension_SetErrorURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWebWizardExtension_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0233 */
/* [local] */ 

#define SID_WebWizardHost IID_IWebWizardExtension
#define SHPWHF_NORECOMPRESS             0x00000001  // don't allow/prompt for recompress of streams
#define SHPWHF_NONETPLACECREATE         0x00000002  // don't create a network place when transfer is complete
#define SHPWHF_NOFILESELECTOR           0x00000004  // don't show the file selector
#define SHPWHF_VALIDATEVIAWEBFOLDERS    0x00010000  // enable web folders to validate network places (ANP support)


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0233_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0233_v0_0_s_ifspec;

#ifndef __IPublishingWizard_INTERFACE_DEFINED__
#define __IPublishingWizard_INTERFACE_DEFINED__

/* interface IPublishingWizard */
/* [unique][object][uuid][helpstring] */ 


EXTERN_C const IID IID_IPublishingWizard;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("aa9198bb-ccec-472d-beed-19a4f6733f7a")
    IPublishingWizard : public IWizardExtension
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IDataObject *pdo,
            /* [in] */ DWORD dwOptions,
            /* [string][in] */ LPCWSTR pszServiceProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransferManifest( 
            /* [out] */ HRESULT *phrFromTransfer,
            /* [out] */ IXMLDOMDocument **pdocManifest) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPublishingWizardVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPublishingWizard * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPublishingWizard * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPublishingWizard * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPages )( 
            IPublishingWizard * This,
            /* [out][in] */ HPROPSHEETPAGE *aPages,
            /* [in] */ UINT cPages,
            /* [out] */ UINT *pnPagesAdded);
        
        HRESULT ( STDMETHODCALLTYPE *GetFirstPage )( 
            IPublishingWizard * This,
            /* [out] */ HPROPSHEETPAGE *phpage);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastPage )( 
            IPublishingWizard * This,
            /* [out] */ HPROPSHEETPAGE *phpage);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IPublishingWizard * This,
            /* [in] */ IDataObject *pdo,
            /* [in] */ DWORD dwOptions,
            /* [string][in] */ LPCWSTR pszServiceProvider);
        
        HRESULT ( STDMETHODCALLTYPE *GetTransferManifest )( 
            IPublishingWizard * This,
            /* [out] */ HRESULT *phrFromTransfer,
            /* [out] */ IXMLDOMDocument **pdocManifest);
        
        END_INTERFACE
    } IPublishingWizardVtbl;

    interface IPublishingWizard
    {
        CONST_VTBL struct IPublishingWizardVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPublishingWizard_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPublishingWizard_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPublishingWizard_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPublishingWizard_AddPages(This,aPages,cPages,pnPagesAdded)	\
    (This)->lpVtbl -> AddPages(This,aPages,cPages,pnPagesAdded)

#define IPublishingWizard_GetFirstPage(This,phpage)	\
    (This)->lpVtbl -> GetFirstPage(This,phpage)

#define IPublishingWizard_GetLastPage(This,phpage)	\
    (This)->lpVtbl -> GetLastPage(This,phpage)


#define IPublishingWizard_Initialize(This,pdo,dwOptions,pszServiceProvider)	\
    (This)->lpVtbl -> Initialize(This,pdo,dwOptions,pszServiceProvider)

#define IPublishingWizard_GetTransferManifest(This,phrFromTransfer,pdocManifest)	\
    (This)->lpVtbl -> GetTransferManifest(This,phrFromTransfer,pdocManifest)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPublishingWizard_Initialize_Proxy( 
    IPublishingWizard * This,
    /* [in] */ IDataObject *pdo,
    /* [in] */ DWORD dwOptions,
    /* [string][in] */ LPCWSTR pszServiceProvider);


void __RPC_STUB IPublishingWizard_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPublishingWizard_GetTransferManifest_Proxy( 
    IPublishingWizard * This,
    /* [out] */ HRESULT *phrFromTransfer,
    /* [out] */ IXMLDOMDocument **pdocManifest);


void __RPC_STUB IPublishingWizard_GetTransferManifest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPublishingWizard_INTERFACE_DEFINED__ */


#ifndef __IFolderViewHost_INTERFACE_DEFINED__
#define __IFolderViewHost_INTERFACE_DEFINED__

/* interface IFolderViewHost */
/* [object][local][helpstring][uuid] */ 


EXTERN_C const IID IID_IFolderViewHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1ea58f02-d55a-411d-b09e-9e65ac21605b")
    IFolderViewHost : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ HWND hwndParent,
            /* [in] */ IDataObject *pdo,
            /* [in] */ RECT *prc) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFolderViewHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFolderViewHost * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFolderViewHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFolderViewHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IFolderViewHost * This,
            /* [in] */ HWND hwndParent,
            /* [in] */ IDataObject *pdo,
            /* [in] */ RECT *prc);
        
        END_INTERFACE
    } IFolderViewHostVtbl;

    interface IFolderViewHost
    {
        CONST_VTBL struct IFolderViewHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFolderViewHost_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFolderViewHost_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFolderViewHost_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFolderViewHost_Initialize(This,hwndParent,pdo,prc)	\
    (This)->lpVtbl -> Initialize(This,hwndParent,pdo,prc)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFolderViewHost_Initialize_Proxy( 
    IFolderViewHost * This,
    /* [in] */ HWND hwndParent,
    /* [in] */ IDataObject *pdo,
    /* [in] */ RECT *prc);


void __RPC_STUB IFolderViewHost_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFolderViewHost_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_shobjidl_0235 */
/* [local] */ 

#define ACDD_VISIBLE        0x0001


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0235_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0235_v0_0_s_ifspec;

#ifndef __IAutoCompleteDropDown_INTERFACE_DEFINED__
#define __IAutoCompleteDropDown_INTERFACE_DEFINED__

/* interface IAutoCompleteDropDown */
/* [unique][object][uuid] */ 


EXTERN_C const IID IID_IAutoCompleteDropDown;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3CD141F4-3C6A-11d2-BCAA-00C04FD929DB")
    IAutoCompleteDropDown : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDropDownStatus( 
            /* [out] */ DWORD *pdwFlags,
            /* [string][out] */ LPWSTR *ppwszString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetEnumerator( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAutoCompleteDropDownVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoCompleteDropDown * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoCompleteDropDown * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoCompleteDropDown * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDropDownStatus )( 
            IAutoCompleteDropDown * This,
            /* [out] */ DWORD *pdwFlags,
            /* [string][out] */ LPWSTR *ppwszString);
        
        HRESULT ( STDMETHODCALLTYPE *ResetEnumerator )( 
            IAutoCompleteDropDown * This);
        
        END_INTERFACE
    } IAutoCompleteDropDownVtbl;

    interface IAutoCompleteDropDown
    {
        CONST_VTBL struct IAutoCompleteDropDownVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoCompleteDropDown_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAutoCompleteDropDown_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAutoCompleteDropDown_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAutoCompleteDropDown_GetDropDownStatus(This,pdwFlags,ppwszString)	\
    (This)->lpVtbl -> GetDropDownStatus(This,pdwFlags,ppwszString)

#define IAutoCompleteDropDown_ResetEnumerator(This)	\
    (This)->lpVtbl -> ResetEnumerator(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAutoCompleteDropDown_GetDropDownStatus_Proxy( 
    IAutoCompleteDropDown * This,
    /* [out] */ DWORD *pdwFlags,
    /* [string][out] */ LPWSTR *ppwszString);


void __RPC_STUB IAutoCompleteDropDown_GetDropDownStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAutoCompleteDropDown_ResetEnumerator_Proxy( 
    IAutoCompleteDropDown * This);


void __RPC_STUB IAutoCompleteDropDown_ResetEnumerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAutoCompleteDropDown_INTERFACE_DEFINED__ */



#ifndef __ShellObjects_LIBRARY_DEFINED__
#define __ShellObjects_LIBRARY_DEFINED__

/* library ShellObjects */
/* [version][lcid][helpstring][uuid] */ 

#define SID_PublishingWizard CLSID_PublishingWizard

EXTERN_C const IID LIBID_ShellObjects;

EXTERN_C const CLSID CLSID_QueryCancelAutoPlay;

#ifdef __cplusplus

class DECLSPEC_UUID("331F1768-05A9-4ddd-B86E-DAE34DDC998A")
QueryCancelAutoPlay;
#endif

EXTERN_C const CLSID CLSID_DriveSizeCategorizer;

#ifdef __cplusplus

class DECLSPEC_UUID("94357B53-CA29-4b78-83AE-E8FE7409134F")
DriveSizeCategorizer;
#endif

EXTERN_C const CLSID CLSID_DriveTypeCategorizer;

#ifdef __cplusplus

class DECLSPEC_UUID("B0A8F3CF-4333-4bab-8873-1CCB1CADA48B")
DriveTypeCategorizer;
#endif

EXTERN_C const CLSID CLSID_FreeSpaceCategorizer;

#ifdef __cplusplus

class DECLSPEC_UUID("B5607793-24AC-44c7-82E2-831726AA6CB7")
FreeSpaceCategorizer;
#endif

EXTERN_C const CLSID CLSID_TimeCategorizer;

#ifdef __cplusplus

class DECLSPEC_UUID("3bb4118f-ddfd-4d30-a348-9fb5d6bf1afe")
TimeCategorizer;
#endif

EXTERN_C const CLSID CLSID_SizeCategorizer;

#ifdef __cplusplus

class DECLSPEC_UUID("55d7b852-f6d1-42f2-aa75-8728a1b2d264")
SizeCategorizer;
#endif

EXTERN_C const CLSID CLSID_AlphabeticalCategorizer;

#ifdef __cplusplus

class DECLSPEC_UUID("3c2654c6-7372-4f6b-b310-55d6128f49d2")
AlphabeticalCategorizer;
#endif

EXTERN_C const CLSID CLSID_MergedCategorizer;

#ifdef __cplusplus

class DECLSPEC_UUID("8e827c11-33e7-4bc1-b242-8cd9a1c2b304")
MergedCategorizer;
#endif

EXTERN_C const CLSID CLSID_ImageProperties;

#ifdef __cplusplus

class DECLSPEC_UUID("7ab770c7-0e23-4d7a-8aa2-19bfad479829")
ImageProperties;
#endif

EXTERN_C const CLSID CLSID_PropertiesUI;

#ifdef __cplusplus

class DECLSPEC_UUID("d912f8cf-0396-4915-884e-fb425d32943b")
PropertiesUI;
#endif

EXTERN_C const CLSID CLSID_UserNotification;

#ifdef __cplusplus

class DECLSPEC_UUID("0010890e-8789-413c-adbc-48f5b511b3af")
UserNotification;
#endif

EXTERN_C const CLSID CLSID_UserEventTimerCallback;

#ifdef __cplusplus

class DECLSPEC_UUID("15fffd13-5140-41b8-b89a-c8d5759cd2b2")
UserEventTimerCallback;
#endif

EXTERN_C const CLSID CLSID_UserEventTimer;

#ifdef __cplusplus

class DECLSPEC_UUID("864A1288-354C-4D19-9D68-C2742BB14997")
UserEventTimer;
#endif

EXTERN_C const CLSID CLSID_NetCrawler;

#ifdef __cplusplus

class DECLSPEC_UUID("601ac3dc-786a-4eb0-bf40-ee3521e70bfb")
NetCrawler;
#endif

EXTERN_C const CLSID CLSID_CDBurn;

#ifdef __cplusplus

class DECLSPEC_UUID("fbeb8a05-beee-4442-804e-409d6c4515e9")
CDBurn;
#endif

EXTERN_C const CLSID CLSID_AddressBarParser;

#ifdef __cplusplus

class DECLSPEC_UUID("e0e11a09-5cb8-4b6c-8332-e00720a168f2")
AddressBarParser;
#endif

EXTERN_C const CLSID CLSID_TaskbarList;

#ifdef __cplusplus

class DECLSPEC_UUID("56FDF344-FD6D-11d0-958A-006097C9A090")
TaskbarList;
#endif

EXTERN_C const CLSID CLSID_WebWizardHost;

#ifdef __cplusplus

class DECLSPEC_UUID("c827f149-55c1-4d28-935e-57e47caed973")
WebWizardHost;
#endif

EXTERN_C const CLSID CLSID_PublishDropTarget;

#ifdef __cplusplus

class DECLSPEC_UUID("CC6EEFFB-43F6-46c5-9619-51D571967F7D")
PublishDropTarget;
#endif

EXTERN_C const CLSID CLSID_PublishingWizard;

#ifdef __cplusplus

class DECLSPEC_UUID("6b33163c-76a5-4b6c-bf21-45de9cd503a1")
PublishingWizard;
#endif

EXTERN_C const CLSID CLSID_InternetPrintOrdering;

#ifdef __cplusplus

class DECLSPEC_UUID("add36aa8-751a-4579-a266-d66f5202ccbb")
InternetPrintOrdering;
#endif

EXTERN_C const CLSID CLSID_FolderViewHost;

#ifdef __cplusplus

class DECLSPEC_UUID("20b1cb23-6968-4eb9-b7d4-a66d00d07cee")
FolderViewHost;
#endif
#endif /* __ShellObjects_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_shobjidl_0236 */
/* [local] */ 


extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0236_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_shobjidl_0236_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HBITMAP_UserSize(     unsigned long *, unsigned long            , HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserMarshal(  unsigned long *, unsigned char *, HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserUnmarshal(unsigned long *, unsigned char *, HBITMAP * ); 
void                      __RPC_USER  HBITMAP_UserFree(     unsigned long *, HBITMAP * ); 

unsigned long             __RPC_USER  HGLOBAL_UserSize(     unsigned long *, unsigned long            , HGLOBAL * ); 
unsigned char * __RPC_USER  HGLOBAL_UserMarshal(  unsigned long *, unsigned char *, HGLOBAL * ); 
unsigned char * __RPC_USER  HGLOBAL_UserUnmarshal(unsigned long *, unsigned char *, HGLOBAL * ); 
void                      __RPC_USER  HGLOBAL_UserFree(     unsigned long *, HGLOBAL * ); 

unsigned long             __RPC_USER  HICON_UserSize(     unsigned long *, unsigned long            , HICON * ); 
unsigned char * __RPC_USER  HICON_UserMarshal(  unsigned long *, unsigned char *, HICON * ); 
unsigned char * __RPC_USER  HICON_UserUnmarshal(unsigned long *, unsigned char *, HICON * ); 
void                      __RPC_USER  HICON_UserFree(     unsigned long *, HICON * ); 

unsigned long             __RPC_USER  HMENU_UserSize(     unsigned long *, unsigned long            , HMENU * ); 
unsigned char * __RPC_USER  HMENU_UserMarshal(  unsigned long *, unsigned char *, HMENU * ); 
unsigned char * __RPC_USER  HMENU_UserUnmarshal(unsigned long *, unsigned char *, HMENU * ); 
void                      __RPC_USER  HMENU_UserFree(     unsigned long *, HMENU * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  LPCITEMIDLIST_UserSize(     unsigned long *, unsigned long            , LPCITEMIDLIST * ); 
unsigned char * __RPC_USER  LPCITEMIDLIST_UserMarshal(  unsigned long *, unsigned char *, LPCITEMIDLIST * ); 
unsigned char * __RPC_USER  LPCITEMIDLIST_UserUnmarshal(unsigned long *, unsigned char *, LPCITEMIDLIST * ); 
void                      __RPC_USER  LPCITEMIDLIST_UserFree(     unsigned long *, LPCITEMIDLIST * ); 

unsigned long             __RPC_USER  LPITEMIDLIST_UserSize(     unsigned long *, unsigned long            , LPITEMIDLIST * ); 
unsigned char * __RPC_USER  LPITEMIDLIST_UserMarshal(  unsigned long *, unsigned char *, LPITEMIDLIST * ); 
unsigned char * __RPC_USER  LPITEMIDLIST_UserUnmarshal(unsigned long *, unsigned char *, LPITEMIDLIST * ); 
void                      __RPC_USER  LPITEMIDLIST_UserFree(     unsigned long *, LPITEMIDLIST * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



