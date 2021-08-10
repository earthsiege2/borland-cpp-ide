
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       Control Panel extension DLL definitions         }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Borland Software Corporation        }
{                                                       }
{*******************************************************}

unit Cpl;

{$HPPEMIT '#include <cpl.h>'}

interface

uses Messages, Windows;

{  General rules for being installed in the Control Panel:

      1) The DLL must export a function named CPlApplet which will handle
         the messages discussed below.
      2) If the applet needs to save information in CONTROL.INI minimize
         clutter by using the application name [MMCPL.appletname].
      2) If the applet is refrenced in CONTROL.INI under [MMCPL] use
         the following form:
              ...
              [MMCPL]
              uniqueName=c:\mydir\myapplet.dll
              ...


  The order applet DLL's are loaded by CONTROL.EXE is:

      1) MAIN.CPL is loaded from the windows system directory.

      2) Installable drivers that are loaded and export the
         CplApplet() routine.

      3) DLL's specified in the [MMCPL] section of CONTROL.INI.

      4) DLL's named *.CPL from windows system directory.


 CONTROL.EXE will answer this message and launch an applet

 WM_CPL_LAUNCH

      wParam      - window handle of calling app
      lParam      - LPTSTR of name of applet to launch

 WM_CPL_LAUNCHED

      wParam      - TRUE/FALSE if applet was launched
      lParam      - NULL

 CONTROL.EXE will post this message to the caller when the applet returns
 (ie., when wParam is a valid window handle)
}

const
  {$EXTERNALSYM WM_CPL_LAUNCH}
  WM_CPL_LAUNCH   = (WM_USER+1000);
  {$EXTERNALSYM WM_CPL_LAUNCHED}
  WM_CPL_LAUNCHED = (WM_USER+1001);

  // The messages CPlApplet() must handle:
  {$EXTERNALSYM CPL_DYNAMIC_RES}
  CPL_DYNAMIC_RES = 0;
  { This constant may be used in place of real resource IDs for the idIcon,
    idName or idInfo members of the CPLINFO structure.  Normally, the system
    uses these values to extract copies of the resources and store them in a
    cache.  Once the resource information is in the cache, the system does not
    need to load a CPL unless the user actually tries to use it.

    CPL_DYNAMIC_RES tells the system not to cache the resource, but instead to
    load the CPL every time it needs to display information about an item.  This
    allows a CPL to dynamically decide what information will be displayed, but
    is SIGNIFICANTLY SLOWER than displaying information from a cache.
    Typically, CPL_DYNAMIC_RES is used when a control panel must inspect the
    runtime status of some device in order to provide text or icons to display.
  }
  {$EXTERNALSYM CPL_INIT}
  CPL_INIT = 1;
  { This message is sent to indicate CPlApplet() was found. lParam1 and lParam2
    are not defined. Return TRUE or FALSE indicating whether the control panel
    should proceed.
  }
  {$EXTERNALSYM CPL_GETCOUNT}
  CPL_GETCOUNT = 2;
  { This message is sent to determine the number of applets to be displayed.
    lParam1 and lParam2 are not defined. Return the number of applets you wish
    to display in the control
    panel window.
  }
  {$EXTERNALSYM CPL_INQUIRE}
  CPL_INQUIRE = 3;
  { This message is sent for information about each applet. lParam1 is the
    applet number to register, a value from 0 to(CPL_GETCOUNT - 1).
    lParam2 is a far ptr to a CPLINFO structure. Fill in CPL_INFO's idIcon,
    idName, idInfo and lData fields with the resource id for an icon to
    display, name and description string ids, and a long data item
    associated with applet #lParam1.
  }
  {$EXTERNALSYM CPL_SELECT}
  CPL_SELECT = 4;
  { This message is sent when the applet's icon has been clicked upon.
    lParam1 is the applet number which was selected.  lParam2 is the
    applet's lData value.
  }
  {$EXTERNALSYM CPL_DBLCLK}
  CPL_DBLCLK = 5;
  { This message is sent when the applet's icon has been double-clicked
    upon.  lParam1 is the applet number which was selected.  lParam2 is the
    applet's lData value. This message should initiate the applet's dialog box.
  }
  {$EXTERNALSYM CPL_STOP}
  CPL_STOP = 6;
  { This message is sent for each applet when the control panel is exiting.
    lParam1 is the applet number.  lParam2 is the applet's lData  value.
    Do applet specific cleaning up here.
  }
  {$EXTERNALSYM CPL_EXIT}
  CPL_EXIT = 7;
  { This message is sent just before the control panel calls FreeLibrary.
    lParam1 and lParam2 are not defined.
    Do non-applet specific cleaning up here.
  }
  {$EXTERNALSYM CPL_NEWINQUIRE}
  CPL_NEWINQUIRE = 8;
  { This is the same as CPL_INQUIRE execpt lParam2 is a pointer to a
    NEWCPLINFO structure.  this will be sent before the CPL_INQUIRE
    and if it is responed to (return != 0) CPL_INQUIRE will not be sent
  }
  {$EXTERNALSYM CPL_STARTWPARMS}
  CPL_STARTWPARMS = 9;
  { This message parallels CPL_DBLCLK in that the applet should initiate
    its dialog box.  where it differs is that this invocation is coming
    out of RUNDLL, and there may be some extra directions for execution.
    lParam1: the applet number.
    lParam2: an LPSTR to any extra directions that might exist.
    returns: TRUE if the message was handled; FALSE if not.
  }
  {$EXTERNALSYM CPL_SETUP}
  CPL_SETUP = 200;
  { This message is internal to the Control Panel and MAIN applets.
    It is only sent when an applet is invoked from the Command line
    during system installation.
  }

type
  //A function prototype for CPlApplet()
  {$EXTERNALSYM APPLET_PROC}
  APPLET_PROC = function (hwndCPl: THandle; uMsg: DWORD;
                         lParam1, lParam2: Longint): Longint; stdcall;
  TCPLApplet = APPLET_PROC;

  //The data structure CPlApplet() must fill in.
  PCPLInfo = ^TCPLInfo;
  {$EXTERNALSYM tagCPLINFO}
  tagCPLINFO = packed record
     idIcon: Integer;  // icon resource id, provided by CPlApplet()
     idName: Integer;  // name string res. id, provided by CPlApplet()
     idInfo: Integer;  // info string res. id, provided by CPlApplet()
     lData : Longint;  // user defined data
  end;
  {$EXTERNALSYM CPLINFO}
  CPLINFO = tagCPLINFO;
  TCPLInfo = tagCPLINFO;

  PNewCPLInfoA = ^TNewCPLInfoA;
  PNewCPLInfoW = ^TNewCPLInfoW;
  PNewCPLInfo = PNewCPLInfoA;
  {$EXTERNALSYM tagNEWCPLINFOA}
  tagNEWCPLINFOA = packed record
    dwSize:        DWORD;   // similar to the commdlg
    dwFlags:       DWORD;
    dwHelpContext: DWORD;   // help context to use
    lData:         Longint; // user defined data
    hIcon:         HICON;   // icon to use, this is owned by CONTROL.EXE (may be deleted)
    szName:        array[0..31] of AnsiChar;    // short name
    szInfo:        array[0..63] of AnsiChar;    // long name (status line)
    szHelpFile:    array[0..127] of AnsiChar;   // path to help file to use
  end;
  {$EXTERNALSYM tagNEWCPLINFOW}
  tagNEWCPLINFOW = packed record
    dwSize:        DWORD;   // similar to the commdlg
    dwFlags:       DWORD;
    dwHelpContext: DWORD;   // help context to use
    lData:         Longint; // user defined data
    hIcon:         HICON;   // icon to use, this is owned by CONTROL.EXE (may be deleted)
    szName:        array[0..31] of WideChar;    // short name
    szInfo:        array[0..63] of WideChar;    // long name (status line)
    szHelpFile:    array[0..127] of WideChar;   // path to help file to use
  end;
  {$EXTERNALSYM tagNEWCPLINFO}
  tagNEWCPLINFO = tagNEWCPLINFOA;
  {$EXTERNALSYM NEWCPLINFOA}
  NEWCPLINFOA = tagNEWCPLINFOA;
  {$EXTERNALSYM NEWCPLINFOW}
  NEWCPLINFOW = tagNEWCPLINFOW;
  {$EXTERNALSYM NEWCPLINFO}
  NEWCPLINFO = NEWCPLINFOA;
  TNewCPLInfoA = tagNEWCPLINFOA;
  TNewCPLInfoW = tagNEWCPLINFOW;
  TNewCPLInfo = TNewCPLInfoA;

implementation
end.
