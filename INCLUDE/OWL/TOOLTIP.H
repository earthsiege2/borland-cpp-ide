//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.18  $
//
// Definition of the TTooltip class and helper objects
//----------------------------------------------------------------------------
#if !defined(OWL_TOOLTIP_H)
#define OWL_TOOLTIP_H

#if !defined(OWL_COMMCTRL_H)
# include <owl/commctrl.h>
#endif
#if !defined(OWL_CONTAIN_H)
# include <owl/contain.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TFont;
class _OWLCLASS TTooltip;

//
// class TToolInfo
// ~~~~~ ~~~~~~~~~
// TToolInfo contains information about a particular tool (a tool is
// either a window or an application-defined rectangular area within
// a window's client area). For example, it contains the text
// to be displayed in the tooltip window.
//
class _OWLCLASS TToolInfo : public TOOLINFO {
  public:

    // Default constructor of TToolInfo
    //
    TToolInfo(bool allocCache = false);

    // Constructor for a tooltip associated with a rectangular area
    // within a window's client area. The 'window' receives
    // 'TTN_NEEDTEXT' notifications if 'txt' is not provided.
    //
    TToolInfo(HWND window, const TRect& rect, uint toolId,
              const char far* txt = LPSTR_TEXTCALLBACK);

    // Constructor for a tooltip associated with a rectangular area
    // within a window's client area. The 'txtRes' specifies the ID
    // of the string to be used by the tooltip window.
    //
    TToolInfo(HWND window, const TRect&, uint toolId,
              int resId,  HINSTANCE txtResModule);

    // Constructor for tool implemented as windows (eg. child/controls).
    // 'parent' receives the 'TTN_NEEDTEXT' notification in case where
    // the default LPSTR_TEXTCALLBACK is used for the 'txt' parameter.
    //
    TToolInfo(HWND parent, HWND toolHwnd,
              const char far* txt = LPSTR_TEXTCALLBACK);

    // Constructor for tool implemented as windows (eg. child/controls).
    // 'resId' identifies the resource ID of the string to be used by
    // the tooltip window.
    //
    TToolInfo(HWND parent, HWND toolHwnd, int resId, HINSTANCE strResModule);

    // Set data members of the TOOLINFO structure which identify each tool
    //
    void        SetToolInfo(HWND toolWin, uint id, const TRect& rc);
    void        SetToolInfo(HWND toolWin, uint id);
    void        SetToolInfo(HWND toolWin, HWND parent);

    // Set the text associated with a tooltip and the tool rectangles
    //
    void        SetText(int resId, HINSTANCE hinstance);
    void        SetText(const char far* text, bool copy = true);
    void        SetRect(const TRect& rect);

    // Helper routine which returns the 'HWND'/rect associated with a
    // particular tool.
    //
    HWND        GetToolWindow() const;
    void        GetToolRect(TRect& rect) const;

    // Helper routine to help determine whether a particular
    // location is pertinent to a tool
    //
    bool        IsPointInTool(HWND win, const TPoint& pt) const;

    // Copy ctr & assignment operator
    //
    TToolInfo(const TToolInfo&);
    TToolInfo& operator =(const TToolInfo&);

    // Checks whether two TToolInfo structures refer to the same tool
    //
    bool    operator==(const TToolInfo& ti) const;

    // Return/clear cached text
    //
    const char* GetCacheText() const;
    void        FlushCacheText();

  private:
    TAPointer<char> CacheText;
};

//
// class TTooltipHitTestInfo
// ~~~~~ ~~~~~~~~~~~~~~~~~~~
// TTooltipHitTestInfo is a thin [very thin] wrapper around
// the TTHITTESTINFO structure, used to determined whether a
// point is within the bounding rectangle of a particular tool.
// It's a place-holder for future ObjectWindows enhancements to
// tooltip hit-testing.
//
class _OWLCLASS TTooltipHitTestInfo : public TTHITTESTINFO {
};

//
// class TTooltipEnabler
// ~~~~~ ~~~~~~~~~~~~~~~
// TTooltipEnabler is the object forwarded along the command-chain to
// retrieve the tip text of a tool. The object is not a 'true' command 
// enabler [i.e. invoking SetCheck or Enable do not modify the state of the
// command associated with the tool]; however, by using the 'CommandEnabler'
// setup retrieving the text of tools, the potential of the commands are
// given first crack at customizing the text.
//
class _OWLCLASS TTooltipEnabler : public TCommandEnabler {
  public:
    TTooltipEnabler(TTooltipText& tt, TWindow::THandle hReceiver);

    // Override member functions of TCommandEnabler
    //
    void  SetText(const char far* text);
    void  SetCheck(int /*check*/);

  protected_data:

    // Reference to structure accompanying a notification requesting
    // for the text of a particular tool.
    //
    TTooltipText& TipText;
};

//
// class TTooltip
// ~~~~~ ~~~~~~~~
// TTooltip encapsulates a tooltip window - i.e. a small popup window
// that displays a single line of descriptive test giving the purpose
// of the item underneath the current cursor location.
//
class _OWLCLASS TTooltip : public TControl {
  public:
    TTooltip(TWindow* parent, bool alwaysTip = true, TModule* module = 0);

#if defined(BI_PLAT_WIN32)
    TTooltip(HWND hWnd, TModule* module = 0);
#endif

   ~TTooltip();

    // Set state of tooltip
    //
    void        Activate(bool activate = true);

    // Add/remove/enumerate tools
    //
    bool        AddTool(const TToolInfo&);
    void        DeleteTool(const TToolInfo&);
    bool        EnumTools(uint index, TToolInfo&) const;

    // Update/retrive attribute of tools
    //
    bool        GetCurrentTool(TToolInfo&) const;
    void        GetToolText(TToolInfo&) const;
    uint        GetToolCount() const;
    bool        GetToolInfo(TToolInfo&) const;
    void        SetToolInfo(const TToolInfo&);
    void        UpdateTipText(const TToolInfo&);

    bool        HitTest(TTooltipHitTestInfo&) const;
    void        NewToolRect(const TToolInfo&);
    void        RelayEvent(MSG&);
    void        SetDelayTime(WPARAM flag, int delay);

  protected:
    // Override TWindow virtual member functions
    //
    char far*   GetClassName();

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TTooltip(const TTooltip&);
    TTooltip& operator =(const TTooltip&);


#if defined(BI_PLAT_WIN16)
  protected:
    // Override virtual(s) from TWindow
    //
    void        GetWindowClass(WNDCLASS& wc);
    void        SetupWindow();
    void        CleanupWindow();
    void        Paint(TDC& dc, bool erase, TRect& rect);

    // Routines implementing ObjectWindows Tooltips
    //
    void        Init();
    void        Cleanup();
    void        ShowActiveTip(TPoint& pt);
    void        HideActiveTip();
    void        EnableTimer();
    void        DisableTimer();
    void        RelayEvent(HWND receiver, uint msg, const TPoint& pt);

    // Message Response Functions
    //
    void        EvTimer(uint timerId);
    HFONT       EvGetFont();
    void        EvSetFont(HFONT hFont, bool redraw);
    void        EvLButtonDown(uint modKeys, TPoint& point);
    void        EvRButtonDown(uint modKeys, TPoint& point);

  private:
    // Helpers used by OWL's implementation of TOOLTIPS
    //
    bool                Active;           // Flags if tooltip is active?
    int                 Delay;            // Grace period before popping tip
    TFont*              ToolFont;         // Font used by tooltip window
    TToolInfo*          ActiveTool;       // Currently active tool
    TToolInfo*          PotentialTool;    // Tool we're waiting on
    TPoint              MouseLoc;         // Last recorded mouse loc
    bool                TimerEnabled;     // Flags if Timer's currently set
    TCollection<TToolInfo>* ToolList;     // Collection of Tools

  DECLARE_RESPONSE_TABLE(TTooltip);
#endif  //  (BI_PLAT_WIN16)
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// Inline implementation
//

//
// Sets the text of this tool by providing a string resource identifier
// and the handle of the instance containing that resource.
//
inline void TToolInfo::SetText(int resId, HINSTANCE hinstance)
{
  lpszText = CONST_CAST(char far*, MAKEINTRESOURCE(resId));
  hinst = hinstance;
}

//
// Sets the bounding rectangle of the tool. The coordinates are relative
// to the upper-left corner of the client area of the window.
// NOTE: This flag is only valid if the tool is a rectangle within
//       the window and not a control parented to the window.
//
inline void TToolInfo::SetRect(const TRect& rc)
{
  rect = rc;
}

//
// If the IDs of two tools (or the Window Handles of two tools
// for cases when 'uFlags & TTF_IDISHWND') are similar and the
// handle of the window containing them matches, we'll infer that
// the structures are referring to the same tool.
//
inline bool TToolInfo::operator==(const TToolInfo& ti) const
{
  return (uId == ti.uId && hwnd == ti.hwnd) ? true : false;
}

//
//
//
inline const char* 
TToolInfo::GetCacheText() const 
{
  return (char*)(CONST_CAST(TToolInfo*, this)->CacheText);
}

//
//
//
inline void
TToolInfo::FlushCacheText()
{
  CacheText = 0;
}

//----------------------------------------------------------------------------
// When ObjectWindows relies exclusively on the native implementation of
// TOOLTIPS, the methods to manipulate the control are simple wrappers around
// predefined TOOLTIP messages (TTM_xxxx).
//
#if defined(BI_PLAT_WIN32)

//
// Activates or deactivates the tooltip control. If 'activate' is true,
// the tooltip control is activated, If it is false the tooltip control
// is deactivated.
//
inline void TTooltip::Activate(bool activate)
{
  SendMessage(TTM_ACTIVATE, TParam1(activate));
}

//
// Registers a tool with the tooltip control. The 'TToolInfo' parameter
// contains information that the tooltip control needs to display text
// for the tool.
//
inline bool TTooltip::AddTool(const TToolInfo& ti)
{
  return SendMessage(TTM_ADDTOOL, 0, TParam2(&ti)) != 0;
}

//
// Removes a tool from the tooltip control. You must invoke the
// 'SetToolHandle' or 'SetToolId' method of TToolInfo to identify
// the tool to remove. [i.e. the 'hwnd' or 'uId' members of the
// TToolInfo must identify the tool].
//
inline void TTooltip::DeleteTool(const TToolInfo& ti)
{
  SendMessage(TTM_DELTOOL, 0, TParam2(&ti));
}

//
// Retrieves the information that the tooltip control maintains 
// about the specified tool. Returns true if successul or false otherwise.
// NOTE: The index is zero-based and the TToolInfo structure receives
//       the information about the tool.
//
inline bool TTooltip::EnumTools(uint index, TToolInfo& ti) const
{
  return CONST_CAST(TTooltip*, this)->SendMessage(TTM_ENUMTOOLS,
                                                  index, TParam2(&ti)) != 0;
}

//
// Retrieves information about the current tool. The 'TToolInfo'
// parameter receives the information. Returns true if successful or
// false otherwise.
//
inline bool TTooltip::GetCurrentTool(TToolInfo& ti) const
{
  return CONST_CAST(TTooltip*, this)->SendMessage(TTM_GETCURRENTTOOL,
                                                  0, TParam2(&ti)) != 0;
}

//
// Retrieves the text associated with the specified tool. You must 
// invoke the 'SetToolHandle' or 'SetToolId' method of TToolInfo to 
// identify the tool. [i.e. the 'hwnd' or 'uId' members of the
// TToolInfo must identify the tool].
//
inline void TTooltip::GetToolText(TToolInfo& ti) const
{
  CONST_CAST(TTooltip*, this)->SendMessage(TTM_GETTEXT, 0, TParam2(&ti));
}

//
// Returns the number of tools currently registered with the 
// tooltip control. 
//
inline uint TTooltip::GetToolCount() const
{
  return (uint)CONST_CAST(TTooltip*, this)->SendMessage(TTM_GETTOOLCOUNT);
}

//
// Retrieves the information that the tooltip control maintains about
// a tool. You must invoke the 'SetToolHandle' or 'SetToolId' method 
// of TToolInfo to identify the tool. [i.e. the 'hwnd' or 'uId' members 
// of the TToolInfo must identify the tool].
//
inline bool TTooltip::GetToolInfo(TToolInfo& ti) const
{
  return CONST_CAST(TTooltip*, this)->SendMessage(TTM_GETTOOLINFO, 0,
                                                  TParam2(&ti)) != 0;
}

//
// Sets the information that the tooltip control maintains for a 
// particular tool. You must invoke the 'SetToolHandle' or 
// 'SetToolId' method of TToolInfo to identify the tool. 
// [i.e. the 'hwnd' or 'uId' members of the TToolInfo must 
// identify the tool].
//
inline void TTooltip::SetToolInfo(const TToolInfo& ti)
{
  SendMessage(TTM_SETTOOLINFO, 0, TParam2(&ti));
}

//
// Sets the text of a tool. You must invoke the 'SetToolHandle' or 
// 'SetToolId' method of TToolInfo to identify the tool. 
// [i.e. the 'hwnd' or 'uId' members of the TToolInfo must 
// identify the tool]  
//
inline void TTooltip::UpdateTipText(const TToolInfo& ti)
{
  SendMessage(TTM_UPDATETIPTEXT, 0, TParam2(&ti));
}

//
// Determines whether a tool is within a specified point. The method
// also retrieves information about the tool if one is identified at
// that location. Returns true if a tool if found at the location or
// false otherwise.
//
inline bool TTooltip::HitTest(TTooltipHitTestInfo& ttHTInfo) const
{
  return CONST_CAST(TTooltip*, this)->SendMessage(TTM_HITTEST, 0,
                                                  TParam2(&ttHTInfo)) != 0;
}

//
// Updates the bounding rectangle of a tool. You must invoke the 'SetToolId' 
// method of TToolInfo to identify the tool. [i.e. the 'uId' member
// of the TToolInfo must identify the tool].
//
inline void TTooltip::NewToolRect(const TToolInfo& ti)
{
  SendMessage(TTM_NEWTOOLRECT, 0, TParam2(&ti));
}

//
// Passes a mouse message to the tooltip control for processing.
//
inline void TTooltip::RelayEvent(MSG& msg)
{
  SendMessage(TTM_RELAYEVENT, 0, TParam2(&msg));
}

//
// Sets the initial, reshow and autopopup durations for a tooltip
// control. The 'flag' parameter can be one of the following:
//      TTDT_AUTOMATIC: Automatically calculates the initial. reshow
//                      and autopopup duration based on 'delay'.
//      TTDT_AUTOPOP:   Sets the length of time before the tooltip
//                      window is hidden if the cursor remains 
//                      stationary in the tool's bounding rectangle
//                      after the tooltip window has disappeared.
//      TTDT_INITIAL:   Set the length of time that the cursor must
//                      remain stationary within the bounding rectangle
//                      before the tooltip window is displayed.
//      TTDT_RESHOW:    Set the length of time before subsequent tooltip
//                      windows are displayed when the cursor is moved
//                      from one tool to another.
//
// NOTE: The 'delay' duration is in milliseconds.
//
inline void TTooltip::SetDelayTime(WPARAM flag, int delay)
{
  SendMessage(TTM_SETDELAYTIME, 0, TParam2(delay));
}

#endif  // BI_PLAT_WIN32
#endif  // OWL_TOOLTIP_H
