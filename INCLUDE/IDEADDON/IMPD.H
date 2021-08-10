/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  impd.h
  Created: 11/14/95
  Copyright (c) 1995, 1996 Borland International
  $Revision:   1.15  $
   
   MPD refers to the Multi-Page-Dialog boxes used for setting options in the 
   BCW IDE. A "Chapter" represents a high level item containing one or more
   "Pages" which can be colapsed under the Chapter.
    
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/ 
#ifndef __IMPD_H
#define __IMPD_H

#include <ideaddon\ipolystr.h>
#include <ideaddon\isbar.h>
#include <ideaddon\common.h>    // ProjectNode
#include <ideaddon\impd.uid>

enum MpdType {
  MT_EnvironmentOptions,
  MT_ProjectOptions
};

#define MPD_SUMMARY      0x0000
#define MPD_PAGE          0x0001

#define MPDF_OPEN        0x1000
#define MPDF_CLOSE        0x0000

#define MPD_OPENSUMMARY MPD_SUMMARY|MPDF_OPEN
#define MPD_CLOSEPAGE   MPD_PAGE|MPDF_CLOSE

//.............................................................................
//
//  User implements this class and returns a pointer to an instance of it when
// IMpdChapter::OpenPage() is called by the AddOn wrapper dll.
//
class IMpdPage : public IUnknown {
public:
  //
  //  Init() is called when the page dialog object is initially created.
  //  HWND hDlg        dialog window handle of the page
  //  IStatusBar* isb  represent the status window in MPD
  //
  virtual void Init(HWND hDlg, IStatusBar* isb) = 0;
  //
  // return TRUE if a page can be turned, otherwise return 0.
  //
  virtual BOOL CanClose() = 0;
  //
  //  SetDlgItems() is called to set the page content to the current state
  //  represented by the application internal data
  //
  virtual void SetDlgItems() = 0;
  //
  //  GetDlgItems() is called to set the applcaition internal data based
  //  on current user input
  //
  virtual void GetDlgItems() = 0;
  //
  //  return the modified state of the page
  //  return TRUE if the page has been modified, otherwise return FALSE.
  //
  virtual BOOL IsModified(void) = 0;
  //
  //  undo user modification on current page. IsModified returns FALSE
  //  after Undo() 
  //
  virtual void Undo() = 0;
  //
  //  OnComamnd() is called in response to perform WM_COMMAND processing.
  //  If an application processes this message, it should return zero
  //
  virtual LRESULT OnCommand(UINT id, HWND hWndCtl, UINT notifyCode) = 0;
  //
  //
  //
  virtual HINSTANCE    GetHInstance() = 0;
  virtual UINT          GetResourceId() = 0;
  virtual IPolyString*  GetPageTitle() = 0;
  virtual UINT          GetPageStyle() = 0;
  //
  // call help on the page
  //
  virtual void          Help(BOOL fF1Key) = 0;
  //
  // display information about this page in the status line
  //
  virtual void          DisplayPageStatus() = 0;
};

//.............................................................................
//
//  User implements this class and passes a pointer to an instance of it in
// IMpdServer::RegisterChapter.
//
class IMpdChapter : public IUnknown {
public:
  //
  // SetEditNode set the node to be changed
  //
  //
  virtual void      SetEditNode(ProjectNode node) = 0;
  //
  // open the page indicated by PageResourceId
  //
  virtual IMpdPage* OpenPage(UINT PageResourceId, ProjectNode node = 0 ) = 0;
  //
  // return the number of pages in the chapter
  //
  virtual UINT      GetPageCount() = 0;
  //
  // The first page starts at 1
  //
  virtual IMpdPage* GetPage(UINT iPage) = 0;
  //
  // Close() is called when MPD is closed
  //  fOk is 1 if user select OK button to close MPD
  //
  virtual void      Close(UINT fOk) = 0;
};

//.............................................................................
class IMpdServer : public IUnknown {
public:
  //
  // Register a MPD chapter
  //  
  virtual void RegisterChapter( IMpdChapter * chapter, MpdType type ) = 0;
  //
  // Unregister a MPD chapter. 
  //  
  virtual void UnRegisterChapter(IMpdChapter* chapter) = 0;
};

//
// value of local override state
//
#define MLS_UNKNOWN 0
#define MLS_ON      1
#define MLS_OFF    2

struct IMpdLocalOverride : IUnknown {
  //
  //  int state;   new state of the MPD local override checkbox
  //
  virtual void SetState(int state) = 0;
};

struct IMpdPageLocalOverride : IMpdLocalOverride {
  //
  //  int state;   new state of the MPD local override checkbox
  //
  virtual void InitLocalOverride(IMpdLocalOverride*) = 0;
};

#endif  // __IMPD_H
