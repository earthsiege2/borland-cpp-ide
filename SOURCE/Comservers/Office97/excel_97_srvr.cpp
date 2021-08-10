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

// C++ TLBWRTR : $Revision:   1.0.2.3  $
// File generated on 1/24/2000 9:48:16 AM from Type Library described below.

// ************************************************************************ //
// Type Lib: g:\rampage\typelib\TypeLibraries\EXCEL8.olb (1)
// IID\LCID: {00020813-0000-0000-C000-000000000046}\0
// Helpfile: g:\rampage\typelib\TypeLibraries\VBAXL8.HLP
// DepndLst: 
//   (1) v2.0 Office, (D:\Program Files\Microsoft Office\Office\MSO97.DLL)
//   (2) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (3) v5.0 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBEEXT1.OLB)
//   (4) v4.0 StdVCL, (C:\WINNT\System32\STDVCL40.DLL)
// Errors:
//   Hint: Symbol 'IFont' renamed to 'ExcelIFont'
//   Hint: Symbol 'Window' renamed to 'WINDOW'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'QueryTable' renamed to 'ExcelQueryTable'
//   Hint: Symbol 'Application' renamed to 'ExcelApplication'
//   Hint: Symbol 'Chart' renamed to 'ExcelChart'
//   Hint: Symbol 'Worksheet' renamed to 'ExcelWorksheet'
//   Hint: Symbol 'Global' renamed to 'ExcelGlobal'
//   Hint: Symbol 'Workbook' renamed to 'ExcelWorkbook'
//   Hint: Symbol 'OLEObject' renamed to 'ExcelOLEObject'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Enum Member 'XlDisplayShapes' of 'XlDisplayShapes' changed to 'XlDisplayShapes_'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'DialogBox' renamed to 'DialogBOX'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'DialogBox' renamed to 'DialogBOX'
//   Hint: Member 'Range' of 'Range' changed to 'Range_'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Member 'Name' of 'Name' changed to 'Name_'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'IFont' renamed to 'ExcelIFont'
//   Hint: Symbol 'Window' renamed to 'WINDOW'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'QueryTable' renamed to 'ExcelQueryTable'
//   Hint: Symbol 'Application' renamed to 'ExcelApplication'
//   Hint: Symbol 'Chart' renamed to 'ExcelChart'
//   Hint: Symbol 'Worksheet' renamed to 'ExcelWorksheet'
//   Hint: Symbol 'Global' renamed to 'ExcelGlobal'
//   Hint: Symbol 'Workbook' renamed to 'ExcelWorkbook'
//   Hint: Symbol 'OLEObject' renamed to 'ExcelOLEObject'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Enum Member 'XlDisplayShapes' of 'XlDisplayShapes' changed to 'XlDisplayShapes_'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'DialogBox' renamed to 'DialogBOX'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'DialogBox' renamed to 'DialogBOX'
//   Hint: Member 'Range' of 'Range' changed to 'Range_'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Member 'Name' of 'Name' changed to 'Name_'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'RGB' renamed to 'rgb'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if defined(USING_ATL)
#include <atl\atlvcl.h>
#endif

#include "Excel_97_SRVR.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Excel_97
{

_QueryTablePtr& TExcelQueryTable::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TExcelQueryTable::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TExcelQueryTable::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TExcelQueryTable::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TExcelQueryTable::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TExcelQueryTable::ConnectTo(_QueryTablePtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TExcelQueryTable::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ExcelQueryTable;
  sd.IntfIID = __uuidof(_QueryTable);
  sd.EventIID= __uuidof(RefreshEvents);
  ServerData = &sd;
}

void __fastcall TExcelQueryTable::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    case 1596:
      if (OnBeforeRefresh)
        (OnBeforeRefresh)(this, TVariant(params[0]));
      break;
    case 1597:
      if (OnAfterRefresh)
        (OnAfterRefresh)(this, TVariant(params[0]));
      break;
    default:
      break;
  }
}

_ApplicationPtr& TExcelApplication::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TExcelApplication::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TExcelApplication::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TExcelApplication::Disconnect()
{
  if (m_DefaultIntf) {
    Quit();
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TExcelApplication::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TExcelApplication::ConnectTo(_ApplicationPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TExcelApplication::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ExcelApplication;
  sd.IntfIID = __uuidof(_Application);
  sd.EventIID= __uuidof(AppEvents);
  ServerData = &sd;
}

void __fastcall TExcelApplication::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    case 1565:
      if (OnNewWorkbook)
        (OnNewWorkbook)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1558:
      if (OnSheetSelectionChange)
        (OnSheetSelectionChange)(this, TVariant(params[0]), (Excel_97::Range*)(LPDISPATCH)TVariant(params[1]));
      break;
    case 1559:
      if (OnSheetBeforeDoubleClick)
        (OnSheetBeforeDoubleClick)(this, TVariant(params[0]), (Excel_97::Range*)(LPDISPATCH)TVariant(params[1]), TVariant(params[2]));
      break;
    case 1560:
      if (OnSheetBeforeRightClick)
        (OnSheetBeforeRightClick)(this, TVariant(params[0]), (Excel_97::Range*)(LPDISPATCH)TVariant(params[1]), TVariant(params[2]));
      break;
    case 1561:
      if (OnSheetActivate1)
        (OnSheetActivate1)(this, TVariant(params[0]));
      break;
    case 1562:
      if (OnSheetDeactivate1)
        (OnSheetDeactivate1)(this, TVariant(params[0]));
      break;
    case 1563:
      if (OnSheetCalculate)
        (OnSheetCalculate)(this, TVariant(params[0]));
      break;
    case 1564:
      if (OnSheetChange)
        (OnSheetChange)(this, TVariant(params[0]), (Excel_97::Range*)(LPDISPATCH)TVariant(params[1]));
      break;
    case 1567:
      if (OnWorkbookOpen)
        (OnWorkbookOpen)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1568:
      if (OnWorkbookActivate)
        (OnWorkbookActivate)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1569:
      if (OnWorkbookDeactivate)
        (OnWorkbookDeactivate)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1570:
      if (OnWorkbookBeforeClose)
        (OnWorkbookBeforeClose)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      break;
    case 1571:
      if (OnWorkbookBeforeSave)
        (OnWorkbookBeforeSave)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]));
      break;
    case 1572:
      if (OnWorkbookBeforePrint)
        (OnWorkbookBeforePrint)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      break;
    case 1573:
      if (OnWorkbookNewSheet)
        (OnWorkbookNewSheet)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      break;
    case 1574:
      if (OnWorkbookAddinInstall)
        (OnWorkbookAddinInstall)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1575:
      if (OnWorkbookAddinUninstall)
        (OnWorkbookAddinUninstall)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1554:
      if (OnWindowResize)
        (OnWindowResize)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]), (Excel_97::WINDOW*)(LPDISPATCH)TVariant(params[1]));
      break;
    case 1556:
      if (OnWindowActivate)
        (OnWindowActivate)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]), (Excel_97::WINDOW*)(LPDISPATCH)TVariant(params[1]));
      break;
    case 1557:
      if (OnWindowDeactivate)
        (OnWindowDeactivate)(this, (Excel_97::ExcelWorkbook*)(LPDISPATCH)TVariant(params[0]), (Excel_97::WINDOW*)(LPDISPATCH)TVariant(params[1]));
      break;
    default:
      break;
  }
}

_ChartPtr& TExcelChart::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TExcelChart::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TExcelChart::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TExcelChart::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TExcelChart::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TExcelChart::ConnectTo(_ChartPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TExcelChart::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ExcelChart;
  sd.IntfIID = __uuidof(_Chart);
  sd.EventIID= __uuidof(ChartEvents);
  ServerData = &sd;
}

void __fastcall TExcelChart::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    case 304:
      if (OnActivate)
        (OnActivate)(this);
      break;
    case 1530:
      if (OnDeactivate)
        (OnDeactivate)(this);
      break;
    case 256:
      if (OnResize)
        (OnResize)(this);
      break;
    case 1531:
      if (OnMouseDown)
        (OnMouseDown)(this, (Excel_97::XlMouseButton)(int)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]));
      break;
    case 1532:
      if (OnMouseUp)
        (OnMouseUp)(this, (Excel_97::XlMouseButton)(int)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]));
      break;
    case 1533:
      if (OnMouseMove)
        (OnMouseMove)(this, (Excel_97::XlMouseButton)(int)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]));
      break;
    case 1534:
      if (OnBeforeRightClick)
        (OnBeforeRightClick)(this, TVariant(params[0]));
      break;
    case 1535:
      if (OnDragPlot)
        (OnDragPlot)(this);
      break;
    case 1536:
      if (OnDragOver)
        (OnDragOver)(this);
      break;
    case 1537:
      if (OnBeforeDoubleClick)
        (OnBeforeDoubleClick)(this, (Excel_97::XlChartItem)(int)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]), TVariant(params[3]));
      break;
    case 235:
      if (OnSelect)
        (OnSelect)(this, (Excel_97::XlChartItem)(int)TVariant(params[0]), TVariant(params[1]), TVariant(params[2]));
      break;
    case 1538:
      if (OnSeriesChange)
        (OnSeriesChange)(this, TVariant(params[0]), TVariant(params[1]));
      break;
    case 279:
      if (OnCalculate)
        (OnCalculate)(this);
      break;
    default:
      break;
  }
}

_WorksheetPtr& TExcelWorksheet::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TExcelWorksheet::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TExcelWorksheet::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TExcelWorksheet::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TExcelWorksheet::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TExcelWorksheet::ConnectTo(_WorksheetPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TExcelWorksheet::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ExcelWorksheet;
  sd.IntfIID = __uuidof(_Worksheet);
  sd.EventIID= __uuidof(DocEvents);
  ServerData = &sd;
}

void __fastcall TExcelWorksheet::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    case 1543:
      if (OnSelectionChange)
        (OnSelectionChange)(this, (Excel_97::Range*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1537:
      if (OnBeforeDoubleClick)
        (OnBeforeDoubleClick)(this, (Excel_97::Range*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      break;
    case 1534:
      if (OnBeforeRightClick)
        (OnBeforeRightClick)(this, (Excel_97::Range*)(LPDISPATCH)TVariant(params[0]), TVariant(params[1]));
      break;
    case 304:
      if (OnActivate)
        (OnActivate)(this);
      break;
    case 1530:
      if (OnDeactivate)
        (OnDeactivate)(this);
      break;
    case 279:
      if (OnCalculate1)
        (OnCalculate1)(this);
      break;
    case 1545:
      if (OnChange)
        (OnChange)(this, (Excel_97::Range*)(LPDISPATCH)TVariant(params[0]));
      break;
    default:
      break;
  }
}

_GlobalPtr& TExcelGlobal::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TExcelGlobal::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TExcelGlobal::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TExcelGlobal::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TExcelGlobal::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TExcelGlobal::ConnectTo(_GlobalPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TExcelGlobal::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ExcelGlobal;
  sd.IntfIID = __uuidof(_Global);
  sd.EventIID= GUID_NULL;
  ServerData = &sd;
}

_WorkbookPtr& TExcelWorkbook::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TExcelWorkbook::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TExcelWorkbook::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TExcelWorkbook::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TExcelWorkbook::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TExcelWorkbook::ConnectTo(_WorkbookPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TExcelWorkbook::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ExcelWorkbook;
  sd.IntfIID = __uuidof(_Workbook);
  sd.EventIID= __uuidof(WorkbookEvents);
  ServerData = &sd;
}

void __fastcall TExcelWorkbook::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    case 682:
      if (OnOpen)
        (OnOpen)(this);
      break;
    case 304:
      if (OnActivate)
        (OnActivate)(this);
      break;
    case 1530:
      if (OnDeactivate)
        (OnDeactivate)(this);
      break;
    case 1546:
      if (OnBeforeClose)
        (OnBeforeClose)(this, TVariant(params[0]));
      break;
    case 1547:
      if (OnBeforeSave)
        (OnBeforeSave)(this, TVariant(params[0]), TVariant(params[1]));
      break;
    case 1549:
      if (OnBeforePrint)
        (OnBeforePrint)(this, TVariant(params[0]));
      break;
    case 1550:
      if (OnNewSheet)
        (OnNewSheet)(this, TVariant(params[0]));
      break;
    case 1552:
      if (OnAddinInstall)
        (OnAddinInstall)(this);
      break;
    case 1553:
      if (OnAddinUninstall)
        (OnAddinUninstall)(this);
      break;
    case 1554:
      if (OnWindowResize)
        (OnWindowResize)(this, (Excel_97::WINDOW*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1556:
      if (OnWindowActivate)
        (OnWindowActivate)(this, (Excel_97::WINDOW*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1557:
      if (OnWindowDeactivate)
        (OnWindowDeactivate)(this, (Excel_97::WINDOW*)(LPDISPATCH)TVariant(params[0]));
      break;
    case 1558:
      if (OnSheetSelectionChange)
        (OnSheetSelectionChange)(this, TVariant(params[0]), (Excel_97::Range*)(LPDISPATCH)TVariant(params[1]));
      break;
    case 1559:
      if (OnSheetBeforeDoubleClick)
        (OnSheetBeforeDoubleClick)(this, TVariant(params[0]), (Excel_97::Range*)(LPDISPATCH)TVariant(params[1]), TVariant(params[2]));
      break;
    case 1560:
      if (OnSheetBeforeRightClick)
        (OnSheetBeforeRightClick)(this, TVariant(params[0]), (Excel_97::Range*)(LPDISPATCH)TVariant(params[1]), TVariant(params[2]));
      break;
    case 1561:
      if (OnSheetActivate1)
        (OnSheetActivate1)(this, TVariant(params[0]));
      break;
    case 1562:
      if (OnSheetDeactivate1)
        (OnSheetDeactivate1)(this, TVariant(params[0]));
      break;
    case 1563:
      if (OnSheetCalculate)
        (OnSheetCalculate)(this, TVariant(params[0]));
      break;
    case 1564:
      if (OnSheetChange)
        (OnSheetChange)(this, TVariant(params[0]), (Excel_97::Range*)(LPDISPATCH)TVariant(params[1]));
      break;
    default:
      break;
  }
}

_OLEObjectPtr& TExcelOLEObject::GetDefaultInterface()
{
  if (!m_DefaultIntf)
    Connect();
  return m_DefaultIntf;
}

_di_IUnknown __fastcall TExcelOLEObject::GetDunk()
{
  _di_IUnknown diUnk;
  if (m_DefaultIntf) {
    IUnknownPtr punk = m_DefaultIntf;
    diUnk = LPUNKNOWN(punk);
  }
  return diUnk;
}

void __fastcall TExcelOLEObject::Connect()
{
  if (!m_DefaultIntf) {
    _di_IUnknown punk = GetServer();
    m_DefaultIntf = punk;
    if (ServerData->EventIID != GUID_NULL)
      ConnectEvents(GetDunk());
  }
}

void __fastcall TExcelOLEObject::Disconnect()
{
  if (m_DefaultIntf) {
    
    if (ServerData->EventIID != GUID_NULL)
      DisconnectEvents(GetDunk());
    m_DefaultIntf.Reset();
  }
}

void __fastcall TExcelOLEObject::BeforeDestruction()
{
  Disconnect();
}

void __fastcall TExcelOLEObject::ConnectTo(_OLEObjectPtr intf)
{
  Disconnect();
  m_DefaultIntf = intf;
  if (ServerData->EventIID != GUID_NULL)
    ConnectEvents(GetDunk());
}

void __fastcall TExcelOLEObject::InitServerData()
{
  static Oleserver::TServerData sd;
  sd.ClassID = CLSID_ExcelOLEObject;
  sd.IntfIID = __uuidof(_OLEObject);
  sd.EventIID= __uuidof(OLEObjectEvents);
  ServerData = &sd;
}

void __fastcall TExcelOLEObject::InvokeEvent(int id, TVariantArray& params)
{
  switch(id)
  {
    case 1541:
      if (OnGotFocus)
        (OnGotFocus)(this);
      break;
    case 1542:
      if (OnLostFocus)
        (OnLostFocus)(this);
      break;
    default:
      break;
  }
}


};     // namespace Excel_97


// *********************************************************************//
// The Register function is invoked by the IDE when this module is 
// installed in a Package. It provides the list of Components (including
// OCXes) implemented by this module. The following implementation
// informs the IDE of the OCX proxy classes implemented here.
// *********************************************************************//
namespace Excel_97_srvr
{

void __fastcall PACKAGE Register()
{
  // [7]
  TComponentClass cls_svr[] = {
                              __classid(Excel_97::TExcelQueryTable), 
                              __classid(Excel_97::TExcelApplication), 
                              __classid(Excel_97::TExcelChart), 
                              __classid(Excel_97::TExcelWorksheet), 
                              __classid(Excel_97::TExcelGlobal), 
                              __classid(Excel_97::TExcelWorkbook), 
                              __classid(Excel_97::TExcelOLEObject)
                           };
  RegisterComponents("Servers", cls_svr,
                     sizeof(cls_svr)/sizeof(cls_svr[0])-1);
}

};     // namespace Excel_97_srvr
