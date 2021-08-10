/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

        ideguid.cpp
        Created: 10/28/95
        Copyright (c) 1995, Borland International
        $Header:   Y:/ADMIN/BRIDE/ADDON/DELIVER/INTERFAC/IDEGUID.CPV   1.25   16 Jan 1997 14:47:26   JDOUGLAS  $
        $Revision:   1.25  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#define INITGUID
#define STRICT
#define INC_OLE2
#include <windows.h>
#pragma hdrstop

#ifndef _IFUNC
#define _IFUNC STDMETHODCALLTYPE
#endif

#include <ideaddon\imenu.uid>
#include <ideaddon\IEditor.uid>
#include <ideaddon\IProj.uid>
#include <ideaddon\IProjNod.uid>
#include <ideaddon\IProjEvt.uid>
#include <ideaddon\IPolyStr.uid>
#include <ideaddon\IScript.uid>
#include <ideaddon\ITool.uid>
#include <ideaddon\IToolInf.uid>
#include <ideaddon\IToolExe.uid>
#include <ideaddon\ivfile.uid>
#include <ideaddon\icmd.uid>
#include <ideaddon\IIde.uid>
#include <ideaddon\iview.uid>
#include <ideaddon\ITarg.uid>
#include <ideaddon\IOption.uid>
#include <ideaddon\IMakeSvr.uid>
#include <ideaddon\impd.uid>
#include <ideaddon\itx.uid>
#include <ideaddon\imsgsys.uid>
#include <ideaddon\isbar.uid>
#include <ideaddon\iprset.uid>
#include <ideaddon\iidewin.uid>
#include <ideaddon\iideui.uid>

/*
DEFINE_GUID(IID_Addon_I*, 0x707240??L,
0x4B4B, 0x11CF, 0x9D, 0x40, 0x44, 0x45,0x53, 0x54, 0x00, 0x00 );
*/

//707240C0-4B4B-11CF-9D40-444553540000      IID_Addon_IMessageSystem
//707240C1-4B4B-11CF-9D40-444553540000      IID_Win32_OWL_Target
//707240C2-4B4B-11CF-9D40-444553540000      IID_Java_Target
//707240C3-4B4B-11CF-9D40-444553540000      IID_TARAGET_PROPERTY_PAGE
//707240C4-4B4B-11CF-9D40-444553540000      IID_TARAGET_TYPE
//707240C5-4B4B-11CF-9D40-444553540000      IID_TARAGET_MANAGER
//707240C6-4B4B-11CF-9D40-444553540000      IID_TARAGET_MANAGER_PROPERTY_DIALOG
//707240C7-4B4B-11CF-9D40-444553540000      IID_Addon_IStatusBar
//707240C8-4B4B-11CF-9D40-444553540000      IID_Addon_IMpdServer
//707240C9-4B4B-11CF-9D40-444553540000      IID_Addon_IMpdLocalOverride
//707240CA-4B4B-11CF-9D40-444553540000      IID_Addon_IMpdPageLocalOverride
//707240CB-4B4B-11CF-9D40-444553540000      IID_Addon_ITargetServer
//707240CC-4B4B-11CF-9D40-444553540000      IID_Addon_IOptionSetServer
//707240CD-4B4B-11CF-9D40-444553540000      IID_Addon_IMakeServer
//707240CE-4B4B-11CF-9D40-444553540000      IID_Addon_IIdeServer
//707240CF-4B4B-11CF-9D40-444553540000      IID_Addon_IViewType

//707240D0-4B4B-11CF-9D40-444553540000      IID_Addon_IEditorServer
//707240D1-4B4B-11CF-9D40-444553540000      IID_Addon_IMenuItem
//707240D2-4B4B-11CF-9D40-444553540000      IID_Addon_IMenuClient
//707240D3-4B4B-11CF-9D40-444553540000      IID_Addon_IMenuServer
//707240D4-4B4B-11CF-9D40-444553540000      IID_Addon_IProjectServer
//707240D5-4B4B-11CF-9D40-444553540000      IID_Addon_IProjectNodeInfo
//707240D6-4B4B-11CF-9D40-444553540000      IID_Addon_IProjectClient
//707240D7-4B4B-11CF-9D40-444553540000      IID_Addon_IPolyString
//707240D8-4B4B-11CF-9D40-444553540000      IID_Addon_IScriptServer
//707240D9-4B4B-11CF-9D40-444553540000      IID_Addon_IToolServer
//707240DA-4B4B-11CF-9D40-444553540000      IID_Addon_IToolInfo
//707240DB-4B4B-11CF-9D40-444553540000      IID_Addon_IToolImplementor
//707240DC-4B4B-11CF-9D40-444553540000      IID_PUBLIC_ADDON_TESTER
//707240DD-4B4B-11CF-9D40-444553540000      IID_Addon_IVirtualFile
//707240DE-4B4B-11CF-9D40-444553540000      IID_Addon_ICommand
//707240DF-4B4B-11CF-9D40-444553540000      IID_Addon_ICommandClient

//707240E0-4B4B-11CF-9D40-444553540000      IID_Addon_ICommandServer
//707240E1-4B4B-11CF-9D40-444553540000      IID_Addon_IMenuEvent
//707240E2-4B4B-11CF-9D40-444553540000      IID_Addon_IViewFile
//707240E3-4B4B-11CF-9D40-444553540000      IID_Addon_IViewClient
//707240E4-4B4B-11CF-9D40-444553540000      (reserved: BC)
//707240E5-4B4B-11CF-9D40-444553540000      (reserved: BC)
//707240E6-4B4B-11CF-9D40-444553540000      IID_Addon_IViewType2
//707240E7-4B4B-11CF-9D40-444553540000      IID_Addon_IToolInfo2
//707240E8-4B4B-11CF-9D40-444553540000      IID_Addon_IMessageFolder2
//707240E9-4B4B-11CF-9D40-444553540000      IID_Addon_IPrinterSettings
//707240EA-4B4B-11CF-9D40-444553540000      IID_Addon_IIdeWindow
//707240EB-4B4B-11CF-9D40-444553540000      IID_Addon_IMessageSystem2
//707240EC-4B4B-11CF-9D40-444553540000      IID_Addon_IMessageClient
//707240ED-4B4B-11CF-9D40-444553540000      IID_Addon_IProjectServer2
//707240EE-4B4B-11CF-9D40-444553540000      IID_Addon_IProjectSaveClient
//707240EF-4B4B-11CF-9D40-444553540000      IID_Addon_IProjectServer3

//707240F0-4B4B-11CF-9D40-444553540000      IID_Addon_IProjectNodeInfo2
//707240F1-4B4B-11CF-9D40-444553540000      IID_Addon_IIdeUI
//707240F2-4B4B-11CF-9D40-444553540000      IID_Addon_IEditorServer2
//707240F3-4B4B-11CF-9D40-444553540000      IID_Addon_IAutoDependencyPoster
//707240F4-4B4B-11CF-9D40-444553540000      IID_Addon_IStatusDialog
//707240F5-4B4B-11CF-9D40-444553540000      IID_Addon_IToolInfo3
//707240F6-4B4B-11CF-9D40-444553540000
//707240F7-4B4B-11CF-9D40-444553540000
//707240F8-4B4B-11CF-9D40-444553540000
//707240F9-4B4B-11CF-9D40-444553540000
//707240FA-4B4B-11CF-9D40-444553540000
//707240FB-4B4B-11CF-9D40-444553540000
//707240FC-4B4B-11CF-9D40-444553540000
//707240FD-4B4B-11CF-9D40-444553540000
//707240FE-4B4B-11CF-9D40-444553540000
//707240FF-4B4B-11CF-9D40-444553540000
