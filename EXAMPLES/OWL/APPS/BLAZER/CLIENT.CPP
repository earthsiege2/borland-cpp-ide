//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
// Implementation of TClientWindow.
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/combobox.h>
#include <owl/statusba.h>
#include <owl/celarray.h>
#include <owl/imagelst.h>
#include <owl/mailer.h>
#include <stdio.h>
#include <dos.h>
#include <dir.h>
#include "blazer.h"

DEFINE_RESPONSE_TABLE1(TClientWindow, TPaneSplitter)
  EV_TVN_SELCHANGED (TreeWindId,      TvnSelChanged),
  EV_LVN_GETDISPINFO(ListWindId,      LvnGetDispInfo),
  EV_LVN_BEGINLABELEDIT(ListWindId,   LvnBeginLabelEdit),
  EV_LVN_ENDLABELEDIT(ListWindId,     LvnEndLabelEdit),

  EV_COMMAND        (DrivesId,         CbnDriveSelected),
  EV_COMMAND        (CM_FILESEND,      CmFileSend),
  EV_COMMAND_ENABLE (CM_FILESEND,      CeFileSend),
  EV_COMMAND        (CM_CONTEXTSELECT, CmContextSelect),
  EV_COMMAND_ENABLE (CM_CONTEXTSELECT, CeContextSelect),
END_RESPONSE_TABLE;

DEFINE_HELPCONTEXT(TClientWindow)
  HCENTRY_MENU(IDH_CM_FILESELECT,    CM_FILESELECT),
  HCENTRY_MENU(IDH_CM_FILESEND,      CM_FILESEND),
  HCENTRY_MENU(IDH_CM_EXIT,          CM_EXIT),
  HCENTRY_MENU(IDH_CM_HELPABOUT,     CM_HELPABOUT),
  HCENTRY_MENU(IDH_CM_CONTEXTSELECT, CM_CONTEXTSELECT),
  HCENTRY_CONTROL(IDH_TREEWIND,      TreeWindId),
  HCENTRY_CONTROL(IDH_LISTWIND,      ListWindId),
END_HELPCONTEXT;

//
// The main SDI client window that is a TPaneSplitter with two panes:
// On the left is a TTreeWindow to display the directory hierarchy and
// on the right is a TListWindow to display the files within a selected
// directory.
//
TClientWindow::TClientWindow(TWindow* parent)
:
  TPaneSplitter(parent)
{
//  OwnsElements(0);
  Attr.Style |= (WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
  TLayoutMetrics lm;

  // Create TreeWindow
  //
  TreeWind = new TPaneTreeWindow(this, TreeWindId, 10, 10, 100, 100);
  TreeWind->Attr.Style   |= WS_VISIBLE | TVS_HASLINES |
                            TVS_HASBUTTONS | TVS_LINESATROOT;
  TreeWind->Attr.ExStyle |= WS_EX_CLIENTEDGE;

  // Create ListWindow
  //
  ListWind = new TPaneListWindow(this, ListWindId, 10, 10, 100, 100);
  ListWind->Attr.Style   |= LVS_REPORT | LVS_SORTASCENDING | LVS_EDITLABELS;
  ListWind->Attr.ExStyle |= WS_EX_CLIENTEDGE;

  Images = new TImageList(*GetApplication(), IDB_TREEIMAGE,
                          20, 1, TColor(255, 255, 255), IMAGE_BITMAP, 0);
}

//
//
//
TClientWindow::~TClientWindow()
{
  delete TreeWind;
  delete ListWind;
  delete Images;
}

//
//
//
void
TClientWindow::SetupWindow()
{
  // Initialize base class
  //
  TPaneSplitter::SetupWindow();
  SplitPane(TreeWind, ListWind, psVertical);

  // Initialize context sensitive help
  //
  SETUP_HELPCONTEXT(TBlazerApp, TClientWindow);

  // Initialize TreeWind
  //
  TreeWind->SetImageList(TTreeWindow::Normal, *Images);

  // Initialize ListWind
  //
  TListWindColumn files("Name", 100);
  ListWind->InsertColumn(0, files);
  TListWindColumn date("Modified", 100, TListWindColumn::Left);
  ListWind->InsertColumn(1, date);
  TListWindColumn size("Size", 100, TListWindColumn::Right);
  ListWind->InsertColumn(2, size);
}

//
//
//
void
TClientWindow::CleanupWindow()
{
  // Remove context sensitive help info
  //
  CLEANUP_HELPCONTEXT(TBlazerApp, TClientWindow);

  // Cleanup the base class
  //
  TPaneSplitter::CleanupWindow();
}

//
// A drive was selected in the combobox.
// Read directory information from the drive and store it into
// the TTreeWindow.
//
void
TClientWindow::CbnDriveSelected()
{
  TreeWind->DeleteAllItems();

  char drive[10];
  ListOfDrives->GetSelString(drive, sizeof drive);

  TTreeItem item(drive, Directory, OpenDirectory);
  TTreeNode driveNode = TreeWind->GetRoot().AddChild(item);

  string startDir = drive;
  startDir += "\\*.*";
  AddDirectory(startDir.c_str(), driveNode);

  // sort all the children in the tree
  //
  TTreeNode root = TreeWind->GetRoot();
  root.SortChildren(true);

  if (::StatusBar)
    ::StatusBar->SetText(" ");

  TreeWind->Invalidate();
  ListWind->Invalidate();

  TvnSelChanged(TTwNotify());
  root.GetChild().ExpandItem(TTreeNode::Expand);
}

//
// Fill TListWindow with files if a directory was selected.
// This function is called when user selects a directory or called
// directory by CbnDriveSelected.
//
void
TClientWindow::TvnSelChanged(TTwNotify far& /*notify*/)
{
  ListWind->DeleteAllItems();

  TTreeNode treeItem = TreeWind->GetSelection();
  string fullPath = GetParentDirectory(treeItem);
  if (fullPath.length() == 0)
    return;

  // Fill TListWindow with files from selected directory
  //
  fullPath += "*.*";
  ffblk fb;
  bool done = findfirst(fullPath.c_str(), &fb, FA_NORMAL);
  while (!done) {
    TListWindItem item(fb.ff_name, 0);
    ListWind->InsertItem(item);
    done = findnext(&fb);
  }
}

//
// Callback notification to handle additional column information
// for each file.
// In this case, display file date timestamp and file size.
//
void
TClientWindow::LvnGetDispInfo(TLwDispInfoNotify& dispInfo)
{
  const int BufLen = 255;
  static char buffer[BufLen];
  TListWindItem& dispInfoItem = *(TListWindItem*)&dispInfo.item;

  TListWindItem lvItem(buffer, 0, BufLen);
  lvItem.SetIndex(dispInfoItem.GetIndex());
  ListWind->GetItem(lvItem);

  TTreeNode treeItem = TreeWind->GetSelection();
  string parentDir = GetParentDirectory(treeItem);
  parentDir += lvItem.pszText;

  // Get information about file
  //
  ffblk fb;
  bool done = findfirst(parentDir.c_str(), &fb, FA_NORMAL);
  if (!done) {
    switch (dispInfoItem.GetSubItem()) {
      case 1: { // date
        struct ff_date_struct  {
          unsigned day : 5;
          unsigned month : 4;
          unsigned year80 : 7;
        };
        ff_date_struct date = *(ff_date_struct*)&fb.ff_fdate;
        sprintf(buffer, "%02d/%02d/%04d", date.month, date.day, date.year80+1980);
        dispInfoItem.SetText(buffer);
        break;
      }
      case 2: { // size
        sprintf(buffer, "%lu", fb.ff_fsize);
        dispInfoItem.SetText(buffer);
        break;
      }
    }
  }
}

//
// Recursively traverse the directory hierarchy of the given dirPath.
// dirPath is specified by this format:
//   [drive]:\\{dirs}\\*.*
// where drive is a letter, typically c through z and
//       dirs is zero or more directories separated by a backslash.
//
void
TClientWindow::AddDirectory(const char* dirPath, TTreeNode& parent)
{
  ffblk fb;
  bool done = findfirst(dirPath, &fb, FA_DIREC);
  while (!done) {
    // Allow other programs a chance to work
    //
    // ::Application->PumpWaitingMessages();
    Parent->UpdateWindow();

    char* dirName = fb.ff_name;
    if (fb.ff_attrib & FA_DIREC) {
      if (strcmp(dirName, ".") == 0)
        ; // skip
      else if (strcmp(dirName, "..") == 0)
        ; // skip
      else {
        // Add item
        //
        TTreeItem item(dirName, Directory, Directory);
        TTreeNode newParent = parent.AddChild(item);

        // Recurse
        //
        TAPointer<char> buffer = new char[strlen(dirPath) + strlen(dirName) + 1 + 1];
        strncpy(buffer, dirPath, strlen(dirPath) - 3);

        // Take off *.*
        //
        buffer[strlen(dirPath) - 3] = 0;

        if (::StatusBar)
          ::StatusBar->SetText(dirPath);

        // Add directory\*.* to end
        //
        strcat(buffer, dirName);
        strcat(buffer, "\\*.*");
        AddDirectory(buffer, newParent);
      }
    }
    done = findnext(&fb);
  }
}

//
// Retrieves the directory of the selected item in the TTreeWindow.
//
string
TClientWindow::GetParentDirectory(TTreeNode& treeNode)
{
  string path = "";
  while (treeNode != 0) {
    string toBeAdded = path;
    const int bufLen = 255;
    char* buffer = new char[bufLen];
    buffer[0] = 0;

    TTreeItem tvItem(buffer, bufLen);
    treeNode.GetItem(&tvItem);

    path = buffer;
    path += "\\";
    path += toBeAdded;
    treeNode = treeNode.GetParent();
    delete[] buffer;
  }
  string fullPath = path;
  return fullPath;
}

//
// Notification to begin label editing.
//
bool
TClientWindow::LvnBeginLabelEdit(TLwDispInfoNotify&)
{
  ::MessageBeep(-1);
  return false;
}

//
// Notification to end label editing.
//
void
TClientWindow::LvnEndLabelEdit(TLwDispInfoNotify& dispInfo)
{
  if (dispInfo.item.iItem != -1) {
    if (dispInfo.item.pszText) {
      char text[512];
      sprintf(text, "Attempting to rename to %s on item number %d\n",
        dispInfo.item.pszText, dispInfo.item.iItem);
      MessageBox(text, "Message");
    }
  }
}

//
// Determines if files are selected in the TListWindow.
//
bool
TClientWindow::AreFilesSelected()
{
  if (ListWind) {
    int count = ListWind->GetItemCount();
    for (int i = 0; i < count; i++)
      if (ListWind->GetItemState(i, LVIS_SELECTED))
        return true;
  }
  return false;
}

//
//
//
void
TClientWindow::CeFileSend(TCommandEnabler& ce)
{
  ce.Enable(AreFilesSelected());
}

//
// Send selected files via MAPI.
//
void
TClientWindow::CmFileSend()
{
  if (ListWind) {
    int count = ListWind->GetItemCount();
    TTreeNode treeItem = TreeWind->GetSelection();
    string path = GetParentDirectory(treeItem);
    if (path.length() == 0)
      return;
    for (int i = 0; i < count; i++) {
      const int length = 1024;
      char* fileName = new char[length];
      TListWindItem item(fileName, 0, length);
      item.SetIndex(i);
      ListWind->GetItem(item);
      if (ListWind->GetItemState(i, LVIS_SELECTED)) {
        string temp = path + fileName;
        ::Application->SaveMenuChoice(temp.c_str());
        ::Application->GetMailer()->SendDocuments(this, temp.c_str(), fileName);
      }
      delete[] fileName;
    }
  }
}

//
//
//
void
TClientWindow::CeContextSelect(TCommandEnabler& ce)
{
  ce.Enable(AreFilesSelected());
}

//
// Add selected files to the Most-Recently-Used list.
//
void
TClientWindow::CmContextSelect()
{
  if (ListWind) {
    int count = ListWind->GetItemCount();
    TTreeNode treeItem = TreeWind->GetSelection();
    string path = GetParentDirectory(treeItem);
    if (path.length() == 0)
      return;
    for (int i = 0; i < count; i++) {
      const int length = 1024;
      char* fileName = new char[length];
      TListWindItem item(fileName, 0, length);
      item.SetIndex(i);
      ListWind->GetItem(item);
      if (ListWind->GetItemState(i, LVIS_SELECTED)) {
        string temp = path + fileName;
        ::Application->SaveMenuChoice(temp.c_str());
      }
      delete[] fileName;
    }
  }
}

//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TComboBoxAsGadget, TComboBox)
  EV_NOTIFY_AT_CHILD(CBN_SELCHANGE, CbnSelChanged),
END_RESPONSE_TABLE;

//
//
//
void
TComboBoxAsGadget::CbnSelChanged()
{
  GetParentO()->SendNotification(GetId(), 0, 0);
}

