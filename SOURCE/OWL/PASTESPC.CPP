//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Defines type TPasteSpecialDlg
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/owlpch.h>
#include <owl/listbox.h>
#include <owl/radiobut.h>
#include <owl/edit.h>
#include <ocf/ocview.h>
#include <owl/oledlg.h>
#include <owl/except.h>
#include <bwcc.h>   // for IDHELP
#include <dir.h>

//
// OWL OLE Dialog diagnostic group.
//
DIAG_DECLARE_GROUP(OwlOleDlg);

//
//
//
static bool
CompareTargetDevice(DVTARGETDEVICE FAR* ptdLeft,
                    DVTARGETDEVICE FAR* ptdRight)
{
  if (ptdLeft == ptdRight)
    return true;
  else if (!ptdRight || !ptdLeft)
    return false;
  else if (ptdLeft->tdSize != ptdRight->tdSize)
    return false;
  else if (memcmp(ptdLeft, ptdRight, (int)ptdLeft->tdSize) != 0)
    return false;
  return true;
}

//
// Returns 0 for exact match, 1 for no match, -1 for partial match (which is
// defined to mean the left is a subset of the right: fewer aspects,
// null target device, fewer medium).
//
static int
CompareFormatEtc(FORMATETC FAR* pFetcLeft, FORMATETC FAR* pFetcRight)
{
  bool bExact = true;

  if (pFetcLeft->cfFormat != pFetcRight->cfFormat)
    return 1;
  else if (!CompareTargetDevice (pFetcLeft->ptd, pFetcRight->ptd))
    return 1;
  if (pFetcLeft->dwAspect == pFetcRight->dwAspect)
    //
    // Same aspects implies equality
    //
    ;

  else if ((pFetcLeft->dwAspect & ~pFetcRight->dwAspect) != 0)
    //
    // Left not subset of aspects of right implies not equal
    //
    return 1;
  else
    //
    // left subset of right
    //
    bExact = false;

  if (pFetcLeft->tymed == pFetcRight->tymed)
    // same medium flags; equal
    ;
  else if ((pFetcLeft->tymed & ~pFetcRight->tymed) != 0)
    //
    // left not subset of medium flags of right; not equal
    //
    return 1;
  else
    //
    // left subset of right
    //
    bExact = false;

  return bExact ? 0 : -1;
}

DEFINE_RESPONSE_TABLE1(TPasteSpecialDlg, TOleDialog)
  EV_WM_DRAWCLIPBOARD,
  EV_WM_CHANGECBCHAIN,
  EV_BN_CLICKED(IDC_CHANGEICON, ChangeIconClicked),
  EV_BN_CLICKED(IDC_PASTE, PasteClicked),
  EV_BN_CLICKED(IDC_PASTELINK, PasteLinkClicked),
  EV_BN_CLICKED(IDC_DISPLAYASICON, DisplayAsIconClicked),
  EV_LBN_SELCHANGE(IDC_DISPLAYLIST, DisplayListSelChange),
  EV_LBN_DBLCLK(IDC_DISPLAYLIST, DisplayListDblClk),
END_RESPONSE_TABLE;

//
// Initialize all data members to 0 [or false]
//
TPasteSpecialDlg::TData::TData()
{
  //
  // This class is really just a PODS, so we'll take
  // advantage of memset
  //
  memset(this, 0, sizeof(TData));
}

//
// Initialize all data members to 0 [or false]
//
TPasteSpecialDlg::TPasteListItemData::TPasteListItemData()
{
  //
  // This class is really just a PODS, so we'll take
  // advantage of memset
  //
  memset(this, 0, sizeof(TPasteListItemData));
}

//
// Initialize all data members to 0 [or false]
//
TPasteSpecialDlg::TPasteEntry::TPasteEntry()
{
  //
  // This class is really just a PODS, so we'll take
  // advantage of memset
  //
  memset(this, 0, sizeof(TPasteEntry));
}

//
// Initialize helper object used internally by TPasteSpecialDlg
//
TPasteSpecialDlg::THelper::THelper()
{
  //
  // This structure is a private PODS which allows
  // us to take advantage of memset.
  //
  memset(this, 0, sizeof(THelper));
}

//
// Initialize TPasteSpecial Dialog:
//    - Alias Dialog controls with C++ objects
//    - Initialize internal variables
//
TPasteSpecialDlg::TPasteSpecialDlg(TWindow* parent,
                                   TOcInitInfo &initInfo,
                                   TData *data,
                                   TResId templateId,
                                   const char far *title,
                                   TModule* module):
                  TOleDialog(parent,
                            templateId ? templateId : TResId(DLG_PASTESPECIAL),
                            title,
                            module),
                  InitInfo(initInfo), Helper(*new THelper)
{
  //
  // Wrap controls
  //
  ResultImage     = new TResultImage(this, IDC_RESULTIMAGE);
  IconImage       = new TIconImage(this, IDC_ICONIMAGE);
  DisplayAsIcon   = new TCheckBox(this, IDC_DISPLAYASICON);
  Paste           = new TRadioButton(this, IDC_PASTE);
  PasteLink       = new TRadioButton(this, IDC_PASTELINK);
  DisplayList     = new TListBox(this, IDC_DISPLAYLIST);
  PasteList       = new TListBox(this, IDC_PASTELIST);
  PasteLinkList   = new TListBox(this, IDC_PASTELINKLIST);
  ChangeIcon      = new TButton(this, IDC_CHANGEICON);
  ResultText      = new TStatic(this, IDC_RESULTTEXT);
  SourceText      = new TStatic(this, IDC_SOURCE);
  Help            = new TButton(this, IDHELP);

  //
  // Store TData pointer (if specified)
  //
  Data = data;

  //
  // Init internal variables
  //
  DeleteData       = false;
  pOleUIEntries    = 0;
  pBOleEntries     = 0;
  pBOleLinkEntries = 0;
}

//
// Cleanup memory allocated for TPasteSpecialInfo pointers if
// user relied on default one.
//
TPasteSpecialDlg::~TPasteSpecialDlg()
{
  delete &Helper;

  //
  // Delete Data pointer if we allocated it
  //
  if (DeleteData) {
    delete Data;

    if (pOleUIEntries)
      delete []pOleUIEntries;

    if (pBOleEntries)
      delete []pBOleEntries;

    if (pBOleLinkEntries)
      delete []pBOleLinkEntries;
  }
}

//
// Check if a TPasteSpecialInfo pointer was specified - Create one
// if necessary.
//
int
TPasteSpecialDlg::DoExecute()
{
  if (!Data) {
    if (!GetDefaultPasteSpecialData()) {
      return IDCANCEL;
    }
  }
  return TDialog::DoExecute();
}

//
// Validate flags, Initialize Helper structure,
// Fill Paste/PasteLink listboxes
//
bool
TPasteSpecialDlg::EvInitDialog(HWND hwndFocus)
{
  //
  // Call base to alias controls
  //
  TOleDialog::EvInitDialog(hwndFocus);

  //
  // Enable Wait cursor
  //
  HCURSOR oldCursor = HourGlassOn();

  //
  // Copy user info. and init helper class
  //
  Helper.Flags = Data->Flags;
  Helper.PasteListCurSel = 0;
  Helper.PasteLinkListCurSel = 0;

  //
  // Set control font
  //
  if (Font) {
    ResultText->SetWindowFont(*Font, false);
    SourceText->SetWindowFont(*Font, false);
  }

  //
  // Hide help if requested
  //
  if (!(Helper.Flags & psShowHelp))
    Activate(Help, false);

  //
  // Hide IconDisplay related controls if requested
  //
  if (Helper.Flags & psDisableDisplayAsIcon) {
    Activate(DisplayAsIcon, false);
    Activate(IconImage, false);
    Activate(ChangeIcon, false);
  }

  //
  // Clear 'CheckDisplayAsIcon' [out-flag only]
  //
  Helper.Flags &= ~psCheckDisplayAsIcon;

  //
  // Load 'Unknown Source' and 'Unknown Type' strings
  //
  GetModule()->LoadString(IDS_PSUNKNOWNTYPE,
                          Helper.UnknownType, MaxUnknownLen);
  GetModule()->LoadString(IDS_PSUNKNOWNSRC,
                          Helper.UnknownSource, MaxUnknownLen);
  Helper.AppName[0]= 0;

  //
  // Fill OBJECTDESCRIPTOR structure
  //
  STGMEDIUM medium;
  CLIPFORMAT cfFormat;
  Helper.ObjDesc = FillObjectDescriptorFromData(Data->lpSrcDataObj,
                                                &medium, &cfFormat);
  if (Helper.ObjDesc) {
    LPOBJECTDESCRIPTOR lpOD = (LPOBJECTDESCRIPTOR)GlobalLock(Helper.ObjDesc);

    //
    // Retrieve FullUserTypeName, SourceOfCopy and CLSID
    //
    if (lpOD->dwFullUserTypeName)
      Helper.FullUserTypeNameOD = (LPSTR)lpOD + (int)lpOD->dwFullUserTypeName;
    else
      Helper.FullUserTypeNameOD = Helper.UnknownType;

    if (lpOD->dwSrcOfCopy) {
      Helper.SourceOfDataOD = (LPSTR)lpOD + (int)lpOD->dwSrcOfCopy;

      //
      // If CF_FILENAME is offered, source of copy is a path name;
      // Chop the name to fit the static control it will be displayed in
      //
      if (cfFormat == cfFileName)
        Helper.SourceOfDataOD= ChopText(*SourceText, 0, Helper.SourceOfDataOD);
    }
    else {
      Helper.SourceOfDataOD = Helper.UnknownSource;
    }

    Helper.ClsIdOD = lpOD->clsid;
    Helper.SizeLOD = lpOD->sizel;

    //
    // Update helper class about DVASPECT_ICON & OLEMISC_ONLYICONIC flags
    //
    Helper.SrcAspectIconOD = (lpOD->dwDrawAspect & DVASPECT_ICON) ?
                              true : false;
    Helper.SrcOnlyIconicOD = (lpOD->dwStatus & OLEMISC_ONLYICONIC) ?
                              true : false;

    //
    // Get App. Name of source from auxusertype3 in reg. database
    //
    if (!GetAuxUserType(Helper.ClsIdOD, 3, Helper.AppName, MaxKeyLen, 0)) {
      //
      // Default to "the application which created it" as the name
      //
      GetModule()->LoadString(IDS_PSUNKNOWNAPP, Helper.AppName, MaxKeyLen);
    }

    //
    // Retrieve an icon from the object
    //
    if (Helper.SrcAspectIconOD) {
      Helper.MetaPictOD = GetData(Data->lpSrcDataObj,
                                  CF_METAFILEPICT, 0,
                                  DVASPECT_ICON, &medium);
    }

   //
    // If none, retrieve icon from CLSID
    //
    if (!Helper.MetaPictOD) {
      Helper.MetaPictOD = GetIconFromClass(Helper.ClsIdOD, 0, TRUE);
    }
  }

  //
  // Does object offer CF_LINKSRCDESCRIPTOR
  //
  Helper.LinkSrcDesc = GetData(Data->lpSrcDataObj,
                               cfLinkSrcDescriptor, 0,
                               DVASPECT_CONTENT, &medium);
  if (Helper.LinkSrcDesc) {
    LPLINKSRCDESCRIPTOR lpLSD = (LPLINKSRCDESCRIPTOR)
                                 GlobalLock(Helper.LinkSrcDesc);

    //
    // Get FullUserTypeName, SourceOfCopy and CLSID
    //
    if (lpLSD->dwFullUserTypeName)
      Helper.FullUserTypeNameLSD = (LPSTR)lpLSD +
                                     (int)lpLSD->dwFullUserTypeName;
    else
      Helper.FullUserTypeNameLSD = Helper.UnknownType;

   if (lpLSD->dwSrcOfCopy)
      Helper.SourceOfDataLSD = (LPSTR)lpLSD + (int)lpLSD->dwSrcOfCopy;
    else
      Helper.SourceOfDataLSD = Helper.UnknownSource;

    //
    // If no objectDescriptor, use linkSourceDescriptor source string
    //
    if (!Helper.ObjDesc)
      Helper.SourceOfDataOD = Helper.SourceOfDataLSD;

    Helper.ClsIdLSD = lpLSD->clsid;
    Helper.SizeLLSD = lpLSD->sizel;

    //
    // Update helper class about DVASPECT_ICON & OLEMISC_ONLYICONIC
    //
    Helper.SrcAspectIconLSD = (lpLSD->dwDrawAspect & DVASPECT_ICON) ?
                               true : false;
    Helper.SrcOnlyIconicLSD = (lpLSD->dwStatus & OLEMISC_ONLYICONIC) ?
                               true : false;

    //
    // Retrieve an icon from object
    //
    if (Helper.SrcAspectIconLSD) {
      Helper.MetaPictLSD = GetData(Data->lpSrcDataObj,
                                   CF_METAFILEPICT, 0,
                                   DVASPECT_ICON, &medium);
      //
      // If object offers none, retrieve icon from CLSID
      //
      if (!Helper.MetaPictLSD) {
        //
        // Retrieve 1.5 times width of iconbox
        //
        TRect rect;
        IconImage->GetClientRect(rect);
        int width = rect.Width() *3/2;

        //
        // Chop label to fit width
        //
        char  label[MaxLabelLen];
        strcpyn(label, Helper.SourceOfDataLSD, sizeof(label));
        label[sizeof(label)-1] = 0;
        LPSTR lpszLabel = ChopText(*IconImage, width, label);

        //
        // Retrieve icon
        //
        Helper.MetaPictLSD = GetIconFromClass(Helper.ClsIdLSD,
                                              lpszLabel, FALSE);
      }
    }
  }
  else if (Helper.ObjDesc)  // Offers no LINKSRCDESCRIPTOR but
  {                         // Offers OBJECTDESCRIPTOR - Copy OD values!
    Helper.FullUserTypeNameLSD = Helper.FullUserTypeNameOD;
    Helper.SourceOfDataLSD     = Helper.SourceOfDataOD;
    Helper.ClsIdLSD            = Helper.ClsIdOD;
    Helper.SizeLLSD            = Helper.SizeLOD;
    Helper.SrcAspectIconLSD    = Helper.SrcAspectIconOD;
    Helper.SrcOnlyIconicLSD    = Helper.SrcOnlyIconicOD;

    //
    // Grab copy of MetaPict
    //
    if (Helper.SrcAspectIconLSD) {
      Helper.MetaPictLSD = GetData(Data->lpSrcDataObj,
                                   CF_METAFILEPICT, 0,
                                   DVASPECT_ICON, &medium);
    }

    //
    // Retrieve icon from CLSID
    //
    if (!Helper.MetaPictLSD) {
      //
      // Retrieve 1.5 times width of iconbox
      //
      TRect rect;
      IconImage->GetClientRect(rect);
      int width = rect.Width() *3/2;

      //
      // Chop label to fit width
      //
      char  label[MaxLabelLen];
      strcpyn(label, Helper.SourceOfDataLSD, sizeof(label));
      label[sizeof(label)-1] = 0;
      LPSTR lpszLabel = ChopText(*IconImage, width, label);

      //
      // Retrieve Icon
      //
      Helper.MetaPictLSD = GetIconFromClass(Helper.ClsIdLSD,
                                            lpszLabel, FALSE);
    }
  }

  //
  // We have a non-OLE object
  //
  if (!Helper.ObjDesc  &&  !Helper.LinkSrcDesc) {
    Helper.FullUserTypeNameLSD =
    Helper.FullUserTypeNameOD  = Helper.UnknownType;

    Helper.SourceOfDataLSD =
    Helper.SourceOfDataOD  = Helper.UnknownSource;

    Helper.MetaPictLSD = Helper.MetaPictOD = 0;
  }

  //
  // Update Flags: paste vs. pastelink
  //
  if (Helper.Flags & psSelectPasteLink)
    Helper.Flags = (Helper.Flags & ~psSelectPaste) | psSelectPasteLink;
  else
    Helper.Flags = (Helper.Flags & ~psSelectPasteLink) | psSelectPaste;

  //
  // Mark which PasteEntry formats are available from source data object
  //
  MarkPasteEntryList(Data->lpSrcDataObj, Data->ArrayPasteEntries,
                     Data->cPasteEntries);

  //
  // Check if items are available for pasting
  //
  bool pasteAvailable = FillPasteList();
  if (!pasteAvailable) {
    Helper.Flags &= ~psSelectPaste;
    Paste->EnableWindow(false);
  }

  //
  // Check if items are available for paste-linking
  //
  bool pasteLinkAvailable = FillPasteLinkList();
  if (!pasteLinkAvailable) {
    Helper.Flags &= ~psSelectPasteLink;
    PasteLink->EnableWindow(false);
  }

  //
  // Validate flags base on paste availability
  //
  if (pasteAvailable && !pasteLinkAvailable)
    Helper.Flags |= psSelectPaste;

  if (pasteLinkAvailable && !pasteAvailable)
    Helper.Flags |= psSelectPasteLink;

  if (Helper.Flags & psSelectPaste) {
    CheckRadioButton(IDC_PASTE, IDC_PASTELINK, IDC_PASTE);

    //
    // TogglePaste will set paste flag, so clear it first
    //
    Helper.Flags &= ~psSelectPaste;
    TogglePasteType(psSelectPaste);
  }
  else if (Helper.Flags & psSelectPasteLink) {
    CheckRadioButton(IDC_PASTE, IDC_PASTELINK, IDC_PASTELINK);

    //
    // TogglePaste will set pasteLink flag, so clear it first
    //
    Helper.Flags &= psSelectPasteLink;
    TogglePasteType(psSelectPasteLink);
  }
  else {
    EnableDisplayAsIcon();
    SetPasteSpecialHelpResults();
  }

  //
  // Set Focus to ListBox
  //
  DisplayList->SetFocus();

  //
  // Set property to handle clipboard change notifications
  //
  SetProp(NEXTCBVIEWER, HWND_BROADCAST);
  SetProp(NEXTCBVIEWER, SetClipboardViewer(*this));
  Helper.ClipboardChanged = false;

  //
  // Restore previous cursor
  //
  HourGlassOff(oldCursor);

  return false;
}

//
//
//
void
TPasteSpecialDlg::CleanupWindow()
{
  //
  // Free metafile of non-selected option
  //
  if (Helper.Link)
    TOleMetaPict::Free(Helper.MetaPictOD);
  else
    TOleMetaPict::Free(Helper.MetaPictLSD);

  //
  // Free listbox entries
  //
  FreeListData(*PasteList);
  FreeListData(*PasteLinkList);

  //
  // Free memory allocations
  //
  if (Helper.ObjDesc)
    GlobalFree(Helper.ObjDesc);

  if (Helper.LinkSrcDesc)
    GlobalFree(Helper.LinkSrcDesc);

  //
  // Remove ourselves from Clipboard notification chain
  //
  HWND hwndNextViewer;
  hwndNextViewer = (HWND)GetProp(NEXTCBVIEWER);
  if (hwndNextViewer != HWND_BROADCAST) {
    SetProp(NEXTCBVIEWER, HWND_BROADCAST);
    ChangeClipboardChain(*this, hwndNextViewer);
  }
  RemoveProp(NEXTCBVIEWER);
}

//
// Handles User activating OK button by retrieving the current
// selection and updating the TPasteSpecialInfo and TOcInitInfo
// structures.
//
bool
TPasteSpecialDlg::OleDlgOk()
{
  //
  // Copy Helper information to Data structure
  //
  bool fDestAspectIcon = (Helper.Flags & psCheckDisplayAsIcon) ? true : false;
  Data->Flags = Helper.Flags;
  Data->SelectedIndex = Helper.SelectedIndex;
  Data->fLink = Helper.Link;
  if (Helper.Link) {
    if (Helper.SrcAspectIconLSD == fDestAspectIcon)
      Data->SizeL = Helper.SizeLLSD;
    else
      Data->SizeL.cx = Data->SizeL.cy = 0;
  }
  else {
    if (Helper.SrcAspectIconOD == fDestAspectIcon)
      Data->SizeL = Helper.SizeLOD;
    else
      Data->SizeL.cx = Data->SizeL.cy = 0;
  }

  //
  // Grab selected metafile
  //
  Data->MetaPict = IconImage->GetMetaPict();

  //
  // Update TOcInitInfo data
  //
  if (Data->Flags & psCheckDisplayAsIcon)
    InitInfo.HIcon = (HICON)Data->MetaPict;

  LPDATAOBJECT pDataObj = Data->lpSrcDataObj;
  int i = Data->SelectedIndex;

  //
  // Retrieve selected clipboard format - If we have the BOleFormat handy,
  // go there since it's 'nearer' - otherwise use the Data data
  //
  CLIPFORMAT cf;
  if (pBOleEntries)
    cf = pBOleEntries[i].Id;
  else
    cf = Data->ArrayPasteEntries[i].fmtetc.cfFormat;

  if (cf == cfEmbeddedObject) {
    InitInfo.How   = ihEmbed;
    InitInfo.Where = iwDataObject;
    InitInfo.Data  = pDataObj;
  }
  else if (cf == cfEmbedSource) {
    InitInfo.How     = ihEmbed;
    InitInfo.Where   = iwDataObject;
    InitInfo.Data    = pDataObj;
    InitInfo.Storage = 0;
  }
  else if (cf == cfLinkSource) {
    InitInfo.How   = ihLink;
    InitInfo.Where = iwDataObject;
    InitInfo.Data  = pDataObj;
  }
  else {
    STGMEDIUM medium;
    InitInfo.How   = Data->fLink ? ihLink : ihEmbed;
    InitInfo.Where = iwHandle;
    InitInfo.Handle.DataFormat = cf;

    if (!Data->fLink)
      InitInfo.Handle.Data = GetData(pDataObj, cf, 0,
                                     DVASPECT_CONTENT, &medium);
    //
    // Release data object since we're only passing back a handle [not
    // the data object]
    //
    pDataObj->Release();
  }

  return true;
}

//
// Allocate and Initialize a TPasteSpecialData structure [used if no
// TPasteSpecialData pointer was specified with constructing dialog]
//
bool
TPasteSpecialDlg::GetDefaultPasteSpecialData()
{
  //
  // Should be called only if user did not specify a TPasteSpecialInfo ptr.
  //
  PRECONDITION(Data == 0);

  //
  // Find container we'll be pasting in
  //
  IBContainer far* pCont = 0;
  if (InitInfo.Container)
    pCont = InitInfo.Container;
  else {
    TRACEX(OwlOleDlg, 1, "Container to paste in not found");
    return false;
  }

  //
  // Find data consumer from container
  //
  IBDataConsumer far* pConsumer = 0;
  HRESULT hRes = pCont->QueryInterface(IID_IBDataConsumer,
                                       &(LPVOID)pConsumer);

  if (!SUCCEEDED(hRes)) {
    TRACEX(OwlOleDlg, 1, "Container data consumer not found");
    return false;
  }
  else {
    pConsumer->Release();
  }

  //
  // Check if clipboard is empty or (maybe) unavailable
  //
  LPDATAOBJECT pDataObj = 0;
  if (OleGetClipboard(&pDataObj) != S_OK) {
    TRACEX(OwlOleDlg, 1, "Clipboard's unavailable to paste from");
    return false;
  }

  //
  // Retrieve acceptable formats
  //
  uint nAcceptableFormats = 0;
  nAcceptableFormats = pConsumer->CountFormats();
  if (!nAcceptableFormats) {
    TRACEX(OwlOleDlg, 1, "No acceptable formats from consumer");
    return false;
  }

  //
  // Allocate Dialog parameter information
  //
  pOleUIEntries    = new TPasteEntry[nAcceptableFormats];
  pBOleEntries     = new TOcFormatInfo[nAcceptableFormats];
  pBOleLinkEntries = new uint[nAcceptableFormats];
  Data             = new TData;
  DeleteData       = true;

  //
  // Iterate through formats to initialize structures and track
  // linkable formats
  //
  uint nLinkableFormats   = 0;
  for (int i=0; i<nAcceptableFormats; i++) {
    pConsumer->GetFormat(i, &pBOleEntries[i]);

    InitFormatEtc(pOleUIEntries[i].fmtetc, pBOleEntries[i].Id,
                  pBOleEntries[i].Medium);
    pOleUIEntries[i].lpstrFormatName = pBOleEntries[i].Name[0] ?
                                OleStr(pBOleEntries[i].Name) : OleText("%s");
    pOleUIEntries[i].lpstrResultText =
                          pBOleEntries[i].ResultName[0] ?
                            OleStr(pBOleEntries[i].ResultName) : OleText("%s");
    pOleUIEntries[i].dwFlags =  pBOleEntries[i].IsLinkable ?
                                pfPaste : pfPasteOnly;

    if (pBOleEntries[i].Id == cfEmbeddedObject ||
        pBOleEntries[i].Id == cfLinkSource     ||
        pBOleEntries[i].Id == cfEmbedSource     ) {
      //
      // PasteOnly and EnableIcon are mutually exclusive
      //
      if (pOleUIEntries[i].dwFlags == pfPaste)
        pOleUIEntries[i].dwFlags |= pfEnableIcon;
    }

    if (pBOleEntries[i].IsLinkable) {
      pBOleLinkEntries[nLinkableFormats] = pBOleEntries[i].Id;

      DWORD flag;
      switch(nLinkableFormats) {
        case  0:  flag  = pfLinkType1;  break;
        case  1:  flag  = pfLinkType2;  break;
        case  2:  flag  = pfLinkType2;  break;
        case  3:  flag  = pfLinkType2;  break;
        case  4:  flag  = pfLinkType2;  break;
        case  5:  flag  = pfLinkType2;  break;
        case  6:  flag  = pfLinkType2;  break;
        case  7:  flag  = pfLinkType2;  break;
      }
      pOleUIEntries[i].dwFlags |= flag;
      nLinkableFormats++;
    }
  }

  //
  // Store all relevant PasteSpecial Initialization information
  //
  Data->ArrayPasteEntries = pOleUIEntries;
  Data->cPasteEntries     = nAcceptableFormats;
  Data->lpSrcDataObj      = pDataObj;
  Data->ArrayLinkTypes    = pBOleLinkEntries;
  Data->cLinkTypes        = nLinkableFormats;
  Data->cClsIdExclude     = 0;

  return true;
}

//
//  Mark each entry in the PasteEntryList if its format is available from
//  the source IDataObject*. the dwScratchSpace field of each PasteEntry
//  is set to TRUE if available, else FALSE.
//
void TPasteSpecialDlg::MarkPasteEntryList(LPDATAOBJECT      lpSrcDataObj,
                                          TPasteEntry far*  lpPriorityList,
                                          int               cEntries)
{
  LPENUMFORMATETC     lpEnumFmtEtc = NULL;
  FORMATETC           rgfmtetc[MaxFormatEtc];
  int                 i;
  HRESULT             hrErr;
  long                j, cFetched;

  //
  // Clear all marks
  //
  for (i = 0; i < cEntries; i++) {
    lpPriorityList[i].dwScratchSpace = FALSE;

    if (! lpPriorityList[i].fmtetc.cfFormat) {
      //
      // Caller wants this item always considered available
      // (by specifying a NULL format)
      //
      lpPriorityList[i].dwScratchSpace = TRUE;
    }
    else if (lpPriorityList[i].fmtetc.cfFormat == cfEmbeddedObject
            || lpPriorityList[i].fmtetc.cfFormat == cfEmbedSource
            || lpPriorityList[i].fmtetc.cfFormat == cfFileName) {

      //
      // If there is an OLE object format, then handle it
      // specially by calling OleQueryCreateFromData. the caller
      // need only specify one object type format.
      //
      TRACEX(OwlOleDlg, 1, "OleQueryCreateFromData called");
      hrErr = OleQueryCreateFromData(lpSrcDataObj);

      if(NOERROR == hrErr) {
        lpPriorityList[i].dwScratchSpace = TRUE;
      }
    }
    else if (lpPriorityList[i].fmtetc.cfFormat == cfLinkSource) {

      //
      // If there is OLE 2.0 LinkSource format, then handle it
      // specially by calling OleQueryLinkFromData.
      //
      TRACEX(OwlOleDlg, 1, "OleQueryLinkFromData called");
      hrErr = OleQueryLinkFromData(lpSrcDataObj);
      if(NOERROR == hrErr) {
        lpPriorityList[i].dwScratchSpace = TRUE;
      }
    }
  }

  TRACEX(OwlOleDlg, 1, "IDataObject::EnumFormatEtc called" );
  hrErr = lpSrcDataObj->EnumFormatEtc(DATADIR_GET,
                                      (LPENUMFORMATETC FAR*)&lpEnumFmtEtc);

  if (hrErr != NOERROR) {
    TRACEX(OwlOleDlg, 1, "Unable to get format enumerator." );
    return;   
  }

  //
  // Enumerate the formats offered by the source
  // Loop over all formats offered by the source
  //
  cFetched = 0;
  memset(rgfmtetc, 0, sizeof(rgfmtetc[MaxFormatEtc]));
  if (lpEnumFmtEtc->Next(MaxFormatEtc, rgfmtetc, (ULONG*)&cFetched) == NOERROR
    || (cFetched > 0 && cFetched <= MaxFormatEtc) ) {

    for (j = 0; j < cFetched; j++) {
      for (i = 0; i < cEntries; i++) {
        if (! lpPriorityList[i].dwScratchSpace &&
          CompareFormatEtc(&rgfmtetc[(int)j], &lpPriorityList[i].fmtetc)==0) {
          lpPriorityList[i].dwScratchSpace = TRUE;
        }
      }
    }
  } 

  //
  // Clean up
  //
  if (lpEnumFmtEtc)
    lpEnumFmtEtc->Release();
}

//
// Toggles between Paste and PasteLink. NOTE: The Paste and PasteLink
//  ListBoxes are always invisible. The third visible listbox [displayListBox]
// is filled with the contents of the Paste or PasteLink Listbox
//
bool
TPasteSpecialDlg::TogglePasteType(TPasteSpecialFlags flag)
{
  PRECONDITION(flag == psSelectPaste  ||
               flag == psSelectPasteLink);

  //
  // Skip if option's already selected
  //
  if (Helper.Flags & flag)
    return true;

  //
  // Update Flags
  //
  Helper.Flags= (Helper.Flags & ~(psSelectPaste | psSelectPasteLink)) | flag;

  //
  // Prevent icon display flashes
  //
  Activate(IconImage, false);

  //
  // Update Source and Icon displays and save index
  //
  TListBox *fromList = 0;
  if (Helper.Flags & psSelectPaste) {
    //
    // Set source of object in clipboard
    //
    SourceText->SetText(Helper.SourceOfDataOD);

    //
    // Update Icon is one's available
    //
    if (Helper.MetaPictOD)
      IconImage->SetMetaPict(Helper.MetaPictOD);

    //
    // Save current PasteLink index
    //
    Helper.PasteLinkListCurSel = DisplayList->GetSelIndex();
    if (Helper.PasteLinkListCurSel == LB_ERR)
      Helper.PasteLinkListCurSel = 0;

    //
    // Clear link flag
    //
    Helper.Link = false;

    fromList    = PasteList;
  }
  else { // PasteLink selected
    //
    // Update source of object in clipboard
    //
    SourceText->SetText(Helper.SourceOfDataLSD);

    //
    // Update Icon if one's available
    //
    if (Helper.MetaPictLSD)
      IconImage->SetMetaPict(Helper.MetaPictLSD);

    //
    // Save current Paste index
    //
    Helper.PasteListCurSel = DisplayList->GetSelIndex();
    if (Helper.PasteListCurSel == LB_ERR)
      Helper.PasteListCurSel = 0;

    //
    // Set Link Flag
    //
    Helper.Link = true;

    fromList    = PasteLinkList;
  }

  //
  // Refill display list
  //
  DisplayList->SetRedraw(false);
  DisplayList->ClearList();

  int itemCount = fromList->GetCount();
  TPointer<char> buff = new char[GenericBufferLen];
  for (int i=0; i<itemCount; i++) {
    //
    // Store strings
    //
    fromList->GetString(buff, i);
    DisplayList->InsertString(buff, i);

    //
    // Store item data
    //
    DisplayList->SetItemData(i, fromList->GetItemData(i));
  }

  //
  // Retore saved index
  //
  if (Helper.Flags & psSelectPaste)
    DisplayList->SetSelIndex(Helper.PasteListCurSel);
  else
    DisplayList->SetSelIndex(Helper.PasteLinkListCurSel);

  //
  // Update Display Listbox
  //
  DisplayList->SetRedraw(true);
  DisplayList->Invalidate();
  DisplayList->UpdateWindow();

  //
  // Focus on Display Listbox
  //
  DisplayList->SetFocus();

  //
  // Allow updating of 'displayAsIcon', help result and bitmap
  // according to the new selection
  //
  ChangeListSelection();

  return false;
}

//
// Called when user changes the selection in the Listbox to enable/disable
// 'DisplayAsIcon' and update the result text and bitmap.
//
void
TPasteSpecialDlg::ChangeListSelection()
{
  //
  // Update result text&bitmap and enable/disable 'DisplayAsIcon'
  //
  EnableDisplayAsIcon();
  SetPasteSpecialHelpResults();

  //
  // Retrieve selected index
  //
  int curSel = DisplayList->GetSelIndex();
  if (curSel == LB_ERR)
    return;

  //
  // Retrieve item data associated with index
  //
  TPasteListItemData FAR* itemData;
  itemData = (TPasteListItemData FAR*)DisplayList->GetItemData(curSel);

  if ((long)itemData == LB_ERR)
   return;

  //
  // Save index
  //
  Helper.SelectedIndex = itemData->nPasteEntriesIndex;
}

//
// Enables/Disables 'DisplayAsIcon' based on the current source selection
// container's specification as outlined in table below:
//
//------------------------------------------------------------------------+
// Src. specifies | Src specifies      | Contnr specifies|  NET  RESULTS  |
// DVASPECT_ICON  | OLEMISC_ONLYICONIC | pfEnableIcon    | Check - Enable |
// ===============+====================+=================+================+
//    N/A         |     N/A            |     N           |   N        N   |
// ---------------+--------------------+-----------------+----------------|
//    N/A         |      Y             |     Y           |   Y        N   |
// ---------------+--------------------+-----------------+----------------|
//     Y          |      N             |     Y           |   Y        Y   |
// ---------------+--------------------+-----------------+----------------|
//     N          |      N             |     Y           |   N        Y   |
// ---------------+--------------------+-----------------+----------------|
//
void
TPasteSpecialDlg::EnableDisplayAsIcon()
{
  bool srcOnlyIconic = (Helper.Link) ? Helper.SrcOnlyIconicLSD :
                                       Helper.SrcOnlyIconicOD;
  bool srcAspectIcon = (Helper.Link) ? Helper.SrcAspectIconLSD :
                                       Helper.SrcAspectIconOD;
  HGLOBAL metaPict   = (Helper.Link) ? Helper.MetaPictLSD :
                                       Helper.MetaPictOD;
  bool cntrEnableIcon = false;;
  int  index = DisplayList->GetSelIndex();

  //
  // Get data of current selection
  //
  if (index != LB_ERR) {
    TPasteListItemData FAR* itemData;
    itemData = (TPasteListItemData FAR*)DisplayList->GetItemData(index);
    if ((long)itemData != LB_ERR) {
      cntrEnableIcon = itemData->fCntrEnableIcon;
    }
    else {
      cntrEnableIcon = false;
    }
  }

  //
  // If there's an icon available
  //
  if (metaPict) {
    //
    // Does container specify pfEnableIcon (OLEUIPASTE_ENABLEICON)?
    //
    if (!cntrEnableIcon) {
      //
      // Uncheck and disable 'DisplayAsIcon'
      //
      Helper.Flags &= ~psCheckDisplayAsIcon;
      DisplayAsIcon->Uncheck();
      DisplayAsIcon->EnableWindow(false);

      //
      // Hide the icon image and 'ChangeIcon'
      //
      Activate(ChangeIcon, false);
      Activate(IconImage, false);
    }
    else if (srcOnlyIconic) {     // Does SOURCE specify OLEMISC_ONLYICONIC
      //
      // Check and Disable 'DisplayAsIcon'
      //
      Helper.Flags |= psCheckDisplayAsIcon;
      DisplayAsIcon->Check();
      DisplayAsIcon->EnableWindow(false);

      //
      // Show iconImage and ChangeIcon button
      //
      Activate(ChangeIcon, true);
      Activate(IconImage, true);
    }
    else if (srcAspectIcon) {     // Does SOURCE specify DVASPECT_ICON
      //
      // Check and Enable 'DisplayAsIcon'
      //
      Helper.Flags |= psCheckDisplayAsIcon;
      DisplayAsIcon->Check();
      DisplayAsIcon->EnableWindow(true);

      //
      // Show iconImage and ChangeIcon button
      //
      Activate(ChangeIcon, true);
      Activate(IconImage, true);
    }
    else {
      //
      // Uncheck and Enable DisplayAsIcon
      //
      Helper.Flags &= ~psCheckDisplayAsIcon;
      DisplayAsIcon->Uncheck();
      DisplayAsIcon->EnableWindow(true);

      //
      // Hide IconImage and ChangeIcon button
      //
      Activate(ChangeIcon, false);
      Activate(IconImage, false);
    }
  }
  else {                      // No Icon is available
    //
    // Uncheck and Disable displayAsIcon
    //
    Helper.Flags &= ~psCheckDisplayAsIcon;
    DisplayAsIcon->Uncheck();
    DisplayAsIcon->EnableWindow(false);

    //
    // Hide iconImage and ChangeIcon button
    //
    Activate(ChangeIcon, false);
    Activate(IconImage, false);
  }
}

//
// Updates the flags; Hides/Shows the IconImage control and the
// ChangeIcon Button - Also updates the help result text and bitmap.
//
void
TPasteSpecialDlg::ToggleDisplayAsIcon()
{
  bool checked = IsDlgButtonChecked(IDC_DISPLAYASICON) ? true : false;

  //
  // Update Flags
  //
  if (checked)
    Helper.Flags |= psCheckDisplayAsIcon;
  else
    Helper.Flags &= ~psCheckDisplayAsIcon;

  //
  // Set result text and bitmap
  //
  SetPasteSpecialHelpResults();

  //
  // Show/hide Icon and ChgIcon button
  //
  Activate(IconImage, checked);
  Activate(ChangeIcon, checked);
}

//
//
//
bool
TPasteSpecialDlg::HasPercentS(const char far* str)
{
  if (!str)
    return false;

  //
  // Copy passed string to local buffer
  //
  TPointer<char> buff = new char[GenericBufferLen];
  strcpy(buff, str);

  char* pBuff = buff;
  while(*pBuff) {
    if (*pBuff == '%') {
      pBuff = AnsiNext(pBuff);
      if (*pBuff == 's') {
        return true;
      }
      else if (*pBuff == '%') {
        pBuff = AnsiNext(pBuff);
      }
    }
    else {
      pBuff = AnsiNext(pBuff);
    }
  }
  return false;
}

//
//
//
void
TPasteSpecialDlg::SetPasteSpecialHelpResults()
{
  int selIndex = DisplayList->GetSelIndex();
  if (selIndex == LB_ERR) {
    TRACEX(OwlOleDlg, 1, "No item selected to display HelpResults");
    return;
  }

  TPasteListItemData FAR *lpItemData;
  lpItemData = (TPasteListItemData FAR*)DisplayList->GetItemData(selIndex);
  if ((LRESULT)lpItemData == LB_ERR) {
    TRACEX(OwlOleDlg, 1, "No PasteListItemData found at " << selIndex);
    return;
  }

  int  nPasteEntriesIndex = lpItemData->nPasteEntriesIndex;
  bool fIsObject = HasPercentS(
         Data->ArrayPasteEntries[nPasteEntriesIndex].lpstrFormatName
                     );

  bool fDisplayAsIcon = (Helper.Flags & psCheckDisplayAsIcon) ? true : false;
  LPSTR lpszFullUserTypeName = Helper.Link ?  Helper.FullUserTypeNameLSD :
                                              Helper.FullUserTypeNameOD;
  LPSTR lpszInsert = lpszFullUserTypeName;

  uint iString = 0;
  uint iImage  = 0;

  if (Helper.Flags & psSelectPaste) {
    if (fIsObject) {
      iString = fDisplayAsIcon ? IDS_PSPASTEOBJECTASICON : IDS_PSPASTEOBJECT;
      iImage  = fDisplayAsIcon ? riEmbedIcon : riEmbed;
      lpszInsert = Helper.AppName;
    }
    else {
      iString = IDS_PSPASTEDATA;
      iImage  = riPaste;
    }
  }
  else if (Helper.Flags & psSelectPasteLink) {
    if (fIsObject) {
      iString = fDisplayAsIcon ? IDS_PSPASTELINKOBJECTASICON :
                                 IDS_PSPASTELINKOBJECT;
      iImage  = fDisplayAsIcon ? riLinkIcon : riLink;
    }
    else {
      iString = IDS_PSPASTELINKDATA;
      iImage  = riLink;
    }
  }
  else {
    TRACEX(OwlOleDlg, 1, "Non-OLE object - Error!");
    iString = IDS_PSNONOLE;
    iImage  = riPaste;
  }

  //
  // Allocator buffers to build help text
  //
  TPointer<char> pstr1 = new char[GenericBufferLen];
  TPointer<char> pstr2 = new char[GenericBufferLen];
  TPointer<char> pstr3 = new char[GenericBufferLen];
  TPointer<char> pstr4 = new char[GenericBufferLen];

  //
  // Build String from resource.
  //
  *((char*)pstr1) = 0;    // Default to empty string
  if (GetModule()->LoadString(iString, (LPSTR)(char*)pstr1, GenericBufferLen)) {
    wsprintf((LPSTR)(char*)pstr3,
             Data->ArrayPasteEntries[nPasteEntriesIndex].lpstrResultText,
             lpszInsert);

    wsprintf((LPSTR)(char*)pstr4, (LPSTR)(char*)pstr1, (LPSTR)(char*)pstr3);
    strcpy(pstr1, pstr4);
  }

  //
  // Update Display
  //
  ResultText->SetText(pstr1);
  ResultImage->SetBitmapIndex(iImage);
}

//
// Adds the name of an object to the Paste or PasteLink listboxes.
//
bool
TPasteSpecialDlg::AddPasteListItem(TListBox &list, bool insertFirst,
                                   int pasteEntryIndex,
                                   const char far* fullUserTypeName)
{
  TPointer<char> buff = new char[GenericBufferLen];
  TPasteListItemData FAR* pItemData = new TPasteListItemData;

  //
  // Initialize PasteList Item Data
  //
  pItemData->nPasteEntriesIndex = pasteEntryIndex;
  if (Data->ArrayPasteEntries[pasteEntryIndex].dwFlags &  pfEnableIcon) {
    pItemData->fCntrEnableIcon = TRUE;
  }
  else {
    pItemData->fCntrEnableIcon = FALSE;
  }

  //
  // Build the listbox entry string
  //
  wsprintf((LPSTR)(char*)buff,
           Data->ArrayPasteEntries[pasteEntryIndex].lpstrFormatName,
           (LPSTR)fullUserTypeName);

  //
  // Add data if it's not a duplicate
  //
  if (list.FindString(buff, 0) == LB_ERR) {
    int index = insertFirst ? list.InsertString(buff, 0) : list.AddString(buff);
    list.SetItemData(index, (LPARAM)pItemData);
  }
  else {
    delete pItemData;
  }
  return true;
}

//
// Fill the (invisible) Paste listbox with the formats offered by the
// Clipboard object and asked form by the container
//
bool
TPasteSpecialDlg::FillPasteList()
{
  int   items = 0;
  int   defFormat = -1;
  bool  insertFirst = false;
  bool  tryObjFmt   = false;
  bool  exclude     = false;

  //
  // Loop through target's priority list of formats
  //
  for (int i=0; i<Data->cPasteEntries; i++) {
    if (Data->ArrayPasteEntries[i].dwFlags != pfPasteOnly  &&
        !(Data->ArrayPasteEntries[i].dwFlags & pfPaste))
      continue;

    insertFirst = false;

    if (Data->ArrayPasteEntries[i].fmtetc.cfFormat == cfFileName  ||
        Data->ArrayPasteEntries[i].fmtetc.cfFormat == cfEmbeddedObject ||
        Data->ArrayPasteEntries[i].fmtetc.cfFormat == cfEmbedSource) {
      if (!tryObjFmt) {
        tryObjFmt = true;       // Only use first object format
        insertFirst = true;     // OLE obj. format should always be first

        //
        // Check exclusion list
        //
        exclude = false;
        for( int j=0; j < (int)Data->cClsIdExclude; j++) {
          if (IsEqualCLSID(Helper.ClsIdOD, *(Data->lpClsIdExclude+j))) {
            exclude = true;
            break;
          }
        }

        //
        // Skip object if in exclusion list
        //
        if (exclude)
          continue;
      }
      else {
        //
        // Already added an object format to list
        //
        continue;
      }
    }

    //
    // Ass to list if entry is marked true
    //
    if (Data->ArrayPasteEntries[i].dwScratchSpace) {
      if (defFormat < 0) {
        defFormat = insertFirst ? 0 : items;
      }
      else if (insertFirst) {
        defFormat++;
      }
      if (AddPasteListItem(*PasteList, insertFirst, i,
                           Helper.FullUserTypeNameOD)) {
        items++;
      }
      else {
        FreeListData(*PasteList);
        return false;
      }
    }
  }

  //
  // Initialize select to first matching format
  //
  if (defFormat >= 0)
    Helper.PasteListCurSel = defFormat;

  return (items > 0) ? true : false;
}

//
// Fill the (invisible) PasteLink listbox with the formats offered by the
// Clipboard object and asked form by the container
//
bool
TPasteSpecialDlg::FillPasteLinkList()
{
  int  items = 0;
  int  defFormat = -1;
  bool tryObjFmt = false;
  bool insertFirst = true;
  LPDATAOBJECT lpSrcDataObj = Data->lpSrcDataObj;

  FORMATETC fmtetc;
  memset(&fmtetc, 0, sizeof(fmtetc));

  //
  // Array of flags indicating which link types are supported
  //
  bool arrayLinkTypesSupported[MaxLinkTypes];
  bool linkTypeSupported = false;

  for (int i=0; i<Data->cLinkTypes; i++) {
    if (Data->ArrayLinkTypes[i] == cfLinkSource) {
      TRACEX(OwlOleDlg, 1, "Calling OleQueryLinkFromData.");
      if (OleQueryLinkFromData(lpSrcDataObj) == S_OK) {
        arrayLinkTypesSupported[i] = true;
        linkTypeSupported = true;
      }
      else {
        arrayLinkTypesSupported[i] = false;
      };
    }
    else {
      fmtetc.cfFormat = Data->ArrayLinkTypes[i];
      fmtetc.dwAspect = DVASPECT_CONTENT;
      fmtetc.tymed    = 0xFFFFFFFFL;      // All tymed values
      fmtetc.lindex   = -1;

      TRACEX(OwlOleDlg, 1, "IDataObject::QueryGetData called.");
      if (lpSrcDataObj->QueryGetData(&fmtetc) == S_OK) {
        arrayLinkTypesSupported[i] = true;
        linkTypeSupported = true;
      }
      else {
        arrayLinkTypesSupported[i] = false;
      }
    }
  }

  //
  // Check if link types are offered by SourceDataObject
  //
  if (!linkTypeSupported) {
    TRACEX(OwlOleDlg, 1, "No link types are offered by data source.");
    items = 0;
    return false;
  }

  //
  // Iterate through acceptable formats
  //
  for(i=0; i<Data->cPasteEntries; i++) {
    linkTypeSupported = false;
    //
    // Does container accept an link type offered by source object
    //
    if (Data->ArrayPasteEntries[i].dwFlags & pfLinkAnyType)
      linkTypeSupported = true;
    else  {
      //
      // Checked if link types offered by source are acceptable
      //
      int j=0;
      uint32 pasteFlag;
      for (pasteFlag = pfLinkType1, j=0;
           j < Data->cLinkTypes;
           pasteFlag *=2, j++) {
        if ((Data->ArrayPasteEntries[i].dwFlags & pasteFlag)  &&
            arrayLinkTypesSupported[i]) {
          linkTypeSupported = true;
          break;
        }
      }

      insertFirst = false;
      if ((Data->ArrayPasteEntries[i].fmtetc.cfFormat == cfFileName)  ||
          (Data->ArrayPasteEntries[i].fmtetc.cfFormat == cfLinkSource)) {
        if  (!tryObjFmt) {
          tryObjFmt = true;     // Only use first object format
          insertFirst = true;   // OLE object format should be first
        }
        else {
          continue;             // Already added object format to list
        }
      }

      //
      // Add to list if entry's marked true
      //
      if (linkTypeSupported  &&
          Data->ArrayPasteEntries[i].dwScratchSpace) {
        if (defFormat < 0) {
          defFormat = insertFirst ?  0 : items;
        }
        else if (insertFirst) {
          defFormat++;
        }

        if (AddPasteListItem(*PasteLinkList, insertFirst, i,
                              Helper.FullUserTypeNameLSD)) {
          items++;
        }
        else {
          FreeListData(*PasteLinkList);
          return false;
        }
      }
    }
  }

  //
  // Initialize selection to first matching format
  //
  if (defFormat >= 0)
    Helper.PasteLinkListCurSel = defFormat;

  items = PasteLinkList->GetCount();
  return (items > 0) ? true : false;
}

//
// Frees PasteListItem data memory associated with each listbox entry.
//
void
TPasteSpecialDlg::FreeListData(TListBox &list)
{
  TPasteListItemData FAR *lpItemData;

  int items = list.GetCount();
  for (int i=0; i<items; i++) {
    lpItemData = (TPasteListItemData FAR*)(LPARAM)list.GetItemData(i);
    if ((LPARAM)lpItemData != LB_ERR)
      delete lpItemData;
  }
}

//
// Allows user to change current icon via the ChangeIcon Dialog
//
void
TPasteSpecialDlg::ChangeIconClicked()
{
  TRY {
    //
    // Allocate and populate structure to hold parameters
    //
    TChangeIconDlg::TData &data = *new TChangeIconDlg::TData;
    TPointer<TChangeIconDlg::TData> _cln1(&data);
    data.MetaPict = IconImage->GetMetaPict();
    data.Flags    = ciSelectCurrent;
    data.ClsId    = Helper.Link ? Helper.ClsIdLSD : Helper.ClsIdOD;

    if (Helper.Flags & ioShowHelp)
      data.Flags |= ciShowHelp;

    //
    // Allocate dialog and execute
    //
    TChangeIconDlg &chgIconDlg = *new TChangeIconDlg(this, data);
    TPointer<TChangeIconDlg> _cln2(&chgIconDlg);
    if (chgIconDlg.Execute() == IDOK){
      //
      // Update display with new icon
      //
      IconImage->SetMetaPict(data.MetaPict);

      //
      // Save away new icon
      //
      if (Helper.Link)
        Helper.MetaPictLSD = data.MetaPict;
      else
        Helper.MetaPictOD = data.MetaPict;
    }
  }
  CATCH( (xmsg& msg){ GetModule()->Error(msg, 0); } )
}

//
// Switches to the PasteList
//
void
TPasteSpecialDlg::PasteClicked()
{
  TogglePasteType(psSelectPaste);
}

//
// Switches to the PasteLink List
//
void
TPasteSpecialDlg::PasteLinkClicked()
{
  TogglePasteType(psSelectPasteLink);
}

//
// Handles request to display Paste/Link as Icon
//
void
TPasteSpecialDlg::DisplayAsIconClicked()
{
  ToggleDisplayAsIcon();
}

//
// Handles change in selection of items to paste/pasteLink
//
void
TPasteSpecialDlg::DisplayListSelChange()
{
  ChangeListSelection();
}

//
// A double click on the Paste/PasteLink listbox is treated
// similar to hitting the OK button.
//
void
TPasteSpecialDlg::DisplayListDblClk()
{
  SendNotification(IDOK, BN_CLICKED, GetDlgItem(IDOK));
}

//
// Handles notification that Clipboard content has changed.
// This basically means bad news since the data we're currently
// displaying to the user for Pasting/PasteLinking is now inaccurate.
//
void
TPasteSpecialDlg::EvDrawClipboard()
{
  HWND hwndSaved = (HWND)GetProp(NEXTCBVIEWER);
  if (hwndSaved == HWND_BROADCAST)
    return;

  //
  // Take ourselves out of the loop
  //
  SetProp(NEXTCBVIEWER, HWND_BROADCAST);
  ::ChangeClipboardChain(*this, hwndSaved);

  //
  // Bring down the dialog
  //
}

//
// Handle notification that a Window is being removed from
// Clipboard chain.
//
void
TPasteSpecialDlg::EvChangeCBChain(HWND hwndRemoved, HWND hwndNext)
{
  //
  // If the one after us is going, save the one following it.
  //
  HWND hwndSaved = (HWND)GetProp(NEXTCBVIEWER);
  if (hwndRemoved == hwndSaved) {
    SetProp(NEXTCBVIEWER, hwndNext);
  //
  // Otherwise pass the buck along
  //
  }
  else if (hwndSaved  && hwndSaved != HWND_BROADCAST) {
    ::SendMessage(hwndSaved, WM_CHANGECBCHAIN, (WPARAM)hwndRemoved,
                  (LPARAM)hwndNext);
  }
}

