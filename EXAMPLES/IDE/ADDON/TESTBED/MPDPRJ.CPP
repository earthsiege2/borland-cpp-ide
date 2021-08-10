/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  mpdprj.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.16  $
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <owl\window.h>
#include <ideaddon\impd.h>
#include <ideaddon\ioption.h>
#include <ideaddon\imake.h>
#include <ideaddon\iproj.h>
#include <windowsx.h> // this must come after iproj.h to avoid error
#include <commctrl.h>
#include "tests.hrc"
#include "addonpg.h"

/******************************************************************************
*  This file contains 3 MPD page implementations.
*
*  AddonSummaryPage displays the selected node information
*
*  ProjectPage       lets user set, add and remove named project proerty
*
*  OptionPage       shows IOptionSetServer usage.
*
******************************************************************************/

class AddonProjectPageBase : public AddonPageBase {
public:
  void SetNode(ProjectNode node);
protected:
  ProjectNode     d_node;
};

void AddonProjectPageBase::SetNode(ProjectNode node) {
  d_node = node;
}

/******************************************************************************
*
* AddonSummaryPage displays node information 
*
******************************************************************************/

class AddonSummaryPage : public AddonProjectPageBase {
public:
  AddonSummaryPage(IProjectServer * projectServer);
  ~AddonSummaryPage();
  //
  // IMpdPage interface
  //
  virtual BOOL    CanClose();
  virtual void    SetDlgItems();
  virtual void    GetDlgItems();
  virtual LRESULT OnCommand(UINT id, HWND hWndCtl, UINT notifyCode);
protected:
  IProjectServer* d_projectServer;
};

AddonSummaryPage::AddonSummaryPage(IProjectServer * projectServer) {
  d_projectServer = projectServer;
};

AddonSummaryPage::~AddonSummaryPage() {
  d_projectServer->Release();
};

#define NUM_ITEMS sizeof(headers)/sizeof(headers[0])

void AddonSummaryPage::SetDlgItems() {

  IProjectNodeInfo* pni = d_projectServer->QueryNodeInfo( d_node );
  if (!pni)
    return;

  //
  // This page is read only, so we will initialize it only once.
  //
  if ( GetDlgItem(d_hDlg, IDC_NODEVIEW) ) {
    return;
  }

  IMakeServer*     makeServer = GET_INTERFACE(IMakeServer);
  long inputAge;
  long outputAge;
  if (makeServer) {
    inputAge = makeServer->NodeInputAge( d_node );
    outputAge = makeServer->NodeOutputAge( d_node );
    makeServer->Release();
  } else {
    inputAge = 0;
    outputAge = 0;
  }
  char* itemNames[] = {
     "Name",
     "Type",
     "Description",
     "Input Location",
     "Input Age",
     "Output Location",
     "Output Age",
  };

  char items[10][256];
  int i = 0;

  IPolyString* name = pni->GetName();
  if (name) {
    strcpy(items[i++], name->GetCstr());
    name->Release();
  }
  IPolyString* nodeType = pni->GetNodeType();
  if (nodeType) {
    strcpy(items[i++], nodeType->GetCstr());
    nodeType->Release();
  }
  IPolyString* nodeDesc = pni->GetDescription();
  if (nodeDesc) {
    strcpy(items[i++], nodeDesc->GetCstr());
    nodeDesc->Release();
  }
  IPolyString* nodeInput = pni->GetInputLocation();
  if (nodeInput) {
    strcpy(items[i++], nodeInput->GetCstr());
    nodeInput->Release();
  }

  wsprintf(items[i++], "0x%x", inputAge);

  IPolyString* nodeOutput = pni->GetOutputLocation();
  if (nodeOutput) {
    strcpy(items[i++], nodeOutput->GetCstr());
    nodeOutput->Release();
  }

  wsprintf(items[i++], "0x%x", outputAge);
  pni->Release();

  // Ensure that the common control DLL is loaded.
  InitCommonControls();

  HWND hWndList;      // Handle to the list view window

  // Get the size and position of the parent window
  RECT rcl;          // Rectangle for setting the size of the window
  GetClientRect(d_hDlg, &rcl);

  // Create the list view window that starts out in report view

  extern HINSTANCE ghInst;

  hWndList = CreateWindowEx(WS_EX_NOPARENTNOTIFY,
                            WC_LISTVIEW,                // list view class
                            "",                        // no default text
                            WS_VISIBLE | WS_CHILD | WS_BORDER
                            | LVS_REPORT |WS_EX_CLIENTEDGE,
                            0, 0,
                            rcl.right - rcl.left, rcl.bottom - rcl.top,
                            d_hDlg,
                            (HMENU)IDC_NODEVIEW,
                            ghInst,
                            NULL );

  if (hWndList == NULL )
    return;


  // Now initialize the columns we will need
  // Initialize the LV_COLUMN structure
  // the mask specifies that the .fmt, .ex, width, and .subitem members 
  // of the structure are valid,
  LV_COLUMN lvC;      // List View Column structure
  lvC.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
  lvC.fmt = LVCFMT_LEFT;  // left align the column
  lvC.cx = 75;            // width of the column, in pixels


   static char* headers[] = { "Information", "Value" };

  // Add the columns.
  int index;          // Index used in for loops
   for ( index = 0; index < NUM_ITEMS; ++index ) {
     lvC.iSubItem = index;
      lvC.pszText = headers[index];
     if (ListView_InsertColumn(hWndList, index, &lvC) == -1)
       return;
   };

  LV_ITEM lvI;        // List view item structure
  lvI.mask = LVIF_TEXT | LVIF_STATE;
  lvI.state = 0;      //
  lvI.stateMask = 0;  //

  for (index = 0; index < sizeof(itemNames)/sizeof(itemNames[0]); index++)
  {
    lvI.iItem = index;
    lvI.iSubItem = 0;
    lvI.pszText = itemNames[index]; 
    lvI.cchTextMax = strlen(items[index])+1;

    if (ListView_InsertItem(hWndList, &lvI) == -1)
      return;

    int iSubItem;      // Index for inserting sub items
    for (iSubItem = 1; iSubItem < NUM_ITEMS; iSubItem++)
    {
      ListView_SetItemText( hWndList,
                            index,
                            iSubItem,
                            items[index]);
    }
  }
};

void AddonSummaryPage::GetDlgItems() {};

BOOL AddonSummaryPage::CanClose() { return 1; };


LRESULT AddonSummaryPage::OnCommand(UINT wID, HWND /*hWndCtl*/, UINT /*notifyCode*/) {
  switch (wID)
  {
      default:
      break;
  }
  return 0;
}

/******************************************************************************
*
*  AddonSummaryPage displays the selected node information
*
******************************************************************************/

class ProjectPage : public AddonProjectPageBase {
public:
  ProjectPage(IProjectServer * projectServer);
  ~ProjectPage();
  //
  // IMpdPage interface
  //
  virtual BOOL    CanClose();
  virtual void    SetDlgItems();
  virtual void    GetDlgItems();
  virtual LRESULT OnCommand(UINT id, HWND hWndCtl, UINT notifyCode);
protected:
          void          PFind();
          void          PSet();
          void          PRemove();

          IPolyString*  GetName();

  IProjectServer *  d_projectServer;
};

ProjectPage::ProjectPage(IProjectServer * projectServer) {
  d_projectServer = projectServer;
};

ProjectPage::~ProjectPage() {
  d_projectServer->Release();
};

void ProjectPage::SetDlgItems() {};

void ProjectPage::GetDlgItems() {};

BOOL ProjectPage::CanClose() { return 1; };

IPolyString* ProjectPage::GetName() {
  char bufName[256];
  GetDlgItemText(d_hDlg, IDC_PROPERTY_LABEL, bufName, sizeof(bufName));
  return MakePolyString(bufName);

}

void ProjectPage::PFind() {
  UINT dataSize;
  char* text;
  text = (char *) d_projectServer->NodePropertyFind(d_node,
                                          GetName(),
                                          &dataSize);                                         
  if (dataSize == 0)
   text = "";

  SetDlgItemText(d_hDlg, IDC_PROPERTY, text);

};

void ProjectPage::PSet() {

  char buf[256];
  GetDlgItemText(d_hDlg, IDC_PROPERTY, buf, sizeof(buf));
  d_projectServer->NodePropertySet(d_node, 
                                    GetName(),
                                    buf,
                                    strlen(buf)+1);
  PFind();
};

void ProjectPage::PRemove() {

  d_projectServer->NodePropertyRemove(d_node, GetName());
  PFind();
}


LRESULT ProjectPage::OnCommand(UINT wID, HWND /*hWndCtl*/, UINT /*notifyCode*/) {
  switch (wID)
  {
    case IDC_FIND:
      PFind();
      break;
    case IDC_SET:
      PSet();
      break;
    case IDC_REMOVE:
      PRemove();
      break;
  }
  return 0;
}

/******************************************************************************
*  OptionPage       shows IOptionSetServer usage.
******************************************************************************/

class OptionPage : public AddonProjectPageBase {
public:
  OptionPage(IOptionSetServer* optionSetServer);
  ~OptionPage();
  //
  // IMpdPage interface
  //
  virtual BOOL    CanClose();
  virtual void    SetDlgItems();
  virtual void    GetDlgItems();
  virtual VOID    Init(HWND hDlg, IStatusBar* isb);
  virtual LRESULT OnCommand(UINT id, HWND hWndCtl, UINT notifyCode);
protected:
          void Remove();

  IOptionSetServer* d_optionSetServer;
};

OptionPage::OptionPage(IOptionSetServer* optionSetServer) {
  d_optionSetServer = optionSetServer;
  //
  // always modified
  //
  d_modified = 1;
};

OptionPage::~OptionPage() {
  d_optionSetServer->Release();
};

VOID OptionPage::Init(HWND hDlg, IStatusBar* isb) {

  AddonPageBase::Init(hDlg, isb);
};

BOOL OptionPage::CanClose() { return 1; };

int ids[] = {
            IDC_INCLUDE    ,
            IDC_LIBRARY    ,
        IDC_SOURCE      ,
            IDC_INTERMEDIATE,
            IDC_FINAL      ,
            IDC_DEFINES    ,
            IDC_CMDOVERRIDE ,
};

OptionsStringIds oids[] = {
         OID_Include,
             OID_Library,
             OID_Source,
             OID_Intermediate,
             OID_Final,
             OID_Defines,
             OID_CmdlineOverride,
};

void OptionPage::SetDlgItems() {

   int i;

   for (i = 0; i< sizeof(ids)/sizeof(ids[0]); ++i ) {
    IPolyString* pps = d_optionSetServer->OptionGet(d_node, oids[i]);
      if (pps) {
         SetDlgItemText(d_hDlg, ids[i], pps->GetCstr());
      pps->Release();
      } else
         SetDlgItemText(d_hDlg, ids[i], "");

      char buf[256];
      IPolyString *val;
      GetDlgItemText(d_hDlg, ids[i], buf, sizeof(buf));
      val = MakePolyString(buf);
      d_optionSetServer->OptionApply(d_node, oids[i], val);
   }

};

void OptionPage::GetDlgItems() {
   int i;

   for (i = 0; i< sizeof(ids)/sizeof(ids[0]); ++i ) {
      char buf[256];
    IPolyString *val;
      GetDlgItemText(d_hDlg, ids[i], buf, sizeof(buf));
      val = MakePolyString(buf);
      d_optionSetServer->OptionApply(d_node, oids[i], val);
   }

};

void OptionPage::Remove() {
  d_optionSetServer->OptionRemove(d_node, OID_RemoveAll);
  SetDlgItems();
};


LRESULT OptionPage::OnCommand(UINT wID, HWND /*hWndCtl*/, UINT /*notifyCode*/) {
  switch (wID)
  {
      case IDC_REMOVE:
        Remove();
        break;
      default:
        break;
  }
  return 0;
}


/******************************************************************************
* IMpdProjectChapterAddon: a simple project chapter
******************************************************************************/

IMpdProjectChapterAddon::IMpdProjectChapterAddon() {
  d_projectServer = GET_INTERFACE( IProjectServer );
  d_optionSetServer = GET_INTERFACE( IOptionSetServer );
};

IMpdProjectChapterAddon::~IMpdProjectChapterAddon() {
  d_projectServer->Release();
  d_optionSetServer->Release();
};

void IMpdProjectChapterAddon::Init() {

  d_projectServer->AddRef();
  d_pages[0] = new  AddonSummaryPage(d_projectServer);
  d_pages[0]->SetInfo(MPD_OPENSUMMARY, IDD_MPD_PAGE1, "Addon Summary");

  d_projectServer->AddRef();
  d_pages[1] = new ProjectPage(d_projectServer);
  d_pages[1]->SetInfo(MPD_CLOSEPAGE, IDD_MPD_PAGE4, "Set Named Option");

  d_optionSetServer->AddRef();
  d_pages[2] = new OptionPage(d_optionSetServer);
  d_pages[2]->SetInfo(MPD_CLOSEPAGE, IDD_MPD_PAGE5, "Set Options");

  d_nPages = 3;
};


UINT IMpdProjectChapterAddon::GetResourceId() {return ID_MPD_PROJECT_CHAPTER;};


IMpdPage* IMpdProjectChapterAddon::OpenPage(UINT pid, ProjectNode node) {
  IMpdPage* page;

  switch (pid) {
    case IDD_MPD_PAGE1:
      page = d_pages[0];
      break;
    case IDD_MPD_PAGE4:
      page = d_pages[1];
      break;
    case IDD_MPD_PAGE5:
      page = d_pages[2];
      break;
    default:
      return 0;
  }
  ((AddonProjectPageBase*)page)->SetNode(node);

  page->AddRef();
  return page;
};


