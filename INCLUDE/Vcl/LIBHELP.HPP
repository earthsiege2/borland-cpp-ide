// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'LibHelp.pas' rev: 6.00

#ifndef LibHelpHPP
#define LibHelpHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Libhelp
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const Word hcDFontEditor = 0x61a8;
static const Word hcDColorEditor = 0x61b2;
static const Word hcDMediaPlayerOpen = 0x61bc;
static const Word hcRedirectLinkError = 0x61c6;
static const Word hcRedirectLinkDlg = 0x61c7;
static const Word hcDStringListEditor = 0x6590;
static const Word hcDValueListEditor = 0x6595;
static const Word hcDFilterEditor = 0x659a;
static const Word hcDNotebookEditor = 0x65a4;
static const Word hcDPictureEditor = 0x65ae;
static const Word hcDInputMaskEditor = 0x65b8;
static const Word hcDMaskedTextEditor = 0x65c2;
static const Word hcDOpenMaskFile = 0x65cc;
static const Word hcDColumnsEditor = 0x65d6;
static const Word hcDTableIndexEditor = 0x65e0;
static const Word hcDTreeViewItemEdit = 0x65ea;
static const Word hcDListViewItemEdit = 0x65f4;
static const Word hcDListViewColEdit = 0x65fe;
static const Word hcDHeaderSectionEdit = 0x6608;
static const Word hcDStatusBarEdit = 0x6612;
static const Word hcDImageListEditor = 0x661c;
static const Word hcDCollectionEditor = 0x6626;
static const Word hcDResponseEditor = 0x6630;
static const Word hcDActionListEditor = 0x663a;
static const Word hcDNewStdAction = 0x663b;
static const Word hcDIconViewItemEdit = 0x663c;
static const Word hcmCollectionAdd = 0x6659;
static const Word hcmCollectionDelete = 0x665a;
static const Word hcmCollectionMoveUp = 0x665b;
static const Word hcmCollectionMoveDown = 0x665c;
static const Word hcmCollectionSelectAll = 0x665d;
static const Word hcmCollectionShowButtons = 0x665e;
static const Word hcmDBGridColnAddAllFields = 0x666d;
static const Word hcmDBGridColnRestoreDefaults = 0x666e;
static const Word hcDLoadPicture = 0x6978;
static const Word hcDSavePicture = 0x6982;
static const Word hcDAddNoteBookPage = 0x698c;
static const Word hcDEditNotebookPage = 0x6996;
static const Word hcDStringListLoad = 0x69a0;
static const Word hcDStringListSave = 0x69aa;
static const Word hcDDDEInfo = 0x69b4;
static const Word hcOlePasteSpecial = 0x69be;
static const Word hcOleInsertObject = 0x69c8;
static const Word hcOleConvert = 0x69d2;
static const Word hcDDataBaseEdit = 0x69dc;
static const Word hcDDataSetAdd = 0x69e6;
static const Word hcDStoredProcedure = 0x69f0;
static const Word hcDDefineField = 0x69fa;
static const Word hcDFieldLinksDesign = 0x6a04;
static const Word hcDDefineParameter = 0x6a0e;
static const Word hcDQuery = 0x6a18;
static const Word hcDLoadMenuResource = 0x6a22;
static const Word hcDSelectReportDir = 0x6a2c;
static const Word hcDVCSGetFileDir = 0x6a36;
static const Word hcDVCSGetDir = 0x6a3b;
static const Word hcDVCSPutSelDir = 0x6a40;
static const Word hcDFormExpert = 0x6a4a;
static const Word hcDUpdateSQL = 0x6a54;
static const Word hcDSaveAttributesAs = 0x6a5e;
static const Word hcDAssociateAttributes = 0x6a68;
static const Word hcDAssignClientData = 0x6a72;
static const Word hcDAXDataBindings = 0x6a7c;
static const Word hcDADOConnEdit = 0x6a86;
static const Word hcDADOSQLEdit = 0x6a87;
static const Word hcDIBUpdateSQL = 0x6b6c;
static const Word hcDIBDatabaseEdit = 0x6b76;
static const Word hcDIBTransactionEdit = 0x6b80;
static const Word hcDataSetDesigner = 0x6d60;
static const Word hcMDynamicItem = 0x6f54;
static const Word hcMDatabase = 0x6fb8;
static const Word hcMDatabaseExplore = 0x6fb9;
static const Word hcMDatabaseSQLMon = 0x6fba;
static const Word hcMDatabaseFormExpt = 0x6fbb;
static const Word hcFAlignToGrid = 0x7530;
static const Word hcFBringToFront = 0x7531;
static const Word hcFSendToBack = 0x7532;
static const Word hcFAlign = 0x7533;
static const Word hcFSize = 0x7534;
static const Word hcFScale = 0x7535;
static const Word hcFTabOrder = 0x7536;
static const Word hcFSaveAsTemplate = 0x7537;
static const Word hcFCreateOrder = 0x7538;
static const Word hcFViewAsText = 0x7539;
static const Word hcFRevert = 0x753a;
static const Word hcFFlipChildren = 0x753b;
static const Word hcFFlipChildrenAll = 0x753c;
static const Word hcFFlipChildrenSelected = 0x753d;
static const Word hcFTextDFM = 0x753e;
static const Word hcMMenuDesignerPopup = 0x7594;
static const Word hcMFormDesignerPopup = 0x759e;
static const Word hcMFieldsEditorPopup = 0x75b2;
static const Word hcMFEPAddFieldsItem = 0x75b3;
static const Word hcMFEPNewFieldItem = 0x75b4;
static const Word hcMFEPCut = 0x75b5;
static const Word hcMFEPCopy = 0x75b6;
static const Word hcMFEPPaste = 0x75b7;
static const Word hcMFEPDelete = 0x75b8;
static const Word hcMFEPSelectAll = 0x75b9;
static const Word hcMFEPRetrieveAttribs = 0x75ba;
static const Word hcMFEPSaveAttributes = 0x75bb;
static const Word hcMFEPSaveAttrAs = 0x75bc;
static const Word hcMFEPAssociateAttr = 0x75bd;
static const Word hcMFEPUnAssociateAttr = 0x75be;
static const Word hcDHTMLFileOpen = 0x75c6;
static const Word hcDWebPage = 0x75c7;
static const Word hcDAddWebComp = 0x75c8;
static const Word hcDAddFieldCtrls = 0x75c9;
static const Word hcMWebPageEditor = 0x75ca;
static const Word hcMHTMLPage = 0x75cb;
static const Word hcMWebPageEditorLabels = 0x75cc;
static const Word hcDStylesFileOpen = 0x75cd;
static const Word hcDDecisionCubeEditor = 0x75da;
static const Word hcDDecisionCubeDimensions = 0x75db;
static const Word hcDDecisionCubeMemoryControl = 0x75dc;
static const Word hcDDecisionCubeDesignerOptions = 0x75dd;
static const Word hcDDecisionCubeLimits = 0x75de;
static const Word hcDDecisionQueryEditor = 0x75e4;
static const Word hcDDecisionQueryDimensions = 0x75e5;
static const Word hcDDecisionQuerySQLEditor = 0x75e6;
static const Word hcDVCSManageVersionLabels = 0xc738;
static const Word hcDVCSGet = 0xc742;
static const Word hcDVCSGetFile = 0xc74c;
static const Word hcDVCSArchiveManager = 0xc756;
static const Word hcDVCSCreateArchive = 0xc760;
static const Word hcDVCSOptions = 0xc76a;
static const Word hcDVCSPut = 0xc774;
static const Word hcDVCSPutDir = 0xc77e;
static const Word hcDVCSLockArchives = 0xc788;
static const Word hcDVCSUnlockArchives = 0xc792;

}	/* namespace Libhelp */
using namespace Libhelp;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// LibHelp
