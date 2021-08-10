//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TEventHandler
//----------------------------------------------------------------------------
#include <owl/owlpch.h>
#include <owl/point.h>
#include <owl/eventhan.h>
#include <stdlib.h>

DIAG_DEFINE_GROUP_INIT(OWL_INI, OwlMsg, 1, 0);
                             // diagnostic group for message tracing

#if defined(__TRACE) || defined(__WARN)
  struct WMSTR {
    uint    msg;
    char*   str;
  };

  static  WMSTR  StrTab[] = {
    { WM_CREATE,                "WM_CREATE"               },  // 0x0001
    { WM_DESTROY,               "WM_DESTROY"              },  // 0x0002
    { WM_MOVE,                  "WM_MOVE"                 },  // 0x0003
    { WM_SIZE,                  "WM_SIZE"                 },  // 0x0005
    { WM_ACTIVATE,              "WM_ACTIVATE"             },  // 0x0006
    { WM_SETFOCUS,              "WM_SETFOCUS"             },  // 0x0007
    { WM_KILLFOCUS,             "WM_KILLFOCUS"            },  // 0x0008
    { 0x0009,                   "wm_setvisible"           },  // 0x0009
    { WM_ENABLE,                "WM_ENABLE"               },  // 0x000A
    { WM_SETREDRAW,             "WM_SETREDRAW"            },  // 0x000B
    { WM_SETTEXT,               "WM_SETTEXT"              },  // 0x000C
    { WM_GETTEXT,               "WM_GETTEXT"              },  // 0x000D
    { WM_GETTEXTLENGTH,         "WM_GETTEXTLENGTH"        },  // 0x000E
    { WM_PAINT,                 "WM_PAINT"                },  // 0x000F
    { WM_CLOSE,                 "WM_CLOSE"                },  // 0x0010
    { WM_QUERYENDSESSION,       "WM_QUERYENDSESSION"      },  // 0x0011
    { WM_QUIT,                  "WM_QUIT"                 },  // 0x0012
    { WM_QUERYOPEN,             "WM_QUERYOPEN"            },  // 0x0013
    { WM_ERASEBKGND,            "WM_ERASEBKGND"           },  // 0x0014
    { WM_SYSCOLORCHANGE,        "WM_SYSCOLORCHANGE"       },  // 0x0015
    { WM_ENDSESSION,            "WM_ENDSESSION"           },  // 0x0016
    { 0x0017,                   "WM_SYSTEMERROR"          },  // 0x0017
    { WM_SHOWWINDOW,            "WM_SHOWWINDOW"           },  // 0x0018
    { WM_CTLCOLOR,              "WM_CTLCOLOR"             },  // 0x0019
    { WM_WININICHANGE,          "WM_WININICHANGE"         },  // 0x001A
    { WM_DEVMODECHANGE,         "WM_DEVMODECHANGE"        },  // 0x001B
    { WM_ACTIVATEAPP,           "WM_ACTIVATEAPP"          },  // 0x001C
    { WM_FONTCHANGE,            "WM_FONTCHANGE"           },  // 0x001D
    { WM_TIMECHANGE,            "WM_TIMECHANGE"           },  // 0x001E
    { WM_CANCELMODE,            "WM_CANCELMODE"           },  // 0x001F
    { WM_SETCURSOR,             "WM_SETCURSOR"            },  // 0x0020
    { WM_MOUSEACTIVATE,         "WM_MOUSEACTIVATE"        },  // 0x0021
    { WM_CHILDACTIVATE,         "WM_CHILDACTIVATE"        },  // 0x0022
    { WM_QUEUESYNC,             "WM_QUEUESYNC"            },  // 0x0023
    { WM_GETMINMAXINFO,         "WM_GETMINMAXINFO"        },  // 0x0024
    { 0x0026,                   "wm_painticon"            },  // 0x0026
    { WM_ICONERASEBKGND,        "WM_ICONERASEBKGND"       },  // 0x0027
    { WM_NEXTDLGCTL,            "WM_NEXTDLGCTL"           },  // 0x0028
    { 0x0029,                   "wm_alttabactive"         },  // 0x0029
    { WM_SPOOLERSTATUS,         "WM_SPOOLERSTATUS"        },  // 0x002A
    { WM_DRAWITEM,              "WM_DRAWITEM"             },  // 0x002B
    { WM_MEASUREITEM,           "WM_MEASUREITEM"          },  // 0x002C
    { WM_DELETEITEM,            "WM_DELETEITEM"           },  // 0x002D
    { WM_VKEYTOITEM,            "WM_VKEYTOITEM"           },  // 0x002E
    { WM_CHARTOITEM,            "WM_CHARTOITEM"           },  // 0x002F
    { WM_SETFONT,               "WM_SETFONT"              },  // 0x0030
    { WM_GETFONT,               "WM_GETFONT"              },  // 0x0031
    { 0x0032,                   "wm_sethotkey"            },  // 0x0032
    { 0x0033,                   "wm_gethotkey"            },  // 0x0033
    { 0x0034,                   "wm_filesyschange"        },  // 0x0034
    { 0x0035,                   "wm_isactiveicon"         },  // 0x0035
    { 0x0036,                   "wm_queryparkicon"        },  // 0x0036
    { WM_QUERYDRAGICON,         "WM_QUERYDRAGICON"        },  // 0x0037
    { WM_COMPAREITEM,           "WM_COMPAREITEM"          },  // 0x0039
    { WM_COMPACTING,            "WM_COMPACTING"           },  // 0x0041
    { 0x0042,                   "wm_otherwindowcreated"   },  // 0x0042
    { 0x0043,                   "wm_otherwindowdestroyed" },  // 0x0043
    { WM_COMMNOTIFY,            "WM_COMMNOTIFY"           },  // 0x0044
    { WM_WINDOWPOSCHANGING,     "WM_WINDOWPOSCHANGING"    },  // 0x0046
    { WM_WINDOWPOSCHANGED,      "WM_WINDOWPOSCHANGED"     },  // 0x0047
    { WM_POWER,                 "WM_POWER"                },  // 0x0048
    { WM_NCCREATE,              "WM_NCCREATE"             },  // 0x0081
    { WM_NCDESTROY,             "WM_NCDESTROY"            },  // 0x0082
    { WM_NCCALCSIZE,            "WM_NCCALCSIZE"           },  // 0x0083
    { WM_NCHITTEST,             "WM_NCHITTEST"            },  // 0x0084
    { WM_NCPAINT,               "WM_NCPAINT"              },  // 0x0085
    { WM_NCACTIVATE,            "WM_NCACTIVATE"           },  // 0x0086
    { WM_GETDLGCODE,            "WM_GETDLGCODE"           },  // 0x0087
    { 0x0088,                   "wm_syncpaint"            },  // 0x0088
    { 0x0089,                   "wm_synctask"             },  // 0x0089
    { WM_NCMOUSEMOVE,           "WM_NCMOUSEMOVE"          },  // 0x00A0
    { WM_NCLBUTTONDOWN,         "WM_NCLBUTTONDOWN"        },  // 0x00A1
    { WM_NCLBUTTONUP,           "WM_NCLBUTTONUP"          },  // 0x00A2
    { WM_NCLBUTTONDBLCLK,       "WM_NCLBUTTONDBLCLK"      },  // 0x00A3
    { WM_NCRBUTTONDOWN,         "WM_NCRBUTTONDOWN"        },  // 0x00A4
    { WM_NCRBUTTONUP,           "WM_NCRBUTTONUP"          },  // 0x00A5
    { WM_NCRBUTTONDBLCLK,       "WM_NCRBUTTONDBLCLK"      },  // 0x00A6
    { WM_NCMBUTTONDOWN,         "WM_NCMBUTTONDOWN"        },  // 0x00A7
    { WM_NCMBUTTONUP,           "WM_NCMBUTTONUP"          },  // 0x00A8
    { WM_NCMBUTTONDBLCLK,       "WM_NCMBUTTONDBLCLK"      },  // 0x00A9
    { WM_KEYDOWN,               "WM_KEYDOWN"              },  // 0x0100
    { WM_KEYUP,                 "WM_KEYUP"                },  // 0x0101
    { WM_CHAR,                  "WM_CHAR"                 },  // 0x0102
    { WM_SYSKEYDOWN,            "WM_SYSKEYDOWN"           },  // 0x0104
    { WM_SYSKEYUP,              "WM_SYSKEYUP"             },  // 0x0105
    { WM_SYSCHAR,               "WM_SYSCHAR"              },  // 0x0106
    { WM_SYSDEADCHAR,           "WM_SYSDEADCHAR"          },  // 0x0107
    { WM_INITDIALOG,            "WM_INITDIALOG"           },  // 0x0110
    { WM_COMMAND,               "WM_COMMAND"              },  // 0x0111
    { WM_SYSCOMMAND,            "WM_SYSCOMMAND"           },  // 0x0112
    { WM_TIMER,                 "WM_TIMER"                },  // 0x0113
    { WM_HSCROLL,               "WM_HSCROLL"              },  // 0x0114
    { WM_VSCROLL,               "WM_VSCROLL"              },  // 0x0115
    { WM_INITMENU,              "WM_INITMENU"             },  // 0x0116
    { WM_INITMENUPOPUP,         "WM_INITMENUPOPUP"        },  // 0x0117
    { 0x0118,                   "wm_systimer"             },  // 0x0118
    { WM_MENUSELECT,            "WM_MENUSELECT"           },  // 0x011F
    { WM_MENUCHAR,              "WM_MENUCHAR"             },  // 0x0120
    { WM_ENTERIDLE,             "WM_ENTERIDLE"            },  // 0x0121
    { 0x0131,                   "wm_lbtrackpoint"         },  // 0x0131
    { WM_MOUSEMOVE,             "WM_MOUSEMOVE"            },  // 0x0200
    { WM_LBUTTONDOWN,           "WM_LBUTTONDOWN"          },  // 0x0201
    { WM_LBUTTONUP,             "WM_LBUTTONUP"            },  // 0x0202
    { WM_LBUTTONDBLCLK,         "WM_LBUTTONDBLCLK"        },  // 0x0203
    { WM_RBUTTONDOWN,           "WM_RBUTTONDOWN"          },  // 0x0204
    { WM_RBUTTONUP,             "WM_RBUTTONUP"            },  // 0x0205
    { WM_RBUTTONDBLCLK,         "WM_RBUTTONDBLCLK"        },  // 0x0206
    { WM_MBUTTONDOWN,           "WM_MBUTTONDOWN"          },  // 0x0207
    { WM_MBUTTONUP,             "WM_MBUTTONUP"            },  // 0x0208
    { WM_MBUTTONDBLCLK,         "WM_MBUTTONDBLCLK"        },  // 0x0209
    { WM_PARENTNOTIFY,          "WM_PARENTNOTIFY"         },  // 0x0210
    { 0x0211,                   "wm_entermenuloop"        },  // 0x0211
    { 0x0212,                   "wm_exitmenuloop"         },  // 0x0212
    { WM_MDICREATE,             "WM_MDICREATE"            },  // 0x0220
    { WM_MDIDESTROY,            "WM_MDIDESTROY"           },  // 0x0221
    { WM_MDIACTIVATE,           "WM_MDIACTIVATE"          },  // 0x0222
    { WM_MDIRESTORE,            "WM_MDIRESTORE"           },  // 0x0223
    { WM_MDINEXT,               "WM_MDINEXT"              },  // 0x0224
    { WM_MDIMAXIMIZE,           "WM_MDIMAXIMIZE"          },  // 0x0225
    { WM_MDITILE,               "WM_MDITILE"              },  // 0x0226
    { WM_MDICASCADE,            "WM_MDICASCADE"           },  // 0x0227
    { WM_MDIICONARRANGE,        "WM_MDIICONARRANGE"       },  // 0x0228
    { WM_MDIGETACTIVE,          "WM_MDIGETACTIVE"         },  // 0x0229
    { 0x022A,                   "wm_dropobject"           },  // 0x022A
    { 0x022B,                   "wm_querydropobject"      },  // 0x022B
    { 0x022C,                   "wm_begindrag"            },  // 0x022C
    { 0x022D,                   "wm_dragloop"             },  // 0x022D
    { 0x022E,                   "wm_dragselect"           },  // 0x022E
    { 0x022F,                   "wm_dragmove"             },  // 0x022F
    { WM_MDISETMENU,            "WM_MDISETMENU"           },  // 0x0230
    { 0x0231,                   "wm_entersizemove"        },  // 0x0231
    { 0x0232,                   "wm_exitsizemove"         },  // 0x0232
    { WM_DROPFILES,             "WM_DROPFILES"            },  // 0x0233
    { WM_CUT,                   "WM_CUT"                  },  // 0x0300
    { WM_COPY,                  "WM_COPY"                 },  // 0x0301
    { WM_PASTE,                 "WM_PASTE"                },  // 0x0302
    { WM_CLEAR,                 "WM_CLEAR"                },  // 0x0303
    { WM_UNDO,                  "WM_UNDO"                 },  // 0x0304
    { WM_RENDERFORMAT,          "WM_RENDERFORMAT"         },  // 0x0305
    { WM_RENDERALLFORMATS,      "WM_RENDERALLFORMATS"     },  // 0x0306
    { WM_DESTROYCLIPBOARD,      "WM_DESTROYCLIPBOARD"     },  // 0x0307
    { WM_DRAWCLIPBOARD,         "WM_DRAWCLIPBOARD"        },  // 0x0308
    { WM_PAINTCLIPBOARD,        "WM_PAINTCLIPBOARD"       },  // 0x0309
    { WM_VSCROLLCLIPBOARD,      "WM_VSCROLLCLIPBOARD"     },  // 0x030A
    { WM_SIZECLIPBOARD,         "WM_SIZECLIPBOARD"        },  // 0x030B
    { WM_ASKCBFORMATNAME,       "WM_ASKCBFORMATNAME"      },  // 0x030C
    { WM_CHANGECBCHAIN,         "WM_CHANGECBCHAIN"        },  // 0x030D
    { WM_HSCROLLCLIPBOARD,      "WM_HSCROLLCLIPBOARD"     },  // 0x030E
    { WM_QUERYNEWPALETTE,       "WM_QUERYNEWPALETTE"      },  // 0x030F
    { WM_PALETTEISCHANGING,     "WM_PALETTEISCHANGING"    },  // 0x0310
    { WM_PALETTECHANGED,        "WM_PALETTECHANGED"       },  // 0x0311
  };

  //
  // MsgCompare: this internal function is used by the qsort() and
  // bsearch() functions to compare two StrTab elements.
  //
  static int
  MsgCompare(const void* e1, const void* e2)
  {
    return ((WMSTR*)e1)->msg - ((WMSTR*)e2)->msg;
  }

  ostream& operator <<(ostream& os, const MsgName& msg)
  {
    WMSTR  key;
    WMSTR* item;

    // if it's a user message, then just show the offset value
    if (msg.Message >= WM_USER)
      return os << "WM_USER+" << hex << (msg.Message - WM_USER);

    // otherwise, search for it in the table
    else {
      // initialize the search key
      key.msg = msg.Message;

      // let bsearch() do the work
      item = (WMSTR*)bsearch(&key, StrTab, COUNTOF(StrTab), sizeof(WMSTR), MsgCompare);

      // if message found, then insert the name
      if (item)
        return os << item->str;

      // otherwise, just insert the message number
      else
        return os << "Message " << hex << msg.Message;
    }
  }
#endif


bool
TEventHandler::Find(TEventInfo&, TEqualOperator)
{
  return false;
}

LRESULT
TEventHandler::Dispatch(TEventInfo& eventInfo, WPARAM wParam, LPARAM lParam)
{
  PRECONDITION(eventInfo.Entry);
  return (*eventInfo.Entry->Dispatcher)(
           *eventInfo.Object,
           (TAnyPMF __RTFAR&)eventInfo.Entry->Pmf,
           wParam, lParam
         );
}

bool
TEventHandler::SearchEntries(TGenericTableEntry __RTFAR* entries,
                             TEventInfo&         eventInfo,
                             TEqualOperator      equal)
{
  if (equal) {
    while (entries->Dispatcher != 0) {
      if (equal(*entries, eventInfo)) {
        eventInfo.Entry = entries;
        return true;
      }
      entries++;
    }
  }
  else {
    while (entries->Dispatcher != 0) {
      if (entries->Msg == eventInfo.Msg && entries->Id == eventInfo.Id) {
        eventInfo.Entry = entries;
        return true;
      }
      entries++;
    }
  }

  return false;
}
