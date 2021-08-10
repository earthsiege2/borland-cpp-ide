//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//   Base OLE UI dialog class definitions
//----------------------------------------------------------------------------
#if !defined(OWL_OLEDLG_H)
#define OWL_OLEDLG_H

#if !defined(OWL_OPENSAVE_H)
# include <owl/opensave.h>
#endif
#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OCF_OCVIEW_H)
# include <ocf/ocview.h>
#endif

#include <owl/oledlg.rh>
class _OWLCLASS TWindow;
class _OWLCLASS TEdit;
class _OWLCLASS TStatic;
class _OWLCLASS TButton;
class _OWLCLASS TRadioButton;
class _OWLCLASS TCheckBox;
class _OWLCLASS TListBox;

//
// Constants
//
const int MaxLinkTypes    = 8;      // Max # of link types
const int MaxPathLen      = 256;    // Max length of file name
const int MaxKeyLen       = 256;    // Max lenght of reg. key
const int LoadStringLen   = 256;    // Default length buffer for LoadStrings
const int MaxLabelLen     = 40;     // Max length of icon label
const int MaxUnknownLen   = 100;    // Max Length of UnknownType string
const int CLSIDStringLen  = 39;     // Length of string CLSID
const int GenericBufferLen= 1024;   // Generic scratch buffer length
const int cxIconPad       = 12;     // x-padding in TIconListBox
const int cyIconPad       = 4;      // y-padding in TIconListBox
const int LinkTypeLen     = 20;     // Hold "Automatic" or "Manual"
const int LinksListCols   = 3;      // Number of Column in Edit Links Dlg
const int PrefixSize      = 8;      // Used for Chopping text
const int MaxFormatEtc    = 20;     // Max. # of FormatEtc
const int HiMetricPerInch = 2540;
extern const char ClsIdStr[];        // "\\CLSID" Helpful when RegDB-searching

//
// Clipboard Format Strings
//
#if !defined(CF_EMBEDSOURCE)
# define CF_EMBEDSOURCE        "Embed Source"
#endif
#if !defined(CF_EMBEDDEDOBJECT)
# define CF_EMBEDDEDOBJECT     "Embedded Object"
#endif
#if !defined(CF_LINKSOURCE)
# define CF_LINKSOURCE         "Link Source"
#endif
#if !defined(CF_CUSTOMLINKSOURCE)
# define CF_CUSTOMLINKSOURCE   "Custom Link Source"
#endif
#if !defined(CF_OBJECTDESCRIPTOR)
# define CF_OBJECTDESCRIPTOR   "Object Descriptor"
#endif
#if !defined(CF_LINKSRCDESCRIPTOR)
# define CF_LINKSRCDESCRIPTOR  "Link Source Descriptor"
#endif
#if !defined(CF_OWNERLINK)
# define CF_OWNERLINK          "OwnerLink"
#endif
#if !defined(CF_FILENAME)
# define CF_FILENAME           "FileName"
#endif
#if !defined(NEXTCBVIEWER)
# define NEXTCBVIEWER          "NextCBViewer"
#endif

//
// Forward referenced classes
//
class _OWLCLASS TIconListBox;

//
//
// Class TOleDialog
// ----- ----------
//  Base class of OLE dialogs
//
class _USERCLASS TOleDialog : public TDialog { 
  public:
    TOleDialog(TWindow* parent,
               TResId   templateId,
               const char far *title = 0,
               TModule *module = 0);

    //
    // Disable modeless usage
    //
    HWND          DoCreate()  { return 0; }

    //
    // Force derive class to redefine 
    //
    int           DoExecute() = 0;

  protected:
    void          SetupWindow();
    void          CleanupWindow();

    //
    // Event handlers to allow proper cleanup prior to closing the dialog
    //
    void          CmOk();
    virtual bool  OleDlgOk() = 0;

    //
    // To Enable/Show or Disable/Hide a control
    //
    void          Activate(TWindow*, bool);

    //
    // OLE 2.0 Wrappers to simplify Dlg. management
    //  [Based on OLESTD, OLE2UI, BOleService etc.]
    //
    HGLOBAL       GetIconFromClass(REFCLSID clsid, const char far* label, bool useType);
    HGLOBAL       GetIconFromFile(const char far* path, bool useFile);
    HGLOBAL       FillObjectDescriptorFromData(LPDATAOBJECT dataObject,
                                               LPSTGMEDIUM  medium,
                                               CLIPFORMAT FAR *cfFmt);
    HGLOBAL       GetObjectDescriptorData(CLSID clsid, DWORD dwDrawAspect,
                                          SIZEL sizel, POINTL pointl,
                                          DWORD dwStatus,
                                          LPSTR lpszFullUserTypeName,
                                          LPSTR lpszSrcOfCopy);
    uint          GetAuxUserType(REFCLSID clsid, WORD auxUserType,
                                 char far* lpszAuxUserType, int len,
                                 HKEY hkey);
    uint          GetUserTypeOfClass(REFCLSID clsid, char far* lpszUserStr,
                                     uint len);
    HGLOBAL       GetData(LPDATAOBJECT dataObj, CLIPFORMAT cfFormat,
                          DVTARGETDEVICE FAR *targetDevice, DWORD aspect,
                          LPSTGMEDIUM medium);

    //
    // Helper routines shared by OLE Dialogs
    //
    HFILE         DoesFileExist(const char* filename, OFSTRUCT& ofs);
    char far*     PtrToNthField(char far*, int nField, char chDelim);
    int           ErrorWithFile(uint strId, const char* fileName,
                                uint mbFlags = MB_OK);
    void          OpenFileError(uint errCode, const char* fileName);
    bool          BrowseDlg(char* file, char* initialDir, uint filterId,
                            uint32 flags);
    int           PopupMessage(uint idMsg, uint idTitle, uint mbFlags);
    int           GetTextWSize(TDC &dc, char far* lpsz);
    char far*     ChopText(TWindow&, int widdth, char far* str);
    char far*     AnsiPrev(const char far* start, const char far* current);
    char far*     AnsiNext(const char far* current);

    //
    // Near versions of few helpers from above [used in MEDIUM model]
    //
#if defined(BI_DATA_NEAR)
    char*         ChopText(TWindow&, int width, char* str);
    char*         AnsiPrev(const char* start, const char* current);
    char*         AnsiNext(const char* current);
#endif

    //
    // Clipboard formats
    //
    static uint16 cfObjectDescriptor;
    static uint16 cfLinkSrcDescriptor;
    static uint16 cfEmbedSource;
    static uint16 cfEmbeddedObject;
    static uint16 cfLinkSource;
    static uint16 cfOwnerLink;
    static uint16 cfFileName;
    static bool   cfInit;

    //
    // Non-bold font for static controls
    //
    TFont*        Font;

    //
    // Dialog's title
    //
    const char far* ODTitle;

  DECLARE_RESPONSE_TABLE(TOleDialog);
};


//
// Class TIconImage
// ----- ----------
//  Simple control which displays an OLE Icon [which is really a metafile
//  with embedded icon and label].
//
class TIconImage : public TControl {
  public:
    TIconImage(TWindow* parent, int resourceId, TModule* module = 0);

    void        GetWindowClass(WNDCLASS& wndclass);
    char far*   GetClassName();

    bool        SetMetaPict(HGLOBAL hMetaPict, bool deleteOld = false);
    HGLOBAL     GetMetaPict() const { return MetaPict;  }

  protected:
    void        EvPaint();
    bool        EvEraseBkgnd(HDC);

  private:
    HGLOBAL     MetaPict;

  DECLARE_RESPONSE_TABLE(TIconImage);
};


//
// Indices of the predefined bitmap used by TResultImage
//
const uint riNone       = 0xffff;
const uint riPaste      = 0;
const uint riEmbed      = 1;
const uint riEmbedIcon  = 2;
const uint riLink       = 3;
const uint riLinkIcon   = 4;


//
// Class TResultImage
// ----- ------------
//  Control which simply displays a bitmap leaving one of the colors as
//  transparent. Can also only display part of the bitmap if the latter
//  is a *bitmap of smaller bitmaps*.
//
class _USERCLASS TResultImage : public TControl {
  public:
    TResultImage(TWindow* parent, int resourceId, TModule* module = 0);
    ~TResultImage();

    void        GetWindowClass(WNDCLASS& wndclass);
    char far*   GetClassName();

    void        SetBitmap(TResId resId, TColor transparent = TColor::Black,
                          uint numRows = 0, uint index = 0,
                          TAutoDelete = AutoDelete);
    void        SetBitmapIndex(uint);

  protected:
    void        EvPaint();
    void        SetupWindow();

    TBitmap    *Bitmap;
    bool        ShouldDelete;
    uint        NumRows, CurIndex, CX, CY;
    TColor      ClearColor;

  DECLARE_RESPONSE_TABLE(TResultImage);
};


//
// Class TOleMetaPict
// ----- ------------
//  Helper class providing methods to manipulate an OLE Icon [which is
//  really a metafile with embedded icon, label and icon source info]
//
class _USERCLASS TOleMetaPict {
  public:
    TOleMetaPict(HICON hIcon, char far* lpszLabel, TAutoDelete = AutoDelete);
    TOleMetaPict(HGLOBAL metaPict, TAutoDelete = NoAutoDelete);
    ~TOleMetaPict();

    //
    // Conversion operator to underlying/native type
    //
    operator      HGLOBAL() const { return MetaPict;  }

    bool          Draw(TDC &dc, TRect &rect, bool IconOnly) const;
    int           ExtractLabel(char far* label, uint32* wrap=0) const;
    HICON         ExtractIcon(HINSTANCE) const;
    bool          ExtractIconSource(char far* source, uint& index) const;
    static bool   Free(HGLOBAL& metaPict);

  protected:
    HGLOBAL       MetaPict;
    bool          ShouldDelete;
};


//
// ChangeIcon Data Flags
//
enum TChangeIconFlags {
  ciShowHelp      = 0x0001,
  ciSelectCurrent = 0x0002,
  ciSelectDefault = 0x0004,
  ciSelectFromFile= 0x0008,
  ciUseIconExe    = 0x0010,
};


//
// Class TChangeIconDlg
// ----- --------------
//
class _USERCLASS TChangeIconDlg : public TOleDialog {
  public:
    class _USERCLASS TData {
      public:
        TData();
        uint32    Flags;                  // Data Flags
        HGLOBAL   MetaPict;               // *The* image
        CLSID     ClsId;                  // Class for Default Icon
        char      IconExe[MaxPathLen];    // File to extract icon from
    };

    TChangeIconDlg(TWindow* parent,
                   TData&   data,
                   TResId   templateId = 0,
                   const char far* title = 0,
                   TModule* module = 0);
    ~TChangeIconDlg();
    int                 DoExecute();

  protected:
    void                SetupWindow();
    void                CleanupWindow();
    bool                OleDlgOk();

    void                SetIcon(TStatic&, HICON);

    uint                FillIconList(const char*);
    void                UpdateResultIcon(TChangeIconFlags);

    void                CurrentClicked();
    void                DefaultClicked();
    void                FromFileClicked();

    void                LabelKillFocus();
    void                FileNameNotification(uint);
    void                IconListSetFocus();
    void                IconListSelChange();
    void                IconListDblClk();
    void                BrowseClicked();

    TData&              Data;

    TStatic*            CurrentIcon;
    TStatic*            DefaultIcon;
    TRadioButton*       Current;
    TRadioButton*       Default;
    TRadioButton*       FromFile;

    TEdit*              FileName;
    TIconListBox*       IconList;

    TEdit*              Label;
    TStatic*            ResultIcon;
    TStatic*            ResultLabel;

    TButton*            Help;
    TButton*            Browse;

  private:
    //
    // Used internally to keep track of dialog's state
    //
    class _USERCLASS THelper {
      public:
        THelper();

        uint32    Flags;
        HICON     CurIcon;
        char      Label[MaxLabelLen+1];
        char      File[MaxPathLen];
        uint      IconIndex;

        HICON     DefIcon;
        char      DefIconFile[MaxPathLen];
        uint      DefIconIndex;
    };

   THelper&       Helper;

  DECLARE_RESPONSE_TABLE(TChangeIconDlg);
};


//
// Enumerations used to populate Flags member of TInsertObjectDlg::TData
//
enum TInsertObjectFlags {
  ioShowHelp            = 0x0001,
  ioSelectCreateNew     = 0x0002,
  ioSelectCreateFromFile= 0x0004,
  ioCheckLink           = 0x0008,
  ioCheckDisplayAsIcon  = 0x0010,
  ioDisableLink         = 0x0100,
  ioVerifyServerExist   = 0x0200,
  ioDisableDisplayAsIcon= 0x0400
};


//
// Class TInsertObjectDlg
// ----- ----------------
//
class _USERCLASS TInsertObjectDlg : public TOleDialog {
  public:
    //
    // Class TData  (InsertObject Data)
    // ----- -----  ------------- -----
    //
    class _USERCLASS TData {
      public:
        TData();
        uint32      Flags;
        CLSID       ClsId;
        char far*   FileName;
        LPCLSID     lpClsIdExclude;
        uint        cClsIdExclude;
        HGLOBAL     MetaPict;
    };

    TInsertObjectDlg(TWindow* parent,
                     TOcInitInfo &initInfo,
                     TData  *insObj = 0,
                     TResId  templateId = 0,
                     const char far* title = 0,
                     TModule* module = 0);
   ~TInsertObjectDlg();
    int           DoExecute();

  protected:
    bool          EvInitDialog(HWND);
    void          CleanupWindow();
    bool          OleDlgOk();

    int           FillClassList();
    bool          ToggleObjectSource(TInsertObjectFlags);
    void          UpdateClassType(bool);
    void          UpdateClassIcon();
    void          SetInsertObjectResults();
    bool          ValidateInsertFile(bool showErr=true);
    bool          GetCurrentCLSID(CLSID&);

    //
    // Response Methods
    //
    void          CreateNewClicked();
    void          CreateFromFileClicked();
    void          BrowseFileClicked();
    void          LinkToFileClicked();
    void          DisplayAsIconClicked();
    void          ChangeIconClicked();
    void          ObjectListChanged();
    void          ObjectListDoubleClicked();
    void          FileNameChanged();
    void          FileNameKillFocus();

    TOcInitInfo&  InitInfo;
    TData*        Data;

    TCheckBox*    DisplayAsIcon;
    TButton*      ChangeIcon;
    TButton*      Browse;
    TCheckBox*    Link;
    TStatic*      File;
    TStatic*      FileType;
    TEdit*        FileName;
    TListBox*     ObjectList;
    TStatic*      ObjectType;
    TStatic*      ResultText;
    TResultImage* ResultImage;
    TIconImage*   IconImage;
    TButton*      Help;
    TButton*      Ok;
    TRadioButton* CreateNew;
    TRadioButton* CreateFromFile;

  private:
    bool          GetDefaultInsertObjectData();

    //
    // Class THelper
    // ----- -------
    //  Used internally to keep track of dialog's state
    //
    class _USERCLASS THelper {
      public:
        THelper();

        uint32    Flags;
        CLSID     ClsId;
        char      FileName[MaxPathLen];
        bool      FileSelected;
        bool      AsIconNew;
        bool      AsIconFile;
        bool      FileDirty;
        bool      FileValid;
        uint      ErrCode;
        HGLOBAL   MetaPict;
    };

    THelper&      Helper;
    bool          DeleteData;

    static OLECHAR  DynamicScopePath[MaxPathLen];
    static CLSID    DynamicScopeClsid;

  DECLARE_RESPONSE_TABLE(TInsertObjectDlg);
};


//
// Enumeration flags for Flags member of TConvertDlg::TData
//
enum TConvertFlags {
  cvShowHelpButton      = 0x0001,
  cvSetConvertDefault   = 0x0002,
  cvSetActivateDefault  = 0x0004,
  cvSelectConvertTo     = 0x0008,
  cvSelectActivateAs    = 0x0010,
  cvDisableDisplayAsIcon= 0x0020,
  cvDisableActivateAs   = 0x0040
};


//
// Class TConvertDlg
// ----- -----------
//
class _USERCLASS TConvertDlg : public TOleDialog {
  public:
    //
    // Class TData
    // ----- -----
    //
    class _USERCLASS TData {
      public:
        TData(TOcPart& ocpart);

        uint32    Flags;
        CLSID     ClsId;
        CLSID     ClsIdConvertDefault;
        CLSID     ClsIdActivateDefault;
        CLSID     ClsIdNew;
        uint32    dvAspect;
        WORD      wFormat;
        bool      fIsLinkedObject;
        HGLOBAL   MetaPict;
        LPSTR     lpszUserType;
        bool      fObjectsIconChanged;
        LPSTR     lpszDefLabel;
        uint      ClsIdExclude;
        LPCLSID   lpClsIdExclude;
    };

    TConvertDlg(TWindow* parent, TData& data, TResId  templateId = 0,
                const char far* title = 0, TModule* module = 0);
   ~TConvertDlg();

    void          SetupWindow();
    void          CleanupWindow();

  protected:
    uint          FillClassList();
    void          UpdateClassIcon();
    bool          IsValidClassID(CLSID);
    void          SetConvertResults();
    bool          FormatIncluded(char* str, WORD wFormat);

    TStatic*      ObjectType;
    TListBox*     ConvertList;
    TListBox*     ActivateList;

    TCheckBox*    DisplayAsIcon;
    TStatic*      ResultText;
    TStatic*      ResultIcon;
    TStatic*      IconLabel1;
    TStatic*      IconLabel2;

    TRadioButton* ConvertTo;
    TRadioButton* ActivateAs;
    TButton*      ChangeIcon;

    TButton*      Help;

    TData&        Data;
  private:
    //
    // Class used internally to keep track of dialog state
    //
    class _USERCLASS THelper {
      public:
        THelper(){ memset(this, 0, sizeof(THelper)); }

        uint32      Flags;
        TListBox*   VisibleList;
        TListBox*   InvisibleList;
        CLSID       ClsId;
        DWORD       dvAspect;
        bool        fCustomIcon;
        uint        IconIndex;
        LPSTR       lpszIconSource;
        LPSTR       lpszCurrentObject;
        LPSTR       lpszConvertDefault;
        LPSTR       lpszActivateDefault;
   };
   THelper&         Helper;

  DECLARE_RESPONSE_TABLE(TConvertDlg);
};

//
// Enumerations used to populate Flags member of TPasteSpecialDlg::TData
//
enum TPasteSpecialFlags {
  psShowHelp            = 0x0001,
  psSelectPaste         = 0x0002,
  psSelectPasteLink     = 0x0004,
  psCheckDisplayAsIcon  = 0x0008,
  psDisableDisplayAsIcon= 0x0010
};

//
//
//
enum  TOleUIPasteFlag {
   pfPasteOnly     = 0,
   pfLinkType1     = 1,
   pfLinkType2     = 2,
   pfLinkType3     = 4,
   pfLinkType4     = 8,
   pfLinkType5     = 16,
   pfLinkType6     = 32,
   pfLinkType7     = 64,
   pfLinkType8     = 128,
   pfPaste         = 512,
   pfLinkAnyType   = 1024,
   pfEnableIcon    = 2048
};

//
// Class TPasteSpecialDlg
// ----- ----------------
//
class _USERCLASS TPasteSpecialDlg : public TOleDialog {

  public:
    class _USERCLASS TPasteEntry;

    //
    // Class TData  (TPasteSpecialDlg Data)
    // ----- -----  ----------------- -----
    //
    class _USERCLASS TData {
      public:
        TData();
        uint32            Flags;
        LPDATAOBJECT      lpSrcDataObj;
        TPasteEntry FAR*  ArrayPasteEntries;
        int               cPasteEntries;
        uint far*         ArrayLinkTypes;
        int               cLinkTypes;
        LPCLSID           lpClsIdExclude;
        uint              cClsIdExclude;
        int               SelectedIndex;
        bool              fLink;
        HGLOBAL           MetaPict;
        SIZEL             SizeL;
    };

  protected:
    //
    // Class TPasteEntry
    // ----- -----------
    //
    class _USERCLASS TPasteEntry {
      public:
        TPasteEntry();

        FORMATETC     fmtetc;
        LPCSTR        lpstrFormatName;
        LPCSTR        lpstrResultText;
        DWORD         dwFlags;
        DWORD         dwScratchSpace;
    };

    //
    // Class TPasteListItemData
    // ----- ------------------
    //
    class _USERCLASS TPasteListItemData {
      public:
        TPasteListItemData();

        int   nPasteEntriesIndex;
        bool  fCntrEnableIcon;
    };

  public:
    TPasteSpecialDlg(TWindow* parent,
                     TOcInitInfo &initInfo,
                     TData *data = 0,
                     TResId templateId = 0,
                     const char far* title = 0,
                     TModule* module = 0);
    ~TPasteSpecialDlg();

    int           DoExecute();

  protected:
    bool          EvInitDialog(HWND);
    void          CleanupWindow();
    bool          OleDlgOk();

    bool          GetDefaultPasteSpecialData();

    bool          TogglePasteType(TPasteSpecialFlags);
    void          ChangeListSelection();
    void          EnableDisplayAsIcon();
    void          ToggleDisplayAsIcon();
    void          SetPasteSpecialHelpResults();

    bool          FillPasteList();
    bool          FillPasteLinkList();
    bool          AddPasteListItem(TListBox&, bool,  int, const char far*);
    void          FreeListData(TListBox&);

    bool          HasPercentS(const char far*);

    void          MarkPasteEntryList(LPDATAOBJECT lpSrcDataObj,
                                     TPasteEntry far* lpPriorityList,
                                     int cEntries);

    void          EvDrawClipboard();
    void          EvChangeCBChain(HWND hwndRemoved, HWND hwndNext);

    void          ChangeIconClicked();
    void          PasteClicked();
    void          PasteLinkClicked();
    void          DisplayAsIconClicked();

    void          DisplayListSelChange();
    void          DisplayListDblClk();

    TCheckBox*    DisplayAsIcon;
    TButton*      ChangeIcon;
    TRadioButton* Paste;
    TRadioButton* PasteLink;
    TResultImage* ResultImage;
    TIconImage*   IconImage;
    TListBox*     DisplayList;
    TListBox*     PasteList;
    TListBox*     PasteLinkList;
    TStatic*      ResultText;
    TStatic*      SourceText;
    TButton*      Help;

    TOcInitInfo  &InitInfo;
    TData        *Data;

  private:
    //
    // Used internally to keep track of dialog's state
    //
    struct _USERCLASS THelper {
      public:
        THelper();

        uint32      Flags;
        int         PasteListCurSel;
        int         PasteLinkListCurSel;
        int         SelectedIndex;
        bool        Link;
        char        UnknownType[MaxUnknownLen];
        char        UnknownSource[MaxUnknownLen];
        char        AppName[MaxKeyLen];

        CLSID       ClsIdOD;
        SIZEL       SizeLOD;

        char far*   FullUserTypeNameOD;
        char far*   SourceOfDataOD;
        bool        SrcAspectIconOD;
        bool        SrcOnlyIconicOD;
        HGLOBAL     MetaPictOD;
        HGLOBAL     ObjDesc;

        CLSID       ClsIdLSD;
        SIZEL       SizeLLSD;

        char far*   FullUserTypeNameLSD;
        char far*   SourceOfDataLSD;
        bool        SrcAspectIconLSD;
        bool        SrcOnlyIconicLSD;
        HGLOBAL     MetaPictLSD;
        HGLOBAL     LinkSrcDesc;

        bool        ClipboardChanged;
    };

    THelper&        Helper;

    //
    // Used internally if no TData* is specified
    //
    bool                 DeleteData;
    TPasteEntry         *pOleUIEntries;
    TOcFormatInfo*       pBOleEntries;
    uint                *pBOleLinkEntries;

  DECLARE_RESPONSE_TABLE(TPasteSpecialDlg);
};


#if !defined(LPOLEUILINKCONTAINER)

// IOleUILinkContainer Interface
// -----------------------------
//    This interface must be implemented by container applications that
//    want to use the EditLinks dialog. the EditLinks dialog calls back
//    to the container app to perform the OLE functions to manipulate
//    the links within the container. The OWL Edit Links Dialog uses
//    Bolero's implementation of this interface.
//

#define LPOLEUILINKCONTAINER     IOleUILinkContainer FAR*

#undef  INTERFACE
#define INTERFACE   IOleUILinkContainer

DECLARE_INTERFACE_(IOleUILinkContainer, IUnknown)
{
  //*** IUnknown methods ***/
  STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
  STDMETHOD_(ULONG,AddRef) (THIS) PURE;
  STDMETHOD_(ULONG,Release) (THIS) PURE;

  STDMETHOD_(DWORD,GetNextLink) (THIS_ DWORD dwLink) PURE;
  STDMETHOD(SetLinkUpdateOptions) (THIS_ DWORD dwLink, DWORD dwUpdateOpt) PURE;
  STDMETHOD(GetLinkUpdateOptions) (THIS_ DWORD dwLink, DWORD FAR* lpdwUpdateOpt) PURE;
  STDMETHOD(SetLinkSource) (THIS_
      DWORD       dwLink,
      LPSTR       lpszDisplayName,
      ULONG       lenFileName,
      ULONG FAR*  pchEaten,
      BOOL        fValidateSource) PURE;
  STDMETHOD(GetLinkSource) (THIS_
      DWORD       dwLink,
      LPSTR FAR*  lplpszDisplayName,
      ULONG FAR*  lplenFileName,
      LPSTR FAR*  lplpszFullLinkType,
      LPSTR FAR*  lplpszShortLinkType,
      BOOL FAR*   lpfSourceAvailable,
      BOOL FAR*   lpfIsSelected) PURE;
  STDMETHOD(OpenLinkSource) (THIS_ DWORD dwLink) PURE;
  STDMETHOD(UpdateLink) (THIS_
      DWORD dwLink,
      BOOL fErrorMessage,
      BOOL fErrorAction) PURE;
  STDMETHOD(CancelLink) (THIS_ DWORD dwLink) PURE;
};

#endif  //  !defined  LPOLEUILINKCONTAINER

//
// Enumeration used to populate dwFlags member of TEditLinksDlg::TData
//
enum TEditLinksFlags {
  elShowHelp           = 0x0001,
  elDisableUpdateNow   = 0x0002,
  elDisableOpenSource  = 0x0004,
  elDisableChangeSource= 0x0008,
  elDisableCancelLink  = 0x0010
};

//
// Class TEditLinksDlg
// ----- -------------
//
class _USERCLASS TEditLinksDlg : public TOleDialog {
  public:
    //
    // Class TEditLinksDlg::TData
    // ----- --------------------
    //  Class used to pass in the necessary information to the
    //  EditLinks dialog.
    //
    class _USERCLASS TData {
      public:
        TData(const TOcView&);
        ~TData();
        uint32 dwFlags;
        LPOLEUILINKCONTAINER lpOleUILinkContainer;
    };

    TEditLinksDlg(TWindow* parent,
                  const TOcView& ocView,
                  TResId templateId = 0,
                  const char far* title = 0,
                  TModule* module = 0);
    ~TEditLinksDlg();
    int             DoExecute();
    bool            OleDlgOk() {return true;}

  protected:
    bool            EvInitDialog(HWND);
    void            DrawLinksListEntry(DRAWITEMSTRUCT far&);

    void            EvMeasureItem(uint, MEASUREITEMSTRUCT far&);
    void            EvDrawItem(uint, DRAWITEMSTRUCT far&);
    LRESULT         EvCompareItem(uint, COMPAREITEMSTRUCT far&);
    void            EvDeleteItem(uint, DELETEITEMSTRUCT far&);

    void            ChangeSourceClicked();
    void            AutomaticClicked();
    void            ManualClicked();
    void            BreakLinkClicked();
    void            UpdateNowClicked();
    void            OpenSourceClicked();

  private:
    //
    // Used internally to store information about a particular link
    //
    class _USERCLASS TLinkInfo {
      public:
        TLinkInfo(DWORD);
        ~TLinkInfo();

        uint32      dwLink;
        char*       lpszDisplayName;
        char*       lpszItemName;
        char*       lpszShortFileName;
        char*       lpszShortLinkType;
        char*       lpszFullLinkType;
        char*       lpszAMX;
        uint32      clenFileName;
        bool        fSourceAvailable;
        bool        fIsAuto;
        bool        fIsMarked;
        bool        fDontFree;
        bool        fIsSelected;
    };

    //
    // Used internally to keep track of dialog's state
    //
    class _USERCLASS THelper {
      public:
        THelper();

        bool    fClose;
        int    *rgIndex;
        int     cSelItems;
        bool    fItemsExist;
        char    szClose[50];
    };

    //
    // Class TChgSrcFileOpenDlg
    // ----- ------------------
    //  This customized version of the FileOpen dialog performs
    //  validation on the file name entered. It is used when the
    //  user decides to change the source of a Link.
    //
    class _USERCLASS TChgSrcFileOpenDlg : public TFileOpenDialog {
      public:
        //
        // Class TChgSrcData
        // ----- -----------
        //
        class _USERCLASS TChgSrcData {
          public:
            TChgSrcData(TLinkInfo far*, TEditLinksDlg::TData&);

            TEditLinksDlg::TLinkInfo far* lpLI;
            TEditLinksDlg::TData&         Data;
            bool                          fValidLink;
            char*                         lpszFrom;
            char*                         lpszTo;
        };

        TChgSrcFileOpenDlg(TWindow* parent,
                          TData&   data,
                          TChgSrcData& chgSrcData,
                          TResId   templateId = 0,
                          const char far* title = 0,
                          TModule* module = 0);
        ~TChgSrcFileOpenDlg();

      protected:
        void              SetupWindow();

        TChgSrcData&      ChgSrcData;

      private:
        //
        // Class THelper
        // ----- -------
        //
        class _USERCLASS THelper {
          public:
            THelper() { memset(this, 0, sizeof(THelper)); }

            bool    fValidLink;
            char    szFileName[MaxPathLen];
            char    szItemName[MaxPathLen];
            bool    bFileNameStored;
            bool    bItemNameStored;
            char    szEdit[MaxPathLen];
            LPSTR   lpszFrom;
            LPSTR   lpszTo;
        };
        THelper&    Helper;
    };

  protected:
    bool            Container_ChangeSource();
    HRESULT         Container_AutomaticManual(bool fAutoMan);
    HRESULT         Container_UpdateNow();
    HRESULT         Container_OpenSource();

    int             AddLinkLBItem(TLinkInfo* lpLinkInfo, bool sel);
    void            UpdateLinkLBItem(int nIndex, bool bSelect);
    void            ChangeAllLinks(char* from, char* to);
    bool            ChangeSource(char* file,
                                 TChgSrcFileOpenDlg::TChgSrcData&,
                                 uint);
    void            BreakString(TLinkInfo*);
    HRESULT         CancelLink();

    int             GetSelectedItems(int* &);
    void            InitControls();

    void            DiffPrefix(const char*, const char*, char* &, char* &);
    int             LoadLinkLB();
    void            RefreshLinkLB();
    int             LBPad() const;

    TListBox*       LinksList;
    TButton*        UpdateBtn;
    TButton*        OpenBtn;
    TButton*        ChangeBtn;
    TButton*        BreakLinkBtn;
    TButton*        Help;
    TButton*        Cancel;
    TRadioButton*   Automatic;
    TRadioButton*   Manual;
    TStatic*        LinkSource;
    TStatic*        LinkType;

    int             nColPos[LinksListCols];
    int             nMaxCharWidth, nHeightLine;
    TData*          Data;

  private:
    THelper&        Helper;

  DECLARE_RESPONSE_TABLE(TEditLinksDlg);
};

//----------------------------------------------------------------------------
// Inlines
//

//
//
//
inline HGLOBAL
TOleDialog::GetIconFromClass(REFCLSID clsid, const char far* label, bool useType)
{
  return ::OleGetIconOfClass(clsid, OleStr(const_cast<char far*>(label)), useType);
}

//
//
//
inline HGLOBAL
TOleDialog::GetIconFromFile(const char far* path, bool useFile)
{
  return ::OleGetIconOfFile(OleStr(const_cast<char far*>(path)), useFile);
}

//
//
//
inline char far*
TOleDialog::AnsiPrev(const char far* start, const char far* current)
{
  return ::AnsiPrev(start, current);
}

//
//
//
inline char far*
TOleDialog::AnsiNext(const char far* current)
{
  return ::AnsiNext(current);
}

#if defined(BI_DATA_NEAR)

//
//
//
inline char*
TOleDialog::AnsiPrev(const char* start, const char* current)
{
  char far* str = ::AnsiPrev(start, current);
  CHECK(HIWORD(str) == HIWORD(start));
  return (char*)(LOWORD(str));
}

//
//
//
inline char*
TOleDialog::AnsiNext(const char* current)
{
  char far* str = ::AnsiNext(current);
  CHECK(HIWORD(str) == HIWORD(current));
  return (char*)(LOWORD(str));
}

//
//
//
inline char*
TOleDialog::ChopText(TWindow& win, int width, char* str)
{
  char far* lpstr  = str;
  char far* result = ChopText(win, width, lpstr);
  CHECK(HIWORD(result) == HIWORD(lpstr));
  return (char*)(LOWORD(result));
}
#endif    // BI_DATA_NEAR

//
//
//
inline char far*
TResultImage::GetClassName()
{
  return RESULTIMAGE_CLSNAME;
}

//
//
//
inline char far*
TIconImage::GetClassName()
{
  return ICONIMAGE_CLSNAME;
}

//
//
//
inline HCURSOR
HourGlassOn()
{
  HCURSOR oldCursor = ::SetCursor(::LoadCursor(0, IDC_WAIT));
  ShowCursor(TRUE);
  return oldCursor;
}

//
//
//
inline void
HourGlassOff(HCURSOR hCursor)
{
  ShowCursor(FALSE);
  SetCursor(hCursor);
}

//
// Slight variation of strncpy() which guarantees a NULL-terminated
// destination - Returns 0 if the 'maxLen' is only 1.
//
inline char far*
strcpyn(char far* dest, const char far* src, size_t maxLen)
{
  PRECONDITION(!IsBadWritePtr(dest, maxLen));
  dest[maxLen-1] = 0;
  return (maxLen > 1) ? strncpy(dest, src, maxLen-1) : 0;
}

#if defined(BI_DATA_NEAR)
inline char*
strcpyn(char* dest, const char* src, size_t maxlen)
{
  char far *lpDest = dest;
  char far *lpResult = strcpyn(dest, src, maxlen);
  CHECK(HIWORD(lpResult) == HIWORD(lpDest));
  return (char*)(LOWORD(lpResult));
}
#endif

//
// Initialize FORMATETC structure
//
inline void
InitFormatEtc(FORMATETC &fmt, CLIPFORMAT cf, DWORD tymed, LONG lindex = -1,
              DWORD dwAspect = DVASPECT_CONTENT, 
              DVTARGETDEVICE FAR* ptd = 0)
{
  fmt.cfFormat  = cf;
  fmt.dwAspect  = dwAspect;
  fmt.ptd       = ptd;
  fmt.tymed     = tymed;
  fmt.lindex    = lindex;
}

#endif  //  __USER_OLEDLG_H
