//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Implementation of TOleMetaPict, manipulates Ole2 MetafilePict/Icon
//----------------------------------------------------------------------------
#define INC_OLE2
#include <owl/owlpch.h>
#include <owl/oledlg.h>

//
// OWL OLE Dialog diagnostic group.
//
DIAG_DECLARE_GROUP(OwlOleDlg);

//
// Class used for label and source extraction from a metafile
//
class _OWLCLASS TLabelExtract {
  public:
    //
    // Use memset to initialize PODS
    //
    TLabelExtract() {memset(this, 0, sizeof(TLabelExtract));}

    LPSTR       lpsz;
    UINT        Index;      // index in lpsz (so we can retrieve 2+ lines)
    DWORD       PrevIndex;  // index of last line (so we can mimic word wrap)

    union {
      UINT      cch;        //Length of label for label extraction
      UINT      iIcon;      //Index of icon in source extraction.
    } u;

    //
    //For internal use in enum procs
    //
    BOOL        fFoundIconOnly;
    BOOL        fFoundSource;
    BOOL        fFoundIndex;
};

//
// Class used for extracting icons from a metafile (CreateIcon parameters)
//
class _OWLCLASS TIconExtract {
  public:
    //
    // Use memset to initialize PODS
    //
    TIconExtract() {memset(this, 0, sizeof(TIconExtract));}

    HICON       hIcon;          // Icon created in the enumeration proc.
    BOOL        fAND;
    HGLOBAL     hMemAND;        // Enumeration proc allocates and copies
    HINSTANCE   hInst;          // Module instance handle
};

//
// Class used to pass info to EnumMetafileDraw
//
class _OWLCLASS TDrawInfo {
  public:
    //
    // Use memset to initialize PODS
    //
    TDrawInfo() {memset(this, 0, sizeof(TDrawInfo));}

    RECT     Rect;
    BOOL     fIconOnly;
};

//
// String [comment] in Metafile which flags that the label follows
//
static char szIconOnly[] = "IconOnly";       

int CALLBACK __export EnumMetafileIconDraw(HDC, HANDLETABLE FAR*, METARECORD FAR*, int, LPARAM);
int CALLBACK __export EnumMetafileExtractLabel(HDC, HANDLETABLE FAR*, METARECORD FAR*, int, TLabelExtract far*);
int CALLBACK __export EnumMetafileExtractIcon(HDC, HANDLETABLE FAR*, METARECORD FAR*, int, TIconExtract far*);
int CALLBACK __export EnumMetafileExtractIconSource(HDC, HANDLETABLE FAR*, METARECORD FAR*, int, TLabelExtract far*);

//
//
//
static uint
MapLogHimToPix(int hiMetric, int pelsPerInch)
{
  return (uint)(((double)hiMetric * pelsPerInch)/HiMetricPerInch);
}

//
//
//
static int
XformWidthInHimetricToPixels(TDC& dc, int widthInHiMetric)
{
  int logPix   = dc.GetDeviceCaps(LOGPIXELSX);
  int pixWidth = MapLogHimToPix(widthInHiMetric, logPix);
  return pixWidth;
}

//
//
//
static int
XformHeightInHimetricToPixels(TDC& dc, int heightInHiMetric)
{
  int logPix    = dc.GetDeviceCaps(LOGPIXELSY);
  int pixHeight = MapLogHimToPix(heightInHiMetric, logPix);
  return pixHeight;
}

//
//
//
BOOL 
OleUIMetafilePictIconDraw(HDC hDC, LPRECT pRect, 
                          HGLOBAL hMetaPict, BOOL fIconOnly)
{
  LPMETAFILEPICT  pMF;
  TDrawInfo        di;
  int             cx, cy;
  SIZE            size;
  POINT           point;

  if (!hMetaPict)
    return FALSE;

  pMF = (LPMETAFILEPICT)GlobalLock(hMetaPict);

  if (NULL==pMF) {
    TRACEX(OwlOleDlg, 1, "Unable to lock MetaPict Handle");
    return FALSE;
  }

  di.Rect = *pRect;
  di.fIconOnly = fIconOnly;

  //
  // Transform to back to pixels
  //
  cx = XformWidthInHimetricToPixels(TDC(hDC), pMF->xExt);
  cy = XformHeightInHimetricToPixels(TDC(hDC), pMF->yExt);

  SaveDC(hDC);

  SetMapMode(hDC, pMF->mm);
  SetViewportOrgEx(hDC, (pRect->right - cx) / 2, 0, &point);

  SetViewportExtEx(hDC, min ((pRect->right - cx) / 2 + cx, cx), cy, &size);

  if (fIconOnly) {
    EnumMetaFile(hDC, pMF->hMF, (MFENUMPROC)EnumMetafileIconDraw, 
                (LPARAM)(TDrawInfo far*)&di);
  }
  else {
    PlayMetaFile(hDC, pMF->hMF);
  }

  RestoreDC(hDC, -1);
  GlobalUnlock(hMetaPict);
  return TRUE;
}

int CALLBACK __export
EnumMetafileIconDraw(HDC hDC, HANDLETABLE FAR *phTable, 
                     METARECORD FAR *pMFR, 
                     int cObj, LPARAM lParam)
{
  TDrawInfo far* lpdi = (TDrawInfo far*)lParam;

  //
  // We play everything blindly except for DIBBITBLT (or DIBSTRETCHBLT)
  // and ESCAPE with MFCOMMENT.  For the BitBlts we change the x,y to
  // draw at (0,0) instead of wherever it was written to draw.  The
  // comment tells us there to stop if we don't want to draw the label.
  //

  //
  //If we're playing icon only, stop enumeration at the comment.
  //
  if (lpdi->fIconOnly) {
    if (META_ESCAPE==pMFR->rdFunction && MFCOMMENT==pMFR->rdParm[0]) {
      if (0==lstrcmpi(szIconOnly, (LPSTR)&pMFR->rdParm[2]))
        return 0;
    }

    //
    // Check for the records in which we want to munge the coordinates.
    // destX is offset 6 for BitBlt, offset 9 for StretchBlt, either of
    // which may appear in the metafile.
    // 
    if (META_DIBBITBLT==pMFR->rdFunction)
      pMFR->rdParm[6]=0;

    if (META_DIBSTRETCHBLT==pMFR->rdFunction)
        pMFR->rdParm[9] = 0;
  }

  PlayMetaFileRecord(hDC, phTable, pMFR, cObj);
  return 1;
}

UINT
OleUIMetafilePictExtractLabel(HGLOBAL hMetaPict, LPSTR lpszLabel,
                              UINT cchLabel, LPDWORD lpWrapIndex)
{
  LPMETAFILEPICT  pMF;
  TLabelExtract    le;
  HDC             hDC;

  //
  // We extract the label by getting a screen DC and walking the metafile
  // records until we see the ExtTextOut record we put there.  That
  // record will have the string embedded in it which we then copy out.
  //
  if (!hMetaPict || !lpszLabel || !cchLabel)
    return FALSE;

  pMF= (LPMETAFILEPICT)GlobalLock(hMetaPict);

  if (NULL==pMF)
    return FALSE;

  le.lpsz=lpszLabel;
  le.u.cch=cchLabel;
  le.Index=0;
  le.fFoundIconOnly=FALSE;
  le.fFoundSource=FALSE;
  le.fFoundIndex=FALSE;
  le.PrevIndex = 0;

  //
  // Use a screen DC so we have something valid to pass in.
  //
  hDC=GetDC(NULL);
  EnumMetaFile(hDC, pMF->hMF, (MFENUMPROC)EnumMetafileExtractLabel,
              (LONG)(TLabelExtract far*)&le);
  ReleaseDC(NULL, hDC);

  GlobalUnlock(hMetaPict);

  //
  // Tell where we wrapped (if calling function cares)
  //
  if (lpWrapIndex)
    *lpWrapIndex = le.PrevIndex;

  //
  // Return amount of text copied
  //
  return le.u.cch;
}

int CALLBACK __export
EnumMetafileExtractLabel(HDC /*hDC*/,
                         HANDLETABLE FAR* /*phTable*/,
                         METARECORD FAR *pMFR,
                         int /*cObj*/, 
                         TLabelExtract far* pLE)
{
  //
  // We don't allow anything to happen until we see "IconOnly"
  // in an MFCOMMENT that is used to enable everything else.
  // 
  if (!pLE->fFoundIconOnly) {
    if (META_ESCAPE==pMFR->rdFunction && MFCOMMENT==pMFR->rdParm[0]) {
      if (0==lstrcmpi(szIconOnly, (LPSTR)&pMFR->rdParm[2]))
        pLE->fFoundIconOnly=TRUE;
    }

    return 1;
  }

  //
  // Enumerate all records looking for META_EXTTEXTOUT - there can be more
  // than one.
  //
  if (META_EXTTEXTOUT==pMFR->rdFunction) {
    UINT        cchMax;
    LPSTR       lpszTemp;

    //
    // If ExtTextOut has NULL fuOptions, then the rectangle is omitted
    // from the record, and the string starts at rdParm[4].  If
    // fuOptions is non-NULL, then the string starts at rdParm[8]
    // (since the rectange takes up four WORDs in the array).  In
    // both cases, the string continues for (rdParm[2]+1) >> 1
    // words.  We just cast a pointer to rdParm[8] to an LPSTR and
    // lstrcpyn into the buffer we were given.
    //
    // Note that we use element 8 in rdParm instead of 4 because we
    // passed ETO_CLIPPED in for the options on ExtTextOut--docs say
    // [4] which is rect doesn't exist if we passed zero there.
    //
    // 
    cchMax=min(pLE->u.cch - pLE->Index, (UINT)pMFR->rdParm[2]);
    lpszTemp = pLE->lpsz + pLE->Index;

    lstrcpyn(lpszTemp, (LPSTR)&(pMFR->rdParm[8]), cchMax + 1);

    pLE->PrevIndex = pLE->Index;
    pLE->Index += cchMax;
  }

  return 1;
}

HICON 
OleUIMetafilePictExtractIcon(HGLOBAL hMetaPict, HINSTANCE hinst)
{
  LPMETAFILEPICT  pMF;
  HDC             hDC;
  TIconExtract     ie;

  //
  // We extract the label by getting a screen DC and walking the metafile
  // records until we see the ExtTextOut record we put there.  That
  // record will have the string embedded in it which we then copy out.
  // 

  if (NULL==hMetaPict)
    return NULL;

  pMF= (LPMETAFILEPICT)GlobalLock(hMetaPict);

  if (NULL==pMF)
    return FALSE;

  ie.fAND=TRUE;
  ie.hInst = hinst;

  hDC=GetDC(NULL);
  EnumMetaFile(hDC, pMF->hMF, (MFENUMPROC)EnumMetafileExtractIcon, 
              (LONG)(TIconExtract far*)&ie);
  ReleaseDC(NULL, hDC);
  GlobalUnlock(hMetaPict);

  return ie.hIcon;
}

int CALLBACK __export
EnumMetafileExtractIcon(HDC hDC, HANDLETABLE FAR* /*phTable*/,
                        METARECORD FAR *pMFR, int /*cObj*/,
                        TIconExtract far* pIE)
{
  LPBITMAPINFO        lpBI;
  LPBITMAPINFOHEADER  lpBH;
  LPBYTE              lpbSrc;
  LPBYTE              lpbDst;
  UINT                uWidth, uHeight;
  DWORD               cb;
  HGLOBAL             hMem;
  BITMAP              bm;
  HBITMAP             hBmp;

  //
  // Continue enumeration if we don't see the records we want.
  //
  if (META_DIBBITBLT != pMFR->rdFunction && 
      META_DIBSTRETCHBLT != pMFR->rdFunction)
    return 1;

  //
  // Windows 3.0 DrawIcon uses META_DIBBITBLT in whereas 3.1 uses
  // META_DIBSTRETCHBLT so we have to handle each case separately.
  // 

  if (META_DIBBITBLT==pMFR->rdFunction) {
    //
    // Get dimensions and the BITMAPINFO struct.
    //
    uHeight=pMFR->rdParm[1];
    uWidth =pMFR->rdParm[2];
    lpBI=(LPBITMAPINFO)&(pMFR->rdParm[8]);
  }
  if (META_DIBSTRETCHBLT==pMFR->rdFunction) {
    //
    // Get dimensions and the BITMAPINFO struct.
    //
    uHeight=pMFR->rdParm[2];
    uWidth =pMFR->rdParm[3];
    lpBI=(LPBITMAPINFO)&(pMFR->rdParm[10]);
  }

  lpBH=(LPBITMAPINFOHEADER)&(lpBI->bmiHeader);

  //
  // Pointer to the bits which follows the BITMAPINFO structure.
  //
  lpbSrc=(LPBYTE)lpBI+sizeof(BITMAPINFOHEADER);

  //
  // Add the length of the color table.
  //
  if (0!=lpBH->biClrUsed)
    lpbSrc+=(int)(DWORD)(lpBH->biClrUsed*sizeof(RGBQUAD));
  else  {
    //
    // 1 << bc gives 2, 16, 256 for 1, 4, or 256 colors
    lpbSrc+=(int)(DWORD)((1 << (lpBH->biBitCount))*sizeof(RGBQUAD));
  }

  //
  // All the bits we have in lpbSrc are device-independent, so we
  // need to change them over to be device-dependent using SetDIBits.
  // Once we have a bitmap with the device-dependent bits, we can
  // GetBitmapBits to have buffers with the real data.
  //
  // For each pass we have to allocate memory for the bits.  We save
  // the memory for the mask between passes.
  // 
     
  //
  // Use CreateBitmap for ANY monochrome bitmaps
  //
  if (pIE->fAND || 1==lpBH->biBitCount || lpBH->biBitCount > 8)
    hBmp=CreateBitmap((UINT)lpBH->biWidth, (UINT)lpBH->biHeight, 1, 1, NULL);
  else if (lpBH->biBitCount <= 8)
    hBmp=CreateCompatibleBitmap(hDC, (UINT)lpBH->biWidth, (UINT)lpBH->biHeight);

  if (!hBmp || !SetDIBits(hDC, hBmp, 0, (UINT)lpBH->biHeight, 
                         (LPVOID)lpbSrc, lpBI, DIB_RGB_COLORS)) {
    if (!pIE->fAND)
      GlobalFree(pIE->hMemAND);

    DeleteObject(hBmp);
    return 0;
  }

  //
  // Allocate memory and get the DDBits into it.
  //
  GetObject(hBmp, sizeof(bm), &bm);

  cb=bm.bmHeight*bm.bmWidthBytes * bm.bmPlanes;

  hMem=GlobalAlloc(GHND, cb);

  if (NULL==hMem) {
    if (NULL!=pIE->hMemAND)
      GlobalFree(pIE->hMemAND);

    DeleteObject(hBmp);
    return 0;
  }

  lpbDst=(LPBYTE)GlobalLock(hMem);
  GetBitmapBits(hBmp, cb, (LPVOID)lpbDst);

  DeleteObject(hBmp);
  GlobalUnlock(hMem);

  //
  // If this is the first pass (pIE->fAND==TRUE) then save the memory
  // of the AND bits for the next pass.
  // 
  if (pIE->fAND) {
    pIE->fAND=FALSE;
    pIE->hMemAND=hMem;

    //
    // Continue enumeration looking for the next blt record.
    //
    return 1;
  }
  else {
    //
    // Get the AND pointer again.
    //
    lpbSrc=(LPBYTE)GlobalLock(pIE->hMemAND);

    //
    // Create the icon now that we have all the data.  lpbDst already
    // points to the XOR bits.
    // 
    pIE->hIcon=CreateIcon(pIE->hInst, uWidth, uHeight, (BYTE)bm.bmPlanes,
                         (BYTE)bm.bmBitsPixel, (LPVOID)lpbSrc,
                         (LPVOID)lpbDst);

    GlobalUnlock(pIE->hMemAND);
    GlobalFree(pIE->hMemAND);
    GlobalFree(hMem);

    //
    // We're done so we can stop.
    //
    return 0;
  }
}

BOOL OleUIMetafilePictExtractIconSource(HGLOBAL hMetaPict, 
                                        LPSTR lpszSource, 
                                        UINT FAR *piIcon)
{
  LPMETAFILEPICT  pMF;
  TLabelExtract    le;
  HDC             hDC;

  //
  // We will walk the metafile looking for the two comment records
  // following the IconOnly comment.  The flags fFoundIconOnly and
  // fFoundSource indicate if we have found IconOnly and if we have
  // found the source comment already.
  // 
  if (NULL==hMetaPict || NULL==lpszSource || NULL==piIcon)
    return FALSE;

  pMF=(LPMETAFILEPICT)GlobalLock(hMetaPict);

  if (NULL==pMF)
    return FALSE;

  le.lpsz=lpszSource;
  le.fFoundIconOnly=FALSE;
  le.fFoundSource=FALSE;
  le.fFoundIndex=FALSE;

  //
  // Use a screen DC so we have something valid to pass in.
  //
  hDC=GetDC(NULL);
  EnumMetaFile(hDC, pMF->hMF, (MFENUMPROC)EnumMetafileExtractIconSource, 
              (LONG)(TLabelExtract far*)&le);
  ReleaseDC(NULL, hDC);

  GlobalUnlock(hMetaPict);

  //
  // Copy the icon index to the caller's variable.
  //
  *piIcon=le.u.iIcon;
  
  //
  // Check that we found everything.
  //
  return (le.fFoundIconOnly && le.fFoundSource && le.fFoundIndex);
}

int CALLBACK __export
EnumMetafileExtractIconSource(HDC /*hDC*/,
                              HANDLETABLE FAR* /*phTable*/,
                              METARECORD FAR *pMFR,
                              int /*cObj*/, 
                              TLabelExtract far* pLE)
{
  LPSTR psz;

  //
  // We don't allow anything to happen until we see "IconOnly"
  // in an MFCOMMENT that is used to enable everything else.
  // 
  if (!pLE->fFoundIconOnly) {
    if (META_ESCAPE==pMFR->rdFunction && MFCOMMENT==pMFR->rdParm[0]) {
      if (0==lstrcmpi(szIconOnly, (LPSTR)&pMFR->rdParm[2]))
        pLE->fFoundIconOnly=TRUE;
      }

    return 1;
  }

  //
  // Now see if we find the source string.
  //
  if (!pLE->fFoundSource) {
    if (META_ESCAPE==pMFR->rdFunction && MFCOMMENT==pMFR->rdParm[0]) {
      strcpyn(pLE->lpsz, (LPSTR)&pMFR->rdParm[2], MaxPathLen);
      pLE->lpsz[MaxPathLen-1] = '\0';
      pLE->fFoundSource=TRUE;
    }

    return 1;
  }

  //
  // Next comment will be the icon index.
  //
  if (META_ESCAPE==pMFR->rdFunction && MFCOMMENT==pMFR->rdParm[0]) {
    //
    // This string contains the icon index in string form,
    // so we need to convert back to a UINT.  After we see this
    // we can stop the enumeration.  The comment will have
    // a null terminator because we made sure to save it.
    //
    psz=(LPSTR)&pMFR->rdParm[2];
    pLE->u.iIcon=0;

    //
    // Do Ye Olde atoi
    //
    while (*psz)
      pLE->u.iIcon=(10*pLE->u.iIcon)+((*psz++)-'0');

    pLE->fFoundIndex=TRUE;
    return 0;
  }

  return 1;
}

//
// Aliases an OLE MetafilePictIcon
//
TOleMetaPict::TOleMetaPict(HGLOBAL metaPict, TAutoDelete autoDelete):
              MetaPict(metaPict), ShouldDelete(autoDelete==AutoDelete)
{}

//
// Frees Metafile and Memory handle (if ShouldDelete)
//
TOleMetaPict::~TOleMetaPict()
{
  if (ShouldDelete)
    Free(MetaPict);
}

//
// Frees the Metafile Handle and Global Memory Handle
//
bool
TOleMetaPict::Free(HGLOBAL& metaPict)
{
  if (!metaPict)
    return false;

  LPMETAFILEPICT pMF = (LPMETAFILEPICT)GlobalLock(metaPict);
  if (!pMF) {
    TRACEX(OwlOleDlg, 1, "Unable to lock MetaPict Handle");
    return false;
  }

  if (pMF->hMF)
    DeleteMetaFile(pMF->hMF);

  GlobalUnlock(metaPict);
  GlobalFree(metaPict);
  metaPict = 0;
  return true;
}

//
//
//
bool
TOleMetaPict::Draw(TDC& dc, TRect& rect, bool iconOnly) const
{
  PRECONDITION(MetaPict);
  return OleUIMetafilePictIconDraw(dc, &rect, MetaPict, iconOnly) ?
         true : false;  
}

//
//
//
int
TOleMetaPict::ExtractLabel(char far* label, uint32 *wrap) const
{
  PRECONDITION(MetaPict);
  return OleUIMetafilePictExtractLabel(MetaPict, label, MaxLabelLen, wrap);
}

//
//
//
HICON
TOleMetaPict::ExtractIcon(HINSTANCE hinst) const
{
  PRECONDITION(MetaPict);
  return OleUIMetafilePictExtractIcon(MetaPict, hinst);
}

//
//
//
bool
TOleMetaPict::ExtractIconSource(char far* source, uint& index) const
{
  PRECONDITION(MetaPict);
  return OleUIMetafilePictExtractIconSource(MetaPict, source, &index);
}
