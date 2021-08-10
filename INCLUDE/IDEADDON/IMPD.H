/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  impd.h
  Created: 11/14/95
  Copyright (c) 1995, 1996 Borland International
  $Header:   Y:\admin\bride\addon\deliver\interfac\impd.h_v   1.20   18 Nov 1996 11:29:40   JDOUGLAS  $
  $Revision:   1.20  $
   
  MPD refers to the Multi-Page-Dialog boxes used for setting options in the 
  BCW IDE. A "Chapter" represents a high level item containing one or more
  "Pages" which can be colapsed under the Chapter.

  Interface declared in this file:

  implemented by IDE

  IMpdServer
  IMpdLocalOverride

  implemented by IDE client

  IMpdPage  
  IMpdChapter
  IMpdPageLocalOverride

  Overview:

  User implements IMpdChaper and calls IMpdServer::RegisterChapter() to register
  the chapter. There are two MPDs, Project and Environment in IDE currently.
  Client calls RegisterChapter() with MpdType type == MT_EnvironmentOptions to
  add a chapter to Option|Project MPD or register with MpdType
  type == MT_ProjectOptions to add chapter to Option|Envoronment MPD.

  The following actions occour during MPD open:

    1. IDE calls IMpdChapter::SetEditNode(node) to inform client that IDE
       is about to open a MPD for node. For environment MPD, this argument
       should be ignored.

    2. IDE calls IMpdChapter::GetPageCount() to determine the number of page
       client will have.  If the returned page count is 0, MPD will not show
       any page from this chapter and no calls will be made to this chapter
       until next MPD open.  Client can return different values based
       on the node passed in IMpdChapter::SetEditNode()

    3. If IMpdChapter::GetPageCount() retuns no-zero value.
       IDE calls IMpdChapter::GetPage(iPage) to retrieve all the pages
       available.
       
    4. IDE calls IMpdPage::GetHInstance() and IMpdPage::GetResourceId() to
       locate the MPD dialog resource. 
       IDE calls to IMpdPage::GetPageTitle() to get the text displayed in
       MPD tree window and on top of the dialog page.
       IDE calls GetPageStyle() to determine the chapter configuration in 
       MPD tree window.

    5. When an addon page is selected in MPD, IDE calls IMpdChapter::OpenPage()
       to open an addon page. The PageResourceId in the argument is the returned
       value of IMpdPage::GetResourceId(). It indicates which page to open.

    6. If IMpdChapter::OpenPage() returns a valid IMpdPage. IMpdPage::Init() is
       called and addon page is passed a valid dialog window handle.  If the
       addon page supports IMpdPageLocalOverride interface, 
       IDE calls IMpdPageLocalOverride::InitLocalOverride() and passes addon
       page IMpdLocalOverride interface to intialize local override.  After
       calling Init(), IDE calls SetDlgItems() to initialize the page.

    7. Now the addon page is on the screen.  If user select a different page,
       IDE will call IMpdPage::CanClose() to get permission to switch to a
       different page. If CanClose() returns TRUE, IDE will switch to the new
       page.  Otherwise nothing is changed. If user selects the Undo button,
       IMpdPage::Undo() is called to undo user changes.  Addon page can also
       implement IMpdPage::OnCommand() perform any WM_COMMAND message
       processing.

    8. If user clicks on OK button and IMpdPage::IsModified() returns TRUE,
       IDE calls IMpdPage::GetDlgItems() to retrieve any user changes at the
       dialog UI level.

    9. After the MPD is closed. All clients' IMpdChapter::Close(fOk) is called.
       If user clicks OK button, then fOk is TRUE. Otherwise fOk is FALSE.
    
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

#define MPD_SUMMARY       0x0000
#define MPD_PAGE          0x0001

#define MPDF_OPEN         0x1000
#define MPDF_CLOSE        0x0000

#define MPD_OPENSUMMARY  MPD_SUMMARY|MPDF_OPEN
#define MPD_CLOSEPAGE    MPD_PAGE|MPDF_CLOSE

//.............................................................................
//
//  User implements this class and returns a pointer to an instance of it when
//  IMpdChapter::OpenPage() is called by the AddOn wrapper dll.
//
class IMpdPage : public IUnknown {
 public:
  //
  //  Init() is called when the page dialog object is initially created.
  //  HWND hDlg         dialog window handle of the page
  //  IStatusBar* isb   represent the status window in MPD
  //
  virtual void BCWADDON_CMETHOD Init(HWND hDlg, IStatusBar* isb) = 0;
  //
  // return TRUE if a page can be turned, otherwise return 0.
  //
  virtual BOOL BCWADDON_CMETHOD CanClose() = 0;
  //
  //  SetDlgItems() is called to set the page content to the current state
  //  represented by the application internal data
  //
  virtual void BCWADDON_CMETHOD SetDlgItems() = 0;
  //
  //  GetDlgItems() is called to set the applcaition internal data based
  //  on current user input
  //
  virtual void BCWADDON_CMETHOD GetDlgItems() = 0;
  //
  //  return the modified state of the page
  //  return TRUE if the page has been modified, otherwise return FALSE.
  //
  virtual BOOL BCWADDON_CMETHOD IsModified(void) = 0;
  //
  //  undo user modification on current page. IsModified returns FALSE
  //  after Undo() 
  //
  virtual void BCWADDON_CMETHOD Undo() = 0;
  //
  //  OnComamnd() is called in response to perform WM_COMMAND processing.
  //  If an application processes this message, it should return zero
  //
  virtual LRESULT BCWADDON_CMETHOD OnCommand(UINT id, HWND hWndCtl, UINT notifyCode) = 0;
  //
  //
  //
  virtual HINSTANCE BCWADDON_CMETHOD GetHInstance() = 0;
  virtual UINT BCWADDON_CMETHOD GetResourceId() = 0;
  virtual IPolyString* BCWADDON_CMETHOD GetPageTitle() = 0;
  //
  // return a combination of MPDF_* flags defined in this file
  //
  virtual UINT BCWADDON_CMETHOD GetPageStyle() = 0;
  //
  // call help on the page
  //
  virtual void BCWADDON_CMETHOD Help(BOOL fF1Key) = 0;
  //
  // display information about this page in the status line
  //
  virtual void BCWADDON_CMETHOD DisplayPageStatus() = 0;
};

//.............................................................................
//
// User implements this class and passes a pointer to an instance of it in
// IMpdServer::RegisterChapter.
//
class IMpdChapter : public IUnknown {
 public:
  //
  // SetEditNode set the node to be changed
  //
  //
  virtual void BCWADDON_CMETHOD SetEditNode(ProjectNode node) = 0;
  //
  // open the page indicated by PageResourceId
  //
  virtual IMpdPage* BCWADDON_CMETHOD OpenPage(UINT PageResourceId, ProjectNode node = 0 ) = 0;
  //
  // return the number of pages in the chapter
  //
  virtual UINT BCWADDON_CMETHOD GetPageCount() = 0;
  //
  // The first page starts at 1
  //
  virtual IMpdPage* BCWADDON_CMETHOD GetPage(UINT iPage) = 0;
  //
  // Close() is called when MPD is closed
  // fOk is 1 if user select OK button to close MPD
  //
  virtual void BCWADDON_CMETHOD Close(UINT fOk) = 0;
};

//.............................................................................
class IMpdServer : public IUnknown {
 public:
  //
  // Register a MPD chapter
  //  
  virtual void BCWADDON_CMETHOD RegisterChapter( IMpdChapter * chapter, MpdType type ) = 0;
  //
  // Unregister a MPD chapter. 
  //  
  virtual void BCWADDON_CMETHOD UnRegisterChapter(IMpdChapter* chapter) = 0;
};

//
// value of local override state
//
#define MLS_UNKNOWN 0    // local check box is disabled
#define MLS_ON      1    // local check box is checked
#define MLS_OFF     2    // local check box is not checked

struct IMpdLocalOverride : IUnknown {
  //
  // This interface is implemented by IDE and addon client.
  //
  //  IDE MPD implementation:
  //    SetState() sets the local check box to value passed in state.
  //
  //  Addon client implementation:
  //    IDE calls SetSate() when user checks or unchecks the check box.
  //
  //  int  state:   new state of the MPD local override checkbox
  //
  virtual void BCWADDON_CMETHOD SetState(int state) = 0;
};

struct IMpdPageLocalOverride : IMpdLocalOverride {
  //
  //  addon client implements this interface.  MPD will pass its local
  //  override interface to client thru InitLocalOverride() call.
  // 
  //  The IMpdLocalOverride pointer is good for as long as the MPD page
  //  is open. An easy way to handle the issue of when to release this
  //  is to keep an override pointer around until you are issued a 
  //  new one, via the next call of this method, or until the Chapter
  //  closes.
  //
  virtual void BCWADDON_CMETHOD InitLocalOverride(IMpdLocalOverride*) = 0;
};

#endif  // __IMPD_H
