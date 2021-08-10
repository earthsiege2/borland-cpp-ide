//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Implementation of TOleView. Doc/View view derived from TOleWindow that
//   supports Ole2 using OCF TOcView & TOcRemView
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/owlpch.h>
#include <owl/window.h>
#include <owl/gdiobjec.h>
#include <owl/scroller.h>
#include <owl/docmanag.h>
#include <owl/docview.rh>
#include <owl/oleview.rh>
#include <owl/oleframe.h>
#include <owl/oleview.h>
#include <owl/oledoc.h>

//----------------------------------------------------------------------------
// TOleView
//

DEFINE_RESPONSE_TABLE1(TOleView, TOleWindow)
  EV_VN_ISWINDOW,

  // Container specific messages
  //
  EV_VN_INVALIDATE,
  EV_VN_DOCOPENED,
  EV_VN_DOCCLOSED,
  EV_OC_VIEWPARTINVALID,

  // Server specific messages
  //
  EV_OC_VIEWSAVEPART,
  EV_OC_VIEWLOADPART,
  EV_OC_VIEWINSMENUS,
  EV_OC_VIEWCLOSE,
  EV_OC_VIEWOPENDOC,
  EV_OC_VIEWATTACHWINDOW,
  EV_OC_VIEWSETLINK,
  EV_OC_VIEWBREAKLINK,
  EV_OC_VIEWGETITEMNAME,
END_RESPONSE_TABLE;

TOleView::TOleView(TDocument& doc, TWindow* parent)
:
  TView(doc),
  TOleWindow(parent, doc.GetDocManager().GetApplication())
{
  Destroying = false;
  TOleDocument* oleDoc = TYPESAFE_DOWNCAST(&GetDocument(), TOleDocument);
  CHECK(oleDoc);
  OcDoc = oleDoc->GetOcDoc(); // Let OleWindow member point to it for accessor
}

TOleView::~TOleView()
{
  Destroying = true;
  if (IsRemote())
    Destroy();  // make sure that derived TWindow shutdown virtuals get called
  OcDoc = 0;  // we don't own it, don't let TOleWindow delete it
}

//
// Override TOleWindow's version to pass info to TOleDocument & provide a
// second chance to find the RegLink.
//
TOcView*
TOleView::CreateOcView(TRegLink* link, bool isRemote, IUnknown* outer)
{
  // Assume an embedded document until we find out later if we are a link
  // or a load-from-file
  //
  if (isRemote)
    GetDocument().SetEmbedded(true);

  return TOleWindow::CreateOcView(link ? link : GetDocument().GetTemplate(),
                                  isRemote, outer);
}

//
// Override TView's GetViewMenu to make an on-the-fly decision about which
// menu to use: normal, or embedded.
//
TMenuDescr*
TOleView::GetViewMenu()
{
  if (TView::GetViewMenu())
    return TView::GetViewMenu();

//!CQ && not a link!
  if (IsRemote() && GetModule()->FindResource(IDM_OLEVIEWEMBED, RT_MENU))
    SetViewMenu(new TMenuDescr(IDM_OLEVIEWEMBED, GetModule()));
  else
    SetViewMenu(new TMenuDescr(IDM_OLEVIEW, GetModule()));

  return TView::GetViewMenu();
}

//
// Does a given HWND belong to this view? Yes if it is us, or a child of us
//
bool
TOleView::VnIsWindow(HWND hWnd)
{
  return hWnd == HWindow || IsChild(hWnd);
}

//
// Intercept CanClose() to interpose OpenEdit semantics
// Bypasses TOleWindow in order to get Doc query involved
//
bool
TOleView::CanClose()
{
  // We don't want to close the view for DLL servers
  //
  if (IsOpenEditing() && !OcApp->IsOptionSet(amExeMode)) {
    TOleFrame* olefr = TYPESAFE_DOWNCAST(GetApplication()->GetMainWindow(), TOleFrame);
    CHECK(olefr);
    olefr->ShowWindow(SW_HIDE);
    TOleWindow::OleShutDown();
    return false;
  }

  // say yes if there are more than one TOleView's attached to the document
  //
  if (OtherViewExists() || GetOcRemView())
    return true;

  if (Doc->CanClose())
  {
    if (OcDoc)
      OcDoc->Close();
    return true;
  }

  return false;

}

//
//  Check if other TOleView already exists
//
bool
TOleView::OtherViewExists()
{
  TView* curView = GetDocument().GetViewList();
  while (curView) {
    TOleLinkView* oleLinkView = TYPESAFE_DOWNCAST(curView, TOleLinkView);
    if (!oleLinkView && curView != this)
      return true;

    curView = curView->GetNextView();
  }

  return false;
}

//
// Perform normal CleanupWindow, plus let the OcView object know we have closed
//
void
TOleView::CleanupWindow()
{
  if (!OtherViewExists()) {

    TOleWindow::CleanupWindow();

    // Delete the TOleView now rather wait until ~TOleFrame if its parent
    // is TRemViewBucket
    //
    TOleFrame* mainWindow = TYPESAFE_DOWNCAST(GetApplication()->GetMainWindow(),
                                            TOleFrame);
    if (mainWindow && mainWindow->GetRemViewBucket() == Parent && !Destroying)
      GetApplication()->Condemn(this);
  }
}

//
// Shut down the associated OCF partners if possible
//
bool
TOleView::OleShutDown()
{
  TOleWindow::OleShutDown();
  if (OcDoc && !OtherViewExists())
    OcDoc->Close();
  return true;
}


//
//  Invalidate the view region specified by rect
//
bool
TOleView::VnInvalidate(TRect& rect)
{
  InvalidateRect(rect, true);

  return true;
}

//
//  The associated doc is opened
//
bool
TOleView::VnDocOpened(int /*omode*/)
{
  DragPart = 0;
  Pos.SetNull();
  Scale.Reset();
  return true;
}

//
//  The associated doc is closed
//
bool
TOleView::VnDocClosed(int /*omode*/)
{
  OcDoc = 0;
  return true;
}

//
// TOcRemView is going away, disconnect TOleWindow with it so we don't use it
// later. In some cases we also need to delete the document.
//
bool
TOleView::EvOcViewClose()
{
  TOcRemView* ocRemView = GetOcRemView();

  // When TOcRemView gets shut down in the Embed From File case,
  // we need to cleanup the document and view right away. Otherwise,
  // the document and view will be shut down as part of the frame shut down
  // process.
  //
  if (ocRemView && ocRemView->GetKind() == TOcRemView::LoadFromFile) {
    OcView = 0;   // OcView is going away, so don't mess with it
    OcDoc = 0;    // OleDoc will delete OcDoc, so don't mess with it
    delete &GetDocument();
  }
  else {
    TOleWindow::EvOcViewClose();
  }

  return true;
}

//
// Ask server to save itself in the IStorage
//
bool
TOleView::EvOcViewSavePart(TOcSaveLoad far& ocSave)
{
  PRECONDITION(ocSave.StorageI);

  TOleDocument* doc = TYPESAFE_DOWNCAST(&GetDocument(), TOleDocument);
  if (!doc)
    return false;

  doc->SetStorage(ocSave.StorageI, (ocSave.SameAsLoad || ocSave.Remember));

  bool status;
  if (ocSave.SaveSelection) {
    status = doc->CommitSelection(*this, ocSave.UserData);
  }
  else {
    // Save view remote view info such as origin and extent
    //
    TOcRemView* ocRemView = GetOcRemView();
    if (ocRemView)
      ocRemView->Save(ocSave.StorageI);

    status = doc->Commit(true);
  }

  // Restore the original storage
  //
  if (!ocSave.SameAsLoad && !ocSave.Remember)
    doc->RestoreStorage();

  return status;
}

//
// Ask server to load itself from the IStorage
//
bool
TOleView::EvOcViewLoadPart(TOcSaveLoad far& ocLoad)
{
  PRECONDITION(ocLoad.StorageI);

  TOleDocument* doc = TYPESAFE_DOWNCAST(&GetDocument(), TOleDocument);
  doc->SetStorage(ocLoad.StorageI);

  // Load view remote view info such as origin and extent
  //
  CHECK(GetOcRemView());
  GetOcRemView()->Load(ocLoad.StorageI);

  bool status = GetDocument().Open(doc->GetOpenMode());

  if (!ocLoad.Remember)
    doc->SetStorage(0);

  return status;
}

//
// Ask container to open an existing document
// Used for linking from embedding
//
bool
TOleView::EvOcViewOpenDoc(const char far* path)
{
  TOleDocument* oleDoc = TYPESAFE_DOWNCAST(&GetDocument(), TOleDocument);
  CHECK(oleDoc && GetOcDoc());

  oleDoc->SetEmbedded(false); // must really be a link or load-from-file
  oleDoc->SetStorage(0);      // release the current storage
  oleDoc->SetDocPath(path);
  oleDoc->InitDoc();
  oleDoc->Open(ofRead, path);

  string newName(oleDoc->GetDocPath());
  GetOcDoc()->SetName(newName);
  Invalidate();
  return true;
}

//
// Insert server menu into the composite one
//
bool
TOleView::EvOcViewInsMenus(TOcMenuDescr far& sharedMenu)
{
  // Recreate a temporary composite menu for frame and child
  //
  TMenuDescr compMenuDesc; // empty menudescr
  if (GetViewMenu()) {
    compMenuDesc.Merge(*GetViewMenu());
    compMenuDesc.Merge(TMenuDescr(0,  -1, 0, -1, 0, -1, 0));
  }

  TMenuDescr shMenuDescr(sharedMenu.HMenu,
                         sharedMenu.Width[0],
                         sharedMenu.Width[1],
                         sharedMenu.Width[2],
                         sharedMenu.Width[3],
                         sharedMenu.Width[4],
                         sharedMenu.Width[5]);
  shMenuDescr.Merge(compMenuDesc);

  for (int i = 0; i < 6; i++)
    sharedMenu.Width[i] = shMenuDescr.GetGroupCount(i);

  return true;
}

//
// Notify the active view of part data changes
//
bool
TOleView::EvOcViewPartInvalid(TOcPartChangeInfo& changeInfo)
{
  if (changeInfo.IsDataChange())
    GetDocument().SetDirty(true);

  // Reflect the change in part in other (non-active) views
  //
  TRect rect(changeInfo.GetPart()->GetRect());
  rect.right++;
  rect.bottom++;
  TOleClientDC dc(*this);
  dc.LPtoDP((TPoint*)&rect, 2);

  GetDocument().NotifyViews(vnInvalidate, (long)&rect, 0);

  // Notify container if this is an intermediate container
  //
  InvalidatePart((TOcInvalidate)changeInfo.GetType());

  return true;  // stop further processing by OCF
}

//
// Attach this view back to its owl parent for either open editing, or
// mearly inplace de-activating
//
bool
TOleView::EvOcViewAttachWindow(bool attach)
{
  TOleFrame* mainWindow = TYPESAFE_DOWNCAST(GetApplication()->GetMainWindow(),
                                            TOleFrame);
  if (!mainWindow)
    return false;  // server app is shutting down

  // There won't be any TOcRemView if we're reestablishing the link
  //
  if (attach) {
    if (IsOpenEditing()) {
      // Get the normal app notify handler to set up the parent for us
      // knowing that we are now open editing
      //
      if (mainWindow->GetRemViewBucket() == Parent) {
        GetDocument().GetDocManager().PostEvent(dnCreate, *this);
      }
    }
  }
  else {
    if (IsOpenEditing() && Parent != mainWindow)
      Parent->PostMessage(WM_CLOSE);
    SetParent(mainWindow->GetRemViewBucket());  // simple reparent
  }
  return true;
}

//
// Find the item name for whole doc or selection
//
bool
TOleView::EvOcViewGetItemName(TOcItemName& item)
{
  if (item.Selection) {
    if (DragPart) {
      item.Name = DragPart->GetName();
      return true;
    }
  }
  else {
    item.Name = "Content"; // item name representing the whole document
    return true;
  }
  return false;
}

//----------------------------------------------------------------------------
// Linking Spport
//

//
// Establish link with whole doc or selection
//
bool
TOleView::EvOcViewSetLink(TOcLinkView& /*view*/)
{
  return false;
}

//
// Break link with whole doc or selection
//
bool
TOleView::EvOcViewBreakLink(TOcLinkView& view)
{
  // Find the link view with the moniker
  //
  TView* target = GetDocument().QueryViews(vnLinkView, (long)&view, this);

  // Delete a linked view to this document
  //
  delete target;
  return true;
}

//----------------------------------------------------------------------------
// TOleLinkView
//

DEFINE_RESPONSE_TABLE(TOleLinkView)
  EV_VN_LINKVIEW,
  EV_VN_LINKMONIKER,
END_RESPONSE_TABLE;

TOleLinkView::TOleLinkView(TDocument& doc, TOcLinkView& view)
:
  TView(doc),
  OcLinkView(view)
{
}

TOleLinkView::~TOleLinkView()
{
  OcLinkView.Release();
}

//
// See if a TOleLinkView is associated with this TOcRemView
//
bool
TOleLinkView::VnLinkView(TOcLinkView& view)
{
  if (&OcLinkView == &view)
    return true;

  return false;
}

//
// See if a TOleLinkView is associated with this TOcRemView
//
bool
TOleLinkView::VnLinkMoniker(TString& moniker)
{
  if ((char*)OcLinkView.GetMoniker() == (char*)moniker)
    return true;

  return false;
}

//
// Update all links to this view
//
bool
TOleLinkView::UpdateLinks()
{
  OcLinkView.Invalidate(invView);
  return true;
}

//
// Get the moniker corresponding to this view
//
TString&
TOleLinkView::GetMoniker()
{
  return OcLinkView.GetMoniker();
}
