// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'MidConst.pas' rev: 5.00

#ifndef MidConstHPP
#define MidConstHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Midconst
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define MIDAS_CatDesc "Borland MIDAS Application Servers"
extern PACKAGE GUID CATID_MIDASAppServer;
#define SCatImplBaseKey "CLSID\\%s\\Implemented Categories"
#define SCatImplKey "CLSID\\%s\\Implemented Categories\\%s"
#define MIDAS_DLL "MIDAS.DLL"
#define SClsid "CLSID\\"
#define SPooled "Pooled"
#define SMaxObjects "MaxObjects"
#define STimeout "Timeout"
#define SSingleton "Singleton"
#define SSockets "Sockets"
#define SWeb "Web"
static const char SFlagOn = '\x31';
static const char SFlagOff = '\x30';
extern PACKAGE System::ResourceString _SProviderNotExported;
#define Midconst_SProviderNotExported System::LoadResourceString(&Midconst::_SProviderNotExported)
extern PACKAGE System::ResourceString _SNoDataProvider;
#define Midconst_SNoDataProvider System::LoadResourceString(&Midconst::_SNoDataProvider)
extern PACKAGE System::ResourceString _SInvalidDataPacket;
#define Midconst_SInvalidDataPacket System::LoadResourceString(&Midconst::_SInvalidDataPacket)
extern PACKAGE System::ResourceString _SRefreshError;
#define Midconst_SRefreshError System::LoadResourceString(&Midconst::_SRefreshError)
extern PACKAGE System::ResourceString _SProviderInvalid;
#define Midconst_SProviderInvalid System::LoadResourceString(&Midconst::_SProviderInvalid)
extern PACKAGE System::ResourceString _SServerNameBlank;
#define Midconst_SServerNameBlank System::LoadResourceString(&Midconst::_SServerNameBlank)
extern PACKAGE System::ResourceString _SRepositoryIdBlank;
#define Midconst_SRepositoryIdBlank System::LoadResourceString(&Midconst::_SRepositoryIdBlank)
extern PACKAGE System::ResourceString _SAggsGroupingLevel;
#define Midconst_SAggsGroupingLevel System::LoadResourceString(&Midconst::_SAggsGroupingLevel)
extern PACKAGE System::ResourceString _SAggsNoSuchLevel;
#define Midconst_SAggsNoSuchLevel System::LoadResourceString(&Midconst::_SAggsNoSuchLevel)
extern PACKAGE System::ResourceString _SNoCircularReference;
#define Midconst_SNoCircularReference System::LoadResourceString(&Midconst::_SNoCircularReference)
extern PACKAGE System::ResourceString _SErrorLoadingMidas;
#define Midconst_SErrorLoadingMidas System::LoadResourceString(&Midconst::_SErrorLoadingMidas)
extern PACKAGE System::ResourceString _SCannotCreateDataSet;
#define Midconst_SCannotCreateDataSet System::LoadResourceString(&Midconst::_SCannotCreateDataSet)
extern PACKAGE System::ResourceString _SSocketReadError;
#define Midconst_SSocketReadError System::LoadResourceString(&Midconst::_SSocketReadError)
extern PACKAGE System::ResourceString _SInvalidProviderName;
#define Midconst_SInvalidProviderName System::LoadResourceString(&Midconst::_SInvalidProviderName)
extern PACKAGE System::ResourceString _SBadVariantType;
#define Midconst_SBadVariantType System::LoadResourceString(&Midconst::_SBadVariantType)
extern PACKAGE System::ResourceString _SInvalidAction;
#define Midconst_SInvalidAction System::LoadResourceString(&Midconst::_SInvalidAction)
extern PACKAGE System::ResourceString _SInvalidResponse;
#define Midconst_SInvalidResponse System::LoadResourceString(&Midconst::_SInvalidResponse)
extern PACKAGE System::ResourceString _SRecordNotFound;
#define Midconst_SRecordNotFound System::LoadResourceString(&Midconst::_SRecordNotFound)
extern PACKAGE System::ResourceString _STooManyRecordsModified;
#define Midconst_STooManyRecordsModified System::LoadResourceString(&Midconst::_STooManyRecordsModified)
	
extern PACKAGE System::ResourceString _SInvalidOptParamType;
#define Midconst_SInvalidOptParamType System::LoadResourceString(&Midconst::_SInvalidOptParamType)
extern PACKAGE System::ResourceString _SMissingDataSet;
#define Midconst_SMissingDataSet System::LoadResourceString(&Midconst::_SMissingDataSet)
extern PACKAGE System::ResourceString _SConstraintFailed;
#define Midconst_SConstraintFailed System::LoadResourceString(&Midconst::_SConstraintFailed)
extern PACKAGE System::ResourceString _SField;
#define Midconst_SField System::LoadResourceString(&Midconst::_SField)
extern PACKAGE System::ResourceString _SReadOnlyProvider;
#define Midconst_SReadOnlyProvider System::LoadResourceString(&Midconst::_SReadOnlyProvider)
extern PACKAGE System::ResourceString _SNoKeySpecified;
#define Midconst_SNoKeySpecified System::LoadResourceString(&Midconst::_SNoKeySpecified)
extern PACKAGE System::ResourceString _SFieldNameTooLong;
#define Midconst_SFieldNameTooLong System::LoadResourceString(&Midconst::_SFieldNameTooLong)
extern PACKAGE System::ResourceString _SNoDataSets;
#define Midconst_SNoDataSets System::LoadResourceString(&Midconst::_SNoDataSets)
extern PACKAGE System::ResourceString _SRecConstFail;
#define Midconst_SRecConstFail System::LoadResourceString(&Midconst::_SRecConstFail)
extern PACKAGE System::ResourceString _SFieldConstFail;
#define Midconst_SFieldConstFail System::LoadResourceString(&Midconst::_SFieldConstFail)
extern PACKAGE System::ResourceString _SDefExprFail;
#define Midconst_SDefExprFail System::LoadResourceString(&Midconst::_SDefExprFail)
extern PACKAGE System::ResourceString _SArrayElementError;
#define Midconst_SArrayElementError System::LoadResourceString(&Midconst::_SArrayElementError)
extern PACKAGE System::ResourceString _SNoTableName;
#define Midconst_SNoTableName System::LoadResourceString(&Midconst::_SNoTableName)
extern PACKAGE System::ResourceString _SNoEditsAllowed;
#define Midconst_SNoEditsAllowed System::LoadResourceString(&Midconst::_SNoEditsAllowed)
extern PACKAGE System::ResourceString _SNoDeletesAllowed;
#define Midconst_SNoDeletesAllowed System::LoadResourceString(&Midconst::_SNoDeletesAllowed)
extern PACKAGE System::ResourceString _SNoInsertsAllowed;
#define Midconst_SNoInsertsAllowed System::LoadResourceString(&Midconst::_SNoInsertsAllowed)
extern PACKAGE System::ResourceString _SCannotChangeCommandText;
#define Midconst_SCannotChangeCommandText System::LoadResourceString(&Midconst::_SCannotChangeCommandText)
	
extern PACKAGE System::ResourceString _SNoServers;
#define Midconst_SNoServers System::LoadResourceString(&Midconst::_SNoServers)
extern PACKAGE System::ResourceString _SReturnError;
#define Midconst_SReturnError System::LoadResourceString(&Midconst::_SReturnError)
extern PACKAGE System::ResourceString _SNoWinSock2;
#define Midconst_SNoWinSock2 System::LoadResourceString(&Midconst::_SNoWinSock2)
extern PACKAGE System::ResourceString _SURLRequired;
#define Midconst_SURLRequired System::LoadResourceString(&Midconst::_SURLRequired)
extern PACKAGE System::ResourceString _SDefaultURL;
#define Midconst_SDefaultURL System::LoadResourceString(&Midconst::_SDefaultURL)
extern PACKAGE System::ResourceString _SInvalidURL;
#define Midconst_SInvalidURL System::LoadResourceString(&Midconst::_SInvalidURL)
extern PACKAGE System::ResourceString _SServerIsBusy;
#define Midconst_SServerIsBusy System::LoadResourceString(&Midconst::_SServerIsBusy)
extern PACKAGE System::ResourceString _SObjectNotAvailable;
#define Midconst_SObjectNotAvailable System::LoadResourceString(&Midconst::_SObjectNotAvailable)

}	/* namespace Midconst */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Midconst;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// MidConst
