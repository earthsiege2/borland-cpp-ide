// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// C++ TLBWRTR : $Revision:   1.0.1.0.1.2  $
// File generated on 1/29/2002 1:28:06 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office10\msoutl.olb (1)
// LIBID: {00062FFF-0000-0000-C000-000000000046}
// LCID: 0
// Helpfile: c:\program files\microsoft office\office10\VBAOL10.CHM
// HelpString: Microsoft Outlook 10.0 Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v2.2 Office, (C:\Program Files\Common Files\Microsoft Shared\Office10\MSO.DLL)
// Errors:
//   Hint: Symbol 'Application' renamed to 'OutlookApplication'
//   Hint: Symbol 'Application' renamed to 'OutlookApplication'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include "Outlook_XP.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Outlook_xp
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                      
// *********************************************************************//
const GUID LIBID_Outlook = {0x00062FFF, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Action = {0x00063043, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Application = {0x00063001, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__NameSpace = {0x00063002, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Recipient = {0x00063045, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_AddressEntry = {0x0006304B, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_AddressEntries = {0x0006304A, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Folders = {0x00063040, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_MAPIFolder = {0x00063006, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Items = {0x00063041, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Explorer = {0x00063003, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Panes = {0x00063009, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Selection = {0x00063087, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_View = {0x00063095, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Views = {0x0006308D, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_AddressLists = {0x00063048, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_AddressList = {0x00063049, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_SyncObjects = {0x00063086, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_SyncObject = {0x00063084, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__SyncObject = {0x00063083, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_SyncObjectEvents = {0x00063085, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Inspector = {0x00063005, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Explorers = {0x0006300A, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Explorer = {0x00063050, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ExplorerEvents = {0x0006304F, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ExplorerEvents_10 = {0x0006300F, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Inspectors = {0x00063008, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Inspector = {0x00063058, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_InspectorEvents = {0x0006307D, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_InspectorEvents_10 = {0x0006302A, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Search = {0x0006300B, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Results = {0x0006300C, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Reminders = {0x000630B1, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__Reminder = {0x000630B0, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Actions = {0x0006303E, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ApplicationEvents = {0x0006304E, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_PropertyPages = {0x00063080, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__AppointmentItem = {0x00063033, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Attachments = {0x0006303C, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Attachment = {0x00063007, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_FormDescription = {0x00063046, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_UserProperties = {0x0006303D, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_UserProperty = {0x00063042, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Recipients = {0x0006303B, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_MailItem = {0x00061033, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__MailItem = {0x00063034, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Links = {0x0006308A, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Link = {0x00063089, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_ItemProperties = {0x000630A8, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_ItemProperty = {0x000630A7, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ItemEvents = {0x0006303A, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ItemEvents_10 = {0x0006302B, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_RecurrencePattern = {0x00063044, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Exceptions = {0x0006304C, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Exception = {0x0006304D, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_AppointmentItem = {0x00061030, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_MeetingItem = {0x00061036, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__MeetingItem = {0x00063062, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__ContactItem = {0x00063021, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__DistListItem = {0x00063081, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__DocumentItem = {0x00063020, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ExplorersEvents = {0x00063078, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_FoldersEvents = {0x00063076, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_InspectorsEvents = {0x00063079, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ItemsEvents = {0x00063077, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__JournalItem = {0x00063022, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_NameSpaceEvents = {0x0006308C, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__NoteItem = {0x00063025, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_OutlookBarGroup = {0x00063073, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__OutlookBarShortcuts = {0x00063074, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_OutlookBarShortcut = {0x00063075, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__OutlookBarGroups = {0x00063072, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_OutlookBarGroupsEvents = {0x0006307B, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__OutlookBarPane = {0x00063070, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_OutlookBarStorage = {0x00063071, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_OutlookBarPaneEvents = {0x0006307A, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_OutlookBarShortcutsEvents = {0x0006307C, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_PropertyPage = {0x0006307E, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_PropertyPageSite = {0x0006307F, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID_Pages = {0x0006303F, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__PostItem = {0x00063024, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__RemoteItem = {0x00063023, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__ReportItem = {0x00063026, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__TaskItem = {0x00063035, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_TaskItem = {0x00061032, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__TaskRequestAcceptItem = {0x00063038, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__TaskRequestDeclineItem = {0x00063039, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__TaskRequestItem = {0x00063036, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__TaskRequestUpdateItem = {0x00063037, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ApplicationEvents_10 = {0x0006300E, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ResultsEvents = {0x0006300D, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID__ViewsEvents = {0x000630A5, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_ReminderCollectionEvents = {0x000630B2, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_OutlookApplication = {0x0006F03A, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_ContactItem = {0x00061031, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_DistListItem = {0x0006103C, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_DocumentItem = {0x00061061, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Explorers = {0x00063053, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Inspectors = {0x00063054, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Folders = {0x00063051, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Items = {0x00063052, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_JournalItem = {0x00061037, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_NameSpace = {0x0006308B, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_NoteItem = {0x00061034, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_OutlookBarGroups = {0x00063056, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_OutlookBarPane = {0x00063055, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_OutlookBarShortcuts = {0x00063057, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_PostItem = {0x0006103A, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_RemoteItem = {0x00061060, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_ReportItem = {0x00061035, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_TaskRequestAcceptItem = {0x00061052, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_TaskRequestDeclineItem = {0x00061053, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_TaskRequestItem = {0x00061050, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_TaskRequestUpdateItem = {0x00061051, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__IRecipientControl = {0xD87E7E16, 0x6897, 0x11CE,{ 0xA6, 0xC0, 0x00,0xAA, 0x00, 0x60,0x8F, 0xAA} };
const GUID DIID__DRecipientControl = {0x0006F025, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID__DRecipientControlEvents = {0xD87E7E17, 0x6897, 0x11CE,{ 0xA6, 0xC0, 0x00,0xAA, 0x00, 0x60,0x8F, 0xAA} };
const GUID CLSID__RecipientControl = {0x0006F023, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__IDocSiteControl = {0x43507DD0, 0x811D, 0x11CE,{ 0xB5, 0x65, 0x00,0xAA, 0x00, 0x60,0x8F, 0xAA} };
const GUID DIID__DDocSiteControl = {0x0006F026, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID__DDocSiteControlEvents = {0x50BB9B50, 0x811D, 0x11CE,{ 0xB5, 0x65, 0x00,0xAA, 0x00, 0x60,0x8F, 0xAA} };
const GUID CLSID__DocSiteControl = {0x0006F024, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__IDpxCtrl = {0x0006F097, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID__DpxCtrl = {0x0006F099, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__IPageWrapCtrl = {0x494F0970, 0xDD96, 0x11D2,{ 0xAF, 0x70, 0x00,0x60, 0x08, 0xAF,0xF1, 0x17} };
const GUID DIID__DPageWrapCtrl = {0x0006F096, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID__DPageWrapCtrlEvents = {0x494F0971, 0xDD96, 0x11D2,{ 0xAF, 0x70, 0x00,0x60, 0x08, 0xAF,0xF1, 0x17} };
const GUID CLSID__PageWrapCtrl = {0x0006F098, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID IID__IInspectorCtrl = {0xE182A127, 0xEADD, 0x46E1,{ 0xB8, 0x78, 0x48,0x2C, 0x48, 0xCD,0x87, 0x54} };
const GUID DIID__DInspectorCtrl = {0x0006F09D, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID__DInspectorEvents = {0x2D9C6D57, 0xBD3C, 0x4275,{ 0xBE, 0xD2, 0x73,0xF0, 0xED, 0xC1,0x8C, 0xCE} };
const GUID CLSID__InspectorCtrl = {0x0006F09C, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID DIID_DDataSourceObject = {0x11858B51, 0xDE06, 0x494E,{ 0x91, 0x5A, 0x6C,0xCE, 0xF1, 0x7F,0x7C, 0xB6} };
const GUID CLSID_DataSourceObject = {0x0006F02C, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Results = {0x00061039, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Views = {0x0006F027, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Reminder = {0x0006F028, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };
const GUID CLSID_Reminders = {0x0006F029, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00,0x00, 0x00, 0x00,0x00, 0x46} };

};     // namespace Outlook_xp
