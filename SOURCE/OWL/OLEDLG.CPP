//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
 //   Defines type TOleDialog, the base class of all OLE Dialog classes
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/owlpch.h>
#include <owl/dialog.h>
#include <owl/opensave.h>
#include <owl/listbox.h>
#include <owl/radiobut.h>
#include <owl/checkbox.h>
#include <owl/groupbox.h>
#include <owl/edit.h>
#include <ocf/ocview.h>
#include <dir.h>
#include <owl/oledlg.h>

//
// Owl OLE Dialog general diagnostic group
//
DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlOleDlg, 1, 0);

//
// Helper variables
//
extern const char ClsIdStr[] = "\\CLSID";
const  char PrefixFmt[] = "%c%c%c...\\";

//
// Returns OBJECTDESCRIPTOR handle
//
HGLOBAL
TOleDialog::GetObjectDescriptorData(CLSID clsid, DWORD dwDrawAspect,
                                    SIZEL sizel, POINTL pointl,
                                    DWORD dwStatus,
                                    LPSTR lpszFullUserTypeName,
                                    LPSTR lpszSrcOfCopy)
{
  //
  // Length of full user name
  //
  DWORD dwFullUserTypeNameLen = lpszFullUserTypeName ?
                  strlen(lpszFullUserTypeName)+1 : 0;

  //
  // Length of source copy string
  //
  DWORD dwSrcOfCopyLen;
  if (lpszSrcOfCopy)
    dwSrcOfCopyLen = strlen(lpszSrcOfCopy)+1;
  else {
    //
    // User user type name as source string
    //
    lpszSrcOfCopy =  lpszFullUserTypeName;
    dwSrcOfCopyLen = dwFullUserTypeNameLen;
  }

  //
  // Allocate space for OBJECTDESCRIPTOR and the additional string data
  //
  DWORD dwObjectDescSize = sizeof(OBJECTDESCRIPTOR);
  HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE | GMEM_SHARE,
                             dwObjectDescSize + dwFullUserTypeNameLen +
                             dwSrcOfCopyLen);

  //
  // Bail out of memory failure
  //
  if (!hMem)
    return 0;

  LPOBJECTDESCRIPTOR lpOD = (LPOBJECTDESCRIPTOR)GlobalLock(hMem);

  //
  // Set the FullUserTypeName offset and copy the string
  //
  if (lpszFullUserTypeName) {
    lpOD->dwFullUserTypeName = dwObjectDescSize;
    strcpy((LPSTR)lpOD + (int)lpOD->dwFullUserTypeName, lpszFullUserTypeName);
  }
  else {
     //
     // zero offset indicates that string is not present
     //
    lpOD->dwFullUserTypeName = 0;
  }

  //
  // Set the SrcOfCopy offset and copy the string
  //
  if (lpszSrcOfCopy) {
    lpOD->dwSrcOfCopy = dwObjectDescSize + dwFullUserTypeNameLen;
    strcpy((LPSTR)lpOD+(int)lpOD->dwSrcOfCopy , lpszSrcOfCopy);
  }
  else {
    //
    // zero offset indicates that string is not present
    //
    lpOD->dwSrcOfCopy = 0;
  }

  //
  // Initialize the rest of the OBJECTDESCRIPTOR
  //
  lpOD->cbSize       = dwObjectDescSize + dwFullUserTypeNameLen +
                       dwSrcOfCopyLen;
  lpOD->clsid        = clsid;
  lpOD->dwDrawAspect = dwDrawAspect;
  lpOD->sizel        = sizel;
  lpOD->pointl       = pointl;
  lpOD->dwStatus     = dwStatus;

  GlobalUnlock(hMem);
  return hMem;
}

//
// Retrieve data from an IDataObject in a specified format on a
// global memory block. This function ALWAYS returns a private copy
// of the data to the caller. if necessary a copy is made of the
// data (ie. if lpMedium->pUnkForRelease != 0). The caller assumes
// ownership of the data block in all cases and must free the data
// when done with it. The caller may directly free the data handle
// returned (taking care whether it is a simple HGLOBAL or a HANDLE
// to a MetafilePict) or the caller may call
// ReleaseStgMedium(lpMedium). this OLE helper function will do the
// right thing.
//
HGLOBAL
TOleDialog::GetData(LPDATAOBJECT lpDataObj, CLIPFORMAT cfFormat,
                    DVTARGETDEVICE FAR* lpTargetDevice,
                    DWORD dwDrawAspect, LPSTGMEDIUM lpMedium)
{
  FORMATETC formatetc;

  // Init FORMATETC structure
  //
  DWORD tymed;
  switch (cfFormat) {
    case CF_METAFILEPICT:
      tymed = TYMED_MFPICT;
      break;

    case CF_BITMAP:
      tymed = TYMED_GDI;
      break;

    default:
      tymed = TYMED_HGLOBAL;
      break;
  }
  InitFormatEtc(formatetc, cfFormat, tymed, -1, dwDrawAspect, lpTargetDevice);

  TRACEX(OwlOleDlg, 1, "IDataObject::GetData called");
  if (lpDataObj->GetData((LPFORMATETC)&formatetc, lpMedium) != NOERROR)
    return 0;

  HGLOBAL hGlobal = lpMedium->hGlobal;  //!CQ nonamelessunion? u.
  if (!hGlobal)
    return 0;

  //
  // Check if hGlobal really points to valid memory
  //
  LPVOID lp = GlobalLock(hGlobal);
  if (lp) {
    if (IsBadReadPtr(lp, 1)) {
      GlobalUnlock(hGlobal);
      return 0;
    }
    GlobalUnlock(hGlobal);
  }

  if (hGlobal != 0 && lpMedium->pUnkForRelease != 0) {
    //
    // OLE2NOTE: the callee wants to retain ownership of the data.
    //    this is indicated by passing a non-0 pUnkForRelease.
    //    thus, we will make a copy of the data and release the
    //    callee's copy.
    //
    HGLOBAL hCopy;
    hCopy = OleDuplicateData(hGlobal, cfFormat, GHND|GMEM_SHARE);
    ReleaseStgMedium(lpMedium);

    hGlobal = hCopy;
    lpMedium->hGlobal = hCopy;    //!CQ nonamelessunion? u.
    lpMedium->pUnkForRelease = 0;
  }
  return hGlobal;
}

//
// Fills and returns a OBJECTDESCRIPTOR structure. The source object will
// offer CF_OBJECTDESCRIPTOR if it is an OLE2 object, CF_OWNERLINK if it
// is an OLE1 object, or CF_FILENAME if it has been copied to the clipboard
// by FileManager.
//
HGLOBAL
TOleDialog::FillObjectDescriptorFromData(LPDATAOBJECT lpDataObject,
                                         LPSTGMEDIUM  lpmedium,
                                         CLIPFORMAT far* lpcfFmt)
{
  CLSID              clsid;
  SIZEL              sizelHim;
  POINTL             pointl;
  LPSTR              lpsz, szFullUserTypeName, szSrcOfCopy, 
                     szClassName, szDocName, szItemName;
  int                nClassName, nDocName, nItemName, nFullUserTypeName;
  LPSTR              szBuf = 0;
  HKEY               hKey = 0;
  DWORD              dw = MaxPathLen;  
  HGLOBAL            hObjDesc;
  HRESULT            hrErr;

  //
  // GetData CF_OBJECTDESCRIPTOR format from the object on the clipboard.
  // Only OLE 2 objects on the clipboard will offer CF_OBJECTDESCRIPTOR
  //
  HGLOBAL hMem = GetData(lpDataObject, cfObjectDescriptor, 0, DVASPECT_CONTENT, lpmedium);

  if (hMem != 0) {
    *lpcfFmt = cfObjectDescriptor;
    return hMem;
  }
  else if ((hMem = GetData(lpDataObject,  cfOwnerLink, 
                           0, DVASPECT_CONTENT, lpmedium)) != 0) {
    //
    // If CF_OBJECTDESCRIPTOR is not available, i.e. if this is not an
    // OLE2 object, check if this is an OLE 1 object. OLE 1 objects
    // will offer CF_OWNERLINK
    //
    *lpcfFmt = cfOwnerLink;

    //
    // CF_OWNERLINK contains 0-terminated strings for class name,
    // document name and item name with two 0 terminating characters
    // at the end
    //
    szClassName = (LPSTR)GlobalLock(hMem);
    nClassName  = strlen(szClassName);
    szDocName   = szClassName + nClassName + 1;
    nDocName    = strlen(szDocName);
    szItemName  = szDocName + nDocName + 1;
    nItemName   = strlen(szItemName);

    //
    // Find FullUserTypeName from Registration database using class name
    //
    if (RegOpenKey(HKEY_CLASSES_ROOT, 0, &hKey) != ERROR_SUCCESS)
       goto error;

    //
    // Allocate space for szFullUserTypeName & szSrcOfCopy. 
    // Maximum length of FullUserTypeName is MaxKeyLen. 
    // SrcOfCopy is constructed by concatenating FullUserTypeName, 
    // Document Name and ItemName separated by spaces.
    //
    TOleAllocator allocator;
    szBuf = (LPSTR)allocator.Alloc((DWORD)2*MaxKeyLen+nDocName+nItemName+4);
    if (!szBuf)
      goto error;

    szFullUserTypeName = szBuf;
    szSrcOfCopy = szFullUserTypeName+MaxKeyLen+1;

    //
    // Get FullUserTypeName
    //
    if (::RegQueryValue(hKey, 0, szFullUserTypeName, (LONG*)&dw) != ERROR_SUCCESS)
       goto error;

    //
    // Build up SrcOfCopy string from FullUserTypeName, DocumentName & ItemName
    //
    lpsz = szSrcOfCopy;
    lstrcpy(lpsz, szFullUserTypeName);
    nFullUserTypeName = lstrlen(szFullUserTypeName);
    lpsz[nFullUserTypeName]=' ';
    lpsz += nFullUserTypeName+1;
    lstrcpy(lpsz, szDocName);
    lpsz[nDocName] = ' ';
    lpsz += nDocName+1;
    lstrcpy(lpsz, szItemName);

    sizelHim.cx = sizelHim.cy = 0;
    pointl.x = pointl.y = 0;

    CLSIDFromProgID(OleStr(szClassName), &clsid);

    hObjDesc = GetObjectDescriptorData(clsid, DVASPECT_CONTENT, sizelHim,
                                       pointl, 0, szFullUserTypeName,
                                       szSrcOfCopy);
    if (!hObjDesc)
       goto error;

  //
  // Check if object is CF_FILENAME
  //
  }
  else if ((hMem = GetData(lpDataObject, cfFileName, 0,  DVASPECT_CONTENT,
                           lpmedium)) != 0) {
    *lpcfFmt = cfFileName;
    lpsz = (LPSTR)GlobalLock(hMem);
    hrErr = GetClassFile(OleStr(lpsz), &clsid);

    //
    // OLE2NOTE: if the file does not have an OLE class
    //    associated, then use the OLE 1 Packager as the class of
    //    the object to be created. this is the behavior of
    //    OleCreateFromData API
    //
    if (hrErr != NOERROR)
      CLSIDFromProgID(OleText("Package"), &clsid);
    sizelHim.cx = sizelHim.cy = 0;
    pointl.x = pointl.y = 0;

    TOleAllocator allocator;
    szBuf = (LPSTR)allocator.Alloc(MaxKeyLen);
    if (0 == szBuf)
      goto error;

    GetUserTypeOfClass(clsid, szBuf, 0);

    hObjDesc = GetObjectDescriptorData(clsid, DVASPECT_CONTENT, sizelHim,
                                       pointl, 0, szBuf, lpsz);
    if (!hObjDesc)
      goto error;
  }
  else {
    TRACEX(OwlOleDlg, 1, "Unable to retrieve OBJECTDESCRIPTOR info.");
    goto error;
  }

  //
  // Clean up
  //
  if (szBuf)
    TOleAllocator().Free((LPVOID)szBuf);

  if (hMem) {
    GlobalUnlock(hMem);
    GlobalFree(hMem);
  }

  if (hKey) {
    RegCloseKey(hKey);
  }

  return hObjDesc;

error:
  if (szBuf)
    TOleAllocator().Free((LPVOID)szBuf);

  if (hMem) {
    GlobalUnlock(hMem);
    GlobalFree(hMem);
  }

  if (hKey) {
    RegCloseKey(hKey);
  }

  return 0;
}

//
// Returns the specified AuxUserType from the reg db.
//
uint
TOleDialog::GetAuxUserType(REFCLSID rclsid, WORD wAuxUserType,
                           LPSTR lpszAuxUserType, int cch, HKEY hKey)
{
  bool     fCloseRegDB = false;
  HKEY     hThisKey;
  if (!hKey) {
    if (::RegOpenKey(HKEY_CLASSES_ROOT, 0, &hThisKey) != ERROR_SUCCESS)
      return 0;
    fCloseRegDB = true;
  }
  else {
    hThisKey = hKey;
  }

  LPOLESTR lpszCLSID;
  StringFromCLSID(rclsid, &lpszCLSID);

  char     szKey[MaxKeyLen];     
  lstrcpy(szKey, "CLSID\\");
  lstrcat(szKey, OleStr(lpszCLSID));
  char     szTemp[32];
  wsprintf(szTemp, "\\AuxUserType\\%d", wAuxUserType);
  lstrcat(szKey, szTemp);

  lpszAuxUserType[0] = '\0';
  LONG dw = cch;
  LRESULT lRet = ::RegQueryValue(hThisKey, szKey, lpszAuxUserType, &dw);

  if (lRet != ERROR_SUCCESS) {
    dw = 0;
    lpszAuxUserType[0] = '\0';
  }

  if (fCloseRegDB)
    RegCloseKey(hThisKey);

  TOleAllocator().Free((LPVOID)lpszCLSID);

  return (UINT)dw;
}

//
//
//
uint
TOleDialog::GetUserTypeOfClass(REFCLSID clsid, char far* lpszUserStr, uint len)
{
  if (!lpszUserStr)
    return 0;

  HKEY hKey;
  if (RegOpenKey(HKEY_CLASSES_ROOT, 0, &hKey) != ERROR_SUCCESS)
    return 0;

  LPOLESTR lpszClsId;
  bool freeClsId = HRIsOK(StringFromCLSID(clsid, &lpszClsId));

  char  szKey[MaxPathLen];
  strcpy(szKey, ::ClsIdStr);
  if (freeClsId)
    strcat(szKey, OleStr(lpszClsId));

  LONG buffSize = len;
  LPOLESTR lpszProgId;
  bool  freeProgId = false;
  if (::RegQueryValue(hKey, szKey, lpszUserStr, &buffSize) != ERROR_SUCCESS) {
    //
    // Check for OLE 1.0 class
    //
    if (CoIsOle1Class(clsid)) {
      freeProgId = HRIsOK(ProgIDFromCLSID(clsid, &lpszProgId));
      if (freeProgId) {
        buffSize = len;
        if (::RegQueryValue(hKey, OleStr(lpszProgId),
                          lpszUserStr, &buffSize) != ERROR_SUCCESS)
          buffSize = 0;
      }
    }
  }

  TOleAllocator oleAllocator;
  if (freeClsId)
    oleAllocator.Free(lpszClsId);

  if (freeProgId)
    oleAllocator.Free(lpszProgId);

  RegCloseKey(hKey);
  return (uint)buffSize;
}

//
// DoesFileExist
// -------------
//  Tests for the existence via OpenFile [which opens and closes the file]
//  Returns HFILE_ERROR if an error occurs with ofs.nErrCode containing an
//  error value.
//
HFILE
TOleDialog::DoesFileExist(const char* filename, OFSTRUCT& ofs)
{
  //
  // The following check for reserved MS-DOS device names is necessary
  // because OleCreateFromFile() does not perform such check. More
  // information about this issue is available on the MSDN CD, article
  // 'OleCreateFile() Does Not Check for Reserved Names' - PSS ID# Q111015.
  //
  static char *illegalNames[] = {"LPT1", "LPT2", "LPT3",
                                 "COM1", "COM2", "COM3", "COM4",
                                 "CON", "AUX", "PRN"};
  for (int i=0; i<sizeof(illegalNames)/sizeof(illegalNames[0]); i++) {
    if (strcmpi(filename, illegalNames[i]) == 0) {
      memset(&ofs, 0, sizeof(ofs));
      ofs.nErrCode = 0x0002;  // File not found
      return HFILE_ERROR;
    }
  }

  return OpenFile(filename, &ofs, OF_EXIST);
}

//
// Returns a pointer to the beginning of the nth field of a string -
// Fields are delimited by 'chDelim'
//
LPSTR
TOleDialog::PtrToNthField(LPSTR lpszStr, int nField, char chDelim)
{
  LPSTR lpszField = lpszStr;
  int    cFieldFound = 1;

  if (nField == 1)
    return lpszStr;

  while(*lpszField) {
    if (*lpszField++ == chDelim) {
      cFieldFound++;
      if (cFieldFound == nField)
        return lpszField;
    }
  }
  return lpszField;
}

//
// TOleDialog's Response Table
//
DEFINE_RESPONSE_TABLE1(TOleDialog, TDialog)
  EV_WM_CLOSE,
  EV_COMMAND(IDOK, CmOk),
  EV_COMMAND(IDCANCEL, CmCancel),
END_RESPONSE_TABLE;

//
// Registered Clipboard Formats
//
uint16 TOleDialog::cfObjectDescriptor = 0;
uint16 TOleDialog::cfLinkSrcDescriptor= 0;
uint16 TOleDialog::cfEmbedSource      = 0;
uint16 TOleDialog::cfEmbeddedObject   = 0;
uint16 TOleDialog::cfLinkSource       = 0;
uint16 TOleDialog::cfOwnerLink        = 0;
uint16 TOleDialog::cfFileName         = 0;
bool   TOleDialog::cfInit             = false;

//
//
//
TOleDialog::TOleDialog(TWindow*        parent,
                       TResId          templateId,
                       const char far* title,
                       TModule*        module)
:
  TDialog(parent, templateId, module),
  ODTitle(title), Font(0)
{
  //
  // Register  Clipboard Formats
  //
  if (!cfInit) {
    cfObjectDescriptor  = (uint16)::RegisterClipboardFormat(CF_OBJECTDESCRIPTOR);
    cfLinkSrcDescriptor = (uint16)::RegisterClipboardFormat(CF_LINKSRCDESCRIPTOR);
    cfEmbedSource       = (uint16)::RegisterClipboardFormat(CF_EMBEDSOURCE);
    cfEmbeddedObject    = (uint16)::RegisterClipboardFormat(CF_EMBEDDEDOBJECT);
    cfLinkSource        = (uint16)::RegisterClipboardFormat(CF_LINKSOURCE);
    cfOwnerLink         = (uint16)::RegisterClipboardFormat(CF_OWNERLINK);
    cfFileName          = (uint16)::RegisterClipboardFormat(CF_FILENAME);
    cfInit = true;
  }
}

//
// Creates non-bold font for static controls and update dialog's title
// if user specified one.
//
void
TOleDialog::SetupWindow()
{
    TDialog::SetupWindow();

    //
    // Create non-bold font for text displays
    //
    HFONT   hfont = GetWindowFont();
    LOGFONT lf;
    GetObject(hfont, sizeof(LOGFONT), &lf);
    lf.lfWeight=FW_NORMAL;
    Font = new TFont(&lf);

    //
    // Override title if user specified one
    //
    if (ODTitle)
      SetCaption(ODTitle);
}

//
// Cleanup Font
//
void
TOleDialog::CleanupWindow()
{
  if (Font) {
    delete Font;
    Font = 0;
  }
}

//
// Enables and shows [or disables and hides] a [child] window
//
void
TOleDialog::Activate(TWindow *win, bool activate)
{
  win->Show(activate ? SW_SHOW : SW_HIDE);
  win->EnableWindow(activate);
}

//
// Responds to OK button by invoking virtual method prior before chaining
// to base class CmOk if everything's OK - This allows the derived OLE-DLG
// to 'veto' the closure of the dialog.
//
void
TOleDialog::CmOk()
{
  if (OleDlgOk()) {
    TDialog::CmOk();
  }
}

//
// Displays a MessageBox informing user of an error resulting
// from a file operation.
//
int
TOleDialog::ErrorWithFile(uint strId, const char* fileName, uint mbFlags)
{
  const int BuffLen = MaxPathLen*2;
  TPointer<char>  pstr1 = new char[BuffLen];
  TPointer<char>  pstr2 = new char[BuffLen];
  TPointer<char>  pstr3 = new char[BuffLen];

  if (GetModule()->LoadString(strId, pstr1, BuffLen)) {
    wsprintf((LPSTR)(char*)pstr2, (LPSTR)(char*)pstr1, (LPSTR)fileName);
    GetWindowText((LPSTR)(char*)pstr3, BuffLen);
    return MessageBox(pstr2, pstr3, mbFlags);
  }

  return 0;
}

//
// Invokes ErrorWithFile [see above] with the appropriate string resource
// Id. based on the Error Code specified.
//
void
TOleDialog::OpenFileError(uint errCode, const char* fileName)
{
  switch (errCode) {
    case  0x0005:   // Access denied
          ErrorWithFile(IDS_CIFILEACCESS, fileName);
          break;

    case  0x0020:   // Sharing Violation
          ErrorWithFile(IDS_CIFILESHARE, fileName);
          break;

    case  0x0002:   // File not found
    case  0x0003:   // Path not found
          ErrorWithFile(IDS_CIINVALIDFILE, fileName);
          break;

    default:        // Other failures
          ErrorWithFile(IDS_CIFILEOPENFAIL, fileName);
          break;
  }
}

//
// Displays the standard FileOpen with the 'Browse' caption.
//
bool
TOleDialog::BrowseDlg(char* file, char* initDir, uint filterId, uint32 flags)
{
  //
  // Retrieve filters from resource if specified
  //
  char  filterBuff[256];
  char *filterPtr = 0;
  if (filterId)
    if (GetModule()->LoadString(filterId, filterBuff, sizeof(filterBuff)))
      filterPtr = filterBuff;

  //
  // Retrieve dialog's title from resource
  //
  char  titleBuff[128];
  char *titlePtr = 0;
  if (GetModule()->LoadString(IDS_BROWSE, titleBuff, sizeof(titleBuff)))
    titlePtr = titleBuff;

  //
  // Create/Init TFileOpenDialog data structure
  //
  TOpenSaveDialog::TData *data;
  data = new TOpenSaveDialog::TData(flags, filterPtr, 0, initDir);

  //
  // Execute dialog and return status [copying new filename if necessary]
  //
  TFileOpenDialog fopenDlg(this, *data, 0, titlePtr);
  int ret = fopenDlg.Execute();

  if (ret == IDOK)
    strcpyn(file, data->FileName, MaxPathLen);

  delete data;
  return (ret == IDOK) ? true : false;
}

//
//
//
char far*
TOleDialog ::ChopText(TWindow &ctl, int width, char far* lpch)
{
  //
  // Use client area's width if 0 width specified
  //
  if (!width) {
    TRect rect;
    ctl.GetClientRect(rect);
    width = rect.Width();
  }

  //
  // Grab control's font
  //
  HFONT hFont = ctl.GetWindowFont();
  if (!hFont)
    hFont = (HFONT)GetStockObject(SYSTEM_FONT);
  TFont font(hFont);

  //
  // Graf control's DC and select font
  //
  TClientDC hdc(ctl);
  hdc.SelectObject(font);

  if (GetTextWSize(hdc, lpch) > width) {
    char szPrefix[PrefixSize];
    wsprintf(szPrefix, PrefixFmt, lpch[0], lpch[1], lpch[2]);
    width -= GetTextWSize(hdc, szPrefix);

    bool done = false;
    while (!done) {
      while(*lpch  &&  (*lpch != '\\'))
        lpch = AnsiNext(lpch);
      if (*lpch)
        lpch = AnsiNext(lpch);

      if (!*lpch  ||  GetTextWSize(hdc, lpch) <= width) {
        if (!*lpch)
          szPrefix[strlen(szPrefix)-1] = 0;

        for (int i=strlen(szPrefix)-1; i>=0; --i)
          *--lpch = szPrefix[i];

        done = true;
      }
    }
  }

  hdc.RestoreFont();
  return lpch;
}

//
//
//
int
TOleDialog::GetTextWSize(TDC &dc, char far* lpsz)
{
  TSize size;
  if (dc.GetTextExtent(lpsz, strlen(lpsz), size))
    return size.cx;
  else
    return 0;
}

//
//
//
int
TOleDialog::PopupMessage(uint msgId, uint titleId, uint mbFlags)
{
  TPointer<char>  pTitle = new char[LoadStringLen];
  TPointer<char>  pMsg   = new char[LoadStringLen];

  GetModule()->LoadString(msgId, pTitle, LoadStringLen);
  GetModule()->LoadString(titleId, pTitle, LoadStringLen);

  return MessageBox(pMsg, pTitle, mbFlags);
}


DEFINE_RESPONSE_TABLE1(TIconImage, TControl)
  EV_WM_PAINT,
  EV_WM_ERASEBKGND,
END_RESPONSE_TABLE;

//
//
//
TIconImage::TIconImage(TWindow* parent, int resourceId, TModule* module)
           :TControl(parent, resourceId, module), MetaPict(0)
{}

//
//
//
void
TIconImage::GetWindowClass(WNDCLASS& wndclass)
{
  TControl::GetWindowClass(wndclass);

  wndclass.hbrBackground = 0;
  wndclass.style = 0;
}

//
//
//
bool
TIconImage::SetMetaPict(HGLOBAL metaPict, bool deleteOld)
{
  HGLOBAL oldMeta = MetaPict;
  MetaPict = metaPict;

  Invalidate();
  UpdateWindow();

  if (deleteOld) {
    if (oldMeta) {
      return TOleMetaPict::Free(oldMeta);
    }
    else {
      TRACEX(OwlOleDlg, 1, "Old handle is 0 and was not deleted");
      return false;
    }
  }
  return true;
}

//
//
//
void
TIconImage::EvPaint()
{
  TPaintDC dc(*this);
  TRect clientRect;
  GetClientRect(clientRect);

  TOleMetaPict oleMetaPict(MetaPict);
  oleMetaPict.Draw(dc, clientRect, false);
}

//
//
//
bool
TIconImage::EvEraseBkgnd(HDC hdc)
{
  HBRUSH  hBrush;
#if defined(BI_PLAT_WIN32)
  hBrush = (HBRUSH)Parent->SendMessage(WM_CTLCOLORDLG, (WPARAM)hdc,
                                       (LPARAM)GetParent());
#else
  hBrush = (HBRUSH)Parent->SendMessage(WM_CTLCOLOR, (WPARAM)hdc,
                                      MAKELPARAM(GetParent(), CTLCOLOR_DLG));
#endif

  if (!hBrush)
    return false;

  TBrush brush(hBrush);
#if defined(BI_PLAT_WIN16)
  brush.UnrealizeObject();
#endif

  TDC dc(hdc);
  dc.SetBrushOrg(0, 0);

  TRect rect;
  GetClientRect(rect);
  dc.FillRect(rect, brush);
  return true;
}

//
// Constants
//
const long RopDSPDxax = 0x00E20746L;

//
//
//
DEFINE_RESPONSE_TABLE1(TResultImage, TControl)
  EV_WM_PAINT,
END_RESPONSE_TABLE;

//
// Init variables
//
TResultImage::TResultImage(TWindow* parent, int resourceId, TModule* module)
             :TControl(parent, resourceId, module)
{
  Bitmap = 0;
  ShouldDelete = false;
}

//
// Clean up bitmap (if necessary)
//
TResultImage::~TResultImage()
{
  SetBitmap(0);
}

//
//
//
void
TResultImage::GetWindowClass(WNDCLASS& wndclass)
{
  TControl::GetWindowClass(wndclass);

  wndclass.hbrBackground = 0;
  wndclass.style = CS_VREDRAW | CS_HREDRAW;
}

//
//
//
void
TResultImage::SetupWindow()
{
  TControl::SetupWindow();

  //
  // Init Result Bitmap
  //
  TResId bmpId;
  TScreenDC screenDC;
  int cx = screenDC.GetDeviceCaps(LOGPIXELSY);
  if (cx <= 72)                 bmpId = IDB_RESULTSEGA;
  if (cx > 72  &&  cx < 120)    bmpId = IDB_RESULTSVGA;
  if (cx >= 120)                bmpId = IDB_RESULTSHIRESVGA;
  SetBitmap(bmpId, TColor::LtCyan, 7, 0);
}

//
//
//
void
TResultImage::SetBitmap(TResId bmpId, TColor transparentColor,
                        uint numRows, uint curIndex, TAutoDelete autoDelete)
{
  //
  // Cleanup current bitmap if 'shouldDelete' is enabled
  //
  if (Bitmap  &&  ShouldDelete)
  {
    delete Bitmap;
    Bitmap = 0;
  }

  //
  // Retrieve new bitmap if necessary
  //
  if (bmpId != 0)
  {
    ShouldDelete = autoDelete == AutoDelete ? true : false;
    Bitmap = new TBitmap(*GetModule(), bmpId);

    NumRows   = numRows;
    CurIndex  = curIndex;
    ClearColor= transparentColor;

    CX = Bitmap->Width();
    CY = Bitmap->Height();

    if (numRows)
      CY /= numRows;

    SetBitmapIndex(curIndex);   // Invalidates the window
  }
}

//
//
//
void
TResultImage::SetBitmapIndex(uint curIndex)
{
  PRECONDITION(Bitmap);
  PRECONDITION(curIndex < NumRows);

  CurIndex = curIndex;

  //
  // Force repaint
  //
  Invalidate(false);
  UpdateWindow();
}

//
//
//
void
TResultImage::EvPaint()
{
  TPaintDC dc(*this);

  //
  // Retrieve background brush of parent
  //
  HBRUSH  hBrush = 0;

  {
  TClientDC parentDC(*Parent);
#if defined(BI_PLAT_WIN32)
  hBrush = (HBRUSH)Parent->SendMessage(WM_CTLCOLORDLG, (WPARAM)(HDC)parentDC,
                                       (LPARAM)GetParent());
#else
  hBrush = (HBRUSH)Parent->SendMessage(WM_CTLCOLOR, (WPARAM)(HDC)parentDC,
                                      MAKELPARAM(GetParent(), CTLCOLOR_DLG));
#endif
  }

  //
  // Make our DC's background color match parent's background
  //
  if (hBrush)
  {
    LOGBRUSH lb;
    GetObject(hBrush, sizeof(LOGBRUSH), &lb);
    dc.SetBkColor(TColor(lb.lbColor));
  }

  if (!Bitmap)
    return;

  //
  // Destination Coordinates for bitmap: Center bitmap
  //
  uint dstX =0, dstY =0;
  TRect rect;
  GetClientRect(rect);
  if ((rect.right + rect.left) > CX)
    dstX = (rect.right + rect.left - CX)/2;
  if ((rect.bottom + rect.top) > CY)
    dstY = (rect.bottom + rect.top - CY)/2;

  //
  // Source Coordinates: Offset to appropriate row for source
  //
  uint srcX, srcY;
  srcX = 0;
  srcY = CY * CurIndex;

  //
  // Three intermediate memory DCs
  //
  TMemoryDC hdcSrc(dc), hdcMid(dc), hdcMem(dc);

  //
  // Select our bitmap in a Source MemDC [for bitblt]
  //
  hdcSrc.SelectObject(*Bitmap);

  //
  // Create monochrome bitmap for masking
  //
  TBitmap bmpMono(hdcMid, CX, CY);
  hdcMid.SelectObject(bmpMono);

  //
  // Create 'middle' bitmap
  //
  TBitmap bmpMid(dc, CX, CY);
  hdcMem.SelectObject(bmpMid);

  //
  // Create monochrome mask
  //
  TColor bkColor = hdcSrc.SetBkColor(ClearColor);
  hdcMid.BitBlt(0, 0, CX, CY, hdcSrc, srcX, srcY);
  hdcSrc.SetBkColor(bkColor);

  //
  // Save unmodified image in temporary bitmap
  //
  hdcMem.BitBlt(0, 0, CX, CY, hdcSrc, srcX, srcY);

  //
  // Create/Select background color brush
  //
  TBrush bkBrush(dc.GetBkColor());
  hdcMem.SelectObject(bkBrush);

  //
  // Force conversion of monochrome to stay black & white
  //
  hdcMem.SetTextColor(TColor(0));
  hdcMem.SetBkColor(TColor(255, 255, 255));

  //
  // Blt brush where monochrome mask is '1'; Leave destination untouch
  // where it's '0'.
  //
  hdcMem.BitBlt(0, 0, CX, CY, hdcMid, 0, 0, RopDSPDxax);
  dc.BitBlt(dstX, dstY, CX, CY, hdcMem, 0, 0);

  //
  // Restore DC attributes
  //
  hdcMem.RestoreBrush();
  hdcMem.RestoreBitmap();
  hdcMid.RestoreBitmap();
}
