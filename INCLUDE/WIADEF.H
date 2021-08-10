#pragma option push -b -a8 -pc -A- /*P_O_Push*/
/******************************************************************************
*
*  (C) COPYRIGHT MICROSOFT CORP., 1998-1999
*
*  TITLE:       wiadef.h
*
*  VERSION:     2.0
*
*  DATE:        27 July, 1999
*
*  DESCRIPTION:
*   Header file used to define WIA constants and globals.
*
******************************************************************************/

//
//  BUGBUG: Include our local copy of the GDI+ Image Guids : only temporary and
//  must be removed as soon as GDI+ is in SDK
//

#include "imgguids.h"

/**************************************************************************
*
*
*
*       WIA Errors
*
*
*
***************************************************************************/


//
// Define the facility code. Move this to sdk\inc???
//

#define FACILITY_WIA 33

//
// Definitions for WIA_ERRORs. Applications can test for these errors
// on API return, to keep users informed of conditions which a user
// could correct.
//

#define BASE_VAL_WIA_ERROR 0x00000000

#define WIA_ERROR_GENERAL_ERROR              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 1))
#define WIA_ERROR_PAPER_JAM                  MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 2))
#define WIA_ERROR_PAPER_EMPTY                MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 3))
#define WIA_ERROR_PAPER_PROBLEM              MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 4))
#define WIA_ERROR_OFFLINE                    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 5))
#define WIA_ERROR_BUSY                       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 6))
#define WIA_ERROR_WARMING_UP                 MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 7))
#define WIA_ERROR_USER_INTERVENTION          MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 8))
#define WIA_ERROR_ITEM_DELETED               MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 9))
#define WIA_ERROR_DEVICE_COMMUNICATION       MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 10))
#define WIA_ERROR_INVALID_COMMAND            MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIA, (BASE_VAL_WIA_ERROR + 11))

//
// SelectDeviceDlg & GetImageDlg flags
//

#define WIA_SELECT_DEVICE_NODEFAULT          0x00000001

//
// GetImageDlg & DeviceDlg flags
//

#define WIA_DEVICE_DIALOG_SINGLE_IMAGE       0x00000002

//**************************************************************************
//
//
//
//       WIA Events
//
//
//
//**************************************************************************

//
// Event registration flags, used by RegisterEventLaunch,
// RegisterEventCallbackInterface and RegisterEventCallbackCLSID.
//

#define  WIA_REGISTER_EVENT_CALLBACK        0x00000001
#define  WIA_UNREGISTER_EVENT_CALLBACK      0x00000002
#define  WIA_SET_DEFAULT_HANDLER            0x00000004

//
// Event type : individual bits of the possible event type combinations
//

#define  WIA_NOTIFICATION_EVENT             0x00000001
#define  WIA_ACTION_EVENT                   0x00000002

//
// Flag to indicate the corresponding persistent handler is default
//

#define  WIA_IS_DEFAULT_HANDLER             0x00000001

// {143E4E83-6497-11d2-A231-00C04FA31809}
DEFINE_GUID(WIA_EVENT_DEVICE_DISCONNECTED, 0x143e4e83, 0x6497, 0x11d2, 0xa2, 0x31, 0x0, 0xc0, 0x4f, 0xa3, 0x18, 0x9);

// {A28BBADE-64B6-11d2-A231-00C04FA31809}
DEFINE_GUID(WIA_EVENT_DEVICE_CONNECTED, 0xa28bbade, 0x64b6, 0x11d2, 0xa2, 0x31, 0x0, 0xc0, 0x4f, 0xa3, 0x18, 0x9);

// 1d22a559-e14f-11d2-b326-00c04f68ce61
DEFINE_GUID(WIA_EVENT_ITEM_DELETED, 0x1d22a559, 0xe14f, 0x11d2, 0xb3, 0x26, 0x00, 0xc0, 0x4f, 0x68, 0xce, 0x61);

// 4c8f4ef5-e14f-11d2-b326-00c04f68ce61
DEFINE_GUID(WIA_EVENT_ITEM_CREATED, 0x4c8f4ef5, 0xe14f, 0x11d2, 0xb3, 0x26, 0x00, 0xc0, 0x4f, 0x68, 0xce, 0x61);

// {9638bbfd-d1bd-11d2-b31f-00c04f68ce61}
DEFINE_GUID(WIA_EVENT_VOLUME_INSERT, 0x9638bbfd, 0xd1bd, 0x11d2, 0xb3, 0x1f, 0x00, 0xc0, 0x4f, 0x68, 0xce, 0x61);


//**************************************************************************
//
//
//
//      WIA Commands
//
//
//
//**************************************************************************

// 9b26b7b2-acad-11d2-a093-00c04f72dc3c
DEFINE_GUID(WIA_CMD_SYNCHRONIZE, 0x9b26b7b2, 0xacad, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);

// af933cac-acad-11d2-a093-00c04f72dc3c
DEFINE_GUID(WIA_CMD_TAKE_PICTURE, 0xaf933cac, 0xacad, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);

// e208c170-acad-11d2-a093-00c04f72dc3c
DEFINE_GUID(WIA_CMD_DELETE_ALL_ITEMS, 0xe208c170, 0xacad, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);

// 04e725b0-acae-11d2-a093-00c04f72dc3c
DEFINE_GUID(WIA_CMD_CHANGE_DOCUMENT, 0x04e725b0, 0xacae, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);

// 1f3b3d8e-acae-11d2-a093-00c04f72dc3c
DEFINE_GUID(WIA_CMD_UNLOAD_DOCUMENT, 0x1f3b3d8e, 0xacae, 0x11d2, 0xa0, 0x93, 0x00, 0xc0, 0x4f, 0x72, 0xdc, 0x3c);


// The following are private commands for debugging use only.


// 73815942-dbea-11d2-8416-00c04fa36145
DEFINE_GUID(WIA_CMD_DELETE_DEVICE_TREE, 0x73815942, 0xdbea, 0x11d2, 0x84, 0x16, 0x00, 0xc0, 0x4f, 0xa3, 0x61, 0x45);

// 9cba5ce0-dbea-11d2-8416-00c04fa36145
DEFINE_GUID(WIA_CMD_BUILD_DEVICE_TREE, 0x9cba5ce0, 0xdbea, 0x11d2, 0x84, 0x16, 0x00, 0xc0, 0x4f, 0xa3, 0x61, 0x45);


//**************************************************************************
//
//
//      WIA Icons
//
//          Event   : -1000 to -1499 (Standard), -1500 to -1999 (Custom)
//          Command : -2000 to -2499 (Standard), -2500 to -2999 (Custom)
//
//**************************************************************************

#define WIA_ICON_DEVICE_DISCONNECTED    (L"sti.dll,-1000")
#define WIA_ICON_DEVICE_CONNECTED       (L"sti.dll,-1001")
#define WIA_ICON_ITEM_DELETED           (L"sti.dll,-1002")
#define WIA_ICON_ITEM_CREATED           (L"sti.dll,-1003")
#define WIA_ICON_VOLUME_INSERT          (L"sti.dll,-1004")
#define WIA_ICON_SYNCHRONIZE            (L"sti.dll,-2000")
#define WIA_ICON_TAKE_PICTURE           (L"sti.dll,-2001")
#define WIA_ICON_DELETE_ALL_ITEMS       (L"sti.dll,-2002")
#define WIA_ICON_CHANGE_DOCUMENT        (L"sti.dll,-2003")
#define WIA_ICON_UNLOAD_DOCUMENT        (L"sti.dll,-2004")
#define WIA_ICON_DELETE_DEVICE_TREE     (L"sti.dll,-2005")
#define WIA_ICON_BUILD_DEVICE_TREE      (L"sti.dll,-2006")

//**************************************************************************
//
//
//
//      WIA Callbacks
//
//
//
//**************************************************************************

//
//
// IImageTransfer TYMED
//
// IImageTransfer constant, should be added to objidl.idl ???:
//

#define TYMED_CALLBACK                          128

//
// IImageTransfer Callback Status. Messages must be a
// single value
//

#define IT_MSG_DATA_HEADER                      0x0001
#define IT_MSG_DATA                             0x0002
#define IT_MSG_STATUS                           0x0003
#define IT_MSG_TERMINATION                      0x0004
#define IT_MSG_NEW_PAGE                         0x0005

//
//  Flags may be bit field combinations
//

#define IT_STATUS_TRANSFER_FROM_DEVICE          0x0001
#define IT_STATUS_PROCESSING_DATA               0x0002
#define IT_STATUS_TRANSFER_TO_CLIENT            0x0004

//
// IWIAEventCallback codes
//

#define WIA_MAJOR_EVENT_DEVICE_CONNECT          0x01
#define WIA_MAJOR_EVENT_DEVICE_DISCONNECT       0x02
#define WIA_MAJOR_EVENT_PICTURE_TAKEN           0x03
#define WIA_MAJOR_EVENT_PICTURE_DELETED         0x04

//
// device connection status
//

#define  WIA_DEVICE_NOT_CONNECTED               0
#define  WIA_DEVICE_CONNECTED                   1


//**************************************************************************
//
//
//
//      WIA Enumeration Flags
//
//
//
//**************************************************************************

//
// EnumDeviceCapabilities flags
//

#define WIA_DEVICE_COMMANDS 1
#define WIA_DEVICE_EVENTS 2


//
// EnumDeviceInfo Flags
//

#define WIA_DEVINFO_ENUM_LOCAL                  0x00000010


//**************************************************************************
//
//
//
//      WIA Item constants
//
//
//
//**************************************************************************

//
// Item Types
//

#define WiaItemTypeFree                         0x00000000
#define WiaItemTypeImage                        0x00000001
#define WiaItemTypeFile                         0x00000002
#define WiaItemTypeFolder                       0x00000004
#define WiaItemTypeRoot                         0x00000008
#define WiaItemTypeAnalyze                      0x00000010
#define WiaItemTypeAudio                        0x00000020
#define WiaItemTypeDevice                       0x00000040
#define WiaItemTypeDeleted                      0x00000080
#define WiaItemTypeDisconnected                 0x00000100

#define WiaItemTypeMask                         0x000001FF

//
// big max device specific item context, may want smaller
//

#define WIA_MAX_CTX_SIZE                        0x01000000

//**************************************************************************
//
//
//
//      WIA Properties
//
//
//
//**************************************************************************


/*******************************************************************************
//
// WIA_PROPERTY_INFO
//
//   This information is available for every WIA property
//
// Elements
//
//   lSize        - size of this structure
//   lAccessFlags - r/w access of property
//   vt           - vartype of property
//   lInfoType    - info for prop values (none,range,array)
//   Nom          - Nominal(default) value
//   Min          - range min
//   Max          - range max
//   Inc          - range increment
//   cNumList     - number of elements in list
//   pList        - pointer to list of elements
//
//*******************************************************************************/

#define WIA_PROP_READ            0x01
#define WIA_PROP_WRITE           0x02
#define WIA_PROP_RW              WIA_PROP_READ | WIA_PROP_WRITE
#define WIA_PROP_SYNC_REQUIRED   0x04

#define WIA_PROP_NONE            0x08
#define WIA_PROP_RANGE           0x10
#define WIA_PROP_LIST            0x20
#define WIA_PROP_FLAG            0x40

#define WIA_PROP_CACHEABLE       0x10000

//
// Specify that the item can be deleted from the device
//

#define WIA_ITEM_CAN_BE_DELETED  0x80
#define WIA_ITEM_READ            WIA_PROP_READ
#define WIA_ITEM_WRITE           WIA_PROP_WRITE
#define WIA_ITEM_RD              (WIA_ITEM_READ | WIA_ITEM_CAN_BE_DELETED)
#define WIA_ITEM_RWD             (WIA_ITEM_READ | WIA_ITEM_WRITE | WIA_ITEM_CAN_BE_DELETED)


#ifndef __WIAPROP_H_INCLUDED
#define __WIAPROP_H_INCLUDED

//
// Device Information Property ID constants. Device information properties
// are present on all WIA devices. These property values are stored in the
// registry and copied to each device when the device object is created. These
// properties are only written by setup applications and are not writable by
// normal applications
//
//
// ! Remember: all propids must have a string and extension string defined and
//   all properties must be added to the correct array of PROPID/PROPNAMES  in
//   wiapropp.h and the propid/name mapping array: g_wiaPropIdToName. 
//
// 
//

#define WIA_RESERVED_FOR_NEW_PROPS              1024

#define WIA_DIP_FIRST                           2
#define WIA_DIP_DEV_ID                          2
#define WIA_DIP_VEND_DESC                       3
#define WIA_DIP_DEV_DESC                        4
#define WIA_DIP_DEV_TYPE                        5
#define WIA_DIP_PORT_NAME                       6
#define WIA_DIP_DEV_NAME                        7
#define WIA_DIP_SERVER_NAME                     8
#define WIA_DIP_REMOTE_DEV_ID                   9
#define WIA_DIP_UI_CLSID                        10
#define WIA_DIP_LAST                            10

#define WIA_NUM_DIP          1 + WIA_DIP_LAST - WIA_DIP_FIRST

#define WIA_DIP_DEV_ID_STR                      L"Unique Device ID"
#define WIA_DIP_VEND_DESC_STR                   L"Manufacturer"
#define WIA_DIP_DEV_DESC_STR                    L"Description"
#define WIA_DIP_DEV_TYPE_STR                    L"Type"
#define WIA_DIP_PORT_NAME_STR                   L"Port"
#define WIA_DIP_DEV_NAME_STR                    L"Name"
#define WIA_DIP_SERVER_NAME_STR                 L"Server"
#define WIA_DIP_REMOTE_DEV_ID_STR               L"Remote Device ID"
#define WIA_DIP_UI_CLSID_STR                    L"UI Class ID"

//
// constant arrays for device information property init
//

#ifdef WIA_DECLARE_DEVINFO_PROP_ARRAY

PROPSPEC g_psDeviceInfo[WIA_NUM_DIP] =
{
    {PRSPEC_PROPID, WIA_DIP_DEV_ID},
    {PRSPEC_PROPID, WIA_DIP_VEND_DESC},
    {PRSPEC_PROPID, WIA_DIP_DEV_DESC},
    {PRSPEC_PROPID, WIA_DIP_DEV_TYPE},
    {PRSPEC_PROPID, WIA_DIP_PORT_NAME},
    {PRSPEC_PROPID, WIA_DIP_DEV_NAME},
    {PRSPEC_PROPID, WIA_DIP_SERVER_NAME},
    {PRSPEC_PROPID, WIA_DIP_REMOTE_DEV_ID},
    {PRSPEC_PROPID, WIA_DIP_UI_CLSID}
};

PROPID g_piDeviceInfo[WIA_NUM_DIP] =
{
    WIA_DIP_DEV_ID,
    WIA_DIP_VEND_DESC,
    WIA_DIP_DEV_DESC,
    WIA_DIP_DEV_TYPE,
    WIA_DIP_PORT_NAME,
    WIA_DIP_DEV_NAME,
    WIA_DIP_SERVER_NAME,
    WIA_DIP_REMOTE_DEV_ID,
    WIA_DIP_UI_CLSID,
};

LPOLESTR g_pszDeviceInfo[WIA_NUM_DIP] =
{
    WIA_DIP_DEV_ID_STR,
    WIA_DIP_VEND_DESC_STR,
    WIA_DIP_DEV_DESC_STR,
    WIA_DIP_DEV_TYPE_STR,
    WIA_DIP_PORT_NAME_STR,
    WIA_DIP_DEV_NAME_STR,
    WIA_DIP_SERVER_NAME_STR,
    WIA_DIP_REMOTE_DEV_ID_STR,
    WIA_DIP_UI_CLSID_STR,
};

#else

extern PROPSPEC             g_psDeviceInfo[WIA_NUM_DIP];
extern PROPID               g_piDeviceInfo[WIA_NUM_DIP];
extern LPOLESTR             g_pszDeviceInfo[WIA_NUM_DIP];

#endif

//
// In addition to device information properties, wia devices have r/w properties
// associated with both the Device object and the Item object. Device properties
// represent device level information such as connection status, device time,
// current number of items... There are some device properties that would only relate
// to a camera device, such as ShutterSpeed, FocusMode, number of picts remaining.
//

//
// common device properties (DPA)
//

#define WIA_DPA_FIRST                           WIA_DIP_FIRST + WIA_RESERVED_FOR_NEW_PROPS
#define WIA_DPA_FIRMWARE_VERSION                WIA_DPA_FIRST + 0
#define WIA_DPA_CONNECT_STATUS                  WIA_DPA_FIRST + 1
#define WIA_DPA_DEVICE_TIME                     WIA_DPA_FIRST + 2
#define WIA_DPA_LAST                            WIA_DPA_FIRST + 2

#define WIA_DPA_FIRMWARE_VERSION_STR            L"Firmware Version"
#define WIA_DPA_CONNECT_STATUS_STR              L"Connect Status"
#define WIA_DPA_DEVICE_TIME_STR                 L"Device Time"

#define WIA_NUM_DPA  1 + WIA_DPA_LAST - WIA_DPA_FIRST

//
// camera only device properties (DPC)
//

#define WIA_DPC_FIRST                           WIA_DPA_FIRST + WIA_RESERVED_FOR_NEW_PROPS
#define WIA_DPC_PICTURES_TAKEN                  WIA_DPC_FIRST + 0
#define WIA_DPC_PICTURES_REMAINING              WIA_DPC_FIRST + 1
#define WIA_DPC_EXPOSURE_MODE                   WIA_DPC_FIRST + 2
#define WIA_DPC_EXPOSURE_COMP                   WIA_DPC_FIRST + 3
#define WIA_DPC_EXPOSURE_TIME                   WIA_DPC_FIRST + 4
#define WIA_DPC_FNUMBER                         WIA_DPC_FIRST + 5
#define WIA_DPC_FLASH_MODE                      WIA_DPC_FIRST + 6
#define WIA_DPC_FOCUS_MODE                      WIA_DPC_FIRST + 7
#define WIA_DPC_FOCUS_MANUAL_DIST               WIA_DPC_FIRST + 8
#define WIA_DPC_ZOOM_POSITION                   WIA_DPC_FIRST + 9
#define WIA_DPC_PAN_POSITION                    WIA_DPC_FIRST + 10
#define WIA_DPC_TILT_POSITION                   WIA_DPC_FIRST + 11
#define WIA_DPC_TIMER_MODE                      WIA_DPC_FIRST + 12
#define WIA_DPC_TIMER_VALUE                     WIA_DPC_FIRST + 13
#define WIA_DPC_POWER_MODE                      WIA_DPC_FIRST + 14
#define WIA_DPC_BATTERY_STATUS                  WIA_DPC_FIRST + 15
#define WIA_DPC_THUMB_WIDTH                     WIA_DPC_FIRST + 16
#define WIA_DPC_THUMB_HEIGHT                    WIA_DPC_FIRST + 17
#define WIA_DPC_PICT_WIDTH                      WIA_DPC_FIRST + 18
#define WIA_DPC_PICT_HEIGHT                     WIA_DPC_FIRST + 19
#define WIA_DPC_LAST                            WIA_DPC_FIRST + 20

#define WIA_NUM_DPC              1 + WIA_DPC_LAST - WIA_DPC_FIRST

#define WIA_DPC_PICTURES_TAKEN_STR              L"Pictures Taken"
#define WIA_DPC_PICTURES_REMAINING_STR          L"Pictures Remaining"
#define WIA_DPC_EXPOSURE_MODE_STR               L"Exposure Mode"
#define WIA_DPC_EXPOSURE_COMP_STR               L"Exposure Compensation"
#define WIA_DPC_EXPOSURE_TIME_STR               L"Exposure Time"
#define WIA_DPC_FNUMBER_STR                     L"F Number"
#define WIA_DPC_FLASH_MODE_STR                  L"Flash Mode"
#define WIA_DPC_FOCUS_MODE_STR                  L"Focus Mode"
#define WIA_DPC_FOCUS_MANUAL_DIST_STR           L"Focus Manual Dist"
#define WIA_DPC_ZOOM_POSITION_STR               L"Zoom Position"
#define WIA_DPC_PAN_POSITION_STR                L"Pan Position"
#define WIA_DPC_TILT_POSITION_STR               L"Tilt Position"
#define WIA_DPC_TIMER_MODE_STR                  L"Timer Mode"
#define WIA_DPC_TIMER_VALUE_STR                 L"Timer Value"
#define WIA_DPC_POWER_MODE_STR                  L"Power Mode"
#define WIA_DPC_BATTERY_STATUS_STR              L"Battery Status"
#define WIA_DPC_THUMB_WIDTH_STR                 L"Thumbnail Width"
#define WIA_DPC_THUMB_HEIGHT_STR                L"Thumbnail Height"
#define WIA_DPC_PICT_WIDTH_STR                  L"Picture Width"
#define WIA_DPC_PICT_HEIGHT_STR                 L"Picture Height"

//
// Scanner only device properties (DPS)
//

#define WIA_DPS_FIRST                          WIA_DPC_FIRST + WIA_RESERVED_FOR_NEW_PROPS
#define WIA_DPS_HORIZONTAL_BED_SIZE            WIA_DPS_FIRST + 0
#define WIA_DPS_VERTICAL_BED_SIZE              WIA_DPS_FIRST + 1
#define WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE     WIA_DPS_FIRST + 2
#define WIA_DPS_VERTICAL_SHEET_FEED_SIZE       WIA_DPS_FIRST + 3
#define WIA_DPS_SHEET_FEEDER_REGISTRATION      WIA_DPS_FIRST + 4
#define WIA_DPS_HORIZONTAL_BED_REGISTRATION    WIA_DPS_FIRST + 5
#define WIA_DPS_VERTICAL_BED_REGISTRATION      WIA_DPS_FIRST + 6
#define WIA_DPS_PLATEN_COLOR                   WIA_DPS_FIRST + 7
#define WIA_DPS_PAD_COLOR                      WIA_DPS_FIRST + 8
#define WIA_DPS_FILTER_SELECT                  WIA_DPS_FIRST + 9
#define WIA_DPS_DITHER_SELECT                  WIA_DPS_FIRST + 10
#define WIA_DPS_DITHER_PATTERN_DATA            WIA_DPS_FIRST + 11
#define WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES WIA_DPS_FIRST + 12
#define WIA_DPS_DOCUMENT_HANDLING_STATUS       WIA_DPS_FIRST + 13
#define WIA_DPS_DOCUMENT_HANDLING_SELECT       WIA_DPS_FIRST + 14
#define WIA_DPS_DOCUMENT_HANDLING_CAPACITY     WIA_DPS_FIRST + 15
#define WIA_DPS_OPTICAL_XRES                   WIA_DPS_FIRST + 16
#define WIA_DPS_OPTICAL_YRES                   WIA_DPS_FIRST + 17
#define WIA_DPS_ENDORSER_CHARACTERS            WIA_DPS_FIRST + 18
#define WIA_DPS_ENDORSER_STRING                WIA_DPS_FIRST + 19
#define WIA_DPS_SCAN_AHEAD_PAGES               WIA_DPS_FIRST + 20
#define WIA_DPS_MAX_SCAN_TIME                  WIA_DPS_FIRST + 21
#define WIA_DPS_PAGES                          WIA_DPS_FIRST + 22
#define WIA_DPS_PAGE_SIZE                      WIA_DPS_FIRST + 23
#define WIA_DPS_PAGE_WIDTH                     WIA_DPS_FIRST + 24
#define WIA_DPS_PAGE_HEIGHT                    WIA_DPS_FIRST + 25
#define WIA_DPS_LAST                           WIA_DPS_FIRST + 25

#define WIA_NUM_DPS          1 + WIA_DPS_LAST - WIA_DPS_FIRST

#define WIA_DPS_HORIZONTAL_BED_SIZE_STR                L"Horizontal Bed Size"
#define WIA_DPS_VERTICAL_BED_SIZE_STR                  L"Vertical Bed Size"
#define WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE_STR         L"Horizontal Sheet Feed Size"
#define WIA_DPS_VERTICAL_SHEET_FEED_SIZE_STR           L"Vertical Sheet Feed Size"
#define WIA_DPS_SHEET_FEEDER_REGISTRATION_STR          L"Sheet Feeder Registration"
#define WIA_DPS_HORIZONTAL_BED_REGISTRATION_STR        L"Horizontal Bed Registration"
#define WIA_DPS_VERTICAL_BED_REGISTRATION_STR          L"Vertical Bed Registration"
#define WIA_DPS_PLATEN_COLOR_STR                       L"Platen Color"
#define WIA_DPS_PAD_COLOR_STR                          L"Pad Color"
#define WIA_DPS_FILTER_SELECT_STR                      L"Filter Select"
#define WIA_DPS_DITHER_SELECT_STR                      L"Dither Select"
#define WIA_DPS_DITHER_PATTERN_DATA_STR                L"Dither Pattern Data"
#define WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_STR     L"Document Handling Capabilities"
#define WIA_DPS_DOCUMENT_HANDLING_STATUS_STR           L"Document Handling Status"
#define WIA_DPS_DOCUMENT_HANDLING_SELECT_STR           L"Document Handling Select"
#define WIA_DPS_DOCUMENT_HANDLING_CAPACITY_STR         L"Document Handling Capacity"
#define WIA_DPS_OPTICAL_XRES_STR                       L"Horizontal Optical Resolution"
#define WIA_DPS_OPTICAL_YRES_STR                       L"Vertical Optical Resolution"
#define WIA_DPS_ENDORSER_CHARACTERS_STR                L"Endorser Characters"
#define WIA_DPS_ENDORSER_STRING_STR                    L"Endorser String"
#define WIA_DPS_SCAN_AHEAD_PAGES_STR                   L"Scan Ahead Pages"
#define WIA_DPS_MAX_SCAN_TIME_STR                      L"Max Scan Time"
#define WIA_DPS_PAGES_STR                              L"Pages"
#define WIA_DPS_PAGE_SIZE_STR                          L"Page Size"
#define WIA_DPS_PAGE_WIDTH_STR                         L"Page Width"
#define WIA_DPS_PAGE_HEIGHT_STR                        L"Page Height"

//
// Constants used with scanner only device properties (DPS)
//

//
// WIA_DPS_SHEET_FEEDER_REGISTRATION and
// WIA_DPS_HORIZONTAL_BED_REGISTRATION constants:
//

#define  LEFT_JUSTIFIED             0
#define  CENTERED                   1
#define  RIGHT_JUSTIFIED            2

//
// WIA_DPS_VERTICAL_BED_REGISTRATION constants:
//

#define  TOP_JUSTIFIED              0
#define  CENTERED                   1
#define  BOTTOM_JUSTIFIED           2

//
// WIA_DPS_ORIENTATION and WIA_DPS_ROTATION constants:
//

#define  PORTRAIT                   0
#define  LANSCAPE                   1
#define  ROT180                     2
#define  ROT270                     3

//
// WIA_DPS_MIRROR flags:
//

#define  MIRRORED                   0x01

//
// WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES flags:
//

#define  FEED                       0x01
#define  FLAT                       0x02
#define  DETECT_FLAT                0x04
#define  DETECT_SCAN                0x08
#define  DETECT_FEED                0x10
#define  DETECT_DUP                 0x20

//
// WIA_DPS_DOCUMENT_HANDLING_STATUS flags:
//

#define  FEED_READY                 0x01
#define  FLAT_READY                 0x02
#define  DUP_READY                  0x04
#define  FLAT_COVER_UP              0x08
#define  PATH_COVER_UP              0x10
#define  PAPER_JAM                  0x20

//
// WIA_DPS_DOCUMENT_HANDLING_SELECT flags:
//

#define  FEEDER                     0x001
#define  FLATBED                    0x002
#define  DUPLEX                     0x004
#define  FRONT_FIRST                0x008
#define  BACK_FIRST                 0x010
#define  FRONT_ONLY                 0x020
#define  BACK_ONLY                  0x040
#define  NEXT_PAGE                  0x080
#define  PREFEED                    0x100
#define  AUTO_ADVANCE               0x200

//
// WIA_DPS_SCAN_AHEAD_PAGES constants:
//

#define  WIA_SCAN_AHEAD_ALL         0


//
// WIA_DPS_PAGES constants:
//

#define  ALL_PAGES                  0


//
// Common WIA Item properties. Item properties are used
// to determine characteristics of the item and/or to set preferences
// for item acquisition
//

#define WIA_IPA_FIRST                          WIA_DPS_FIRST + WIA_RESERVED_FOR_NEW_PROPS
#define WIA_IPA_ITEM_NAME                      WIA_IPA_FIRST + 0
#define WIA_IPA_FULL_ITEM_NAME                 WIA_IPA_FIRST + 1
#define WIA_IPA_ITEM_TIME                      WIA_IPA_FIRST + 2
#define WIA_IPA_ITEM_FLAGS                     WIA_IPA_FIRST + 3
#define WIA_IPA_ACCESS_RIGHTS                  WIA_IPA_FIRST + 4
#define WIA_IPA_DATATYPE                       WIA_IPA_FIRST + 5
#define WIA_IPA_DEPTH                          WIA_IPA_FIRST + 6
#define WIA_IPA_PREFERRED_FORMAT               WIA_IPA_FIRST + 7
#define WIA_IPA_FORMAT                         WIA_IPA_FIRST + 8
#define WIA_IPA_COMPRESSION                    WIA_IPA_FIRST + 9
#define WIA_IPA_TYMED                          WIA_IPA_FIRST + 10
#define WIA_IPA_CHANNELS_PER_PIXEL             WIA_IPA_FIRST + 11
#define WIA_IPA_BITS_PER_CHANNEL               WIA_IPA_FIRST + 12
#define WIA_IPA_PLANAR                         WIA_IPA_FIRST + 13
#define WIA_IPA_PIXELS_PER_LINE                WIA_IPA_FIRST + 14
#define WIA_IPA_BYTES_PER_LINE                 WIA_IPA_FIRST + 15
#define WIA_IPA_NUMBER_OF_LINES                WIA_IPA_FIRST + 16
#define WIA_IPA_GAMMA_CURVES                   WIA_IPA_FIRST + 17
#define WIA_IPA_ITEM_SIZE                      WIA_IPA_FIRST + 18
#define WIA_IPA_COLOR_PROFILE                  WIA_IPA_FIRST + 19
#define WIA_IPA_MIN_BUFFER_SIZE                WIA_IPA_FIRST + 20
#define WIA_IPA_REGION_TYPE                    WIA_IPA_FIRST + 21
#define WIA_IPA_LAST                           WIA_IPA_FIRST + 21

#define  WIA_NUM_IPA         1 + WIA_IPA_LAST - WIA_IPA_FIRST

#define  WIA_IPA_ITEM_NAME_STR                  L"Item Name"
#define  WIA_IPA_FULL_ITEM_NAME_STR             L"Full Item Name"
#define  WIA_IPA_ITEM_TIME_STR                  L"Item Time Stamp"
#define  WIA_IPA_ITEM_FLAGS_STR                 L"Item Flags"
#define  WIA_IPA_ACCESS_RIGHTS_STR              L"Access Rights"
#define  WIA_IPA_DATATYPE_STR                   L"Data Type"
#define  WIA_IPA_DEPTH_STR                      L"Bits Per Pixel"
#define  WIA_IPA_PREFERRED_FORMAT_STR           L"Preferred Format"
#define  WIA_IPA_FORMAT_STR                     L"Format"
#define  WIA_IPA_COMPRESSION_STR                L"Compression"
#define  WIA_IPA_TYMED_STR                      L"Media Type"
#define  WIA_IPA_CHANNELS_PER_PIXEL_STR         L"Channels Per Pixel"
#define  WIA_IPA_BITS_PER_CHANNEL_STR           L"Bits Per Channel"
#define  WIA_IPA_PLANAR_STR                     L"Planar"
#define  WIA_IPA_PIXELS_PER_LINE_STR            L"Pixels Per Line"
#define  WIA_IPA_BYTES_PER_LINE_STR             L"Bytes Per Line"
#define  WIA_IPA_NUMBER_OF_LINES_STR            L"Number of Lines"
#define  WIA_IPA_GAMMA_CURVES_STR               L"Gamma Curves"
#define  WIA_IPA_ITEM_SIZE_STR                  L"Item Size"
#define  WIA_IPA_COLOR_PROFILE_STR              L"Color Profiles"
#define  WIA_IPA_MIN_BUFFER_SIZE_STR            L"Minimum Buffer Size"
#define  WIA_IPA_REGION_TYPE_STR                L"Region Type"

//                                              
// Constants used with the WIA item properties: 
//

//
//  Page size constants
//

#define WIA_PAGE_A4         0
#define WIA_PAGE_LETTER     1
#define WIA_PAGE_CUSTOM     2

#define WIA_PAGE_LETTER_WIDTH       8500
#define WIA_PAGE_LETTER_HEIGHT      10500


//
//  FORMAT FLAGS constants:
//

#define WIA_TOPDOWN                 0x00000001  // biHeight must be negative
#define WIA_BOTTOMUP                0x00000002  // biHeight must be positive

//
// temp new format defn
//
// !!! These definitions need to be merged with OS definitions
// of clipformat ???
//

#define CF_JPEG                                 19
#define CF_TOPDOWN_DIB                          20
#define CF_BOTTOMUP_DIB                         CF_DIB
#define CF_MULTI_TIFF                           22

//
// WIA_IPA_COMPRESSION constants:
//

#define WIA_COMPRESSION_NONE        0
#define WIA_COMPRESSION_BI_RLE4     1
#define WIA_COMPRESSION_BI_RLE8     2
#define WIA_COMPRESSION_G3          3

//
// planar -vs- packed
//

#define WIA_PACKED_PIXEL            0
#define WIA_PLANAR                  1

//
// Constants for DataType property
//

#define WIA_DATA_THRESHOLD                      0
#define WIA_DATA_DITHER                         1
#define WIA_DATA_GRAYSCALE                      2
#define WIA_DATA_COLOR                          3
#define WIA_DATA_COLOR_THRESHOLD                4
#define WIA_DATA_COLOR_DITHER                   5

//
// camera specific item properties IPC
//

#define WIA_IPC_FIRST                          WIA_IPA_FIRST + WIA_RESERVED_FOR_NEW_PROPS
#define WIA_IPC_THUMBNAIL                      WIA_IPC_FIRST + 0
#define WIA_IPC_THUMB_WIDTH                    WIA_IPC_FIRST + 1
#define WIA_IPC_THUMB_HEIGHT                   WIA_IPC_FIRST + 2
#define WIA_IPC_AUDIO_AVAILABLE                WIA_IPC_FIRST + 3
#define WIA_IPC_AUDIO_DATA_FORMAT              WIA_IPC_FIRST + 4
#define WIA_IPC_AUDIO_DATA                     WIA_IPC_FIRST + 5
#define WIA_IPC_LAST                           WIA_IPC_FIRST + 5

#define WIA_NUM_IPC         1 + WIA_IPC_LAST - WIA_IPC_FIRST

#define WIA_IPC_THUMBNAIL_STR                  L"Thumbnail Data"
#define WIA_IPC_THUMB_WIDTH_STR                L"Thumbnail Width"
#define WIA_IPC_THUMB_HEIGHT_STR               L"Thumbnail Height"
#define WIA_IPC_AUDIO_AVAILABLE_STR            L"Audio Available"
#define WIA_IPC_AUDIO_DATA_FORMAT_STR          L"Audio Format"
#define WIA_IPC_AUDIO_DATA_STR                 L"Audio Data"


//
// Scanner specific Item properties IPS
//
#define WIA_IPS_FIRST                          WIA_IPC_FIRST + WIA_RESERVED_FOR_NEW_PROPS
#define WIA_IPS_CUR_INTENT                     WIA_IPS_FIRST + 0
#define WIA_IPS_XRES                           WIA_IPS_FIRST + 1
#define WIA_IPS_YRES                           WIA_IPS_FIRST + 2 
#define WIA_IPS_XPOS                           WIA_IPS_FIRST + 3 
#define WIA_IPS_YPOS                           WIA_IPS_FIRST + 4 
#define WIA_IPS_XEXTENT                        WIA_IPS_FIRST + 5 
#define WIA_IPS_YEXTENT                        WIA_IPS_FIRST + 6 
#define WIA_IPS_PHOTOMETRIC_INTERP             WIA_IPS_FIRST + 7 
#define WIA_IPS_BRIGHTNESS                     WIA_IPS_FIRST + 8 
#define WIA_IPS_CONTRAST                       WIA_IPS_FIRST + 9 
#define WIA_IPS_ORIENTATION                    WIA_IPS_FIRST + 10 
#define WIA_IPS_ROTATION                       WIA_IPS_FIRST + 11 
#define WIA_IPS_MIRROR                         WIA_IPS_FIRST + 12
#define WIA_IPS_THRESHOLD                      WIA_IPS_FIRST + 13
#define WIA_IPS_LAST                           WIA_IPS_FIRST + 13

#define WIA_NUM_IPS         1 + WIA_IPS_LAST - WIA_IPS_FIRST

#define WIA_IPS_CUR_INTENT_STR                 L"Current Intent"
#define WIA_IPS_XRES_STR                       L"Horizontal Resolution"
#define WIA_IPS_YRES_STR                       L"Vertical Resolution"
#define WIA_IPS_XPOS_STR                       L"Horizontal Start Position"
#define WIA_IPS_YPOS_STR                       L"Vertical Start Position"
#define WIA_IPS_XEXTENT_STR                    L"Horizontal Extent"
#define WIA_IPS_YEXTENT_STR                    L"Vertical Extent"
#define WIA_IPS_PHOTOMETRIC_INTERP_STR         L"Photometric Interpretation"
#define WIA_IPS_BRIGHTNESS_STR                 L"Brightness"
#define WIA_IPS_CONTRAST_STR                   L"Contrast"
#define WIA_IPS_ORIENTATION_STR                L"Orientation"
#define WIA_IPS_ROTATION_STR                   L"Rotation"
#define WIA_IPS_MIRROR_STR                     L"Mirror"
#define WIA_IPS_THRESHOLD_STR                  L"Threshold"

//
// WIA_IPA_BRIGHTNESS  constants:
//

#define  BRIGHTNESS_LIGHT           -1
#define  BRIGHTNESS_AUTO            -2
#define  BRIGHTNESS_NORM            -3
#define  BRIGHTNESS_DARK            -4

//
// WIA_IPA_CONTRAST  constants:
//

#define  CONTRAST_AUTO              -1

//
// WIA property itendifier. WIA extended properties give information
// about the possible values the property may be set to.
// Min, Max, Step are used to set up a range of legal values
// Nom represents the default(nominal) value
// Index constants for accessing range values from array.
//

#define  WIA_RANGE_MIN                          0
#define  WIA_RANGE_NOM                          1
#define  WIA_RANGE_MAX                          2
#define  WIA_RANGE_STEP                         3
#define  WIA_RANGE_NUM_ELEMS                    4

#define  WIA_LIST_COUNT                         0
#define  WIA_LIST_NOM                           1
#define  WIA_LIST_VALUES                        2
#define  WIA_LIST_NUM_ELEMS                     2

#define  WIA_FLAG_NOM                           0
#define  WIA_FLAG_VALUES                        1
#define  WIA_FLAG_NUM_ELEMS                     2

//
// Intent image type constants
// To provide an intent, use an image type and a size/quality flags or'ed together.
// Both flags are optional, the driver or acquisition UI will provide defaults if either is
// not present
//
                            
#define WIA_INTENT_NONE                 0x00000000
#define WIA_INTENT_IMAGE_TYPE_COLOR     0x00000001
#define WIA_INTENT_IMAGE_TYPE_GRAYSCALE 0x00000002
#define WIA_INTENT_IMAGE_TYPE_TEXT      0x00000004
#define WIA_INTENT_IMAGE_TYPE_MASK      0x0000000F

//
// Intent size / quality constants
//
#define WIA_INTENT_MINIMIZE_SIZE        0x00010000
#define WIA_INTENT_MAXIMIZE_QUALITY     0x00020000
#define WIA_INTENT_SIZE_MASK            0x000F0000

#define WIA_INTENT_USER                         100

//
// remote Device info DIP
//

#define WIA_PRIVATE_DEVPROP                     4096
#define WIA_PRIVATE_ITEMPROP                    4096


//
// Property ID to name string mapping
//

#ifdef DEFINE_WIA_PROPID_TO_NAME

WIA_PROPID_TO_NAME g_wiaPropIdToName[] = 
{
    {WIA_DIP_DEV_ID,                          WIA_DIP_DEV_ID_STR},
    {WIA_DIP_VEND_DESC,                       WIA_DIP_VEND_DESC_STR},
    {WIA_DIP_DEV_DESC,                        WIA_DIP_DEV_DESC_STR},
    {WIA_DIP_DEV_TYPE,                        WIA_DIP_DEV_TYPE_STR},
    {WIA_DIP_PORT_NAME,                       WIA_DIP_PORT_NAME_STR},
    {WIA_DIP_DEV_NAME,                        WIA_DIP_DEV_NAME_STR},
    {WIA_DIP_SERVER_NAME,                     WIA_DIP_SERVER_NAME_STR},
    {WIA_DIP_REMOTE_DEV_ID,                   WIA_DIP_REMOTE_DEV_ID_STR},
    {WIA_DIP_UI_CLSID,                        WIA_DIP_UI_CLSID_STR},
    {WIA_DPA_FIRMWARE_VERSION,                WIA_DPA_FIRMWARE_VERSION_STR},
    {WIA_DPA_CONNECT_STATUS,                  WIA_DPA_CONNECT_STATUS_STR},
    {WIA_DPA_DEVICE_TIME,                     WIA_DPA_DEVICE_TIME_STR},
    {WIA_DPC_PICTURES_TAKEN,                  WIA_DPC_PICTURES_TAKEN_STR},
    {WIA_DPC_PICTURES_REMAINING,              WIA_DPC_PICTURES_REMAINING_STR},
    {WIA_DPC_EXPOSURE_MODE,                   WIA_DPC_EXPOSURE_MODE_STR},
    {WIA_DPC_EXPOSURE_COMP,                   WIA_DPC_EXPOSURE_COMP_STR},
    {WIA_DPC_EXPOSURE_TIME,                   WIA_DPC_EXPOSURE_TIME_STR},
    {WIA_DPC_FNUMBER,                         WIA_DPC_FNUMBER_STR},
    {WIA_DPC_FLASH_MODE,                      WIA_DPC_FLASH_MODE_STR},
    {WIA_DPC_FOCUS_MODE,                      WIA_DPC_FOCUS_MODE_STR},
    {WIA_DPC_FOCUS_MANUAL_DIST,               WIA_DPC_FOCUS_MANUAL_DIST_STR},
    {WIA_DPC_ZOOM_POSITION,                   WIA_DPC_ZOOM_POSITION_STR},
    {WIA_DPC_PAN_POSITION,                    WIA_DPC_PAN_POSITION_STR},
    {WIA_DPC_TILT_POSITION,                   WIA_DPC_TILT_POSITION_STR},
    {WIA_DPC_TIMER_MODE,                      WIA_DPC_TIMER_MODE_STR},
    {WIA_DPC_TIMER_VALUE,                     WIA_DPC_TIMER_VALUE_STR},
    {WIA_DPC_POWER_MODE,                      WIA_DPC_POWER_MODE_STR},
    {WIA_DPC_BATTERY_STATUS,                  WIA_DPC_BATTERY_STATUS_STR},
    {WIA_DPS_HORIZONTAL_BED_SIZE,             WIA_DPS_HORIZONTAL_BED_SIZE_STR},
    {WIA_DPS_VERTICAL_BED_SIZE,               WIA_DPS_VERTICAL_BED_SIZE_STR},
    {WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE,      WIA_DPS_HORIZONTAL_SHEET_FEED_SIZE_STR},
    {WIA_DPS_VERTICAL_SHEET_FEED_SIZE,        WIA_DPS_VERTICAL_SHEET_FEED_SIZE_STR},
    {WIA_DPS_SHEET_FEEDER_REGISTRATION,       WIA_DPS_SHEET_FEEDER_REGISTRATION_STR},
    {WIA_DPS_HORIZONTAL_BED_REGISTRATION,     WIA_DPS_HORIZONTAL_BED_REGISTRATION_STR},
    {WIA_DPS_VERTICAL_BED_REGISTRATION,       WIA_DPS_VERTICAL_BED_REGISTRATION_STR},
    {WIA_DPS_PLATEN_COLOR,                    WIA_DPS_PLATEN_COLOR_STR},
    {WIA_DPS_PAD_COLOR,                       WIA_DPS_PAD_COLOR_STR},
    {WIA_DPS_FILTER_SELECT,                   WIA_DPS_FILTER_SELECT_STR},
    {WIA_DPS_DITHER_SELECT,                   WIA_DPS_DITHER_SELECT_STR},
    {WIA_DPS_DITHER_PATTERN_DATA,             WIA_DPS_DITHER_PATTERN_DATA_STR},
    {WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES,  WIA_DPS_DOCUMENT_HANDLING_CAPABILITIES_STR},
    {WIA_DPS_DOCUMENT_HANDLING_STATUS,        WIA_DPS_DOCUMENT_HANDLING_STATUS_STR},
    {WIA_DPS_DOCUMENT_HANDLING_SELECT,        WIA_DPS_DOCUMENT_HANDLING_SELECT_STR},
    {WIA_DPS_DOCUMENT_HANDLING_CAPACITY,      WIA_DPS_DOCUMENT_HANDLING_CAPACITY_STR},
    {WIA_DPS_OPTICAL_XRES,                    WIA_DPS_OPTICAL_XRES_STR},
    {WIA_DPS_OPTICAL_YRES,                    WIA_DPS_OPTICAL_YRES_STR},
    {WIA_DPS_ENDORSER_CHARACTERS,             WIA_DPS_ENDORSER_CHARACTERS_STR},
    {WIA_DPS_ENDORSER_STRING,                 WIA_DPS_ENDORSER_STRING_STR},
    {WIA_DPS_SCAN_AHEAD_PAGES,                WIA_DPS_SCAN_AHEAD_PAGES_STR},
    {WIA_DPS_MAX_SCAN_TIME,                   WIA_DPS_MAX_SCAN_TIME_STR},
    {WIA_DPS_PAGES,                           WIA_DPS_PAGES_STR},
    {WIA_DPS_PAGE_SIZE,                       WIA_DPS_PAGE_SIZE_STR},
    {WIA_DPS_PAGE_WIDTH,                      WIA_DPS_PAGE_WIDTH_STR},
    {WIA_DPS_PAGE_HEIGHT,                     WIA_DPS_PAGE_HEIGHT_STR},
    {WIA_IPA_ITEM_NAME,                       WIA_IPA_ITEM_NAME_STR},
    {WIA_IPA_FULL_ITEM_NAME,                  WIA_IPA_FULL_ITEM_NAME_STR},
    {WIA_IPA_ITEM_TIME,                       WIA_IPA_ITEM_TIME_STR},
    {WIA_IPA_ITEM_FLAGS,                      WIA_IPA_ITEM_FLAGS_STR},
    {WIA_IPA_ACCESS_RIGHTS,                   WIA_IPA_ACCESS_RIGHTS_STR},
    {WIA_IPA_DATATYPE,                        WIA_IPA_DATATYPE_STR},
    {WIA_IPA_DEPTH,                           WIA_IPA_DEPTH_STR},
    {WIA_IPA_PREFERRED_FORMAT,                WIA_IPA_PREFERRED_FORMAT_STR},
    {WIA_IPA_FORMAT,                          WIA_IPA_FORMAT_STR},
    {WIA_IPA_COMPRESSION,                     WIA_IPA_COMPRESSION_STR},
    {WIA_IPA_TYMED,                           WIA_IPA_TYMED_STR},
    {WIA_IPA_CHANNELS_PER_PIXEL,              WIA_IPA_CHANNELS_PER_PIXEL_STR},
    {WIA_IPA_BITS_PER_CHANNEL,                WIA_IPA_BITS_PER_CHANNEL_STR},
    {WIA_IPA_PLANAR,                          WIA_IPA_PLANAR_STR},
    {WIA_IPA_PIXELS_PER_LINE,                 WIA_IPA_PIXELS_PER_LINE_STR},
    {WIA_IPA_BYTES_PER_LINE,                  WIA_IPA_BYTES_PER_LINE_STR},
    {WIA_IPA_NUMBER_OF_LINES,                 WIA_IPA_NUMBER_OF_LINES_STR},
    {WIA_IPA_GAMMA_CURVES,                    WIA_IPA_GAMMA_CURVES_STR},
    {WIA_IPA_ITEM_SIZE,                       WIA_IPA_ITEM_SIZE_STR},
    {WIA_IPA_COLOR_PROFILE,                   WIA_IPA_COLOR_PROFILE_STR},
    {WIA_IPA_MIN_BUFFER_SIZE,                 WIA_IPA_MIN_BUFFER_SIZE_STR},
    {WIA_IPA_REGION_TYPE,                     WIA_IPA_REGION_TYPE_STR},
    {WIA_IPC_THUMBNAIL,                       WIA_IPC_THUMBNAIL_STR},
    {WIA_IPC_THUMB_WIDTH,                     WIA_IPC_THUMB_WIDTH_STR},
    {WIA_IPC_THUMB_HEIGHT,                    WIA_IPC_THUMB_HEIGHT_STR},
    {WIA_IPC_AUDIO_AVAILABLE,                 WIA_IPC_AUDIO_AVAILABLE_STR},
    {WIA_IPC_AUDIO_DATA_FORMAT,               WIA_IPC_AUDIO_DATA_FORMAT_STR},
    {WIA_IPC_AUDIO_DATA,                      WIA_IPC_AUDIO_DATA_STR},
    {WIA_IPS_CUR_INTENT,                      WIA_IPS_CUR_INTENT_STR},
    {WIA_IPS_XRES,                            WIA_IPS_XRES_STR},
    {WIA_IPS_YRES,                            WIA_IPS_YRES_STR},
    {WIA_IPS_XPOS,                            WIA_IPS_XPOS_STR},
    {WIA_IPS_YPOS,                            WIA_IPS_YPOS_STR},
    {WIA_IPS_XEXTENT,                         WIA_IPS_XEXTENT_STR},
    {WIA_IPS_YEXTENT,                         WIA_IPS_YEXTENT_STR},
    {WIA_IPS_PHOTOMETRIC_INTERP,              WIA_IPS_PHOTOMETRIC_INTERP_STR},
    {WIA_IPS_BRIGHTNESS,                      WIA_IPS_BRIGHTNESS_STR},
    {WIA_IPS_CONTRAST,                        WIA_IPS_CONTRAST_STR},
    {WIA_IPS_ORIENTATION,                     WIA_IPS_ORIENTATION_STR},
    {WIA_IPS_ROTATION,                        WIA_IPS_ROTATION_STR},
    {WIA_IPS_MIRROR,                          WIA_IPS_MIRROR_STR},
    {WIA_IPS_THRESHOLD,                       WIA_IPS_THRESHOLD_STR},
    {0,                                       L"Not a WIA property"}
};

#endif
#endif //WIAPROP_H_INCLUDED

 
 
//
//   Macro Helpers
//

#define WIA_PROP_LIST_COUNT(ppv) (((PROPVARIANT*)ppv)->cal.cElems - WIA_LIST_VALUES) 

#define WIA_PROP_LIST_VALUE(ppv, index)                              \\
     ((index > ((PROPVARIANT*) ppv)->cal.cElems - WIA_LIST_VALUES) || (index < -WIA_LIST_NOM)) ?\\
     NULL :                                                          \\
     (((PROPVARIANT*) ppv)->vt == VT_UI1) ?                          \\
     ((PROPVARIANT*) ppv)->caub.pElems[WIA_LIST_VALUES + index] :    \\
     (((PROPVARIANT*) ppv)->vt == VT_UI2) ?                          \\
     ((PROPVARIANT*) ppv)->caui.pElems[WIA_LIST_VALUES + index] :    \\
     (((PROPVARIANT*) ppv)->vt == VT_UI4) ?                          \\
     ((PROPVARIANT*) ppv)->caul.pElems[WIA_LIST_VALUES + index] :    \\
     (((PROPVARIANT*) ppv)->vt == VT_I2) ?                           \\
     ((PROPVARIANT*) ppv)->cai.pElems[WIA_LIST_VALUES + index] :     \\
     (((PROPVARIANT*) ppv)->vt == VT_I4) ?                           \\
     ((PROPVARIANT*) ppv)->cal.pElems[WIA_LIST_VALUES + index] :     \\
     (((PROPVARIANT*) ppv)->vt == VT_R4) ?                           \\
     ((PROPVARIANT*) ppv)->caflt.pElems[WIA_LIST_VALUES + index] :   \\
     (((PROPVARIANT*) ppv)->vt == VT_R8) ?                           \\
     ((PROPVARIANT*) ppv)->cadbl.pElems[WIA_LIST_VALUES + index] :   \\
     (((PROPVARIANT*) ppv)->vt == VT_BSTR) ?                         \\
     (LONG)(((PROPVARIANT*) ppv)->cabstr.pElems[WIA_LIST_VALUES + index]) : \\
     NULL


//
//   End of Macro Helpers
//

#pragma option pop /*P_O_Pop*/
