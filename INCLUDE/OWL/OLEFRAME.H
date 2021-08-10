//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1994 by Borland International, All Rights Reserved
//
//----------------------------------------------------------------------------
#if !defined(OWL_OLEFRAME_H)
#define OWL_OLEFRAME_H

#if !defined(OWL_DECFRAME_H)
# include <owl/decframe.h>
#endif
#if !defined(OWL_OCFEVENT_H)
# include <owl/ocfevent.h>
#endif
#if !defined(OCF_OCREG)
# include <ocf/ocreg.h>
#endif
#if !defined(OWL_OLEFACTO_H)
# include <owl/olefacto.h>
#endif

// pad decorations IDs, 4 total: 32042, 32043, 32044, 32045
//
const int IDW_PADDECORATION = 32042;
const int IDW_REMVIEWBUCKET = 32046;  // Window id for remote view holder
const int IDT_DLLIDLE       = 32000;  // Idle timer ID for DLL servers

class TOcMenuDescr;
class _ICLASS TOcApp;

//
// class TOleFrame
// ----- ---------
//
// Decorated frame that supports OLE 2 using OCF
//
class _USERCLASS TOleFrame : public TDecoratedFrame {
  public:
    TOleFrame(const char far* title,
              TWindow*        clientWnd,
              bool            trackMenuSelection = false,
              TModule*        module = 0);
   ~TOleFrame();
    TOcApp*    GetOcApp() {return OcApp;}
    void       SetOcApp(TOcApp* app);
    void       AddUserFormatName(const char far* name, const char far* resultName, const char far* id);

    TWindow*   GetRemViewBucket() {return ChildWithId(IDW_REMVIEWBUCKET);}
    void       OleViewClosing(bool close);

  protected:
    void       SetupWindow();
    void       CleanupWindow();
    void       Destroy(int retVal);

    void       EvSize(uint sizeType, TSize& size);
    void       EvActivateApp(bool active, HTASK hTask);
    void       EvTimer(uint timerId);

    LRESULT    EvOcEvent(WPARAM wParam, LPARAM lParam);
    bool       EvOcAppInsMenus(TOcMenuDescr far& sharedMenu);
    bool       EvOcAppMenus(TOcMenuDescr far& md);
    bool       EvOcAppProcessMsg(MSG far* msg);
    bool       EvOcAppFrameRect(TRect far* rect);
    bool       EvOcAppBorderSpaceReq(TRect far* rect);
    bool       EvOcAppBorderSpaceSet(TRect far* rect);
    void       EvOcAppStatusText(const char far* rect);
    void       EvOcAppRestoreUI();
    void       EvOcAppDialogHelp(TOcDialogHelp far& dh) {}
    bool       EvOcAppShutdown();

  protected:
    TOcApp*    OcApp;
    TMenu      StashedContainerPopups;
    int        StashCount;
    void       StashContainerPopups(const TMenuDescr& shMenuDescr);
    void       DestroyStashedPopups();
    HMENU      HOldMenu;

  private:
    enum {
      DontCare, UserInitiated, ViewInitiated, ServerInitiated
    } OcShutDown;

  DECLARE_RESPONSE_TABLE(TOleFrame);
};

#endif  // OWL_OLEFRAME_H
