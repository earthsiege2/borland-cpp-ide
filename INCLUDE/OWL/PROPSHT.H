//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.20  $
//
// Definition of classes encapsulating PropertySheets and PropertyPages
//----------------------------------------------------------------------------
#if !defined(OWL_PROPSHT_H)
#define OWL_PROPSHT_H

#if !defined(OWL_DEFS_H)
# include <owl/defs.h>
#endif
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif

// Documented but missing from system headers!
//
#if !defined(PSH_MULTILINETABS)
# define PSH_MULTILINETABS 0x0010
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TIcon;
class _OWLCLASS TPropertySheet;
class _OWLCLASS TPropertyPage;
class _OWLCLASS TTabControl;
class _OWLCLASS TTabKeyDown;

//
// Prototypes of callbacks used to iterate through PropertyPages
//
typedef void (*TActionPageFunc)(TPropertyPage* pPage, void* param);
typedef bool (*TCondPageFunc)(TPropertyPage* pPage, void* param);

//----------------------------------------------------------------------------
// TPropertyPage
//----------------------------------------------------------------------------

//
// class TPropertyPage
// ~~~~~ ~~~~~~~~~~~~~
// The 'TPropertyPage' object represents a dialog box found within a property
// sheet. Each 'page' contains controls for setting a group of related
// properties. Each page has a tab that the user can select to bring the page
// to the foreground of the property sheet.
//
class _OWLCLASS TPropertyPage: public TDialog {
  public:
    TPropertyPage(TPropertySheet* parent, TResId resId,
                  const char far* title = 0, TResId iconRes = 0,
                  TModule* module = 0);
   ~TPropertyPage();

    // Set attributes of the page
    //
    void            SetIcon(const TIcon&);
    void            SetIcon(TResId iconResId);
    void            SetTitle(const char far*);
    void            SetTitle(int txtResId);

    // Get/Set caption
    //
    bool            GetPageCaption(char* txt, int size);
    void            SetPageCaption(char far* caption);

    // Retrieve Sheet object [i.e. Parent of page]
    //
    TPropertySheet* GetSheet() const;

    // Operator to return HPROSHEETPAGE handle
    //
    operator        HPROPSHEETPAGE() const;

    // Retrieve information about this page
    //
    void            CopyPageInfo(PROPSHEETPAGE& pgInfo) const;
    PROPSHEETPAGE&  GetPropSheetPage();

    // Create/Destroy the HPROPSHEETPAGE handle that uniquely identifies this
    // page.
    //
    HPROPSHEETPAGE  CreatePropertyPage();
    bool            DestroyPropertyPage();

    // Override this to process messages within the dialog function
    // Return true if message handled, false if not.
    //
    virtual bool    DialogFunction(uint msg, TParam1 p1, TParam2 p2);

    // Overriden to patch PSN_FIRST-PSN_LAST notifications
    //
    virtual TResult EvNotify(uint id, TNotify far& notifyInfo);

    // Overriden virtuals of TWindow/TDialog
    //
    bool            Create();

    // This is the callback invoked when the a property sheet page is created
    // and destroyed
    //
    static uint CALLBACK OWL_EXPORT16
    PropCallback(HWND hwnd, uint uMsg, LPPROPSHEETPAGE ppsp);

    // This is the callback invoked when notifications are sent to the pages
    //
    static int CALLBACK OWL_EXPORT16
    PropDlgProc(HWND hDlg, uint msg, WPARAM wParam, LPARAM lParam);

  protected:

    // Virtual methods to handle the Sheet notifications. Some of these 
    // methods will most likely be overriden by TPropertyPage-derived classes
    //
    virtual   int   Apply(TNotify far&);
    virtual   bool  KillActive(TNotify far&);
    virtual   void  Help(TNotify far&);
    virtual   void  Reset(TNotify far&);
    virtual   int   SetActive(TNotify far&);
    virtual   int   WizBack(TNotify far&);
    virtual   bool  WizFinish(TNotify far&);
    virtual   int   WizNext(TNotify far&);

    // Following structure holds information about this dialog when it is
    // inserted into a PropertySheet
    //
    PROPSHEETPAGE   PageInfo;

    // Handle of this property page
    //
    HPROPSHEETPAGE  HPropPage;

    // Flags if native implementation is used
    //
    bool            UseNative;

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TPropertyPage(const TPropertyPage&);
    TPropertyPage& operator =(const TPropertyPage&);

    // Method that ties the C++ object presenting the page with the underlying
    // 'HWND' handle.
    //
    static void     InitHandle(THandle pageHandle, LPPROPSHEETPAGE pageInfo);

    // Caption of dialog as stored in resource
    //
    TAPointer<char> ResCaption;

#if !defined(OWL_NATIVECTRL_ALWAYS)
    // The following methods are only valid when ObjectWindows is providing
    // the underlying implementation of PropertySheet/Page. These methods are
    // protected to support derived classes. However, your derived classes
    // should be implemented to rely on these methods only when the Common
    // Control library is unavailable and ObjectWindows is providing the
    // underlying implementation of PropertySheet/PropertyPages.
    //

  public:
    void            SetModified(bool modified);
    bool            IsModified() const;

  protected:
    void            SetupWindow();

  private:
    bool            Modified;
#endif
    DECLARE_RESPONSE_TABLE(TPropertyPage);
//  DECLARE_STREAMABLE(_OWLCLASS, TPropertyPage, 1);
};

//----------------------------------------------------------------------------
// TPropertySheet
//----------------------------------------------------------------------------
class _OWLCLASS TPshNotify : public PSHNOTIFY {
  public:
    TPshNotify(HWND hwnd, uint id, uint code, LPARAM lp);
    operator  NMHDR&() { return hdr; }
};

//
// class TPropertySheet
// ~~~~~ ~~~~~~~~~~~~~~
// TPropertySheet encapsulates a window which contains one or more overlapping
// child windows knowns as property pages. The sheet provides a container
// which display pages allowing the user to view and edit related properties
// grouped in individual pages.
//
class _OWLCLASS TPropertySheet : public TWindow {
  public:
    TPropertySheet(TWindow* parent, const char far* title,
                   uint startPage = 0,
                   bool isWizard = false,
                   uint32 flags = PSH_DEFAULT,
                   TModule* module = 0);
   ~TPropertySheet();

    // Override virtual functions defined by class TWindow
    //
    void            SetCaption(const char far* title);
    int             Execute();
    bool            Create();
    int             Run(bool modal);

    // Manipulate (add, remove, select) pages of the property sheet
    //
    void            AddPage(TPropertyPage&);
    bool            SelectPage(TPropertyPage&);
    bool            SelectPage(int pgIndex);
    bool            SelectPage(TResId pgRes);
    void            RemovePage(TPropertyPage&);
    void            RemovePage(int pgIndex);
    int             GetPageCount() const;

    // Inform sheet of changes in state of page
    //
    void            PageChanged(const TPropertyPage&);
    void            PageUnchanged(TPropertyPage&);

    // Have sheet simulate user actions
    //
    void            PressButton(int button);
    bool            Apply();

    // Query the pages of the sheet
    //
    int             QuerySiblings(TParam1, TParam2);

    // Inform sheet of special requirements
    //
    void            RebootSystem();
    void            RestartWindows();

    // Update sheet attributes: title, buttons, ...
    //
    void            SetTitle(const char far* text,
                             uint32 style = PSH_PROPTITLE);
    void            SetFinishText(const char far* text);
    void            SetWizButtons(uint32 flags);
    void            CancelToClose();

    // Retrieve handle to underlying tab control or current page
    //
    HWND            GetTabControl() const;
    HWND            GetCurrentPage() const;

    // Allow processing of dialog messages
    //
    bool            IsDialogMessage(MSG far& msg);

    // Retrieve the structure describing the sheet
    //
    PROPSHEETHEADER& GetPropSheetHeader();

    // Helper routines to query/iterate about/through pages
    //
    void            ForEachPage(TActionPageFunc action, void* paramList = 0);
    TPropertyPage*  FirstPageThat(TCondPageFunc cond, void* paramList = 0);

  protected:
    bool            UseNative;      // Are we using native (OS) implementation
    bool            SubClassSheet;  // Should we subclass the sheet (OS only)

    // Flags if sheet is a wizard
    //
    bool            IsWizard;

    // Holds information necessary to create the property sheet
    //
    PROPSHEETHEADER HeaderInfo;

    // Helper routine to retrieve handle of pages
    //
    bool            GetPageHandles();

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TPropertySheet(const TPropertySheet&);
    TPropertySheet& operator =(const TPropertySheet&);

    // Method that ties the C++ object presenting the sheet
    // with the underlying 'HWND' handle.
    //
    void            InitHandle(THandle sheetHandle);
    friend          TPropertyPage;

#if !defined(OWL_NATIVECTRL_ALWAYS)
    // The following methods are only valid when ObjectWindows is providing
    // the underlying implementation of PropertySheet/Page. These methods are
    // protected to support derived classes. However, your derived classes
    // should be implemented to rely on these methods only when the Common
    // Control library is unavailable and ObjectWindows is providing the
    // underlying implementation of PropertySheet/PropertyPages.
    //
  protected:
    // Override TWindow virtual member functions
    //
    void            SetupWindow();
    char far*       GetClassName();
    void            GetWindowClass(WNDCLASS& wndClass);

    // Helper routines to ask for info. about pages of sheet
    //
    TPropertyPage*  PageAtIndex(int index) const;
    int             IndexOfPage(const TPropertyPage* page) const;
    TPropertyPage*  GetActivePage() const;
    bool            SetActivePage(int index);
    int             TabIndexOfPage(const TPropertyPage* page) const;
    TPropertyPage*  PageAtTabIndex(int index) const;

    // Helper routines to create, position, size, sync. tab, pages
    // and the buttons of the property sheet. 
    //
    void            SyncTabAndPages();
    void            UpdateTabAndSheetSize(const TRect& pageRect);
    void            PositionPage(TPropertyPage* page);
    void            ComputeMarginAndButton();
    bool            CreateButtons();
    HWND            CreateButton(int id, const char* caption);
    bool            UpdateButtons();

    // Variables
    //
    TTabControl*    Tab;                // Pointer to tab control
    int             ActiveIndex;        // Index of active page
    TRect           PageRect;           // Area occupied to page
    HWND            FocusHwnd;          // Handle of focus window
    TSize           ButtonSize;         // Width/Height of buttons
    int             Margin;             // Tab/Dialog & Button/Button margin
    bool            ApplyEnabled;       // Apply button enabled;
    TFont*          Font;               // Pointer to font object

    // Event Handlers
    //
    void            EvSize(uint sizeType, TSize& size);
    void            EvActivate(uint active, bool minimized, THandle other);
    void            EvSetFocus(THandle hWndLostFocus);
    HFONT           EvGetFont();

    void            TabSelChange(TNotify far& nmHdr);
    bool            TabSelChanging(TNotify far& nmHdr);
    void            TabKeyDown(TTabKeyDown far& kdNot);

    void            ButtonClicked(uint id);

    DECLARE_RESPONSE_TABLE(TPropertySheet);
#endif
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>


//----------------------------------------------------------------------------
// Inline implementations
//
inline
TPshNotify::TPshNotify(HWND hwnd, uint id, uint code, LPARAM lp)
{
  hdr.hwndFrom = hwnd;
  hdr.idFrom = id;
  hdr.code = code;
  lParam = lp;
}

//
// Returns the HPROPSHEETPAGE handle representing an unlying PropertyPage.
// NOTE: This method is only functional when the Common Control library
//       provides the underlying implementation of PropertyPages.
//
// NOTE: The 'CreatePropertyPage' method also returns the HPROPSHEETPAGE.
//       However, it will attempt to create the page if the latter had not been
//       created beforehand. The HPROPSHEETPAGE operator simply returns the
//       page handle without attempting to create the page.
//
inline TPropertyPage::operator HPROPSHEETPAGE() const
{
  PRECONDITION(HPropPage);
  return HPropPage;
}

//
// Return structure which describes the characteristics/attributes of page.
//
inline PROPSHEETPAGE&  
TPropertyPage::GetPropSheetPage()
{
  return PageInfo;  
}

//
// Return pointer to parent/sheet object
//
inline TPropertySheet*
TPropertyPage::GetSheet() const
{
  CHECK(GetParentO());
  CHECK(TYPESAFE_DOWNCAST(GetParentO(), TPropertySheet));
  return TYPESAFE_DOWNCAST(GetParentO(), TPropertySheet);
}

#if !defined(OWL_NATIVECTRL_ALWAYS)
//
//
//
inline void            
TPropertyPage::SetModified(bool modified) 
{
  Modified = modified;
}

//
//
//
inline bool            
TPropertyPage::IsModified() const
{
  return Modified;
}
#endif

//
// Return structure which describes the characteristics/attributes of sheet.
//
inline PROPSHEETHEADER& 
TPropertySheet::GetPropSheetHeader() 
{
  return HeaderInfo;  
}

#endif  // OWL_PROPSHT_H
